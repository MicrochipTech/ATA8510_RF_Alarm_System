/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/globals/src/globals.c $
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
#include "../../stdc/src/stdc.h"
#include "../../eep/src/eep.h"
#include "../../rf/src/rf.h"
#include "../../rfpolling/src/rfpolling.h"
#include "../../system/src/system.h"
#include "globals.h"
#include "../../calib/src/calib.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/** \brief <b>COPY_SERVICE_AND_CHANNEL_FROM_EEPROM</b> is used as define to
    copy complete service and channel information from EEPROM
 */
#define COPY_SERVICE_AND_CHANNEL_FROM_EEPROM    (uint8_t)0x81U
/** \brief <b>COPY_CHANNEL_ONLY_FROM_EEPROM</b> is used as define to
    copy only channel information from EEPROM
 */
#define COPY_CHANNEL_ONLY_FROM_EEPROM           (uint8_t)0x41U
/** \brief <b>COPY_SERVICE_AND_CHANNEL_FROM_SRAM</b> is used as define to
    copy complete service and channel information from SRAM
 */
#define COPY_SERVICE_AND_CHANNEL_FROM_SRAM      (uint8_t)0x80U
/** \brief <b>COPY_CHANNEL_ONLY_FROM_SRAM</b> is used as define to
    copy only channel information from SRAM
 */
#define COPY_CHANNEL_ONLY_FROM_SRAM             (uint8_t)0x40U

/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/
/** \brief <b>trxConf</b>
    contains the transceiver configuration information/setting.
*/
#pragma location = ".trxram"
__no_init sTrxConfig trxConf;

/** \brief <b>events</b>
    contains the event information/setting.
*/
#pragma location = ".eventram"
__no_init volatile sEventData events;

/** \brief <b>tmpAryApp</b>
    used as scratch memory e.g. for block read from EEPROM.
*/
#pragma location = ".aryram"
__no_init uint8_t tmpAryApp[10];

/** \brief <b>extReq</b>
    contains information for controlling external commands/requests.
*/
#pragma location = ".extreq"
__no_init sExtReq extReq;

/** \brief <b>triggerEEPwr</b>
    contains information for EEPROM secure write access.
*/
#pragma location = ".eeptrig"
__no_init sTriggerEEP triggerEEPwr;

/** \brief <b>sleepModeConfig</b>
    contains settings for the sleep mode feature.
    \li Bit 7: firmware sleep mode enable flag
    \li Bit 6: rfu
    \li Bit 5: rfu
    \li Bit 4: rfu
    \li Bit 3..1: sleep mode
        - 0: idle
        - 1: extended power-save
        - 2: power-save
        - 3: power-down
    \li Bit 0: activityFlag
*/
#pragma location = ".sleep"
__no_init uint8_t sleepModeConfig;

/** \brief <b>currentService</b>
    contains the current service configuration in the SRAM used by the firmware.
*/
#pragma location = ".currentservice"
__no_init sCurrentServiceConfiguration currentService;

/** \brief <b>sramServices</b>
    contains the service configuration in the SRAM (could be modified via ext. uC).
*/
#pragma location = ".sramservices"
__no_init sServiceConfiguration sramServices[NUM_SRAM_SERVICES];

/** \brief <b>facLock</b>
    contains a copy in SRAM of some factory locked registers.
*/
#pragma location = ".faclock"
__no_init sFacLock facLock;

/** \brief <b>debug</b>
    contains the last error codes for system error and ssm error.
*/
#pragma location = ".debug"
__no_init sDebug debug;

/** \brief <b>rssiThresholds</b>
    contains the RSSI thresholds for each channel.
*/
#pragma location = ".rssi"
__no_init sRssi rssiThresholds[NUM_SERVICES][NUM_CHANNELS_PER_SERVICE];

/** \brief <b>rssiAtWcok</b>
    contains the RSSI average values for each channel. Measured at WCOK
*/
#pragma location = ".rssi"
__no_init uint8_t rssiAtWcok[NUM_SERVICES][NUM_CHANNELS_PER_SERVICE];

/** \brief <b>frequencyOffsetAtWcok</b>
    contains the detected frequencyOffset at WCOK.
*/
#pragma location = ".freq"
__no_init uint8_t frequencyOffsetAtWcok;

/** \brief <b>subChan</b>
    contains the measured RSSI values determined during subchanneling.
*/
#pragma location = ".subchan"
__no_init sSubChanneling subChan;


/** \brief <b>rxIrqEvents</b>
    contains the interrupt mask configuration of RDSIMR register
    for RXMode and PollingMode
    \li rxIrqEvents[0]: RDSIMR configuration before WCOA/B
    \li rxIrqEvents[1]: RDSIMR configuration after WCOA/B
    \li rxIrqEvents[2]: RDSIMR configuration after SOTA/B
*/
#pragma location = ".rxirqevents"
__no_init uint8_t rxIrqEvents[3];

/* -- SIX-2608 -- */
/** \brief <b>sramServiceChannelSwitchConfig</b>
    contains the channel switch service configuration in the SRAM,
    which could be modified via ext. uC.
*/
#pragma location = ".sramservicechannelswitchconfig"
__no_init sEEPromServiceChannelSwitchConfig sramServiceChannelSwitchConfig[NUM_SRAM_SERVICES];

/* -- SIX-1509 -- */
/** \brief <b>sramPollingChannelStatistics</b>
    contains the best channel computation result,
    which could be read by an ext. uC.
*/
#pragma location = ".srampollingchannelstatistics"
__no_init sSramPollingChannelStatistics sramPollingChannelStatistics;

/** \brief <b>lowestRssiOfCurPolCycle</b>
    contains the temporary RSSI value of the Best Channel of the 
    current polling loop.
*/
#pragma location = ".srampollingchannelstatistics"
__root __no_init uint8_t lowestRssiOfCurPolCycle;

/** \brief <b>tempBestChannelPollingIndex</b>
    contains the polling index of the Best Channel of the 
    current polling loop.
*/
#pragma location = ".srampollingchannelstatistics"
__root __no_init uint8_t tempBestChannelPollingIndex;

/** \brief <b>tempBestChannelServiceChannelConfig</b>
    contains the service and channel number of the Best Channel of the 
    current polling loop.
*/
#pragma location = ".srampollingchannelstatistics"
__root __no_init uint8_t tempBestChannelServiceChannelConfig;
/* -- SIX-1509 -- */

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_setClk_C</b>
    does the basic system clock settings.

    \param val - value written to CLPR register

    \return none

    \image html ATA_setClk_C.png
    \image rtf ATA_setClk_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_setClk_C(uint8_t val)
{
    uint8_t sreg;
    sreg = SREG;
    __disable_interrupt();
    CLPR = BM_CLPCE;
    CLPR = val;
    SREG = sreg;
}
/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_wdtDisable_C</b>
    disables the watchdog timer.

    \return none

    \image html ATA_wdtDisable_C.png
    \image rtf ATA_wdtDisable_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_wdtDisable_C(void)
{
    uint8_t sreg;
    sreg = SREG;
    __disable_interrupt();
    MCUSR &= (uint8_t)(~BM_WDRF);
    WDTCR = (BM_WDCE | BM_WDE);
    WDTCR = (BM_WDPS2 | BM_WDPS1 | BM_WDPS0);
    SREG = sreg;
}
/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_wdtEnable_C</b>
    enables the watchdog timer according to EEPROM configuration.

    \return none

    \image html ATA_wdtEnable_C.png
    \image rtf ATA_wdtEnable_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_wdtEnable_C(void)
{
    uint8_t wdtcr;
    uint8_t sreg;
    T0CR  = ATA_eepRDbyte_ASM(&eepWdtConf.confT0CR);
    T0IFR = ATA_eepRDbyte_ASM(&eepWdtConf.confT0IFR);
    wdtcr = ATA_eepRDbyte_ASM(&eepWdtConf.confWDTCR);
    sreg = SREG;
    _CLI;
    WDTCR |= (BM_WDCE | BM_WDE);
    WDTCR = wdtcr;
    WDTCR = wdtcr; /* must be re-written as enabling and setting the prescaler at the same time is not possible */
    SREG = sreg;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_SleepMode_C</b>
    is used to set the system to sleep in PollingMode and IDLEMode.

    \return none

    \image html ATA_SleepMode_C.png
    \image rtf ATA_SleepMode_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_SleepMode_C(void)
{
    if(sleepModeConfig & BM_SLEEP_MODE_CONFIG_ENABLE) {
        if (flowCtrl.pLut == 0x0000U) {
            if ( (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM) == OPM_IDLE ) {
                ATA_Sleep_C();
            }
            else if ( (trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM) == OPM_POLLING ) {
                ATA_Sleep_C();
            }
            else {
                /* no SLEEP during RX and TX */
            }
        }
        else {
            /* SW state machines in progress --> goto SLEEP Idle if possible */
            if (sysStatus & BM_SYS_STATUS_SSM_SLEEP_ENABLE) {
                /* set sleep to IdleMode */
                SMCR = 0x00U;

                ATA_Sleep_C();
                /* set to default sleep mode and disable sleep */
                SMCR = sleepModeConfig & (BM_SM0 | BM_SM1 | BM_SM2);
                /* reset sw state machine enable flag */
                sysStatus &= (uint8_t)~BM_SYS_STATUS_SSM_SLEEP_ENABLE;
            }
            else {
                /* if no State Machine Sleep enabled --> do nothing */
            }
        }
    }
    else {
        /* Sleep disabled */
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_Sleep_C</b>
    does the sleep register setting.

    \return none

    \image html ATA_Sleep_C.png
    \image rtf ATA_Sleep_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_Sleep_C(void)
{
    _CLI;
    if (    ( sysStatus & (BM_SYS_STATUS_TRIGGER_MAIN_LOOP | BM_SYS_STATUS_SPI_CMD_IN_PROGRESS) )
         || ( DBCR & BIT_MASK_3 )
       ) {
        _SEI;
    }
    else {
        SMCR |= BM_SE;
        _SEI;
        _SLEEP;
        SMCR &= (uint8_t)~BM_SE;
    }
    sysStatus &= (uint8_t)~BM_SYS_STATUS_TRIGGER_MAIN_LOOP;
}

/*-----------------------------------------------------------------------------*/
/** \brief <b>ATA_currentServiceInit_C</b>
    initializes currentService variable.

    \param config - service/channel configuration to be loaded

    \return none

    \image html ATA_currentServiceInit_C.png
    \image rtf ATA_currentServiceInit_C.png
    \n
*/
/*-----------------------------------------------------------------------------*/
VOIDFUNC ATA_currentServiceInit_C(svcChConfig_t config)
{
    uint8_t tmp     = 0U;
    uint8_t *dstPtr = (uint8_t *)0x0000U;
    uint8_t *srcPtr = (uint8_t *)0x0000U;

    uint8_t serviceNumber = config & BM_SVC_CH_CONFIG_SER;
    uint8_t channelNumber = config & BM_SVC_CH_CONFIG_CH;
    channelNumber >>= 4;

    if( serviceNumber >= NUM_SERVICES )
    {
        serviceNumber = 0U; // default service is service[0] from EEPROM
    }
    else{}

    if( channelNumber >= NUM_CHANNELS_PER_SERVICE )
    {
        channelNumber = 0U; // default channel is channnel[0] from EEPROM
    }
    else{}

    if( serviceNumber != (trxConf.lastServiceChannelConfig & BM_SVC_CH_CONFIG_SER) )
    {
        tmp = 0x80U;    // indicate new service and channel must be copied
    }
    else if( (trxConf.lastServiceChannelConfig & BM_SVC_CH_CONFIG_CH) != (config & BM_SVC_CH_CONFIG_CH) )
    {
        tmp = 0x40U;    // indicate only new channel must be copied
    }
    else{}

    if( serviceNumber < NUM_EEPROM_SERVICES )
    {
        tmp |= 0x01U;   // indicate copy actions from EEPROM
    }
    /*lint --e{662} GeWi (23nov11) suppress "Possible creation of out-of-bounds pointer ..." --> bounds checked in if..else before */
    switch( tmp )
    {
        case COPY_SERVICE_AND_CHANNEL_FROM_EEPROM:
        {   // copy service from EEPROM, required time ~115us (not FRC worst case)
            dstPtr = (uint8_t *)&currentService.service;
            srcPtr = (uint8_t *)&eepServices[serviceNumber].service;
            ATA_copyEepSvc_ASM(dstPtr, srcPtr);

        }
        //lint -fallthrough
        case COPY_CHANNEL_ONLY_FROM_EEPROM:
        {   // copy channel from EEPROM, required time ~25us (not FRC worst case)
            dstPtr = (uint8_t *)&currentService.channel;
            srcPtr = (uint8_t *)&eepServices[serviceNumber].channel[channelNumber];
            ATA_copyEepChannel_ASM(dstPtr, srcPtr);
            break;
        }
        case COPY_SERVICE_AND_CHANNEL_FROM_SRAM:
        {   // copy service from SRAM, required time ~134us (not FRC worst case)
            dstPtr = (uint8_t *)&currentService.service;
            srcPtr = (uint8_t *)&sramServices[serviceNumber - NUM_EEPROM_SERVICES].service;
            ATA_copySramSvc_ASM(dstPtr, srcPtr);

        }
        //lint -fallthrough
        case COPY_CHANNEL_ONLY_FROM_SRAM:
        {   // copy channel from SRAM, required time ~26us (not FRC worst case)
            dstPtr = (uint8_t *)&currentService.channel;
            srcPtr = (uint8_t *)&sramServices[serviceNumber - NUM_EEPROM_SERVICES].channel[channelNumber];
            ATA_copySramChannel_ASM(dstPtr, srcPtr);
            break;
        }
        default:
        {
            // no changes on service and/or channel configuration
        }
    }
    /*lint -restore*/

    // set new service/channel configuration active
    trxConf.lastServiceChannelConfig = config;

    /* set events variable according to current configuration */
    events_config = config;
}


/*-----------------------------------------------------------------------------*/
/** \brief <b>ATA_initPollingConfiguration_C</b>
    gets the Timer1 configuration and initializes polling configuration array.

    \return none

    \image html ATA_initPollingConfiguration_C.png
    \image rtf ATA_initPollingConfiguration_C.png
    \n
*/
/*-----------------------------------------------------------------------------*/
VOIDFUNC ATA_initPollingConfiguration_C(void)
{
    ATA_eepRDblock_C((uint8_t *)&eepPollLoopConf.confT1COR, (uint8_t)sizeof(pollConfig), (uint8_t *)&pollConfig.confT1COR);

    // Polling Cycle Timing Basic Init
    calib.srcRes    = (uint8_t)pollConfig.confT1COR;
    calib.srcCorVal = calib.srcRes;
}

/*-----------------------------------------------------------------------------*/
/** \brief <b>ATA_initRssiConfiguration_C</b>
    initializes the RSSI configuration array.

    \return none

    \image html ATA_initRssiConfiguration_C.png
    \image rtf ATA_initRssiConfiguration_C.png
    \n
*/
/*-----------------------------------------------------------------------------*/
VOIDFUNC ATA_initRssiConfiguration_C(void)
{
    /* rssiThresholds[svc][ch].RSSL = 0x00U is already done with SRAM initialization */

    for (uint8_t svc = 0U; svc < NUM_SERVICES; svc++) {
        rssiThresholds[svc][0U].RSSH = 0x0FFU;
        rssiThresholds[svc][1U].RSSH = 0x0FFU;
        rssiThresholds[svc][2U].RSSH = 0x0FFU;
    }

    /* rssiAtWcok[svc][ch] = 0x00U is already done with SRAM initialization */
}

/*-----------------------------------------------------------------------------*/
/** \brief <b>ATA_initFacLockedArea_C</b>
    initialize facLock variable.

    \return none

    \image html ATA_initFacLockedArea_C.png
    \image rtf ATA_initFacLockedArea_C.png
    \n
*/
/*-----------------------------------------------------------------------------*/
VOIDFUNC ATA_initFacLockedArea_C(void)
{
    ATA_eepRDblock_C((uint8_t *)&eepFacLock.confFEBIA, (uint8_t)sizeof(facLock), (uint8_t *)&facLock.confFEBIA);
}

/*-----------------------------------------------------------------------------*/
/**  \brief <b>ATA_clkSwitchFRC_C</b>
    switches the AVR core to be clocked with FRC. Keep prescaler
    settings in mind.

    \return none

    \image html ATA_clkSwitchFRC_C.png
    \image rtf ATA_clkSwitchFRC_C.png
    \n
*/
/*-----------------------------------------------------------------------------*/
VOIDFUNC ATA_clkSwitchFRC_C(void)
{
    uint8_t cmcr = CMCR & 0xF0U;
    CMOCR |= BM_FRCAO;
    do {
        _NOP;
    } while((CMOCR & BM_FRCACT) == 0U);

    __disable_interrupt();
    CMCR = BM_CMCCE;
    CMCR = cmcr;
    __enable_interrupt();

    /* set divider to 1 */
    __disable_interrupt();
    CLPR = BM_CLPCE;
    CLPR = BM_CLTPS0;
    __enable_interrupt();

    // --SIX-3293-- CMOCR = (trxConf.systemConfig >> 4) & BM_FRCAO;
    CMOCR = (trxConf.systemConfig >> 4) & (BM_SRCAO | BM_FRCAO);
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_initChannelSwitchForCurrentService_C</b>
    Apply channel switch configuration to PORTC for the currently selected service.
    Depending on the selected service, either the given EEPROM or SRAM service
    is used.

    \return none

    \image html ATA_initChannelSwitchForCurrentService_C.png
    \image rtf ATA_initChannelSwitchForCurrentService_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_initChannelSwitchForCurrentService_C(void)
{
    uint8_t serviceNumber = trxConf.serviceChannelConfig & BM_SVC_CH_CONFIG_SER;
    uint8_t mask = 0U;
    uint8_t pattern = 0U;
    
    /* Check if number of services stated in trxConf.serviceChannelConfig is valid. */
    if( serviceNumber >= NUM_SERVICES )
    {
        serviceNumber = 0U; // default service is service[0] from EEPROM
        mask = ATA_eepRDbyte_ASM(&eepServiceChannelSwitchConfig[serviceNumber].antennaSwitchingMask);
        pattern = ATA_eepRDbyte_ASM(&eepServiceChannelSwitchConfig[serviceNumber].antennaSwitchingPattern);
    }
    else if ( serviceNumber >= NUM_EEPROM_SERVICES )
    {
        serviceNumber = serviceNumber - NUM_EEPROM_SERVICES; // get values from SRAM services
        mask = sramServiceChannelSwitchConfig[serviceNumber].antennaSwitchingMask;
        pattern = sramServiceChannelSwitchConfig[serviceNumber].antennaSwitchingPattern;
    }
    else
    {
        mask = ATA_eepRDbyte_ASM(&eepServiceChannelSwitchConfig[serviceNumber].antennaSwitchingMask);
        pattern = ATA_eepRDbyte_ASM(&eepServiceChannelSwitchConfig[serviceNumber].antennaSwitchingPattern);
    }

    /* Only write pattern bits of the current service where the corresponding mask bit is set to zero to PORTC. */
    PORTC = (PORTC & mask) | ((uint8_t)(~mask) & pattern);
}
