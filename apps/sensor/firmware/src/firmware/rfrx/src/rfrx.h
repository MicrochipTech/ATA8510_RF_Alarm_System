/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/rfrx/src/rfrx.h $
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
/** \file rfrx.h
 */

#ifndef RFRX_H
#define RFRX_H


#ifdef __IAR_SYSTEMS_ICC__

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "../../globals/src/globals.h"
#include "../../system/src/system.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  TYPE DEFINITIONS                                                         */
/*===========================================================================*/

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern VOIDFUNC ATA_startInitRxSSM_C(void);

extern VOIDFUNC ATA_doFrequencySettingsRx_C(void);

extern VOIDFUNC ATA_configureRxSSM_C(void);

extern VOIDFUNC ATA_initCorrelator_C(void);

extern VOIDFUNC ATA_initRxBuffer_C(void);

extern VOIDFUNC ATA_initRssiBuffer_C(void);

extern VOIDFUNC ATA_rxStateInitSSM_C(void);

extern VOIDFUNC ATA_rxStateStartSSM_C(void);

extern VOIDFUNC ATA_rxStateWait4SSMstateGetTelegram_C(void);

extern VOIDFUNC ATA_rxStateWait4SSMrdy_C(void);

extern VOIDFUNC ATA_pureRxUp_C(void);

extern VOIDFUNC ATA_rssiStateInitSSM_C(void);

extern VOIDFUNC ATA_rssiStateWait4SSMrdy_C(void);

extern VOIDFUNC ATA_rssiStateStartSSM_C(void);

extern VOIDFUNC ATA_rxStateInitSubchanneling_C(void);

extern VOIDFUNC ATA_rxStateSubchanneling_Center_Freq_C(void);

extern VOIDFUNC ATA_rxStateSubchanneling_Lower_Freq_C(void);

extern VOIDFUNC ATA_rxStateSubchanneling_Upper_Freq_C(void);

#elif defined __IAR_SYSTEMS_ASM__

#endif

#endif /* RFRX_H */