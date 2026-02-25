/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "alarm.h"
#include "common.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Modul Globals                                                             */
/*===========================================================================*/

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/

void state_alarm(void) {
    sCommandAlMsg_T al = {
        .hdr = {
            .msg = AL_MSG,
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
    al.hdr.id.raw = app_data.device_id;

    set_tx_mode((uint8_t *)&al, sizeof(al));
    SWITCH_STATE(STATE_ALARM_START_RX_ACK_MSG);
    
}

void state_alarm_start_rx_ack_msg(void) {
    if ( IS_IDLE_MODE() ) {

        ENABLE_TIMER1(100);
        
        set_rx_mode();
        SWITCH_STATE(STATE_ALARM_RX_ACK_MSG);
    } else {
       // still in tx mode, wait ...
    }
}

void state_alarm_rx_ack_msg(void) {
    if (get_telegram(tmpAryApp)) {
        DISABLE_TIMER1();
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
            if (p_cmd_hdr->msg == ACK_MSG) {
                SWITCH_STATE(STATE_IDLE);
            } else {
                // wrong command received --> send alarm again
                SWITCH_STATE(STATE_ALARM);
            }
    } else if ( TIMER1_EXPIRED() ) {
        /* Timeout */
        DISABLE_TIMER1();
        set_idle_mode();
        SWITCH_STATE(STATE_ALARM);
    } else {
    }    
}