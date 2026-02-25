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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "definitions.h"
#include "console.h"
#include "application/test/test.h"
#include <string.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
/** data structure containing application version information */
struct sVersion {
    uint8_t major;  /**< major version */
    uint8_t minor;  /**< minor version */
    uint8_t patch;  /**< patch version */
}__PACKED;
/** typedef for data structure ::sVersion */
typedef struct sVersion sVersion_T;
/** application version information (stored in FLASH) */
const sVersion_T app_version = {
    .major = 0, .minor = 0, .patch=1
};

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */
/*
 * Console Commands
 */
void _CONSOLE_CmdVersion(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv) {
    SYS_CONSOLE_PRINT("CENTRAL V%d.%d.%d\r\n",app_version.major,app_version.minor,app_version.patch);
}

eSENSOR_ID_T _COMMAND_GetSensorId(char *sensor_name) {
    eSENSOR_ID_T id = SENSOR_ID_INVALID;
    if ( strcmp(sensor_name, "S1") == 0 ) { id = SENSOR_0; }
    else if ( strcmp(sensor_name, "S2") == 0 ) { id = SENSOR_1; }
    else if ( strcmp(sensor_name, "S3") == 0 ) { id = SENSOR_2; }
    else if ( strcmp(sensor_name, "S4") == 0 ) { id = SENSOR_3; }
    else if ( strcmp(sensor_name, "S5") == 0 ) { id = SENSOR_4; }
    else {}
    return id;
}

void _CONSOLE_CmdStartLearn(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv) {
    sMSG_T msg;
    msg.id = MSG_ID_INVALID;
    if (argc == 2 ) {
        if ( strcmp(argv[1], "C") == 0 ) {
            // Start Learn Mode on Central Device
            msg.id = MSG_ID_CONSOLE_CMD_START_LEARN_CENTRAL;
        } else {
            msg.id = MSG_ID_CONSOLE_CMD_START_LEARN_SENSOR;
            msg.data[0] = _COMMAND_GetSensorId(argv[1]);
        }
    } 
    if (msg.id != MSG_ID_INVALID) {
        xQueueSend(app_data.msg_queue, &msg, 0);
    } else {
        SYS_CONSOLE_PRINT("Usage: START_LEARN <C/S1..S5>\r\n",argv[0],argv[1]);
    }
}

void _COMMAND_CmdVerify(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv) {
    /* TODO: Add Implementation */
}

void _CommandSetAlarm(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv) {
    sMSG_T msg;
    msg.id = MSG_ID_INVALID;
    if (argc == 2) {
        msg.id = MSG_ID_CONSOLE_CMD_SENSOR_ALARM;
        msg.data[0] = _COMMAND_GetSensorId(argv[1]);
    }
    if (msg.id != MSG_ID_INVALID) {
        xQueueSend(app_data.msg_queue, &msg, 0);
    }
}

void _COMMAND_CmdCentralReset(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv) {
    NVIC_SystemReset();
}

void _COMMAND_CmdSensorReset(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv) {
    sMSG_T msg;
    msg.id = MSG_ID_INVALID;
    if (argc == 2) {
        msg.id = MSG_ID_CONSOLE_CMD_SENSOR_RESET;
        msg.data[0] = _COMMAND_GetSensorId(argv[1]);
    }
    if (msg.id != MSG_ID_INVALID) {
        xQueueSend(app_data.msg_queue, &msg, 0);
    }
}

void _COMMAND_CmdTest(SYS_CMD_DEVICE_NODE* pCmdIO, int argc, char **argv) {
    /* TODO: Add Implementation */
    // SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "_COMMAND_Learn(...)");
    sMSG_T msg;
    msg.id = MSG_ID_CONSOLE_CMD_TEST;
    xQueueSend(app_data.msg_queue, &msg, 0);
}


// state logging on/off
static const SYS_CMD_DESCRIPTOR cmdTbl[] = {
    {"VERSION?", _CONSOLE_CmdVersion, ": Get Version"},
    {"START_LEARN", _CONSOLE_CmdStartLearn, ": Start Learn Mode"},
    {"verify", _COMMAND_CmdVerify, ": Start Verify Mode"},
    {"SET_ALARM", _CommandSetAlarm, ": Set Sensor Alarm"},
    {"CENTRAL_RESET", _COMMAND_CmdCentralReset, ": Set Central Reset"},
    {"SENSOR_RESET", _COMMAND_CmdSensorReset, ": Set Sensor Reset"},
    {"TEST", _COMMAND_CmdTest, ": Start Test"},
};

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */
void CONSOLE_Initialize(void) {
    bool result = SYS_CMD_ADDGRP(cmdTbl, sizeof(cmdTbl)/sizeof(*cmdTbl),"commands", ": Commands");
    ASSERT(!result, "SYS_CMD_ADDGRP fails");    
}

void CONSOLE_Tasks(sMSG_T *p_msg) {
    if ( p_msg->id == MSG_ID_CONSOLE_CMD_START_LEARN_SENSOR  ) {
        eSENSOR_ID_T id  = p_msg->data[0];
        TEST_SensorStartLearn(id);
    } else if ( p_msg->id == MSG_ID_CONSOLE_CMD_SENSOR_RESET ) {
        eSENSOR_ID_T id  = p_msg->data[0];
        TEST_SensorApplyReset(id);
    } else if ( p_msg->id == MSG_ID_CONSOLE_CMD_SENSOR_ALARM ) {
        eSENSOR_ID_T id  = p_msg->data[0];
        TEST_SensorSetAlarm(id);
    } else {
    }
}
/* *****************************************************************************
 End of File
 */
