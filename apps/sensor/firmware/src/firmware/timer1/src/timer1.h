/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/timer1/src/timer1.h $
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

/** \file timer1.h
 */

#ifndef TIMER1_H
#define TIMER1_H
/*---------------------------------------------------------------------------*/
/*  INCLUDES                                                                 */
/*---------------------------------------------------------------------------*/
#include "../../stdc/src/stdc.h"

/*---------------------------------------------------------------------------*/
/*  DEFINES                                                                  */
/*---------------------------------------------------------------------------*/

/** \brief <b>TMR1LOCK</b> 
    is the set-mask for sTmr1Config.status lock bit.
*/
#define TMR1LOCK    (uint8_t)0x80

/** \brief <b>TMR1UNLOCK</b> 
    is the reset-mask for sTmr1Config.status lock bit.
*/
#define TMR1UNLOCK  (uint8_t)0x7F

/** \brief <b>TMR1ENA</b> 
    is the bitmask for T1ENA in T1CR.
*/
#define TMR1ENA     (uint8_t)0x80

/*---------------------------------------------------------------------------*/
/*  TYPE DEFINITIONS                                                         */
/*---------------------------------------------------------------------------*/

/** \brief <b>timer1IRQHandler</b>
    is used for function pointer definition of Timer1 ISRs
*/
typedef void (*timer1IRQHandler)(void);

/*----------------------------------------------------------------------------- */
/** \brief <b>sTmr1Config</b> 
    contains the status and the function pointers for Timer1 ISRs.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief  <b>status</b>
        contains Timer1 lock indicator
        \li Bit 7:    lock indicator (0:unlocked/1:locked)
        \li Bit 6..0: rfu
    */
    uint8_t status;

    /** \brief <b>compIsr</b>
        is used function pointer which is executed at timer1 compare interrupt 
        to allow flexible usage of this interrupt source in firmware and user software
    */
    timer1IRQHandler compIsr;

    /** \brief <b>ovfIsr</b>
        is used as function pointer which is executed at timer1 overflow interrupt 
        to allow flexible usage of this interrupt source in firmware and user software
    */
    timer1IRQHandler ovfIsr;
}sTmr1Config;

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern sTmr1Config timer1;

extern UINT8FUNC ATA_timer1Open_C(uint8_t ctrl, uint8_t mode, uint8_t irqMask, timer1IRQHandler ovf, timer1IRQHandler comp);

extern VOIDFUNC ATA_timer1Close_ASM(void);

extern VOIDFUNC ATA_timer1comintHandler_ASM(void);

extern VOIDFUNC ATA_timer1ovfintHandler_ASM(void);

extern VOIDFUNC ATA_timer1ResetRun_ASM(void);

#endif /* TIMER1_H */