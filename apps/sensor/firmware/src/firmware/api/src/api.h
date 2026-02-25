/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/api/src/api.h $
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

/** \file api.h
*/

#ifndef API_H
#define API_H

#if defined(__IAR_SYSTEMS_ICC__) || defined(__XC8_CC__)

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "../../globals/src/globals.h"
#include "../../extif/src/extif.h"
#include "../../timer1/src/timer1.h"
#include "../../timer2/src/timer2.h"
#include "../../timer3/src/timer3.h"
#include "../../timer4/src/timer4.h"
#include "../../timer5/src/timer5.h"
/*===========================================================================*/
/*  DEFINES  */
/*===========================================================================*/
#define ROM_VERSION 0x21U
#define ROMPATCH_VERSION 0x02U

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern __root const prog_char romVersion;
extern __root const prog_char romPatchVersion;

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern UINT8FUNC ATA_ReadFillLevelRxBuffer_C( void );

extern UINT8FUNC ATA_ReadFillLevelTxBuffer_C( void );

extern UINT8FUNC ATA_ReadFillLevelRssiBuffer_C( void );

extern VOIDFUNC ATA_GetEventBytes_C( uint8_t* eventsSystem, uint8_t* eventsEvents, uint8_t* eventsPower, uint8_t* eventsConfig );

extern VOIDFUNC ATA_ReadRssiBuffer_C( uint8_t* data, uint8_t dataLen );

extern VOIDFUNC ATA_ReadRxBuffer_C( uint8_t* data, uint8_t dataLen );

// --SIX-5444--  extern VOIDFUNC ATA_WriteSramRegisters_C( const uint8_t* data, uint8_t* address, uint8_t dataLen );
extern VOIDFUNC ATA_WriteSramRegisters_C( uint8_t* data, uint8_t* address, uint8_t dataLen );

extern VOIDFUNC ATA_ReadSramRegisters_C( uint8_t* data, uint8_t* address, uint8_t dataLen );

extern VOIDFUNC ATA_WriteEeprom_C( uint8_t* address, uint8_t data );

extern UINT8FUNC ATA_ReadEeprom_C( uint8_t* address );

// --SIX-5444-- extern VOIDFUNC ATA_WriteTxBuffer_C( const uint8_t* data, uint8_t dataLen );
extern VOIDFUNC ATA_WriteTxBuffer_C( uint8_t* data, uint8_t dataLen );

// --SIX-5444--extern VOIDFUNC ATA_WriteTxPreambleBuffer_C( const uint8_t* data, uint8_t dataLen );
extern VOIDFUNC ATA_WriteTxPreambleBuffer_C( uint8_t* data, uint8_t dataLen );

extern VOIDFUNC ATA_SetSystemMode_C( sysModeConfig_t systemModeConfig, svcChConfig_t serviceChannelConfig );

extern VOIDFUNC ATA_CalibrateAndCheck_C( tuneCheckConfig_t tuneCheckConfig, svcChConfig_t serviceChannelConfig );

// --SIX-- not used anymore extern VOIDFUNC ATA_SystemResetRom_C( void );
// --SIX-- not used anymore
// --SIX-- not used anymore extern VOIDFUNC ATA_SystemResetFlash_C( void );

extern UINT8FUNC ATA_GetRomVersion_C( void );

extern VOIDFUNC ATA_GetFlashVersion_C( uint8_t* versionRom, uint16_t* versionFlash, uint8_t* versionCustomerSpecific );

extern VOIDFUNC ATA_CustomerConfigurableCommand_C( void );

extern VOIDFUNC ATA_SystemReset_C( void );

extern VOIDFUNC ATA_TriggerEepromSecureWrite_C( void );

extern VOIDFUNC ATA_SetVoltageMonitor_C( uint8_t vmcsr_val );

extern VOIDFUNC ATA_OffCommand_C( void );

extern UINT16FUNC ATA_ReadTemperature_C( void );

extern VOIDFUNC ATA_InitSramService_C(uint8_t sramServiceNumber, uint8_t eepromServiceNumber);

extern VOIDFUNC ATA_StartRssiMeasurement_C( svcChConfig_t serviceChannelConfig );

extern UINT8FUNC ATA_GetRssiAverageValue_C( void );

extern UINT8FUNC ATA_GetRssiPeakValue_C( void );


// module API
extern UINT8FUNC  API_ReadFillLevelRxBuffer_C(void);
extern UINT8FUNC  API_ReadFillLevelTxBuffer_C(void);
extern UINT8FUNC  API_ReadFillLevelRssiBuffer_C(void);
extern VOIDFUNC   API_GetEventBytes_C( uint8_t* eventsSystem, uint8_t* eventsEvents, uint8_t* eventsPower, uint8_t* eventsConfig );
extern VOIDFUNC   API_ReadRssiBuffer_C( uint8_t* data, uint8_t dataLen );
extern VOIDFUNC   API_ReadRxBuffer_C( uint8_t* data, uint8_t dataLen );
// --SIX-5444-- extern VOIDFUNC   API_WriteSramRegisters_C( const uint8_t* data, uint8_t* address, uint8_t dataLen );
extern VOIDFUNC   API_WriteSramRegisters_C( uint8_t* data, uint8_t* address, uint8_t dataLen );
extern VOIDFUNC   API_ReadSramRegisters_C( uint8_t* data, uint8_t* address, uint8_t dataLen );
extern VOIDFUNC   API_WriteEeprom_C( uint8_t* address, uint8_t data );
extern UINT8FUNC  API_ReadEeprom_C( uint8_t* address );
// --SIX-5444-- extern VOIDFUNC   API_WriteTxBuffer_C( const uint8_t* data, uint8_t dataLen );
extern VOIDFUNC   API_WriteTxBuffer_C( uint8_t* data, uint8_t dataLen );
// --SIX-5444-- extern VOIDFUNC   API_WriteTxPreambleBuffer_C( const uint8_t* data, uint8_t dataLen );
extern VOIDFUNC   API_WriteTxPreambleBuffer_C( uint8_t* data, uint8_t dataLen );
extern VOIDFUNC   API_SetSystemMode_C( sysModeConfig_t systemModeConfig, svcChConfig_t serviceChannelConfig );
extern VOIDFUNC   API_CalibrateAndCheck_C( tuneCheckConfig_t tuneCheckConfig, svcChConfig_t serviceChannelConfig );
//--GW--SIX-- not used anymore extern VOIDFUNC   API_SystemResetRom_C( void );
//--GW--SIX-- not used anymore extern VOIDFUNC   API_SystemResetFlash_C( void );
extern UINT8FUNC  API_GetRomVersion_C( void );
extern VOIDFUNC   API_GetFlashVersion_C( uint8_t* versionRom, uint16_t* versionFlash, uint8_t* versionCustomerSpecific );
extern VOIDFUNC   API_CustomerConfigurableCommand_C( void );
extern VOIDFUNC   API_SystemReset_C( void );
extern VOIDFUNC   API_TriggerEepromSecureWrite_C( void );
extern VOIDFUNC   API_SetVoltageMonitor_C( uint8_t vmcsr_val );
extern VOIDFUNC   API_OffCommand_C( void );
extern UINT16FUNC API_ReadTemperature_C( void );
extern VOIDFUNC   API_InitSramService_C(uint8_t sramServiceNumber, uint8_t eepromServiceNumber);
extern VOIDFUNC   API_StartRssiMeasurement_C( svcChConfig_t serviceChannelConfig );
extern UINT8FUNC  API_GetRssiAverageValue_C( void );
extern UINT8FUNC  API_GetRssiPeakValue_C( void );

// module CALIB
extern VOIDFUNC API_rfCalibration_C(void);
extern VOIDFUNC API_anttuneStateInitSSM_C(void);
extern VOIDFUNC API_sysAntTuneSsmEnable_C(void);
extern VOIDFUNC API_anttuneStateStartSSM_C(void);
extern VOIDFUNC API_anttuneStateWait4SSMrdy_C(void);
extern VOIDFUNC API_anttuneStateSetCmdRdy_C(void);
extern VOIDFUNC API_vcocalStateInitSSM_C(void);
extern VOIDFUNC API_sysVcoCalSsmEnable_C(void);
extern VOIDFUNC API_vcocalStateStartSSM_C(void);
extern VOIDFUNC API_vcocalStateWait4SSMrdy_C(void);
extern VOIDFUNC API_vcocalStateSetCmdRdy_C(void);
extern VOIDFUNC API_tempmeasStateInitSSM_C(void);
extern VOIDFUNC API_sysTempMeasSsmEnable_C(void);
extern VOIDFUNC API_tempmeasStateStartSSM_C(void);
extern VOIDFUNC API_tempmeasStateWait4SSMrdy_C(void);
extern VOIDFUNC API_tempmeasStateWait4Temperature_C(void);
extern VOIDFUNC API_tempmeasStateSetCmdRdy_C(void);

// module EEP
extern VOIDFUNC  API_eepWRbyte_C(uint8_t *addr, uint8_t data);
extern VOIDFUNC  API_eepWRblock_C(uint8_t *addr, uint8_t *data, uint8_t len);
extern UINT8FUNC API_eepRDbyte_ASM(uint8_t *addr);
extern VOIDFUNC  API_eepRDblock_C(uint8_t *addr, uint8_t len, uint8_t *buffer);
extern VOIDFUNC  API_eepromSecureWrite_C(void);

// module EXTIF
extern UINT8FUNC API_SpiOpen_C(eSpiModi mode, uint8_t irq, uint8_t dord);
extern VOIDFUNC  API_initExtIf_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr);
extern VOIDFUNC  API_PatchSpiReady_ASM(void);
extern VOIDFUNC  API_pinChangeInterrupt0Handler_ASM(void);
extern VOIDFUNC  API_pinChangeInterrupt1Handler_ASM(void);
extern VOIDFUNC  API_SpiClose_ASM(void);
extern VOIDFUNC  API_spiSerialTransferCompleteHandler_ASM(void);
extern VOIDFUNC  API_spiRxBufferHandler_ASM(void);
extern VOIDFUNC  API_spiTxBufferHandler_ASM(void);
extern VOIDFUNC  API_portBisr_ASM(void);
extern VOIDFUNC  API_portCisr_ASM(void);
extern VOIDFUNC  API_interrupt0Handler_ASM(void);
extern VOIDFUNC  API_interrupt1Handler_ASM(void);

// module GLOBALS
extern VOIDFUNC API_setClk_C(uint8_t val);
extern VOIDFUNC API_wdtDisable_C(void);
extern VOIDFUNC API_wdtEnable_C(void);
extern VOIDFUNC API_SleepMode_C(void);
extern VOIDFUNC API_Sleep_C(void);
extern VOIDFUNC API_currentServiceInit_C(svcChConfig_t config);
extern VOIDFUNC API_initPollingConfiguration_C(void);
extern VOIDFUNC API_initRssiConfiguration_C(void);
extern VOIDFUNC API_initFacLockedArea_C(void);
extern VOIDFUNC API_clkSwitchFRC_C(void);
extern VOIDFUNC API_initChannelSwitchForCurrentService_C(void);
extern VOIDFUNC API_clkSwitchXTO_ASM(void);
extern VOIDFUNC API_copyEepSvc_ASM(uint8_t *dstPtr, uint8_t *srcPtr);
extern VOIDFUNC API_copyEepChannel_ASM(uint8_t *dstPtr, uint8_t *srcPtr);
extern VOIDFUNC API_copySramSvc_ASM(uint8_t *dstPtr, uint8_t *srcPtr);
extern VOIDFUNC API_copySramChannel_ASM(uint8_t *dstPtr, uint8_t *srcPtr);

// module IDSCAN
extern VOIDFUNC API_doIdScan_C(void);

// module INIT
extern VOIDFUNC  API_initIoConfig_C(void);
extern VOIDFUNC  API_defaultIoConfig_C(void);
extern UINT8FUNC API_systemInit_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr);
extern VOIDFUNC  API_checkWakeupSource_C(void);
extern VOIDFUNC  API_doInitialization_C(void);
extern VOIDFUNC  API_systemCalibAtStartup_C(void);

// module RF
extern UINT8FUNC API_startInitTxRxSSM_C(void);
extern VOIDFUNC  API_startShutDownSSM_C(void);
extern VOIDFUNC  API_ssmInterrupt_C(void);
extern VOIDFUNC  API_IDscanBufferFullInterrupt_C(void);
extern VOIDFUNC  API_resetSSMs_C(void);
extern VOIDFUNC  API_switchIdleXTO_ASM(void);
extern VOIDFUNC  API_setRxActive_ASM(void);
extern VOIDFUNC  API_clrRxActive_ASM(void);
extern VOIDFUNC  API_setSystemError_ASM(void);

extern VOIDFUNC  API_dataFifoOverUnderFlowHandler_ASM(void);
extern VOIDFUNC  API_rssiPreambleFifoOverUnderFlowHandler_ASM(void);

// module RFPOLLING
extern VOIDFUNC API_pollStateInitCurrentPollingChannel_C(void);
extern VOIDFUNC API_pollStateInitSSM_C(void);
extern VOIDFUNC API_pollStateWait4SSMstateGetTelegram_C(void);
extern VOIDFUNC API_pollStateWait4ShutdownRdyTRX_C(void);
extern VOIDFUNC API_pollStateCheck4NextPollingChannel_C(void);
extern VOIDFUNC API_pollStateISR_ASM(void);

// module RFRX
extern VOIDFUNC API_rxStateInitSSM_C(void);
extern VOIDFUNC API_rxStateStartSSM_C(void);
extern VOIDFUNC API_rxStateWait4SSMstateGetTelegram_C(void);
extern VOIDFUNC API_rxStateWait4SSMrdy_C(void);
extern VOIDFUNC API_pureRxUp_C(void);
extern VOIDFUNC API_rssiStateInitSSM_C(void);
extern VOIDFUNC API_rssiStateWait4SSMrdy_C(void);
extern VOIDFUNC API_rssiStateStartSSM_C(void);
extern VOIDFUNC API_rxStateInitSubchanneling_C(void);
extern VOIDFUNC API_rxStateSubchanneling_Center_Freq_C(void);
extern VOIDFUNC API_rxStateSubchanneling_Lower_Freq_C(void);
extern VOIDFUNC API_rxStateSubchanneling_Upper_Freq_C(void);
extern VOIDFUNC API_wakeCheckOkPathB_ASM(void);
extern VOIDFUNC API_wakeCheckOkPathA_ASM(void);
extern VOIDFUNC API_startOfTelegramPathB_ASM(void);
extern VOIDFUNC API_startOfTelegramPathA_ASM(void);
extern VOIDFUNC API_endOfTelegramPathB_ASM(void);
extern VOIDFUNC API_endOfTelegramPathA_ASM(void);
extern VOIDFUNC API_dataFifoFillLevelReached_ASM(void);
extern VOIDFUNC API_rssiPreambleFifoFillLevelReached_ASM(void);

// module RFTX
extern VOIDFUNC API_txStateInitSSM_C(void);
extern VOIDFUNC API_txStateStartSSM_C(void);
extern VOIDFUNC API_txStateWait4SSMrdy_C(void);
extern VOIDFUNC API_txTransparentStateWait4SSMrdy_C(void);
extern VOIDFUNC API_txStateTransparentMode_C(void);
extern VOIDFUNC API_txStateWait4FillLevel_C(void);
extern VOIDFUNC API_txStateStartTxModulator_C(void);
extern VOIDFUNC API_txStateStartWait4TransmissionComplete_C(void);
extern VOIDFUNC API_openTimer3forTxing_C(void);
extern VOIDFUNC API_sysTxingBufferedMode_C(void);
extern VOIDFUNC API_sysTxingTransparentMode_C(void);
extern VOIDFUNC API_TxModulatorTelegramFinish_ASM(void);

// module SYSTEM
extern VOIDFUNC  API_check4extRequests_C(void);
extern VOIDFUNC  API_serviceInitSwitching_C(void);
extern VOIDFUNC  API_systemFlowCtrl_C(void);
extern VOIDFUNC  API_sysExeStateMachineFunc_C(void);
extern UINT8FUNC API_setIdleMode_C(void);
extern VOIDFUNC  API_systemFlowStateWaitXtoReady_C(void);
extern VOIDFUNC  API_systemStartSSM_C(uint8_t errorCode);
extern VOIDFUNC  API_systemWait4SSMrdy_C(uint8_t errorCode, uint8_t shutdownIdx);
extern VOIDFUNC  API_systemFlowStateShutdownTRX_C(void);
extern VOIDFUNC  API_systemFlowStateWait4ShutdownRdyTRX_C(void);
extern VOIDFUNC  API_systemFlowStateMachineEnd_C(void);
extern VOIDFUNC  API_systemErrorLoop_C(uint8_t errorCode);
extern VOIDFUNC  API_lowBatt_C(void);
extern VOIDFUNC  API_avccLow_C(void);
extern VOIDFUNC  API_avccReset_C(void);
extern VOIDFUNC  API_triggerSrcCalibration_C(void);
extern VOIDFUNC  API_triggerFrcCalibration_C(void);
extern VOIDFUNC  API_triggerSelfCheck_C(void);
extern VOIDFUNC  API_wait4avcc_C(void);
extern VOIDFUNC  API_systemModeSwitching_C(void);
extern VOIDFUNC  API_tuneCheckSwitching_C(void);
extern VOIDFUNC  API_miscTriggerSwitching_C(void);
extern VOIDFUNC  API_setEventPin_ASM(void);

// module TIMER1
extern UINT8FUNC API_timer1Open_C(uint8_t ctrl, uint8_t mode, uint8_t irqMask, timer1IRQHandler ovf, timer1IRQHandler comp);
extern VOIDFUNC  API_timer1Close_ASM(void);
extern VOIDFUNC  API_timer1comintHandler_ASM(void);
extern VOIDFUNC  API_timer1ovfintHandler_ASM(void);

// module TIMER2
extern UINT8FUNC API_timer2Open_C(uint8_t ctrl, uint8_t mode, uint8_t irqMask, timer2IRQHandler ovf, timer2IRQHandler comp);
extern VOIDFUNC  API_timer2Close_ASM(void);
extern VOIDFUNC  API_timer2ComIntHandler_ASM(void);
extern VOIDFUNC  API_timer2OvfIntHandler_ASM(void);

// module TIMER3
extern UINT8FUNC API_timer3Open_C(uint8_t ctrl, uint8_t modeA, uint8_t modeB, uint8_t irqMask, timer3IRQHandler comp, timer3IRQHandler ovf, timer3IRQHandler cap);
extern VOIDFUNC  API_timer3Close_ASM(void);
extern VOIDFUNC  API_timer3ComIntHandler_ASM(void);
extern VOIDFUNC  API_timer3OvfIntHandler_ASM(void);
extern VOIDFUNC  API_timer3CapIntHandler_ASM(void);

// module TIMER4
extern UINT8FUNC API_timer4Open_C(uint8_t ctrl, uint8_t modea, uint8_t modeb, uint8_t irqMask, timer4IRQHandler comp, timer4IRQHandler ovf, timer4IRQHandler icap);
extern VOIDFUNC  API_timer4Close_ASM(void);
extern VOIDFUNC  API_timer4ComIntHandler_ASM(void);
extern VOIDFUNC  API_timer4OvfIntHandler_ASM(void);
extern VOIDFUNC  API_timer4CapIntHandler_ASM(void);

// module TIMER5
extern UINT8FUNC API_timer5Open_C(uint8_t ctrl, uint8_t irqMask, timer5IRQHandler ovf, timer5IRQHandler comp);
extern VOIDFUNC  API_timer5Close_ASM(void);
extern VOIDFUNC  API_timer5ComIntHandler_ASM(void);
extern VOIDFUNC  API_timer5OvfIntHandler_ASM(void);

#elif defined __IAR_SYSTEMS_ASM__
/*startSimExtraction*/
ROM_VERSION         EQU 0x21
ROMPATCH_VERSION    EQU 0x00
/*stopSimExtraction*/
#endif

#endif /* API_H */
