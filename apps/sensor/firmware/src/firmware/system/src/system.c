/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/system/src/system.c $
  $LastChangedRevision: 648718 $
  $LastChangedDate: 2021-10-27 15:12:44 +0200 (Mi, 27 Okt 2021) $
  $LastChangedBy: gwillbol $
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

/** \file system.c
*/

/*---------------------------------------------------------------------------*/
/*  INCLUDES                                                                 */
/*---------------------------------------------------------------------------*/
#include "system.h"
#include "../../api/src/api.h"
#include "../../eep/src/eep.h"
#include "../../rf/src/rf.h"
#include "../../rfpolling/src/rfpolling.h"
#include "../../rftx/src/rftx.h"
#include "../../rfrx/src/rfrx.h"
#include "../../globals/src/globals.h"
#include "../../calib/src/calib.h"
#include "../../timer1/src/timer1.h"
#include "../../timer2/src/timer2.h"
#include "../../timer3/src/timer3.h"
#include "../../init/src/init.h"

/*---------------------------------------------------------------------------*/
/*  DEFINES                                                                  */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*  Modul Globals                                                            */
/*---------------------------------------------------------------------------*/

/** \brief <b>pRxSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    RXMode (Buffered and Transparent).
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pRxSysFlowStateMachine;

/** \brief <b>rxFlowStateMachine</b>
    look up table of the SW state machine used for RXMode (Buffered and Transparent).
    \details
    The following states are executed in this SW state machine:
    \li ATA_rxStateInitSSM_C:
        this state does the initialization of the registers for RXMode, the
        configuration of the Sequencer State Machine and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready
    \li ATA_rxStateStartSSM_C:
        this state starts the SSM
    \li ATA_rxStateWait4SSMstateGetTelegram_C:
        this state waits until the SSM has reached the get_telegram sub state machine
    \li ATA_rxStateWait4SSMrdy_C:
        this state waits until the SSM signals readiness
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables

    \image html RxSysFlowStateMachine.png
    \image rtf RxSysFlowStateMachine.png
    \n

*/
__root sysFlowStateMachineFuncLut rxFlowStateMachine[8] = {
    ATA_rxStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_rxStateStartSSM_C,
    ATA_rxStateWait4SSMstateGetTelegram_C,
    ATA_rxStateWait4SSMrdy_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pTxBufSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    TXMode (Buffered only).
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pTxBufSysFlowStateMachine;

/** \brief <b>txBufFlowStateMachine</b>
    look up table of the SW state machine used for TXMode (Buffered only).
    \details
    The following states are executed in this SW state machine:
    \li ATA_txStateInitSSM_C:
        this state does the initialization of the registers for TXMode, the
        configuration of the Sequencer State Machine and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready
    \li ATA_txStateStartSSM_C:
        this state starts the SSM
    \li ATA_txStateWait4SSMrdy_C:
        this state waits until the SSM signals readiness
    \li ATA_txStateWait4FillLevel_C:
        this state waits until the fill level of Preamble and Data FIFO is reached
    \li ATA_txStateStartTxModulator_C:
        this state start the TX Modulator
    \li ATA_txStateStartWait4TransmissionComplete_C:
        this state waits until the TX Modulator has finished
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables

    \image html TxBufSysFlowStateMachine.png
    \image rtf TxBufSysFlowStateMachine.png
    \n

*/
__root sysFlowStateMachineFuncLut txBufFlowStateMachine[10] = {
    ATA_txStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_txStateStartSSM_C,
    ATA_txStateWait4SSMrdy_C,
    ATA_txStateWait4FillLevel_C,
    ATA_txStateStartTxModulator_C,
    ATA_txStateStartWait4TransmissionComplete_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pTxTransSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    TXMode (transparent mode only).
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pTxTransSysFlowStateMachine;

/** \brief <b>txTransFlowStateMachine</b>
    look up table of the SW state machine used for TXMode (transparent mode only).
    \details
    The following states are executed in this SW state machine:
    \li ATA_txStateInitSSM_C:
        this state does the initialization of the registers for TXMode, the
        configuration of the Sequencer State Machine and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready
    \li ATA_txStateStartSSM_C:
        this state starts the SSM
    \li ATA_txTransparentStateWait4SSMrdy_C:
        this state waits until the SSM signals readiness
    \li ATA_txStateTransparentMode_C:
        this state is active during TXMode(transparent)
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables

    \image html TxTransSysFlowStateMachine.png
    \image rtf TxTransSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut txTransFlowStateMachine[8] = {
    ATA_txStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_txStateStartSSM_C,
    ATA_txTransparentStateWait4SSMrdy_C,
    ATA_txStateTransparentMode_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pPollSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    Polling Mode.
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pPollSysFlowStateMachine;

/** \brief <b>pollFlowStateMachine</b>
    look up table of the SW state machine used for Polling Mode.
    \details
    The following states are executed in this SW state machine:
    \li ATA_pollStateInitCurrentPollingChannel_C:
        this state sets the current polling channel configuration.
    \li ATA_pollStateInitSSM_C:
        this state initializes the sequencer state machine.
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready.
    \li ATA_rxStateStartSSM_C:
        this state starts the SSM.
    \li ATA_pollStateWait4SSMstateGetTelegram_C:
        this state waits for the reaching of the sub state machine Get Telegram.
    \li ATA_rxStateWait4SSMrdy_C:
        this state waits until the SSM signals readiness.
    \li ATA_pollStateCheck4NextPollingChannel_C:
        this state checks for end of polling cycle, end of polling loop ...
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM
    \li ATA_pollStateWait4ShutdownRdyTRX_C:
        this state machine function waits for end of ShutDown sequencer state machine.
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables.

    \image html PollingSysFlowStateMachine.png
    \image rtf PollingSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut pollFlowStateMachine[10] = {
    ATA_pollStateInitCurrentPollingChannel_C,
    ATA_pollStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_rxStateStartSSM_C,
    ATA_pollStateWait4SSMstateGetTelegram_C,
    ATA_rxStateWait4SSMrdy_C,
    ATA_pollStateCheck4NextPollingChannel_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_pollStateWait4ShutdownRdyTRX_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pAntTuneSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    antenna tuning.
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pAntTuneSysFlowStateMachine;

/** \brief <b>anttuneFlowStateMachine</b>
    look up table of the SW state machine used for antenna tuning.
    \details
    The following states are executed in this SW state machine:
    \li ATA_anttuneStateInitSSM_C:
        this state does the initialization of the registers for
        antenna tuning, the configuration of the Sequencer State Machine
        and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready.
    \li ATA_anttuneStateStartSSM_C:
        this state starts the sequencer state machine
    \li ATA_anttuneStateWait4SSMrdy_C:
        this state waits for the end of the sequencer state machine
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM.
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished.
    \li ATA_anttuneStateSetCmdRdy_C:
        this state signal CMD_RDY event.
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables.

    \image html AntTuneSysFlowStateMachine.png
    \image rtf AntTuneSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut anttuneFlowStateMachine[8] = {
    ATA_anttuneStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_anttuneStateStartSSM_C,
    ATA_anttuneStateWait4SSMrdy_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_anttuneStateSetCmdRdy_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pVcoCalSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    VCO calibration.
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pVcoCalSysFlowStateMachine;

/** \brief <b>vcocalFlowStateMachine</b>
    look up table of the SW state machine used for VCO calibration.
    \details
    The following states are executed in this SW state machine:
    \li ATA_vcocalStateInitSSM_C:
        this state does the initialization of the registers for
        VCO calibration, the configuration of the Sequencer State Machine
        and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready.
    \li ATA_vcocalStateStartSSM_C:
        this state starts the sequencer state machine
    \li ATA_vcocalStateWait4SSMrdy_C:
        this state waits for the end of the sequencer state machine
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM.
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished.
    \li ATA_vcocalStateSetCmdRdy_C:
        this state signal CMD_RDY event.
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables.

    \image html VcoCalSysFlowStateMachine.png
    \image rtf VcoCalSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut vcocalFlowStateMachine[8] = {
    ATA_vcocalStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_vcocalStateStartSSM_C,
    ATA_vcocalStateWait4SSMrdy_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_vcocalStateSetCmdRdy_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pPureRxSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    pureRX operating mode.
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pPureRxSysFlowStateMachine;

/** \brief <b>pureRxFlowStateMachine</b>
    look up table of the SW state machine used for pureRX Mode.
    \details
    The following states are executed in this SW state machine:
    \li ATA_rxStateInitSSM_C:
        this state does the initialization of the registers for RXMode, the
        configuration of the Sequencer State Machine and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready.
    \li ATA_rxStateStartSSM_C:
        this state starts the SSM
    \li ATA_rxStateWait4SSMstateGetTelegram_C:
        this state waits until the SSM has reached the get_telegram sub state machine
    \li ATA_pureRxUp_C:
        this state is active during pureRX Mode
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM.
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished.
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables.

    \image html PureRxSysFlowStateMachine.png
    \image rtf PureRxSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut pureRxFlowStateMachine[8] = {
    ATA_rxStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_rxStateStartSSM_C,
    ATA_rxStateWait4SSMstateGetTelegram_C,
    ATA_pureRxUp_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pRssiSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    RSSI measurement on demand.
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pRssiSysFlowStateMachine;

/** \brief <b>rssiFlowStateMachine</b>
    look up table of the SW state machine used for RSSI measurement.
    \details
    The following states are executed in this SW state machine:
    \li ATA_rssiStateInitSSM_C:
        this state does the initialization of the registers for RSSI measurement, the
        configuration of the Sequencer State Machine and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready.
    \li ATA_rssiStateStartSSM_C:
        this state starts the SSM
    \li ATA_rxStateWait4SSMstateGetTelegram_C:
        this state waits until the SSM has reached the get_telegram sub state machine
    \li ATA_rssiStateWait4SSMrdy_C:
        this state waits for the end of the sequencer state machine.
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM.
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished.
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables.

    \image html RssiSysFlowStateMachine.png
    \image rtf RssiSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut rssiFlowStateMachine[8] = {
    ATA_rssiStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_rssiStateStartSSM_C,
    ATA_rxStateWait4SSMstateGetTelegram_C,
    ATA_rssiStateWait4SSMrdy_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pTempMeasSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    temperature measurement on demand.
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pTempMeasSysFlowStateMachine;
/** \brief <b>tempmeasSysFlowStateMachine</b>
    look up table of the SW state machine used for temperature measurement.
    \details
    The following states are executed in this SW state machine:
    \li ATA_tempmeasStateInitSSM_C:
        this state does the initialization of the registers for temperature measurement, the
        configuration of the Sequencer State Machine and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready.
    \li ATA_tempmeasStateStartSSM_C:
        this state starts the SSM
    \li ATA_tempmeasStateWait4SSMrdy_C:
        this state waits for the end of the sequencer state machine.
    \li ATA_tempmeasStateWait4Temperature_C:
        this state reads the temperature value
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM.
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished.
    \li ATA_tempmeasStateSetCmdRdy_C:
        this state sets CMD_RDY event
    \li ATA_systemFlowStateMachineEnd_C:
        this state resets the SW state machine control variables.

    \image html TempMeasSysFlowStateMachine.png
    \image rtf TempMeasSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut tempmeasSysFlowStateMachine[9] = {
    ATA_tempmeasStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_tempmeasStateStartSSM_C,
    ATA_tempmeasStateWait4SSMrdy_C,
    ATA_tempmeasStateWait4Temperature_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_tempmeasStateSetCmdRdy_C,
    ATA_systemFlowStateMachineEnd_C
};

/** \brief <b>pSelfCheckSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    self check feature.
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pSelfCheckSysFlowStateMachine;
/** \brief <b>selfCheckSysFlowStateMachine</b>
    look up table of the SW state machine used for self check feature.
    \details
    The following states are executed in this SW state machine:
    \li ATA_tempmeasStateInitSSM_C:
        this state does the initialization of the registers for temperature measurement, the
        configuration of the Sequencer State Machine and starts the XTO
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready.
    \li ATA_tempmeasStateStartSSM_C:
        this state starts the SSM
    \li ATA_tempmeasStateWait4SSMrdy_C:
        this state waits for the end of the sequencer state machine.
    \li ATA_tempmeasStateWait4Temperature_C:
        this state reads the temperature value
    \li ATA_systemFlowStateShutdownTRX_C:
        this state starts the shutdown SSM.
    \li ATA_systemFlowStateWait4ShutdownRdyTRX_C:
        this state waits until the shutdown SSM has finished.
    \li ATA_tempmeasStateSetCmdRdy_C:
        this state sets CMD_RDY event
    \li ATA_triggerSelfCheck_C:
        this state triggers SRC, FRC and register refresh during self-check and calibration

    \image html SelfCheckSysFlowStateMachine.png
    \image rtf SelfCheckSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut selfCheckSysFlowStateMachine[9] = {
    ATA_tempmeasStateInitSSM_C,
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_tempmeasStateStartSSM_C,
    ATA_tempmeasStateWait4SSMrdy_C,
    ATA_tempmeasStateWait4Temperature_C,
    ATA_systemFlowStateShutdownTRX_C,
    ATA_systemFlowStateWait4ShutdownRdyTRX_C,
    ATA_tempmeasStateSetCmdRdy_C,
    ATA_triggerSelfCheck_C
};

/** \brief <b>pSubChannelingSysFlowStateMachine</b>
    points to look up table of the SW state machine used for
    sub-channeling feature.
    \details
    This pointer is initialized in function ATA_initStateMachines_C
    at system initialization. If the user wants to change this flow,
    the pointer should be modified after initialization.
*/
#pragma location = ".flowctrl"
__no_init sysFlowStateMachineFuncLut *pSubChannelingSysFlowStateMachine;

/** \brief <b>subChannelingSysFlowStateMachine</b>
    look up table of the SW state machine used for sub-channeling feature.
    \details
    The following states are executed in this SW state machine:
    \li ATA_systemFlowStateWaitXtoReady_C:
        this state waits for XTO ready.
    \li ATA_rxStateInitSubchanneling_C:
        this state reconfigures the sequencer state machine for subchanneling
    \li ATA_rxStateSubchanneling_Center_Freq_C:
        this state adjustes the receiving frequency to the center frequency
    \li ATA_rxStateSubchanneling_Lower_Freq_C:
        this state adjustes the receiving frequency to the lower frequency
    \li ATA_rxStateSubchanneling_Upper_Freq_C:
        this state adjustes the receiving frequency to the upper frequency

    \image html SubChannelingSysFlowStateMachine.png
    \image rtf SubChannelingSysFlowStateMachine.png
    \n
*/
__root sysFlowStateMachineFuncLut subChannelingSysFlowStateMachine[5] = {
    ATA_systemFlowStateWaitXtoReady_C,
    ATA_rxStateInitSubchanneling_C,
    ATA_rxStateSubchanneling_Center_Freq_C,
    ATA_rxStateSubchanneling_Lower_Freq_C,
    ATA_rxStateSubchanneling_Upper_Freq_C
};

/** \brief <b>flowCtrl</b>
    is used for software state machine control.
    The complete SW state machine flow is controlled with this variable.
*/
#pragma location = ".flowctrl"
__no_init sSystemFlowCtrl flowCtrl;


/*---------------------------------------------------------------------------*/
/*  IMPLEMENTATION                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_check4extRequests_C</b>
    checks for external requests from SPI for
    \li system mode switching
    \li tune and check
    \li service initialization
    \li ...
    If a valid external request is detected, the sw state machine are
    configured accordingly in corresponding functions.

    \return none

    \image html ATA_check4extRequests_C.png
    \image rtf ATA_check4extRequests_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_check4extRequests_C(void)
{
    //uint8_t error = 0x00U;

    /* check for command request (internal or external) */
    if(sysStatus & BM_SYS_STATUS_UPDATE)
    {
        ATA_systemModeSwitching_C();
    }
    else{
    }

    if (extReq.tuneCheckConfig) {
        ATA_tuneCheckSwitching_C();
    }
    else {
    }

    if (extReq.serviceInitConfig) {
        ATA_serviceInitSwitching_C();
    }
    else {
    }

    if (extReq.miscTrigger) {
        ATA_miscTriggerSwitching_C();
    }
    else {
    }


    if (triggerEEPwr.triggerEEPwr) {
        /* Trigger the secure write to the EEPROM.
        The Flag is reseted inside this function */
        ATA_eepromSecureWrite_C();
    }
    else{
    }
}
/*---------------------------------------------------------------------------*/
/** \brief <b> ATA_systemModeSwitching_C</b>
    checks and configures the sw state machines for system mode switching.
    If incorrect system mode switching is detected, the system sets the
    error flag and switches back to IDLEMode.

    \return none

    \image html ATA_systemModeSwitching_C.png
    \image rtf ATA_systemModeSwitching_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_systemModeSwitching_C()
{
    uint8_t error = 0x00U;
    uint8_t new_opm, last_opm;

    /* --SIX-3369-- */
    /* --SIX-3370-- */
    __disable_interrupt();
    /* --SIX-3369-- */
    /* --SIX-3370-- */
    sysStatus &= (uint8_t)~BM_SYS_STATUS_UPDATE;

    trxConf.lastSystemModeConfig = trxConf.systemModeConfig;

    /* --SIX-3369-- */
    /* --SIX-3370-- */
    // __disable_interrupt();
    /* --SIX-3369-- */
    /* --SIX-3370-- */
    trxConf.systemModeConfig     = extReq.systemModeConfig;
    extReq.systemModeConfig      = 0U;
    trxConf.serviceChannelConfig = extReq.serviceChannelConfig;
    extReq.serviceChannelConfig  = 0U;
    __enable_interrupt();

    /* SIX-1365 */
    last_opm = trxConf.lastSystemModeConfig & BM_SYS_MODE_CONFIG_OPM;
    if(last_opm == OPM_TX) {
        /* system switches from TX to other Mode (Stop TX) -> clear FIFOs */
        PRR2  |= BM_PRTM;
        DFL   |= BM_DFCLR;
        SFL   |= BM_SFCLR;
    }
    else {
        /* system switches from RXMode or PollingMode to IdleMode -> NO clearing of FIFOs */
    }
    /* SIX-1365 */

    new_opm = trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM;
    if( new_opm == OPM_IDLE )
    {
        /* systems switches to IdleMode */
        /* --SIX-3011-- */
        /* --SIX-342-- */
        ATA_SetVoltageMonitor_C(0x00U);
        /* --SIX-342-- */
        /* --SIX-3011-- */
    }
    else if( (last_opm != OPM_IDLE) && (new_opm == OPM_POLLING) )
    {   // no switching allowed if PollingMode should be started and system is not in IDLEMode
        // or RXMode or TXMode should be started while system is in PollingMode
        /* --SIX-3011-- */
        ATA_SetVoltageMonitor_C(0x00U);
        /* --SIX-3011-- */
        error = 0x01U;
    }
    else
    {
        /* systems switches to TX/RX/Polling Mode: check/prepare system for direct/normal switching */

        /* --SIX-3011-- */
        /* --SIX-342-- */
        ATA_SetVoltageMonitor_C(ATA_eepRDbyte_ASM(&eepConfValid.confVMCSR));
        /* --SIX-342-- */
        /* --SIX-3011-- */

        if (sysStatus & BM_SYS_STATUS_RDY_4_DIRECTSWITCHING) {
            // do direct switching
            trxConf.systemModeConfig |= BM_SYS_MODE_CONFIG_DIRECT_SWITCH;

            /* SIX-1365 */
            /* clear the FIFOs at all direct switch operations */
            PRR2  |= BM_PRTM;
            DFL   |= BM_DFCLR;
            SFL   |= BM_SFCLR;
            /* SIX-1365 */

        }
        else {
            ATA_stopSsmWatchdog_C();
            SSMRR = BM_SSMST;
            trxConf.systemModeConfig &= (uint8_t)~BM_SYS_MODE_CONFIG_DIRECT_SWITCH;
        }
    }

    /* remove ready for direct switch indication if switching ot another mode */
    sysStatus &= (uint8_t)~BM_SYS_STATUS_RDY_4_DIRECTSWITCHING;

    ATA_clrRxActive_ASM();

    if( error == 0x00U )
    {
        /* check parameter trxConf.serviceChannelConfig pathA/pathB */
        /* SIX-1533 */
        if (new_opm == OPM_IDLE) {
            /* no pathA/pathB setting if switching to IDLEMode */
            error = 0x00U;
        }
        else if (new_opm == OPM_TX) {
            uint8_t mask = trxConf.serviceChannelConfig & (BIT_MASK_7|BIT_MASK_6);
            if (   (mask == 0U )
                || (mask == (BIT_MASK_7|BIT_MASK_6))
               ) {
                error = 0x01U;
            }
        }
        else if (new_opm == OPM_RX) {
            uint8_t mask = trxConf.serviceChannelConfig & (BIT_MASK_7|BIT_MASK_6);
            if ( mask == 0U ) {
                error = 0x01U;
            }
        }
        else {
            /* no pathA/pathB setting if switching to PollingMode */
            error = 0x00U;
        }
        /* SIX-1533 */
        /* end of checking parameter trxConf.serviceChannelConfig pathA/pathB */
    }

    if (error == 0x00U) {

        if (new_opm == OPM_IDLE) {
            /* >>>>>>>>>>>>>>>>>> ATA_triggerIdleMode_C >>>>>>>>>>>>>>>>>> */
            ATA_stopSsmWatchdog_C();
            SSMRR = BM_SSMST;
            error = ATA_setIdleMode_C();
            /* <<<<<<<<<<<<<<<<<< ATA_triggerIdleMode_C <<<<<<<<<<<<<<<<<< */
        }
        else if (new_opm == OPM_TX) {
            /* >>>>>>>>>>>>>>>>>> ATA_triggerTxMode_C >>>>>>>>>>>>>>>>>> */
            /* --SIX-342-- */
            if (sysStatus & BM_SYS_STATUS_AVCCLOW) {
                error = 0x01U;
            }
            else {

                /* enable SFIFO/DFIFO overflow/underflow interrupt in TX anyway */
                DFI |= BM_DFERIM;
                SFI |= BM_SFERIM;

                flowCtrl.index = 0U;
                if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_TRANSPARENT_MODE) {
                    flowCtrl.pLut = pTxTransSysFlowStateMachine;
                }
                else {
                    flowCtrl.pLut = pTxBufSysFlowStateMachine;
                }

            }
            /* --SIX-342-- */
            /* <<<<<<<<<<<<<<<<<< ATA_triggerTxMode_C <<<<<<<<<<<<<<<<<< */
        }
        else if (new_opm == OPM_RX) {
            /* >>>>>>>>>>>>>>>>>> ATA_triggerRxMode_C >>>>>>>>>>>>>>>>>> */
            flowCtrl.index = 0U;
            if(trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA){
                flowCtrl.pLut = pPureRxSysFlowStateMachine;
            }
            else{
                flowCtrl.pLut = pRxSysFlowStateMachine;
            }
            /* <<<<<<<<<<<<<<<<<< ATA_triggerRxMode_C <<<<<<<<<<<<<<<<<< */
        }
        else {
            /* >>>>>>>>>>>>>>> ATA_triggerPollingMode_C >>>>>>>>>>>>>>>> */
            
            /* -- SIX-1509 -- Reset the Best Channel helper variables */
            lowestRssiOfCurPolCycle = 0xFFU;
            tempBestChannelPollingIndex = 0U;
            tempBestChannelServiceChannelConfig = 0U;
            /* -- SIX-1509 -- */
            
            // check for fast Polling
            if( pollConfig.confT1COR )
            {
                /* Timer1 controlled polling is selected */
                if( ATA_timer1Open_C( 0x00U, pollConfig.confT1MR, 0x02U, (timer1IRQHandler)0x0000, ATA_pollStateISR_ASM) == OK )
                {
                    T1COR = (uint8_t)calib.srcCorVal;

                    // signalize polling is in progress, block Timer1 ISR full functionality
                    // signalize system self-check and calibration after first polling cycle
                    pollStatus.flags = (POLLING_SELFCHECK_FIRST_CYCLE | POLLING_ACTIVE);

                    ATA_timer1ResetRun_ASM();
                }
                else
                {
                    debug.errorCode = DEBUG_ERROR_CODE_POLLING_TIMER1_LOCKED;
                    debug.ssmErrorCode = 0U;
                    error = 0x01U;  // signalize error
                }
            }
            else
            {
                /* fast Polling is selected */
                pollStatus.flags |= POLLING_FAST;
            }

            if( error == 0x00U )
            {
                pollStatus.cycleCnt = 1U;   // default polling cycle counter value

                // enable VCO calibration if selected in spi command
                if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_VCO_TUNING ) {
                    pollStatus.flags |= POLLING_VCO_CAL_ON_FIRST_CHANNEL;
                }
                else {
                    pollStatus.flags &= (uint8_t)~POLLING_VCO_CAL_ON_FIRST_CHANNEL;
                }


                // extReq.serviceChannelConfig contains the start index to pollConfig.pollChanConf[]
                pollStatus.confIdx = trxConf.serviceChannelConfig & BM_NUM_POLL_CHAN_CONFIG;

                flowCtrl.index = 0U;
                flowCtrl.pLut  = pPollSysFlowStateMachine;
            }
            /* >>>>>>>>>>>>>>> ATA_triggerPollingMode_C >>>>>>>>>>>>>>>> */
        }
    }

    if( error == 0x01U )
    {
        /* in case of incorrect request, raise error flag and go to IDLEMode */
        debug.errorCode = DEBUG_ERROR_CODE_INVALID_OPM_SWITCHING;
        debug.ssmErrorCode = 0U;
        ATA_setSystemError_ASM();

        (void)ATA_setIdleMode_C();
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b> ATA_tuneCheckSwitching_C</b>
    checks and configures the sw state machine for tune and check commands.
    If a tune and check command is detected and the system is not in IDLEMode
    the system sets the error flag.

    \return none

    \image html ATA_tuneCheckSwitching_C.png
    \image rtf ATA_tuneCheckSwitching_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_tuneCheckSwitching_C(void)
{
    __disable_interrupt();
    trxConf.tuneCheckConfig = extReq.tuneCheckConfig;
    extReq.tuneCheckConfig  = 0U;
    __enable_interrupt();

    if( (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM) == OPM_IDLE )
    {
        __disable_interrupt();
        trxConf.serviceChannelConfig = extReq.serviceChannelConfig;
        extReq.serviceChannelConfig  = 0U;
        __enable_interrupt();

        if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_ANTENNA_TUNING )
        {
            /* >>>>>>>>>> ATA_triggerAntennaTuning_C >>>>>>>>>> */
            sysStatus      |= BM_SYS_STATUS_CALIB;   // indicates a calibration process is ongoing
            flowCtrl.index  = 0U;
            flowCtrl.pLut   = pAntTuneSysFlowStateMachine;
            /* <<<<<<<<<< ATA_triggerAntennaTuning_C <<<<<<<<<< */
        }
        else if (trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_TEMP_MEASUREMENT) {
            /* Temperature Measurement */
            /* >>>>>>>>>> ATA_triggerTemperatureMeasurement_C >>>>>>>>>> */
            sysStatus      |= BM_SYS_STATUS_CALIB;  // indicates a calibration process is ongoing
            flowCtrl.index  = 0U;
            flowCtrl.pLut   = pTempMeasSysFlowStateMachine;
            /* <<<<<<<<<< ATA_triggerTemperatureMeasurement_C <<<<<<<<<< */
        }
        else if (trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_SRC_CALIB) {
            /* SRC Calibration */
            ATA_triggerSrcCalibration_C();
        }
        else if (trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_FRC_CALIB) {
            /* FRC Calibration */
            ATA_triggerFrcCalibration_C();
        }
        else if (trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_VCO_CALIB) {
            /* VCO Calibration */
            /* >>>>>>>>>> ATA_triggerVcoCalibration_C >>>>>>>>>> */
            sysStatus      |= BM_SYS_STATUS_CALIB;   // indicates a calibration process is ongoing
            flowCtrl.index  = 0U;
            flowCtrl.pLut   = pVcoCalSysFlowStateMachine;
            /* <<<<<<<<<< ATA_triggerVcoCalibration_C <<<<<<<<<< */
        }
        else if (trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_SELF_CHECK) {
            /* Self Check */
            /* <<<<<<<<<< ATA_triggerSystemSelfCheck_C <<<<<<<<<< */
            sysStatus      |= BM_SYS_STATUS_CALIB;   // indicates a calibration process is ongoing
            flowCtrl.index  = SELFCHECK_FLOW_STATE_SRCFRCREGREFRESH;
            flowCtrl.pLut   = pSelfCheckSysFlowStateMachine;

            // read self-check configuration from EEPROM
            trxConf.tuneCheckConfig = (ATA_eepRDbyte_ASM(&eepTrxCal.calConf1)|BM_TUNE_CHECK_CONFIG_SELF_CHECK);

            // check for Temperature Measurement during self-check
            if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_TEMP_MEASUREMENT )
            {
                flowCtrl.index = SELFCHECK_FLOW_STATE_TEMPMEAS;
            }
            /* <<<<<<<<<< ATA_triggerSystemSelfCheck_C <<<<<<<<<< */
        }
        else {
        }
    }
    else
    {
        __disable_interrupt();
        extReq.serviceChannelConfig = 0U;
        __enable_interrupt();
        /* in case of incorrect request, raise error flag and go to IDLEMode */
        debug.errorCode = DEBUG_ERROR_CODE_INVALID_OPM_MODE_DURING_TUNE_AND_CHECK;
        debug.ssmErrorCode = 0U;
        ATA_setSystemError_ASM();
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b> ATA_serviceInitSwitching_C</b>
    does the service initialization (including the channel switch initialization)
    according to the configuration from SPI command "Init SRAM Service".

    \return none

    \image html ATA_serviceInitSwitching_C.png
    \image rtf ATA_serviceInitSwitching_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_serviceInitSwitching_C(void)
{
    __disable_interrupt();
    trxConf.serviceInitConfig = extReq.serviceInitConfig;
    extReq.serviceInitConfig = 0U;
    __enable_interrupt();

    if (trxConf.serviceInitConfig & BM_EXT_REQ_SERVICE_INIT_CONFIG_UPDATE_FLAG) {
        /* Init SRAM service with EEPROM service */
        uint8_t sramServiceNumber = 0U;
        uint8_t eepromServiceNumber = 0U;

        sramServiceNumber   = (trxConf.serviceInitConfig & BM_EXT_REQ_SERVICE_INIT_CONFIG_SRAM_NUMBER)   >> EXT_REQ_SERVICE_INIT_CONFIG_SRAM_NUMBER;
        eepromServiceNumber = (trxConf.serviceInitConfig & BM_EXT_REQ_SERVICE_INIT_CONFIG_EEPROM_NUMBER) >> EXT_REQ_SERVICE_INIT_CONFIG_EEPROM_NUMBER;

        if(   (sramServiceNumber < NUM_SRAM_SERVICES)
           && (eepromServiceNumber < NUM_EEPROM_SERVICES) )
        {
            ATA_eepRDblock_C( (uint8_t *)&eepServices[eepromServiceNumber],
                            (uint8_t) sizeof(sServiceConfiguration),
                            (uint8_t *)&sramServices[sramServiceNumber]);
            
            /* -- SIX-2608 -- */
            ATA_eepRDblock_C( (uint8_t *)&eepServiceChannelSwitchConfig[eepromServiceNumber],
                              (uint8_t) sizeof(sEEPromServiceChannelSwitchConfig),
                              (uint8_t *)&sramServiceChannelSwitchConfig[sramServiceNumber]);
            /* -- SIX-2608 -- */
            
            trxConf.serviceInitConfig = 0U;
        }
        else
        {
            debug.errorCode = DEBUG_ERROR_CODE_SERVICE_INIT_FAILURE;
            debug.ssmErrorCode = 0U;
            ATA_setSystemError_ASM();
        }
    }
    else {
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b> ATA_miscTriggerSwitching_C</b>
    configures the SW state machine for RSSI measurement on demand.

    \return none

    \image html ATA_miscTriggerSwitching_C.png
    \image rtf ATA_miscTriggerSwitching_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_miscTriggerSwitching_C(void)
{
    /* >>>>>>>>>>>>>>>>>>> ATA_miscTriggerSwitching_C >>>>>>>>>>>>>>>>>>>> */
    __disable_interrupt();
    trxConf.miscTrigger = extReq.miscTrigger;
    extReq.miscTrigger = 0U;
    __enable_interrupt();

    if (trxConf.miscTrigger & BM_EXT_REQ_MISC_TRIGGER_START_RSSI ) {

        /* serviceChannelConfig is needed for RSSI measurement */
        __disable_interrupt();
        trxConf.serviceChannelConfig = extReq.serviceChannelConfig;
        extReq.serviceChannelConfig  = 0U;
        __enable_interrupt();

        /* set system to RX Mode */
        trxConf.systemModeConfig &= (uint8_t)~(BM_SYS_MODE_CONFIG_OPM);
        trxConf.systemModeConfig |= BM_SYS_MODE_CONFIG_OPM1;

        flowCtrl.index = 0U;
        flowCtrl.pLut = pRssiSysFlowStateMachine;

    }
    /* <<<<<<<<<<<<<<<<<<< ATA_miscTriggerSwitching_C <<<<<<<<<<<<<<<<<<<< */
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_systemFlowCtrl_C</b>
    controls the SW state machine flows.

    \return none

    \image html ATA_systemFlowCtrl_C.png
    \image rtf ATA_systemFlowCtrl_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_systemFlowCtrl_C(void)
{
    uint8_t opm = trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM;
    if (opm == OPM_IDLE) {
        // IDLEMode
        // IdleStatePreProcessing()
    }
    else if (opm == OPM_TX) {
        // TXMode
        // TxStatePreProcessing()
    }
    else if (opm == OPM_RX) {
        // RXMode
        // RxStatePreProcessing()
    }
    else {
        // PollingMode
        // ATA_pollingPreProcessing_C();
    }

    ATA_sysExeStateMachineFunc_C();
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_sysExeStateMachineFunc_C</b>
    executes the linked function pointers of different SW state machines.

    \return none

    \image html ATA_sysExeStateMachineFunc_C.png
    \image rtf ATA_sysExeStateMachineFunc_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_sysExeStateMachineFunc_C(void)
{
    if( flowCtrl.pLut )
    {
        GPIOR0 |= BIT_MASK_1;   /* set GPIOR0.1 to indicate begin of state machine activity */
        sysFlowStateMachineFunc pFunc = *(sysFlowStateMachineFunc)flowCtrl.pLut[flowCtrl.index];
        pFunc();
        GPIOR0 &= (uint8_t)~BIT_MASK_1;   /* reset GPIOR0.1 to indicate end of state machine activity */
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_sysIdleMode_C</b>
    sets the ATA5831 into IDLEMode forced internally.

    \return none

    \image html ATA_sysIdleMode_C.png
    \image rtf ATA_sysIdleMode_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_sysIdleMode_C(void)
{
    ATA_shutDownRf_C();
    ATA_shutDownFe_C();

    SSMIMR = 0x00U;     // disable SSM interrupt
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_setIdleMode_C</b>
    sets the ATA5831 into IDLEMode forced by an external command.

    \return OK or FAIL

    \image html ATA_setIdleMode_C.png
    \image rtf ATA_setIdleMode_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
uint8_t ATA_setIdleMode_C(void)
{
    uint8_t error = OK;
    uint8_t idleMode, idleModeSelector = 0U;

    if (SUPCR & BM_AVEN)
    {
        error = ATA_blockingShutDownSSM_C();
    }

    // additional time for HW SSM, probably not needed
    idleModeSelector = (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR) >> 3;
    idleMode         = trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR;

    ATA_sysIdleMode_C();

    if( idleModeSelector != idleMode )
    {
        if( idleModeSelector )
        {
            ATA_checkAndSwitchIdleXTO_C();
        }
        else{}
    }

    ATA_timer1Close_ASM();
    pollStatus.flags = 0U;

    // switch to IDLEMode
    trxConf.systemModeConfig &= (uint8_t)~BM_SYS_MODE_CONFIG_OPM;
    ATA_systemFlowStateMachineEnd_C();

    return error;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_systemFlowStateWaitXtoReady_C</b>
    checks for frontend XTO ready.

    \return none

    \image html ATA_systemFlowStateWaitXtoReady_C.png
    \image rtf ATA_systemFlowStateWaitXtoReady_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_systemFlowStateWaitXtoReady_C(void)
{
    /* do we need a security XTO ready flag counter */
    if( FESR & BM_XRDY )
    {
        if( (trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR) == 0U )
        {   // system operates in IDLE_RC mode
            ATA_clkSwitchXTO_ASM();
            trxConf.systemConfig |= BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR;
        }
        flowCtrl.index++;
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_systemStartSSM_C</b>
    starts the sequencer state machine and switch to next state.

    \param errorCode - signalled errorCode for debugging purpose

    \return none

    \image html ATA_systemStartSSM_C.png
    \image rtf ATA_systemStartSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_systemStartSSM_C( uint8_t errorCode )
{
    /* SSMIFR - SSM Interrupt Flag Register */
    SSMIFR = 0x00U;

    /* SSMSR - SSM status register */
    SSMSR |= BM_SSMERR;

    sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;     // reset flag

    /* SSMIMR - SSM Interrupt Mask Register */
    SSMIMR = BM_SSMIM;

    /* SSMRR - SSM Run Register */
    SSMRR = BM_SSMR;

    /* start WatchDog with timeout for SSM */
    if( ATA_startSsmWatchdog_C() )
    {
        debug.errorCode = errorCode;
        debug.ssmErrorCode = 0U;
        ATA_setSystemError_ASM();
    }

    flowCtrl.index++;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_systemWait4SSMrdy_C</b>
    checks for the end of the sequencer state machine signalization
    and switch to next state. On occurrence of a SSM timeout an error is raised.

    \param errorCode - signalled errorCode for debugging purpose
    \param shutdownIdx  - SW state machine index to shutdown current operation mode

    \return none

    \image html ATA_systemWait4SSMrdy_C.png
    \image rtf ATA_systemWait4SSMrdy_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_systemWait4SSMrdy_C( uint8_t errorCode, uint8_t shutdownIdx )
{
    if( (sysStatus & BM_SYS_STATUS_SSMRDY) && (SSMSR == 0x00U) )
    {
        ATA_stopSsmWatchdog_C();
        sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;
        flowCtrl.index++;
    }
    else
    {
        /* check timeout for SSM */
        if( (T2IFR & BM_T2COF) || SSMSR )
        {    /* timeout of SSM occured */
            SSMRR = BM_SSMST;       /* reset current state machine */
            ATA_stopSsmWatchdog_C();

            debug.errorCode = errorCode;
            debug.ssmErrorCode = SSMSR;
            ATA_setSystemError_ASM();

            // patch SW state to shutdown
            flowCtrl.index = shutdownIdx;
        }
        else
        {}
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_systemFlowStateShutdownTRX_C</b>
    this state machine function starts the shut down sequencer state machine.

    \return none

    \image html ATA_systemFlowStateShutdownTRX_C.png
    \image rtf ATA_systemFlowStateShutdownTRX_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_systemFlowStateShutdownTRX_C(void)
{
    ATA_startShutDownSSM_C();

    /* start WatchDog with timeout for SSM */
    if (ATA_startSsmWatchdog_C()) {
        debug.errorCode = DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMER_LOCKED;
        debug.ssmErrorCode = 0U;
        ATA_setSystemError_ASM();
    }

    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_systemFlowStateWait4ShutdownRdyTRX_C</b>
    this state machine function waits for end of ShutDown SSM.

    \return none

    \image html ATA_systemFlowStateWait4ShutdownRdyTRX_C.png
    \image rtf ATA_systemFlowStateWait4ShutdownRdyTRX_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_systemFlowStateWait4ShutdownRdyTRX_C(void)
{

    if ( (sysStatus & BM_SYS_STATUS_SSMRDY) && (SSMSR==0x00U) ) {
        ATA_stopSsmWatchdog_C();
        sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;

        ATA_sysIdleMode_C();

        // clear OPM only if no system selfcheck from PollingMode is executed
        if( pollStatus.flags & POLLING_SELFCHECK )
        {}
        else
        {
            trxConf.systemModeConfig &= (uint8_t)~BM_SYS_MODE_CONFIG_OPM;
        }

        flowCtrl.index++;
    }
    else {
        /* check timeout for SSM */
        if (( T2IFR & BM_T2COF ) || SSMSR ) {    /* timeout of SSM occured */
            SSMRR = BM_SSMST;       /* reset current state machine */
            ATA_stopSsmWatchdog_C();

            debug.errorCode = DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT;
            debug.ssmErrorCode = SSMSR;
            ATA_setSystemError_ASM();

            ATA_sysIdleMode_C();

            // clear OPM only if no system selfcheck from PollingMode is executed
            if( pollStatus.flags & POLLING_SELFCHECK )
            {}
            else
            {
                trxConf.systemModeConfig &= (uint8_t)~BM_SYS_MODE_CONFIG_OPM;
            }

            flowCtrl.index++;
        }
        else {
        }
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_systemFlowStateMachineEnd_C</b>
    common system flow state machine function for all operation modes
    this function is a empty function which do simply nothing
    and shall be the last state of each system flow state machine.

    \return none

    \image html ATA_systemFlowStateMachineEnd_C.png
    \image rtf ATA_systemFlowStateMachineEnd_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_systemFlowStateMachineEnd_C(void)
{
    flowCtrl.msmstate = 0xFFU;
    flowCtrl.index    = 0U;
    flowCtrl.pLut     = 0x0000U;

    sysStatus                &= (uint8_t)~BM_SYS_STATUS_CALIB;
    trxConf.systemModeConfig &= (uint8_t)~(BM_SYS_MODE_CONFIG_RF_CALIBRATION | BM_SYS_MODE_CONFIG_ANTENNA_TUNING | BM_SYS_MODE_CONFIG_VCO_TUNING);
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_systemErrorLoop_C</b>
    endless loop which signals a system error and stays in an endless loop.

    \param errorCode - signalled errorCode for debugging purpose

    \return none

    \image html ATA_systemErrorLoop_C.png
    \image rtf ATA_systemErrorLoop_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_systemErrorLoop_C(uint8_t errorCode)
{
    ATA_wdtDisable_C();
    debug.errorCode = errorCode;
    debug.ssmErrorCode = 0U;
    ATA_setSystemError_ASM();
    for(;;) {
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_startSsmWatchdog_C</b>
    starts Timer2 to check timeouts of HW sequencer state machines.

    \return FAIL if timer2 is locked

    \image html ATA_startSsmWatchdog_C.png
    \image rtf ATA_startSsmWatchdog_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_startSsmWatchdog_C(void)
{
    uint8_t retVal = FAIL;
    if(!(timer2.status & TMR2LOCK)) {   /* Timer2 is not locked, writing is okay */
        timer2.status |= TMR2LOCK;      /* Lock Timer2 */
        PRR1 &= (uint8_t)~BM_PRT2;      /* power up */
        T2MR = 0x00U;                   /* clk_select = SRC / prescaler = 0 */

        T2COR = 0xFFU;

        T2IFR = 0x03U;                  /* reset IRQ flags */
        T2IMR = 0x00U;                  /* disable all IRQs */
        ATA_timer2ResetRun_ASM();
        retVal = OK;
    }

    sysStatus &= (uint8_t)~BM_SYS_STATUS_SSM_SLEEP_ENABLE;
    return retVal;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_stopSsmWatchdog_C</b>
    stops the sequencer state machine watchdog.

    \return none

    \image html ATA_stopSsmWatchdog_C.png
    \image rtf ATA_stopSsmWatchdog_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_stopSsmWatchdog_C(void)
{
    ATA_timer2Close_ASM();
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_lowBatt_C</b>
    is used as interrupt handler for voltage monitor. If interrupt occurs the
    LOWBATT event in events_system is set and if configured the event pin is
    set as configured. To avoid multiple signalizations the interrupt is disabled.

    \return none

    \image html ATA_lowBatt_C.png
    \image rtf ATA_lowBatt_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
#pragma vector=VMON_vect
__interrupt void ATA_lowBatt_C(void)
{   /*lint !e957 GeWi (30jun11) ISR needs no prototype therefore Note 957 is disabled */
    VMCSR &= (uint8_t)~BM_VMIM;

    events_system |= BM_EVENTS_SYSTEM_LOWBATT;

    if (events.sysEventMask & BM_SYS_EVENT_CONFIG_LOWBATT) {
        ATA_setEventPin_ASM();
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_avccLow_C</b>
    interrupt handler for AVCCLOW. If interrupt occurs the AVCCLOW event in
    events_system is set and if configured the event pin is set as configured.
    To avoid multiple signalizations the interrupt is disabled.

    \return none

    \image html ATA_avccLow_C.png
    \image rtf ATA_avccLow_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
#pragma vector=AVCCL_vect
__interrupt void ATA_avccLow_C(void)
{   /*lint !e957 GeWi (30jun11) ISR needs no prototype therefore Note 957 is disabled */
    SUPCR &= (uint8_t)~BM_AVCCLM;

    events_system |= BM_EVENTS_SYSTEM_AVCCLOW;

    sysStatus |= BM_SYS_STATUS_AVCCLOW;

    if (events.sysEventMask & BM_SYS_EVENT_CONFIG_AVCCLOW) {
        ATA_setEventPin_ASM();
    }

    if ((trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM) == OPM_TX ) {
        debug.errorCode = DEBUG_ERROR_CODE_AVCCLOW_DURING_TX;
        debug.ssmErrorCode = 0U;
        ATA_setSystemError_ASM();
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_avccReset_C</b>
    interrupt handler for AVCCRESET. There is no signalization for this interrupt
    source available in the event bytes. To avoid multiple signalization the
    interrupt is disabled.

    \return none
*/
/*----------------------------------------------------------------------------- */
#pragma vector=AVCCR_vect
__interrupt void ATA_avccReset_C(void)
{   /*lint !e957 GeWi (30oct11) ISR needs no prototype therefore Note 957 is disabled */
    SUPCR &= (uint8_t)~BM_AVCCRM;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_checkAndSwitchIdleXTO_C</b>
    enables AVCC and waits for AVCC ready. Afterwards the SW switches to Idle XTO.

    \return none

    \image html ATA_checkAndSwitchIdleXTO_C.png
    \image rtf ATA_checkAndSwitchIdleXTO_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_checkAndSwitchIdleXTO_C(void)
{
    SUPCR |= BM_AVEN;

    ATA_wait4avcc_C();

    ATA_switchIdleXTO_ASM();
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_triggerSrcCalibration_C</b>
    triggers SRC calibration feature.

    \return none

    \image html ATA_triggerSrcCalibration_C.png
    \image rtf ATA_triggerSrcCalibration_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_triggerSrcCalibration_C(void)
{
    sysStatus |= BM_SYS_STATUS_CALIB;       // indicates a calibration process is ongoing

    // check for IDLEMode(RC)/IDLEMode(XTO)
    if( (trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR) == 0U )
    {
        // Start XTO
        ATA_checkAndSwitchIdleXTO_C();
    }

    // do calibration
    ATA_srcCalib_ASM();

    // restore original system settings
    ATA_shutDownFe_C();

    trxConf.tuneCheckConfig &= (uint8_t)~BM_TUNE_CHECK_CONFIG_SRC_CALIB;
    sysStatus               &= (uint8_t)~BM_SYS_STATUS_CALIB;   // there is no state machine for FRC cal so only the function is called and the sysStatus has to restored

    events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
    if (events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_SRC_CAL) {
        ATA_setEventPin_ASM();
    }
    else {
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_triggerFrcCalibration_C</b>
    triggers FRC calibration feature.

    \return none

    \image html ATA_triggerFrcCalibration_C.png
    \image rtf ATA_triggerFrcCalibration_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_triggerFrcCalibration_C(void)
{
    sysStatus |= BM_SYS_STATUS_CALIB;       // indicates a calibration process is ongoing

    // check for IDLEMode(RC)/IDLEMode(XTO)
    if( (trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR) == 0U )
    {
        // Start XTO
        ATA_checkAndSwitchIdleXTO_C();
    }

    // do calibration
    ATA_frcCalib_ASM();

    // restore original system settings
    ATA_shutDownFe_C();

    trxConf.tuneCheckConfig &= (uint8_t)~BM_TUNE_CHECK_CONFIG_FRC_CALIB;
    sysStatus               &= (uint8_t)~BM_SYS_STATUS_CALIB;   // there is no state machine for FRC cal so only the function is called and the sysStatus has to restored

    events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
    if (events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_FRC_CAL) {
        ATA_setEventPin_ASM();
    }
    else {
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_triggerSelfCheck_C</b>
    triggers SRC, FRC and register refresh during self-check and calibration.

    \return none

    \image html ATA_triggerSelfCheck_C.png
    \image rtf ATA_triggerSelfCheck_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_triggerSelfCheck_C(void)
{
    // check for SRC calibration during self-check
    if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_SRC_CALIB )
    {
        ATA_triggerSrcCalibration_C();
    }

    // check for FRC calibration during self-check
    if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_FRC_CALIB )
    {
        ATA_triggerFrcCalibration_C();
    }

    // check for register refresh during self-check
    if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_REG_REFRESH )
    {
        trxConf.lastServiceChannelConfig  = 0xFFU;
        trxConf.tuneCheckConfig          &= (uint8_t)~BM_TUNE_CHECK_CONFIG_REG_REFRESH;
    }

    flowCtrl.msmstate = 0xFFU;
    flowCtrl.index    = 0U;
    flowCtrl.pLut     = 0x0000U;

    sysStatus                &= (uint8_t)~BM_SYS_STATUS_CALIB;
    trxConf.systemModeConfig &= (uint8_t)~(BM_SYS_MODE_CONFIG_RF_CALIBRATION | BM_SYS_MODE_CONFIG_ANTENNA_TUNING | BM_SYS_MODE_CONFIG_VCO_TUNING);
    trxConf.tuneCheckConfig  &= (uint8_t)~BM_TUNE_CHECK_CONFIG_SELF_CHECK;


    events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
    if( events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_SELF_CHECK )
    {
        ATA_setEventPin_ASM();
    }
    else
    {}

    // check if system self-check from PollingMode was executed
    if( pollStatus.flags & POLLING_SELFCHECK )
    {
        ATA_sysIdleMode_C();                            // shutdown RF, FE and DSP

        pollStatus.flags &= (uint8_t)~POLLING_SELFCHECK;
        // enable next polling cycle
        pollStatus.flags &= (uint8_t)~POLLING_ACTIVE;
    }
    else {
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_wait4avcc_C</b>
    polls AVCC interrupt flags until AVCC is stable and enables the interrupts
    according to their EEPROM settings.

    \return none

    \image html ATA_wait4avcc_C.png
    \image rtf ATA_wait4avcc_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_wait4avcc_C(void)
{
    (void)ATA_startSsmWatchdog_C();
    do {
        // clear AVCC related flags
        SUPFR |= (BM_AVCCLF | BM_AVCCRF );
        if( T2IFR & BM_T2COF ){
            debug.errorCode = DEBUG_ERROR_CODE_AVCCLOW_TIMEOUT;
            debug.ssmErrorCode = 0U;
            ATA_setSystemError_ASM();
            break;
        }
    }while(SUPFR & (BM_AVCCLF | BM_AVCCRF ));
    ATA_stopSsmWatchdog_C();

    {
        uint8_t avccConfig = ATA_eepRDbyte_ASM(&eepTrxConf.sysConfig);
        SUPFR |= (BM_AVCCLF | BM_AVCCRF );
        SUPCR |= (avccConfig & BM_EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_AVCCLOW_DISABLE) ? 0x00U : BM_AVCCLM;
        SUPCR |= (avccConfig & BM_EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_LOWBATT_DISABLE) ? 0x00U : BM_AVCCRM;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_blockingShutDownSSM_C</b>
    shuts down SSM and waits for SSM ready signalization.

    \return OK on success, FAIL on failure

    \image html ATA_blockingShutDownSSM_C.png
    \image rtf ATA_blockingShutDownSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_blockingShutDownSSM_C(void)
{
    uint8_t error = OK;

    ATA_startShutDownSSM_C();

    /* start WatchDog with timeout for SSM */
    if( ATA_startSsmWatchdog_C() )
    {
        debug.errorCode = DEBUG_ERROR_CODE_SETIDLEMODE_TIMER_LOCKED;
        debug.ssmErrorCode = 0U;
        error = FAIL;
    }

    do
    {
        if( (sysStatus & BM_SYS_STATUS_SSMRDY) && (SSMSR == 0x00U) )
        {
            sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;
            break;
        }
        else
        {
            /* check timeout for SSM */
            if( T2IFR & BM_T2COF )       /* timeout of SSM occured */
            {
                SSMRR = BM_SSMST;       /* reset current state machine */
                debug.errorCode = DEBUG_ERROR_CODE_SETIDLEMODE_MISS_SSMRDY;
                debug.ssmErrorCode = SSMSR;
                error = FAIL;
            }
        }
    }while(error == OK);

    ATA_stopSsmWatchdog_C();

    return error;
}
