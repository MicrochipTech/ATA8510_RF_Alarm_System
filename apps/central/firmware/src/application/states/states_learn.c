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

/** \file states_learn.c
 * function for learn state machine.
 */

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
/** timer callback function entered when timeout during learn occured
 * - stop timeout timer and
 * - switch to state ::STATE_LEARN_FAIL
 * @param[in] context not used
 */
static void _STATE_LearnTimeout(uintptr_t context) { 
    SYS_TIME_TimerStop(app_data.timer_timeout);
    STATE_SwitchState(STATE_LEARN_FAIL, true);
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */


/** Initial learn state function
 * \param p_msg message to be handled
 * 
@startuml state_learn
start
    - create and start timeout timer (10s expiration time)
    - set RX Mode
    #APPLICATION: --> START_LEARN_RX_PART_REQ;
stop
@enduml
 */
void STATE_Learn(sMsg_T *p_msg) {
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
    
    STATE_SwitchState(STATE_LEARN_RX_PART_REQ, true);
}

/** Wait for PART_REQ message
 * \param p_msg message to be handled
 *
@startuml state_learn_rx_part_req
start
if (RF_IRQ == 1) then (yes)
    if (RF.EVENTS.SYS_ERR == 1) then (yes)
        - stop timeout timer
        - readout debug information
        #APPLICATION: --> STATE_LEARN_FAIL;
    else
        if (RF.EVENTS.EOTA == 1) then (yes)
            - read received message
            if (msg.id == PART_REQ) then (yes)
                - store candidate device id
                #APPLICATION: --> STATE_LEARN_TX_PART_REQ_RESP;
            else
                - Reset RX Mode
                note : unknown command received
            endif
        endif
    endif
endif
stop
@enduml
 */
void STATE_LearnRxPartReq(sMsg_T *p_msg) { 
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if (rf_data.events.system.sys_err == 1) {
            SYS_TIME_TimerStop(app_data.timer_timeout);
            RF_GetDebug();

            STATE_SwitchState(STATE_LEARN_FAIL, true);
        } else {
            if ( rf_data.events.events.eota == 1 ) {
                uint8_t len = RF_ATA8510_SPI_ReadFillLevelRxFifo();
                uint8_t data[32]= {0};
                RF_ATA8510_SPI_ReadRxFifo(len,data);
                
                sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)data;
                if (p_cmd_hdr->msg == PART_REQ) {
                    
                    sCommandPartReq_T *p_part_req = (sCommandPartReq_T *)data;
                    app_data.candidate_device_id = p_part_req->hdr.id;
                    STATE_SwitchState(STATE_LEARN_TX_PART_REQ_RESP, true);
                } else {
                    RF_SetRxModeBuffered();
                }
            }
        }
    }    
}

/** Sends PART_REQ_RESP command to the device.
 * \param p_msg message to be handled
 *
@startuml state_learn_tx_part_req_resp
start
    - create PART_REQ_RESP message
    - start TX Mode
    #APPLICATION: --> STATE_LEARN_TX_PART_REQ_RESP_COMPLETE;
stop
@enduml 
 */
void STATE_LearnTxPartReqResp(sMsg_T *p_msg) { 
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
                .alarm = ALARM_OFF,
                .payload = 0,
                .security = SECURITY_OFF,
                .okay = 0,
                .network = 0,
                .battery = 0,
            },
        },
        .count = 0,
    };

    RF_SetTxModeBuffered(sizeof(resp), (uint8_t *)&resp);

    STATE_SwitchState(STATE_LEARN_TX_PART_REQ_RESP_COMPLETE, true);
}

/** Transmission of PART_REQ_RESP command complete
 * \param p_msg message to be handled
 * 
@startuml state_learn_tx_part_req_resp_complete
start
if (RF_IRQ == 1) then (yes)
    if (RF.EVENTS.SYS_ERR == 1) then (yes)
        - read out debug information
    elseif (RF.EVENTS.EOTA == 1) then (yes)
        - wait 500us
        #APPLICATION: --> STATE_LEARN_TX_CON_VER_STAT;
    endif
endif
stop
@enduml
 */
void STATE_LearnTxPartReqRespComplete(sMsg_T *p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if (rf_data.events.system.sys_err == 1) {
            SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nSYS_ERROR");
            RF_GetDebug();
        } else if ( rf_data.events.events.eota == 1 ) {
            APPLICATION_DelayUs(500);
            STATE_SwitchState(STATE_LEARN_TX_CON_VER_STAT, true);
            
        }
    }
}

/** Sends CON_VER_STA command to the device.
 * \param p_msg message to be handled
 *
@startuml state_learn_tx_con_ver_stat
start
    - create CON_VER_STA message
    - start TX Mode
    #APPLICATION: --> STATE_LEARN_TX_CON_VER_STAT_COMPLETE;
stop
@enduml 
 */
void STATE_LearnTxConVerStat(sMsg_T* p_msg) {
    sCommandConVerSta_T con_ver_sta = {
        .hdr = {
            .id = app_data.device_id,
            .msg = CON_VER_STA,
            .sta = {
                .bmz_update = 0,
                .accept_device = 0,
                .alarm = ALARM_OFF,
                .payload = 0,
                .security = SECURITY_OFF,
                .okay = 0,
                .network = 0,
                .battery = 0,
            },
        },
        .status = 0xABCD,
    };

    RF_SetTxModeBuffered(sizeof(con_ver_sta), (uint8_t *)&con_ver_sta);
    
    STATE_SwitchState(STATE_LEARN_TX_CON_VER_STAT_COMPLETE, true);
}

/** Transmission of CON_VER_STAT command complete
 * \param p_msg message to be handled
 * 
@startuml state_learn_tx_con_ver_stat_complete
start
if (RF_IRQ == 1) then (yes)
    if (RF.EVENTS.SYS_ERR == 1) then (yes)
        - read out debug information
    elseif (RF.EVENTS.EOTA == 1) then (yes)
        - Set RF RX Mode
        #APPLICATION: --> STATE_LEARN_RX_ACK_MSG;
    endif
endif
stop
@enduml
 */
void STATE_LearnTxConVerStatComplete(sMsg_T* p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if (rf_data.events.system.sys_err == 1) {
            SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nSYS_ERROR");
            RF_GetDebug();
        } else if ( rf_data.events.events.eota == 1 ) {
            RF_SetRxModeBuffered();
            STATE_SwitchState(STATE_LEARN_RX_ACK_MSG, true);
        }
    }
}

/** Wait for ACK_MSG received
 * \param p_msg message to be handled
 * 
@startuml state_learn_rx_ack_msg
start
if (RF_IRQ == 1) then (yes)
    - read message
    if (msg.id == ACK_MSG) then (yes)
        #APPLICATION: --> state STATE_LEARN_PASS;
    else
        - Set RX Mode 
        note right : invalid command received
    endif
endif
stop
@enduml
 */
void STATE_LearnRxAckMsg(sMsg_T* p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if ( rf_data.events.events.eota == 1 ) {
            uint8_t len = RF_ATA8510_SPI_ReadFillLevelRxFifo();
            uint8_t data[32]= {0};
            RF_ATA8510_SPI_ReadRxFifo(len,data);

            sCommandHeader_T *p_cmd_hdr = (sCommandHeader_T *)data;
            if (p_cmd_hdr->msg == ACK_MSG) {
                STATE_SwitchState(STATE_LEARN_PASS, true);
            } else {
                RF_SetRxModeBuffered();
            }
        }
    }    
}

/** learning passed
 * \param p_msg message to be handled
 * 
@startuml state_learn_pass
start
if (sensor not in sensor_list) then (yes)
    - add sensor to sensor_list
endif
- stop timeout timer
#APPLICATION: --> STATE_IDLE;
stop
@enduml
 */
void STATE_LearnPass(sMsg_T *p_msg) { 
    app_data.candidate_device_id.level = 1;
    if ( APPLICATION_GetSensor(app_data.candidate_device_id) == NULL) {
        APPLICATION_AddSensor(app_data.candidate_device_id);
    }
    SYS_TIME_TimerStop(app_data.timer_timeout);
    STATE_SwitchState(STATE_IDLE, true);
    
    APPLICATION_SendStatus();
}

/** learning failed
 * \param p_msg message to be handled
 * 
@startuml
start
- set RF Idle Mode
#APPLICATION: --> STATE_IDLE;
stop
@enduml
 */
void STATE_LearnFail(sMsg_T *p_msg) { 
    /*
     * Set ATA8510 System Mode to Idle Mode(RC)
     */
    RF_SetIdleMode();

    STATE_SwitchState(STATE_IDLE, true);
}

/* *****************************************************************************
 End of File
 */
