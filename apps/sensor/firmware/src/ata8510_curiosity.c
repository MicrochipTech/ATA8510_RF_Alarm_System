/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  $URL: $
  $LastChangedRevision: $
  $LastChangedDate: $
  $LastChangedBy: $
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/** \file ata8510_curiosity.c
    this file contains the main routine for ATA8510 Flash software for 
    ATA8510 Alarm Systems application
*/

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "ata8510_curiosity.h"

#include "common.h"
#include "rtc.h"
#include "keep_alive.h"
#include "child_learn.h"
#include "parent_learn.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/** Major Flash Version */
#define FLASH_MAJOR_VERSION     2
/** Minor Flash Version */
#define FLASH_MINOR_VERSION     32
/** Customer Flash Version */
#define FLASH_CUSTOMER_VERSION  0

/** Define used for consistency checking between Flash and ROM version */
#define FLASH_VERSION_CHECK ((FLASH_MAJOR_VERSION<<4U)|(FLASH_MINOR_VERSION >> 5U))
/** Error Code, which is used when Flash and ROM versions are inconsistent */
#define DEBUG_ERROR_CODE_FLASH_VERSION_INCONSISTENCY    0xFFU

/*===========================================================================*/
/*  Modul Globals                                                             */
/*===========================================================================*/
/** Data type containing the flash version information */
typedef struct
{
    uint8_t major;  /**< Major Flash version information */
    uint8_t minor;  /**< Minor Flash version information */
    uint8_t customer;   /**< Customer Flash version information */
}sFlashVersion_t;

/** section definition for flash version location in flash space */
#define VERSIONS_SECTION __section(".version")

/** Flash version for ATA8510 Alarm Systems application */
const VERSIONS_SECTION sFlashVersion_t flashVersion = {
    .major = FLASH_MAJOR_VERSION,
    .minor = FLASH_MINOR_VERSION,
    .customer = FLASH_CUSTOMER_VERSION
};

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/** CSTACK used for IAR functions in ROM */
int cstack[0x20];
uint8_t state;
sAppData_T app_data;

/* Idle State */
static void state_idle(void);
/* Alarm State */
static void state_alarm(void);
/* Verification State */
static void state_verification(void);
/* Status Update State */
static void state_status_update(void);
/* Error State */
static void state_error(void);

/** State machine function table of the application
 */
const fpVoidFuncVoid_T _state_table[] = {
    /* Idle State */
    state_idle,
    /* Keep Alive States */
    state_ka_cf,
    state_ka_cf_process_child_rx_ka_msg,
    state_ka_cf_process_child_tx_ack_msg,
    state_ka_cf_process_child_tx_ack_msg_complete,
    state_ka_cf_tx_ka_msg,
    state_ka_cf_start_rx_ack,
    state_ka_cf_rx_ack,
    state_ka_cf_sleep,
    /* Child Sensor Learn States */
    state_child_sensor_learn_tx_part_req,
    state_child_sensor_learn_start_rx_part_req_resp,
    state_child_sensor_learn_rx_part_req_resp,
    state_child_sensor_learn_rx_con_ver_stat,
    state_child_sensor_learn_tx_ack_msg,
    state_child_sensor_learn_tx_ack_msg_complete,
    /* Parent Sensor Learn States */
    state_parent_sensor_learn_start_rx_part_req,
    state_parent_sensor_learn_rx_part_req,
    state_parent_sensor_learn_tx_con_ver_req,
    state_parent_sensor_learn_start_rx_con_ver_resp,
    state_parent_sensor_learn_rx_con_ver_resp,
    state_parent_sensor_learn_tx_part_req_resp,
    state_parent_sensor_learn_tx_con_ver_stat,
    state_parent_sensor_learn_start_rx_ack_msg,
    state_parent_sensor_learn_rx_ack_msg,
    state_parent_sensor_learn_tx_ud_msg,
    state_parent_sensor_learn_start_rx_ack_msg_ud,
    state_parent_sensor_learn_rx_ack_msg_ud,
    /* Reset Device ID */
    state_reset_device_id,
    /* Verification State */
    state_verification,
    /* Status Update State */
    state_status_update,
    /* Alarm state */
    state_alarm,
    /* Error State */
    state_error,
};

/** Main routine for ATA8510 Alarm Systems application.
 * The main function checks for a valid system wake up, initializes the system
 * and enters the main loop which is responsible for command decoding, system
 * control and sleep mode control.
 * @return always 0
 */
int16_t main(void)
{
    /* setup MCUCR register for INTVEC at Flash start */

    MCUCR = 1 << IVCE;
    MCUCR = 1 << IVSEL;

    uint8_t mcusr = MCUSR;
    MCUSR = 0;

    API_checkWakeupSource_C();
    API_wdtDisable_C();
    API_setClk_C(1 << CLTPS0);	/* FRC for AVR core, Timer with FRC */

    // check for version inconsistency
    if ( romVersion != FLASH_VERSION_CHECK)
    {
        API_systemErrorLoop_C(DEBUG_ERROR_CODE_FLASH_VERSION_INCONSISTENCY);
    }

    /* if EEPROM configuration is not valid goto endless loop and signal error */
    if(API_systemInit_C(ATA_portBisr_ASM, ATA_portCisr_ASM, (irqIntHandler)0x0000))
    {
        API_systemErrorLoop_C(DEBUG_ERROR_CODE_SYSTEM_ERROR_EEPROM_NOT_VALID);
    }
    PORTC |= (1<<2);    // Out High as default for debug pattern pin
    
    DDRB |= (1<<0);
    PORTB &= ~(1<<0);
    

    sAppData_T *p_eep_data = (sAppData_T *)ADDRESS_EEP_DATA;
    app_data.device_id = eeprom_read_word (&p_eep_data->device_id);
    
    LED_GREEN_OFF();
    
    SWITCH_STATE(STATE_IDLE);
    
    if ( (events_power & (1<<EVENTS_POWER_NPWRON1)) && (mcusr & (1<<EXTRF)) ) {
        if ( app_data.device_id == 0xFFFF ) {
            /* Child Learn */
            SWITCH_STATE(STATE_CHILD_SENSOR_LEARN_TX_PART_REQ);
        } else {
            /* Parent Learn */
            SWITCH_STATE(STATE_PARENT_LEARN_START_RX_PART_REQ);
        }
        do {
            PINC = (1<<2);
        } while(!(PINC & 1<<PINC1));  // wait until user switch is released
        
    } else if (events_power & (1<<EVENTS_POWER_NPWRON1)) {
        SWITCH_STATE(STATE_ALARM);
    } else {
    }
    
    for(;;)
    {
        _WDR;
        GPIOR0 ^= BIT_MASK_2;   /* toggle GPIOR0.2 to indicate main loop frequency */
        
        check_reset_device_id();
        
        /*
         * Application State Machine
         */
        fpVoidFuncVoid_T func = _state_table[state];
        func();
        
        API_check4extRequests_C();
        
        if((uint16_t)flowCtrl.pLut > 0x8000)
        {
            sysFlowStateMachineFunc pFunc = *(sysFlowStateMachineFunc)flowCtrl.pLut[flowCtrl.index];
            pFunc();
        }
        else
        {
            API_systemFlowCtrl_C();
        }        

        if ( IS_IDLE_STATE() || IS_KEEP_ALIVE_STATE() || IS_LEARN_STATE() ){
            /** \todo Check for sleep mode condition */
        } else {
            API_SleepMode_C();
        }
    }
    return 0;
}

uint8_t get_num_child_sensors(void) {
    uint8_t count = 0;
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        if (app_data.child_id[i] != INVALID_SENSOR_ID) { 
            count++; 
        } else { 
            break;
        }
    }
    return count;
}
uint8_t remove_child_sensor(uint16_t id) {
    uint8_t sensor_found = FALSE;
    
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        if (app_data.child_id[i] == id) {
            // sensor found --> remove !!
            app_data.child_id[i] = INVALID_SENSOR_ID;
            sensor_found = TRUE;
        }
    }
    return sensor_found;
}

uint8_t add_child_sensor(uint16_t id) {
    uint8_t sensor_added = FALSE;
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        if (app_data.child_id[i]== INVALID_SENSOR_ID) {
            app_data.child_id[i] = id;
            sensor_added = TRUE;
            break;
        }
    }
    return sensor_added;
}

static void state_idle(void) {
    /* DO NOTHING */
    app_data.status.t4_comp_int = 0;

    rtc_init();

    APPLY_ALARM_TO_LED();
    
    SWITCH_STATE(STATE_KA_CF);
    
}
static void state_alarm(void) {
    /* Wake Up from Power Off due to button press == ALARM */
    do {
        DBG_PATTERN8(0xCC);
    } while (PINC & (1<<PINC4));   // wait for MFP of RTC == low()

    rtc_init();

    app_data.status.bmz_update = 1; // signal change
    if (app_data.status.alarm == ALARM_OFF) {
        app_data.status.alarm = ALARM_ON;
    } else {
        app_data.status.alarm = ALARM_OFF;
    }
    APPLY_ALARM_TO_LED();

    SWITCH_STATE(STATE_KA_CF);
}


static void state_verification(void) {
    /** \todo Add Implementation */
    SWITCH_STATE(STATE_ERROR);
}

static void state_status_update(void) {
    /** \todo Add Implementation */
    SWITCH_STATE(STATE_ERROR);
}

static void state_error(void) {
    PINC = 1<<2;
    for (int i=0; i<10; i++) { _NOP; }
    PINC = 1<<2;
}

