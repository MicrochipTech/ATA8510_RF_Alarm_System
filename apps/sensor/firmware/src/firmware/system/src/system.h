/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/system/src/system.h $
  $LastChangedRevision: 648642 $
  $LastChangedDate: 2021-10-26 15:28:50 +0200 (Di, 26 Okt 2021) $
  $LastChangedBy: swagner $
-------------------------------------------------------------------------------
  Project:      ATA5831
  Target MCU:   ATA5831
  Compiler:     IAR C/C++ Compiler for AVR 5.51.0
-------------------------------------------------------------------------------

******************************************************************************
* Copyright 2011, Atmel Automotive GmbH                                       *
*                                                                             *
* This software is owned by the Atmel Automotive GmbH                         *
* and is protected by and subject to worldwide patent protection.             *
* Atmel hereby grants to licensee a personal,                                 *
* non-exclusive, non-transferable license to copy, use, modify, create        *
* derivative works of, and compile the Atmel Source Code and derivative       *
* works for the sole purpose of creating custom software in support of        *
* licensee product to be used only in conjunction with a Atmel integrated     *
* circuit as specified in the applicable agreement. Any reproduction,         *
* modification, translation, compilation, or representation of this           *
* software except as specified above is prohibited without the express        *
* written permission of Atmel.                                                *
*                                                                             *
* Disclaimer: ATMEL MAKES NO WARRANTY OF ANY KIND,EXPRESS OR IMPLIED,         *
* WITH REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED    *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.         *
* Atmel reserves the right to make changes without further notice to the      *
* materials described herein. Atmel does not assume any liability arising     *
* out of the application or use of any product or circuit described herein.   *
* Atmel does not authorize its products for use as critical components in     *
* life-support systems where a malfunction or failure may reasonably be       *
* expected to result in significant injury to the user. The inclusion of      *
* Atmel products in a life-support systems application implies that the       *
* manufacturer assumes all risk of such use and in doing so indemnifies       *
* Atmel against all charges.                                                  *
*                                                                             *
* Use may be limited by and subject to the applicable Atmel software          *
* license agreement.                                                          *
******************************************************************************/

/** \file system.h
*/

#ifndef SYSTEM_H
#define SYSTEM_H
/* ---------------------------------------------------------------------------*/
/*   INCLUDES                                                                 */
/* ---------------------------------------------------------------------------*/
#include "../../stdc/src/stdc.h"
/* ---------------------------------------------------------------------------*/
/*   DEFINES                                                                  */
/* ---------------------------------------------------------------------------*/
#define SYS_FLOW_INIT_STATE                     0U
#define RX_FLOW_STATE_INIT_SSM                  SYS_FLOW_INIT_STATE
#define RX_FLOW_STATE_WAIT_XTO_RDY              RX_FLOW_STATE_INIT_SSM        + 1U
#define RX_FLOW_STATE_START_SSM                 RX_FLOW_STATE_WAIT_XTO_RDY    + 1U
#define RX_FLOW_STATE_SSM_GETTELEGRAM           RX_FLOW_STATE_START_SSM       + 1U
#define RX_FLOW_STATE_SSM_RDY                   RX_FLOW_STATE_SSM_GETTELEGRAM + 1U
#define RX_FLOW_STATE_SHUTDOWN                  RX_FLOW_STATE_SSM_RDY         + 1U
#define RX_FLOW_STATE_SHUTDOWN_RDY              RX_FLOW_STATE_SHUTDOWN        + 1U
#define RX_FLOW_STATE_END                       RX_FLOW_STATE_SHUTDOWN_RDY    + 1U

#define TX_FLOW_STATE_INIT_SSM                  SYS_FLOW_INIT_STATE
#define TX_FLOW_STATE_WAIT_XTO_RDY              TX_FLOW_STATE_INIT_SSM              + 1U
#define TX_FLOW_STATE_START_SSM                 TX_FLOW_STATE_WAIT_XTO_RDY          + 1U
#define TX_FLOW_STATE_SSM_RDY                   TX_FLOW_STATE_START_SSM             + 1U
#define TX_FLOW_STATE_WAIT4FILLLEVEL            TX_FLOW_STATE_SSM_RDY               + 1U
#define TX_FLOW_STATE_START_TX_MODULATOR        TX_FLOW_STATE_WAIT4FILLLEVEL        + 1U
#define TX_FLOW_STATE_TRANSMISSION_COMPLETE     TX_FLOW_STATE_START_TX_MODULATOR    + 1U
#define TX_FLOW_STATE_SHUTDOWN                  TX_FLOW_STATE_TRANSMISSION_COMPLETE + 1U
#define TX_FLOW_STATE_SHUTDOWN_RDY              TX_FLOW_STATE_SHUTDOWN              + 1U
#define TX_FLOW_STATE_END                       TX_FLOW_STATE_SHUTDOWN_RDY          + 1U

#define TX_TRANS_FLOW_INIT_SSM                  SYS_FLOW_INIT_STATE
#define TX_TRANS_FLOW_WAIT_XTO_RDY              TX_TRANS_FLOW_INIT_SSM                  + 1U
#define TX_TRANS_FLOW_START_SSM                 TX_TRANS_FLOW_WAIT_XTO_RDY              + 1U
#define TX_TRANS_FLOW_STATE_SSM_RDY             TX_TRANS_FLOW_START_SSM                 + 1U
#define TX_TRANS_FLOW_STATE_TRANSPARENT_STATE   TX_TRANS_FLOW_STATE_SSM_RDY             + 1U
#define TX_TRANS_FLOW_STATE_SHUTDOWN            TX_TRANS_FLOW_STATE_TRANSPARENT_STATE   + 1U
#define TX_TRANS_FLOW_STATE_SHUTDOWN_RDY        TX_TRANS_FLOW_STATE_SHUTDOWN            + 1U
#define TX_TRANS_FLOW_STATE_END                 TX_TRANS_FLOW_STATE_SHUTDOWN_RDY        + 1U

#define POLL_FLOW_STATE_INIT_CHANNEL            SYS_FLOW_INIT_STATE
#define POLL_FLOW_STATE_INIT_SSM                POLL_FLOW_STATE_INIT_CHANNEL    + 1U
#define POLL_FLOW_STATE_WAIT_XTO_RDY            POLL_FLOW_STATE_INIT_SSM        + 1U
#define POLL_FLOW_STATE_START_SSM               POLL_FLOW_STATE_WAIT_XTO_RDY    + 1U
#define POLL_FLOW_STATE_SSM_GETTELEGRAM         POLL_FLOW_STATE_START_SSM       + 1U
#define POLL_FLOW_STATE_SSM_RDY                 POLL_FLOW_STATE_SSM_GETTELEGRAM + 1U
#define POLL_FLOW_STATE_NEXT_CHANNEL            POLL_FLOW_STATE_SSM_RDY         + 1U
#define POLL_FLOW_STATE_SHUTDOWN                POLL_FLOW_STATE_NEXT_CHANNEL    + 1U
#define POLL_FLOW_STATE_SHUTDOWN_RDY            POLL_FLOW_STATE_SHUTDOWN        + 1U
#define POLL_FLOW_STATE_END                     POLL_FLOW_STATE_SHUTDOWN_RDY    + 1U

#define ANTTUNE_FLOW_STATE_INIT_SSM             SYS_FLOW_INIT_STATE
#define ANTTUNE_FLOW_STATE_WAIT_XTO_RDY         ANTTUNE_FLOW_STATE_INIT_SSM     + 1U
#define ANTTUNE_FLOW_STATE_START_SSM            ANTTUNE_FLOW_STATE_WAIT_XTO_RDY + 1U
#define ANTTUNE_FLOW_STATE_SSM_RDY              ANTTUNE_FLOW_STATE_START_SSM    + 1U
#define ANTTUNE_FLOW_STATE_SHUTDOWN             ANTTUNE_FLOW_STATE_SSM_RDY      + 1U
#define ANTTUNE_FLOW_STATE_SHUTDOWN_RDY         ANTTUNE_FLOW_STATE_SHUTDOWN     + 1U
#define ANTTUNE_FLOW_STATE_CMD_RDY              ANTTUNE_FLOW_STATE_SHUTDOWN_RDY + 1U
#define ANTTUNE_FLOW_STATE_END                  ANTTUNE_FLOW_STATE_CMD_RDY      + 1U

#define VCOCAL_FLOW_STATE_INIT_SSM              SYS_FLOW_INIT_STATE
#define VCOCAL_FLOW_STATE_WAIT_XTO_RDY          VCOCAL_FLOW_STATE_INIT_SSM     + 1U
#define VCOCAL_FLOW_STATE_START_SSM             VCOCAL_FLOW_STATE_WAIT_XTO_RDY + 1U
#define VCOCAL_FLOW_STATE_SSM_RDY               VCOCAL_FLOW_STATE_START_SSM    + 1U
#define VCOCAL_FLOW_STATE_SHUTDOWN              VCOCAL_FLOW_STATE_SSM_RDY      + 1U
#define VCOCAL_FLOW_STATE_SHUTDOWN_RDY          VCOCAL_FLOW_STATE_SHUTDOWN     + 1U
#define VCOCAL_FLOW_STATE_CMD_RDY               VCOCAL_FLOW_STATE_SHUTDOWN_RDY + 1U
#define VCOCAL_FLOW_STATE_END                   VCOCAL_FLOW_STATE_CMD_RDY      + 1U

#define PURE_RX_FLOW_STATE_INIT_SSM             SYS_FLOW_INIT_STATE
#define PURE_RX_FLOW_STATE_WAIT_XTO_RDY         PURE_RX_FLOW_STATE_INIT_SSM        + 1U
#define PURE_RX_FLOW_STATE_START_SSM            PURE_RX_FLOW_STATE_WAIT_XTO_RDY    + 1U
#define PURE_RX_FLOW_STATE_SSM_GETTELEGRAM      PURE_RX_FLOW_STATE_START_SSM       + 1U
#define PURE_RX_FLOW_PURE_RX_UP                 PURE_RX_FLOW_STATE_SSM_GETTELEGRAM + 1U
#define PURE_RX_FLOW_STATE_SHUTDOWN             PURE_RX_FLOW_PURE_RX_UP            + 1U
#define PURE_RX_FLOW_STATE_SHUTDOWN_RDY         PURE_RX_FLOW_STATE_SHUTDOWN        + 1U
#define PURE_RX_FLOW_STATE_END                  PURE_RX_FLOW_STATE_SHUTDOWN_RDY    + 1U

#define RSSI_FLOW_STATE_INIT_SSM                SYS_FLOW_INIT_STATE
#define RSSI_FLOW_STATE_WAIT_XTO_RDY            RSSI_FLOW_STATE_INIT_SSM        + 1U
#define RSSI_FLOW_STATE_START_SSM               RSSI_FLOW_STATE_WAIT_XTO_RDY    + 1U
#define RSSI_FLOW_STATE_SSM_GETTELEGRAM         RSSI_FLOW_STATE_START_SSM       + 1U
#define RSSI_FLOW_STATE_SSM_RDY                 RSSI_FLOW_STATE_SSM_GETTELEGRAM + 1U
#define RSSI_FLOW_STATE_SHUTDOWN                RSSI_FLOW_STATE_SSM_RDY         + 1U
#define RSSI_FLOW_STATE_SHUTDOWN_RDY            RSSI_FLOW_STATE_SHUTDOWN        + 1U
#define RSSI_FLOW_STATE_END                     RSSI_FLOW_STATE_SHUTDOWN_RDY    + 1U

#define TEMPMEAS_FLOW_STATE_INIT_SSM            SYS_FLOW_INIT_STATE
#define TEMPMEAS_FLOW_STATE_WAIT_XTO_RDY        TEMPMEAS_FLOW_STATE_INIT_SSM         + 1U
#define TEMPMEAS_FLOW_STATE_START_SSM           TEMPMEAS_FLOW_STATE_WAIT_XTO_RDY     + 1U
#define TEMPMEAS_FLOW_STATE_SSM_RDY             TEMPMEAS_FLOW_STATE_START_SSM        + 1U
#define TEMPMEAS_FLOW_STATE_WAIT4TEMPERATURE    TEMPMEAS_FLOW_STATE_SSM_RDY          + 1U
#define TEMPMEAS_FLOW_STATE_SHUTDOWN            TEMPMEAS_FLOW_STATE_WAIT4TEMPERATURE + 1U
#define TEMPMEAS_FLOW_STATE_SHUTDOWN_RDY        TEMPMEAS_FLOW_STATE_SHUTDOWN         + 1U
#define TEMPMEAS_FLOW_STATE_CMD_RDY             TEMPMEAS_FLOW_STATE_SHUTDOWN_RDY     + 1U
#define TEMPMEAS_FLOW_STATE_END                 TEMPMEAS_FLOW_STATE_CMD_RDY          + 1U

#define SELFCHECK_FLOW_STATE_TEMPMEAS           SYS_FLOW_INIT_STATE
#define SELFCHECK_FLOW_STATE_SRCFRCREGREFRESH   SELFCHECK_FLOW_STATE_TEMPMEAS + 8U

#define SUBCHANNELING_FLOW_STATE_WAIT_XTO_RDY   SYS_FLOW_INIT_STATE
#define SUBCHANNELING_FLOW_STATE_INIT_SSM       SUBCHANNELING_FLOW_STATE_WAIT_XTO_RDY + 1U
#define SUBCHANNELING_FLOW_STATE_CENTER_FREQ    SUBCHANNELING_FLOW_STATE_INIT_SSM     + 1U
#define SUBCHANNELING_FLOW_STATE_LOWER_FREQ     SUBCHANNELING_FLOW_STATE_CENTER_FREQ  + 1U
#define SUBCHANNELING_FLOW_STATE_UPPER_FREQ     SUBCHANNELING_FLOW_STATE_LOWER_FREQ   + 1U

#define FLOW_CTRL_LAST_STARTED_SSM_SHUTDOWN     0U
#define FLOW_CTRL_LAST_STARTED_SSM_TX           (FLOW_CTRL_LAST_STARTED_SSM_SHUTDOWN + 1U)
#define FLOW_CTRL_LAST_STARTED_SSM_RX           (FLOW_CTRL_LAST_STARTED_SSM_TX + 1U)
/* ---------------------------------------------------------------------------*/
/*   TYPE DEFINITIONS                                                         */
/* ---------------------------------------------------------------------------*/
/** \brief <b>sysFlowStateMachineFunc</b>
    is used for function pointer definition of system flow state machines.
*/
typedef void (*sysFlowStateMachineFunc)(void);

/** \brief <b>sysFlowStateMachineFuncLut</b>
    is used for function pointer definition of system flow state machine
    look up tables in code section.
*/
typedef const sysFlowStateMachineFunc __flash sysFlowStateMachineFuncLut;

/*----------------------------------------------------------------------------- */
/** \brief <b>sSystemFlowCtrl</b> 
    contains the information to control the flow of the software state machines. 
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>msmstate</b>
        is used as SSM master state machine state to stop software driven timeout control
    */
    uint8_t          msmstate; 
    
    /** brief <b>index</b>
        contains the current state machine index
    */
    volatile uint8_t index;
    
    /** \brief <b>pLut</b>
        is used as pointer to currently used state machine look up table
    */
    sysFlowStateMachineFuncLut *pLut;
    /** \brief <b>lastStartedSsm</b>
        is used as indicator for last started SSM to ensure correct operating mode transitions
    */
    uint8_t          lastStartedSsm;
}sSystemFlowCtrl;


/*----------------------------------------------------------------------------- */
/*---------------------------------------------------------------------------*/
/*  EXTERNAL PROTOTYPES                                                      */
/*---------------------------------------------------------------------------*/

extern VOIDFUNC ATA_check4extRequests_C(void);

extern VOIDFUNC ATA_systemFlowCtrl_C(void);

extern VOIDFUNC ATA_sysExeStateMachineFunc_C(void);

extern VOIDFUNC ATA_sysIdleMode_C(void);

extern UINT8FUNC ATA_setIdleMode_C(void);

extern VOIDFUNC ATA_systemStartSSM_C(uint8_t errorCode);

extern VOIDFUNC ATA_systemWait4SSMrdy_C(uint8_t errorCode, uint8_t shutdownIdx);

extern VOIDFUNC ATA_systemFlowStateWaitXtoReady_C(void);

extern VOIDFUNC ATA_systemFlowStateShutdownTRX_C(void);

extern VOIDFUNC ATA_systemFlowStateWait4ShutdownRdyTRX_C(void);

extern VOIDFUNC ATA_systemFlowStateMachineEnd_C(void);

extern VOIDFUNC ATA_systemErrorLoop_C(uint8_t errorCode);

extern UINT8FUNC ATA_startSsmWatchdog_C(void);

extern VOIDFUNC ATA_stopSsmWatchdog_C(void);

extern VOIDFUNC ATA_setEventPin_ASM(void);

extern VOIDFUNC ATA_checkAndSwitchIdleXTO_C(void);

extern VOIDFUNC ATA_triggerSrcCalibration_C(void);

extern VOIDFUNC ATA_triggerFrcCalibration_C(void);

extern VOIDFUNC ATA_triggerSelfCheck_C(void);

extern VOIDFUNC ATA_serviceInitSwitching_C(void);

extern VOIDFUNC ATA_wait4avcc_C(void);

extern UINT8FUNC ATA_blockingShutDownSSM_C(void);

extern VOIDFUNC ATA_systemModeSwitching_C(void);

extern VOIDFUNC ATA_tuneCheckSwitching_C(void);

extern VOIDFUNC ATA_miscTriggerSwitching_C(void);

extern sysFlowStateMachineFuncLut *pRxSysFlowStateMachine;
extern sysFlowStateMachineFuncLut rxFlowStateMachine[8];

extern sysFlowStateMachineFuncLut *pTxBufSysFlowStateMachine;
extern sysFlowStateMachineFuncLut txBufFlowStateMachine[10];

extern sysFlowStateMachineFuncLut *pTxTransSysFlowStateMachine;
extern sysFlowStateMachineFuncLut txTransFlowStateMachine[8];

extern sysFlowStateMachineFuncLut *pPollSysFlowStateMachine;
extern sysFlowStateMachineFuncLut pollFlowStateMachine[10];

extern sysFlowStateMachineFuncLut *pAntTuneSysFlowStateMachine;
extern sysFlowStateMachineFuncLut anttuneFlowStateMachine[8];

extern sysFlowStateMachineFuncLut *pVcoCalSysFlowStateMachine;
extern sysFlowStateMachineFuncLut vcocalFlowStateMachine[8];

extern sysFlowStateMachineFuncLut *pPureRxSysFlowStateMachine;
extern sysFlowStateMachineFuncLut pureRxFlowStateMachine[8];

extern sysFlowStateMachineFuncLut *pRssiSysFlowStateMachine;
extern sysFlowStateMachineFuncLut rssiFlowStateMachine[8];

extern sysFlowStateMachineFuncLut *pTempMeasSysFlowStateMachine;
extern sysFlowStateMachineFuncLut tempmeasSysFlowStateMachine[9];

extern sysFlowStateMachineFuncLut *pSelfCheckSysFlowStateMachine;
extern sysFlowStateMachineFuncLut selfCheckSysFlowStateMachine[9];

extern sysFlowStateMachineFuncLut *pSubChannelingSysFlowStateMachine;
extern sysFlowStateMachineFuncLut subChannelingSysFlowStateMachine[5];

extern __no_init sSystemFlowCtrl flowCtrl;

#endif /* SYSTEM_H */