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
sFuncPair_T _states[] = {
    /* INIT */
    { STATE_INIT, STATE_Init },
    { STATE_WAIT_RF_SYS_RDY, STATE_WaitRfSysRdy },
    /* IDLE */
    { STATE_IDLE, STATE_Idle },
    /* KEEP ALIVE */
    { STATE_KEEP_ALIVE_TX_ACK, STATE_KeepAliveTxAck},
    { STATE_KEEP_ALIVE_TX_ACK_COMPLETE, STATE_KeepAliveTxAckComplete},
    /* LEARN */
    { STATE_LEARN, STATE_Learn },
    { STATE_LEARN_RX_PART_REQ, STATE_LearnRxPartReq },
    { STATE_LEARN_TX_PART_REQ_RESP, STATE_LearnTxPartReqResp },
    { STATE_LEARN_TX_PART_REQ_RESP_COMPLETE, STATE_LearnTxPartReqRespComplete },
    { STATE_LEARN_TX_CON_VER_STAT, STATE_LearnTxConVerStat },
    { STATE_LEARN_TX_CON_VER_STAT_COMPLETE, STATE_LearnTxConVerStatComplete },
    { STATE_LEARN_RX_ACK_MSG, STATE_LearnRxAckMsg },
    { STATE_LEARN_PASS, STATE_LearnPass },
    { STATE_LEARN_FAIL, STATE_LearnFail },
    /* ALARM */
    { STATE_ALARM, STATE_Alarm },
    { STATE_ALARM_TX_ACK_MSG_COMPLETE, STATE_AlarmTxAckMsgComplete },
    /* CONNECTION VERIFICATION */
    { STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP, STATE_ConnectionVerificationTxConVerResp },
    { STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE, STATE_ConnectionVerificationTxConVerRespComplete },
    /* UPDATE */
    { STATE_UPDATE_TX_ACK, STATE_UpdateTxAck},
    { STATE_UPDATE_TX_ACK_COMPLETE, STATE_UpdateTxAckComplete},
    /* ERROR */
    { STATE_ERROR, STATE_Error },
};

sMsgPair_T _state_names[] = {
    { STATE_INIT, "STATE_INIT" },
    { STATE_WAIT_RF_SYS_RDY, "STATE_WAIT_RF_SYS_RDY" },
    { STATE_IDLE, "STATE_IDLE" },
    { STATE_LEARN, "STATE_LEARN" },
    { STATE_LEARN_RX_PART_REQ, "STATE_LEARN_RX_PART_REQ" },
    { STATE_LEARN_TX_PART_REQ_RESP, "STATE_LEARN_TX_PART_REQ_RESP" },
    { STATE_LEARN_TX_PART_REQ_RESP_COMPLETE, "STATE_LEARN_TX_PART_REQ_RESP_COMPLETE" },
    { STATE_LEARN_TX_CON_VER_STAT, "STATE_LEARN_TX_CON_VER_STAT" },
    { STATE_LEARN_TX_CON_VER_STAT_COMPLETE, "STATE_LEARN_TX_CON_VER_STAT_COMPLETE" },
    { STATE_LEARN_RX_ACK_MSG, "STATE_LEARN_RX_ACK_MSG" },
    { STATE_LEARN_PASS, "STATE_LEARN_PASS" },
    { STATE_LEARN_FAIL, "STATE_LEARN_FAIL" },
    { STATE_ALARM, "STATE_ALARM" },
    { STATE_ALARM_TX_ACK_MSG_COMPLETE, "STATE_ALARM_TX_ACK_MSG_COMPLETE" },
    { STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP, "STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP" },
    { STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE, "STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE" },
    { STATE_UPDATE_TX_ACK, "STATE_UPDATE_TX_ACK"},
    { STATE_UPDATE_TX_ACK_COMPLETE, "STATE_UPDATE_TX_ACK_COMPLETE"},
    { STATE_ERROR, "STATE_ERROR" },
};


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

void STATES_Initialize(void) {
    STATE_SwitchState(STATE_INIT);
}

void STATES_Tasks(sMSG_T *p_msg) {
    
    fpVoidFuncMsg_T p_func = (fpVoidFuncMsg_T)APPLICATION_GetFunction( 
            app_data.state,
            _states,
            sizeof(_states)/sizeof(*_states)
            );
    if (p_func != NULL) {
        p_func(p_msg);
    } else {
        ASSERT(true, "Unknown Application State");
    }
}

void STATE_SwitchState(eAPPLICATION_STATE_T state) {
    app_data.state = state;
    const char *p_msg = APPLICATION_GetMsg(
        state, 
        _state_names,
        sizeof(_state_names)/sizeof(*_state_names)
        );
    if ( p_msg != NULL){
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\n>>> ");
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, p_msg);
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, " <<<\r\n");
    }
    
    uint8_t pattern = TEST_GetPattern(state);
    TEST_DebugPattern8(pattern);

    sMSG_T msg;
    msg.id = MSG_ID_APP_TRIGGER;
    xQueueSend(app_data.msg_queue, &msg, 0);        
}

/* *****************************************************************************
 End of File
 */
