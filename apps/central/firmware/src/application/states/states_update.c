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

/** \file states_update.c
 * functions for update state machine.
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
/** Creates ACK_MSG and sends it out
 * next state: ::STATE_UPDATE_TX_ACK_COMPLETE
 * \param p_msg message to be handled
 */
void STATE_UpdateTxAck(sMsg_T* p_msg) {
    sCommandAckMsg_T ack = {
        .hdr = {
            .id = app_data.device_id,
            .msg = ACK_MSG,
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
    };

    RF_SetTxModeBuffered(sizeof(ack), (uint8_t *)&ack);
    // EXT2_GPIO1_Clear();
    STATE_SwitchState(STATE_UPDATE_TX_ACK_COMPLETE, true);
}

/** ACK_MSG transmission finished.
 * \param p_msg message to be handled
 * 
 */
void STATE_UpdateTxAckComplete(sMsg_T* p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if (rf_data.events.system.sys_err == 1) {
            SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nSYS_ERROR");
            RF_GetDebug();
        } else if ( rf_data.events.events.eota == 1 ) {
            // EXT2_GPIO1_Clear();
            STATE_SwitchState(STATE_IDLE, true);
        }
        APPLICATION_SendStatus();
    }
}

/* *****************************************************************************
 End of File
 */
