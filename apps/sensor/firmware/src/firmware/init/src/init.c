/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/init/src/init.c $
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

/** \file init.c
    this package does the wakeup detection and the system initialization
    according to the EEPROM settings.
*/

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "../../eep/src/eep.h"
#include "../../extif/src/extif.h"
#include "../../globals/src/globals.h"
#include "../../rf/src/rf.h"
#include "../../rfrx/src/rfrx.h"
#include "../../rftx/src/rftx.h"
#include "../../timer1/src/timer1.h"
#include "../../timer2/src/timer2.h"
#include "../../timer3/src/timer3.h"
#include "../../timer4/src/timer4.h"
#include "../../calib/src/calib.h"
#include "../../system/src/system.h"
#include "init.h"
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
/** \brief <b>ATA_initIoConfig_C</b>
    is used to do a basic I/O configuration at system start according to EEPROM
    settings.

    The following registers are initialized with the content of EEPROM variable
    eepIO:
        - PORTB
        - PORTC
        - DDRB
        - DDRC
        - PCICR
        - PCMSK0
        - PCMSK1
        - MCUCR

    \return none

    \image html ATA_initIoConfig_C.png
    \image rtf ATA_initIoConfig_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_initIoConfig_C(void)
{
    ATA_eepRDblock_C(&eepIO.confDDRB,(uint8_t)sizeof(sEEPromIOConfig),&tmpAryApp[0]);
    PORTB  = tmpAryApp[6];
    PORTC  = tmpAryApp[7];

    DDRB   = tmpAryApp[0];
    DDRC   = tmpAryApp[1];

    PCICR  = tmpAryApp[3];
    PCMSK0 = tmpAryApp[4];
    PCMSK1 = tmpAryApp[5];

    MCUCR  = tmpAryApp[2];
    MCUCR |= BM_ENPS;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_defaultIoConfig_C</b>
    is used to do a basic I/O configuration at system start if EEPROM content
    is not valid.

    \return none

    The IO registers are initialized as follows:
        - PORTC = 0x3F
        - PORTB = 0x00
        - DDRC  = 0x00
        - DDRB  = 0xC9\n

    Comment:
        - PORT = '1' -> internal pull-up
        - PORT = '0' -> internal pull-down
        - DDR  = '1' -> output
        - DDR  = '0' -> input

    \image html ATA_defaultIoConfig_C.png
    \image rtf ATA_defaultIoConfig_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_defaultIoConfig_C(void)
{
    /* all PortC pins are input tri-stated */
    PORTC = (uint8_t)0x3F;
    /* PortB has SPI I/O settings, ext. Event Pin as output */
    PORTB = (uint8_t)0x00;
    DDRC = (uint8_t)0x00;
    DDRB = (uint8_t)0xC9; /* MISO, SCK, Event and RX_Active pin as output */

    MCUCR |= BM_ENPS;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_systemInit_C</b>
    does the main system initialization.

    If the EEPROM content is valid (checked with EEPROM variable eepConfValid.confVal[1..]),
    the system initialization is done according to the EEPROM setting for:
        - ATA_initExtif_C: does the initialization of extif software module
        - ATA_initIOConfig_C: does the IO configuration according to EEPROM settings
        - ATA_wdtEnable_C: enables the watchdog
        - ATA_initPollingConfiguration_C: initializes the system for PollingMode
        - ATA_initRssiConfiguration_C: initializes the RSSI feature of the system
        - ATA_doInitialization_C: initialization of SW state machine, calibration at start-up ...
        - ATA_initPureRx_C: initialization of pureRx feature of the system
    After the initialization is completed, the SW sets SYS_RDY event in events_system and
    sets the event pin if configured.

    If the EEPROM content is invalid, the SW does a basic initialization to ensure
    SPI communication. The following fucntions are used in this case:
        - ATA_defaultIOConfig_C: does the default IO configuration
        - ATA_SpiOpen_C: configures the SPI to ensure communication

    \param pBisr function pointer for PC int on portB
    \param pCisr function pointer for PC int on portC
    \param i0isr function pointer for irq on int0

    \return SUCCESS if EEPROM content is valid. Otherwise FAIL.

    \image html ATA_systemInit_C.png
    \image rtf ATA_systemInit_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
UINT8FUNC ATA_systemInit_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr)
{
    uint8_t retVal = OK;

    /* Default EEPROM settings used for different application types exceeds the
       unprotected EEPROM memory space (0x00 - 0xFF). For that reason, protected
       EEPROM memory locations (WP0 ... WP3) are enabled. */
    EEPR = (BM_EEAP3 | BM_EEAP2 | BM_EEAP1 | BM_EEAP0);

    /*
     * FIFO initialization
     */
    PRR2 &= (uint8_t)~(BM_PRDF | BM_PRSF); // power up FIFOs
    DFI |= BM_DFERIM;            // Enable Over-/Underflow IRQ for DFifo
    SFI |= BM_SFERIM;            // Enable Over-/Underflow IRQ for SFifo

    /* check if EEPROM configuration is valid */
    if( !((ATA_eepRDbyte_ASM(&eepConfValid.confVal)&BM_EEP_CONFIGVALID_CONFVAL_NVAL) == BM_EEP_CONFIGVALID_CONFVAL_NVAL1) )
    {
        ATA_defaultIoConfig_C();
        PRR0   &= (uint8_t)~BM_PRCO;
        CLKOD   = (uint8_t)0x0A;
        CLKOCR  = BM_CLKOEN;

        (void)ATA_SpiOpen_C(SpiMode0,(uint8_t)SPIIRQon,SPIMSB);
        retVal = FAIL;
    }
    else{
        uint8_t temp = 0U;
        uint8_t idleSelector = ATA_eepRDbyte_ASM(&eepTrxConf.sysStartConf);
        if( idleSelector & BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR ) {
            SUPCR |= BM_AVEN;
        }

        /* does the initialization according to eepConfValid and eepTrxConf */
        ATA_initExtIf_C(pBisr, pCisr, i0isr);
        ATA_initIoConfig_C();
        ATA_wdtEnable_C();
        ATA_initPollingConfiguration_C();
        ATA_initRssiConfiguration_C();
        ATA_doInitialization_C();

        temp = ATA_eepRDbyte_ASM(&eepConfValid.confVal);
        /* if EEPROM configuration is set to enable the pure RXMode */
        if( temp & BM_EEP_CONFIGVALID_CONFVAL_PURERXMODE )
        {
            // check if SPI communication is disabled for pure RXMode
            if( !(temp & BM_EEP_CONFIGVALID_CONFVAL_ENSPIPURERXMODE) )
            {
                /* --SIX-3361-- */
                /* --SIX-3370-- */
                // ATA_SpiClose_ASM();
                ATA_spiClose_C();
                /* --SIX-3370-- */
                /* --SIX-3361-- */
            }

            /* --SIX-3232-- */
            __disable_interrupt();
            trxConf.systemModeConfig     = extReq.systemModeConfig;
            extReq.systemModeConfig      = 0U;
            trxConf.serviceChannelConfig = extReq.serviceChannelConfig;
            extReq.serviceChannelConfig  = 0U;
            __enable_interrupt();
            /* --SIX-3232-- */
            
            trxConf.systemConfig |= BM_TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA;
            // enable Int0 for triggering the enable and disable of pure RX
            
            /* --SIX-3370-- */
            /* --SIX-3369-- */
            // extIf.irqInt0   = ATA_pureRxModeCtrl_ASM;
            extIf.irqInt0   = ATA_pureRxModeCtrl_v212_ASM;
            /* --SIX-3369-- */
            /* --SIX-3370-- */
            
            EIFR   = (uint8_t)0x01;
            EICRA |= (uint8_t)0x01;
            EIMSK |= (uint8_t)0x01;
            /* --SIX-3370-- */
            /* --SIX-3369-- */
            // ATA_pureRxModeCtrl_ASM();
            ATA_pureRxModeCtrl_v212_ASM();
            /* --SIX-3369-- */
            /* --SIX-3370-- */
        }

        // set SYS_RDY event flag
        // set PWRON/NPWRON event pin
        events_system |= BM_EVENTS_SYSTEM_SYS_RDY;
        temp  = events_power;
        temp &= events.pinEventMask;
        if( (events.sysEventMask & BM_SYS_EVENT_CONFIG_SYS_RDY) || temp ) {
            ATA_setEventPin_ASM();
        }
    }
    return retVal;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_doInitialization_C</b>
    does the initialisation of SW state machine, calibration at startup ...

    The SW initializes according to the EEPROM settings the following parts:
        - Clock setting
        - SPI
        - RX_ACTIVE and EventPin
        - Debouncing and DebugSwitch
        - SRAM services
        - SW state machines
        - Sleep mode configuration
        - System calibration at system startup
        - ...

    \return none

    \image html ATA_doInitialization_C.png
    \image rtf ATA_doInitialization_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_doInitialization_C(void)
{
    initFuncPtr ptr;
    uint16_t    tmp;
    uint8_t     dordSpi, modeSpi;
    uint8_t     serviceInit;

    uint8_t clkConfig = ATA_eepRDbyte_ASM(&eepTrxConf.clkConfig);
    uint8_t spiConfig = ATA_eepRDbyte_ASM(&eepTrxConf.spiConfig);
    uint8_t sysConfig = ATA_eepRDbyte_ASM(&eepTrxConf.sysConfig);

    if( sysConfig & BM_EEP_TRXCONF_SYSCONFIG_VS22V ) {
        SUPCA1 = ATA_eepRDbyte_ASM(&eepVsPa.SUPCA1);
    }

    /*
     * Clock initialization
     * set CMOCR.FRCAO and CMOCR.SRCAO according to EEPROM configuration
     */
    CMOCR = (clkConfig >> 4) & 0x03U;

    /*
     * SPI initialization
     */
    dordSpi = spiConfig&(uint8_t)0x80;
    dordSpi = dordSpi >> 7;
    modeSpi = spiConfig&(uint8_t)0x60;
    modeSpi = modeSpi >> 3;

    (void)ATA_SpiOpen_C((eSpiModi)modeSpi,(uint8_t)SPIIRQon,dordSpi);

    /* default setting for service/channel and tune/check configuration */
    /* trxConf intialization to 0x00U is already done in SRAM initialization */
    trxConf.lastServiceChannelConfig = 0xFFU;

    /*
     * EVENT pin initialization
     */
    ATA_eepRDblock_C((uint8_t *)&eepEventConf.pinEventConf, (uint8_t)sizeof(eepEventConf), (uint8_t *)&events.pinEventMask);
    // eventCopy[4] and eventCtrl is already initialized with 0 due to SRAM initialization

    DDRB |= BM_DDRB6;
    if( events.sysEventMask & BM_SYS_EVENT_CONFIG_EVENTPIN_POL ) {
        PORTB &= (uint8_t)~BM_PORTB6;  // EVENTPIN_POL = 1 --> high active
    }
    else {
        PORTB |= BM_PORTB6;            // EVENTPIN_POL = 0 --> low active
    }

    /*
     * RX_ACTIVE initialization
     */
    if( events.sysEventMask & BM_SYS_EVENT_CONFIG_RX_ACTIVE_EN ) {
        DDRB |= BM_DDRB7;
        ATA_clrRxActive_ASM();
    }

    /*
     * Debug initialization
     */
    DBGSW = ATA_eepRDbyte_ASM(&eepDebug.DBGSW);

    /*
     * Debouncing initialization
     */
    ATA_eepRDblock_C((uint8_t *)&eepDebounce.DBCR, (uint8_t)sizeof(eepDebounce), (uint8_t *)&DBCR);

    /*
     * Clock Out initialization
     */
    if( clkConfig & BIT_MASK_2 ) {
        PRR0   &= (uint8_t)~BM_PRCO;
        CLKOD   = ATA_eepRDbyte_ASM(&eepTrxConf.clkOutDiv);
        CLKOCR  = clkConfig & (uint8_t)0x03;
        CLKOCR |= (uint8_t)(clkConfig & (uint8_t)0x04);
        DDRB   |= BM_DDRB0;
    }

    /*
     * TRX config initialization
     */
    trxConf.tuneCheckConfig      = ATA_eepRDbyte_ASM(&eepConfValid.confInitFlags) & 0xF0U;
    trxConf.systemModeConfig     = ATA_eepRDbyte_ASM(&eepTrxConf.sysStartConf);
    trxConf.serviceChannelConfig = ATA_eepRDbyte_ASM(&eepTrxConf.sysStartSvcChConfig);

    /* set idle mode selector and power supply 5V/3V bits */
    trxConf.systemConfig  = (sysConfig >> 4) & BM_TRXCONF_SYSTEM_CONFIG_VS5V_SELECTOR;
    trxConf.systemConfig |= (trxConf.systemModeConfig >> 3) & BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR;
    trxConf.systemConfig |= (uint8_t)(clkConfig & (uint8_t)0x30);
    trxConf.systemConfig |= sysConfig & (BM_TRXCONF_SYSTEM_CONFIG_SFIFO_OFL_UFL_RX_DISABLE | BM_TRXCONF_SYSTEM_CONFIG_DFIFO_OFL_UFL_RX_DISABLE);

    /*
     * IdScan status initialization
     */
    trxConf.idScanStatus = ATA_eepRDbyte_ASM(&eepID.idEna) & BM_SYS_IDS_ENABLED;

    /*
     * SRAM service initialization
     */
    serviceInit = ATA_eepRDbyte_ASM(&eepTrxConf.svcInitConf);
    if( serviceInit & BIT_MASK_3 ) {
        /* update of SRAM service 0 */
        extReq.serviceInitConfig  = serviceInit & (BIT_MASK_2 | BIT_MASK_1);
        extReq.serviceInitConfig |= BIT_MASK_7;
        ATA_serviceInitSwitching_C();
    }

    if( serviceInit & BIT_MASK_7 ) {
        /* update of SRAM service 1 */
        extReq.serviceInitConfig  = serviceInit >> 4U;
        extReq.serviceInitConfig &= (BIT_MASK_2 | BIT_MASK_1);
        extReq.serviceInitConfig |= BIT_MASK_7 | BIT_MASK_0;
        ATA_serviceInitSwitching_C();
    }

    ATA_initStateMachines_C();

    /* check for linked routine */
    tmp  = (uint16_t)ATA_eepRDbyte_ASM(&eepConfValid.funcPtr[0]);
    tmp  = tmp << 8;
    tmp |= (uint16_t)ATA_eepRDbyte_ASM(&eepConfValid.funcPtr[1]);

    /*lint -e923 GeWi (23nov2011)*/
    /* disable lint error 923 - Cast between pointer type and an integral type.
     * Misra Rule 11.3 says: Casting between a pointer and an integer type should be avoided where possible,
     * but may be unavoidable when addressing memory mapped registers or other hardware specific features.
     */
    ptr  = (initFuncPtr)tmp;
    _WDR;
    if( (ptr!=(initFuncPtr)0x0000) && (ptr!=(initFuncPtr)0xFFFF) ){
        ptr();
    }
    /*lint -restore */

    ATA_initFacLockedArea_C();

    /* SLEEP configuration */
    sleepModeConfig = ATA_eepRDbyte_ASM(&eepSleepMode.sleepModeConf);
    SMCR = sleepModeConfig;

    /* check for IDLEMode(RC)/IDLEMode(XTO) */
    if( trxConf.systemConfig & BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR )
    {   /* IDLEMode(XTO) */
        /*--> should be part of HW state machine */
        ATA_wait4avcc_C();
        ATA_switchIdleXTO_ASM();
    }

    /* run calibration routines at system start-up */
    if( trxConf.tuneCheckConfig & 0xF0U )
    {
        uint8_t idleModeSelector = trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR;
        uint8_t systemConfig     = trxConf.systemConfig;
        trxConf.systemConfig    |= BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR;

        if( idleModeSelector ){
            /* XTO already switched on */
        }
        else {
            trxConf.systemModeConfig |= BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR;
            ATA_checkAndSwitchIdleXTO_C();
        }

        ATA_systemCalibAtStartup_C();

        trxConf.systemModeConfig &= idleModeSelector;
        ATA_shutDownFe_C();

        trxConf.systemConfig = systemConfig;
    }

    extReq.systemModeConfig      = ATA_eepRDbyte_ASM(&eepTrxConf.sysStartConf);
    trxConf.systemModeConfig     = extReq.systemModeConfig & BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR;
    extReq.serviceChannelConfig  = ATA_eepRDbyte_ASM(&eepTrxConf.sysStartSvcChConfig);
    trxConf.serviceChannelConfig = 0U;
    if( (extReq.systemModeConfig & BM_SYS_MODE_CONFIG_OPM) == OPM_POLLING )
    {   /* start config OPM is PollingMode */
        extReq.serviceChannelConfig = 0U;   // start polling with array index 0
        sysStatus |= BM_SYS_STATUS_UPDATE;
    }
    else if( extReq.systemModeConfig & BM_SYS_MODE_CONFIG_OPM )
    {
        sysStatus |= BM_SYS_STATUS_UPDATE;
    }
    else {
        /* Start config OPM is IDLEMode */
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_checkWakeupSource_C</b>
    checks the status of the NPWRON/PWRON pins.

    This function checks the wake up conditions of the system.
    If a correct wakeup is detected, the wakeup source is signalled in events_power.
    If no wakeup source is detected, the system is set back to OFFMode.

    \return none

    \image html ATA_checkWakeupSource_C.png
    \image rtf ATA_checkWakeupSource_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_checkWakeupSource_C(void)
{
    uint8_t tmp8;

    /* get current events_power content */
    tmp8  = (uint8_t)(PINC >> 1) & (uint8_t)0x1F; /* PC1..5 */
    tmp8 |= (uint8_t)(((PINB & BM_PINB7) ? BM_EVENTS_POWER_NPWRON6 : 0x00U)); /* PB7 */
    tmp8 |= (uint8_t)(((PINB & BM_PINB4) ? BM_EVENTS_POWER_PWRON   : 0x00U)); /* PB4 */
    tmp8 ^= (uint8_t)0x3F; /* invert all NPWRON except PWRON and Debug Event */

    if( tmp8 )
    {   // wakeup event detected --> signal in event flags
        events_power = tmp8;
    }
    else
    {   // no wakeup event detected --> go back to off mode
        DDRB  = 0x00U;
        DDRC  = 0x00U;
        PORTB = 0xFFU;
        PORTC = 0xFFU;

        while(EECR & BM_NVMBSY){}

        SUPCR |= BM_DVDIS;
    }
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_initStateMachines_C</b>
    initializes the pointer for each SW state machine.

    This function does the pointer initialization for the SW state machines.
    If the SW state machine shall be patched by User Software, these pointers shall
    be overwritten after ATA_initStateMachines_C to enable usage of own SW state
    machines located in FLASH space.

    \return none

    \image html ATA_initStateMachines_C.png
    \image rtf ATA_initStateMachines_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_initStateMachines_C(void)
{
    pTxBufSysFlowStateMachine         = txBufFlowStateMachine;
    pTxTransSysFlowStateMachine       = txTransFlowStateMachine;
    pRxSysFlowStateMachine            = rxFlowStateMachine;
    pPollSysFlowStateMachine          = pollFlowStateMachine;
    pPureRxSysFlowStateMachine        = pureRxFlowStateMachine;
    pAntTuneSysFlowStateMachine       = anttuneFlowStateMachine;
    pVcoCalSysFlowStateMachine        = vcocalFlowStateMachine;
    pTempMeasSysFlowStateMachine      = tempmeasSysFlowStateMachine;
    pSelfCheckSysFlowStateMachine     = selfCheckSysFlowStateMachine;
    pRssiSysFlowStateMachine          = rssiFlowStateMachine;
    pSubChannelingSysFlowStateMachine = subChannelingSysFlowStateMachine;

    flowCtrl.msmstate = 0xFFU;
    flowCtrl.index    = 0U;
    flowCtrl.pLut     = 0x0000U;
}

/*----------------------------------------------------------------------------- */
/** \brief <b>ATA_systemCalibAtStartup_C</b>
    does the calibration at system start-up.

    This function does the calibration at system start-up according to the EEPROM
    setting in varible eepConfValid.confInitFlags[7..4].
    The following calibrations are available:
        -Antenna tuning
        - Temperature measurement
        - SRC calibration
        - FRC calibration

    \return none

    \image html ATA_systemCalibAtStartup_C.png
    \image rtf ATA_systemCalibAtStartup_C.png
    \n
*/
/*----------------------------------------------------------------------------- */
VOIDFUNC ATA_systemCalibAtStartup_C(void)
{
    /*----------------------------------------------------------------------------- */
    /** \brief <b>Antenna Tuning</b> at start-up.

        \image html ATA_triggerAntennaTuningAtStartup_C.png
        \image rtf ATA_triggerAntennaTuningAtStartup_C.png
        \n
    */
    /*----------------------------------------------------------------------------- */

    if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_ANTENNA_TUNING )
    {   // Antenna Tuning
        /* >>>>>>>>>> ATA_triggerAntennaTuningAtStartup_C >>>>>>>>>> */
        sysStatus      |= BM_SYS_STATUS_CALIB;  // indicates a calibration process is ongoing
        flowCtrl.index  = 0U;
        flowCtrl.pLut   = pAntTuneSysFlowStateMachine;

        do
        {
            ATA_sysExeStateMachineFunc_C();
            _WDR;
        }
        // wait until calibration has finished or timeout occurred
        while( sysStatus & BM_SYS_STATUS_CALIB );

        trxConf.tuneCheckConfig &= (uint8_t)~BM_TUNE_CHECK_CONFIG_ANTENNA_TUNING;

        events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
        if( events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_ANT_TUNE )
        {
            ATA_setEventPin_ASM();
        }
        /* <<<<<<<<<< ATA_triggerAntennaTuningAtStartup_C <<<<<<<<<< */
    }

    /*----------------------------------------------------------------------------- */
    /** \brief <b>Temperature Measurement</b> at start-up.

        \image html ATA_triggerTemperatureMeasurementAtStartup_C.png
        \image rtf ATA_triggerTemperatureMeasurementAtStartup_C.png
        \n
    */
    /*----------------------------------------------------------------------------- */

    if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_TEMP_MEASUREMENT )
    {   // Temperature Measurement
        /* >>>>>>>>>> ATA_triggerTemperatureMeasurementAtStartup_C >>>>>>>>>> */
        sysStatus      |= BM_SYS_STATUS_CALIB;  // indicates a calibration process is ongoing
        flowCtrl.index  = 0U;
        flowCtrl.pLut   = pTempMeasSysFlowStateMachine;

        do
        {
            ATA_sysExeStateMachineFunc_C();
            _WDR;
        }
        // wait until calibration has finished or timeout occurred
        while( sysStatus & BM_SYS_STATUS_CALIB );

        trxConf.tuneCheckConfig &= (uint8_t)~BM_TUNE_CHECK_CONFIG_TEMP_MEASUREMENT;

        events_system |= BM_EVENTS_SYSTEM_CMD_RDY;
        if( events.cmdRdyConf & BM_EVENTS_CMDRDYCONF_TEMP_MEAS )
        {
            ATA_setEventPin_ASM();
        }
        /* <<<<<<<<<< ATA_triggerTemperatureMeasurementAtStartup_C <<<<<<<<<< */
    }

    /*----------------------------------------------------------------------------- */
    /** \brief <b>SRC Calibration</b> at start-up.

        \image html ATA_triggerSrcCalibration_C.png
        \image rtf ATA_triggerSrcCalibration_C.png
        \n
    */
    /*----------------------------------------------------------------------------- */
    if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_SRC_CALIB )
    {   // SRC Calibration
        ATA_triggerSrcCalibration_C();
    }

    /*----------------------------------------------------------------------------- */
    /** \brief <b>FRC Calibration</b> at start-up.

        \image html ATA_triggerFrcCalibration_C.png
        \image rtf ATA_triggerFrcCalibration_C.png
        \n
    */
    /*----------------------------------------------------------------------------- */
    if( trxConf.tuneCheckConfig & BM_TUNE_CHECK_CONFIG_FRC_CALIB )
    {   // FRC Calibration
        ATA_triggerFrcCalibration_C();
    }
}
