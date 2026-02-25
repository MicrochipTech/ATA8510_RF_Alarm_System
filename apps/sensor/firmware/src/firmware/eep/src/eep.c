/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/eep/src/eep.c $
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
/** \file eep.c
*/

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "eep.h"
#include "../../globals/src/globals.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/
/** \brief <b>eepVersion</b>
    contains the version information etc. for the configuration tool.
*/
#pragma location = ".eepversion"
/*lint --e{528} GeWi (23nov11) suppress "eepVersion not referenced" --> GUI related EEPROM setting */
__root __no_init static uint8_t  eepVersion[8];    
/*lint -restore*/

/** \brief <b>eepDebug</b>
    contains the register setting for debugging support.
*/
#pragma location = ".eepdebug"
__root __no_init sEEPromDebug eepDebug;

/** \brief <b>eepDebounce</b>
    contains the register setting for debouncing.
*/
#pragma location = ".eepdebounce"
__root __no_init sEEPromDebouncing eepDebounce;

/** \brief <b>eepromServices</b>
    contains the service configuration in the EEPROM (could NOT be modified via ext. uC).
*/
#pragma location = ".eepserviceconfiguration"
__root __no_init sServiceConfiguration eepServices[NUM_EEPROM_SERVICES];

/** \brief <b>eepPollLoopConf</b>
    contains the polling configuration.
*/
#pragma location = ".eeppollloopconfiguration"
__root __no_init sEEPromPollLoopConf eepPollLoopConf;

/** \brief <b>eepFacLock</b>
    contains the factory locked EEPROM setting.
*/
#pragma location = ".eepfaclock"
__root __no_init sEEPromFactoryLock  eepFacLock;

/** \brief <b>eepConfValid</b>
    contains the configuration settings.
*/
#pragma location = ".eepconfvalid"
__root __no_init sEEPromConfigValid  eepConfValid;

/** \brief <b>eepIO</b>
    contains the io configuration.
*/
#pragma location = ".eepioconf"
__root __no_init sEEPromIOConfig     eepIO;

/** \brief <b>eepTrxConf</b>
    contains the transceiver configuration.
*/
#pragma location = ".eeptrxconf"
__root __no_init sEEPromTrxConfig    eepTrxConf;

/** \brief <b>eepTrxCal</b>
    contains the settings for TRX calibration.
*/
#pragma location = ".eeptrxcalib"
__root __no_init sEEPromTrxCalib     eepTrxCal;

/** \brief <b>eepID</b>
    contains the setting for IDSCAN.
*/
#pragma location = ".eepid"
__root __no_init sEEPromIDctrl       eepID;

/** \brief <b>eepWdtConf</b>
    contains the setting for watchdog timer configuration.
*/
#pragma location = ".eepwdt"
__root __no_init sEEPromWDTimer      eepWdtConf;


/** \brief <b>eepEventConf</b>
    contains the configuration of events.
*/
#pragma location = ".eepevent"
__root __no_init sEEPromEventConfig  eepEventConf;

/** \brief <b>eepSleepMode</b>
    contains the information for sleep mode configuration.
*/
#pragma location = ".eepsleepmode"
__root __no_init sEEPromSleepMode    eepSleepMode;

/** \brief <b>eepFRCcalib</b>
    contains the settings for frc calibration.
*/
#pragma location = ".eepfrccalib"
__root __no_init sEEPromFRCcalib     eepFRCcalib;

/** \brief <b>eepRssi</b>
    contains the register setting for RSSI.
*/
#pragma location = ".eeprssi"
__root __no_init sEEPromRssi eepRssi;

/** \brief <b>eepVsPa</b>
    contains the register setting for SUPCA1 in case of VSPA = 2V2.
*/
#pragma location = ".eepvspa"
__root __no_init sEEPromVsPa eepVsPa;


/* -- SIX-2608 -- */
/** \brief <b>eepServiceChannelSwitchConfig</b>
    contains the channel switch configuration for all services 
*/
#pragma location = ".eepservicechannelswitchconfig"
__root __no_init sEEPromServiceChannelSwitchConfig eepServiceChannelSwitchConfig[NUM_EEPROM_SERVICES];

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_eepWRbyte_C</b>
    writes a byte to the EEPROM.
    
    \param addr Address to be written
    \param data Data to be written
    
    \return none
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_eepWRbyte_C(uint8_t *addr, uint8_t data)
{
    __disable_interrupt();
    while(EECR & BM_NVMBSY){}
    /*lint -e923 GeWi (23nov2011)*/
    /* disable lint error 923 - Cast between pointer type and an integral type.
     * Misra Rule 11.3 says: Casting between a pointer and an integer type should be avoided where possible,
     * but may be unavoidable when addressing memory mapped registers or other hardware specific features. 
     */
    EEARH = (uint8_t)((uint16_t)addr >> 8U);
    EEARL = (uint8_t)((uint16_t)addr >> 0U);
    /*lint -restore */
    EEDR = data;
    EECR &= (uint8_t)~(BM_EEPM1 | BM_EEPM0);
    EECR |= BM_EEMWE;
    EECR |= BM_EEWE;
    __enable_interrupt();
}
/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_eepWRblock_C</b>
    writes a data block to EEPROM.
    
    \param *addr Address to be written
    \param *data Data to be written
    \param len   Number of bytes to be written
    
    \return none
*/
/*---------------------------------------------------------------------------*/
/*lint --e{818}*/
VOIDFUNC ATA_eepWRblock_C(uint8_t *addr, uint8_t *data, uint8_t len)
{
    uint8_t i = 0U;
    for(i=0U; i<len; i++) {
        ATA_eepWRbyte_C(addr++,*data++);
    }
}
/*lint -restore */

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_eepRDblock_C</b>
    reads a data block from EEPROM.
    
    \param *addr address to be read
    \param len number of bytes to read
    \param *buffer address to store read data
    
    \return none
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_eepRDblock_C(uint8_t *addr, uint8_t len, uint8_t *buffer)
{
    uint8_t i, *data;
    data = buffer;

    while(EECR & BM_EEWE){}
    /*lint -e923 GeWi (23nov2011)*/
    /* disable lint error 923 - Cast between pointer type and an integral type.
     * Misra Rule 11.3 says: Casting between a pointer and an integer type should be avoided where possible,
     * but may be unavoidable when addressing memory mapped registers or other hardware specific features. 
     */
    EEARH = (uint8_t)((uint16_t)addr >> 8U);
    EEARL = (uint8_t)((uint16_t)addr >> 0U);
    /*lint -restore */
    EECR2 |= BM_EEBRE;

    for( i=0x00U; i<len; i++){
        *data++ = EEDR;
    }

    // --SIX-3196--
    EECR2 &= (uint8_t)~(BM_EEBRE);
    // --SIX-3196--
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_eepromSecureWrite_C</b>
    Routine checks if a EEPROM secure write has to be triggered. If this is
    the case, the data residing in SRAM will be copied to SRAM.
    
    \return none
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_eepromSecureWrite_C(void)
{
    uint16_t eepPtr;
    /* Secure EEPROM write */
    if(triggerEEPwr.triggerEEPwr==(uint8_t)0xEE){
        triggerEEPwr.triggerEEPwr = (uint8_t)0x00;
        //EEPROM write is triggered
        eepPtr = (uint8_t)tmpAryApp[0];
        eepPtr = ( (eepPtr & 0x00FFU) << 8U);
        eepPtr |= (uint8_t)tmpAryApp[1];
        /*lint -e923 GeWi (23nov2011)*/
        /* disable lint error 923 - Cast between pointer type and an integral type.
         * Misra Rule 11.3 says: Casting between a pointer and an integer type should be avoided where possible,
         * but may be unavoidable when addressing memory mapped registers or other hardware specific features. 
         */
        ATA_eepWRblock_C((uint8_t *)eepPtr,(uint8_t *)&tmpAryApp[3],tmpAryApp[2]);
        /*lint -restore */
    }
}
