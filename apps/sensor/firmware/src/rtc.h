/* 
 * File:   rtc.h
 * Author: M43814
 *
 * Created on January 23, 2026, 3:30 PM
 */

/** \file rtc.h
 * include file for module rtc
 */

#ifndef RTC_H
#define	RTC_H

#ifdef	__cplusplus
extern "C" {
#endif


/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "ata8510_curiosity.h"
/*===========================================================================*/
/*  DEFINES  */
/*===========================================================================*/
/* 
 * Instruction Set 
 */
#define EEREAD  0x03    /**< Read data from EEPROM array beginning at selected address */
#define EEWRITE 0x02    /**< Write data to EEPROM array beginning at selected address */
#define EEWRDI  0x04    /**< Reset the write enable latch (disable write operations) */
#define EEWREN  0x06    /**< Set the write enable latch (enable write operations) */
#define SRREAD  0x05    /**< Read STATUS register */
#define SRWRITE 0x01    /**< Write STATUS register */
#define READ    0x13    /**< Read data from RTCC/SRAM array beginning at selected address */
#define WRITE   0x12    /**< Write data to RTCC/SRAM array beginning at selected address */
#define UNLOCK  0x14    /**< Unlock the protected EEPROM block for a write operation */
#define IDWRITE 0x32    /**< Write data from the protected EEPROM block beginning at the selected address */
#define IDREAD  0x33    /**< Read data from the protected EEPROM block beginning at selected address */
#define CLRRAM  0x54    /**< Clear all SRAM data to '0' */

/* 
 * Timekeeping Registers 
 */
#define RTCHSEC 0x00    /**< RTCHSEC: Timekeeping Hundreth of Seconds Value Register (Address 0x00) */
#define RTCHSEC_DEFAULT 0x00    /**< RTCHSEC Default Value */

#define RTCSEC 0x01 /**< RTCSEC: Timekeeping Seconds Value Register (Address 0x01) */
#define RTCSEC_DEFAULT 0x00 /**< RTCSEC Default value */
/** data structure for RTCSEC register
 */
struct sRTCSEC {
    union {
        struct {
            uint8_t secone : 4; /**< Binary-Coded Decimal Value of Second's Ones Digit (Contains a value from 0 to 9) */
            uint8_t secten : 3; /**< Binary-Coded Decimal Value of Second's Tens Digit (Contains a value from 0 to 5) */
            uint8_t st : 1; /**< Start Oscillator bit. (1=Oscillator enabled, 0=Oscillator disabled)*/
        };
        uint8_t raw;    /**< register byte value */
    };
};
/** Type definition for data structure ::sRTCSEC
 */
typedef struct sRTCSEC sRTCSEC_t;
    
#define RTCMIN  0x02    /**< RTCMIN: Timekeeping Minutes Value Register (Address 0x02) */
#define RTCMIN_DEFAULT  0x00    /**< RTCMIN Default Value */

#define RTCHOUR 0x03    /**< RTCHOUR: Timekeeping Hours Value Register (Address 0x03) */
#define RTCHOUR_DEFAULT 0x00    /**< RTCHOUR Default Value */
/** data structure for RTCHOUR register
 */
struct sRTCHOUR {
    union {
        struct {
            uint8_t hrone : 4;  /**< __HRONE<3:0>:__ Binary-Coded Decimal Value of Hour's Ones Digit. 
                                 * Contains a value from 0 to 9. 
                                 */
            uint8_t hrten0 : 1; /**< __HRTEN0:__ Binary-Coded Decimal Value of Hour's Tens Digit. 
                                 * Contains a value from 0 to 1 if 12/24 is 1, otherwise contains a value from 0 to 2
                                 */
            uint8_t am_pm_hrten1 : 1;   /**< __AM/PM:__  
                                         * 1 = PM
                                         * 0 = AM
                                         *  or __HRTEN1:__ Binary-Coded Decimal Value of Hour's Tens Digit.
                                         * Contains a value from 0 to 2
                                         */
            uint8_t time_format_12_24 : 1;  /**< __12/24:__ 12 or 24 Hour Time Format  
                                             * 1 = 12-hour format
                                             * 0 = 24-hour format
                                             */
            uint8_t trim_sign : 1;  /**< __TRIMSIGN:__ Trim Sign bit  
                                     * 1 = Add clocks to correct for slow time
                                     * 0 = Subtract clocks to correct for fast time
                                     */
        };
        uint8_t raw;    /**< register byte value */
    };
};
/** Type definition for data structure ::sRTCHOUR
 */
typedef struct sRTCHOUR sRTCHOUR_t;

#define RTCWKDAY 0x04   /**< RTCWKDAY: Timekeeping Weekday Value Register (Address 0x04) */
#define RTCWKDAY_DEFAULT 0x01   /**< RTCWKDAY Default Value */
/** data structure for RTCWKDAY register
 */
struct sRTCWKDAY {
    union {
        struct {
            uint8_t wkday : 3;      /**< __WKDAY<2:0>__: Binary-Coded Decimal Value of Week Day  
                                     * Contains a value from 1 to 7. The representation is user-defined.
                                     */
            uint8_t vbaten : 1;     /**< __VBATEN__: External Battery Backup Supply (VBAT) Enable bit  
                                     * 1 = VBAT input is enabled
                                     * 0 = VBAT input is disabled
                                     */
            uint8_t pwrfail : 1;    /**< __PWRFAIL__: Power Failure Status bit  
                                     * 1 = Primary power was lost
                                     * 0 = Primary power has not been lost
                                     */
            uint8_t oscrun : 1; /**< __OSCRUN__: Oscillator Status bit  
                                 * 1 = Oscillator is enabled and running
                                 * 0 = Oscillator has stopped or has been disabled
                                 */
            uint8_t rfu : 2;    /**< reserved for ufuture use */
        };
        uint8_t raw;    /**< register byte value */
    };
};
/** Type definition for data structure ::sRTCWKDAY */
typedef struct sRTCWKDAY sRTCWKDAY_t;

#define RTCDATE 0x05    /**< RTCDATE: Timekeeping Date Value Register (Address 0x05) */
#define RTCDATE_DEFAULT 0x01    /**< RTCDATE Default Value */

#define RTCMTH 0x06 /**< RTCMTH: Timekeeping Month Value Register (Address 0x06) */
#define RTCMTH_DEFAULT 0x01 /**< RTCMTH Default Value */

#define RTCYEAR 0x07    /**< RTCYEAR: Timekeeping Year Value Register (Address 0x07) */
#define RTCYEAR_DEFAULT 0x01    /**< RTCYEAR Default Value */

#define CONTROL 0x08    /**< CONTROL: RTCC Control Register (Address 0x08) */
#define CONTROL_DEFAULT 0x00    /**< CONTROL Default value */
/** data structure for CONTROL register
 */
struct sCONTROL {
    union {
        struct{
            uint8_t sqwfs : 2;  /**< __SQWFS<1:0>:__ Square Wave Clock Output Frequency Select bits  
                                 * <ins>If SQWEN=1 and CRSTRIM=0:</ins>  
                                 * Selects frequency of clock output on CLKOUT  
                                 * 00 = 1Hz  
                                 * 01 = 4.096 kHz  
                                 * 10 = 8.192 kHz  
                                 * 11 = 32.768 kHz  
                                 * <ins>If SQWEN=0 or CRSTRIM=1:</ins>  
                                 * Unused  
                                 */
            uint8_t crstrim : 1;    /**< __CRSTRIM:__ Coarse Trim Mode Enable bit  
                                     * Coarse Trim mode results in the MCP795XX applying digital trimming every second.  
                                     * 1 = Enable Coarse Trim mode. If SQWEN=1, CLKOUT will output trimmed 1Hz nominal clock signal.  
                                     * 0 = Disable Coarse Trim mode.  
                                     */
            uint8_t extosc : 1; /**< __EXTOSC:__ External Oscillator input bit  
                                 * 1= Enable X1 pin to be driven by external 32.768 kHz source  
                                 * 0= Disable external 32.768 kHz input
                                 */
            uint8_t alm0en : 1; /**< __ALM0EN__: Alarm 0 Module Enable bit  
                                 * 1 = Alarm 0 enabled  
                                 * 0 = Alarm 0 disabled  
                                 */
            uint8_t alm1en : 1; /**< __ALM1EN__: Alarm 1 Module Enable bit  
                                 * 1 = Alarm 1 enabled  
                                 * 0 = Alarm 1 disabled  
                                 */
            uint8_t sqwen : 1;  /**< __SQWEN__: Square Wave Output Enable bit 
                                 * 1 = Enable Square Wave Clock Output mode  
                                 * 0 = Disable Square Wave Clock Output mode  
                                 */
            uint8_t rfu : 1;    /**< __Unimplemented:__ Read as '1' */
        };
        uint8_t raw;    /**< register byte value */
    };
};
/** Type definition for data structure ::sCONTROL
 */
typedef struct sCONTROL sCONTROL_t;

#define OSCTRIM 0x09    /**< OSCTRIM: Oscillator Digital Trim Register (Address 0x09) */
#define OSCTRIM_DEFAULT 0x00    /**< OSCTRIM Default Value */

/** data structure for OSCTRIM register 
 */
struct sOSCTRIM {
    union {
        struct {
            uint8_t trimval : 8;    /**< __TRIMVAL<7:0>:__ Oscillator Trim Value bits  
                                     * <ins>When CRSTRIM=0:</ins>  
                                     * 11111111 = Add or subtract 510 clock cycles every minute  
                                     * 11111110 = Add or subtract 508 clock cycles every minute  
                                     * ...  
                                     * 00000010 = Add or subtract 4 clock cycles every minute  
                                     * 00000001 = Add or subtract 2 clock cycles every minute  
                                     * 00000000 = Disable digital trimming  
                                     * 
                                     * <ins>When CRSTRIM=1:</ins>  
                                     * 11111111 = Add or subtract 510 clock cycles every second  
                                     * 11111110 = Add or subtract 508 clock cycles every second  
                                     * ...  
                                     * 00000010 = Add or subtract 4 clock cycles every second  
                                     * 00000001 = Add or subtract 2 clock cycles every second  
                                     * 00000000 = Disable digital trimming  
                                     * 
                                     */
        };
        uint8_t raw;    /**< register byte value */
    };
};
/** Type definition for data structure ::sOSCTRIM
 */
typedef struct sOSCTRIM sOSCTRIM_t;

/* 
 * Alarm 0 
 */
#define ALM0SEC 0x0C    /**< ALM1SEC: Alarm 0 Seconds Value Register (Address 0x0C) */
#define ALM0SEC_DEFAULT 0x00    /**< ALM0SEC Default Value */
#define ALM0MIN 0x0D    /**< ALM0MIN: Alarm 0 Minutes Value Register (Address 0x0D) */
#define ALM0MIN_DEFAULT 0x00    /**< ALM0MIN Default Value */
#define ALM0HOUR 0x0E   /**< ALM0HOUR: Alarm 0 Hour Value Register (Address 0x0E) */
#define ALM0HOUR_DEFAULT 0x00   /**< ALM0HOUR Default Value */
#define ALM0WKDAY 0x0F  /**< ALM0WKDAY: Alarm 0 Weekday Value Register (Address 0x0F) */
#define ALM0WKDAY_DEFAULT 0x01  /**< ALM0WKDAY Default Value */
#define ALM0DATE 0x10   /**< ALM0DATE: Alarm 0 Date Value Register (Address 0x10) */
#define ALM0DATE_DEFAULT 0x01   /**< ALM0DATE Default Value */
#define ALM0MTH 0x11    /**< ALM0MTH: Alarm 0 Month Value Register (Address 0x11) */
#define ALM0MTH_DEFAULT 0x01    /**< ALM0MTH Default Value */

/* 
 * Alarm 1 
 */
#define ALM1HSEC 0x12   /**< ALM1HSEC: Alarm 1 Hundreths of Seconds Value Register (Address 0x12) */
#define ALM1HSEC_DEFAULT 0x00   /**< ALM1HSEC Default Value */
/** data structure for ALM1HSEC register
 */
struct sALM1HSEC {
    union {
        struct {
            uint8_t hsecone : 4;    /**< __HSECONE<3:0>:__ Binary-Coded Decimal Value of Hundreth fo Seconds Ones Digit. Contains a value from 0 to 9 */
            uint8_t hsecten : 4;    /**< __HSECTEN<3:0>:__ Binary-Coded Decimal Value of Hundreth of Seconds Tens Digit. Contains a value from 0 to 9 */
        };
        uint8_t raw;    /**< register byte value */
    };
};
/** Type definition for data structure ::sALM1HSEC
 */
typedef struct sALM1HSEC sALM1HSEC_t;

#define ALM1SEC 0x13    /**< ALM1SEC: Alarm 1 Seconds Value Register (Address 0x13) */
#define ALM1SEC_DEFAULT 0x00    /**< ALM1SEC Default value */
/** data structure for ALM1SEC register
 */
struct sALM1SEC {
    union {
        struct {
            uint8_t secone : 4; /**< Binary-Coded Decimal Value of Second's Ones Digit (Contains a value from 0 to 9) */
            uint8_t secten : 3; /**< Binary-Coded Decimal Value of Second's Tens Digit (Contains a value from 0 to 5) */
            uint8_t rfu : 1; /**< Unimplemented. Read as '0' */
        };
        uint8_t raw;    /**< register byte value */
    };
};
/** Type definition for data structure ::sALM1SEC
 */
typedef struct sALM1SEC sALM1SEC_t;

#define ALM1MIN 0x14    /**< ALM1MIN: Alarm 1 Minutes Value Register (Address 0x14) */
#define ALM1MIN_DEFAULT 0x00    /**< ALM1MIN Default Value */
#define ALM1HOUR 0x15   /**< ALM1HOUR: Alarm 1 Hour Value Register (Address 0x15) */
#define ALM1HOUR_DEFAULT 0x00   /**< ALM1HOUR Default Value */

#define ALM1WKDAY 0x16  /**< ALM1WKDAY: Alarm 1 Weekday Value Register (Address 0x16) */
#define ALM1WKDAY_DEFAULT 0x01  /**< ALM1WKDAY Default Value */

#define ALM1DATE 0x17   /**< ALM1DATE: Alarm 1 Date Value Register (Address 0x17) */
#define ALM1DATE_DEFAULT 0x01   /**< ALM1DATE Default Value */

/* 
 * Power-Fail Timestamp 
 */
/* 
 * Power-Down Timestamp 
 */
#define PWRDNMIN 0x18   /**< PWRDNMIN: Power-Down Timestamp Minutes Value Register (Address 0x18) */
#define PWRDNMIN_DEFAULT 0x00   /**< PWRDNMIN Default Value */
#define PWRDNHOUR 0x19  /**< PWRDNHOUR: Power-Down Timestamp Hour Value Register (Address 0x19) */
#define PWRDNHOUR_DEFAULT 0x00  /**< PWRDNHOUR Default Value */
#define PWRDNDATE 0x1A  /**< PWRDNDATE: Power-Down Timestamp Date Value Register (Address 0x1A) */
#define PWRDNDATE_DEFAULT 0x00  /**< PWRDNDATE Default Value */
#define PWRDNMTH 0x1B   /**< PWRDNMTH: Power-Down Timestamp Month Value Register (Address 0x1B) */
#define PWRDNMTH_DEFAULT 0x00   /**< PWRDNMTH Default Value */
/* 
 * Power-Up Timestamp 
 */
#define PWRUPMIN 0x1C   /**< PWRUPMIN: Power-Up Timestamp Minutes Value Register (Address 0x1C) */
#define PWRUPMIN_DEFAULT 0x00   /**< PWRUPMIN Default Value */
#define PWRUPHOUR 0x1D  /**< PWRUPHOUR: Power-Up Timestamp Hours Value Register (Address 0x1D) */
#define PWRUPHOUR_DEFAULT 0x00  /**< PWRUPHOUR Default Value */
#define PWRUPDATE 0x1E  /**< PWRUPDATE: Power-Up Timestamp Date Value Register (Address 0x1E) */
#define PWRUPDATE_DEFAULT 0x00  /**< PWRUPDATE Default Value */
#define PWRUPMTH 0x1F   /**< PWRUPMTH: Power-Up Timestamp Month Value Register (Address 0x1F) */
#define PWRUPMTH_DEFAULT 0x00   /**< PWRUPMTH Default Value */
 
/* 
 * SRAM
 */
#define RTC_SRAM_START  0x20    /**< SRAM Start Address */
#define RTC_SRAM_SIZE   64  /**< SRAM Size */
#define RTC_SRAM_END    (RTC_SRAM_START + RTC_SRAM_SIZE - 1)    /**< SRAM End Address */

/*
 * EEPROM
 */
#define RTC_EEPROM_START    0x00    /**< EEPROM Start Address */
#define RTC_EEPROM_SIZE 128 /**< EEPROM Size */
#define RTC_EEPROM_END  (RTC_EEPROM_START + RTC_EEPROM_SIZE - 1)    /**< EEPROM End Address */

/*
 * Protected EEPROM
 */
#define RTC_PROT_EEPROM_START   0x00    /**< Protected EEPROM Start Address */
#define RTC_PROT_EEPROM_SIZE    8   /**< Protected EEPROM Size */
#define RTC_PROT_EEPROM_END     (RTC_PROT_EEPROM_START + RTC_PROT_EEPROM_SIZE - 1)  /**< Protected EEPROM End Address */

#define RTC_LOCKABLE_USER_ID_START  0x08    /**< Lockable User ID Start Address */
#define RTC_LOCKABLE_USER_ID_SIZE   8   /**< Lockable User ID Size */
#define RTC_LOCKABLE_USER_ID_END    (RTC_LOCKABLE_USER_ID_START + RTC_LOCKABLE_USER_ID_SIZE -1) /**< Lockable User ID End Address */
/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

/**
 * initialization routine for RTC Module
 * - configure SPI (Host)
 * - configure Alarm 1 for 1s (see ::rtc_configure)
 */
extern void rtc_init(void);

/**
 * writes ::app_data to rtc sram
 */
extern void rtc_write_app_data(void);

/**
 * Write to RTC SRAM
 * @param address RTC SRAM Start address
 * @param p_data data pointer to write data
 * @param len number of bytes to write
 */
extern void rtc_write_sram(uint8_t address, uint8_t *p_data, uint8_t len);



#ifdef	__cplusplus
}
#endif

#endif	/* RTC_H */

