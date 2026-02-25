/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/calib/src/calib.h $
  $LastChangedRevision: 648642 $
  $LastChangedDate: 2021-10-26 15:28:50 +0200 (Di, 26 Okt 2021) $
  $LastChangedBy: swagner $
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

/** \file calib.h
 */

#ifndef CALIB_H
#define CALIB_H

#ifdef __IAR_SYSTEMS_ICC__
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  TYPE DEFINITIONS                                                         */
/*===========================================================================*/

/** \brief <b>pfCalibFrc</b>
    is a function pointer type definition used for patch FRC calibration
*/
typedef void (*pfCalibFrc)(void);
/*----------------------------------------------------------------------------- */
/** \brief <b>sCalibResults</b>
    holds the calibration, tune and temp measurement results
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>sramFEAT</b>
        contains the Front-End Amplifier Bias and Antenna Tuning results
        \li Bit 7..4: rfu
        \li Bit 3..0: ANTN[3..0]
    */
    uint8_t sramFEAT;

    /** \brief <b>sramTEMPH</b>
        contains the temperature high byte
    */
    uint8_t sramTEMPH;

    /** \brief <b>sramTEMPL</b>
        contains the temperature low byte
    */
    uint8_t sramTEMPL;

    /** \brief <b>tempMeas</b>
        contains the 8 bit temperature meas. result in a range of 0 ... 175
    */
    uint8_t tempMeas;

    /** \brief <b>srcRes</b>
        contains the result of the meas. f_src oscillator
    */
    uint8_t srcRes;

    /** \brief <b>srcCorVal</b>
        correction value for Timer1 to match configured polling cycle
    */
    uint8_t srcCorVal;

    /** \brief <b>vcoRes</b>
        contains the result of the meas. f_vco frequency
    */
    uint8_t vcoRes;
}sCalibResults;

/*----------------------------------------------------------------------------- */
/** \brief <b>sFrcCalib</b>
    contains the results of the FRC calibration measurement results
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>highByte</b>
        8q8 representation highByte.lowByte
    */
    uint8_t highByte;
    /** \brief <b>lowByte</b>
        8q8 representation highByte.lowByte
    */
    uint8_t lowByte;
    /** \brief <b>compValData</b>
        stores TIMER3 ICAP result during the tuning process
    */
    uint8_t compValData;
}sFrcCalib;

/*----------------------------------------------------------------------------- */
/** \brief <b>sFRCcalPtr</b>
    contains a function pointer to the desired routine for calibrating the FRC.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>frcCalFunc</b>
        is a function pointer for patching the FRC calibration
    */
    pfCalibFrc frcCalFunc;
}sFRCcalPtr;

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern sCalibResults calib;

extern sFrcCalib frcResults;

extern sFRCcalPtr frcCalPtr;

extern UINT8FUNC ATA_checkModulationType4TX_ASM(void);

extern VOIDFUNC ATA_rfCalibration_C(void);

extern VOIDFUNC ATA_anttuneStateInitSSM_C(void);

extern VOIDFUNC ATA_sysAntTuneSsmEnable_C(void);

extern VOIDFUNC ATA_anttuneStateStartSSM_C(void);

extern VOIDFUNC ATA_anttuneStateWait4SSMrdy_C(void);

extern VOIDFUNC ATA_anttuneStateSetCmdRdy_C(void);

extern VOIDFUNC ATA_vcocalStateInitSSM_C(void);

extern VOIDFUNC ATA_sysVcoCalSsmEnable_C(void);

extern VOIDFUNC ATA_vcocalStateStartSSM_C(void);

extern VOIDFUNC ATA_vcocalStateWait4SSMrdy_C(void);

extern VOIDFUNC ATA_vcocalStateSetCmdRdy_C(void);

extern VOIDFUNC ATA_tempmeasStateInitSSM_C(void);

extern VOIDFUNC ATA_sysTempMeasSsmEnable_C(void);

extern VOIDFUNC ATA_startInitTempMeasSSM_C(void);

extern VOIDFUNC ATA_configureTempMeasSSM_C(void);

extern VOIDFUNC ATA_tempmeasStateStartSSM_C(void);

extern VOIDFUNC ATA_tempmeasStateWait4SSMrdy_C(void);

extern VOIDFUNC ATA_tempmeasStateWait4Temperature_C(void);

extern VOIDFUNC ATA_tempmeasStateSetCmdRdy_C(void);

extern VOIDFUNC ATA_frcCalib_ASM(void);

extern VOIDFUNC ATA_getT2T3_ASM(void);

extern VOIDFUNC ATA_srcCalib_ASM(void);

extern INT32FUNC ATA_shiftRightInt32_ASM(int32_t word, uint8_t shift);

extern INT16FUNC ATA_shiftRightInt16_ASM(int16_t word, uint8_t shift);

#elif defined __IAR_SYSTEMS_ASM__
/*startSimExtraction*/
/* sCalibResults */
SRAM_FEAT          EQU 0x00
SRAM_TEMPH         EQU SRAM_FEAT + 1
SRAM_TEMPL         EQU SRAM_TEMPH + 1
SRAM_TEMP_MEAS     EQU SRAM_TEMPL + 1
SRCRESULT          EQU SRAM_TEMP_MEAS + 1
SRCCORVAL          EQU SRCRESULT + 1
VCORESULT          EQU SRCCORVAL + 1

/* sFrcCalib */
HIGHBYTE           EQU 0x00
LOWBYTE            EQU HIGHBYTE + 1
COMPVALDATA        EQU LOWBYTE + 1

/*stopSimExtraction*/
#endif

#endif /* CALIB_H */