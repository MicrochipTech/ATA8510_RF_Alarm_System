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

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Module Globals                                                             */
/*===========================================================================*/
uint16_t rx_window;  /**< contains RX active time needed for KA_MSG processing with child sensors */
int16_t correction_offset;   /**< correction value for Timer4 to synchronize KA_MSG processing (information send with 'ACK_KA_MSG' message) */
int16_t correction_interval; /**< correction value for Timer4 to synchronize KA_MSG processing (information send with 'ACK_KA_MSG' message) */
/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/**
@startuml state_keep_alive
start
: Start Timer 4;
note right: Configure Timer 4 (interrupt enable, timeout @ 1s) 
: Initialize local variables;
#Orange : SWITCH_STATE(STATE_KEEP_ALIVE_TX_KA_MSG);
stop
@enduml
 */
void state_keep_alive(void) {
    ENABLE_TIMER4_INT(TIMER4_VAL_1SEC + app_data.ka_interval_correction);
    rx_window = 0;
    correction_offset = 0;
    correction_interval = 0;
    SWITCH_STATE(STATE_KEEP_ALIVE_TX_KA_MSG);
}

/**
@startuml state_keep_alive_tx_ka_msg
start
: Create KA_MSG;
: Set TX Mode;
#Orange : SWITCH_STATE(STATE_KEEP_ALIVE_START_RX_ACK);
stop
@enduml
 */
void state_keep_alive_tx_ka_msg(void) {
    sCommandKeepAlive_T keep_alive = {
        .hdr = {
            .msg = KA_MSG,
            .sta = {
                .bmz_update = 0,
                .accept_device = 0,
                .clear_blocked_list = 0,
                .payload = 0,
                .security = 0,
                .okay = 0,
                .network = 0,
                .battery = 0
            },
        }
    };
    keep_alive.hdr.id.raw = app_data.device_id;
    
    set_tx_mode((uint8_t *)&keep_alive, sizeof(keep_alive));
    
    SWITCH_STATE(STATE_KEEP_ALIVE_START_RX_ACK);
}
/**
@startuml state_keep_alive_start_rx_ack
start
if (IS_IDLE_MODE()?) then (yes)
    : LED_GREEN_TOGGLE();
    : Set RX Mode;
    #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_RX_ACK);
    ' : Start 200ms timeout;
else
    : Still in TX Mode, wait...;
endif
stop
@enduml
 */

void state_keep_alive_start_rx_ack(void) {
   if ( IS_IDLE_MODE() ) {
        LED_GREEN_TOGGLE();
        
        set_rx_mode();
        SWITCH_STATE(STATE_KEEP_ALIVE_RX_ACK);
        // start 200ms timer for timeout
        // ENABLE_TIMER1(200); 
   } else {
       // still in tx mode, wait ...
   }
}

/** 
@startuml state_keep_alive_rx_ack
start
if (Telegram Received?) then (yes)
    : LED_GREEN_TOGGLE();
    ' : Disable Timer;
    if (msg == ACK_MSG) then (yes)
        if (msg.device_id == parent_id) then (yes)
            : correction_offset = msg.correction_offset;
            : correction_interval = msg.correction_interval;
            if (has_child_sensors) then (yes)
                : rx_window = T4CNT;
                note right : Start RX window measurement for KA_MSG from child sensor
                : Set RX Mode;
                #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_RX_KA_MSG);
            else
                #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_SLEEP);
            endif
        else
            #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_START_RX_ACK);
        endif
    else
        #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_START_RX_ACK);
    endif
elseif (1s timeout occured?) then (yes)
    : Start 200ms Timer;
    : Wait until Timer is expired;
    #Orange : SYSTEM_RESET();
else
    : Still in RX Mode, wait...;
endif
stop
@enduml
 */
void state_keep_alive_rx_ack(void) {
    if (get_telegram(tmpAryApp)) {
        LED_GREEN_TOGGLE();
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == ACK_MSG) {
            sCommandAckKaMsg_T *p = (sCommandAckKaMsg_T *)&tmpAryApp;
            if (p->hdr.id.raw == app_data.parent_id ) {

                correction_offset = p->correction_offset;
                if (correction_offset != 0) {
                    uint16_t val = TIMER4_VAL_1SEC + app_data.ka_interval_correction + correction_offset;
                    HALT_TIMER4();
                    val = val - T4CNT;  // remaining time
                    DISABLE_TIMER4();
                    
                    debug_pattern16_pc2(val);
                    ENABLE_TIMER4_INT(val);
                }                
                correction_interval = p->correction_interval;
                if (correction_interval != 0) {

                    app_data.ka_interval_correction += correction_interval;
                    sAppData_T *p_eep_data = (sAppData_T *)ADDRESS_EEP_DATA;

                    eeprom_write_word((uint16_t *)&p_eep_data->ka_interval_correction, app_data.ka_interval_correction);    // ~10ms
                }
                
                
                if (get_num_child_sensors()> 0) {
                    HALT_TIMER4();
                    rx_window = T4CNT;  // time between start of rx mode and telegram  (*0.512us)                
                    RUN_TIMER4();

                    set_rx_mode();
                    SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_RX_KA_MSG);
                } else {
                    SWITCH_STATE(STATE_KEEP_ALIVE_SLEEP);
                }
            } else {
                SWITCH_STATE(STATE_KEEP_ALIVE_START_RX_ACK);
            }
        } else {
            // wrong command received
            SWITCH_STATE(STATE_KEEP_ALIVE_START_RX_ACK);
        }
    } else if ( status.t4_comp_int) {
#if false
        DISABLE_TIMER1();
        ENABLE_TIMER1(200);
        while ( !TIMER1_EXPIRED() );
#endif
        SYSTEM_RESET();
    } else {
    }
}

/**
@startuml state_keep_alive_process_child_rx_ka_msg
start
if (Telegram Received?) then (yes)
    if (msg == ACK_MSG) then (yes)
        if (message.device_id in child_sensors()) then (yes)
            : remove child sensor from list;
            : rx_window = T4CNT - rx_window;
            note right : Stop RX window measurement for KA_MSG from child sensor
            #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_TX_ACK_MSG);
        else
            : Set RX Mode;
            #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_RX_KA_MSG);

        endif
    elseif (1s timeout occured?) then (yes)
        : Start 200ms Timer;
        : Wait until Timer is expired;
        #Orange : SYSTEM_RESET();
    else
        : Set RX Mode;
        #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_RX_KA_MSG);
    endif
else
endif
stop
@enduml
 */
void state_keep_alive_process_child_rx_ka_msg(void) {
    if (get_telegram(tmpAryApp)) {
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == KA_MSG) {
            sCommandKeepAlive_T *p = (sCommandKeepAlive_T *)&tmpAryApp;
            uint16_t id = p->hdr.id.raw;
            if ( remove_child_sensor(id) == TRUE ) {
                // child sensor removed from sensor list
                HALT_TIMER4();
                rx_window = T4CNT - rx_window;
                RUN_TIMER4()

                SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_TX_ACK_MSG);
            } else {
                // child sensor not found in sensor list --> send no ack
                set_rx_mode();
                SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_RX_KA_MSG);
            }
        } else {
            // wrong command received
            set_rx_mode();
            SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_RX_KA_MSG);
        }
    } else if ( status.t4_comp_int) {
#if false
        DISABLE_TIMER1();
        ENABLE_TIMER1(200);
        while ( !TIMER1_EXPIRED() );
#endif
        SYSTEM_RESET();
    } else {
    }
}

/**
@startuml state_keep_alive_process_child_tx_ack_msg
start
if (IS_IDLE_MODE()?) then (yes)
    : Create ACK_MSG;
    note right : msg.device_id = app_data.device_id
    : msg.correction_offset = correction_offset;
    note right : forward correction_offset from parent to child
    : msg.correction_interval = correction_interval;
    note right : forward correction_interval from parent to child

    if (rx_window > 40 ms) then (yes)
        :msg.correction_interval -= 5ms;
    endif
    if (rx_window < 20 ms) then (yes)
        :msg.correction_offset += 15ms;
        :msg.correction_interval += 15ms;
    endif
    : Set TX Mode;
    #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_TX_ACK_MSG_COMPLETE);
else
endif
stop
@enduml
 */
void state_keep_alive_process_child_tx_ack_msg(void) {
    if ( IS_IDLE_MODE()  ) {
        sCommandAckKaMsg_T ack_msg = {
            .hdr = {
                .msg = ACK_MSG,
                .sta = {
                    .bmz_update = 0,
                    .accept_device = 0,
                    .clear_blocked_list = 0,
                    .payload = 0,
                    .security = 0,
                    .okay = 0,
                    .network = 0,
                    .battery = 0
                },
            }
        };
        ack_msg.hdr.id.raw = app_data.device_id;
        ack_msg.correction_offset = correction_offset;
        ack_msg.correction_interval = correction_interval;

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
        
        set_tx_mode((uint8_t *)&ack_msg, sizeof(ack_msg));
        SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_TX_ACK_MSG_COMPLETE);
    }
}
/**
@startuml state_keep_alive_process_child_tx_ack_msg_complete
start
if (IS_IDLE_MODE()?) then (yes)
    if (has_child_sensors) then (yes)
        : Set RX Mode;
        #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_RX_KA_MSG);
    else
        #Orange : SWITCH_STATE(STATE_KEEP_ALIVE_SLEEP);
    endif
else
endif
stop
@enduml
 */
void state_keep_alive_process_child_tx_ack_msg_complete(void) {
    if ( IS_IDLE_MODE()  ) {
        if (get_num_child_sensors() > 0) {
            set_rx_mode();
            SWITCH_STATE(STATE_KEEP_ALIVE_PROCESS_CHILD_RX_KA_MSG);
        } else {
            SWITCH_STATE(STATE_KEEP_ALIVE_SLEEP);
        }
    } else {
    }
}

/**
@startuml state_keep_alive_sleep
start
if (correction_interval != 0) then (yes) 
    : eep_data.ka_interval_correction += correction_interval;
    note : save correction interval in EEPROM for next KA_MSG cycle
    : apply interval to current cycle;
else
endif

if (correction_offset != 0) then (yes)
    : apply offset t current cycle;
else
endif

: Enable Pin Change Interrupt for PC1 to wake up in alarm case;
repeat
    : Enter Sleep Mode;
    if (ALARM Button Pressed?) then (yes)
        #Orange : SWITCH_STATE(STATE_ALARM);
        stop
    else
    endif
repeat while (Timer4 expired?) is (no) not (yes)
#Orange : SYSTEM_RESET();
stop
@enduml
 */
void state_keep_alive_sleep(void) {
#if false
    if (correction_interval != 0) {

        app_data.ka_interval_correction += correction_interval;
        sAppData_T *p_eep_data = (sAppData_T *)ADDRESS_EEP_DATA;

        eeprom_write_word((uint16_t *)&p_eep_data->ka_interval_correction, app_data.ka_interval_correction);    // ~10ms

        // HALT_TIMER4();
        // T4COR = TIMER4_VAL_1SEC + app_data.ka_interval_correction;
        // RUN_TIMER4();

    }
#endif
#if false
    if (correction_offset != 0) {
        
        HALT_TIMER4();
        val = val - T4COR;  // remaining time
        DISABLE_TIMER4();
        ENABLE_TIMER4_INT(val + correction_offset);

    }
#endif
    
    /* Enable Pin Change Interrupt for PC1 to wake up in alarm case */
    PCMSK1 |= ( 1 << PCINT9);
    PCICR |= ( 1 << PCIE1);
    do {
        /* Enter Sleep Mode  */
        API_SleepMode_C();

        if ( ( PINC & (1 << PINC1) ) == 0) {
            /* Wake Up from Sleep due to button press == ALARM */
            SWITCH_STATE(STATE_ALARM);
            return;
        }
    } while(status.t4_comp_int == 0);  // to avoid wrong wakeups

    /* DO NOTHING --> Switch device to off mode (wake up from RTC) */
    // API_OffCommand_C();  /** \todo Replace SystemReset by OFF */
    SYSTEM_RESET();
}
