/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/timer2/src/timer2.c $
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
/** \file timer2.c
*/

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "timer2.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/


/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/
/** \brief <b>timer2</b>
    contains the configuration settings for Timer2.
*/
#pragma location = ".tmr2ram"
__no_init sTmr2Config timer2;

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/** \brief <b>ATA_timer2Open_C</b>
    opens and initializes Timer2.

    \param ctrl setting for T2CR register
    \param mode setting for T2MR register
    \param irqMask setting for T2IMR register
    \param ovf  function pointer for Timer2 overflow interrupt 
    \param comp function pointer for Timer2 compare interrupt

    \return OK on success, FAIL on failure 
    
    \image html ATA_timer2Open_C.png
    \image rtf ATA_timer2Open_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_timer2Open_C(uint8_t ctrl, uint8_t mode, uint8_t irqMask, timer2IRQHandler ovf, timer2IRQHandler comp)
{
	uint8_t retVal = FAIL;
    /* Opens Timer2 in the desired configuration */
    if(!(timer2.status&TMR2LOCK)){      /* Timer2 is not locked, writing is okay */
        PRR1 &= (uint8_t)~BM_PRT2;      /* power up */
        timer2.status |= TMR2LOCK;      /* Lock Timer2 */
        T2MR = mode;
        T2CR = ctrl;
        T2IFR |= ((uint8_t)(BM_T2COF|BM_T2OFF));  /* reset all possible flags */
        timer2.compIsr = comp;
        timer2.ovfIsr = ovf;
        T2IMR = irqMask;
        retVal = OK;
    }
    return retVal;
}
