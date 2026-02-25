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

void STATE_KeepAliveTxAck(sMSG_T *p_msg) {
    // send ack msg in correct slot
    int slot = APPLICATION_GetSensorSlot(app_data.ka_device_id);
    sCommandAckKaMsg_T ack_ka = {
        .hdr = {
            .id = app_data.device_id,
            .msg = ACK_MSG,
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
        .correction_offset = 0,
        .correction_interval = 0,
    };
    
    if ( app_data.sensor_slot == slot ) {
        ack_ka.correction_offset = 0;
        ack_ka.correction_interval = 0;
    } else if (app_data.sensor_slot == ((slot + 1)%NUMBER_OF_SENSORS )) {
        ack_ka.correction_offset = -200; // reduce sleep time of sensor by 100ms for 1 interval cycle
        ack_ka.correction_interval = -10; // reduce sleep time by 5ms for following cycles
    } else if (app_data.sensor_slot == ((slot + 2)%NUMBER_OF_SENSORS )) {
        ack_ka.correction_offset = -600; // reduce sleep time of sensor by 300ms for 1 interval cycle
        ack_ka.correction_interval = -10; // reduce sleep time by 5ms for following cycles
    } else if (app_data.sensor_slot == ((slot + 3)%NUMBER_OF_SENSORS )) {
        ack_ka.correction_offset = 600; // extend sleep time of sensor by 300ms for 1 interval cycle
        ack_ka.correction_interval = 10; // extend sleep time by 5ms for following cycles
    } else if (app_data.sensor_slot == ((slot + 4)%NUMBER_OF_SENSORS )) {
        ack_ka.correction_offset = 200; // extend sleep time by 100 ms for 1 interval cycle
        ack_ka.correction_interval = 10; // extend sleep time by 5ms for following cycles
    } else {
    }

    RF_SetTxModeBuffered(sizeof(ack_ka), (uint8_t *)&ack_ka);
    STATE_SwitchState(STATE_KEEP_ALIVE_TX_ACK_COMPLETE);
}

void STATE_KeepAliveTxAckComplete(sMSG_T *p_msg) {
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
