/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL:
  $LastChangedRevision:
  $LastChangedDate:
  $LastChangedBy:
-------------------------------------------------------------------------------
  Project:      ATA5831
  Target MCU:   ATA5831
  Compiler:     IAR C/C++ Compiler for AVR 6.12.1
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

/** \file ata8510_curiosity.h
 * Project include file
*/

#ifndef ATA8510_CURIOSITY_H
#define ATA8510_CURIOSITY_H
/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#define __no_init   /**< define to disable IAR compiler keyword '__no_init' for XC8 compiler */
#define __root  /**< define to disable IAR compiler keyword '__root' for XC8 compiler */
#include <xc.h>
#include <avr/eeprom.h>

#include "firmware/api/src/api.h"
#include "firmware/eep/src/eep.h"
#include "firmware/extif/src/extif.h"
#include "firmware/globals/src/globals.h"
#include "firmware/init/src/init.h"
#include "firmware/stdc/src/stdc.h"
#include "firmware/timer1/src/timer1.h"
#include "firmware/timer2/src/timer2.h"
#include "firmware/timer3/src/timer3.h"
#include "firmware/timer4/src/timer4.h"
#include "firmware/timer5/src/timer5.h"
#include "firmware/calib/src/calib.h"
#include "firmware/rf/src/rf.h"
#include "firmware/rftx/src/rftx.h"
#include "firmware/rfrx/src/rfrx.h"
#include "firmware/system/src/system.h"

#include "wrap.h"
/*===========================================================================*/
/*  DEFINES  */
/*===========================================================================*/
/*
 * LED GREEN (PC5)
 */
#define LED_GREEN_OFF() {PORTC |= (1<<5);}  /**< Switch LED GREEN (PC5) off */
#define LED_GREEN_ON() {PORTC &= ~(1<<5);}  /**< Switch LED GREEN (PC5) on */
#define LED_GREEN_TOGGLE() {PINC = (1<<5);} /**< Toggle LED GREEN (PC5) */

/*
 * Synchronization (PRE and SFID)
 */
#define PREAMBLE    0x5555  /**< RF preamble data used for application */
#define SFID        0x4E    /**< RF sfid data used for application */

#define NUMBER_OF_SENSORS   5   /**< maximum number of supported child sensors*/
#define INVALID_SENSOR_ID   0xFFFF  /**< invalid sensor device id */

struct sDeviceId {
    union {
        struct {
            uint16_t uid : 12;
            uint16_t level : 4;
        };
        uint16_t raw;
    };

};
typedef struct sDeviceId sDeviceId_T;

struct sSensorStatus {
    union {
        struct {
            uint8_t alarm : 1;  /**< Bit 0: Alarm */
            uint8_t rfu_bit_1 : 1;  /**< Bit 1: RFU */
            uint8_t rfu_bit_2 : 1;  /**< Bit 2: RFU */
            uint8_t rfu_bit_3 : 1;  /**< Bit 3: RFU */
            uint8_t rfu_bit_4 : 1;  /**< Bit 4: RFU */
            uint8_t rfu_bit_5 : 1;  /**< Bit 5: RFU */
            uint8_t rfu_bit_6 : 1;  /**< Bit 6: RFU */
            uint8_t rfu_bit_7 : 1;  /**< Bit 7: RFU */
        };
        uint8_t raw;
    };
};
typedef struct sSensorStatus sSensorStatus_T;

/** enum for application command IDs */
typedef enum {
    KA_MSG = 0x03,  /**< Message Identifier for Keep-Alive message/command */
    UD_MSG = 0x04,  /**< Message Identifier for Update message/command */
    ACK_MSG = 0x05, /**< Message Identifier for Acknowledge message/command */
    AL_MSG = 0x06,  /**< Message Identifier for Alarm message/command */
    PART_REQ = 0x07,    /**< Message Identifier for Participation Request message/command */
    PART_REQ_RESP = 0x08,   /**< Message Identifier for Participation Request Response message/command */
    MEM_KEY = 0x09, /**< Message Identifier for Member Key Exchange message/command */
    CAN_KEY = 0x0A, /**< Message Identifier for Candidate Key Exchange message/command */
    CON_VER_STA = 0x0B, /**< Message Identifier for Connection Verification Status message/command */
    CON_VER_REQ = 0x0C, /**< Message Identifier for Connection Verification Request message/command */
    CON_VER_RESP = 0x0D,    /**< Message Identifier for Connection Verification Response message/command */
    PAY_MSG = 0x0E, /**< Message Identifier for Paylod message/command */
    NUM_MSGS    /**< Number of Message Identifiers */
} eMsg_T;

/** data structure containing status information of the sensor */
struct sStatus {
    union {
        struct {
            uint8_t bmz_update : 1;
            uint8_t accept_device : 1;
            uint8_t clear_blocked_list : 1;
            uint8_t payload : 1;
            uint8_t security : 1;
            uint8_t okay : 1;
            uint8_t network : 1;
            uint8_t battery : 1;
        };
        uint8_t raw;
    };
};
/** type definition for ::sStatus */
typedef struct sStatus sStatus_T;

struct sCommandHeader {
    sDeviceId_T id;
    uint8_t msg;
    sStatus_T sta;
};
typedef struct sCommandHeader sCommandHeader_T;

struct sCommandNoPayload {
    sCommandHeader_T hdr;
};
typedef struct sCommandNoPayload sCommandPartReqResp_T;

/*
 * KA_MSG
 * The keep alive message is the regular communication triggered by the upper 
 * level device. It's answered with an ACK_MSG or UD_MSG
 */
typedef struct sCommandNoPayload sCommandKeepAlive_T;

/*
 * UD_MSG
 * The update message adds an update field with variable length between STA and 
 * CRC. It's used to maintain the network with information like sleep time or 
 * information about the network topology.
 * The first byte indicates the length of the additional information. After that
 * a variable number of parameters and update values can be added.
 * 
 */
/** enumeration for US_MSG IDs */
typedef enum {
    UD_ID_NEW_CHILD,    /**<* Update Message ID which signals a new child sensor is available in the network */
    NUM_UD_IDS  /**< Number of Update Message IDs */
} eUdMsgId_T;

/** data structure for payload of UD_MSG command 
 */
struct sUdMsgNewChild {
    uint16_t parent_id; /**< contains the parent id of the new sensor connection */
    uint16_t child_id;  /**< contains the child id of the new sensor connection */
};
/** type definition for ::sUdMsgNewChild */
typedef struct sUdMsgNewChild sUdMsgNewChild_T;

/** UD_MSG command data structure 
 */
struct sCommandUdMsg {
    sCommandHeader_T hdr;   /**< command header information */
    uint8_t length; /**< length parameter */
    eUdMsgId_T id;  /**< message id of UD_MSG (\sa ::eUdMsgId_T) */
    union {
        sUdMsgNewChild_T new_child; /**< new sensor connection data */
    };
};
/** type definition for ::sCommandUdMsg */
typedef struct sCommandUdMsg sCommandUdMsg_T;

/* 
 * ACK_MSG
 */
typedef struct sCommandNoPayload sCommandAckMsg_T;

/** data structure for 'ACK_MSG' message used to acknowledge 'KA_MSG' message */
struct sCommandAckKaMsg {
    sCommandHeader_T hdr;   /**< command header */
    int16_t correction_offset;   /**< correction value for synchronization of 'KA_MSG' messages, reduces/extend sleep time for 1 interval cycle */
    int16_t correction_interval;    /**< correction value for 'KA_MSG' interval, value applied to following interval cylces */
    
};
/** typedef for ::sCommandAckKaMsg */
typedef struct sCommandAckKaMsg sCommandAckKaMsg_T;

/* 
 * AL_MSG
 */
typedef struct sCommandNoPayload sCommandAlMsg_T;


/*
 * PART_REQ
 */
struct sCommandPartReq {
    sCommandHeader_T hdr;
    uint8_t device_type;
};
typedef struct sCommandPartReq sCommandPartReq_T;

/*
 * PART_REQ_RESP
 */

/*
 * MEM_KEY
 */

/*
 * CAN_KEY
 */

/*
 * CON_VER_STA
 */

/*
 * The connection status contains a time base for regular communication and the 
 * actual number of nodes within the level (of the new connected device)
 */
struct sConVerSta {
    union {
        uint16_t tick_cnt : 12;  /** \todo  add content */
        uint16_t number_of_nodes : 4;  /** \todo add content */
    };
    uint16_t raw;
};
typedef struct sConVerSta sConVerSta_T;

struct sCommandConVerSta {
    sCommandHeader_T hdr;   /**< command heaader */
    uint16_t status;    /**< connection verification status */
};
typedef struct sCommandConVerSta sCommandConVerSta_T;

/** CON_VER_REQ command structure 
 */
struct sCommandConVerReq {
    sCommandHeader_T hdr;
    uint16_t device_id;
    uint8_t device_type;
};
/** type definition for ::sCommandConVerReq */
typedef struct sCommandConVerReq sCommandConVerReq_T;

/** CON_VER_RESP command structure 
 */
struct sCommandConVerResp {
    sCommandHeader_T hdr;
    uint16_t device_id;
};
/** type defintion for ::sCommandConVerResp */
typedef struct sCommandConVerResp sCommandConVerResp_T;

/*
 * PAY MSG
 */

/** data structure containing the bits for controlling the application
 */
union uStatus {
    struct {
    uint8_t t4_comp_int : 1;  /** Bit 0: status flag for timer4 compare interrupt, set in ISR to '1' */
    uint8_t pin_change1_int : 1;  /** Bit 1: status flag for pin change1 interrupt, set in ISR to '1' */
    uint8_t rfu_bit2 : 1;  /** Bit 2: reserved for future use */
    uint8_t rfu_bit3 : 1;  /** Bit 3: reserved for future use */
    uint8_t rfu_bit4 : 1;  /** Bit 4: reserved for future use */
    uint8_t rfu_bit5 : 1;  /** Bit 5: reserved for future use */
    uint8_t rfu_bit6 : 1;  /** Bit 6: reserved for future use */
    uint8_t rfu_bit7 : 1;  /** Bit 7: reserved for future use */
    };
    uint8_t raw;    /**< status byte */
};
/** type definition for ::sStatus */
typedef union uStatus uStatus_T;

/** data structure containing the device ids for 
 * ATA8510 Alarm Systems application 
 */
struct sAppData {
    uint16_t device_id;  /**< 16-bit device ID (default: 0xFFFF) */
    uint16_t parent_id;  /**< 16-bit parent ID (default: 0xFFFF) */
    uint16_t child_id[NUMBER_OF_SENSORS];    /**< 5 x (16-bit child ID) (default: 0xFFFF)  */
    int16_t ka_interval_correction; /**< correction value to synchronize interval for KA_MSG processing (default: 0 = ~0ms) */
    /* 
     * EEPROM Settings for Sensor Synchronization
     */
    uint16_t rx_window_upper_threshold; /**< rx_window upper threshold (default: 200 = ~100ms) */
    uint16_t rx_window_lower_threshold; /**< rx_window lower threshold (default: 80 = ~40ms )*/

    int16_t correction_offset_up;   /**< correction_offset applied when rx_window > rx_window upper threshold (default: 40 = ~20ms) */
    int16_t correction_interval_up; /**< correction_interval applied when rx_window > rx_window upper threshold (default: 0 = ~0ms) */
    
    int16_t correction_offset_mid;  /**< correction_offset applied when lower threshold < rx_window < upper_threshold (default: -10 = ~5ms) */
    int16_t correction_interval_mid; /**< correction_interval applied when lower threshold < rx_window < upper_threshold (default: -10 = ~5ms) */
    
    int16_t correction_offset_low;  /**< correction_offset applied when rx_window < lower_threshold (default: 40 = ~20ms) */
    int16_t correction_interval_low;    /**< correction_interval applied when rx_window < lower_threshold (default: 10 = ~5ms)) */
    
};
/** type definition for ::sAppData */
typedef struct sAppData sAppData_T;

/** start address for application data store in EEPROM */
#define ADDRESS_EEP_DATA    0x0280  


/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/
/** CSTACK used for IAR functions in ROM */
extern int __section(".noinit") cstack[0x20];
/** contains the current state of the application (\sa ::eState_T) */
extern uint8_t state;
/** contains the application status of the sensor application */
extern volatile uStatus_T status;
/** contains the device ids of the sensor (own id, parent and child ids) */
extern sAppData_T app_data;

/**
 * returns the number of connected/learned child sensors
 * @return number of child sensors
 */
extern uint8_t get_num_child_sensors(void);

/**
 * removes child sensor from sensor list
 * @param id device id of the child sensor to remove
 * @return TRUE if successful, otherwise FALSE
 */
extern uint8_t remove_child_sensor(uint16_t id);
/**
 * adds a sensor to the child sensor list
 * @param id device id of the child sensor to add
 * @return TRUE if successful, otherwise FALSE
 */
extern uint8_t add_child_sensor(uint16_t id);


#endif /* ATA8510_CURIOSITY_H */
