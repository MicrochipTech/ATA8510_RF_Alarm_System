/*lint -e9059 */
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  $URL: http://svnservulm.corp.atmel.com/svn/CDB/Apps/Apps_SW/Trunk/SW_Projects/XC8/ATA8510_FLASH_XC8/src/wrap_thunk.h $
  $LastChangedRevision: 660705 $
  $LastChangedDate: 2022-04-26 08:54:34 +0200 (Di, 26 Apr 2022) $
  $LastChangedBy: gwillbol $
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/*lint -restore */

#ifndef WRAP_THUNK_H
#define WRAP_THUNK_H
/*==================================================*/
/*  INCLUDES                                        */
/*==================================================*/
#include "ata8510_curiosity.h"
#include <stdint.h>

/*==================================================*/
/*  DEFINES                                         */
/*==================================================*/

#define CODE_SAVE_REGS \
    "push r2\r\n" \
    "push r3\r\n" \
    "push r16\r\n" \
    "push r17\r\n" \
    "push r28\r\n" \
    "push r29\r\n" \
    "ldi r28, lo8(cstack+0x1F)\r\n" \
    "ldi r29, hi8(cstack+0x1F)\r\n"

#define CODE_RESTORE_REGS_AND_RET \
    "clr r1\r\n" \
    "pop r29\r\n" \
    "pop r28\r\n" \
    "pop r17\r\n" \
    "pop r16\r\n" \
    "pop r3\r\n" \
    "pop r2\r\n" \
    "ret\r\n"

#define CODE_JUMP(func, thunk)              \
    "ldi r30, lo8(gs(__real_"#func "))\r\n" \
    "ldi r31, hi8(gs(__real_"#func "))\r\n" \
    "jmp "#thunk "\r\n"

/*==================================================*/
/*  TYPE DEFINITIONS                                */
/*==================================================*/

/*==================================================*/
/*  GLOBALS (VARIABLES)                             */
/*==================================================*/

/*==================================================*/
/*  GLOBALS (FUNCTIONS)                             */
/*==================================================*/

extern void thunk_void_void();
extern void thunk_uint8_void();
extern void thunk_uint16_void();
extern void thunk_void_uint8();
extern void thunk_void_uint8_uint8();
extern void thunk_uint8_uint8_uint8_uint8();
extern void thunk_uint8_ptr();
extern void thunk_void_ptr();
extern void thunk_void_ptr_ptr();
extern void thunk_void_ptr_ptr_uint8();
extern void thunk_uint8_ptr_ptr_ptr();
extern void thunk_void_ptr_ptr_ptr();
extern void thunk_void_ptr_ptr_ptr_ptr();
extern void thunk_void_ptr_uint8();
extern void thunk_void_ptr_uint8_ptr();
extern void thunk_uint16_uint8_uint8();
extern void thunk_int16_int8_uint8();
extern void thunk_uint32_uint16_uint16();
extern void thunk_int32_int16_int16();
extern void thunk_int32_int32_uint8();
extern void thunk_int16_int16_uint8();

#endif /* WRAP_THUNK_H */