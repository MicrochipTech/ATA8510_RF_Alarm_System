/*lint -e9059 */
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/wrap.h $
  $LastChangedRevision: 660705 $
  $LastChangedDate: 2022-04-26 08:54:34 +0200 (Di, 26 Apr 2022) $
  $LastChangedBy: gwillbol $
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/*lint -restore */

#ifndef WRAP_H
#define WRAP_H
/*==================================================*/
/*  INCLUDES                                        */
/*==================================================*/
#include "wrap_thunk.h"

/*==================================================*/
/*  DEFINES                                         */
/*==================================================*/


#define WRAP_VOID_VOID(func) \
extern void func(void); \
void __attribute__((naked)) __wrap_##func (void) { __asm ( CODE_JUMP (func, thunk_void_void) ); }

#define WRAP_U8_VOID(func) \
extern uint8_t func(void); \
void __attribute__((naked)) __wrap_##func (void) { __asm ( CODE_JUMP (func, thunk_uint8_void) ); }

#define WRAP_U16_VOID(func) \
extern uint16_t func(void); \
void __attribute__((naked)) __wrap_##func (void) { __asm ( CODE_JUMP (func, thunk_uint16_void) ); }

#define WRAP_VOID_U8(func) \
extern void func(uint8_t); \
void __attribute__((naked)) __wrap_##func (uint8_t a) { __asm ( CODE_JUMP (func, thunk_void_uint8) ); }

#define WRAP_VOID_U8_U8(func) \
extern void func(uint8_t, uint8_t); \
void __attribute__((naked)) __wrap_##func (uint8_t a, uint8_t b) { __asm ( CODE_JUMP (func, thunk_void_uint8_uint8) ); }

#define WRAP_U8_E8_U8_U8(func) \
extern uint8_t func(eSpiModi, uint8_t, uint8_t); \
uint8_t __attribute__((naked)) __wrap_##func (eSpiModi a, uint8_t b, uint8_t c) { __asm ( CODE_JUMP (func, thunk_uint8_uint8_uint8_uint8) ); }

#define WRAP_VOID_SCC(func) \
extern void func(svcChConfig_t); \
void __attribute__((naked)) __wrap_##func (svcChConfig_t scc) { __asm ( CODE_JUMP (func, thunk_void_uint8) ); }

#define WRAP_VOID_PU8_U8(func) \
extern void func(uint8_t *, uint8_t); \
void __attribute__((naked)) __wrap_##func (uint8_t *p, uint8_t a) { __asm ( CODE_JUMP (func, thunk_void_ptr_uint8) ); }

#define WRAP_VOID_CPU8_U8(func) \
extern void func(const uint8_t* , uint8_t ); \
void __attribute__((naked)) __wrap_##func (const uint8_t *p, uint8_t a) { __asm ( CODE_JUMP (func, thunk_void_ptr_uint8) ); }

#define WRAP_VOID_PU8(func) \
extern void func(uint8_t *); \
void __attribute__((naked)) __wrap_##func (uint8_t *p1) { __asm ( CODE_JUMP (func, thunk_void_ptr) ); }

#define WRAP_VOID_PU8_PU8(func) \
extern void func(uint8_t *, uint8_t*); \
void __attribute__((naked)) __wrap_##func (uint8_t *p1, uint8_t *p2) { __asm ( CODE_JUMP (func, thunk_void_ptr_ptr) ); }

#define WRAP_VOID_PU8_PU8_U8(func) \
extern void func(uint8_t *, uint8_t*, uint8_t); \
void __attribute__((naked)) __wrap_##func (uint8_t *p1, uint8_t *p2, uint8_t a) { __asm ( CODE_JUMP (func, thunk_void_ptr_ptr_uint8) ); }

#define WRAP_VOID_CPU8_PU8_U8(func) \
extern void func(const uint8_t *, uint8_t*, uint8_t); \
void __attribute__((naked)) __wrap_##func (const uint8_t *p1, uint8_t *p2, uint8_t a) { __asm ( CODE_JUMP (func, thunk_void_ptr_ptr_uint8) ); }

#define WRAP_U8_PU8(func) \
extern uint8_t func(uint8_t *); \
uint8_t __attribute__((naked)) __wrap_##func (uint8_t *p) { __asm ( CODE_JUMP (func, thunk_uint8_ptr) ); }

#define WRAP_VOID_PU8_PU8_PU8_PU8(func) \
extern void func(uint8_t *, uint8_t *, uint8_t *, uint8_t *);   \
void __attribute__((naked)) __wrap_##func (uint8_t *p1, uint8_t *p2, uint8_t *p3, uint8_t *p4) { __asm ( CODE_JUMP (func, thunk_void_ptr_ptr_ptr_ptr) ); }

#define WRAP_VOID_SMC_SCC(func) \
extern void func(sysModeConfig_t, svcChConfig_t); \
void __attribute__((naked)) __wrap_##func (sysModeConfig_t svc, svcChConfig_t ch) { __asm ( CODE_JUMP (func, thunk_void_uint8_uint8) ); }

#define WRAP_VOID_TCC_SCC(func) \
extern void func(tuneCheckConfig_t, svcChConfig_t); \
void __attribute__((naked)) __wrap_##func (tuneCheckConfig_t svc, svcChConfig_t ch) { __asm ( CODE_JUMP (func, thunk_void_uint8_uint8) ); }

#define WRAP_VOID_PU8_PU16_PU8(func) \
extern void func(uint8_t *, uint16_t*, uint8_t*); \
void __attribute__((naked)) __wrap_##func (uint8_t *p1, uint16_t *p2, uint8_t *p3) { __asm ( CODE_JUMP (func, thunk_void_ptr_ptr_ptr) ); }

#define WRAP_VOID_PU8_U8_PU8(func) \
extern void func(uint8_t *, uint8_t, uint8_t*); \
void __attribute__((naked)) __wrap_##func (uint8_t *p1, uint8_t a, uint8_t *p2) { __asm ( CODE_JUMP (func, thunk_void_ptr_uint8_ptr) ); }

#define WRAP_VOID_FP_FP_FP(func) \
extern void func(pcIntHandler, pcIntHandler, irqIntHandler);   \
uint8_t __attribute__((naked)) __wrap_##func (pcIntHandler int1, pcIntHandler int2, irqIntHandler int3) { __asm ( CODE_JUMP (func, thunk_void_ptr_ptr_ptr) ); }

#define WRAP_U8_FP_FP_FP(func) \
extern uint8_t func(pcIntHandler, pcIntHandler, irqIntHandler);   \
uint8_t __attribute__((naked)) __wrap_##func (pcIntHandler int1, pcIntHandler int2, irqIntHandler int3) { __asm ( CODE_JUMP (func, thunk_uint8_ptr_ptr_ptr) ); }

#define WRAP_U16_U8_U8(func) \
extern uint16_t func(uint8_t, uint8_t); \
uint16_t __attribute__((naked)) __wrap_##func (uint8_t a, uint8_t b) { __asm( CODE_JUMP (func, thunk_uint16_uint8_uint8) ); }
        
#define WRAP_I16_I8_U8(func) \
extern int16_t func(int8_t, uint8_t); \
int16_t __attribute__((naked)) __wrap_##func (int8_t a, uint8_t b) { __asm( CODE_JUMP (func, thunk_int16_int8_uint8) ); }

#define WRAP_U32_U16_U16(func) \
extern uint32_t func(uint16_t, uint16_t); \
uint32_t __attribute__((naked)) __wrap_##func (uint16_t a, uint16_t b) { __asm( CODE_JUMP (func, thunk_uint32_uint16_uint16) ); }

#define WRAP_I32_I16_I16(func) \
extern int32_t func(int16_t, int16_t); \
int32_t __attribute__((naked)) __wrap_##func (int16_t a, int16_t b) { __asm( CODE_JUMP (func, thunk_int32_int16_int16) ); }

#define WRAP_I32_I32_U8(func) \
extern int32_t func(int32_t, uint8_t); \
int32_t __attribute__((naked)) __wrap_##func (int32_t a, uint8_t b) { __asm( CODE_JUMP (func, thunk_int32_int32_uint8) ); }

#define WRAP_I16_I16_U8(func) \
extern int16_t func(int16_t, uint8_t); \
int16_t __attribute__((naked)) __wrap_##func (int16_t a, uint8_t b) { __asm( CODE_JUMP (func, thunk_int16_int16_uint8) ); }

#define WRAP_ATA_ReadFillLevelRxBuffer_C(func)					WRAP_U8_VOID(func)				// UINT8FUNC ATA_ReadFillLevelRxBuffer_C( void )
#define WRAP_ATA_ReadFillLevelTxBuffer_C(func)					WRAP_U8_VOID(func)				// UINT8FUNC ATA_ReadFillLevelTxBuffer_C( void )
#define WRAP_ATA_ReadFillLevelRssiBuffer_C(func)				WRAP_U8_VOID(func)				// UINT8FUNC ATA_ReadFillLevelRssiBuffer_C( void )
#define WRAP_ATA_GetEventBytes_C(func)							WRAP_VOID_PU8_PU8_PU8_PU8(func)	// VOIDFUNC ATA_GetEventBytes_C( uint8_t* eventsSystem, uint8_t* eventsEvents, uint8_t* eventsPower, uint8_t* eventsConfig )
#define WRAP_ATA_ReadRssiBuffer_C(func)							WRAP_VOID_PU8_U8(func)			// VOIDFUNC ATA_ReadRssiBuffer_C( uint8_t* data, uint8_t dataLen )
#define WRAP_ATA_ReadRxBuffer_C(func)							WRAP_VOID_PU8_U8(func)			// VOIDFUNC ATA_ReadRxBuffer_C( uint8_t* data, uint8_t dataLen )
#define WRAP_ATA_WriteSramRegisters_C(func)						WRAP_VOID_PU8_PU8_U8(func) 		// VOIDFUNC ATA_WriteSramRegisters_C( uint8_t* data, uint8_t* address, uint8_t dataLen )
#define WRAP_ATA_ReadSramRegisters_C(func)						WRAP_VOID_PU8_PU8_U8(func) 		// VOIDFUNC ATA_ReadSramRegisters_C( uint8_t* data, uint8_t* address, uint8_t dataLen )
#define WRAP_ATA_WriteEeprom_C(func)							WRAP_VOID_PU8_U8(func)			// VOIDFUNC ATA_WriteEeprom_C( uint8_t* address, uint8_t data )
#define WRAP_ATA_ReadEeprom_C(func)								WRAP_U8_PU8(func)				// UINT8FUNC ATA_ReadEeprom_C( uint8_t* address )
#define WRAP_ATA_WriteTxBuffer_C(func)							WRAP_VOID_PU8_U8(func)			// VOIDFUNC ATA_WriteTxBuffer_C( uint8_t* data, uint8_t dataLen )
#define WRAP_ATA_WriteTxPreambleBuffer_C(func)					WRAP_VOID_PU8_U8(func)			// VOIDFUNC ATA_WriteTxPreambleBuffer_C( uint8_t* data, uint8_t dataLen )
#define WRAP_ATA_SetSystemMode_C(func)							WRAP_VOID_SMC_SCC(func)			// VOIDFUNC ATA_SetSystemMode_C( sysModeConfig_t systemModeConfig, svcChConfig_t serviceChannelConfig )
#define WRAP_ATA_CalibrateAndCheck_C(func)						WRAP_VOID_TCC_SCC(func)			// VOIDFUNC ATA_CalibrateAndCheck_C( tuneCheckConfig_t tuneCheckConfig, svcChConfig_t serviceChannelConfig )
#define WRAP_ATA_GetRomVersion_C(func)							WRAP_U8_VOID(func)				// UINT8FUNC ATA_GetRomVersion_C( void )
#define WRAP_ATA_GetFlashVersion_C(func)						WRAP_VOID_PU8_PU16_PU8(func)	// VOIDFUNC ATA_GetFlashVersion_C( uint8_t* versionRom, uint16_t* versionFlash, uint8_t* versionCustomerSpecific )
#define WRAP_ATA_CustomerConfigurableCommand_C(func)			WRAP_VOID_VOID(func)			// VOIDFUNC ATA_CustomerConfigurableCommand_C( void )
#define WRAP_ATA_SystemReset_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_SystemReset_C( void )
#define WRAP_ATA_TriggerEepromSecureWrite_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_TriggerEepromSecureWrite_C( void )
#define WRAP_ATA_SetVoltageMonitor_C(func)						WRAP_VOID_U8(func)				// VOIDFUNC ATA_SetVoltageMonitor_C( uint8_t vmcsr_val )
#define WRAP_ATA_OffCommand_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_OffCommand_C( void )
#define WRAP_ATA_ReadTemperature_C(func)						WRAP_U16_VOID(func)				// UINT16FUNC ATA_ReadTemperature_C( void )
#define WRAP_ATA_InitSramService_C(func)						WRAP_VOID_U8_U8(func)			// VOIDFUNC ATA_InitSramService_C(uint8_t sramServiceNumber, uint8_t eepromServiceNumber)
#define WRAP_ATA_StartRssiMeasurement_C(func)					WRAP_VOID_SCC(func)				// VOIDFUNC ATA_StartRssiMeasurement_C( svcChConfig_t serviceChannelConfig )
#define WRAP_ATA_GetRssiAverageValue_C(func)					WRAP_U8_VOID(func)				// UINT8FUNC ATA_GetRssiAverageValue_C( void )
#define WRAP_ATA_GetRssiPeakValue_C(func)						WRAP_U8_VOID(func)				// UINT8FUNC ATA_GetRssiPeakValue_C( void )
#define WRAP_API_ReadFillLevelRxBuffer_C(func)                  WRAP_U8_VOID(func)            	// UINT8FUNC  API_ReadFillLevelRxBuffer_C(void);
#define WRAP_API_ReadFillLevelTxBuffer_C(func)                  WRAP_U8_VOID(func)              // UINT8FUNC  API_ReadFillLevelTxBuffer_C(void);
#define WRAP_API_ReadFillLevelRssiBuffer_C(func)                WRAP_U8_VOID(func)              // UINT8FUNC  API_ReadFillLevelRssiBuffer_C(void);
#define WRAP_API_GetEventBytes_C(func)                          WRAP_VOID_PU8_PU8_PU8_PU8(func) // VOIDFUNC   API_GetEventBytes_C( uint8_t* eventsSystem, uint8_t* eventsEvents, uint8_t* eventsPower, uint8_t* eventsConfig );
#define WRAP_API_ReadRssiBuffer_C(func)                         WRAP_VOID_PU8_U8(func)          // VOIDFUNC   API_ReadRssiBuffer_C( uint8_t* data, uint8_t dataLen );
#define WRAP_API_ReadRxBuffer_C(func)                           WRAP_VOID_PU8_U8(func)          // VOIDFUNC   API_ReadRxBuffer_C( uint8_t* data, uint8_t dataLen );
#define WRAP_API_WriteSramRegisters_C(func)                     WRAP_VOID_PU8_PU8_U8(func)     	// VOIDFUNC   API_WriteSramRegisters_C( const uint8_t* data, uint8_t* address, uint8_t dataLen );
#define WRAP_API_ReadSramRegisters_C(func)                      WRAP_VOID_PU8_PU8_U8(func)      // VOIDFUNC   API_ReadSramRegisters_C( uint8_t* data, uint8_t* address, uint8_t dataLen );
#define WRAP_API_WriteEeprom_C(func)                            WRAP_VOID_PU8_U8(func)          // VOIDFUNC   API_WriteEeprom_C( uint8_t* address, uint8_t data );
#define WRAP_API_ReadEeprom_C(func)                             WRAP_U8_PU8(func)               // UINT8FUNC  API_ReadEeprom_C( uint8_t* address );
#define WRAP_API_WriteTxBuffer_C(func)                          WRAP_VOID_PU8_U8(func)         	// VOIDFUNC   API_WriteTxBuffer_C( const uint8_t* data, uint8_t dataLen );
#define WRAP_API_WriteTxPreambleBuffer_C(func)                  WRAP_VOID_PU8_U8(func)         	// VOIDFUNC   API_WriteTxPreambleBuffer_C( const uint8_t* data, uint8_t dataLen );
#define WRAP_API_SetSystemMode_C(func)                          WRAP_VOID_SMC_SCC(func)         // VOIDFUNC   API_SetSystemMode_C( sysModeConfig_t systemModeConfig, svcChConfig_t serviceChannelConfig );
#define WRAP_API_CalibrateAndCheck_C(func)                  	WRAP_VOID_TCC_SCC(func)         // VOIDFUNC   API_CalibrateAndCheck_C( tuneCheckConfig_t tuneCheckConfig, svcChConfig_t serviceChannelConfig );#define WRAP_API_CalibrateAndCheck_C(func)
#define WRAP_API_GetRomVersion_C(func)                          WRAP_U8_VOID(func)              // UINT8FUNC  API_GetRomVersion_C( void );
#define WRAP_API_GetFlashVersion_C(func)                        WRAP_VOID_PU8_PU16_PU8(func)    // VOIDFUNC   API_GetFlashVersion_C( uint8_t* versionRom, uint16_t* versionFlash, uint8_t* versionCustomerSpecific );
#define WRAP_API_CustomerConfigurableCommand_C(func)            WRAP_VOID_VOID(func)            // VOIDFUNC   API_CustomerConfigurableCommand_C( void );
#define WRAP_API_SystemReset_C(func)                            WRAP_VOID_VOID(func)            // VOIDFUNC   API_SystemReset_C( void );
#define WRAP_API_TriggerEepromSecureWrite_C(func)               WRAP_VOID_VOID(func)            // VOIDFUNC   API_TriggerEepromSecureWrite_C( void );
#define WRAP_API_SetVoltageMonitor_C(func)                      WRAP_VOID_U8(func)              // VOIDFUNC   API_SetVoltageMonitor_C( uint8_t vmcsr_val );
#define WRAP_API_OffCommand_C(func)                             WRAP_VOID_VOID(func)            // VOIDFUNC   API_OffCommand_C( void );
#define WRAP_API_ReadTemperature_C(func)                        WRAP_U16_VOID(func)             // UINT16FUNC API_ReadTemperature_C( void );
#define WRAP_API_InitSramService_C(func)                    	WRAP_VOID_U8_U8(func)           // VOIDFUNC   API_InitSramService_C(uint8_t sramServiceNumber, uint8_t eepromServiceNumber);
#define WRAP_API_StartRssiMeasurement_C(func)                   WRAP_VOID_SCC(func)             // VOIDFUNC   API_StartRssiMeasurement_C( svcChConfig_t serviceChannelConfig );
#define WRAP_API_GetRssiAverageValue_C(func)                    WRAP_U8_VOID(func)              // UINT8FUNC  API_GetRssiAverageValue_C( void );
#define WRAP_API_GetRssiPeakValue_C(func)                       WRAP_U8_VOID(func)              // UINT8FUNC  API_GetRssiPeakValue_C( void );
#define WRAP_API_rfCalibration_C(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC API_rfCalibration_C(void);
#define WRAP_API_anttuneStateInitSSM_C(func)                    WRAP_VOID_VOID(func)            // VOIDFUNC API_anttuneStateInitSSM_C(void);
#define WRAP_API_sysAntTuneSsmEnable_C(func)                    WRAP_VOID_VOID(func)            // VOIDFUNC API_sysAntTuneSsmEnable_C(void);
#define WRAP_API_anttuneStateStartSSM_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC API_anttuneStateStartSSM_C(void);
#define WRAP_API_anttuneStateWait4SSMrdy_C(func)                WRAP_VOID_VOID(func)            // VOIDFUNC API_anttuneStateWait4SSMrdy_C(void);
#define WRAP_API_anttuneStateSetCmdRdy_C(func)                  WRAP_VOID_VOID(func)            // VOIDFUNC API_anttuneStateSetCmdRdy_C(void);
#define WRAP_API_vcocalStateInitSSM_C(func)                     WRAP_VOID_VOID(func)            // VOIDFUNC API_vcocalStateInitSSM_C(void);
#define WRAP_API_sysVcoCalSsmEnable_C(func)                     WRAP_VOID_VOID(func)            // VOIDFUNC API_sysVcoCalSsmEnable_C(void);
#define WRAP_API_vcocalStateStartSSM_C(func)                    WRAP_VOID_VOID(func)            // VOIDFUNC API_vcocalStateStartSSM_C(void);
#define WRAP_API_vcocalStateWait4SSMrdy_C(func)                 WRAP_VOID_VOID(func)            // VOIDFUNC API_vcocalStateWait4SSMrdy_C(void);
#define WRAP_API_vcocalStateSetCmdRdy_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC API_vcocalStateSetCmdRdy_C(void);
#define WRAP_API_tempmeasStateInitSSM_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC API_tempmeasStateInitSSM_C(void);
#define WRAP_API_sysTempMeasSsmEnable_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC API_sysTempMeasSsmEnable_C(void);
#define WRAP_API_tempmeasStateStartSSM_C(func)                  WRAP_VOID_VOID(func)            // VOIDFUNC API_tempmeasStateStartSSM_C(void);
#define WRAP_API_tempmeasStateWait4SSMrdy_C(func)               WRAP_VOID_VOID(func)            // VOIDFUNC API_tempmeasStateWait4SSMrdy_C(void);
#define WRAP_API_tempmeasStateWait4Temperature_C(func)          WRAP_VOID_VOID(func)            // VOIDFUNC API_tempmeasStateWait4Temperature_C(void);
#define WRAP_API_tempmeasStateSetCmdRdy_C(func)                 WRAP_VOID_VOID(func)            // VOIDFUNC API_tempmeasStateSetCmdRdy_C(void);
#define WRAP_API_eepWRbyte_C(func)                              WRAP_VOID_PU8_U8(func)          // VOIDFUNC  API_eepWRbyte_C(uint8_t *addr, uint8_t data);
#define WRAP_API_eepWRblock_C(func)                             WRAP_VOID_PU8_PU8_U8(func)      // VOIDFUNC  API_eepWRblock_C(uint8_t *addr, uint8_t *data, uint8_t len);
#define WRAP_API_eepRDblock_C(func)                             WRAP_VOID_PU8_U8_PU8(func)      // VOIDFUNC  API_eepRDblock_C(uint8_t *addr, uint8_t len, uint8_t *buffer);
#define WRAP_API_eepromSecureWrite_C(func)                      WRAP_VOID_VOID(func)            // VOIDFUNC  API_eepromSecureWrite_C(void);
#define WRAP_API_eepRDbyte_ASM(func)                            WRAP_U8_PU8(func)               // UINT8FUNC API_eepRDbyte_ASM(uint8_t *addr);
#define WRAP_API_SpiOpen_C(func)                                WRAP_U8_E8_U8_U8(func)          // UINT8FUNC API_SpiOpen_C(eSpiModi mode, uint8_t irq, uint8_t dord);
#define WRAP_API_initExtIf_C(func)                              WRAP_VOID_FP_FP_FP(func)        // VOIDFUNC  API_initExtIf_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr);
#define WRAP_API_PatchSpiReady_ASM(func)                        WRAP_VOID_VOID(func)            // VOIDFUNC  API_PatchSpiReady_ASM(void);
#define WRAP_API_SpiClose_ASM(func)                             WRAP_VOID_VOID(func)            // VOIDFUNC  API_SpiClose_ASM(void);
#define WRAP_API_portBisr_ASM(func)                             WRAP_VOID_VOID(func)            // VOIDFUNC  API_portBisr_ASM(void);
#define WRAP_API_portCisr_ASM(func)                             WRAP_VOID_VOID(func)            // VOIDFUNC  API_portCisr_ASM(void);
#define WRAP_API_setClk_C(func)                                 WRAP_VOID_U8(func)              // VOIDFUNC API_setClk_C(uint8_t val);
#define WRAP_API_wdtDisable_C(func)                             WRAP_VOID_VOID(func)            // VOIDFUNC API_wdtDisable_C(void);
#define WRAP_API_wdtEnable_C(func)                              WRAP_VOID_VOID(func)            // VOIDFUNC API_wdtEnable_C(void);
#define WRAP_API_SleepMode_C(func)                              WRAP_VOID_VOID(func)            // VOIDFUNC API_SleepMode_C(void);
#define WRAP_API_Sleep_C(func)                                  WRAP_VOID_VOID(func)            // VOIDFUNC API_Sleep_C(void);
#define WRAP_API_currentServiceInit_C(func)                     WRAP_VOID_SCC(func)             // VOIDFUNC API_currentServiceInit_C(svcChConfig_t config);
#define WRAP_API_initPollingConfiguration_C(func)               WRAP_VOID_VOID(func)            // VOIDFUNC API_initPollingConfiguration_C(void);
#define WRAP_API_initRssiConfiguration_C(func)                  WRAP_VOID_VOID(func)            // VOIDFUNC API_initRssiConfiguration_C(void);
#define WRAP_API_initFacLockedArea_C(func)                      WRAP_VOID_VOID(func)            // VOIDFUNC API_initFacLockedArea_C(void);
#define WRAP_API_clkSwitchFRC_C(func)                           WRAP_VOID_VOID(func)            // VOIDFUNC API_clkSwitchFRC_C(void);
#define WRAP_API_initChannelSwitchForCurrentService_C(func)     WRAP_VOID_VOID(func)            // VOIDFUNC API_initChannelSwitchForCurrentService_C(void);
#define WRAP_API_clkSwitchXTO_ASM(func)                         WRAP_VOID_VOID(func)            // VOIDFUNC API_clkSwitchXTO_ASM(void);
#define WRAP_API_copyEepSvc_ASM(func)                           WRAP_VOID_PU8_PU8(func)         // VOIDFUNC API_copyEepSvc_ASM(uint8_t *dstPtr, uint8_t *srcPtr);
#define WRAP_API_copyEepChannel_ASM(func)                       WRAP_VOID_PU8_PU8(func)         // VOIDFUNC API_copyEepChannel_ASM(uint8_t *dstPtr, uint8_t *srcPtr);
#define WRAP_API_copySramSvc_ASM(func)                          WRAP_VOID_PU8_PU8(func)         // VOIDFUNC API_copySramSvc_ASM(uint8_t *dstPtr, uint8_t *srcPtr);
#define WRAP_API_copySramChannel_ASM(func)                      WRAP_VOID_PU8_PU8(func)         // VOIDFUNC API_copySramChannel_ASM(uint8_t *dstPtr, uint8_t *srcPtr);
#define WRAP_API_doIdScan_C(func)                               WRAP_VOID_VOID(func)            // VOIDFUNC API_doIdScan_C(void);
#define WRAP_API_initIoConfig_C(func)                           WRAP_VOID_VOID(func)            // VOIDFUNC  API_initIoConfig_C(void);
#define WRAP_API_defaultIoConfig_C(func)                        WRAP_VOID_VOID(func)            // VOIDFUNC  API_defaultIoConfig_C(void);
#define WRAP_API_systemInit_C(func)                             WRAP_U8_FP_FP_FP(func)          // UINT8FUNC API_systemInit_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr);
#define WRAP_API_doInitialization_C(func)                       WRAP_VOID_VOID(func)            // VOIDFUNC  API_doInitialization_C(void);
#define WRAP_API_checkWakeupSource_C(func)                      WRAP_VOID_VOID(func)            // VOIDFUNC  API_checkWakeupSource_C(void);
#define WRAP_API_systemCalibAtStartup_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC  API_systemCalibAtStartup_C(void);
#define WRAP_API_startInitTxRxSSM_C(func)                       WRAP_U8_VOID(func)              // UINT8FUNC API_startInitTxRxSSM_C(void);
#define WRAP_API_startShutDownSSM_C(func)                       WRAP_VOID_VOID(func)            // VOIDFUNC  API_startShutDownSSM_C(void);
#define WRAP_API_ssmInterrupt_C(func)                           WRAP_VOID_VOID(func)            // VOIDFUNC  API_ssmInterrupt_C(void);
#define WRAP_API_resetSSMs_C(func)                              WRAP_VOID_VOID(func)            // VOIDFUNC  API_resetSSMs_C(void);
#define WRAP_API_switchIdleXTO_ASM(func)                        WRAP_VOID_VOID(func)            // VOIDFUNC  API_switchIdleXTO_ASM(void);
#define WRAP_API_setRxActive_ASM(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC  API_setRxActive_ASM(void);
#define WRAP_API_clrRxActive_ASM(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC  API_clrRxActive_ASM(void);
#define WRAP_API_setSystemError_ASM(func)                       WRAP_VOID_VOID(func)            // VOIDFUNC  API_setSystemError_ASM(void);
#define WRAP_API_pollStateInitCurrentPollingChannel_C(func)     WRAP_VOID_VOID(func)            // VOIDFUNC API_pollStateInitCurrentPollingChannel_C(void);
#define WRAP_API_pollStateInitSSM_C(func)                       WRAP_VOID_VOID(func)            // VOIDFUNC API_pollStateInitSSM_C(void);
#define WRAP_API_pollStateWait4SSMstateGetTelegram_C(func)      WRAP_VOID_VOID(func)            // VOIDFUNC API_pollStateWait4SSMstateGetTelegram_C(void);
#define WRAP_API_pollStateWait4ShutdownRdyTRX_C(func)           WRAP_VOID_VOID(func)            // VOIDFUNC API_pollStateWait4ShutdownRdyTRX_C(void);
#define WRAP_API_pollStateCheck4NextPollingChannel_C(func)      WRAP_VOID_VOID(func)            // VOIDFUNC API_pollStateCheck4NextPollingChannel_C(void);
#define WRAP_API_pollStateISR_ASM(func)                         WRAP_VOID_VOID(func)            // VOIDFUNC API_pollStateISR_ASM(void);
#define WRAP_API_rxStateInitSSM_C(func)                         WRAP_VOID_VOID(func)            // VOIDFUNC API_rxStateInitSSM_C(void);
#define WRAP_API_rxStateStartSSM_C(func)                        WRAP_VOID_VOID(func)            // VOIDFUNC API_rxStateStartSSM_C(void);
#define WRAP_API_rxStateWait4SSMstateGetTelegram_C(func)        WRAP_VOID_VOID(func)            // VOIDFUNC API_rxStateWait4SSMstateGetTelegram_C(void);
#define WRAP_API_rxStateWait4SSMrdy_C(func)                     WRAP_VOID_VOID(func)            // VOIDFUNC API_rxStateWait4SSMrdy_C(void);
#define WRAP_API_pureRxUp_C(func)                               WRAP_VOID_VOID(func)            // VOIDFUNC API_pureRxUp_C(void);
#define WRAP_API_rssiStateInitSSM_C(func)                       WRAP_VOID_VOID(func)            // VOIDFUNC API_rssiStateInitSSM_C(void);
#define WRAP_API_rssiStateWait4SSMrdy_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC API_rssiStateWait4SSMrdy_C(void);
#define WRAP_API_rssiStateStartSSM_C(func)                      WRAP_VOID_VOID(func)            // VOIDFUNC API_rssiStateStartSSM_C(void);
#define WRAP_API_rxStateInitSubchanneling_C(func)               WRAP_VOID_VOID(func)            // VOIDFUNC API_rxStateInitSubchanneling_C(void);
#define WRAP_API_rxStateSubchanneling_Center_Freq_C(func)       WRAP_VOID_VOID(func)            // VOIDFUNC API_rxStateSubchanneling_Center_Freq_C(void);
#define WRAP_API_rxStateSubchanneling_Lower_Freq_C(func)        WRAP_VOID_VOID(func)            // VOIDFUNC API_rxStateSubchanneling_Lower_Freq_C(void);
#define WRAP_API_rxStateSubchanneling_Upper_Freq_C(func)        WRAP_VOID_VOID(func)            // VOIDFUNC API_rxStateSubchanneling_Upper_Freq_C(void);
#define WRAP_API_wakeCheckOkPathA_ASM(func)                     WRAP_VOID_VOID(func)            // VOIDFUNC API_wakeCheckOkPathA_ASM(void);
#define WRAP_API_txStateInitSSM_C(func)                         WRAP_VOID_VOID(func)            // VOIDFUNC API_txStateInitSSM_C(void);
#define WRAP_API_txStateStartSSM_C(func)                        WRAP_VOID_VOID(func)            // VOIDFUNC API_txStateStartSSM_C(void);
#define WRAP_API_txStateWait4SSMrdy_C(func)                     WRAP_VOID_VOID(func)            // VOIDFUNC API_txStateWait4SSMrdy_C(void);
#define WRAP_API_txTransparentStateWait4SSMrdy_C(func)          WRAP_VOID_VOID(func)            // VOIDFUNC API_txTransparentStateWait4SSMrdy_C(void);
#define WRAP_API_txStateTransparentMode_C(func)                 WRAP_VOID_VOID(func)            // VOIDFUNC API_txStateTransparentMode_C(void);
#define WRAP_API_txStateWait4FillLevel_C(func)                  WRAP_VOID_VOID(func)            // VOIDFUNC API_txStateWait4FillLevel_C(void);
#define WRAP_API_txStateStartTxModulator_C(func)                WRAP_VOID_VOID(func)            // VOIDFUNC API_txStateStartTxModulator_C(void);
#define WRAP_API_txStateStartWait4TransmissionComplete_C(func)  WRAP_VOID_VOID(func)            // VOIDFUNC API_txStateStartWait4TransmissionComplete_C(void);
#define WRAP_API_openTimer3forTxing_C(func)                     WRAP_VOID_VOID(func)            // VOIDFUNC API_openTimer3forTxing_C(void);
#define WRAP_API_sysTxingBufferedMode_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC API_sysTxingBufferedMode_C(void);
#define WRAP_API_sysTxingTransparentMode_C(func)                WRAP_VOID_VOID(func)            // VOIDFUNC API_sysTxingTransparentMode_C(void);
#define WRAP_API_check4extRequests_C(func)                      WRAP_VOID_VOID(func)            // VOIDFUNC  API_check4extRequests_C(void);
#define WRAP_API_serviceInitSwitching_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC  API_serviceInitSwitching_C(void);
#define WRAP_API_systemFlowCtrl_C(func)                         WRAP_VOID_VOID(func)            // VOIDFUNC  API_systemFlowCtrl_C(void);
#define WRAP_API_sysExeStateMachineFunc_C(func)                 WRAP_VOID_VOID(func)            // VOIDFUNC  API_sysExeStateMachineFunc_C(void);
#define WRAP_API_setIdleMode_C(func)                            WRAP_U8_VOID(func)              // UINT8FUNC API_setIdleMode_C(void);
#define WRAP_API_systemFlowStateWaitXtoReady_C(func)            WRAP_VOID_VOID(func)            // VOIDFUNC  API_systemFlowStateWaitXtoReady_C(void);
#define WRAP_API_systemStartSSM_C(func)                         WRAP_VOID_U8(func)              // VOIDFUNC  API_systemStartSSM_C(uint8_t errorCode);
#define WRAP_API_systemWait4SSMrdy_C(func)                      WRAP_VOID_U8_U8(func)           // VOIDFUNC  API_systemWait4SSMrdy_C(uint8_t errorCode, uint8_t shutdownIdx);
#define WRAP_API_systemFlowStateShutdownTRX_C(func)             WRAP_VOID_VOID(func)            // VOIDFUNC  API_systemFlowStateShutdownTRX_C(void);
#define WRAP_API_systemFlowStateWait4ShutdownRdyTRX_C(func)     WRAP_VOID_VOID(func)            // VOIDFUNC  API_systemFlowStateWait4ShutdownRdyTRX_C(void);
#define WRAP_API_systemFlowStateMachineEnd_C(func)              WRAP_VOID_VOID(func)            // VOIDFUNC  API_systemFlowStateMachineEnd_C(void);
#define WRAP_API_systemErrorLoop_C(func)                        WRAP_VOID_U8(func)              // VOIDFUNC  API_systemErrorLoop_C(uint8_t errorCode);
#define WRAP_API_triggerSrcCalibration_C(func)                  WRAP_VOID_VOID(func)            // VOIDFUNC  API_triggerSrcCalibration_C(void);
#define WRAP_API_triggerFrcCalibration_C(func)                  WRAP_VOID_VOID(func)            // VOIDFUNC  API_triggerFrcCalibration_C(void);
#define WRAP_API_triggerSelfCheck_C(func)                       WRAP_VOID_VOID(func)            // VOIDFUNC  API_triggerSelfCheck_C(void);
#define WRAP_API_wait4avcc_C(func)                              WRAP_VOID_VOID(func)            // VOIDFUNC  API_wait4avcc_C(void);
#define WRAP_API_systemModeSwitching_C(func)                    WRAP_VOID_VOID(func)            // VOIDFUNC  API_systemModeSwitching_C(void);
#define WRAP_API_tuneCheckSwitching_C(func)                     WRAP_VOID_VOID(func)            // VOIDFUNC  API_tuneCheckSwitching_C(void);
#define WRAP_API_miscTriggerSwitching_C(func)                   WRAP_VOID_VOID(func)            // VOIDFUNC  API_miscTriggerSwitching_C(void);
#define WRAP_API_setEventPin_ASM(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC  API_setEventPin_ASM(void);
// #define WRAP_API_timer1Open_C(func)
#define WRAP_API_timer1Close_ASM(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC  API_timer1Close_ASM(void);
// #define WRAP_API_timer2Open_C(func)
#define WRAP_API_timer2Close_ASM(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC  API_timer2Close_ASM(void);
//
// module TIMER3
// extern UINT8FUNC API_timer3Open_C(uint8_t ctrl, uint8_t modeA, uint8_t modeB, uint8_t irqMask, timer3IRQHandler comp, timer3IRQHandler ovf, timer3IRQHandler cap);
#define WRAP_API_timer3Close_ASM(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC  API_timer3Close_ASM(void);
// #define WRAP_API_timer4Open_C(func)
#define WRAP_API_timer4Close_ASM(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC  API_timer4Close_ASM(void);
// #define WRAP_API_timer5Open_C(func)
#define WRAP_API_timer5Close_ASM(func)                          WRAP_VOID_VOID(func)            // VOIDFUNC  API_timer5Close_ASM(void);
#define WRAP_API_stopSsmWatchdog_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC API_stopSsmWatchdog_C(void)
#define WRAP_API_timer1ResetRun_ASM(func)						WRAP_VOID_VOID(func)			// VOIDFUNC API_timer1ResetRun_ASM(void)
#define WRAP_ATA_rfCalibration_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rfCalibration_C(void)
#define WRAP_ATA_anttuneStateInitSSM_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_anttuneStateInitSSM_C(void)
#define WRAP_ATA_sysAntTuneSsmEnable_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_sysAntTuneSsmEnable_C(void)
#define WRAP_ATA_anttuneStateStartSSM_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_anttuneStateStartSSM_C(void)
#define WRAP_ATA_anttuneStateWait4SSMrdy_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_anttuneStateWait4SSMrdy_C(void)
#define WRAP_ATA_anttuneStateSetCmdRdy_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_anttuneStateSetCmdRdy_C(void)
#define WRAP_ATA_vcocalStateInitSSM_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_vcocalStateInitSSM_C(void)
#define WRAP_ATA_sysVcoCalSsmEnable_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_sysVcoCalSsmEnable_C(void)
#define WRAP_ATA_vcocalStateStartSSM_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_vcocalStateStartSSM_C(void)
#define WRAP_ATA_vcocalStateWait4SSMrdy_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_vcocalStateWait4SSMrdy_C(void)
#define WRAP_ATA_vcocalStateSetCmdRdy_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_vcocalStateSetCmdRdy_C(void)
#define WRAP_ATA_tempmeasStateInitSSM_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_tempmeasStateInitSSM_C(void)
#define WRAP_ATA_sysTempMeasSsmEnable_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_sysTempMeasSsmEnable_C(void)
#define WRAP_ATA_startInitTempMeasSSM_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_startInitTempMeasSSM_C(void)
#define WRAP_ATA_configureTempMeasSSM_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_configureTempMeasSSM_C(void)
#define WRAP_ATA_tempmeasStateStartSSM_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_tempmeasStateStartSSM_C(void)
#define WRAP_ATA_tempmeasStateWait4SSMrdy_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_tempmeasStateWait4SSMrdy_C(void)
#define WRAP_ATA_tempmeasStateWait4Temperature_C(func)			WRAP_VOID_VOID(func)			// VOIDFUNC ATA_tempmeasStateWait4Temperature_C(void)
#define WRAP_ATA_tempmeasStateSetCmdRdy_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_tempmeasStateSetCmdRdy_C(void)
#define WRAP_ATA_checkModulationType4TX_ASM(func)				WRAP_U8_VOID(func)				// UINT8FUNC ATA_checkModulationType4TX_ASM(void)
#define WRAP_ATA_frcCalib_ASM(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_frcCalib_ASM(void)
#define WRAP_ATA_frcMeas_ASM(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_frcMeas_ASM(void)
#define WRAP_ATA_getT2T3_ASM(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_getT2T3_ASM(void)
#define WRAP_ATA_srcCalib_ASM(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_srcCalib_ASM(void)
#define WRAP_ATA_correctTimer1CompVal_ASM(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_correctTimer1CompVal_ASM(void)
#define WRAP_ATA_shiftRightInt32_ASM(func)						WRAP_I32_I32_U8(func)			// INT32FUNC ATA_shiftRightInt32_ASM(int32_t word, uint8_t shift)
#define WRAP_ATA_shiftRightInt16_ASM(func)						WRAP_I16_I16_U8(func) 			// INT16FUNC ATA_shiftRightInt16_ASM(int16_t word, uint8_t shift)
#define WRAP_ATA_srcMeas_ASM(func)								WRAP_U8_VOID(func)				// UINT8FUNC ATA_srcMeas_ASM(void)
#define WRAP_ATA_eepWRbyte_C(func)								WRAP_VOID_PU8_U8(func)			// VOIDFUNC ATA_eepWRbyte_C(uint8_t *addr, uint8_t data)
#define WRAP_ATA_eepWRblock_C(func)								WRAP_VOID_PU8_PU8_U8(func)		// VOIDFUNC ATA_eepWRblock_C(uint8_t *addr, uint8_t *data, uint8_t len)
#define WRAP_ATA_eepRDblock_C(func)								WRAP_VOID_PU8_U8_PU8(func)		// VOIDFUNC  ATA_eepRDblock_C(uint8_t *addr, uint8_t len, uint8_t *buffer)
#define WRAP_ATA_eepromSecureWrite_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_eepromSecureWrite_C(void)
#define WRAP_ATA_eepRDbyte_ASM(func)							WRAP_U8_PU8(func)				// UINT8FUNC ATA_eepRDbyte_ASM(uint8_t *addr)
#define WRAP_ATA_SpiOpen_C(func)								WRAP_U8_E8_U8_U8(func)			// UINT8FUNC ATA_SpiOpen_C(eSpiModi mode, uint8_t irq, uint8_t dord)
#define WRAP_ATA_spiClose_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC  ATA_spiClose_C(void)
#define WRAP_ATA_initExtIf_C(func)								WRAP_VOID_FP_FP_FP(func)		// VOIDFUNC ATA_initExtIf_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr)
#define WRAP_ATA_PatchSpiReady_ASM(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_PatchSpiReady_ASM(void)
#define WRAP_ATA_SpiClose_ASM(func)								WRAP_VOID_VOID(func)			// VOIDFUNC  ATA_SpiClose_ASM(void)
#define WRAP_ATA_portBisr_ASM(func)								WRAP_VOID_VOID(func)			// VOIDFUNC  ATA_portBisr_ASM(void)
#define WRAP_ATA_portCisr_ASM(func)								WRAP_VOID_VOID(func)			// VOIDFUNC  ATA_portCisr_ASM(void)
#define WRAP_ATA_pureRxModeCtrl_ASM(func)						WRAP_VOID_VOID(func)			// VOIDFUNC  ATA_pureRxModeCtrl_ASM(void)
#define WRAP_ATA_pureRxModeCtrl_v212_ASM(func)					WRAP_VOID_VOID(func)			// VOIDFUNC  ATA_pureRxModeCtrl_v212_ASM(void)
#define WRAP_ATA_setClk_C(func)									WRAP_VOID_U8(func)				// VOIDFUNC ATA_setClk_C(uint8_t val)
#define WRAP_ATA_wdtDisable_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_wdtDisable_C(void)
#define WRAP_ATA_wdtEnable_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_wdtEnable_C(void)
#define WRAP_ATA_SleepMode_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_SleepMode_C(void)
#define WRAP_ATA_Sleep_C(func)									WRAP_VOID_VOID(func)			// VOIDFUNC ATA_Sleep_C(void)
#define WRAP_ATA_currentServiceInit_C(func)						WRAP_VOID_SCC(func)				// VOIDFUNC ATA_currentServiceInit_C(svcChConfig_t config)
#define WRAP_ATA_initPollingConfiguration_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initPollingConfiguration_C(void)
#define WRAP_ATA_initRssiConfiguration_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initRssiConfiguration_C(void)
#define WRAP_ATA_initFacLockedArea_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initFacLockedArea_C(void)
#define WRAP_ATA_clkSwitchFRC_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_clkSwitchFRC_C(void)
#define WRAP_ATA_initChannelSwitchForCurrentService_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initChannelSwitchForCurrentService_C(void)
#define WRAP_ATA_clkSwitchXTO_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_clkSwitchXTO_ASM(void)
#define WRAP_ATA_mulU8U8_ASM(func)								WRAP_U16_U8_U8(func)			// UINT16FUNC ATA_mulU8U8_ASM(uint8_t fac1, uint8_t fac2)
#define WRAP_ATA_mulS8U8_ASM(func)								WRAP_I16_I8_U8(func)			// INT16FUNC ATA_mulS8U8_ASM(int8_t fac1, uint8_t fac2)
#define WRAP_ATA_mpy16u_ASM(func)								WRAP_U32_U16_U16(func)			// UINT32FUNC ATA_mpy16u_ASM(uint16_t fac1, uint16_t fac2)
// #define WRAP_ATA_mpy16u(func)
#define WRAP_ATA_mpy16s_ASM(func)								WRAP_I32_I16_I16(func)			// INT32FUNC ATA_mpy16s_ASM(int16_t fac1, int16_t fac2)
// #define WRAP_ATA_mpy16s(func)
#define WRAP_ATA_waitNus_ASM(func)								WRAP_VOID_U8(func)				// VOIDFUNC ATA_waitNus_ASM(uint8_t time)
#define WRAP_ATA_mulU8UbyCor_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_mulU8UbyCor_ASM(void)
#define WRAP_ATA_divU16U8_ASM(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_divU16U8_ASM(void)
#define WRAP_ATA_copyEepSvc_ASM(func)							WRAP_VOID_PU8_PU8(func)			// VOIDFUNC ATA_copyEepSvc_ASM(uint8_t *dstPtr, uint8_t *srcPtr)
#define WRAP_ATA_copyEepChannel_ASM(func)						WRAP_VOID_PU8_PU8(func)			// VOIDFUNC ATA_copyEepChannel_ASM(uint8_t *dstPtr, uint8_t *srcPtr)
#define WRAP_ATA_copySramSvc_ASM(func)							WRAP_VOID_PU8_PU8(func)			// VOIDFUNC ATA_copySramSvc_ASM(uint8_t *dstPtr, uint8_t *srcPtr)
#define WRAP_ATA_copySramChannel_ASM(func)						WRAP_VOID_PU8_PU8(func)			// VOIDFUNC ATA_copySramChannel_ASM(uint8_t *dstPtr, uint8_t *srcPtr)
#define WRAP_ATA_doIdScan_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_doIdScan_C(void)
#define WRAP_ATA_doIdSubScan_C(func)							WRAP_VOID_PU8(func)				// VOIDFUNC ATA_doIdSubScan_C(uint8_t *addr);
#define WRAP_ATA_initIoConfig_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initIoConfig_C(void)
#define WRAP_ATA_defaultIoConfig_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_defaultIoConfig_C(void)
#define WRAP_ATA_systemInit_C(func)								WRAP_U8_FP_FP_FP(func)				// UINT8FUNC ATA_systemInit_C(pcIntHandler pBisr, pcIntHandler pCisr, irqIntHandler i0isr)
#define WRAP_ATA_doInitialization_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_doInitialization_C(void)
#define WRAP_ATA_checkWakeupSource_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_checkWakeupSource_C(void)
#define WRAP_ATA_initStateMachines_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initStateMachines_C(void)
#define WRAP_ATA_systemCalibAtStartup_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_systemCalibAtStartup_C(void)
#define WRAP_ATA_resetSSMs_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_resetSSMs_C(void)
#define WRAP_ATA_startInitTxRxSSM_C(func)						WRAP_U8_VOID(func)				// UINT8FUNC ATA_startInitTxRxSSM_C(void)
#define WRAP_ATA_startShutDownSSM_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_startShutDownSSM_C(void)
#define WRAP_ATA_doFeInit4TxRxSSM_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_doFeInit4TxRxSSM_C(void)
#define WRAP_ATA_doFevcoRegisterCalculation_C(func)				WRAP_U8_VOID(func)				// UINT8FUNC ATA_doFevcoRegisterCalculation_C(void)
#define WRAP_ATA_shutDownRf_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_shutDownRf_C(void)
#define WRAP_ATA_shutDownFe_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_shutDownFe_C(void)
#define WRAP_ATA_pwrDwnDsp_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_pwrDwnDsp_C(void)
#define WRAP_ATA_ssmInterrupt_C(func)							WRAP_VOID_VOID(func)			// __interrupt void ATA_ssmInterrupt_C(void)
#define WRAP_ATA_switchIdleXTO_ASM(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_switchIdleXTO_ASM(void)
#define WRAP_ATA_setRxActive_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_setRxActive_ASM(void)
#define WRAP_ATA_clrRxActive_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_clrRxActive_ASM(void)
#define WRAP_ATA_setSystemError_ASM(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_setSystemError_ASM(void)
#define WRAP_ATA_pollStateInitCurrentPollingChannel_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_pollStateInitCurrentPollingChannel_C(void)
#define WRAP_ATA_pollStateInitSSM_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_pollStateInitSSM_C(void)
#define WRAP_ATA_pollStateWait4SSMstateGetTelegram_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_pollStateWait4SSMstateGetTelegram_C(void)
#define WRAP_ATA_pollStateWait4ShutdownRdyTRX_C(func)			WRAP_VOID_VOID(func)			// VOIDFUNC ATA_pollStateWait4ShutdownRdyTRX_C(void)
#define WRAP_ATA_pollStateCheck4NextPollingChannel_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_pollStateCheck4NextPollingChannel_C(void)
#define WRAP_ATA_pollStateISR_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_pollStateISR_ASM(void)
#define WRAP_ATA_doFrequencySettingsRx_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_doFrequencySettingsRx_C(void)
#define WRAP_ATA_startInitRxSSM_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_startInitRxSSM_C(void)
#define WRAP_ATA_configureRxSSM_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_configureRxSSM_C(void)
#define WRAP_ATA_initCorrelator_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initCorrelator_C(void)
#define WRAP_ATA_initRxBuffer_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initRxBuffer_C(void)
#define WRAP_ATA_initRssiBuffer_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_initRssiBuffer_C(void)
#define WRAP_ATA_rxStateInitSSM_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxStateInitSSM_C(void)
#define WRAP_ATA_rxStateStartSSM_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxStateStartSSM_C(void)
#define WRAP_ATA_rxStateWait4SSMstateGetTelegram_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxStateWait4SSMstateGetTelegram_C(void)
#define WRAP_ATA_rxStateWait4SSMrdy_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxStateWait4SSMrdy_C(void)
#define WRAP_ATA_pureRxUp_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_pureRxUp_C(void)
#define WRAP_ATA_rssiStateInitSSM_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rssiStateInitSSM_C(void)
#define WRAP_ATA_rssiStateWait4SSMrdy_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rssiStateWait4SSMrdy_C(void)
#define WRAP_ATA_rssiStateStartSSM_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rssiStateStartSSM_C(void)
#define WRAP_ATA_rxStateInitSubchanneling_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxStateInitSubchanneling_C(void)
#define WRAP_ATA_rxStateSubchanneling_Center_Freq_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxStateSubchanneling_Center_Freq_C(void)
#define WRAP_ATA_rxStateSubchanneling_Lower_Freq_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxStateSubchanneling_Lower_Freq_C(void)
#define WRAP_ATA_rxStateSubchanneling_Upper_Freq_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxStateSubchanneling_Upper_Freq_C(void)
#define WRAP_ATA_rxIntConfPathA_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxIntConfPathA_C(void)
#define WRAP_ATA_rxIntConfPathB_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_rxIntConfPathB_C(void)
#define WRAP_ATA_signalEotAtSsmRdy_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_signalEotAtSsmRdy_C(void)
#define WRAP_ATA_startInitTxSSM_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_startInitTxSSM_C(void)
#define WRAP_ATA_configureTxSSM_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_configureTxSSM_C(void)
#define WRAP_ATA_doFrequencySettingsTx_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_doFrequencySettingsTx_C(void)
#define WRAP_ATA_openTimer3forTxing_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_openTimer3forTxing_C(void)
#define WRAP_ATA_sysTxingBufferedMode_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_sysTxingBufferedMode_C(void)
#define WRAP_ATA_sysTxingTransparentMode_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_sysTxingTransparentMode_C(void)
#define WRAP_ATA_setupTxModulator_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_setupTxModulator_C(void)
#define WRAP_ATA_txStateInitSSM_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_txStateInitSSM_C(void)
#define WRAP_ATA_txStateStartSSM_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_txStateStartSSM_C(void)
#define WRAP_ATA_txStateWait4SSMrdy_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_txStateWait4SSMrdy_C(void)
#define WRAP_ATA_txTransparentStateWait4SSMrdy_C(func)			WRAP_VOID_VOID(func)			// VOIDFUNC ATA_txTransparentStateWait4SSMrdy_C(void)
#define WRAP_ATA_txStateTransparentMode_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_txStateTransparentMode_C(void)
#define WRAP_ATA_txStateWait4FillLevel_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_txStateWait4FillLevel_C(void)
#define WRAP_ATA_txStateStartTxModulator_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_txStateStartTxModulator_C(void)
#define WRAP_ATA_txStateStartWait4TransmissionComplete_C(func)	WRAP_VOID_VOID(func)			// VOIDFUNC ATA_txStateStartWait4TransmissionComplete_C(void)
// #define WRAP_ATA_SignatureTestAsm(func)
#define WRAP_ATA_check4extRequests_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_check4extRequests_C(void)
#define WRAP_ATA_systemModeSwitching_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_systemModeSwitching_C(void)
#define WRAP_ATA_tuneCheckSwitching_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_tuneCheckSwitching_C(void)
#define WRAP_ATA_serviceInitSwitching_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_serviceInitSwitching_C(void)
#define WRAP_ATA_miscTriggerSwitching_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_miscTriggerSwitching_C(void)
#define WRAP_ATA_systemFlowCtrl_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_systemFlowCtrl_C(void)
#define WRAP_ATA_sysExeStateMachineFunc_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_sysExeStateMachineFunc_C(void)
#define WRAP_ATA_sysIdleMode_C(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_sysIdleMode_C(void)
#define WRAP_ATA_setIdleMode_C(func)							WRAP_U8_VOID(func)			// UINT8FUNC ATA_setIdleMode_C(void)
#define WRAP_ATA_systemFlowStateWaitXtoReady_C(func)			WRAP_VOID_VOID(func)			// VOIDFUNC ATA_systemFlowStateWaitXtoReady_C(void)
#define WRAP_ATA_systemStartSSM_C(func)							WRAP_VOID_U8(func)				// VOIDFUNC ATA_systemStartSSM_C(uint8_t errorCode)
#define WRAP_ATA_systemWait4SSMrdy_C(func)						WRAP_VOID_U8_U8(func)			// VOIDFUNC ATA_systemWait4SSMrdy_C(uint8_t errorCode, uint8_t shutdownIdx)
#define WRAP_ATA_systemFlowStateShutdownTRX_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_systemFlowStateShutdownTRX_C(void)
#define WRAP_ATA_systemFlowStateWait4ShutdownRdyTRX_C(func)		WRAP_VOID_VOID(func)			// VOIDFUNC ATA_systemFlowStateWait4ShutdownRdyTRX_C(void)
#define WRAP_ATA_systemFlowStateMachineEnd_C(func)				WRAP_VOID_VOID(func)			// VOIDFUNC ATA_systemFlowStateMachineEnd_C(void)
#define WRAP_ATA_systemErrorLoop_C(func)						WRAP_VOID_U8(func)				// VOIDFUNC ATA_systemErrorLoop_C(uint8_t errorCode)
#define WRAP_ATA_startSsmWatchdog_C(func)						WRAP_U8_VOID(func)				// UINT8FUNC ATA_startSsmWatchdog_C(void)
#define WRAP_ATA_stopSsmWatchdog_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_stopSsmWatchdog_C(void)
#define WRAP_ATA_checkAndSwitchIdleXTO_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_checkAndSwitchIdleXTO_C(void)
#define WRAP_ATA_triggerSrcCalibration_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_triggerSrcCalibration_C(void)
#define WRAP_ATA_triggerFrcCalibration_C(func)					WRAP_VOID_VOID(func)			// VOIDFUNC ATA_triggerFrcCalibration_C(void)
#define WRAP_ATA_triggerSelfCheck_C(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_triggerSelfCheck_C(void)
#define WRAP_ATA_wait4avcc_C(func)								WRAP_VOID_VOID(func)			// VOIDFUNC ATA_wait4avcc_C(void)
#define WRAP_ATA_blockingShutDownSSM_C(func)					WRAP_U8_VOID(func)			// UINT8FUNC ATA_blockingShutDownSSM_C(void)
#define WRAP_ATA_setEventPin_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_setEventPin_ASM(void)
// #define WRAP_ATA_timer1Open_C(func)
#define WRAP_ATA_timer1Close_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_timer1Close_ASM(void)
#define WRAP_ATA_timer1ResetRun_ASM(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_timer1ResetRun_ASM(void)
// #define WRAP_ATA_timer2Open_C(func)
#define WRAP_ATA_timer2Close_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_timer2Close_ASM(void)
#define WRAP_ATA_timer2ResetRun_ASM(func)						WRAP_VOID_VOID(func)			// VOIDFUNC ATA_timer2ResetRun_ASM(void)
// #define WRAP_ATA_timer3Open_C(func)
#define WRAP_ATA_timer3Close_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_timer3Close_ASM(void)
// #define WRAP_ATA_timer4Open_C(func)
#define WRAP_ATA_timer4Close_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_timer4Close_ASM(void)
// #define WRAP_ATA_timer5Open_C(func)
#define WRAP_ATA_timer5Close_ASM(func)							WRAP_VOID_VOID(func)			// VOIDFUNC ATA_timer5Close_ASM(void)

#endif /* WRAP_H */