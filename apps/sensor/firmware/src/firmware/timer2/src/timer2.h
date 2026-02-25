/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/timer2/src/timer2.h $
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
/** \file timer2.h
*/

#ifndef TIMER2_H
#define TIMER2_H

#if defined(__IAR_SYSTEMS_ICC__) || defined(__XC8_CC__)
/*---------------------------------------------------------------------------*/
/*  INCLUDES                                                                 */
/*---------------------------------------------------------------------------*/
#include "../../stdc/src/stdc.h"

/*---------------------------------------------------------------------------*/
/*  DEFINES                                                                  */
/*---------------------------------------------------------------------------*/

/** \brief <b>TMR2LOCK</b>
    is the set-mask for sTmr2Config.status lock bit.
*/
#define TMR2LOCK    (uint8_t)0x80

/** \brief <b>TMR2UNLOCK</b>
    is the reset-mask for sTmr2Config.status lock bit.
*/
#define TMR2UNLOCK  (uint8_t)0x7F

/*---------------------------------------------------------------------------*/
/*  TYPE DEFINITIONS                                                         */
/*---------------------------------------------------------------------------*/
/** \brief <b>timer2IRQHandler</b>
    is used for function pointer definition of Timer2 ISRs.
*/
typedef void (*timer2IRQHandler)(void);

/*----------------------------------------------------------------------------- */
/** \brief <b>sTmr2Config</b>
    contains the status and the function pointers for Timer2 ISRs
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief status
        contains timer 2 lock indicator
        \li Bit 7:    lock indicator (0:unlocked/1:locked)
        \li Bit 6..0: rfu
    */
    uint8_t status;

    /** \brief <b>compIsr</b>
        is used as function pointer which is executed at timer2 compare interrupt
        to allow flexible usage of this interrupt source in firmware and user software
    */
    timer2IRQHandler compIsr;

    /** \brief <b>ovfIsr</b>
        is used as function pointer which is executed at timer2 overflow interrupt
        to allow flexible usage of this interrupt source in firmware and user software
    */
    timer2IRQHandler ovfIsr;
}sTmr2Config;

/*---------------------------------------------------------------------------*/
/*  EXTERNAL PROTOTYPES                                                      */
/*---------------------------------------------------------------------------*/

extern sTmr2Config timer2;

extern UINT8FUNC ATA_timer2Open_C(uint8_t ctrl, uint8_t mode, uint8_t irqMask, timer2IRQHandler ovf, timer2IRQHandler comp);

extern VOIDFUNC ATA_timer2Close_ASM(void);

extern VOIDFUNC ATA_timer2ComIntHandler_ASM(void);

extern VOIDFUNC ATA_timer2OvfIntHandler_ASM(void);

extern VOIDFUNC ATA_timer2ResetRun_ASM(void);

#elif defined __IAR_SYSTEMS_ASM__
#endif

#endif /* TIMER2_H */