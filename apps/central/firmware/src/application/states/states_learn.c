/* ************************************************************************** */
/** Descriptive File Name

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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "states.h"
#include "../command/command.h"
#include "../rf/rf.h"

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

static void _STATE_LearnTimeout(uintptr_t context) { 
    SYS_TIME_TimerStop(app_data.timer_timeout);
    STATE_SwitchState(STATE_LEARN_FAIL);
    
    /* TODO: Add Implementation */ 
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */



void STATE_Learn(sMSG_T *p_msg) {
    /*
     * Start Timeout Timer for Learn State (10 seconds )
     */
    app_data.timer_timeout = SYS_TIME_TimerCreate(
            0, 
            SYS_TIME_MSToCount(10*1000),
            &_STATE_LearnTimeout, 
            (uintptr_t) NULL,
            SYS_TIME_SINGLE
            );
    SYS_TIME_TimerStart(app_data.timer_timeout);
    
    /*
     * Set ATA8510 System Mode (RX buffered, Service 0, Channel 0, Path A)
     */
    RF_SetRxModeBuffered();
    
    STATE_SwitchState(STATE_LEARN_RX_PART_REQ);
}

void STATE_LearnRxPartReq(sMSG_T *p_msg) { 
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if (rf_data.events.system.sys_err == 1) {
            SYS_TIME_TimerStop(app_data.timer_timeout);
            RF_GetDebug();

            STATE_SwitchState(STATE_LEARN_FAIL);
        } else {
            if ( rf_data.events.events.eota == 1 ) {
                uint8_t len = RF_ATA8510_SPI_ReadFillLevelRxFifo();
                uint8_t data[32]= {0};
                RF_ATA8510_SPI_ReadRxFifo(len,data);
                
                sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)data;
                if (p_cmd_hdr->msg == PART_REQ) {
                    
                    sCommandPartReq_T *p_part_req = (sCommandPartReq_T *)data;
                    app_data.candidate_device_id = p_part_req->hdr.id;
                    STATE_SwitchState(STATE_LEARN_TX_PART_REQ_RESP);
                } else {
                    RF_SetRxModeBuffered();
                }
            }
        }
    }    
}

void STATE_LearnTxPartReqResp(sMSG_T *p_msg) { 
    /*
     * Set ATA8510 System Mode (RX buffered, Service 0, Channel 0, Path A)
     */
    sCommandPartReqResp_T resp = {
        .hdr = {
            .id = app_data.device_id,
            .msg = PART_REQ_RESP,
            .sta = {
                .bmz_update = 0,
                .accept_device = 0,
                .clear_blocked_list = 0,
                .payload = 0,
                .security = 0,  // TODO: define SECURITY_OFF/SECURITY_ON
                .okay = 0,
                .network = 0,
                .battery = 0,
            },
        },
    };

    RF_SetTxModeBuffered(sizeof(resp), (uint8_t *)&resp);

    STATE_SwitchState(STATE_LEARN_TX_PART_REQ_RESP_COMPLETE);
}

void STATE_LearnTxPartReqRespComplete(sMSG_T *p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        //  TODO: Check for system error !!!
        if ( rf_data.events.events.eota == 1 ) {
            APPLICATION_DelayUs(500);
            STATE_SwitchState(STATE_LEARN_TX_CON_VER_STAT);
            
        }
    }
}

void STATE_LearnTxConVerStat(sMSG_T* p_msg) {
    sCommandConVerSta_T con_ver_sta = {
        .hdr = {
            .id = app_data.device_id,
            .msg = CON_VER_STA,
            .sta = {
                .bmz_update = 0,
                .accept_device = 0,
                .clear_blocked_list = 0,
                .payload = 0,
                .security = 0,  // TODO: define SECURITY_OFF/SECURITY_ON
                .okay = 0,
                .network = 0,
                .battery = 0,
            },
        },
        .status.raw = 0xABCD,
    };

    RF_SetTxModeBuffered(sizeof(con_ver_sta), (uint8_t *)&con_ver_sta);
    
    STATE_SwitchState(STATE_LEARN_TX_CON_VER_STAT_COMPLETE);
    // TODO: ADD Implementation
}

void STATE_LearnTxConVerStatComplete(sMSG_T* p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        //  TODO: Check for system error !!!
        if ( rf_data.events.events.eota == 1 ) {
            RF_SetRxModeBuffered();
            STATE_SwitchState(STATE_LEARN_RX_ACK_MSG);
        }
        // TODO: ADD Implementation
    }
}

void STATE_LearnRxAckMsg(sMSG_T* p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if ( rf_data.events.events.eota == 1 ) {
            uint8_t len = RF_ATA8510_SPI_ReadFillLevelRxFifo();
            uint8_t data[32]= {0};
            RF_ATA8510_SPI_ReadRxFifo(len,data);

            sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)data;
            if (p_cmd_hdr->msg == ACK_MSG) {
                STATE_SwitchState(STATE_LEARN_PASS);
            } else {
                RF_SetRxModeBuffered();
            }
        }
    }    
    // TODO: ADD Implementation
}

void STATE_LearnPass(sMSG_T *p_msg) { 
    app_data.candidate_device_id.level = 1;
    if ( APPLICATION_GetSensor(app_data.candidate_device_id) == NULL) {
        APPLICATION_AddSensor(app_data.candidate_device_id);
    }
    SYS_TIME_TimerStop(app_data.timer_timeout);
    STATE_SwitchState(STATE_IDLE);
}

void STATE_LearnFail(sMSG_T *p_msg) { 
    /*
     * Set ATA8510 System Mode to Idle Mode(RC)
     */
    RF_SetIdleMode();

    STATE_SwitchState(STATE_IDLE);
}

/* *****************************************************************************
 End of File
 */
