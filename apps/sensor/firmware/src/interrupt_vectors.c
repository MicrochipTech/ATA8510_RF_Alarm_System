/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/interrupt_vectors.c $
  $LastChangedRevision: 660661 $
  $LastChangedDate: 2022-04-25 14:52:31 +0200 (Mo, 25 Apr 2022) $
  $LastChangedBy: gwillbol $
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/** \file interrupt_vectors.c
*/

/*===========================================================================*/
/*  INCLUDES                                                                 */
/*===========================================================================*/
#include "ata8510_curiosity.h"


/*===========================================================================*/
/*  DEFINES                                                                  */
/*===========================================================================*/
/*===========================================================================*/
/*  Modul Globals                                                             */
/*===========================================================================*/
/*===========================================================================*/
/*  IMPLEMENTATION                                                           */
/*===========================================================================*/
/**
 * Interrupt Vector Table
 */
__attribute__((naked,section(".interrupt_vectors"))) void start(void) {
    asm(".global __vector_default");
    asm("__vector_default:");
    asm(".org 0");
    asm("jmp    __init");
    /* external interrupt request 0 */
    asm(".org 4");
    asm("jmp    API_interrupt0Handler_ASM");
    /* external interrupt request 1 */
    asm(".org 8");
    asm("JMP     API_interrupt1Handler_ASM");
    /* pin change interrupt request 0 */
    asm(".org 12");
    asm("JMP     API_pinChangeInterrupt0Handler_ASM");
    /* pin change interrupt request 1 */
    asm(".org 16");
    asm("JMP     API_pinChangeInterrupt1Handler_ASM");
    /* voltage monitoring interrupt */
    asm(".org 20");
    asm("JMP     XC8_lowBatt_C");
    /* avcc reset interrupt */
    asm(".org 24");
    asm("JMP     XC8_avccReset_C");
    /* avcc low interrupt */
    asm(".org 28");
    asm("JMP     XC8_avccLow_C");
    /* timer 0 interval interrupt */
    asm(".org 32");
    asm("RETI");
    /* timer/counter 1 compare match interrupt */
    asm(".org 36");
    asm("JMP     API_timer1ComIntHandler_ASM");
    /* timer/counter 1 overflow interrupt */
    asm(".org 40");
    asm("JMP     API_timer1OvfIntHandler_ASM");
    /* timer/counter 2 compare match interrupt */
    asm(".org 44");
    asm("JMP     API_timer2ComIntHandler_ASM");
    /* timer/counter 2 overflow interrupt */
    asm(".org 48");
    asm("JMP     API_timer2OvfIntHandler_ASM");
    /* timer/counter 3 capture event interrupt */
    asm(".org 52");
    asm("JMP     API_timer3CapIntHandler_ASM");
    /* timer/counter 3 compare match interrupt */
    asm(".org 56");
    asm("JMP     API_timer3ComIntHandler_ASM");
    /* timer/counter 3 overflow interrupt */
    asm(".org 60");
    asm("JMP     API_timer3OvfIntHandler_ASM");
    /* timer/counter 4 capture event interrupt */
    asm(".org 64");
    asm("RETI");    // asm("JMP     API_timer4CapIntHandler_ASM");
    /* timer/counter 4 compare match interrupt */
    asm(".org 68");
    asm("JMP  XC8_Timer4CompareInterrupt_C");    // asm("JMP     API_timer4ComIntHandler_ASM");
    /* timer/counter 4 overflow interrupt */
    asm(".org 72");
    asm("RETI");    // asm("JMP     API_timer4OvfIntHandler_ASM");
    /* timer/counter 5 compare match interrupt */
    asm(".org 76");
    asm("JMP     API_timer5ComIntHandler_ASM");
    /* timer/counter 5 overflow interrupt */
    asm(".org 80");
    asm("JMP     API_timer5OvfIntHandler_ASM");
    /* spi serial transfer complete interrupt */
    asm(".org 84");
    asm("JMP     API_spiSerialTransferCompleteHandler_ASM");
    /* SPI Rx Buffer Interrupt */
    asm(".org 88");
    asm("JMP     API_spiRxBufferHandler_ASM");
    /* SPI Tx Buffer Interrupt */
    asm(".org 92");
    asm("JMP     API_spiTxBufferHandler_ASM");
    /* Sequencer State Machine Interrupt */
    asm(".org 96");
    asm("JMP   XC8_ssmInterrupt_C");
    /* DATA FIFO fill level reached interrupt */
    asm(".org 100");
    asm("JMP API_dataFifoFillLevelReached_ASM");
    /* DATA FIFO overflow or underflow error interrupt */
    asm(".org 104");
    asm("JMP API_dataFifoOverUnderFlowHandler_ASM");
    /* RSSI/Preamble FIFO fill level reached interrupt */
    asm(".org 108");
    asm("JMP API_rssiPreambleFifoFillLevelReached_ASM");
    /* RSSI/Preamble FIFO overflow or underflow error interrupt */
    asm(".org 112");
    asm("JMP API_rssiPreambleFifoOverUnderFlowHandler_ASM");
    /* Tx Modulator Telegram Finish interrupt */
    asm(".org 116");
    asm("JMP API_TxModulatorTelegramFinish_ASM");
    /* UHF receiver wake check ok on rx path B */
    asm(".org 120");
    asm("JMP API_wakeCheckOkPathB_ASM");
    /* UHF receiver wake check ok on rx path A */
    asm(".org 124");
    asm("JMP API_wakeCheckOkPathA_ASM");
    /* UHF receiver start of telegram ok on rx path B */
    asm(".org 128");
    asm("JMP API_startOfTelegramPathB_ASM");
    /* UHF receiver start of telegram ok on rx path A */
    asm(".org 132");
    asm("JMP API_startOfTelegramPathA_ASM");
    /* UHF receiver end of telegram on rx path B */
    asm(".org 136");
    asm("JMP API_endOfTelegramPathB_ASM");
    /* UHF receiver end of telegram on rx path A */
    asm(".org 140");
    asm("JMP API_endOfTelegramPathA_ASM");
    /* UHF receiver new bit on rx path B */
    asm(".org 144");
    asm("RETI");
    /* UHF receiver new bit on rx path A */
    asm(".org 148");
    asm("RETI");
    /* External input Clock Monitor Interrupt */
    asm(".org 152");
    asm("RETI");
    /* EEPROM Ready Interrupt */
    asm(".org 156");
    asm("RETI");
    /* Store Program Memory Ready Interrupt */
    asm(".org 160");
    asm("RETI");
    /* IDscan buffer full level reached interrupt */
    asm(".org 164");
    asm("JMP XC8_IDscanBufferFullInterrupt_C");
}

/**
 * Pin Change Interrupt 1 Service Routine
 * sets ::status.pin_change1_int flag
 * needed to trigger state machine when button is pressed
 */
void __interrupt(PCI1_vect_num) XC8_pinChange1_C(void) {
    app_data.status.pin_change1_int = 1;
}

/**
 * LOW Batt Interrupt Service Routine
 */
void __interrupt(VMON_vect_num) XC8_lowBatt_C(void) {
    VMCSR &= (uint8_t)~(1 << VMIM);

    events_system |= BM_EVENTS_SYSTEM_LOWBATT;

    if (events.sysEventMask & BM_SYS_EVENT_CONFIG_LOWBATT) {
        API_setEventPin_ASM();
    }    
}

/**
 * AVCC Reset Interrupt Service Routine
 */
void __interrupt(AVCCR_vect_num) XC8_avccReset_C(void) {
    SUPCR &= (uint8_t)~(1 << AVCCRM);
}
        
/**
 * AVCC Low Interrupt Service Routine
 */
void __interrupt(AVCCL_vect_num) XC8_avccLow_C(void) {
    SUPCR &= (uint8_t)~(1 << AVCCLM);

    events_system |= BM_EVENTS_SYSTEM_AVCCLOW;

    sysStatus |= BM_SYS_STATUS_AVCCLOW;

    if (events.sysEventMask & BM_SYS_EVENT_CONFIG_AVCCLOW) {
        API_setEventPin_ASM();
    }

    if ((trxConf.systemModeConfig & BM_SYS_MODE_CONFIG_OPM) == OPM_TX ) {
        debug.errorCode = DEBUG_ERROR_CODE_AVCCLOW_DURING_TX;
        debug.ssmErrorCode = 0U;
        API_setSystemError_ASM();
    }    
}

/**
 * SSM Ready Interrupt Service Routine
 */
void __interrupt(SSM_vect_num) XC8_ssmInterrupt_C(void) {
    sysStatus |= ( BM_SYS_STATUS_TRIGGER_MAIN_LOOP | BM_SYS_STATUS_SSMRDY );
}

/**
 * ID Scan Buffer Full Interrupt Service Routine
 */
void __interrupt(IDFULL_vect_num) XC8_IDscanBufferFullInterrupt_C(void) {
    sysStatus            |= BM_SYS_STATUS_TRIGGER_MAIN_LOOP;
    trxConf.idScanStatus |= BM_SYS_ID_SCAN_STATUS_BUF_FULL;    
}

/**
 * Timer4 Compare Interrupt Service Routine
 * sets ::status.t4_comp_int flag
 */
void __interrupt(T4COMP_vect_num) XC8_Timer4CompareInterrupt_C(void) {
    app_data.status.t4_comp_int = 1;
}