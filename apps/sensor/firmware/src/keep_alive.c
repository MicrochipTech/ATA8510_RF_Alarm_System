/** \file keep_alive.c

@startuml keep_alive_implementation
title KEEP ALIVE IMPLEMENTATION
start
: start Timer 0 for 1s interval;
if (child sensors?) then (yes)
    group "Process Child Sensors" {
        repeat 
            : start RX;
            note right : Check for KA_MSG of child device
            : start TX;
            note right : Send ACK_MSG to child device
            : remove sensor from sensor list;
        repeat while (child sensors?) is (yes) not (no)
    }
endif
: start TX;
note right : Send KA_MSG to parent device
: start RX;
note right :  Wait for ACK_MSG from parent device
: enter Sleep mode until Timer 0 elapses;
stop
@enduml

*/

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "keep_alive.h"
#include "common.h"
#include "rtc.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Module Globals                                                             */
/*===========================================================================*/
#if 0 /* correction */
uint16_t rx_window;  /**< contains RX active time needed for KA_MSG processing with child sensors */
int16_t correction_offset;   /**< correction value for Timer4 to synchronize KA_MSG processing (information send with 'ACK_KA_MSG' message) */
int16_t correction_interval; /**< correction value for Timer4 to synchronize KA_MSG processing (information send with 'ACK_KA_MSG' message) */
#endif

/**
 * Keep Alive Update control data
 * indicates flags if update is triggered from parent device, child device, or own device
 */
union uKeepAliveUpdate {
    struct {
    uint8_t from_parent : 1;  /** Bit 0: update triggered from parent device */
    uint8_t from_child : 1;  /** Bit 1: update triggered from child device */
    uint8_t from_own : 1;  /** Bit 2: update triggered by button press on own device */
    uint8_t rfu_bit3 : 1;  /** Bit 3: reserved for future use */
    uint8_t rfu_bit4 : 1;  /** Bit 4: reserved for future use */
    uint8_t rfu_bit5 : 1;  /** Bit 5: reserved for future use */
    uint8_t rfu_bit6 : 1;  /** Bit 6: reserved for future use */
    uint8_t rfu_bit7 : 1;  /** Bit 7: reserved for future use */
    };
    uint8_t raw;    /**< update byte */
}keep_alive_update; /**< contains keep alive update control data */
/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/** store alarm in EEPROM */
static void _state_keep_alive_store_status(void) {
    uStatus_T status;
    status.raw = 0;
#if 0 /* correction */
    status.apply_correction = app_data.status.apply_correction;
#endif
    status.bmz_update = app_data.status.bmz_update;
    status.alarm = app_data.status.alarm;
    rtc_write_sram(
            RTC_SRAM_APP_DATA_STATUS, 
            &status.raw, 
            sizeof(app_data.status)
            );
}

/*
 * -----------------------------------------------------------------------------
 * -----------------------------------------------------------------------------
 * KEEP ALIVE CHILD FIRST STATE MACHINE IMPLEMENTATION
 * -----------------------------------------------------------------------------
 * -----------------------------------------------------------------------------
 */


void state_ka_cf(void) {
#if 0 /* correction */
    rx_window = 0;
    correction_offset = app_data.offset;
    correction_interval = app_data.interval;
#endif
    keep_alive_update.from_parent = 0;
    keep_alive_update.from_child = 0;
    keep_alive_update.from_own = app_data.status.bmz_update;
    
    // STATE_KA_CF --> STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG
    if (get_num_child_sensors()> 0) {
        set_rx_mode();        
        SWITCH_STATE(STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG);
    } else {
        SWITCH_STATE(STATE_KA_CF_TX_KA_MSG);
    }
}

void state_ka_cf_process_child_rx_ka_msg(void) {
    if (get_telegram(tmpAryApp)) {
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;

        if (p_cmd_hdr->msg == KA_MSG) {
            sCommandKeepAlive_T *p = (sCommandKeepAlive_T *)&tmpAryApp;
            uint16_t id = p->hdr.id.raw;
            if ( remove_child_sensor(id) == TRUE ) {
                // child sensor removed from sensor list
#if 0 /* correction */
                HALT_TIMER4();
                rx_window = T4CNT - rx_window;
                RUN_TIMER4();
#endif
                if (p->hdr.sta.bmz_update == 1) {
                    keep_alive_update.from_child = 1;
                    app_data.status.bmz_update = p->hdr.sta.bmz_update;
                    app_data.status.alarm = p->hdr.sta.alarm;
                }

                // STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG --> STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG
                SWITCH_STATE(STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG);
                
            } else {
                // child sensor not found in sensor list --> send no ack
                set_rx_mode();
                SWITCH_STATE(STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG);
            }
        } else {
            // wrong command received
            set_rx_mode();
            SWITCH_STATE(STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG);
        }
    } else if ( app_data.status.t4_comp_int) {
        SWITCH_STATE(STATE_IDLE);
    } else {
    }
}

void state_ka_cf_process_child_tx_ack_msg(void) {
    if ( IS_IDLE_MODE()  ) {
        sCommandAckKaMsg_T ack_msg = {
            .hdr = {
                .msg = ACK_MSG,
                .sta = {
                    .bmz_update = 0,
                    .accept_device = 0,
                    .alarm = 0,
                    .payload = 0,
                    .security = SECURITY_OFF,
                    .okay = 0,
                    .network = 0,
                    .battery = 0
                },
            }
        };
        ack_msg.hdr.id.raw = app_data.device_id;

        if ( (keep_alive_update.from_own == 1)      ||
             (keep_alive_update.from_parent == 1)   ||
             (keep_alive_update.from_child == 1)
           ) {
            ack_msg.hdr.sta.bmz_update = 1;
            ack_msg.hdr.sta.alarm = app_data.status.alarm;
        }
        
        ack_msg.correction_offset = 0/*correction_offset*/;
        ack_msg.correction_interval = 0/*correction_interval*/;
        
#if 0 /* correction */
        if (rx_window >= app_data.rx_window_upper_threshold/*200*/ ) {
            ack_msg.correction_offset -= (rx_window - app_data.correction_offset_up/*40*/);
            ack_msg.correction_interval -= app_data.correction_interval_up;
        }
        else if ((rx_window < app_data.rx_window_upper_threshold/*200*/) && (rx_window > app_data.rx_window_lower_threshold/*80*/)) { 
            ack_msg.correction_offset -= app_data.correction_offset_mid/*10*/;
            ack_msg.correction_interval -= app_data.correction_interval_mid/*10*/;
        }
        else if (rx_window <= app_data.rx_window_lower_threshold/*80*/) { 
            ack_msg.correction_offset += app_data.correction_offset_low/*40*/;
            ack_msg.correction_interval += app_data.correction_interval_low/*10*/;
        } else {
        }
#endif
        
        set_tx_mode((uint8_t *)&ack_msg, sizeof(ack_msg));
        // STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG --> STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG_COMPLETE
        SWITCH_STATE(STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG_COMPLETE);
    }
}

void state_ka_cf_process_child_tx_ack_msg_complete(void) {
    if ( IS_IDLE_MODE()  ) {
        if (get_num_child_sensors() > 0) {
            set_rx_mode();
            SWITCH_STATE(STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG);
        } else {
            // STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG_COMPLETE --> STATE_KA_CF_TX_KA_MSG
            SWITCH_STATE(STATE_KA_CF_TX_KA_MSG);
        }
    } else {
    }
}

void state_ka_cf_tx_ka_msg(void) {
    sCommandKeepAlive_T keep_alive = {
        .hdr = {
            .msg = KA_MSG,
            .sta = {
                .bmz_update = keep_alive_update.from_own,   // forward to parent device
                .accept_device = 0,
                .alarm = app_data.status.alarm,
                .payload = 0,
                .security = SECURITY_OFF,
                .okay = 0,
                .network = 0,
                .battery = 0
            },
        }
    };
    keep_alive.hdr.id.raw = app_data.device_id;
    
    set_tx_mode((uint8_t *)&keep_alive, sizeof(keep_alive));
    
    // STATE_KA_CF_TX_KA_MSG --> STATE_KA_CF_START_RX_ACK
    SWITCH_STATE(STATE_KA_CF_START_RX_ACK);
}

void state_ka_cf_start_rx_ack(void) {
    if ( IS_IDLE_MODE() ) {
        set_rx_mode();
        // STATE_KA_CF_START_RX_ACK --> STATE_KA_CF_RX_ACK
        SWITCH_STATE(STATE_KA_CF_RX_ACK);
    } else {
        // still in tx mode, wait ...
    }
}

void state_ka_cf_rx_ack(void) {
    if (get_telegram(tmpAryApp)) {

        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == ACK_MSG) {
            sCommandAckKaMsg_T *p = (sCommandAckKaMsg_T *)&tmpAryApp;
            if (p->hdr.id.raw == app_data.parent_id ) {
                if (p->hdr.sta.bmz_update == 1) {
                    /* 
                     * parent signals bmz_update, apply to app_data and update childs 
                     */
                    keep_alive_update.from_parent = 1;
                    app_data.status.bmz_update = p->hdr.sta.bmz_update;
                    app_data.status.alarm = p->hdr.sta.alarm;
                    APPLY_ALARM_TO_LED();
                    
                }
#if 0 /* correction */
                correction_offset = p->correction_offset;   // correction offset from parent
                correction_interval = p->correction_interval;   // correction interval from parent
                if (correction_offset > 100) {
                    uint16_t val = app_data.ka_interval - (2 * correction_offset) - 20 /* ~10ms */;
                    ENABLE_TIMER4_INT(val);
                    while(app_data.status.t4_comp_int == 0);
                    SWITCH_STATE(STATE_IDLE);
                    return;
                }
#endif
                // STATE_KA_CF_RX_ACK --> STATE_KA_CF_SLEEP
                SWITCH_STATE(STATE_KA_CF_SLEEP);
            } else {
                SWITCH_STATE(STATE_KA_CF_START_RX_ACK);
            }
        } else {
            // wrong command received
            SWITCH_STATE(STATE_KA_CF_START_RX_ACK);
        }
    } else if ( app_data.status.t4_comp_int) {
        SWITCH_STATE(STATE_IDLE);
    } else {
    }
}

void state_ka_cf_sleep(void) {
    
    // DBG_PATTERN8(app_data.status.raw);
    
    if ( (keep_alive_update.from_own == 1) || 
         (keep_alive_update.from_parent == 1)
    ) {
        app_data.status.bmz_update = 0;
    }
    
    if (keep_alive_update.from_child == 1) {
        app_data.status.bmz_update = 1;
    }
    _state_keep_alive_store_status();
    
    app_data.count = (app_data.count+1)%10;
    if (app_data.count == 0) {
        for (int i=0;i<100;i++) {
            debug_pattern8_pc2(0xAA);
            debug_pattern8_pc2(0x55);
        }
    }
    rtc_write_sram(
            RTC_SRAM_APP_DATA_COUNT,
            (uint8_t *)&app_data.count,
            sizeof(app_data.count));

#if 0 /* correction */
    if (app_data.status.apply_correction) {
        app_data.status.apply_correction = 0;
    } else {
        app_data.status.apply_correction = 1;
        app_data.offset = correction_offset;
        app_data.interval = correction_interval;
        rtc_write_sram(
                RTC_SRAM_APP_DATA_OFFSET, 
                (uint8_t *)&app_data.offset, 
                sizeof(app_data.offset)
                );
        rtc_write_sram(
                RTC_SRAM_APP_DATA_INTERVAL, 
                (uint8_t *)&app_data.interval, 
                sizeof(app_data.interval)
                );
    }
#endif

    if (app_data.status.alarm == ALARM_OFF) {
        MCUCR |= (1<<ENPS);
        DDRC |= (1<<2);    // Out High as default for debug pattern pin
        PORTC |= (1<<2);    // Out High as default for debug pattern pin

        API_OffCommand_C();

        for (;;) {
            _NOP;
        }
    } else {
        // ALARM IS ON!!! --> DO NOT ENTER OFF MODE (ENTER SLEEP INSTEAD)
        /* Enable Pin Change Interrupt for PC1 to wake up in alarm case */
        PCMSK1 |= ( 1 << PCINT9);   // PC1  
        PCMSK1 |= ( 1 << PCINT12);  // PC4

        PCICR |= ( 1 << PCIE1);
        
        do {
            API_SleepMode_C();
            if ( ( PINC & (1 << PINC1) ) == 0) {
                /* Wake Up from Sleep due to button press == ALARM */
                app_data.status.bmz_update = 1; // signal change
                app_data.status.alarm = ALARM_OFF;
                _state_keep_alive_store_status(); 
            }
        } while(PINC & (1<<PINC4));   // wait for MFP of RTC == low
        SWITCH_STATE(STATE_IDLE);
    }

}
