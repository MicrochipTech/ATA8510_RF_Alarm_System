/* ************************************************************************** */
/* Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/** \file states.h
 * include file for application state machine implementation. 
 */

#ifndef _STATES_H    /* Guard against multiple inclusion */
#define _STATES_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "definitions.h"
#include "../application.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */


    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************
    extern void STATES_Initialize(void);
    extern void STATES_Tasks(sMsg_T *p_msg);
    
    extern void STATE_SwitchState(eAPPLICATION_STATE_T state, bool print_state);

    extern void STATE_Init(sMsg_T *p_msg);
    extern void STATE_WaitRfSysRdy(sMsg_T *p_msg);
    
    extern void STATE_Idle(sMsg_T *p_msg);
    
    extern void STATE_KeepAliveTxAck(sMsg_T *p_msg);
    extern void STATE_KeepAliveTxAckComplete(sMsg_T *p_msg);
    
    extern void STATE_Learn(sMsg_T *p_msg);
    extern void STATE_LearnRxPartReq(sMsg_T *p_msg);
    extern void STATE_LearnTxPartReqResp(sMsg_T *p_msg);
    extern void STATE_LearnTxPartReqRespComplete(sMsg_T *p_msg);
    extern void STATE_LearnTxConVerStat(sMsg_T* p_msg);
    extern void STATE_LearnTxConVerStatComplete(sMsg_T* p_msg);
    extern void STATE_LearnRxAckMsg(sMsg_T* p_msg);
    extern void STATE_LearnPass(sMsg_T *p_msg);
    extern void STATE_LearnFail(sMsg_T *p_msg);
    
    extern void STATE_ConnectionVerificationTxConVerResp(sMsg_T* p_msg);
    extern void STATE_ConnectionVerificationTxConVerRespComplete(sMsg_T* p_msg);
    
    extern void STATE_UpdateTxAck(sMsg_T* p_msg);
    extern void STATE_UpdateTxAckComplete(sMsg_T* p_msg);
    
    extern void STATE_Error(sMsg_T *p_msg);
    
    

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _STATES_H */

/* *****************************************************************************
 End of File
 */
