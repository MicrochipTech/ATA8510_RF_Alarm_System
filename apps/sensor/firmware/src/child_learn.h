/* 
 * File:   child_learn.h
 * Author: M43814
 *
 * Created on January 21, 2026, 1:05 PM
 */

/** \file child_learn.h
 * include file for module child_learn
 */

#ifndef CHILD_LEARN_H
#define	CHILD_LEARN_H

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
/* Child Sensor Learn States */
/** 
 * Sends the PART_REQ command to the parent device to initiate pairing.
 */
extern void state_child_sensor_learn_tx_part_req(void);
/**
 * Starts RF receive mode to wait for the PART_REQ_RESP message from the parent.
 */
extern void state_child_sensor_learn_start_rx_part_req_resp(void);
/**
 * Receives the PART_REQ_RESP message and restarts RF receive mode for further communication.
 */
extern void state_child_sensor_learn_rx_part_req_resp(void);
/**
 * Receives the CON_VER_STAT message, indicating the connection verification status.
 */
extern void state_child_sensor_learn_rx_con_ver_stat(void);
/**
 * Creates an ACK_MSG and starts RF transmission to acknowledge receipt.
 */
extern void state_child_sensor_learn_tx_ack_msg(void);
/**
 * Completes the transmission of the ACK_MSG.
 */
extern void state_child_sensor_learn_tx_ack_msg_complete(void);




#ifdef	__cplusplus
}
#endif

#endif	/* CHILD_LEARN_H */

