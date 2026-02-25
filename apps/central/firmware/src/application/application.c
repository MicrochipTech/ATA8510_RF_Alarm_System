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

/** \file application.c
 * central device of ATA8510 Alarm Systems application
 */
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "application.h"
#include "console/console.h"
#include "command/command.h"
#include "rf/rf.h"
#include "states/states.h"
#include "test/test.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

sAPPLICATION_T app_data;
sSensor_T sensor_array[NUMBER_OF_SENSORS];

/** Assertion for application debugging */
#define APPLICATION_ASSERT(test,fmt, ...) { \
    SYS_DEBUG_PRINT(SYS_ERROR_DEBUG, "\r\n[APPLICATION_ASSERT] %s(..) : ",__func__); \
    SYS_DEBUG_PRINT(SYS_ERROR_DEBUG, fmt, ##__VA_ARGS__); \
}

/** Define for the CPU clock frequency in MHz */
#define CPU_CLOCK_FREQUENCY_IN_MHZ (CPU_CLOCK_FREQUENCY / 1000000)

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */
sSensor_T *APPLICATION_GetSensor(sDeviceId_T id) {
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        if (sensor_array[i].id.raw == id.raw) {
            return &sensor_array[i];
        }
    }
    APPLICATION_ASSERT(p_sens != NULL, "Unknown Sensor");
    return NULL;
}

int8_t APPLICATION_GetSensorSlot(sDeviceId_T id) {
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        if (sensor_array[i].id.raw == id.raw) {
            return i;
        }
    }
    return -1;
}

sSensor_T *APPLICATION_AddSensor(sDeviceId_T id) { 
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        if (sensor_array[i].id.raw == INVALID_SENSOR_ID) {
            sensor_array[i].id.raw = id.raw;
            sensor_array[i].status.raw = 0x00;
            return &sensor_array[i];
        }
    }    
    return NULL;
}

uint8_t APPLICATION_GetNumberOfSensors(void) {
    uint8_t number_of_sensors = 0;
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        if (sensor_array[i].id.raw != INVALID_SENSOR_ID) {
            number_of_sensors++;
        }
    }
    return number_of_sensors;
}
           
void APPLICATION_StatusTimer(uintptr_t context) { 
    sMSG_T msg;
    msg.id = MSG_ID_SEND_STATUS;
    xQueueSend(app_data.msg_queue, &msg, 0);     
}

// --GW-- volatile bool do_sync = false;
// --GW-- volatile uint8_t slot = 0;

void APPLICATION_SensorSlotTimer(uintptr_t context) {

    app_data.sensor_slot++;
    app_data.sensor_slot %= NUMBER_OF_SENSORS;

    if (app_data.state == STATE_KEEP_ALIVE_TX_ACK ){
        sMSG_T msg;
        msg.id = MSG_ID_SENSOR_SLOT_TIMER;
        xQueueSend(app_data.msg_queue, &msg, 0);     
    }

    if (app_data.sensor_slot == 0) {
        EXT2_GPIO2_Set();
    } else {
        EXT2_GPIO2_Clear();
        EXT2_GPIO2_Set();
        APPLICATION_DelayUs(100);
        EXT2_GPIO2_Clear();
        
    }
    
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */
void APPLICATION_Initialize(void)
{
    app_data.msg_queue = xQueueCreate(MSG_QUEUE_SIZE, sizeof(sMSG_T));

    /* command initialize */
    COMMAND_Initialize();
    
    /* console interface */
    CONSOLE_Initialize();

    RF_Initialize();
    
    TEST_Initialize();
    
    STATES_Initialize();
    /* init sensors */
    for (int i=0; i<NUMBER_OF_SENSORS; i++) {
        sensor_array[i].id.raw = INVALID_SENSOR_ID;
    }
   
    /* TODO: Add Implementation */
}

void APPLICATION_Tasks(void)
{
    sMSG_T msg;
    if ( xQueueReceive(app_data.msg_queue, &msg, (TickType_t)0) ) {
        RF_Tasks(&msg);
        
        COMMAND_Tasks(&msg);
        
        CONSOLE_Tasks(&msg);
        
        TEST_Tasks(&msg);
        
        STATES_Tasks(&msg);
    }
}

void *APPLICATION_GetFunction(uint32_t id, const sFuncPair_T *p_func_table, size_t size) {
    for (int i=0; i<size; i++) {
        if ( id == p_func_table[i].id ) {
            return p_func_table[i].func;
        }
    }
    return NULL;
}

const char *APPLICATION_GetMsg(uint32_t id, const sMsgPair_T *p_msg_table, size_t size) {
    for (int i=0; i<size; i++) {
        if ( id == p_msg_table[i].id ) {
            return p_msg_table[i].msg;
        }
    }
    return NULL;
}

/*
 * Delay Functions
 */
void APPLICATION_DelayUs(uint32_t delay_us) {
    uint32_t count = delay_us * CPU_CLOCK_FREQUENCY_IN_MHZ / 5;
    for (uint32_t i=0;i<count;i++){__NOP();}
}

void APPLICATION_DelayMs(uint32_t delay_ms) {
    for (uint32_t i=0;i<delay_ms;i++) {
        APPLICATION_DelayUs(1000);
    }
}

/** FreeRTOS Hook function */
void vApplicationDaemonTaskStartupHook() 
{
    /* see line 758 in apps\001_central\src\third_party\rtos\FreeRTOS\Source\timers.c */
}

/* *****************************************************************************
 End of File
 */
