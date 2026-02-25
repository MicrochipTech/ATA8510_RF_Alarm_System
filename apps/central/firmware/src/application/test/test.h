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
/** \file test.h
 *  contains test implementation of the application
 */

#ifndef _TEST_H    /* Guard against multiple inclusion */
#define _TEST_H


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
    
    #define TEST_NRESET_Set()   EXT3_MUX_DEMUX_SIG_1_Set()  /**< set NRESET to high level */
    #define TEST_NRESET_Clear() EXT3_MUX_DEMUX_SIG_1_Clear()    /**< set NRESET to low level */
    #define TEST_NPWRON_Set()   EXT3_MUX_DEMUX_SIG_2_Set()  /**< set NPWRON1 to high level */
    #define TEST_NPWRON_Clear() EXT3_MUX_DEMUX_SIG_2_Clear()    /**< set NPWRON1 to low level */

    /** enum for sensor IDs/Addresses */
    typedef enum {
        SENSOR_0 = 0,   /**< sensor 0 ID/Address */
        SENSOR_1,   /**< sensor 1 ID/Address */
        SENSOR_2,   /**< sensor 2 ID/Address */
        SENSOR_3,   /**< sensor 3 ID/Address */
        SENSOR_4,   /**< sensor 4 ID/Address */
        SENSOR_NUM, /**< number of sensors */
        SENSOR_ID_INVALID = 0xFF    /**< initial value */
    }eSENSOR_ID_T;

    /** enumeration for debug pattern */
    typedef enum {
        /* INIT */
        PATTERN_INIT = 0x00,    /**< debug init for 'INIT' (0x00) */
        PATTERN_STATE_INIT, /**< debug init for '::STATE_INIT' (0x01) */
        PATTERN_STATE_WAIT_RF_SYS_RDY,  /**< debug init for '::STATE_WAIT_RF_SYS_RDY' (0x02) */
        /* IDLE */
        PATTERN_IDLE = 0x10,    /**< debug init for 'IDLE' (0x10) */
        /* KEEP ALIVE */
        PATTERN_KEEP_ALIVE = 0x20,  /**< debug init for '::KEEP_ALIVE' (0x20) */
        PATTERN_STATE_KEEP_ALIVE_TX_ACK, /**< debug init for '::STATE_KEEP_ALIVE_TX_ACK' (0x21) */
        PATTERN_STATE_KEEP_ALIVE_TX_ACK_COMPLETE,   /**< debug init for '::STATE_KEEP_ALIVE_TX_ACK_COMPLETE' (0x22) */
        /* LEARN */
        PATTERN_LEARN = 0x40,   /**< debug init for 'LEARN' (0x40) */
        PATTERN_STATE_LEARN = 0x40, /**< debug init for '::STATE_LEARN' (0x40) */
        PATTERN_STATE_LEARN_RX_PART_REQ,    /**< debug init for '::STATE_LEARN_RX_PART_REQ' (0x41) */
        PATTERN_STATE_LEARN_TX_PART_REQ_RESP,   /**< debug init for '::STATE_LEARN_TX_PART_REQ_RESP' (0x42) */
        PATTERN_STATE_LEARN_TX_PART_REQ_RESP_COMPLETE,  /**< debug init for '::STATE_LEARN_TX_PART_REQ_RESP_COMPLETE' (0x43) */
        PATTERN_STATE_LEARN_TX_CON_VER_STAT,    /**< debug init for '::STATE_LEARN_TX_CON_VER_STAT' (0x44) */
        PATTERN_STATE_LEARN_TX_CON_VER_STAT_COMPLETE,   /**< debug init for '::STATE_LEARN_TX_CON_VER_STAT_COMPLETE' (0x45) */
        PATTERN_STATE_LEARN_RX_ACK_MSG, /**< debug init for '::STATE_LEARN_RX_ACK_MSG' (0x46) */
        PATTERN_STATE_LEARN_PASS,   /**< debug init for '::STATE_LEARN_PASS' (0x47) */
        PATTERN_STATE_LEARN_FAIL,   /**< debug init for '::STATE_LEARN_FAIL' (0x48) */
        /* ALARM*/
        PATTERN_ALARM_STATE = 0x80, /**< debug init for 'ALARM_STATE' (0x80) */
        PATTERN_STATE_ALARM = 0x80, /**< debug init for '::STATE_ALARM' (0x80) */
        PATTERN_STATE_ALARM_TX_ACK_MSG_COMPLETE,    /**< debug init for '::STATE_ALARM_TX_ACK_MSG_COMPLETE' (0x81) */
        /* CONNECTION VERIFICATION */
        PATTERN_CONNECTION_VERIFICATION = 0x90, /**< debug init for 'CONNECTION_VERIFICATION' (0x90) */
        PATTERN_STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP = 0x90,   /**< debug init for '::STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP' (0x90) */
        PATTERN_STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE, /**< debug init for '::STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE' (0x91) */
        /* UPDATE */        
        PATTERN_STATE_UPDATE = 0xA0,    /**< debug init for 'STATE_UPDATE' (0xA0) */
        PATTERN_STATE_UPDATE_TX_ACK = 0xA0, /**< debug init for '::STATE_UPDATE_TX_ACK' (0xA0) */
        PATTERN_STATE_UPDATE_TX_ACK_COMPLETE,   /**< debug init for '::STATE_UPDATE_TX_ACK_COMPLETE' (0xA1) */
        /* ERROR */
        PATTERN_ERROR_STATE = 0xB0  /**< debug init for 'ERROR_STATE' (0xB0) */
        
    } eDebugPattern_T;

    /** Set Pattern Pin to High Level */
    #define SET_PATTERN_PIN() EXT2_GPIO1_Set()
    /** Set Pattern Pin to Low Level */
    #define CLEAR_PATTERN_PIN() EXT2_GPIO1_Clear()
    /**
     * Toggle Pattern Pin Set - Delay(val)
     * @param val pulse length
     */
    #define TOGGLE_PATTERN_PIN(val) { \
        SET_PATTERN_PIN(); \
        APPLICATION_DelayUs(val); \
        CLEAR_PATTERN_PIN(); \
        APPLICATION_DelayUs(val); \
    }

    #define PATTERN_RESET_LEN   100 /**< Length of reset pulse of pattern (for debugging)  */
    #define PATTERN_DATA_LEN    20  /**< Length of data bit of pattern (for debugging) */
    #define PATTERN_TOGGLE_PULSE_LEN   2    /**< Length of separator pulse of pattern (for debugging) */
    #define PATTERN_DATA_ACTIVE_LEN (PATTERN_DATA_LEN - PATTERN_TOGGLE_PULSE_LEN)   /**< Length of data/payload information of pattern (for debugging) */
    /**
     * Reset Sequence of Pattern 
     * Low for ::PATTERN_RESET_LEN followed by a 'High' pulse of len ::PATTERN_TOGGLE_PULSE_LEN
     */
    #define PATTERN_RESET_SEQUENCE() \
    { \
        CLEAR_PATTERN_PIN(); \
        APPLICATION_DelayUs(PATTERN_RESET_LEN); \
        SET_PATTERN_PIN(); \
        APPLICATION_DelayUs(PATTERN_TOGGLE_PULSE_LEN); \
    }
    /**
     * End Sequence of Pattern
     * Low for ::PATTERN_TOGGLE_PULSE_LEN befor setting line to 'High'
     */
    #define PATTERN_END_SEQUENCE() \
    { \
        CLEAR_PATTERN_PIN(); \
        APPLICATION_DelayUs(PATTERN_TOGGLE_PULSE_LEN); \
        SET_PATTERN_PIN(); \
    }
    /**
     * Sequence for '1'
     */
    #define PATTERN_WRITE_1_SEQUENCE() \
    { \
        CLEAR_PATTERN_PIN(); \
        APPLICATION_DelayUs(PATTERN_TOGGLE_PULSE_LEN); \
        SET_PATTERN_PIN(); \
        APPLICATION_DelayUs(PATTERN_DATA_ACTIVE_LEN); \
    }

    /** Sequence for '0' */
    #define PATTERN_WRITE_0_SEQUENCE() \
    { \
        CLEAR_PATTERN_PIN(); \
        APPLICATION_DelayUs(PATTERN_DATA_ACTIVE_LEN); \
        SET_PATTERN_PIN(); \
        APPLICATION_DelayUs(PATTERN_TOGGLE_PULSE_LEN); \
    }
    
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************
    /**
     * Test initialization routine
     */
    extern void TEST_Initialize(void);
    /**
     * Test main routine
     * @param p_msg message handle to parse in test module main routine
     */
    extern void TEST_Tasks(sMSG_T *p_msg);
    /**
     * Apply reset to sensor module 
     * @param address   sensor address
     */
    extern void TEST_SensorApplyReset(uint8_t address);
    /**
     * Apply alarm to sensor module
     * @param address   sensor address
     */
    extern void TEST_SensorSetAlarm(uint8_t address);
    /**
     * Apply learn sequence to sensor module
     * @param address   sensor address
     */
    extern void TEST_SensorStartLearn(uint8_t address);

    /**
     * Get Pattern of given state
     * @param state application state 
     * @return pattern for application state, otherwise 0xAA
     */
    extern uint8_t TEST_GetPattern(uint8_t state);
    /**
     * Send out debug pattern (8-bit) on PATTERN_PIN EXT2_GPIO1
     * @param pattern pattern to send out
     */
    extern void TEST_DebugPattern8(uint8_t pattern);

    /**
     * Send out debug pattern (16-bit) on PATTERN_PIN EXT2_GPIO1
     * @param pattern pattern to send out
     */
    extern void TEST_DebugPattern16(uint16_t pattern);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _TEST_H */

/* *****************************************************************************
 End of File
 */
