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

/** \file states_keep_alive.c
 * functions for keep alive state machine.
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


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */
/** create and send keep alive TX_ACK message
 * entered after KA_MSG received
 * \param p_msg message to be handled
 * 
@startuml state_keep_alive_tx_ack
start
    - create ACK_MSG message
    - measure time difference between slot and current time
    - correct keep alive offset
    - correct keep alive interval
    - start TX Mode 
    #APPLICATION: --> STATE_KEEP_ALIVE_TX_ACK_COMPLETE;
stop
@enduml
 */
void STATE_KeepAliveTxAck(sMsg_T *p_msg) {
    // send ack msg in correct slot
    int slot = APPLICATION_GetSensorSlot(app_data.ka_device_id);
    
    sSensor_T *p = APPLICATION_GetSensor(app_data.ka_device_id);
    
    sCommandAckKaMsg_T ack_ka = {
        .hdr = {
            .id = app_data.device_id,
            .msg = ACK_MSG,
            .sta = 
            {
                .bmz_update = p->status.bmz_update,
                .accept_device = 0,
                .alarm = app_data.alarm,
                .payload = 0,
                .security = SECURITY_OFF,
                .okay = 0,
                .network = 0,
                .battery = 0,
            },
        },
        .correction_offset = 0,
        .correction_interval = 0,
    };
    
    uint32_t time_stamp_1 = SYS_TIME_CounterGet();
    uint32_t time_ms = SYS_TIME_CountToMS(time_stamp_1 - app_data.slot_time_stamp[slot]);

    ack_ka.correction_offset = (int16_t)time_ms;
    ack_ka.correction_interval = 0;
    
    RF_SetTxModeBuffered(sizeof(ack_ka), (uint8_t *)&ack_ka);
    STATE_SwitchState(STATE_KEEP_ALIVE_TX_ACK_COMPLETE, true);
}

/** ACK_MSG transmission completed
 * \param p_msg message to be handled
 * 
@startuml state_keep_alive_tx_ack_complete
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
void STATE_KeepAliveTxAckComplete(sMsg_T *p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if (rf_data.events.system.sys_err == 1) {
            SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nSYS_ERROR");
            RF_GetDebug();
        } else if ( rf_data.events.events.eota == 1 ) {
            // EXT2_GPIO1_Clear();
            STATE_SwitchState(STATE_IDLE, false);
        }
    }
}


/* *****************************************************************************
 End of File
 */
