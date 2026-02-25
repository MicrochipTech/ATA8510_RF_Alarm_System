/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/rfrx/src/rfrx.c $
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
/*---------------------------------------------------------------------------*/
/*  INCLUDES                                                                 */
/*---------------------------------------------------------------------------*/
#include "rfrx.h"
#include "../../rf/src/rf.h"
#include "../../rftx/src/rftx.h"
#include "../../globals/src/globals.h"
#include "../../eep/src/eep.h"
#include "../../system/src/system.h"
#include "../../idscan/src/idscan.h"

/*---------------------------------------------------------------------------*/
/*  DEFINES                                                                  */
/*---------------------------------------------------------------------------*/
// RSSI FIFO fill level to read out RSSI value used for subchanneling
#define MIN_RSSI_FIFO_FILL_LEVEL_4_SUBCHANNELING    1U

/*---------------------------------------------------------------------------*/
/*  Modul Globals                                                            */
/*---------------------------------------------------------------------------*/
static VOIDFUNC ATA_rxIntConfPathA_C(void);
static VOIDFUNC ATA_rxIntConfPathB_C(void);
static VOIDFUNC ATA_signalEotAtSsmRdy_C(void);

/*---------------------------------------------------------------------------*/
/*  IMPLEMENTATION                                                           */
/*---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_doFrequencySettingsRx_C</b>
    does the Rx specific frequency settings.

    \return none

    \image html ATA_doFrequencySettingsRx_C.png
    \image rtf ATA_doFrequencySettingsRx_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_doFrequencySettingsRx_C(void)
{
    uint32_t frequency = ((uint32_t)currentService.channel.FFREQ[2] << 16U)
                        |((uint32_t)currentService.channel.FFREQ[1] <<  8U)
                        |((uint32_t)currentService.channel.FFREQ[0] <<  0U);

    FFREQ2H = FFREQ1H;
    FFREQ2M = FFREQ1M;
    FFREQ2L = FFREQ1L;

    FSCR    = BM_TXMOD | BM_SFM;    // switch to frequency FFREQ2

    FFREQ1H = (uint8_t)(frequency >> 16U);
    FFREQ1M = (uint8_t)(frequency >>  8U);
    FFREQ1L = (uint8_t)(frequency >>  0U);

    FSCR    = 0x00U;                // switch back to FFREQ1
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_startInitRxSSM_C</b>
    does the Rx specific initalization of TxRx sequencer state machine.

    \return none

    \image html ATA_startInitRxSSM_C.png
    \image rtf ATA_startInitRxSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_startInitRxSSM_C(void)
{
    PRR0 &= (uint8_t)~BM_PRTXDC;
    PRR0 &= (uint8_t)~BM_PRRXDC;
    PRR2 &= (uint8_t)~BM_PRSSM;

    PRR2 |= BM_PRTM;

    ATA_doFrequencySettingsRx_C();

    RDSIMR = 0U;

    CHDN = currentService.service.CHDN;
    CHCR = currentService.service.CHCR;

    DMCRA = currentService.service.DMCRA;
    DMCRB = currentService.service.DMCRB;

    DMDRA = currentService.service.DMDRA;
    DMMA  = currentService.service.DMMA;

    DMDRB = currentService.service.DMDRB;
    DMMB  = currentService.service.DMMB;

    DMCDA = currentService.service.DMCDA;
    SYCA  = currentService.service.SYCA;

    DMCDB = currentService.service.DMCDB;
    SYCB  = currentService.service.SYCB;

    SOTC1A = currentService.service.SOT1A;
    SOTC2A = currentService.service.SOT2A;
    SOTC1B = currentService.service.SOT1B;
    SOTC2B = currentService.service.SOT2B;

    EOTC1A = currentService.service.EOT1A;
    EOTC2A = currentService.service.EOT2A;
    EOTC3A = currentService.service.EOT3A;
    EOTC1B = currentService.service.EOT1B;
    EOTC2B = currentService.service.EOT2B;
    EOTC3B = currentService.service.EOT3B;

    WCOTOA = currentService.service.WCOtimeOutA;
    WCOTOB = currentService.service.WCOtimeOutB;

    SOTTOA = currentService.service.SOTtimeOutA;
    SOTTOB = currentService.service.SOTtimeOutB;

    ATA_initCorrelator_C();
    ATA_initRxBuffer_C();

    /* init RSSI_BUF */
    if( (currentService.service.rssiSysConf & BM_SERVICE_RSSISYSCONF_RSSI_ENABLE)
        ||
        (currentService.service.rxSysSet & BM_SERVICE_RXSYSSET_SUBCHANNELING) )
    {
        ATA_initRssiBuffer_C();
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_configureRxSSM_C</b>
    does the configuration of Rx sequencer state machine.

    \return none

    \image html ATA_configureRxSSM_C.png
    \image rtf ATA_configureRxSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_configureRxSSM_C(void)
{
    /* SSMRR - SSM Run Register*/
    SSMRR = BM_SSMST;   /* set SSM in stop state to reset SSM */

    SSMSR |= BM_SSMERR;

    /* SSMCR - SSM Control Register*/
    SSMCR = 0U;
    SSMCR |= (currentService.service.RDOCR & BM_ETRPB) ? BIT_MASK_7 : 0x00U;
    SSMCR |= (currentService.service.RDOCR & BM_ETRPA) ? BIT_MASK_6 : 0x00U;

    /* SSMRCR - SSM Rx Control Register*/
    SSMRCR  = (trxConf.serviceChannelConfig & (BM_SVC_CH_CONFIG_PATHB | BM_SVC_CH_CONFIG_PATHA)) >> 6U;

    if (currentService.service.RDOCR & (BM_TMDS1 | BM_TMDS0) ) {
        SSMRCR |= BM_SSMTMOE;
    }
    else {
    }
    SSMRCR |= currentService.service.rxSysSet & (BM_SERVICE_RXSYSSET_IFAMPLIFIER_ENABLE | BM_SERVICE_RXSYSSET_PATH_VALID_AFTER_SOT | BM_SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHB | BM_SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHA);

    // power-down IDscan FIFO, path A and B
    PRR2 |= ( BM_PRIDS | BM_PRXB | BM_PRXA );

    // reset IDscan flags
    trxConf.idScanStatus &= (uint8_t)~BM_SYS_ID_SCAN_STATUS_RESET_FLAGS;

    // check for buffered mode, enabled IDscan for current service and for a valid number of IDs
    if(    (!(trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_TRANSPARENT_MODE))
        && (currentService.service.rxSysSet & BM_SERVICE_RXSYSSET_IDSCAN_ENABLE)
        && (trxConf.idScanStatus & BM_SYS_IDS_ENABLED) )
    {
        // --WORKAROUND--SIX-- SIX-1571
        IDS |= BM_IDFULL;   //  clear IRQ flag
        // --WORKAROUND--SIX-- SIX-1571

        /* power-up IDscan FIFO */
        PRR2 &= (uint8_t)~BM_PRIDS;

        /* signalize HW that IDscan is enabled */
        SSMRCR |= BM_SSMIDSE;

        /* enable IDscan buffer full interrupt */
        IDC |= BM_IDFIM;

        // indicate valid IDscan conditions, RF interrupts are disabled -> no CLI/SEI needed
        trxConf.idScanCtrl = BM_SYS_ID_SCAN_CTRL_IDSCAN_ACTIVE;
    }
    else
    {
        // disable IDscan buffer full interrupt
        IDC                &= (uint8_t)~BM_IDFIM;
        trxConf.idScanCtrl  = (uint8_t)0x00;    // RF interrupts are disabled -> no CLI/SEI needed
    }

    if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_VCO_TUNING )
    {
        /* incl. VCO TUNING */
        MSMCR1 = SSM_PLL_EN_STATE       | (uint8_t)(SSM_VCO_TUNING_STATE << 4U);
        MSMCR2 = SSM_PLL_LOCK_STATE     | (uint8_t)(SSM_RX_DSP_EN_STATE << 4U);
        MSMCR3 = SSM_GET_TELEGRAM_STATE | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR4 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);

        flowCtrl.msmstate = 10U;
    }
    else
    {
        /* NO VCO TUNING */
        MSMCR1 = SSM_PLL_EN_STATE       | (uint8_t)(SSM_PLL_LOCK_STATE << 4U);
        MSMCR2 = SSM_RX_DSP_EN_STATE    | (uint8_t)(SSM_GET_TELEGRAM_STATE << 4U);
        MSMCR3 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR4 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);

        flowCtrl.msmstate = 8U;
    }

    /* DIRECT SWITCHING */
    if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_DIRECT_SWITCH) {
        /* if direct switching is used --> overwrite 1st state in MSMCR1[3..0] */
        MSMCR1 &= (uint8_t)(BM_MSMSM13 | BM_MSMSM12 | BM_MSMSM11 | BM_MSMSM10);
        if(trxConf.lastSystemModeConfig & BM_SYS_MODE_CONFIG_OPM1) {
            /* coming from RX --> 1st state is rx_tx ssm */
            MSMCR1 |= SSM_RX_DSP_DIS_STATE;

        } else {
            /* coming from TX --> 1st state is tx_dsp_dis */
            MSMCR1 |= SSM_TX_2_RX_STATE;
        }

    }
    else {

    }

    GTCR  = (currentService.service.rxSetPathA[1] & BM_SERVICE_RXSETPATHA_GTCR) >> 4U;
    GTCR |= (currentService.service.rxSetPathB[1] & BM_SERVICE_RXSETPATHB_GTCR);

    SSMFBR = currentService.service.CHSTARTFILTER;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_initCorrelator_C</b>
    initializes the correlator with service specific wup/sfid settings.

    \return none

    \image html ATA_initCorrelator_C.png
    \image rtf ATA_initCorrelator_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_initCorrelator_C(void)
{
    WUP1A = currentService.service.WUPA[0];
    WUP2A = currentService.service.WUPA[1];
    WUP3A = currentService.service.WUPA[2];
    WUP4A = currentService.service.WUPA[3];

    WUP1B = currentService.service.WUPB[0];
    WUP2B = currentService.service.WUPB[1];
    WUP3B = currentService.service.WUPB[2];
    WUP4B = currentService.service.WUPB[3];


    WUPLA = currentService.service.WUPLA;
    WUPLB = currentService.service.WUPLB;

    WUPTA = currentService.service.WUPTA;
    WUPTB = currentService.service.WUPTB;

    SFID1A = currentService.service.SFIDA[0];
    SFID2A = currentService.service.SFIDA[1];
    SFID3A = currentService.service.SFIDA[2];
    SFID4A = currentService.service.SFIDA[3];

    SFID1B = currentService.service.SFIDB[0];
    SFID2B = currentService.service.SFIDB[1];
    SFID3B = currentService.service.SFIDB[2];
    SFID4B = currentService.service.SFIDB[3];

    SFIDCA = currentService.service.SFIDCA;
    SFIDCB = currentService.service.SFIDCB;
    SFIDLA = currentService.service.SFIDLA;
    SFIDLB = currentService.service.SFIDLB;

}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_initRxBuffer_C</b>
    initializes the Rx Buffer Block with service specific settings.

    \return none

    \image html ATA_initRxBuffer_C.png
    \image rtf ATA_initRxBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_initRxBuffer_C(void)
{
    /*
     * Path A
     */

    /* RX CRC polynomial for data path A */
    RXCPHA = currentService.service.RXCPA[1];
    RXCPLA = currentService.service.RXCPA[0];

    /* RX CRC init value for data path A */
    RXCIHA = currentService.service.RXCIA[1];
    RXCILA = currentService.service.RXCIA[0];

    /* RX CRC skip bit number for data path A */
    RXCSBA = currentService.service.RXSBA;

    /* RX data telegram length register for data path A*/
    RXTLHA = currentService.service.RXTLA[1];
    RXTLLA = currentService.service.RXTLA[0];

    /*
     * Path B
     */

     /* RX CRC polynomial for data path B */
    RXCPHB = currentService.service.RXCPB[1];
    RXCPLB = currentService.service.RXCPB[0];

    /* RX CRC init value for data path B */
    RXCIHB = currentService.service.RXCIB[1];
    RXCILB = currentService.service.RXCIB[0];

    /* RX CRC skip bit number for data path B */
    RXCSBB = currentService.service.RXSBB;

    /* RX data telegram length register for data path B*/
    RXTLHB = currentService.service.RXTLB[1];
    RXTLLB = currentService.service.RXTLB[0];

    /*
     * Common setting
     */
    RXBC1 = currentService.service.RXBC1;
}


/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_initRssiBuffer_C</b>
    this function initializes the RSSI buffer.

    \return none

    \image html ATA_initRssiBuffer_C.png
    \image rtf ATA_initRssiBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_initRssiBuffer_C(void)
{
    svcChConfig_t config = trxConf.serviceChannelConfig;
    uint8_t serviceNumber = config & BM_SVC_CH_CONFIG_SER;
    uint8_t channelNumber = config & BM_SVC_CH_CONFIG_CH;
    channelNumber >>= 4;

    RSSL = rssiThresholds[serviceNumber][channelNumber].RSSL;
    RSSH = rssiThresholds[serviceNumber][channelNumber].RSSH;
    RSSC = currentService.service.RSSC;

    ATA_eepRDblock_C((uint8_t *)&eepRssi.RSIFG, (uint8_t)sizeof(eepRssi), (uint8_t *)&RSIFG);
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxStateInitSSM_C</b>
    this Rx state initializes the sequencer state machine
    and switch to next state -> ATA_rxStateStartSSM_C.

    \return none

    \image html ATA_rxStateInitSSM_C.png
    \image rtf ATA_rxStateInitSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxStateInitSSM_C(void)
{
    (void)ATA_startInitTxRxSSM_C();
    
    /* -- SIX-2608 -- */
    if (currentService.service.trxSysConf & BM_SERVICE_TRXSYSCONF_CHANNEL_SWITCHING) {
        // channel switch enabled for this service    
        ATA_initChannelSwitchForCurrentService_C();
    }
    /* -- SIX-2608 -- */

    // check for enabled subchanneling feature
    if( currentService.service.rxSysSet & BM_SERVICE_RXSYSSET_SUBCHANNELING )
    {
        // flowCtrl.index still 0
        // flowCtrl.index = SUBCHANNELING_FLOW_STATE_WAIT_XTO_RDY;

        flowCtrl.pLut = pSubChannelingSysFlowStateMachine;

        if( FESR & BM_XRDY )
        {
            ATA_rxStateInitSubchanneling_C();
            flowCtrl.index = SUBCHANNELING_FLOW_STATE_CENTER_FREQ;
        }
    }
    else
    {   // subchanneling disabled
        if (FESR & BM_XRDY) {
            /* if XTO is already on skip state ATA_systemFlowStateWaitXtoReady_C */
            ATA_rxStateStartSSM_C();
            flowCtrl.index = RX_FLOW_STATE_SSM_GETTELEGRAM;
        }
        else {
            flowCtrl.index++;
        }
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxStateStartSSM_C</b>
    this Rx state starts the sequencer state machine
    and switch to next state -> ATA_rxStateWait4SSMstateGetTelegram_C.

    \return none

    \image html ATA_rxStateStartSSM_C.png
    \image rtf ATA_rxStateStartSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxStateStartSSM_C(void)
{
    if(     (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_TRANSPARENT_MODE)
        &&  (!(trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA)) )
    {
        DDRC |= (BM_DDRC3 | BM_DDRC5);
        /* DDRC3 = TMDO */
        /* DDRC5 = TMDO_CLK */
        
        /* -- SIX-3009 -- */
        SSMRCR |= BM_SSMTMOE;
    }

    // set RSSI FIFO fill level to generate related interrupt,
    // it sets SFDRA automatically to RX direction (0)
    SFC  = (currentService.service.rssiSysConf & BM_SERVICE_RSSISYSCONF_RSSI_BUF);
    // no DATA FIFO fill level to generate related interrupt
    // it sets DFDRA automatically to RX direction (0)
    DFC = 0x00U;

    RDSIMR = 0U;
    RDSIFR = (BM_WCOB | BM_WCOA | BM_SOTB | BM_SOTA | BM_EOTB | BM_EOTA | BM_NBITB | BM_NBITA);

    rxIrqEvents[0] = 0U;    // before WCOA
    rxIrqEvents[1] = 0U;    // after WCOA
    rxIrqEvents[2] = 0U;    // after SOTA

    // activate rx buffer pathA
    if( trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA ) {
        /* -- SIX-1342 -- */
        /* enable RX buffer only in buffered mode*/
        if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_TRANSPARENT_MODE) {
        }
        else {
            PRR2   &= (uint8_t)~BM_PRXA;
        }
        /* -- SIX-1342 -- */

        ATA_rxIntConfPathA_C();

        if (currentService.service.rxSetPathA[1] & BM_SERVICE_RXSETPATHA_RXEHA)
        {
            /* dummy signalization: pauses HW state machine until 'demodulator automatic restart' are restored */
            SSMRCR |= BM_SSMIDSE;
        }
    }

    // activate rx buffer pathB
    if( trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHB ) {
        /* -- SIX-1342 -- */
        /* enable RX buffer only in buffered mode*/
        if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_TRANSPARENT_MODE) {
        }
        else {
            PRR2   &= (uint8_t)~BM_PRXB;
        }
        /* -- SIX-1342 -- */

        ATA_rxIntConfPathB_C();

        if (currentService.service.rxSetPathB[1]&BM_SERVICE_RXSETPATHB_RXEHB)
        {
            /* dummy signalization: pauses HW state machine until 'demodulator automatic restart' are restored */
            SSMRCR |= BM_SSMIDSE;
        }
    }

    // clear SOTB/A flags if system is in pure RXMode
    if( trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA )
    {
        rxIrqEvents[0] &= (BM_WCOBM | BM_WCOAM);
    }

    RDSIMR = rxIrqEvents[0];    // set mask configuration to before WCOA/B

    /* -- SIX-1303 --*/
    /* RX/POLLING Mode selected*/
    ATA_setRxActive_ASM();
    /* -- SIX-1303 --*/

    flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_RX;
    ATA_systemStartSSM_C( DEBUG_ERROR_CODE_RX_STATESTARTSSM_TIMER_LOCKED );

    /* SIX-1340*/
    /* clear Data FIFO and Preamble FIFO before RX is ready */
    DFL   |= BM_DFCLR;
    SFL   |= BM_SFCLR;
    /* SIX-1340*/

    if( currentService.service.rssiSysConf & BM_SERVICE_RSSISYSCONF_RSSI_ENABLE )
    {
        PRR2 &= (uint8_t)~BM_PRRS;
        SFI  |= BM_SFFLIM;      // enable RSSI FIFO fill level interrupt
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxStateWait4SSMstateGetTelegram_C</b>
    this Rx state waits for the reaching of the sub state machine
    Get Telegram of the sequencer state machine and switch to
    next state -> ATA_rxStateWait4SSMrdy_C.

    \return none

    \image html ATA_rxStateWait4SSMstateGetTelegram_C.png
    \image rtf ATA_rxStateWait4SSMstateGetTelegram_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxStateWait4SSMstateGetTelegram_C(void)
{
    if( MSMSTR >= flowCtrl.msmstate )
    {
        ATA_stopSsmWatchdog_C();

        /* disable/enable overflow/underflow interrupt for SFIFO in RX according to trxConfig.systemConfig setting */
        if (trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_SFIFO_OFL_UFL_RX_DISABLE) {
            /* disable overflow/underflow interrupt for SFIFO in RX */
            SFI &= (uint8_t)~BM_SFERIM;
        }
        else {
            SFI |= BM_SFERIM;
        }

        /* disable/enable overflow/underflow interrupt for DFIFO in RX according to trxConfig.systemConfig setting */
        if (trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_DFIFO_OFL_UFL_RX_DISABLE) {
            /* disable overflow/underflow interrupt for SFIFO in RX */
            DFI &= (uint8_t)~BM_DFERIM;
        }
        else {
            DFI |= BM_DFERIM;
        }

        /* set enable flag for directswitching */
        sysStatus |= BM_SYS_STATUS_RDY_4_DIRECTSWITCHING;

        /* SSM is ready --> store FEVCT */
        currentService.service.FEVCT = FEVCT;

        flowCtrl.index++;
    }
    /* -- SIX-1591 --*/
    else if( (sysStatus & BM_SYS_STATUS_SSMRDY) && (SSMSR == 0U) )
    {    // check if SSM ready, e.g. by EOT, is signalized, but this routine couldn't proceed, e.g. SPI interrupt
        ATA_stopSsmWatchdog_C();

        /* set enable flag for directswitching */
        sysStatus |= BM_SYS_STATUS_RDY_4_DIRECTSWITCHING;

        /* SSM is ready --> store FEVCT */
        currentService.service.FEVCT = FEVCT;

        flowCtrl.index++;
    }
    /* -- SIX-1591 --*/
    else
    {
        // check timeout for SSM
        if( (T2IFR & BM_T2COF) || SSMSR )
        {    // timeout of SSM occured
            SSMRR = BM_SSMST;       // reset current state machine
            ATA_stopSsmWatchdog_C();

            debug.errorCode = DEBUG_ERROR_CODE_RX_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT;
            debug.ssmErrorCode = SSMSR;
            ATA_setSystemError_ASM();

            // patch SW state to shutdown
            if(trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA ) {
                /* pure RX mode */
                flowCtrl.index = PURE_RX_FLOW_STATE_SHUTDOWN;
            }
            else {
                /* RX mode */
                flowCtrl.index = RX_FLOW_STATE_SHUTDOWN;
            }
        }
        else
        {}
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxStateWait4SSMrdy_C</b>
    this Rx state waits for the end of the sequencer state machine
    and switch to next state -> ATA_rxStateWait4WCO_C.

    \return none

    \image html ATA_rxStateWait4SSMrdy_C.png
    \image rtf ATA_rxStateWait4SSMrdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxStateWait4SSMrdy_C(void)
{
    if( trxConf.idScanCtrl & BM_SYS_ID_SCAN_CTRL_IDSCAN_ACTIVE )
    {   // IDscanning is activated

        // valid for RXMode und PollingMode, if not all IDs checked and SOT occurred
        if(  ( !(trxConf.idScanStatus & BM_SYS_ID_SCAN_STATUS_VALID) ) && ( trxStatus & BM_TRX_STATUS_RX_SOTA_SOTB ) )
        {
            uint8_t idscan_status, idscan_ctrl;

            _CLI;
            idscan_status = trxConf.idScanStatus;
            idscan_ctrl   = trxConf.idScanCtrl;
            _SEI;

            // check for EOT on SOT signaling path or IDscan buffer full interrupt
            if( ( idscan_status & BM_SYS_ID_SCAN_STATUS_BUF_FULL )
                ||
                ( ((idscan_ctrl & BM_SYS_ID_SCAN_CTRL_EOTB) && (trxStatus & BM_TRX_STATUS_RX_SOTB))
                  ||
                  ((idscan_ctrl & BM_SYS_ID_SCAN_CTRL_EOTA) && (trxStatus & BM_TRX_STATUS_RX_SOTA))
                ) )
            {
                ATA_doIdScan_C();
                // possible results: all IDs checked     -> ID fail or ID ok
                //                   not all IDs checked -> neither ID fail nor ID ok

                // restart behavior for RXMode located in ATA_doIdScan_C()
            }
        }

        if( sysStatus&BM_SYS_STATUS_SSMRDY )
        {
            if( SSMSR )
            {
                debug.errorCode = DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR;
                debug.ssmErrorCode = SSMSR;
                ATA_setSystemError_ASM();
            }
            else
            {}

            RDSIMR     = 0U;    // disable RF interrupts
            sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;

            ATA_signalEotAtSsmRdy_C();

            flowCtrl.index++;
        }
        else
        {
            sysStatus |= BM_SYS_STATUS_SSM_SLEEP_ENABLE;
        }
    }
    else    // IDscan disabled or transparent data reception
    {
        // only set in PollingMode and path A and/or path B should restart the demodulator
        // if( (SSMRCR&BM_SSMIDSE) && (trxStatus&BM_TRX_STATUS_RX_SOTA_SOTB) && (trxStatus&BM_TRX_STATUS_RX_EOTA_EOTB) )
        if( (SSMRCR&BM_SSMIDSE)
            &&
            ( ((trxStatus&BM_TRX_STATUS_RX_SOTB) && (trxStatus&BM_TRX_STATUS_RX_EOTB))
              ||
              ((trxStatus&BM_TRX_STATUS_RX_SOTA) && (trxStatus&BM_TRX_STATUS_RX_EOTA))
            ) )
        {
            // check for current data reception path
            if( ((GTCR&BM_RXTEHB) && (RXBC2&BM_RXBPB))
                ||
                ((GTCR&BM_RXTEHA) && (!(RXBC2&BM_RXBPB))) )
            {   // 'restart RX after EOT' selected

                RDSIMR = 0U;
                RDSIFR = (BM_WCOB | BM_WCOA | BM_SOTB | BM_SOTA | BM_EOTB | BM_EOTA | BM_NBITB | BM_NBITA);

                if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM0) {
                    // if PollingMode is selected --> restore DARA/B settings
                    GTCR |= (currentService.service.rxSetPathA[1] & BM_SERVICE_RXSETPATHA_DARA) >> 4U;
                    GTCR |= (currentService.service.rxSetPathB[1] & BM_SERVICE_RXSETPATHB_DARB);
                }

                // activate rx buffer pathA
                RDSIMR = rxIrqEvents[0];    // set mask configuration to before WCOA/B
                trxStatus = 0U;             // reset trx status before restarting reception
            }

            SSMFCR = BM_SSMIDSF;    // ID fail
        }

        if( sysStatus&BM_SYS_STATUS_SSMRDY )
        {
            if( SSMSR )
            {
                debug.errorCode = DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR;
                debug.ssmErrorCode = SSMSR;
                ATA_setSystemError_ASM();
            }
            else
            {}

            RDSIMR     = 0U;
            sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;
            // set idscan valid flags
            trxConf.idScanStatus |= (BM_SYS_ID_SCAN_STATUS_RESULT|BM_SYS_ID_SCAN_STATUS_VALID);

            ATA_signalEotAtSsmRdy_C();

            flowCtrl.index++;

            SSMRCR &= (uint8_t)~BM_SSMIDSE;
        }
        else
        {
            // no state changes occurred
            sysStatus |= BM_SYS_STATUS_SSM_SLEEP_ENABLE;
        }
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_pureRxUp_C</b>
    pure RX is activated and running.
    The entering of the sleep mode is enabled.

    \return none

    \image html ATA_pureRxUp_C.png
    \image rtf ATA_pureRxUp_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_pureRxUp_C(void)
{
    sysStatus |= BM_SYS_STATUS_SSM_SLEEP_ENABLE;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rssiStateInitSSM_C</b>
    init function used for RSSI on demand.

    \return none

    \image html ATA_rssiStateInitSSM_C.png
    \image rtf ATA_rssiStateInitSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rssiStateInitSSM_C(void)
{
    (void)ATA_startInitTxRxSSM_C();

    SOTC1A = 0U;
    SOTC2A = 0U;
    SOTC1B = 0U;
    SOTC2B = 0U;

    EOTC1A = 0U;
    EOTC2A = 0U;
    EOTC3A = 0U;
    EOTC1B = 0U;
    EOTC2B = 0U;
    EOTC3B = 0U;
    /* set error handling in GTCR for path A/B --> restart RX after EOT */
    GTCR |= (uint8_t)(BM_RXTEHA | BM_RXTEHB);
    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rssiStateWait4SSMrdy_C</b>
    this RSSI state waits for the end of the sequencer state machine.

    \return none

    \image html ATA_rssiStateWait4SSMrdy_C.png
    \image rtf ATA_rssiStateWait4SSMrdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rssiStateWait4SSMrdy_C(void)
{
    if( sysStatus&BM_SYS_STATUS_SSMRDY )
    {
        RDSIMR     = 0U;
        sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;
        flowCtrl.index++;
    }
    else
    {
        sysStatus |= BM_SYS_STATUS_SSM_SLEEP_ENABLE;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rssiStateStartSSM_C</b>
    this Rssi state starts the sequencer state machine
    and switch to next state -> ATA_rxStateWait4SSMstateGetTelegram_C.

    \return none

    \image html ATA_rssiStateStartSSM_C.png
    \image rtf ATA_rssiStateStartSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rssiStateStartSSM_C(void)
{
    // set buffer fill level to generate related interrupts,
    // it sets SFDRA automatically to RX direction (0)
    SFC   = (currentService.service.rssiSysConf & BM_SERVICE_RSSISYSCONF_RSSI_BUF);
    // no DATA FIFO fill level to generate related interrupt
    // it sets DFDRA automatically to RX direction (0)
    DFC = 0x00U;

    RDSIMR = 0U;
    RDSIFR = (BM_WCOB | BM_WCOA | BM_SOTB | BM_SOTA | BM_EOTB | BM_EOTA | BM_NBITB | BM_NBITA);

    /* RX/POLLING Mode selected*/
    ATA_setRxActive_ASM();

    flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_RX;
    ATA_systemStartSSM_C( DEBUG_ERROR_CODE_RSSI_STATESTARTSSM_TIMER_LOCKED );

    SFL  |= BM_SFCLR;   // clear RSSI FIFO and status flags
    PRR2 &= (uint8_t)~BM_PRRS;
    SFI  |= BM_SFFLIM;  // enable RSSI FIFO fill level interrupt
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxStateInitSubchanneling_C</b>
    this Rx state reconfigures the sequencer state machine for subchanneling
    and switch to next state -> ATA_rxStateSubchanneling_Center_Freq_C.

    \return none

    \image html ATA_rxStateInitSubchanneling_C.png
    \image rtf ATA_rxStateInitSubchanneling_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxStateInitSubchanneling_C(void)
{
    if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_VCO_TUNING )
    {
       /* incl. VCO TUNING */
       MSMCR1 = SSM_PLL_EN_STATE       | (uint8_t)(SSM_VCO_TUNING_STATE << 4U);
       MSMCR2 = SSM_PLL_LOCK_STATE     | (uint8_t)(SSM_RX_DSP_EN_STATE << 4U);
       MSMCR3 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
       MSMCR4 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
    }
    else
    {
       /* NO VCO TUNING */
       MSMCR1 = SSM_PLL_EN_STATE       | (uint8_t)(SSM_PLL_LOCK_STATE << 4U);
       MSMCR2 = SSM_RX_DSP_EN_STATE    | (uint8_t)(SSM_END_STATE << 4U);
       MSMCR3 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
       MSMCR4 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
    }

    flowCtrl.msmstate = 0xFFU;

    // set buffer fill level to 1 to generate related interrupt,
    // it sets SFDRA automatically to RX direction (0)
    SFC            = MIN_RSSI_FIFO_FILL_LEVEL_4_SUBCHANNELING;
    subChan.flags  = BM_SUBCHANNELING_ACTIVE;

    /* -- SIX-1588 --*/
    // set RXACTIVE for subchanneling, still RXMode or PollingMode selected
    ATA_setRxActive_ASM();
    /* -- SIX-1588 --*/

    flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_RX;
    ATA_systemStartSSM_C( DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMER_LOCKED );

    SFL  |= BM_SFCLR;   // clear RSSI FIFO and status flags
    PRR2 &= (uint8_t)~BM_PRRS;
    SFI  |= BM_SFFLIM;  // enable RSSI FIFO fill level interrupt
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxStateSubchanneling_Center_Freq_C</b>
    this Rx state adjustes the receiving frequency to the lower frequency.
    It reads the RSSI value and modifies the sequencer state machine
    and switch to next state -> ATA_rxStateSubchanneling_Lower_Freq_C.

    \return none

    \image html ATA_rxStateSubchanneling_Center_Freq_C.png
    \image rtf ATA_rxStateSubchanneling_Center_Freq_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxStateSubchanneling_Center_Freq_C(void)
{
    // wait SSM ready signalization
    if( (sysStatus & BM_SYS_STATUS_SSMRDY) && (subChan.flags & BM_SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED) )
    {
        uint32_t frequency;

        ATA_stopSsmWatchdog_C();

        // get currently used frequency
        frequency  = (uint32_t)FFREQ1H << 16U;
        frequency += (uint32_t)FFREQ1M << 8U;
        frequency += (uint32_t)FFREQ1L << 0U;

        // adjust lower frequency -> frequency = frequency - offset
        frequency -= (uint32_t)currentService.service.FREQoffset[1] << 8U;
        frequency -= (uint32_t)currentService.service.FREQoffset[0] << 0U;

        // read RSSI value of center frequency
        subChan.rssi[0] = SFD;

        /* -- SIX-1594 --*/
        FFREQ2H = FFREQ1H;
        FFREQ2M = FFREQ1M;
        FFREQ2L = FFREQ1L;

        FSCR    = BM_TXMOD | BM_SFM;    // switch to frequency FFREQ2

        // store new frequency
        FFREQ1H = (uint8_t)(frequency >> 16U);
        FFREQ1M = (uint8_t)(frequency >>  8U);
        FFREQ1L = (uint8_t)(frequency >>  0U);

        FSCR    = 0x00U;                // switch back to FFREQ1
        /* -- SIX-1594 --*/

        MSMCR1 = SSM_RX_DSP_DIS_STATE   | (uint8_t)(SSM_RX_DSP_EN_STATE << 4U);
        MSMCR2 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR3 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR4 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);

        flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_RX;
        ATA_systemStartSSM_C( DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMER_LOCKED );

        subChan.flags &= (uint8_t)~BM_SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED;   // clear interrupt occurred flag
        SFL           |= BM_SFCLR;  // clear RSSI FIFO and status flags
        SFI           |= BM_SFFLIM; // enable RSSI FIFO fill level interrupt
    }
    else
    {
        // check timeout for SSM
        if( (T2IFR & BM_T2COF) || SSMSR )
        {    // timeout of SSM occured
            SSMRR = BM_SSMST;       // reset current state machine
            ATA_stopSsmWatchdog_C();

            debug.errorCode    = DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMEOUT;
            debug.ssmErrorCode = SSMSR;
            ATA_setSystemError_ASM();

            // restore SW state machine to shut down and enter IDLEMode
            if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM0 )
            {   // PollingMode
                flowCtrl.index = POLL_FLOW_STATE_SHUTDOWN;
                flowCtrl.pLut  = pPollSysFlowStateMachine;
            }
            else
            {   // RXMode, no pure RXMode
                flowCtrl.index = RX_FLOW_STATE_SHUTDOWN;
                flowCtrl.pLut  = pRxSysFlowStateMachine;
            }
        }
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxStateSubchanneling_Lower_Freq_C</b>
    this Rx state adjustes the receiving frequency to the upper frequency.
    It reads the RSSI value
    and switch to next state -> ATA_rxStateSubchanneling_Upper_Freq_C.

    \return none

    \image html ATA_rxStateSubchanneling_Lower_Freq_C.png
    \image rtf ATA_rxStateSubchanneling_Lower_Freq_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxStateSubchanneling_Lower_Freq_C(void)
{
    // wait SSM ready signalization
    if( (sysStatus & BM_SYS_STATUS_SSMRDY) && (subChan.flags & BM_SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED) )
    {
        uint32_t frequency;

        ATA_stopSsmWatchdog_C();

        // get currently used frequency
        frequency  = (uint32_t)FFREQ1H << 16U;
        frequency += (uint32_t)FFREQ1M << 8U;
        frequency += (uint32_t)FFREQ1L << 0U;

        // adjust upper frequency -> frequency = frequency + 2*offset
        frequency += (uint32_t)currentService.service.FREQoffset[1] << 9U;
        frequency += (uint32_t)currentService.service.FREQoffset[0] << 1U;

        // read RSSI value of lower frequency
        subChan.rssi[1] = SFD;

        /* -- SIX-1594 --*/
        FFREQ2H = FFREQ1H;
        FFREQ2M = FFREQ1M;
        FFREQ2L = FFREQ1L;

        FSCR    = BM_TXMOD | BM_SFM;    // switch to frequency FFREQ2

        // store new frequency
        FFREQ1H = (uint8_t)(frequency >> 16U);
        FFREQ1M = (uint8_t)(frequency >>  8U);
        FFREQ1L = (uint8_t)(frequency >>  0U);

        FSCR    = 0x00U;                // switch back to FFREQ1
        /* -- SIX-1594 --*/

        flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_RX;
        ATA_systemStartSSM_C( DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMER_LOCKED );

        subChan.flags &= (uint8_t)~BM_SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED;   // clear interrupt occurred flag
        SFL           |= BM_SFCLR;  // clear RSSI FIFO and status flags
        SFI           |= BM_SFFLIM; // enable RSSI FIFO fill level interrupt
    }
    else
    {
        // check timeout for SSM
        if( (T2IFR & BM_T2COF) || SSMSR )
        {    // timeout of SSM occured
            SSMRR = BM_SSMST;       // reset current state machine
            ATA_stopSsmWatchdog_C();

            debug.errorCode    = DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMEOUT;
            debug.ssmErrorCode = SSMSR;
            ATA_setSystemError_ASM();

            // restore SW state machine to shut down and enter IDLEMode
            if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM0 )
            {   // PollingMode
                flowCtrl.index = POLL_FLOW_STATE_SHUTDOWN;
                flowCtrl.pLut  = pPollSysFlowStateMachine;
            }
            else
            {   // RXMode, no pure RXMode
                flowCtrl.index = RX_FLOW_STATE_SHUTDOWN;
                flowCtrl.pLut  = pRxSysFlowStateMachine;
            }
        }
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxStateSubchanneling_Upper_Freq_C</b>
    this Rx state adjustes the receiving frequency to the subchannel frequency
    having the best RSSI value.
    It reads the RSSI value and modifies the sequencer state machine
    and switches back to the RXMode or PollingMode state machine to start
    telegram reception.

    \return none

    \image html ATA_rxStateSubchanneling_Upper_Freq_C.png
    \image rtf ATA_rxStateSubchanneling_Upper_Freq_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxStateSubchanneling_Upper_Freq_C(void)
{
    // wait SSM ready signalization
    if( (sysStatus & BM_SYS_STATUS_SSMRDY) && (subChan.flags & BM_SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED) )
    {
        ATA_stopSsmWatchdog_C();

        // configure SSM to go ahead with receiving
        MSMCR1 = SSM_RX_DSP_DIS_STATE   | (uint8_t)(SSM_RX_DSP_EN_STATE << 4U);
        MSMCR2 = SSM_GET_TELEGRAM_STATE | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR3 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR4 = SSM_END_STATE          | (uint8_t)(SSM_END_STATE << 4U);
        flowCtrl.msmstate = 0x06U;

        // read RSSI value of upper frequency
        subChan.rssi[2] = SFD;

        // find best RSSI value and adjust frequency accordingly
        if( (subChan.rssi[0] >= subChan.rssi[1]) && (subChan.rssi[0] >= subChan.rssi[2]) )
        {   // receive with center frequency
            ATA_doFrequencySettingsRx_C();
        }
        else if( (subChan.rssi[1] > subChan.rssi[2]) )
        {   // receive with lower frequency
            uint32_t frequency = ((uint32_t)currentService.channel.FFREQ[2] << 16U)
                                |((uint32_t)currentService.channel.FFREQ[1] <<  8U)
                                |((uint32_t)currentService.channel.FFREQ[0] <<  0U);

            // adjust lower frequency -> frequency = frequency - offset
            frequency -= (uint32_t)currentService.service.FREQoffset[1] << 8U;
            frequency -= (uint32_t)currentService.service.FREQoffset[0] << 0U;

            /* -- SIX-1594 --*/
            FFREQ2H = FFREQ1H;
            FFREQ2M = FFREQ1M;
            FFREQ2L = FFREQ1L;

            FSCR    = BM_TXMOD | BM_SFM;    // switch to frequency FFREQ2

            // store new frequency
            FFREQ1H = (uint8_t)(frequency >> 16U);
            FFREQ1M = (uint8_t)(frequency >>  8U);
            FFREQ1L = (uint8_t)(frequency >>  0U);

            FSCR    = 0x00U;                // switch back to FFREQ1
            /* -- SIX-1594 --*/
        }
        else
        {   // receive with upper frequency
            // frequency already adjusted
        }

        // restore SW state machine to go ahead with telegram reception
        if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM0 )
        {   // PollingMode
            flowCtrl.index = POLL_FLOW_STATE_START_SSM;
            flowCtrl.pLut  = pPollSysFlowStateMachine;
        }
        else
        {   // RXMode, no pure RXMode
            flowCtrl.index = RX_FLOW_STATE_START_SSM;
            flowCtrl.pLut  = pRxSysFlowStateMachine;
        }

        // disable RSSI FIFO power if no RSSI measurement while waiting for telegrams should be done
        PRR2 |= (uint8_t)BM_PRRS;

        // clear RSSI FIFO and status flags
        SFL |= BM_SFCLR;

        // clear subchanneling flags
        subChan.flags = 0U;
    }
    else
    {
        // check timeout for SSM
        if( (T2IFR & BM_T2COF) || SSMSR )
        {    // timeout of SSM occured
            SSMRR = BM_SSMST;       // reset current state machine
            ATA_stopSsmWatchdog_C();

            debug.errorCode    = DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMEOUT;
            debug.ssmErrorCode = SSMSR;
            ATA_setSystemError_ASM();

            // restore SW state machine to shut down and enter IDLEMode
            if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM0 )
            {   // PollingMode
                flowCtrl.index = POLL_FLOW_STATE_SHUTDOWN;
                flowCtrl.pLut  = pPollSysFlowStateMachine;
            }
            else
            {   // RXMode, no pure RXMode
                flowCtrl.index = RX_FLOW_STATE_SHUTDOWN;
                flowCtrl.pLut  = pRxSysFlowStateMachine;
            }
        }
    }
}


/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxIntConfPathA_C</b>
    this function configures the rxIrqEvents array according to the
    SSM settings

    \return none

    \image html ATA_rxIntConfPathA_C.png
    \image rtf ATA_rxIntConfPathA_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxIntConfPathA_C(void)
{
        rxIrqEvents[0] |= (BM_WCOAM | BM_SOTAM);    // before WCOA
        rxIrqEvents[1] |= (BM_WCOAM | BM_SOTAM);    // after WCOA
        rxIrqEvents[2] |= BM_EOTAM;                 // after SOTA
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rxIntConfPathB_C</b>
    this function configures the rxIrqEvents array according to the
    SSM settings

    \return none

    \image html ATA_rxIntConfPathB_C.png
    \image rtf ATA_rxIntConfPathB_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rxIntConfPathB_C(void)
{
        rxIrqEvents[0] |= (BM_WCOBM | BM_SOTBM);    // before WCOB
        rxIrqEvents[1] |= (BM_WCOBM | BM_SOTBM);    // after WCOB
        rxIrqEvents[2] |=  BM_EOTBM;                // after SOTB
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_signalEotAtSsmRdy_C</b>
    this function set EOT event pin after SSM is ready and GTCR.GAPMA is
    enabled

    \return none

    \image html ATA_signalEotAtSsmRdy_C.png
    \image rtf ATA_signalEotAtSsmRdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_signalEotAtSsmRdy_C(void)
{
    uint8_t mask = 0U;
    if ((trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM0) == 0U) {
        /* RX Mode */
        if ((trxStatus & (BM_TRX_STATUS_RX_SOTA | BM_TRX_STATUS_RX_SOTB))==0U) {
            /* SOTA and SOTB are not set */
            if ((trxStatus & (BM_TRX_STATUS_RX_WCOA | BM_TRX_STATUS_RX_WCOB)) == 0U) {
                /* WCOA = 0 and WCOB = 0 set EOTA and EOTB */
                mask |= BM_EVENTS_EVENTS_EOTA;
                mask |= BM_EVENTS_EVENTS_EOTB;
            }
            else if ((trxStatus & (BM_TRX_STATUS_RX_WCOA | BM_TRX_STATUS_RX_WCOB)) == BM_TRX_STATUS_RX_WCOA) {
                /* WCOA = 1 and WCOB = 0 set EOTA */
                mask |= BM_EVENTS_EVENTS_EOTA;
            }
            else if ((trxStatus & (BM_TRX_STATUS_RX_WCOA | BM_TRX_STATUS_RX_WCOB)) == BM_TRX_STATUS_RX_WCOB) {
                /* WCOA = 0 and WCOB = 1 set EOTB */
                mask |= BM_EVENTS_EVENTS_EOTB;
            }
            else {
                /* WCOA = 1 and WCOB = 1 set EOTA and EOTB */
                mask |= BM_EVENTS_EVENTS_EOTA;
                mask |= BM_EVENTS_EVENTS_EOTB;
            }

            if ( (trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA) == 0U ) {
                /* Path A disabled --> clear EOTA flag */
                mask &= (uint8_t)~BM_EVENTS_EVENTS_EOTA;
            }

            if ( (trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHB) == 0U ) {
                /* Path B disabled --> clear EOTB flag */
                mask &= (uint8_t)~BM_EVENTS_EVENTS_EOTB;
            }

            /* EOTA/EOTB event setting */
            events_events |= mask;
            if (   ((events_events & BM_EVENTS_EVENTS_EOTA) && (currentService.service.rxSysEvent & BM_SERVICE_RXSYSEVENT_EOTA))
                || ((events_events & BM_EVENTS_EVENTS_EOTB) && (currentService.service.rxSysEvent & BM_SERVICE_RXSYSEVENT_EOTB))
               )
            {
                ATA_setEventPin_ASM();
            }
        }
        else {
                /* after SOTA or SOTB no EOT signalization when SSM ready */
        }
    }
    else {
        /* PollingMode --> do nothing */
    }


}
