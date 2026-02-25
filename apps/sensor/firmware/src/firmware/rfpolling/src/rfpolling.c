/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/rfpolling/src/rfpolling.c $
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
#include "rfpolling.h"
#include "../../globals/src/globals.h"
#include "../../system/src/system.h"
#include "../../rf/src/rf.h"
#include "../../rfrx/src/rfrx.h"
#include "../../eep/src/eep.h"
#include "../../timer1/src/timer1.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/

/** \brief <b>pollConfig</b>
    contains the PollingMode specific channel and Timer1 settings.
*/
#pragma location = ".pollingconfig"
__root __no_init sPollingConfig    pollConfig;

/** \brief <b>pollStatus</b>
    contains the PollingMode specific status information.
*/
#pragma location = ".pollingstatus"
__root __no_init sPollingStatus    pollStatus;

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_pollStateInitCurrentPollingChannel_C</b>
    sets current polling channel configuration for start of rx sequencer state
    machine.

    \return none

    \image html ATA_pollStateInitCurrentPollingChannel_C.png
    \image rtf ATA_pollStateInitCurrentPollingChannel_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_pollStateInitCurrentPollingChannel_C(void)
{
    uint8_t index = pollStatus.confIdx;

    // mask all unneeded bits and overwrite it with stored configuration
    trxConf.systemModeConfig &= (uint8_t)BM_POLLCONFIG_SYS_MODE_CONFIG_VALID;
    trxConf.systemModeConfig |= (pollConfig.pollChanConf[index].config & BM_POLLCONFIG_CONFIG_CALIBRATION);

    // check if VCO calibration must be done on first polling channel
    if( pollStatus.flags & POLLING_VCO_CAL_ON_FIRST_CHANNEL )
    {
        trxConf.systemModeConfig |= BM_SYS_MODE_CONFIG_VCO_TUNING;
        pollStatus.flags         &= (uint8_t)~POLLING_VCO_CAL_ON_FIRST_CHANNEL;
    }

    trxConf.serviceChannelConfig = pollConfig.pollChanConf[index].svcChConfig;

    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_pollStateInitSSM_C</b>
    this Polling state initializes the sequencer state machine
    and switch to next state -> ATA_systemFlowStateWaitXtoReady_C.

    \return none

    \image html ATA_pollStateInitSSM_C.png
    \image rtf ATA_pollStateInitSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_pollStateInitSSM_C(void)
{
    (void)ATA_startInitTxRxSSM_C();

    /* -- SIX-2608 -- */
    if (currentService.service.trxSysConf & BM_SERVICE_TRXSYSCONF_CHANNEL_SWITCHING) {
        // channel switch enabled for this service
        ATA_initChannelSwitchForCurrentService_C();
    }
    /* -- SIX-2608 -- */

    // clear 'demodulator automatic restart'
    GTCR  &= (uint8_t)~(BM_DARB | BM_DARA);
    DMCRA &= (uint8_t)~BM_DMARA;
    DMCRB &= (uint8_t)~BM_DMARB;

    // check for enabled subchanneling feature
    if( currentService.service.rxSysSet & BM_SERVICE_RXSYSSET_SUBCHANNELING )
    {
        flowCtrl.pLut = pSubChannelingSysFlowStateMachine;

        if( FESR & BM_XRDY )
        {
            ATA_rxStateInitSubchanneling_C();
            // flowCtrl.index already incremented to 2
            //flowCtrl.index = SUBCHANNELING_FLOW_STATE_CENTER_FREQ;
        }
        else
        {
            flowCtrl.index = SUBCHANNELING_FLOW_STATE_WAIT_XTO_RDY;
        }
    }
    else
    {   // subchanneling disabled
        if (FESR & BM_XRDY) {
            /* if XTO is already on skip state ATA_systemFlowStateWaitXtoReady_C */
            ATA_rxStateStartSSM_C();
            flowCtrl.index = POLL_FLOW_STATE_SSM_GETTELEGRAM;
        }
        else {
            flowCtrl.index++;
        }
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_pollStateWait4SSMstateGetTelegram_C</b>
    waits for the reaching of the sub state machine Get Telegram of the
    sequencer state machine and switch to next state -> ATA_rxStateWait4SSMrdy_C.

    \return none

    \image html ATA_pollStateWait4SSMstateGetTelegram_C.png
    \image rtf ATA_pollStateWait4SSMstateGetTelegram_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_pollStateWait4SSMstateGetTelegram_C(void)
{
    if( MSMSTR >= flowCtrl.msmstate )
    {
        // no software security control used during telegram detection/reception
        ATA_stopSsmWatchdog_C();

        // disable/enable overflow/underflow interrupt for SFIFO in RX according to trxConfig.systemConfig setting
        if( trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_SFIFO_OFL_UFL_RX_DISABLE )
        {
            // disable overflow/underflow interrupt for SFIFO in RX
            SFI &= (uint8_t)~BM_SFERIM;
        }
        else
        {
            SFI |= BM_SFERIM;
        }

        // disable/enable overflow/underflow interrupt for DFIFO in RX according to trxConfig.systemConfig setting
        if( trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_DFIFO_OFL_UFL_RX_DISABLE )
        {
            // disable overflow/underflow interrupt for SFIFO in RX
            DFI &= (uint8_t)~BM_DFERIM;
        }
        else
        {
            DFI |= BM_DFERIM;
        }

        // set enable flag for direct switching
        sysStatus |= BM_SYS_STATUS_RDY_4_DIRECTSWITCHING;

        // SSM is ready --> store FEVCT
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

            debug.errorCode = DEBUG_ERROR_CODE_POLL_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT;
            debug.ssmErrorCode = SSMSR;
            ATA_setSystemError_ASM();

            // patch SW state to shutdown
            flowCtrl.index = POLL_FLOW_STATE_SHUTDOWN;
        }
        else
        {}
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_pollStateWait4ShutdownRdyTRX_C</b>
    this state machine function waits for end of ShutDown sequencer state machine.

    \return none

    \image html ATA_pollStateWait4ShutdownRdyTRX_C.png
    \image rtf ATA_pollStateWait4ShutdownRdyTRX_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_pollStateWait4ShutdownRdyTRX_C(void)
{
    if( (sysStatus & BM_SYS_STATUS_SSMRDY) && (SSMSR == 0x00U) )
    {
        ATA_stopSsmWatchdog_C();
        sysStatus &= (uint8_t)~BM_SYS_STATUS_SSMRDY;

        ATA_sysIdleMode_C();

        ATA_timer1Close_ASM();

        trxConf.systemModeConfig &= (uint8_t)~BM_SYS_MODE_CONFIG_OPM;

        pollStatus.flags = 0U;
        flowCtrl.index   = POLL_FLOW_STATE_END;
    }
    else
    {
        // check timeout for SSM
        if( (T2IFR & BM_T2COF) || SSMSR )
        {    // timeout of SSM occured
            SSMRR = BM_SSMST;       // reset current state machine
            ATA_stopSsmWatchdog_C();

            debug.errorCode = DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT;
            debug.ssmErrorCode = SSMSR;
            ATA_setSystemError_ASM();

            ATA_sysIdleMode_C();

            ATA_timer1Close_ASM();

            trxConf.systemModeConfig &= (uint8_t)~BM_SYS_MODE_CONFIG_OPM;

            pollStatus.flags = 0U;
            flowCtrl.index   = POLL_FLOW_STATE_END;
        }
        else{}
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_pollStateCheck4NextPollingChannel_C</b>
    checks for end of polling cycle, end of polling loop and enters
    polling sleep or switch to next channel config.
    Enhanced with Polling channel statistics as defined in SIX-1509.

    \return none

    \image html ATA_pollStateCheck4NextPollingChannel_C.png
    \image rtf ATA_pollStateCheck4NextPollingChannel_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_pollStateCheck4NextPollingChannel_C(void)
{
    // stop PollingMode in case of successful telegram reception or
    // stop PollingMode in case of an occurred error
    if( (trxStatus & BM_TRX_STATUS_RX_SOTA_SOTB)
        &&
        ( (trxConf.idScanStatus & (BM_SYS_ID_SCAN_STATUS_RESULT|BM_SYS_ID_SCAN_STATUS_VALID)) == (BM_SYS_ID_SCAN_STATUS_RESULT|BM_SYS_ID_SCAN_STATUS_VALID)) )
    {
        //ATA_timer1Close_ASM();
        flowCtrl.index++;
        
        /* -- SIX-1509 --  A valid telegram has been received, thus the actually selected channel is the best channel. */
        if( currentService.service.rssiSysConf & BM_SERVICE_RSSISYSCONF_RSSI_ENABLE )
        {
            lowestRssiOfCurPolCycle = 0xFFU;
            _CLI;
            sramPollingChannelStatistics.bestChannelPollingIndex = pollStatus.confIdx;
            sramPollingChannelStatistics.bestChannelServiceChannelConfig = trxConf.serviceChannelConfig;
            _SEI;
            
        }
        else
        {
            /* Do computation of best channel until now */
            _CLI;
            sramPollingChannelStatistics.bestChannelPollingIndex = tempBestChannelPollingIndex;
            sramPollingChannelStatistics.bestChannelServiceChannelConfig = tempBestChannelServiceChannelConfig;
            _SEI;
        }
        /* -- SIX-1509 -- */
    }
    else
    {// go ahead with next polling channel
        
        uint8_t config = pollConfig.pollChanConf[pollStatus.confIdx].config;

        /* -- SIX-1509 --  Polling statistics are performed after each polling channel. */
        if( currentService.service.rssiSysConf & BM_SERVICE_RSSISYSCONF_RSSI_ENABLE )
        {
            /* Check SFL whether SFD contains at least one value. If SFL equals 0, this polling channel is not to be considered for Polling Channel Statistics */
            if ( SFL != 0U )
            {
                /* Check whether the RSSI value of the current polling channel is the lowest. If two or more polling channels have the same RSSI value, 
                   only the first channel is considered  */
                /* --SIX-3051-- */
                uint8_t tmpSFD = SFD;
                /* --SIX-3051-- */
                if ( tmpSFD < lowestRssiOfCurPolCycle )
                {
                    lowestRssiOfCurPolCycle = tmpSFD;
                    tempBestChannelPollingIndex = pollStatus.confIdx;
                    tempBestChannelServiceChannelConfig = trxConf.serviceChannelConfig;
                }
            }
        }
        /* -- SIX-1509 -- */
        
        pollStatus.confIdx = (pollStatus.confIdx + 1U) & BM_NUM_POLL_CHAN_CONFIG;
        
        // check for end of polling loop
        if( config & BM_POLLCONFIG_CONFIG_EOL )
        {
            // set polling channel configuration to beginning of config array
            pollStatus.confIdx = 0U;

            /* -- SIX-1509 -- Clear the RSSI value of the current polling cycle and update the global Best Channel information with the Best Channel of the current polling loop */
            lowestRssiOfCurPolCycle = 0xFFU;
            
            _CLI;
            sramPollingChannelStatistics.bestChannelPollingIndex = tempBestChannelPollingIndex;
            sramPollingChannelStatistics.bestChannelServiceChannelConfig = tempBestChannelServiceChannelConfig;
            _SEI;
            /* -- SIX-1509 -- */
        }
        else{}

        // reset sw state machine and start with next polling channel configuration
        flowCtrl.index = 0U;

        // check for non fast Polling and end of polling cycle
        if( (!(pollStatus.flags & POLLING_FAST))
            &&
            (config & BM_POLLCONFIG_CONFIG_EOP) )
        {
            uint16_t selfcheck = ( (uint16_t)ATA_eepRDbyte_ASM(&eepTrxCal.selfChk) ) << 4U;

            trxConf.systemModeConfig &= (uint8_t)~BM_SYS_MODE_CONFIG_DIRECT_SWITCH;
            sysStatus &= (uint8_t)~BM_SYS_STATUS_RDY_4_DIRECTSWITCHING;

            flowCtrl.pLut = 0x0000U;    // hang-out polling function pointer

            (void)ATA_blockingShutDownSSM_C();

            // check for globally enabled system self-check and calibration and additionally
            // the number of polling cylces equals the number of configured polling cycles
            // or system self-check and calibration after first polling cycle is enabled
            if( selfcheck &&
                ( (selfcheck == pollStatus.cycleCnt)
                  ||
                  (pollStatus.flags & POLLING_SELFCHECK_FIRST_CYCLE)
                ) )
            {
                    pollStatus.flags    &= (uint8_t)~POLLING_SELFCHECK_FIRST_CYCLE;
                    pollStatus.cycleCnt  = 0U;       // reset polling cycle counter value

                    // read self-check configuration from EEPROM
                    trxConf.tuneCheckConfig = ATA_eepRDbyte_ASM(&eepTrxCal.calConf1);

                    // check for something to do
                    if( trxConf.tuneCheckConfig )
                    {
                        trxConf.tuneCheckConfig |= BM_TUNE_CHECK_CONFIG_SELF_CHECK;

                        pollStatus.flags |= POLLING_SELFCHECK;      // trigger system self-check and calibration

                        sysStatus      |= BM_SYS_STATUS_CALIB;      // indicates a calibration process is ongoing
                        flowCtrl.index  = SELFCHECK_FLOW_STATE_SRCFRCREGREFRESH;
                        flowCtrl.pLut   = pSelfCheckSysFlowStateMachine;

                        // check for Temperature Measurement during self-check
                        if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_TEMP_MEASUREMENT )
                        {
                            flowCtrl.index = SELFCHECK_FLOW_STATE_TEMPMEAS;
                        }
                    }
                    else
                    {   // nothing to do
                        ATA_sysIdleMode_C();                            // shutdown RF, FE and DSP
                        pollStatus.flags &= (uint8_t)~POLLING_ACTIVE;   // indicate current polling cycle has been finished
                    }
            }
            else
            {
                ATA_sysIdleMode_C();                            // shutdown RF, FE and DSP
                pollStatus.flags &= (uint8_t)~POLLING_ACTIVE;   // indicate current polling cycle has been finished
            }
        }
        else
        {
            //ATA_pwrDwnDsp_C();
            trxConf.systemModeConfig     |= BM_SYS_MODE_CONFIG_DIRECT_SWITCH;
            trxConf.lastSystemModeConfig  = trxConf.systemModeConfig;
        }
    }
}
