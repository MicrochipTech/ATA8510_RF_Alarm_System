/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/globals/src/globals.h $
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

/** \file globals.h Include global firmware structures.
    - sRfData includes the RF data buffer control variables
    - sRssi   includes buffer control variables for RSSI processing
    - sGlobalSystemFlags includes the global system flags
*/

#ifndef GLOBALS_H
#define GLOBALS_H
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "globals_types.h"
#include "globals_defs.h"

#if defined(__IAR_SYSTEMS_ICC__) || defined(__XC8_CC__)
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
// see globals_types.h for typedefs and structs
// see globals_defs.h for defines
/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern sTrxConfig trxConf;

extern volatile sEventData events;

extern uint8_t tmpAryApp[10];

extern uint8_t sleepModeConfig;

extern sExtReq extReq;

extern sTriggerEEP triggerEEPwr;

extern sCurrentServiceConfiguration currentService;

extern sServiceConfiguration sramServices[NUM_SRAM_SERVICES];

//extern uint8_t pollLoopConfig[16];

extern sFacLock facLock;

extern sDebug debug;

extern sRssi rssiThresholds[NUM_SERVICES][NUM_CHANNELS_PER_SERVICE];

extern uint8_t rssiAtWcok[NUM_SERVICES][NUM_CHANNELS_PER_SERVICE];

extern uint8_t frequencyOffsetAtWcok;

extern sSubChanneling subChan;

extern uint8_t rxIrqEvents[3];

/* -- SIX-2608 -- */
extern sEEPromServiceChannelSwitchConfig sramServiceChannelSwitchConfig[NUM_SRAM_SERVICES];

/* -- SIX-1509 -- */
extern __no_init sSramPollingChannelStatistics sramPollingChannelStatistics;
extern __root __no_init uint8_t lowestRssiOfCurPolCycle;
extern __root __no_init uint8_t tempBestChannelPollingIndex;
extern __root __no_init uint8_t tempBestChannelServiceChannelConfig;
/* -- SIX-1509 -- */

extern VOIDFUNC ATA_setClk_C(uint8_t val);

extern VOIDFUNC ATA_clkSwitchXTO_ASM(void);

extern VOIDFUNC ATA_clkSwitchFRC_C(void);

extern VOIDFUNC ATA_wdtDisable_C(void);

extern VOIDFUNC ATA_wdtEnable_C(void);

extern VOIDFUNC ATA_SleepMode_C(void);

extern VOIDFUNC ATA_Sleep_C(void);

extern VOIDFUNC ATA_waitNus_ASM(uint8_t time);

extern VOIDFUNC ATA_mpy16u(void);

extern VOIDFUNC ATA_divU16U8_ASM(void);

extern VOIDFUNC ATA_mulU8UbyCor_ASM(void);

extern VOIDFUNC ATA_currentServiceInit_C(svcChConfig_t config);

extern VOIDFUNC ATA_initPollingConfiguration_C(void);

extern VOIDFUNC ATA_initRssiConfiguration_C(void);

extern VOIDFUNC ATA_initFacLockedArea_C(void);

extern UINT16FUNC ATA_mulU8U8_ASM(uint8_t fac1, uint8_t fac2);

extern INT16FUNC ATA_mulS8U8_ASM(int8_t fac1, uint8_t fac2);

extern UINT32FUNC ATA_mpy16u_ASM(uint16_t fac1, uint16_t fac2);

extern INT32FUNC ATA_mpy16s_ASM(int16_t fac1, int16_t fac2);

extern VOIDFUNC ATA_copyEepSvc_ASM(uint8_t *dstPtr, uint8_t *srcPtr);

extern VOIDFUNC ATA_copyEepChannel_ASM(uint8_t *dstPtr, uint8_t *srcPtr);

extern VOIDFUNC ATA_copySramSvc_ASM(uint8_t *dstPtr, uint8_t *srcPtr);

extern VOIDFUNC ATA_copySramChannel_ASM(uint8_t *dstPtr, uint8_t *srcPtr);

/* -- SIX-2608 -- */
extern VOIDFUNC ATA_initChannelSwitchForCurrentService_C(void);

#elif defined __IAR_SYSTEMS_ASM__
/*startSimExtraction*/

/* sEEPromServiceChannelSwitchConfig */
SRAM_SERVICE0_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK    EQU 0x00
SRAM_SERVICE0_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_PATTERN EQU SRAM_SERVICE0_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK + 1

SRAM_SERVICE1_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK    EQU SRAM_SERVICE0_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_PATTERN + 1
SRAM_SERVICE1_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_PATTERN EQU SRAM_SERVICE1_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK + 1

/* sSramPollingChannelStatistics */
SRAM_POLLING_CHANNEL_STATISTICS_BESTCHANNELPOLLINGINDEX         EQU 0x00
SRAM_POLLING_CHANNEL_STATISTICS_BESTCHANNELSERVICECHANNELCONFIG EQU SRAM_POLLING_CHANNEL_STATISTICS_BESTCHANNELPOLLINGINDEX + 1

LOWEST_RSSI_OF_CUR_POL_CYCLE            EQU SRAM_POLLING_CHANNEL_STATISTICS_BESTCHANNELSERVICECHANNELCONFIG + 1
TEMP_BEST_CHANNEL_POLLING_INDEX         EQU LOWEST_RSSI_OF_CUR_POL_CYCLE + 1
TEMP_BEST_CHANNEL_SERVICE_CHANNELCONFIG EQU TEMP_BEST_CHANNEL_POLLING_INDEX + 1

/*stopSimExtraction*/

#endif

#endif /* GLOBALS_H */