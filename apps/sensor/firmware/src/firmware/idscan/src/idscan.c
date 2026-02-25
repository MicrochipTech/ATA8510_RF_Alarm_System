/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/idscan/src/idscan.c $
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
/** \file idscan.c
*/
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "idscan.h"
#include "../../eep/src/eep.h"
#include "../../system/src/system.h"
#include "../../globals/src/globals.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_doIdScan_C</b>
    Performs the ID scanning, if enabled. Before a new scanning should be done
    the flags have to be cleared! (valid, ok)

    \return none

    \image html ATA_doIdScan_C.png
    \image rtf ATA_doIdScan_C.png
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_doIdScan_C(void)
{
    uint8_t tmp;

    ATA_doIdSubScan_C(&eepID.id[(trxConf.idScanCtrl&BM_SYS_IDS_ENABLED)].data[0]);

    tmp = trxConf.idScanStatus;

    if( ((trxConf.idScanCtrl & BM_SYS_IDS_ENABLED) >= (tmp & BM_SYS_IDS_ENABLED))
        ||
        (tmp & BM_SYS_ID_SCAN_STATUS_RESULT) )
    {
        // disable interrupts during writing variable
        _CLI;
        trxConf.idScanStatus |= BM_SYS_ID_SCAN_STATUS_VALID;
        trxConf.idScanCtrl   &= (uint8_t)~BM_SYS_IDS_ENABLED;
        _SEI;

        // signalize HW the result after completion of IDscanning
        if( trxConf.idScanStatus & BM_SYS_ID_SCAN_STATUS_RESULT )
        {
            // clear 'telegram end handling' configuration
            GTCR   &= (uint8_t)~(BM_RXTEHB | BM_RXTEHA);
            SSMFCR  = BM_SSMIDSO;   // ID ok
        }
        else
        {
            // --WORKAROUND--SIX-- SIX-1552
            tmp = PRR2; // store buffer configuration
            // --WORKAROUND--SIX-- SIX-1552

            RDSIMR = 0U;
            RDSIFR = (BM_WCOB | BM_WCOA | BM_SOTB | BM_SOTA | BM_EOTB | BM_EOTA | BM_NBITB | BM_NBITA);

            while( RDPR & BM_RDPRF )
            {}

            // disable both receiving paths
            RDPR |= (BM_PRPTA | BM_PRPTB);

            while( RDPR & BM_RDPRF )
            {}

            // --WORKAROUND--SIX-- SIX-1552
            // power-down RSSI, path A and B buffers
            PRR2 |= ( BM_PRRS | BM_PRXB | BM_PRXA );

            // restore buffer configuration
            PRR2 &= tmp;
            // --WORKAROUND--SIX-- SIX-1552

            DFL |= BM_DFCLR;    // clear data FIFO
            SFL |= BM_SFCLR;    // clear preamble FIFO

            // check for PollingMode
            if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM0 )
            {
                // clear 'telegram end handling' configuration
                GTCR &= (uint8_t)~(BM_RXTEHB | BM_RXTEHA);
            }
            else    // RXMode selected
            {
                // check for current data reception path
                if( ((GTCR&BM_RXTEHB) && (RXBC2&BM_RXBPB))
                    ||
                    ((GTCR&BM_RXTEHA) && ((RXBC2&BM_RXBPB)==0U)) )
                {   // 'restart RX after EOT' selected

                    RDSIMR = 0U;
                    RDSIFR = (BM_WCOB | BM_WCOA | BM_SOTB | BM_SOTA | BM_EOTB | BM_EOTA | BM_NBITB | BM_NBITA);

                    RDSIMR = rxIrqEvents[0];    // set mask configuration to before WCOA/B

                    // reset initial settings of id scan
                    trxConf.idScanStatus &= (uint8_t)~BM_SYS_ID_SCAN_STATUS_RESET_FLAGS;

                    trxStatus = 0U;            // reset trx status before restarting reception
                }
                else    // no 'restart RX after EOT' selected
                {
                    // clear 'telegram end handling' configuration
                    GTCR   &= (uint8_t)~(BM_RXTEHB | BM_RXTEHA);
                }
            }
            sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;

            SSMFCR = BM_SSMIDSF;    // ID fail
        }
    }
    else
    {
        sysStatus |= BM_SYS_STATUS_TRIGGER_MAIN_LOOP;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_doIdSubScan_C</b>
    Performs the ID scanning of the 3 parts [0..5, 6..11, 12..17].

    \param addr starting address of the EEPROM id

    \return none

    \image html ATA_doIdSubScan_C.png
    \image rtf ATA_doIdSubScan_C.png
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_doIdSubScan_C(uint8_t *addr)
{
    uint8_t i, cycles = (trxConf.idScanStatus & BM_SYS_IDS_ENABLED);

    cycles -= (trxConf.idScanCtrl & BM_SYS_IDS_ENABLED);

    if( cycles > 6U )
    {
        cycles = 6U;
    }
    else
    {}

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

    for( i = 0U; i < cycles; i++ )
    {
        IDB0 = EEDR;
        IDB1 = EEDR;
        IDB2 = EEDR;
        IDB3 = EEDR;
        IDC  = (EEDR | BM_IDFIM);
        _NOP;       // one cycle delay needed by HW
        if( IDS & BM_IDOK )
        {
            // disable interrupts during writing variable
            _CLI;
            trxConf.idScanStatus |= BM_SYS_ID_SCAN_STATUS_RESULT;
            _SEI;
            if(trxStatus & BM_TRX_STATUS_RX_SOTA){ /* pathA */
                events_events |= BM_EVENTS_EVENTS_ID_CHECKA;
                if(currentService.service.rxSysEvent & BM_SERVICE_RXSYSEVENT_IDCHECKA ) {
                    ATA_setEventPin_ASM();
                }
            }
            else{ /* pathB */
                events_events |= BM_EVENTS_EVENTS_ID_CHECKB;
                if(currentService.service.rxSysEvent & BM_SERVICE_RXSYSEVENT_IDCHECKB ) {
                    ATA_setEventPin_ASM();
                }
            }
            break;
        }
        else{
        }
    }
    // --SIX-3196--
    EECR2 &= (uint8_t)~(BM_EEBRE);
    // --SIX-3196--

    // disable interrupts during writing variable
    _CLI;
    trxConf.idScanCtrl += cycles;
    _SEI;
}
