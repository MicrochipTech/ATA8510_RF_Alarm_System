/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "child_learn.h"
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

void state_child_sensor_learn_tx_part_req(void) {
    if ( IS_IDLE_MODE()  ) {
        rtc_init();

        /* generate device_id from production data content starting at 
         * eeprom address 0x410
         */
        app_data.device_id = 0;
        for (int i=0; i<12; i++) {
            app_data.device_id += eeprom_read_byte((const uint8_t *)(0x0410 + i));
        }
        app_data.device_id &= 0x0FFF;

        sCommandPartReq_T part_req = {
            .hdr = {
                .msg = PART_REQ,
                .sta = {
                    .bmz_update = 0,
                    .accept_device = 0,
                    .alarm = ALARM_OFF,
                    .payload = 1,
                    .security = SECURITY_OFF,
                    .okay = 0,
                    .network = 0,
                    .battery = 0
                },
            },
            .device_type = 0xAA
        };
        part_req.hdr.id.raw = app_data.device_id;

        set_tx_mode((uint8_t *)&part_req, sizeof(part_req));
        SWITCH_STATE(STATE_CHILD_SENSOR_LEARN_START_RX_PART_REQ_RESP);
    }
}

void state_child_sensor_learn_start_rx_part_req_resp(void) {
   if ( IS_IDLE_MODE()  ) {
        set_rx_mode();
        ENABLE_RX_TIMEOUT(1);
        SWITCH_STATE(STATE_CHILD_SENSOR_LEARN_RX_PART_REQ_RESP);
   } else {
       // still in tx mode, wait ...
   }
}

void state_child_sensor_learn_rx_part_req_resp(void) {
    if (get_telegram(tmpAryApp)) {
        DISABLE_TIMER1();
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == PART_REQ_RESP) {
            sCommandPartReqResp_T *p = (sCommandPartReqResp_T *)&tmpAryApp;
            app_data.parent_id = p->hdr.id.raw;
            app_data.count = p->count;
            rtc_write_sram(
                    RTC_SRAM_APP_DATA_COUNT,
                    (uint8_t *)&app_data.count,
                    sizeof(app_data.count));
            // app_data.parent_id = p_cmd_hdr->id.raw;

            // update device id
            uint16_t level = (app_data.parent_id >> 12)+1;
            app_data.device_id &= ~(0xF000);
            app_data.device_id |= (level << 12);

            set_rx_mode();

            ENABLE_RX_TIMEOUT(10);
            SWITCH_STATE(STATE_CHILD_SENSOR_LEARN_RX_CON_VER_STAT);
        } else {
            // wrong command received
            SWITCH_STATE(STATE_CHILD_SENSOR_LEARN_START_RX_PART_REQ_RESP);
        }
    } else if ( TIMER1_EXPIRED() ) {
        /* Timeout */
        DISABLE_TIMER1();
        SWITCH_STATE(STATE_IDLE);
    } else {
        // do nothing
    }
}

void state_child_sensor_learn_rx_con_ver_stat(void) {
    if ( get_telegram(tmpAryApp) ) {
        DISABLE_TIMER1();
        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)&tmpAryApp;
        if (p_cmd_hdr->msg == CON_VER_STA) {
            /** \todo Decode Content */
            SWITCH_STATE(STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG);
        } else {
            // wrong command received
            SWITCH_STATE(STATE_IDLE);
        }
    } else if ( TIMER1_EXPIRED() ) {
        /* Timeout */
        DISABLE_TIMER1(); 
        SWITCH_STATE(STATE_IDLE);
    } else {
        // do nothing
    }
}     

void state_child_sensor_learn_tx_ack_msg(void) {
    if ( IS_IDLE_MODE()  ) {
        sCommandAckMsg_T ack_msg = {
            .hdr = {
                .msg = ACK_MSG,
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
            }
        };
        ack_msg.hdr.id.raw = app_data.device_id;
        
        set_tx_mode((uint8_t *)&ack_msg, sizeof(ack_msg));
        SWITCH_STATE(STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG_COMPLETE);
    }
}  

void state_child_sensor_learn_tx_ack_msg_complete(void) {
    if ( IS_IDLE_MODE()  ) {
        rtc_write_sram(
                RTC_SRAM_APP_DATA_DEVICE_ID, 
                (uint8_t *)&app_data.device_id, 
                sizeof(app_data.device_id)
                );
        
        sAppData_T *p_eep_data = (sAppData_T *)ADDRESS_EEP_DATA;
        eeprom_write_word(&p_eep_data->device_id, app_data.device_id);
        
        rtc_write_sram(
                RTC_SRAM_APP_DATA_PARENT_ID, 
                (uint8_t *)&app_data.parent_id, 
                sizeof(app_data.parent_id)
                );
        
                        
        ENABLE_TIMER4_INT(2200);
        while(app_data.status.t4_comp_int == 0);
        
        SWITCH_STATE(STATE_IDLE);
        
    } else {
        // still in tx mode, wait ...
    }
}
