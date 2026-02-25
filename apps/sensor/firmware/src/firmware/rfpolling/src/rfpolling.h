/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/rfpolling/src/rfpolling.h $
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
/** \file rfpolling.h
 */

#ifndef RFPOLLING_H
#define RFPOLLING_H

#ifdef __IAR_SYSTEMS_ICC__

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
#include "../../globals/src/globals.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/

/** \brief <b>POLLING_ACTIVE</b>
    indicates polling cycle is in progress.
*/
#define POLLING_ACTIVE                      0x01U

/** \brief <b>POLLING_FAST</b>
    indicates fast PollingMode is used.
*/
#define POLLING_FAST                        0x02U

/** \brief <b>POLLING_SELFCHECK</b>
    indicates system self-check and calibration should be executed/is in progress during PollingMode.
*/
#define POLLING_SELFCHECK                   0x04U

/** \brief <b>POLLING_SELFCHECK_FIRST_CYCLE</b>
    indicates system self-check and calibration should be executed at the end of first polling cycle.
*/
#define POLLING_SELFCHECK_FIRST_CYCLE       0x08U

/** \brief <b>POLLING_VCO_CAL_ON_FIRST_CHANNEL</b>
    indicates a VCO calibration must be executed on first polling channel.
*/
#define POLLING_VCO_CAL_ON_FIRST_CHANNEL    0x10U

/** \brief <b>BM_POLLCONFIG_CONFIG_CALIBRATION</b>
    is used as bitmask in Polling Mode.
 */
#define BM_POLLCONFIG_CONFIG_CALIBRATION    ( BM_SYS_MODE_CONFIG_RF_CALIBRATION | BM_SYS_MODE_CONFIG_VCO_TUNING )

/** \brief <b>BM_POLLCONFIG_SYS_MODE_CONFIG_VALID</b>
    is used as bitmask in Polling Mode.
 */
#define BM_POLLCONFIG_SYS_MODE_CONFIG_VALID ( BM_SYS_MODE_CONFIG_IDLE_MODE_SELECTOR | BM_SYS_MODE_CONFIG_DIRECT_SWITCH | BM_SYS_MODE_CONFIG_TRANSPARENT_MODE | BM_SYS_MODE_CONFIG_OPM )

/** \brief <b>POLLCONFIG_CONFIG_EOP</b>
    indicates the end of a polling cycle EOC (End Of Cycle), the next polling cycle is started
    with the next channel configuration located in the SRAM array.
*/
#define POLLCONFIG_CONFIG_EOP           BIT_0

/** \brief <b>BM_POLLCONFIG_CONFIG_EOP</b>
    is used as bitmask for POLLCONFIG_CONFIG_EOP bit.
 */
#define BM_POLLCONFIG_CONFIG_EOP        BIT_MASK_0

/** \brief <b>POLLCONFIG_CONFIG_EOL</b>
    indicates the end of a polling loop EOL (End Of Loop), the next polling cycle is started
    with the first channel configuration located in the SRAM array.
*/
#define POLLCONFIG_CONFIG_EOL           BIT_1

/** \brief <b>BM_POLLCONFIG_CONFIG_EOL</b>
    is used as bitmask for POLLCONFIG_CONFIG_EOL bit.
 */
#define BM_POLLCONFIG_CONFIG_EOL        BIT_MASK_1

/*===========================================================================*/
/*  TYPE DEFINITIONS                                                         */
/*===========================================================================*/

/*----------------------------------------------------------------------------- */
/** \brief <b>sPollingConfig</b>
    contains the polling channel configuration and the Polling timer
    configuration for SRAM polling array.
 */
/*----------------------------------------------------------------------------- */
typedef struct
{
    /** \brief <b>confT1COR</b>
        is the T1COR register setting used for polling cycle configuration.
     */
    uint8_t confT1COR;

    /** \brief <b>confT1MR</b>
        is the T1MR register setting used for polling cycle configuration.
        \li Bit 7..6:  rfu
        \li Bit 5..2:  T1PS[3..0]
        \li Bit 1..0:  T1CS[1..0]
     */
    uint8_t confT1MR;

    /** \brief <b>pollChanConf</b>
        array containing the service/channel configuration.
     */
    sPollingChannelConfig pollChanConf[NUM_POLL_CHAN_CONFIG];
}  sPollingConfig;

/*----------------------------------------------------------------------------- */
/** \brief <b>sPollingStatus</b>
    contains status information needed by firmware for polling control
 */
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>cycleCnt</b>
        global 16-bit polling cycle counter.
     */
    uint16_t cycleCnt;

    /** \brief <b>confIdx</b>
        indicates currently used polling configuration index.
     */
    uint8_t confIdx;

    /** \brief <b>status</b>
        contains flags for storing status information during polling.
        \li Bit 7..5: rfu
        \li Bit 4: <br>
            - 1: first polling channel includes VCO calibration (forced by command) <br>
            - 0: first polling channel may include VCO calibration (config dependent) <br>
        \li Bit 3: <br>
            - 1: system self-check and calibration should be executed at the end of first polling cycle <br>
            - 0: no execution of system self-check and calibration at the end of first polling cycle <br>
        \li Bit 2: <br>
            - 1: system self-check and calibration during PollingMode should be executed/is in progress <br>
            - 0: system self-check and calibration during PollingMode not active <br>
        \li Bit 1: <br>
            - 1: fast PollingMode enabled <br>
            - 0: standard PollingMode enabled <br>
        \li Bit 0: <br>
            - 1: polling cycle is in progress <br>
            - 0: polling cycle is not active <br>
     */
    uint8_t flags;
} sPollingStatus;

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern sPollingConfig pollConfig;

extern sPollingStatus pollStatus;

extern VOIDFUNC ATA_pollStateInitCurrentPollingChannel_C(void);

extern VOIDFUNC ATA_pollStateInitSSM_C(void);

extern VOIDFUNC ATA_pollStateWait4SSMstateGetTelegram_C(void);

extern VOIDFUNC ATA_pollStateWait4ShutdownRdyTRX_C(void);

extern VOIDFUNC ATA_pollStateCheck4NextPollingChannel_C(void);

extern VOIDFUNC ATA_pollStateISR_ASM(void);

#elif defined __IAR_SYSTEMS_ASM__
/*startSimExtraction*/

/* sPollingConfig offset definitions */
POLL_T1COR                      EQU 0x00
POLL_T1MR                       EQU 0x01
POLL_CHAN_CONF                  EQU 0x02

/* sPollingStatus offset definitions */
POLL_CYCLE_CNT                  EQU 0x00
POLL_CONF_IDX                   EQU 0x02
POLL_FLAGS                      EQU 0x03


/* Flags and associated bitmask definitions in PollingMode */
POLLING_VCO_CAL_ON_FIRST_CHANNEL    EQU BIT_4   /* Bit 4: 1: first polling channel includes VCO calibration (forced by command) */
                                                /*        0: first polling channel may include VCO calibration (config dependent) */
POLLING_SELFCHECK_FIRST_CYCLE       EQU BIT_3   /* Bit 3: 1: system self-check and calibration should be executed at the end of first polling cycle */
                                                /*        0: no execution of system self-check and calibration at the end of first polling cycle */
POLLING_SELFCHECK                   EQU BIT_2   /* Bit 2: 1: system self-check and calibration during PollingMode should be executed/is in progress */
                                                /*        0: system self-check and calibration during PollingMode not active */
POLLING_FAST                        EQU BIT_1   /* Bit 1: 1: fast PollingMode enabled */
                                                /*        0: standard PollingMode enabled */
POLLING_ACTIVE                      EQU BIT_0   /* Bit 0: 1: polling cycle is in progress */
                                                /*        0: polling cycle is not active */

BM_POLLING_VCO_CAL_ON_FIRST_CHANNEL EQU ( 1 << POLLING_VCO_CAL_ON_FIRST_CHANNEL )
BM_POLLING_SELFCHECK_FIRST_CYCLE    EQU ( 1 << POLLING_SELFCHECK_FIRST_CYCLE )
BM_POLLING_SELFCHECK                EQU ( 1 << POLLING_SELFCHECK )
BM_POLLING_FAST                     EQU ( 1 << POLLING_FAST )
BM_POLLING_ACTIVE                   EQU ( 1 << POLLING_ACTIVE )


POLL_CYCLE_CNT_LB                   EQU 0x00   /* low byte of global cycle counter */
POLL_CYCLE_CNT_HB                   EQU 0x01   /* high byte of global cycle counter */
/*stopSimExtraction*/
#endif

#endif /* RFPOLLIING_H */