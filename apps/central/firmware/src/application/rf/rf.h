/* ************************************************************************** */
/* Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/** \file rf.h
 *  contains RF implementation of the application
 */

#ifndef _RF_H    /* Guard against multiple inclusion */
#define _RF_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "definitions.h"
#include "../application.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */
	#define SFIFO_SIZE	16  /**< size of ATA8510 Support FIFO */
	#define DFIFO_SIZE	32  /**< size of ATA8510 Data FIFO */
	
	#define ATA8510_SPI_CMD_ID_READ_FILL_LEVEL_RX_FIFO	0x01    /**< ATA8510 'Read Fill Level RX Fifo' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_READ_FILL_LEVEL_RX_FIFO	3   /**< ATA8510 'Read Fill Level RX Fifo' SPI command length */
	
	#define ATA8510_SPI_CMD_ID_READ_FILL_LEVEL_TX_FIFO	0x02    /**< ATA8510 'Read Fill Level TX Fifo' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_READ_FILL_LEVEL_TX_FIFO	3   /**< ATA8510 'Read Fill Level TX Fifo' SPI command length */
	
	#define ATA8510_SPI_CMD_ID_READ_FILL_LEVEL_RSSI_FIFO	0x03    /**< ATA8510 'Read Fill Level RSSI Fifo' SPI command ID */
	
	#define ATA8510_SPI_CMD_ID_GET_EVENT_BYTES	0x04    /**< ATA8510 'Get Event Bytes' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_GET_EVENT_BYTES	4   /**< ATA8510 'Get Event Bytes' SPI command length */
	
	#define ATA8510_SPI_CMD_ID_READ_RSSI_FIFO	0x05    /**< ATA8510 'Read RSSI Fifo' SPI command ID */
	
	#define ATA8510_SPI_CMD_ID_READ_RX_FIFO	0x06    /**< ATA8510 'Read RX Fifo' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_READ_RX_FIFO	DFIFO_SIZE + 3  /**< ATA8510 'Read RX Fifo' SPI command maximum length */
	
	#define ATA8510_SPI_CMD_ID_WRITE_SRAM_REGISTER	0x07    /**< ATA8510 'Write SRAM/Register' SPI command ID */

    #define ATA8510_SPI_CMD_ID_READ_SRAM_REGISTER	0x08    /**< ATA8510 'Read SRAM/Register' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_READ_SRAM_REGISTER	5 + 16  /**< ATA8510 'Read SRAM/Register' SPI command length (maximum 16 bytes to read) */

	#define ATA8510_SPI_CMD_ID_WRITE_EEPROM	0x09    /**< ATA8510 'Write EEPROM' SPI command ID */

    #define ATA8510_SPI_CMD_ID_READ_EEPROM	0x0A    /**< ATA8510 'Read EEPROM' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_READ_EEPROM	5       /**< ATA8510 'Read EEPROM' SPI command length */
	
	#define ATA8510_SPI_CMD_ID_WRITE_TX_FIFO	0x0B    /**< ATA8510 'Write TX Fifo' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_WRITE_TX_FIFO	DFIFO_SIZE + 2	/**< ATA8510 'Write TX Fifo' SPI command maximum length */ 
	
	#define ATA8510_SPI_CMD_ID_WRITE_TX_PREAMBLE_FIFO	0x0C    /**< ATA8510 'Write TX Preamble Fifo' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_WRITE_TX_PREAMBLE_FIFO	SFIFO_SIZE + 2	/**< ATA8510 'Write TX Preamble Fifo' SPI command maximum length */ 
	
	#define ATA8510_SPI_CMD_ID_SET_SYSTEM_MODE	0x0D    /**< ATA8510 'Set System Mode' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_SET_SYSTEM_MODE	3   /**< ATA8510 'Set System Mode' SPI command length */
	
	#define ATA8510_SPI_CMD_ID_CALIBRATE_AND_CHECK	0x0E    /**< ATA8510 'Calibrate and Check' SPI command ID */
	#define ATA8510_SPI_CMD_ID_PATCH_SPI	0x0F    /**< ATA8510 'Patch SPI' SPI command ID */
	
	#define ATA8510_SPI_CMD_ID_GET_VERSION_ROM	0x12    /**< ATA8510 'Get Version ROM' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_GET_VERSION_ROM	3   /**< ATA8510 'Get Version ROM' SPI command length */
	
	#define ATA8510_SPI_CMD_ID_GET_VERSION_FLASH	0x13    /**< ATA8510 'Get Version FLASH' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_GET_VERSION_FLASH	6   /**< ATA8510 'Get Version FLASH' SPI command length */
	
	#define ATA8510_SPI_CMD_ID_CUSTOMER_CONFIGURABLE_COMMAND	0x14    /**< ATA8510 'Customer Configurable Command' SPI command ID */
	#define ATA8510_SPI_CMD_ID_SYSTEM_RESET	0x15    /**< ATA8510 'System Reset' SPI command ID */
	#define ATA8510_SPI_CMD_ID_TRIGGER_EEPROM_SECURE_WRITE	0x16    /**< ATA8510 'EEPROM Secure Write' SPI command ID */
	#define ATA8510_SPI_CMD_ID_SET_VOLTAGE_MONITOR	0x17    /**< ATA8510 'Set Voltage Monitor' SPI command ID */
	
	#define ATA8510_SPI_CMD_ID_OFF_COMMAND	0x18    /**< ATA8510 'OFF Command' SPI command ID */
	#define ATA8510_SPI_CMD_LEN_OFF_COMMAND	2   /**< ATA8510 'OFF Command' SPI command length */
	
	#define ATA8510_SPI_CMD_ID_READ_TEMPERATURE_MEASUREMENT	0x19    /**< ATA8510 'Read Temperature Measurement' SPI command ID */
	#define ATA8510_SPI_CMD_ID_INIT_SRAM_SERVICE 0x1A   /**< ATA8510 'Initialize SRAM Service' SPI command ID */
	#define ATA8510_SPI_CMD_ID_START_RSSI_MEASUREMENT	0x1B    /**< ATA8510 'Start RSSI Measurement' SPI command ID */
	#define ATA8510_SPI_CMD_ID_GET_RSSI_VALUE	0x1C    /**< ATA8510 'Get RSSI value' SPI command ID */
	#define ATA8510_SPI_CMD_ID_READ_RX_FIFO_BYTE_INTERRUPT	0x1D    /**< ATA8510 'Read RX Fifo Byte Interrupt' SPI command ID */
	#define ATA8510_SPI_CMD_ID_READ_RSSI_FIFO_BYTE_INTERRUPT	0x1E    /**< ATA8510 'Read RSSI Fifo Byte Interrupt' SPI command ID */
	#define ATA8510_SPI_CMD_ID_WRITE_TX_FIFO_BYTE_INTERRUPT	0x1F    /**< ATA8510 'Read TX Fifo Byte Interrupt' SPI command ID */
	#define ATA8510_SPI_CMD_ID_WRITE_TX_PREAMBLE_FIFO_BYTE_INTERRUPT	0x20    /**< ATA8510 'Read TX Preamble Fifo Byte Interrupt' SPI command ID */

    #define ATA8510_SRAM_ADDR_TRX_CONF_SYSTEM_MODE_CONFIG    0x2E0  /**< SRAM Address of ATA8510 variable trxConf.systemModeConfig (contains operation mode information) */
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /** typedef for ATA8510 operation modes */
    typedef enum {
		OPM_IDLE = 0x00,    /**< IDLE Mode */
		OPM_TX, /**< TX Mode */
		OPM_RX, /**< RX Mode */
		OPM_POLLING /**< POLLING Mode */
	}eOpm_t;
	
    /** typedef for ATA8510 RX/TX modes*/
	typedef enum {
		BUFFERED_MODE = 0x00,   /**< buffered mode */
		TRANSPARENT_MODE    /**< transparent mode */
	}eTransparentMode_t;
	
    /** typedef for ATA8510 Idle Mode selector */
	typedef enum {
		IDLE_RC = 0x00, /**< Idle Mode running with RC oscillator */
		IDLE_XTO    /**< Idle Mode running with XTO oscillator */
	}eIdleModeSelector_t;
	
    /** typedef for ATA8510 VCO tuning */
	typedef enum {
		VCO_TUNE_OFF = 0x00,    /**< VCO tuning disabled */
		VCO_TUNE_ON /**< VCO tuning enabled */
	}eVcoTune_t;

    /** typedef for ATA8510 antenna tuning */
	typedef enum {
		ANT_TUNE_OFF = 0x00,    /**< antenna tuning disabled */
		ANT_TUNE_ON /**< antenna tuning enabled */
	}eAntTune_t;
	
    /** typedef for ATA8510 RF calibration */
	typedef enum {  
		RF_CAL_OFF = 0x00,  /**< RF calibration disabled */
		RF_CAL_ON   /**< RF calibration enabled */
	}eRfCal_t;

	/** data structure for ATA8510 system mode configuration */
	struct sSystemModeConfig {
		union {
			struct {
				eOpm_t opm : 2; /**< Bit 0..1: operation mode bits */
				eTransparentMode_t tmden : 1;	/**< Bit 2: transparent mode enable bit */
				uint8_t rfu_bit_3 : 1;	/**< Bit 3: rfu */
				eIdleModeSelector_t idle_mode_selector : 1;	/**< Bit 4:  Idle mode (RC/XTO) selector */
				eVcoTune_t vco_tune : 1;	/**< Bit 5:  VCO tuning enable */
				eAntTune_t ant_tune : 1;	/**< Bit 6:  Antenna tuning enable */
				eRfCal_t rf_cal : 1;	/**< Bit 7:  RF calibration enable */
			};
			uint8_t raw;    /**< 8-bit system mode configuration */
		};
	}__PACKED;
    /** typedef for struct ::sSystemModeConfig */
	typedef struct sSystemModeConfig sSystemModeConfig_t;
	
    /** typedef for ATA8510 services */
	typedef enum {
		SERVICE_0 = 0x00,	/**< Service 0: EEPROM service */
		SERVICE_1,  /**< Service 1: EEPROM service */
		SERVICE_2,	/**< Service 2: EEPROM service */
		SERVICE_3,	/**< Service 3: SRAM service */
		SERVICE_4,	/**< Service 4: SRAM service */
	}eService_t;
	
    /** typedef for ATA8510 channels*/
	typedef enum {
		CHANNEL_0 = 0x00,   /**< Channel 0 */
		CHANNEL_1,  /**< Channel 1 */
		CHANNEL_2,  /**< Channel 2 */
	}eChannel_t;
	
    /** typedef for ATA8510 Path A selection */
	typedef enum {
		PATH_A_OFF = 0x00,  /**< Path A disabled */
		PATH_A_ON   /**< Path A enabled */
	}ePathA_t;
	/** typedef for ATA8510 Path B selection */
	typedef enum {
		PATH_B_OFF = 0x00,  /**< Path B disabled */
		PATH_B_ON   /**< Path B enabled */
	}ePathB_t;

    /** data structure for ATA8510 service channel configuration */
	struct sServiceChannelConfig {
		union {
            struct {
                eService_t ser : 3;	/**< Bit 0..2: RF service bits */
                uint8_t rfu_bit_3 : 1;	/**< Bit 3: rfu */
                eChannel_t ch : 2;	/**< Bit 4..5: RF channel bits */
                ePathA_t ena_path_a : 1;	/**< Bit 6: Enable Path A */
                ePathB_t ena_path_b : 1;	/**< Bit 7: Enable Path B */
            };
            uint8_t raw;    /**< 8-bit service channel configuration */
		};
	}__PACKED;
    /** typedef for ::sServiceChannelConfig */
	typedef struct sServiceChannelConfig sServiceChannelConfig_t;
	
	
	/** data structure for ATA8510 event byte 'System' */
	struct sSystemEvent {
		union {
			struct {
				uint8_t dfifo_tx : 1;	/**< Bit 0: TX DFIFO Overflow/Underflow */
				uint8_t dfifo_rx : 1;	/**< Bit 1: RX DFIFO Overflow/Underflow */
				uint8_t sfifo : 1;      /**< Bit 2: SFIFO Overflow/Underflow */
				uint8_t lowbatt : 1;	/**< Bit 3: Low Battery */
				uint8_t avcclow : 1;	/**< Bit 4: AVCC Low */
				uint8_t sys_rdy : 1;	/**< Bit 5: System Ready */
				uint8_t cmd_rdy : 1;	/**< Bit 6: Command Ready */
				uint8_t sys_err : 1;	/**< Bit 7: System Error */
			};
			uint8_t raw;    /**< 8-bit event byte */
		};
	}__PACKED;
    /** typedef for struct ::sSystemEvent */
	typedef struct sSystemEvent sSystemEvent_t;
	
    /** data structure for ATA8510 event byte 'Events */
	struct sEventsEvent {
		union {
			struct {
				uint8_t eotb : 1;	/**< Bit 0: End Of Telegram Path B */
				uint8_t sotb : 1;	/**< Bit 1: Start of Telegram Path B */
				uint8_t wcokb : 1;	/**< Bit 2: Wake Check OK Path B */
				uint8_t idchkb : 1;	/**< Bit 3: ID Check Path B */
				uint8_t eota : 1;	/**< Bit 4: End Of Telegram Path A */
				uint8_t sota : 1;	/**< Bit 5: Start Of Telegram Path A */
				uint8_t wcoka : 1;	/**< Bit 6: Wake Check OK Path A */
				uint8_t idcka : 1;	/**< Bit 7: ID Check Path A */
			};
			uint8_t raw;    /**< 8-bit event byte */
		};
	}__PACKED;
    /** typedef for ::sEventsEvent */
	typedef struct sEventsEvent sEventsEvent_t;
	
    /** data structure for ATA8510 event byte 'Power'*/
	struct sPowerEvent {
		union {
			struct {
				uint8_t npwron1 : 1;	/**< Bit 0: Wakeup via NPWRON1/PC1 */
				uint8_t npwron2 : 1;	/**< Bit 1: Wakeup via NPWRON2/PC2 */
				uint8_t npwron3 : 1;	/**< Bit 2: Wakeup via NPWRON3/PC3 */
				uint8_t npwron4 : 1;	/**< Bit 3: Wakeup via NPWRON4/PC4 */
				uint8_t npwron5 : 1;	/**< Bit 4: Wakeup via NPWRON5/PC5 */
				uint8_t npwron6 : 1;	/**< Bit 5: Wakeup via NPWRON6/PC6 */
				uint8_t debug : 1;	/**< Bit 6: Debug Event */
				uint8_t pwron : 1;	/**< Bit 7: Wakeup via PWRON/PB4 */
			};
			uint8_t raw;    /**< 8-bit event byte */
		};
	}__PACKED;
    /** typedef for ::sPowerEvent */
	typedef struct sPowerEvent sPowerEvent_t;
	
    /** typedef for ATA8510 event byte 'Config' */
	typedef struct sServiceChannelConfig sConfigEvent_t;
	
    /** data structure for ATA8510 events */
	struct sEvents {
		sSystemEvent_t system;  /**< system event byte */
		sEventsEvent_t events;  /**< events event byte */
		sPowerEvent_t power;    /**< power event byte */
		sConfigEvent_t config;  /**< config event byte */
	}__PACKED;
    /** typedef for ::sEvents */
	typedef struct sEvents sEvents_t;
    
    /** typedef for ATA8510 Error Codes */
    typedef enum {
        DEBUG_ERROR_CODE_SYSTEM_ERROR_EEPROM_NOT_VALID = 0x00,	/**< This error code is set if the EEPROM content is not valid. If this error occurs, the software stays in an endless loop. SPI communication is still possible.*/
        DEBUG_ERROR_CODE_SETIDLEMODE_MISS_SSMRDY = 0x01,	/**< This error code is set if the shut down SSM does not signal SSM_RDY.*/
        DEBUG_ERROR_CODE_SETIDLEMODE_TIMER_LOCKED = 0x02,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for shutdown.*/
        DEBUG_ERROR_CODE_RX_STATESTARTSSM_TIMER_LOCKED = 0x3,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for RX.*/
        DEBUG_ERROR_CODE_RX_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT = 0x04,	/**< This error code is set if the GET_TELEGRAM is not started at the right time. If this error occurs, the system is switched to IDLEMode via shut down SSM.*/
        DEBUG_ERROR_CODE_TX_STATESTARTSSM_TIMER_LOCKED = 0x05,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for Tx.*/
        DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT = 0x06,	/**< This error code is set if the Tx SSM is not started at the right time. If this error occurs, the system is switched to IDLEMode via shut down SSM.*/
        DEBUG_ERROR_CODE_POLL_STATESTARTSSM_TIMER_LOCKED = 0x07,	/**< --> ERROR CODE NOT USED IN FIRMWARE!!!!*/
        DEBUG_ERROR_CODE_POLL_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT = 0x08, /**< This error code is set if the GET_TELEGRAM is not started at the right time. If this error occurs, the system is switched to IDLEMode via shut down SSM.*/
        DEBUG_ERROR_CODE_ANTTUNE_STATESTARTSSM_TIMER_LOCKED = 0x09,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for antenna tuning.*/
        DEBUG_ERROR_CODE_ANTTUNE_STATEWAIT4SSMRDY_TIMEOUT = 0x0A,	/**< This error code is set if the antenna tuning SSM is not competed at the right time. If this error occurs, the system is switched to IDLEMode via shut down SSM.*/
        DEBUG_ERROR_CODE_VCOCAL_STATESTARTSSM_TIMER_LOCKED = 0x0B, 	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for VCO tuning.*/
        DEBUG_ERROR_CODE_VCOCAL_STATEWAIT4SSMRDY_TIMEOUT = 0x0C,	/**< This error code is set if the VCO tuning SSM is not competed at the right time. If this error occurs, the system is switched to IDLEMode via shut down SSM.*/
        DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMER_LOCKED = 0x0D,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for shut down SSM.*/
        DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT = 0x0E,	/**< This error code is set if the shut down SSM has not completed at the right time.*/
        DEBUG_ERROR_CODE_POLLING_TIMER1_LOCKED = 0x0F,	/**< This error code is set if the polling timer (Timer1) is not available for polling.*/
        DEBUG_ERROR_CODE_INVALID_OPM_SWITCHING = 0x10,	/**< This error code is set if the OPM switching is not allowed.*/
        DEBUG_ERROR_CODE_INVALID_OPM_MODE_DURING_TUNE_AND_CHECK = 0x11,	/**< This error code is set if TuneAndCheck is requested via SPI and the system is not in IDLEMode.*/
        DEBUG_ERROR_CODE_AVCCLOW_DURING_TX = 0x12,	/**< This error code is set if AVCCLOW interrupt is executed and the system is in TXMode.*/
        DEBUG_ERROR_CODE_SERVICE_INIT_FAILURE = 0x13,	/**< This error code is set if the SRAM service initialization contains wrong parameters.*/
        DEBUG_ERROR_CODE_DFIFO_OVER_UNDER_FLOW = 0x14,	/**< This error code is set if a data FIFO overflow/underflow is detected. The corresponding interrupt is disabled to prevent continuous overflow/underflow interrupts.*/
        DEBUG_ERROR_CODE_SFIFO_OVER_UNDER_FLOW = 0x15,	/**< This error code is set if an RSSI/preamble FIFO overflow/underflow is detected. The corresponding interrupt is disabled to prevent continuous overflow/underflow interrupts.*/
        DEBUG_ERROR_CODE_RSSI_STATESTARTSSM_TIMER_LOCKED = 0x16,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for RSSI measurement.*/
        DEBUG_ERROR_CODE_SRC_FRC_CALIB_FAILED = 0x17,	/**< This error code is set if Timer2 and Timer3 are not available for SRC/FRC calibration.*/
        DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR = 0x18,	/**< This error code is set if GetRxTelegram SSM returns with error code and SSM_RDY.*/
        DEBUG_ERROR_CODE_TEMPMEAS_STATESTARTSSM_TIMER_LOCKED = 0x19,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for temperature measurement.*/
        DEBUG_ERROR_CODE_TEMPMEAS_STATEWAIT4SSMRDY_TIMEOUT = 0x1A,	/**< This error code is set if the temperature measurement SSM has not completed at the right time.*/
        DEBUG_ERROR_CODE_AVCCLOW_TIMEOUT = 0x1B,	/**< This error code is set if AVCC is not enabled at the right time (180?s).*/
        DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMER_LOCKED = 0x1C,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for subchanneling on center frequency.*/
        DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMER_LOCKED = 0x1D,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for subchanneling on lower frequency.*/
        DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMER_LOCKED = 0x1E,	/**< This error code is set if the SSM watchdog timer (Timer2) is not available for subchanneling on upper frequency.*/
        DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMEOUT = 0x1F,	/**< This error code is set if the SSM used for subchanneling at the center frequency has not completed at the right time.*/
        DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMEOUT = 0x20,	/**< This error code is set if the SSM used for subchanneling at the lower frequency has not completed at the right time.*/
        DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMEOUT = 0x21,	/**< This error code is set if the SSM used for subchanneling at the upper frequency has not completed at the right time.  */      
    } eErrorCode_t;
    /** typedef for ATA8510 SSM error codes */
    typedef enum {
        DEBUG_SSM_ERROR_CODE_PLL_ENABLE = 0x81,	/**< This error code is set if an error occurs in the PLL enable SSM. */
        DEBUG_SSM_ERROR_CODE_PLL_LOCK = 0x82,	/**< This error code is set if an error occurs in the PLL lock SSM. */
        DEBUG_SSM_ERROR_CODE_RX_DSP_ENABLE = 0x83,	/**< This error code is set if an error occurs in the Rx DSP enable SSM. */
        DEBUG_SSM_ERROR_CODE_RX_DSP_DISABLE = 0x84,	/**< This error code is set if an error occurs in the Rx DSP disable SSM. */
        DEBUG_SSM_ERROR_CODE_TX_DSP_ENABLE = 0x85,	/**< This error code is set if an error occurs in the Tx DSP enable SSM. */
        DEBUG_SSM_ERROR_CODE_TX_DSP_DISABLE = 0x86,	/**< This error code is set if an error occurs in the Tx DSP disable SSM. */
        DEBUG_SSM_ERROR_CODE_RX_TO_TX = 0x87,	/**< This error code is set if an error occurs in the Rx to Tx SSM. */
        DEBUG_SSM_ERROR_CODE_TX_TO_RX = 0x88,	/**< This error code is set if an error occurs in the Tx to Rx SSM. */
        DEBUG_SSM_ERROR_CODE_GET_TELEGRAM = 0x89,	/**< This error code is set if an error occurs in the get telegram SSM. */
        DEBUG_SSM_ERROR_CODE_SEND_TELEGRAM = 0x8A,	/**< This error code is set if an error occurs in the send telegram SSM. */
        DEBUG_SSM_ERROR_CODE_SHUT_DOWN = 0x8B,	/**< This error code is set if an error occurs in the shut down SSM. */
        DEBUG_SSM_ERROR_CODE_VCO_TUNING = 0x8C,	/**< This error code is set if an error occurs in the VCO tuning SSM. */
        DEBUG_SSM_ERROR_CODE_ANT_TUNING = 0x8D,	/**< This error code is set if an error occurs in the antenna tuning SSM. */
    } eSsmErrorCode_t;
    
    /** data structure for debug information in SRAM of ATA8510*/
    struct sDebug {
        eErrorCode_t error_code;    /**< ATA8510 error code */
        uint8_t ssm_error_code; /**< ATA8510 SSM error code */
    }__PACKED;
    /** typedef for ::sDebug */
    typedef struct sDebug sDebug_t;
    
    /** data structure for public data of module RF */
    struct sRfData {
        sEvents_t events;   /**< ATA8510 event bytes */
        // volatile bool is_irq;
    };
    /** typedef for ::sRfData */
    typedef struct sRfData sRfData_t;    
    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************
    /** application data for module RF */
    extern sRfData_t rf_data;

    /**
     * RF module initialization function
     */
    extern void RF_Initialize(void);
    
    /**
     * RF module main function
     * @param p_msg message handle to process in RF module main function
     */
    extern void RF_Tasks(sMsg_T *p_msg);
    /**
     * Apply Reset to ATA8510 module
     */
    extern void RF_Reset(void);
    /**
     * Check if RF module is in Idle mode
     * @return true if in Idle mode, otherwise false
     */
    extern bool RF_IsIdleMode(void);
    /**
     * Check if RF module is in RX mode
     * @return true if in RX mode, otherwise false
     */
    extern bool RF_IsRxMode(void);
    /**
     * Check if RF module is in TX mode
     * @return true if in TX mode, otherwise false
     */
    extern bool RF_IsTxMode(void);
    /**
     * Set RF module to Idle mode
     */
    extern void RF_SetIdleMode(void);
    /**
     * Set RF module to RX(buffered) mode
     */
    extern void RF_SetRxModeBuffered(void);
    /**
     * Set RF module to TX(buffered) mode and send data 
     * @param len   number of bytes to transmit
     * @param p_data    pointer to data to tranmsit
     */
    extern void RF_SetTxModeBuffered(uint8_t len, uint8_t *p_data);
    /**
     * Get ATA8510 Debug information
     * @return debug information
     */
    extern sDebug_t RF_GetDebug(void);
    /**
     * Read ATA8510 RX FIFO Fill Level Information via SPI
     * @return number of bytes in RX FIFO
     */
    extern uint8_t RF_ATA8510_SPI_ReadFillLevelRxFifo(void);
    /**
     * Read ATA8510 Event Bytes Information via SPI
     * @param p_data    pointer to events
     * @return  number of event bytes read from SPI
     */
    extern uint8_t RF_ATA8510_SPI_GetEventBytes(sEvents_t *p_data);
    /**
     * Read ATA8510 RX FIFO via SPI
     * @param len number of bytes to read from RX FIFO
     * @param p_data pointer to data 
     * @return number of bytes read from RX FIFO
     */
    extern uint8_t RF_ATA8510_SPI_ReadRxFifo(uint8_t len, uint8_t *p_data);
    /**
     * Read from ATA8510 SRAM/Register space via SPI
     * @param len   number of bytes to read
     * @param address   start address to read
     * @param p_data    pointer to data 
     * @return  number of bytes read from SPI
     */
    extern uint8_t RF_ATA8510_SPI_ReadSramRegister(uint8_t len, uint16_t address, uint8_t *p_data );
    /**
     * Read from ATA8510 EEPROM space via SPI
     * @param address   EEPROM address to read
     * @return  EEPROM content
     */
    extern uint8_t RF_ATA8510_SPI_ReadEeprom(uint16_t address);
    /**
     * Write to ATA8510 TX FIFO via SPI
     * @param len   number of bytes to write to ATA8510 TX FIFO
     * @param p_data    pointer to data
     * @return number of bytes transmitted via SPI
     */
    extern uint8_t RF_ATA8510_SPI_WriteTxFifo(uint8_t len, uint8_t *p_data);
/**
     * Write to ATA8510 Support FIFO via SPI
     * @param len   number of bytes to write to ATA8510 Support FIFO
     * @param p_data    pointer to data
     * @return number of bytes transmitted via SPI
     */    
    extern uint8_t RF_ATA8510_SPI_WriteTxPreambleFifo(uint8_t len, uint8_t *p_data);
    /**
     * Set ATA8510 System Mode 
     * @param   mode system mode configuration
     * @param service_channel   service channel configuration
     * @return number of bytes transmitted via SPI
     */
    extern uint8_t RF_ATA8510_SPI_SetSystemMode(sSystemModeConfig_t mode, sServiceChannelConfig_t service_channel);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _RF_H */

/* *****************************************************************************
 End of File
 */
