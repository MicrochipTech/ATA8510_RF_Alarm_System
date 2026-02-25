/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/extif/src/extif.c $
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
/** \file extif.c
*/
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "extif.h"
#include "../../timer4/src/timer4.h"
#include "../../eep/src/eep.h"
#include "../../system/src/system.h"

/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/
/** \brief <b>extIf</b>
    contains the variables used for spi communication.
*/
#pragma location = ".ifram"
__root __no_init sIFData        extIf;

/** \brief <b>customCmd</b>
    contains the variables used for a customer specific spi command.
*/
#pragma location = ".customcmd"
__root __no_init sCustomCommand customCmd;


/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_SpiOpen_C</b>
    opens and initializes the AVR - SPI peripheral of the system.

    \param mode
        \li Mode0: (Lead. edge) Sample rising, (Trail. edge) Setup falling
        \li Mode1: (Lead. edge) Setup rising, (Trail. edge) Sample falling
        \li Mode2: (Lead. edge) Sample falling, (Trail. edge) Setup rising
        \li Mode3: (Lead. edge) Setup falling, (Trail. edge) Sample rising

    \param irq
        \li TRUE => IRQ is enabled,
        \li FALSE => IRQ is disabled

    \param dord
        \li SpiMSB => MSB first
        \li SpiLSB => LSB first

    \return on success 0 (okay)

    \image html ATA_SpiOpen_C.png
    \image rtf ATA_SpiOpen_C.png
    \n
    */
/*----------------------------------------------------------------------------- */
UINT8FUNC ATA_SpiOpen_C(eSpiModi mode, uint8_t irq, uint8_t dord)
{
    uint8_t tmp;
    uint8_t retVal = FAIL;
    if(SPCR!=(uint8_t)0x00){ /* SPI already opened */
        /* return (uint8_t)FAIL; */
    }
    else{
        PRR0 &= (uint8_t)~BM_PRSPI;/* power Up SPI */
        /* Setup SPI control Register SPCR */
        tmp = (uint8_t)mode;

        if(dord==SPILSB){
            tmp |= (uint8_t)BM_DORD;
        }else{
            /* bit is already cleared */
        }
        if(irq){
            tmp |= (uint8_t)BM_SPIE;
        }else{
            /* bit is already cleared */
        }
        tmp |= (uint8_t)BM_SPE;/* enable SPI operation */
        SPCR = (uint8_t)tmp;
        SPDR = (uint8_t)0x00;
        /* Setup SPI Status Register SPSR */
        SPSR = (uint8_t)0x00;

        /* Setup SPI I/O pins. /SS, SCK, MOSI to input and MISO to output */

        DDRB &= (uint8_t)(~BM_DDRB5);
        DDRB |= BM_DDRB3;

        /* Int1 setup for /SS */
        EICRA |= BM_ISC10;
        EICRA &= (uint8_t)~(BM_ISC11);
        EIMSK |= BM_INT1;

        retVal = OK;
    }
    return retVal;
}

/* --SIX-3361-- */
/* --SIX-3370-- */
/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_spiClose_C</b>
    closes SPI interface
 */
/*----------------------------------------------------------------------------- */
#pragma location =  ".romv212"
VOIDFUNC ATA_spiClose_C(void)
{
    // switch off SPI interrupts
    // INT1
    EIMSK &= (uint8_t)~(BM_INT1); 
    EICRA &= (uint8_t)~(BM_ISC11 | BM_ISC10);
    // SPI
    SFIR   = 0U; // SFIR.SRIE, SFIR.STIE
    SPCR   = 0U; //
    // remove power from SPI block
    PRR0 |= BM_PRSPI;
    
    // restore PORTB configuration from EEPROM
    uint8_t portMask = PORTB & (uint8_t)~(BM_PORTB5|BM_PORTB3|BM_PORTB2|BM_PORTB1);
    portMask |= ( ATA_eepRDbyte_ASM(&eepIO.confPORTB) & (BM_PORTB5|BM_PORTB3|BM_PORTB2|BM_PORTB1) );
    PORTB  = portMask;
    
    uint8_t ddrMask  = DDRB & (uint8_t)~(BM_DDRB5|BM_DDRB3|BM_DDRB2|BM_DDRB1);  
    ddrMask |= ( ATA_eepRDbyte_ASM(&eepIO.confDDRB) & (BM_DDRB5|BM_DDRB3|BM_DDRB2|BM_DDRB1) );
    DDRB   = ddrMask;
    
    sysStatus &= (uint8_t)~BM_SYS_STATUS_SPI_CMD_IN_PROGRESS;
}
/* --SIX-3370-- */
/* --SIX-3361-- */


/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_initExtIf_C</b>
    does the initialization of extif software module.

    \param pBisr function pointer for PC int on portB
    \param pCisr function pointer for PC int on portC
    \param i0isr function pointer for irq on int0

    \return none

    \image html ATA_initExtIf_C.png
    \image rtf ATA_initExtIf_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_initExtIf_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr)
{
    /* always to be done to get the SPI working */
    extIf.pcInt0old = PINB;
    extIf.pcInt1old = PINC;
    extIf.pcInt0    = pBisr;
    extIf.pcInt1    = pCisr;
    /* INT0 configuration */
    extIf.irqInt0   = i0isr;
}
