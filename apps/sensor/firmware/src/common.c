
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "common.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

#define SYSTEM_MODE_CONFIG  ( BM_SYS_MODE_CONFIG_VCO_TUNING )

#define SET_PATTERN_PIN() { PORTC |= (1<<2); }
#define CLEAR_PATTERN_PIN() { PORTC &= ~(1<<2); }
#define TOGGLE_PATTERN_PIN(delay) { \
    PINC = 1<<2; \
    for (int i=0; i<delay; i++) { _NOP; } \
    PINC = 1<<2; \
    for (int i=0; i<delay; i++) { _NOP; } \
}

#define PATTERN_RESET_LEN   100 // 100us
#define PATTERN_DATA_LEN    20  // 20 us
#define PATTERN_TOGGLE_PULSE_LEN    2   // 2us
#define PATTERN_DATA_ACTIVE_LEN (PATTERN_DATA_LEN - PATTERN_TOGGLE_PULSE_LEN)
#define PATTERN_RESET_SEQUENCE() \
{ \
    SET_PATTERN_PIN(); \
    for (int i=0; i<PATTERN_TOGGLE_PULSE_LEN; i++) { _NOP; } \
    CLEAR_PATTERN_PIN(); \
    for (int i=0; i<PATTERN_RESET_LEN; i++) { _NOP; } \
    SET_PATTERN_PIN(); \
    for (int i=0; i<PATTERN_TOGGLE_PULSE_LEN; i++) { _NOP; } \
}
#define PATTERN_END_SEQUENCE() \
{ \
    CLEAR_PATTERN_PIN(); \
    for (int i=0; i<PATTERN_TOGGLE_PULSE_LEN; i++) { _NOP; } \
    SET_PATTERN_PIN(); \
}
#define PATTERN_WRITE_1_SEQUENCE() \
{ \
    CLEAR_PATTERN_PIN(); \
    for (int i=0; i<PATTERN_TOGGLE_PULSE_LEN; i++) { _NOP; } \
    SET_PATTERN_PIN(); \
    for (int i=0; i<PATTERN_DATA_ACTIVE_LEN; i++) { _NOP; } \
}

#define PATTERN_WRITE_0_SEQUENCE() \
{ \
    CLEAR_PATTERN_PIN(); \
    for (int i=0; i<PATTERN_DATA_ACTIVE_LEN; i++) { _NOP; } \
    SET_PATTERN_PIN(); \
    for (int i=0; i<PATTERN_TOGGLE_PULSE_LEN; i++) { _NOP; } \
}

/*===========================================================================*/
/*  Modul Globals                                                             */
/*===========================================================================*/

/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
void debug_pattern8_pc2(uint8_t pattern) {
    _CLI;
    PATTERN_RESET_SEQUENCE();
    for (int i=7; i>=0;i--) {
        if ( pattern & (1<<i) )  { 
            PATTERN_WRITE_1_SEQUENCE() 
        } else {
            PATTERN_WRITE_0_SEQUENCE();
        }
    }
    PATTERN_END_SEQUENCE();    
    _SEI;
}
void debug_pattern16_pc2(uint16_t pattern) {
    _CLI;
    PATTERN_RESET_SEQUENCE();
    for (int i=15; i>=0;i--) {
        if ( pattern & (1<<i) ) {
            PATTERN_WRITE_1_SEQUENCE();            
        } else {
            PATTERN_WRITE_0_SEQUENCE();
        }
    }
    PATTERN_END_SEQUENCE();
    _SEI;
}

void set_idle_mode(void) {
    API_SetSystemMode_C( OPM_IDLE, app_data.service_channel_config );
}

void set_tx_mode(uint8_t *p_data, uint8_t len) {
    const uint8_t preamble[] = {0x30, 0x55, 0x55, 0x55, 0x55, 0x55, 0x56}; \
    API_WriteTxPreambleBuffer_C( (uint8_t *)preamble, sizeof(preamble) ); \
    API_WriteTxBuffer_C( p_data, len );
    /** \todo ADD CRC HERE */
    API_SetSystemMode_C( SYSTEM_MODE_CONFIG | OPM_TX, app_data.service_channel_config );
}

void set_rx_mode(void) {
    API_SetSystemMode_C( SYSTEM_MODE_CONFIG | OPM_RX, app_data.service_channel_config );
}

uint8_t get_telegram(uint8_t *p_data) {
    if ( IS_IDLE_MODE() && IS_TELEGRAM_RECEIVED() ) {

        PORTB &= ~(1<<PORTB6);  // Clear Event Pin
        uint8_t fill_level = API_ReadFillLevelRxBuffer_C();
        if (fill_level > 0) {
            API_ReadRxBuffer_C(p_data, fill_level);
            /** \todo  VERIFY CRC HERE */
        }
        return fill_level;
    }
    return 0;
}