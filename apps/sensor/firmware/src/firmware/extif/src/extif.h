/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/extif/src/extif.h $
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

/** \file extif.h
*/

#ifndef EXTIF_H
#define EXTIF_H

#if defined(__IAR_SYSTEMS_ICC__) || defined(__XC8_CC__)

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "../../globals/src/globals.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/** \brief <b>SPILSB</b>
    is the setting for dord if spi is lsb first
*/
#define SPILSB           (uint8_t)1

/** \brief <b>SPIMSB</b>
    is the setting for dord if spi is msb first
*/
#define SPIMSB           (uint8_t)0

/** \brief <b>SPIIRQon</b>
    is the enable setting for the spi irq
*/
#define SPIIRQon         (uint8_t)1

/** \brief <b>SPIIRQoff</b>
    is the disable setting for the spi irq
*/
#define SPIIRQoff        (uint8_t)0

/** \brief <b>IDLE</b>
    is the idle mode setting for extif.status variable
*/
#define IDLE             (uint8_t)0      /* spi.status */

/*===========================================================================*/
/*  TYPE DEFINITIONS                                                         */
/*===========================================================================*/

/** \brief <b>pcIntHandler</b>
    is used for function pointer definition of pin change ISRs.
*/
typedef void (*pcIntHandler)(void);

/** \brief <b>irqIntHandler</b>
    is used for function pointer definition of int0 ISR.
*/
typedef void (*irqIntHandler)(void);

/** \brief <b>flashFunc</b>
    is used for function pointer definition to add or patch the SPI functionality.
*/
typedef void (*flashFunc)(void);



/*----------------------------------------------------------------------------- */
/** \brief <b>eSpiModi</b>
    contains definition of the different SPI modes
*/
/*----------------------------------------------------------------------------- */
typedef enum{
    /** \brief <b>SpiMode0</b>
        (Lead. edge) Sample rising, (Trail. edge) Setup falling
    */
    SpiMode0 = 0,
    /** \brief <b>SpiMode1</b>
        (Lead. edge) Setup rising, (Trail. edge) Sample falling
    */
    SpiMode1,
    /** \brief <b>SpiMode2</b>
        (Lead. edge) Sample falling, (Trail. edge) Setup rising
    */
    SpiMode2,
    /** \brief <b>SpiMode3</b>
        (Lead. edge) Setup falling, (Trail. edge) Sample rising
    */
    SpiMode3

}eSpiModi;

/*----------------------------------------------------------------------------- */
/** \brief <b>sIFData</b>
    contains the configuration/variables which are used for SPI communication
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>tmp[2]</b>
        used as temporary registers for storing address info.
    */
    volatile uint8_t tmp[2];

    /** \brief <b>pcInt0</b>
        is the function pointer to the routine executed, , when an IRQ occures via PCINT0.
    */
    pcIntHandler pcInt0;

    /** \brief <b>pcInt1</b>
        is the function pointer to the routine executed, when an IRQ occures via PCINT1.
    */
    pcIntHandler pcInt1;

    /** \brief <b>pcInt0old</b>
        is the old value of pcint0, to detect which pin caused the IRQ.
    */
    uint8_t pcInt0old;

    /** \brief <b>pcInt1old</b>
        is the old val of pcint1, to detect which pin caused the IRQ.
    */
    uint8_t pcInt1old;

    /** \brief <b>irqInt0</b>
        is the function pointer to a function executed, when irq0 triggers the system.
    */
    irqIntHandler irqInt0;

    /** \brief <b>flashPtr</b>
        is the function pointer to a function residing in flash to add or patch the SPI functionality.
    */
    flashFunc flashPtr;

    /** \brief <b>addressPtr[2]</b>
        used as address pointer for storing addresses of block read/write.
    */
    volatile uint8_t addressPtr[2];

    /** \brief <b>length</b>
        used as length indicator for buffer read/write commands.
    */
    volatile uint8_t length;

}sIFData;

/*----------------------------------------------------------------------------- */
/** \brief <b>sCustomCommand</b>
    contains data for patching the spi interface to enable a customer specific
    command.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>customPtr</b>
        is a pointer to a function residing in flash to add or patch the SPI
        functionality.
    */
    flashFunc customPtr;
}sCustomCommand;

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern UINT8FUNC ATA_SpiOpen_C(eSpiModi mode, uint8_t irq, uint8_t dord);

/* --SIX-3370-- */
/* --SIX-3361-- */
extern VOIDFUNC  ATA_spiClose_C(void);
/* --SIX-3361-- */
/* --SIX-3369-- */
extern VOIDFUNC  ATA_pureRxModeCtrl_v212_ASM(void);
/* --SIX-3369-- */
/* --SIX-3370-- */

extern VOIDFUNC  ATA_SpiClose_ASM(void);

extern VOIDFUNC  ATA_SpiReset_ASM(void);

extern VOIDFUNC  ATA_portBisr_ASM(void);

extern VOIDFUNC  ATA_portCisr_ASM(void);

extern VOIDFUNC  ATA_pureRxModeCtrl_ASM(void);

extern VOIDFUNC ATA_PatchSpiReady_ASM(void);

extern VOIDFUNC ATA_initExtIf_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr);

extern sIFData extIf;

extern sCustomCommand customCmd;

#elif defined __IAR_SYSTEMS_ASM__
/*startSimExtraction*/
IDLE                          EQU 0x00

/* sIFData */
IFDATA_TMP0                   EQU   0x00
IFDATA_TMP1                   EQU   IFDATA_TMP0 + 1

IFDATA_PCINT0PTRL             EQU   IFDATA_TMP1 + 1
IFDATA_PCINT0PTRH             EQU   IFDATA_PCINT0PTRL + 1
IFDATA_PCINT1PTRL             EQU   IFDATA_PCINT0PTRH + 1
IFDATA_PCINT1PTRH             EQU   IFDATA_PCINT1PTRL + 1

IFDATA_PCINT0OLD              EQU   IFDATA_PCINT1PTRH + 1
IFDATA_PCINT1OLD              EQU   IFDATA_PCINT0OLD + 1

IFDATA_INT0PTRL               EQU   IFDATA_PCINT1OLD + 1
IFDATA_INT0PTRH               EQU   IFDATA_INT0PTRL + 1

IFDATA_FLASHPTRL              EQU   IFDATA_INT0PTRH + 1
IFDATA_FLASHPTRH              EQU   IFDATA_FLASHPTRL + 1

IFDATA_ADDRESSPTRL            EQU   IFDATA_FLASHPTRH + 1
IFDATA_ADDRESSPTRH            EQU   IFDATA_ADDRESSPTRL + 1

IFDATA_LENGTH                 EQU   IFDATA_ADDRESSPTRH + 1

/* sCustomCommand */
CUSTOMCOMMAND_CUSTOMPTRL      EQU 0x00
CUSTOMCOMMAND_CUSTOMPTRH      EQU 0x01



MAXCOMMANDS             EQU 0x21

TX_BUFFER_FIFO_SIZE     EQU 0x04
RX_BUFFER_FIFO_SIZE     EQU TX_BUFFER_FIFO_SIZE

TX_DIR                  EQU 1
RX_DIR                  EQU 0
/*stopSimExtraction*/

#endif

#endif /* EXTIF_H */