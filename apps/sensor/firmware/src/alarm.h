/* 
 * File:   alarm.h
 * Author: M43814
 *
 * Created on January 22, 2026, 2:32 PM
 */

 /**
  * \file alarm.h
  * include file for module alarm
  */

#ifndef ALARM_H
#define	ALARM_H

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
/*===========================================================================*/
/*  EXTERNAL PROTOTYPES                                                      */
/*===========================================================================*/
/* Alarm State */
/** State machine function for '::STATE_ALARM'
 * Sends AL_MSG via RF Tx and switch to state '::STATE_ALARM_START_RX_ACK_MSG'
 */
extern void state_alarm(void);
/** State machine function for '::STATE_ALARM_START_RX_ACK_MSG'
 * Starts RF Rx Mode if Tx of AL_MSG is completed and switch to state '::STATE_ALARM_RX_ACK_MSG'
 * \note starts a timer with 100ms expiration time
 */
extern void state_alarm_start_rx_ack_msg(void);
/** State machine function for '::STATE_ALARM_RX_ACK_MSG'
 * If ACK_MSG is received correct, switch to state '::STATE_IDLE',
 * otherwise switch to state '::STATE_ALARM' and repeat AL_MSG sending
 */
extern void state_alarm_rx_ack_msg(void);



#ifdef	__cplusplus
}
#endif

#endif	/* ALARM_H */

