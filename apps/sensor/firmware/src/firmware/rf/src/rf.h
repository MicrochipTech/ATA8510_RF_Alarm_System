/* *H**************************************************************************
  Use of this software is subject to Atmel's Software License Agreement.
-------------------------------------------------------------------------------
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/firmware/rf/src/rf.h $
  $LastChangedRevision: 654163 $
  $LastChangedDate: 2022-01-11 14:55:00 +0100 (Di, 11 Jan 2022) $
  $LastChangedBy: gwillbol $
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
/** \file rf.h
 */

#ifndef RF_H
#define RF_H

#if defined(__IAR_SYSTEMS_ICC__) || defined(__XC8_CC__)

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "../../stdc/src/stdc.h"
/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/* SSM state definitions */
/** \brief <b>SSM_END_STATE</b> is used as define for end state */
#define SSM_END_STATE               0U
/** \brief <b>SSM_PLL_EN_STATE</b> is used as define for PLL enable sub state machine */
#define SSM_PLL_EN_STATE            (SSM_END_STATE           + 1U)
/** \brief <b>SSM_PLL_LOCK_STATE</b> is used as define for PLL lock sub state machine */
#define SSM_PLL_LOCK_STATE          (SSM_PLL_EN_STATE        + 1U)
/** \brief <b>SSM_RX_DSP_EN_STATE</b> is used as define for RX DSP enable sub state machine */
#define SSM_RX_DSP_EN_STATE         (SSM_PLL_LOCK_STATE      + 1U)
/** \brief <b>SSM_RX_DSP_DIS_STATE</b> is used as define for RX DSP disable sub state machine */
#define SSM_RX_DSP_DIS_STATE        (SSM_RX_DSP_EN_STATE     + 1U)
/** \brief <b>SSM_TX_DSP_EN_STATE</b> is used as define for TX DSP enable sub state machine */
#define SSM_TX_DSP_EN_STATE         (SSM_RX_DSP_DIS_STATE    + 1U)
/** \brief <b>SSM_TX_DSP_DIS_STATE</b> is used as define for TX DSP disable sub state machine */
#define SSM_TX_DSP_DIS_STATE        (SSM_TX_DSP_EN_STATE     + 1U)
/** \brief <b>SSM_RX_2_TX_STATE</b> is used as define for RX to TX sub state machine */
#define SSM_RX_2_TX_STATE           (SSM_TX_DSP_DIS_STATE    + 1U)
/** \brief <b>SSM_TX_2_RX_STATE</b> is used as define for TX to RX sub state machine */
#define SSM_TX_2_RX_STATE           (SSM_RX_2_TX_STATE       + 1U)
/** \brief <b>SSM_GET_TELEGRAM_STATE</b> is used as define for get telegram sub state machine */
#define SSM_GET_TELEGRAM_STATE      (SSM_TX_2_RX_STATE       + 1U)
/** \brief <b>SSM_SEND_TELEGRAM_STATE</b> is used as define for send telegram sub state machine */
#define SSM_SEND_TELEGRAM_STATE     (SSM_GET_TELEGRAM_STATE  + 1U)
/** \brief <b>SSM_SHUTDOWN_STATE</b> is used as define for shut down sub state machine */
#define SSM_SHUTDOWN_STATE          (SSM_SEND_TELEGRAM_STATE + 1U)
/** \brief <b>SSM_VCO_TUNING_STATE</b> is used as define for vco tuning sub state machine */
#define SSM_VCO_TUNING_STATE        (SSM_SHUTDOWN_STATE      + 1U)
/** \brief <b>SSM_ANTENNA_TUNING_STATE</b> is used as define for antenna tuning sub state machine */
#define SSM_ANTENNA_TUNING_STATE    (SSM_VCO_TUNING_STATE    + 1U)


/** \brief <b>BM_DFFLS</b> is used as data fifo fill level bit mask */
#define BM_DFFLS					(BM_DFFLS0|BM_DFFLS1|BM_DFFLS2|BM_DFFLS3|BM_DFFLS4|BM_DFFLS5)
/** \brief <b>BM_SFFLS</b> is used as support fifo fill level bit mask */
#define BM_SFFLS					(BM_SFFLS0 |BM_SFFLS1 |BM_SFFLS2 |BM_SFFLS3 |BM_SFFLS4 )

/*===========================================================================*/
/*  TYPE DEFINITIONS                                                         */
/*===========================================================================*/

/*----------------------------------------------------------------------------- */
/** \brief <b>sRfPaCtrl</b>
    contains a byte to control the PAs' output power.
*/
/*----------------------------------------------------------------------------- */
typedef struct{
    /** \brief <b>sRfPaCtrl</b>
        byte containg the daming of the EEPROM configured output power.
    */
    volatile uint8_t paDamping;
}sRfPaCtrl;

/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/

extern sRfPaCtrl                  rfPaCtrl;

extern uint8_t                    rfRssiValue;

extern VOIDFUNC ATA_resetSSMs_C(void);

extern VOIDFUNC ATA_switchIdleXTO_ASM(void);

extern VOIDFUNC ATA_shutDownRf_C(void);

extern VOIDFUNC ATA_shutDownFe_C(void);

extern VOIDFUNC ATA_pwrDwnDsp_C(void);

extern UINT8FUNC ATA_startInitTxRxSSM_C(void);

extern VOIDFUNC ATA_setRxActive_ASM(void);

extern VOIDFUNC ATA_clrRxActive_ASM(void);

extern VOIDFUNC ATA_setSystemError_ASM(void);

extern VOIDFUNC ATA_startShutDownSSM_C(void);

extern VOIDFUNC ATA_doFeInit4TxRxSSM_C(void);

extern UINT8FUNC ATA_doFevcoRegisterCalculation_C(void);

#elif defined __IAR_SYSTEMS_ASM__

#endif

#endif /* RF_H */