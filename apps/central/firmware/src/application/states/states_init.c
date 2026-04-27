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

/** \file states_init.c
 * function for initialization state machines.
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
/** Init state of state machine
 * \param p_msg message to be handled
 * 
@startuml state_init
start
    - create & start status timer (1s)
    - create & start slot timer (200ms)
    - Reset ATA8510
    #APPLICATION: --> STATE_WAIT_RF_SYS_RDY;
stop
@enduml
 */
void STATE_Init(sMsg_T *p_msg) {
    /* Create Message Queue */
    app_data.cnt = 0;
    app_data.timer_status = SYS_TIME_TimerCreate(
            0, 
            SYS_TIME_MSToCount(1*1000), // 1s
            &APPLICATION_StatusTimer, 
            (uintptr_t) NULL,
            SYS_TIME_PERIODIC
            );
    SYS_TIME_TimerStart(app_data.timer_status);

    app_data.timer_sensor_slot = SYS_TIME_TimerCreate(
        0, 
        SYS_TIME_MSToCount(200),    // 200ms    5 slots in 1s -> 200ms each
        &APPLICATION_SensorSlotTimer, 
        (uintptr_t) NULL,
        SYS_TIME_PERIODIC
    );
    SYS_TIME_TimerStart(app_data.timer_sensor_slot);
    
    app_data.device_id.raw = INVALID_SENSOR_ID;
    app_data.candidate_device_id.raw = INVALID_SENSOR_ID;
    app_data.button_pressed_at_reset = !SWITCH_Get();

    RF_Reset();
    
    STATE_SwitchState(STATE_WAIT_RF_SYS_RDY, true);
    
}

/** wait until ATA8510 is ready
 * \param p_msg message to be handled
 * 
@startuml state_wait_rf_sys_rdy
start
if (RF_IRQ == 1) then (yes)
    if (RF.EVENTS.SYS_RDY == 1) then (yes)
        - generate device_id
        if (Button Pressed @ Reset) then (yes)
            #APPLICATION: --> STATE_LEARN;
        else
            #APPLICATION: --> STATE_IDLE;
        endif
    endif
endif
stop
@enduml
 */
void STATE_WaitRfSysRdy(sMsg_T *p_msg) {
    if (p_msg->id == MSG_ID_RF_IRQ) {
        if (rf_data.events.system.sys_rdy == 1) {
            app_data.device_id.raw = INVALID_SENSOR_ID;
            for (int i=0; i<12; i++){
                app_data.device_id.raw += RF_ATA8510_SPI_ReadEeprom(0x0410 + i);
                APPLICATION_DelayUs(100);
            }
            app_data.service_channel_config = RF_ATA8510_SPI_ReadEeprom(0x02A0);
            
            app_data.device_id.level = 0;
            if (app_data.button_pressed_at_reset == true) {
                STATE_SwitchState(STATE_LEARN, true);
            } else {
                STATE_SwitchState(STATE_IDLE, true);
                APPLICATION_SendStatus();
            }
        } else {
        }
    }
}



/* *****************************************************************************
 End of File
 */
