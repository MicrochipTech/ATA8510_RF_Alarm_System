; .global ATA_rfShutDownRf_C
; .type ATA_rfShutDownRf_C, @function
; ATA_rfShutDownRf_C:
; 	; Clobber r16 and r17
; 	ldi r16, 0x50
; 	ldi r17, 0x70
; 	ret
;
; .global ATA_systemWait4SSMrdy_C
; .type ATA_systemWait4SSMrdy_C, @function
; ATA_systemWait4SSMrdy_C:
;     ; Check if r16 and r17 hold correct args
; 	cpi r16, 0x2
; 	brne 1f
; 	cpi r17, 0x3
; 	brne 1f
; 	; Clobber r16. 17, 24 and Y
;     ldi r16, 0x50
;     ldi r17, 0x70
;     ldi r24, 0x80
;     ldi r28, 0x90
;     ldi r29, 0xa0
; 	ret
; 1:
; 	call abort
;
; .global ATA_rfGapMode_C
; .type ATA_rfGapMode_C, @function
; ATA_rfGapMode_C:
; 	; Clobber r16 and r17
; 	ldi r16, 0x50
; 	ldi r17, 0x70
; 	ret
;
; .global ATA_rfIdScanSubCheck_C
; .type ATA_rfIdScanSubCheck_C, @function
; ATA_rfIdScanSubCheck_C:
;     ;;  Clobber r14
;     mov r14, r28
;     cpi r16, lo8(dummy)
;     brne 1f
;     cpi r17, hi8(dummy)
;     brne 1f
;     mov r30, r16
;     mov r31, r17
;     ldi r16, 0xDE
;     st  Z, r16
; 	ret
; 1:
;     call abort
;
; .global ATA_apiReadRxBuffer_C
; .type ATA_apiReadRxBuffer_C, @function
; ATA_apiReadRxBuffer_C:
;     cpi r16, lo8(dummy)
;     brne 1f
;     cpi r17, hi8(dummy)
;     brne 1f
;     cpi r18, 0xBE
;     brne 1f
;     mov r30, r16
;     mov r31, r17
;     ldi r16, 0xDE
;     st  Z, r16
; 	ret
; 1:
;     call abort
;
; .global ATA_apiWriteTxPreambleBuffer_C
; .type ATA_apiWriteTxPreambleBuffer_C, @function
; ATA_apiWriteTxPreambleBuffer_C:
;     cpi r16, lo8(dummy)
;     brne 1f
;     cpi r17, hi8(dummy)
;     brne 1f
;     cpi r18, 0xBE
;     brne 1f
; 	ret
;     mov r30, r16
;     mov r31, r17
;     ld  r18, Z
;     cpi r18, 0xEF
;     brne 1f
; 1:
;     call abort
;
; .global ATA_apiStartMemoryCheck_C
; .type ATA_apiStartMemoryCheck_C, @function
; ATA_apiStartMemoryCheck_C:
;     cpi r16, lo8(dummy)
;     brne 1f
;     cpi r17, hi8(dummy)
;     brne 1f
;     cpi r18, 0xCD
;     brne 1f
;     cpi r19, 0xAB
;     brne 1f
;     cpi r20, 0xBE
;     brne 1f
;     mov r30, r16
;     mov r31, r17
;     ldi r16, 0xDE
;     st  Z, r16
;     ldi r16, 0xDB               ; return 0xDB
; 	ret
; 1:
;     call abort
;
; .global ATA_apiReadEeprom_C
; .type ATA_apiReadEeprom_C, @function
; ATA_apiReadEeprom_C:
;     ;;  Clobber r14
;     mov r14, r28
;     cpi r16, lo8(dummy)
;     brne 1f
;     cpi r17, hi8(dummy)
;     brne 1f
;     mov r30, r16
;     mov r31, r17
;     ldi r16, 0xDE
;     st  Z, r16
;     ldi r16, 0xDB
; 	ret
; 1:
;     call abort
;
;
; .global ATA_eepWriteNBytes_C
; .type ATA_eepWriteNBytes_C, @function
; ATA_eepWriteNBytes_C:
;     ;;  Clobber r14
;     mov r14, r28
;     cpi r16, lo8(dummy)
;     brne 1f
;     cpi r17, hi8(dummy)
;     brne 1f
;     cpi r18, lo8(dummy2)
;     brne 1f
;     cpi r19, hi8(dummy2)
;     brne 1f
;     cpi r20, 0xCD
;     brne 1f
;     mov r30, r16
;     mov r31, r17
;     ldi r16, 0xDE
;     st  Z, r16
;     mov r30, r18
;     mov r31, r19
;     ldi r16, 0xDF
;     st  Z, r16
; 	ret
; 1:
;     call abort
