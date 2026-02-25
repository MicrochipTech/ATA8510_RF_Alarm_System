/* ************************************************************************** */
/** Descriptive File Name

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
    extern void STATES_Tasks(sMSG_T *p_msg);
    
    extern void STATE_SwitchState(eAPPLICATION_STATE_T state);

    extern void STATE_Init(sMSG_T *p_msg);
    extern void STATE_WaitRfSysRdy(sMSG_T *p_msg);
    
    extern void STATE_Idle(sMSG_T *p_msg);
    
    extern void STATE_KeepAliveTxAck(sMSG_T *p_msg);
    extern void STATE_KeepAliveTxAckComplete(sMSG_T *p_msg);
    
    extern void STATE_Learn(sMSG_T *p_msg);
    extern void STATE_LearnRxPartReq(sMSG_T *p_msg);
    extern void STATE_LearnTxPartReqResp(sMSG_T *p_msg);
    extern void STATE_LearnTxPartReqRespComplete(sMSG_T *p_msg);
    extern void STATE_LearnTxConVerStat(sMSG_T* p_msg);
    extern void STATE_LearnTxConVerStatComplete(sMSG_T* p_msg);
    extern void STATE_LearnRxAckMsg(sMSG_T* p_msg);
    extern void STATE_LearnPass(sMSG_T *p_msg);
    extern void STATE_LearnFail(sMSG_T *p_msg);
    
    extern void STATE_ConnectionVerificationTxConVerResp(sMSG_T* p_msg);
    extern void STATE_ConnectionVerificationTxConVerRespComplete(sMSG_T* p_msg);
    
    extern void STATE_Alarm(sMSG_T *p_msg);
    extern void STATE_AlarmTxAckMsgComplete (sMSG_T *p_msg);
    
    extern void STATE_UpdateTxAck(sMSG_T* p_msg);
    extern void STATE_UpdateTxAckComplete(sMSG_T* p_msg);
    
    extern void STATE_Error(sMSG_T *p_msg);
    
    

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _STATES_H */

/* *****************************************************************************
 End of File
 */
