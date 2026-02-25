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

/** \file application.h
 * This header file provides prototypes and defintions for the application.  
 */

#ifndef _APPLICATION_H    /* Guard against multiple inclusion */
#define _APPLICATION_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "definitions.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */
    /** Assertion for application module
     *  \param test condition for message print out
     *  \param message  message to print out if test is true
     */
    #define ASSERT(test,message) \
    { \
        if (test) { \
            SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "[Assertion] "); \
            SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, message); \
        } \
    }

    #define MSG_QUEUE_SIZE  10  /**< application message queue size*/
    #define MSG_DATA_SIZE   32  /**< message data buffer size */
    #define NUMBER_OF_SENSORS 5 /**< number of supported sensors in application */
    #define INVALID_SENSOR_ID 0x0000    /**< define to invalidate sensor entry */

    /** enum containing supported message ids */
    typedef enum {
        MSG_ID_INVALID,     /**< invalid message used for initialization */
        MSG_ID_APP_TRIGGER, /**< trigger application */
        MSG_ID_SEND_STATUS, /**< trigger send status output */
        MSG_ID_SENSOR_SLOT_TIMER, /**< message used for slotted communication with sensor devices */ 
        MSG_ID_CONSOLE_CMD_VERSION, /**< 'version' command received */
        MSG_ID_CONSOLE_CMD_START_LEARN_CENTRAL, /**< start learn mode on central device */
        MSG_ID_CONSOLE_CMD_START_LEARN_SENSOR, /**< start learn mode on sensor device */
        MSG_ID_CONSOLE_CMD_VERIFY, /**< 'verify' command received */
        MSG_ID_CONSOLE_CMD_SENSOR_LEARN, /**< 'sl' command received (sensor learn) */
        MSG_ID_CONSOLE_CMD_SENSOR_ALARM, /**< 'sa' command received (sensor alarm) */
        MSG_ID_CONSOLE_CMD_SENSOR_RESET, /**< 'sr' command received (sensor reset) */
        MSG_ID_CONSOLE_CMD_TEST, /**< 'test' command received */
        MSG_ID_RF_IRQ, /**< ATA8510 RF IRQ detected */
        NUM_MSG_IDS /**< number of message ids*/
    } eMSG_ID_T;
    
    /** enum containing application states */
    typedef enum {
        /* INIT */
        STATE_INIT, /**< Init state */
        STATE_WAIT_RF_SYS_RDY,  /**< Wait for ATA8510 SYS_RDY*/
        /* IDLE */
        STATE_IDLE, /**< Idle state */
        /* KEEP ALIVE */
        STATE_KEEP_ALIVE_TX_ACK,    /**< Send 'ACK' message if Keep Alive command is received */
        STATE_KEEP_ALIVE_TX_ACK_COMPLETE,   /**< Wait for ATA8510 TX complete */
        /* LEARN */
        STATE_LEARN,    /**< Initial learn state */
        STATE_LEARN_RX_PART_REQ,    /**< Wait until command 'RX_PART_REQ' is received */
        STATE_LEARN_TX_PART_REQ_RESP,   /**< Send command 'PART_REQ_RESP' */
        STATE_LEARN_TX_PART_REQ_RESP_COMPLETE, /**< Wait for ATA8510 TX complete */
        STATE_LEARN_TX_CON_VER_STAT,    /**< Send command 'CON_VER_STA' */
        STATE_LEARN_TX_CON_VER_STAT_COMPLETE,   /**< Wait for ATA8510 TX complete */
        STATE_LEARN_RX_ACK_MSG, /**< Wait until command 'ACK_MSG' is received */
        STATE_LEARN_PASS,   /**< Learning successful */
        STATE_LEARN_FAIL,   /**< Learning failed */
        /* ALARM*/
        STATE_ALARM,    /**< Initial Alarm State */
        STATE_ALARM_TX_ACK_MSG_COMPLETE,    /**< Wait for ATA8510 TX complete */
        /* CONNECTION VERIFICATION */
                STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP,  /**< Send command 'CON_VER_RESP' */
                STATE_CONNECTION_VERIFICATION_TX_CON_VER_RESP_COMPLETE, /**< Wait for Tx of 'CON_VER_RESP' is completed */
        /* UPDATE */
                STATE_UPDATE_TX_ACK,    /**< Create and send 'ACK_MSG' */
                STATE_UPDATE_TX_ACK_COMPLETE,   /**< Wait for Tx of 'ACK_MSG' is completed */
        /* ERROR */
        STATE_ERROR,  /**< Error state */
        NUMBER_STATES   /**< Number of application states */
    } eAPPLICATION_STATE_T;
    

    
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************
    /** data structure for a message used in application message queue */
    struct sMSG {
        eMSG_ID_T id;   /**< message id */
        uint8_t data[MSG_DATA_SIZE];    /**< message buffer */
    };
    /** typedef for ::sMSG \todo apply naming conventions sMsg_T*/
    typedef struct sMSG sMSG_T;

    /** data structure for the device id */
    struct sDeviceId {
        union {
            struct {
                uint16_t uid : 12;  /**< 12-bit Unique ID (UID) */
                uint16_t level : 4; /**< 4-bit sensor level */
            };
            uint16_t raw;   /**< 16-bit device id */
        };
    }__PACKED;
    /** typedef for ::sDeviceId */
    typedef struct sDeviceId sDeviceId_T;
    
    /** data structure for sensor status */
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
            uint8_t raw;    /**< 8-bit sensor status */
        };
    }__PACKED;
    /** typedef for ::sSensorStatus */
    typedef struct sSensorStatus sSensorStatus_T;
    
    /** data structure for sensor device*/
    struct sSensor {
        sDeviceId_T id; /**< device/sensor id */
        sSensorStatus_T status; /**< sensor status */
    }__PACKED;
    /** typedef for ::sSensor */
    typedef struct sSensor sSensor_T;
    
    /** application data structure
     *  contains application specific data such as states, queues, timer handles, ..
     */
    struct sAPPLICATION {
        eAPPLICATION_STATE_T state; /**< contains the application state */
        QueueHandle_t msg_queue;    /**< message queue for the application */
        uint32_t cnt;   /**< counter used for status output */
        SYS_TIME_HANDLE timer_status;   /**< periodic timer (1s period) for status printout */ 
        SYS_TIME_HANDLE timer_sensor_slot;  /**< periodic timer (200ms period) for slotted communication with sensor devices */ 
        SYS_TIME_HANDLE timer_timeout;  /**< single shot timer for timeout handling */
        
        bool button_pressed_at_reset;   /**< indicates if button is pressed at reset to enter learning mode */
        
        sDeviceId_T device_id;  /**< contains the device id of the central */
        sDeviceId_T candidate_device_id;    /**< device id of the candidate during learning mode */
        
        uint8_t sensor_slot; /**< contains the current slot information (0..(::NUMBER_OF_SENSORS-1)) */
        ///> \todo keep alive messsage --> put to union with learning data, connection verification data ....
        sDeviceId_T ka_device_id;
        
        // connection verification
        uint16_t /*sDeviceId_T*/ con_ver_device_id; /**< device id of new sensor device */
        uint8_t con_ver_device_type;    /**< device type of new sensor device */
    };
    /**
     * application data structure
     */
    typedef struct sAPPLICATION sAPPLICATION_T;
    
    /** data structure for a function pair consists of 
     * - 32-bit function id
     * - void * function pointer
     */
    struct sFuncPair {
        uint32_t id;    /**< 32-bit function id */
        void *func; /**< function pointer */
    };
    /** typedef for ::sFuncPair */
    typedef struct sFuncPair sFuncPair_T;

    /** data structure for a message pair which consists of 
     * - 32-bit message id
     * - message string
     */
    struct sMsgPair {
        uint32_t id;    /**< 32-bit message id */
        const char *msg;    /**< message string */
    };
    /** typedef for ::sMsgPair */
    typedef struct sMsgPair sMsgPair_T;
    
    /** typedef for applications state machine functions */
    typedef void (* fpVoidFuncMsg_T)(sMSG_T *p_msg);

    
    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************
    /**
     * application data
     */
    extern sAPPLICATION_T app_data; 
    // --GW-- extern volatile bool do_sync;
    // --GW-- extern volatile uint8_t slot;
    
    /**
     * Sensor list 
     */
    extern sSensor_T sensor_array[NUMBER_OF_SENSORS];
    
    /**
     * Get sensor device with given 'id'
     * @param id sensor id
     * @return pointer to sensor device with given id, otherwise NULL
     */
    extern sSensor_T *APPLICATION_GetSensor(sDeviceId_T id);
    
    /**
     * Get sensor slot of given sensor for slotted communication with child sensors
     * @param id sensor id
     * @return slot number of given sensor, otherwise -1
     */
    extern int8_t APPLICATION_GetSensorSlot(sDeviceId_T id);
    
    /**
     * Add sensor device with given 'id' to sensor list
     * @param id sensor id 
     * @return pointer to added sensor device, otherwise NULL
     */
    extern sSensor_T *APPLICATION_AddSensor(sDeviceId_T id);
    /**
     * Returns the number of connected sensor devices
     * @return number of connected sensor devices
     */
    extern uint8_t APPLICATION_GetNumberOfSensors(void);
    /**
     * Application status timer (triggered every 1s)
     * @param context pointr to context (not used, therefore always NULL)
     */
    extern void APPLICATION_StatusTimer(uintptr_t context);
    
    /** 
     * Application timer for slotted communication with child sensors (200ms interval)
     * @param context pointer to context (not used, therefore always NULL)
     */
    extern void APPLICATION_SensorSlotTimer(uintptr_t context);
    /**
     * Application initialization routine
     */
    extern void APPLICATION_Initialize(void);
    /**
     * Application main routine
     */
    extern void APPLICATION_Tasks(void);
    
    /**
     * Get corresponding function of given id
     * @param id    function id (32-bit)
     * @param p_func_table  function table
     * @param size  number of entries in function table
     * @return function pointer if function is in table, otherwise NULL
     */
    extern void *APPLICATION_GetFunction(uint32_t id, const sFuncPair_T *p_func_table, size_t size);
    
    /**
     * Get correspondign message of given id
     * @param id    message id (32-bit)
     * @param p_msg_table   message table
     * @param size  number of entries in message table
     * @return pointer to message if message is in table, otherwise NULL
     */
    extern const char *APPLICATION_GetMsg(uint32_t id, const sMsgPair_T *p_msg_table, size_t size);
    
    /**
     * Delay Function
     * @param delay_us  Delay in us
     */
    extern void APPLICATION_DelayUs(uint32_t delay_us);
    /**
     * Delay Function
     * @param delay_ms  Delay in ms
     */
    extern void APPLICATION_DelayMs(uint32_t delay_ms);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APPLICATION_H */

/* *****************************************************************************
 End of File
 */
