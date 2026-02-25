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


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */


void STATE_ConnectionVerificationTxConVerResp(sMSG_T* p_msg) {

    sCommandConVerResp_T resp = {
        .hdr = {
            .id = app_data.device_id,
            .msg = CON_VER_RESP,
            .sta = {
                .bmz_update = 0,
                .accept_device = 1,
                .clear_blocked_list = 0,
                .payload = 0,
                .security = 0,  // TODO: define SECURITY_OFF/SECURITY_ON
                .okay = 0,
                .network = 0,
                .battery = 0,
            },
        },
        .device_id = app_data.con_ver_device_id
    };

    RF_SetTxModeBuffered(sizeof(resp), (uint8_t *)&resp);
    // EXT2_GPIO1_Clear();
    STATE_SwitchState(STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE);    
}

void STATE_ConnectionVerificationTxConVerRespComplete(sMSG_T* p_msg){
    if (p_msg->id == MSG_ID_RF_IRQ) {
        //  TODO: Check for system error !!!
        if ( rf_data.events.events.eota == 1 ) {
            // EXT2_GPIO1_Clear();
            STATE_SwitchState(STATE_IDLE);
        }
    }
}


/* *****************************************************************************
 End of File
 */
