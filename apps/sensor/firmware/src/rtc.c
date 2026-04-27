/** \file rtc.c
 * contains implementation for module rtc
 */
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "rtc.h"
#include "ata8510_curiosity.h"

/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/*===========================================================================*/
/*  Modul Globals                                                             */
/*===========================================================================*/
#define RTC_NSS_SET()   PORTB |=  (1<<PB5)  /**< set RTC SPI NSS to high */
#define RTC_NSS_CLEAR() PORTB &= ~(1<<PB5)  /**< set RTC SPI NSS to low */

/**
 * Macro for SPI Read and Write Byte Transfer
 * @param tx data byte to transmit
 * @param rx data byte to receive
 */
#define RTC_SPI_DATA_TRX(tx,rx) \
{ \
    SPDR=tx; \
    while (!(SPSR & (1<<SPIF))); \
    rx=SPDR; \
}

/**
 * Macro for SPI Write Byte Transfer
 * @param tx data byte to transmit
 */
#define RTC_SPI_DATA_TX(tx) \
{ \
    SPDR=tx; \
    while (!(SPSR & (1<<SPIF))); \
    (void)SPDR; \
}

/**
 * Macro for SPI Read Byte Transfer
 * @param rx data byte to receive
 */
#define RTC_SPI_DATA_RX(rx) \
{ \
    SPDR=0x00; \
    while (!(SPSR & (1<<SPIF))); \
    rx = SPDR; \
}

/**
 * Macro for SPI Port Disabling
 */
#define RTC_SPI_PORT_DISABLE() \
{ \
    DDRB &= ~(1<<PB1);  /* PB1/SCK (Input) */ \
    PORTB &= ~(1<<PB1); \
    DDRB &= ~(1<<PB2);  /* PB2/MOSI (Input) */ \
    PORTB &= ~(1<<PB2); \
    DDRB &= ~(1<<PB3);  /* PB3/MISO (Input) */ \
    PORTB &= ~(1<<PB3); \
    DDRB &= ~(1<<PB5);  /* PB5/NSS (Input) */ \
    PORTB &= ~(1<<PB5); \
}

/** 
 * Macro for SPI Port Enabling 
 */
#define RTC_SPI_PORT_ENABLE() \
{ \
    DDRB |=  (1<<PB1);  /* PB1/SCK (Output Low) */ \
    PORTB &= ~(1<<PB1); \
    DDRB |=  (1<<PB2);  /* PB2/MOSI (Output High) */ \
    PORTB |= (1<<PB2); \
    DDRB &= ~(1<<PB3);  /* PB3/MISO (Input) */ \
    PORTB &= ~(1<<PB3); \
    DDRB |=  (1<<PB5);  /* PB5/NSS (Output High) */ \
    PORTB |=  (1<<PB5); \
}

/** 
 * Macro for SPI Register configuration 
 */
#define RTC_SPI_REGISTER_SETTING() \
{ \
    /* SPCR Register Setting */ \
    SPCR = (0<<SPIE) |  /* SPI Interrupt Enable */ \
           (1<<SPE)  |  /* SPI Enable */ \
           (0<<DORD) |  /* Data Order */ \
           (1<<MSTR) |  /* Host/Client Select */ \
           (0<<CPHA) |  /* Clock Phase */ \
           (0<<SPR1) |  /* SPI Clock Rate Select */ \
           (0<<SPR0); \
    /* SPSR Register Setting */ \
    SPSR = (0<<SPIF) |  /* SPI Interrupt Flag */ \
           (0<<TXIF) |  /* Transmit Buffer Interrupt Flag */ \
           (0<<RXIF) |  /* Receive Buffer Interrupt Flag */ \
           (0<<SPI2X);  /* Double SPI Speed */ \
}

/** Switch Power off from RTC5 Click board */
#define RTC_POWER_OFF_RTC5_CLICK()  PORTB |=  (1<<PB0)
/** Switch Power on from RTC5 Click board */
#define RTC_POWER_ON_RTC5_CLICK()   PORTB &= ~(1<<PB0)
    
/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
static void rtc_reset(void);
static void rtc_start_oscillator(void);
static void rtc_spi_init(void);
static void rtc_spi(uint8_t *p_data, uint8_t len);
static void rtc_read_app_data(void);
static void rtc_configure(void);
/*
 * Instructions
 */
/**
 * Read RTC register
 * @param address RTC register address
 * @return RTC register value
 */
static uint8_t rtc_read_reg(uint8_t address);
/**
 * Read from RTC SRAM
 * @param address RTC SRAM Start Address
 * @param p_data data pointer to store read data
 * @param len number of bytes to read
 */
static void rtc_read_sram(uint8_t address, uint8_t *p_data, uint8_t len);
/**
 * Write RTC register
 * @param address RTC Register address
 * @param val RTC Register value
 */
static void rtc_write_reg(uint8_t address, uint8_t val);

/**
 * Clear RTC SRAM
 */
void rtc_clear_sram(void);


void rtc_init(void) {
    // Initialize SPI for RTC communication
    rtc_spi_init(); 
    // Read Data from RTC SRAM ( !!! before resetting RTC !!! )
    rtc_read_app_data();
    // Reset RTC device for correct alarm generation on MFP/PC4
    rtc_reset();
    // Re-Initialize SPI for RTC communication
    rtc_spi_init();
    
    rtc_configure();
}

uint8_t rtc_read_reg(uint8_t address) 
{
    tmpAryApp[0] = READ;
    tmpAryApp[1] = address;
    tmpAryApp[2] = 0x00;
    rtc_spi(tmpAryApp,3);
    return tmpAryApp[2];
}

void rtc_read_sram(uint8_t address, uint8_t *p_data, uint8_t len) 
{
    RTC_NSS_CLEAR();
    RTC_SPI_DATA_TX(READ);
    RTC_SPI_DATA_TX(address);
    for (int i=0;i<len;i++) {
        RTC_SPI_DATA_RX(p_data[i]);
    }
    RTC_NSS_SET();
}

void rtc_write_reg(uint8_t address, uint8_t val)
{
    tmpAryApp[0] = WRITE;
    tmpAryApp[1] = address;
    tmpAryApp[2] = val;
    rtc_spi(tmpAryApp,3);
}

void rtc_write_sram(uint8_t address, uint8_t *p_data, uint8_t len) {
    RTC_NSS_CLEAR();
    RTC_SPI_DATA_TX(WRITE);
    RTC_SPI_DATA_TX(address);
    for (int i=0;i<len;i++) {
        RTC_SPI_DATA_TX(p_data[i]);
    }
    RTC_NSS_SET();
}

void rtc_clear_sram(void) {
    tmpAryApp[0] = CLRRAM;
    tmpAryApp[1] = 0x00;
    rtc_spi(tmpAryApp,2);
}

void rtc_configure(void) {
    rtc_start_oscillator();
    
    sALM1SEC_t alm1sec;
    alm1sec.secone = 1;
    rtc_write_reg(ALM1SEC, alm1sec.raw);
    rtc_write_reg(ALM1WKDAY, ALM1WKDAY_DEFAULT);

    sCONTROL_t control_reg;
    control_reg.alm1en = 1;
    rtc_write_reg(CONTROL, control_reg.raw);
}

void rtc_read_app_data(void){
    rtc_read_sram(
        RTC_SRAM_START, 
        (uint8_t *)&app_data, 
        sizeof(sAppData_T)
    );
}

void rtc_write_app_data(void){
    rtc_write_sram(
        RTC_SRAM_APP_DATA, 
        (uint8_t *)&app_data, 
        sizeof(app_data)
    );             
}

static void rtc_reset(void) {
    SPCR &= ~(1<<SPE);
    RTC_SPI_PORT_DISABLE();
    RTC_POWER_OFF_RTC5_CLICK();
    for (int i=0;i<1000;i++){_NOP;} // ~ 1.3ms duration
    RTC_POWER_ON_RTC5_CLICK();
    for (int i=0;i<100;i++){_NOP;}
}

static void rtc_start_oscillator(void) {
    sRTCSEC_t rtcsec;
    rtcsec.raw = RTCSEC_DEFAULT;
    rtcsec.st = 1;
    rtc_write_reg(RTCSEC, rtcsec.raw);
    // wait until oscillator is enabled an running
    while (TRUE) {
        sRTCWKDAY_t rtcwkday;
        rtcwkday.raw = rtc_read_reg(RTCWKDAY);
        if ( rtcwkday.oscrun == 1) {
            break;
        }
        for (int i=0;i<100;i++){_NOP;}
    }
}

static void rtc_spi_init(void) {
    EIMSK &= ~(1<<INT1);    // Disable INT1
    RTC_SPI_PORT_ENABLE();
    RTC_SPI_REGISTER_SETTING();
}

static void rtc_spi(uint8_t *p_data, uint8_t len) {
    RTC_NSS_CLEAR();
    for (int i=0;i<len;i++) {
        RTC_SPI_DATA_TRX(*p_data, *p_data++);
    }
    RTC_NSS_SET();
}
