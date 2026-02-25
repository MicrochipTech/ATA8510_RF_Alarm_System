/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/rftx/src/rftx.c $
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
/** \file rftx.c
*/
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "rftx.h"
#include "../../rf/src/rf.h"
#include "../../rfrx/src/rfrx.h"
#include "../../globals/src/globals.h"
#include "../../eep/src/eep.h"
#include "../../timer3/src/timer3.h"
#include "../../system/src/system.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/


/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_startInitTxSSM_C</b>
    does the Tx specific initalization of Tx/Rx sequencer state machine.

    \return none

    \image html ATA_startInitTxSSM_C.png
    \image rtf ATA_startInitTxSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_startInitTxSSM_C(void)
{
    PRR0 &= (uint8_t)~BM_PRTXDC;
    PRR2 &= (uint8_t)~BM_PRSSM;
    
    /* --SIX-1384-- */    
    /* disable RX interrupt when starting tx mode to avoid incorrect eot signalling */
    RDSIMR = 0U;
    RDSIFR = (BM_WCOB | BM_WCOA | BM_SOTB | BM_SOTA | BM_EOTB | BM_EOTA | BM_NBITB | BM_NBITA);    
    /* --SIX-1384--  */
    
    ATA_doFrequencySettingsTx_C();

    /* ATA_setupPllStartUpTx(); */

    if (trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA) {
        /* Path A enabled */
        FSFCR = currentService.service.FSFCRA;

        GACDIVL = currentService.service.GACDIVA[0];
        GACDIVH = currentService.service.GACDIVA[1];
    }
    else {
        /* Path B enabled */
        FSFCR = currentService.service.FSFCRB;

        GACDIVL = currentService.service.GACDIVB[0];
        GACDIVH = currentService.service.GACDIVB[1];
    }

    /* ATA_setupAntTuneTx(); */
    if (currentService.service.FEPAC < 0x2BU) {
    }
    else {
        SUPCR |= BM_AVDIC;
    }
    /* setting of FEALR.RNGE neccessary for Antenna tuning (SSM review 22jul2011) */
    FEANT = (currentService.service.FEALR_FEANT & 0x0FU);
    FEALR = ((currentService.service.FEALR_FEANT & 0x30U) >> 4U);

    ATA_setupTxModulator_C();
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_configureTxSSM_C</b>
    does the configuration of Tx sequencer state machine.

    \return none

    \image html ATA_configureTxSSM_C.png
    \image rtf ATA_configureTxSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_configureTxSSM_C(void)
{
    uint8_t txSetPath0 = 0U;
    uint8_t txSetPath1 = 0U;
    uint8_t config = trxConf.systemModeConfig & (BM_SYS_MODE_CONFIG_VCO_TUNING | BM_SYS_MODE_CONFIG_ANTENNA_TUNING);

    /* SSMCR - SSM Run Register*/
    SSMRR = BM_SSMST;   /* set SSM in stop state to reset SSM*/

    if (config == 0U) {
        /* NO VCO TUNING */
        /* NO ANTENNA TUNING */
        MSMCR1 = SSM_PLL_EN_STATE           | (uint8_t)(SSM_PLL_LOCK_STATE << 4U);
        MSMCR2 = SSM_TX_DSP_EN_STATE        | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR3 = SSM_END_STATE              | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR4 = SSM_END_STATE              | (uint8_t)(SSM_END_STATE << 4U);
    }
    else if (config == BM_SYS_MODE_CONFIG_VCO_TUNING){
        /* ONLY VCO TUNING */
        /* NO ANTENNA TUNING */
        MSMCR1 = SSM_PLL_EN_STATE           | (uint8_t)(SSM_VCO_TUNING_STATE << 4U);
        MSMCR2 = SSM_PLL_LOCK_STATE         | (uint8_t)(SSM_TX_DSP_EN_STATE << 4U);
        MSMCR3 = SSM_END_STATE              | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR4 = SSM_END_STATE              | (uint8_t)(SSM_END_STATE << 4U);
    }
    else if (config == BM_SYS_MODE_CONFIG_ANTENNA_TUNING){
        /* NO VCO TUNING */
        /* ONLY ANTENNA TUNING */
        MSMCR1 = SSM_PLL_EN_STATE           | (uint8_t)(SSM_PLL_LOCK_STATE << 4U);
        MSMCR2 = SSM_TX_DSP_EN_STATE        | (uint8_t)(SSM_ANTENNA_TUNING_STATE << 4U);
        MSMCR3 = SSM_END_STATE              | (uint8_t)(SSM_END_STATE << 4U); //
        MSMCR4 = SSM_END_STATE              | (uint8_t)(SSM_END_STATE << 4U); //
    }
    else{
        /* VCO TUNING */
        /* ANTENNA TUNING */
        MSMCR1 = SSM_PLL_EN_STATE           | (uint8_t)(SSM_VCO_TUNING_STATE << 4U);
        MSMCR2 = SSM_PLL_LOCK_STATE         | (uint8_t)(SSM_TX_DSP_EN_STATE << 4U);
        MSMCR3 = SSM_ANTENNA_TUNING_STATE   | (uint8_t)(SSM_END_STATE << 4U);
        MSMCR4 = SSM_END_STATE              | (uint8_t)(SSM_END_STATE << 4U);
    }

    /* DIRECT SWITCHING */
    if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_DIRECT_SWITCH) {
        /* if direct switching is used --> overwrite 1st state in MSMCR1[3..0] */
        MSMCR1 &= (uint8_t)(BM_MSMSM13 | BM_MSMSM12 | BM_MSMSM11 | BM_MSMSM10);
        if(trxConf.lastSystemModeConfig & BM_SYS_MODE_CONFIG_OPM1) {
            /* coming from RX --> 1st state is rx_tx ssm */
            MSMCR1 |= SSM_RX_2_TX_STATE;

        } else {
            /* coming from TX --> 1st state is tx_dsp_dis */
            MSMCR1 |= SSM_TX_DSP_DIS_STATE;
        }
    }
    else {

    }
    SSMFBR = currentService.service.CHSTARTFILTER;

    /* SSMCR - SSM Control Register*/
    SSMCR = BM_SSMTX;

    if( trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_VS5V_SELECTOR ) {
        SSMCR |= BM_SSMPVE;
    }

    if (trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA) {
        /* Path A enabled */
        txSetPath0 = currentService.service.txSetPathA[0];
        txSetPath1 = currentService.service.txSetPathA[1];
    }
    else {
        /* Path B enabled */
        txSetPath0 = currentService.service.txSetPathB[0];
        txSetPath1 = currentService.service.txSetPathB[1];
    }

    /* SSMCR.SSMTGE - Sequencer State Machine Tx Gauss Enable */
    if (txSetPath0 & BM_SERVICE_TXSETPATH_GAUS) {
        /* Gauss Enable */
        SSMCR |= BM_SSMTGE;
    }

    /* SSMCR.SSMTPE - Sequencer State Machine Tx Preemphasis Enable */
    if (txSetPath0 & BM_SERVICE_TXSETPATH_PREE) {
        /* Preemphasis Enable */
        SSMCR |= BM_SSMTPE;
    }

    /* SSMCR.SSMTAE - Sequencer State Machine Tx Ask-Shaping Enable */
    if (txSetPath1 & BM_SERVICE_TXSETPATH_ASK_SHAPING) {
        /* ASK shaping enable */
        SSMCR |= BM_SSMTAE;
    }
 }

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_doFrequencySettingsTx_C</b>
    does the Tx specific frequency settings.

    \return none

    \image html ATA_doFrequencySettingsTx_C.png
    \image rtf ATA_doFrequencySettingsTx_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_doFrequencySettingsTx_C(void)
{
    uint32_t frequency = ((uint32_t)currentService.channel.FFREQ[2] << 16U)
                        |((uint32_t)currentService.channel.FFREQ[1] <<  8U)
                        |((uint32_t)currentService.channel.FFREQ[0] <<  0U);
    /* --- F_TX = F_LO + F_IF --- */
    frequency +=  ((uint32_t)currentService.service.IF[1] <<  8U)
                 |((uint32_t)currentService.service.IF[0] <<  0U);

    if (trxStatus & BM_TRX_STATUS_TX_ASK_FSK_MODULATION) {
        /* ASK Modulation */
        /* --- F_TX_ASK = F_LO + F_IF --- */
        FFREQ2H = FFREQ1H;
        FFREQ2M = FFREQ1M;
        FFREQ2L = FFREQ1L;

        FSCR    = BM_TXMOD | BM_SFM;    // switch to frequency FFREQ2

        FFREQ1H = (uint8_t)(frequency >> 16U);
        FFREQ1M = (uint8_t)(frequency >>  8U);
        FFREQ1L = (uint8_t)(frequency >>  0U);

        FSCR    = 0x00U;                // switch back to FFREQ1
    }
    else
    {   /* FSK Modulation */
        uint32_t freqdev = (  ((uint32_t)currentService.service.txDevA[1] <<  8U)
                             |((uint32_t)currentService.service.txDevA[0] <<  0U));

        if( trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHB )
        {
            /* Path B enabled */
            freqdev = (  ((uint32_t)currentService.service.txDevB[1] <<  8U)
                        |((uint32_t)currentService.service.txDevB[0] <<  0U));
        }

        FFREQ2H = FFREQ1H;
        FFREQ2M = FFREQ1M;
        FFREQ2L = FFREQ1L;

        FSCR    = BM_TXMOD | BM_SFM;    // switch to frequency FFREQ2
        /* F_TX_FSK1 = T_TX_ASK-FDEV/2 */
        frequency -= freqdev/2U;


        FFREQ1H = (uint8_t)(frequency >> 16U);
        FFREQ1M = (uint8_t)(frequency >>  8U);
        FFREQ1L = (uint8_t)(frequency >>  0U);

        FSCR    = 0x00U;                // switch back to FFREQ1

        /* F_TX_FSK2 = T_TX_ASK+FDEV/2 = FF_TX_FSK1 + FDEV */
        frequency += freqdev;

        FFREQ2H = (uint8_t)(frequency >> 16U);
        FFREQ2M = (uint8_t)(frequency >>  8U);
        FFREQ2L = (uint8_t)(frequency >>  0U);
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_openTimer3forTxing_C</b>
    configure Timer3 for Tx.

    \return none

    \image html ATA_openTimer3forTxing_C.png
    \image rtf ATA_openTimer3forTxing_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_openTimer3forTxing_C(void)
{
    timer3.status |= BIT_MASK_7;    /* lock timer3 */
    
    /* -- SIX-3057 -- */
    PRR1 &= (uint8_t)~BM_PRT3;       /* enable power for timer3 */
    /* -- SIX-3057 -- */
    
    T3IMR = 0U;
    T3MRB = 0U;
    T3MRA = BM_T3CS1;               /* clk = xto/4 prescaler = 1 */

    if(trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA){
        /* setup T3COR for Tx Data Rate for Path A */
        T3CORL = currentService.service.TXDRA[0];
        T3CORH = currentService.service.TXDRA[1];
    }
    else {
        /* setup T3COR for Tx Data Rate for Path B */
        T3CORL = currentService.service.TXDRB[0];
        T3CORH = currentService.service.TXDRB[1];
    }
    T3CR |= (BM_T3ENA | BM_T3CRM | BM_T3CTM);
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_sysTxingBufferedMode_C</b>
    setup the Send-TX state machine in buffered mode.

    \return none

    \image html ATA_sysTxingBufferedMode_C.png
    \image rtf ATA_sysTxingBufferedMode_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_sysTxingBufferedMode_C(void)
{
    FSEN |= BM_SDEN;    /* ATA_enableRegs4Tx */

    FSCR &= BM_TXMOD;
    FSCR |= BM_TXMS1;

    if (trxStatus & BM_TRX_STATUS_TX_ASK_FSK_MODULATION)
    {
        // ASK Modulation
        FSCR |= BM_TXMOD;
    }
    else
    {
        // FSK Modulation
        FSCR |= BM_SFM;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_sysTxingTransparentMode_C</b>
    setup the Send-TX state machine in transparent mode.

    \return none

    \image html ATA_sysTxingTransparentMode_C.png
    \image rtf ATA_sysTxingTransparentMode_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_sysTxingTransparentMode_C(void)
{
    FSEN |= BM_SDEN;    /* ATA_enableRegs4Tx */

    FSCR &= BM_TXMOD;
    FSCR |= BM_TXMS0;

    if( trxStatus & BM_TRX_STATUS_TX_ASK_FSK_MODULATION )
    {
        // ASK Modulation
        FSCR |= BM_TXMOD;
    }
    else
    {
        // FSK Modulation
        FSCR |= BM_SFM;

    }
    DDRC  &= (uint8_t)~BM_DDRC4;
    PORTC &= (uint8_t)~BM_PORTC4;

}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_setupTxModulator_C</b>
    this function initializes the TX modulator according to the settings in
    variable currentService.service.

    \return none

    \image html ATA_setupTxModulator_C.png
    \image rtf ATA_setupTxModulator_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_setupTxModulator_C(void)
{
    if (trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA) {
        TMCR1 = BM_TMCIM | BM_TMSCS;
        TMCR2 = currentService.service.TMCR2A;
        TMSR  = BM_TMTCF;
        TMSSC = currentService.service.TMSSCA;
        TMTLL = currentService.service.TMTLA[0];
        TMTLH = currentService.service.TMTLA[1];
        TMCPL = currentService.service.TMCPA[0];
        TMCPH = currentService.service.TMCPA[1];
        TMCIL = currentService.service.TMCIA[0];
        TMCIH = currentService.service.TMCIA[1];
        TMCSB = currentService.service.TMCSBA;
    }
    else {
        TMCR1 = BM_TMCIM | BM_TMSCS;
        TMCR2 = currentService.service.TMCR2B;
        TMSR  = BM_TMTCF;
        TMSSC = currentService.service.TMSSCB;
        TMTLL = currentService.service.TMTLB[0];
        TMTLH = currentService.service.TMTLB[1];
        TMCPL = currentService.service.TMCPB[0];
        TMCPH = currentService.service.TMCPB[1];
        TMCIL = currentService.service.TMCIB[0];
        TMCIH = currentService.service.TMCIB[1];
        TMCSB = currentService.service.TMCSBB;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_txStateInitSSM_C</b>
    this tx state machine initializes the sequencer state machine
    and switch to next state -> ATA_txStateWait4SSMrdy_C.

    \return none

    \image html ATA_txStateInitSSM_C.png
    \image rtf ATA_txStateInitSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_txStateInitSSM_C(void)
{
    (void)ATA_startInitTxRxSSM_C();

    /* setup TX for acting in buffered or transparent mode. */
    if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_TRANSPARENT_MODE) {
        /* TMDEN = 1 -> transparent Mode */
        ATA_sysTxingTransparentMode_C();
    }
    else {
        /* TMDEN = 0 -> buffered Mode */
        ATA_sysTxingBufferedMode_C();
    }

    if (FESR & BM_XRDY) {
        /* if XTO is already on skip state ATA_systemFlowStateWaitXtoReady_C */
        ATA_txStateStartSSM_C();
        flowCtrl.index = TX_FLOW_STATE_SSM_RDY;
    }
    else {
        flowCtrl.index++;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_txStateStartSSM_C</b>
    this tx state machine starts the sequencer state machine
    and switch to next state -> ATA_txStateWait4SSMrdy_C.

    \return none

    \image html ATA_txStateStartSSM_C.png
    \image rtf ATA_txStateStartSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_txStateStartSSM_C(void)
{
    flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_TX;
    ATA_systemStartSSM_C( DEBUG_ERROR_CODE_TX_STATESTARTSSM_TIMER_LOCKED );
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_txStateWait4SSMrdy_C</b>
    this tx state machine waits for the end of the sequencer state machine
    and switch to next state -> ATA_txStateWait4FillLevel_C.

    \return none

    \image html ATA_txStateWait4SSMrdy_C.png
    \image rtf ATA_txStateWait4SSMrdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_txStateWait4SSMrdy_C(void)
{
    ATA_systemWait4SSMrdy_C( DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT,
                             TX_FLOW_STATE_SHUTDOWN );

    if( flowCtrl.index == (TX_FLOW_STATE_SSM_RDY + 1U) ) {

        /* set cmdRdy flag for TX */
        events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
        if (events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_TX) {
            ATA_setEventPin_ASM();
        }
        else {
        }

        /* SSM is ready --> store FEVCT and FEAT */
        currentService.service.FEAT = FEAT;
        currentService.service.FEVCT = FEVCT;

        /* set enable flag for directswitching */
        sysStatus |= BM_SYS_STATUS_RDY_4_DIRECTSWITCHING;

        ATA_txStateWait4FillLevel_C();
    }
    else {
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_txTransparentStateWait4SSMrdy_C</b>
    this tx state machine waits for the end of the sequencer state machine
    and switch to next state -> ATA_txStateTransparentMode_C.

    \return none

    \image html ATA_txTransparentStateWait4SSMrdy_C.png
    \image rtf ATA_txTransparentStateWait4SSMrdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_txTransparentStateWait4SSMrdy_C(void)
{
    ATA_systemWait4SSMrdy_C( DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT,
                             TX_TRANS_FLOW_STATE_SHUTDOWN );

    if( flowCtrl.index == (TX_FLOW_STATE_SSM_RDY + 1U) ) {
        /* SSM is ready --> store FEVCT and FEAT */
        currentService.service.FEAT = FEAT;
        currentService.service.FEVCT = FEVCT;

        sysStatus |= BM_SYS_STATUS_RDY_4_DIRECTSWITCHING;

        /* set enable flag for directswitching */
        FSCR |= BM_PAOER;

        /* set cmdRdy flag for TX */
        events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
        if (events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_TX) {
            ATA_setEventPin_ASM();
        }
        else {
        }
    }
    else {
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_txStateTransparentMode_C</b>
    this tx state is executed after TX transparent mode is reached.
    This state is the last one in TX transparent mode. Transition to other
    modes is only possible over IDLEMode.

    \return none

    \image html ATA_txStateTransparentMode_C.png
    \image rtf ATA_txStateTransparentMode_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_txStateTransparentMode_C(void)
{
    sysStatus |= BM_SYS_STATUS_SSM_SLEEP_ENABLE;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_txStateWait4FillLevel_C</b>
    this tx state machine waits for the correct fill level
    of the TX buffer and switches to next state -> ATA_txStateStartTxModulator_C.

    \return none

    \image html ATA_txStateWait4FillLevel_C.png
    \image rtf ATA_txStateWait4FillLevel_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_txStateWait4FillLevel_C(void)
{
    uint8_t txFifoStartFillLevel  = 0U;
    uint8_t preambleFifoStartFillLevel = 0U;

    if( trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA )
    {
        // PATH A
        txFifoStartFillLevel = currentService.service.txSetPathA[0] & BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL;
        preambleFifoStartFillLevel = currentService.service.txSetPathA[1] & BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL ;
    }
    else
    {
        // PATH B
        txFifoStartFillLevel = currentService.service.txSetPathB[0] & BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL;
        preambleFifoStartFillLevel = currentService.service.txSetPathB[1] & BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL ;
    }

    if(    ( txFifoStartFillLevel  <= (DFL & BM_DFFLS) )
        && ( preambleFifoStartFillLevel <= (SFL & BM_SFFLS) )
      )
    {
        flowCtrl.index++;
        ATA_txStateStartTxModulator_C();
    }
    else
    {
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_txStateStartTxModulator_C</b>
    this tx state machine function configures the TX fifos and
    starts/enables the TX modulator
    and switch to next state -> ATA_txStateStartWait4TransmissionComplete_C.

    \return none

    \image html ATA_txStateStartTxModulator_C.png
    \image rtf ATA_txStateStartTxModulator_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_txStateStartTxModulator_C(void)
{
    // preamble buffer
    SFC  = BM_SFDRA;       // TXMode for preamble buffer
    // set buffer fill level to generate related interrupts
    if( trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA ) {
        SFC |= (currentService.service.txPreambleSysEventA & BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF);
    }
    else {
        SFC |= (currentService.service.txPreambleSysEventB & BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF);
    }
    SFI |= BM_SFFLIM;       // enable preamble buffer fill level interrupt

    // data fifo
    DFC = BM_DFDRA;        // TXMode for data fifo buffer

    // set buffer fill level to generate related interrupts
    if( trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA )
    {
        DFC |= (currentService.service.txSysEventA & BM_SERVICE_TXSYSEVENTA_TXBUF);
    }
    else
    {
        DFC |= (currentService.service.txSysEventB & BM_SERVICE_TXSYSEVENTB_TXBUF);
    }

    DFI  |= BM_DFFLIM;      // enable data fifo buffer fill level interrupt

    FSCR |= BM_PAOER;

    PRR2 |= BM_PRTM;
    PRR2 &= (uint8_t)~BM_PRTM;       // power-up TX modulator after finishing buffer configuration

    ATA_openTimer3forTxing_C();

    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_txStateStartWait4TransmissionComplete_C</b>
    this tx state machine function waits for transmission complete interrupt.
    If buffer empty interrupt occurs the state machine switch
    to next state -> ATA_systemFlowStateShutdownTRX_C.

    \return none

    \image html ATA_txStateStartWait4TransmissionComplete_C.png
    \image rtf ATA_txStateStartWait4TransmissionComplete_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_txStateStartWait4TransmissionComplete_C(void)
{
    uint8_t txSysEvent = 0U;
    if (trxStatus & BM_TRX_STATUS_TX_TRANSMISSION_COMPLETE)
    {
        // disable buffer fill level interrupts -> Over-/Underflow IRQ is still active
        SFI &= (uint8_t)~BM_SFFLIM;
        DFI &= (uint8_t)~BM_DFFLIM;
        trxStatus &= (uint8_t)~BM_TRX_STATUS_TX_TRANSMISSION_COMPLETE;

        /* switch PA OFF */
        FSCR &= (uint8_t)~BM_PAOER;

        if (trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_PATHA) {
            /* Path A enabled */
            txSysEvent = currentService.service.txSysEventA;
        }
        else {
            /* Path B enabled */
            txSysEvent = currentService.service.txSysEventB;
        }

        if (txSysEvent & BM_SERVICE_TXSYSEVENTA_TX_ENDING) {
            /* TX ENDING = 1 --> stay in TX and goto ATA_txStateWait4FillLevel_C */
            flowCtrl.index = TX_FLOW_STATE_WAIT4FILLLEVEL;
        }
        else {
            flowCtrl.index++;
        }
    }
    else {
        sysStatus |= BM_SYS_STATUS_SSM_SLEEP_ENABLE;
    }
}
