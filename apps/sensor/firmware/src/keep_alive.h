/* 
 * File:   keep_alive.h
 * Author: M43814
 *
 * Created on January 21, 2026, 11:53 AM
 */
/** \file keep_alive.h
 * header file for keep alive implementation
 */
#ifndef KEEP_ALIVE_H
#define	KEEP_ALIVE_H

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
/**
 * Initial state for keep alive implementation
 * - start checking of child sensors
 */
extern void state_keep_alive(void);

/**
 * Wait for KA_MSG from child sensor received
 */
extern void state_keep_alive_process_child_rx_ka_msg(void);
/**
 * Start RF TX to send ACK_MSG to child sensor device
 */
extern void state_keep_alive_process_child_tx_ack_msg(void);
/**
 * RF TX of ACK_MSG completed
 */
extern void state_keep_alive_process_child_tx_ack_msg_complete(void);
/**
 * Send out KA_MSG to parent sensor
 */
extern void state_keep_alive_tx_ka_msg(void);
/** 
 * Start RF RX mode to receive ACK_MSG from parent
 */
extern void state_keep_alive_start_rx_ack(void);
/**
 * ACK_MSG received
 */
extern void state_keep_alive_rx_ack(void);
/** 
 * Enter Sleep Mode after KA_MSG was acknowledged
 */
extern void state_keep_alive_sleep(void);

/**
 * Initial state keep alive implementation (Child First approach)
 */
extern void state_ka_cf(void);
/**
 * Wait for KA_MSG from child sensor received
 */
extern void state_ka_cf_process_child_rx_ka_msg(void);
/**
 * Start RF TX to send ACK_MSG to child sensor device
 */
extern void state_ka_cf_process_child_tx_ack_msg(void);
/**
 * RF TX of ACK_MSG complete
 */
extern void state_ka_cf_process_child_tx_ack_msg_complete(void);
/**
 * Send out KA_MSG to parent sensor
 */
extern void state_ka_cf_tx_ka_msg(void);
/**
 * Start RF RX mode to receive ACK_MSG from parent
 */
extern void state_ka_cf_start_rx_ack(void);
/**
 * ACK_MSG received
 */
extern void state_ka_cf_rx_ack(void);
/**
 * Enter Sleep Mode after KA_MSG was acknowledged
 */
extern void state_ka_cf_sleep(void);



#ifdef	__cplusplus
}
#endif

#endif	/* KEEP_ALIVE_H */

