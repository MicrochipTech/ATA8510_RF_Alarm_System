/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/rf/src/rf.c $
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
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "rf.h"
#include "../../globals/src/globals.h"
#include "../../eep/src/eep.h"
#include "../../timer2/src/timer2.h"
#include "../../timer3/src/timer3.h"
#include "../../calib/src/calib.h"
#include "../../rfrx/src/rfrx.h"
#include "../../rftx/src/rftx.h"
#include "../../system/src/system.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/

/** \brief <b>rfPaCtrl</b>
    contains the power amplifier specific settings.
*/
#pragma location = ".pactrl"
__no_init sRfPaCtrl rfPaCtrl;

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_resetSSMs_C</b>
    is called at system mode switching and checks if direct switching is possible
    or not. The sequencer state machines are configured and started accordingly.
    \return none

    \image html ATA_resetSSMs_C.png
    \image rtf ATA_resetSSMs_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_resetSSMs_C(void)
{
    if (   (flowCtrl.lastStartedSsm != FLOW_CTRL_LAST_STARTED_SSM_SHUTDOWN)
        // && (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_DIRECT_SWITCH)
       )
    {
        if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_DIRECT_SWITCH) {
            /* SSM is running */
            SSMRR = BM_SSMST;   /* stop running SSM */

            /* --SIX-3308-- */
            DFL   |= BM_DFCLR;
            SFL   |= BM_SFCLR;
            /* --SIX-3308-- */
            
            /* SSMCR - SSM Control Register*/
            SSMCR &= (uint8_t)(BIT_MASK_7 | BIT_MASK_6) ;

            /* MSMCR1..2 - Master State Machine Control Register 1..2 */
            if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM1 ) {
                // RXMode/PollingMode selected
                if(flowCtrl.lastStartedSsm == FLOW_CTRL_LAST_STARTED_SSM_RX) {
                    /* coming from RX --> 1st state is rx_dsp_dis ssm */
                    MSMCR1 = SSM_RX_DSP_DIS_STATE;
                } else {
                    /* coming from TX --> 1st state is tx_rx */
                    MSMCR1 = SSM_TX_2_RX_STATE;
                }
            }
            else {
                // TXMode selected
                if(flowCtrl.lastStartedSsm == FLOW_CTRL_LAST_STARTED_SSM_RX) {
                    /* coming from RX --> 1st state is rx_tx ssm */
                    MSMCR1 = SSM_RX_2_TX_STATE;
                } else {
                    /* coming from TX --> 1st state is tx_dsp_dis */
                    MSMCR1 = SSM_TX_DSP_DIS_STATE;
                }
            }

            /* SSMIFR - SSM Interrupt Flag Register */
            SSMIFR = 0x00U;

            /* SSMSR - SSM status register */
            SSMSR |= BM_SSMERR;

            sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;     // reset flag

            /* SSMIMR - SSM Interrupt Mask Register */
            SSMIMR = BM_SSMIM;

            /* SSMRR - SSM Run Register */
            SSMRR = BM_SSMR;
        }
        else {
            /* no direct switching --> start shutdown ssm and wait until its down */
            (void)ATA_blockingShutDownSSM_C();
        }
    }
    else{
        /* last running SSM was SHUTDOWN SSM --> no SSM for switching required */
    }
}
/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_startInitTxRxSSM_C</b>
    is used to configure the TX/RX sequencer state machines
    and is usually part of the 1st state of the SW state machines for RXMode, TXMode ...

    This function
    \li enables AVCC
    \li loads the service/channel configuration into currentService (ATA_currentServiceInit_C)
    \li initializes the FE after AVCC is ready
    \li does register initialization for RXMode, TXMode ...(ATA_startInitRxSSM_C/ATA_startInitTxSSM_C)
    \li triggers RF calibration (ATA_rfCalibration_C)
    \li configures the Sequencer State Machines (SSM) for RXMode or TXMode

    \return status of ATA_startInitTxRxSSM_C. If interrupted by SPI command FAIL is returned other OK

    \image html ATA_startInitTxRxSSM_C.png
    \image rtf ATA_startInitTxRxSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
UINT8FUNC ATA_startInitTxRxSSM_C(void)
{
    FSCR  = 0x00U;

    // reset subchanneling flags
    subChan.flags = 0U;

    /* check for interruption due to SPI command 'Set System Mode' */
    if (sysStatus & BM_SYS_STATUS_UPDATE) {
        return FAIL;
    }

    /* --SIX-1539--  */
    /* reset currently running RX/TX SSM */
    ATA_resetSSMs_C();
    /* --SIX-1539--  */

    /* check for interruption due to SPI command 'Set System Mode' */
    if (sysStatus & BM_SYS_STATUS_UPDATE) {
        return FAIL;
    }

    // AVCC needs up to 150us/100us (depends on 3V/5V) to ramp-up after setting AVEN.
    // While executing routines ATA_currentServiceInit_C() and ATA_checkModulationType_ASM() AVCC ramps up.
    SUPCR |= BM_AVEN;

    // takes ~10us(no copy actions) - ~160us(service and channel SRAM copy actions), FRC based (not FRC worstcase)
    ATA_currentServiceInit_C(trxConf.serviceChannelConfig);

    /* check for interruption due to SPI command 'Set System Mode' */
    if (sysStatus & BM_SYS_STATUS_UPDATE) {
        return FAIL;
    }

    trxStatus = 0U;
    if( trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM1 )
    {   // RXMode/PollingMode selected
        trxStatus  =  currentService.service.rxSetPathA[1] & BM_TRX_STATUS_RX_ASK_FSK_MODULATION_PATHA;
        trxStatus |= (uint8_t)((currentService.service.rxSetPathB[1] & BM_TRX_STATUS_RX_ASK_FSK_MODULATION_PATHB) << 1U);
    }
    else
    {   // TXMode selected
        if( ATA_checkModulationType4TX_ASM() )    // takes ~2.5us, FRC based
        {
            trxStatus |= TRX_STATUS_TX_ASK_MODULATION;
        }
    }

    ATA_wait4avcc_C();

    /* check for interruption due to SPI command 'Set System Mode' */
    if (sysStatus & BM_SYS_STATUS_UPDATE) {
        return FAIL;
    }

    ATA_doFeInit4TxRxSSM_C();

    if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM1) {
        // RXMode/PollingMode selected
        ATA_startInitRxSSM_C();
    }
    else {
        // TXMode selected
        ATA_startInitTxSSM_C();
    }

    /* check for interruption due to SPI command 'Set System Mode' */
    if (sysStatus & BM_SYS_STATUS_UPDATE) {
        return FAIL;
    }

    if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_RF_CALIBRATION) {
        ATA_rfCalibration_C();
    }

    /* check for interruption due to SPI command 'Set System Mode' */
    if (sysStatus & BM_SYS_STATUS_UPDATE) {
        return FAIL;
    }


    /* setup Sequencer State Machine */
    if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM1) {
        /* RXMode/PollingMode selected */
        ATA_configureRxSSM_C();
    }
    else {
        /* TXMode selected */
        ATA_configureTxSSM_C();
    }

    return OK;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_startShutDownSSM_C</b>
    This function configures and starts the ShutDown sequencer state machine.

    \return none

    \image html ATA_startShutDownSSM_C.png
    \image rtf ATA_startShutDownSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_startShutDownSSM_C(void)
{
    /* disable flag for directswitching */
    sysStatus &= (uint8_t)~BM_SYS_STATUS_RDY_4_DIRECTSWITCHING;

    flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_SHUTDOWN;

    /* switch PA OFF */
    FSCR &= (uint8_t)~BM_PAOER;

    /* --SIX-2557-- */
    /* switch off antenna tuning */
    FSEN &= (uint8_t)~BM_ANTT;
    /* --SIX-2557-- */

    /* enable SSM working */
    PRR2 &= (uint8_t)~BM_PRSSM;

    /* SSMCR - SSM Run Register*/
    SSMRR = BM_SSMST;   /* set SSM in stop state to reset SSM */

    /* SSMCR - SSM Control Register*/
    SSMCR = 0x00U;

    /* MSMCR1 - Master State Machine Control Register 1 */
    MSMCR1 = 0x0BU;

    /* SSMIFR - SSM Interrupt Flag Register */
    SSMIFR = 0x00U;

    /* SSMSR - SSM status register */
    SSMSR |= BM_SSMERR;

    sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;     // reset flag

    /* SSMIMR - SSM Interrupt Mask Register */
    SSMIMR = BM_SSMIM;

    /* SSMRR - SSM Run Register */
    SSMRR = BM_SSMR;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_doFeInit4TxRxSSM_C</b>
    This function does the RF frontend initialization for TXMode or RXMode.

    \return none

    \image html ATA_doFeInit4TxRxSSM_C.png
    \image rtf ATA_doFeInit4TxRxSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_doFeInit4TxRxSSM_C(void)
{
    uint8_t idleModeSelector = trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR;

    if (idleModeSelector == 0U) {
        // IDLE_RC
        FETN4 = facLock.confFETN4;
        FEEN1 |= BM_XTOEN;
    }
    else {  // IDLE_XTO
    }

    if ((currentService.channel.FECR & BM_S4N3) == 0U) {
        FELNA = facLock.confFELNA2;
    }
    else {
        FELNA = facLock.confFELNA;
    }

    FEAT = currentService.service.FEAT;

    FEBT = facLock.confFEBT;

    /* SIX-825 */
    if (currentService.service.FEPAC > rfPaCtrl.paDamping) {
        FEPAC = currentService.service.FEPAC - rfPaCtrl.paDamping;
    }
    else {
        FEPAC = 0U;
    }
    /* SIX-825 */

    FEVCO = ATA_doFevcoRegisterCalculation_C();
    /* >>>>>>>>>>>>>>>>>>> ATA_doAntennaSwitching_C >>>>>>>>>>>>>>>>>>>> */
    /* SIX-836 */
    /* FEEN2.SDRX = FEEN2.SDTX = 0; --> default setting */
    FEEN2 &= (uint8_t)~(BM_SDRX|BM_SDTX);

    if (currentService.service.trxSysConf & BM_SERVICE_TRXSYSCONF_ANTENNA_SWITCHING) {
        /* antennaSwitching enabled */
        if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM1) {
            /* RX/RX Polling */
            /* FEEN2.SDRX = sServiceSpecificConfiguration.rxSysSet Bit 0 (switching_SDRX); */
            /* FEEN2.SDTX = sServiceSpecificConfiguration.rxSysSet Bit 1 (switching_SDTX); */
            FEEN2 |= (currentService.service.rxSysSet & BM_SERVICE_RXSYSSET_SWITCHING);
        }
        else {
            /* TX */
            /* FEEN2.SDRX = FEEN2.SDTX = 0; */
        }
    }
    else {
        /* antennaSwitching disabled */
        if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM1) {
            /* RX/RX Polling */
            /* FEEN2.SDRX = 1; */
            /* FEEN2.SDTX = 0; */
            FEEN2 |= BM_SERVICE_RXSYSSET_SWITCHING_SDRX;
        }
        else {
            /* TX */
            /* FEEN2.SDRX = 0; */
            /* FEEN2.SDTX = 1; */
            FEEN2 |= BM_SERVICE_RXSYSSET_SWITCHING_SDTX;
        }
    }
    /* SIX-836 */
    /* <<<<<<<<<<<<<<<<<<< ATA_doAntennaSwitching_C <<<<<<<<<<<<<<<<<<<< */

    FECR  = currentService.channel.FECR;
    FEMS  = currentService.channel.FEMS;
    FEVCT = currentService.service.FEVCT;

}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_doFevcoRegisterCalculation_C</b>
    This function does the calculation for FEVCO register setting.

    \return calculated value for FEVCO register
*/
/*----------------------------------------------------------------------------- */
UINT8FUNC ATA_doFevcoRegisterCalculation_C(void)
{
    uint8_t retVal = 0U;

    int8_t result       = 0;

    uint8_t vcob        = (currentService.service.FEVCO & 0xF0U) >> 4U;
    uint8_t vcobOffset  = (facLock.confFEVCOoffset & 0xF0U) >> 4U;

    uint8_t cpcc        = currentService.service.FEVCO & 0x0FU;
    uint8_t cpccOffset  = facLock.confFEVCOoffset & 0x0FU;

    /* sign extension for vcob */
    if (vcob > 7U) {
        vcob |= 0xF0U;
    }

    /* sign extension for cpcc */
    if (cpcc > 7U) {
        cpcc |= 0xF0U;
    }
    /* setup vcob settings */
    result = 7 + (int8_t)vcob + (int8_t)vcobOffset;
    if(result < 0) {
        result = 0;
    }
    else {
    }
    vcob = (uint8_t)((uint8_t)result << 4U);
    vcob &= 0xF0U;

    /* setup cpcc settings */
    result = 7 + (int8_t)cpcc + (int8_t)cpccOffset;
    if (result < 0){
        result = 0;
    }
    else {
    }
    cpcc = (uint8_t)result;
    cpcc &= 0x0FU;

    retVal = vcob | cpcc;

    return retVal;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_shutDownRf_C</b>
    This function sets the RF related parts to a defined start value.

    \return none

    \image html ATA_shutDownRf_C.png
    \image rtf ATA_shutDownRf_C.png
    \n
*/
/*-----------------------------------------------------------------------------*/
VOIDFUNC ATA_shutDownRf_C(void)
{
    DDRC = ATA_eepRDbyte_ASM(&eepIO.confDDRC);

    RDSIMR = 0U;

    ATA_pwrDwnDsp_C();

    if (SUPCR & BM_AVEN) {
        FECR &= (uint8_t)~BM_ANDP;       // switch off Antenna Damping
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_shutDownFe_C</b>
    This function removes power from the RF frontend.

    \return none

    \image html ATA_shutDownFe_C.png
    \image rtf ATA_shutDownFe_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_shutDownFe_C(void)
{
    if (SUPCR & BM_AVEN) {
        ATA_waitNus_ASM(8U);        // delay regarding the FRC clk

        if ((trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR)== 0U){
            // IDLE_RC
            ATA_clkSwitchFRC_C();
            FEEN1 = 0U;
            SUPCR &= (uint8_t)~(BM_AVEN | BM_AVCCRM | BM_AVCCLM | BM_AVDIC);
        }
        else{
            // IDLE_XTO
            SUPCR &= (uint8_t)~(BM_AVDIC);
            FEEN2 = 0U;
            FEEN1 = BM_XTOEN;
        }
    }

    trxConf.systemConfig &= (uint8_t)~BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR;
    trxConf.systemConfig |= (trxConf.systemModeConfig >> 3) & BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR;

    ATA_clrRxActive_ASM();
}

/*-----------------------------------------------------------------------------*/
/**  \brief <b>ATA_pwrDwnDsp_C</b>
    This function powers down the DSP.

    \return none

    \image html ATA_pwrDwnDsp_C.png
    \image rtf ATA_pwrDwnDsp_C.png
    \n
*/
/*-----------------------------------------------------------------------------*/
VOIDFUNC ATA_pwrDwnDsp_C(void)
{
    ATA_timer2Close_ASM();
    ATA_timer3Close_ASM();

    RDSIFR = (BM_WCOB | BM_WCOA | BM_SOTB | BM_SOTA | BM_EOTB | BM_EOTA | BM_NBITB | BM_NBITA);

    RDCR = 0x00U;
    FSCR = 0x00U;
    FSEN = 0x00U;

    while(RDPR & BM_RDPRF){
    }

    RDPR = (BM_PRTMP | BM_PRFLT | BM_PRPTA | BM_PRPTB);
    RDOCR = 0x00U;

    PRR2 |= (BM_PRSSM | BM_PRTM | BM_PRRS | BM_PRIDS | BM_PRXB | BM_PRXA);
    PRR1 |= (BM_PRT3 | BM_PRT2);
    PRR0 |= (BM_PRCRC | BM_PRTXDC | BM_PRRXDC);
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_ssmInterrupt_C</b>
    This funtion is the interrupt handler for sequencer state machine READY event.

    \return none

    \image html ATA_ssmInterrupt_C.png
    \image rtf ATA_ssmInterrupt_C.png
*/
/*----------------------------------------------------------------------------- */
#pragma vector=SSM_vect
__interrupt void ATA_ssmInterrupt_C(void)
{   /*lint !e957 GeWi (30jun11) ISR needs no prototype therefore Note 957 is disabled */
    sysStatus |= ( BM_SYS_STATUS_TRIGGER_MAIN_LOOP | BM_SYS_STATUS_SSMRDY );
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_IDscanBufferFullInterrupt_C</b>
    This function is the interrupt handler for IDscan buffer full event.

    \return none

    \image html ATA_IDscanBufferFullInterrupt_C.png
    \image rtf ATA_IDscanBufferFullInterrupt_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
#pragma vector=IDFULL_vect
__interrupt void ATA_IDscanBufferFullInterrupt_C(void)
{   /*lint !e957 GeWi (30jun11) ISR needs no prototype therefore Note 957 is disabled */
    sysStatus            |= BM_SYS_STATUS_TRIGGER_MAIN_LOOP;
    trxConf.idScanStatus |= BM_SYS_ID_SCAN_STATUS_BUF_FULL;
}
