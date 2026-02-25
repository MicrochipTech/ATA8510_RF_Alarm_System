/* *C**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/api/src/api.c $
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
#include "api.h"
#include "../../extif/src/extif.h"
#include "../../globals/src/globals.h"
#include "../../rf/src/rf.h"
#include "../../rfrx/src/rfrx.h"
#include "../../rftx/src/rftx.h"
#include "../../calib/src/calib.h"
#include "../../eep/src/eep.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/*===========================================================================*/
/*  Modul Globals                                                            */
/*===========================================================================*/

/** \brief <b>romVersion</b>
    contains the rom version
*/
#pragma location = ".romversion"
__root const prog_char romVersion = ROM_VERSION;
#pragma location = ".rompatchversion"
__root const prog_char romPatchVersion = ROMPATCH_VERSION;




/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_ReadFillLevelRxBuffer_C</b>
    reads the fill level of the Rx buffer.

    \return fillLevel fill level of the Rx buffer in bytes

    \image html ATA_ReadFillLevelRxBuffer_C.png
    \image rtf ATA_ReadFillLevelRxBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_ReadFillLevelRxBuffer_C( void )
{
    return DFL;     /* return fill level of D-FF */

}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_ReadFillLevelTxBuffer_C</b>
    reads the fill level of the Tx buffer.

    \return fillLevel fill level of the Tx buffer in bytes

    \image html ATA_ReadFillLevelTxBuffer_C.png
    \image rtf ATA_ReadFillLevelTxBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_ReadFillLevelTxBuffer_C( void )
{
    return DFL;         /* return fill level of D-FF */
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_ReadFillLevelRssiBuffer_C</b>
    reads the fill level of the RSSI buffer.

    \return fillLevel fill level of the RSSI buffer in bytes

    \image html ATA_ReadFillLevelRssiBuffer_C.png
    \image rtf ATA_ReadFillLevelRssiBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_ReadFillLevelRssiBuffer_C( void )
{
    return SFL;         /* return fill level of S-FF */
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_GetEventBytes_C</b>
    returns the actual event bytes and resets the eventcopy structure.

    \param eventsSystem  ptr to system events
    \param eventsEvents  ptr to events events
    \param eventsPower  ptr to power events
    \param eventsConfig  ptr to config events

    \return none

    \image html ATA_GetEventBytes_C.png
    \image rtf ATA_GetEventBytes_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_GetEventBytes_C( uint8_t* eventsSystem, uint8_t* eventsEvents, uint8_t* eventsPower, uint8_t* eventsConfig )
{
    _CLI;

    *eventsSystem = events_system;          /* return events.System */
    *eventsEvents = events_events;          /* return events.Events */
    *eventsPower  = events_power;           /* return events.Power  */
    *eventsConfig = events_config;          /* return events.Config */

    /* -- Clear the sended events in Events-Copy -- */
    events.eventCopy[0] = 0U;
    events.eventCopy[1] = 0U;
    events.eventCopy[2] = 0U;
    events.eventCopy[3] = 0U;

    _SEI;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_ReadRssiBuffer_C</b>
    reads the RSSI buffer with a specific dataLen. Sets the data access direction
    automatically and resets it after return from function.

    \param data  ptr to destination data buffer array
    \param dataLen  count of data bytes to read

    \return none

    \image html ATA_ReadRssiBuffer_C.png
    \image rtf ATA_ReadRssiBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_ReadRssiBuffer_C( uint8_t* data, uint8_t dataLen )
{
    uint8_t TempSfcAccess = (SFC & BM_SFDRA );
    SFC &= (uint8_t)(~BM_SFDRA);      /* Switch to RX */

    while( dataLen > 0U ){

        *data = SFD;        /* Copy from SFD to data */
        data++;

        dataLen--;
    }

    if( TempSfcAccess ) {       /* Restore data access direction */
        SFC |= (uint8_t)(BM_SFDRA);
    }
    else {
        SFC &= (uint8_t)(~BM_SFDRA);
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_ReadRxBuffer_C</b>
    reads the Rx buffer with a specific dataLen. Sets the data access direction
    automatically and resets it after return from function.

    \param data  ptr to destination data buffer array
    \param dataLen  count of data bytes to be read

    \return none

    \image html ATA_ReadRxBuffer_C.png
    \image rtf ATA_ReadRxBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_ReadRxBuffer_C( uint8_t* data, uint8_t dataLen )
{
    uint8_t TempDfcAccess = (DFC & BM_DFDRA );
    DFC &= (uint8_t)(~BM_DFDRA);      /* Switch to RX */

    while( dataLen > 0U ){

        *data = DFD;        /* Copy from DFD to data */
        data++;

        dataLen--;
    }

    if( TempDfcAccess ) {       /* Restore data access direction */
        DFC |= (uint8_t)(BM_DFDRA);
    }
    else {
        DFC &= (uint8_t)(~BM_DFDRA);
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_WriteSramRegisters_C</b>
    writes a data buffer of a specifc dataLen to a specific SRAM/register address.

    \param data  ptr to source data buffer array
    \param address  ptr to destination memory address
    \param dataLen  count of data bytes to be written

    \return none

    \image html ATA_WriteSramRegisters_C.png
    \image rtf ATA_WriteSramRegisters_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_WriteSramRegisters_C( const uint8_t* data, uint8_t* address, uint8_t dataLen )
{
    uint8_t* MemPtr = address;

    while( dataLen > 0U ) {

        *MemPtr = *data;
        MemPtr++;
        data++;

        dataLen--;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_ReadSramRegisters_C</b>
    reads data of a specifc dataLen from a specific SRAM/register address.

    \param data  ptr to destination data buffer array
    \param address  ptr to source memory address
    \param dataLen  count of data bytes to be read

    \return none

    \image html ATA_ReadSramRegisters_C.png
    \image rtf ATA_ReadSramRegisters_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_ReadSramRegisters_C( uint8_t* data, uint8_t* address, uint8_t dataLen )
{
    uint8_t* MemPtr = address;

    while( dataLen > 0U ) {

        *data = *MemPtr;
        MemPtr++;
        data++;

        dataLen--;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_WriteEeprom_C</b>
    writes one data byte to an EEPROM address.

    \param address  ptr to destination EEPROM address
    \param data  data byte which shall be writen to the EEPROM

    \return none

    \image html ATA_WriteEeprom_C.png
    \image rtf ATA_WriteEeprom_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_WriteEeprom_C( uint8_t* address, uint8_t data )
{
    ATA_eepWRbyte_C( address, data );
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_ReadEeprom_C</b>
    reads one data byte from an EEPROM address.

    \param address  ptr to source EEPROM address

    \return data byte which is read from the EEPROM

    \image html ATA_ReadEeprom_C.png
    \image rtf ATA_ReadEeprom_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_ReadEeprom_C( uint8_t* address )
{
    return ATA_eepRDbyte_ASM( address );
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_WriteTxBuffer_C</b>
    writes data to the Tx buffer. Sets the data access direction
    automatically and resets it after return from function.

    \param data  ptr to source data buffer
    \param dataLen  count of data bytes to be written

    \return none

    \image html ATA_WriteTxBuffer_C.png
    \image rtf ATA_WriteTxBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_WriteTxBuffer_C( const uint8_t* data, uint8_t dataLen )
{
    uint8_t TempDfcAccess = (DFC & BM_DFDRA );
    DFC |= (uint8_t)(BM_DFDRA);           /* Switch to TX */

    while( dataLen > 0U ) {

         DFD = *data;           /* Copy from data to DFD */
         data++;

        dataLen--;
    }

    if( TempDfcAccess ) {       /* Restore data access direction */
        DFC |= (uint8_t)(BM_DFDRA);
    }
    else {
        DFC &= (uint8_t)(~BM_DFDRA);
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_WriteTxPreambleBuffer_C</b>
    writes data to the TxPreamble buffer. Sets the data access direction
    automatically and resets it after return from function.

    \param data  ptr to source data buffer
    \param dataLen  count of data bytes to be written

    \return none

    \image html ATA_WriteTxPreambleBuffer_C.png
    \image rtf ATA_WriteTxPreambleBuffer_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_WriteTxPreambleBuffer_C( const uint8_t* data, uint8_t dataLen )
{
    uint8_t TempSfcAccess = (SFC & BM_SFDRA );
    SFC |= (uint8_t)(BM_SFDRA);           /* Switch to TX */

    while( dataLen > 0U ) {

        SFD = *data;        /* Copy from data to SFD */
        data++;

        dataLen--;
    }

    if( TempSfcAccess ) {       /* Restore data access direction */
        SFC |= (uint8_t)(BM_SFDRA);
    }
    else {
        SFC &= (uint8_t)(~BM_SFDRA);
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_SetSystemMode_C</b>
    sets the values for extReq.systemModeConfig and extReq.serviceChannelConfig.

    \param systemModeConfig  new value for extReq.systemModeConfig
    \param serviceChannelConfig  new value for extReq.serviceChannelConfig

    \return none

    \image html ATA_SetSystemMode_C.png
    \image rtf ATA_SetSystemMode_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_SetSystemMode_C( sysModeConfig_t systemModeConfig, svcChConfig_t serviceChannelConfig )
{
    /* -- Copy the systemModeConfig -- */
    extReq.systemModeConfig = systemModeConfig;
    sysStatus |= BM_SYS_STATUS_UPDATE;

    /* -- Copy the serviceChannelConfig -- */
    extReq.serviceChannelConfig = serviceChannelConfig;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_CalibrateAndCheck_C</b>
    sets the values for extReq.tuneCheckConfig and extReq.serviceChannelConfig.

    \param tuneCheckConfig  new value for extReq.tuneCheckConfig
    \param serviceChannelConfig  new value for extReq.serviceChannelConfig

    \return none

    \image html ATA_CalibrateAndCheck_C.png
    \image rtf ATA_CalibrateAndCheck_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_CalibrateAndCheck_C( tuneCheckConfig_t tuneCheckConfig, svcChConfig_t serviceChannelConfig )
{
    /* -- Copy the tuneCheckConfig -- */
    extReq.tuneCheckConfig = tuneCheckConfig;

    /* -- Copy the serviceChannelConfig -- */
    extReq.serviceChannelConfig = serviceChannelConfig;
}

//--GW--SIX-- not used anymore /*---------------------------------------------------------------------------*/
//--GW--SIX-- not used anymore /** \brief <b>ATA_SystemResetRom_C</b>
//--GW--SIX-- not used anymore     resets the system to start address 0x0000.
//--GW--SIX-- not used anymore 
//--GW--SIX-- not used anymore     \return none
//--GW--SIX-- not used anymore 
//--GW--SIX-- not used anymore     \image html ATA_SystemResetRom_C.png
//--GW--SIX-- not used anymore     \image rtf ATA_SystemResetRom_C.png
//--GW--SIX-- not used anymore     \n
//--GW--SIX-- not used anymore */
//--GW--SIX-- not used anymore /*---------------------------------------------------------------------------*/
//--GW--SIX-- not used anymore VOIDFUNC ATA_SystemResetRom_C( void )
//--GW--SIX-- not used anymore {
//--GW--SIX-- not used anymore     __asm( "JMP     0x0000" );
//--GW--SIX-- not used anymore }
//--GW--SIX-- not used anymore 
//--GW--SIX-- not used anymore /*---------------------------------------------------------------------------*/
//--GW--SIX-- not used anymore /** \brief <b>ATA_SystemResetFlash_C</b>
//--GW--SIX-- not used anymore     resets the system to flash start address 0x2000.
//--GW--SIX-- not used anymore 
//--GW--SIX-- not used anymore     \return none
//--GW--SIX-- not used anymore 
//--GW--SIX-- not used anymore     \image html ATA_SystemResetFlash_C.png
//--GW--SIX-- not used anymore     \image rtf ATA_SystemResetFlash_C.png
//--GW--SIX-- not used anymore     \n
//--GW--SIX-- not used anymore */
//--GW--SIX-- not used anymore /*---------------------------------------------------------------------------*/
//--GW--SIX-- not used anymore VOIDFUNC ATA_SystemResetFlash_C( void )
//--GW--SIX-- not used anymore {
//--GW--SIX-- not used anymore     __asm( "JMP     0x8000" );
//--GW--SIX-- not used anymore }

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_GetRomVersion_C</b>
    returns the rom version.

    \return romVersion

    \image html ATA_GetRomVersion_C.png
    \image rtf ATA_GetRomVersion_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_GetRomVersion_C( void )
{
    return (uint8_t)romVersion;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_GetFlashVersion_C</b>
    returns the following information:
     - Rom version
     - Flash version
     - Customer Specific Version

    \param versionRom  ptr to rom version
    \param versionFlash  ptr to flash version
    \param versionCustomerSpecific  ptr to customer specific version

    \return none

    \image html ATA_GetFlashVersion_C.png
    \image rtf ATA_GetFlashVersion_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_GetFlashVersion_C( uint8_t* versionRom, uint16_t* versionFlash, uint8_t* versionCustomerSpecific )
{
/*lint -e923 */
/* ChGe (08Jul2011)
 * disable lint error 923 - Cast between pointer type and an integral type.
 * Misra Rule 11.3 says: Casting between a pointer and an integer type should be avoided where possible,
 * but may be unavoidable when addressing memory mapped registers or other hardware specific features.
 */
    prog_uint8_t* memPtr = (prog_uint8_t*)0xCFF0;

/*lint -restore */

    *versionRom = romVersion;
    *versionFlash = ((uint16_t)memPtr[0] << 8U ) | memPtr[1];
    *versionCustomerSpecific = memPtr[2];
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_CustomerConfigurableCommand_C</b>
    extend the SPI command set by jumping to the functions which is stored in
    customCmd.customPtr.

    \return none

    \image html ATA_CustomerConfigurableCommand_C.png
    \image rtf ATA_CustomerConfigurableCommand_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_CustomerConfigurableCommand_C( void )
{
    customCmd.customPtr();      /* Execute the Customer Function which is associated with customCmd.customPtr */
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_SystemReset_C</b>
    resets the system by configure the watchdog and wait until the watchdog
    triggers the system.

    \return none

    \image html ATA_SystemReset_C.png
    \image rtf ATA_SystemReset_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_SystemReset_C( void )
{
    WDTCR = 0x18U;       /* Configure the Watchdog Timer */
    WDTCR = 0x08U;

    for(;;){      /* Wait within a Loop-For-Ever until the Watchdog triggers the system */
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_TriggerEepromSecureWrite_C</b>
    trigger the Eeprom secure write mechanism.

    \return none

    \image html ATA_TriggerEepromSecureWrite_C.png
    \image rtf ATA_TriggerEepromSecureWrite_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_TriggerEepromSecureWrite_C( void )
{
    triggerEEPwr.triggerEEPwr = 0xEEU;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_SetVoltageMonitor_C</b>
    set a new value for the voltage monitor control register VMCSR.

    \param vmcsr_val  new value for VMCSR

    \return none

    \image html ATA_SetVoltageMonitor_C.png
    \image rtf ATA_SetVoltageMonitor_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_SetVoltageMonitor_C( uint8_t vmcsr_val )
{
    VMCSR = 0x20U;           /* Clear pending VoltageMonitorFlag */

    vmcsr_val &= 0x0FU;      /* Clear upper nibble of vmcsr_val */

    if (vmcsr_val == 0U) {
        PRR0 |= BM_PRVM;    /* VM disabled */
    }
    else {
        PRR0 &= (uint8_t)~BM_PRVM;   /* VM enabled */

        VMCSR = vmcsr_val;  /* Set VMCSR */
        _NOP;               /* NOP count is based on the Voltage Monitor WCET of 1.8us and the register update time resulting in */
                            /* 14 cycles (including safety margin) when AVR is running with 6 MHZ. */
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        VMCSR |= BM_VMF;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        _NOP;
        VMCSR |= BM_VMIM;
    }
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_OffCommand_C</b>
    switches the ATA5831 off.

    \return none

    \image html ATA_OffCommand_C.png
    \image rtf ATA_OffCommand_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_OffCommand_C( void )
{
    DDRB = 0U;
    DDRC = 0U;
    PORTB = 0xFFU;
    PORTC = 0xFFU;
    SUPCR |= BM_DVDIS;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_ReadTemperature_C</b>
    returns the measured temperature value.

    \return tempVal temperature value

    \image html ATA_ReadTemperature_C.png
    \image rtf ATA_ReadTemperature_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT16FUNC ATA_ReadTemperature_C( void )
{
    return (((uint16_t)calib.sramTEMPH << 8U) | (calib.sramTEMPL));
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_InitSramService_C</b>
    initializes the service SramService[sramServiceNumber] with the
    service eepService[eepromServiceNumber].

    \param sramServiceNumber  Number of the destination SRAM service
    \param eepromServiceNumber  Number of the source eeporm service

    \return none

    \image html ATA_InitSramService_C.png
    \image rtf ATA_InitSramService_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_InitSramService_C(uint8_t sramServiceNumber, uint8_t eepromServiceNumber)
{
    /* -- Copy the serviceNumbers & Update Flag into extRey.serviceInitConfig -- */
    extReq.serviceInitConfig = (uint8_t)((uint8_t)(sramServiceNumber) | (uint8_t)(eepromServiceNumber << 1U));
    extReq.serviceInitConfig |= BM_EXT_REQ_SERVICE_INIT_CONFIG_UPDATE_FLAG;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_StartRssiMeasurement_C</b>
    starts RSSI measurement of the service/channel configuration of parameter
    serviceChannelConfig.

    \param serviceChannelConfig  new value for extReq.serviceChannelConfig

    \return none

    \image html ATA_StartRssiMeasurement_C.png
    \image rtf ATA_StartRssiMeasurement_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
VOIDFUNC ATA_StartRssiMeasurement_C( svcChConfig_t serviceChannelConfig )
{
    /* -- Copy the serviceChannelConfig -- */
    extReq.serviceChannelConfig = serviceChannelConfig;

    /* -- Set the Trigger-Flag in the MiscTrigger Object -- */
    extReq.miscTrigger |= BM_EXT_REQ_MISC_TRIGGER_START_RSSI;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_GetRssiAverageValue_C</b>
    reads the RSSI averaged value which was measured with ATA_StartRssiMeasurement_C and
    delete the value afterwards.

    \return RssiValue measured RSSI averaged value

    \image html ATA_GetRssiAverageValue_C.png
    \image rtf ATA_GetRssiAverageValue_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_GetRssiAverageValue_C( void )
{
    /* -- Return the measured RSSI Value -- */
    return RSSAV;
}

/*---------------------------------------------------------------------------*/
/** \brief <b>ATA_GetRssiPeakValue_C</b>
    Reads the RSSI peak value which was measured with ATA_StartRssiMeasurement_C and
    delete the value afterwards.

    \return RssiValue measured RSSI peak value

    \image html ATA_GetRssiPeakValue_C.png
    \image rtf ATA_GetRssiPeakValue_C.png
    \n
*/
/*---------------------------------------------------------------------------*/
UINT8FUNC ATA_GetRssiPeakValue_C( void )
{
    /* -- Return the measured RSSI Value -- */
    return RSSPK;
}
