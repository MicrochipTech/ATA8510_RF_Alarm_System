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
/** \file test.c
 * contains test implementation of the application
 */
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "test.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
/** internal data structure for test module */
struct sTest {
    SYS_TIME_HANDLE timer;  /**< timer used to generate delay times in console module */
};
/** typedef for ::sTest */
typedef struct sTest sTest_T;
/** internal/private data for test module */
sTest_T _test_data;


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */
static void _TEST_MuxSetAddress(uint8_t address) {
    (address & 1<<0) ? EXT3_MUX_DEMUX_S0_Set() : EXT3_MUX_DEMUX_S0_Clear();
    (address & 1<<1) ? EXT3_MUX_DEMUX_S1_Set() : EXT3_MUX_DEMUX_S1_Clear();
    (address & 1<<2) ? EXT3_MUX_DEMUX_S2_Set() : EXT3_MUX_DEMUX_S2_Clear();
    (address & 1<<3) ? EXT3_MUX_DEMUX_S3_Set() : EXT3_MUX_DEMUX_S3_Clear();
}

static void _TEST_SwitchPressedCallback(uintptr_t context){
    sMSG_T msg;
    // msg.id = MSG_ID_CONSOLE_CMD_TEST;
    msg.id = MSG_ID_CONSOLE_CMD_START_LEARN_CENTRAL;
    xQueueSend(app_data.msg_queue, &msg, 0);
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

void TEST_Initialize(void) {
    EIC_CallbackRegister(EIC_PIN_8, _TEST_SwitchPressedCallback, (uintptr_t)NULL);
    EIC_InterruptEnable(EIC_PIN_8);
    
    _TEST_MuxSetAddress(0x00);
}

void TEST_Tasks(sMSG_T *p_msg) {
    if ( p_msg->id == MSG_ID_CONSOLE_CMD_TEST ) {
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nTEST\r\n");
#if true
        TEST_SensorStartLearn(SENSOR_0);
#else
        TEST_SensorApplyReset(SENSOR_0);
        APPLICATION_DelayUs(100);
        TEST_SensorApplyReset(SENSOR_1);
        APPLICATION_DelayUs(100);
        TEST_SensorApplyReset(SENSOR_2);
        APPLICATION_DelayUs(100);
        TEST_SensorApplyReset(SENSOR_3);
        APPLICATION_DelayUs(100);
        TEST_SensorApplyReset(SENSOR_4);
        APPLICATION_DelayUs(100);
#endif
    }
}

void TEST_SensorApplyReset(uint8_t address) {
    _TEST_MuxSetAddress(address);
    APPLICATION_DelayUs(100);
    TEST_NRESET_Clear();
    APPLICATION_DelayUs(500);
    TEST_NRESET_Set();
    APPLICATION_DelayUs(100);
}

static void _TEST_SensorSetAlarmCb(uintptr_t context) { 
    SYS_TIME_TimerStop(_test_data.timer);
    SYS_TIME_TimerDestroy(_test_data.timer);
    TEST_NPWRON_Set();    // Release Button
}

void TEST_SensorSetAlarm(uint8_t address) {
    _test_data.timer = SYS_TIME_TimerCreate(
            0, 
            SYS_TIME_MSToCount(500),
            &_TEST_SensorSetAlarmCb, 
            (uintptr_t) NULL,
            SYS_TIME_SINGLE
            );
    _TEST_MuxSetAddress(address);
    TEST_NPWRON_Clear();    // Press Button
    SYS_TIME_TimerStart(_test_data.timer);
}

void TEST_SensorStartLearn(uint8_t address) {
    _TEST_MuxSetAddress(address);
    APPLICATION_DelayUs(100);
    TEST_NPWRON_Clear();    // Press Button
    TEST_NRESET_Clear();
    APPLICATION_DelayUs(500);
    TEST_NRESET_Set();
    APPLICATION_DelayUs(500);
    TEST_NPWRON_Set();    // Release Button
}

uint8_t TEST_GetPattern(uint8_t state) {
    const uint8_t pattern_dict[][2] = {
        {0xFF, PATTERN_INIT},
        {STATE_INIT, PATTERN_STATE_INIT},
        {STATE_WAIT_RF_SYS_RDY, PATTERN_STATE_WAIT_RF_SYS_RDY},
        {STATE_IDLE, PATTERN_IDLE},
        {0xFF, PATTERN_KEEP_ALIVE},
        {STATE_KEEP_ALIVE_TX_ACK, PATTERN_STATE_KEEP_ALIVE_TX_ACK},
        {STATE_KEEP_ALIVE_TX_ACK_COMPLETE, PATTERN_STATE_KEEP_ALIVE_TX_ACK_COMPLETE},
        {0xFF, PATTERN_LEARN},
        {STATE_LEARN, PATTERN_STATE_LEARN},    
        {STATE_LEARN_RX_PART_REQ, PATTERN_STATE_LEARN_RX_PART_REQ},
        {STATE_LEARN_TX_PART_REQ_RESP, PATTERN_STATE_LEARN_TX_PART_REQ_RESP},
        {STATE_LEARN_TX_PART_REQ_RESP_COMPLETE, PATTERN_STATE_LEARN_TX_PART_REQ_RESP_COMPLETE},
        {STATE_LEARN_TX_CON_VER_STAT, PATTERN_STATE_LEARN_TX_CON_VER_STAT},
        {STATE_LEARN_TX_CON_VER_STAT_COMPLETE, PATTERN_STATE_LEARN_TX_CON_VER_STAT_COMPLETE},
        {STATE_LEARN_RX_ACK_MSG, PATTERN_STATE_LEARN_RX_ACK_MSG},
        {STATE_LEARN_PASS, PATTERN_STATE_LEARN_PASS},
        {STATE_LEARN_FAIL, PATTERN_STATE_LEARN_FAIL},
        {0xFF, PATTERN_ALARM_STATE},
        {STATE_ALARM, PATTERN_STATE_ALARM},    
        {STATE_ALARM_TX_ACK_MSG_COMPLETE, PATTERN_STATE_ALARM_TX_ACK_MSG_COMPLETE},
        { STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP, PATTERN_STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP },
        { STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE, PATTERN_STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE },
        { STATE_UPDATE_TX_ACK, PATTERN_STATE_UPDATE_TX_ACK },
        { STATE_UPDATE_TX_ACK_COMPLETE, PATTERN_STATE_UPDATE_TX_ACK_COMPLETE },
      
        {STATE_ERROR, PATTERN_ERROR_STATE}
    };
    for (int i=0; i<sizeof(pattern_dict)/2;i++ ) {
        if (pattern_dict[i][0] == state) {
            return pattern_dict[i][1];
        }
    }
    return 0xAA;
}

void TEST_DebugPattern8(uint8_t pattern) {
    __disable_irq();
    PATTERN_RESET_SEQUENCE();
    for (int i=7; i>=0;i--) {
        if ( pattern & (1<<i) )  { 
            PATTERN_WRITE_1_SEQUENCE() 
        } else {
            PATTERN_WRITE_0_SEQUENCE();
        }
    }
    PATTERN_END_SEQUENCE();
    __enable_irq();
}

void TEST_DebugPattern16(uint16_t pattern) {
    __disable_irq();
    PATTERN_RESET_SEQUENCE();
    for (int i=15; i>=0;i--) {
        if ( pattern & (1<<i) ) {
            PATTERN_WRITE_1_SEQUENCE();            
        } else {
            PATTERN_WRITE_0_SEQUENCE();
        }
    }
    PATTERN_END_SEQUENCE();
    __enable_irq();
}
/* *****************************************************************************
 End of File
 */
