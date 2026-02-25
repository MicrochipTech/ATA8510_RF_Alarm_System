/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/calib/src/calib.c $
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
/** \file calib.c
*/
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "calib.h"
#include "../../globals/src/globals.h"
#include "../../eep/src/eep.h"
#include "../../system/src/system.h"
#include "../../rf/src/rf.h"
#include "../../rfrx/src/rfrx.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/
/** \brief calib
    contains the calibration, tune and temperature measurement results
*/
#pragma location = ".calibram"
__no_init sCalibResults calib;

/** \brief frcResults
    contains the results of frc calibration
*/
#pragma location = ".frcresram"
__no_init sFrcCalib frcResults;

/** \brief frcCalPtr
    contains a patchable function pointer for FRC calibration
*/
#pragma location = ".frcfunc"
__no_init sFRCcalPtr frcCalPtr;

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_rfCalibration_C</b>
    Temp depending correction of XTAL based RF - Frequency. The XTAL temperature
    dependant deviation must be held inside the EEPROM in order to compensate
    this temperature dependant deviation of the XTAL.

    \return none

    \image html ATA_rfCalibration_C.png
    \image rtf ATA_rfCalibration_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_rfCalibration_C(void)
{
    uint8_t index = 0U;
    uint8_t remainder = 0U;

    if( calib.tempMeas < 2U ) {
        // measured temperature is less than -48°C
        // --> limit temperature to avoid index mismatch
        index = 0U;
        remainder = 0U;
    }
    else if( calib.tempMeas > 178U ) {
        // measured temperature is greater or equal than +128°C
        // --> limit temperature to avoid index mismatch
        index = 22U;
        remainder = 0U;
    }
    else {
        index = (calib.tempMeas-2U) >> 3U;
        remainder = (calib.tempMeas-2U) & 0x07U;
    }


    // read ppmVals from EEPROM settings
    int8_t ppmValL = (int8_t)ATA_eepRDbyte_ASM((uint8_t *)&eepTrxCal.tempCal[index]);
    int8_t ppmValH = 0;
    if (index < 22U) {
        ppmValH = (int8_t)ATA_eepRDbyte_ASM((uint8_t *)&eepTrxCal.tempCal[index+1U]);
    }
    else {
        ppmValH = ppmValL;
    }

    // calculate ppmValue (variable result16) with linear interpolation
    int16_t result16 = ATA_mulS8U8_ASM((ppmValH - ppmValL), remainder );
/* --SIX-1155-- */
    result16 = result16 + ((int16_t)ppmValL * 8);
/* --SIX-1155-- */

    // calculate frequencyOffset
    int32_t ffreq1Offset = ATA_mpy16s_ASM(result16, (int16_t)currentService.service.TMUL);
/* --SIX-1155-- */
    ffreq1Offset+= 0x0080;  // aovid rounding error
    ffreq1Offset = ATA_shiftRightInt32_ASM(ffreq1Offset, 8U);
/* --SIX-1155-- */
    ffreq1Offset = -ffreq1Offset;

    int32_t ffreq2Offset = ffreq1Offset;

    uint32_t ffreqWord  = ((uint32_t)FFREQ1L <<  0U);
    ffreqWord |= ((uint32_t)FFREQ1M <<  8U);
    ffreqWord |= ((uint32_t)FFREQ1H << 16U);

    // apply frequency correction to frequency registers
    ffreq1Offset += (int32_t)ffreqWord;
    ffreqWord     = (uint32_t)ffreq1Offset;

    FFREQ1L = (uint8_t)(ffreqWord >>  0U);
    FFREQ1M = (uint8_t)(ffreqWord >>  8U);
    FFREQ1H = (uint8_t)(ffreqWord >> 16U);


    if (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM1) {
        /* RX/RX Polling selected */
    }
    else {
        /* TX mode selected */
        if (trxStatus & BM_TRX_STATUS_TX_ASK_FSK_MODULATION) {
            /* ASK Modulation */
        }
        else {
            /* FSK Modulation */
            ffreqWord  = ((uint32_t)FFREQ2L <<  0U);
            ffreqWord |= ((uint32_t)FFREQ2M <<  8U);
            ffreqWord |= ((uint32_t)FFREQ2H << 16U);

            // apply frequency correction to frequency registers
            ffreq2Offset += (int32_t)ffreqWord;
            ffreqWord     = (uint32_t)ffreq2Offset;
            FFREQ2L = (uint8_t)(ffreqWord >>  0U);
            FFREQ2M = (uint8_t)(ffreqWord >>  8U);
            FFREQ2H = (uint8_t)(ffreqWord >> 16U);
        }
    }
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*----------------------------- Antenna Tuning ------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_anttuneStateInitSSM_C</b>

    \return none

    \image html ATA_anttuneStateInitSSM_C.png
    \image rtf ATA_anttuneStateInitSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_anttuneStateInitSSM_C(void)
{
    ATA_sysAntTuneSsmEnable_C();
    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_sysAntTuneSsmEnable_C</b>
    setup the RF-TX sequencer state machine and trigger its start.

    \return none

    \image html ATA_sysAntTuneSsmEnable_C.png
    \image rtf ATA_sysAntTuneSsmEnable_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_sysAntTuneSsmEnable_C(void)
{
    trxConf.systemModeConfig |= OPM_TX;
    trxConf.systemModeConfig |= BM_SYS_MODE_CONFIG_ANTENNA_TUNING;

    (void)ATA_startInitTxRxSSM_C();
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_anttuneStateStartSSM_C</b>
    this state starts the sequencer state machine and switch to next state.

    \return none

    \image html ATA_anttuneStateStartSSM_C.png
    \image rtf ATA_anttuneStateStartSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_anttuneStateStartSSM_C(void)
{
    flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_TX;
    ATA_systemStartSSM_C( DEBUG_ERROR_CODE_ANTTUNE_STATESTARTSSM_TIMER_LOCKED );
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_anttuneStateWait4SSMrdy_C</b>
    this state waits for the end of the sequencer state machine
    and switch to next state.

    \return none

    \image html ATA_anttuneStateWait4SSMrdy_C.png
    \image rtf ATA_anttuneStateWait4SSMrdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_anttuneStateWait4SSMrdy_C(void)
{
    ATA_systemWait4SSMrdy_C( DEBUG_ERROR_CODE_ANTTUNE_STATEWAIT4SSMRDY_TIMEOUT,
                             ANTTUNE_FLOW_STATE_SHUTDOWN );

    if( flowCtrl.index == (ANTTUNE_FLOW_STATE_SSM_RDY + 1U) ) {
        /* SSM is ready --> store FEAT */
        currentService.service.FEAT = FEAT;
        calib.sramFEAT = FEAT;
    }

}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_anttuneStateSetCmdRdy_C</b>
    this state set CMD_RDY flag to indicate antenna tuning is complete
    and switch to next state.

    \return none

    \image html ATA_anttuneStateSetCmdRdy_C.png
    \image rtf ATA_anttuneStateSetCmdRdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_anttuneStateSetCmdRdy_C(void)
{
    events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
    if (events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_ANT_TUNE) {
        ATA_setEventPin_ASM();
    }

    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*----------------------------- VCO Calibration -----------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_vcocalStateInitSSM_C</b>

    \return none

    \image html ATA_vcocalStateInitSSM_C.png
    \image rtf ATA_vcocalStateInitSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_vcocalStateInitSSM_C(void)
{
    ATA_sysVcoCalSsmEnable_C();
    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_sysVcoCalSsmEnable_C</b>
    setup the RF-TX sequencer state machine and trigger its start.

    \return none

    \image html ATA_sysVcoCalSsmEnable_C.png
    \image rtf ATA_sysVcoCalSsmEnable_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_sysVcoCalSsmEnable_C(void)
{
    trxConf.systemModeConfig |= OPM_TX;
    trxConf.systemModeConfig |= BM_SYS_MODE_CONFIG_VCO_TUNING;

    (void)ATA_startInitTxRxSSM_C();
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_vcocalStateStartSSM_C</b>
    this state starts the sequencer state machine and switch to next state.

    \return none

    \image html ATA_vcocalStateStartSSM_C.png
    \image rtf ATA_vcocalStateStartSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_vcocalStateStartSSM_C(void)
{
    flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_TX;
    ATA_systemStartSSM_C( DEBUG_ERROR_CODE_VCOCAL_STATESTARTSSM_TIMER_LOCKED );
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_vcocalStateWait4SSMrdy_C</b>
    this state waits for the end of the sequencer state machine
    and switch to next state.

    \return none

    \image html ATA_vcocalStateWait4SSMrdy_C.png
    \image rtf ATA_vcocalStateWait4SSMrdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_vcocalStateWait4SSMrdy_C(void)
{
    ATA_systemWait4SSMrdy_C( DEBUG_ERROR_CODE_VCOCAL_STATEWAIT4SSMRDY_TIMEOUT,
                             VCOCAL_FLOW_STATE_SHUTDOWN );

    if( flowCtrl.index == (VCOCAL_FLOW_STATE_SSM_RDY + 1U) ) {
        /* SSM is ready --> store FEVCT */
        currentService.service.FEVCT = FEVCT;
        calib.vcoRes = FEVCT;
    }

}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_vcocalStateSetCmdRdy_C</b>
    this state set CMD_RDY flag to indicate vco calibration is complete
    and switch to next state.

    \return none

    \image html ATA_vcocalStateSetCmdRdy_C.png
    \image rtf ATA_vcocalStateSetCmdRdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_vcocalStateSetCmdRdy_C(void)
{
    events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
    if (events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_VCO_CAL) {
        ATA_setEventPin_ASM();
    }
    else {
    }
    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*------------------------- Temperature Measurement -------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_tempmeasStateInitSSM_C</b>

    \return none

    \image html ATA_tempmeasStateInitSSM_C.png
    \image rtf ATA_tempmeasStateInitSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_tempmeasStateInitSSM_C(void)
{
    ATA_sysTempMeasSsmEnable_C();
    flowCtrl.index++;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_sysTempMeasSsmEnable_C</b>
    setup the RF-TX sequencer state machine and triggers its start.

    \return none

    \image html ATA_sysTempMeasSsmEnable_C.png
    \image rtf ATA_sysTempMeasSsmEnable_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_sysTempMeasSsmEnable_C(void)
{
    trxConf.systemModeConfig |= OPM_RX | BM_SYS_MODE_CONFIG_VCO_TUNING;

    trxConf.tuneCheckConfig  |= BM_TUNE_CHECK_CONFIG_TEMP_MEASUREMENT;

    //ATA_startInitTxRxSSM_C();
    ATA_startInitTempMeasSSM_C();
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_startInitTempMeasSSM_C</b>
    starts the temperature measurement sequencer state machine the funcPtr array.

    \return none

    \image html ATA_startInitTempMeasSSM_C.png
    \image rtf ATA_startInitTempMeasSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_startInitTempMeasSSM_C(void)
{
    FSCR  = 0x00U;

    // AVCC needs up to 150us/100us (depends on 3V/5V) to ramp-up after setting AVEN.
    // While executing routines ATA_currentServiceInit_C() and ATA_checkModulationType_ASM() AVCC ramps up.
    SUPCR |= BM_AVEN;

    // takes ~10us(no copy actions) - ~160us(service and channel SRAM copy actions), FRC based (not FRC worstcase)
    ATA_currentServiceInit_C(trxConf.serviceChannelConfig);

    trxStatus = 0U;

    trxStatus  =  currentService.service.rxSetPathA[1] & BM_TRX_STATUS_RX_ASK_FSK_MODULATION_PATHA;
    trxStatus |= (uint8_t)((currentService.service.rxSetPathB[1] & BM_TRX_STATUS_RX_ASK_FSK_MODULATION_PATHB) << 1U);

    ATA_wait4avcc_C();

    ATA_doFeInit4TxRxSSM_C();

    ATA_startInitRxSSM_C();

    PRR2 &= (uint8_t)~BM_PRSSM;
    PRR2 |= BM_PRRS;

    FFREQ1H = 0x02U;
    FFREQ1M = 0x5FU;
    FFREQ1L = 0x04U;

    CHDN = 0x14U;
    CHCR = 0x00U;

    FECR = 0x03U;
    
    /* -SIX-2602-- */
    /* store original currentService.service.FEVCO setting */
    uint8_t tmpFevco = currentService.service.FEVCO;
    
    /* apply FEVCO setting */
    currentService.service.FEVCO = 0x10U;
    FEVCO = ATA_doFevcoRegisterCalculation_C();

    /* restore original currentService.service.FEVCO setting */
    currentService.service.FEVCO = tmpFevco;    
    /* -SIX-2602-- */
    
    FEMS = 0x085U;

    // setup Sequencer State Machine
    ATA_configureTempMeasSSM_C();
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_configureTempMeasSSM_C</b>
    does the configuration of temperature measurement sequencer state machine.

    \return none

    \image html ATA_configureTempMeasSSM_C.png
    \image rtf ATA_configureTempMeasSSM_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_configureTempMeasSSM_C(void)
{
    /* SSMCR - SSM Run Register*/
    SSMRR = BM_SSMST;   /* set SSM in stop state to reset SSM*/

    SSMSR |= BM_SSMERR;

    /* SSMCR - SSM Control Register*/
    SSMCR = BM_SSMTM;

    /* SSMRCR - SSM Control Register*/
    SSMRCR = 0U;

    // setup HW state machine configuration always incl. VCO TUNING
    MSMCR1 = SSM_PLL_EN_STATE   | (uint8_t)(SSM_VCO_TUNING_STATE << 4U);
    MSMCR2 = SSM_PLL_LOCK_STATE | (uint8_t)(SSM_RX_DSP_EN_STATE << 4U);
    MSMCR3 = SSM_END_STATE      | (uint8_t)(SSM_END_STATE << 4U);
    MSMCR4 = SSM_END_STATE      | (uint8_t)(SSM_END_STATE << 4U);

    //flowCtrl.msmstate = 10U;

    //SSMFBR = currentService.service.CHSTARTFILTER;
    //SSMFBR = tmpAryApp[CHSTARTFILTER];
    SSMFBR = 0x00U;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_tempmeasStateStartSSM_C</b>
    this state starts the sequencer state machine and switch to next state.

    \return none

    \image html ATA_tempmeasStateStartSSM_C.png
    \image rtf ATA_tempmeasStateStartSSM_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_tempmeasStateStartSSM_C(void)
{
    flowCtrl.lastStartedSsm = FLOW_CTRL_LAST_STARTED_SSM_RX;
    ATA_systemStartSSM_C( DEBUG_ERROR_CODE_TEMPMEAS_STATESTARTSSM_TIMER_LOCKED );
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_tempmeasStateWait4SSMrdy_C</b>
    this state waits for the end of the sequencer state machine and switch
    to next state.

    \return none

    \image html ATA_tempmeasStateWait4SSMrdy_C.png
    \image rtf ATA_tempmeasStateWait4SSMrdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_tempmeasStateWait4SSMrdy_C(void)
{

    ATA_systemWait4SSMrdy_C( DEBUG_ERROR_CODE_TEMPMEAS_STATEWAIT4SSMRDY_TIMEOUT,
                             TEMPMEAS_FLOW_STATE_SHUTDOWN );
}


/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_tempmeasStateWait4Temperature_C</b>
    this state reads the temperature value and ....
    and switch to next state.

    \return none

    \image html ATA_tempmeasStateWait4Temperature_C.png
    \image rtf ATA_tempmeasStateWait4Temperature_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_tempmeasStateWait4Temperature_C(void)
{
    uint8_t TempCal1 = 0U;
    uint8_t TempCal2 = 0U;
    uint8_t TempCal3 = 0U;
    uint8_t TempCal4 = 0U;

    uint32_t TempValue = 0U;

    // read the temperature
    // read TEMPH register 1st, to freeze TEMPL register in shadow register
    calib.sramTEMPH = TEMPH;
    calib.sramTEMPL = TEMPL;

    // Load values from EEPROM
    TempCal1 = ATA_eepRDbyte_ASM( &eepFacLock.confTEMPCAL1 );
    TempCal2 = ATA_eepRDbyte_ASM( &eepFacLock.confTEMPCAL2 );
    TempCal3 = ATA_eepRDbyte_ASM( &eepFacLock.confTEMPCAL3 );
    TempCal4 = ATA_eepRDbyte_ASM( &eepFacLock.confTEMPCAL4 );

    // calculate
    TempValue = (( (uint32_t)calib.sramTEMPH << 8U ) | (uint32_t)calib.sramTEMPL ) - (( (uint32_t)TempCal3 << 8U ) | (uint32_t)TempCal4 );
/* --SIX-1155-- */
    // calib.tempMeas = (uint8_t)(( TempValue * (( (uint32_t)TempCal1 << 8U) | (uint32_t)TempCal2 )) >> 15U );
    TempValue  = TempValue * (( (uint32_t)TempCal1 << 8U) | (uint32_t)TempCal2 );
    TempValue += (uint32_t)0x00004000;
    calib.tempMeas  = (uint8_t)(TempValue >> 15U);
    // --GW-SIX-- Runden der Temperatur durch addition von 0x0000_4000 bevor geschoben wird
/* --SIX-1155-- */
    flowCtrl.index++;
}


/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_tempmeasStateSetCmdRdy_C</b>
    this state set CMD_RDY flag to indicate temperature measurement is
    complete and switch to next state.

    \return none

    \image html ATA_tempmeasStateSetCmdRdy_C.png
    \image rtf ATA_tempmeasStateSetCmdRdy_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_tempmeasStateSetCmdRdy_C(void)
{
    events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
    if( events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_TEMP_MEAS )
    {
        ATA_setEventPin_ASM();
    }
    else
    {}

    trxConf.tuneCheckConfig &= (uint8_t)~BM_TUNE_CHECK_CONFIG_TEMP_MEASUREMENT;
    flowCtrl.index++;
}
