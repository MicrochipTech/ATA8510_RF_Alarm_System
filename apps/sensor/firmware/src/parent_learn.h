/* 
 * File:   parent_learn.h
 * Author: M43814
 *
 * Created on January 21, 2026, 1:13 PM
 */

/** \file parent_learn.h
 * Include file for module 'parent_learn'
 */

#ifndef PARENT_LEARN_H
#define	PARENT_LEARN_H

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
/* Parent Learn Mode */
/**
 * Start RF RX mode to receive PART_REQ message from child sensor
 */
extern void state_parent_sensor_learn_start_rx_part_req(void);
/**
 * PART_REQ message received from child sensor
 */
extern void state_parent_sensor_learn_rx_part_req(void);
/**
 * Start RF TX Mode and send CON_VER_REQ message to parent sensor
 */
extern void state_parent_sensor_learn_tx_con_ver_req(void);
/**
 * Start RF RX mode to receive CON_VER_RESP message from parent sensor
 */
extern void state_parent_sensor_learn_start_rx_con_ver_resp(void);
/**
 * CON_VER_RESP message received from parent sensor
 */
extern void state_parent_sensor_learn_rx_con_ver_resp(void);
/**
 * Start RF TX Mode and send PART_REQ_RESP message to child sensor
 */
extern void state_parent_sensor_learn_tx_part_req_resp(void);
/**
 * Start RF TX Mode and send CON_VER_STAT message to child sensor
 */
extern void state_parent_sensor_learn_tx_con_ver_stat(void);
/**
 * Start RF RX mode to receive ACK_MSG from child sensor
 */
extern void state_parent_sensor_learn_start_rx_ack_msg(void);
/**
 * ACK_MSG received from child sensor
 */
extern void state_parent_sensor_learn_rx_ack_msg(void);
/**
 * Start RF TX Mode and send UD_MSG to parent sensor
 */
extern void state_parent_sensor_learn_tx_ud_msg(void);
/**
 * Start RF RX mode to received ACK_MSG from parent sensor
 */
extern void state_parent_sensor_learn_start_rx_ack_msg_ud(void);
/**
 * ACK_MSG received from parent sensor
 */
extern void state_parent_sensor_learn_rx_ack_msg_ud(void);


/** \todo send ud msg to parent instead of keep alive */

/* Reset Device ID (can only entered in Parent Learn Mode)*/
/**
 * Check if Reset Device ID sequence is triggered (Button press during learn)
 */
extern void check_reset_device_id(void);
/**
 * Reset Device ID of the sensor
 */
extern void state_reset_device_id(void);


#ifdef	__cplusplus
}
#endif

#endif	/* PARENT_LEARN_H */

