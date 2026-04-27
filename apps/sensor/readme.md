# ATA8510_RF_Alarm_System - Sensor Device <!-- omit in toc -->

<img src="images/IoT-Made-Easy-Logo.png" width=100>

> "IoT Made Easy!" - This application example demonstrates a scalable tree-based wireless network using the ATA8510 RF MCU to enable a reliable alarm system deployments with a large number of nodes.

Devices: **| ATA8510 |**<br>
Features: **| RF network topology |**

[Back to Main page](../../README.md)

## ⚠ Disclaimer <!-- omit in toc -->

<b>
THE SOFTWARE ARE PROVIDED "AS IS" AND GIVE A PATH FOR SELF-SUPPORT AND SELF-MAINTENANCE. This repository contains example code intended to help accelerate client product development.  
<br>
<br>
For additional Microchip repos, see: <a href="https://github.com/Microchip-MPLAB-Harmony" target="_blank">https://github.com/Microchip-MPLAB-Harmony</a>
<br>
Checkout the <a href="https://microchipsupport.force.com/s/" target="_blank">Technical support portal</a> to access our knowledge base, community forums or submit support ticket requests.
</b>

## Contents<!-- omit in toc -->
- [Introduction](#introduction)
- [Bill of Materials](#bill-of-materials)
- [Hardware Setup](#hardware-setup)
- [Software Setup](#software-setup)
  - [Development Tools](#development-tools)
- [Overview](#overview)
  - [OFF Mode](#off-mode)
  - [Alarm](#alarm)
  - [Keep-Alive](#keep-alive)
  - [Learn](#learn)
    - [Child Learn](#child-learn)
    - [Parent Learn](#parent-learn)
  - [Reset Device Id](#reset-device-id)
  - [Sensor configuration](#sensor-configuration)
- [Board Programming](#board-programming)
  - [Connection setup](#connection-setup)
  - [Program the precompiled hex file using MPLAB X IPE](#program-the-precompiled-hex-file-using-mplab-x-ipe)
  - [Build and program the application using MPLAB X IDE](#build-and-program-the-application-using-mplab-x-ide)
  - [EEPROM programming](#eeprom-programming)
- [Related links](#related-links)

## Introduction

The Sensor Device is a battery‑powered node in the RF alarm system, designed to detect local events—such as motion or smoke—and report them to the Central Device. Multiple sensors can be deployed throughout a commercial building, forming a scalable tree‑topology network that ensures robust coverage. Each sensor communicates wirelessly with its parent node or directly with the central unit, enabling fast event reporting, enrollment, and status updates across the entire system.

[TOP](#contents)

## Bill of Materials

| TOOLS | QUANTITY |
| :-    | :-       |
| [ATA8510 Curiosity Board](https://www.microchip.com/en-us/development-tool/ev82m22a) | 2 - 5 |
| [Atmel-ICE](https://www.microchip.com/en-us/development-tool/atatmel-ice) or [Power Debugger](https://www.microchip.com/en-us/development-tool/atpowerdebugger) or [PICkit5](https://www.microchip.com/en-us/development-tool/pg164150) | 1 |

[TOP](#contents)

## Hardware Setup

1. Power up the ATA8510 Curiosity Board by connecting a USB Type‑C cable to connector J201
2. Please set the jumper as illustrated in the image below for a 3.3V application

<img src="images/sensor_device.png" height="400">

[TOP](#contents)

## Software Setup

### Development Tools

- <a href="https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide" target="_blank">MPLAB® X IDE v6.25</a> or above
- MPLAB® X IDE plug-ins: MPLAB® Code Configurator (MCC) v5.6.4 and above
- MPLAB® XC32 C/C++ Compiler v5.00
- <a href="https://developerhelp.microchip.com/xwiki/bin/view/software-tools/ipe/installation/" target="_blank">MPLAB® X IPE</a>

[TOP](#contents)

## Overview
This section provides an overview of the sensor application, which is based on the ATA8510 Curiosity Board. It describes the main functions, operational modes, and interactions of the sensor within the network. The section also explains how the sensor device communicates with the central device and other sensors, manages status updates, and responds to events such as pairing and alarms.

The sensor application operates as a state machine with the following states:

- OffMode
- Alarm
- Keep Alive
- Learn including sub states
  - Child Learn
  - Parent Learn
  - Reset Device ID

These states and their transitions are shown in the diagram below.

<img src="images/sensor_state_overview.png" width=1200>

__Button Control__  
These states can be entered using the two buttons on the ATA8510 Curiosity Board. The sensor device, based on the ATA8510 Curiosity Board, includes two buttons for control:

- __Reset Button__
- __User Button__

The following button sequences are implemented:

Button Sequence                               | Function
--                                            |--
Reset Button Pressed                          | Reset Sensor Device
Reset Button + User Button Pressed            | Enter Learn Mode
User Button Pressed during Learn Mode         | Reset Sensor Device ID
User Button Pressed during Idle and Keep Alive| Set Alarm

These button combinations allow users to easily reset the sensor, trigger an alarm, or initiate the learning process.

__LED Signalling__

The two on‑board user LEDs indicate the application’s operating states.

Component | Description     | Pin on ATA8510 RF board
--        |--               |--
D100      | 3.3V Green LED  | -
D101      | 5V Green LED    | -
D102      | User Red LED, <br>__LED on If RX is Active otherwise off__    | PB7
D103      | User Green LED, <br>__Alarm on if LED on, otherwise Alarm off__  | PC5

<img src="images/ata8510_led.png" height="600"/> <br>

### OFF Mode
If the sensor device is inactive, it remains in an off mode to conserve power. The device can be reactivated through button presses or scheduled timer events to enter alarm, keep-alive, or learning states.

### Alarm
When the device is awakened by pressing the user button, it enters the alarm state. In this state, the sensor behaves the same as in the keep-alive mode; however, the alarm status flag is set, and the sensor includes this information in the keep-alive message (KA_MSG).

### Keep-Alive

This chapter introduces the child sensor keep-alive state machine and explains how the sensor device manages periodic status updates, maintains communication with its parent device, and ensures reliable presence detection within the network.
During keep-alive processing, the sensor first handles keep-alive messages from its child sensors. After all child sensors have been processed, the device then processes keep-alive communication with the parent device.

The main states and their functions are as follows:
- __STATE_KA_CF__: Initial state of keep alive state machine
- __STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG__: KA_MSG of child device received
- __STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG__: Create TX_ACK message and send to child sensor
- __STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG_COMPLETE__: Sending TX_ACK message completed
- __STATE_KA_CF_TX_KA_MSG__: send KA_MSG
- __STATE_KA_CF_START_RX_ACK__: start RF RX
- __STATE_KA_CF_RX_ACK__: ACK_MSG received
- __STATE_KA_CF_SLEEP__:  keep alive message handling completed, enter sleep/off mode

This state machine ensures that each sensor maintains regular communication, processes messages from child sensors, and efficiently manages power consumption by entering sleep mode when appropriate.

<img src="images/sensor_keep_alive_states.png"/>  
  
State                                           | State Machine Function
--                                              |--
STATE_KA_CF                                     | state_ka_cf
STATE_KA_CF_PROCESS_CHILD_RX_KA_MSG             | state_ka_cf_process_child_rx_ka_msg
STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG            | state_ka_cf_process_child_tx_ack_msg
STATE_KA_CF_PROCESS_CHILD_TX_ACK_MSG_COMPLETE   | state_ka_cf_process_child_tx_ack_msg_complete
STATE_KA_CF_TX_KA_MSG                           | state_ka_cf_tx_ka_msg
STATE_KA_CF_START_RX_ACK                        | state_ka_cf_start_rx_ack
STATE_KA_CF_RX_ACK                              | state_ka_cf_rx_ack
STATE_KA_CF_SLEEP                               | state_ka_cf_sleep

### Learn
The sensor learning process is managed by two dedicated state machines: one for child learning and one for parent learning. In child learning, the sensor is added to the network as a new device. In parent learning, the sensor is already part of the network and facilitates the addition of a child sensor.

<img src="images/learn_c_s1_s11.png"/>  

#### Child Learn
This chapter describes the child learning process, detailing how a sensor device is added to the network as a new node through a dedicated state machine and specific pairing procedures. The child learning state machine guides this process with the following states:

- __STATE_CHILD_SENSOR_LEARN_TX_PART_REQ:__ Sends the PART_REQ command to the parent device to initiate pairing.
- __STATE_CHILD_SENSOR_LEARN_START_RX_PART_REQ_RESP:__ Starts RF receive mode to wait for the PART_REQ_RESP message from the parent.
- __STATE_CHILD_SENSOR_LEARN_RX_PART_REQ_RESP:__ Receives the PART_REQ_RESP message and restarts RF receive mode for further communication.
- __STATE_CHILD_SENSOR_LEARN_RX_CON_VER_STAT:__ Receives the CON_VER_STAT message, indicating the connection verification status.
- __STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG:__ Creates an ACK_MSG and starts RF transmission to acknowledge receipt.
- __STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG_COMPLETE:__ Completes the transmission of the ACK_MSG.

This sequence ensures secure and reliable integration of the sensor device into the network.

<img src="images/sensor_child_learn_states.png"/>

State                                           | State Machine Function
--                                              |--
STATE_CHILD_SENSOR_LEARN_TX_PART_REQ            | state_child_sensor_learn_tx_part_req
STATE_CHILD_SENSOR_LEARN_START_RX_PART_REQ_RESP | state_child_sensor_learn_start_rx_part_req_resp
STATE_CHILD_SENSOR_LEARN_RX_PART_REQ_RESP       | state_child_sensor_learn_rx_part_req_resp
STATE_CHILD_SENSOR_LEARN_RX_CON_VER_STAT        | state_child_sensor_learn_rx_con_ver_stat
STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG             | state_child_sensor_learn_tx_ack_msg
STATE_CHILD_SENSOR_LEARN_TX_ACK_MSG_COMPLETE    | state_child_sensor_learn_tx_ack_msg_complete

#### Parent Learn
This chapter explains the parent learning process, in which a sensor device that is already part of the network facilitates the addition of a new child sensor through a dedicated state machine and defined communication steps. The parent learning state machine includes the following states:

- __STATE_PARENT_LEARN_START_RX_PART_REQ:__ Start RF receive mode to receive the PART_REQ message from the child sensor.
- __STATE_PARENT_LEARN_RX_PART_REQ:__ PART_REQ message received from the child sensor.
- __STATE_PARENT_LEARN_TX_CON_VER_REQ:__ Start RF transmit mode and send the CON_VER_REQ message to the parent sensor.
- __STATE_PARENT_LEARN_START_RX_CON_VER_RESP:__ Start RF receive mode to receive the CON_VER_RESP message from the parent sensor.
- __STATE_PARENT_LEARN_RX_CON_VER_RESP:__ CON_VER_RESP message received from the parent sensor.
- __STATE_PARENT_LEARN_TX_PART_REQ_RESP:__ Start RF transmit mode and send the PART_REQ_RESP message to the child sensor.
- __STATE_PARENT_LEARN_TX_CON_VER_STAT:__ Start RF transmit mode and send the CON_VER_STAT message to the child sensor.
- __STATE_PARENT_LEARN_START_RX_ACK_MSG:__ Start RF receive mode to receive the ACK_MSG from the child sensor.
- __STATE_PARENT_LEARN_RX_ACK_MSG:__ ACK_MSG received from the child sensor.
- __STATE_PARENT_LEARN_TX_UD_MSG:__ Start RF transmit mode and send the UD_MSG to the parent sensor.
- __STATE_PARENT_LEARN_START_RX_ACK_MSG_UD:__ Start RF receive mode to receive the ACK_MSG from the parent sensor.
- __STATE_PARENT_LEARN_RX_ACK_MSG_UD:__ ACK_MSG received from the parent sensor.

This sequence ensures that the parent sensor manages the integration of a new child sensor efficiently and reliably within the network.

<img src="images/sensor_parent_learn_states.png"/>

State                                    | State Machine Function
--                                       |--
STATE_PARENT_LEARN_START_RX_PART_REQ     | state_parent_sensor_learn_start_rx_part_req
STATE_PARENT_LEARN_RX_PART_REQ           | state_parent_sensor_learn_rx_part_req
STATE_PARENT_LEARN_TX_CON_VER_REQ        | state_parent_sensor_learn_tx_con_ver_req
STATE_PARENT_LEARN_START_RX_CON_VER_RESP | state_parent_sensor_learn_start_rx_con_ver_resp
STATE_PARENT_LEARN_RX_CON_VER_RESP       | state_parent_sensor_learn_rx_con_ver_resp
STATE_PARENT_LEARN_TX_PART_REQ_RESP      | state_parent_sensor_learn_tx_part_req_resp
STATE_PARENT_LEARN_TX_CON_VER_STAT       | state_parent_sensor_learn_tx_con_ver_stat
STATE_PARENT_LEARN_START_RX_ACK_MSG      | state_parent_sensor_learn_start_rx_ack_msg
STATE_PARENT_LEARN_RX_ACK_MSG            | state_parent_sensor_learn_rx_ack_msg
STATE_PARENT_LEARN_TX_UD_MSG             | state_parent_sensor_learn_tx_ud_msg
STATE_PARENT_LEARN_START_RX_ACK_MSG_UD   | state_parent_sensor_learn_start_rx_ack_msg_ud
STATE_PARENT_LEARN_RX_ACK_MSG_UD         | state_parent_sensor_learn_rx_ack_msg_ud

### Reset Device Id

__See also__  
[Removing a Sensor from the Network](/apps/README.md#removing-a-sensor-from-the-network)

### Sensor configuration

The sensor configuration is stored in SRAM of RTC device starting at address 0x20.
RTC SRAM Address| Variable                          | Description
--              |--                                 |-- 
0x20..0x21      | app_data.device_id                | 16-bit Device-ID, see sAppData_T.device_id
0x22..0x23      | app_data.parent_id                | 16-bit Device-ID of the parent device, see sAppData_T.parent_id
0x24..0x25      | app_data.child_id[0]              | 16-bit Device-ID of the child id #0, see sAppData_T.child_id
0x26..0x27      | app_data.child_id[1]              | 16-bit Device-ID of the child id #1, see sAppData_T.child_id
0x28..0x29      | app_data.child_id[2]              | 16-bit Device-ID of the child id #2, see sAppData_T.child_id
0x2A..0x2B      | app_data.child_id[3]              | 16-bit Device-ID of the child id #3, see sAppData_T.child_id
0x2C..0x2D      | app_data.child_id[4]              | 16-bit Device-ID of the child id #4, see sAppData_T.child_id
0x2E            | app_data.service_channel_config   | 8-bit SvcCh configuration used for RF communication
0x2F            | app_data.status                   | 8-bit sensor status
0x30            | app_data.count                    | 8-bit keep-alive counter (modulo 10)

Default setting is stored in EEPROM of ATA8510 starting at address 0x2B0. Default setting is applied when resetting the sensor device id.

EEPROM Address  | Variable                          | Value
--              |--                                 |-- 
0x2B0..0x2B1    | fac_data.device_id                | 0xFFFF
0x2B2..0x2B3    | fac_data.parent_id                | 0xFFFF
0x2B4..0x2B5    | fac_data.child_id[0]              | 0xFFFF
0x2B6..0x2B7    | fac_data.child_id[1]              | 0xFFFF
0x2B8..0x2B9    | fac_data.child_id[2]              | 0xFFFF
0x2BA..0x2BB    | fac_data.child_id[3]              | 0xFFFF
0x2BC..0x2BD    | fac_data.child_id[4]              | 0xFFFF
0x2BE           | fac_data.service_channel_config   | 0x40
0x2BF           | fac_data.status                   | 0x00
0x2C0           | fac_data.count                    | 0x00

[TOP](#contents)

## Board Programming

### Connection setup

- Connect the external debugger to the ISP header (J104)
- Ensure that the jumper is placed on header J103 between pins 1 and 2 during programming

<img src="images/ata8510_atsamice.jpg" width=600>

### Program the precompiled hex file using MPLAB X IPE

* The precompiled HEX file `ata8510_curiosity.X.production.hex` is provided in the hex folder. Follow the steps in the linked guide to <a href="https://developerhelp.microchip.com/xwiki/bin/view/software-tools/ipe/production-mode/program-device/" target="_blank">program this precompiled image using MPLAB X IPE</a>.

### Build and program the application using MPLAB X IDE

The application folder is located at the following path.

**Path: apps\sensor\firmware\ata8510_curiosity.X"**

Follow the steps in the linked guide to <a href="https://developerhelp.microchip.com/xwiki/bin/view/software-tools/ides/x/projects/building/" target="_blank">build and program the application</a>.

### EEPROM programming

1. Place the EEPROM hex file (ATA8510_EEPROM.hex) in the project directory (ata8510_curiosity.X).
2. Make a copy of the EEPROM hex file, rename it (for example, ATA8510_EEPROM_offset.hex) and place it in the same project directory.
3. Within the “Building” category of the “Project Properties” window, add the following to the “Execute this line before build” box (ensure that the check box is enabled): 

 `hexmate r0-3ffs810000,ATA8510_EEPROM.hex -oATA8510_EEPROM_offset.hex`

<img src="images/project_building_properties.png" width="700">

4. Within the “Loading” category of the “Project Properties” window, click the “Add Loadable File…” button, then add the renamed copy of the EEPROM hex file (ATA8510_EEPROM_offset.hex).

<img src="images/project_loading_properties.png" width="700">

5. Within the “Atmel-ICE” category of the “Project Properties” window, ensure that the “Preserve Data Flash”
checkbox is disabled.

<img src="images/project_atmelice_properties.png" width="700">

As a result, an additional hex file ( `ata8510_curiosity.X.production.unified.hex`) is generated and available after building the project. <br>
This hex files includes the firmware and the EEPROM settings. It can be programmed as shown in [chapter Program the precompiled hex file using MPLAB X IPE](#program-the-precompiled-hex-file-using-mplab-x-ipe).

## Related links

- [ATA8510 Curiosity Board](https://www.microchip.com/en-us/development-tool/ev82m22a)
- [ATA8510 Curiosity Board User Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/WSG/ProductDocuments/UserGuides/ATA8510-Curiosity-Board-User%27s-Guide-DS00006071.pdf)

[TOP](#contents)