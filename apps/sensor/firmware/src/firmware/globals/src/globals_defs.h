/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/globals/src/globals_defs.h $
  $LastChangedRevision: 648642 $
  $LastChangedDate: 2021-10-26 15:28:50 +0200 (Di, 26 Okt 2021) $
  $LastChangedBy: swagner $
-------------------------------------------------------------------------------
  Project:      ATA5831
  Target MCU:   ATA5831
  Compiler:     IAR C/C++ Compiler for AVR 5.51.0
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

/** \file globals_defs.h
*/
#ifndef GLOBALS_DEFS_H
#define GLOBALS_DEFS_H

#if defined(__IAR_SYSTEMS_ICC__) || defined(__XC8_CC__)

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/* bits and masks */
#define BIT_7    7
#define BIT_6      6
#define BIT_5      5
#define BIT_4      4
#define BIT_3      3
#define BIT_2      2
#define BIT_1      1
#define BIT_0      0

#define BIT_MASK_7     (uint8_t)(1U << BIT_7)
#define BIT_MASK_6     (uint8_t)(1U << BIT_6)
#define BIT_MASK_5     (uint8_t)(1U << BIT_5)
#define BIT_MASK_4     (uint8_t)(1U << BIT_4)
#define BIT_MASK_3     (uint8_t)(1U << BIT_3)
#define BIT_MASK_2     (uint8_t)(1U << BIT_2)
#define BIT_MASK_1     (uint8_t)(1U << BIT_1)
#define BIT_MASK_0     (uint8_t)(1U << BIT_0)

/** \brief <b>NUM_EEPROM_SERVICES</b>
    is the number of services located in EEPROM
*/
#define NUM_EEPROM_SERVICES            3U

/** \brief <b>NUM_SRAM_SERVICES</b>
    is the number of services located in SRAM
*/
#define NUM_SRAM_SERVICES            2U

/** \brief <b>NUM_SERVICES</b>
    is the total number of services in the application
*/
#define NUM_SERVICES                (NUM_EEPROM_SERVICES + NUM_SRAM_SERVICES)

/** \brief <b>NUM_CHANNELS_PER_SERVICE</b>
    is the number of channels located in one service
*/
#define NUM_CHANNELS_PER_SERVICE    3U

/** \brief <b>NUM_POLL_CHAN_CONFIG</b>
    is the number of polling channel configurations provided as SRAM array
    IMPORTANT: must be of size 2^x to guarantee correct work of corresponding bit mask
*/
#define NUM_POLL_CHAN_CONFIG            16U
#define BM_NUM_POLL_CHAN_CONFIG         (NUM_POLL_CHAN_CONFIG - 1U)

/** \brief <b>RFBUFFERMASK</b>
    is the mask for Rx and Tx buffers
*/
#define RFBUFFERMASK     (uint8_t)0x1F

/** \brief <b>RFBUFFERSIZE</b>
    is the size of Rx and Tx buffers
*/
#define RFBUFFERSIZE     (uint8_t)32

/** \brief <b>RSSIBUFFERMASK</b>
    is the mask of RSSI buffer
*/
#define RSSIBUFFERMASK   (uint8_t)0x1F

/** \brief <b>RSSIBUFFERSIZE</b>
    is the size of RSSI buffer
*/
#define RSSIBUFFERSIZE   (uint8_t)32

/** \brief <b>NEVENTBYTES</b>
    is the number of event bytes
*/
#define NEVENTBYTES 4

/** \brief <b>DEBUG_ERROR_CODE_xxx</b>
    are the errorCodes for ATA5831 SW
*/
#define DEBUG_ERROR_CODE_SYSTEM_ERROR_EEPROM_NOT_VALID                  0U                                                                  // 000<->00
#define DEBUG_ERROR_CODE_SETIDLEMODE_MISS_SSMRDY                        DEBUG_ERROR_CODE_SYSTEM_ERROR_EEPROM_NOT_VALID + 1U                 // 001<->01
#define DEBUG_ERROR_CODE_SETIDLEMODE_TIMER_LOCKED                       DEBUG_ERROR_CODE_SETIDLEMODE_MISS_SSMRDY + 1U                       // 002<->02
#define DEBUG_ERROR_CODE_RX_STATESTARTSSM_TIMER_LOCKED                  DEBUG_ERROR_CODE_SETIDLEMODE_TIMER_LOCKED + 1U                      // 003<->03
#define DEBUG_ERROR_CODE_RX_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT      DEBUG_ERROR_CODE_RX_STATESTARTSSM_TIMER_LOCKED + 1U                 // 004<->04
#define DEBUG_ERROR_CODE_TX_STATESTARTSSM_TIMER_LOCKED                  DEBUG_ERROR_CODE_RX_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT + 1U     // 005<->05
#define DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT                    DEBUG_ERROR_CODE_TX_STATESTARTSSM_TIMER_LOCKED + 1U                 // 006<->06
#define DEBUG_ERROR_CODE_POLL_STATESTARTSSM_TIMER_LOCKED                DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT + 1U                   // 007<->07
#define DEBUG_ERROR_CODE_POLL_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT    DEBUG_ERROR_CODE_POLL_STATESTARTSSM_TIMER_LOCKED + 1U               // 008<->08
#define DEBUG_ERROR_CODE_ANTTUNE_STATESTARTSSM_TIMER_LOCKED             DEBUG_ERROR_CODE_POLL_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT + 1U   // 009<->09
#define DEBUG_ERROR_CODE_ANTTUNE_STATEWAIT4SSMRDY_TIMEOUT               DEBUG_ERROR_CODE_ANTTUNE_STATESTARTSSM_TIMER_LOCKED + 1U            // 010<->0A
#define DEBUG_ERROR_CODE_VCOCAL_STATESTARTSSM_TIMER_LOCKED              DEBUG_ERROR_CODE_ANTTUNE_STATEWAIT4SSMRDY_TIMEOUT + 1U              // 011<->0B
#define DEBUG_ERROR_CODE_VCOCAL_STATEWAIT4SSMRDY_TIMEOUT                DEBUG_ERROR_CODE_VCOCAL_STATESTARTSSM_TIMER_LOCKED + 1U             // 012<->0C
#define DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMER_LOCKED                       DEBUG_ERROR_CODE_VCOCAL_STATEWAIT4SSMRDY_TIMEOUT + 1U               // 013<->0D
#define DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT                            DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMER_LOCKED + 1U                      // 014<->0E
#define DEBUG_ERROR_CODE_POLLING_TIMER1_LOCKED                          DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT + 1U                           // 015<->0F
#define DEBUG_ERROR_CODE_INVALID_OPM_SWITCHING                          DEBUG_ERROR_CODE_POLLING_TIMER1_LOCKED + 1U                         // 016<->10
#define DEBUG_ERROR_CODE_INVALID_OPM_MODE_DURING_TUNE_AND_CHECK         DEBUG_ERROR_CODE_INVALID_OPM_SWITCHING + 1U                         // 017<->11
#define DEBUG_ERROR_CODE_AVCCLOW_DURING_TX                              DEBUG_ERROR_CODE_INVALID_OPM_MODE_DURING_TUNE_AND_CHECK + 1U        // 018<->12
#define DEBUG_ERROR_CODE_SERVICE_INIT_FAILURE                           DEBUG_ERROR_CODE_AVCCLOW_DURING_TX + 1U                             // 019<->13
#define DEBUG_ERROR_CODE_DFIFO_OVER_UNDER_FLOW                          DEBUG_ERROR_CODE_SERVICE_INIT_FAILURE + 1U                          // 020<->14
#define DEBUG_ERROR_CODE_SFIFO_OVER_UNDER_FLOW                          DEBUG_ERROR_CODE_DFIFO_OVER_UNDER_FLOW + 1U                         // 021<->15
#define DEBUG_ERROR_CODE_RSSI_STATESTARTSSM_TIMER_LOCKED                DEBUG_ERROR_CODE_SFIFO_OVER_UNDER_FLOW + 1U                         // 022<->16
#define DEBUG_ERROR_CODE_SRC_FRC_CALIB_FAILED                           DEBUG_ERROR_CODE_RSSI_STATESTARTSSM_TIMER_LOCKED + 1U               // 023<->17
#define DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR                        DEBUG_ERROR_CODE_SRC_FRC_CALIB_FAILED + 1U                          // 024<->18
#define DEBUG_ERROR_CODE_TEMPMEAS_STATESTARTSSM_TIMER_LOCKED            DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR + 1U                       // 025<->19
#define DEBUG_ERROR_CODE_TEMPMEAS_STATEWAIT4SSMRDY_TIMEOUT              DEBUG_ERROR_CODE_TEMPMEAS_STATESTARTSSM_TIMER_LOCKED + 1U           // 026<->1A
#define DEBUG_ERROR_CODE_AVCCLOW_TIMEOUT                                DEBUG_ERROR_CODE_TEMPMEAS_STATEWAIT4SSMRDY_TIMEOUT + 1U             // 027<->1B
#define DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMER_LOCKED  DEBUG_ERROR_CODE_AVCCLOW_TIMEOUT + 1U                               // 028<->1C
#define DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMER_LOCKED   DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMER_LOCKED + 1U // 029<->1D
#define DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMER_LOCKED   DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMER_LOCKED + 1U  // 030<->1E
#define DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMEOUT       DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMER_LOCKED + 1U  // 031<->1F
#define DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMEOUT        DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMEOUT + 1U      // 032<->20
#define DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMEOUT        DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMEOUT + 1U       // 033<->21

/* ------------------------------------------------------------------------- */
/* TRXCONF_TUNE_CHECK_CONFIG                                                 */
/* ------------------------------------------------------------------------- */
#define TUNE_CHECK_CONFIG_ANTENNA_TUNING    BIT_7
#define TUNE_CHECK_CONFIG_TEMP_MEASUREMENT  BIT_6
#define TUNE_CHECK_CONFIG_SRC_CALIB         BIT_5
#define TUNE_CHECK_CONFIG_FRC_CALIB         BIT_4
#define TUNE_CHECK_CONFIG_VCO_CALIB         BIT_3
#define TUNE_CHECK_CONFIG_RF_CALIB          BIT_2
#define TUNE_CHECK_CONFIG_SELF_CHECK        BIT_1
#define TUNE_CHECK_CONFIG_REG_REFRESH       BIT_0

#define BM_TUNE_CHECK_CONFIG_ANTENNA_TUNING    BIT_MASK_7
#define BM_TUNE_CHECK_CONFIG_TEMP_MEASUREMENT  BIT_MASK_6
#define BM_TUNE_CHECK_CONFIG_SRC_CALIB         BIT_MASK_5
#define BM_TUNE_CHECK_CONFIG_FRC_CALIB         BIT_MASK_4
#define BM_TUNE_CHECK_CONFIG_VCO_CALIB         BIT_MASK_3
#define BM_TUNE_CHECK_CONFIG_RF_CALIB          BIT_MASK_2
#define BM_TUNE_CHECK_CONFIG_SELF_CHECK        BIT_MASK_1
#define BM_TUNE_CHECK_CONFIG_REG_REFRESH       BIT_MASK_0


/* ------------------------------------------------------------------------- */
/* TRXCONF_SYSTEM_MODE_CONFIG                                                */
/* ------------------------------------------------------------------------- */
#define SYS_MODE_CONFIG_RF_CALIBRATION          BIT_7
#define SYS_MODE_CONFIG_ANTENNA_TUNING          BIT_6
#define SYS_MODE_CONFIG_VCO_TUNING              BIT_5
#define SYS_MODE_CONFIG_IDLE_MODE_SELECTOR      BIT_4
#define SYS_MODE_CONFIG_DIRECT_SWITCH           BIT_3
#define SYS_MODE_CONFIG_TRANSPARENT_MODE        BIT_2
#define SYS_MODE_CONFIG_OPM1                    BIT_1
#define SYS_MODE_CONFIG_OPM0                    BIT_0

#define BM_SYS_MODE_CONFIG_RF_CALIBRATION       BIT_MASK_7
#define BM_SYS_MODE_CONFIG_ANTENNA_TUNING       BIT_MASK_6
#define BM_SYS_MODE_CONFIG_VCO_TUNING           BIT_MASK_5
#define BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR   BIT_MASK_4
#define BM_SYS_MODE_CONFIG_DIRECT_SWITCH        BIT_MASK_3
#define BM_SYS_MODE_CONFIG_TRANSPARENT_MODE     BIT_MASK_2

#define BM_SYS_MODE_CONFIG_OPM                  ( BIT_MASK_1 | BIT_MASK_0 )
#define BM_SYS_MODE_CONFIG_OPM1                 BIT_MASK_1
#define BM_SYS_MODE_CONFIG_OPM0                 BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* TRXCONF_MISC_TRIGGER                                                      */
/* ------------------------------------------------------------------------- */
#define TRXCONF_MISC_TRIGGER_PC4_OLD                    BIT_1

#define BM_TRXCONF_MISC_TRIGGER_PC4_OLD                 BIT_MASK_1


/* ------------------------------------------------------------------------- */
/* sExtReq.serviceInitConfig                                                 */
/* ------------------------------------------------------------------------- */
#define EXT_REQ_SERVICE_INIT_CONFIG_UPDATE_FLAG         BIT_7
#define EXT_REQ_SERVICE_INIT_CONFIG_EEPROM_NUMBER       BIT_1
#define EXT_REQ_SERVICE_INIT_CONFIG_SRAM_NUMBER         BIT_0

#define BM_EXT_REQ_SERVICE_INIT_CONFIG_UPDATE_FLAG      BIT_MASK_7
#define BM_EXT_REQ_SERVICE_INIT_CONFIG_EEPROM_NUMBER   ( BIT_MASK_1 | BIT_MASK_2 )
#define BM_EXT_REQ_SERVICE_INIT_CONFIG_SRAM_NUMBER      BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sExtReq.miscTrigger                                                       */
/* ------------------------------------------------------------------------- */
#define EXT_REQ_MISC_TRIGGER_START_RSSI                 BIT_0

#define BM_EXT_REQ_MISC_TRIGGER_START_RSSI              BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* Operation modes                                                           */
/* ------------------------------------------------------------------------- */
#define OPM_IDLE        0x00U
#define OPM_TX          0x01U
#define OPM_RX          0x02U
#define OPM_POLLING     0x03U

/* ------------------------------------------------------------------------- */
/* Error handling                                                            */
/* ------------------------------------------------------------------------- */
#define RXERR_IGNORE          0x00U    /* ignore occured bitcheck errors */
#define RXERR_STOP_RECEIVE    0x01U    /* stop data receiving */
#define RXERR_BYTE_RECEIVE    0x02U    /* receive byte completely, then stop data receiving */
#define RXERR_CONTINUOUS      0x03U    /* restart demodulator and go ahead data receiving */

/* ------------------------------------------------------------------------- */
/* TRXCONF_SERVICE_CHANNEL_CONFIG                                            */
/* ------------------------------------------------------------------------- */
#define SVC_CH_CONFIG_PATHB         BIT_7
#define SVC_CH_CONFIG_PATHA         BIT_6
#define SVC_CH_CONFIG_CH1           BIT_5
#define SVC_CH_CONFIG_CH0           BIT_4

#define SVC_CH_CONFIG_SER2          BIT_2
#define SVC_CH_CONFIG_SER1          BIT_1
#define SVC_CH_CONFIG_SER0          BIT_0

#define BM_SVC_CH_CONFIG_PATHB      BIT_MASK_7
#define BM_SVC_CH_CONFIG_PATHA      BIT_MASK_6

#define BM_SVC_CH_CONFIG_CH         ( BIT_MASK_5 | BIT_MASK_4 )
#define BM_SVC_CH_CONFIG_CH1        BIT_MASK_5
#define BM_SVC_CH_CONFIG_CH0        BIT_MASK_4

#define BM_SVC_CH_CONFIG_SER        ( BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SVC_CH_CONFIG_SER2       BIT_MASK_2
#define BM_SVC_CH_CONFIG_SER1       BIT_MASK_1
#define BM_SVC_CH_CONFIG_SER0       BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* TRXCONF_SYSTEM_CONFIG                                                     */
/* ------------------------------------------------------------------------- */
#define TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA                   BIT_7
#define TRXCONF_SYSTEM_CONFIG_SRCAO                         BIT_5
#define TRXCONF_SYSTEM_CONFIG_FRCAO                         BIT_4
#define TRXCONF_SYSTEM_CONFIG_SFIFO_OFL_UFL_RX_DISABLE      BIT_3
#define TRXCONF_SYSTEM_CONFIG_DFIFO_OFL_UFL_RX_DISABLE      BIT_2
#define TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR            BIT_1
#define TRXCONF_SYSTEM_CONFIG_VS5V_SELECTOR                 BIT_0

#define BM_TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA                BIT_MASK_7
#define BM_TRXCONF_SYSTEM_CONFIG_SRCAO                      BIT_MASK_5
#define BM_TRXCONF_SYSTEM_CONFIG_FRCAO                      BIT_MASK_4
#define BM_TRXCONF_SYSTEM_CONFIG_SFIFO_OFL_UFL_RX_DISABLE   BIT_MASK_3
#define BM_TRXCONF_SYSTEM_CONFIG_DFIFO_OFL_UFL_RX_DISABLE   BIT_MASK_2
#define BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR         BIT_MASK_1
#define BM_TRXCONF_SYSTEM_CONFIG_VS5V_SELECTOR              BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* TRXCONF_SYSTEM_IDSCANSTATUS                                               */
/* ------------------------------------------------------------------------- */
#define SYS_ID_SCAN_STATUS_RESULT           BIT_7
#define SYS_ID_SCAN_STATUS_VALID            BIT_6
#define SYS_ID_SCAN_STATUS_BUF_FULL         BIT_5

#define BM_SYS_ID_SCAN_STATUS_RESULT        BIT_MASK_7
#define BM_SYS_ID_SCAN_STATUS_VALID         BIT_MASK_6
#define BM_SYS_ID_SCAN_STATUS_BUF_FULL      BIT_MASK_5
#define BM_SYS_ID_SCAN_STATUS_RESET_FLAGS   ( BM_SYS_ID_SCAN_STATUS_RESULT | BM_SYS_ID_SCAN_STATUS_VALID | BM_SYS_ID_SCAN_STATUS_BUF_FULL )

#define BM_SYS_IDS_ENABLED                  (uint8_t)0x1F

/* ------------------------------------------------------------------------- */
/* TRXCONF_SYSTEM_IDSCANCTRL                                                 */
/* ------------------------------------------------------------------------- */
#define SYS_ID_SCAN_CTRL_IDSCAN_ACTIVE      BIT_7
#define SYS_ID_SCAN_CTRL_EOTB               BIT_6
#define SYS_ID_SCAN_CTRL_EOTA               BIT_5

#define BM_SYS_ID_SCAN_CTRL_IDSCAN_ACTIVE   BIT_MASK_7
#define BM_SYS_ID_SCAN_CTRL_EOTB            BIT_MASK_6
#define BM_SYS_ID_SCAN_CTRL_EOTA            BIT_MASK_5

/* ------------------------------------------------------------------------- */
/* pinEventConfig_t                                                          */
/* ------------------------------------------------------------------------- */
#define PIN_EVENT_CONFIG_POWERON    BIT_7
#define PIN_EVENT_CONFIG_DEBUG      BIT_6
#define PIN_EVENT_CONFIG_NPWR6      BIT_5
#define PIN_EVENT_CONFIG_NPWR5      BIT_4
#define PIN_EVENT_CONFIG_NPWR4      BIT_3
#define PIN_EVENT_CONFIG_NPWR3      BIT_2
#define PIN_EVENT_CONFIG_NPWR2      BIT_1
#define PIN_EVENT_CONFIG_NPWR1      BIT_0

#define BM_PIN_EVENT_CONFIG_POWERON    BIT_MASK_7
#define BM_PIN_EVENT_CONFIG_DEBUG      BIT_MASK_6
#define BM_PIN_EVENT_CONFIG_NPWR6      BIT_MASK_5
#define BM_PIN_EVENT_CONFIG_NPWR5      BIT_MASK_4
#define BM_PIN_EVENT_CONFIG_NPWR4      BIT_MASK_3
#define BM_PIN_EVENT_CONFIG_NPWR3      BIT_MASK_2
#define BM_PIN_EVENT_CONFIG_NPWR2      BIT_MASK_1
#define BM_PIN_EVENT_CONFIG_NPWR1      BIT_MASK_0


/* ------------------------------------------------------------------------- */
/* sysEventConfig_t                                                          */
/* ------------------------------------------------------------------------- */
#define SYS_EVENT_CONFIG_SYS_ERR        BIT_7
#define SYS_EVENT_CONFIG_CMD_RDY        BIT_6
#define SYS_EVENT_CONFIG_SYS_RDY        BIT_5
#define SYS_EVENT_CONFIG_AVCCLOW        BIT_4
#define SYS_EVENT_CONFIG_LOWBATT        BIT_3
#define SYS_EVENT_CONFIG_RX_ACTIVE_EN   BIT_2
#define SYS_EVENT_CONFIG_RX_ACTIVE_POL  BIT_1
#define SYS_EVENT_CONFIG_EVENTPIN_POL   BIT_0

#define BM_SYS_EVENT_CONFIG_SYS_ERR         BIT_MASK_7
#define BM_SYS_EVENT_CONFIG_CMD_RDY         BIT_MASK_6
#define BM_SYS_EVENT_CONFIG_SYS_RDY         BIT_MASK_5
#define BM_SYS_EVENT_CONFIG_AVCCLOW         BIT_MASK_4
#define BM_SYS_EVENT_CONFIG_LOWBATT         BIT_MASK_3
#define BM_SYS_EVENT_CONFIG_RX_ACTIVE_EN    BIT_MASK_2
#define BM_SYS_EVENT_CONFIG_RX_ACTIVE_POL   BIT_MASK_1
#define BM_SYS_EVENT_CONFIG_EVENTPIN_POL    BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* events_power                                                              */
/* ------------------------------------------------------------------------- */
#define EVENTS_POWER_PWRON                  BIT_7
#define EVENTS_POWER_DEBUG                  BIT_6
#define EVENTS_POWER_NPWRON6                BIT_5
#define EVENTS_POWER_NPWRON5                BIT_4
#define EVENTS_POWER_NPWRON4                BIT_3
#define EVENTS_POWER_NPWRON3                BIT_2
#define EVENTS_POWER_NPWRON2                BIT_1
#define EVENTS_POWER_NPWRON1                BIT_0

#define BM_EVENTS_POWER_PWRON               BIT_MASK_7
#define BM_EVENTS_POWER_DEBUG               BIT_MASK_6
#define BM_EVENTS_POWER_NPWRON6             BIT_MASK_5
#define BM_EVENTS_POWER_NPWRON5             BIT_MASK_4
#define BM_EVENTS_POWER_NPWRON4             BIT_MASK_3
#define BM_EVENTS_POWER_NPWRON3             BIT_MASK_2
#define BM_EVENTS_POWER_NPWRON2             BIT_MASK_1
#define BM_EVENTS_POWER_NPWRON1             BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* events_system                                                             */
/* ------------------------------------------------------------------------- */
#define EVENTS_SYSTEM_SYS_ERR               BIT_7
#define EVENTS_SYSTEM_CMD_RDY               BIT_6
#define EVENTS_SYSTEM_SYS_RDY               BIT_5
#define EVENTS_SYSTEM_AVCCLOW               BIT_4
#define EVENTS_SYSTEM_LOWBATT               BIT_3
#define EVENTS_SYSTEM_RSSI_BUF              BIT_2
#define EVENTS_SYSTEM_RX_BUF                BIT_1
#define EVENTS_SYSTEM_TX_BUF                BIT_0

#define BM_EVENTS_SYSTEM_SYS_ERR            BIT_MASK_7
#define BM_EVENTS_SYSTEM_CMD_RDY            BIT_MASK_6
#define BM_EVENTS_SYSTEM_SYS_RDY            BIT_MASK_5
#define BM_EVENTS_SYSTEM_AVCCLOW            BIT_MASK_4
#define BM_EVENTS_SYSTEM_LOWBATT            BIT_MASK_3
#define BM_EVENTS_SYSTEM_RSSI_BUF           BIT_MASK_2
#define BM_EVENTS_SYSTEM_RX_BUF             BIT_MASK_1
#define BM_EVENTS_SYSTEM_TX_BUF             BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* events_events                                                             */
/* ------------------------------------------------------------------------- */
#define EVENTS_EVENTS_ID_CHECKA             BIT_7
#define EVENTS_EVENTS_WCOA                  BIT_6
#define EVENTS_EVENTS_SOTA                  BIT_5
#define EVENTS_EVENTS_EOTA                  BIT_4

#define EVENTS_EVENTS_ID_CHECKB             BIT_3
#define EVENTS_EVENTS_WCOB                  BIT_2
#define EVENTS_EVENTS_SOTB                  BIT_1
#define EVENTS_EVENTS_EOTB                  BIT_0

#define BM_EVENTS_EVENTS_ID_CHECKA          BIT_MASK_7
#define BM_EVENTS_EVENTS_WCOA               BIT_MASK_6
#define BM_EVENTS_EVENTS_SOTA               BIT_MASK_5
#define BM_EVENTS_EVENTS_EOTA               BIT_MASK_4

#define BM_EVENTS_EVENTS_ID_CHECKB          BIT_MASK_3
#define BM_EVENTS_EVENTS_WCOB               BIT_MASK_2
#define BM_EVENTS_EVENTS_SOTB               BIT_MASK_1
#define BM_EVENTS_EVENTS_EOTB               BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* events_cmdRdyConf                                                         */
/* ------------------------------------------------------------------------- */
#define EVENTS_CMDRDYCONF_ANT_TUNE      BIT_7
#define EVENTS_CMDRDYCONF_TEMP_MEAS     BIT_6
#define EVENTS_CMDRDYCONF_SRC_CAL       BIT_5
#define EVENTS_CMDRDYCONF_FRC_CAL       BIT_4
#define EVENTS_CMDRDYCONF_VCO_CAL       BIT_3
#define EVENTS_CMDRDYCONF_RF_CAL        BIT_2
#define EVENTS_CMDRDYCONF_SELF_CHECK    BIT_1
#define EVENTS_CMDRDYCONF_TX            BIT_0

#define BM_EVENTS_CMDRDYCONF_ANT_TUNE      BIT_MASK_7
#define BM_EVENTS_CMDRDYCONF_TEMP_MEAS     BIT_MASK_6
#define BM_EVENTS_CMDRDYCONF_SRC_CAL       BIT_MASK_5
#define BM_EVENTS_CMDRDYCONF_FRC_CAL       BIT_MASK_4
#define BM_EVENTS_CMDRDYCONF_VCO_CAL       BIT_MASK_3
#define BM_EVENTS_CMDRDYCONF_RF_CAL        BIT_MASK_2
#define BM_EVENTS_CMDRDYCONF_SELF_CHECK    BIT_MASK_1
#define BM_EVENTS_CMDRDYCONF_TX            BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.rssiSysConf                                 */
/* ------------------------------------------------------------------------- */
#define SERVICE_RSSISYSCONF_RSSI_ENABLE             BIT_7

#define SERVICE_RSSISYSCONF_RSSI_BUF_EVENT_MASK      BIT_5

#define SERVICE_RSSISYSCONF_RSSI_BUF_4               BIT_4
#define SERVICE_RSSISYSCONF_RSSI_BUF_3               BIT_3
#define SERVICE_RSSISYSCONF_RSSI_BUF_2               BIT_2
#define SERVICE_RSSISYSCONF_RSSI_BUF_1               BIT_1
#define SERVICE_RSSISYSCONF_RSSI_BUF_0               BIT_0

#define BM_SERVICE_RSSISYSCONF_RSSI_ENABLE          BIT_MASK_7

#define BM_SERVICE_RSSISYSCONF_RSSI_BUF_EVENT_MASK   BIT_MASK_5

#define BM_SERVICE_RSSISYSCONF_RSSI_BUF              ( BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_RSSISYSCONF_RSSI_BUF_4            BIT_MASK_4
#define BM_SERVICE_RSSISYSCONF_RSSI_BUF_3            BIT_MASK_3
#define BM_SERVICE_RSSISYSCONF_RSSI_BUF_2            BIT_MASK_2
#define BM_SERVICE_RSSISYSCONF_RSSI_BUF_1            BIT_MASK_1
#define BM_SERVICE_RSSISYSCONF_RSSI_BUF_0            BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.rxSetPathA[0]                               */
/* sServiceSpecificConfiguration.rxSetPathA[1]                               */
/* ------------------------------------------------------------------------- */
#define SERVICE_RXSETPATHA_RX_BUF_EVENT_MASK      BIT_6

#define SERVICE_RXSETPATHA_RX_BUF_5               BIT_5
#define SERVICE_RXSETPATHA_RX_BUF_4               BIT_4
#define SERVICE_RXSETPATHA_RX_BUF_3               BIT_3
#define SERVICE_RXSETPATHA_RX_BUF_2               BIT_2
#define SERVICE_RXSETPATHA_RX_BUF_1               BIT_1
#define SERVICE_RXSETPATHA_RX_BUF_0               BIT_0

#define BM_SERVICE_RXSETPATHA_RX_BUF_EVENT_MASK   BIT_MASK_6

#define BM_SERVICE_RXSETPATHA_RX_BUF              ( BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_RXSETPATHA_RX_BUF_5            BIT_MASK_5
#define BM_SERVICE_RXSETPATHA_RX_BUF_4            BIT_MASK_4
#define BM_SERVICE_RXSETPATHA_RX_BUF_3            BIT_MASK_3
#define BM_SERVICE_RXSETPATHA_RX_BUF_2            BIT_MASK_2
#define BM_SERVICE_RXSETPATHA_RX_BUF_1            BIT_MASK_1
#define BM_SERVICE_RXSETPATHA_RX_BUF_0            BIT_MASK_0

#define SERVICE_RXSETPATHA_IWUPA                BIT_7
#define SERVICE_RXSETPATHA_DARA                 BIT_6
#define SERVICE_RXSETPATHA_GAPMA                BIT_5
#define SERVICE_RXSETPATHA_RXEHA                BIT_4
#define SERVICE_RXSETPATHA_MODULATION           BIT_0


#define BM_SERVICE_RXSETPATHA_IWUPA             BIT_MASK_7
#define BM_SERVICE_RXSETPATHA_DARA              BIT_MASK_6
#define BM_SERVICE_RXSETPATHA_GAPMA             BIT_MASK_5
#define BM_SERVICE_RXSETPATHA_RXEHA             BIT_MASK_4
#define BM_SERVICE_RXSETPATHA_MODULATION        BIT_MASK_0

#define BM_SERVICE_RXSETPATHA_GTCR              (  BM_SERVICE_RXSETPATHA_IWUPA \
                                                 | BM_SERVICE_RXSETPATHA_DARA  \
                                                 | BM_SERVICE_RXSETPATHA_GAPMA \
                                                 | BM_SERVICE_RXSETPATHA_RXEHA \
                                                )

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.rxSetPathB[0]                               */
/* sServiceSpecificConfiguration.rxSetPathB[1]                               */
/* ------------------------------------------------------------------------- */
#define SERVICE_RXSETPATHB_RX_BUF_EVENT_MASK      BIT_6

#define SERVICE_RXSETPATHB_RX_BUF_5               BIT_5
#define SERVICE_RXSETPATHB_RX_BUF_4               BIT_4
#define SERVICE_RXSETPATHB_RX_BUF_3               BIT_3
#define SERVICE_RXSETPATHB_RX_BUF_2               BIT_2
#define SERVICE_RXSETPATHB_RX_BUF_1               BIT_1
#define SERVICE_RXSETPATHB_RX_BUF_0               BIT_0

#define BM_SERVICE_RXSETPATHB_RX_BUF_EVENT_MASK   BIT_MASK_6

#define BM_SERVICE_RXSETPATHB_RX_BUF              ( BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_RXSETPATHB_RX_BUF_5            BIT_MASK_5
#define BM_SERVICE_RXSETPATHB_RX_BUF_4            BIT_MASK_4
#define BM_SERVICE_RXSETPATHB_RX_BUF_3            BIT_MASK_3
#define BM_SERVICE_RXSETPATHB_RX_BUF_2            BIT_MASK_2
#define BM_SERVICE_RXSETPATHB_RX_BUF_1            BIT_MASK_1
#define BM_SERVICE_RXSETPATHB_RX_BUF_0            BIT_MASK_0

#define SERVICE_RXSETPATHB_IWUPB                BIT_7
#define SERVICE_RXSETPATHB_DARB                 BIT_6
#define SERVICE_RXSETPATHB_GAPMB                BIT_5
#define SERVICE_RXSETPATHB_RXEHB                BIT_4
#define SERVICE_RXSETPATHB_MODULATION           BIT_0

#define BM_SERVICE_RXSETPATHB_IWUPB             BIT_MASK_7
#define BM_SERVICE_RXSETPATHB_DARB              BIT_MASK_6
#define BM_SERVICE_RXSETPATHB_GAPMB             BIT_MASK_5
#define BM_SERVICE_RXSETPATHB_RXEHB             BIT_MASK_4
#define BM_SERVICE_RXSETPATHB_MODULATION        BIT_MASK_0

#define BM_SERVICE_RXSETPATHB_GTCR              (  BM_SERVICE_RXSETPATHB_IWUPB \
                                                 | BM_SERVICE_RXSETPATHB_DARB  \
                                                 | BM_SERVICE_RXSETPATHB_GAPMB \
                                                 | BM_SERVICE_RXSETPATHB_RXEHB \
                                                )
/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.rxSysEvent                                  */
/* ------------------------------------------------------------------------- */
#define SERVICE_RXSYSEVENT_IDCHECKA  BIT_7
#define SERVICE_RXSYSEVENT_WCOA      BIT_6
#define SERVICE_RXSYSEVENT_SOTA      BIT_5
#define SERVICE_RXSYSEVENT_EOTA      BIT_4
#define SERVICE_RXSYSEVENT_IDCHECKB  BIT_3
#define SERVICE_RXSYSEVENT_WCOB      BIT_2
#define SERVICE_RXSYSEVENT_SOTB      BIT_1
#define SERVICE_RXSYSEVENT_EOTB      BIT_0

#define BM_SERVICE_RXSYSEVENT_IDCHECKA  BIT_MASK_7
#define BM_SERVICE_RXSYSEVENT_WCOA      BIT_MASK_6
#define BM_SERVICE_RXSYSEVENT_SOTA      BIT_MASK_5
#define BM_SERVICE_RXSYSEVENT_EOTA      BIT_MASK_4
#define BM_SERVICE_RXSYSEVENT_IDCHECKB  BIT_MASK_3
#define BM_SERVICE_RXSYSEVENT_WCOB      BIT_MASK_2
#define BM_SERVICE_RXSYSEVENT_SOTB      BIT_MASK_1
#define BM_SERVICE_RXSYSEVENT_EOTB      BIT_MASK_0


/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.trxSysConf                                  */
/* ------------------------------------------------------------------------- */
#define SERVICE_TRXSYSCONF_TRPB_ENA                 BIT_3
#define SERVICE_TRXSYSCONF_TRPA_ENA                 BIT_2
#define SERVICE_TRXSYSCONF_ANTENNA_SWITCHING        BIT_1
#define SERVICE_TRXSYSCONF_CHANNEL_SWITCHING        BIT_0

#define BM_SERVICE_TRXSYSCONF_TRPB_ENA              BIT_MASK_3
#define BM_SERVICE_TRXSYSCONF_TRPA_ENA              BIT_MASK_2
#define BM_SERVICE_TRXSYSCONF_ANTENNA_SWITCHING     BIT_MASK_1
#define BM_SERVICE_TRXSYSCONF_CHANNEL_SWITCHING     BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.txSetPathA[0]                               */
/* sServiceSpecificConfiguration.txSetPathA[1]                               */
/* ------------------------------------------------------------------------- */
#define SERVICE_TXSETPATHA_GAUS                 BIT_7
#define SERVICE_TXSETPATHA_PREE                 BIT_6
#define SERVICE_TXSETPATHA_STARTTXFILLLEVEL5    BIT_5
#define SERVICE_TXSETPATHA_STARTTXFILLLEVEL4    BIT_4
#define SERVICE_TXSETPATHA_STARTTXFILLLEVEL3    BIT_3
#define SERVICE_TXSETPATHA_STARTTXFILLLEVEL2    BIT_2
#define SERVICE_TXSETPATHA_STARTTXFILLLEVEL1    BIT_1
#define SERVICE_TXSETPATHA_STARTTXFILLLEVEL0    BIT_0

#define BM_SERVICE_TXSETPATHA_GAUS              BIT_MASK_7
#define BM_SERVICE_TXSETPATHA_PREE              BIT_MASK_6

#define BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL  (  BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL5 BIT_MASK_5
#define BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL4 BIT_MASK_4
#define BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL3 BIT_MASK_3
#define BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL2 BIT_MASK_2
#define BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL1 BIT_MASK_1
#define BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL0 BIT_MASK_0

#define SERVICE_TXSETPATHA_MODULATION           BIT_7
#define SERVICE_TXSETPATHA_ASK_SHAPING          BIT_6
#define SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL4    BIT_4
#define SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL3    BIT_3
#define SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL2    BIT_2
#define SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL1    BIT_1
#define SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL0    BIT_0

#define BM_SERVICE_TXSETPATHA_MODULATION        BIT_MASK_7
#define BM_SERVICE_TXSETPATHA_ASK_SHAPING       BIT_MASK_6
#define BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL  ( BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL4 BIT_MASK_4
#define BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL3 BIT_MASK_3
#define BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL2 BIT_MASK_2
#define BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL1 BIT_MASK_1
#define BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL0 BIT_MASK_0
/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.txSetPathB[0]                               */
/* sServiceSpecificConfiguration.txSetPathB[1]                               */
/* ------------------------------------------------------------------------- */
#define SERVICE_TXSETPATHB_GAUS                 BIT_7
#define SERVICE_TXSETPATHB_PREE                 BIT_6
#define SERVICE_TXSETPATHB_STARTTXFILLLEVEL5    BIT_5
#define SERVICE_TXSETPATHB_STARTTXFILLLEVEL4    BIT_4
#define SERVICE_TXSETPATHB_STARTTXFILLLEVEL3    BIT_3
#define SERVICE_TXSETPATHB_STARTTXFILLLEVEL2    BIT_2
#define SERVICE_TXSETPATHB_STARTTXFILLLEVEL1    BIT_1
#define SERVICE_TXSETPATHB_STARTTXFILLLEVEL0    BIT_0

#define BM_SERVICE_TXSETPATHB_GAUS              BIT_MASK_7
#define BM_SERVICE_TXSETPATHB_PREE              BIT_MASK_6

#define BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL  ( BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL5 BIT_MASK_5
#define BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL4 BIT_MASK_4
#define BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL3 BIT_MASK_3
#define BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL2 BIT_MASK_2
#define BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL1 BIT_MASK_1
#define BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL0 BIT_MASK_0

#define SERVICE_TXSETPATHB_MODULATION               BIT_7
#define SERVICE_TXSETPATHB_ASK_SHAPING              BIT_6
#define SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL4  BIT_4
#define SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL3  BIT_3
#define SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL2  BIT_2
#define SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL1  BIT_1
#define SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL0  BIT_0

#define BM_SERVICE_TXSETPATHB_MODULATION        BIT_MASK_7
#define BM_SERVICE_TXSETPATHB_ASK_SHAPING       BIT_MASK_6
#define BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL  ( BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL4 BIT_MASK_4
#define BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL3 BIT_MASK_3
#define BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL2 BIT_MASK_2
#define BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL1 BIT_MASK_1
#define BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL0 BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* general mask for sServiceSpecificConfiguration.txSetPathA/B               */
/* ------------------------------------------------------------------------- */
#define SERVICE_TXSETPATH_GAUS                  BIT_7
#define SERVICE_TXSETPATH_PREE                  BIT_6
#define BM_SERVICE_TXSETPATH_GAUS               BIT_MASK_7
#define BM_SERVICE_TXSETPATH_PREE               BIT_MASK_6

#define SERVICE_TXSETPATH_ASK_SHAPING       BIT_6
#define BM_SERVICE_TXSETPATH_ASK_SHAPING    BIT_MASK_6

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.txSysEventA                                  */
/* ------------------------------------------------------------------------- */
#define SERVICE_TXSYSEVENTA_TX_ENDING               BIT_7
#define SERVICE_TXSYSEVENTA_TXBUF_EVENT_MASK        BIT_6
#define SERVICE_TXSYSEVENTA_TXBUF5                  BIT_5
#define SERVICE_TXSYSEVENTA_TXBUF4                  BIT_4
#define SERVICE_TXSYSEVENTA_TXBUF3                  BIT_3
#define SERVICE_TXSYSEVENTA_TXBUF2                  BIT_2
#define SERVICE_TXSYSEVENTA_TXBUF1                  BIT_1
#define SERVICE_TXSYSEVENTA_TXBUF0                  BIT_0

#define BM_SERVICE_TXSYSEVENTA_TX_ENDING            BIT_MASK_7
#define BM_SERVICE_TXSYSEVENTA_TXBUF_EVENT_MASK     BIT_MASK_6
#define BM_SERVICE_TXSYSEVENTA_TXBUF                ( BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_TXSYSEVENTA_TXBUF5               BIT_MASK_5
#define BM_SERVICE_TXSYSEVENTA_TXBUF4               BIT_MASK_4
#define BM_SERVICE_TXSYSEVENTA_TXBUF3               BIT_MASK_3
#define BM_SERVICE_TXSYSEVENTA_TXBUF2               BIT_MASK_2
#define BM_SERVICE_TXSYSEVENTA_TXBUF1               BIT_MASK_1
#define BM_SERVICE_TXSYSEVENTA_TXBUF0               BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.txSysEventB                                  */
/* ------------------------------------------------------------------------- */
#define SERVICE_TXSYSEVENTB_TX_ENDING               BIT_7
#define SERVICE_TXSYSEVENTB_TXBUF_EVENT_MASK        BIT_6
#define SERVICE_TXSYSEVENTB_TXBUF5                  BIT_5
#define SERVICE_TXSYSEVENTB_TXBUF4                  BIT_4
#define SERVICE_TXSYSEVENTB_TXBUF3                  BIT_3
#define SERVICE_TXSYSEVENTB_TXBUF2                  BIT_2
#define SERVICE_TXSYSEVENTB_TXBUF1                  BIT_1
#define SERVICE_TXSYSEVENTB_TXBUF0                  BIT_0

#define BM_SERVICE_TXSYSEVENTB_TX_ENDING            BIT_MASK_7
#define BM_SERVICE_TXSYSEVENTB_TXBUF_EVENT_MASK     BIT_MASK_6
#define BM_SERVICE_TXSYSEVENTB_TXBUF                ( BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_TXSYSEVENTB_TXBUF5               BIT_MASK_5
#define BM_SERVICE_TXSYSEVENTB_TXBUF4               BIT_MASK_4
#define BM_SERVICE_TXSYSEVENTB_TXBUF3               BIT_MASK_3
#define BM_SERVICE_TXSYSEVENTB_TXBUF2               BIT_MASK_2
#define BM_SERVICE_TXSYSEVENTB_TXBUF1               BIT_MASK_1
#define BM_SERVICE_TXSYSEVENTB_TXBUF0               BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* general mask for sServiceSpecificConfiguration.txSysEventA/B              */
/* ------------------------------------------------------------------------- */
#define SERVICE_TXSYSEVENT_TX_ENDING                BIT_7
#define SERVICE_TXSYSEVENT_TXBUF_EVENT_MASK         BIT_6
#define BM_SERVICE_TXSYSEVENT_TX_ENDING             BIT_MASK_7
#define BM_SERVICE_TXSYSEVENT_TXBUF_EVENT_MASK      BIT_MASK_6

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.txPreambleSysEvent                          */
/* ------------------------------------------------------------------------- */
#define SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF_EVENT_MASK     BIT_5
#define SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF4               BIT_4
#define SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF3               BIT_3
#define SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF2               BIT_2
#define SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF1               BIT_1
#define SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF0               BIT_0

#define BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF_EVENT_MASK  BIT_MASK_5
#define BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF             ( BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
#define BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF4            BIT_MASK_4
#define BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF3            BIT_MASK_3
#define BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF2            BIT_MASK_2
#define BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF1            BIT_MASK_1
#define BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF0            BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.rxSysSet                                    */
/* ------------------------------------------------------------------------- */
#define SERVICE_RXSYSSET_SUBCHANNELING              BIT_7
#define SERVICE_RXSYSSET_IDSCAN_ENABLE              BIT_6
#define SERVICE_RXSYSSET_IFAMPLIFIER_ENABLE         BIT_5
#define SERVICE_RXSYSSET_PATH_VALID_AFTER_SOT       BIT_4
#define SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHB      BIT_3
#define SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHA      BIT_2
#define SERVICE_RXSYSSET_SWITCHING_SDTX             BIT_1
#define SERVICE_RXSYSSET_SWITCHING_SDRX             BIT_0

#define BM_SERVICE_RXSYSSET_SUBCHANNELING           BIT_MASK_7
#define BM_SERVICE_RXSYSSET_IDSCAN_ENABLE           BIT_MASK_6
#define BM_SERVICE_RXSYSSET_IFAMPLIFIER_ENABLE      BIT_MASK_5
#define BM_SERVICE_RXSYSSET_PATH_VALID_AFTER_SOT    BIT_MASK_4
#define BM_SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHB   BIT_MASK_3
#define BM_SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHA   BIT_MASK_2
#define BM_SERVICE_RXSYSSET_SWITCHING_SDTX          BIT_MASK_1
#define BM_SERVICE_RXSYSSET_SWITCHING_SDRX          BIT_MASK_0
#define BM_SERVICE_RXSYSSET_SWITCHING               ( BM_SERVICE_RXSYSSET_SWITCHING_SDTX | BM_SERVICE_RXSYSSET_SWITCHING_SDRX )


/* ------------------------------------------------------------------------- */
/* sysStatus                                                                 */
/* ------------------------------------------------------------------------- */
#define SYS_STATUS_UPDATE                   BIT_7
#define SYS_STATUS_RDY_4_DIRECTSWITCHING    BIT_6
#define SYS_STATUS_SPI_CMD_IN_PROGRESS      BIT_5
#define SYS_STATUS_TRIGGER_MAIN_LOOP        BIT_4
#define SYS_STATUS_SSM_SLEEP_ENABLE         BIT_3
#define SYS_STATUS_CALIB                    BIT_2
#define SYS_STATUS_AVCCLOW                  BIT_1
#define SYS_STATUS_SSMRDY                   BIT_0

#define BM_SYS_STATUS_UPDATE                    BIT_MASK_7
#define BM_SYS_STATUS_RDY_4_DIRECTSWITCHING     BIT_MASK_6
#define BM_SYS_STATUS_SPI_CMD_IN_PROGRESS       BIT_MASK_5
#define BM_SYS_STATUS_TRIGGER_MAIN_LOOP         BIT_MASK_4
#define BM_SYS_STATUS_SSM_SLEEP_ENABLE          BIT_MASK_3
#define BM_SYS_STATUS_CALIB                     BIT_MASK_2
#define BM_SYS_STATUS_AVCCLOW                   BIT_MASK_1
#define BM_SYS_STATUS_SSMRDY                    BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* trxStatus for TX                                                          */
/* ------------------------------------------------------------------------- */
#define TRX_STATUS_TX_TRANSMISSION_COMPLETE     BIT_1
#define TRX_STATUS_TX_ASK_FSK_MODULATION        BIT_0

#define BM_TRX_STATUS_TX_TRANSMISSION_COMPLETE  BIT_MASK_1
#define BM_TRX_STATUS_TX_ASK_FSK_MODULATION     BIT_MASK_0

#define TRX_STATUS_TX_FSK_MODULATION    0U
#define TRX_STATUS_TX_ASK_MODULATION    1U


/* ------------------------------------------------------------------------- */
/* trxStatus for RX                                                          */
/* ------------------------------------------------------------------------- */
#define TRX_STATUS_RX_WCOB                          BIT_7
#define TRX_STATUS_RX_WCOA                          BIT_6
#define TRX_STATUS_RX_SOTB                          BIT_5
#define TRX_STATUS_RX_SOTA                          BIT_4
#define TRX_STATUS_RX_EOTB                          BIT_3
#define TRX_STATUS_RX_EOTA                          BIT_2
#define TRX_STATUS_RX_ASK_FSK_MODULATION_PATHB      BIT_1
#define TRX_STATUS_RX_ASK_FSK_MODULATION_PATHA      BIT_0

#define BM_TRX_STATUS_RX_WCOA_WCOB                  ( BIT_MASK_7 | BIT_MASK_6 )
#define BM_TRX_STATUS_RX_WCOB                       BIT_MASK_7
#define BM_TRX_STATUS_RX_WCOA                       BIT_MASK_6
#define BM_TRX_STATUS_RX_SOTA_SOTB                  ( BIT_MASK_5 | BIT_MASK_4 )
#define BM_TRX_STATUS_RX_SOTB                       BIT_MASK_5
#define BM_TRX_STATUS_RX_SOTA                       BIT_MASK_4
#define BM_TRX_STATUS_RX_EOTA_EOTB                  ( BIT_MASK_3 | BIT_MASK_2 )
#define BM_TRX_STATUS_RX_EOTB                       BIT_MASK_3
#define BM_TRX_STATUS_RX_EOTA                       BIT_MASK_2
#define BM_TRX_STATUS_RX_ASK_FSK_MODULATION_PATHB   BIT_MASK_1
#define BM_TRX_STATUS_RX_ASK_FSK_MODULATION_PATHA   BIT_MASK_0

#define TRX_STATUS_RX_FSK_MODULATION                TRX_STATUS_TX_FSK_MODULATION
#define TRX_STATUS_RX_ASK_MODULATION                TRX_STATUS_TX_ASK_MODULATION

/* ------------------------------------------------------------------------- */
/* sleepModeConfig                                                            */
/* ------------------------------------------------------------------------- */
#define SLEEP_MODE_CONFIG_ENABLE        BIT_7
#define SLEEP_MODE_CONFIG_MODE_2        SM2
#define SLEEP_MODE_CONFIG_MODE_1        SM1
#define SLEEP_MODE_CONFIG_MODE_0        SM0

#define BM_SLEEP_MODE_CONFIG_ENABLE     BIT_MASK_7
#define BM_SLEEP_MODE_CONFIG            ( BM_SLEEP_MODE_CONFIG_MODE_2 | BM_SLEEP_MODE_CONFIG_MODE_1 | BM_SLEEP_MODE_CONFIG_MODE_0 )
#define BM_SLEEP_MODE_CONFIG_MODE_2     BM_SM2
#define BM_SLEEP_MODE_CONFIG_MODE_1     BM_SM1
#define BM_SLEEP_MODE_CONFIG_MODE_0     BM_SM0

/* ------------------------------------------------------------------------- */
/* sSubChanneling                                                            */
/* ------------------------------------------------------------------------- */
#define SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED      BIT_1
#define SUBCHANNELING_ACTIVE                            BIT_0

#define BM_SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED   BIT_MASK_1
#define BM_SUBCHANNELING_ACTIVE                         BIT_MASK_0

#elif defined __IAR_SYSTEMS_ASM__
/*startSimExtraction*/
/* ------------------------------------------------------------------------- */
/* bits and masks                                                            */
/* ------------------------------------------------------------------------- */
BIT_7  EQU 7
BIT_6  EQU 6
BIT_5  EQU 5
BIT_4  EQU 4
BIT_3  EQU 3
BIT_2  EQU 2
BIT_1  EQU 1
BIT_0  EQU 0

BIT_MASK_7 EQU ( 0x01 << BIT_7 )
BIT_MASK_6 EQU ( 0x01 << BIT_6 )
BIT_MASK_5 EQU ( 0x01 << BIT_5 )
BIT_MASK_4 EQU ( 0x01 << BIT_4 )
BIT_MASK_3 EQU ( 0x01 << BIT_3 )
BIT_MASK_2 EQU ( 0x01 << BIT_2 )
BIT_MASK_1 EQU ( 0x01 << BIT_1 )
BIT_MASK_0 EQU ( 0x01 << BIT_0 )
/* bits and masks */

NUM_EEPROM_SERVICES         EQU 3
NUM_SRAM_SERVICES           EQU 2
NUM_SERVICES                EQU ( NUM_EEPROM_SERVICES + NUM_SRAM_SERVICES )
NUM_CHANNELS_PER_SERVICE    EQU 3

RSSIBUFMASK  EQU 0x1F
RSSIBUFSIZE  EQU 32
RFBUFSIZE    EQU 32
RFBUFMASK    EQU 0x1F
RDPTR        EQU 0x00
WRPTR        EQU 0x01
FILLLEVEL    EQU 0x02
THD          EQU 0x03

SETAND       EQU 0x0A
SETOR        EQU 0x0B
CLRAND       EQU 0x0C
CLROR        EQU 0x0D

SSISTATE     EQU 0x00
TMR1STATE    EQU 0x00
TMR2STATE    EQU 0x00
TMR3STATE    EQU 0x00
TMR4STATE    EQU 0x00
TMR5STATE    EQU 0x00

/* ------------------------------------------------------------------------- */
/* svcChConfig_t                                                             */
/* ------------------------------------------------------------------------- */
SVC_CH_CONFIG_ENA_PATHB      EQU BIT_7
SVC_CH_CONFIG_ENA_PATHA      EQU BIT_6
SVC_CH_CONFIG_CH_1           EQU BIT_5
SVC_CH_CONFIG_CH_0           EQU BIT_4
SVC_CH_CONFIG_SER_2          EQU BIT_2
SVC_CH_CONFIG_SER_1          EQU BIT_1
SVC_CH_CONFIG_SER_0          EQU BIT_0

BM_SVC_CH_CONFIG_ENA_PATHB    EQU BIT_MASK_7
BM_SVC_CH_CONFIG_ENA_PATHA    EQU BIT_MASK_6
BM_SVC_CH_CONFIG_CH           EQU BIT_MASK_5 | BIT_MASK_4
BM_SVC_CH_CONFIG_SER          EQU BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sysModeConfig_t                                                           */
/* ------------------------------------------------------------------------- */
SYS_MODE_CONFIG_RF_CALIBRATION          EQU BIT_7
SYS_MODE_CONFIG_ANTENNA_TUNING          EQU BIT_6
SYS_MODE_CONFIG_VCO_TUNING              EQU BIT_5
SYS_MODE_CONFIG_IDLE_MODE_SELECTOR      EQU BIT_4
SYS_MODE_CONFIG_DIRECT_SWITCH           EQU BIT_3
SYS_MODE_CONFIG_TRANSPARENT_MODE        EQU BIT_2
SYS_MODE_CONFIG_OPM1                    EQU BIT_1
SYS_MODE_CONFIG_OPM0                    EQU BIT_0

BM_SYS_MODE_CONFIG_RF_CALIBRATION       EQU BIT_MASK_7
BM_SYS_MODE_CONFIG_ANTENNA_TUNING       EQU BIT_MASK_6
BM_SYS_MODE_CONFIG_VCO_TUNING           EQU BIT_MASK_5
BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR   EQU BIT_MASK_4
BM_SYS_MODE_CONFIG_DIRECT_SWITCH        EQU BIT_MASK_3
BM_SYS_MODE_CONFIG_TRANSPARENT_MODE     EQU BIT_MASK_2

BM_SYS_MODE_CONFIG_OPM                  EQU ( BIT_MASK_1 | BIT_MASK_0 )
BM_SYS_MODE_CONFIG_OPM1                 EQU BIT_MASK_1
BM_SYS_MODE_CONFIG_OPM0                 EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* pinEventConfig_t                                                          */
/* ------------------------------------------------------------------------- */
PIN_EVENT_CONFIG_POWERON    EQU BIT_7
PIN_EVENT_CONFIG_DEBUG      EQU BIT_6
PIN_EVENT_CONFIG_NPWR6      EQU BIT_5
PIN_EVENT_CONFIG_NPWR5      EQU BIT_4
PIN_EVENT_CONFIG_NPWR4      EQU BIT_3
PIN_EVENT_CONFIG_NPWR3      EQU BIT_2
PIN_EVENT_CONFIG_NPWR2      EQU BIT_1
PIN_EVENT_CONFIG_NPWR1      EQU BIT_0

BM_PIN_EVENT_CONFIG_POWERON    EQU  BIT_MASK_7
BM_PIN_EVENT_CONFIG_DEBUG      EQU  BIT_MASK_6
BM_PIN_EVENT_CONFIG_NPWR6      EQU  BIT_MASK_5
BM_PIN_EVENT_CONFIG_NPWR5      EQU  BIT_MASK_4
BM_PIN_EVENT_CONFIG_NPWR4      EQU  BIT_MASK_3
BM_PIN_EVENT_CONFIG_NPWR3      EQU  BIT_MASK_2
BM_PIN_EVENT_CONFIG_NPWR2      EQU  BIT_MASK_1
BM_PIN_EVENT_CONFIG_NPWR1      EQU  BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sysEventConfig_t                                                          */
/* ------------------------------------------------------------------------- */
SYS_EVENT_CONFIG_SYS_ERR        EQU BIT_7
SYS_EVENT_CONFIG_CMD_RDY        EQU BIT_6
SYS_EVENT_CONFIG_SYS_RDY        EQU BIT_5
SYS_EVENT_CONFIG_AVCCLOW        EQU BIT_4
SYS_EVENT_CONFIG_LOWBATT        EQU BIT_3
SYS_EVENT_CONFIG_RX_ACTIVE_EN   EQU BIT_2
SYS_EVENT_CONFIG_RX_ACTIVE_POL  EQU BIT_1
SYS_EVENT_CONFIG_EVENTPIN_POL   EQU BIT_0

BM_SYS_EVENT_CONFIG_SYS_ERR         EQU  BIT_MASK_7
BM_SYS_EVENT_CONFIG_CMD_RDY         EQU  BIT_MASK_6
BM_SYS_EVENT_CONFIG_SYS_RDY         EQU  BIT_MASK_5
BM_SYS_EVENT_CONFIG_AVCCLOW         EQU  BIT_MASK_4
BM_SYS_EVENT_CONFIG_LOWBATT         EQU  BIT_MASK_3
BM_SYS_EVENT_CONFIG_RX_ACTIVE_EN    EQU  BIT_MASK_2
BM_SYS_EVENT_CONFIG_RX_ACTIVE_POL   EQU  BIT_MASK_1
BM_SYS_EVENT_CONFIG_EVENTPIN_POL    EQU  BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sEventData                                                                */
/* ------------------------------------------------------------------------- */
EVENT_PIN_EVENT_MASK    EQU 0
EVENT_SYS_EVENT_MASK    EQU EVENT_PIN_EVENT_MASK + 1
EVENT_CMDRDY            EQU EVENT_SYS_EVENT_MASK + 1
EVENT_EVENTCOPY_SYSTEM  EQU EVENT_CMDRDY + 1
EVENT_EVENTCOPY_EVENTS  EQU EVENT_EVENTCOPY_SYSTEM + 1
EVENT_EVENTCOPY_POWER   EQU EVENT_EVENTCOPY_EVENTS + 1
EVENT_EVENTCOPY_CONFIG  EQU EVENT_EVENTCOPY_POWER + 1
EVENT_EVENTCTRL         EQU EVENT_EVENTCOPY_CONFIG + 1
/* ------------------------------------------------------------------------- */
/* event_power                                                               */
/* ------------------------------------------------------------------------- */
EVENTS_POWER_PWRON                  EQU BIT_7
EVENTS_POWER_DEBUG                  EQU BIT_6
EVENTS_POWER_NPWRON6                EQU BIT_5
EVENTS_POWER_NPWRON5                EQU BIT_4
EVENTS_POWER_NPWRON4                EQU BIT_3
EVENTS_POWER_NPWRON3                EQU BIT_2
EVENTS_POWER_NPWRON2                EQU BIT_1
EVENTS_POWER_NPWRON1                EQU BIT_0

BM_EVENTS_POWER_PWRON               EQU BIT_MASK_7
BM_EVENTS_POWER_DEBUG               EQU BIT_MASK_6
BM_EVENTS_POWER_NPWRON6             EQU BIT_MASK_5
BM_EVENTS_POWER_NPWRON5             EQU BIT_MASK_4
BM_EVENTS_POWER_NPWRON4             EQU BIT_MASK_3
BM_EVENTS_POWER_NPWRON3             EQU BIT_MASK_2
BM_EVENTS_POWER_NPWRON2             EQU BIT_MASK_1
BM_EVENTS_POWER_NPWRON1             EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* event_system                                                              */
/* ------------------------------------------------------------------------- */
EVENTS_SYSTEM_SYS_ERR               EQU BIT_7
EVENTS_SYSTEM_CMD_RDY               EQU BIT_6
EVENTS_SYSTEM_SYS_RDY               EQU BIT_5
EVENTS_SYSTEM_AVCCLOW               EQU BIT_4
EVENTS_SYSTEM_LOWBATT               EQU BIT_3
EVENTS_SYSTEM_RSSI_BUF              EQU BIT_2
EVENTS_SYSTEM_RX_BUF                EQU BIT_1
EVENTS_SYSTEM_TX_BUF                EQU BIT_0

BM_EVENTS_SYSTEM_SYS_ERR            EQU BIT_MASK_7
BM_EVENTS_SYSTEM_CMD_RDY            EQU BIT_MASK_6
BM_EVENTS_SYSTEM_SYS_RDY            EQU BIT_MASK_5
BM_EVENTS_SYSTEM_AVCCLOW            EQU BIT_MASK_4
BM_EVENTS_SYSTEM_LOWBATT            EQU BIT_MASK_3
BM_EVENTS_SYSTEM_RSSI_BUF           EQU BIT_MASK_2
BM_EVENTS_SYSTEM_RX_BUF             EQU BIT_MASK_1
BM_EVENTS_SYSTEM_TX_BUF             EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* events_events                                                             */
/* ------------------------------------------------------------------------- */
EVENTS_EVENTS_ID_CHECKA             EQU BIT_7
EVENTS_EVENTS_WCOA                  EQU BIT_6
EVENTS_EVENTS_SOTA                  EQU BIT_5
EVENTS_EVENTS_EOTA                  EQU BIT_4
EVENTS_EVENTS_ID_CHECKB             EQU BIT_3
EVENTS_EVENTS_WCOB                  EQU BIT_2
EVENTS_EVENTS_SOTB                  EQU BIT_1
EVENTS_EVENTS_EOTB                  EQU BIT_0

BM_EVENTS_EVENTS_ID_CHECKA          EQU BIT_MASK_7
BM_EVENTS_EVENTS_WCOA               EQU BIT_MASK_6
BM_EVENTS_EVENTS_SOTA               EQU BIT_MASK_5
BM_EVENTS_EVENTS_EOTA               EQU BIT_MASK_4
BM_EVENTS_EVENTS_ID_CHECKB          EQU BIT_MASK_3
BM_EVENTS_EVENTS_WCOB               EQU BIT_MASK_2
BM_EVENTS_EVENTS_SOTB               EQU BIT_MASK_1
BM_EVENTS_EVENTS_EOTB               EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* events_cmdRdyConf                                                         */
/* ------------------------------------------------------------------------- */
EVENTS_CMDRDYCONF_ANT_TUNE          EQU     BIT_7
EVENTS_CMDRDYCONF_TEMP_MEAS         EQU     BIT_6
EVENTS_CMDRDYCONF_SRC_CAL           EQU     BIT_5
EVENTS_CMDRDYCONF_FRC_CAL           EQU     BIT_4
EVENTS_CMDRDYCONF_VCO_CAL           EQU     BIT_3
EVENTS_CMDRDYCONF_RF_CAL            EQU     BIT_2
EVENTS_CMDRDYCONF_SELF_CHECK        EQU     BIT_1
EVENTS_CMDRDYCONF_TX                EQU     BIT_0

BM_EVENTS_CMDRDYCONF_ANT_TUNE       EQU     BIT_MASK_7
BM_EVENTS_CMDRDYCONF_TEMP_MEAS      EQU     BIT_MASK_6
BM_EVENTS_CMDRDYCONF_SRC_CAL        EQU     BIT_MASK_5
BM_EVENTS_CMDRDYCONF_FRC_CAL        EQU     BIT_MASK_4
BM_EVENTS_CMDRDYCONF_VCO_CAL        EQU     BIT_MASK_3
BM_EVENTS_CMDRDYCONF_RF_CAL         EQU     BIT_MASK_2
BM_EVENTS_CMDRDYCONF_SELF_CHECK     EQU     BIT_MASK_1
BM_EVENTS_CMDRDYCONF_TX             EQU     BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* events_eventCtrl                                                          */
/* ------------------------------------------------------------------------- */
EVENTS_EVENTCTRL_IRQ_PENDING        EQU     BIT_0

BM_EVENTS_EVENTCTRL_IRQ_PENDING     EQU     BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* Debug Error Codes                                                         */
/* ------------------------------------------------------------------------- */
DEBUG_ERROR_CODE_SYSTEM_ERROR_EEPROM_NOT_VALID                 EQU  0
DEBUG_ERROR_CODE_SETIDLEMODE_MISS_SSMRDY                       EQU  DEBUG_ERROR_CODE_SYSTEM_ERROR_EEPROM_NOT_VALID + 1                  // 001<->01
DEBUG_ERROR_CODE_SETIDLEMODE_TIMER_LOCKED                      EQU  DEBUG_ERROR_CODE_SETIDLEMODE_MISS_SSMRDY + 1                        // 002<->02
DEBUG_ERROR_CODE_RX_STATESTARTSSM_TIMER_LOCKED                 EQU  DEBUG_ERROR_CODE_SETIDLEMODE_TIMER_LOCKED + 1                       // 003<->03
DEBUG_ERROR_CODE_RX_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT     EQU  DEBUG_ERROR_CODE_RX_STATESTARTSSM_TIMER_LOCKED + 1                  // 004<->04
DEBUG_ERROR_CODE_TX_STATESTARTSSM_TIMER_LOCKED                 EQU  DEBUG_ERROR_CODE_RX_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT + 1      // 005<->05
DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT                   EQU  DEBUG_ERROR_CODE_TX_STATESTARTSSM_TIMER_LOCKED + 1                  // 006<->06
DEBUG_ERROR_CODE_POLL_STATESTARTSSM_TIMER_LOCKED               EQU  DEBUG_ERROR_CODE_TX_STATEWAIT4SSMRDY_TIMEOUT + 1                    // 007<->07
DEBUG_ERROR_CODE_POLL_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT   EQU  DEBUG_ERROR_CODE_POLL_STATESTARTSSM_TIMER_LOCKED + 1                // 008<->08
DEBUG_ERROR_CODE_ANTTUNE_STATESTARTSSM_TIMER_LOCKED            EQU  DEBUG_ERROR_CODE_POLL_STATEWAIT4SSMSTATE_GETTELEGRAM_TIMEOUT + 1    // 009<->09
DEBUG_ERROR_CODE_ANTTUNE_STATEWAIT4SSMRDY_TIMEOUT              EQU  DEBUG_ERROR_CODE_ANTTUNE_STATESTARTSSM_TIMER_LOCKED + 1             // 010<->0A
DEBUG_ERROR_CODE_VCOCAL_STATESTARTSSM_TIMER_LOCKED             EQU  DEBUG_ERROR_CODE_ANTTUNE_STATEWAIT4SSMRDY_TIMEOUT + 1               // 011<->0B
DEBUG_ERROR_CODE_VCOCAL_STATEWAIT4SSMRDY_TIMEOUT               EQU  DEBUG_ERROR_CODE_VCOCAL_STATESTARTSSM_TIMER_LOCKED + 1              // 012<->0C
DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMER_LOCKED                      EQU  DEBUG_ERROR_CODE_VCOCAL_STATEWAIT4SSMRDY_TIMEOUT + 1                // 013<->0D
DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT                           EQU  DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMER_LOCKED + 1                       // 014<->0E
DEBUG_ERROR_CODE_POLLING_TIMER1_LOCKED                         EQU  DEBUG_ERROR_CODE_SHUTDOWNTRX_TIMEOUT + 1                            // 015<->0F
DEBUG_ERROR_CODE_INVALID_OPM_SWITCHING                         EQU  DEBUG_ERROR_CODE_POLLING_TIMER1_LOCKED + 1                          // 016<->10
DEBUG_ERROR_CODE_INVALID_OPM_MODE_DURING_TUNE_AND_CHECK        EQU  DEBUG_ERROR_CODE_INVALID_OPM_SWITCHING + 1                          // 017<->11
DEBUG_ERROR_CODE_AVCCLOW_DURING_TX                             EQU  DEBUG_ERROR_CODE_INVALID_OPM_MODE_DURING_TUNE_AND_CHECK + 1         // 018<->12
DEBUG_ERROR_CODE_SERVICE_INIT_FAILURE                          EQU  DEBUG_ERROR_CODE_AVCCLOW_DURING_TX + 1                              // 019<->13
DEBUG_ERROR_CODE_DFIFO_OVER_UNDER_FLOW                         EQU  DEBUG_ERROR_CODE_SERVICE_INIT_FAILURE + 1                           // 020<->14
DEBUG_ERROR_CODE_SFIFO_OVER_UNDER_FLOW                         EQU  DEBUG_ERROR_CODE_DFIFO_OVER_UNDER_FLOW + 1                          // 021<->15
DEBUG_ERROR_CODE_RSSI_STATESTARTSSM_TIMER_LOCKED               EQU  DEBUG_ERROR_CODE_SFIFO_OVER_UNDER_FLOW + 1                          // 022<->16
DEBUG_ERROR_CODE_SRC_FRC_CALIB_FAILED                          EQU  DEBUG_ERROR_CODE_RSSI_STATESTARTSSM_TIMER_LOCKED + 1                // 023<->17
DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR                       EQU  DEBUG_ERROR_CODE_SRC_FRC_CALIB_FAILED + 1                           // 024<->18
DEBUG_ERROR_CODE_TEMPMEAS_STATESTARTSSM_TIMER_LOCKED           EQU  DEBUG_ERROR_CODE_GETRXTELEGRAM_SSM_ERROR + 1                        // 025<->19
DEBUG_ERROR_CODE_TEMPMEAS_STATEWAIT4SSMRDY_TIMEOUT             EQU  DEBUG_ERROR_CODE_TEMPMEAS_STATESTARTSSM_TIMER_LOCKED + 1            // 026<->1A
DEBUG_ERROR_CODE_AVCCLOW_TIMEOUT                               EQU  DEBUG_ERROR_CODE_TEMPMEAS_STATEWAIT4SSMRDY_TIMEOUT + 1              // 027<->1B
DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMER_LOCKED EQU  DEBUG_ERROR_CODE_AVCCLOW_TIMEOUT + 1U                               // 028<->1C
DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMER_LOCKED  EQU  DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMER_LOCKED + 1U // 029<->1D
DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMER_LOCKED  EQU  DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMER_LOCKED + 1U  // 030<->1E
DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMEOUT      EQU  DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMER_LOCKED + 1U  // 031<->1F
DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMEOUT       EQU  DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_CENTERFREQ_TIMEOUT + 1U      // 032<->20
DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_UPPERFREQ_TIMEOUT       EQU  DEBUG_ERROR_CODE_SUBCHAN_STATESTARTSSM_LOWERFREQ_TIMEOUT + 1U       // 033<->21

/* ------------------------------------------------------------------------- */
/* sTrxConfig                                                                */
/* ------------------------------------------------------------------------- */
TRXCONF_TUNE_CHECK_CONFIG               EQU 0
TRXCONF_SYSTEM_MODE_CONFIG              EQU TRXCONF_TUNE_CHECK_CONFIG + 1
TRXCONF_SERVICE_CHANNEL_CONFIG          EQU TRXCONF_SYSTEM_MODE_CONFIG + 1
TRXCONF_SYSTEM_CONFIG                   EQU TRXCONF_SERVICE_CHANNEL_CONFIG + 1
TRXCONF_SERVICE_INIT_CONFIG             EQU TRXCONF_SYSTEM_CONFIG + 1
TRXCONF_MISC_TRIGGER                    EQU TRXCONF_SERVICE_INIT_CONFIG + 1
TRXCONF_LAST_SYSTEM_MODE_CONFIG         EQU TRXCONF_MISC_TRIGGER + 1
TRXCONF_LAST_SERVICE_CHANNEL_CONFIG     EQU TRXCONF_LAST_SYSTEM_MODE_CONFIG + 1
TRXCONF_IDSCAN_STATUS                   EQU TRXCONF_LAST_SERVICE_CHANNEL_CONFIG + 1
TRXCONF_IDSCAN_CTRL                     EQU TRXCONF_IDSCAN_STATUS + 1

/* ------------------------------------------------------------------------- */
/* TRXCONF_TUNE_CHECK_CONFIG                                                 */
/* ------------------------------------------------------------------------- */
TRXCONF_TUNE_CHECK_CONFIG_ANT_TUNE      EQU BIT_7
TRXCONF_TUNE_CHECK_CONFIG_TEMP_MEAS     EQU BIT_6
TRXCONF_TUNE_CHECK_CONFIG_SRC_CAL       EQU BIT_5
TRXCONF_TUNE_CHECK_CONFIG_FRC_CAL       EQU BIT_4
TRXCONF_TUNE_CHECK_CONFIG_VCO_CAL       EQU BIT_3

BM_TRXCONF_TUNE_CHECK_CONFIG_ANT_TUNE   EQU BIT_MASK_7
BM_TRXCONF_TUNE_CHECK_CONFIG_TEMP_MEAS  EQU BIT_MASK_6
BM_TRXCONF_TUNE_CHECK_CONFIG_SRC_CAL    EQU BIT_MASK_5
BM_TRXCONF_TUNE_CHECK_CONFIG_FRC_CAL    EQU BIT_MASK_4
BM_TRXCONF_TUNE_CHECK_CONFIG_VCO_CAL    EQU BIT_MASK_3


/* ------------------------------------------------------------------------- */
/* TRXCONF_SYSTEM_MODE_CONFIG                                                */
/* ------------------------------------------------------------------------- */
TRXCONF_SYSTEM_MODE_CONFIG_SWITCHING            EQU BIT_3
TRXCONF_SYSTEM_MODE_CONFIG_TRANSPARENT          EQU BIT_2

BM_TRXCONF_SYSTEM_MODE_CONFIG_OPM_MASK          EQU ( BIT_MASK_1 | BIT_MASK_0 )
BM_TRXCONF_SYSTEM_MODE_CONFIG_ENAVCOTUNE        EQU BIT_MASK_5
BM_TRXCONF_SYSTEM_MODE_CONFIG_TRANSPARENT       EQU BIT_MASK_2
BM_TRXCONF_SYSTEM_MODE_CONFIG_CLKIDLESELECTOR   EQU BIT_MASK_4
/* ------------------------------------------------------------------------- */
/* Operation modes                                                           */
/* ------------------------------------------------------------------------- */
OPM_IDLE        EQU 0x00
OPM_TX          EQU 0x01
OPM_RX          EQU 0x02
OPM_POLLING     EQU 0x03

/* ------------------------------------------------------------------------- */
/* Error handling                                                           */
/* ------------------------------------------------------------------------- */
RXERR_IGNORE          EQU 0x00    /* ignore occured bitcheck errors */
RXERR_STOP_RECEIVE    EQU 0x01    /* stop data receiving */
RXERR_BYTE_RECEIVE    EQU 0x02    /* receive byte completely, then stop data receiving */
RXERR_CONTINUOUS      EQU 0x03    /* restart demodulator and go ahead data receiving */

/* ------------------------------------------------------------------------- */
/* TRXCONF_SERVICE_CHANNEL_CONFIG                                            */
/* ------------------------------------------------------------------------- */
TRXCONF_SERVICE_CHANNEL_CONFIG_ENA_PATHB        EQU SVC_CH_CONFIG_ENA_PATHB
TRXCONF_SERVICE_CHANNEL_CONFIG_ENA_PATHA        EQU SVC_CH_CONFIG_ENA_PATHA
TRXCONF_SERVICE_CHANNEL_CONFIG_CH               EQU SVC_CH_CONFIG_CH_0
TRXCONF_SERVICE_CHANNEL_CONFIG_SER              EQU SVC_CH_CONFIG_SER_0

BM_TRXCONF_SERVICE_CHANNEL_CONFIG_ENA_PATHB     EQU BM_SVC_CH_CONFIG_ENA_PATHB
BM_TRXCONF_SERVICE_CHANNEL_CONFIG_ENA_PATHA     EQU BM_SVC_CH_CONFIG_ENA_PATHA
BM_TRXCONF_SERVICE_CHANNEL_CONFIG_CH            EQU BM_SVC_CH_CONFIG_CH
BM_TRXCONF_SERVICE_CHANNEL_CONFIG_SER           EQU BM_SVC_CH_CONFIG_SER

/* ------------------------------------------------------------------------- */
/* TRXCONF_SYSTEM_CONFIG                                                     */
/* ------------------------------------------------------------------------- */
TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA                   EQU BIT_7
TRXCONF_SYSTEM_CONFIG_SRCAO                         EQU BIT_5
TRXCONF_SYSTEM_CONFIG_FRCAO                         EQU BIT_4
TRXCONF_SYSTEM_CONFIG_SFIFO_OFL_UFL_RX_DISABLE      EQU BIT_3
TRXCONF_SYSTEM_CONFIG_DFIFO_OFL_UFL_RX_DISABLE      EQU BIT_2
TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR            EQU BIT_1
TRXCONF_SYSTEM_CONFIG_VS5V_SELECTOR                 EQU BIT_0

BM_TRXCONF_SYSTEM_CONFIG_PURE_RX_ENA                EQU BIT_MASK_7
BM_TRXCONF_SYSTEM_CONFIG_SRCAO                      EQU BIT_MASK_5
BM_TRXCONF_SYSTEM_CONFIG_FRCAO                      EQU BIT_MASK_4
BM_TRXCONF_SYSTEM_CONFIG_SFIFO_OFL_UFL_RX_DISABLE   EQU BIT_MASK_3
BM_TRXCONF_SYSTEM_CONFIG_DFIFO_OFL_UFL_RX_DISABLE   EQU BIT_MASK_2
BM_TRXCONF_SYSTEM_CONFIG_IDLE_MODE_SELECTOR         EQU BIT_MASK_1
BM_TRXCONF_SYSTEM_CONFIG_VS5V_SELECTOR              EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* TRXCONF_SYSTEM_IDSCANCTRL                                                 */
/* ------------------------------------------------------------------------- */
SYS_ID_SCAN_CTRL_IDSCAN_ACTIVE      EQU BIT_7
SYS_ID_SCAN_CTRL_EOTB               EQU BIT_6
SYS_ID_SCAN_CTRL_EOTA               EQU BIT_5

BM_SYS_ID_SCAN_CTRL_IDSCAN_ACTIVE   EQU BIT_MASK_7
BM_SYS_ID_SCAN_CTRL_EOTB            EQU BIT_MASK_6
BM_SYS_ID_SCAN_CTRL_EOTA            EQU BIT_MASK_5

/* ------------------------------------------------------------------------- */
/* sleepModeConfig                                                            */
/* ------------------------------------------------------------------------- */
SLEEP_MODE_CONFIG_ENABLE        EQU BIT_7
SLEEP_MODE_CONFIG_MODE_2        EQU SM2
SLEEP_MODE_CONFIG_MODE_1        EQU SM1
SLEEP_MODE_CONFIG_MODE_0        EQU SM0

BM_SLEEP_MODE_CONFIG_ENABLE     EQU BIT_MASK_7
BM_SLEEP_MODE_CONFIG_MODE_2     EQU BM_SM2
BM_SLEEP_MODE_CONFIG_MODE_1     EQU BM_SM1
BM_SLEEP_MODE_CONFIG_MODE_0     EQU BM_SM0

/* ------------------------------------------------------------------------- */
/* sExtReq                                                                   */
/* ------------------------------------------------------------------------- */
EXT_REQ_TUNE_CHECK_CONFIG        EQU 0
EXT_REQ_SYSTEM_MODE_CONFIG       EQU EXT_REQ_TUNE_CHECK_CONFIG + 1
EXT_REQ_SERVICE_CHANNEL_CONFIG   EQU EXT_REQ_SYSTEM_MODE_CONFIG + 1
EXT_REQ_SERVICE_INIT_CONFIG      EQU EXT_REQ_SERVICE_CHANNEL_CONFIG + 1
EXT_REQ_MISC_TRIGGER             EQU EXT_REQ_SERVICE_INIT_CONFIG + 1

/* ------------------------------------------------------------------------- */
/* sExtReq.systemModeConfig                                                  */
/* ------------------------------------------------------------------------- */
BM_EXT_REQ_SYSTEM_MODE_CONFIG_CLKIDLE_SELECTOR      EQU BIT_MASK_4

/* ------------------------------------------------------------------------- */
/* sExtReq.serviceInitConfig                                                 */
/* ------------------------------------------------------------------------- */
EXT_REQ_SERVICE_INIT_CONFIG_UPDATE_FLAG         EQU BIT_7
EXT_REQ_SERVICE_INIT_CONFIG_EEPROM_NUMBER       EQU BIT_1
EXT_REQ_SERVICE_INIT_CONFIG_SRAM_NUMBER         EQU BIT_0

BM_EXT_REQ_SERVICE_INIT_CONFIG_UPDATE_FLAG      EQU BIT_MASK_7
BM_EXT_REQ_SERVICE_INIT_CONFIG_EEPROM_NUMBER    EQU ( BIT_MASK_1 | BIT_MASK_2 )
BM_EXT_REQ_SERVICE_INIT_CONFIG_SRAM_NUMBER      EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sExtReq.miscTrigger                                                       */
/* ------------------------------------------------------------------------- */
EXT_REQ_MISC_TRIGGER_START_RSSI     EQU BIT_0

BM_EXT_REQ_MISC_TRIGGER_START_RSSI  EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* triggerEEPwr                                                              */
/* ------------------------------------------------------------------------- */
TRIGGEREEP  EQU 0x00

/* ------------------------------------------------------------------------- */
/* facLock                                                                   */
/* ------------------------------------------------------------------------- */
FACLOCK_CONF_FEBIA          EQU 0
FACLOCK_CONF_FEBT           EQU FACLOCK_CONF_FEBIA  + 1
FACLOCK_CONF_FELNA          EQU FACLOCK_CONF_FEBT   + 1
FACLOCK_CONF_FELNA2         EQU FACLOCK_CONF_FELNA  + 1
FACLOCK_CONF_FETN4          EQU FACLOCK_CONF_FELNA2 + 1
FACLOCK_CONF_FEVCO_OFFS     EQU FACLOCK_CONF_FETN4  + 1

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration                                             */
/* ------------------------------------------------------------------------- */
SERVICE_CHCR            EQU 0
SERVICE_CHDN            EQU SERVICE_CHCR + 1
SERVICE_CHSTARTFILTER   EQU SERVICE_CHDN + 1
SERVICE_DMCDA           EQU SERVICE_CHSTARTFILTER + 1
SERVICE_DMCDB           EQU SERVICE_DMCDA + 1
SERVICE_DMCRA           EQU SERVICE_DMCDB + 1
SERVICE_DMCRB           EQU SERVICE_DMCRA + 1
SERVICE_DMDRA           EQU SERVICE_DMCRB + 1
SERVICE_DMDRB           EQU SERVICE_DMDRA + 1
SERVICE_DMMA            EQU SERVICE_DMDRB + 1
SERVICE_DMMB            EQU SERVICE_DMMA + 1
SERVICE_EOT1A           EQU SERVICE_DMMB + 1
SERVICE_EOT1B           EQU SERVICE_EOT1A + 1
SERVICE_EOT2A           EQU SERVICE_EOT1B + 1
SERVICE_EOT2B           EQU SERVICE_EOT2A + 1
SERVICE_EOT3A           EQU SERVICE_EOT2B + 1
SERVICE_EOT3B           EQU SERVICE_EOT3A + 1
SERVICE_FEALR_FEANT     EQU SERVICE_EOT3B + 1
SERVICE_FEAT            EQU SERVICE_FEALR_FEANT + 1
SERVICE_FEPAC           EQU SERVICE_FEAT + 1
SERVICE_FEVCO           EQU SERVICE_FEPAC + 1
SERVICE_FEVCT           EQU SERVICE_FEVCO + 1
SERVICE_FREQOFFSET      EQU SERVICE_FEVCT + 1
SERVICE_TXDEVA          EQU SERVICE_FREQOFFSET + 2
SERVICE_TXDEVB          EQU SERVICE_TXDEVA + 2
SERVICE_GACDIVA         EQU SERVICE_TXDEVB + 2
SERVICE_GACDIVB         EQU SERVICE_GACDIVA + 2
SERVICE_IF              EQU SERVICE_GACDIVB + 2
SERVICE_RDOCR           EQU SERVICE_IF + 2
SERVICE_RSSISYSCONF     EQU SERVICE_RDOCR + 1
SERVICE_RXSETPATHA      EQU SERVICE_RSSISYSCONF + 1
SERVICE_RXSETPATHB      EQU SERVICE_RXSETPATHA + 2
SERVICE_RXSYSEVENT      EQU SERVICE_RXSETPATHB + 2
SERVICE_RXSYSSET        EQU SERVICE_RXSYSEVENT + 1
SERVICE_SFIDA           EQU SERVICE_RXSYSSET + 1
SERVICE_SFIDB           EQU SERVICE_SFIDA + 4
SERVICE_SFIDCA          EQU SERVICE_SFIDB + 4
SERVICE_SFIDCB          EQU SERVICE_SFIDCA + 1
SERVICE_SFIDLA          EQU SERVICE_SFIDCB + 1
SERVICE_SFIDLB          EQU SERVICE_SFIDLA + 1
SERVICE_SOT1A           EQU SERVICE_SFIDLB + 1
SERVICE_SOT1B           EQU SERVICE_SOT1A + 1
SERVICE_SOT2A           EQU SERVICE_SOT1B + 1
SERVICE_SOT2B           EQU SERVICE_SOT2A + 1
SERVICE_SOTTIMEOUTA      EQU SERVICE_SOT2B + 1
SERVICE_SOTTIMEOUTB      EQU SERVICE_SOTTIMEOUTA + 1
SERVICE_SYCA            EQU SERVICE_SOTTIMEOUTB + 1
SERVICE_SYCB            EQU SERVICE_SYCA + 1
SERVICE_FSFCRA          EQU SERVICE_SYCB + 1
SERVICE_FSFCRB          EQU SERVICE_FSFCRA + 1
SERVICE_TMUL            EQU SERVICE_FSFCRB + 1
SERVICE_TRXSYSCONF      EQU SERVICE_TMUL + 1
SERVICE_TXDRA           EQU SERVICE_TRXSYSCONF + 1
SERVICE_TXDRB           EQU SERVICE_TXDRA + 2
SERVICE_TXSETPATHA      EQU SERVICE_TXDRB + 2
SERVICE_TXSETPATHB      EQU SERVICE_TXSETPATHA + 2
SERVICE_TXSYSEVENTA     EQU SERVICE_TXSETPATHB + 2
SERVICE_TXSYSEVENTB     EQU SERVICE_TXSYSEVENTA + 1
SERVICE_TXPREAMBLESYSEVENTA EQU SERVICE_TXSYSEVENTB + 1
SERVICE_TXPREAMBLESYSEVENTB EQU SERVICE_TXPREAMBLESYSEVENTA + 1
SERVICE_WCOTIMEOUTA     EQU SERVICE_TXPREAMBLESYSEVENTB + 1
SERVICE_WCOTIMEOUTB     EQU SERVICE_WCOTIMEOUTA + 1
SERVICE_WUPA            EQU SERVICE_WCOTIMEOUTB + 1
SERVICE_WUPB            EQU SERVICE_WUPA + 4
SERVICE_WUPLA           EQU SERVICE_WUPB + 4
SERVICE_WUPLB           EQU SERVICE_WUPLA + 1
SERVICE_WUPTA           EQU SERVICE_WUPLB + 1
SERVICE_WUPTB           EQU SERVICE_WUPTA + 1
SERVICE_RXCPA           EQU SERVICE_WUPTB + 1
SERVICE_RXCIA           EQU SERVICE_RXCPA + 2
SERVICE_RXSBA           EQU SERVICE_RXCIA + 2
SERVICE_RXTLA           EQU SERVICE_RXSBA + 1
SERVICE_RXCPB           EQU SERVICE_RXTLA + 2
SERVICE_RXCIB           EQU SERVICE_RXCPB + 2
SERVICE_RXSBB           EQU SERVICE_RXCIB + 2
SERVICE_RXTLB           EQU SERVICE_RXSBB + 1
SERVICE_RXBC1           EQU SERVICE_RXTLB + 2
SERVICE_TMCR2A           EQU SERVICE_RXBC1 + 1
SERVICE_TMCR2B           EQU SERVICE_TMCR2A + 1
SERVICE_TMSSCA           EQU SERVICE_TMCR2B + 1
SERVICE_TMSSCB           EQU SERVICE_TMSSCA + 1
SERVICE_TMTLA            EQU SERVICE_TMSSCB + 1
SERVICE_TMTLB            EQU SERVICE_TMTLA + 2
SERVICE_TMCPA            EQU SERVICE_TMTLB + 2
SERVICE_TMCPB            EQU SERVICE_TMCPA + 2
SERVICE_TMCIA            EQU SERVICE_TMCPB + 2
SERVICE_TMCIB            EQU SERVICE_TMCIA + 2
SERVICE_TMCSBA           EQU SERVICE_TMCIB + 2
SERVICE_TMCSBB           EQU SERVICE_TMCSBA + 1
SERVICE_RSSC             EQU SERVICE_TMCSBB + 1

SERVICE_SIZEOF          EQU SERVICE_RSSC + 1

/* ------------------------------------------------------------------------- */
/* sChannelSpecificConfiguration                                             */
/* ------------------------------------------------------------------------- */
CHANNEL_FFREQ           EQU 0
CHANNEL_FEMS            EQU CHANNEL_FFREQ + 3
CHANNEL_FECR            EQU CHANNEL_FEMS + 1
CHANNEL_SIZEOF          EQU CHANNEL_FECR + 1

/* ------------------------------------------------------------------------- */
/* sCurrentServiceConfiguration                                              */
/* ------------------------------------------------------------------------- */
CURRENT_SERVICE_SERVICE_OFFSET EQU 0
CURRENT_SERVICE_CHANNEL_OFFSET EQU CURRENT_SERVICE_SERVICE_OFFSET + SERVICE_SIZEOF

/* ------------------------------------------------------------------------- */
/* sCurrentServiceConfiguration.trxSysConf                                   */
/* ------------------------------------------------------------------------- */
SERVICE_TRXSYSCONF_TRPB_ENA                 EQU BIT_3
SERVICE_TRXSYSCONF_TRPA_ENA                 EQU BIT_2
SERVICE_TRXSYSCONF_ANTENNA_SWITCHING        EQU BIT_1
SERVICE_TRXSYSCONF_CHANNEL_SWITCHING        EQU BIT_0

BM_SERVICE_TRXSYSCONF_TRPB_ENA              EQU BIT_MASK_3
BM_SERVICE_TRXSYSCONF_TRPA_ENA              EQU BIT_MASK_2
BM_SERVICE_TRXSYSCONF_ANTENNA_SWITCHING     EQU BIT_MASK_1
BM_SERVICE_TRXSYSCONF_CHANNEL_SWITCHING     EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.rssiSysConf                                 */
/* ------------------------------------------------------------------------- */
SERVICE_RSSISYSCONF_RSSI_ENABLE             EQU BIT_7

SERVICE_RSSISYSCONF_RSSI_BUF_EVENT_MASK     EQU BIT_5

SERVICE_RSSISYSCONF_RSSI_BUF_4              EQU BIT_4
SERVICE_RSSISYSCONF_RSSI_BUF_3              EQU BIT_3
SERVICE_RSSISYSCONF_RSSI_BUF_2              EQU BIT_2
SERVICE_RSSISYSCONF_RSSI_BUF_1              EQU BIT_1
SERVICE_RSSISYSCONF_RSSI_BUF_0              EQU BIT_0

BM_SERVICE_RSSISYSCONF_RSSI_ENABLE          EQU BIT_MASK_7

BM_SERVICE_RSSISYSCONF_RSSI_BUF_EVENT_MASK  EQU BIT_MASK_5

BM_SERVICE_RSSISYSCONF_RSSI_BUF             EQU ( BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
BM_SERVICE_RSSISYSCONF_RSSI_BUF_4           EQU BIT_MASK_4
BM_SERVICE_RSSISYSCONF_RSSI_BUF_3           EQU BIT_MASK_3
BM_SERVICE_RSSISYSCONF_RSSI_BUF_2           EQU BIT_MASK_2
BM_SERVICE_RSSISYSCONF_RSSI_BUF_1           EQU BIT_MASK_1
BM_SERVICE_RSSISYSCONF_RSSI_BUF_0           EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.rxSetPathA[0]                               */
/* sServiceSpecificConfiguration.rxSetPathA[1]                               */
/* ------------------------------------------------------------------------- */
SERVICE_RXSETPATHA_RX_BUF_EVENT_MASK      EQU BIT_6

SERVICE_RXSETPATHA_RX_BUF_5               EQU BIT_5
SERVICE_RXSETPATHA_RX_BUF_4               EQU BIT_4
SERVICE_RXSETPATHA_RX_BUF_3               EQU BIT_3
SERVICE_RXSETPATHA_RX_BUF_2               EQU BIT_2
SERVICE_RXSETPATHA_RX_BUF_1               EQU BIT_1
SERVICE_RXSETPATHA_RX_BUF_0               EQU BIT_0

BM_SERVICE_RXSETPATHA_RX_BUF_EVENT_MASK   EQU BIT_MASK_6

BM_SERVICE_RXSETPATHA_RX_BUF              EQU ( BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
BM_SERVICE_RXSETPATHA_RX_BUF_5            EQU BIT_MASK_5
BM_SERVICE_RXSETPATHA_RX_BUF_4            EQU BIT_MASK_4
BM_SERVICE_RXSETPATHA_RX_BUF_3            EQU BIT_MASK_3
BM_SERVICE_RXSETPATHA_RX_BUF_2            EQU BIT_MASK_2
BM_SERVICE_RXSETPATHA_RX_BUF_1            EQU BIT_MASK_1
BM_SERVICE_RXSETPATHA_RX_BUF_0            EQU BIT_MASK_0

SERVICE_RXSETPATHA_RXERR1                 EQU BIT_7
SERVICE_RXSETPATHA_RXERR0                 EQU BIT_6
SERVICE_RXSETPATHA_MODULATION             EQU BIT_0

BM_SERVICE_RXSETPATHA_RXERR               EQU ( BIT_MASK_7 | BIT_MASK_6 )
BM_SERVICE_RXSETPATHA_RXERR1              EQU BIT_MASK_7
BM_SERVICE_RXSETPATHA_RXERR0              EQU BIT_MASK_6
BM_SERVICE_RXSETPATHA_MODULATION          EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.rxSetPathB[0]                               */
/* sServiceSpecificConfiguration.rxSetPathB[1]                               */
/* ------------------------------------------------------------------------- */
SERVICE_RXSETPATHB_RX_BUF_EVENT_MASK      EQU BIT_6

SERVICE_RXSETPATHB_RX_BUF_5               EQU BIT_5
SERVICE_RXSETPATHB_RX_BUF_4               EQU BIT_4
SERVICE_RXSETPATHB_RX_BUF_3               EQU BIT_3
SERVICE_RXSETPATHB_RX_BUF_2               EQU BIT_2
SERVICE_RXSETPATHB_RX_BUF_1               EQU BIT_1
SERVICE_RXSETPATHB_RX_BUF_0               EQU BIT_0

BM_SERVICE_RXSETPATHB_RX_BUF_EVENT_MASK   EQU BIT_MASK_6

BM_SERVICE_RXSETPATHB_RX_BUF              EQU ( BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
BM_SERVICE_RXSETPATHB_RX_BUF_5            EQU BIT_MASK_5
BM_SERVICE_RXSETPATHB_RX_BUF_4            EQU BIT_MASK_4
BM_SERVICE_RXSETPATHB_RX_BUF_3            EQU BIT_MASK_3
BM_SERVICE_RXSETPATHB_RX_BUF_2            EQU BIT_MASK_2
BM_SERVICE_RXSETPATHB_RX_BUF_1            EQU BIT_MASK_1
BM_SERVICE_RXSETPATHB_RX_BUF_0            EQU BIT_MASK_0

SERVICE_RXSETPATHB_RXERR1                 EQU BIT_7
SERVICE_RXSETPATHB_RXERR0                 EQU BIT_6
SERVICE_RXSETPATHB_MODULATION             EQU BIT_0

BM_SERVICE_RXSETPATHB_RXERR               EQU ( BIT_MASK_7 | BIT_MASK_6 )
BM_SERVICE_RXSETPATHB_RXERR1              EQU BIT_MASK_7
BM_SERVICE_RXSETPATHB_RXERR0              EQU BIT_MASK_6
BM_SERVICE_RXSETPATHB_MODULATION          EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.txSetPathA[0]                               */
/* sServiceSpecificConfiguration.txSetPathA[1]                               */
/* ------------------------------------------------------------------------- */
SERVICE_TXSETPATHA_GAUS                 EQU BIT_7
SERVICE_TXSETPATHA_PREE                 EQU BIT_6
SERVICE_TXSETPATHA_STARTTXFILLLEVEL5    EQU BIT_5
SERVICE_TXSETPATHA_STARTTXFILLLEVEL4    EQU BIT_4
SERVICE_TXSETPATHA_STARTTXFILLLEVEL3    EQU BIT_3
SERVICE_TXSETPATHA_STARTTXFILLLEVEL2    EQU BIT_2
SERVICE_TXSETPATHA_STARTTXFILLLEVEL1    EQU BIT_1
SERVICE_TXSETPATHA_STARTTXFILLLEVEL0    EQU BIT_0

BM_SERVICE_TXSETPATHA_GAUS              EQU BIT_MASK_7
BM_SERVICE_TXSETPATHA_PREE              EQU BIT_MASK_6

BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL  EQU (  BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL5 EQU BIT_MASK_5
BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL4 EQU BIT_MASK_4
BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL3 EQU BIT_MASK_3
BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL2 EQU BIT_MASK_2
BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL1 EQU BIT_MASK_1
BM_SERVICE_TXSETPATHA_STARTTXFILLLEVEL0 EQU BIT_MASK_0

SERVICE_TXSETPATHA_MODULATION               EQU BIT_7
SERVICE_TXSETPATHA_ASK_SHAPING              EQU BIT_6
SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL4  EQU BIT_4
SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL3  EQU BIT_3
SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL2  EQU BIT_2
SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL1  EQU BIT_1
SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL0  EQU BIT_0

BM_SERVICE_TXSETPATHA_MODULATION              EQU BIT_MASK_7
BM_SERVICE_TXSETPATHA_ASK_SHAPING             EQU BIT_MASK_6
BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL  EQU ( BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL4 EQU BIT_MASK_4
BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL3 EQU BIT_MASK_3
BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL2 EQU BIT_MASK_2
BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL1 EQU BIT_MASK_1
BM_SERVICE_TXSETPATHA_STARTPREAMBLEFILLLEVEL0 EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.txSetPathB[0]                               */
/* sServiceSpecificConfiguration.txSetPathB[1]                               */
/* ------------------------------------------------------------------------- */
SERVICE_TXSETPATHB_GAUS                 EQU BIT_7
SERVICE_TXSETPATHB_PREE                 EQU BIT_6
SERVICE_TXSETPATHB_STARTTXFILLLEVEL5    EQU BIT_5
SERVICE_TXSETPATHB_STARTTXFILLLEVEL4    EQU BIT_4
SERVICE_TXSETPATHB_STARTTXFILLLEVEL3    EQU BIT_3
SERVICE_TXSETPATHB_STARTTXFILLLEVEL2    EQU BIT_2
SERVICE_TXSETPATHB_STARTTXFILLLEVEL1    EQU BIT_1
SERVICE_TXSETPATHB_STARTTXFILLLEVEL0    EQU BIT_0

BM_SERVICE_TXSETPATHB_GAUS              EQU BIT_MASK_7
BM_SERVICE_TXSETPATHB_PREE              EQU BIT_MASK_6

BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL  EQU ( BIT_MASK_5 | BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL5 EQU BIT_MASK_5
BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL4 EQU BIT_MASK_4
BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL3 EQU BIT_MASK_3
BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL2 EQU BIT_MASK_2
BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL1 EQU BIT_MASK_1
BM_SERVICE_TXSETPATHB_STARTTXFILLLEVEL0 EQU BIT_MASK_0

SERVICE_TXSETPATHB_MODULATION               EQU BIT_7
SERVICE_TXSETPATHB_ASK_SHAPING              EQU BIT_6
SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL4  EQU BIT_4
SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL3  EQU BIT_3
SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL2  EQU BIT_2
SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL1  EQU BIT_1
SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL0  EQU BIT_0

BM_SERVICE_TXSETPATHB_MODULATION              EQU BIT_MASK_7
BM_SERVICE_TXSETPATHB_ASK_SHAPING             EQU BIT_MASK_6
BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL  EQU ( BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL4 EQU BIT_MASK_4
BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL3 EQU BIT_MASK_3
BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL2 EQU BIT_MASK_2
BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL1 EQU BIT_MASK_1
BM_SERVICE_TXSETPATHB_STARTPREAMBLEFILLLEVEL0 EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sCurrentServiceConfiguration.trxSysEventA                                 */
/* ------------------------------------------------------------------------- */
SERVICE_TXSYSEVENTA_TX_ENDING                EQU BIT_7
SERVICE_TXSYSEVENTA_TX_BUF_EVENT_MASK        EQU BIT_6

BM_SERVICE_TXSYSEVENTA_TX_ENDING             EQU BIT_MASK_7
BM_SERVICE_TXSYSEVENTA_TX_BUF_EVENT_MASK     EQU BIT_MASK_6

/* ------------------------------------------------------------------------- */
/* sCurrentServiceConfiguration.trxSysEventB                                 */
/* ------------------------------------------------------------------------- */
SERVICE_TXSYSEVENTB_TX_ENDING                EQU BIT_7
SERVICE_TXSYSEVENTB_TX_BUF_EVENT_MASK        EQU BIT_6

BM_SERVICE_TXSYSEVENTB_TX_ENDING             EQU BIT_MASK_7
BM_SERVICE_TXSYSEVENTB_TX_BUF_EVENT_MASK     EQU BIT_MASK_6

/* ------------------------------------------------------------------------- */
/* sServiceSpecificConfiguration.txPreambleSysEvent                          */
/* ------------------------------------------------------------------------- */
SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF_EVENT_MASK     EQU BIT_5
SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF4               EQU BIT_4
SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF3               EQU BIT_3
SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF2               EQU BIT_2
SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF1               EQU BIT_1
SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF0               EQU BIT_0

BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF_EVENT_MASK  EQU BIT_MASK_5
BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF             EQU ( BIT_MASK_4 | BIT_MASK_3 | BIT_MASK_2 | BIT_MASK_1 | BIT_MASK_0 )
BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF4            EQU BIT_MASK_4
BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF3            EQU BIT_MASK_3
BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF2            EQU BIT_MASK_2
BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF1            EQU BIT_MASK_1
BM_SERVICE_TXPREAMBLESYSEVENT_TXPREAMBLEBUF0            EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sCurrentServiceConfiguration.rxSysEvent                                   */
/* ------------------------------------------------------------------------- */
SERVICE_RXSYSEVENT_ID_CHECKA        EQU BIT_7
SERVICE_RXSYSEVENT_WCOA             EQU BIT_6
SERVICE_RXSYSEVENT_SOTA             EQU BIT_5
SERVICE_RXSYSEVENT_EOTA             EQU BIT_4
SERVICE_RXSYSEVENT_ID_CHECKB        EQU BIT_3
SERVICE_RXSYSEVENT_WCOB             EQU BIT_2
SERVICE_RXSYSEVENT_SOTB             EQU BIT_1
SERVICE_RXSYSEVENT_EOTB             EQU BIT_0

BM_SERVICE_RXSYSEVENT_ID_CHECKA     EQU BIT_MASK_7
BM_SERVICE_RXSYSEVENT_WCOA          EQU BIT_MASK_6
BM_SERVICE_RXSYSEVENT_SOTA          EQU BIT_MASK_5
BM_SERVICE_RXSYSEVENT_EOTA          EQU BIT_MASK_4
BM_SERVICE_RXSYSEVENT_ID_CHECKB     EQU BIT_MASK_3
BM_SERVICE_RXSYSEVENT_WCOB          EQU BIT_MASK_2
BM_SERVICE_RXSYSEVENT_SOTB          EQU BIT_MASK_1
BM_SERVICE_RXSYSEVENT_EOTB          EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* sCurrentServiceConfiguration.rxSysSet                                     */
/* ------------------------------------------------------------------------- */
SERVICE_RXSYSSET_SUBCHANNELING              EQU BIT_7
SERVICE_RXSYSSET_IDSCAN_ENABLE              EQU BIT_6
SERVICE_RXSYSSET_IFAMPLIFIER_ENABLE         EQU BIT_5
SERVICE_RXSYSSET_PATH_VALID_AFTER_SOT       EQU BIT_4
SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHB      EQU BIT_3
SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHA      EQU BIT_2
SERVICE_RXSYSSET_SWITCHING_SDTX             EQU BIT_1
SERVICE_RXSYSSET_SWITCHING_SDRX             EQU BIT_0

BM_SERVICE_RXSYSSET_SUBCHANNELING           EQU BIT_MASK_7
BM_SERVICE_RXSYSSET_IDSCAN_ENABLE           EQU BIT_MASK_6
BM_SERVICE_RXSYSSET_IFAMPLIFIER_ENABLE      EQU BIT_MASK_5
BM_SERVICE_RXSYSSET_PATH_VALID_AFTER_SOT    EQU BIT_MASK_4
BM_SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHB   EQU BIT_MASK_3
BM_SERVICE_RXSYSSET_ANTENNA_DAMPING_PATHA   EQU BIT_MASK_2
BM_SERVICE_RXSYSSET_SWITCHING_SDTX          EQU BIT_MASK_1
BM_SERVICE_RXSYSSET_SWITCHING_SDRX          EQU BIT_MASK_0
BM_SERVICE_RXSYSSET_SWITCHING               EQU BM_SERVICE_RXSYSSET_SWITCHING_SDTX | BM_SERVICE_RXSYSSET_SWITCHING_SDRX

/* ------------------------------------------------------------------------- */
/* sysStatus                                                                 */
/* ------------------------------------------------------------------------- */
SYS_STATUS_UPDATE                   EQU BIT_7
SYS_STATUS_RDY_4_DIRECTSWITCHING    EQU BIT_6
SYS_STATUS_SPI_CMD_IN_PROGRESS      EQU BIT_5
SYS_STATUS_TRIGGER_MAIN_LOOP        EQU BIT_4
SYS_STATUS_SSM_SLEEP_ENABLE         EQU BIT_3
SYS_STATUS_CALIB                    EQU BIT_2
SYS_STATUS_AVCCLOW                  EQU BIT_1
SYS_STATUS_SSMRDY                   EQU BIT_0

BM_SYS_STATUS_UPDATE                EQU BIT_MASK_7
BM_SYS_STATUS_RDY_4_DIRECTSWITCHING EQU BIT_MASK_6
BM_SYS_STATUS_SPI_CMD_IN_PROGRESS   EQU BIT_MASK_5
BM_SYS_STATUS_TRIGGER_MAIN_LOOP     EQU BIT_MASK_4
BM_SYS_STATUS_SSM_SLEEP_ENABLE      EQU BIT_MASK_3
BM_SYS_STATUS_CALIB                 EQU BIT_MASK_2
BM_SYS_STATUS_AVCCLOW               EQU BIT_MASK_1
BM_SYS_STATUS_SSMRDY                EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* trxStatus for TX                                                          */
/* ------------------------------------------------------------------------- */
TRX_STATUS_TX_TRANSMISSION_COMPLETE     EQU BIT_1
TRX_STATUS_TX_ASK_FSK_MODULATION        EQU BIT_0

BM_TRX_STATUS_TX_TRANSMISSION_COMPLETE  EQU BIT_MASK_1
BM_TRX_STATUS_TX_ASK_FSK_MODULATION     EQU BIT_MASK_0

TRX_STATUS_TX_FSK_MODULATION    EQU     0
TRX_STATUS_TX_ASK_MODULATION    EQU     1

/* ------------------------------------------------------------------------- */
/* trxStatus for RX                                                          */
/* ------------------------------------------------------------------------- */
TRX_STATUS_RX_WCOB  EQU BIT_7
TRX_STATUS_RX_WCOA  EQU BIT_6
TRX_STATUS_RX_SOTB  EQU BIT_5
TRX_STATUS_RX_SOTA  EQU BIT_4
TRX_STATUS_RX_EOTB  EQU BIT_3
TRX_STATUS_RX_EOTA  EQU BIT_2
TRX_STATUS_RX_ASK_FSK_MODULATION    EQU BIT_0

BM_TRX_STATUS_RX_WCOB  EQU BIT_MASK_7
BM_TRX_STATUS_RX_WCOA  EQU BIT_MASK_6
BM_TRX_STATUS_RX_SOTB  EQU BIT_MASK_5
BM_TRX_STATUS_RX_SOTA  EQU BIT_MASK_4
BM_TRX_STATUS_RX_EOTB  EQU BIT_MASK_3
BM_TRX_STATUS_RX_EOTA  EQU BIT_MASK_2
BM_TRX_STATUS_RX_ASK_FSK_MODULATION     EQU BIT_MASK_0

TRX_STATUS_RX_FSK_MODULATION    EQU     TRX_STATUS_TX_FSK_MODULATION
TRX_STATUS_RX_ASK_MODULATION    EQU     TRX_STATUS_TX_ASK_MODULATION

/* ------------------------------------------------------------------------- */
/* sSystemFlowCtrl                                                           */
/* ------------------------------------------------------------------------- */
SYSFLOWCTRL_MSMSTATE                    EQU 0
SYSFLOWCTRL_INDEX                       EQU SYSFLOWCTRL_MSMSTATE + 1
SYSFLOWCTRL_PLUT_LOW_FUNCPTR_ADDR       EQU SYSFLOWCTRL_INDEX + 1
SYSFLOWCTRL_PLUT_HIGH_FUNCPTR_ADDR      EQU SYSFLOWCTRL_PLUT_LOW_FUNCPTR_ADDR + 1

/* ------------------------------------------------------------------------- */
/* sDebug                                                                    */
/* ------------------------------------------------------------------------- */
DEBUG_ERROR_CODE         EQU 0
DEBUG_SSM_ERROR_CODE     EQU DEBUG_ERROR_CODE + 1

/* ------------------------------------------------------------------------- */
/* sSubChanneling                                                            */
/* ------------------------------------------------------------------------- */
SUBCHANNELING_RSSI_VAL  EQU 0U
SUBCHANNELING_FLAGS     EQU SUBCHANNELING_RSSI_VAL + 3

SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED      EQU BIT_1
SUBCHANNELING_ACTIVE                            EQU BIT_0
BM_SUBCHANNELING_RSSI_FIFO_FILL_LEVEL_REACHED   EQU BIT_MASK_1
BM_SUBCHANNELING_ACTIVE                         EQU BIT_MASK_0

/* ------------------------------------------------------------------------- */
/* rxIrqEvents[3]                                                            */
/* ------------------------------------------------------------------------- */
RXIRQEVENTS_BEFORE_WCOAB    EQU 0U
RXIRQEVENTS_AFTER_WCOAB     EQU RXIRQEVENTS_BEFORE_WCOAB + 1
RXIRQEVENTS_AFTER_SOTAB     EQU RXIRQEVENTS_AFTER_WCOAB + 1


/*stopSimExtraction*/
#endif /* __IAR_SYSTEMS_ASM__ */

#endif /* GLOBALS_DEFS_H */