/* 
 * File:   common.h
 * Author: M43814
 *
 * Created on January 22, 2026, 8:51 AM
 */
/** \file common.h
 * Include file for module common
 */
#ifndef COMMON_H
#define	COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "ata8510_curiosity.h"
/*===========================================================================*/
/*  DEFINES  */
/*===========================================================================*/
/** function pointer definition for application state functions */
typedef void (* fpVoidFuncVoid_T)(void);

/** enumeration for application states */
typedef enum {
    /* IDLE STATE */
    STATE_IDLE, /**< Idle State, enter after Reset if the device id is valid */
    /* KEEP ALIVE STATES */
    STATE_KA_CF,    /**< Initial state of keep alive state machine */
    STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG,    /**< KA_MSG of child device received */
    STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG,   /**< Create TX_ACK message and send to child sensor */
    STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG_COMPLETE,  /**< Sending TX_ACK message completed */
    STATE_KA_CF_TX_KA_MSG,  /**< send KA_MSG */
    STATE_KA_CF_START_RX_ACK,   /**< start RF RX */
    STATE_KA_CF_RX_ACK, /**< ACK_MSG received */
    STATE_KA_CF_SLEEP,  /**< keep alive message handling completed, enter sleep mode */
    /* CHILD SENSOR LEARN STATES */
    STATE_CHILD_SENSOR_LEARN_TX_PART_REQ,   /**< Send PART_REQ command to parent device */
    STATE_CHILD_SENSOR_LEARN_START_RX_PART_REQ_RESP,    /**< Start RF Rx to receive PART_REQ_RESP */
    STATE_CHILD_SENSOR_LEARN_RX_PART_REQ_RESP, /**< PART_REQ_RESP message received, restart RF Rx */
    STATE_CHILD_SENSOR_LEARN_RX_CON_VER_STAT, /**< RX_CON_VER_STAT message received */
    STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG, /**< Create ACK_MSG and start RF Tx */
    STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG_COMPLETE,   /**< Sending TX_ACK message completed */
    /* PARENT SENSOR LEARN STATES */
    STATE_PARENT_LEARN_START_RX_PART_REQ,   /**< Start RF RX mode to receive PART_REQ message from child sensor */
    STATE_PARENT_LEARN_RX_PART_REQ,   /**< PART_REQ message received from child sensor */
    STATE_PARENT_LEARN_TX_CON_VER_REQ,   /**< Start RF TX Mode and send CON_VER_REQ message to parent sensor */
    STATE_PARENT_LEARN_START_RX_CON_VER_RESP,   /**< Start RF RX mode to receive CON_VER_RESP message from parent sensor */
    STATE_PARENT_LEARN_RX_CON_VER_RESP,   /**< CON_VER_RESP message received from parent sensor */
    STATE_PARENT_LEARN_TX_PART_REQ_RESP,   /**< Start RF TX Mode and send PART_REQ_RESP message to child sensor */
    STATE_PARENT_LEARN_TX_CON_VER_STAT,   /**< Start RF TX Mode and send CON_VER_STAT message to child sensor */
    STATE_PARENT_LEARN_START_RX_ACK_MSG,   /**< Start RF RX mode to receive ACK_MSG from child sensor */
    STATE_PARENT_LEARN_RX_ACK_MSG,   /**< ACK_MSG received from child sensor */
    STATE_PARENT_LEARN_TX_UD_MSG,   /**< Start RF TX Mode and send UD_MSG to parent sensor */
    STATE_PARENT_LEARN_START_RX_ACK_MSG_UD,   /**< Start RF RX mode to received ACK_MSG from parent sensor */
    STATE_PARENT_LEARN_RX_ACK_MSG_UD,   /**< ACK_MSG received from parent sensor */
    /* RESET DEVICE ID */
    STATE_RESET_DEVICE_ID,  /**< reset device id to remove sensor from network */
    /* VERIFICATION STATE */
    STATE_VERIFICATION, /**< verification state  */
    /* STATUS UPDATE STATE */
    STATE_STATUS_UPDATE,    /**< status update state */
    /* ALARM STATE*/
    STATE_ALARM,    /**< Alarm State */
    /* ERROR STATE */
    STATE_ERROR /**< Error State (infinite loop) */
}eState_T;


/* 
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Timer 1
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */
/** Disable Timer 1*/
#define DISABLE_TIMER1() \
{ \
    T1CR &= ~(1<<T1ENA); \
    PRR1 |=  (1<<PRT1); \
}

/** Enable Timer 1
 * - T1 Clock Select 00b - CLK_SRC 125kHz
 * - T1 Prescaler 0111b - 128 --> (1/125)*128 = 1.024ms
 */
#define ENABLE_TIMER1(val) \
{ \
    PRR1 &= ~(1<<PRT1); \
    T1CR &= ~(1<<T1ENA); \
    T1CR |=  (1<<T1RES); \
    T1COR = val; \
    T1IFR |= (1<<T1COF); \
    T1MR =  (0<< T1CS0) | \
            (0<< T1CS1) | \
            (1<< T1PS0) | \
            (1<< T1PS1) | \
            (1<< T1PS2) | \
            (0<< T1PS3) | \
            (0<< T1DC0) | \
            (0<< T1DC1);  \
    T1CR |=  (1<<T1ENA); \
}

/** Timer 1 expired check 
 * true, if expired, otherwise false
 */
#define TIMER1_EXPIRED() (T1IFR & (1<<T1COF))

/** Enable ~1s Timeout for RXing using Timer 1 */
#define ENABLE_RX_TIMEOUT(val) \
{ \
    PRR1 &= ~(1<<PRT1); \
    T1CR &= ~(1<<T1ENA); \
    T1CR |=  (1<<T1RES); \
    T1COR = (val*4); \
    T1IFR |= (1<<T1COF); \
    T1MR =  (0<< T1CS0) | \
            (0<< T1CS1) | \
            (1<< T1PS0) | \
            (1<< T1PS1) | \
            (1<< T1PS2) | \
            (1<< T1PS3) | \
            (0<< T1DC0) | \
            (0<< T1DC1);  \
    T1CR |=  (1<<T1ENA); \
}

/* 
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Timer 4
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */
/** Halt Timer4
 *  used for reading T4CNT register value
 */
#define HALT_TIMER4() \
{ \
    T4CR &= ~(1<<T4ENA); \
    while (T4CR & (1<<T4ENA)) { _NOP; } \
}

/** Run/Restart halted Timer4 
 */
#define RUN_TIMER4() \
{ \
    T4CR |= (1<<T4ENA); \
}

/** Start/Enable Timer 4 with compare interrupt enable
 * - T4 Clock Select 00b - CLK_SRC 125kHz
 * - T4 Prescaler 110b - 64 --> 0.512ms
 */
#define ENABLE_TIMER4_INT(val16) \
{ \
    PRR1 &= ~(1<<PRT4); \
    T4CR &= ~(1<<T4ENA); \
    while (T4CR & (1<<T4ENA)) { _NOP; } \
    T4CR |=  (1<<T4RES); \
    T4CR |=  (1<<T4CRM); \
    T4MRA = (1<<T4PS2) | (1<<T4PS1) | (0<<T4PS0) | (0<<T4CS1) | (0<<T4CS0); \
    T4IFR = (1<<T4ICF) | (1<<T4COF) |(1<<T4OFF); \
    T4IMR = (0<<T4CPIM) | (1<<T4CIM) | (0<<T4OIM); \
    T4COR = val16; \
    T4CR |= (1<<T4ENA); \
}

/** Enable Timer 4
 * - T4 Clock Select 00b - CLK_SRC 125kHz
 * - T4 Prescaler 110b - 64 --> (1/125)*64 = 0.512ms
 */
#define ENABLE_TIMER4(val16) \
{ \
    PRR1 &= ~(1<<PRT4); \
    T4CR &= ~(1<<T4ENA); \
    while (T4CR & (1<<T4ENA)) { _NOP; } \
    T4CR |=  (1<<T4RES); \
    T4CR |=  (1<<T4CRM); \
    T4MRA = (1<<T4PS2) | (1<<T4PS1) | (0<<T4PS0) | (0<<T4CS1) | (0<<T4CS0); \
    T4IFR = (1<<T4ICF) | (1<<T4COF) |(1<<T4OFF); \
    T4IMR = (0<<T4CPIM) | (0<<T4CIM) | (0<<T4OIM); \
    T4COR = val16; \
    T4CR |= (1<<T4ENA); \
}

/** Stop/Disable Timer 4
 */
#define DISABLE_TIMER4() \
{ \
    T4CR &= ~(1<<T4ENA); \
    while (T4CR & (1<<T4ENA)) { _NOP; } \
    PRR1 |= (1<<PRT4); \
}

/** Timer 4 expired check 
 * true, if expired, otherwise false
 */
#define TIMER4_EXPIRED() (T4IFR & (1<<T4COF))

/** Timer 4 Counter value resulting in 1 second */
#define TIMER4_VAL_1SEC     (1953)
/** Timer 4 Counter value resulting in 5 ms */
#define TIMER4_VAL_5MSEC    (10)


/** pattern to send out on PC2 for debugging */
typedef enum {
    /* IDLE STATE */
    PATTERN_STATE_IDLE = 0x10,  /**< debug pattern for ::STATE_IDLE (0x10) */
    /* KEEP ALIVE STATE */
    PATTERN_KEEP_ALIVE = 0x20,  /**< debug pattern for KEEP_ALIVE (0x20) */
    PATTERN_STATE_KA_CF = 0x20,    /**< debug pattern for ::STATE_KA_CF (0x20) */
    PATTERN_STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG,    /**< debug pattern for ::STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG (0x21) */
    PATTERN_STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG,   /**< debug pattern for ::STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG (0x22) */
    PATTERN_STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG_COMPLETE,  /**< debug pattern for ::STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG_COMPLETE (0x23) */
    PATTERN_STATE_KA_CF_TX_KA_MSG,  /**< debug state for ::STATE_KA_CF_TX_KA_MSG (0x24) */
    PATTERN_STATE_KA_CF_START_RX_ACK,   /**< debug state for ::STATE_KA_CF_START_RX_ACK (0x25) */
    PATTERN_STATE_KA_CF_RX_ACK, /**< debug state for ::STATE_KA_CF_RX_ACK (0x26) */
    PATTERN_STATE_KA_CF_SLEEP,  /**< debug state for ::STATE_KA_CF_SLEEP (0x27) */
    /* CHILD LEARN STATE */
    PATTERN_CHILD_LEARN = 0x30, /**< debug pattern for CHILD_LEARN (0x30) */
    PATTERN_STATE_CHILD_SENSOR_LEARN_TX_PART_REQ = 0x30,    /**< debug pattern for ::STATE_CHILD_SENSOR_LEARN_TX_PART_REQ (0x30) */
    PATTERN_STATE_CHILD_SENSOR_LEARN_START_RX_PART_REQ_RESP,    /**< debug pattern for ::STATE_CHILD_SENSOR_LEARN_START_RX_PART_REQ_RESP (0x31) */
    PATTERN_STATE_CHILD_SENSOR_LEARN_RX_PART_REQ_RESP,  /**< debug pattern for ::STATE_CHILD_SENSOR_LEARN_RX_PART_REQ_RESP (0x32) */
    PATTERN_STATE_CHILD_SENSOR_LEARN_RX_CON_VER_STAT,   /**< debug pattern for ::STATE_CHILD_SENSOR_LEARN_RX_CON_VER_STAT (0x33) */
    PATTERN_STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG,    /**< debug pattern for ::STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG (0x34) */
    PATTERN_STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG_COMPLETE,   /**< debug pattern for ::STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG_COMPLETE (0x35) */
    /* PARENT LEARN STATE */
    PATTERN_PARENT_LEARN = 0x40,    /**< debug pattern for PARENT_LEARN (0x40) */
    PATTERN_STATE_PARENT_LEARN_START_RX_PART_REQ = 0x40,    /**< debug pattern for ::STATE_PARENT_LEARN_START_RX_PART_REQ (0x40) */
    PATTERN_STATE_PARENT_LEARN_RX_PART_REQ, /**< debug pattern for ::STATE_PARENT_LEARN_RX_PART_REQ (0x41) */
    PATTERN_STATE_PARENT_LEARN_TX_CON_VER_REQ,  /**< debug pattern for ::STATE_PARENT_LEARN_TX_CON_VER_REQ (0x42) */
    PATTERN_STATE_PARENT_LEARN_START_RX_CON_VER_RESP,   /**< debug pattern for ::STATE_PARENT_LEARN_START_RX_CON_VER_RESP  (0x43) */
    PATTERN_STATE_PARENT_LEARN_RX_CON_VER_RESP, /**< debug pattern for ::STATE_PARENT_LEARN_RX_CON_VER_RESP (0x44) */
    PATTERN_STATE_PARENT_LEARN_TX_PART_REQ_RESP,    /**< debug pattern for ::STATE_PARENT_LEARN_TX_PART_REQ_RESP (0x45) */
    PATTERN_STATE_PARENT_LEARN_TX_CON_VER_STAT, /**< debug pattern for ::STATE_PARENT_LEARN_TX_CON_VER_STAT (0x46) */
    PATTERN_STATE_PARENT_LEARN_START_RX_ACK_MSG,    /**< debug pattern for ::STATE_PARENT_LEARN_START_RX_ACK_MSG (0x47) */
    PATTERN_STATE_PARENT_LEARN_RX_ACK_MSG,  /**< debug pattern for ::STATE_PARENT_LEARN_RX_ACK_MSG (0x48) */
    PATTERN_STATE_PARENT_LEARN_TX_UD_MSG,   /**< debug pattern for ::STATE_PARENT_LEARN_TX_UD_MSG (0x49) */
    PATTERN_STATE_PARENT_LEARN_START_RX_ACK_MSG_UD, /**< debug pattern for ::STATE_PARENT_LEARN_START_RX_ACK_MSG_UD (0x4A) */
    PATTERN_STATE_PARENT_LEARN_RX_ACK_MSG_UD,   /**< debug pattern for ::STATE_PARENT_LEARN_RX_ACK_MSG_UD (0x4B) */
    /* RESET_DEVICE ID STATE */
    PATTERN_STATE_RESET_DEVICE_ID = 0x50,   /**< debug pattern for ::STATE_RESET_DEVICE_ID (0x50) */
    /* VERIFICATION STATE */
    PATTERN_STATE_VERIFICATION = 0x60,  /**< debug pattern for ::STATE_VERIFICATION (0x60) */
    /* STATUS UPDATE STATE */
    PATTERN_STATE_STATUS_UPDATE = 0x70, /**< debug pattern for ::STATE_STATUS_UPDATE (0x70) */
    /* ALARM STATE */
    PATTERN_STATE_ALARM = 0x80, /**< debug pattern for ::STATE_ALARM (0x80) */
    /* ERROR STATE */
    PATTERN_STATE_ERROR = 0x90, /**< debug pattern for ::STATE_ERROR (0x90) */
    /* PATERN_STATE_RESET */
    PATTERN_RESET_STATE = 0xA0  /**< debug pattern for ::RESET_STATE (0xA0) */
}eDebugPattern_T;

/** Define for debug_pattern8_pc2() function 
 * Can be switched on/off application wide with this defines
 */
#define DBG_PATTERN8(pattern)  { debug_pattern8_pc2(pattern); }
// #define DBG_PATTERN8(pattern)

/** Define for debug_pattern16_pc2() function 
 * Can be switched on/off application wide with this defines
 */
#define DBG_PATTERN16(pattern)  { debug_pattern16_pc2(pattern); }
// #define DBG_PATTERN16(pattern)

/** Define to switch the application state 
 * - switches the state and
 * - sends out debug pattern
 */
#define SWITCH_STATE(var) { \
    DBG_PATTERN8(PATTERN_##var); \
    state = var; \
}
/** Checks if application is in ::STATE_IDLE 
 * true if in ::STATE_IDLE, otherwise false
 */
#define IS_IDLE_STATE() (state == STATE_IDLE)
/** Checks if application is in Keep Alive state 
 * true if in Keep Alive, otherwise false
 */
// #define IS_KEEP_ALIVE_STATE() ((state >=STATE_KEEP_ALIVE)&&(state <=(STATE_KEEP_ALIVE_SLEEP-1)))
#define IS_KEEP_ALIVE_STATE() ((state >=STATE_KA_CF)&&(state <=(PATTERN_STATE_KA_CF_SLEEP-1)))
/** Checks if application is in Parent Learn state 
 * true if in Parent Learn, otherwise false
 */
#define IS_PARENT_LEARN_STATE() ((state >=STATE_PARENT_LEARN_START_RX_PART_REQ)&&(state<=STATE_PARENT_LEARN_RX_ACK_MSG_UD))
/** Checks if application is in Child Learn state 
 * true if in Child Learn, otherwise false
 */
#define IS_CHILD_LEARN_STATE() ((state >=STATE_CHILD_SENSOR_LEARN_TX_PART_REQ)&&(state<=STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG_COMPLETE))
/** Checks if application is in Learn (Parent or Child) state 
 * true if in Learn, otherwise false
 */
#define IS_LEARN_STATE() ( IS_PARENT_LEARN_STATE() || IS_CHILD_LEARN_STATE() )
/** Checks if RF is in IDLE mode 
 * true if in IDLE mode, otherwise false
 */
#define IS_IDLE_MODE() ((trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM) == OPM_IDLE)
/** Checks if RF telegram is received 
 * true if RF telegram is received, otherwise false
 */
#define IS_TELEGRAM_RECEIVED() ( \
    (events_events & BM_EVENTS_EVENTS_WCOA ) && \
    (events_events & BM_EVENTS_EVENTS_SOTA ) && \
    (events_events & BM_EVENTS_EVENTS_EOTA ) \
)
/** Define to reset the device 
 * prints out debug pattern before reset.
 */
#define SYSTEM_RESET() { \
    DBG_PATTERN8(PATTERN_RESET_STATE); \
    API_SystemReset_C(); \
}

/** Sets Green LED according to alarm state
 * if alarm is on, LED is switched on, otherwise LED is is switched off
 */
#define APPLY_ALARM_TO_LED() \
{ \
    if ( app_data.status.alarm == ALARM_ON) { \
        LED_GREEN_ON(); \
    } else { \
        LED_GREEN_OFF(); \
    } \
}
/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/
/**
 * send out 8-bit debug pattern 'pattern' on pin PC2
 * @param pattern 8-bit pattern to send on PC2
 */
extern void debug_pattern8_pc2(uint8_t pattern);

/**
 * send out 16-bit debug pattern 'pattern' on pin PC2
 * @param pattern 16-bit pattern to send on PC2
 */
extern void debug_pattern16_pc2(uint16_t pattern);

/** 
 * switch RF system to IDLE mode 
 */
extern void set_idle_mode(void);
/**
 * switch RF system to TX mode and send out 'len' bytes starting at 'p_data'
 * @param p_data start address of data to send out
 * @param len length of data to send out
 */
extern void set_tx_mode(uint8_t *p_data, uint8_t len);
/**
 * start RF RX mode
 */
extern void set_rx_mode(void);
/**
 * get received RF telegram
 * @param p_data address to store the received data
 * @return number of bytes received
 */
extern uint8_t get_telegram(uint8_t *p_data);


#ifdef	__cplusplus
}
#endif

#endif	/* COMMON_H */

