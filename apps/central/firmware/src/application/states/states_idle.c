/* ************************************************************************** */
/* Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/** \file states_idle.c
 * functions for idle state machine.
 */
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "states.h"
#include "../command/command.h"
#include "../rf/rf.h"
#include "../test/test.h"
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

static void _STATE_StartLearnCentral(void) {
    RF_SetIdleMode();
    STATE_SwitchState(STATE_LEARN, true);
}

static void _STATE_SendStatus(void) {
    char msg[80] = {0};
    size_t offset = 0;
    offset += sprintf(msg+offset,"%04X",app_data.device_id.raw);
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        uint16_t id = sensor_array[i].id.raw;
        uint8_t status =  sensor_array[i].status.raw;
        if (id != INVALID_SENSOR_ID) {
            offset += sprintf(msg+offset,";[%04X,%02X]",id,status);
        }
    }
    SYS_CONSOLE_PRINT("%%%08X;%s%%\r\n",app_data.cnt++,msg);
}


static void _STATE_KeepAliveMsgRcvd(uint8_t *p_data) {
    sCommandKeepAlive_T *p = (sCommandKeepAlive_T *)p_data;
    sSensor_T *p_sens = APPLICATION_GetSensor(p->hdr.id);

    if (p_sens != NULL ) {
        
        p_sens->status.alarm = p->hdr.sta.alarm;    // update status
        
        if (p->hdr.sta.bmz_update == 1) {
            for (int i=0; i<NUMBER_OF_SENSORS; i++) {
                if (sensor_array[i].id.raw != INVALID_SENSOR_ID) {
                    if (sensor_array[i].id.raw == p->hdr.id.raw) {
                        sensor_array[i].status.bmz_update = 0;
                    } else {
                        sensor_array[i].status.bmz_update = 1;
                    }
                }
            }    
            app_data.alarm = p_sens->status.alarm;
            if (app_data.alarm == true ) {
                SYS_CONSOLE_MESSAGE("ALARM ON\r\n");
            } else {
                SYS_CONSOLE_MESSAGE("ALARM OFF\r\n");
            }
        }
        
        if (app_data.alarm == 1) {
            LED_On();
        } else {
            LED_Off();
        }

        app_data.ka_device_id = p->hdr.id;
        STATE_SwitchState(STATE_KEEP_ALIVE_TX_ACK, true);
        
    } else {
        // unknown KA_MSG received --> Restart RX
        RF_SetRxModeBuffered();
    }
}

static void _STATE_ConnectionVerificationRequestMsgRcvd(uint8_t *p_data) {
    sCommandConVerReq_T *p = (sCommandConVerReq_T *)p_data;
    app_data.con_ver_device_id = p->device_id;
    app_data.con_ver_device_type = p->device_type;
    /** \todo Add Implementation -- add to sensor map */
    STATE_SwitchState(STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP, true);
}

static void _STATE_UpdateMsgRcvd(uint8_t *p_data) {
    // sCommandUpdate_T *p = (sCommandUpdate_T *)p_data;
    /** \todo Add Implementation - decode content */
    STATE_SwitchState(STATE_UPDATE_TX_ACK, true);
}

static void _STATE_RfIrq(void) {
    if ( rf_data.events.events.eota == 1 ) {
        uint8_t len = RF_ATA8510_SPI_ReadFillLevelRxFifo();
        uint8_t data[32]= {0};
        RF_ATA8510_SPI_ReadRxFifo(len,data);

        sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)data;
        if ( p_cmd_hdr->msg == KA_MSG ) {
            _STATE_KeepAliveMsgRcvd(data);
        } else if (p_cmd_hdr->msg == CON_VER_REQ) {
            _STATE_ConnectionVerificationRequestMsgRcvd(data);
        } else if (p_cmd_hdr->msg == UD_MSG) {
            _STATE_UpdateMsgRcvd(data);
        } else {
            SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nUnsupported command\r\n");
            /*
             * Restart RX Mode if wrong/unexpected command is received
             */
            if (RF_IsRxMode() == false) {
                RF_SetRxModeBuffered();
            }

        }
    }
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */
/** Idle state
 * \param p_msg message to be handled
 * 
@startuml state_idle
start
switch (msg.id)
    case (MSG_ID_CONSOLE_CMD_START_LEARN_CENTRAL)
        - Start Learn
    case (MSG_ID_CONSOLE_CMD_VERIFY)
        - TODO: ADD IMPLEMENTATION
        - Set Idle Mode
    case (MSG_ID_SEND_STATUS)
        - Send Status 
    case (MSG_ID_RF_IRQ)
        - Handle RF
    case (default)
        if (is RF RX Mode?) then (no)
            - Restart RX Mode
        endif
endswitch
stop
@enduml
*/

void STATE_Idle(sMsg_T *p_msg) {

    switch ( p_msg->id ) {
        case MSG_ID_CONSOLE_CMD_START_LEARN_CENTRAL: {
            _STATE_StartLearnCentral();
            break;
        }
        case MSG_ID_CONSOLE_CMD_START_LEARN_SENSOR: { 
            break; 
        }
        case MSG_ID_CONSOLE_CMD_VERIFY: { 
            RF_SetIdleMode();
            break; 
        }
        case MSG_ID_SEND_STATUS: {
            _STATE_SendStatus();
            break;
        }
        case MSG_ID_RF_IRQ: {
            _STATE_RfIrq();
            break;
        }
        default: {
            if (RF_IsRxMode() == false) {
                RF_SetRxModeBuffered(); // Restart RX Mode
            }
            break;
        }
    }
}



/* *****************************************************************************
 End of File
 */
