/* ************************************************************************** */
/* Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <string.h>

#include "rf.h"
#include "../application.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
sRfData_t rf_data;

volatile bool _is_irq = false;

#define RF_ASSERT(test,fmt, ...) { \
    SYS_DEBUG_PRINT(SYS_ERROR_DEBUG, "\r\n[RF_ASSERT] %s(..) : ",__func__); \
    SYS_DEBUG_PRINT(SYS_ERROR_DEBUG, fmt, ##__VA_ARGS__); \
}

#define RF_NRESET_ENABLE()  EXT1_ATA8510_NRESET_PCINT8_PC0_OutputEnable()
#define RF_NRESET_DISABLE()  EXT1_ATA8510_NRESET_PCINT8_PC0_InputEnable()
#define RF_NRESET_SET() EXT1_ATA8510_NRESET_PCINT8_PC0_Set()
#define RF_NRESET_CLEAR() EXT1_ATA8510_NRESET_PCINT8_PC0_Clear()


#define RF_PWRON_ENABLE() EXT1_ATA8510_PWRON_PCINT4_LED1_PB4_OutputEnable()
#define RF_PWRON_DISABLE() EXT1_ATA8510_PWRON_PCINT4_LED1_PB4_InputEnable()
#define RF_PWRON_SET()  EXT1_ATA8510_PWRON_PCINT4_LED1_PB4_Set()
#define RF_PWRON_CLEAR()  EXT1_ATA8510_PWRON_PCINT4_LED1_PB4_Clear()

#define RF_IRQ_PIN  EIC_PIN_14
#define RF_IRQ_GET()    (((PORT_REGS->GROUP[1].PORT_IN >> 14U)) & 0x01U)

#define RF_SPI_NSS_ENABLE() EXT1_ATA8510_PCINT5_INT1_NSS_PB5_OutputEnable()
#define RF_SPI_NSS_DISABLE()    EXT1_ATA8510_PCINT5_INT1_NSS_PB5_InputEnable()
#define RF_SPI_NSS_SET()    EXT1_ATA8510_PCINT5_INT1_NSS_PB5_Set()
#define RF_SPI_NSS_CLEAR()  EXT1_ATA8510_PCINT5_INT1_NSS_PB5_Clear()

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*
 * IRQ Functions
 */
static void _RF_IrqCallback(uintptr_t context) {
    _is_irq = (bool)RF_IRQ_GET();
    if (_is_irq) {
        sMsg_T msg;
        msg.id = MSG_ID_RF_IRQ;
        xQueueSend(app_data.msg_queue, &msg, 0);
    }
    
}

/*
 * Command Functions
 */
uint8_t _RF_ATA8510_SPI_Send(uint8_t len, uint8_t *p_tx, uint8_t *p_rx) { 

    RF_SPI_NSS_CLEAR();
    APPLICATION_DelayUs(100);
    SERCOM1_SPI_WriteRead(p_tx, len, p_rx, len);
    do {
    } while ( SERCOM1_SPI_IsBusy() );
    APPLICATION_DelayUs(100);
    RF_SPI_NSS_SET();

	rf_data.events.system.raw = p_rx[0];
	rf_data.events.events.raw = p_rx[1];
	return len; 
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */
void RF_Initialize(void) {

    RF_NRESET_ENABLE();
    RF_PWRON_ENABLE(); 

    EIC_CallbackRegister(RF_IRQ_PIN, _RF_IrqCallback, (uintptr_t)NULL);
    EIC_InterruptEnable(RF_IRQ_PIN);
    _is_irq = false;
}

void RF_Tasks(sMsg_T *p_msg) {
    if ( p_msg->id == MSG_ID_RF_IRQ ) {
        RF_ATA8510_SPI_GetEventBytes(NULL);
    } else {
    }
}

void RF_Reset(void) {
    EIC_InterruptDisable(RF_IRQ_PIN);
    
    RF_PWRON_SET();
    
    RF_NRESET_CLEAR();
    APPLICATION_DelayUs(500);
    RF_NRESET_SET();

    EIC_REGS->EIC_INTFLAG |= (1UL << (uint32_t)RF_IRQ_PIN);
    EIC_InterruptEnable(RF_IRQ_PIN);

    APPLICATION_DelayUs(1000);
    RF_PWRON_CLEAR();
}

static sSystemModeConfig_t RF_ATA8510_GetOpm(void) {
    sSystemModeConfig_t opm;
    RF_ATA8510_SPI_ReadSramRegister(
            1, 
            ATA8510_SRAM_ADDR_TRX_CONF_SYSTEM_MODE_CONFIG, 
            (uint8_t *)&opm 
        );
    return opm;
}

bool RF_IsIdleMode(void) {
    sSystemModeConfig_t mode = RF_ATA8510_GetOpm();
    if ( mode.opm == OPM_IDLE )
        return true;
    return false;
}
bool RF_IsRxMode(void) {
    sSystemModeConfig_t mode = RF_ATA8510_GetOpm();
    if ( mode.opm == OPM_RX )
        return true;
    return false;
}
bool RF_IsTxMode(void) {
    sSystemModeConfig_t mode = RF_ATA8510_GetOpm();
    if ( mode.opm == OPM_TX )
        return true;
    return false;
}

void RF_SetIdleMode(void) {
    /*
     * Set ATA8510 System Mode to Idle Mode(RC)
     */
    sSystemModeConfig_t mode = {
        .opm = OPM_IDLE,
        .tmden = TRANSPARENT_MODE,
        .idle_mode_selector = IDLE_RC,
        .vco_tune = VCO_TUNE_OFF,
        .ant_tune = ANT_TUNE_OFF,
        .rf_cal = RF_CAL_OFF,
    };
    sServiceChannelConfig_t service_channel;
    service_channel.raw = app_data.service_channel_config;
    
    RF_ATA8510_SPI_SetSystemMode(mode, service_channel);
}


void RF_SetRxModeBuffered(void) {
    sSystemModeConfig_t mode = {
        .opm = OPM_RX,
        .tmden = BUFFERED_MODE,
        .idle_mode_selector = IDLE_RC,
        .vco_tune = VCO_TUNE_OFF,
        .ant_tune = ANT_TUNE_OFF,
        .rf_cal = RF_CAL_OFF,
    };
    sServiceChannelConfig_t service_channel;
    service_channel.raw = app_data.service_channel_config;
    RF_ATA8510_SPI_SetSystemMode(mode, service_channel);
}


void RF_SetTxModeBuffered(uint8_t len, uint8_t *p_data) {
    
    const uint8_t preamble[] = {0x30, 0x55, 0x55, 0x55, 0x55, 0x55, 0x56};
    
    RF_ATA8510_SPI_WriteTxPreambleFifo(sizeof(preamble), (uint8_t *)preamble);
    
    RF_ATA8510_SPI_WriteTxFifo(len, p_data);
    
    sSystemModeConfig_t mode = {
        .opm = OPM_TX,
        .tmden = BUFFERED_MODE,
        .idle_mode_selector = IDLE_RC,
        .vco_tune = VCO_TUNE_OFF,
        .ant_tune = ANT_TUNE_OFF,
        .rf_cal = RF_CAL_OFF,
    };
    sServiceChannelConfig_t service_channel;
    service_channel.raw = app_data.service_channel_config;
    RF_ATA8510_SPI_SetSystemMode(mode, service_channel);
}


sDebug_t RF_GetDebug(void) {

    const sMsgPair_T _error_codes[] = {
        { DEBUG_ERROR_CODE_SYSTEM_ERROR_EEPROM_NOT_VALID, "DEBUG_ERROR_CODE_SYSTEM_ERROR_EEPROM_NOT_VALID"},
        { DEBUG_ERROR_CODE_SETIDLEMODE_MISS_SSMRDY, "DEBUG_ERROR_CODE_SETIDLEMODE_MISS_SSMRDY"},
        { DEBUG_ERROR_CODE_SETIDLEMODE_TIMER_LOCKED, "DEBUG_ERROR_CODE_SETIDLEMODE_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_RX_STATESTARTSSM_TIMER_LOCKED, "DEBUG_ERROR_CODE_RX_STATESTARTSSM_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_RX_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT, "DEBUG_ERROR_CODE_RX_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT"},
        { DEBUG_ERROR_CODE_TX_STATESTARTSSM_TIMER_LOCKED, "DEBUG_ERROR_CODE_TX_STATESTARTSSM_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT, "DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT"},
        { DEBUG_ERROR_CODE_POLL_STATESTARTSSM_TIMER_LOCKED, "DEBUG_ERROR_CODE_POLL_STATESTARTSSM_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_POLL_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT, "DEBUG_ERROR_CODE_POLL_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT"},
        { DEBUG_ERROR_CODE_ANTTUNE_STATESTARTSSM_TIMER_LOCKED, "DEBUG_ERROR_CODE_ANTTUNE_STATESTARTSSM_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_ANTTUNE_STATEWAIT4SSMRDY_TIMEOUT, "DEBUG_ERROR_CODE_ANTTUNE_STATEWAIT4SSMRDY_TIMEOUT"},
        { DEBUG_ERROR_CODE_VCOCAL_STATESTARTSSM_TIMER_LOCKED, "DEBUG_ERROR_CODE_VCOCAL_STATESTARTSSM_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_VCOCAL_STATEWAIT4SSMRDY_TIMEOUT, "DEBUG_ERROR_CODE_VCOCAL_STATEWAIT4SSMRDY_TIMEOUT"},
        { DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMER_LOCKED, "DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT, "DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT"},
        { DEBUG_ERROR_CODE_POLLING_TIMER1_LOCKED, "DEBUG_ERROR_CODE_POLLING_TIMER1_LOCKED"},
        { DEBUG_ERROR_CODE_INVALID_OPM_SWITCHING, "DEBUG_ERROR_CODE_INVALID_OPM_SWITCHING"},
        { DEBUG_ERROR_CODE_INVALID_OPM_MODE_DURING_TUNE_AND_CHECK, "DEBUG_ERROR_CODE_INVALID_OPM_MODE_DURING_TUNE_AND_CHECK"},
        { DEBUG_ERROR_CODE_AVCCLOW_DURING_TX, "DEBUG_ERROR_CODE_AVCCLOW_DURING_TX"},
        { DEBUG_ERROR_CODE_SERVICE_INIT_FAILURE, "DEBUG_ERROR_CODE_SERVICE_INIT_FAILURE"},
        { DEBUG_ERROR_CODE_DFIFO_OVER_UNDER_FLOW, "DEBUG_ERROR_CODE_DFIFO_OVER_UNDER_FLOW"},
        { DEBUG_ERROR_CODE_SFIFO_OVER_UNDER_FLOW, "DEBUG_ERROR_CODE_SFIFO_OVER_UNDER_FLOW"},
        { DEBUG_ERROR_CODE_RSSI_STATESTARTSSM_TIMER_LOCKED, "DEBUG_ERROR_CODE_RSSI_STATESTARTSSM_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_SRC_FRC_CALIB_FAILED, "DEBUG_ERROR_CODE_SRC_FRC_CALIB_FAILED"},
        { DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR, "DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR"},
        { DEBUG_ERROR_CODE_TEMPMEAS_STATESTARTSSM_TIMER_LOCKED, "DEBUG_ERROR_CODE_TEMPMEAS_STATESTARTSSM_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_TEMPMEAS_STATEWAIT4SSMRDY_TIMEOUT, "DEBUG_ERROR_CODE_TEMPMEAS_STATEWAIT4SSMRDY_TIMEOUT"},
        { DEBUG_ERROR_CODE_AVCCLOW_TIMEOUT, "DEBUG_ERROR_CODE_AVCCLOW_TIMEOUT"},
        { DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMER_LOCKED, "DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMER_LOCKED, "DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMER_LOCKED, "DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMER_LOCKED"},
        { DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMEOUT, "DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMEOUT"},
        { DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMEOUT, "DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMEOUT"},
        { DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMEOUT, "DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMEOUT"},
    };
    const sMsgPair_T _ssm_error_codes[] = {
        { DEBUG_SSM_ERROR_CODE_PLL_ENABLE, "DEBUG_SSM_ERROR_CODE_PLL_ENABLE" },
        { DEBUG_SSM_ERROR_CODE_PLL_LOCK, "DEBUG_SSM_ERROR_CODE_PLL_LOCK" },
        { DEBUG_SSM_ERROR_CODE_RX_DSP_ENABLE, "DEBUG_SSM_ERROR_CODE_RX_DSP_ENABLE" },
        { DEBUG_SSM_ERROR_CODE_RX_DSP_DISABLE, "DEBUG_SSM_ERROR_CODE_RX_DSP_DISABLE" },
        { DEBUG_SSM_ERROR_CODE_TX_DSP_ENABLE, "DEBUG_SSM_ERROR_CODE_TX_DSP_ENABLE" },
        { DEBUG_SSM_ERROR_CODE_TX_DSP_DISABLE, "DEBUG_SSM_ERROR_CODE_TX_DSP_DISABLE" },
        { DEBUG_SSM_ERROR_CODE_RX_TO_TX, "DEBUG_SSM_ERROR_CODE_RX_TO_TX" },
        { DEBUG_SSM_ERROR_CODE_TX_TO_RX, "DEBUG_SSM_ERROR_CODE_TX_TO_RX" },
        { DEBUG_SSM_ERROR_CODE_GET_TELEGRAM, "DEBUG_SSM_ERROR_CODE_GET_TELEGRAM" },
        { DEBUG_SSM_ERROR_CODE_SEND_TELEGRAM, "DEBUG_SSM_ERROR_CODE_SEND_TELEGRAM" },
        { DEBUG_SSM_ERROR_CODE_SHUT_DOWN, "DEBUG_SSM_ERROR_CODE_SHUT_DOWN" },
        { DEBUG_SSM_ERROR_CODE_VCO_TUNING, "DEBUG_SSM_ERROR_CODE_VCO_TUNING" },
        { DEBUG_SSM_ERROR_CODE_ANT_TUNING, "DEBUG_SSM_ERROR_CODE_ANT_TUNING" },
    };    
    sDebug_t debug;
    RF_ATA8510_SPI_ReadSramRegister(2, 0x300, (uint8_t *)&debug );

    /*
     * Error Code @ 0x0300
     */
    const char *p_error_code_msg = APPLICATION_GetMsg(
        debug.error_code, 
        _error_codes,
        sizeof(_error_codes)/sizeof(*_error_codes)
        );
    if ( p_error_code_msg != NULL){
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\n[ERROR] ");
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, p_error_code_msg);
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\n");
    }

    /*
     * SSM Error Code @ 0x0301
     */
    const char *p_ssm_error_code_msg = APPLICATION_GetMsg(
        debug.ssm_error_code, 
        _ssm_error_codes,
        sizeof(_ssm_error_codes)/sizeof(*_ssm_error_codes)
        );
    if ( p_ssm_error_code_msg != NULL){
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\n[SSM_ERROR] ");
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, p_ssm_error_code_msg);
        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\n");
    }
    
    return debug;
    
}

uint8_t RF_ATA8510_SPI_ReadFillLevelRxFifo(void) { 
	uint8_t cmd[ATA8510_SPI_CMD_LEN_READ_FILL_LEVEL_RX_FIFO] = {0};
	cmd[0] = ATA8510_SPI_CMD_ID_READ_FILL_LEVEL_RX_FIFO;
	_RF_ATA8510_SPI_Send(ATA8510_SPI_CMD_LEN_READ_FILL_LEVEL_RX_FIFO,cmd,cmd);
	return cmd[2];
}

uint8_t RF_ATA8510_SPI_GetEventBytes(sEvents_t *p_data) { 
	uint8_t cmd[ATA8510_SPI_CMD_LEN_GET_EVENT_BYTES] = {0};
	cmd[0] = ATA8510_SPI_CMD_ID_GET_EVENT_BYTES;
	_RF_ATA8510_SPI_Send(ATA8510_SPI_CMD_LEN_GET_EVENT_BYTES,cmd,(uint8_t *)&rf_data.events);
	if ( p_data != NULL ) {
		memcpy((uint8_t *)p_data, (uint8_t *)&rf_data.events, ATA8510_SPI_CMD_LEN_GET_EVENT_BYTES);
	}
	return ATA8510_SPI_CMD_LEN_GET_EVENT_BYTES;
}

uint8_t RF_ATA8510_SPI_ReadRxFifo(uint8_t len, uint8_t *p_data) { 
	uint8_t cmd[ATA8510_SPI_CMD_LEN_READ_RX_FIFO] = {0};
	cmd[0] = ATA8510_SPI_CMD_ID_READ_RX_FIFO;
	cmd[1] = len;
	_RF_ATA8510_SPI_Send(len+3, cmd, cmd);
	if (p_data != NULL ) {
		memcpy(p_data, cmd+3, len);
	}
	return len;
}


uint8_t RF_ATA8510_SPI_ReadSramRegister(uint8_t len, uint16_t address, uint8_t *p_data ) { 
    
    if ( len > 16 ) {
        RF_ASSERT( len > 16, "Length exceeds maximum of 16 bytes");
    } else {
        uint8_t cmd[ATA8510_SPI_CMD_LEN_READ_SRAM_REGISTER] = {0};
        cmd[0] = ATA8510_SPI_CMD_ID_READ_SRAM_REGISTER;
        cmd[1] = len;
        cmd[2] = (uint8_t) ( (address >> 8) & 0x00FF ); // addr_high
        cmd[3] = (uint8_t) ( (address >> 0) & 0x00FF ); // addr_low
        _RF_ATA8510_SPI_Send(len+5, cmd, cmd);
        if( p_data != NULL ) {
            memcpy(p_data, cmd+5,len);
        }
        return len + 5;
        
    }
    return 0;
}

uint8_t RF_ATA8510_SPI_ReadEeprom(uint16_t address) { 
    uint8_t cmd[ATA8510_SPI_CMD_LEN_READ_EEPROM] = {0};
    cmd[0] = ATA8510_SPI_CMD_ID_READ_EEPROM;
    cmd[1] = (uint8_t) ( (address >> 8) & 0x00FF ); // addr_high
    cmd[2] = (uint8_t) ( (address >> 0) & 0x00FF ); // addr_low
    _RF_ATA8510_SPI_Send(ATA8510_SPI_CMD_LEN_READ_EEPROM, cmd, cmd);
    return cmd[4];
}


uint8_t RF_ATA8510_SPI_WriteTxFifo(uint8_t len, uint8_t *p_data) { 
	uint8_t cmd[ATA8510_SPI_CMD_LEN_WRITE_TX_FIFO] = {0};
	cmd[0] = ATA8510_SPI_CMD_ID_WRITE_TX_FIFO;
	cmd[1] = len;
	memcpy(cmd+2,p_data,len);
	return _RF_ATA8510_SPI_Send(len+2, cmd, NULL);
}

uint8_t RF_ATA8510_SPI_WriteTxPreambleFifo(uint8_t len, uint8_t *p_data) { 
	uint8_t cmd[ATA8510_SPI_CMD_LEN_WRITE_TX_PREAMBLE_FIFO] = {0};
	cmd[0] = ATA8510_SPI_CMD_ID_WRITE_TX_PREAMBLE_FIFO;
	cmd[1] = len;
	memcpy(cmd+2,p_data,len);
	return _RF_ATA8510_SPI_Send(len+2, cmd, NULL);
}

uint8_t RF_ATA8510_SPI_SetSystemMode(sSystemModeConfig_t mode, sServiceChannelConfig_t service_channel) { 
	uint8_t cmd[ATA8510_SPI_CMD_LEN_SET_SYSTEM_MODE] = {0};
	cmd[0] = ATA8510_SPI_CMD_ID_SET_SYSTEM_MODE;
    cmd[1] = mode.raw;
    cmd[2] = service_channel.raw;
	return _RF_ATA8510_SPI_Send(ATA8510_SPI_CMD_LEN_SET_SYSTEM_MODE, cmd, NULL);
}
/* *****************************************************************************
 End of File
 */
