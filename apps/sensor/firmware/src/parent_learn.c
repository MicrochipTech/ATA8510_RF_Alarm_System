/** \file parent_learn.c
 * contains 'parent_learn' state machine functions
 */
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "parent_learn.h"
#include "common.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Modul Globals                                                             */
/*===========================================================================*/
static uint16_t _learn_id;
/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/

void state_parent_sensor_learn_start_rx_part_req(void) {
    rtc_init();
    
    set_rx_mode();
    ENABLE_RX_TIMEOUT(10);
    SWITCH_STATE(STATE_PARENT_LEARN_RX_PART_REQ);
}

void state_parent_sensor_learn_rx_part_req(void) {
    if (get_telegram(tmpAryApp) ) {
        DISABLE_TIMER1();
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == PART_REQ) {
            for (int i=0; i<NUMBER_OF_SENSORS; i++){
                if (app_data.child_id[i] == INVALID_SENSOR_ID) {
                    // empty entry
                    sDeviceId_T _id = p_cmd_hdr->id;
                    _id.level = (app_data.device_id >> 12)+1;
                    _learn_id = _id.raw;
                    app_data.child_id[i] = _learn_id;
                    break;
                }
            }
            SWITCH_STATE(STATE_PARENT_LEARN_TX_CON_VER_REQ);
        } else {
            /*
             * Wrong/Unexpected Command Received
             */
            SWITCH_STATE(STATE_PARENT_LEARN_START_RX_PART_REQ);
        }
    } else if ( TIMER1_EXPIRED() ) {
        /* 
         * 10s Timeout 
         */
        DISABLE_TIMER1();    
        SWITCH_STATE(STATE_IDLE);
    } else {
        /*
         * Do Nothing
         */
    }
}

void state_parent_sensor_learn_tx_con_ver_req(void) {
    if ( IS_IDLE_MODE() ) {
        
        sCommandConVerReq_T con_ver_req = {
            .hdr = {
                .msg = CON_VER_REQ,
                .sta = {
                    .bmz_update = 0,
                    .accept_device = 0,
                    .alarm = ALARM_OFF,
                    .payload = 0,
                    .security = SECURITY_OFF,
                    .okay = 0,
                    .network = 0,
                    .battery = 0
                },
            },
            .device_id = _learn_id,
            .device_type = 0x55
        };
        con_ver_req.hdr.id.raw = app_data.device_id;
        set_tx_mode ((uint8_t *)&con_ver_req, sizeof(con_ver_req));
        
        SWITCH_STATE(STATE_PARENT_LEARN_START_RX_CON_VER_RESP);
    }    
}

void state_parent_sensor_learn_start_rx_con_ver_resp(void) {
   if ( IS_IDLE_MODE()  ) {
        set_rx_mode();
        ENABLE_RX_TIMEOUT(10);
        SWITCH_STATE(STATE_PARENT_LEARN_RX_CON_VER_RESP);
   } else  {
       /*
        * Still in TX Mode --> wait ...
        */
   }
}

void state_parent_sensor_learn_rx_con_ver_resp(void) {
    if ( get_telegram(tmpAryApp) ) {
        DISABLE_TIMER1();
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == CON_VER_RESP) {
            sCommandConVerResp_T *p = (sCommandConVerResp_T *)&tmpAryApp;
            
            if ( (p->device_id == _learn_id) && (p->hdr.sta.accept_device) ) {
                SWITCH_STATE(STATE_PARENT_LEARN_TX_PART_REQ_RESP);
            } else {
                /*
                 * Wrong Device or Device not accepted
                 */
                SWITCH_STATE(STATE_IDLE);
            }
        } else {
            /*
             * Wrong/Unexpected Command Received
             */
            SWITCH_STATE(STATE_IDLE);
        }
    }else if ( TIMER1_EXPIRED() ) {
        /* 
         * 10s Timeout 
         */
        DISABLE_TIMER1();    
        SWITCH_STATE(STATE_IDLE);
    }
}

void state_parent_sensor_learn_tx_part_req_resp(void) {
    if ( IS_IDLE_MODE() ) {
        sCommandPartReqResp_T part_req_resp = {
            .hdr = {
                .msg = PART_REQ_RESP,
                .sta = {
                    .bmz_update = 0,
                    .accept_device = 1,
                    .alarm = ALARM_OFF,
                    .payload = 0,
                    .security = SECURITY_OFF,
                    .okay = 0,
                    .network = 0,
                    .battery = 0
                },
            }
        };
        part_req_resp.hdr.id.raw = app_data.device_id;
        part_req_resp.count = (app_data.count)%10;
        
        set_tx_mode((uint8_t *)&part_req_resp, sizeof(part_req_resp));
        SWITCH_STATE(STATE_PARENT_LEARN_TX_CON_VER_STAT);
        
        ENABLE_TIMER1(10); // 10ms timer
        
    }    
}

void state_parent_sensor_learn_tx_con_ver_stat(void){
    if ( IS_IDLE_MODE() &&
         ( TIMER1_EXPIRED() )
        ) {
        DISABLE_TIMER1();
        
        sCommandConVerSta_T con_ver_sta = {
            .hdr = {
                .msg = CON_VER_STA,
                .sta = {
                    .bmz_update = 0,
                    .accept_device = 0,
                    .alarm = ALARM_OFF,
                    .payload = 0,
                    .security = SECURITY_OFF,
                    .okay = 0,
                    .network = 0,
                    .battery = 0
                },
            },
            .status = 0xAABB
        };
        con_ver_sta.hdr.id.raw = app_data.device_id;
        
        set_tx_mode((uint8_t *)&con_ver_sta, sizeof(con_ver_sta));
        SWITCH_STATE(STATE_PARENT_LEARN_START_RX_ACK_MSG);
    } else {
        // still in tx or waiting mode, wait...
    }
}

void state_parent_sensor_learn_start_rx_ack_msg(void){
    if ( IS_IDLE_MODE() ) {
        set_rx_mode();
        ENABLE_RX_TIMEOUT(1);
        SWITCH_STATE(STATE_PARENT_LEARN_RX_ACK_MSG);
    } else {
        // still in tx mode, wait ...
    }
}

void state_parent_sensor_learn_rx_ack_msg(void) {
    if ( get_telegram(tmpAryApp) ) {
        DISABLE_TIMER1();
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == ACK_MSG) {
            /** \todo Decode Content */
            // --NO-NEED-TO-UPDATE-- eeprom_write_word(&p_eep_data->device_id, ids.device_id);
            // --NO-NEED-TO-UPDATE-- eeprom_write_word(&p_eep_data->parent_id, ids.parent_id);
            add_child_sensor(_learn_id);
            rtc_write_sram(
                    RTC_SRAM_APP_DATA_CHILD_ID, 
                    (uint8_t *)&app_data.child_id, 
                    sizeof(app_data.child_id)
                    );
            SWITCH_STATE(STATE_PARENT_LEARN_TX_UD_MSG);
        } else {
            // wrong command received
            SWITCH_STATE(STATE_ERROR);
        }
    } else if ( TIMER1_EXPIRED() ) {
        /* Timeout */
        DISABLE_TIMER1();    
        SWITCH_STATE(STATE_IDLE);
    } else {
        // do nothing
    }
}

void state_parent_sensor_learn_tx_ud_msg(void) {
    if ( IS_IDLE_MODE() ) {
        sCommandUdMsg_T ud_msg = {
            .hdr = {
                .msg = UD_MSG,
                .sta = {
                    .bmz_update = 0,
                    .accept_device = 0,
                    .alarm = ALARM_OFF,
                    .payload = 0,
                    .security = SECURITY_OFF,
                    .okay = 0,
                    .network = 0,
                    .battery = 0
                }
            },
            .length = 5,
            .id = UD_ID_NEW_CHILD,
            .new_child = {
                .parent_id = app_data.device_id,
                .child_id = _learn_id
            }
        };
        ud_msg.hdr.id.raw = app_data.device_id;
        set_tx_mode( (uint8_t *)&ud_msg, sizeof(ud_msg));
        SWITCH_STATE(STATE_PARENT_LEARN_START_RX_ACK_MSG_UD);
    } else {
        /*
         * Do Nothing --> still wait..
         */
    }
}
void state_parent_sensor_learn_start_rx_ack_msg_ud(void) {
    if ( IS_IDLE_MODE() ) {
        set_rx_mode();
        ENABLE_RX_TIMEOUT(1);
        SWITCH_STATE(STATE_PARENT_LEARN_RX_ACK_MSG_UD);
    } else {
        // still in tx mode, wait ...
    }
}
void state_parent_sensor_learn_rx_ack_msg_ud(void) {
    if ( get_telegram(tmpAryApp) ) {
        DISABLE_TIMER1();
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == ACK_MSG) {

            ENABLE_TIMER4_INT(2000); // ~1s
            while(app_data.status.t4_comp_int == 0);

            SWITCH_STATE(STATE_IDLE);
        } else {
            // wrong command received
            SWITCH_STATE(STATE_ERROR);
        }
    } else if ( TIMER1_EXPIRED() ) {
        /* Timeout */
        DISABLE_TIMER1();    
        SWITCH_STATE(STATE_IDLE);
    } else {
        // do nothing
    }
}

void check_reset_device_id(void) { 
    if ( IS_LEARN_STATE() && (!(PINC & 1<<PINC1)) ) {
        SWITCH_STATE(STATE_RESET_DEVICE_ID);
    }
}

void state_reset_device_id(void) {
    sAppData_T *p_eep_fac_data = (sAppData_T *)ADDRESS_EEP_FAC_DATA;
    eeprom_read_block (&app_data, p_eep_fac_data, sizeof(sAppData_T));

    rtc_write_app_data();

    sAppData_T *p_eep_data = (sAppData_T *)ADDRESS_EEP_DATA;
    eeprom_write_word(&p_eep_data->device_id, app_data.device_id);

    while(!(PINC & 1<<PINC1));
    SWITCH_STATE(STATE_IDLE);
}
