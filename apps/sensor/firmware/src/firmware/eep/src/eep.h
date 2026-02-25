/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/eep/src/eep.h $
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

/** \file eep.h Include relevant EEPROM structures.
*/

#ifndef EEP_H
#define EEP_H

#if defined(__IAR_SYSTEMS_ICC__)

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "../../globals/src/globals.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/** \brief <b>EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_LOWBATT_DISABLE</b>
    is used at bit definition for sEEPromTrxConfig.sysConfig variable
 */
#define EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_LOWBATT_DISABLE    BIT_0

/** \brief <b>EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_AVCCLOW_DISABLE</b>
    is used at bit definition for sEEPromTrxConfig.sysConfig variable
 */
#define EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_AVCCLOW_DISABLE    BIT_1

/** \brief <b>EEP_TRXCONF_SYSCONFIG_DFIFO_OFL_UFL_RX_DISABLE</b>
    is used at bit definition for sEEPromTrxConfig.sysConfig variable
 */
#define EEP_TRXCONF_SYSCONFIG_DFIFO_OFL_UFL_RX_DISABLE      BIT_2

/** \brief <b>EEP_TRXCONF_SYSCONFIG_SFIFO_OFL_UFL_RX_DISABLE</b>
    is used at bit definition for sEEPromTrxConfig.sysConfig variable
 */
#define EEP_TRXCONF_SYSCONFIG_SFIFO_OFL_UFL_RX_DISABLE      BIT_3

/** \brief <b>EEP_TRXCONF_SYSCONFIG_VS5V</b>
    is used at bit definition for sEEPromTrxConfig.sysConfig variable
 */
#define EEP_TRXCONF_SYSCONFIG_VS5V                          BIT_4

/** \brief <b>EEP_TRXCONF_SYSCONFIG_VS22V</b>
    is used at bit definition for sEEPromTrxConfig.sysConfig variable
 */
#define EEP_TRXCONF_SYSCONFIG_VS22V                         BIT_5

/** \brief <b>BM_EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_LOWBATT_DISABLE</b>
    is used at bitmask definition for sEEPromTrxConfig.sysConfig variable
 */
#define BM_EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_LOWBATT_DISABLE BIT_MASK_0

/** \brief <b>BM_EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_AVCCLOW_DISABLE</b>
    is used at bitmask definition for sEEPromTrxConfig.sysConfig variable
 */
#define BM_EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_AVCCLOW_DISABLE BIT_MASK_1

/** \brief <b>BM_EEP_TRXCONF_SYSCONFIG_DFIFO_OFL_UFL_RX_DISABLE</b>
    is used at bitmask definition for sEEPromTrxConfig.sysConfig variable
 */
#define BM_EEP_TRXCONF_SYSCONFIG_DFIFO_OFL_UFL_RX_DISABLE   BIT_MASK_2

/** \brief <b>BM_EEP_TRXCONF_SYSCONFIG_SFIFO_OFL_UFL_RX_DISABLE</b>
    is used at bitmask definition for sEEPromTrxConfig.sysConfig variable
 */
#define BM_EEP_TRXCONF_SYSCONFIG_SFIFO_OFL_UFL_RX_DISABLE   BIT_MASK_3

/** \brief <b>BM_EEP_TRXCONF_SYSCONFIG_VS5V</b>
    is used at bitmask definition for sEEPromTrxConfig.sysConfig variable
 */
#define BM_EEP_TRXCONF_SYSCONFIG_VS5V                       BIT_MASK_4

/** \brief <b>BM_EEP_TRXCONF_SYSCONFIG_VS22V</b>
    is used at bitmask definition for sEEPromTrxConfig.sysConfig variable
 */
#define BM_EEP_TRXCONF_SYSCONFIG_VS22V                      BIT_MASK_5

/** \brief <b>EEP_CONFIGVALID_CONFVAL_NVAL0</b>
    is used at bit definition for sEEPromConfigValid.confVal variable
 */
#define EEP_CONFIGVALID_CONFVAL_NVAL0                       BIT_0

/** \brief <b>EEP_CONFIGVALID_CONFVAL_NVAL1</b>
    is used at bit definition for sEEPromConfigValid.confVal variable
 */
#define EEP_CONFIGVALID_CONFVAL_NVAL1                       BIT_1

/** \brief <b>EEP_CONFIGVALID_CONFVAL_PURERXMODE</b>
    is used at bit definition for sEEPromConfigValid.confVal variable
 */
#define EEP_CONFIGVALID_CONFVAL_PURERXMODE                  BIT_2

/** \brief <b>EEP_CONFIGVALID_CONFVAL_ENSPIPURERXMODE</b>
    is used at bit definition for sEEPromConfigValid.confVal variable
 */
#define EEP_CONFIGVALID_CONFVAL_ENSPIPURERXMODE             BIT_3


/** \brief <b>BM_EEP_CONFIGVALID_CONFVAL_NVAL0</b>
    is used at bitmask definition for sEEPromConfigValid.confVal variable
 */
#define BM_EEP_CONFIGVALID_CONFVAL_NVAL0                    BIT_MASK_0

/** \brief <b>BM_EEP_CONFIGVALID_CONFVAL_NVAL1</b>
    is used at bitmask definition for sEEPromConfigValid.confVal variable
 */
#define BM_EEP_CONFIGVALID_CONFVAL_NVAL1                    BIT_MASK_1

/** \brief <b>BM_EEP_CONFIGVALID_CONFVAL_NVAL</b>
    is used at bitmask definition for sEEPromConfigValid.confVal variable
 */
#define BM_EEP_CONFIGVALID_CONFVAL_NVAL                    ( BIT_MASK_1 | BIT_MASK_0 )

/** \brief <b>BM_EEP_CONFIGVALID_CONFVAL_PURERXMODE</b>
    is used at bitmask definition for sEEPromConfigValid.confVal variable
 */
#define BM_EEP_CONFIGVALID_CONFVAL_PURERXMODE               BIT_MASK_2

/** \brief <b>BM_EEP_CONFIGVALID_CONFVAL_ENSPIPURERXMODE</b>
    is used at bitmask definition for sEEPromConfigValid.confVal variable
 */
#define BM_EEP_CONFIGVALID_CONFVAL_ENSPIPURERXMODE          BIT_MASK_3

/*===========================================================================*/
/*  TYPE DEFINITIONS                                                         */
/*===========================================================================*/
/** \brief <b>initFuncPtr</b>
    is used for function pointer definition of initialization function.
*/
typedef void (*initFuncPtr)(void);/* used to create flexible adjustable ISRs*/

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromFactoryLock</b>
    holds the settings of the factory locked EEPROM region.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>confFEBIA</b>
        is the Front-End bias Amplifier Register.
        \li Bit 7..4: rfu
        \li Bit 3..0: BIAM[3..0]
     */
    uint8_t confFEBIA;
    /** \brief <b>confFEBT</b>
        is the Front-End RC Tuning Register.
        \li Bit 3..2: RTN2[1..0]
        \li Bit 1..0: CTN2[1..0]
     */
    uint8_t confFEBT;
    /** \brief <b>confFELNA</b>
        is the Front-End LNA Bias Register.
        \li Bit 7..4: LBL[3..0]
        \li Bit 3..0: LBH[3..0]
     */
    uint8_t confFELNA;
    /** \brief <b>confFELNA2</b>
        is the Front-End LNA Bias Register 2 used for 315 MHz.
        \li Bit 7..4: LBLX_315[3..0]
     */
    uint8_t confFELNA2;
    /** \brief <b>confFETN4</b>
        is the Front-End RC Tuning 4bit Register.
        \li Bit 7..4: RTN4[3..0]
        \li Bit 3..0: CTN4[3..0]
     */
    uint8_t confFETN4;
    /** \brief <b>confFEVCOoffset</b>
        is the value calculated during production testing.
        A value examined during test, B value is coming from EEP settings
        final value is 7+A+B.
        A: 2's complement representation 8 bit!
        \li Bit 7..4:    VCOB3 .. VCOB0
        \li Bit 3..0:    CPCC3 .. CPCC0
     */
    uint8_t confFEVCOoffset;
    /** \brief <b>confTEMPCAL1</b>
        is the 1/Gain of Temperature Sensor High Byte.
     */
    uint8_t confTEMPCAL1;
    /** \brief confTEMPCAL2
        is the 1/Gain of Temperature Sensor Low Byte.
     */
    uint8_t confTEMPCAL2;
    /** \brief <b>confTEMPCAL3</b>
        is the Temperature High Byte at -50 Degree Celsius.
     */
    uint8_t confTEMPCAL3;
    /** \brief confTEMPCAL4
        is the Temperature Low Byte at -50 Degree Celsius.
     */
    uint8_t confTEMPCAL4;
}sEEPromFactoryLock;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromConfigValid</b>
    holds the flags to indicate the status of the EEProm settings.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>confInitFlags</b>
        enables and disables available Init Functions.
        \li Bit 7:       AntTune @ system startUp
        \li Bit 6:       TempMeas @ system startUp
        \li Bit 5:       SRC @ system startUp
        \li Bit 4:       FRC @ system startUp
        \li Bit 3:       rfu
        \li Bit 2:       rfu
        \li Bit 1:       rfu
        \li Bit 0:       rfu
     */
    uint8_t confInitFlags;
    /** \brief <b>confVal</b>
        is the configuration valid Register indicating whether the
        EEPROM settings are valid or not.
        \li Bit 7..4:    rfu
        \li Bit 3:       Enable SPI in pureRXMode (1:enable/0:disable)
        \li Bit 2:       pureRXMode enable/disable (1:enable/0:disable)
        \li Bit 1..0:    Valid => 10
     */
    uint8_t confVal;
    /** \brief <b>confVMCSR</b>
        is a copy of VMCSR register used for Voltage Monitor configuration.
     */
    uint8_t confVMCSR;
    /** \brief <b>FUNCPTR[2]</b>
        points to a routine executed while the system initialization
        is in progress (MSB first)
     */
    uint8_t funcPtr[2];
}sEEPromConfigValid;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromIOConfig</b>
    holds the configuration of the system I/O.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>confDDRB</b>
        is the PortB Data Direction Register.
     */
    uint8_t confDDRB;
    /** \brief <b>confDDRC</b>
        is the PortC Data Direction Register.
     */
    uint8_t confDDRC;
    /** \brief <b>confMCUCR</b>
        contains MCU Control Register information.
        \li Bit 7: PB7HS
        \li Bit 6: PB7LS
        \li Bit 5: PB4HS
        \li Bit 4: PUD
        \li Bit 3: ENPS
        \li Bit 2: rfu
        \li Bit 1: IVSEL
        \li Bit 0: IVCE
     */
    uint8_t confMCUCR;
    /** \brief <b>confPCICR</b>
        is the Pin Change Interrupt Control Register.
        \li Bit 1: PCIE1 Enable Pin Change Interrupt Port C
        \li Bit 0: PCIE0 Enable Pin Change Interrupt Port B
     */
    uint8_t confPCICR;
    /** \brief <b>confPCMSK0</b>
        is the Pin Change Mask Register 0.
     */
    uint8_t confPCMSK0;
    /** \brief <b>confPCMSK1</b>
        is the Pin Change Mask Register 1.
     */
    uint8_t confPCMSK1;
    /** \brief <b>confPORTB</b>
        is the PortB Data Register.
     */
    uint8_t confPORTB;
    /** \brief <b>confPORTC</b>
        is the PortC Data Register.
     */
    uint8_t confPORTC;
}sEEPromIOConfig;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromTrxConfig</b>
    holds the settings for the TRX configuration
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>clkConfig</b>
        contains the clock configuration
        \li Bit 7: rfu
        \li Bit 6: rfu
        \li Bit 5: SRCAO: SRC Always On
        \li Bit 4: FRCAO: FRC Always On
        \li Bit 3: rfu
        \li Bit 2: CLKOEN
            - 1: Enable clock output driver to CLK_OUT
            - 0: Disable clock output driver to CLK_OUT
        \li Bit 1..0: CLKOS[1..0] Clock output select
            - 0: SRC Clock is selected
            - 1: FRC Clock is selected
            - 2: ADC Divider Clock is selected
            - 3: XTO Clock is selected
     */
    uint8_t clkConfig;

    /** \brief <b>spiConfig</b>
        contains the SPI configuration
        \li Bit 7:    DORD: Data Order
        \li Bit 6:    CPOL: Clock Polarity
        \li Bit 5:    CPHA: Clock Phase
        \li Bit 4:    rfu
        \li Bit 3:    rfu
        \li Bit 2:    rfu
        \li Bit 1:    rfu
        \li Bit 0:    rfu
     */
    uint8_t spiConfig;

    /** \brief <b>sysConfig</b>
        contains supply voltage information and interrupt setting configuration
        \li Bit 7:    rfu
        \li Bit 6:    rfu
        \li Bit 5:    VS22V
        \li Bit 4:    VS5V: Power Supply 5V/3V
        \li Bit 3:    SFIFO_OFL_UFL_RX_DISABLE 0:enabled/1:disabled
        \li Bit 2:    DFIFO_OFL_UFL_RX_DISABLE 0:enabled/1:disabled
        \li Bit 1:    AVCCLOW_DISABLE 0:enabled/1:disabled
        \li Bit 0:    LOWBATT_DISABLE 0:enabled/1:disabled
     */
    uint8_t sysConfig;
    /** \brief <b>clkOutDiv</b>
        contains the output clock divider configuration
        \li Bit 7..0: CLKOD[7..0] Clock output divider setting<br>
            Clock divider is defined in the range of 0 .. 255.<br>
            Note: minimal divider for \#CLKOS=4, otherwise 0
            CLK_OUT = \#CLKOS / (2* \#CLKOD)
     */
    uint8_t clkOutDiv;
    /** \brief <b>sysStartConf</b>
        contains the system mode configuration at start-up.
        \li Bit 7:      RF_CAL
        \li Bit 6:      ANT_TUNE
        \li Bit 5:      VCO_TUNE
        \li Bit 4:      Idle mode selector 0: RC, 1:XTO
        \li Bit 3:      rfu
        \li Bit 2:      TMDEN: Transparent Mode Data Enable
        \li Bit 1..0:   OPM[0..1]: Operation Mode
            - 0: IDLEMode (SPI or LIN)
            - 1: TXMode
            - 2: RXMode
            - 3: PollingMode
     */
    uint8_t sysStartConf;
    /** \brief <b>sysStartSvcChConfig</b>
        contains the service/channel configuration at start-up.
        \li Bit 7: enaPathB
        \li Bit 6: enaPathA
        \li Bits 5..4: ch[1..0]
        \li Bit 3: rfu
        \li Bits 2..0: ser[2..0]
     */
    svcChConfig_t sysStartSvcChConfig;
    /** \brief <b>svcInitConf</b>
        contains the settings for service initialization.
        \li Bit 7:    Service 4 (SRAM) update flag: 0:no init / 1: init
        \li Bit 6..5: Service identifier 0..2 (EEPROM)
        \li Bit 4:    1 - Service identifier 4(SRAM)
        \li Bit 3:    Service 3 (SRAM) update flag: 0:no init / 1: init
        \li Bit 2..1: Service identifier 0..2 (EEPROM)
        \li Bit 0:    0 - Service identifier 3 (SRAM)
     */
    uint8_t    svcInitConf;
}sEEPromTrxConfig;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromTrxCalib</b>
    holds the settings for the TRX checks & calibrations
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>calConf1</b>
        is the Calibration Configuration Byte 1.
     */
    tuneCheckConfig_t calConf1;
    /** \brief <b>calConf2</b>
        is the Calibration Configuration Byte 2
        \li Bit 7..0: SRC[7..0] defines SRCCAL_VAR used for calibration of the polling cycle.
     */
    uint8_t calConf2;
    /** \brief <b>selfChk</b>
        contains the selfCheck configuration.
        Byte*16 ==> every X cycle a self chk is performed.
        \li Bit 7..0: SC[7..0] Defines how often this Self Check will be executed
            - 0:   No Self Check
            - 1:   Self Check every 1*16 Polling Cycle
            - ...
            - 255: Self Check every 255*16 Polling Cycle
     */
    uint8_t selfChk;
    /** \brief <b>tempCal[23]</b>
        is a 23 Byte table for XTAL temp deviation
     */
    int8_t tempCal[23];
}sEEPromTrxCalib;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromIDctrl</b>
    contains the ID Scan configuration of all 18 IDs
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>idEna</b>
        contains the number of enabled IDs (0=all disabled, 1..18 check n IDs).
        \li Bit 7..5:  rfu
        \li Bit 4..0:  ID[4..0]
     */
    uint8_t idEna;

    /** \brief <b>id</b>
        is a array with 18 ID configurations.
     */
    sId     id[18];
}sEEPromIDctrl;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromWDTimer</b>
    holds the settings for the watchdog
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>confT0CR</b>
        contains the Timer0 Control configuration.
        \li Bit 7..5:   rfu
        \li Bit 4:      TOPR:
        \li Bit 3:      TOIE:
        \li Bit [2..0]: TOPS[2..0]:
     */
    uint8_t confT0CR;
    /** \brief <b>confT0IFR</b>
        contains the T0IFR settings.
        \li Bit 7..1:   rfu
        \li Bit 0:      T0F
     */
    uint8_t confT0IFR;
    /** \brief <b>confWDTCR</b>
        contains the Watchdog Timer0 configuration.
        \li Bit 7..5:   rfu
        \li Bit 4:      WDCE:
        \li Bit 3:      WDE:
        \li Bit [2..0]: WDPS[2..0]:
     */
    uint8_t confWDTCR;
}sEEPromWDTimer;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromEventConfig</b>
    holds the settings/maskbits of the system Events.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>pinEventConf</b>
        pin event configuration.
     */
    pinEventConfig_t pinEventConf;
    /** \brief <b>sysEventConf</b>
        system event configuration.
     */
    sysEventConfig_t sysEventConf;

    /** \brief <b>cmdRdyConf</b>
        holds the CMD_RDY event configuration.
        \li Bit7: enable CMD_RDY event for Antenna tuning
        \li Bit6: enable CMD_RDY event for Temperature Measurement
        \li Bit5: enable CMD_RDY event for SRC calibration
        \li Bit4: enable CMD_RDY event for FRC calibration
        \li Bit3: enable CMD_RDY event for VCO tuning
        \li Bit2: enable CMD_RDY event for RF calibration
        \li Bit1: enable CMD_RDY event for Self check
        \li Bit0: enable CMD_RDY event for TX
     */
    uint8_t    cmdRdyConf;
}sEEPromEventConfig;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromSleepMode</b>
    holds the configuration for sleep mode behaviour in Rx Polling
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>sleepModeConf</b>
        contains the sleep mode configuration
        \li Bit 7: firmware sleep mode enable flag
        \li Bit 6: rfu
        \li Bit 5: rfu
        \li Bit 4: rfu
        \li Bit 3..1: sleep mode
            - 0: idle
            - 1: extended power-save
            - 2: power-save
            - 3: power-down
        \li Bit 0: rfu
     */
    uint8_t sleepModeConf;
}sEEPromSleepMode;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromFRCcalib</b>
    holds the configuration for FRC calibration
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>frcCalibGate</b>
        holds the duration of the meas. gate (XTO depending).
     */
    uint8_t frcCalibGate;
}sEEPromFRCcalib;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromPollLoopConf</b>
    contains the Timer configuration for Polling Cycle and the polling
    configuration itself.
 */
/*----------------------------------------------------------------------------- */
typedef struct
{
    /** \brief <b>confT1COR</b>
        is the Timer 1 Compare Register
     */
    uint8_t confT1COR;
    /** \brief <b>confT1MR</b>
        is the Timer 1 Mode Register
        \li Bit 7..6:  rfu
        \li Bit 5..2:  T1PS[3..0]
        \li Bit 1..0:  T1CS[1..0]
     */
    uint8_t confT1MR;
    /** \brief <b>pollLoopConf</b>
        contains the polling svc/ch configuration setting
     */
    sPollingChannelConfig pollLoopConf[NUM_POLL_CHAN_CONFIG];
}  sEEPromPollLoopConf;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromDebug</b>
    contains the register setting for debbuging support.
 */
/*----------------------------------------------------------------------------- */
typedef struct
{
    /** \brief <b>DBGSW</b>
        contains the Debugging Support Switch information
        \li Bit 7:    DBGSE - Debugging Support Switch Enable
        \li Bit 6:    CPBF - CPU Busy Flag
        \li Bit 5..4: CPBFOS[1..0] - CPU Busy Flag Output Select
            - 0: No output port selected
            - 1: PB0
            - 2: PB4
            - 3: PC1
        \li Bit 3..0: DBGGS[3..0] - Debugging Support Group Select
        <table border="1">
            <tr><th>DBGGS[3:0]</th><th>PC1</th><th>PC3</th><th>PC4</th><th>PC5</th><th>PB0</th><th>PB4</th></tr>

            <tr><td> 0</td><td>     WCOB</td><td>     WCOA</td><td>     SOTB</td><td>     SOTA</td><td>     EOTB</td><td>     EOTA</td></tr>
            <tr><td> 1</td><td>     WCOB</td><td>     SOTB</td><td>     EOTB</td><td>    NBITB</td><td>        0</td><td>        0</td></tr>
            <tr><td> 2</td><td>     WCOA</td><td>     SOTA</td><td>     EOTA</td><td>    NBITA</td><td>        0</td><td>        0</td></tr>
            <tr><td> 3</td><td>        0</td><td>   SSMERR</td><td>  SSMESM3</td><td>  SSMESM2</td><td>  SSMESM1</td><td>  SSMESM0</td></tr>
            <tr><td> 4</td><td>    SFIOA</td><td>    WUPOA</td><td>    MANOA</td><td>    SYTOA</td><td>    AMPOA</td><td>    CAROA</td></tr>
            <tr><td> 5</td><td>    SFIOB</td><td>    WUPOB</td><td>    MANOB</td><td>    SYTOB</td><td>    AMPOB</td><td>    CAROB</td></tr>
            <tr><td> 6</td><td>    MANFB</td><td>    SYTFB</td><td>    AMPFB</td><td>    CARFB</td><td>        0</td><td>        0</td></tr>
            <tr><td> 7</td><td>    MANFA</td><td>    SYTFA</td><td>    AMPFA</td><td>    CARFA</td><td>        0</td><td>        0</td></tr>
            <tr><td> 8</td><td>GPIOR0[5]</td><td>GPIOR0[4]</td><td>GPIOR0[3]</td><td>GPIOR0[2]</td><td>GPIOR0[1]</td><td>GPIOR0[0]</td></tr>
            <tr><td> 9</td><td>GPIOR3[5]</td><td>GPIOR3[4]</td><td>GPIOR3[3]</td><td>GPIOR3[2]</td><td>GPIOR3[1]</td><td>GPIOR3[0]</td></tr>
            <tr><td>10</td><td>GPIOR4[5]</td><td>GPIOR4[4]</td><td>GPIOR4[3]</td><td>GPIOR4[2]</td><td>GPIOR4[1]</td><td>GPIOR4[0]</td></tr>
            <tr><td>11</td><td>GPIOR5[5]</td><td>GPIOR5[4]</td><td>GPIOR5[3]</td><td>GPIOR5[2]</td><td>GPIOR5[1]</td><td>GPIOR5[0]</td></tr>
            <tr><td>12</td><td>GPIOR6[5]</td><td>GPIOR6[4]</td><td>GPIOR6[3]</td><td>GPIOR6[2]</td><td>GPIOR6[1]</td><td>GPIOR6[0]</td></tr>
            <tr><td>13</td><td>        0</td><td>   SSMST4</td><td>   SSMST4</td><td>   SSMST2</td><td>   SSMST1</td><td>   SSMST0</td></tr>
            <tr><td>14</td><td>  SSMSTA5</td><td>  SSMSTA4</td><td>  SSMSTA3</td><td>  SSMSTA2</td><td>  SSMSTA1</td><td>  SSMSTA0</td></tr>
            <tr><td>15</td><td>  SSMSTB5</td><td>  SSMSTB5</td><td>  SSMSTB3</td><td>  SSMSTB2</td><td>  SSMSTB1</td><td>  SSMSTB0</td></tr>
        </table>
     */
    uint8_t DBGSW;
}  sEEPromDebug;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromDebouncing</b>
    contains the register setting for debouncing.
 */
/*----------------------------------------------------------------------------- */
typedef struct
{
    /** \brief <b>DBCR</b>
        contains DeBounce Control Register setting
        \li Bit 7: rfu
        \li Bit 6: rfu
        \li Bit 5: rfu
        \li Bit 4: rfu
        \li Bit 3: rfu
        \li Bit 2: DBTMS - DeBounce Timer Mask Select
        \li Bit 1: DBCS - DeBounce Clock Select
        \li Bit 0: DBMD - DeBounce MoDe
     */
    uint8_t DBCR;

    /** \brief <b>DBTC</b>
        contains the DeBounce Timer Compare Register setting
        \li Bit [7..0]:   DBTCn - DeBounce Timer Compare
     */
    uint8_t DBTC;

    /** \brief <b>DBENB</b>
        contains the DeBounce Enable PortB Register setting
        \li Bit [7..0]:    DBENBn - DeBounce ENable
     */
    uint8_t DBENB;

    /** \brief <b>DBENC</b>
        contains the DeBounce Enable PortC Register setting
        \li Bit [7..0]:   DBENCn - DeBounce ENable
     */
    uint8_t DBENC;
}sEEPromDebouncing;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromRssi</b>
    contains the register setting for RSSI configuration.
 */
/*----------------------------------------------------------------------------- */
typedef struct
{
    /** \brief <b>RSIFG</b>
        contains RSSI High IF Amplifier Gain register setting
     */
    uint8_t RSIFG;
    /** \brief <b>RSLDV</b>
        contains the RSSI Low Band Damping Value register setting
     */
    uint8_t RSLDV;
    /** \brief <b>RSHDV</b>
        contains the RSSI High Band Damping Value register setting
     */
    uint8_t RSHDV;
}sEEPromRssi;


/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromVsPa</b>
    contains the register setting for VSPA = 2V2.
 */
/*----------------------------------------------------------------------------- */
typedef struct {
    /** \brief <b>SUPCA1</b>
        contaisn SUPCA1 register setting for VSPA = 2V2
     */
    uint8_t SUPCA1;
}sEEPromVsPa;

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern VOIDFUNC ATA_eepWRbyte_C(uint8_t *addr, uint8_t data);

extern VOIDFUNC ATA_eepWRblock_C(uint8_t *addr, uint8_t *data, uint8_t len);

extern UINT8FUNC ATA_eepRDbyte_ASM(uint8_t *addr);

extern VOIDFUNC  ATA_eepRDblock_C(uint8_t *addr, uint8_t len, uint8_t *buffer);

extern VOIDFUNC ATA_eepromSecureWrite_C(void);

extern sEEPromFactoryLock  eepFacLock;

extern sEEPromConfigValid  eepConfValid;

extern sEEPromIOConfig     eepIO;

extern sEEPromTrxConfig    eepTrxConf;

extern sEEPromTrxCalib     eepTrxCal;

extern sEEPromIDctrl       eepID;

extern sEEPromWDTimer      eepWdtConf;

extern sEEPromEventConfig  eepEventConf;

extern sEEPromSleepMode    eepSleepMode;

extern sEEPromFRCcalib     eepFRCcalib;

extern sServiceConfiguration eepServices[NUM_EEPROM_SERVICES];

extern sEEPromPollLoopConf eepPollLoopConf;

extern sEEPromDebug eepDebug;

extern sEEPromDebouncing eepDebounce;

extern sEEPromRssi eepRssi;

extern sEEPromVsPa eepVsPa;

/* -- SIX-2608 -- */
extern sEEPromServiceChannelSwitchConfig eepServiceChannelSwitchConfig[NUM_EEPROM_SERVICES];

#elif defined __IAR_SYSTEMS_ASM__
/*startSimExtraction*/
/* sEEPromFactoryLock */
EEP_FACLOCK_CONF_FEBIA              EQU 0x00
EEP_FACLOCK_CONF_FEBT               EQU 0x01
EEP_FACLOCK_CONF_FELNA              EQU 0x02
EEP_FACLOCK_CONF_FELNA2             EQU 0x03
EEP_FACLOCK_CONF_FETN4              EQU 0x04
EEP_FACLOCK_CONF_FEVCOOFFSET        EQU 0x05
EEP_FACLOCK_CONF_TEMPCAL1           EQU 0x06
EEP_FACLOCK_CONF_TEMPCAL2           EQU 0x07
EEP_FACLOCK_CONF_TEMPCAL3           EQU 0x08
EEP_FACLOCK_CONF_TEMPCAL4           EQU 0x09

/* sEEPromConfigValid */
EEP_CONFIGVALID_CONFINITFLAGS       EQU 0x00
EEP_CONFIGVALID_CONFVAL             EQU EEP_CONFIGVALID_CONFINITFLAGS + 1
EEP_CONFIGVALID_CONFVMCSR           EQU EEP_CONFIGVALID_CONFVAL + 1
EEP_CONFIGVALID_FUNCPTR             EQU EEP_CONFIGVALID_CONFVMCSR + 1

/* sEEPromIOConfig */
EEP_IOCONFIG_CONF_DDRB              EQU 0x00
EEP_IOCONFIG_CONF_DDRC              EQU EEP_IOCONFIG_CONF_DDRB + 1
EEP_IOCONFIG_CONF_MCUCR             EQU EEP_IOCONFIG_CONF_DDRC + 1
EEP_IOCONFIG_CONF_PCICR             EQU EEP_IOCONFIG_CONF_MCUCR + 1
EEP_IOCONFIG_CONF_PCMSK0            EQU EEP_IOCONFIG_CONF_PCICR + 1
EEP_IOCONFIG_CONF_PCMSK1            EQU EEP_IOCONFIG_CONF_PCMSK0 + 1
EEP_IOCONFIG_CONF_PORTB             EQU EEP_IOCONFIG_CONF_PCMSK1 + 1
EEP_IOCONFIG_CONF_PORTC             EQU EEP_IOCONFIG_CONF_PORTB + 1

/* sEEPromTrxConfig */
EEP_TRXCONFIG_CLKCONFIG             EQU 0x00
EEP_TRXCONFIG_SPICONFIG             EQU EEP_TRXCONFIG_CLKCONFIG + 1
EEP_TRXCONFIG_SYSCONFIG             EQU EEP_TRXCONFIG_SPICONFIG + 1
EEP_TRXCONFIG_CLKOUTCONFIG          EQU EEP_TRXCONFIG_SYSCONFIG + 1
EEP_TRXCONFIG_SYSSTARTCONF          EQU EEP_TRXCONFIG_CLKOUTCONFIG + 1
EEP_TRXCONFIG_SYSSTARTSVCCHCONFIG   EQU EEP_TRXCONFIG_SYSSTARTCONF + 1
EEP_TRXCONFIG_SVCINITCONF           EQU EEP_TRXCONFIG_SYSSTARTSVCCHCONFIG + 1

EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_LOWBATT_DISABLE    EQU BIT_0
EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_AVCCLOW_DISABLE    EQU BIT_1
EEP_TRXCONF_SYSCONFIG_DFIFO_OFL_UFL_RX_DISABLE      EQU BIT_2
EEP_TRXCONF_SYSCONFIG_SFIFO_OFL_UFL_RX_DISABLE      EQU BIT_3
EEP_TRXCONF_SYSCONFIG_VS5V                          EQU BIT_4
EEP_TRXCONF_SYSCONFIG_VS22V                         EQU BIT_5

BM_EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_LOWBATT_DISABLE EQU BIT_MASK_0
BM_EEP_TRXCONF_SYSCONFIG_AVCCCONFIG_AVCCLOW_DISABLE EQU BIT_MASK_1
BM_EEP_TRXCONF_SYSCONFIG_DFIFO_OFL_UFL_RX_DISABLE   EQU BIT_MASK_2
BM_EEP_TRXCONF_SYSCONFIG_SFIFO_OFL_UFL_RX_DISABLE   EQU BIT_MASK_3
BM_EEP_TRXCONF_SYSCONFIG_VS5V                       EQU BIT_MASK_4
BM_EEP_TRXCONF_SYSCONFIG_VS22V                      EQU BIT_MASK_5

/* sEEPromTrxCalib */
EEP_TRXCALIB_CALCONF1               EQU 0x00
EEP_TRXCALIB_CALCONF2               EQU 0x01
EEP_TRXCALIB_SELFCHK                EQU 0x02
EEP_TRXCALIB_TEMPCAL                EQU 0x03

/* sEEPromIDctrl */
EEP_IDCTRL_IDBYTE                   EQU 0x00
EEP_IDCTRL_IDCTRL                   EQU 0x48
EEP_IDCTRL_IDEN                     EQU 0x51

/* sEEPromWDTimer */
EEP_WDTIMER_CONFT0CR                EQU 0x00
EEP_WDTIMER_CONFT0IFR               EQU 0x01
EEP_WDTIMER_CONFWDTCR               EQU 0x02

/* sEEPromEventConfig */
EEP_EVENTCONFIG_PINEVENTCONF        EQU 0x00
EEP_EVENTCONFIG_SYSEVENTCONF        EQU EEP_EVENTCONFIG_PINEVENTCONF + 1
EEP_EVENTCONFIG_CMDRDYCONF          EQU EEP_EVENTCONFIG_SYSEVENTCONF + 1

/* sEEPromSleepMode */
EEP_SLEEPMODE_SLEEPMODECONF         EQU 0x00

/* sEEPromFRCcalib */
EEP_FRCCALIB_FRCCALIBGATE           EQU 0x00

/* sEEPromPollLoopConf */
EEP_POLLLOOPCONF_CONFT1COR          EQU 0x00
EEP_POLLLOOPCONF_CONFT1MR           EQU 0x01
EEP_POLLLOOPCONF_POLLLOOPCONF       EQU 0x02

/* sEEPromDebug */
EEP_DEBUG_DBGSW                     EQU 0x00

/* sEEPromDebouncing */
EEP_DEBOUNCING_DBCR                 EQU 0x00
EEP_DEBOUNCING_DBTC                 EQU EEP_DEBOUNCING_DBCR + 1
EEP_DEBOUNCING_DBENB                EQU EEP_DEBOUNCING_DBTC + 1
EEP_DEBOUNCING_DBENC                EQU EEP_DEBOUNCING_DBENB + 1


/* sEEPromRssi */
EEP_RSSI_RSIFG                      EQU 0x00
EEP_RSSI_RSLDV                      EQU EEP_RSSI_RSIFG + 1
EEP_RSSI_RSHDV                      EQU EEP_RSSI_RSLDV + 1

/* sEEPromVsPa */
EEP_VSPA_SUPCA1                     EQU 0x00

/* sEEPromServiceChannelSwitchConfig */
EEP_SERVICE0_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK    EQU 0x00
EEP_SERVICE0_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_PATTERN EQU EEP_SERVICE0_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK + 1

EEP_SERVICE1_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK    EQU EEP_SERVICE0_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_PATTERN + 1
EEP_SERVICE1_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_PATTERN EQU EEP_SERVICE1_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK + 1

EEP_SERVICE2_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK    EQU EEP_SERVICE1_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_PATTERN + 1
EEP_SERVICE2_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_PATTERN EQU EEP_SERVICE2_CHANNEL_SWITCHCONFIG_ANTENNA_SWITCHING_MASK + 1

/*stopSimExtraction*/
#endif

#endif /* EEP_H */