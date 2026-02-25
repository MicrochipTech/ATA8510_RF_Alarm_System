#include "wrap_thunk.h"

void __attribute__((naked, used))
thunk_void_void() {
  __asm ( CODE_SAVE_REGS \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_uint8_void() {
  __asm ( CODE_SAVE_REGS \
         "icall\r\n" \
         "mov r24, r16\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_uint16_void() {
  __asm ( CODE_SAVE_REGS \
         "icall\r\n" \
         "mov r24, r16\r\n" \
         "mov r25, r17\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_uint8_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r22\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_uint8_uint8_uint8_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r22\r\n"  \
         "mov  r18, r20\r\n"  \
         "icall\r\n" \
         "mov r24, r16\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_uint8_ptr() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "icall\r\n" \
         "mov r24, r16\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_ptr_ptr() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "mov  r19, r23\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_ptr() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_ptr_ptr_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "mov  r19, r23\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_uint8_ptr_ptr_ptr() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "mov  r19, r23\r\n"  \
         "icall\r\n" \
         "mov  r24, r16\r\n"
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_ptr_ptr_ptr() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "mov  r19, r23\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_ptr_ptr_ptr_ptr() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r22\r\n"  \
         "mov  r22, r18\r\n"  \
         "mov  r18, r16\r\n"  \
         "mov  r16, r23\r\n"  \
         "mov  r23, r19\r\n"  \
         "mov  r19, r16\r\n"  \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_ptr_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_void_ptr_uint8_ptr() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "mov  r19, r23\r\n"  \
         "icall\r\n" \
          CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_uint16_uint8_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r22\r\n"  \
         "icall\r\n" \
		 "mov r24, r16\r\n" \
         "mov r25, r17\r\n" \
		  CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_int16_int8_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r22\r\n"  \
         "icall\r\n" \
		 "mov r24, r16\r\n" \
         "mov r25, r17\r\n" \
		  CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_uint32_uint16_uint16() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "mov  r19, r23\r\n"  \
         "icall\r\n" \
         "mov r24, r16\r\n" \
         "mov r25, r17\r\n" \
		 "mov r22, r18\r\n" \
		 "mov r23, r19\r\n" \
		  CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_int32_int16_int16() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "mov  r19, r23\r\n"  \
         "icall\r\n" \
         "mov r24, r16\r\n" \
         "mov r25, r17\r\n" \
		 "mov r22, r18\r\n" \
		 "mov r23, r19\r\n" \
		  CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_int32_int32_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "mov  r19, r23\r\n"  \
         "icall\r\n" \
         "mov r24, r16\r\n" \
         "mov r25, r17\r\n" \
		 "mov r22, r18\r\n" \
		 "mov r23, r19\r\n" \
		  CODE_RESTORE_REGS_AND_RET); \
}

void __attribute__((naked, used))
thunk_int16_int16_uint8() {
  __asm ( CODE_SAVE_REGS \
         "mov  r16, r24\r\n"  \
         "mov  r17, r25\r\n"  \
         "mov  r18, r22\r\n"  \
         "icall\r\n" \
         "mov r24, r16\r\n" \
         "mov r25, r17\r\n" \
		  CODE_RESTORE_REGS_AND_RET); \
}

