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

/** \file command.h
 * contains the command set for the RF communication in the application
 */

#ifndef _COMMAND_H    /* Guard against multiple inclusion */
#define _COMMAND_H


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

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /** typedef for message id's */
    typedef enum {
        KA_MSG = 0x03,  /**< Keep Alive message id */
        UD_MSG = 0x04,  /**< Update message id */
        ACK_MSG = 0x05, /**< Acknowledge message id */
        AL_MSG = 0x06,  /**< Alarm messge id */
        PART_REQ = 0x07,    /**< Participation Request message id */
        PART_REQ_RESP = 0x08,   /**<  Participation Request Response message id */
        MEM_KEY = 0x09, /**< Member Key exchange message id */
        CAN_KEY = 0x0A, /**< Candidate Key exchange message id */
        CON_VER_STA = 0x0B, /**< Connection Verification Status message id */
        CON_VER_REQ = 0x0C, /**< Connection Verification Request message id */
        CON_VER_RESP = 0x0D,    /**< Connection Verification Response message id */
        PAY_MSG = 0x0E, /**< Payload message id */
        NUM_MSGS    /**< Number of message id's */
    } eMsg_T;
    /** typedef for alarm state */
    typedef enum {
        ALARM_OFF = 0,  /**< alarm is off */
        ALARM_ON = 1    /**< alarm is on  */
    } eAlarm_T;
    /** enumeration for security bit in sStatus_T
     */
    typedef enum {
        SECURITY_OFF = 0,   /**< Security NOT used for next communication */
        SECURITY_ON = 1 /**< Security used for next communication */
    } eSecurity_T;

    /** data structure containing the sensor status */
    struct sStatus {
        union {
            struct {
                uint8_t bmz_update : 1; /**< Bit 0: BMZ Update: If this bit is set to 1, 
                                         * the upper level device is notified about a
                                         * verification of the ongoing request at 
                                         * the BMZ. This enables the upper level 
                                         * devices to stay in receive mode waiting
                                         * for response from BMZ
                                         */
                uint8_t accept_device : 1;  /**< Bit 1: used in CON_VER_RESP, 1=device accepted, otherwise device ignored  */
                uint8_t alarm : 1;      /**< Bit 2: ALARM: If this bit is set to 1,
                                         * Alarm is ON in the network. */
                uint8_t payload : 1;    /**< Bit 3: Payload: If this bit ist set to 1, 
                                         * it indicates there is more to communicate
                                         * required and a payload message will be 
                                         * triggered after this message
                                         */
                uint8_t security : 1;   /**< Bit 4: If this bit is set to 1, security 
                                         * is used for next communication
                                         */
                uint8_t okay : 1;   /**< Bit 5: If this bit is set to 1, the last 
                                     * command is understood
                                     */
                uint8_t network : 1;    /**< Bit 6: If this bit is set to 1, 
                                         * there are further levels above this level.
                                         * That means it's not the end of the branch.
                                         */
                uint8_t battery : 1;    /**< Bit 7: If this bit is set to 1, 
                                         * battery voltage is below the configured
                                         * threshold
                                         */
            };
            uint8_t raw;    /**< 8-bit sensor status */
        };
    }__PACKED;
    /** typedef for ::sStatus */
    typedef struct sStatus sStatus_T;
    
    /** data structure for command header */
    struct sCommandHeader {
        sDeviceId_T id; /**< device id (16-bit) */
        uint8_t msg;    /**< message id (8-bit) */
        sStatus_T sta;  /**< status byte (8-bit) */
    }__PACKED;
    /** typedef for ::sCommandHeader */
    typedef struct sCommandHeader sCommandHeader_T;

    /** general data structure for commands without payload */
    struct sCommandNoPayload {
        sCommandHeader_T hdr;   /**< command header */
    }__PACKED;
    
    /*
     * KA_MSG
     * The keep alive message is the regular communication triggered by the upper 
     * level device. It's answered with an ACK_MSG or UD_MSG
     */
    /** typedef for 'KA_MSG' command (keep alive) */
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
    /** type definition for commands without payload */
    typedef struct sCommandNoPayload sCommandUpdate_T;
    /* 
     * ACK_MSG
     */
    /** typedef for 'ACK_MSG' command (Acknowledgement) */
    typedef struct sCommandNoPayload sCommandAckMsg_T;

    /** data structure for 'ACK_MSG' message used to acknowledge 'KA_MSG' message */
    struct sCommandAckKaMsg {
        sCommandHeader_T hdr;   /**< command header */
        int16_t correction_offset;   /**< correction value for synchronization of 'KA_MSG' messages, reduces/extend sleep time for 1 interval cycle */
        int16_t correction_interval;    /**< correction value for 'KA_MSG' interval, value applied to following interval cylces */
    }__PACKED;
    /** typedef for ::sCommandAckKaMsg */
    typedef struct sCommandAckKaMsg sCommandAckKaMsg_T;    
    
    
    /* 
     * AL_MSG
     */
    /** typedef for 'AL_MSG' command (Alarm) */
    typedef struct sCommandNoPayload sCommandAlMsg_T;
    
    /*
     * PART_REQ
     */

    /** enumeration for device type of 'PART_REQ' command
     */
    typedef enum {
        DEVICE_TYPE_UNKNOWN = 0,   /**< unknown device */
        DEVICE_TYPE_ATA8510,   /**< ATA8510 device */
        NUMBER_OF_DEVICE_TYPES  /**< number of supported device types */
    } eDeviceType_T;
    /** data structure for command 'PART_REQ' */
    struct sCommandPartReq {
        sCommandHeader_T hdr;   /**< command header */
        eDeviceType_T device_type;    /**< device type of the sensor device */
    }__PACKED;
    /** typedef for ::sCommandPartReq */
    typedef struct sCommandPartReq sCommandPartReq_T;

    /*
     * PART_REQ_RESP
     */
    /** data structure for command 'PART_REQ_RESP' */
    struct sCommandPartReqResp {
        sCommandHeader_T hdr;   /**< command header */
        uint8_t count;  /**< KA message counter (modulo 10) */
    }__PACKED;
    /** typedef for ::sCommandPartReqResp */
    typedef struct sCommandPartReqResp sCommandPartReqResp_T;    

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

    /** data structure for command 'CON_VER_STA' */
    struct sCommandConVerSta {
        sCommandHeader_T hdr;   /**< header */
        uint16_t status;    /**< payload/status */
    }__PACKED;
    /** typedef for structure ::sCommandConVerSta */
    typedef struct sCommandConVerSta sCommandConVerSta_T;
    
    /*
     * CON_VER_REQ
     */
    /** data structure for 'CON_VER_REQ' command */
    struct sCommandConVerReq {
        sCommandHeader_T hdr;   /**< command header*/
        uint16_t device_id; /**< device id */
        uint8_t device_type;    /**< device type */
    }__PACKED;
    /** type definition for structure ::sCommandConVerReq */
    typedef struct sCommandConVerReq sCommandConVerReq_T;
    
    /*
     * CON_VER_RESP
     */
    /** data structure for 'CON_VER_RESP' command */
    struct sCommandConVerResp {
        sCommandHeader_T hdr;   /**< command header */
        uint16_t device_id; /**< device id */
    }__PACKED;
    /** type definition for structure ::sCommandConVerResp */
    typedef struct sCommandConVerResp sCommandConVerResp_T;

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _COMMAND_H */

/* *****************************************************************************
 End of File
 */
