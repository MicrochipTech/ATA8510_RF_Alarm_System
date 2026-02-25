/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/globals/src/globals_types.h $
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

/** \file globals_types.h
*/
#ifndef GLOBALS_TYPES_H
#define GLOBALS_TYPES_H

#if defined__IAR_SYSTEMS_ICC__

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "globals_defs.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/*===========================================================================*/
/*  TYPE DEFINITIONS                                                         */
/*===========================================================================*/

/** \brief <b>svcChConfig_t</b>
    is a typedef for the Service/Channel configuration
    \li Bit 7: enaPathB
    \li Bit 6: enaPathA
    \li Bit 5: ch[1]
    \li Bit 4: ch[0]
    \li Bit 3: rfu
    \li Bit 2: ser[2]
    \li Bit 1: ser[1]
    \li Bit 0: ser[0]
 */
typedef uint8_t         svcChConfig_t;

/** \brief <b>tuneCheckConfig_t</b>
    is a typedef for the Tune and Check configuration
    \li Bit 7: Antenna Tuning
    \li Bit 6: Temperature Measurement
    \li Bit 5: SRC calibration
    \li Bit 4: FRC calibration
    \li Bit 3: VCO calibration
    \li Bit 2: RF calibration
    \li Bit 1: Self check
    \li Bit 0: Register Refresh during Self check
 */
typedef uint8_t         tuneCheckConfig_t;

/** \brief <b>sysModeConfig_t</b>
    is a typedef for system Mode configuration
    \li Bit 7:         RF calibration flag (0:disabled / 1:enabled)
    \li Bit 6:         Antenna tuning flag (0:disabled / 1:enabled)
    \li Bit 5:         VCO tuning flag (0:disabled / 1:enabled)
    \li Bit 4:         next system IDLEMode selector 0:RC / 1:XTO
    \li Bit 3:         direct (1)/ normal (0) switching
    \li Bit 2:         TMDEN: Transparent Mode Data Enable
    \li Bit 1..0:      OPM[0..1]: Operation Mode
        - 0: Idle Mode (SPI or LIN)
        - 1: TX Mode
        - 2: RX Mode
        - 3: RX Polling Mode
 */
typedef uint8_t         sysModeConfig_t;

/** \brief <b>pinEventConfig_t</b>
    is a typedef for pin event configuration
    \li Bit 7:    PowerOn
    \li Bit 6:    Debug
    \li Bit 5:    nPWR6
    \li Bit 4:    nPWR5
    \li Bit 3:    nPWR4
    \li Bit 2:    nPWR3
    \li Bit 1:    nPWR2
    \li Bit 0:    nPWR1
 */
typedef uint8_t     pinEventConfig_t;

/** \brief <b>sysEventConfig_t</b>
    is a typedef for system event configuration
    \li Bit 7:    SystemErrorFlag
    \li Bit 6:    CMD_RDY
    \li Bit 5:    SYS_RDY
    \li Bit 4:    AVCCLOWM
    \li Bit 3:    LOWBATTM
    \li Bit 2:    RX_ACTIVE_EN
    \li Bit 1:    RX_ACTIV/E_POL
    \li Bit 0:    EventPinPolarity
 */
typedef uint8_t     sysEventConfig_t;

/*----------------------------------------------------------------------------- */
/** \brief <b>sTrxConfig</b>
    holds the settings for the Transceiver Configuration
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>tuneCheckConfig</b>
        contains the Tune and Check Configuration which shall be done
     */
    tuneCheckConfig_t tuneCheckConfig;

    /** \brief <b>systemModeConfig</b>
        contains the current System mode configuration
     */
    sysModeConfig_t systemModeConfig;

    /** \brief <b>serviceChannelConfig</b>
        contains the Service/Channel configuration
     */
    svcChConfig_t serviceChannelConfig;

    /** \brief systemConfig
        contains system specific configuration settings for trx
        \li Bit 7:    pureRxMode enable 1:enabled / 0:disabled
        \li Bit 6:    rfu
        \li Bit 5:    SRCAO: SRC always ON/OFF --> 0:OFF/1:ON
        \li Bit 4:    FRCAO: FRC always ON/OFF --> 0:OFF/1:ON
        \li Bit 3:    SFIFO_OFL_UFL_RX_DISABLE 0:enabled/1:disabled
        \li Bit 2:    DFIFO_OFL_UFL_RX_DISABLE 0:enabled/1:disabled
        \li Bit 1:    current system IDLEMode selector 0:RC / 1:XTO
        \li Bit 0:    VS5V: Power Supply 0:3V / 1:5V
     */
    uint8_t systemConfig;

    /** \brief <b>serviceInitConfig</b>
        holds the service init configuration
        \li Bit7: updateFlag
        \li Bit6: rfu
        \li Bit5: rfu
        \li Bit4: rfu
        \li Bit3: rfu
        \li Bit2: eepromService1
        \li Bit1: eepromService0 0..2
        \li Bit0: sramService    0..1
     */
    uint8_t serviceInitConfig;

    /** \brief <b>miscTrigger</b>
        holds the miscellaneous trigger
        \li Bit7: rfu
        \li Bit6: rfu
        \li Bit5: rfu
        \li Bit4: rfu
        \li Bit3: rfu
        \li Bit2: rfu
        \li Bit1: PC4 old state, if in pure RX mode
        \li Bit0: start RSSI measurment
     */
    uint8_t    miscTrigger;

    /** \brief <b>lastSystemModeConfig</b>
        contains the last valid System mode configuration
     */
    sysModeConfig_t lastSystemModeConfig;

    /** \brief <b>lastServiceChannelConfig</b>
        contains the last valid Service/Channel configuration
     */
    svcChConfig_t lastServiceChannelConfig;

    /** \brief <b>idScanStatus</b>
        contains the status of the ID scanning
        \li Bit7: id scan result (1:okay / 0:fail)
        \li Bit6: id scan valid  (1:valid / 0:invalid)
        \li Bit5: id scan buffer full (1:7 or more bytes in buffer / 0:less than 7 bytes in buffer)
        \li Bit4: idEna4
        \li Bit3: idEna3
        \li Bit2: idEna2
        \li Bit1: idEna1
        \li Bit0: idEna0
    */
    volatile uint8_t idScanStatus;

    /** \brief <b>idScanCtrl</b>
        contains the loop counter of the ID scanning (0, 6, 12)
        \li Bit7: id scan active to check data stream for valid IDs
            - 0: at least one id scan condition fails, no id scan possible
            - 1: all conditions for id scanning are fulfilled (buffered mode, etc.)
        \li Bit6: EOT path B
            - 0: reset state, no EOT on path B occurred
            - 1: EOT on path B occurred
        \li Bit5: EOT path A
            - 0: reset state, no EOT on path A occurred
            - 1: EOT on path A occurred
        \li Bit4: idCnt4
        \li Bit3: idCnt3
        \li Bit2: idCnt2
        \li Bit1: idCnt1
        \li Bit0: idCnt0
    */
    volatile uint8_t idScanCtrl;
}sTrxConfig;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEventData</b>
    contains bytes to handle the system events/irqs.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>pinEventMask</b>
        holds the pin event mask information
     */
    pinEventConfig_t    pinEventMask;

    /** \brief <b>sysEventMask</b>
        holds the system event mask information
     */
    sysEventConfig_t    sysEventMask;

    /** \brief <b>cmdRdyConf</b>
        holds the CMD_RDY event configuration
        \li Bit 7: enable CMD_RDY event for Antenna Tuning
        \li Bit 6: enable CMD_RDY event for Temperature Measurement
        \li Bit 5: enable CMD_RDY event for SRC calibration
        \li Bit 4: enable CMD_RDY event for FRC calibration
        \li Bit 3: enable CMD_RDY event for VCO calibration
        \li Bit 2: enable CMD_RDY event for RF calibration
        \li Bit 1: enable CMD_RDY event for Self check
        \li Bit 0: enable CMD_RDY event for TX
     */
    uint8_t    cmdRdyConf;

    /** \brief <b>eventCopy<</b>
        contains the variables used for a event flags synchronization
    */
    uint8_t eventCopy[4];

    /** \brief <b>eventCtrl</b>
        contains the variables used for controlling the event signaling feature
        \li Bit 7: rfu
        \li Bit 6: rfu
        \li Bit 5: rfu
        \li Bit 4: rfu
        \li Bit 3: rfu
        \li Bit 2: rfu
        \li Bit 1: rfu
        \li Bit 0: IRQ during SPI command
     */
     uint8_t eventCtrl;

}sEventData;

/*----------------------------------------------------------------------------- */
/** \brief <b>sExtReq</b>
    contains the configuration which was selected via SPI command
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>tuneCheckConfig</b>
        contains the Tune and Check settings from external
     */
    tuneCheckConfig_t tuneCheckConfig;

    /** \brief <b>systemModeConfig</b>
        contains the System mode configuration from external\
     */
    sysModeConfig_t systemModeConfig;

    /** \brief <b>serviceChannelConfig</b>
        contains the Service/Channel configuration
     */
    svcChConfig_t serviceChannelConfig;

    /** \brief <b>serviceInitConfig</b>
        holds the service init configuration
        \li Bit7: updateFlag
        \li Bit6: rfu
        \li Bit5: rfu
        \li Bit4: rfu
        \li Bit3: rfu
        \li Bit2: eepromService1
        \li Bit1: eepromService0 0..2
        \li Bit0: sramService    0..1
     */
    uint8_t    serviceInitConfig;

    /** \brief <b>miscTrigger</b>
        holds the miscellaneous trigger
        \li Bit7: rfu
        \li Bit6: rfu
        \li Bit5: rfu
        \li Bit4: rfu
        \li Bit3: rfu
        \li Bit2: rfu
        \li Bit1: rfu
        \li Bit0: start RSSI measurment
     */
    uint8_t    miscTrigger;

}sExtReq;

/*----------------------------------------------------------------------------- */
/** \brief <b>sTriggerEEP</b>
    contains the EEPtriggering byte
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>triggerEEPwr</b>
        needed to trigger the EEPsecureWrite
    */
    uint8_t triggerEEPwr;

}sTriggerEEP;

/*----------------------------------------------------------------------------- */
/** \brief <b>sServiceSpecificConfiguration</b>
    is the service specific configuration structure
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>CHCR</b>
        Channel Filter Configuration Register settings
     */
    uint8_t CHCR;
    /** \brief <b>CHDN</b>
        Channel Filter Down Sampling Register settings
     */
    uint8_t CHDN;
    /** \brief <b>CHSTARTFILTER</b>
        Channel Filter Startup Time
     */
    uint8_t CHSTARTFILTER;
    /** \brief <b>DMCDA</b>
        Demodulator Carrier Detect Register settings for Path A
     */
    uint8_t DMCDA;
    /** \brief <b>DMCDB</b>
        Demodulator Carrier Detect Register settings for Path B
     */
    uint8_t DMCDB;
    /** \brief <b>DMCRA</b>
        Demodulator Control Register settings for Path A
     */
    uint8_t DMCRA;
    /** \brief <b>DMCRB</b>
        Demodulator Control Register settings for Path B
     */
    uint8_t DMCRB;
    /** \brief <b>DMDRA</b>
        Demodulator Data Rate on Path A Register settings
     */
    uint8_t DMDRA;
    /** \brief <b>DMDRB</b>
        Demodulator Data Rate on PathB Register settings
     */
    uint8_t DMDRB;
    /** \brief <b>DMMA</b>
        Demodulator Mode Register settings for Path A
     */
    uint8_t DMMA;
    /** \brief <b>DMMB</b>
        Demodulator Mode Register settings for Path B
     */
    uint8_t DMMB;
    /** \brief <b>EOT1A</b>
        EOT settings during WUP check
     */
    uint8_t EOT1A;
    /** \brief <b>EOT1B</b>
        EOT settings during WUP check
     */
    uint8_t EOT1B;
    /** \brief <b>EOT2A</b>
        EOT settings during SFID check
     */
    uint8_t EOT2A;
    /** \brief <b>EOT2B</b>
        EOT settings during SFID check
     */
    uint8_t EOT2B;
    /** \brief <b>EOT3A</b>
        EOT settings during RX on pathA
     */
    uint8_t EOT3A;
    /** \brief <b>EOT3B</b>
        EOT settings during RX on pathB
     */
    uint8_t EOT3B;
    /** \brief <b>FEALR_FEANT</b>
        this variable contains a combination of FEANT and FEALR register
        \li Bit 7:    rfu
        \li Bit 6:    rfu
        \li Bit 5:    FEALR.RNGE1
        \li Bit 4:    FEALR.RNGE0
        \li Bit 3:    FEANT.LVLC3
        \li Bit 2:    FEANT.LVLC2
        \li Bit 1:    FEANT.LVLC1
        \li Bit 0:    FEANT.LVLC0
     */
    uint8_t FEALR_FEANT;
    /** \brief <b>FEAT</b>
        Frontend Amplifier Bias and Antenna Tuning Register settings
     */
    uint8_t FEAT;
    /** \brief <b>FEPAC</b>
        Frontend Power Amplifier Register settings
     */
    uint8_t FEPAC;
    /** \brief <b>FEVCO</b>
        Frontend VCO and PLL Control Register settings
     */
    uint8_t FEVCO;
    /** \brief <b>FEVCT</b>
        Frontend VCO Tuning Register settings
     */
    uint8_t FEVCT;
    /** \brief <b>FREQoffset</b>
        Frequency Offset, if subChanneling is used
     */
    uint8_t FREQoffset[2];
    /** \brief <b>txDevA</b>
        frequency deviation settings path A (HighByte and LowByte), will be used for SW calculations
     */
    uint8_t txDevA[2];
    /** \brief <b>txDevB</b>
        frequency deviation settings path B (HighByte and LowByte), will be used for SW calculations
     */
    uint8_t txDevB[2];
    /** \brief <b>GACDIVA</b>
        Gauss Clock Divider Register settings
     */
    uint8_t GACDIVA[2];
    /** \brief <b>GACDIVB</b>
        Gauss Clock Divider Register settings
     */
    uint8_t GACDIVB[2];
    /** \brief <b>IF</b>
        IF setting (HighByte and LowByte) will be used for SW calculations
     */
    uint8_t IF[2];
    /** \brief <b>RDOCR</b>
        Rx Dsp Output Control Register settings
     */
    uint8_t RDOCR;
    /** \brief <b>rssiSysConf</b>
        is used for RSSI enabling/disabling and event signaling
        \li Bit 7: RssiEnable
        \li Bit 6: rfu
        \li Bit 5: rssiBufEvMask contains the enable flag for RSSI buffer fill level event
                - 1: enabled
                - 0: disabled
        \li Bit 4..Bit 0: RSSIbuf contains the fill level information for RSSI buffer fill level event
     */
    uint8_t rssiSysConf;
    /** \brief <b>rxSetPathA</b>
        is used for RX event signaling and configuration for Path A.<br>
        <b>rxSetPathA[0]</b>
        \li Bit 7: rfu
        \li Bit 6: rxBufEvMaskA contains the enable flag for RX buffer fill level event for path A
                - 1: enabled
                - 0: disabled
        \li Bit 5..Bit 0: RXbufA contains the fill level information for RX buffer fill level event for path A<br>

        <b>rxSetPathA[1]</b>
        \li Bit 7:    IWUPA
        \li Bit 6:    DARA
        \li Bit 5:    GAPMA
        \li Bit 4:    RXEHA
        \li Bit 3:    rfu
        \li Bit 2:    rfu
        \li Bit 1:    rfu
        \li Bit 0:    RX modulation path A (0=FSK/1=ASK)
     */
    uint8_t rxSetPathA[2];
    /** \brief <b>rxSetPathB[0]</b>
        is used for RX event signaling and configuration for Path B.<br>
        <b>rxSetPathA[0]</b>
        \li Bit 7: rfu
        \li Bit 6: rxBufEvMaskBcontains the enable flag for RX buffer fill level event for path B
                - 1: enabled
                - 0: disabled
        \li Bit 5..Bit 0: RXbufB contains the fill level information for RX buffer fill level event for path A<br>

        <b>rxSetPathB[1]</b>
        \li Bit 7:    IWUPB
        \li Bit 6:    DARB
        \li Bit 5:    GAPMB
        \li Bit 4:    RXEHB
        \li Bit 3:    rfu
        \li Bit 2:    rfu
        \li Bit 1:    rfu
        \li Bit 0:    RX modulation path B (0=FSK/1=ASK)
     */
    uint8_t rxSetPathB[2];
    /** \brief <b>rxSysEvent</b>
        is used for event configuration
        \li Bit 7: IDCHKOKA_Mask
        \li Bit 6: WCOKA_Mask
        \li Bit 5: SOTA_Mask
        \li Bit 4: EOTA_Mask
        \li Bit 3: IDCHKOKB_Mask
        \li Bit 2: WCOKB_Mask
        \li Bit 1: SOTB_Mask
        \li Bit 0: EOTB_Mask
     */
    uint8_t rxSysEvent;
    /** \brief <b>rxSysSet</b>
        is used for disabling/enabling of RXMode features
        \li Bit 7: subchanneling enable/disable
        \li Bit 6: IDscan enable/disable
        \li Bit 5: SSM IF amplifier enable
        \li Bit 4: path valid after SOT enable/disable
        \li Bit 3: automatic Antenna Damping path B enable/disable
        \li Bit 2: automatic Antenna Damping path A enable/disable
        \li Bit 1: switching_SDTX
        \li Bit 0: switching_SDRX
     */
    uint8_t rxSysSet;
    /** \brief <b>SFIDA</b>
        Start Frame ID Byte Configuration for Path A
     */
    uint8_t SFIDA[4];
    /** \brief <b>SFIDB</b>
        Start Frame ID Byte Configuration for Path B
     */
    uint8_t SFIDB[4];
    /** \brief <b>SFIDCA</b>
        Start Frame ID Configuration for Path A
     */
    uint8_t SFIDCA;
    /** \brief <b>SFIDCB</b>
        Start Frame ID Configuration for Path B
     */
    uint8_t SFIDCB;
    /** \brief <b>SFIDLA</b>
        Start Frame ID Length Configuration for Path A
     */
    uint8_t SFIDLA;
    /** \brief <b>SFIDLB</b>
        Start Frame ID Length Configuration for Path B
     */
    uint8_t SFIDLB;
    /** \brief <b>SOT1A</b>
        SOT setting for Path A before WUP match
     */
    uint8_t SOT1A;
    /** \brief <b>SOT1B</b>
        SOT setting for Path B before WUP match
     */
    uint8_t SOT1B;
    /** \brief <b>SOT2A</b>
        SOT setting for Path A after WUP match
     */
    uint8_t SOT2A;
    /** \brief <b>SOT2B</b>
        SOT setting for Path B after WUP match
     */
    uint8_t SOT2B;
    /** \brief <b>SOTtimeOutA</b>
        Configuration for Start Of Telegram/Bit Check okay Time Out for path A
     */
    uint8_t SOTtimeOutA;
    /** \brief <b>SOTtimeOutB</b>
        Configuration for Start Of Telegram/Bit Check okay Time Out for path B
     */
    uint8_t SOTtimeOutB;
    /** \brief <b>SYCA</b>
        Symbol Check Configuration Register settings for Data Path A
     */
    uint8_t SYCA;
    /** \brief <b>SYCB</b>
        Symbol Check Configuration Register settings for Data Path B
     */
    uint8_t SYCB;
    /** \brief <b>FSFCRA</b>
        Tx DSP Filter Control Register settings for path A
     */
    uint8_t FSFCRA;
    /** \brief <b>FSFCRB</b>
        Tx DSP Filter Control Register settings for path B
     */
    uint8_t FSFCRB;
    /** \brief <b>TMUL</b>
        Multiplier to calculate temperature compensation
     */
    uint8_t TMUL;
    /** \brief <b>trxSysConf</b>
        contains the TRX System Configuration
        \li Bit 7: rfu
        \li Bit 6: rfu
        \li Bit 5: rfu
        \li Bit 4: rfu
        \li Bit 3: TRPB enable/disable
        \li Bit 2: TRPA enable/disable
        \li Bit 1: Antenna Switching enable/disable
        \li Bit 0: Channel Switching enable/disable
     */
    uint8_t trxSysConf;
    /** \brief <b>TXDRA</b>
        TX Data Rate setting of Path A (HighByte and LowByte) will be used for SW
        calculations
     */
    uint8_t TXDRA[2];
    /** \brief <b>TXDRB</b>
        TX Data Rate setting of Path B (HighByte and LowByte) will be used for SW
        calculations
     */
    uint8_t TXDRB[2];
    /** \brief <b>txSetPathA</b>
        is used for TXMode configuration of Path A

        <b>txSetPathA[0]</b>
        \li Bit 7: GAUS
        \li Bit 6: PREE
        \li Bit 5..Bit 0: StartTxDataFillLevel<br>

        <b>txSetPathA[1]</b>
        \li Bit 7: TX modulation path A (0=FSK/1=ASK)
        \li Bit 6: ASK shaping enable for path A
        \li Bit 5: rfu
        \li Bit 4..0: StartPreambleFillLevel
     */
    uint8_t txSetPathA[2];
    /** \brief <b>txSetPathB</b>
        is used for TXMode configuration of Path B

        <b>txSetPathB[0]</b>
        \li Bit 7: GAUS
        \li Bit 6: PREE
        \li Bit 5..Bit 0: StartTxDataFillLevel<br>

        <b>txSetPathB[1]</b>
        \li Bit 7: TX modulation path B (0=FSK/1=ASK)
        \li Bit 6: ASK shaping enable for path B
        \li Bit 5: rfu
        \li Bit 4..0: StartPreambleFillLevel
     */
     uint8_t txSetPathB[2];
    /** \brief <b>txSysEventA</b>
        is used for event configuration in TXMode for transmission on Path A
        \li Bit 7: TX-Ending (0: go to idle / 1: PA off, stay in TX)
        \li Bit 6: txBufEvMask
        \li Bit 5..Bit 0: TxBufFillLevel
     */
    uint8_t txSysEventA;
    /** \brief <b>txSysEventB</b>
        is used for event configuration in TXMode for transmission on Path B
        \li Bit 7: TX-Ending (0: go to idle / 1: PA off, stay in TX)
        \li Bit 6: txBufEvMask
        \li Bit 5..Bit 0: TxBufFillLevel
     */
    uint8_t txSysEventB;
    /** \brief <b>txPreambleSysEventA</b>
        is used preamble buffer event configuration in TXMode for transmission on Path A
        \li Bit 7: rfu
        \li Bit 6: rfu
        \li Bit 5: txPreambleBufEvMask
        \li Bit 4..Bit 0: PreambleBufFillLevel
     */
    uint8_t txPreambleSysEventA;
    /** \brief <b>txPreambleSysEventB</b>
        is used preamble buffer event configuration in TXMode for transmission on Path B
        \li Bit 7: rfu
        \li Bit 6: rfu
        \li Bit 5: txPreambleBufEvMask
        \li Bit 4..Bit 0: PreambleBufFillLevel
     */
    uint8_t txPreambleSysEventB;
    /** \brief <b>WCOtimeOutA</b>
        Configuration for Wake Check Ok Time Out for path A
     */
    uint8_t WCOtimeOutA;
    /** \brief <b>WCOtimeOutB</b>
        Configuration for Wake Check Ok Time Out for path B
     */
    uint8_t WCOtimeOutB;
    /** \brief <b>WUPA</b>
        Wake Up Pattern Configuration for Path A
     */
    uint8_t WUPA[4];
    /** \brief <b>WUPB</b>
        Wake Up Pattern Configuration for Path B
     */
    uint8_t WUPB[4];
    /** \brief <b>WUPLA</b>
        Wake Up Pattern Length Configuration for Path A
     */
    uint8_t WUPLA;
    /** \brief <b>WUPLB</b>
        Wake Up Pattern Length Configuration for Path B
     */
    uint8_t WUPLB;
    /** \brief <b>WUTA</b>
        Wake Up Pattern Threshold Configuration for Path A
     */
    uint8_t WUPTA;
    /** \brief <b>WUTB</b>
        Wake Up Pattern Threshold Configuration for Path B
     */
    uint8_t WUPTB;
    /** \brief <b>RXCPA</b>
        RX CRC Polynomial for data path A
     */
    uint8_t RXCPA[2];
    /** \brief <b>RXCIA</b>
        RX CRC Init value for data path A
     */
    uint8_t RXCIA[2];
    /** \brief <b>RXSBA</b>
        RX CRC Skip Bit number for data path A
     */
    uint8_t RXSBA;
    /** \brief <b>RXTLA</b>
        RX Telegram Length for data path A
     */
    uint8_t RXTLA[2];
    /** \brief <b>RXCPB</b>
        RX CRC Polynomial for data path B
     */
    uint8_t RXCPB[2];
    /** \brief <b>RXCIB</b>
        RX CRC Init value for data path B
     */
    uint8_t RXCIB[2];
    /** \brief <b>RXSBB</b>
        RX CRC Skip Bit number for data path B
     */
    uint8_t RXSBB;
    /** \brief <b>RXTLB</b>
        RX Telegram Length for data path B
     */
    uint8_t RXTLB[2];
    /** \brief <b>RXBC1</b>
        RX Buffer Configuration register 1
     */
    uint8_t RXBC1;

    /** \brief <b>TMCR2A</b>
        Tx Modulator Control Register 2
     */
    uint8_t TMCR2A;
    /** \brief <b>TMCR2B</b>
        Tx Modulator Control Register 2
     */
    uint8_t TMCR2B;

    /** \brief <b>TMSSCA</b>
        Tx Modulator Stop Sequence Configuration
     */
    uint8_t TMSSCA;
    /** \brief <b>TMSSCB</b>
        Tx Modulator Stop Sequence Configuration
     */
    uint8_t TMSSCB;

    /** \brief <b>TMTLA</b>
        Tx Modulator Telegram Length
     */
    uint8_t TMTLA[2];
    /** \brief <b>TMTLB</b>
        Tx Modulator Telegram Length
     */
    uint8_t TMTLB[2];

    /** \brief <b>TMCPA</b>
        Tx Modulator CRC Polynomial
     */
    uint8_t TMCPA[2];
    /** \brief <b>TMCPB</b>
        Tx Modulator CRC Polynomial
     */
    uint8_t TMCPB[2];

    /** \brief <b>TMCIA</b>
        Tx Modulator CRC Init value
     */
    uint8_t TMCIA[2];
    /** \brief <b>TMCIB</b>
        Tx Modulator CRC Init value
     */
    uint8_t TMCIB[2];

    /** \brief <b>TMCSBA</b>
        Tx Modulator CRC Skip Bit number
     */
    uint8_t TMCSBA;
    /** \brief <b>TMCSBB</b>
        Tx Modulator CRC Skip Bit number
     */
    uint8_t TMCSBB;

    /** \brief  <b>RSSC</b>
        RSSI Configuration Register
     */
    uint8_t RSSC;
}sServiceSpecificConfiguration;

/*----------------------------------------------------------------------------- */
/** \brief <b>sChannelSpecificConfiguration</b>
    is the channel specific configuration structure
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief  <b>FFREQ</b>
        3 bytes FFRQ base setting
     */
    uint8_t FFREQ[3];
    /** \brief  <b>FEMS</b>
        Frontend Mode and Swallow Register setting
        \li Bit 7..4: PLL Mode
        \li Bit 3..0: PLL Swallow
     */
    uint8_t FEMS;
    /** \brief <b>FECR</b>
        Frontend Control Register settings for temperature measurement channel
        \li  Bit 7..6:  rfu
        \li  Bit 5:     ANPS
        \li  Bit 4:     PLCKG
        \li  Bit 3:     ADHS
        \li  Bit 2:     ANDP
        \li  Bit 1:     S4N3
        \li  Bit 0:     LBNHB
     */
    uint8_t FECR;
}sChannelSpecificConfiguration;

/*----------------------------------------------------------------------------- */
/** \brief <b>sServiceConfiguration</b>
    is the service configuration structure used for SRAM/EEPROM services
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>service</b>
        contains the service specific part of a service configuration
     */
    sServiceSpecificConfiguration  service;
    /** \brief <b>channel</b>
        contains the channel specific part of a service configuration
     */
    sChannelSpecificConfiguration channel[3];
}sServiceConfiguration;

/*----------------------------------------------------------------------------- */
/** \brief <b>sServiceConfiguration</b>
    is the service configuration structure used for current service, which
    is a copy from EEPROM/SRAM service and used for HW initialization
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>service</b>
        contains the service specific part of a service configuration
     */
    sServiceSpecificConfiguration  service;
    /** \brief <b>channel</b>
        contains the channel specific part of a service configuration
     */
    sChannelSpecificConfiguration channel;
}sCurrentServiceConfiguration;

/*----------------------------------------------------------------------------- */
/** \brief <b>sFacLock</b>
    contains a copy from some factory locked EEPROM bytes to avoid reloading
    from EEPROM after system initialization
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
}sFacLock;


/*----------------------------------------------------------------------------- */
/** \brief <b>sDebug</b>
    contains the bytes for the last occured system error and the last occured
    ssm errror
 */
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>errorCode</b>
        contains the last occured system error
     */
    uint8_t errorCode;
    /** \brief <b>ssmErrorCode</b>
        contains the last occured ssm error
     */
    uint8_t ssmErrorCode;
}sDebug;

/*----------------------------------------------------------------------------- */
/** \brief <b>sPollingChannelConfig</b>
    contains polling control configuration byte and service channel configuration
    byte and is used in polling configuration array.
 */
/*----------------------------------------------------------------------------- */
typedef struct {
    /** \brief <b>config</b>
        is used for polling control of polling array and tune options for
        currently used polling channel
        \li Bit 7:    RF Calibration
        \li Bit 6:    rfu
        \li Bit 5:    VCO tuning
        \li Bit 4:    rfu
        \li Bit 3:    rfu
        \li Bit 2:    rfu
        \li Bit 1:    EOL --> End Of Polling Loop
        \li Bit 0:    EOP --> End Of Polling Cycle
     */
    uint8_t config;
    /** \brief <b>svcChConfig</b>
        contains the currently used polling channel configuration
        \li Bit 7: enaPathB
        \li Bit 6: enaPathA
        \li Bit 5: ch[1]
        \li Bit 4: ch[0]
        \li Bit 3: rfu
        \li Bit 2: ser[2]
        \li Bit 1: ser[1]
        \li Bit 0: ser[0]
     */
    svcChConfig_t svcChConfig;
}sPollingChannelConfig;

/*lint -e14 */

/* GeWi (18feb2011)
 * disable lint error 14 - because definition of variables
 * located at absolute address or register should be placed
 * in header file see iar technical note 43262
 * see http://supp.iar.com/Support/?note=43262
 */

/** \brief <b>sysStatus</b>
    is used as register variable for status bits and is
    located in AVR register GPIOR3 at address 0x001B<br>
    <b>TX / RX:</b>
    \li Bit 7:    update flag for external requests
    \li Bit 6:    Rdy4DirectSwitching
    \li Bit 5:    SPI command in progress
    \li Bit 4:    SPI command pending
    \li Bit 3:    Sleep during SW state machines enable/disable
    \li Bit 2:    Calibration activity flag
    \li Bit 1:    AVCCLOW interrupt occured
    \li Bit 0:    SSMrdy Sequencer State Machine Ready flag
 */
#pragma location = 0x001B       /* GPIOR3 */
__io __no_init uint8_t sysStatus;

/** \brief <b>trxStatus</b>
    is used as register variable for status bits in rx and tx mode
    and is located in AVR register GPIOR4 at address 0x001C<br>
    <b>TX:</b>
    \li Bit 7:    rfu
    \li Bit 6:    rfu
    \li Bit 5:    rfu
    \li Bit 4:    rfu
    \li Bit 3:    rfu
    \li Bit 2:    rfu
    \li Bit 1:    Tx Modulator Transmission Complete Interrupt
    \li Bit 0:    ASK/FSK Modulation 0 = FSK / 1 = ASK<br>

    <b>RX:</b>
    \li Bit 7:    WCOB - Wake Check Ok on path B
    \li Bit 6:    WCOA - Wake Check Ok on path A
    \li Bit 5:    SOTB - Start Of Telegram on path B
    \li Bit 4:    SOTA - Start Of Telegram on path A
    \li Bit 3:    EOTB - End Of Telegram on path B
    \li Bit 2:    EOTA - End Of Telegram on path A
    \li Bit 1:    ASK/FSK Modulation for Path B 0 = FSK / 1 = ASK
    \li Bit 0:    ASK/FSK Modulation for Path A 0 = FSK / 1 = ASK
 */
#pragma location = 0x001C       /* GPIOR4 */
__io __no_init uint8_t trxStatus;

/** \brief <b>events_system</b>
    contains the event flags with ATA5831 system information
    and is located in AVR register R15
    \li Bit 7:    SYS_ERR
    \li Bit 6:    CMD_RDY
    \li Bit 5:    SYS_RDY
    \li Bit 4:    AVCCLOW
    \li Bit 3:    LOWBATT
    \li Bit 2:    RSSI_BUF
    \li Bit 1:    RX_BUF
    \li Bit 0:    TX_BUF
 */
#pragma location = 15           /* R15 */
__regvar __no_init uint8_t events_system;


/** \brief <b>events_events</b>
    contains the event flags with ATA5831 RX/TX/RSSI information
    and is located in AVR register R14
    \li Bit 7:    ID_CHECK
    \li Bit 6:    WCOA
    \li Bit 5:    SOTA
    \li Bit 4:    EOTA
    \li Bit 3:    ID_CHECKB
    \li Bit 2:    WCOB
    \li Bit 1:    SOTB
    \li Bit 0:    EOTB
 */
#pragma location = 14           /* R14 */
__regvar __no_init volatile uint8_t events_events;

/** \brief <b>events_power</b>
    contains the event flags with powerOn nPowerOn information
    and is located in AVR register R13
    \li Bit 7: PWRON
    \li Bit 6: DEBUG Event
    \li Bit 5: NPWRON6
    \li Bit 4: NPWRON5
    \li Bit 3: NPWRON4
    \li Bit 2: NPWRON3
    \li Bit 1: NPWRON2
    \li Bit 0: NPWRON1
 */
#pragma location = 13           /* R13 */
__regvar __no_init volatile uint8_t events_power;

/** \brief <b>events_config</b>
    holds the current selected service channel configuration
    and is located in AVR register R12
 */
#pragma location = 12           /* R12 */
__regvar __no_init volatile uint8_t events_config;

/*lint -restore */
 /*----------------------------------------------------------------------------- */
/** \brief <b>sId</b>
    holds the id configuration of one id
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>data</b>
        contains four bytes ID.
     */
    uint8_t data[4];
    /** \brief <b>config</b>
        is used as ID configuration byte.
        \li Bit 7:    IDCE ID Check Execute
        \li Bit 6..4: rfu
        \li Bit 3..2: IDBO[1:0] ID Byte Offset
            - 0: Offset: 0 Bytes
            - 1: Offset: 1 Byte
            - 2: Offset: 2 Bytes
            - 3: Offset: 3 Bytes
        \li Bit 1..0: IDL[1:0] ID Length
            - 0: ID Byte Length: 1 Byte
            - 1: ID Byte Length: 2 Bytes
            - 2: ID Byte Length: 3 Bytes
            - 3: ID Byte Length: 4 Bytes
     */
    uint8_t config;
}sId;

/*----------------------------------------------------------------------------- */
/** \brief <b>sRssi</b>
    contains the configurations/results for RSSI measurement
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>RSSL</b>
        RSSI Low Threshold for Signal Check
     */
    uint8_t RSSL;
    /** \brief <b>RSSH</b>
        RSSI High Threshold for Signal Check
     */
    uint8_t RSSH;
}sRssi;


/*----------------------------------------------------------------------------- */
/** \brief <b>sSubChanneling</b>
    contains status information and stores the measured RSSI values
    determined during subchanneling
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>rssi</b>
        is used as array containing the measured RSSI values.
        \li Index[0] ... RSSI value for center frequency
        \li Index[1] ... RSSI value for lower frequency
        \li Index[2] ... RSSI value for upper frequency
     */
    uint8_t rssi[3];
    /** \brief <b>flags</b>
        is used to store status information during subchanneling.
        \li Bit 7..2: rfu
        \li Bit 1:
            1: RSSI FIFO fill level for subchanneling reached
            0: RSSI FIFO fill level for subchanneling not reached
        \li Bit 0:
            1: subchanneling active
            0: subchanneling inactive
     */
    uint8_t flags;
}sSubChanneling;

/* -- SIX-2608 -- */
/*----------------------------------------------------------------------------- */
/** \brief <b>sEEPromServiceChannelSwitchConfig</b>
    holds the channel switch configuration of a service.
*/
/*----------------------------------------------------------------------------- */
typedef struct
{
    /** \brief <b>antennaSwitchingMask</b>
        Defines which pins of PORTC are allowed to be modified by the pattern.
        A bit value of 0 designates the dedicated pin as being modifiable, bit value 1 as being left unmodifiable.
     */
    uint8_t antennaSwitchingMask;

    /** \brief <b>antennaSwitchingPattern</b>
        Defines the actual pattern to be used.
        Only pattern bits where the corresponding mask bit position is set to zero will be used.
     */
    uint8_t antennaSwitchingPattern;

}sEEPromServiceChannelSwitchConfig;

/* -- SIX-1509 -- */
/*----------------------------------------------------------------------------- */
/** \brief <b>sSramPollingChannelStatistics</b>
    contains the polling channel statistics.
*/
/*----------------------------------------------------------------------------- */
typedef struct
{
    /** \brief <b>bestChannelPollingIndex</b>
        contains the index of the polling channel in SRAM array pollConfig.pollChanConf,
        which is considered to be the best channel of the last polling cycle.
        It is either the channel on which a valid telegram has been received, respectively
        the channel with the lowest RSSI value.
     */
    uint8_t bestChannelPollingIndex;

    /** \brief <b>bestChannelServiceChannelConfig</b>
        contains the service and channel number of the best channel given by the
        bestChannelPollingIndex
    */
    uint8_t bestChannelServiceChannelConfig;

}sSramPollingChannelStatistics;

#elif defined __XC8_CC__
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "globals_defs.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/*===========================================================================*/
/*  TYPE DEFINITIONS                                                         */
/*===========================================================================*/

/** \brief <b>svcChConfig_t</b>
    is a typedef for the Service/Channel configuration
    \li Bit 7: enaPathB
    \li Bit 6: enaPathA
    \li Bit 5: ch[1]
    \li Bit 4: ch[0]
    \li Bit 3: rfu
    \li Bit 2: ser[2]
    \li Bit 1: ser[1]
    \li Bit 0: ser[0]
 */
typedef uint8_t         svcChConfig_t;

/** \brief <b>tuneCheckConfig_t</b>
    is a typedef for the Tune and Check configuration
    \li Bit 7: Antenna Tuning
    \li Bit 6: Temperature Measurement
    \li Bit 5: SRC calibration
    \li Bit 4: FRC calibration
    \li Bit 3: VCO calibration
    \li Bit 2: RF calibration
    \li Bit 1: Self check
    \li Bit 0: Register Refresh during Self check
 */
typedef uint8_t         tuneCheckConfig_t;

/** \brief <b>sysModeConfig_t</b>
    is a typedef for system Mode configuration
    \li Bit 7:         RF calibration flag (0:disabled / 1:enabled)
    \li Bit 6:         Antenna tuning flag (0:disabled / 1:enabled)
    \li Bit 5:         VCO tuning flag (0:disabled / 1:enabled)
    \li Bit 4:         next system IDLEMode selector 0:RC / 1:XTO
    \li Bit 3:         direct (1)/ normal (0) switching
    \li Bit 2:         TMDEN: Transparent Mode Data Enable
    \li Bit 1..0:      OPM[0..1]: Operation Mode
        - 0: Idle Mode (SPI or LIN)
        - 1: TX Mode
        - 2: RX Mode
        - 3: RX Polling Mode
 */
typedef uint8_t         sysModeConfig_t;

/** \brief <b>pinEventConfig_t</b>
    is a typedef for pin event configuration
    \li Bit 7:    PowerOn
    \li Bit 6:    Debug
    \li Bit 5:    nPWR6
    \li Bit 4:    nPWR5
    \li Bit 3:    nPWR4
    \li Bit 2:    nPWR3
    \li Bit 1:    nPWR2
    \li Bit 0:    nPWR1
 */
typedef uint8_t     pinEventConfig_t;

/** \brief <b>sysEventConfig_t</b>
    is a typedef for system event configuration
    \li Bit 7:    SystemErrorFlag
    \li Bit 6:    CMD_RDY
    \li Bit 5:    SYS_RDY
    \li Bit 4:    AVCCLOWM
    \li Bit 3:    LOWBATTM
    \li Bit 2:    RX_ACTIVE_EN
    \li Bit 1:    RX_ACTIV/E_POL
    \li Bit 0:    EventPinPolarity
 */
typedef uint8_t     sysEventConfig_t;

/*----------------------------------------------------------------------------- */
/** \brief <b>sTrxConfig</b>
    holds the settings for the Transceiver Configuration
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>tuneCheckConfig</b>
        contains the Tune and Check Configuration which shall be done
     */
    tuneCheckConfig_t tuneCheckConfig;

    /** \brief <b>systemModeConfig</b>
        contains the current System mode configuration
     */
    sysModeConfig_t systemModeConfig;

    /** \brief <b>serviceChannelConfig</b>
        contains the Service/Channel configuration
     */
    svcChConfig_t serviceChannelConfig;

    /** \brief systemConfig
        contains system specific configuration settings for trx
        \li Bit 7:    pureRxMode enable 1:enabled / 0:disabled
        \li Bit 6:    rfu
        \li Bit 5:    SRCAO: SRC always ON/OFF --> 0:OFF/1:ON
        \li Bit 4:    FRCAO: FRC always ON/OFF --> 0:OFF/1:ON
        \li Bit 3:    SFIFO_OFL_UFL_RX_DISABLE 0:enabled/1:disabled
        \li Bit 2:    DFIFO_OFL_UFL_RX_DISABLE 0:enabled/1:disabled
        \li Bit 1:    current system IDLEMode selector 0:RC / 1:XTO
        \li Bit 0:    VS5V: Power Supply 0:3V / 1:5V
     */
    uint8_t systemConfig;

    /** \brief <b>serviceInitConfig</b>
        holds the service init configuration
        \li Bit7: updateFlag
        \li Bit6: rfu
        \li Bit5: rfu
        \li Bit4: rfu
        \li Bit3: rfu
        \li Bit2: eepromService1
        \li Bit1: eepromService0 0..2
        \li Bit0: sramService    0..1
     */
    uint8_t serviceInitConfig;

    /** \brief <b>miscTrigger</b>
        holds the miscellaneous trigger
        \li Bit7: rfu
        \li Bit6: rfu
        \li Bit5: rfu
        \li Bit4: rfu
        \li Bit3: rfu
        \li Bit2: rfu
        \li Bit1: PC4 old state, if in pure RX mode
        \li Bit0: start RSSI measurment
     */
    uint8_t    miscTrigger;

    /** \brief <b>lastSystemModeConfig</b>
        contains the last valid System mode configuration
     */
    sysModeConfig_t lastSystemModeConfig;

    /** \brief <b>lastServiceChannelConfig</b>
        contains the last valid Service/Channel configuration
     */
    svcChConfig_t lastServiceChannelConfig;

    /** \brief <b>idScanStatus</b>
        contains the status of the ID scanning
        \li Bit7: id scan result (1:okay / 0:fail)
        \li Bit6: id scan valid  (1:valid / 0:invalid)
        \li Bit5: id scan buffer full (1:7 or more bytes in buffer / 0:less than 7 bytes in buffer)
        \li Bit4: idEna4
        \li Bit3: idEna3
        \li Bit2: idEna2
        \li Bit1: idEna1
        \li Bit0: idEna0
    */
    volatile uint8_t idScanStatus;

    /** \brief <b>idScanCtrl</b>
        contains the loop counter of the ID scanning (0, 6, 12)
        \li Bit7: id scan active to check data stream for valid IDs
            - 0: at least one id scan condition fails, no id scan possible
            - 1: all conditions for id scanning are fulfilled (buffered mode, etc.)
        \li Bit6: EOT path B
            - 0: reset state, no EOT on path B occurred
            - 1: EOT on path B occurred
        \li Bit5: EOT path A
            - 0: reset state, no EOT on path A occurred
            - 1: EOT on path A occurred
        \li Bit4: idCnt4
        \li Bit3: idCnt3
        \li Bit2: idCnt2
        \li Bit1: idCnt1
        \li Bit0: idCnt0
    */
    volatile uint8_t idScanCtrl;
}sTrxConfig;

/*----------------------------------------------------------------------------- */
/** \brief <b>sEventData</b>
    contains bytes to handle the system events/irqs.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>pinEventMask</b>
        holds the pin event mask information
     */
    pinEventConfig_t    pinEventMask;

    /** \brief <b>sysEventMask</b>
        holds the system event mask information
     */
    sysEventConfig_t    sysEventMask;

    /** \brief <b>cmdRdyConf</b>
        holds the CMD_RDY event configuration
        \li Bit 7: enable CMD_RDY event for Antenna Tuning
        \li Bit 6: enable CMD_RDY event for Temperature Measurement
        \li Bit 5: enable CMD_RDY event for SRC calibration
        \li Bit 4: enable CMD_RDY event for FRC calibration
        \li Bit 3: enable CMD_RDY event for VCO calibration
        \li Bit 2: enable CMD_RDY event for RF calibration
        \li Bit 1: enable CMD_RDY event for Self check
        \li Bit 0: enable CMD_RDY event for TX
     */
    uint8_t    cmdRdyConf;

    /** \brief <b>eventCopy<</b>
        contains the variables used for a event flags synchronization
    */
    uint8_t eventCopy[4];

    /** \brief <b>eventCtrl</b>
        contains the variables used for controlling the event signaling feature
        \li Bit 7: rfu
        \li Bit 6: rfu
        \li Bit 5: rfu
        \li Bit 4: rfu
        \li Bit 3: rfu
        \li Bit 2: rfu
        \li Bit 1: rfu
        \li Bit 0: IRQ during SPI command
     */
     uint8_t eventCtrl;

}sEventData;

/*----------------------------------------------------------------------------- */
/** \brief <b>sExtReq</b>
    contains the configuration which was selected via SPI command
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>tuneCheckConfig</b>
        contains the Tune and Check settings from external
     */
    tuneCheckConfig_t tuneCheckConfig;

    /** \brief <b>systemModeConfig</b>
        contains the System mode configuration from external\
     */
    sysModeConfig_t systemModeConfig;

    /** \brief <b>serviceChannelConfig</b>
        contains the Service/Channel configuration
     */
    svcChConfig_t serviceChannelConfig;

    /** \brief <b>serviceInitConfig</b>
        holds the service init configuration
        \li Bit7: updateFlag
        \li Bit6: rfu
        \li Bit5: rfu
        \li Bit4: rfu
        \li Bit3: rfu
        \li Bit2: eepromService1
        \li Bit1: eepromService0 0..2
        \li Bit0: sramService    0..1
     */
    uint8_t    serviceInitConfig;

    /** \brief <b>miscTrigger</b>
        holds the miscellaneous trigger
        \li Bit7: rfu
        \li Bit6: rfu
        \li Bit5: rfu
        \li Bit4: rfu
        \li Bit3: rfu
        \li Bit2: rfu
        \li Bit1: rfu
        \li Bit0: start RSSI measurment
     */
    uint8_t    miscTrigger;

}sExtReq;

/*----------------------------------------------------------------------------- */
/** \brief <b>sTriggerEEP</b>
    contains the EEPtriggering byte
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>triggerEEPwr</b>
        needed to trigger the EEPsecureWrite
    */
    uint8_t triggerEEPwr;

}sTriggerEEP;

/*----------------------------------------------------------------------------- */
/** \brief <b>sServiceSpecificConfiguration</b>
    is the service specific configuration structure
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    uint8_t chcr;
    uint8_t chdn;           /* rename for xc8 to avoid mismatch with define */
    uint8_t CHSTARTFILTER;
    uint8_t dmcda;          /* rename for xc8 to avoid mismatch with define */
    uint8_t dmcdb;          /* rename for xc8 to avoid mismatch with define */
    uint8_t dmcra;          /* rename for xc8 to avoid mismatch with define */
    uint8_t dmcrb;          /* rename for xc8 to avoid mismatch with define */
    uint8_t dmdra;          /* rename for xc8 to avoid mismatch with define */
    uint8_t dmdrb;          /* rename for xc8 to avoid mismatch with define */
    uint8_t dmma;           /* rename for xc8 to avoid mismatch with define */
    uint8_t dmmb;           /* rename for xc8 to avoid mismatch with define */
    uint8_t eot1a;          /* rename for xc8 to avoid mismatch with define */
    uint8_t eot1b;          /* rename for xc8 to avoid mismatch with define */
    uint8_t eot2a;          /* rename for xc8 to avoid mismatch with define */
    uint8_t eot2b;          /* rename for xc8 to avoid mismatch with define */
    uint8_t eot3a;          /* rename for xc8 to avoid mismatch with define */
    uint8_t eot3b;          /* rename for xc8 to avoid mismatch with define */
    uint8_t fealr_feant;    /* rename for xc8 to avoid mismatch with define */
    uint8_t feat;           /* rename for xc8 to avoid mismatch with define */
    uint8_t fepac;          /* rename for xc8 to avoid mismatch with define */
    uint8_t fevco;          /* rename for xc8 to avoid mismatch with define */
    uint8_t fevct;          /* rename for xc8 to avoid mismatch with define */
    uint8_t FREQoffset[2];
    uint8_t txDevA[2];
    uint8_t txDevB[2];
    uint8_t gacdiva[2];     /* rename for xc8 to avoid mismatch with define */
    uint8_t gacdivb[2];     /* rename for xc8 to avoid mismatch with define */
    uint8_t IF[2];
    uint8_t rdocr;          /* rename for xc8 to avoid mismatch with define */
    uint8_t rssiSysConf;
    uint8_t rxSetPathA[2];
    uint8_t rxSetPathB[2];
    uint8_t rxSysEvent;
    uint8_t rxSysSet;
    uint8_t sfida[4];       /* rename for xc8 to avoid mismatch with define */
    uint8_t sfidb[4];       /* rename for xc8 to avoid mismatch with define */
    uint8_t sfidca;         /* rename for xc8 to avoid mismatch with define */
    uint8_t sfidcb;         /* rename for xc8 to avoid mismatch with define */
    uint8_t sfidla;         /* rename for xc8 to avoid mismatch with define */
    uint8_t sfidlb;         /* rename for xc8 to avoid mismatch with define */
    uint8_t sot1a;          /* rename for xc8 to avoid mismatch with define */
    uint8_t sot1b;          /* rename for xc8 to avoid mismatch with define */
    uint8_t sot2a;          /* rename for xc8 to avoid mismatch with define */
    uint8_t sot2b;          /* rename for xc8 to avoid mismatch with define */
    uint8_t SOTtimeOutA;
    uint8_t SOTtimeOutB;
    uint8_t syca;           /* rename for xc8 to avoid mismatch with define */
    uint8_t sycb;           /* rename for xc8 to avoid mismatch with define */
    uint8_t fsfcra;         /* rename for xc8 to avoid mismatch with define */
    uint8_t fsfcrb;         /* rename for xc8 to avoid mismatch with define */
    uint8_t tmul;           /* rename for xc8 to avoid mismatch with define */
    uint8_t trxSysConf;
    uint8_t txdra[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t txdrb[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t txSetPathA[2];
    uint8_t txSetPathB[2];
    uint8_t txSysEventA;
    uint8_t txSysEventB;
    uint8_t txPreambleSysEventA;
    uint8_t txPreambleSysEventB;
    uint8_t WCOtimeOutA;
    uint8_t WCOtimeOutB;
    uint8_t wupa[4];        /* rename for xc8 to avoid mismatch with define */
    uint8_t wupb[4];        /* rename for xc8 to avoid mismatch with define */
    uint8_t wupla;          /* rename for xc8 to avoid mismatch with define */
    uint8_t wuplb;          /* rename for xc8 to avoid mismatch with define */
    uint8_t wupta;          /* rename for xc8 to avoid mismatch with define */
    uint8_t wuptb;          /* rename for xc8 to avoid mismatch with define */
    uint8_t rxcpa[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t rxcia[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t rxsba;          /* rename for xc8 to avoid mismatch with define */
    uint8_t rxtla[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t rxcpb[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t rxcib[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t rxsbb;          /* rename for xc8 to avoid mismatch with define */
    uint8_t rxtlb[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t rxbc1;          /* rename for xc8 to avoid mismatch with define */
    uint8_t tmcr2a;         /* rename for xc8 to avoid mismatch with define */
    uint8_t tmcr2b;         /* rename for xc8 to avoid mismatch with define */
    uint8_t tmssca;         /* rename for xc8 to avoid mismatch with define */
    uint8_t tmsscb;         /* rename for xc8 to avoid mismatch with define */
    uint8_t tmtla[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t tmtlb[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t tmcpa[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t tmcpb[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t tmcia[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t tmcib[2];       /* rename for xc8 to avoid mismatch with define */
    uint8_t tmcsba;         /* rename for xc8 to avoid mismatch with define */
    uint8_t tmcsbb;         /* rename for xc8 to avoid mismatch with define */
    uint8_t rssc;           /* rename for xc8 to avoid mismatch with define */
}sServiceSpecificConfiguration;

typedef struct{
    uint8_t ffreq[3];       /* rename for xc8 to avoid mismatch with define */
    uint8_t fems;           /* rename for xc8 to avoid mismatch with define */
    uint8_t fecr;           /* rename for xc8 to avoid mismatch with define */
}sChannelSpecificConfiguration;

typedef struct{
    sServiceSpecificConfiguration  service;
    sChannelSpecificConfiguration channel[3];
}sServiceConfiguration;

typedef struct{
    sServiceSpecificConfiguration  service;
    sChannelSpecificConfiguration channel;
}sCurrentServiceConfiguration;

typedef struct{
    uint8_t confFEBIA;
    uint8_t confFEBT;
    uint8_t confFELNA;
    uint8_t confFELNA2;
    uint8_t confFETN4;
    uint8_t confFEVCOoffset;
}sFacLock;

typedef struct{
    uint8_t errorCode;
    uint8_t ssmErrorCode;
}sDebug;

typedef struct {
    uint8_t config;
    svcChConfig_t svcChConfig;
}sPollingChannelConfig;

// #pragma location = 0x001B       /* GPIOR3 */
// __io __no_init uint8_t sysStatus;
extern uint8_t sysStatus;
//
// #pragma location = 0x001C       /* GPIOR4 */
// __io __no_init uint8_t trxStatus;
extern uint8_t trxStatus;
//
// #pragma location = 15           /* R15 */
// __regvar __no_init uint8_t events_system;
extern uint8_t events_system;
//
// #pragma location = 14           /* R14 */
// __regvar __no_init volatile uint8_t events_events;
extern volatile uint8_t events_events;
//
// #pragma location = 13           /* R13 */
// __regvar __no_init volatile uint8_t events_power;
extern volatile uint8_t events_power;
//
// #pragma location = 12           /* R12 */
// __regvar __no_init volatile uint8_t events_config;
extern volatile uint8_t events_config;

typedef struct{
    uint8_t data[4];
    uint8_t config;
}sId;

typedef struct{
    uint8_t rssl;       /* rename for xc8 to avoid mismatch with define */
    uint8_t rssh;       /* rename for xc8 to avoid mismatch with define */
}sRssi;

typedef struct{
    uint8_t rssi[3];
    uint8_t flags;
}sSubChanneling;

typedef struct
{
    uint8_t antennaSwitchingMask;
    uint8_t antennaSwitchingPattern;
}sEEPromServiceChannelSwitchConfig;

typedef struct
{
    uint8_t bestChannelPollingIndex;
    uint8_t bestChannelServiceChannelConfig;
}sSramPollingChannelStatistics;


#elif defined __IAR_SYSTEMS_ASM__
#endif /* __IAR_SYSTEMS_ASM__ */

#endif /* GLOBALS_TYPES_H */