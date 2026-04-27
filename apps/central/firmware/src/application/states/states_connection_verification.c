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

/** \file states_connection_verification.c
 * functions for connection verification state machine
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


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/** create and send CON_VER_RESP message
 * \param p_msg message to be handled
 * 
@startuml state_connection_verification_tx_con_ver_resp
start
   - Create CON_VER_RESP message
   - Set TX Mode
   #APPLICATION: --> STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE;
stop
@enduml
 */
void STATE_ConnectionVerificationTxConVerResp(sMsg_T* p_msg) {

    sCommandConVerResp_T resp = {
        .hdr = {
            .id = app_data.device_id,
            .msg = CON_VER_RESP,
            .sta = {
                .bmz_update = 0,
                .accept_device = 1,
                .alarm = ALARM_OFF,
                .payload = 0,
                .security = SECURITY_OFF,
                .okay = 0,
                .network = 0,
                .battery = 0,
            },
        },
        .device_id = app_data.con_ver_device_id
    };

    RF_SetTxModeBuffered(sizeof(resp), (uint8_t *)&resp);
    // EXT2_GPIO1_Clear();
    STATE_SwitchState(STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE, true);    
}

/** CON_VER_RESP command transmission complete
 * \param p_msg message to be handled
 * 
@startuml
start
if (RF_IRQ == 1) then (yes)
    if (RF.EVENTS.SYS_ERR == 1) then (yes)
        - read out debug information
    elseif (RF.EVENTS.EOTA == 1) then (yes)
        #APPLICATION: --> STATE_IDLE;
    endif
endif
stop
@enduml
 */
void STATE_ConnectionVerificationTxConVerRespComplete(sMsg_T* p_msg){
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if (rf_data.events.system.sys_err == 1) {
            SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nSYS_ERROR");
            RF_GetDebug();
        } else if ( rf_data.events.events.eota == 1 ) {
            // EXT2_GPIO1_Clear();
            STATE_SwitchState(STATE_IDLE, true);
        }
    }
}


/* *****************************************************************************
 End of File
 */
