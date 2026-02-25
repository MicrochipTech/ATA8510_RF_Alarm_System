;***** THIS IS A MACHINE GENERATED FILE - DO NOT EDIT ********************
;***** Created: 2013-07-22 09:11 ******* Source: ATA5831.xml *************
;*************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;* 
;* Number            : AVR000
;* File Name         : "ATA5831def.inc"
;* Title             : Register/Bit Definitions for the ATA5831
;* Date              : 2013-07-22
;* Version           : 2.25
;* Support E-mail    : avr@atmel.com
;* Target MCU        : ATA5831
;* 
;* DESCRIPTION
;* When including this file in the assembly program file, all I/O register 
;* names and I/O register bit names appearing in the data book can be used.
;* In addition, the six registers forming the three data pointers X, Y and 
;* Z have been assigned names XL - ZH. Highest RAM address for Internal 
;* SRAM is also defined 
;* 
;* The Register names are represented by their hexadecimal address.
;* 
;* The Register Bit names are represented by their bit number (0-7).
;* 
;* Please observe the difference in using the bit names with instructions
;* such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc"
;* (skip if bit in register set/cleared). The following example illustrates
;* this:
;* 
;* in    r16,PORTB             ;read PORTB latch
;* sbr   r16,(1<<PB6)+(1<<PB5) ;set PB6 and PB5 (use masks, not bit#)
;* out   PORTB,r16             ;output to PORTB
;* 
;* in    r16,TIFR              ;read the Timer Interrupt Flag Register
;* sbrc  r16,TOV0              ;test the overflow flag (use bit#)
;* rjmp  TOV0_is_set           ;jump if set
;* ...                         ;otherwise do something else
;*************************************************************************
#ifndef _REGDEF_INC_
#define _REGDEF_INC_
; ***** SPECIFY DEVICE ***************************************************
;.device ATA5831
SIGNATURE_000       EQU 0x1e
SIGNATURE_001       EQU 0x95
SIGNATURE_002       EQU 0x61
; ***** I/O REGISTER DEFINITIONS *****************************************
; NOTE:
; Definitions marked "MEMORY MAPPED"are extended I/O ports
; and cannot be used with IN/OUT instructions
PRR0       EQU 0x01
PRR1       EQU 0x02
PRR2       EQU 0x03
RDPR       EQU 0x04
PINB       EQU 0x05
DDRB       EQU 0x06
PORTB       EQU 0x07
PINC       EQU 0x08
DDRC       EQU 0x09
PORTC       EQU 0x0a
FSCR       EQU 0x0b
RDSIFR       EQU 0x0d
MCUCR       EQU 0x0e
PCIFR       EQU 0x0f
T0CR       EQU 0x10
T1CR       EQU 0x11
T2CR       EQU 0x12
T3CR       EQU 0x13
T4CR       EQU 0x14
T1IFR       EQU 0x15
T2IFR       EQU 0x16
T3IFR       EQU 0x17
T4IFR       EQU 0x18
T5IFR       EQU 0x19
GPIOR0       EQU 0x1a
GPIOR3       EQU 0x1b
GPIOR4       EQU 0x1c
GPIOR5       EQU 0x1d
GPIOR6       EQU 0x1e
EECR       EQU 0x1f
EEDR       EQU 0x20
EEARL       EQU 0x21
EEARH       EQU 0x22
EEPR       EQU 0x23
GPIOR1       EQU 0x24
GPIOR2       EQU 0x25
PCICR       EQU 0x26
EIMSK       EQU 0x27
EIFR       EQU 0x28
CRCDIR       EQU 0x29
VMCSR       EQU 0x2a
MCUSR       EQU 0x2b
SPCR       EQU 0x2c
SPSR       EQU 0x2d
SPDR       EQU 0x2e
T0IFR       EQU 0x2f
DWDR       EQU 0x31
RDCR       EQU 0x33
EOTSA       EQU 0x34
EOTCA       EQU 0x35
EOTSB       EQU 0x36
EOTCB       EQU 0x37
SMCR       EQU 0x38
CMCR       EQU 0x39
CMIMR       EQU 0x3a
CLPR       EQU 0x3b
SPMCSR       EQU 0x3c
SPL       EQU 0x3d
SPH       EQU 0x3e
SREG       EQU 0x3f
FSEN       EQU 0x60       ; MEMORY MAPPED
FSFCR       EQU 0x61       ; MEMORY MAPPED
GACDIVL       EQU 0x62       ; MEMORY MAPPED
GACDIVH       EQU 0x63       ; MEMORY MAPPED
FFREQ1L       EQU 0x64       ; MEMORY MAPPED
FFREQ1M       EQU 0x65       ; MEMORY MAPPED
FFREQ1H       EQU 0x66       ; MEMORY MAPPED
FFREQ2L       EQU 0x67       ; MEMORY MAPPED
FFREQ2M       EQU 0x68       ; MEMORY MAPPED
FFREQ2H       EQU 0x69       ; MEMORY MAPPED
EICRA       EQU 0x6b       ; MEMORY MAPPED
PCMSK0       EQU 0x6c       ; MEMORY MAPPED
PCMSK1       EQU 0x6d       ; MEMORY MAPPED
WDTCR       EQU 0x6e       ; MEMORY MAPPED
T1CNT       EQU 0x6f       ; MEMORY MAPPED
T1COR       EQU 0x70       ; MEMORY MAPPED
T1MR       EQU 0x71       ; MEMORY MAPPED
T1IMR       EQU 0x72       ; MEMORY MAPPED
T2CNT       EQU 0x73       ; MEMORY MAPPED
T2COR       EQU 0x74       ; MEMORY MAPPED
T2MR       EQU 0x75       ; MEMORY MAPPED
T2IMR       EQU 0x76       ; MEMORY MAPPED
T3CNTL       EQU 0x77       ; MEMORY MAPPED
T3CNTH       EQU 0x78       ; MEMORY MAPPED
T3CORL       EQU 0x79       ; MEMORY MAPPED
T3CORH       EQU 0x7a       ; MEMORY MAPPED
T3ICRL       EQU 0x7b       ; MEMORY MAPPED
T3ICRH       EQU 0x7c       ; MEMORY MAPPED
T3MRA       EQU 0x7d       ; MEMORY MAPPED
T3MRB       EQU 0x7e       ; MEMORY MAPPED
T3IMR       EQU 0x7f       ; MEMORY MAPPED
T4CNTL       EQU 0x80       ; MEMORY MAPPED
T4CNTH       EQU 0x81       ; MEMORY MAPPED
T4CORL       EQU 0x82       ; MEMORY MAPPED
T4CORH       EQU 0x83       ; MEMORY MAPPED
T4ICRL       EQU 0x84       ; MEMORY MAPPED
T4ICRH       EQU 0x85       ; MEMORY MAPPED
T4MRA       EQU 0x86       ; MEMORY MAPPED
T4MRB       EQU 0x87       ; MEMORY MAPPED
T4IMR       EQU 0x88       ; MEMORY MAPPED
T5OCRL       EQU 0x8a       ; MEMORY MAPPED
T5OCRH       EQU 0x8b       ; MEMORY MAPPED
T5CCR       EQU 0x8c       ; MEMORY MAPPED
T5CNTL       EQU 0x8d       ; MEMORY MAPPED
T5CNTH       EQU 0x8e       ; MEMORY MAPPED
T5IMR       EQU 0x8f       ; MEMORY MAPPED
GTCCR       EQU 0x90       ; MEMORY MAPPED
SOTSB       EQU 0x91       ; MEMORY MAPPED
SOTSA       EQU 0x92       ; MEMORY MAPPED
SOTCB       EQU 0x93       ; MEMORY MAPPED
SOTCA       EQU 0x94       ; MEMORY MAPPED
TESRB       EQU 0x95       ; MEMORY MAPPED
TESRA       EQU 0x96       ; MEMORY MAPPED
RDSIMR       EQU 0x98       ; MEMORY MAPPED
RDOCR       EQU 0x99       ; MEMORY MAPPED
TEMPL       EQU 0x9b       ; MEMORY MAPPED
TEMPH       EQU 0x9c       ; MEMORY MAPPED
SYCB       EQU 0x9d       ; MEMORY MAPPED
SYCA       EQU 0x9e       ; MEMORY MAPPED
RXFOB       EQU 0x9f       ; MEMORY MAPPED
RXFOA       EQU 0xa0       ; MEMORY MAPPED
DMMB       EQU 0xa1       ; MEMORY MAPPED
DMMA       EQU 0xa2       ; MEMORY MAPPED
DMCDB       EQU 0xa3       ; MEMORY MAPPED
DMCDA       EQU 0xa4       ; MEMORY MAPPED
DMCRB       EQU 0xa5       ; MEMORY MAPPED
DMCRA       EQU 0xa6       ; MEMORY MAPPED
DMDRB       EQU 0xa7       ; MEMORY MAPPED
DMDRA       EQU 0xa8       ; MEMORY MAPPED
CHCR       EQU 0xa9       ; MEMORY MAPPED
CHDN       EQU 0xaa       ; MEMORY MAPPED
SFIDCB       EQU 0xab       ; MEMORY MAPPED
SFIDLB       EQU 0xac       ; MEMORY MAPPED
WUPTB       EQU 0xad       ; MEMORY MAPPED
WUPLB       EQU 0xae       ; MEMORY MAPPED
SFID1B       EQU 0xaf       ; MEMORY MAPPED
SFID2B       EQU 0xb0       ; MEMORY MAPPED
SFID3B       EQU 0xb1       ; MEMORY MAPPED
SFID4B       EQU 0xb2       ; MEMORY MAPPED
WUP1B       EQU 0xb3       ; MEMORY MAPPED
WUP2B       EQU 0xb4       ; MEMORY MAPPED
WUP3B       EQU 0xb5       ; MEMORY MAPPED
WUP4B       EQU 0xb6       ; MEMORY MAPPED
SFIDCA       EQU 0xb7       ; MEMORY MAPPED
SFIDLA       EQU 0xb8       ; MEMORY MAPPED
WUPTA       EQU 0xb9       ; MEMORY MAPPED
WUPLA       EQU 0xba       ; MEMORY MAPPED
SFID1A       EQU 0xbb       ; MEMORY MAPPED
SFID2A       EQU 0xbc       ; MEMORY MAPPED
SFID3A       EQU 0xbd       ; MEMORY MAPPED
SFID4A       EQU 0xbe       ; MEMORY MAPPED
WUP1A       EQU 0xbf       ; MEMORY MAPPED
WUP2A       EQU 0xc0       ; MEMORY MAPPED
WUP3A       EQU 0xc1       ; MEMORY MAPPED
WUP4A       EQU 0xc2       ; MEMORY MAPPED
CLKOD       EQU 0xc3       ; MEMORY MAPPED
CLKOCR       EQU 0xc4       ; MEMORY MAPPED
XFUSE       EQU 0xc5       ; MEMORY MAPPED
SRCCAL       EQU 0xc6       ; MEMORY MAPPED
FRCCAL       EQU 0xc7       ; MEMORY MAPPED
CMSR       EQU 0xc8       ; MEMORY MAPPED
CMOCR       EQU 0xc9       ; MEMORY MAPPED
SUPFR       EQU 0xca       ; MEMORY MAPPED
SUPCR       EQU 0xcb       ; MEMORY MAPPED
SUPCA1       EQU 0xcc       ; MEMORY MAPPED
SUPCA2       EQU 0xcd       ; MEMORY MAPPED
SUPCA3       EQU 0xce       ; MEMORY MAPPED
SUPCA4       EQU 0xcf       ; MEMORY MAPPED
CALRDY       EQU 0xd0       ; MEMORY MAPPED
VMCAL       EQU 0xd1       ; MEMORY MAPPED
DFS       EQU 0xd2       ; MEMORY MAPPED
DFTLL       EQU 0xd3       ; MEMORY MAPPED
DFTLH       EQU 0xd4       ; MEMORY MAPPED
DFL       EQU 0xd5       ; MEMORY MAPPED
DFWP       EQU 0xd6       ; MEMORY MAPPED
DFRP       EQU 0xd7       ; MEMORY MAPPED
DFD       EQU 0xd8       ; MEMORY MAPPED
DFI       EQU 0xd9       ; MEMORY MAPPED
DFC       EQU 0xda       ; MEMORY MAPPED
SFS       EQU 0xdb       ; MEMORY MAPPED
SFL       EQU 0xdc       ; MEMORY MAPPED
SFWP       EQU 0xdd       ; MEMORY MAPPED
SFRP       EQU 0xde       ; MEMORY MAPPED
SFD       EQU 0xdf       ; MEMORY MAPPED
SFI       EQU 0xe0       ; MEMORY MAPPED
SFC       EQU 0xe1       ; MEMORY MAPPED
SSMCR       EQU 0xe2       ; MEMORY MAPPED
SSMRCR       EQU 0xe3       ; MEMORY MAPPED
SSMFBR       EQU 0xe4       ; MEMORY MAPPED
SSMRR       EQU 0xe5       ; MEMORY MAPPED
SSMSR       EQU 0xe6       ; MEMORY MAPPED
SSMIFR       EQU 0xe7       ; MEMORY MAPPED
SSMIMR       EQU 0xe8       ; MEMORY MAPPED
MSMSTR       EQU 0xe9       ; MEMORY MAPPED
SSMSTR       EQU 0xea       ; MEMORY MAPPED
SSMXSR       EQU 0xeb       ; MEMORY MAPPED
MSMCR1       EQU 0xec       ; MEMORY MAPPED
MSMCR2       EQU 0xed       ; MEMORY MAPPED
MSMCR3       EQU 0xee       ; MEMORY MAPPED
MSMCR4       EQU 0xef       ; MEMORY MAPPED
GTCR       EQU 0xf0       ; MEMORY MAPPED
SOTC1A       EQU 0xf1       ; MEMORY MAPPED
SOTC2A       EQU 0xf2       ; MEMORY MAPPED
SOTC1B       EQU 0xf3       ; MEMORY MAPPED
SOTC2B       EQU 0xf4       ; MEMORY MAPPED
EOTC1A       EQU 0xf5       ; MEMORY MAPPED
EOTC2A       EQU 0xf6       ; MEMORY MAPPED
EOTC3A       EQU 0xf7       ; MEMORY MAPPED
EOTC1B       EQU 0xf8       ; MEMORY MAPPED
EOTC2B       EQU 0xf9       ; MEMORY MAPPED
EOTC3B       EQU 0xfa       ; MEMORY MAPPED
WCOTOA       EQU 0xfb       ; MEMORY MAPPED
WCOTOB       EQU 0xfc       ; MEMORY MAPPED
SOTTOA       EQU 0xfd       ; MEMORY MAPPED
SOTTOB       EQU 0xfe       ; MEMORY MAPPED
SSMFCR       EQU 0xff       ; MEMORY MAPPED
FESR       EQU 0x100       ; MEMORY MAPPED
FEEN1       EQU 0x101       ; MEMORY MAPPED
FEEN2       EQU 0x102       ; MEMORY MAPPED
FELNA       EQU 0x103       ; MEMORY MAPPED
FEAT       EQU 0x104       ; MEMORY MAPPED
FEPAC       EQU 0x105       ; MEMORY MAPPED
FEVCT       EQU 0x106       ; MEMORY MAPPED
FEBT       EQU 0x107       ; MEMORY MAPPED
FEMS       EQU 0x108       ; MEMORY MAPPED
FETN4       EQU 0x109       ; MEMORY MAPPED
FECR       EQU 0x10a       ; MEMORY MAPPED
FEVCO       EQU 0x10b       ; MEMORY MAPPED
FEALR       EQU 0x10c       ; MEMORY MAPPED
FEANT       EQU 0x10d       ; MEMORY MAPPED
FEBIA       EQU 0x10e       ; MEMORY MAPPED
TMFSM       EQU 0x120       ; MEMORY MAPPED
TMCRL       EQU 0x121       ; MEMORY MAPPED
TMCRH       EQU 0x122       ; MEMORY MAPPED
TMCSB       EQU 0x123       ; MEMORY MAPPED
TMCIL       EQU 0x124       ; MEMORY MAPPED
TMCIH       EQU 0x125       ; MEMORY MAPPED
TMCPL       EQU 0x126       ; MEMORY MAPPED
TMCPH       EQU 0x127       ; MEMORY MAPPED
TMSHR       EQU 0x128       ; MEMORY MAPPED
TMTLL       EQU 0x129       ; MEMORY MAPPED
TMTLH       EQU 0x12a       ; MEMORY MAPPED
TMSSC       EQU 0x12b       ; MEMORY MAPPED
TMSR       EQU 0x12c       ; MEMORY MAPPED
TMCR2       EQU 0x12d       ; MEMORY MAPPED
TMCR1       EQU 0x12e       ; MEMORY MAPPED
RXBC1       EQU 0x12f       ; MEMORY MAPPED
RXBC2       EQU 0x130       ; MEMORY MAPPED
RXTLLB       EQU 0x131       ; MEMORY MAPPED
RXTLHB       EQU 0x132       ; MEMORY MAPPED
RXCRLB       EQU 0x133       ; MEMORY MAPPED
RXCRHB       EQU 0x134       ; MEMORY MAPPED
RXCSBB       EQU 0x135       ; MEMORY MAPPED
RXCILB       EQU 0x136       ; MEMORY MAPPED
RXCIHB       EQU 0x137       ; MEMORY MAPPED
RXCPLB       EQU 0x138       ; MEMORY MAPPED
RXCPHB       EQU 0x139       ; MEMORY MAPPED
RXDSB       EQU 0x13a       ; MEMORY MAPPED
RXTLLA       EQU 0x13b       ; MEMORY MAPPED
RXTLHA       EQU 0x13c       ; MEMORY MAPPED
RXCRLA       EQU 0x13d       ; MEMORY MAPPED
RXCRHA       EQU 0x13e       ; MEMORY MAPPED
RXCSBA       EQU 0x13f       ; MEMORY MAPPED
RXCILA       EQU 0x140       ; MEMORY MAPPED
RXCIHA       EQU 0x141       ; MEMORY MAPPED
RXCPLA       EQU 0x142       ; MEMORY MAPPED
RXCPHA       EQU 0x143       ; MEMORY MAPPED
RXDSA       EQU 0x144       ; MEMORY MAPPED
CRCCR       EQU 0x145       ; MEMORY MAPPED
CRCDOR       EQU 0x146       ; MEMORY MAPPED
IDB0       EQU 0x147       ; MEMORY MAPPED
IDB1       EQU 0x148       ; MEMORY MAPPED
IDB2       EQU 0x149       ; MEMORY MAPPED
IDB3       EQU 0x14a       ; MEMORY MAPPED
IDC       EQU 0x14b       ; MEMORY MAPPED
IDS       EQU 0x14c       ; MEMORY MAPPED
RSSAV       EQU 0x14d       ; MEMORY MAPPED
RSSPK       EQU 0x14e       ; MEMORY MAPPED
RSSL       EQU 0x14f       ; MEMORY MAPPED
RSSH       EQU 0x150       ; MEMORY MAPPED
RSSC       EQU 0x151       ; MEMORY MAPPED
DBCR       EQU 0x152       ; MEMORY MAPPED
DBTC       EQU 0x153       ; MEMORY MAPPED
DBENB       EQU 0x154       ; MEMORY MAPPED
DBENC       EQU 0x155       ; MEMORY MAPPED
DBGSW       EQU 0x156       ; MEMORY MAPPED
SFFR       EQU 0x157       ; MEMORY MAPPED
SFIR       EQU 0x158       ; MEMORY MAPPED
EECR2       EQU 0x159       ; MEMORY MAPPED
PGMST       EQU 0x15a       ; MEMORY MAPPED
EEST       EQU 0x15b       ; MEMORY MAPPED
RSIFG       EQU 0x15c       ; MEMORY MAPPED
RSLDV       EQU 0x15d       ; MEMORY MAPPED
RSHDV       EQU 0x15e       ; MEMORY MAPPED
RSCOM       EQU 0x15f       ; MEMORY MAPPED
; ***** BIT DEFINITIONS **************************************************
; ***** CHFLT ************************
; CHCR - Channel Filter Configuration Register
BWM0       EQU 0       ; Bandwidth Mode bit 0
BM_BWM0    EQU (1<<BWM0)       

BWM1       EQU 1       ; Bandwidth Mode bit 1
BM_BWM1    EQU (1<<BWM1)       

BWM2       EQU 2       ; Bandwidth Mode bit 2
BM_BWM2    EQU (1<<BWM2)       

BWM3       EQU 3       ; Bandwidth Mode bit 3
BM_BWM3    EQU (1<<BWM3)       

; CHDN - Channel Filter Down Sampling Register
BBDN0       EQU 0       ; Baseband Filter Down Sampling Ratio bit 0
BM_BBDN0    EQU (1<<BBDN0)       

BBDN1       EQU 1       ; Baseband Filter Down Sampling Ratio bit 1
BM_BBDN1    EQU (1<<BBDN1)       

BBDN2       EQU 2       ; Baseband Filter Down Sampling Ratio bit 2
BM_BBDN2    EQU (1<<BBDN2)       

BBDN3       EQU 3       ; Baseband Filter Down Sampling Ratio bit 3
BM_BBDN3    EQU (1<<BBDN3)       

BBDN4       EQU 4       ; Baseband Filter Down Sampling Ratio bit 4
BM_BBDN4    EQU (1<<BBDN4)       

ADCDN       EQU 5       ; ADC Down Sampling Configuration
BM_ADCDN    EQU (1<<ADCDN)       

; ***** CLK **************************
; CLKOCR - Clock output control Register
CLKOS0       EQU 0       ; Clock output source bit 0
BM_CLKOS0    EQU (1<<CLKOS0)       

CLKOS1       EQU 1       ; Clock output source bit 1
BM_CLKOS1    EQU (1<<CLKOS1)       

CLKOEN       EQU 2       ; Clock output driver enable
BM_CLKOEN    EQU (1<<CLKOEN)       

; CLKOD - Clock output divider settings Register
CLKOD0       EQU 0       ; Clock output divider bit 0
BM_CLKOD0    EQU (1<<CLKOD0)       

CLKOD1       EQU 1       ; Clock output divider bit 1
BM_CLKOD1    EQU (1<<CLKOD1)       

CLKOD2       EQU 2       ; Clock output divider bit 2
BM_CLKOD2    EQU (1<<CLKOD2)       

CLKOD3       EQU 3       ; Clock output divider bit 3
BM_CLKOD3    EQU (1<<CLKOD3)       

CLKOD4       EQU 4       ; Clock output divider bit 4
BM_CLKOD4    EQU (1<<CLKOD4)       

CLKOD5       EQU 5       ; Clock output divider bit 5
BM_CLKOD5    EQU (1<<CLKOD5)       

CLKOD6       EQU 6       ; Clock output divider bit 6
BM_CLKOD6    EQU (1<<CLKOD6)       

CLKOD7       EQU 7       ; Clock output divider bit 7
BM_CLKOD7    EQU (1<<CLKOD7)       

; CMOCR - Clock management override control register
FRCAO       EQU 0       ; FRC Always On
BM_FRCAO    EQU (1<<FRCAO)       

SRCAO       EQU 1       ; SRC Always On
BM_SRCAO    EQU (1<<SRCAO)       

FRCACT       EQU 2       ; FRC Active
BM_FRCACT    EQU (1<<FRCACT)       

SRCACT       EQU 3       ; SRC Active
BM_SRCACT    EQU (1<<SRCACT)       

; CMSR - Clock management status Register
ECF       EQU 0       ; External clock fail
BM_ECF    EQU (1<<ECF)       

; FRCCAL - Fast RC oscillator calibration Register
FRCCAL0       EQU 0       ; Fast RC oscillator calibration bit 0
BM_FRCCAL0    EQU (1<<FRCCAL0)       

FRCCAL1       EQU 1       ; Fast RC oscillator calibration bit 1
BM_FRCCAL1    EQU (1<<FRCCAL1)       

FRCCAL2       EQU 2       ; Fast RC oscillator calibration bit 2
BM_FRCCAL2    EQU (1<<FRCCAL2)       

FRCCAL3       EQU 3       ; Fast RC oscillator calibration bit 3
BM_FRCCAL3    EQU (1<<FRCCAL3)       

FRCCAL4       EQU 4       ; Fast RC oscillator calibration bit 4
BM_FRCCAL4    EQU (1<<FRCCAL4)       

FRCTC       EQU 5       ; Fast RC oscillator temperature compensation
BM_FRCTC    EQU (1<<FRCTC)       

; PRR0 - Power reduction Register 0
PRSPI       EQU 0       ; Power Reduction Serial Peripheral Interface
BM_PRSPI    EQU (1<<PRSPI)       

PRRXDC       EQU 1       ; Power Reduction Receive DSP Control
BM_PRRXDC    EQU (1<<PRRXDC)       

PRTXDC       EQU 2       ; Power Reduction Transmit DSP Control
BM_PRTXDC    EQU (1<<PRTXDC)       

PRCRC       EQU 3       ; Power Reduction CRC
BM_PRCRC    EQU (1<<PRCRC)       

PRVM       EQU 4       ; Power Reduction Voltage Monitor
BM_PRVM    EQU (1<<PRVM)       

PRCO       EQU 5       ; Power Reduction Clock Output
BM_PRCO    EQU (1<<PRCO)       

; PRR1 - Power reduction Register 1
PRT1       EQU 0       ; Power Reduction Timer 1
BM_PRT1    EQU (1<<PRT1)       

PRT2       EQU 1       ; Power Reduction Timer 2
BM_PRT2    EQU (1<<PRT2)       

PRT3       EQU 2       ; Power Reduction Timer 3
BM_PRT3    EQU (1<<PRT3)       

PRT4       EQU 3       ; Power Reduction Timer 4
BM_PRT4    EQU (1<<PRT4)       

PRT5       EQU 4       ; Power Reduction Timer 5
BM_PRT5    EQU (1<<PRT5)       

; PRR2 - Power reduction register 2
PRXB       EQU 0       ; Power Reduction Rx Buffer B
BM_PRXB    EQU (1<<PRXB)       

PRXA       EQU 1       ; Power Reduction Rx Buffer A
BM_PRXA    EQU (1<<PRXA)       

PRSF       EQU 2       ; Power Reduction Preamble/RSSI FIFO
BM_PRSF    EQU (1<<PRSF)       

PRDF       EQU 3       ; Power Reduction Data FIFO
BM_PRDF    EQU (1<<PRDF)       

PRIDS       EQU 4       ; Power Reduction ID scan
BM_PRIDS    EQU (1<<PRIDS)       

PRRS       EQU 5       ; Power Reduction RSSI Buffer
BM_PRRS    EQU (1<<PRRS)       

PRTM       EQU 6       ; Power Reduction Tx Modulator
BM_PRTM    EQU (1<<PRTM)       

PRSSM       EQU 7       ; Power Reduction Sequencer State Machine
BM_PRSSM    EQU (1<<PRSSM)       

; RDPR - Rx DSP power reduction register
PRPTB       EQU 0       ; Power reduction register for the demodulator and receiving path A
BM_PRPTB    EQU (1<<PRPTB)       

PRPTA       EQU 1       ; Power reduction register for the demodulator and receiving path B
BM_PRPTA    EQU (1<<PRPTA)       

PRFLT       EQU 2       ; Power reduction register for the digital channel filter
BM_PRFLT    EQU (1<<PRFLT)       

PRTMP       EQU 3       ; Power reduction register for temperature measurement
BM_PRTMP    EQU (1<<PRTMP)       

APRPTB       EQU 4       ; Automatic Power Reduction of Path B
BM_APRPTB    EQU (1<<APRPTB)       

APRPTA       EQU 5       ; Automatic Power Reduction of Path A
BM_APRPTA    EQU (1<<APRPTA)       

ARDPRF       EQU 6       ; Automatic Rx DSP Power Reduction Flag
BM_ARDPRF    EQU (1<<ARDPRF)       

RDPRF       EQU 7       ; Rx DSP power reduction register(RDPR) busy flag
BM_RDPRF    EQU (1<<RDPRF)       

; SRCCAL - Slow RC oscillator calibration Register
SRCCAL0       EQU 0       ; Slow RC oscillator calibration bit 0
BM_SRCCAL0    EQU (1<<SRCCAL0)       

SRCCAL1       EQU 1       ; Slow RC oscillator calibration bit 1
BM_SRCCAL1    EQU (1<<SRCCAL1)       

SRCCAL2       EQU 2       ; Slow RC oscillator calibration bit 2
BM_SRCCAL2    EQU (1<<SRCCAL2)       

SRCCAL3       EQU 3       ; Slow RC oscillator calibration bit 3
BM_SRCCAL3    EQU (1<<SRCCAL3)       

SRCCAL4       EQU 4       ; Slow RC oscillator calibration bit 4
BM_SRCCAL4    EQU (1<<SRCCAL4)       

SRCCAL5       EQU 5       ; Slow RC oscillator calibration bit 5
BM_SRCCAL5    EQU (1<<SRCCAL5)       

SRCTC0       EQU 6       ; Slow RC oscillator temperature compensation bit 0
BM_SRCTC0    EQU (1<<SRCTC0)       

SRCTC1       EQU 7       ; Slow RC oscillator temperature compensation bit 1
BM_SRCTC1    EQU (1<<SRCTC1)       

; XFUSE - 
; ***** CPU **************************
; CLPR - Clock Prescaler Register
CLKPS0       EQU 0       ; System Clock Prescaler Select bit 0
BM_CLKPS0    EQU (1<<CLKPS0)       

CLKPS1       EQU 1       ; System Clock Prescaler Select bit 1
BM_CLKPS1    EQU (1<<CLKPS1)       

CLKPS2       EQU 2       ; System Clock Prescaler Select bit 2
BM_CLKPS2    EQU (1<<CLKPS2)       

CLTPS0       EQU 3       ; Timer Clock Prescaler Select bit 0
BM_CLTPS0    EQU (1<<CLTPS0)       

CLTPS1       EQU 4       ; Timer Clock Prescaler Select bit 1
BM_CLTPS1    EQU (1<<CLTPS1)       

CLTPS2       EQU 5       ; Timer Clock Prescaler Select bit 2
BM_CLTPS2    EQU (1<<CLTPS2)       

CLPCE       EQU 7       ; Clock Prescaler Change Enable
BM_CLPCE    EQU (1<<CLPCE)       

; CMCR - Clock Management Control Register
CMM0       EQU 0       ; Clock Management Mode bit 0
BM_CMM0    EQU (1<<CMM0)       

CMM1       EQU 1       ; Clock Management Mode bit 1
BM_CMM1    EQU (1<<CMM1)       

CMM2       EQU 2       ; Clock Management Mode bit 2
BM_CMM2    EQU (1<<CMM2)       

CCS       EQU 3       ; Core Clock Select
BM_CCS    EQU (1<<CCS)       

SRCD       EQU 4       ; Slow RC oscillator disable
BM_SRCD    EQU (1<<SRCD)       

CMONEN       EQU 6       ; Clock monitor enable
BM_CMONEN    EQU (1<<CMONEN)       

CMCCE       EQU 7       ; Clock management control change enable
BM_CMCCE    EQU (1<<CMCCE)       

; CMIMR - Clock interrupt mask Register
ECIE       EQU 0       ; External clock interrupt enable
BM_ECIE    EQU (1<<ECIE)       

; DWDR - Debug Wire Data Register
DWDR0       EQU 0       ; Debug Wire Data Register bit 0
BM_DWDR0    EQU (1<<DWDR0)       

DWDR1       EQU 1       ; Debug Wire Data Register bit 1
BM_DWDR1    EQU (1<<DWDR1)       

DWDR2       EQU 2       ; Debug Wire Data Register bit 2
BM_DWDR2    EQU (1<<DWDR2)       

DWDR3       EQU 3       ; Debug Wire Data Register bit 3
BM_DWDR3    EQU (1<<DWDR3)       

DWDR4       EQU 4       ; Debug Wire Data Register bit 4
BM_DWDR4    EQU (1<<DWDR4)       

DWDR5       EQU 5       ; Debug Wire Data Register bit 5
BM_DWDR5    EQU (1<<DWDR5)       

DWDR6       EQU 6       ; Debug Wire Data Register bit 6
BM_DWDR6    EQU (1<<DWDR6)       

DWDR7       EQU 7       ; Debug Wire Data Register bit 7
BM_DWDR7    EQU (1<<DWDR7)       

; MCUCR - MCU control Register
IVCE       EQU 0       ; Interrupt Vector Change Enable
BM_IVCE    EQU (1<<IVCE)       

IVSEL       EQU 1       ; Interrupt Vector Select
BM_IVSEL    EQU (1<<IVSEL)       

SPIIO       EQU 2       ; SPI Interrupt Only
BM_SPIIO    EQU (1<<SPIIO)       

ENPS       EQU 3       ; Enable Port Settings
BM_ENPS    EQU (1<<ENPS)       

PUD       EQU 4       ; Pull-up Resistors Disable
BM_PUD    EQU (1<<PUD)       

PB4HS       EQU 5       ; Port B4 High Side Driver enable
BM_PB4HS    EQU (1<<PB4HS)       

PB7LS       EQU 6       ; Port B7 Low Side Driver enable
BM_PB7LS    EQU (1<<PB7LS)       

PB7HS       EQU 7       ; Port B7 High Side Driver enable
BM_PB7HS    EQU (1<<PB7HS)       

; MCUSR - MCU Status Register
PORF       EQU 0       ; Power-On Reset Flag
BM_PORF    EQU (1<<PORF)       

EXTRF       EQU 1       ; External Reset Flag
BM_EXTRF    EQU (1<<EXTRF)       

WDRF       EQU 3       ; Watchdog Reset Flag
BM_WDRF    EQU (1<<WDRF)       

; SMCR - Sleep mode control Register
SE       EQU 0       ; Sleep Enable
BM_SE    EQU (1<<SE)       

SM0       EQU 1       ; Sleep Mode Select bit 0
BM_SM0    EQU (1<<SM0)       

SM1       EQU 2       ; Sleep Mode Select bit 1
BM_SM1    EQU (1<<SM1)       

SM2       EQU 3       ; Sleep Mode Select bit 2
BM_SM2    EQU (1<<SM2)       

; SPH - Stack Pointer High
SP8       EQU 0       ; Stack pointer bit 8
BM_SP8    EQU (1<<SP8)       

SP9       EQU 1       ; Stack pointer bit 9
BM_SP9    EQU (1<<SP9)       

SP10       EQU 2       ; Stack pointer bit 10
BM_SP10    EQU (1<<SP10)       

; SPL - Stack Pointer Low
SP0       EQU 0       ; Stack pointer bit 0
BM_SP0    EQU (1<<SP0)       

SP1       EQU 1       ; Stack pointer bit 1
BM_SP1    EQU (1<<SP1)       

SP2       EQU 2       ; Stack pointer bit 2
BM_SP2    EQU (1<<SP2)       

SP3       EQU 3       ; Stack pointer bit 3
BM_SP3    EQU (1<<SP3)       

SP4       EQU 4       ; Stack pointer bit 4
BM_SP4    EQU (1<<SP4)       

SP5       EQU 5       ; Stack pointer bit 5
BM_SP5    EQU (1<<SP5)       

SP6       EQU 6       ; Stack pointer bit 6
BM_SP6    EQU (1<<SP6)       

SP7       EQU 7       ; Stack pointer bit 7
BM_SP7    EQU (1<<SP7)       

; SPMCSR - Store Program Memory Control and Status Register
SELFPRGEN       EQU 0       ; Self Programming Enable
BM_SELFPRGEN    EQU (1<<SELFPRGEN)       

PGERS       EQU 1       ; Page Erase
BM_PGERS    EQU (1<<PGERS)       

PGWRT       EQU 2       ; Page Write
BM_PGWRT    EQU (1<<PGWRT)       

BLBSET       EQU 3       ; Boot Lock Bit Set
BM_BLBSET    EQU (1<<BLBSET)       

SPMIE       EQU 7       ; SPM Interrupt Enable
BM_SPMIE    EQU (1<<SPMIE)       

; SREG - Status Register
SREG_C       EQU 0       ; Carry Flag
BM_SREG_C    EQU (1<<SREG_C)       

SREG_Z       EQU 1       ; Zero Flag
BM_SREG_Z    EQU (1<<SREG_Z)       

SREG_N       EQU 2       ; Negative Flag
BM_SREG_N    EQU (1<<SREG_N)       

SREG_V       EQU 3       ; Two's Complement Overflow Flag
BM_SREG_V    EQU (1<<SREG_V)       

SREG_S       EQU 4       ; Sign Bit
BM_SREG_S    EQU (1<<SREG_S)       

SREG_H       EQU 5       ; Half Carry Flag
BM_SREG_H    EQU (1<<SREG_H)       

SREG_T       EQU 6       ; Bit Copy Storage
BM_SREG_T    EQU (1<<SREG_T)       

SREG_I       EQU 7       ; Global Interrupt Enable
BM_SREG_I    EQU (1<<SREG_I)       

; ***** CRC **************************
; CRCCR - CRC Control Register
CRCRS       EQU 0       ; CRC Data Register Reset
BM_CRCRS    EQU (1<<CRCRS)       

REFLI       EQU 1       ; Reflect Data Input Byte
BM_REFLI    EQU (1<<REFLI)       

REFLO       EQU 2       ; Reflect Data Output Byte
BM_REFLO    EQU (1<<REFLO)       

; CRCDIR - CRC Data Input Register
CRCDIR0       EQU 0       ; CRC Data Input Register bit 0
BM_CRCDIR0    EQU (1<<CRCDIR0)       

CRCDIR1       EQU 1       ; CRC Data Input Register bit 1
BM_CRCDIR1    EQU (1<<CRCDIR1)       

CRCDIR2       EQU 2       ; CRC Data Input Register bit 2
BM_CRCDIR2    EQU (1<<CRCDIR2)       

CRCDIR3       EQU 3       ; CRC Data Input Register bit 3
BM_CRCDIR3    EQU (1<<CRCDIR3)       

CRCDIR4       EQU 4       ; CRC Data Input Register bit 4
BM_CRCDIR4    EQU (1<<CRCDIR4)       

CRCDIR5       EQU 5       ; CRC Data Input Register bit 5
BM_CRCDIR5    EQU (1<<CRCDIR5)       

CRCDIR6       EQU 6       ; CRC Data Input Register bit 6
BM_CRCDIR6    EQU (1<<CRCDIR6)       

CRCDIR7       EQU 7       ; CRC Data Input Register bit 7
BM_CRCDIR7    EQU (1<<CRCDIR7)       

; CRCDOR - CRC Data Output Register
CRCDOR0       EQU 0       ; CRC Data Output Register bit 0
BM_CRCDOR0    EQU (1<<CRCDOR0)       

CRCDOR1       EQU 1       ; CRC Data Output Register bit 1
BM_CRCDOR1    EQU (1<<CRCDOR1)       

CRCDOR2       EQU 2       ; CRC Data Output Register bit 2
BM_CRCDOR2    EQU (1<<CRCDOR2)       

CRCDOR3       EQU 3       ; CRC Data Output Register bit 3
BM_CRCDOR3    EQU (1<<CRCDOR3)       

CRCDOR4       EQU 4       ; CRC Data Output Register bit 4
BM_CRCDOR4    EQU (1<<CRCDOR4)       

CRCDOR5       EQU 5       ; CRC Data Output Register bit 5
BM_CRCDOR5    EQU (1<<CRCDOR5)       

CRCDOR6       EQU 6       ; CRC Data Output Register bit 6
BM_CRCDOR6    EQU (1<<CRCDOR6)       

CRCDOR7       EQU 7       ; CRC Data Output Register bit 7
BM_CRCDOR7    EQU (1<<CRCDOR7)       

; ***** DEBOUNCE *********************
; DBCR - DeBounce Control Register
DBMD       EQU 0       ; Debounce Mode
BM_DBMD    EQU (1<<DBMD)       

DBCS       EQU 1       ; Debounce Clock Select
BM_DBCS    EQU (1<<DBCS)       

DBTMS       EQU 2       ; Debounce Timer Mask Select
BM_DBTMS    EQU (1<<DBTMS)       

DBHA       EQU 3       ; Debounce Handshake Active
BM_DBHA    EQU (1<<DBHA)       

; DBENB - DeBounce Enable Port B
DBENB0       EQU 0       ; DeBounce Enable Port B Pin 0
BM_DBENB0    EQU (1<<DBENB0)       

DBENB1       EQU 1       ; DeBounce Enable Port B Pin 1
BM_DBENB1    EQU (1<<DBENB1)       

DBENB2       EQU 2       ; DeBounce Enable Port B Pin 2
BM_DBENB2    EQU (1<<DBENB2)       

DBENB3       EQU 3       ; DeBounce Enable Port B Pin 3
BM_DBENB3    EQU (1<<DBENB3)       

DBENB4       EQU 4       ; DeBounce Enable Port B Pin 4
BM_DBENB4    EQU (1<<DBENB4)       

DBENB5       EQU 5       ; DeBounce Enable Port B Pin 5
BM_DBENB5    EQU (1<<DBENB5)       

DBENB6       EQU 6       ; DeBounce Enable Port B Pin 6
BM_DBENB6    EQU (1<<DBENB6)       

DBENB7       EQU 7       ; DeBounce Enable Port B Pin 7
BM_DBENB7    EQU (1<<DBENB7)       

; DBENC - DeBounce Enable Port C
DBENC0       EQU 0       ; DeBounce Enable Port C Pin 0
BM_DBENC0    EQU (1<<DBENC0)       

DBENC1       EQU 1       ; DeBounce Enable Port C Pin 1
BM_DBENC1    EQU (1<<DBENC1)       

DBENC2       EQU 2       ; DeBounce Enable Port C Pin 2
BM_DBENC2    EQU (1<<DBENC2)       

DBENC3       EQU 3       ; DeBounce Enable Port C Pin 3
BM_DBENC3    EQU (1<<DBENC3)       

DBENC4       EQU 4       ; DeBounce Enable Port C Pin 4
BM_DBENC4    EQU (1<<DBENC4)       

DBENC5       EQU 5       ; DeBounce Enable Port C Pin 5
BM_DBENC5    EQU (1<<DBENC5)       

; DBTC - Debounce Timer Compare Register
DBTC0       EQU 0       ; Debounce Timer Compare bit 0
BM_DBTC0    EQU (1<<DBTC0)       

DBTC1       EQU 1       ; Debounce Timer Compare bit 1
BM_DBTC1    EQU (1<<DBTC1)       

DBTC2       EQU 2       ; Debounce Timer Compare bit 2
BM_DBTC2    EQU (1<<DBTC2)       

DBTC3       EQU 3       ; Debounce Timer Compare bit 3
BM_DBTC3    EQU (1<<DBTC3)       

DBTC4       EQU 4       ; Debounce Timer Compare bit 4
BM_DBTC4    EQU (1<<DBTC4)       

DBTC5       EQU 5       ; Debounce Timer Compare bit 5
BM_DBTC5    EQU (1<<DBTC5)       

DBTC6       EQU 6       ; Debounce Timer Compare bit 6
BM_DBTC6    EQU (1<<DBTC6)       

DBTC7       EQU 7       ; Debounce Timer Compare bit 7
BM_DBTC7    EQU (1<<DBTC7)       

; ***** DEBUG ************************
; DBGSW - Debugging Support Switch
DBGGS0       EQU 0       ; Debugging Support Group Select bit 0
BM_DBGGS0    EQU (1<<DBGGS0)       

DBGGS1       EQU 1       ; Debugging Support Group Select bit 1
BM_DBGGS1    EQU (1<<DBGGS1)       

DBGGS2       EQU 2       ; Debugging Support Group Select bit 2
BM_DBGGS2    EQU (1<<DBGGS2)       

DBGGS3       EQU 3       ; Debugging Support Group Select bit 3
BM_DBGGS3    EQU (1<<DBGGS3)       

CPBFOS0       EQU 4       ; CPU Busy Flag Output Select bit 0
BM_CPBFOS0    EQU (1<<CPBFOS0)       

CPBFOS1       EQU 5       ; CPU Busy Flag Output Select bit 1
BM_CPBFOS1    EQU (1<<CPBFOS1)       

CPBF       EQU 6       ; CPU Busy Flag
BM_CPBF    EQU (1<<CPBF)       

DBGSE       EQU 7       ; Debugging Support Switch Enable
BM_DBGSE    EQU (1<<DBGSE)       

; ***** DEMOD ************************
; DMCDA - Demodulator Carrier Detect for path A
DMCLA0       EQU 0       ; Demodulator Carrier Detect Limit for path A bit 0
BM_DMCLA0    EQU (1<<DMCLA0)       

DMCLA1       EQU 1       ; Demodulator Carrier Detect Limit for path A bit 1
BM_DMCLA1    EQU (1<<DMCLA1)       

DMCLA2       EQU 2       ; Demodulator Carrier Detect Limit for path A bit 2
BM_DMCLA2    EQU (1<<DMCLA2)       

DMCLA3       EQU 3       ; Demodulator Carrier Detect Limit for path A bit 3
BM_DMCLA3    EQU (1<<DMCLA3)       

DMCLA4       EQU 4       ; Demodulator Carrier Detect Limit for path A bit 4
BM_DMCLA4    EQU (1<<DMCLA4)       

DMCTA0       EQU 5       ; Demodulator Carrier Detect Time for path A bit 0
BM_DMCTA0    EQU (1<<DMCTA0)       

DMCTA1       EQU 6       ; Demodulator Carrier Detect Time for path A bit 1
BM_DMCTA1    EQU (1<<DMCTA1)       

DMCTA2       EQU 7       ; Demodulator Carrier Detect Time for path A bit 2
BM_DMCTA2    EQU (1<<DMCTA2)       

; DMCDB - Demodulator Carrier Detect for path B
DMCLB0       EQU 0       ; Demodulator Carrier Detect Limit for path B bit 0
BM_DMCLB0    EQU (1<<DMCLB0)       

DMCLB1       EQU 1       ; Demodulator Carrier Detect Limit for path B bit 1
BM_DMCLB1    EQU (1<<DMCLB1)       

DMCLB2       EQU 2       ; Demodulator Carrier Detect Limit for path B bit 2
BM_DMCLB2    EQU (1<<DMCLB2)       

DMCLB3       EQU 3       ; Demodulator Carrier Detect Limit for path B bit 3
BM_DMCLB3    EQU (1<<DMCLB3)       

DMCLB4       EQU 4       ; Demodulator Carrier Detect Limit for path B bit 4
BM_DMCLB4    EQU (1<<DMCLB4)       

DMCTB0       EQU 5       ; Demodulator Carrier Detect Time for path B bit 0
BM_DMCTB0    EQU (1<<DMCTB0)       

DMCTB1       EQU 6       ; Demodulator Carrier Detect Time for path B bit 1
BM_DMCTB1    EQU (1<<DMCTB1)       

DMCTB2       EQU 7       ; Demodulator Carrier Detect Time for path B bit 2
BM_DMCTB2    EQU (1<<DMCTB2)       

; DMCRA - Demodulator Control Register for path A
DMPGA0       EQU 0       ; Demodulator PLL loop gain for path A bit 0
BM_DMPGA0    EQU (1<<DMPGA0)       

DMPGA1       EQU 1       ; Demodulator PLL loop gain for path A bit 1
BM_DMPGA1    EQU (1<<DMPGA1)       

DMPGA2       EQU 2       ; Demodulator PLL loop gain for path A bit 2
BM_DMPGA2    EQU (1<<DMPGA2)       

DMPGA3       EQU 3       ; Demodulator PLL loop gain for path A bit 3
BM_DMPGA3    EQU (1<<DMPGA3)       

DMPGA4       EQU 4       ; Demodulator PLL loop gain for path A bit 4
BM_DMPGA4    EQU (1<<DMPGA4)       

SASKA       EQU 5       ; Select ASK input for path A
BM_SASKA    EQU (1<<SASKA)       

SY1TA       EQU 6       ; Symbol check with only 1T on path A
BM_SY1TA    EQU (1<<SY1TA)       

DMARA       EQU 7       ; Demodulator automatic restart on path A
BM_DMARA    EQU (1<<DMARA)       

; DMCRB - Demodulator Control Register for path B
DMPGB0       EQU 0       ; Demodulator PLL loop gain for path B bit 0
BM_DMPGB0    EQU (1<<DMPGB0)       

DMPGB1       EQU 1       ; Demodulator PLL loop gain for path B bit 1
BM_DMPGB1    EQU (1<<DMPGB1)       

DMPGB2       EQU 2       ; Demodulator PLL loop gain for path B bit 2
BM_DMPGB2    EQU (1<<DMPGB2)       

DMPGB3       EQU 3       ; Demodulator PLL loop gain for path B bit 3
BM_DMPGB3    EQU (1<<DMPGB3)       

DMPGB4       EQU 4       ; Demodulator PLL loop gain for path B bit 4
BM_DMPGB4    EQU (1<<DMPGB4)       

SASKB       EQU 5       ; Select ASK input for path B
BM_SASKB    EQU (1<<SASKB)       

SY1TB       EQU 6       ; Symbol check with only 1T on path B
BM_SY1TB    EQU (1<<SY1TB)       

DMARB       EQU 7       ; Demodulator automatic restart on path B
BM_DMARB    EQU (1<<DMARB)       

; DMDRA - Demodulator Data Rate on path A
DMAA0       EQU 0       ; Demodulator Moving Average Data Rate factor on path A bit 0
BM_DMAA0    EQU (1<<DMAA0)       

DMAA1       EQU 1       ; Demodulator Moving Average Data Rate factor on path A bit 1
BM_DMAA1    EQU (1<<DMAA1)       

DMAA2       EQU 2       ; Demodulator Moving Average Data Rate factor on path A bit 2
BM_DMAA2    EQU (1<<DMAA2)       

DMAA3       EQU 3       ; Demodulator Moving Average Data Rate factor on path A bit 3
BM_DMAA3    EQU (1<<DMAA3)       

DMDNA0       EQU 4       ; Demodulator Downsampling on path A bit 0
BM_DMDNA0    EQU (1<<DMDNA0)       

DMDNA1       EQU 5       ; Demodulator Downsampling on path A bit 1
BM_DMDNA1    EQU (1<<DMDNA1)       

DMDNA2       EQU 6       ; Demodulator Downsampling on path A bit 2
BM_DMDNA2    EQU (1<<DMDNA2)       

DMDNA3       EQU 7       ; Demodulator Downsampling on path A bit 3
BM_DMDNA3    EQU (1<<DMDNA3)       

; DMDRB - Demodulator Data Rate on path B
DMAB0       EQU 0       ; Demodulator Moving Average Data Rate factor on path B bit 0
BM_DMAB0    EQU (1<<DMAB0)       

DMAB1       EQU 1       ; Demodulator Moving Average Data Rate factor on path B bit 1
BM_DMAB1    EQU (1<<DMAB1)       

DMAB2       EQU 2       ; Demodulator Moving Average Data Rate factor on path B bit 2
BM_DMAB2    EQU (1<<DMAB2)       

DMAB3       EQU 3       ; Demodulator Moving Average Data Rate factor on path B bit 3
BM_DMAB3    EQU (1<<DMAB3)       

DMDNB0       EQU 4       ; Demodulator Downsampling on path B bit 0
BM_DMDNB0    EQU (1<<DMDNB0)       

DMDNB1       EQU 5       ; Demodulator Downsampling on path B bit 1
BM_DMDNB1    EQU (1<<DMDNB1)       

DMDNB2       EQU 6       ; Demodulator Downsampling on path B bit 2
BM_DMDNB2    EQU (1<<DMDNB2)       

DMDNB3       EQU 7       ; Demodulator Downsampling on path B bit 3
BM_DMDNB3    EQU (1<<DMDNB3)       

; DMMA - Demodulator Mode for path A
DMATA0       EQU 0       ; Demodulator Amplitude Threshold for path A bit 0
BM_DMATA0    EQU (1<<DMATA0)       

DMATA1       EQU 1       ; Demodulator Amplitude Threshold for path A bit 1
BM_DMATA1    EQU (1<<DMATA1)       

DMATA2       EQU 2       ; Demodulator Amplitude Threshold for path A bit 2
BM_DMATA2    EQU (1<<DMATA2)       

DMATA3       EQU 3       ; Demodulator Amplitude Threshold for path A bit 3
BM_DMATA3    EQU (1<<DMATA3)       

DMATA4       EQU 4       ; Demodulator Amplitude Threshold for path A bit 4
BM_DMATA4    EQU (1<<DMATA4)       

DMPA       EQU 5       ; Demodulator Data Polarity Selection for path A
BM_DMPA    EQU (1<<DMPA)       

DMHA       EQU 6       ; Demodulator Hold Mode for path A
BM_DMHA    EQU (1<<DMHA)       

DMNEA       EQU 7       ; Demodulator NRZ Enable for path A
BM_DMNEA    EQU (1<<DMNEA)       

; DMMB - Demodulator Mode for Path B
DMATB0       EQU 0       ; Demodulator Amplitude Threshold for path B bit 0
BM_DMATB0    EQU (1<<DMATB0)       

DMATB1       EQU 1       ; Demodulator Amplitude Threshold for path B bit 1
BM_DMATB1    EQU (1<<DMATB1)       

DMATB2       EQU 2       ; Demodulator Amplitude Threshold for path B bit 2
BM_DMATB2    EQU (1<<DMATB2)       

DMATB3       EQU 3       ; Demodulator Amplitude Threshold for path B bit 3
BM_DMATB3    EQU (1<<DMATB3)       

DMATB4       EQU 4       ; Demodulator Amplitude Threshold for path B bit 4
BM_DMATB4    EQU (1<<DMATB4)       

DMPB       EQU 5       ; Demodulator Data Polarity Selection for path B
BM_DMPB    EQU (1<<DMPB)       

DMHB       EQU 6       ; Demodulator Hold Mode for path B
BM_DMHB    EQU (1<<DMHB)       

DMNEB       EQU 7       ; Demodulator NRZ Enable for path B
BM_DMNEB    EQU (1<<DMNEB)       

; RXFOA - Received Frequency Offset vs Intermediate Frequency on path A
RXFOA0       EQU 0       ; Received frequency offset for path A bit 0
BM_RXFOA0    EQU (1<<RXFOA0)       

RXFOA1       EQU 1       ; Received frequency offset for path A bit 1
BM_RXFOA1    EQU (1<<RXFOA1)       

RXFOA2       EQU 2       ; Received frequency offset for path A bit 2
BM_RXFOA2    EQU (1<<RXFOA2)       

RXFOA3       EQU 3       ; Received frequency offset for path A bit 3
BM_RXFOA3    EQU (1<<RXFOA3)       

RXFOA4       EQU 4       ; Received frequency offset for path A bit 4
BM_RXFOA4    EQU (1<<RXFOA4)       

RXFOA5       EQU 5       ; Received frequency offset for path A bit 5
BM_RXFOA5    EQU (1<<RXFOA5)       

RXFOA6       EQU 6       ; Received frequency offset for path A bit 6
BM_RXFOA6    EQU (1<<RXFOA6)       

RXFOA7       EQU 7       ; Received frequency offset for path A bit 7
BM_RXFOA7    EQU (1<<RXFOA7)       

; RXFOB - Received Frequency Offset vs Intermediate Frequency on path B
RXFOB0       EQU 0       ; Received frequency offset for path B bit 0
BM_RXFOB0    EQU (1<<RXFOB0)       

RXFOB1       EQU 1       ; Received frequency offset for path B bit 1
BM_RXFOB1    EQU (1<<RXFOB1)       

RXFOB2       EQU 2       ; Received frequency offset for path B bit 2
BM_RXFOB2    EQU (1<<RXFOB2)       

RXFOB3       EQU 3       ; Received frequency offset for path B bit 3
BM_RXFOB3    EQU (1<<RXFOB3)       

RXFOB4       EQU 4       ; Received frequency offset for path B bit 4
BM_RXFOB4    EQU (1<<RXFOB4)       

RXFOB5       EQU 5       ; Received frequency offset for path B bit 5
BM_RXFOB5    EQU (1<<RXFOB5)       

RXFOB6       EQU 6       ; Received frequency offset for path B bit 6
BM_RXFOB6    EQU (1<<RXFOB6)       

RXFOB7       EQU 7       ; Received frequency offset for path B bit 7
BM_RXFOB7    EQU (1<<RXFOB7)       

; ***** DFIFO ************************
; DFC - Data FIFO Configuration Register
DFFLC0       EQU 0       ; Data FIFO Fill-Level Configuration bit 0
BM_DFFLC0    EQU (1<<DFFLC0)       

DFFLC1       EQU 1       ; Data FIFO Fill-Level Configuration bit 1
BM_DFFLC1    EQU (1<<DFFLC1)       

DFFLC2       EQU 2       ; Data FIFO Fill-Level Configuration bit 2
BM_DFFLC2    EQU (1<<DFFLC2)       

DFFLC3       EQU 3       ; Data FIFO Fill-Level Configuration bit 3
BM_DFFLC3    EQU (1<<DFFLC3)       

DFFLC4       EQU 4       ; Data FIFO Fill-Level Configuration bit 4
BM_DFFLC4    EQU (1<<DFFLC4)       

DFFLC5       EQU 5       ; Data FIFO Fill-Level Configuration bit 5
BM_DFFLC5    EQU (1<<DFFLC5)       

DFDRA       EQU 7       ; Data FIFO Direct Read Access Operational Mode
BM_DFDRA    EQU (1<<DFDRA)       

; DFI - Data FIFO Interrupt Mask Register
DFFLIM       EQU 0       ; Data FIFO Fill-level Interrupt Mask
BM_DFFLIM    EQU (1<<DFFLIM)       

DFERIM       EQU 1       ; Data FIFO Error Interrupt Mask
BM_DFERIM    EQU (1<<DFERIM)       

; DFL - Data FIFO Fill Level Register
DFFLS0       EQU 0       ; Data FIFO Fill Level Status bit 0
BM_DFFLS0    EQU (1<<DFFLS0)       

DFFLS1       EQU 1       ; Data FIFO Fill Level Status bit 1
BM_DFFLS1    EQU (1<<DFFLS1)       

DFFLS2       EQU 2       ; Data FIFO Fill Level Status bit 2
BM_DFFLS2    EQU (1<<DFFLS2)       

DFFLS3       EQU 3       ; Data FIFO Fill Level Status bit 3
BM_DFFLS3    EQU (1<<DFFLS3)       

DFFLS4       EQU 4       ; Data FIFO Fill Level Status bit 4
BM_DFFLS4    EQU (1<<DFFLS4)       

DFFLS5       EQU 5       ; Data FIFO Fill Level Status bit 5
BM_DFFLS5    EQU (1<<DFFLS5)       

DFCLR       EQU 7       ; Data FIFO Clear
BM_DFCLR    EQU (1<<DFCLR)       

; DFRP - Data FIFO Read Pointer
DFRP0       EQU 0       ; Data FIFO Read Pointer bit 0
BM_DFRP0    EQU (1<<DFRP0)       

DFRP1       EQU 1       ; Data FIFO Read Pointer bit 1
BM_DFRP1    EQU (1<<DFRP1)       

DFRP2       EQU 2       ; Data FIFO Read Pointer bit 2
BM_DFRP2    EQU (1<<DFRP2)       

DFRP3       EQU 3       ; Data FIFO Read Pointer bit 3
BM_DFRP3    EQU (1<<DFRP3)       

DFRP4       EQU 4       ; Data FIFO Read Pointer bit 4
BM_DFRP4    EQU (1<<DFRP4)       

DFRP5       EQU 5       ; Data FIFO Read Pointer bit 5
BM_DFRP5    EQU (1<<DFRP5)       

; DFS - Data FIFO Status Register
DFFLRF       EQU 0       ; Data FIFO Fill-Level Reached Status Flag
BM_DFFLRF    EQU (1<<DFFLRF)       

DFUFL       EQU 1       ; Data FIFO Underflow Flag
BM_DFUFL    EQU (1<<DFUFL)       

DFOFL       EQU 2       ; Data FIFO Overflow Flag
BM_DFOFL    EQU (1<<DFOFL)       

; DFTLH - Data FIFO Telegram Length High Byte
DFTLH0       EQU 0       ; Data FIFO Telegram Length High Byte bit 0
BM_DFTLH0    EQU (1<<DFTLH0)       

DFTLH1       EQU 1       ; Data FIFO Telegram Length High Byte bit 1
BM_DFTLH1    EQU (1<<DFTLH1)       

DFTLH2       EQU 2       ; Data FIFO Telegram Length High Byte bit 2
BM_DFTLH2    EQU (1<<DFTLH2)       

DFTLH3       EQU 3       ; Data FIFO Telegram Length High Byte bit 3
BM_DFTLH3    EQU (1<<DFTLH3)       

; DFTLL - Data FIFO Telegram Length Low Byte
DFTLL0       EQU 0       ; Data FIFO Telegram Length Low Byte bit 0
BM_DFTLL0    EQU (1<<DFTLL0)       

DFTLL1       EQU 1       ; Data FIFO Telegram Length Low Byte bit 1
BM_DFTLL1    EQU (1<<DFTLL1)       

DFTLL2       EQU 2       ; Data FIFO Telegram Length Low Byte bit 2
BM_DFTLL2    EQU (1<<DFTLL2)       

DFTLL3       EQU 3       ; Data FIFO Telegram Length Low Byte bit 3
BM_DFTLL3    EQU (1<<DFTLL3)       

DFTLL4       EQU 4       ; Data FIFO Telegram Length Low Byte bit 4
BM_DFTLL4    EQU (1<<DFTLL4)       

DFTLL5       EQU 5       ; Data FIFO Telegram Length Low Byte bit 5
BM_DFTLL5    EQU (1<<DFTLL5)       

DFTLL6       EQU 6       ; Data FIFO Telegram Length Low Byte bit 6
BM_DFTLL6    EQU (1<<DFTLL6)       

DFTLL7       EQU 7       ; Data FIFO Telegram Length Low Byte bit 7
BM_DFTLL7    EQU (1<<DFTLL7)       

; DFWP - Data FIFO Write Pointer
DFWP0       EQU 0       ; Data FIFO Write Pointer bit 0
BM_DFWP0    EQU (1<<DFWP0)       

DFWP1       EQU 1       ; Data FIFO Write Pointer bit 1
BM_DFWP1    EQU (1<<DFWP1)       

DFWP2       EQU 2       ; Data FIFO Write Pointer bit 2
BM_DFWP2    EQU (1<<DFWP2)       

DFWP3       EQU 3       ; Data FIFO Write Pointer bit 3
BM_DFWP3    EQU (1<<DFWP3)       

DFWP4       EQU 4       ; Data FIFO Write Pointer bit 4
BM_DFWP4    EQU (1<<DFWP4)       

DFWP5       EQU 5       ; Data FIFO Write Pointer bit 5
BM_DFWP5    EQU (1<<DFWP5)       

; ***** EEPROM ***********************
; EEARH - EEPROM Address Register High Byte
EEAR8       EQU 0       ; EEPROM Read/Write Address bit 8
BM_EEAR8    EQU (1<<EEAR8)       

EEAR9       EQU 1       ; EEPROM Read/Write Address bit 9
BM_EEAR9    EQU (1<<EEAR9)       

EEAR10       EQU 2       ; EEPROM Read/Write Address bit 10
BM_EEAR10    EQU (1<<EEAR10)       

; EEARL - EEPROM Address Register Low Byte
EEAR0       EQU 0       ; EEPROM Read/Write Address bit 0
BM_EEAR0    EQU (1<<EEAR0)       

EEAR1       EQU 1       ; EEPROM Read/Write Address bit 1
BM_EEAR1    EQU (1<<EEAR1)       

EEAR2       EQU 2       ; EEPROM Read/Write Address bit 2
BM_EEAR2    EQU (1<<EEAR2)       

EEAR3       EQU 3       ; EEPROM Read/Write Address bit 3
BM_EEAR3    EQU (1<<EEAR3)       

EEAR4       EQU 4       ; EEPROM Read/Write Address bit 4
BM_EEAR4    EQU (1<<EEAR4)       

EEAR5       EQU 5       ; EEPROM Read/Write Address bit 5
BM_EEAR5    EQU (1<<EEAR5)       

EEAR6       EQU 6       ; EEPROM Read/Write Address bit 6
BM_EEAR6    EQU (1<<EEAR6)       

EEAR7       EQU 7       ; EEPROM Read/Write Address bit 7
BM_EEAR7    EQU (1<<EEAR7)       

; EECR - EEPROM Control Register
EERE       EQU 0       ; EEPROM Read Enable
BM_EERE    EQU (1<<EERE)       

EEWE       EQU 1       ; EEPROM Write Enable
BM_EEWE    EQU (1<<EEWE)       

EEMWE       EQU 2       ; EEPROM Master Write Enable
BM_EEMWE    EQU (1<<EEMWE)       

EERIE       EQU 3       ; EEPROM Ready Interrupt Enable
BM_EERIE    EQU (1<<EERIE)       

EEPM0       EQU 4       ; EEPROM Programming Mode bit 0
BM_EEPM0    EQU (1<<EEPM0)       

EEPM1       EQU 5       ; EEPROM Programming Mode bit 1
BM_EEPM1    EQU (1<<EEPM1)       

EEPAGE       EQU 6       ; EEPROM page access (multiple bytes access mode)
BM_EEPAGE    EQU (1<<EEPAGE)       

NVMBSY       EQU 7       ; Non-volatile memory busy
BM_NVMBSY    EQU (1<<NVMBSY)       

; EECR2 - EEPROM Control Register 2
EEBRE       EQU 0       ; EEPROM Burst Read Enable
BM_EEBRE    EQU (1<<EEBRE)       

; EEPR - EEPROM Protection Register
EEAP0       EQU 0       ; EEPROM Access Protection bit 0
BM_EEAP0    EQU (1<<EEAP0)       

EEAP1       EQU 1       ; EEPROM Access Protection bit 1
BM_EEAP1    EQU (1<<EEAP1)       

EEAP2       EQU 2       ; EEPROM Access Protection bit 2
BM_EEAP2    EQU (1<<EEAP2)       

EEAP3       EQU 3       ; EEPROM Access Protection bit 3
BM_EEAP3    EQU (1<<EEAP3)       

; ***** FE ***************************
; FEALR - Front-End Antenna Level Detector Range
RNGE0       EQU 0       ; Range of the ANT_TUNE level detector bit 0
BM_RNGE0    EQU (1<<RNGE0)       

RNGE1       EQU 1       ; Range of the ANT_TUNE level detector bit 1
BM_RNGE1    EQU (1<<RNGE1)       

; FEANT - Front-End ANTenna
LVLC0       EQU 0       ; antenna signal LeVeL bit 0
BM_LVLC0    EQU (1<<LVLC0)       

LVLC1       EQU 1       ; antenna signal LeVeL bit 1
BM_LVLC1    EQU (1<<LVLC1)       

LVLC2       EQU 2       ; antenna signal LeVeL bit 2
BM_LVLC2    EQU (1<<LVLC2)       

LVLC3       EQU 3       ; antenna signal LeVeL bit 3
BM_LVLC3    EQU (1<<LVLC3)       

; FEAT - Front-End Antenna Tuning
ANTN0       EQU 0       ; Antenna Tuning bit 0
BM_ANTN0    EQU (1<<ANTN0)       

ANTN1       EQU 1       ; Antenna Tuning bit 1
BM_ANTN1    EQU (1<<ANTN1)       

ANTN2       EQU 2       ; Antenna Tuning bit 2
BM_ANTN2    EQU (1<<ANTN2)       

ANTN3       EQU 3       ; Antenna Tuning bit 3
BM_ANTN3    EQU (1<<ANTN3)       

; FEBIA - Front-End IF Amplifier BIAS
IFAEN       EQU 7       ; IF Amplifier Enable
BM_IFAEN    EQU (1<<IFAEN)       

; FEBT - Front-End RC Tuning Register
CTN20       EQU 0       ; Capacitor Tuning bit 0
BM_CTN20    EQU (1<<CTN20)       

CTN21       EQU 1       ; Capacitor Tuning bit 1
BM_CTN21    EQU (1<<CTN21)       

RTN20       EQU 2       ; Resistor Tuning bit 0
BM_RTN20    EQU (1<<RTN20)       

RTN21       EQU 3       ; Resistor Tuning bit 1
BM_RTN21    EQU (1<<RTN21)       

; FECR - Front-End Control Register
LBNHB       EQU 0       ; Select Low-Band Not High-Band
BM_LBNHB    EQU (1<<LBNHB)       

S4N3       EQU 1       ; Select 433 Not 315MHz Band
BM_S4N3    EQU (1<<S4N3)       

ANDP       EQU 2       ; Antenna Damping
BM_ANDP    EQU (1<<ANDP)       

ADHS       EQU 3       ; ADC High Sample Rate
BM_ADHS    EQU (1<<ADHS)       

PLCKG       EQU 4       ; PLL Lock Detect Gate
BM_PLCKG    EQU (1<<PLCKG)       

ANPS       EQU 5       ; ASK Not DPSK Switch
BM_ANPS    EQU (1<<ANPS)       

; FEEN1 - Front-End Enable Register 1
PLEN       EQU 0       ; PLL enable
BM_PLEN    EQU (1<<PLEN)       

PLCAL       EQU 1       ; PLL calibration mode
BM_PLCAL    EQU (1<<PLCAL)       

XTOEN       EQU 2       ; Cristal Oscillator enable
BM_XTOEN    EQU (1<<XTOEN)       

LNAEN       EQU 3       ; Low Noise Amplifier enable
BM_LNAEN    EQU (1<<LNAEN)       

ADEN       EQU 4       ; Analog Digital Converter enable
BM_ADEN    EQU (1<<ADEN)       

ADCLK       EQU 5       ; ADC Clock enable
BM_ADCLK    EQU (1<<ADCLK)       

PLSP1       EQU 6       ; PLL Speedup 1
BM_PLSP1    EQU (1<<PLSP1)       

ATEN       EQU 7       ; Antenna Tuning Enable
BM_ATEN    EQU (1<<ATEN)       

; FEEN2 - Front-End Enable Register 2
SDRX       EQU 0       ; Single Pole Double Throw (SPDT) Switch RX
BM_SDRX    EQU (1<<SDRX)       

SDTX       EQU 1       ; Single Pole Double Throw (SPDT) Switch TX
BM_SDTX    EQU (1<<SDTX)       

PAEN       EQU 2       ; Power Amplifier enable
BM_PAEN    EQU (1<<PAEN)       

TMPM       EQU 3       ; Temperature measurement
BM_TMPM    EQU (1<<TMPM)       

PLPEN       EQU 4       ; PLL Post En IQ divider
BM_PLPEN    EQU (1<<PLPEN)       

XTPEN       EQU 5       ; XTO VPump enable
BM_XTPEN    EQU (1<<XTPEN)       

CPBIA       EQU 6       ; Cap Array Bias
BM_CPBIA    EQU (1<<CPBIA)       

; FELNA - Front-End LNA Bias Register
LBH0       EQU 0       ; LNA Bias High band bit 0
BM_LBH0    EQU (1<<LBH0)       

LBH1       EQU 1       ; LNA Bias High band bit 1
BM_LBH1    EQU (1<<LBH1)       

LBH2       EQU 2       ; LNA Bias High band bit 2
BM_LBH2    EQU (1<<LBH2)       

LBH3       EQU 3       ; LNA Bias High band bit 3
BM_LBH3    EQU (1<<LBH3)       

LBL0       EQU 4       ; LNA Bias Low band bit 0
BM_LBL0    EQU (1<<LBL0)       

LBL1       EQU 5       ; LNA Bias Low band bit 1
BM_LBL1    EQU (1<<LBL1)       

LBL2       EQU 6       ; LNA Bias Low band bit 2
BM_LBL2    EQU (1<<LBL2)       

LBL3       EQU 7       ; LNA Bias Low band bit 3
BM_LBL3    EQU (1<<LBL3)       

; FEMS - Front-End Main and Swallow Control Register
PLLS0       EQU 0       ; PLL Swallow bit 0
BM_PLLS0    EQU (1<<PLLS0)       

PLLS1       EQU 1       ; PLL Swallow bit 1
BM_PLLS1    EQU (1<<PLLS1)       

PLLS2       EQU 2       ; PLL Swallow bit 2
BM_PLLS2    EQU (1<<PLLS2)       

PLLS3       EQU 3       ; PLL Swallow bit 3
BM_PLLS3    EQU (1<<PLLS3)       

PLLM0       EQU 4       ; PLL Mode bit 0
BM_PLLM0    EQU (1<<PLLM0)       

PLLM1       EQU 5       ; PLL Mode bit 1
BM_PLLM1    EQU (1<<PLLM1)       

PLLM2       EQU 6       ; PLL Mode bit 2
BM_PLLM2    EQU (1<<PLLM2)       

PLLM3       EQU 7       ; PLL Mode bit 3
BM_PLLM3    EQU (1<<PLLM3)       

; FEPAC - Front-End Power Amplifier Control Register
PACR0       EQU 0       ; Power Amplifier Control Register bit 0
BM_PACR0    EQU (1<<PACR0)       

PACR1       EQU 1       ; Power Amplifier Control Register bit 1
BM_PACR1    EQU (1<<PACR1)       

PACR2       EQU 2       ; Power Amplifier Control Register bit 2
BM_PACR2    EQU (1<<PACR2)       

PACR3       EQU 3       ; Power Amplifier Control Register bit 3
BM_PACR3    EQU (1<<PACR3)       

PACR4       EQU 4       ; Power Amplifier Control Register bit 4
BM_PACR4    EQU (1<<PACR4)       

PACR5       EQU 5       ; Power Amplifier Control Register bit 5
BM_PACR5    EQU (1<<PACR5)       

PACR6       EQU 6       ; Power Amplifier Control Register bit 6
BM_PACR6    EQU (1<<PACR6)       

PACR7       EQU 7       ; Power Amplifier Control Register bit 7
BM_PACR7    EQU (1<<PACR7)       

; FESR - Front-End Status Register
LBSAT       EQU 0       ; LNA Low band saturated
BM_LBSAT    EQU (1<<LBSAT)       

HBSAT       EQU 1       ; LNA High band saturated
BM_HBSAT    EQU (1<<HBSAT)       

XRDY       EQU 2       ; XTO ready
BM_XRDY    EQU (1<<XRDY)       

PLCK       EQU 3       ; PLL locked
BM_PLCK    EQU (1<<PLCK)       

ANTS       EQU 4       ; Antenna saturated
BM_ANTS    EQU (1<<ANTS)       

; FETN4 - Front-End RC Tuning 4bit Register
CTN40       EQU 0       ; 4 bit Capacitor Tuning bit 0
BM_CTN40    EQU (1<<CTN40)       

CTN41       EQU 1       ; 4 bit Capacitor Tuning bit 1
BM_CTN41    EQU (1<<CTN41)       

CTN42       EQU 2       ; 4 bit Capacitor Tuning bit 2
BM_CTN42    EQU (1<<CTN42)       

CTN43       EQU 3       ; 4 bit Capacitor Tuning bit 3
BM_CTN43    EQU (1<<CTN43)       

RTN40       EQU 4       ; 4 bit Resistor Tuning bit 0
BM_RTN40    EQU (1<<RTN40)       

RTN41       EQU 5       ; 4 bit Resistor Tuning bit 1
BM_RTN41    EQU (1<<RTN41)       

RTN42       EQU 6       ; 4 bit Resistor Tuning bit 2
BM_RTN42    EQU (1<<RTN42)       

RTN43       EQU 7       ; 4 bit Resistor Tuning bit 3
BM_RTN43    EQU (1<<RTN43)       

; FEVCO - Front-End VCO and PLL control
CPCC0       EQU 0       ; Charge pump current control bit 0
BM_CPCC0    EQU (1<<CPCC0)       

CPCC1       EQU 1       ; Charge pump current control bit 1
BM_CPCC1    EQU (1<<CPCC1)       

CPCC2       EQU 2       ; Charge pump current control bit 2
BM_CPCC2    EQU (1<<CPCC2)       

CPCC3       EQU 3       ; Charge pump current control bit 3
BM_CPCC3    EQU (1<<CPCC3)       

VCOB0       EQU 4       ; VCO Bias bit 0
BM_VCOB0    EQU (1<<VCOB0)       

VCOB1       EQU 5       ; VCO Bias bit 1
BM_VCOB1    EQU (1<<VCOB1)       

VCOB2       EQU 6       ; VCO Bias bit 2
BM_VCOB2    EQU (1<<VCOB2)       

VCOB3       EQU 7       ; VCO Bias bit 3
BM_VCOB3    EQU (1<<VCOB3)       

; FEVCT - Front-End VCO Tuning Register
FEVCT0       EQU 0       ; Front-End VCO Tuning Register bit 0
BM_FEVCT0    EQU (1<<FEVCT0)       

FEVCT1       EQU 1       ; Front-End VCO Tuning Register bit 1
BM_FEVCT1    EQU (1<<FEVCT1)       

FEVCT2       EQU 2       ; Front-End VCO Tuning Register bit 2
BM_FEVCT2    EQU (1<<FEVCT2)       

FEVCT3       EQU 3       ; Front-End VCO Tuning Register bit 3
BM_FEVCT3    EQU (1<<FEVCT3)       

; ***** FRSYNC ***********************
; SFID1A - Start-Frame ID byte 1 for data path A
SFID1A0       EQU 0       ; Start-Frame ID byte 1 for data path A bit 0
BM_SFID1A0    EQU (1<<SFID1A0)       

SFID1A1       EQU 1       ; Start-Frame ID byte 1 for data path A bit 1
BM_SFID1A1    EQU (1<<SFID1A1)       

SFID1A2       EQU 2       ; Start-Frame ID byte 1 for data path A bit 2
BM_SFID1A2    EQU (1<<SFID1A2)       

SFID1A3       EQU 3       ; Start-Frame ID byte 1 for data path A bit 3
BM_SFID1A3    EQU (1<<SFID1A3)       

SFID1A4       EQU 4       ; Start-Frame ID byte 1 for data path A bit 4
BM_SFID1A4    EQU (1<<SFID1A4)       

SFID1A5       EQU 5       ; Start-Frame ID byte 1 for data path A bit 5
BM_SFID1A5    EQU (1<<SFID1A5)       

SFID1A6       EQU 6       ; Start-Frame ID byte 1 for data path A bit 6
BM_SFID1A6    EQU (1<<SFID1A6)       

SFID1A7       EQU 7       ; Start-Frame ID byte 1 for data path A bit 7
BM_SFID1A7    EQU (1<<SFID1A7)       

; SFID1B - Start-Frame ID byte 1 for data path B
SFID1B0       EQU 0       ; Start-Frame ID byte 1 for data path B bit 0
BM_SFID1B0    EQU (1<<SFID1B0)       

SFID1B1       EQU 1       ; Start-Frame ID byte 1 for data path B bit 1
BM_SFID1B1    EQU (1<<SFID1B1)       

SFID1B2       EQU 2       ; Start-Frame ID byte 1 for data path B bit 2
BM_SFID1B2    EQU (1<<SFID1B2)       

SFID1B3       EQU 3       ; Start-Frame ID byte 1 for data path B bit 3
BM_SFID1B3    EQU (1<<SFID1B3)       

SFID1B4       EQU 4       ; Start-Frame ID byte 1 for data path B bit 4
BM_SFID1B4    EQU (1<<SFID1B4)       

SFID1B5       EQU 5       ; Start-Frame ID byte 1 for data path B bit 5
BM_SFID1B5    EQU (1<<SFID1B5)       

SFID1B6       EQU 6       ; Start-Frame ID byte 1 for data path B bit 6
BM_SFID1B6    EQU (1<<SFID1B6)       

SFID1B7       EQU 7       ; Start-Frame ID byte 1 for data path B bit 7
BM_SFID1B7    EQU (1<<SFID1B7)       

; SFID2A - Start-Frame ID byte 2 for data path A
SFID2A0       EQU 0       ; Start-Frame ID byte 2 for data path A bit 0
BM_SFID2A0    EQU (1<<SFID2A0)       

SFID2A1       EQU 1       ; Start-Frame ID byte 2 for data path A bit 1
BM_SFID2A1    EQU (1<<SFID2A1)       

SFID2A2       EQU 2       ; Start-Frame ID byte 2 for data path A bit 2
BM_SFID2A2    EQU (1<<SFID2A2)       

SFID2A3       EQU 3       ; Start-Frame ID byte 2 for data path A bit 3
BM_SFID2A3    EQU (1<<SFID2A3)       

SFID2A4       EQU 4       ; Start-Frame ID byte 2 for data path A bit 4
BM_SFID2A4    EQU (1<<SFID2A4)       

SFID2A5       EQU 5       ; Start-Frame ID byte 2 for data path A bit 5
BM_SFID2A5    EQU (1<<SFID2A5)       

SFID2A6       EQU 6       ; Start-Frame ID byte 2 for data path A bit 6
BM_SFID2A6    EQU (1<<SFID2A6)       

SFID2A7       EQU 7       ; Start-Frame ID byte 2 for data path A bit 7
BM_SFID2A7    EQU (1<<SFID2A7)       

; SFID2B - Start-Frame ID byte 2 for data path B
SFID2B0       EQU 0       ; Start-Frame ID byte 2 for data path B bit 0
BM_SFID2B0    EQU (1<<SFID2B0)       

SFID2B1       EQU 1       ; Start-Frame ID byte 2 for data path B bit 1
BM_SFID2B1    EQU (1<<SFID2B1)       

SFID2B2       EQU 2       ; Start-Frame ID byte 2 for data path B bit 2
BM_SFID2B2    EQU (1<<SFID2B2)       

SFID2B3       EQU 3       ; Start-Frame ID byte 2 for data path B bit 3
BM_SFID2B3    EQU (1<<SFID2B3)       

SFID2B4       EQU 4       ; Start-Frame ID byte 2 for data path B bit 4
BM_SFID2B4    EQU (1<<SFID2B4)       

SFID2B5       EQU 5       ; Start-Frame ID byte 2 for data path B bit 5
BM_SFID2B5    EQU (1<<SFID2B5)       

SFID2B6       EQU 6       ; Start-Frame ID byte 2 for data path B bit 6
BM_SFID2B6    EQU (1<<SFID2B6)       

SFID2B7       EQU 7       ; Start-Frame ID byte 2 for data path B bit 7
BM_SFID2B7    EQU (1<<SFID2B7)       

; SFID3A - Start-Frame ID byte 3 for data path A
SFID3A0       EQU 0       ; Start-Frame ID byte 3 for data path A bit 0
BM_SFID3A0    EQU (1<<SFID3A0)       

SFID3A1       EQU 1       ; Start-Frame ID byte 3 for data path A bit 1
BM_SFID3A1    EQU (1<<SFID3A1)       

SFID3A2       EQU 2       ; Start-Frame ID byte 3 for data path A bit 2
BM_SFID3A2    EQU (1<<SFID3A2)       

SFID3A3       EQU 3       ; Start-Frame ID byte 3 for data path A bit 3
BM_SFID3A3    EQU (1<<SFID3A3)       

SFID3A4       EQU 4       ; Start-Frame ID byte 3 for data path A bit 4
BM_SFID3A4    EQU (1<<SFID3A4)       

SFID3A5       EQU 5       ; Start-Frame ID byte 3 for data path A bit 5
BM_SFID3A5    EQU (1<<SFID3A5)       

SFID3A6       EQU 6       ; Start-Frame ID byte 3 for data path A bit 6
BM_SFID3A6    EQU (1<<SFID3A6)       

SFID3A7       EQU 7       ; Start-Frame ID byte 3 for data path A bit 7
BM_SFID3A7    EQU (1<<SFID3A7)       

; SFID3B - Start-Frame ID byte 3 for data path B
SFID3B0       EQU 0       ; Start-Frame ID byte 3 for data path B bit 0
BM_SFID3B0    EQU (1<<SFID3B0)       

SFID3B1       EQU 1       ; Start-Frame ID byte 3 for data path B bit 1
BM_SFID3B1    EQU (1<<SFID3B1)       

SFID3B2       EQU 2       ; Start-Frame ID byte 3 for data path B bit 2
BM_SFID3B2    EQU (1<<SFID3B2)       

SFID3B3       EQU 3       ; Start-Frame ID byte 3 for data path B bit 3
BM_SFID3B3    EQU (1<<SFID3B3)       

SFID3B4       EQU 4       ; Start-Frame ID byte 3 for data path B bit 4
BM_SFID3B4    EQU (1<<SFID3B4)       

SFID3B5       EQU 5       ; Start-Frame ID byte 3 for data path B bit 5
BM_SFID3B5    EQU (1<<SFID3B5)       

SFID3B6       EQU 6       ; Start-Frame ID byte 3 for data path B bit 6
BM_SFID3B6    EQU (1<<SFID3B6)       

SFID3B7       EQU 7       ; Start-Frame ID byte 3 for data path B bit 7
BM_SFID3B7    EQU (1<<SFID3B7)       

; SFID4A - Start-Frame ID byte 4 for data path A
SFID4A0       EQU 0       ; Start-Frame ID byte 4 for data path A bit 0
BM_SFID4A0    EQU (1<<SFID4A0)       

SFID4A1       EQU 1       ; Start-Frame ID byte 4 for data path A bit 1
BM_SFID4A1    EQU (1<<SFID4A1)       

SFID4A2       EQU 2       ; Start-Frame ID byte 4 for data path A bit 2
BM_SFID4A2    EQU (1<<SFID4A2)       

SFID4A3       EQU 3       ; Start-Frame ID byte 4 for data path A bit 3
BM_SFID4A3    EQU (1<<SFID4A3)       

SFID4A4       EQU 4       ; Start-Frame ID byte 4 for data path A bit 4
BM_SFID4A4    EQU (1<<SFID4A4)       

SFID4A5       EQU 5       ; Start-Frame ID byte 4 for data path A bit 5
BM_SFID4A5    EQU (1<<SFID4A5)       

SFID4A6       EQU 6       ; Start-Frame ID byte 4 for data path A bit 6
BM_SFID4A6    EQU (1<<SFID4A6)       

SFID4A7       EQU 7       ; Start-Frame ID byte 4 for data path A bit 7
BM_SFID4A7    EQU (1<<SFID4A7)       

; SFID4B - Start-Frame ID byte 4 for data path B
SFID4B0       EQU 0       ; Start-Frame ID byte 4 for data path B bit 0
BM_SFID4B0    EQU (1<<SFID4B0)       

SFID4B1       EQU 1       ; Start-Frame ID byte 4 for data path B bit 1
BM_SFID4B1    EQU (1<<SFID4B1)       

SFID4B2       EQU 2       ; Start-Frame ID byte 4 for data path B bit 2
BM_SFID4B2    EQU (1<<SFID4B2)       

SFID4B3       EQU 3       ; Start-Frame ID byte 4 for data path B bit 3
BM_SFID4B3    EQU (1<<SFID4B3)       

SFID4B4       EQU 4       ; Start-Frame ID byte 4 for data path B bit 4
BM_SFID4B4    EQU (1<<SFID4B4)       

SFID4B5       EQU 5       ; Start-Frame ID byte 4 for data path B bit 5
BM_SFID4B5    EQU (1<<SFID4B5)       

SFID4B6       EQU 6       ; Start-Frame ID byte 4 for data path B bit 6
BM_SFID4B6    EQU (1<<SFID4B6)       

SFID4B7       EQU 7       ; Start-Frame ID byte 4 for data path B bit 7
BM_SFID4B7    EQU (1<<SFID4B7)       

; SFIDCA - Start-Frame ID Control for data path A
SFIDTA0       EQU 0       ; Start-Frame ID threshold for data path A bit 0
BM_SFIDTA0    EQU (1<<SFIDTA0)       

SFIDTA1       EQU 1       ; Start-Frame ID threshold for data path A bit 1
BM_SFIDTA1    EQU (1<<SFIDTA1)       

SFIDTA2       EQU 2       ; Start-Frame ID threshold for data path A bit 2
BM_SFIDTA2    EQU (1<<SFIDTA2)       

SFIDTA3       EQU 3       ; Start-Frame ID threshold for data path A bit 3
BM_SFIDTA3    EQU (1<<SFIDTA3)       

SFIDTA4       EQU 4       ; Start-Frame ID threshold for data path A bit 4
BM_SFIDTA4    EQU (1<<SFIDTA4)       

SEMEA       EQU 7       ; Serial mode enable for data path A
BM_SEMEA    EQU (1<<SEMEA)       

; SFIDCB - Start-Frame ID Control for data path B
SFIDTB0       EQU 0       ; Start-Frame ID threshold for data path B bit 0
BM_SFIDTB0    EQU (1<<SFIDTB0)       

SFIDTB1       EQU 1       ; Start-Frame ID threshold for data path B bit 1
BM_SFIDTB1    EQU (1<<SFIDTB1)       

SFIDTB2       EQU 2       ; Start-Frame ID threshold for data path B bit 2
BM_SFIDTB2    EQU (1<<SFIDTB2)       

SFIDTB3       EQU 3       ; Start-Frame ID threshold for data path B bit 3
BM_SFIDTB3    EQU (1<<SFIDTB3)       

SFIDTB4       EQU 4       ; Start-Frame ID threshold for data path B bit 4
BM_SFIDTB4    EQU (1<<SFIDTB4)       

SEMEB       EQU 7       ; Serial mode enable for data path B
BM_SEMEB    EQU (1<<SEMEB)       

; SFIDLA - Start-Frame ID Length for data path A
SFIDLA0       EQU 0       ; Start-Frame ID Length for data path A bit 0
BM_SFIDLA0    EQU (1<<SFIDLA0)       

SFIDLA1       EQU 1       ; Start-Frame ID Length for data path A bit 1
BM_SFIDLA1    EQU (1<<SFIDLA1)       

SFIDLA2       EQU 2       ; Start-Frame ID Length for data path A bit 2
BM_SFIDLA2    EQU (1<<SFIDLA2)       

SFIDLA3       EQU 3       ; Start-Frame ID Length for data path A bit 3
BM_SFIDLA3    EQU (1<<SFIDLA3)       

SFIDLA4       EQU 4       ; Start-Frame ID Length for data path A bit 4
BM_SFIDLA4    EQU (1<<SFIDLA4)       

SFIDLA5       EQU 5       ; Start-Frame ID Length for data path A bit 5
BM_SFIDLA5    EQU (1<<SFIDLA5)       

; SFIDLB - Start-Frame ID Length for data path B
SFIDLB0       EQU 0       ; Start-Frame ID Length for data path B bit 0
BM_SFIDLB0    EQU (1<<SFIDLB0)       

SFIDLB1       EQU 1       ; Start-Frame ID Length for data path B bit 1
BM_SFIDLB1    EQU (1<<SFIDLB1)       

SFIDLB2       EQU 2       ; Start-Frame ID Length for data path B bit 2
BM_SFIDLB2    EQU (1<<SFIDLB2)       

SFIDLB3       EQU 3       ; Start-Frame ID Length for data path B bit 3
BM_SFIDLB3    EQU (1<<SFIDLB3)       

SFIDLB4       EQU 4       ; Start-Frame ID Length for data path B bit 4
BM_SFIDLB4    EQU (1<<SFIDLB4)       

SFIDLB5       EQU 5       ; Start-Frame ID Length for data path B bit 5
BM_SFIDLB5    EQU (1<<SFIDLB5)       

; WUP1A - Wake-Up Pattern byte 1 for data path A
WUP1A0       EQU 0       ; Wake-Up Pattern byte 1 for data path A bit 0
BM_WUP1A0    EQU (1<<WUP1A0)       

WUP1A1       EQU 1       ; Wake-Up Pattern byte 1 for data path A bit 1
BM_WUP1A1    EQU (1<<WUP1A1)       

WUP1A2       EQU 2       ; Wake-Up Pattern byte 1 for data path A bit 2
BM_WUP1A2    EQU (1<<WUP1A2)       

WUP1A3       EQU 3       ; Wake-Up Pattern byte 1 for data path A bit 3
BM_WUP1A3    EQU (1<<WUP1A3)       

WUP1A4       EQU 4       ; Wake-Up Pattern byte 1 for data path A bit 4
BM_WUP1A4    EQU (1<<WUP1A4)       

WUP1A5       EQU 5       ; Wake-Up Pattern byte 1 for data path A bit 5
BM_WUP1A5    EQU (1<<WUP1A5)       

WUP1A6       EQU 6       ; Wake-Up Pattern byte 1 for data path A bit 6
BM_WUP1A6    EQU (1<<WUP1A6)       

WUP1A7       EQU 7       ; Wake-Up Pattern byte 1 for data path A bit 7
BM_WUP1A7    EQU (1<<WUP1A7)       

; WUP1B - Wake-Up Pattern byte 1 for data path B
WUP1B0       EQU 0       ; Wake-Up Pattern byte 1 for data path B bit 0
BM_WUP1B0    EQU (1<<WUP1B0)       

WUP1B1       EQU 1       ; Wake-Up Pattern byte 1 for data path B bit 1
BM_WUP1B1    EQU (1<<WUP1B1)       

WUP1B2       EQU 2       ; Wake-Up Pattern byte 1 for data path B bit 2
BM_WUP1B2    EQU (1<<WUP1B2)       

WUP1B3       EQU 3       ; Wake-Up Pattern byte 1 for data path B bit 3
BM_WUP1B3    EQU (1<<WUP1B3)       

WUP1B4       EQU 4       ; Wake-Up Pattern byte 1 for data path B bit 4
BM_WUP1B4    EQU (1<<WUP1B4)       

WUP1B5       EQU 5       ; Wake-Up Pattern byte 1 for data path B bit 5
BM_WUP1B5    EQU (1<<WUP1B5)       

WUP1B6       EQU 6       ; Wake-Up Pattern byte 1 for data path B bit 6
BM_WUP1B6    EQU (1<<WUP1B6)       

WUP1B7       EQU 7       ; Wake-Up Pattern byte 1 for data path B bit 7
BM_WUP1B7    EQU (1<<WUP1B7)       

; WUP2A - Wake-Up Pattern byte 2 for data path A
WUP2A0       EQU 0       ; Wake-Up Pattern byte 2 for data path A bit 0
BM_WUP2A0    EQU (1<<WUP2A0)       

WUP2A1       EQU 1       ; Wake-Up Pattern byte 2 for data path A bit 1
BM_WUP2A1    EQU (1<<WUP2A1)       

WUP2A2       EQU 2       ; Wake-Up Pattern byte 2 for data path A bit 2
BM_WUP2A2    EQU (1<<WUP2A2)       

WUP2A3       EQU 3       ; Wake-Up Pattern byte 2 for data path A bit 3
BM_WUP2A3    EQU (1<<WUP2A3)       

WUP2A4       EQU 4       ; Wake-Up Pattern byte 2 for data path A bit 4
BM_WUP2A4    EQU (1<<WUP2A4)       

WUP2A5       EQU 5       ; Wake-Up Pattern byte 2 for data path A bit 5
BM_WUP2A5    EQU (1<<WUP2A5)       

WUP2A6       EQU 6       ; Wake-Up Pattern byte 2 for data path A bit 6
BM_WUP2A6    EQU (1<<WUP2A6)       

WUP2A7       EQU 7       ; Wake-Up Pattern byte 2 for data path A bit 7
BM_WUP2A7    EQU (1<<WUP2A7)       

; WUP2B - Wake-Up Pattern byte 2 for data path B
WUP2B0       EQU 0       ; Wake-Up Pattern byte 2 for data path B bit 0
BM_WUP2B0    EQU (1<<WUP2B0)       

WUP2B1       EQU 1       ; Wake-Up Pattern byte 2 for data path B bit 1
BM_WUP2B1    EQU (1<<WUP2B1)       

WUP2B2       EQU 2       ; Wake-Up Pattern byte 2 for data path B bit 2
BM_WUP2B2    EQU (1<<WUP2B2)       

WUP2B3       EQU 3       ; Wake-Up Pattern byte 2 for data path B bit 3
BM_WUP2B3    EQU (1<<WUP2B3)       

WUP2B4       EQU 4       ; Wake-Up Pattern byte 2 for data path B bit 4
BM_WUP2B4    EQU (1<<WUP2B4)       

WUP2B5       EQU 5       ; Wake-Up Pattern byte 2 for data path B bit 5
BM_WUP2B5    EQU (1<<WUP2B5)       

WUP2B6       EQU 6       ; Wake-Up Pattern byte 2 for data path B bit 6
BM_WUP2B6    EQU (1<<WUP2B6)       

WUP2B7       EQU 7       ; Wake-Up Pattern byte 2 for data path B bit 7
BM_WUP2B7    EQU (1<<WUP2B7)       

; WUP3A - Wake-Up Pattern byte 3 for data path A
WUP3A0       EQU 0       ; Wake-Up Pattern byte 3 for data path A bit 0
BM_WUP3A0    EQU (1<<WUP3A0)       

WUP3A1       EQU 1       ; Wake-Up Pattern byte 3 for data path A bit 1
BM_WUP3A1    EQU (1<<WUP3A1)       

WUP3A2       EQU 2       ; Wake-Up Pattern byte 3 for data path A bit 2
BM_WUP3A2    EQU (1<<WUP3A2)       

WUP3A3       EQU 3       ; Wake-Up Pattern byte 3 for data path A bit 3
BM_WUP3A3    EQU (1<<WUP3A3)       

WUP3A4       EQU 4       ; Wake-Up Pattern byte 3 for data path A bit 4
BM_WUP3A4    EQU (1<<WUP3A4)       

WUP3A5       EQU 5       ; Wake-Up Pattern byte 3 for data path A bit 5
BM_WUP3A5    EQU (1<<WUP3A5)       

WUP3A6       EQU 6       ; Wake-Up Pattern byte 3 for data path A bit 6
BM_WUP3A6    EQU (1<<WUP3A6)       

WUP3A7       EQU 7       ; Wake-Up Pattern byte 3 for data path A bit 7
BM_WUP3A7    EQU (1<<WUP3A7)       

; WUP3B - Wake-Up Pattern byte 3 for data path B
WUP3B0       EQU 0       ; Wake-Up Pattern byte 3 for data path B bit 0
BM_WUP3B0    EQU (1<<WUP3B0)       

WUP3B1       EQU 1       ; Wake-Up Pattern byte 3 for data path B bit 1
BM_WUP3B1    EQU (1<<WUP3B1)       

WUP3B2       EQU 2       ; Wake-Up Pattern byte 3 for data path B bit 2
BM_WUP3B2    EQU (1<<WUP3B2)       

WUP3B3       EQU 3       ; Wake-Up Pattern byte 3 for data path B bit 3
BM_WUP3B3    EQU (1<<WUP3B3)       

WUP3B4       EQU 4       ; Wake-Up Pattern byte 3 for data path B bit 4
BM_WUP3B4    EQU (1<<WUP3B4)       

WUP3B5       EQU 5       ; Wake-Up Pattern byte 3 for data path B bit 5
BM_WUP3B5    EQU (1<<WUP3B5)       

WUP3B6       EQU 6       ; Wake-Up Pattern byte 3 for data path B bit 6
BM_WUP3B6    EQU (1<<WUP3B6)       

WUP3B7       EQU 7       ; Wake-Up Pattern byte 3 for data path B bit 7
BM_WUP3B7    EQU (1<<WUP3B7)       

; WUP4A - Wake-Up Pattern byte 4 for data path A
WUP4A0       EQU 0       ; Wake-Up Pattern byte 4 for data path A bit 0
BM_WUP4A0    EQU (1<<WUP4A0)       

WUP4A1       EQU 1       ; Wake-Up Pattern byte 4 for data path A bit 1
BM_WUP4A1    EQU (1<<WUP4A1)       

WUP4A2       EQU 2       ; Wake-Up Pattern byte 4 for data path A bit 2
BM_WUP4A2    EQU (1<<WUP4A2)       

WUP4A3       EQU 3       ; Wake-Up Pattern byte 4 for data path A bit 3
BM_WUP4A3    EQU (1<<WUP4A3)       

WUP4A4       EQU 4       ; Wake-Up Pattern byte 4 for data path A bit 4
BM_WUP4A4    EQU (1<<WUP4A4)       

WUP4A5       EQU 5       ; Wake-Up Pattern byte 4 for data path A bit 5
BM_WUP4A5    EQU (1<<WUP4A5)       

WUP4A6       EQU 6       ; Wake-Up Pattern byte 4 for data path A bit 6
BM_WUP4A6    EQU (1<<WUP4A6)       

WUP4A7       EQU 7       ; Wake-Up Pattern byte 4 for data path A bit 7
BM_WUP4A7    EQU (1<<WUP4A7)       

; WUP4B - Wake-Up Pattern byte 4 for data path B
WUP4B0       EQU 0       ; Wake-Up Pattern byte 4 for data path B bit 0
BM_WUP4B0    EQU (1<<WUP4B0)       

WUP4B1       EQU 1       ; Wake-Up Pattern byte 4 for data path B bit 1
BM_WUP4B1    EQU (1<<WUP4B1)       

WUP4B2       EQU 2       ; Wake-Up Pattern byte 4 for data path B bit 2
BM_WUP4B2    EQU (1<<WUP4B2)       

WUP4B3       EQU 3       ; Wake-Up Pattern byte 4 for data path B bit 3
BM_WUP4B3    EQU (1<<WUP4B3)       

WUP4B4       EQU 4       ; Wake-Up Pattern byte 4 for data path B bit 4
BM_WUP4B4    EQU (1<<WUP4B4)       

WUP4B5       EQU 5       ; Wake-Up Pattern byte 4 for data path B bit 5
BM_WUP4B5    EQU (1<<WUP4B5)       

WUP4B6       EQU 6       ; Wake-Up Pattern byte 4 for data path B bit 6
BM_WUP4B6    EQU (1<<WUP4B6)       

WUP4B7       EQU 7       ; Wake-Up Pattern byte 4 for data path B bit 7
BM_WUP4B7    EQU (1<<WUP4B7)       

; WUPLA - Wake-Up Pattern Length for data path A
WUPLA0       EQU 0       ; Wake-Up Pattern Length for data path A bit 0
BM_WUPLA0    EQU (1<<WUPLA0)       

WUPLA1       EQU 1       ; Wake-Up Pattern Length for data path A bit 1
BM_WUPLA1    EQU (1<<WUPLA1)       

WUPLA2       EQU 2       ; Wake-Up Pattern Length for data path A bit 2
BM_WUPLA2    EQU (1<<WUPLA2)       

WUPLA3       EQU 3       ; Wake-Up Pattern Length for data path A bit 3
BM_WUPLA3    EQU (1<<WUPLA3)       

WUPLA4       EQU 4       ; Wake-Up Pattern Length for data path A bit 4
BM_WUPLA4    EQU (1<<WUPLA4)       

WUPLA5       EQU 5       ; Wake-Up Pattern Length for data path A bit 5
BM_WUPLA5    EQU (1<<WUPLA5)       

; WUPLB - Wake-Up Pattern Length for data path B
WUPLB0       EQU 0       ; Wake-Up Pattern Length for data path B bit 0
BM_WUPLB0    EQU (1<<WUPLB0)       

WUPLB1       EQU 1       ; Wake-Up Pattern Length for data path B bit 1
BM_WUPLB1    EQU (1<<WUPLB1)       

WUPLB2       EQU 2       ; Wake-Up Pattern Length for data path B bit 2
BM_WUPLB2    EQU (1<<WUPLB2)       

WUPLB3       EQU 3       ; Wake-Up Pattern Length for data path B bit 3
BM_WUPLB3    EQU (1<<WUPLB3)       

WUPLB4       EQU 4       ; Wake-Up Pattern Length for data path B bit 4
BM_WUPLB4    EQU (1<<WUPLB4)       

WUPLB5       EQU 5       ; Wake-Up Pattern Length for data path B bit 5
BM_WUPLB5    EQU (1<<WUPLB5)       

; WUPTA - Wake-Up Pattern Threshold for data path A
WUPTA0       EQU 0       ; Wake-Up Pattern Threshold for data path A bit 0
BM_WUPTA0    EQU (1<<WUPTA0)       

WUPTA1       EQU 1       ; Wake-Up Pattern Threshold for data path A bit 1
BM_WUPTA1    EQU (1<<WUPTA1)       

WUPTA2       EQU 2       ; Wake-Up Pattern Threshold for data path A bit 2
BM_WUPTA2    EQU (1<<WUPTA2)       

WUPTA3       EQU 3       ; Wake-Up Pattern Threshold for data path A bit 3
BM_WUPTA3    EQU (1<<WUPTA3)       

WUPTA4       EQU 4       ; Wake-Up Pattern Threshold for data path A bit 4
BM_WUPTA4    EQU (1<<WUPTA4)       

; WUPTB - Wake-Up Pattern Threshold for data path B
WUPTB0       EQU 0       ; Wake-Up Pattern Threshold for data path B bit 0
BM_WUPTB0    EQU (1<<WUPTB0)       

WUPTB1       EQU 1       ; Wake-Up Pattern Threshold for data path B bit 1
BM_WUPTB1    EQU (1<<WUPTB1)       

WUPTB2       EQU 2       ; Wake-Up Pattern Threshold for data path B bit 2
BM_WUPTB2    EQU (1<<WUPTB2)       

WUPTB3       EQU 3       ; Wake-Up Pattern Threshold for data path B bit 3
BM_WUPTB3    EQU (1<<WUPTB3)       

WUPTB4       EQU 4       ; Wake-Up Pattern Threshold for data path B bit 4
BM_WUPTB4    EQU (1<<WUPTB4)       

; ***** GPIOREGS *********************
; GPIOR0 - General Purpose I/O Register 0
GPIOR00       EQU 0       ; 
BM_GPIOR00    EQU (1<<GPIOR00)       

GPIOR01       EQU 1       ; 
BM_GPIOR01    EQU (1<<GPIOR01)       

GPIOR02       EQU 2       ; 
BM_GPIOR02    EQU (1<<GPIOR02)       

GPIOR03       EQU 3       ; 
BM_GPIOR03    EQU (1<<GPIOR03)       

GPIOR04       EQU 4       ; 
BM_GPIOR04    EQU (1<<GPIOR04)       

GPIOR05       EQU 5       ; 
BM_GPIOR05    EQU (1<<GPIOR05)       

GPIOR06       EQU 6       ; 
BM_GPIOR06    EQU (1<<GPIOR06)       

GPIOR07       EQU 7       ; 
BM_GPIOR07    EQU (1<<GPIOR07)       

; GPIOR1 - General Purpose I/O Register 1
GPIOR10       EQU 0       ; 
BM_GPIOR10    EQU (1<<GPIOR10)       

GPIOR11       EQU 1       ; 
BM_GPIOR11    EQU (1<<GPIOR11)       

GPIOR12       EQU 2       ; 
BM_GPIOR12    EQU (1<<GPIOR12)       

GPIOR13       EQU 3       ; 
BM_GPIOR13    EQU (1<<GPIOR13)       

GPIOR14       EQU 4       ; 
BM_GPIOR14    EQU (1<<GPIOR14)       

GPIOR15       EQU 5       ; 
BM_GPIOR15    EQU (1<<GPIOR15)       

GPIOR16       EQU 6       ; 
BM_GPIOR16    EQU (1<<GPIOR16)       

GPIOR17       EQU 7       ; 
BM_GPIOR17    EQU (1<<GPIOR17)       

; GPIOR2 - General Purpose I/O Register 2
GPIOR20       EQU 0       ; 
BM_GPIOR20    EQU (1<<GPIOR20)       

GPIOR21       EQU 1       ; 
BM_GPIOR21    EQU (1<<GPIOR21)       

GPIOR22       EQU 2       ; 
BM_GPIOR22    EQU (1<<GPIOR22)       

GPIOR23       EQU 3       ; 
BM_GPIOR23    EQU (1<<GPIOR23)       

GPIOR24       EQU 4       ; 
BM_GPIOR24    EQU (1<<GPIOR24)       

GPIOR25       EQU 5       ; 
BM_GPIOR25    EQU (1<<GPIOR25)       

GPIOR26       EQU 6       ; 
BM_GPIOR26    EQU (1<<GPIOR26)       

GPIOR27       EQU 7       ; 
BM_GPIOR27    EQU (1<<GPIOR27)       

; GPIOR3 - General Purpose I/O Register 3
GPIOR30       EQU 0       ; 
BM_GPIOR30    EQU (1<<GPIOR30)       

GPIOR31       EQU 1       ; 
BM_GPIOR31    EQU (1<<GPIOR31)       

GPIOR32       EQU 2       ; 
BM_GPIOR32    EQU (1<<GPIOR32)       

GPIOR33       EQU 3       ; 
BM_GPIOR33    EQU (1<<GPIOR33)       

GPIOR34       EQU 4       ; 
BM_GPIOR34    EQU (1<<GPIOR34)       

GPIOR35       EQU 5       ; 
BM_GPIOR35    EQU (1<<GPIOR35)       

GPIOR36       EQU 6       ; 
BM_GPIOR36    EQU (1<<GPIOR36)       

GPIOR37       EQU 7       ; 
BM_GPIOR37    EQU (1<<GPIOR37)       

; GPIOR4 - General Purpose I/O Register 4
GPIOR40       EQU 0       ; 
BM_GPIOR40    EQU (1<<GPIOR40)       

GPIOR41       EQU 1       ; 
BM_GPIOR41    EQU (1<<GPIOR41)       

GPIOR42       EQU 2       ; 
BM_GPIOR42    EQU (1<<GPIOR42)       

GPIOR43       EQU 3       ; 
BM_GPIOR43    EQU (1<<GPIOR43)       

GPIOR44       EQU 4       ; 
BM_GPIOR44    EQU (1<<GPIOR44)       

GPIOR45       EQU 5       ; 
BM_GPIOR45    EQU (1<<GPIOR45)       

GPIOR46       EQU 6       ; 
BM_GPIOR46    EQU (1<<GPIOR46)       

GPIOR47       EQU 7       ; 
BM_GPIOR47    EQU (1<<GPIOR47)       

; GPIOR5 - General Purpose I/O Register 5
GPIOR50       EQU 0       ; 
BM_GPIOR50    EQU (1<<GPIOR50)       

GPIOR51       EQU 1       ; 
BM_GPIOR51    EQU (1<<GPIOR51)       

GPIOR52       EQU 2       ; 
BM_GPIOR52    EQU (1<<GPIOR52)       

GPIOR53       EQU 3       ; 
BM_GPIOR53    EQU (1<<GPIOR53)       

GPIOR54       EQU 4       ; 
BM_GPIOR54    EQU (1<<GPIOR54)       

GPIOR55       EQU 5       ; 
BM_GPIOR55    EQU (1<<GPIOR55)       

GPIOR56       EQU 6       ; 
BM_GPIOR56    EQU (1<<GPIOR56)       

GPIOR57       EQU 7       ; 
BM_GPIOR57    EQU (1<<GPIOR57)       

; GPIOR6 - General Purpose I/O Register 6
GPIOR60       EQU 0       ; 
BM_GPIOR60    EQU (1<<GPIOR60)       

GPIOR61       EQU 1       ; 
BM_GPIOR61    EQU (1<<GPIOR61)       

GPIOR62       EQU 2       ; 
BM_GPIOR62    EQU (1<<GPIOR62)       

GPIOR63       EQU 3       ; 
BM_GPIOR63    EQU (1<<GPIOR63)       

GPIOR64       EQU 4       ; 
BM_GPIOR64    EQU (1<<GPIOR64)       

GPIOR65       EQU 5       ; 
BM_GPIOR65    EQU (1<<GPIOR65)       

GPIOR66       EQU 6       ; 
BM_GPIOR66    EQU (1<<GPIOR66)       

GPIOR67       EQU 7       ; 
BM_GPIOR67    EQU (1<<GPIOR67)       

; ***** IDSCAN ***********************
; IDB0 - ID Byte 0
IDB00       EQU 0       ; ID Byte 0 bit 0
BM_IDB00    EQU (1<<IDB00)       

IDB01       EQU 1       ; ID Byte 0 bit 1
BM_IDB01    EQU (1<<IDB01)       

IDB02       EQU 2       ; ID Byte 0 bit 2
BM_IDB02    EQU (1<<IDB02)       

IDB03       EQU 3       ; ID Byte 0 bit 3
BM_IDB03    EQU (1<<IDB03)       

IDB04       EQU 4       ; ID Byte 0 bit 4
BM_IDB04    EQU (1<<IDB04)       

IDB05       EQU 5       ; ID Byte 0 bit 5
BM_IDB05    EQU (1<<IDB05)       

IDB06       EQU 6       ; ID Byte 0 bit 6
BM_IDB06    EQU (1<<IDB06)       

IDB07       EQU 7       ; ID Byte 0 bit 7
BM_IDB07    EQU (1<<IDB07)       

; IDB1 - ID Byte 1
IDB10       EQU 0       ; ID Byte 1 bit 0
BM_IDB10    EQU (1<<IDB10)       

IDB11       EQU 1       ; ID Byte 1 bit 1
BM_IDB11    EQU (1<<IDB11)       

IDB12       EQU 2       ; ID Byte 1 bit 2
BM_IDB12    EQU (1<<IDB12)       

IDB13       EQU 3       ; ID Byte 1 bit 3
BM_IDB13    EQU (1<<IDB13)       

IDB14       EQU 4       ; ID Byte 1 bit 4
BM_IDB14    EQU (1<<IDB14)       

IDB15       EQU 5       ; ID Byte 1 bit 5
BM_IDB15    EQU (1<<IDB15)       

IDB16       EQU 6       ; ID Byte 1 bit 6
BM_IDB16    EQU (1<<IDB16)       

IDB17       EQU 7       ; ID Byte 1 bit 7
BM_IDB17    EQU (1<<IDB17)       

; IDB2 - ID Byte 2
IDB20       EQU 0       ; ID Byte 2 bit 0
BM_IDB20    EQU (1<<IDB20)       

IDB21       EQU 1       ; ID Byte 2 bit 1
BM_IDB21    EQU (1<<IDB21)       

IDB22       EQU 2       ; ID Byte 2 bit 2
BM_IDB22    EQU (1<<IDB22)       

IDB23       EQU 3       ; ID Byte 2 bit 3
BM_IDB23    EQU (1<<IDB23)       

IDB24       EQU 4       ; ID Byte 2 bit 4
BM_IDB24    EQU (1<<IDB24)       

IDB25       EQU 5       ; ID Byte 2 bit 5
BM_IDB25    EQU (1<<IDB25)       

IDB26       EQU 6       ; ID Byte 2 bit 6
BM_IDB26    EQU (1<<IDB26)       

IDB27       EQU 7       ; ID Byte 2 bit 7
BM_IDB27    EQU (1<<IDB27)       

; IDB3 - ID Byte 3
IDB30       EQU 0       ; ID Byte 3 bit 0
BM_IDB30    EQU (1<<IDB30)       

IDB31       EQU 1       ; ID Byte 3 bit 1
BM_IDB31    EQU (1<<IDB31)       

IDB32       EQU 2       ; ID Byte 3 bit 2
BM_IDB32    EQU (1<<IDB32)       

IDB33       EQU 3       ; ID Byte 3 bit 3
BM_IDB33    EQU (1<<IDB33)       

IDB34       EQU 4       ; ID Byte 3 bit 4
BM_IDB34    EQU (1<<IDB34)       

IDB35       EQU 5       ; ID Byte 3 bit 5
BM_IDB35    EQU (1<<IDB35)       

IDB36       EQU 6       ; ID Byte 3 bit 6
BM_IDB36    EQU (1<<IDB36)       

IDB37       EQU 7       ; ID Byte 3 bit 7
BM_IDB37    EQU (1<<IDB37)       

; IDC - ID Configuration
IDL0       EQU 0       ; ID Length bit 0
BM_IDL0    EQU (1<<IDL0)       

IDL1       EQU 1       ; ID Length bit 1
BM_IDL1    EQU (1<<IDL1)       

IDBO0       EQU 2       ; ID Byte Offset bit 0
BM_IDBO0    EQU (1<<IDBO0)       

IDBO1       EQU 3       ; ID Byte Offset bit 1
BM_IDBO1    EQU (1<<IDBO1)       

IDFIM       EQU 5       ; ID Full Interrupt Mask
BM_IDFIM    EQU (1<<IDFIM)       

IDCLR       EQU 6       ; ID Clear
BM_IDCLR    EQU (1<<IDCLR)       

IDCE       EQU 7       ; ID Check Execute
BM_IDCE    EQU (1<<IDCE)       

; IDS - ID Status
IDOK       EQU 0       ; ID Scan Ok Flag
BM_IDOK    EQU (1<<IDOK)       

IDFULL       EQU 1       ; ID Full Flag
BM_IDFULL    EQU (1<<IDFULL)       

; ***** INT **************************
; EICRA - External Interrupt control Register
ISC00       EQU 0       ; Interrupt Sense Control 0 bit 0
BM_ISC00    EQU (1<<ISC00)       

ISC01       EQU 1       ; Interrupt Sense Control 0 bit 1
BM_ISC01    EQU (1<<ISC01)       

ISC10       EQU 2       ; Interrupt Sense Control 1 bit 0
BM_ISC10    EQU (1<<ISC10)       

ISC11       EQU 3       ; Interrupt Sense Control 1 bit 1
BM_ISC11    EQU (1<<ISC11)       

; EIFR - External Interrupt Flag Register
INTF0       EQU 0       ; External Interrupt Flag 0
BM_INTF0    EQU (1<<INTF0)       

INTF1       EQU 1       ; External Interrupt Flag 1
BM_INTF1    EQU (1<<INTF1)       

; EIMSK - External Interrupt Mask Register
INT0       EQU 0       ; External Interrupt Request 0 Enable
BM_INT0    EQU (1<<INT0)       

INT1       EQU 1       ; External Interrupt Request 1 Enable
BM_INT1    EQU (1<<INT1)       

; PCICR - Pin change Interrupt control Register
PCIE0       EQU 0       ; Pin Change Interrupt Enable 0
BM_PCIE0    EQU (1<<PCIE0)       

PCIE1       EQU 1       ; Pin Change Interrupt Enable 1
BM_PCIE1    EQU (1<<PCIE1)       

; PCIFR - Pin change Interrupt flag Register
PCIF0       EQU 0       ; Pin Change Interrupt Flag 0
BM_PCIF0    EQU (1<<PCIF0)       

PCIF1       EQU 1       ; Pin Change Interrupt Flag 1
BM_PCIF1    EQU (1<<PCIF1)       

; PCMSK0 - Pin change Mask Register 0
PCINT0       EQU 0       ; Pin Change Enable Mask bit 0
BM_PCINT0    EQU (1<<PCINT0)       

PCINT1       EQU 1       ; Pin Change Enable Mask bit 1
BM_PCINT1    EQU (1<<PCINT1)       

PCINT2       EQU 2       ; Pin Change Enable Mask bit 2
BM_PCINT2    EQU (1<<PCINT2)       

PCINT3       EQU 3       ; Pin Change Enable Mask bit 3
BM_PCINT3    EQU (1<<PCINT3)       

PCINT4       EQU 4       ; Pin Change Enable Mask bit 4
BM_PCINT4    EQU (1<<PCINT4)       

PCINT5       EQU 5       ; Pin Change Enable Mask bit 5
BM_PCINT5    EQU (1<<PCINT5)       

PCINT6       EQU 6       ; Pin Change Enable Mask bit 6
BM_PCINT6    EQU (1<<PCINT6)       

PCINT7       EQU 7       ; Pin Change Enable Mask bit 7
BM_PCINT7    EQU (1<<PCINT7)       

; PCMSK1 - Pin change Mask Register 1
PCINT8       EQU 0       ; Pin Change Enable Mask bit 8
BM_PCINT8    EQU (1<<PCINT8)       

PCINT9       EQU 1       ; Pin Change Enable Mask bit 9
BM_PCINT9    EQU (1<<PCINT9)       

PCINT10       EQU 2       ; Pin Change Enable Mask bit 10
BM_PCINT10    EQU (1<<PCINT10)       

PCINT11       EQU 3       ; Pin Change Enable Mask bit 11
BM_PCINT11    EQU (1<<PCINT11)       

PCINT12       EQU 4       ; Pin Change Enable Mask bit 12
BM_PCINT12    EQU (1<<PCINT12)       

PCINT13       EQU 5       ; Pin Change Enable Mask bit 13
BM_PCINT13    EQU (1<<PCINT13)       

; ***** MEM **************************
; EEST - EEPROM Status Register
EESYN0       EQU 0       ; EEPROM Syndrome bit 0
BM_EESYN0    EQU (1<<EESYN0)       

EESYN1       EQU 1       ; EEPROM Syndrome bit 1
BM_EESYN1    EQU (1<<EESYN1)       

EESYN2       EQU 2       ; EEPROM Syndrome bit 2
BM_EESYN2    EQU (1<<EESYN2)       

EESYN3       EQU 3       ; EEPROM Syndrome bit 3
BM_EESYN3    EQU (1<<EESYN3)       

; PGMST - Program Memory Status Register
PGMSYN0       EQU 0       ; Program Memory Syndrome bit 0
BM_PGMSYN0    EQU (1<<PGMSYN0)       

PGMSYN1       EQU 1       ; Program Memory Syndrome bit 1
BM_PGMSYN1    EQU (1<<PGMSYN1)       

PGMSYN2       EQU 2       ; Program Memory Syndrome bit 2
BM_PGMSYN2    EQU (1<<PGMSYN2)       

PGMSYN3       EQU 3       ; Program Memory Syndrome bit 3
BM_PGMSYN3    EQU (1<<PGMSYN3)       

PGMSYN4       EQU 4       ; Program Memory Syndrome bit 4
BM_PGMSYN4    EQU (1<<PGMSYN4)       

; ***** PORTB ************************
; DDRB - Port B Data Direction Register
DDRB0       EQU 0       ; Port B Data Direction Register bit 0
BM_DDRB0    EQU (1<<DDRB0)       

DDRB1       EQU 1       ; Port B Data Direction Register bit 1
BM_DDRB1    EQU (1<<DDRB1)       

DDRB2       EQU 2       ; Port B Data Direction Register bit 2
BM_DDRB2    EQU (1<<DDRB2)       

DDRB3       EQU 3       ; Port B Data Direction Register bit 3
BM_DDRB3    EQU (1<<DDRB3)       

DDRB4       EQU 4       ; Port B Data Direction Register bit 4
BM_DDRB4    EQU (1<<DDRB4)       

DDRB5       EQU 5       ; Port B Data Direction Register bit 5
BM_DDRB5    EQU (1<<DDRB5)       

DDRB6       EQU 6       ; Port B Data Direction Register bit 6
BM_DDRB6    EQU (1<<DDRB6)       

DDRB7       EQU 7       ; Port B Data Direction Register bit 7
BM_DDRB7    EQU (1<<DDRB7)       

; PINB - Port B Input Pins
PINB0       EQU 0       ; Port B Input Pins bit 0
BM_PINB0    EQU (1<<PINB0)       

PINB1       EQU 1       ; Port B Input Pins bit 1
BM_PINB1    EQU (1<<PINB1)       

PINB2       EQU 2       ; Port B Input Pins bit 2
BM_PINB2    EQU (1<<PINB2)       

PINB3       EQU 3       ; Port B Input Pins bit 3
BM_PINB3    EQU (1<<PINB3)       

PINB4       EQU 4       ; Port B Input Pins bit 4
BM_PINB4    EQU (1<<PINB4)       

PINB5       EQU 5       ; Port B Input Pins bit 5
BM_PINB5    EQU (1<<PINB5)       

PINB6       EQU 6       ; Port B Input Pins bit 6
BM_PINB6    EQU (1<<PINB6)       

PINB7       EQU 7       ; Port B Input Pins bit 7
BM_PINB7    EQU (1<<PINB7)       

; PORTB - Port B Data Register
PORTB0       EQU 0       ; Port B Data Register bit 0
BM_PORTB0    EQU (1<<PORTB0)       

PB0       EQU 0       ; For compatibility
BM_PB0    EQU (1<<PB0)       

PORTB1       EQU 1       ; Port B Data Register bit 1
BM_PORTB1    EQU (1<<PORTB1)       

PB1       EQU 1       ; For compatibility
BM_PB1    EQU (1<<PB1)       

PORTB2       EQU 2       ; Port B Data Register bit 2
BM_PORTB2    EQU (1<<PORTB2)       

PB2       EQU 2       ; For compatibility
BM_PB2    EQU (1<<PB2)       

PORTB3       EQU 3       ; Port B Data Register bit 3
BM_PORTB3    EQU (1<<PORTB3)       

PB3       EQU 3       ; For compatibility
BM_PB3    EQU (1<<PB3)       

PORTB4       EQU 4       ; Port B Data Register bit 4
BM_PORTB4    EQU (1<<PORTB4)       

PB4       EQU 4       ; For compatibility
BM_PB4    EQU (1<<PB4)       

PORTB5       EQU 5       ; Port B Data Register bit 5
BM_PORTB5    EQU (1<<PORTB5)       

PB5       EQU 5       ; For compatibility
BM_PB5    EQU (1<<PB5)       

PORTB6       EQU 6       ; Port B Data Register bit 6
BM_PORTB6    EQU (1<<PORTB6)       

PB6       EQU 6       ; For compatibility
BM_PB6    EQU (1<<PB6)       

PORTB7       EQU 7       ; Port B Data Register bit 7
BM_PORTB7    EQU (1<<PORTB7)       

PB7       EQU 7       ; For compatibility
BM_PB7    EQU (1<<PB7)       

; ***** PORTC ************************
; DDRC - Port C Data Direction Register
DDRC0       EQU 0       ; Port C Data Direction Register bit 0
BM_DDRC0    EQU (1<<DDRC0)       

DDRC1       EQU 1       ; Port C Data Direction Register bit 1
BM_DDRC1    EQU (1<<DDRC1)       

DDRC2       EQU 2       ; Port C Data Direction Register bit 2
BM_DDRC2    EQU (1<<DDRC2)       

DDRC3       EQU 3       ; Port C Data Direction Register bit 3
BM_DDRC3    EQU (1<<DDRC3)       

DDRC4       EQU 4       ; Port C Data Direction Register bit 4
BM_DDRC4    EQU (1<<DDRC4)       

DDRC5       EQU 5       ; Port C Data Direction Register bit 5
BM_DDRC5    EQU (1<<DDRC5)       

; PINC - Port C Input Pins
PINC0       EQU 0       ; Port C Input Pins bit 0
BM_PINC0    EQU (1<<PINC0)       

PINC1       EQU 1       ; Port C Input Pins bit 1
BM_PINC1    EQU (1<<PINC1)       

PINC2       EQU 2       ; Port C Input Pins bit 2
BM_PINC2    EQU (1<<PINC2)       

PINC3       EQU 3       ; Port C Input Pins bit 3
BM_PINC3    EQU (1<<PINC3)       

PINC4       EQU 4       ; Port C Input Pins bit 4
BM_PINC4    EQU (1<<PINC4)       

PINC5       EQU 5       ; Port C Input Pins bit 5
BM_PINC5    EQU (1<<PINC5)       

; PORTC - Port C Data Register
PORTC0       EQU 0       ; Port C Data Register bit 0
BM_PORTC0    EQU (1<<PORTC0)       

PC0       EQU 0       ; For compatibility
BM_PC0    EQU (1<<PC0)       

PORTC1       EQU 1       ; Port C Data Register bit 1
BM_PORTC1    EQU (1<<PORTC1)       

PC1       EQU 1       ; For compatibility
BM_PC1    EQU (1<<PC1)       

PORTC2       EQU 2       ; Port C Data Register bit 2
BM_PORTC2    EQU (1<<PORTC2)       

PC2       EQU 2       ; For compatibility
BM_PC2    EQU (1<<PC2)       

PORTC3       EQU 3       ; Port C Data Register bit 3
BM_PORTC3    EQU (1<<PORTC3)       

PC3       EQU 3       ; For compatibility
BM_PC3    EQU (1<<PC3)       

PORTC4       EQU 4       ; Port C Data Register bit 4
BM_PORTC4    EQU (1<<PORTC4)       

PC4       EQU 4       ; For compatibility
BM_PC4    EQU (1<<PC4)       

PORTC5       EQU 5       ; Port C Data Register bit 5
BM_PORTC5    EQU (1<<PORTC5)       

PC5       EQU 5       ; For compatibility
BM_PC5    EQU (1<<PC5)       

; ***** RSSIB ************************
; RSCOM - RSSI Compensation Register
RSDC       EQU 0       ; RSSI Damping Compensation
BM_RSDC    EQU (1<<RSDC)       

RSIFC       EQU 1       ; RSSI IF Amplifier Compensation
BM_RSIFC    EQU (1<<RSIFC)       

; RSHDV - RSSI High Band Damping Value
RSHDV0       EQU 0       ; 
BM_RSHDV0    EQU (1<<RSHDV0)       

RSHDV1       EQU 1       ; 
BM_RSHDV1    EQU (1<<RSHDV1)       

RSHDV2       EQU 2       ; 
BM_RSHDV2    EQU (1<<RSHDV2)       

RSHDV3       EQU 3       ; 
BM_RSHDV3    EQU (1<<RSHDV3)       

RSHDV4       EQU 4       ; 
BM_RSHDV4    EQU (1<<RSHDV4)       

RSHDV5       EQU 5       ; 
BM_RSHDV5    EQU (1<<RSHDV5)       

RSHDV6       EQU 6       ; 
BM_RSHDV6    EQU (1<<RSHDV6)       

RSHDV7       EQU 7       ; 
BM_RSHDV7    EQU (1<<RSHDV7)       

; RSIFG - RSSI High IF Amplifier Gain
RSIFG0       EQU 0       ; 
BM_RSIFG0    EQU (1<<RSIFG0)       

RSIFG1       EQU 1       ; 
BM_RSIFG1    EQU (1<<RSIFG1)       

RSIFG2       EQU 2       ; 
BM_RSIFG2    EQU (1<<RSIFG2)       

RSIFG3       EQU 3       ; 
BM_RSIFG3    EQU (1<<RSIFG3)       

RSIFG4       EQU 4       ; 
BM_RSIFG4    EQU (1<<RSIFG4)       

RSIFG5       EQU 5       ; 
BM_RSIFG5    EQU (1<<RSIFG5)       

RSIFG6       EQU 6       ; 
BM_RSIFG6    EQU (1<<RSIFG6)       

RSIFG7       EQU 7       ; 
BM_RSIFG7    EQU (1<<RSIFG7)       

; RSLDV - RSSI Low Band Damping Value
RSLDV0       EQU 0       ; 
BM_RSLDV0    EQU (1<<RSLDV0)       

RSLDV1       EQU 1       ; 
BM_RSLDV1    EQU (1<<RSLDV1)       

RSLDV2       EQU 2       ; 
BM_RSLDV2    EQU (1<<RSLDV2)       

RSLDV3       EQU 3       ; 
BM_RSLDV3    EQU (1<<RSLDV3)       

RSLDV4       EQU 4       ; 
BM_RSLDV4    EQU (1<<RSLDV4)       

RSLDV5       EQU 5       ; 
BM_RSLDV5    EQU (1<<RSLDV5)       

RSLDV6       EQU 6       ; 
BM_RSLDV6    EQU (1<<RSLDV6)       

RSLDV7       EQU 7       ; 
BM_RSLDV7    EQU (1<<RSLDV7)       

; RSSAV - RSSI Average Value
RSSAV0       EQU 0       ; RSSI Average Value bit 0
BM_RSSAV0    EQU (1<<RSSAV0)       

RSSAV1       EQU 1       ; RSSI Average Value bit 1
BM_RSSAV1    EQU (1<<RSSAV1)       

RSSAV2       EQU 2       ; RSSI Average Value bit 2
BM_RSSAV2    EQU (1<<RSSAV2)       

RSSAV3       EQU 3       ; RSSI Average Value bit 3
BM_RSSAV3    EQU (1<<RSSAV3)       

RSSAV4       EQU 4       ; RSSI Average Value bit 4
BM_RSSAV4    EQU (1<<RSSAV4)       

RSSAV5       EQU 5       ; RSSI Average Value bit 5
BM_RSSAV5    EQU (1<<RSSAV5)       

RSSAV6       EQU 6       ; RSSI Average Value bit 6
BM_RSSAV6    EQU (1<<RSSAV6)       

RSSAV7       EQU 7       ; RSSI Average Value bit 7
BM_RSSAV7    EQU (1<<RSSAV7)       

; RSSC - RSSI Configuration Register
RSUP0       EQU 0       ; RSSI Update Period bit 0
BM_RSUP0    EQU (1<<RSUP0)       

RSUP1       EQU 1       ; RSSI Update Period bit 1
BM_RSUP1    EQU (1<<RSUP1)       

RSUP2       EQU 2       ; RSSI Update Period bit 2
BM_RSUP2    EQU (1<<RSUP2)       

RSUP3       EQU 3       ; RSSI Update Period bit 3
BM_RSUP3    EQU (1<<RSUP3)       

RSWLH       EQU 4       ; RSSI within Low and High Limits
BM_RSWLH    EQU (1<<RSWLH)       

RSHRX       EQU 5       ; RSSI High Band Reception
BM_RSHRX    EQU (1<<RSHRX)       

RSPKF       EQU 6       ; RSSI Peak Values to SFIFO
BM_RSPKF    EQU (1<<RSPKF)       

; RSSH - RSSI High Threshold for Signal Check
RSSH0       EQU 0       ; RSSI High Threshold for Signal Check bit 0
BM_RSSH0    EQU (1<<RSSH0)       

RSSH1       EQU 1       ; RSSI High Threshold for Signal Check bit 1
BM_RSSH1    EQU (1<<RSSH1)       

RSSH2       EQU 2       ; RSSI High Threshold for Signal Check bit 2
BM_RSSH2    EQU (1<<RSSH2)       

RSSH3       EQU 3       ; RSSI High Threshold for Signal Check bit 3
BM_RSSH3    EQU (1<<RSSH3)       

RSSH4       EQU 4       ; RSSI High Threshold for Signal Check bit 4
BM_RSSH4    EQU (1<<RSSH4)       

RSSH5       EQU 5       ; RSSI High Threshold for Signal Check bit 5
BM_RSSH5    EQU (1<<RSSH5)       

RSSH6       EQU 6       ; RSSI High Threshold for Signal Check bit 6
BM_RSSH6    EQU (1<<RSSH6)       

RSSH7       EQU 7       ; RSSI High Threshold for Signal Check bit 7
BM_RSSH7    EQU (1<<RSSH7)       

; RSSL - RSSI Low Threshold for Signal Check
RSSL0       EQU 0       ; RSSI Low Threshold for Signal Check bit 0
BM_RSSL0    EQU (1<<RSSL0)       

RSSL1       EQU 1       ; RSSI Low Threshold for Signal Check bit 1
BM_RSSL1    EQU (1<<RSSL1)       

RSSL2       EQU 2       ; RSSI Low Threshold for Signal Check bit 2
BM_RSSL2    EQU (1<<RSSL2)       

RSSL3       EQU 3       ; RSSI Low Threshold for Signal Check bit 3
BM_RSSL3    EQU (1<<RSSL3)       

RSSL4       EQU 4       ; RSSI Low Threshold for Signal Check bit 4
BM_RSSL4    EQU (1<<RSSL4)       

RSSL5       EQU 5       ; RSSI Low Threshold for Signal Check bit 5
BM_RSSL5    EQU (1<<RSSL5)       

RSSL6       EQU 6       ; RSSI Low Threshold for Signal Check bit 6
BM_RSSL6    EQU (1<<RSSL6)       

RSSL7       EQU 7       ; RSSI Low Threshold for Signal Check bit 7
BM_RSSL7    EQU (1<<RSSL7)       

; RSSPK - RSSI Peak Value
RSSPK0       EQU 0       ; RSSI Peak Value bit 0
BM_RSSPK0    EQU (1<<RSSPK0)       

RSSPK1       EQU 1       ; RSSI Peak Value bit 1
BM_RSSPK1    EQU (1<<RSSPK1)       

RSSPK2       EQU 2       ; RSSI Peak Value bit 2
BM_RSSPK2    EQU (1<<RSSPK2)       

RSSPK3       EQU 3       ; RSSI Peak Value bit 3
BM_RSSPK3    EQU (1<<RSSPK3)       

RSSPK4       EQU 4       ; RSSI Peak Value bit 4
BM_RSSPK4    EQU (1<<RSSPK4)       

RSSPK5       EQU 5       ; RSSI Peak Value bit 5
BM_RSSPK5    EQU (1<<RSSPK5)       

RSSPK6       EQU 6       ; RSSI Peak Value bit 6
BM_RSSPK6    EQU (1<<RSSPK6)       

RSSPK7       EQU 7       ; RSSI Peak Value bit 7
BM_RSSPK7    EQU (1<<RSSPK7)       

; ***** RXBUF ************************
; RXBC1 - Rx Buffer configuration register 1
RXCEA       EQU 0       ; RX CRC Enable data path A
BM_RXCEA    EQU (1<<RXCEA)       

RXCBLA0       EQU 1       ; Receive CRC Bit Lengths setting for data path A bit 0
BM_RXCBLA0    EQU (1<<RXCBLA0)       

RXCBLA1       EQU 2       ; Receive CRC Bit Lengths setting for data path A bit 1
BM_RXCBLA1    EQU (1<<RXCBLA1)       

RXMSBA       EQU 3       ; Receive Data MSB-first for data path A
BM_RXMSBA    EQU (1<<RXMSBA)       

RXCEB       EQU 4       ; RX CRC Enable data path B
BM_RXCEB    EQU (1<<RXCEB)       

RXCBLB0       EQU 5       ; Receive CRC Bit Lengths setting for data path B bit 0
BM_RXCBLB0    EQU (1<<RXCBLB0)       

RXCBLB1       EQU 6       ; Receive CRC Bit Lengths setting for data path B bit 1
BM_RXCBLB1    EQU (1<<RXCBLB1)       

RXMSBB       EQU 7       ; Receive Data MSB-first for data path B
BM_RXMSBB    EQU (1<<RXMSBB)       

; RXBC2 - Rx Buffer configuration register 2
RXBPB       EQU 0       ; RX Buffer Path B select signal
BM_RXBPB    EQU (1<<RXBPB)       

RXBF       EQU 1       ; RX Buffer Finish
BM_RXBF    EQU (1<<RXBF)       

RXBCLR       EQU 2       ; RX Buffer Clear
BM_RXBCLR    EQU (1<<RXBCLR)       

; RXCIHA - Rx CRC Init value high byte for data path A
RXCIHA0       EQU 0       ; Rx CRC Init value (16-bit RXCI) High byte for data path A bit 0
BM_RXCIHA0    EQU (1<<RXCIHA0)       

RXCIHA1       EQU 1       ; Rx CRC Init value (16-bit RXCI) High byte for data path A bit 1
BM_RXCIHA1    EQU (1<<RXCIHA1)       

RXCIHA2       EQU 2       ; Rx CRC Init value (16-bit RXCI) High byte for data path A bit 2
BM_RXCIHA2    EQU (1<<RXCIHA2)       

RXCIHA3       EQU 3       ; Rx CRC Init value (16-bit RXCI) High byte for data path A bit 3
BM_RXCIHA3    EQU (1<<RXCIHA3)       

RXCIHA4       EQU 4       ; Rx CRC Init value (16-bit RXCI) High byte for data path A bit 4
BM_RXCIHA4    EQU (1<<RXCIHA4)       

RXCIHA5       EQU 5       ; Rx CRC Init value (16-bit RXCI) High byte for data path A bit 5
BM_RXCIHA5    EQU (1<<RXCIHA5)       

RXCIHA6       EQU 6       ; Rx CRC Init value (16-bit RXCI) High byte for data path A bit 6
BM_RXCIHA6    EQU (1<<RXCIHA6)       

RXCIHA7       EQU 7       ; Rx CRC Init value (16-bit RXCI) High byte for data path A bit 7
BM_RXCIHA7    EQU (1<<RXCIHA7)       

; RXCIHB - Rx CRC Init value high byte for data path B
RXCIHB0       EQU 0       ; Rx CRC Init value (16-bit RXCI) High byte for data path B bit 0
BM_RXCIHB0    EQU (1<<RXCIHB0)       

RXCIHB1       EQU 1       ; Rx CRC Init value (16-bit RXCI) High byte for data path B bit 1
BM_RXCIHB1    EQU (1<<RXCIHB1)       

RXCIHB2       EQU 2       ; Rx CRC Init value (16-bit RXCI) High byte for data path B bit 2
BM_RXCIHB2    EQU (1<<RXCIHB2)       

RXCIHB3       EQU 3       ; Rx CRC Init value (16-bit RXCI) High byte for data path B bit 3
BM_RXCIHB3    EQU (1<<RXCIHB3)       

RXCIHB4       EQU 4       ; Rx CRC Init value (16-bit RXCI) High byte for data path B bit 4
BM_RXCIHB4    EQU (1<<RXCIHB4)       

RXCIHB5       EQU 5       ; Rx CRC Init value (16-bit RXCI) High byte for data path B bit 5
BM_RXCIHB5    EQU (1<<RXCIHB5)       

RXCIHB6       EQU 6       ; Rx CRC Init value (16-bit RXCI) High byte for data path B bit 6
BM_RXCIHB6    EQU (1<<RXCIHB6)       

RXCIHB7       EQU 7       ; Rx CRC Init value (16-bit RXCI) High byte for data path B bit 7
BM_RXCIHB7    EQU (1<<RXCIHB7)       

; RXCILA - Rx CRC Init value low byte for data path A
RXCILA0       EQU 0       ; Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 0
BM_RXCILA0    EQU (1<<RXCILA0)       

RXCILA1       EQU 1       ; Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 1
BM_RXCILA1    EQU (1<<RXCILA1)       

RXCILA2       EQU 2       ; Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 2
BM_RXCILA2    EQU (1<<RXCILA2)       

RXCILA3       EQU 3       ; Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 3
BM_RXCILA3    EQU (1<<RXCILA3)       

RXCILA4       EQU 4       ; Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 4
BM_RXCILA4    EQU (1<<RXCILA4)       

RXCILA5       EQU 5       ; Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 5
BM_RXCILA5    EQU (1<<RXCILA5)       

RXCILA6       EQU 6       ; Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 6
BM_RXCILA6    EQU (1<<RXCILA6)       

RXCILA7       EQU 7       ; Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 7
BM_RXCILA7    EQU (1<<RXCILA7)       

; RXCILB - Rx CRC Init value low byte for data path B
RXCILB0       EQU 0       ; Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 0
BM_RXCILB0    EQU (1<<RXCILB0)       

RXCILB1       EQU 1       ; Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 1
BM_RXCILB1    EQU (1<<RXCILB1)       

RXCILB2       EQU 2       ; Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 2
BM_RXCILB2    EQU (1<<RXCILB2)       

RXCILB3       EQU 3       ; Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 3
BM_RXCILB3    EQU (1<<RXCILB3)       

RXCILB4       EQU 4       ; Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 4
BM_RXCILB4    EQU (1<<RXCILB4)       

RXCILB5       EQU 5       ; Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 5
BM_RXCILB5    EQU (1<<RXCILB5)       

RXCILB6       EQU 6       ; Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 6
BM_RXCILB6    EQU (1<<RXCILB6)       

RXCILB7       EQU 7       ; Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 7
BM_RXCILB7    EQU (1<<RXCILB7)       

; RXCPHA - Rx CRC polynomial high byte for data path A
RXCPHA0       EQU 0       ; Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 0
BM_RXCPHA0    EQU (1<<RXCPHA0)       

RXCPHA1       EQU 1       ; Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 1
BM_RXCPHA1    EQU (1<<RXCPHA1)       

RXCPHA2       EQU 2       ; Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 2
BM_RXCPHA2    EQU (1<<RXCPHA2)       

RXCPHA3       EQU 3       ; Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 3
BM_RXCPHA3    EQU (1<<RXCPHA3)       

RXCPHA4       EQU 4       ; Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 4
BM_RXCPHA4    EQU (1<<RXCPHA4)       

RXCPHA5       EQU 5       ; Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 5
BM_RXCPHA5    EQU (1<<RXCPHA5)       

RXCPHA6       EQU 6       ; Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 6
BM_RXCPHA6    EQU (1<<RXCPHA6)       

RXCPHA7       EQU 7       ; Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 7
BM_RXCPHA7    EQU (1<<RXCPHA7)       

; RXCPHB - Rx CRC polynomial high byte for data path B
RXCPHB0       EQU 0       ; Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 0
BM_RXCPHB0    EQU (1<<RXCPHB0)       

RXCPHB1       EQU 1       ; Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 1
BM_RXCPHB1    EQU (1<<RXCPHB1)       

RXCPHB2       EQU 2       ; Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 2
BM_RXCPHB2    EQU (1<<RXCPHB2)       

RXCPHB3       EQU 3       ; Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 3
BM_RXCPHB3    EQU (1<<RXCPHB3)       

RXCPHB4       EQU 4       ; Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 4
BM_RXCPHB4    EQU (1<<RXCPHB4)       

RXCPHB5       EQU 5       ; Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 5
BM_RXCPHB5    EQU (1<<RXCPHB5)       

RXCPHB6       EQU 6       ; Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 6
BM_RXCPHB6    EQU (1<<RXCPHB6)       

RXCPHB7       EQU 7       ; Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 7
BM_RXCPHB7    EQU (1<<RXCPHB7)       

; RXCPLA - Rx CRC polynomial low byte for data path A
RXCPLA1       EQU 1       ; Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 1
BM_RXCPLA1    EQU (1<<RXCPLA1)       

RXCPLA2       EQU 2       ; Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 2
BM_RXCPLA2    EQU (1<<RXCPLA2)       

RXCPLA3       EQU 3       ; Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 3
BM_RXCPLA3    EQU (1<<RXCPLA3)       

RXCPLA4       EQU 4       ; Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 4
BM_RXCPLA4    EQU (1<<RXCPLA4)       

RXCPLA5       EQU 5       ; Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 5
BM_RXCPLA5    EQU (1<<RXCPLA5)       

RXCPLA6       EQU 6       ; Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 6
BM_RXCPLA6    EQU (1<<RXCPLA6)       

RXCPLA7       EQU 7       ; Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 7
BM_RXCPLA7    EQU (1<<RXCPLA7)       

; RXCPLB - Rx CRC polynomial low byte for data path B
RXCPLB1       EQU 1       ; Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 1
BM_RXCPLB1    EQU (1<<RXCPLB1)       

RXCPLB2       EQU 2       ; Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 2
BM_RXCPLB2    EQU (1<<RXCPLB2)       

RXCPLB3       EQU 3       ; Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 3
BM_RXCPLB3    EQU (1<<RXCPLB3)       

RXCPLB4       EQU 4       ; Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 4
BM_RXCPLB4    EQU (1<<RXCPLB4)       

RXCPLB5       EQU 5       ; Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 5
BM_RXCPLB5    EQU (1<<RXCPLB5)       

RXCPLB6       EQU 6       ; Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 6
BM_RXCPLB6    EQU (1<<RXCPLB6)       

RXCPLB7       EQU 7       ; Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 7
BM_RXCPLB7    EQU (1<<RXCPLB7)       

; RXCRHA - Rx CRC result register high byte for data path A
RXCRHA0       EQU 0       ; Rx CRC Result register High byte for data path A bit 0
BM_RXCRHA0    EQU (1<<RXCRHA0)       

RXCRHA1       EQU 1       ; Rx CRC Result register High byte for data path A bit 1
BM_RXCRHA1    EQU (1<<RXCRHA1)       

RXCRHA2       EQU 2       ; Rx CRC Result register High byte for data path A bit 2
BM_RXCRHA2    EQU (1<<RXCRHA2)       

RXCRHA3       EQU 3       ; Rx CRC Result register High byte for data path A bit 3
BM_RXCRHA3    EQU (1<<RXCRHA3)       

RXCRHA4       EQU 4       ; Rx CRC Result register High byte for data path A bit 4
BM_RXCRHA4    EQU (1<<RXCRHA4)       

RXCRHA5       EQU 5       ; Rx CRC Result register High byte for data path A bit 5
BM_RXCRHA5    EQU (1<<RXCRHA5)       

RXCRHA6       EQU 6       ; Rx CRC Result register High byte for data path A bit 6
BM_RXCRHA6    EQU (1<<RXCRHA6)       

RXCRHA7       EQU 7       ; Rx CRC Result register High byte for data path A bit 7
BM_RXCRHA7    EQU (1<<RXCRHA7)       

; RXCRHB - Rx CRC result register high byte for data path B
RXCRHB0       EQU 0       ; Rx CRC Result register High Byte for data path B bit 0
BM_RXCRHB0    EQU (1<<RXCRHB0)       

RXCRHB1       EQU 1       ; Rx CRC Result register High Byte for data path B bit 1
BM_RXCRHB1    EQU (1<<RXCRHB1)       

RXCRHB2       EQU 2       ; Rx CRC Result register High Byte for data path B bit 2
BM_RXCRHB2    EQU (1<<RXCRHB2)       

RXCRHB3       EQU 3       ; Rx CRC Result register High Byte for data path B bit 3
BM_RXCRHB3    EQU (1<<RXCRHB3)       

RXCRHB4       EQU 4       ; Rx CRC Result register High Byte for data path B bit 4
BM_RXCRHB4    EQU (1<<RXCRHB4)       

RXCRHB5       EQU 5       ; Rx CRC Result register High Byte for data path B bit 5
BM_RXCRHB5    EQU (1<<RXCRHB5)       

RXCRHB6       EQU 6       ; Rx CRC Result register High Byte for data path B bit 6
BM_RXCRHB6    EQU (1<<RXCRHB6)       

RXCRHB7       EQU 7       ; Rx CRC Result register High Byte for data path B bit 7
BM_RXCRHB7    EQU (1<<RXCRHB7)       

; RXCRLA - Rx CRC result register low byte for data path A
RXCRLA0       EQU 0       ; Rx CRC Result register Low byte for data path A bit 0
BM_RXCRLA0    EQU (1<<RXCRLA0)       

RXCRLA1       EQU 1       ; Rx CRC Result register Low byte for data path A bit 1
BM_RXCRLA1    EQU (1<<RXCRLA1)       

RXCRLA2       EQU 2       ; Rx CRC Result register Low byte for data path A bit 2
BM_RXCRLA2    EQU (1<<RXCRLA2)       

RXCRLA3       EQU 3       ; Rx CRC Result register Low byte for data path A bit 3
BM_RXCRLA3    EQU (1<<RXCRLA3)       

RXCRLA4       EQU 4       ; Rx CRC Result register Low byte for data path A bit 4
BM_RXCRLA4    EQU (1<<RXCRLA4)       

RXCRLA5       EQU 5       ; Rx CRC Result register Low byte for data path A bit 5
BM_RXCRLA5    EQU (1<<RXCRLA5)       

RXCRLA6       EQU 6       ; Rx CRC Result register Low byte for data path A bit 6
BM_RXCRLA6    EQU (1<<RXCRLA6)       

RXCRLA7       EQU 7       ; Rx CRC Result register Low byte for data path A bit 7
BM_RXCRLA7    EQU (1<<RXCRLA7)       

; RXCRLB - Rx CRC result register low byte for data path B
RXCRLB0       EQU 0       ; Rx CRC Result register Low Byte for data path B bit 0
BM_RXCRLB0    EQU (1<<RXCRLB0)       

RXCRLB1       EQU 1       ; Rx CRC Result register Low Byte for data path B bit 1
BM_RXCRLB1    EQU (1<<RXCRLB1)       

RXCRLB2       EQU 2       ; Rx CRC Result register Low Byte for data path B bit 2
BM_RXCRLB2    EQU (1<<RXCRLB2)       

RXCRLB3       EQU 3       ; Rx CRC Result register Low Byte for data path B bit 3
BM_RXCRLB3    EQU (1<<RXCRLB3)       

RXCRLB4       EQU 4       ; Rx CRC Result register Low Byte for data path B bit 4
BM_RXCRLB4    EQU (1<<RXCRLB4)       

RXCRLB5       EQU 5       ; Rx CRC Result register Low Byte for data path B bit 5
BM_RXCRLB5    EQU (1<<RXCRLB5)       

RXCRLB6       EQU 6       ; Rx CRC Result register Low Byte for data path B bit 6
BM_RXCRLB6    EQU (1<<RXCRLB6)       

RXCRLB7       EQU 7       ; Rx CRC Result register Low Byte for data path B bit 7
BM_RXCRLB7    EQU (1<<RXCRLB7)       

; RXCSBA - Rx CRC skip bit number for data path A
RXCSBA0       EQU 0       ; Rx CRC Skip Bit number for data path A bit 0
BM_RXCSBA0    EQU (1<<RXCSBA0)       

RXCSBA1       EQU 1       ; Rx CRC Skip Bit number for data path A bit 1
BM_RXCSBA1    EQU (1<<RXCSBA1)       

RXCSBA2       EQU 2       ; Rx CRC Skip Bit number for data path A bit 2
BM_RXCSBA2    EQU (1<<RXCSBA2)       

RXCSBA3       EQU 3       ; Rx CRC Skip Bit number for data path A bit 3
BM_RXCSBA3    EQU (1<<RXCSBA3)       

RXCSBA4       EQU 4       ; Rx CRC Skip Bit number for data path A bit 4
BM_RXCSBA4    EQU (1<<RXCSBA4)       

RXCSBA5       EQU 5       ; Rx CRC Skip Bit number for data path A bit 5
BM_RXCSBA5    EQU (1<<RXCSBA5)       

RXCSBA6       EQU 6       ; Rx CRC Skip Bit number for data path A bit 6
BM_RXCSBA6    EQU (1<<RXCSBA6)       

RXCSBA7       EQU 7       ; Rx CRC Skip Bit number for data path A bit 7
BM_RXCSBA7    EQU (1<<RXCSBA7)       

; RXCSBB - Rx CRC skip bit number for data path B
RXCSBB0       EQU 0       ; Rx CRC Skip Bit number for data path B bit 0
BM_RXCSBB0    EQU (1<<RXCSBB0)       

RXCSBB1       EQU 1       ; Rx CRC Skip Bit number for data path B bit 1
BM_RXCSBB1    EQU (1<<RXCSBB1)       

RXCSBB2       EQU 2       ; Rx CRC Skip Bit number for data path B bit 2
BM_RXCSBB2    EQU (1<<RXCSBB2)       

RXCSBB3       EQU 3       ; Rx CRC Skip Bit number for data path B bit 3
BM_RXCSBB3    EQU (1<<RXCSBB3)       

RXCSBB4       EQU 4       ; Rx CRC Skip Bit number for data path B bit 4
BM_RXCSBB4    EQU (1<<RXCSBB4)       

RXCSBB5       EQU 5       ; Rx CRC Skip Bit number for data path B bit 5
BM_RXCSBB5    EQU (1<<RXCSBB5)       

RXCSBB6       EQU 6       ; Rx CRC Skip Bit number for data path B bit 6
BM_RXCSBB6    EQU (1<<RXCSBB6)       

RXCSBB7       EQU 7       ; Rx CRC Skip Bit number for data path B bit 7
BM_RXCSBB7    EQU (1<<RXCSBB7)       

; RXDSA - Rx data shift register for data path A
RXDSA0       EQU 0       ; Receive Data Shift register for data path A bit 0
BM_RXDSA0    EQU (1<<RXDSA0)       

RXDSA1       EQU 1       ; Receive Data Shift register for data path A bit 1
BM_RXDSA1    EQU (1<<RXDSA1)       

RXDSA2       EQU 2       ; Receive Data Shift register for data path A bit 2
BM_RXDSA2    EQU (1<<RXDSA2)       

RXDSA3       EQU 3       ; Receive Data Shift register for data path A bit 3
BM_RXDSA3    EQU (1<<RXDSA3)       

RXDSA4       EQU 4       ; Receive Data Shift register for data path A bit 4
BM_RXDSA4    EQU (1<<RXDSA4)       

RXDSA5       EQU 5       ; Receive Data Shift register for data path A bit 5
BM_RXDSA5    EQU (1<<RXDSA5)       

RXDSA6       EQU 6       ; Receive Data Shift register for data path A bit 6
BM_RXDSA6    EQU (1<<RXDSA6)       

RXDSA7       EQU 7       ; Receive Data Shift register for data path A bit 7
BM_RXDSA7    EQU (1<<RXDSA7)       

; RXDSB - Rx data shift register for data path B
RXDSB0       EQU 0       ; Receive Data Shift register for data path B bit 0
BM_RXDSB0    EQU (1<<RXDSB0)       

RXDSB1       EQU 1       ; Receive Data Shift register for data path B bit 1
BM_RXDSB1    EQU (1<<RXDSB1)       

RXDSB2       EQU 2       ; Receive Data Shift register for data path B bit 2
BM_RXDSB2    EQU (1<<RXDSB2)       

RXDSB3       EQU 3       ; Receive Data Shift register for data path B bit 3
BM_RXDSB3    EQU (1<<RXDSB3)       

RXDSB4       EQU 4       ; Receive Data Shift register for data path B bit 4
BM_RXDSB4    EQU (1<<RXDSB4)       

RXDSB5       EQU 5       ; Receive Data Shift register for data path B bit 5
BM_RXDSB5    EQU (1<<RXDSB5)       

RXDSB6       EQU 6       ; Receive Data Shift register for data path B bit 6
BM_RXDSB6    EQU (1<<RXDSB6)       

RXDSB7       EQU 7       ; Receive Data Shift register for data path B bit 7
BM_RXDSB7    EQU (1<<RXDSB7)       

; RXTLHA - Rx data telegram length register high byte for data path A
RXTLHA0       EQU 0       ; RXTL (Receive Telegram Length) register High byte for data path A bit 0
BM_RXTLHA0    EQU (1<<RXTLHA0)       

RXTLHA1       EQU 1       ; RXTL (Receive Telegram Length) register High byte for data path A bit 1
BM_RXTLHA1    EQU (1<<RXTLHA1)       

RXTLHA2       EQU 2       ; RXTL (Receive Telegram Length) register High byte for data path A bit 2
BM_RXTLHA2    EQU (1<<RXTLHA2)       

RXTLHA3       EQU 3       ; RXTL (Receive Telegram Length) register High byte for data path A bit 3
BM_RXTLHA3    EQU (1<<RXTLHA3)       

; RXTLHB - Rx data telegram length register high byte for data path B
RXTLHB0       EQU 0       ; RXTL (Receive Telegram Length) register High byte for data path B bit 0
BM_RXTLHB0    EQU (1<<RXTLHB0)       

RXTLHB1       EQU 1       ; RXTL (Receive Telegram Length) register High byte for data path B bit 1
BM_RXTLHB1    EQU (1<<RXTLHB1)       

RXTLHB2       EQU 2       ; RXTL (Receive Telegram Length) register High byte for data path B bit 2
BM_RXTLHB2    EQU (1<<RXTLHB2)       

RXTLHB3       EQU 3       ; RXTL (Receive Telegram Length) register High byte for data path B bit 3
BM_RXTLHB3    EQU (1<<RXTLHB3)       

; RXTLLA - Rx data telegram length register low byte for data path A
RXTLLA0       EQU 0       ; RXTL (Receive Telegram Length) register Low value for data path A bit 0
BM_RXTLLA0    EQU (1<<RXTLLA0)       

RXTLLA1       EQU 1       ; RXTL (Receive Telegram Length) register Low value for data path A bit 1
BM_RXTLLA1    EQU (1<<RXTLLA1)       

RXTLLA2       EQU 2       ; RXTL (Receive Telegram Length) register Low value for data path A bit 2
BM_RXTLLA2    EQU (1<<RXTLLA2)       

RXTLLA3       EQU 3       ; RXTL (Receive Telegram Length) register Low value for data path A bit 3
BM_RXTLLA3    EQU (1<<RXTLLA3)       

RXTLLA4       EQU 4       ; RXTL (Receive Telegram Length) register Low value for data path A bit 4
BM_RXTLLA4    EQU (1<<RXTLLA4)       

RXTLLA5       EQU 5       ; RXTL (Receive Telegram Length) register Low value for data path A bit 5
BM_RXTLLA5    EQU (1<<RXTLLA5)       

RXTLLA6       EQU 6       ; RXTL (Receive Telegram Length) register Low value for data path A bit 6
BM_RXTLLA6    EQU (1<<RXTLLA6)       

RXTLLA7       EQU 7       ; RXTL (Receive Telegram Length) register Low value for data path A bit 7
BM_RXTLLA7    EQU (1<<RXTLLA7)       

; RXTLLB - Rx data telegram length register low byte for data path B
RXTLLB0       EQU 0       ; RXTL (Receive Telegram Length) register Low byte for data path B bit 0
BM_RXTLLB0    EQU (1<<RXTLLB0)       

RXTLLB1       EQU 1       ; RXTL (Receive Telegram Length) register Low byte for data path B bit 1
BM_RXTLLB1    EQU (1<<RXTLLB1)       

RXTLLB2       EQU 2       ; RXTL (Receive Telegram Length) register Low byte for data path B bit 2
BM_RXTLLB2    EQU (1<<RXTLLB2)       

RXTLLB3       EQU 3       ; RXTL (Receive Telegram Length) register Low byte for data path B bit 3
BM_RXTLLB3    EQU (1<<RXTLLB3)       

RXTLLB4       EQU 4       ; RXTL (Receive Telegram Length) register Low byte for data path B bit 4
BM_RXTLLB4    EQU (1<<RXTLLB4)       

RXTLLB5       EQU 5       ; RXTL (Receive Telegram Length) register Low byte for data path B bit 5
BM_RXTLLB5    EQU (1<<RXTLLB5)       

RXTLLB6       EQU 6       ; RXTL (Receive Telegram Length) register Low byte for data path B bit 6
BM_RXTLLB6    EQU (1<<RXTLLB6)       

RXTLLB7       EQU 7       ; RXTL (Receive Telegram Length) register Low byte for data path B bit 7
BM_RXTLLB7    EQU (1<<RXTLLB7)       

; ***** RXDSP ************************
; EOTCA - End Of Telegram Conditions for path A
CARFEA       EQU 0       ; CARrier check Failed Enable for path A
BM_CARFEA    EQU (1<<CARFEA)       

AMPFEA       EQU 1       ; AMPlitude Failed Enable for path A
BM_AMPFEA    EQU (1<<AMPFEA)       

SYTFEA       EQU 2       ; SYmbol Timing check Failed Enable for path A
BM_SYTFEA    EQU (1<<SYTFEA)       

MANFEA       EQU 3       ; MANchester Coding Failed Enable for path A
BM_MANFEA    EQU (1<<MANFEA)       

TMOFEA       EQU 4       ; Time-Out Fail Enable on path A
BM_TMOFEA    EQU (1<<TMOFEA)       

TELREA       EQU 5       ; Telegram Length Reached Enable on path A
BM_TELREA    EQU (1<<TELREA)       

RRFEA       EQU 6       ; RSSI Range Fail Enable on path A
BM_RRFEA    EQU (1<<RRFEA)       

EOTBFE       EQU 7       ; End Of Telegram on path B Fail Enable
BM_EOTBFE    EQU (1<<EOTBFE)       

; EOTCB - End Of Telegram Conditions for path B
CARFEB       EQU 0       ; CARrier check Failed Enable for path B
BM_CARFEB    EQU (1<<CARFEB)       

AMPFEB       EQU 1       ; AMPlitude Failed Enable for path B
BM_AMPFEB    EQU (1<<AMPFEB)       

SYTFEB       EQU 2       ; SYmbol Timing check Failed Enable for path B
BM_SYTFEB    EQU (1<<SYTFEB)       

MANFEB       EQU 3       ; MANchester Coding Failed Enable for path B
BM_MANFEB    EQU (1<<MANFEB)       

TMOFEB       EQU 4       ; Time-Out Fail Enable on path B
BM_TMOFEB    EQU (1<<TMOFEB)       

TELREB       EQU 5       ; Telegram Length Reached Enable on path B
BM_TELREB    EQU (1<<TELREB)       

RRFEB       EQU 6       ; RSSI Range Fail Enable on path B
BM_RRFEB    EQU (1<<RRFEB)       

EOTAFE       EQU 7       ; End Of Telegram on path B Fail Enable
BM_EOTAFE    EQU (1<<EOTAFE)       

; EOTSA - End Of Telegram Status on path A
CARFA       EQU 0       ; CARrier check Failed on path A
BM_CARFA    EQU (1<<CARFA)       

AMPFA       EQU 1       ; AMPlitude Failed on path A
BM_AMPFA    EQU (1<<AMPFA)       

SYTFA       EQU 2       ; SYmbol Timing check Failed on path A
BM_SYTFA    EQU (1<<SYTFA)       

MANFA       EQU 3       ; MANchester coding Failed on path A
BM_MANFA    EQU (1<<MANFA)       

TMOFA       EQU 4       ; Time-Out Fail on path A
BM_TMOFA    EQU (1<<TMOFA)       

TELRA       EQU 5       ; Telegram Length Reached on path A
BM_TELRA    EQU (1<<TELRA)       

RRFA       EQU 6       ; RSSI Range Fail on path A
BM_RRFA    EQU (1<<RRFA)       

EOTBF       EQU 7       ; End Of Telegram on path B Flag
BM_EOTBF    EQU (1<<EOTBF)       

; EOTSB - End Of Telegram Status on path B
CARFB       EQU 0       ; CARrier check Failed on path B
BM_CARFB    EQU (1<<CARFB)       

AMPFB       EQU 1       ; AMPlitude Failed on path B
BM_AMPFB    EQU (1<<AMPFB)       

SYTFB       EQU 2       ; SYmbol Timing check Failed on path B
BM_SYTFB    EQU (1<<SYTFB)       

MANFB       EQU 3       ; MANchester coding Failed on path B
BM_MANFB    EQU (1<<MANFB)       

TMOFB       EQU 4       ; Time-Out Fail on path B
BM_TMOFB    EQU (1<<TMOFB)       

TELRB       EQU 5       ; Telegram Length Reached on path B
BM_TELRB    EQU (1<<TELRB)       

RRFB       EQU 6       ; RSSI Range Fail on path B
BM_RRFB    EQU (1<<RRFB)       

EOTAF       EQU 7       ; End Of Telegram on path A Flag
BM_EOTAF    EQU (1<<EOTAF)       

; RDCR - Rx DSP control register
RDPU       EQU 0       ; Rx DSP Power Up
BM_RDPU    EQU (1<<RDPU)       

ADIVEN       EQU 1       ; Divided ADC clock enable
BM_ADIVEN    EQU (1<<ADIVEN)       

RDEN       EQU 2       ; Rx DSP enable
BM_RDEN    EQU (1<<RDEN)       

; RDOCR - Rx DSP output control
TMDS0       EQU 1       ; Transparent Mode Data Select bit 0
BM_TMDS0    EQU (1<<TMDS0)       

TMDS1       EQU 2       ; Transparent Mode Data Select bit 1
BM_TMDS1    EQU (1<<TMDS1)       

ETRPA       EQU 3       ; Enable Transparent Path A
BM_ETRPA    EQU (1<<ETRPA)       

ETRPB       EQU 4       ; Enable Transparent Path B
BM_ETRPB    EQU (1<<ETRPB)       

RDSIDA       EQU 5       ; Rx DSP Start bit Is Data for path A
BM_RDSIDA    EQU (1<<RDSIDA)       

RDSIDB       EQU 6       ; Rx DSP Start bit Is Data for path B
BM_RDSIDB    EQU (1<<RDSIDB)       

; RDSIFR - Rx DSP status interrupt flag register
NBITA       EQU 0       ; New Bit on Rx path A
BM_NBITA    EQU (1<<NBITA)       

NBITB       EQU 1       ; New Bit on Rx path B
BM_NBITB    EQU (1<<NBITB)       

EOTA       EQU 2       ; End Of Telegram on path A
BM_EOTA    EQU (1<<EOTA)       

EOTB       EQU 3       ; End Of Telegram on path B
BM_EOTB    EQU (1<<EOTB)       

SOTA       EQU 4       ; Start Of Telegram on path A
BM_SOTA    EQU (1<<SOTA)       

SOTB       EQU 5       ; Start Of Telegram on path B
BM_SOTB    EQU (1<<SOTB)       

WCOA       EQU 6       ; Wake Conditions Ok on path A
BM_WCOA    EQU (1<<WCOA)       

WCOB       EQU 7       ; Wake Conditions Ok on path B
BM_WCOB    EQU (1<<WCOB)       

; RDSIMR - Rx DSP status interrupt mask register
NBITAM       EQU 0       ; New bit on Rx path A interrupt mask register
BM_NBITAM    EQU (1<<NBITAM)       

NBITBM       EQU 1       ; New bit on Rx path B interrupt mask register
BM_NBITBM    EQU (1<<NBITBM)       

EOTAM       EQU 2       ; End Of Telegram on Rx path A interrupt mask register
BM_EOTAM    EQU (1<<EOTAM)       

EOTBM       EQU 3       ; End Of Telegram on Rx path B interrupt mask register
BM_EOTBM    EQU (1<<EOTBM)       

SOTAM       EQU 4       ; Start Of Telegram on Rx path A interrupt mask register
BM_SOTAM    EQU (1<<SOTAM)       

SOTBM       EQU 5       ; Start Of Telegram on Rx path B interrupt mask register
BM_SOTBM    EQU (1<<SOTBM)       

WCOAM       EQU 6       ; Wake Conditions Ok on path A interrupt mask register
BM_WCOAM    EQU (1<<WCOAM)       

WCOBM       EQU 7       ; Wake Conditions Ok on path B interrupt mask register
BM_WCOBM    EQU (1<<WCOBM)       

; SOTCA - Start Of Telegram Conditions for path A
CAROEA       EQU 0       ; CARrier check Ok Enabled for path A
BM_CAROEA    EQU (1<<CAROEA)       

AMPOEA       EQU 1       ; AMPlitude Ok Enabled for path A
BM_AMPOEA    EQU (1<<AMPOEA)       

SYTOEA       EQU 2       ; Symbol Timing Ok Enabled for path A
BM_SYTOEA    EQU (1<<SYTOEA)       

MANOEA       EQU 3       ; Manchester Coding Ok Enabled for path A
BM_MANOEA    EQU (1<<MANOEA)       

WUPEA       EQU 4       ; Wake Up Pattern match Enabled for path A
BM_WUPEA    EQU (1<<WUPEA)       

SFIDEA       EQU 5       ; Start of Frame IDentifier match Enabled for path A
BM_SFIDEA    EQU (1<<SFIDEA)       

RROEA       EQU 6       ; RSSI Range OK Enable for path A
BM_RROEA    EQU (1<<RROEA)       

WCOBOE       EQU 7       ; Wake Check OK from path B Ok Enable
BM_WCOBOE    EQU (1<<WCOBOE)       

; SOTCB - Start Of Telegram Conditions for path B
CAROEB       EQU 0       ; CARrier check Ok Enabled for path B
BM_CAROEB    EQU (1<<CAROEB)       

AMPOEB       EQU 1       ; AMPlitude Ok Enabled for path B
BM_AMPOEB    EQU (1<<AMPOEB)       

SYTOEB       EQU 2       ; Symbol Timing Ok Enabled for path B
BM_SYTOEB    EQU (1<<SYTOEB)       

MANOEB       EQU 3       ; Manchester Coding Ok Enabled for path B
BM_MANOEB    EQU (1<<MANOEB)       

WUPEB       EQU 4       ; Wake Up Pattern match Enabled for path B
BM_WUPEB    EQU (1<<WUPEB)       

SFIDEB       EQU 5       ; Start of Frame IDentifier match Enabled for path B
BM_SFIDEB    EQU (1<<SFIDEB)       

RROEB       EQU 6       ; RSSI Range OK Enable for path B
BM_RROEB    EQU (1<<RROEB)       

WCOAOE       EQU 7       ; Wake Check OK from path A Ok Enable
BM_WCOAOE    EQU (1<<WCOAOE)       

; SOTSA - Start Of Telegram Status for path A
CAROA       EQU 0       ; CARrier check Ok on path A
BM_CAROA    EQU (1<<CAROA)       

AMPOA       EQU 1       ; AMPlitude Ok on path A
BM_AMPOA    EQU (1<<AMPOA)       

SYTOA       EQU 2       ; Symbol Timing Ok on path A
BM_SYTOA    EQU (1<<SYTOA)       

MANOA       EQU 3       ; Manchester Coding Ok on path A
BM_MANOA    EQU (1<<MANOA)       

WUPOA       EQU 4       ; Wake Up Pattern matched on path A
BM_WUPOA    EQU (1<<WUPOA)       

SFIDOA       EQU 5       ; Start of Frame IDentifier matched on path A
BM_SFIDOA    EQU (1<<SFIDOA)       

RROA       EQU 6       ; RSSI Range Ok on Path A
BM_RROA    EQU (1<<RROA)       

WCOBO       EQU 7       ; Wake Check Ok on path B Ok
BM_WCOBO    EQU (1<<WCOBO)       

; SOTSB - Start Of Telegram Status for path B
CAROB       EQU 0       ; CARrier check Ok on path B
BM_CAROB    EQU (1<<CAROB)       

AMPOB       EQU 1       ; AMPlitude Ok on path B
BM_AMPOB    EQU (1<<AMPOB)       

SYTOB       EQU 2       ; Symbol Timing Ok on path B
BM_SYTOB    EQU (1<<SYTOB)       

MANOB       EQU 3       ; Manchester Coding Ok on path B
BM_MANOB    EQU (1<<MANOB)       

WUPOB       EQU 4       ; Wake Up Pattern matched on path B
BM_WUPOB    EQU (1<<WUPOB)       

SFIDOB       EQU 5       ; Start of Frame IDentifier matched on path B
BM_SFIDOB    EQU (1<<SFIDOB)       

RROB       EQU 6       ; RSSI Range Ok on Path B
BM_RROB    EQU (1<<RROB)       

WCOAO       EQU 7       ; Wake Check Ok on path A Ok
BM_WCOAO    EQU (1<<WCOAO)       

; TESRA - Telegram Status Register on Path A
CRCOA       EQU 0       ; Cyclic Redundancy Check Ok on path A
BM_CRCOA    EQU (1<<CRCOA)       

EOTLA0       EQU 1       ; End of Telegram Location on path A bit 0
BM_EOTLA0    EQU (1<<EOTLA0)       

EOTLA1       EQU 2       ; End of Telegram Location on path A bit 1
BM_EOTLA1    EQU (1<<EOTLA1)       

; TESRB - Telegram Status Register on Path B
CRCOB       EQU 0       ; Cyclic Redundancy Check Ok on path B
BM_CRCOB    EQU (1<<CRCOB)       

EOTLB0       EQU 1       ; End of Telegram Location on path B bit 0
BM_EOTLB0    EQU (1<<EOTLB0)       

EOTLB1       EQU 2       ; End of Telegram Location on path B bit 1
BM_EOTLB1    EQU (1<<EOTLB1)       

; ***** SFIFO ************************
; SFC - Support FIFO Configuration Register
SFFLC0       EQU 0       ; Support FIFO Fill-Level Configuration bit 0
BM_SFFLC0    EQU (1<<SFFLC0)       

SFFLC1       EQU 1       ; Support FIFO Fill-Level Configuration bit 1
BM_SFFLC1    EQU (1<<SFFLC1)       

SFFLC2       EQU 2       ; Support FIFO Fill-Level Configuration bit 2
BM_SFFLC2    EQU (1<<SFFLC2)       

SFFLC3       EQU 3       ; Support FIFO Fill-Level Configuration bit 3
BM_SFFLC3    EQU (1<<SFFLC3)       

SFFLC4       EQU 4       ; Support FIFO Fill-Level Configuration bit 4
BM_SFFLC4    EQU (1<<SFFLC4)       

SFDRA       EQU 7       ; Support FIFO Direct Read Access Operational Mode
BM_SFDRA    EQU (1<<SFDRA)       

; SFI - Support FIFO Interrupt Mask Register
SFFLIM       EQU 0       ; Support FIFO Fill-level Interrupt Mask
BM_SFFLIM    EQU (1<<SFFLIM)       

SFERIM       EQU 1       ; Support FIFO Error Interrupt Mask
BM_SFERIM    EQU (1<<SFERIM)       

; SFL - Support FIFO Fill Level Register
SFFLS0       EQU 0       ; Support FIFO Fill Level Status bit 0
BM_SFFLS0    EQU (1<<SFFLS0)       

SFFLS1       EQU 1       ; Support FIFO Fill Level Status bit 1
BM_SFFLS1    EQU (1<<SFFLS1)       

SFFLS2       EQU 2       ; Support FIFO Fill Level Status bit 2
BM_SFFLS2    EQU (1<<SFFLS2)       

SFFLS3       EQU 3       ; Support FIFO Fill Level Status bit 3
BM_SFFLS3    EQU (1<<SFFLS3)       

SFFLS4       EQU 4       ; Support FIFO Fill Level Status bit 4
BM_SFFLS4    EQU (1<<SFFLS4)       

SFCLR       EQU 7       ; Support FIFO Clear
BM_SFCLR    EQU (1<<SFCLR)       

; SFRP - Support FIFO Read Pointer
SFRP0       EQU 0       ; Support FIFO Read Pointer bit 0
BM_SFRP0    EQU (1<<SFRP0)       

SFRP1       EQU 1       ; Support FIFO Read Pointer bit 1
BM_SFRP1    EQU (1<<SFRP1)       

SFRP2       EQU 2       ; Support FIFO Read Pointer bit 2
BM_SFRP2    EQU (1<<SFRP2)       

SFRP3       EQU 3       ; Support FIFO Read Pointer bit 3
BM_SFRP3    EQU (1<<SFRP3)       

SFRP4       EQU 4       ; Support FIFO Read Pointer bit 4
BM_SFRP4    EQU (1<<SFRP4)       

; SFS - Support FIFO Status Register
SFFLRF       EQU 0       ; Support FIFO Fill-Level Reached Status Flag
BM_SFFLRF    EQU (1<<SFFLRF)       

SFUFL       EQU 1       ; Support FIFO Underflow Flag
BM_SFUFL    EQU (1<<SFUFL)       

SFOFL       EQU 2       ; Support FIFO Overflow Flag
BM_SFOFL    EQU (1<<SFOFL)       

; SFWP - Support FIFO Write Pointer
SFWP0       EQU 0       ; Support FIFO Write Pointer bit 0
BM_SFWP0    EQU (1<<SFWP0)       

SFWP1       EQU 1       ; Support FIFO Write Pointer bit 1
BM_SFWP1    EQU (1<<SFWP1)       

SFWP2       EQU 2       ; Support FIFO Write Pointer bit 2
BM_SFWP2    EQU (1<<SFWP2)       

SFWP3       EQU 3       ; Support FIFO Write Pointer bit 3
BM_SFWP3    EQU (1<<SFWP3)       

SFWP4       EQU 4       ; Support FIFO Write Pointer bit 4
BM_SFWP4    EQU (1<<SFWP4)       

; ***** SPI **************************
; SFFR - SPI FIFO Fill Status Register
RFL0       EQU 0       ; Receive Buffer Fill Level bit 0
BM_RFL0    EQU (1<<RFL0)       

RFL1       EQU 1       ; Receive Buffer Fill Level bit 1
BM_RFL1    EQU (1<<RFL1)       

RFL2       EQU 2       ; Receive Buffer Fill Level bit 2
BM_RFL2    EQU (1<<RFL2)       

RFC       EQU 3       ; Rx Buffer Clear
BM_RFC    EQU (1<<RFC)       

TFL0       EQU 4       ; Transmit Buffer Fill Level bit 0
BM_TFL0    EQU (1<<TFL0)       

TFL1       EQU 5       ; Transmit Buffer Fill Level bit 1
BM_TFL1    EQU (1<<TFL1)       

TFL2       EQU 6       ; Transmit Buffer Fill Level bit 02
BM_TFL2    EQU (1<<TFL2)       

TFC       EQU 7       ; SPI Tx Buffer Clear
BM_TFC    EQU (1<<TFC)       

; SFIR - SPI FIFO Interrupt Register
RIL0       EQU 0       ; Receive Buffer Interrupt Level bit 0
BM_RIL0    EQU (1<<RIL0)       

RIL1       EQU 1       ; Receive Buffer Interrupt Level bit 1
BM_RIL1    EQU (1<<RIL1)       

RIL2       EQU 2       ; Receive Buffer Interrupt Level bit 2
BM_RIL2    EQU (1<<RIL2)       

SRIE       EQU 3       ; Rx Buffer Interrupt Enable
BM_SRIE    EQU (1<<SRIE)       

TIL0       EQU 4       ; Transmit Buffer Interrupt Level bit 0
BM_TIL0    EQU (1<<TIL0)       

TIL1       EQU 5       ; Transmit Buffer Interrupt Level bit 1
BM_TIL1    EQU (1<<TIL1)       

TIL2       EQU 6       ; Transmit Buffer Interrupt Level bit 2
BM_TIL2    EQU (1<<TIL2)       

STIE       EQU 7       ; SPI Tx Buffer Interrupt Enable
BM_STIE    EQU (1<<STIE)       

; SPCR - SPI control Register
SPR0       EQU 0       ; SPI Clock Rate Select 0
BM_SPR0    EQU (1<<SPR0)       

SPR1       EQU 1       ; SPI Clock Rate Select 1
BM_SPR1    EQU (1<<SPR1)       

CPHA       EQU 2       ; Clock Phase
BM_CPHA    EQU (1<<CPHA)       

CPOL       EQU 3       ; Clock Polarity
BM_CPOL    EQU (1<<CPOL)       

MSTR       EQU 4       ; Master/Slave Select
BM_MSTR    EQU (1<<MSTR)       

DORD       EQU 5       ; Data Order
BM_DORD    EQU (1<<DORD)       

SPE       EQU 6       ; SPI Enable
BM_SPE    EQU (1<<SPE)       

SPIE       EQU 7       ; Spe Interrupt Enable
BM_SPIE    EQU (1<<SPIE)       

; SPSR - SPI Status Register
SPI2X       EQU 0       ; Double SPI Speed Bit
BM_SPI2X    EQU (1<<SPI2X)       

RXIF       EQU 4       ; Rx Buffer Interrupt Flag
BM_RXIF    EQU (1<<RXIF)       

TXIF       EQU 5       ; Tx Buffer Interrupt Flag
BM_TXIF    EQU (1<<TXIF)       

SPIF       EQU 7       ; SPI Interrupt Flag
BM_SPIF    EQU (1<<SPIF)       

; ***** SSM **************************
; EOTC1A - End Of Telegram Conditions 1 for Path A
CARFEA1       EQU 0       ; CARrier check Failed Enable for path A
BM_CARFEA1    EQU (1<<CARFEA1)       

AMPFEA1       EQU 1       ; AMPlitude Failed Enable for path A
BM_AMPFEA1    EQU (1<<AMPFEA1)       

SYTFEA1       EQU 2       ; SYmbol Timing check Failed Enable for Path A
BM_SYTFEA1    EQU (1<<SYTFEA1)       

MANFEA1       EQU 3       ; MANchester Coding Failed Enable for Path A
BM_MANFEA1    EQU (1<<MANFEA1)       

TMOFEA1       EQU 4       ; Time-Out Fail Enable on Path A
BM_TMOFEA1    EQU (1<<TMOFEA1)       

TELREA1       EQU 5       ; Telegram Length Reached Enable on Path A
BM_TELREA1    EQU (1<<TELREA1)       

RRFEA1       EQU 6       ; RSSI Range Fail Enable on Path A
BM_RRFEA1    EQU (1<<RRFEA1)       

EOTBFE1       EQU 7       ; End Of Telegram on Path B Fail Enable
BM_EOTBFE1    EQU (1<<EOTBFE1)       

; EOTC1B - End Of Telegram Conditions 1 for Path B
CARFEB1       EQU 0       ; CARrier check Failed Enable for path B
BM_CARFEB1    EQU (1<<CARFEB1)       

AMPFEB1       EQU 1       ; AMPlitude Failed Enable for path B
BM_AMPFEB1    EQU (1<<AMPFEB1)       

SYTFEB1       EQU 2       ; SYmbol Timing check Failed Enable for Path B
BM_SYTFEB1    EQU (1<<SYTFEB1)       

MANFEB1       EQU 3       ; MANchester Coding Failed Enable for Path B
BM_MANFEB1    EQU (1<<MANFEB1)       

TMOFEB1       EQU 4       ; Time-Out Fail Enable on Path B
BM_TMOFEB1    EQU (1<<TMOFEB1)       

TELREB1       EQU 5       ; Telegram Length Reached Enable on Path B
BM_TELREB1    EQU (1<<TELREB1)       

RRFEB1       EQU 6       ; RSSI Range Fail Enable on Path B
BM_RRFEB1    EQU (1<<RRFEB1)       

EOTAFE1       EQU 7       ; End Of Telegram on Path B Fail Enable
BM_EOTAFE1    EQU (1<<EOTAFE1)       

; EOTC2A - End Of Telegram Conditions 2 for Path A
CARFEA2       EQU 0       ; CARrier check Failed Enable for path A
BM_CARFEA2    EQU (1<<CARFEA2)       

AMPFEA2       EQU 1       ; AMPlitude Failed Enable for path A
BM_AMPFEA2    EQU (1<<AMPFEA2)       

SYTFEA2       EQU 2       ; SYmbol Timing check Failed Enable for Path A
BM_SYTFEA2    EQU (1<<SYTFEA2)       

MANFEA2       EQU 3       ; MANchester Coding Failed Enable for Path A
BM_MANFEA2    EQU (1<<MANFEA2)       

TMOFEA2       EQU 4       ; Time-Out Fail Enable on Path A
BM_TMOFEA2    EQU (1<<TMOFEA2)       

TELREA2       EQU 5       ; Telegram Length Reached Enable on Path A
BM_TELREA2    EQU (1<<TELREA2)       

RRFEA2       EQU 6       ; RSSI Range Fail Enable on Path A
BM_RRFEA2    EQU (1<<RRFEA2)       

EOTBFE2       EQU 7       ; End Of Telegram on Path B Fail Enable
BM_EOTBFE2    EQU (1<<EOTBFE2)       

; EOTC2B - End Of Telegram Conditions 2 for Path B
CARFEB2       EQU 0       ; CARrier check Failed Enable for path B
BM_CARFEB2    EQU (1<<CARFEB2)       

AMPFEB2       EQU 1       ; AMPlitude Failed Enable for path B
BM_AMPFEB2    EQU (1<<AMPFEB2)       

SYTFEB2       EQU 2       ; SYmbol Timing check Failed Enable for Path B
BM_SYTFEB2    EQU (1<<SYTFEB2)       

MANFEB2       EQU 3       ; MANchester Coding Failed Enable for Path B
BM_MANFEB2    EQU (1<<MANFEB2)       

TMOFEB2       EQU 4       ; Time-Out Fail Enable on Path B
BM_TMOFEB2    EQU (1<<TMOFEB2)       

TELREB2       EQU 5       ; Telegram Length Reached Enable on Path B
BM_TELREB2    EQU (1<<TELREB2)       

RRFEB2       EQU 6       ; RSSI Range Fail Enable on Path B
BM_RRFEB2    EQU (1<<RRFEB2)       

EOTAFE2       EQU 7       ; End Of Telegram on Path B Fail Enable
BM_EOTAFE2    EQU (1<<EOTAFE2)       

; EOTC3A - End Of Telegram Conditions 3 for Path A
CARFEA3       EQU 0       ; CARrier check Failed Enable for path A
BM_CARFEA3    EQU (1<<CARFEA3)       

AMPFEA3       EQU 1       ; AMPlitude Failed Enable for path A
BM_AMPFEA3    EQU (1<<AMPFEA3)       

SYTFEA3       EQU 2       ; SYmbol Timing check Failed Enable for Path A
BM_SYTFEA3    EQU (1<<SYTFEA3)       

MANFEA3       EQU 3       ; MANchester Coding Failed Enable for Path A
BM_MANFEA3    EQU (1<<MANFEA3)       

TMOFEA3       EQU 4       ; Time-Out Fail Enable on Path A
BM_TMOFEA3    EQU (1<<TMOFEA3)       

TELREA3       EQU 5       ; Telegram Length Reached Enable on Path A
BM_TELREA3    EQU (1<<TELREA3)       

RRFEA3       EQU 6       ; RSSI Range Fail Enable on Path A
BM_RRFEA3    EQU (1<<RRFEA3)       

EOTBFE3       EQU 7       ; End Of Telegram on Path B Fail Enable
BM_EOTBFE3    EQU (1<<EOTBFE3)       

; EOTC3B - End Of Telegram Conditions 3 for Path B
CARFEB3       EQU 0       ; CARrier check Failed Enable for path B
BM_CARFEB3    EQU (1<<CARFEB3)       

AMPFEB3       EQU 1       ; AMPlitude Failed Enable for path B
BM_AMPFEB3    EQU (1<<AMPFEB3)       

SYTFEB3       EQU 2       ; SYmbol Timing check Failed Enable for Path B
BM_SYTFEB3    EQU (1<<SYTFEB3)       

MANFEB3       EQU 3       ; MANchester Coding Failed Enable for Path B
BM_MANFEB3    EQU (1<<MANFEB3)       

TMOFEB3       EQU 4       ; Time-Out Fail Enable on Path B
BM_TMOFEB3    EQU (1<<TMOFEB3)       

TELREB3       EQU 5       ; Telegram Length Reached Enable on Path B
BM_TELREB3    EQU (1<<TELREB3)       

RRFEB3       EQU 6       ; RSSI Range Fail Enable on Path B
BM_RRFEB3    EQU (1<<RRFEB3)       

EOTAFE3       EQU 7       ; End Of Telegram on Path B Fail Enable
BM_EOTAFE3    EQU (1<<EOTAFE3)       

; GTCR - Get Telegram Control Register
RXTEHA       EQU 0       ; Rx Telegram End Handling Path A
BM_RXTEHA    EQU (1<<RXTEHA)       

GAPMA       EQU 1       ; Gap Mode Path A
BM_GAPMA    EQU (1<<GAPMA)       

DARA       EQU 2       ; Demodulator Automatic Restart on Path A
BM_DARA    EQU (1<<DARA)       

IWUPA       EQU 3       ; Intermittent WUP Mode Path A
BM_IWUPA    EQU (1<<IWUPA)       

RXTEHB       EQU 4       ; Rx Telegram End Handling Path B
BM_RXTEHB    EQU (1<<RXTEHB)       

GAPMB       EQU 5       ; Gap Mode Path B
BM_GAPMB    EQU (1<<GAPMB)       

DARB       EQU 6       ; Demodulator Automatic Restart on Path B
BM_DARB    EQU (1<<DARB)       

IWUPB       EQU 7       ; Intermittent WUP Mode Path B
BM_IWUPB    EQU (1<<IWUPB)       

; MSMCR1 - Master State Machine Control Register 1
MSMSM00       EQU 0       ; Master State Machine SubState Machine Select 0 bit 0
BM_MSMSM00    EQU (1<<MSMSM00)       

MSMSM01       EQU 1       ; Master State Machine SubState Machine Select 0 bit 1
BM_MSMSM01    EQU (1<<MSMSM01)       

MSMSM02       EQU 2       ; Master State Machine SubState Machine Select 0 bit 2
BM_MSMSM02    EQU (1<<MSMSM02)       

MSMSM03       EQU 3       ; Master State Machine SubState Machine Select 0 bit 3
BM_MSMSM03    EQU (1<<MSMSM03)       

MSMSM10       EQU 4       ; Master State Machine SubState Machine Select 1 bit 0
BM_MSMSM10    EQU (1<<MSMSM10)       

MSMSM11       EQU 5       ; Master State Machine SubState Machine Select 1 bit 1
BM_MSMSM11    EQU (1<<MSMSM11)       

MSMSM12       EQU 6       ; Master State Machine SubState Machine Select 1 bit 2
BM_MSMSM12    EQU (1<<MSMSM12)       

MSMSM13       EQU 7       ; Master State Machine SubState Machine Select 1 bit 3
BM_MSMSM13    EQU (1<<MSMSM13)       

; MSMCR2 - Master State Machine Control Register 2
MSMSM20       EQU 0       ; Master State Machine SubState Machine Select 2 bit 0
BM_MSMSM20    EQU (1<<MSMSM20)       

MSMSM21       EQU 1       ; Master State Machine SubState Machine Select 2 bit 1
BM_MSMSM21    EQU (1<<MSMSM21)       

MSMSM22       EQU 2       ; Master State Machine SubState Machine Select 2 bit 2
BM_MSMSM22    EQU (1<<MSMSM22)       

MSMSM23       EQU 3       ; Master State Machine SubState Machine Select 2 bit 3
BM_MSMSM23    EQU (1<<MSMSM23)       

MSMSM30       EQU 4       ; Master State Machine SubState Machine Select 3 bit 0
BM_MSMSM30    EQU (1<<MSMSM30)       

MSMSM31       EQU 5       ; Master State Machine SubState Machine Select 3 bit 1
BM_MSMSM31    EQU (1<<MSMSM31)       

MSMSM32       EQU 6       ; Master State Machine SubState Machine Select 3 bit 2
BM_MSMSM32    EQU (1<<MSMSM32)       

MSMSM33       EQU 7       ; Master State Machine SubState Machine Select 3 bit 3
BM_MSMSM33    EQU (1<<MSMSM33)       

; MSMCR3 - Master State Machine Control Register 3
MSMSM40       EQU 0       ; Master State Machine SubState Machine Select 4 bit 0
BM_MSMSM40    EQU (1<<MSMSM40)       

MSMSM41       EQU 1       ; Master State Machine SubState Machine Select 4 bit 1
BM_MSMSM41    EQU (1<<MSMSM41)       

MSMSM42       EQU 2       ; Master State Machine SubState Machine Select 4 bit 2
BM_MSMSM42    EQU (1<<MSMSM42)       

MSMSM43       EQU 3       ; Master State Machine SubState Machine Select 4 bit 3
BM_MSMSM43    EQU (1<<MSMSM43)       

MSMSM50       EQU 4       ; Master State Machine SubState Machine Select 5 bit 0
BM_MSMSM50    EQU (1<<MSMSM50)       

MSMSM51       EQU 5       ; Master State Machine SubState Machine Select 5 bit 1
BM_MSMSM51    EQU (1<<MSMSM51)       

MSMSM52       EQU 6       ; Master State Machine SubState Machine Select 5 bit 2
BM_MSMSM52    EQU (1<<MSMSM52)       

MSMSM53       EQU 7       ; Master State Machine SubState Machine Select 5 bit 3
BM_MSMSM53    EQU (1<<MSMSM53)       

; MSMCR4 - Master State Machine Control Register 4
MSMSM60       EQU 0       ; Master State Machine SubState Machine Select 6 bit 0
BM_MSMSM60    EQU (1<<MSMSM60)       

MSMSM61       EQU 1       ; Master State Machine SubState Machine Select 6 bit 1
BM_MSMSM61    EQU (1<<MSMSM61)       

MSMSM62       EQU 2       ; Master State Machine SubState Machine Select 6 bit 2
BM_MSMSM62    EQU (1<<MSMSM62)       

MSMSM63       EQU 3       ; Master State Machine SubState Machine Select 6 bit 3
BM_MSMSM63    EQU (1<<MSMSM63)       

MSMSM70       EQU 4       ; Master State Machine SubState Machine Select 7 bit 0
BM_MSMSM70    EQU (1<<MSMSM70)       

MSMSM71       EQU 5       ; Master State Machine SubState Machine Select 7 bit 1
BM_MSMSM71    EQU (1<<MSMSM71)       

MSMSM72       EQU 6       ; Master State Machine SubState Machine Select 7 bit 2
BM_MSMSM72    EQU (1<<MSMSM72)       

MSMSM73       EQU 7       ; Master State Machine SubState Machine Select 7 bit 3
BM_MSMSM73    EQU (1<<MSMSM73)       

; MSMSTR - Master State Machine state register
SSMMST0       EQU 0       ; Sequencer State Machine Master State bit 0
BM_SSMMST0    EQU (1<<SSMMST0)       

SSMMST1       EQU 1       ; Sequencer State Machine Master State bit 1
BM_SSMMST1    EQU (1<<SSMMST1)       

SSMMST2       EQU 2       ; Sequencer State Machine Master State bit 2
BM_SSMMST2    EQU (1<<SSMMST2)       

SSMMST3       EQU 3       ; Sequencer State Machine Master State bit 3
BM_SSMMST3    EQU (1<<SSMMST3)       

SSMMST4       EQU 4       ; Sequencer State Machine Master State bit 4
BM_SSMMST4    EQU (1<<SSMMST4)       

; SOTC1A - Start Of Telegram Conditions 1 for Path A
CAROEA1       EQU 0       ; CARrier check Ok Enabled for path A
BM_CAROEA1    EQU (1<<CAROEA1)       

AMPOEA1       EQU 1       ; AMPlitude Ok Enabled for path A
BM_AMPOEA1    EQU (1<<AMPOEA1)       

SYTOEA1       EQU 2       ; Symbol Timing Ok Enabled for path A
BM_SYTOEA1    EQU (1<<SYTOEA1)       

MANOEA1       EQU 3       ; Manchester Coding Ok Enabled for path A
BM_MANOEA1    EQU (1<<MANOEA1)       

WUPEA1       EQU 4       ; Wake Up Pattern match Enabled for path A
BM_WUPEA1    EQU (1<<WUPEA1)       

SFIDEA1       EQU 5       ; Start of Frame IDentifier match Enabled for path A
BM_SFIDEA1    EQU (1<<SFIDEA1)       

RROEA1       EQU 6       ; RSSI Range OK Enable for path A
BM_RROEA1    EQU (1<<RROEA1)       

WCOBOE1       EQU 7       ; Wake Check OK from path B Ok Enable
BM_WCOBOE1    EQU (1<<WCOBOE1)       

; SOTC1B - Start Of Telegram Conditions 1 for Path B
CAROEB1       EQU 0       ; CARrier check Ok Enabled for path B
BM_CAROEB1    EQU (1<<CAROEB1)       

AMPOEB1       EQU 1       ; AMPlitude Ok Enabled for path B
BM_AMPOEB1    EQU (1<<AMPOEB1)       

SYTOEB1       EQU 2       ; Symbol Timing Ok Enabled for path B
BM_SYTOEB1    EQU (1<<SYTOEB1)       

MANOEB1       EQU 3       ; Manchester Coding Ok Enabled for path B
BM_MANOEB1    EQU (1<<MANOEB1)       

WUPEB1       EQU 4       ; Wake Up Pattern match Enabled for path B
BM_WUPEB1    EQU (1<<WUPEB1)       

SFIDEB1       EQU 5       ; Start of Frame IDentifier match Enabled for path B
BM_SFIDEB1    EQU (1<<SFIDEB1)       

RROEB1       EQU 6       ; RSSI Range Ok on Path A
BM_RROEB1    EQU (1<<RROEB1)       

WCOAOE1       EQU 7       ; Wake Check Ok on path B Ok
BM_WCOAOE1    EQU (1<<WCOAOE1)       

; SOTC2A - Start Of Telegram Conditions 2 for Path A
CAROEA2       EQU 0       ; CARrier check Ok Enabled for path A
BM_CAROEA2    EQU (1<<CAROEA2)       

AMPOEA2       EQU 1       ; AMPlitude Ok Enabled for path A
BM_AMPOEA2    EQU (1<<AMPOEA2)       

SYTOEA2       EQU 2       ; Symbol Timing Ok Enabled for path A
BM_SYTOEA2    EQU (1<<SYTOEA2)       

MANOEA2       EQU 3       ; Manchester Coding Ok Enabled for path A
BM_MANOEA2    EQU (1<<MANOEA2)       

WUPEA2       EQU 4       ; Wake Up Pattern match Enabled for path A
BM_WUPEA2    EQU (1<<WUPEA2)       

SFIDEA2       EQU 5       ; Start of Frame IDentifier match Enabled for path A
BM_SFIDEA2    EQU (1<<SFIDEA2)       

RROEA2       EQU 6       ; RSSI Range OK Enable for path A
BM_RROEA2    EQU (1<<RROEA2)       

WCOBOE2       EQU 7       ; Wake Check OK from path B Ok Enable
BM_WCOBOE2    EQU (1<<WCOBOE2)       

; SOTC2B - Start Of Telegram Conditions 2 for Path B
CAROEB2       EQU 0       ; CARrier check Ok Enabled for path B
BM_CAROEB2    EQU (1<<CAROEB2)       

AMPOEB2       EQU 1       ; AMPlitude Ok Enabled for path B
BM_AMPOEB2    EQU (1<<AMPOEB2)       

SYTOEB2       EQU 2       ; Symbol Timing Ok Enabled for path B
BM_SYTOEB2    EQU (1<<SYTOEB2)       

MANOEB2       EQU 3       ; Manchester Coding Ok Enabled for path B
BM_MANOEB2    EQU (1<<MANOEB2)       

WUPEB2       EQU 4       ; Wake Up Pattern match Enabled for path B
BM_WUPEB2    EQU (1<<WUPEB2)       

SFIDEB2       EQU 5       ; Start of Frame IDentifier match Enabled for path B
BM_SFIDEB2    EQU (1<<SFIDEB2)       

RROEB2       EQU 6       ; RSSI Range Ok on Path A
BM_RROEB2    EQU (1<<RROEB2)       

WCOAOE2       EQU 7       ; Wake Check Ok on path B Ok
BM_WCOAOE2    EQU (1<<WCOAOE2)       

; SOTTOA - Start Of Telegram Time Out for path A
SOTTOA0       EQU 0       ; Start of telegram time out for path A bit 0
BM_SOTTOA0    EQU (1<<SOTTOA0)       

SOTTOA1       EQU 1       ; Start of telegram time out for path A bit 1
BM_SOTTOA1    EQU (1<<SOTTOA1)       

SOTTOA2       EQU 2       ; Start of telegram time out for path A bit 2
BM_SOTTOA2    EQU (1<<SOTTOA2)       

SOTTOA3       EQU 3       ; Start of telegram time out for path A bit 3
BM_SOTTOA3    EQU (1<<SOTTOA3)       

SOTTOA4       EQU 4       ; Start of telegram time out for path A bit 4
BM_SOTTOA4    EQU (1<<SOTTOA4)       

SOTTOA5       EQU 5       ; Start of telegram time out for path A bit 5
BM_SOTTOA5    EQU (1<<SOTTOA5)       

SOTTOA6       EQU 6       ; Start of telegram time out for path A bit 6
BM_SOTTOA6    EQU (1<<SOTTOA6)       

SOTTOA7       EQU 7       ; Start of telegram time out for path A bit 7
BM_SOTTOA7    EQU (1<<SOTTOA7)       

; SOTTOB - Start Of Telegram Time Out for path B
SOTTOB0       EQU 0       ; Start of telegram time out for path B bit 0
BM_SOTTOB0    EQU (1<<SOTTOB0)       

SOTTOB1       EQU 1       ; Start of telegram time out for path B bit 1
BM_SOTTOB1    EQU (1<<SOTTOB1)       

SOTTOB2       EQU 2       ; Start of telegram time out for path B bit 2
BM_SOTTOB2    EQU (1<<SOTTOB2)       

SOTTOB3       EQU 3       ; Start of telegram time out for path B bit 3
BM_SOTTOB3    EQU (1<<SOTTOB3)       

SOTTOB4       EQU 4       ; Start of telegram time out for path B bit 4
BM_SOTTOB4    EQU (1<<SOTTOB4)       

SOTTOB5       EQU 5       ; Start of telegram time out for path B bit 5
BM_SOTTOB5    EQU (1<<SOTTOB5)       

SOTTOB6       EQU 6       ; Start of telegram time out for path B bit 6
BM_SOTTOB6    EQU (1<<SOTTOB6)       

SOTTOB7       EQU 7       ; Start of telegram time out for path B bit 7
BM_SOTTOB7    EQU (1<<SOTTOB7)       

; SSMCR - SSM Control Register
SSMTX       EQU 0       ; Sequencer State Machine Tx
BM_SSMTX    EQU (1<<SSMTX)       

SSMTM       EQU 1       ; Sequencer State Machine Temperature Measurement
BM_SSMTM    EQU (1<<SSMTM)       

SSMTGE       EQU 2       ; Sequencer State Machine Tx Gauss Enable
BM_SSMTGE    EQU (1<<SSMTGE)       

SSMTPE       EQU 3       ; Sequencer State Machine Tx Preemphasis Enable
BM_SSMTPE    EQU (1<<SSMTPE)       

SSMPVE       EQU 4       ; Sequencer State Machine PV Enable
BM_SSMPVE    EQU (1<<SSMPVE)       

SSMTAE       EQU 5       ; Sequencer State Machine Tx Ask-Shaping Enable
BM_SSMTAE    EQU (1<<SSMTAE)       

SETRPA       EQU 6       ; Sequencer State Machine Enable Transparent Path A
BM_SETRPA    EQU (1<<SETRPA)       

SETRPB       EQU 7       ; Sequencer State Machine Enable Transparent Path B
BM_SETRPB    EQU (1<<SETRPB)       

; SSMFBR - SSM Filter Bandwidth Register
SSMFID0       EQU 0       ; Sequencer State Machine Filter Delay bit 0
BM_SSMFID0    EQU (1<<SSMFID0)       

SSMFID1       EQU 1       ; Sequencer State Machine Filter Delay bit 1
BM_SSMFID1    EQU (1<<SSMFID1)       

SSMFID2       EQU 2       ; Sequencer State Machine Filter Delay bit 2
BM_SSMFID2    EQU (1<<SSMFID2)       

SSMDFDT       EQU 3       ; Sequencer State Machine Double Filter Delay Time
BM_SSMDFDT    EQU (1<<SSMDFDT)       

SSMHADT       EQU 4       ; Sequencer State Machine Half Antennadamping Delay Time
BM_SSMHADT    EQU (1<<SSMHADT)       

SSMPLDT       EQU 5       ; Sequencer State Machine PLL Lock Delay Time
BM_SSMPLDT    EQU (1<<SSMPLDT)       

; SSMFCR - SSM Flow Control Register
SSMIDSO       EQU 0       ; Sequencer State Machine ID Scan OK
BM_SSMIDSO    EQU (1<<SSMIDSO)       

SSMIDSF       EQU 1       ; Sequencer State Machine ID Scan Fail
BM_SSMIDSF    EQU (1<<SSMIDSF)       

; SSMIFR - SSM Interrupt Flag Register
SSMIF       EQU 0       ; Sequencer State Machine Interrupt Flag
BM_SSMIF    EQU (1<<SSMIF)       

; SSMIMR - SSM interrupt mask register
SSMIM       EQU 0       ; Sequencer State Machine Interrupt Mask
BM_SSMIM    EQU (1<<SSMIM)       

; SSMRCR - SSM Rx Control Register
SSMPA       EQU 0       ; Sequencer State Machine Path A
BM_SSMPA    EQU (1<<SSMPA)       

SSMPB       EQU 1       ; Sequencer State Machine Path B
BM_SSMPB    EQU (1<<SSMPB)       

SSMADA       EQU 2       ; Sequencer State Machine Antenna Damping Disable Path A
BM_SSMADA    EQU (1<<SSMADA)       

SSMADB       EQU 3       ; Sequencer State Machine Antenna Damping Disable Path B
BM_SSMADB    EQU (1<<SSMADB)       

SSMPVS       EQU 4       ; Sequencer State Machine Path Valid After SOT
BM_SSMPVS    EQU (1<<SSMPVS)       

SSMIFA       EQU 5       ; Sequencer State Machine IF Amplifier Enable
BM_SSMIFA    EQU (1<<SSMIFA)       

SSMIDSE       EQU 6       ; Sequencer State Machine ID Scan Enable
BM_SSMIDSE    EQU (1<<SSMIDSE)       

SSMTMOE       EQU 7       ; Sequencer State Machine Transparent Mode Output Enable
BM_SSMTMOE    EQU (1<<SSMTMOE)       

; SSMRR - SSM Run Register
SSMR       EQU 0       ; Sequencer State Machine Run
BM_SSMR    EQU (1<<SSMR)       

SSMST       EQU 1       ; Sequencer State Machine Stop
BM_SSMST    EQU (1<<SSMST)       

; SSMSR - SSM Status Register
SSMESM0       EQU 0       ; Sequencer State Machine Error State Machine bit 0
BM_SSMESM0    EQU (1<<SSMESM0)       

SSMESM1       EQU 1       ; Sequencer State Machine Error State Machine bit 1
BM_SSMESM1    EQU (1<<SSMESM1)       

SSMESM2       EQU 2       ; Sequencer State Machine Error State Machine bit 2
BM_SSMESM2    EQU (1<<SSMESM2)       

SSMESM3       EQU 3       ; Sequencer State Machine Error State Machine bit 3
BM_SSMESM3    EQU (1<<SSMESM3)       

SSMERR       EQU 7       ; Sequencer State Machine Error
BM_SSMERR    EQU (1<<SSMERR)       

; SSMSTR - SSM State Register
SSMSTA0       EQU 0       ; Sequencer State Machine State A bit 0
BM_SSMSTA0    EQU (1<<SSMSTA0)       

SSMSTA1       EQU 1       ; Sequencer State Machine State A bit 1
BM_SSMSTA1    EQU (1<<SSMSTA1)       

SSMSTA2       EQU 2       ; Sequencer State Machine State A bit 2
BM_SSMSTA2    EQU (1<<SSMSTA2)       

SSMSTA3       EQU 3       ; Sequencer State Machine State A bit 3
BM_SSMSTA3    EQU (1<<SSMSTA3)       

SSMSTA4       EQU 4       ; Sequencer State Machine State A bit 4
BM_SSMSTA4    EQU (1<<SSMSTA4)       

SSMSTA5       EQU 5       ; Sequencer State Machine State A bit 5
BM_SSMSTA5    EQU (1<<SSMSTA5)       

; SSMXSR - SSM extended State Register
SSMSTB0       EQU 0       ; Sequencer State Machine State B bit 0
BM_SSMSTB0    EQU (1<<SSMSTB0)       

SSMSTB1       EQU 1       ; Sequencer State Machine State B bit 1
BM_SSMSTB1    EQU (1<<SSMSTB1)       

SSMSTB2       EQU 2       ; Sequencer State Machine State B bit 2
BM_SSMSTB2    EQU (1<<SSMSTB2)       

SSMSTB3       EQU 3       ; Sequencer State Machine State B bit 3
BM_SSMSTB3    EQU (1<<SSMSTB3)       

SSMSTB4       EQU 4       ; Sequencer State Machine State B bit 4
BM_SSMSTB4    EQU (1<<SSMSTB4)       

SSMSTB5       EQU 5       ; Sequencer State Machine State B bit 5
BM_SSMSTB5    EQU (1<<SSMSTB5)       

; WCOTOA - Wait check ok time out for path A
WCOTOA0       EQU 0       ; Wait check ok time out for path A bit 0
BM_WCOTOA0    EQU (1<<WCOTOA0)       

WCOTOA1       EQU 1       ; Wait check ok time out for path A bit 1
BM_WCOTOA1    EQU (1<<WCOTOA1)       

WCOTOA2       EQU 2       ; Wait check ok time out for path A bit 2
BM_WCOTOA2    EQU (1<<WCOTOA2)       

WCOTOA3       EQU 3       ; Wait check ok time out for path A bit 3
BM_WCOTOA3    EQU (1<<WCOTOA3)       

WCOTOA4       EQU 4       ; Wait check ok time out for path A bit 4
BM_WCOTOA4    EQU (1<<WCOTOA4)       

WCOTOA5       EQU 5       ; Wait check ok time out for path A bit 5
BM_WCOTOA5    EQU (1<<WCOTOA5)       

WCOTOA6       EQU 6       ; Wait check ok time out for path A bit 6
BM_WCOTOA6    EQU (1<<WCOTOA6)       

WCOTOA7       EQU 7       ; Wait check ok time out for path A bit 7
BM_WCOTOA7    EQU (1<<WCOTOA7)       

; WCOTOB - Wait check ok time out for path B
WCOTOB0       EQU 0       ; Wait check ok time out for path B bit 0
BM_WCOTOB0    EQU (1<<WCOTOB0)       

WCOTOB1       EQU 1       ; Wait check ok time out for path B bit 1
BM_WCOTOB1    EQU (1<<WCOTOB1)       

WCOTOB2       EQU 2       ; Wait check ok time out for path B bit 2
BM_WCOTOB2    EQU (1<<WCOTOB2)       

WCOTOB3       EQU 3       ; Wait check ok time out for path B bit 3
BM_WCOTOB3    EQU (1<<WCOTOB3)       

WCOTOB4       EQU 4       ; Wait check ok time out for path B bit 4
BM_WCOTOB4    EQU (1<<WCOTOB4)       

WCOTOB5       EQU 5       ; Wait check ok time out for path B bit 5
BM_WCOTOB5    EQU (1<<WCOTOB5)       

WCOTOB6       EQU 6       ; Wait check ok time out for path B bit 6
BM_WCOTOB6    EQU (1<<WCOTOB6)       

WCOTOB7       EQU 7       ; Wait check ok time out for path B bit 7
BM_WCOTOB7    EQU (1<<WCOTOB7)       

; ***** SUP **************************
; CALRDY - Calibration ready signature
CALRDY0       EQU 0       ; Calibration ready signature bit 0
BM_CALRDY0    EQU (1<<CALRDY0)       

CALRDY1       EQU 1       ; Calibration ready signature bit 1
BM_CALRDY1    EQU (1<<CALRDY1)       

CALRDY2       EQU 2       ; Calibration ready signature bit 2
BM_CALRDY2    EQU (1<<CALRDY2)       

CALRDY3       EQU 3       ; Calibration ready signature bit 3
BM_CALRDY3    EQU (1<<CALRDY3)       

CALRDY4       EQU 4       ; Calibration ready signature bit 4
BM_CALRDY4    EQU (1<<CALRDY4)       

CALRDY5       EQU 5       ; Calibration ready signature bit 5
BM_CALRDY5    EQU (1<<CALRDY5)       

CALRDY6       EQU 6       ; Calibration ready signature bit 6
BM_CALRDY6    EQU (1<<CALRDY6)       

CALRDY7       EQU 7       ; Calibration ready signature bit 7
BM_CALRDY7    EQU (1<<CALRDY7)       

; SUPCA1 - Supply calibration register 1
PV22       EQU 2       ; Power Amplifier Voltage 2.2V
BM_PV22    EQU (1<<PV22)       

PVDIC       EQU 3       ; Power Amplifier Regulator Double Internal Current
BM_PVDIC    EQU (1<<PVDIC)       

PVCAL0       EQU 4       ; Power Amplifier Regulator Calibration bit 0
BM_PVCAL0    EQU (1<<PVCAL0)       

PVCAL1       EQU 5       ; Power Amplifier Regulator Calibration bit 1
BM_PVCAL1    EQU (1<<PVCAL1)       

PVCAL2       EQU 6       ; Power Amplifier Regulator Calibration bit 2
BM_PVCAL2    EQU (1<<PVCAL2)       

PVCAL3       EQU 7       ; Power Amplifier Regulator Calibration bit 3
BM_PVCAL3    EQU (1<<PVCAL3)       

; SUPCA2 - Supply calibration register 2
BGCAL0       EQU 0       ; Band Gap Calibration bit 0
BM_BGCAL0    EQU (1<<BGCAL0)       

BGCAL1       EQU 1       ; Band Gap Calibration bit 1
BM_BGCAL1    EQU (1<<BGCAL1)       

BGCAL2       EQU 2       ; Band Gap Calibration bit 2
BM_BGCAL2    EQU (1<<BGCAL2)       

BGCAL3       EQU 3       ; Band Gap Calibration bit 3
BM_BGCAL3    EQU (1<<BGCAL3)       

; SUPCA3 - Supply calibration register 3
ACAL4       EQU 0       ; AVCC Reset Threshold Calibration bit 4
BM_ACAL4    EQU (1<<ACAL4)       

ACAL5       EQU 1       ; AVCC Reset Threshold Calibration bit 5
BM_ACAL5    EQU (1<<ACAL5)       

ACAL6       EQU 2       ; AVCC Reset Threshold Calibration bit 6
BM_ACAL6    EQU (1<<ACAL6)       

ACAL7       EQU 3       ; AVCC Reset Threshold Calibration bit 7
BM_ACAL7    EQU (1<<ACAL7)       

DCAL4       EQU 4       ; DVCC Reset Threshold Calibration bit 4
BM_DCAL4    EQU (1<<DCAL4)       

DCAL5       EQU 5       ; DVCC Reset Threshold Calibration bit 5
BM_DCAL5    EQU (1<<DCAL5)       

DCAL6       EQU 6       ; DVCC Reset Threshold Calibration bit 6
BM_DCAL6    EQU (1<<DCAL6)       

; SUPCA4 - Supply calibration register 4
ACAL0       EQU 0       ; AVCC Regulator Output Voltage Calibration bit 0
BM_ACAL0    EQU (1<<ACAL0)       

ACAL1       EQU 1       ; AVCC Regulator Output Voltage Calibration bit 1
BM_ACAL1    EQU (1<<ACAL1)       

ACAL2       EQU 2       ; AVCC Regulator Output Voltage Calibration bit 2
BM_ACAL2    EQU (1<<ACAL2)       

ACAL3       EQU 3       ; AVCC Regulator Output Voltage Calibration bit 3
BM_ACAL3    EQU (1<<ACAL3)       

DCAL0       EQU 4       ; DVCC Regulator Output Voltage Calibration bit 0
BM_DCAL0    EQU (1<<DCAL0)       

DCAL1       EQU 5       ; DVCC Regulator Output Voltage Calibration bit 1
BM_DCAL1    EQU (1<<DCAL1)       

DCAL2       EQU 6       ; DVCC Regulator Output Voltage Calibration bit 2
BM_DCAL2    EQU (1<<DCAL2)       

DCAL3       EQU 7       ; DVCC Regulator Output Voltage Calibration bit 3
BM_DCAL3    EQU (1<<DCAL3)       

; SUPCR - Supply Control Register
AVCCRM       EQU 0       ; AVCC Reset Interrupt Mask Bit
BM_AVCCRM    EQU (1<<AVCCRM)       

AVCCLM       EQU 1       ; AVCC Low Interrupt Mask Bit
BM_AVCCLM    EQU (1<<AVCCLM)       

PVEN       EQU 2       ; Power amplifier Voltage supply Enable
BM_PVEN    EQU (1<<PVEN)       

DVDIS       EQU 4       ; DVCC Disable
BM_DVDIS    EQU (1<<DVDIS)       

AVEN       EQU 5       ; AVCC Enable
BM_AVEN    EQU (1<<AVEN)       

AVDIC       EQU 6       ; AVCC Double Internal Current
BM_AVDIC    EQU (1<<AVDIC)       

; SUPFR - Supply Interrupt Flag Register
AVCCRF       EQU 0       ; AVCC reset interrupt flag
BM_AVCCRF    EQU (1<<AVCCRF)       

AVCCLF       EQU 1       ; AVCC low interrupt flag
BM_AVCCLF    EQU (1<<AVCCLF)       

; VMCAL - Voltage Monitor Calibration register
VMCAL0       EQU 0       ; Voltage monitor calibration bit 0
BM_VMCAL0    EQU (1<<VMCAL0)       

VMCAL1       EQU 1       ; Voltage monitor calibration bit 1
BM_VMCAL1    EQU (1<<VMCAL1)       

VMCAL2       EQU 2       ; Voltage monitor calibration bit 2
BM_VMCAL2    EQU (1<<VMCAL2)       

; VMCSR - Voltage Monitor Control and Status Register
VMLS0       EQU 0       ; Voltage Monitor Level Select bit 0
BM_VMLS0    EQU (1<<VMLS0)       

VMLS1       EQU 1       ; Voltage Monitor Level Select bit 1
BM_VMLS1    EQU (1<<VMLS1)       

VMLS2       EQU 2       ; Voltage Monitor Level Select bit 2
BM_VMLS2    EQU (1<<VMLS2)       

VMLS3       EQU 3       ; Voltage Monitor Level Select bit 3
BM_VMLS3    EQU (1<<VMLS3)       

VMIM       EQU 4       ; Voltage Monitor Interrupt Mask
BM_VMIM    EQU (1<<VMIM)       

VMF       EQU 5       ; Voltage Monitor Flag
BM_VMF    EQU (1<<VMF)       

; ***** SYMCH ************************
; SYCA - Symbol check configuration for data path A
SYCSA0       EQU 0       ; Symbol Check check size for data path A bit 0
BM_SYCSA0    EQU (1<<SYCSA0)       

SYCSA1       EQU 1       ; Symbol Check check size for data path A bit 1
BM_SYCSA1    EQU (1<<SYCSA1)       

SYCSA2       EQU 2       ; Symbol Check check size for data path A bit 2
BM_SYCSA2    EQU (1<<SYCSA2)       

SYCSA3       EQU 3       ; Symbol Check check size for data path A bit 3
BM_SYCSA3    EQU (1<<SYCSA3)       

SYTLA0       EQU 4       ; Symbol timing limit for path A bit 0
BM_SYTLA0    EQU (1<<SYTLA0)       

SYTLA1       EQU 5       ; Symbol timing limit for path A bit 1
BM_SYTLA1    EQU (1<<SYTLA1)       

SYTLA2       EQU 6       ; Symbol timing limit for path A bit 2
BM_SYTLA2    EQU (1<<SYTLA2)       

SYTLA3       EQU 7       ; Symbol timing limit for path A bit 3
BM_SYTLA3    EQU (1<<SYTLA3)       

; SYCB - Symbol check configuration for data path B
SYCSB0       EQU 0       ; Symbol Check check size for data path B bit 0
BM_SYCSB0    EQU (1<<SYCSB0)       

SYCSB1       EQU 1       ; Symbol Check check size for data path B bit 1
BM_SYCSB1    EQU (1<<SYCSB1)       

SYCSB2       EQU 2       ; Symbol Check check size for data path B bit 2
BM_SYCSB2    EQU (1<<SYCSB2)       

SYCSB3       EQU 3       ; Symbol Check check size for data path B bit 3
BM_SYCSB3    EQU (1<<SYCSB3)       

SYTLB0       EQU 4       ; Symbol timing limit for path B bit 0
BM_SYTLB0    EQU (1<<SYTLB0)       

SYTLB1       EQU 5       ; Symbol timing limit for path B bit 1
BM_SYTLB1    EQU (1<<SYTLB1)       

SYTLB2       EQU 6       ; Symbol timing limit for path B bit 2
BM_SYTLB2    EQU (1<<SYTLB2)       

SYTLB3       EQU 7       ; Symbol timing limit for path B bit 3
BM_SYTLB3    EQU (1<<SYTLB3)       

; ***** TEMPER ***********************
; TEMPH - Temperature High byte
TEMPH0       EQU 0       ; Temperature High byte bit 0
BM_TEMPH0    EQU (1<<TEMPH0)       

TEMPH1       EQU 1       ; Temperature High byte bit 1
BM_TEMPH1    EQU (1<<TEMPH1)       

TEMPH2       EQU 2       ; Temperature High byte bit 2
BM_TEMPH2    EQU (1<<TEMPH2)       

TEMPH3       EQU 3       ; Temperature High byte bit 3
BM_TEMPH3    EQU (1<<TEMPH3)       

TEMPH4       EQU 4       ; Temperature High byte bit 4
BM_TEMPH4    EQU (1<<TEMPH4)       

TEMPH5       EQU 5       ; Temperature High byte bit 5
BM_TEMPH5    EQU (1<<TEMPH5)       

TEMPH6       EQU 6       ; Temperature High byte bit 6
BM_TEMPH6    EQU (1<<TEMPH6)       

TEMPH7       EQU 7       ; Temperature High byte bit 7
BM_TEMPH7    EQU (1<<TEMPH7)       

; TEMPL - Temperature Low byte
TEMPL0       EQU 0       ; Temperature Low byte bit 0
BM_TEMPL0    EQU (1<<TEMPL0)       

TEMPL1       EQU 1       ; Temperature Low byte bit 1
BM_TEMPL1    EQU (1<<TEMPL1)       

TEMPL2       EQU 2       ; Temperature Low byte bit 2
BM_TEMPL2    EQU (1<<TEMPL2)       

TEMPL3       EQU 3       ; Temperature Low byte bit 3
BM_TEMPL3    EQU (1<<TEMPL3)       

TEMPL4       EQU 4       ; Temperature Low byte bit 4
BM_TEMPL4    EQU (1<<TEMPL4)       

TEMPL5       EQU 5       ; Temperature Low byte bit 5
BM_TEMPL5    EQU (1<<TEMPL5)       

TEMPL6       EQU 6       ; Temperature Low byte bit 6
BM_TEMPL6    EQU (1<<TEMPL6)       

TEMPL7       EQU 7       ; Temperature Low byte bit 7
BM_TEMPL7    EQU (1<<TEMPL7)       

; ***** TIMER0_WDT *******************
; T0CR - Timer0 Control Register
T0PS0       EQU 0       ; Timer 0 Prescaler Select bit 0
BM_T0PS0    EQU (1<<T0PS0)       

T0PS1       EQU 1       ; Timer 0 Prescaler Select bit 1
BM_T0PS1    EQU (1<<T0PS1)       

T0PS2       EQU 2       ; Timer 0 Prescaler Select bit 2
BM_T0PS2    EQU (1<<T0PS2)       

T0IE       EQU 3       ; Timer 0 Interrupt Enable
BM_T0IE    EQU (1<<T0IE)       

T0PR       EQU 4       ; Timer 0 Prescaler Reset
BM_T0PR    EQU (1<<T0PR)       

; T0IFR - Timer0 Interrupt Flag Register
T0F       EQU 0       ; Timer0 Flag
BM_T0F    EQU (1<<T0F)       

; WDTCR - Watchdog Timer0 control Register
WDPS0       EQU 0       ; Watchdog Prescaler Select bit 0
BM_WDPS0    EQU (1<<WDPS0)       

WDPS1       EQU 1       ; Watchdog Prescaler Select bit 1
BM_WDPS1    EQU (1<<WDPS1)       

WDPS2       EQU 2       ; Watchdog Prescaler Select bit 2
BM_WDPS2    EQU (1<<WDPS2)       

WDE       EQU 3       ; Watchdog System Reset Enable
BM_WDE    EQU (1<<WDE)       

WDCE       EQU 4       ; Watchdog Change Enable
BM_WDCE    EQU (1<<WDCE)       

; ***** TIMER1 ***********************
; T1CNT - Timer1 Counter Register
T1CNT0       EQU 0       ; Timer1 Counter bit 0
BM_T1CNT0    EQU (1<<T1CNT0)       

T1CNT1       EQU 1       ; Timer1 Counter bit 1
BM_T1CNT1    EQU (1<<T1CNT1)       

T1CNT2       EQU 2       ; Timer1 Counter bit 2
BM_T1CNT2    EQU (1<<T1CNT2)       

T1CNT3       EQU 3       ; Timer1 Counter bit 3
BM_T1CNT3    EQU (1<<T1CNT3)       

T1CNT4       EQU 4       ; Timer1 Counter bit 4
BM_T1CNT4    EQU (1<<T1CNT4)       

T1CNT5       EQU 5       ; Timer1 Counter bit 5
BM_T1CNT5    EQU (1<<T1CNT5)       

T1CNT6       EQU 6       ; Timer1 Counter bit 6
BM_T1CNT6    EQU (1<<T1CNT6)       

T1CNT7       EQU 7       ; Timer1 Counter bit 7
BM_T1CNT7    EQU (1<<T1CNT7)       

; T1COR - Timer1 Compare Register
T1COR0       EQU 0       ; Timer1 Compare bit 0
BM_T1COR0    EQU (1<<T1COR0)       

T1COR1       EQU 1       ; Timer1 Compare bit 1
BM_T1COR1    EQU (1<<T1COR1)       

T1COR2       EQU 2       ; Timer1 Compare bit 2
BM_T1COR2    EQU (1<<T1COR2)       

T1COR3       EQU 3       ; Timer1 Compare bit 3
BM_T1COR3    EQU (1<<T1COR3)       

T1COR4       EQU 4       ; Timer1 Compare bit 4
BM_T1COR4    EQU (1<<T1COR4)       

T1COR5       EQU 5       ; Timer1 Compare bit 5
BM_T1COR5    EQU (1<<T1COR5)       

T1COR6       EQU 6       ; Timer1 Compare bit 6
BM_T1COR6    EQU (1<<T1COR6)       

T1COR7       EQU 7       ; Timer1 Compare bit 7
BM_T1COR7    EQU (1<<T1COR7)       

; T1CR - Timer1 control Register
T1OTM       EQU 0       ; Timer1 Overflow Toggle Mask
BM_T1OTM    EQU (1<<T1OTM)       

T1CTM       EQU 1       ; Timer1 Compare Toggle Mask
BM_T1CTM    EQU (1<<T1CTM)       

T1CRM       EQU 2       ; Timer1 Compare Reset Mask
BM_T1CRM    EQU (1<<T1CRM)       

T1TOP       EQU 4       ; Timer1 Toggle Output Preset
BM_T1TOP    EQU (1<<T1TOP)       

T1RES       EQU 5       ; Timer1 Reset
BM_T1RES    EQU (1<<T1RES)       

T1TOS       EQU 6       ; Timer1 Toggle with Start
BM_T1TOS    EQU (1<<T1TOS)       

T1ENA       EQU 7       ; Timer1 Enable
BM_T1ENA    EQU (1<<T1ENA)       

; T1IFR - Timer1 Interrupt Flag Register
T1OFF       EQU 0       ; Timer1 Overflow Flag
BM_T1OFF    EQU (1<<T1OFF)       

T1COF       EQU 1       ; Timer1 Compare Flag
BM_T1COF    EQU (1<<T1COF)       

; T1IMR - Timer1 Interrupt Mask Register
T1OIM       EQU 0       ; Timer1 Overflow Interrupt Mask
BM_T1OIM    EQU (1<<T1OIM)       

T1CIM       EQU 1       ; Timer1 Compare Interrupt Mask
BM_T1CIM    EQU (1<<T1CIM)       

; T1MR - Timer1 Mode Register
T1CS0       EQU 0       ; Timer1 Clock Select bit 0
BM_T1CS0    EQU (1<<T1CS0)       

T1CS1       EQU 1       ; Timer1 Clock Select bit 1
BM_T1CS1    EQU (1<<T1CS1)       

T1PS0       EQU 2       ; Timer1 Prescaler Select bit 0
BM_T1PS0    EQU (1<<T1PS0)       

T1PS1       EQU 3       ; Timer1 Prescaler Select bit 1
BM_T1PS1    EQU (1<<T1PS1)       

T1PS2       EQU 4       ; Timer1 Prescaler Select bit 2
BM_T1PS2    EQU (1<<T1PS2)       

T1PS3       EQU 5       ; Timer1 Prescaler Select bit 3
BM_T1PS3    EQU (1<<T1PS3)       

T1DC0       EQU 6       ; Timer1 Duty Cycle bit 0
BM_T1DC0    EQU (1<<T1DC0)       

T1DC1       EQU 7       ; Timer1 Duty Cycle bit 1
BM_T1DC1    EQU (1<<T1DC1)       

; ***** TIMER2 ***********************
; T2CNT - Timer2 Counter Register
T2CNT0       EQU 0       ; Timer2 Counter bit 0
BM_T2CNT0    EQU (1<<T2CNT0)       

T2CNT1       EQU 1       ; Timer2 Counter bit 1
BM_T2CNT1    EQU (1<<T2CNT1)       

T2CNT2       EQU 2       ; Timer2 Counter bit 2
BM_T2CNT2    EQU (1<<T2CNT2)       

T2CNT3       EQU 3       ; Timer2 Counter bit 3
BM_T2CNT3    EQU (1<<T2CNT3)       

T2CNT4       EQU 4       ; Timer2 Counter bit 4
BM_T2CNT4    EQU (1<<T2CNT4)       

T2CNT5       EQU 5       ; Timer2 Counter bit 5
BM_T2CNT5    EQU (1<<T2CNT5)       

T2CNT6       EQU 6       ; Timer2 Counter bit 6
BM_T2CNT6    EQU (1<<T2CNT6)       

T2CNT7       EQU 7       ; Timer2 Counter bit 7
BM_T2CNT7    EQU (1<<T2CNT7)       

; T2COR - Timer2 Compare Register
T2COR0       EQU 0       ; Timer2 Compare bit 0
BM_T2COR0    EQU (1<<T2COR0)       

T2COR1       EQU 1       ; Timer2 Compare bit 1
BM_T2COR1    EQU (1<<T2COR1)       

T2COR2       EQU 2       ; Timer2 Compare bit 2
BM_T2COR2    EQU (1<<T2COR2)       

T2COR3       EQU 3       ; Timer2 Compare bit 3
BM_T2COR3    EQU (1<<T2COR3)       

T2COR4       EQU 4       ; Timer2 Compare bit 4
BM_T2COR4    EQU (1<<T2COR4)       

T2COR5       EQU 5       ; Timer2 Compare bit 5
BM_T2COR5    EQU (1<<T2COR5)       

T2COR6       EQU 6       ; Timer2 Compare bit 6
BM_T2COR6    EQU (1<<T2COR6)       

T2COR7       EQU 7       ; Timer2 Compare bit 7
BM_T2COR7    EQU (1<<T2COR7)       

; T2CR - Timer2 Control Register
T2OTM       EQU 0       ; Timer2 Overflow Toggle Mask
BM_T2OTM    EQU (1<<T2OTM)       

T2CTM       EQU 1       ; Timer2 Compare Toggle Mask
BM_T2CTM    EQU (1<<T2CTM)       

T2CRM       EQU 2       ; Timer2 Compare Reset Mask
BM_T2CRM    EQU (1<<T2CRM)       

T2TOP       EQU 4       ; Timer2 Toggle Output Preset
BM_T2TOP    EQU (1<<T2TOP)       

T2RES       EQU 5       ; Timer2 Reset
BM_T2RES    EQU (1<<T2RES)       

T2TOS       EQU 6       ; Timer2 Toggle with Start
BM_T2TOS    EQU (1<<T2TOS)       

T2ENA       EQU 7       ; Timer2 Enable
BM_T2ENA    EQU (1<<T2ENA)       

; T2IFR - Timer2 Interrupt Flag Register
T2OFF       EQU 0       ; Timer2 Overflow Flag
BM_T2OFF    EQU (1<<T2OFF)       

T2COF       EQU 1       ; Timer2 Compare Flag
BM_T2COF    EQU (1<<T2COF)       

; T2IMR - Timer2 Interrupt Mask Register
T2OIM       EQU 0       ; Timer2 Overflow Interrupt Mask
BM_T2OIM    EQU (1<<T2OIM)       

T2CIM       EQU 1       ; Timer2 Compare Interrupt Mask
BM_T2CIM    EQU (1<<T2CIM)       

; T2MR - Timer2 Mode Register
T2CS0       EQU 0       ; Timer2 Clock Select bit 0
BM_T2CS0    EQU (1<<T2CS0)       

T2CS1       EQU 1       ; Timer2 Clock Select bit 1
BM_T2CS1    EQU (1<<T2CS1)       

T2PS0       EQU 2       ; Timer2 Prescaler Select bit 0
BM_T2PS0    EQU (1<<T2PS0)       

T2PS1       EQU 3       ; Timer2 Prescaler Select bit 1
BM_T2PS1    EQU (1<<T2PS1)       

T2PS2       EQU 4       ; Timer2 Prescaler Select bit 2
BM_T2PS2    EQU (1<<T2PS2)       

T2PS3       EQU 5       ; Timer2 Prescaler Select bit 3
BM_T2PS3    EQU (1<<T2PS3)       

T2DC0       EQU 6       ; Timer2 Duty Cycle bit 0
BM_T2DC0    EQU (1<<T2DC0)       

T2DC1       EQU 7       ; Timer2 Duty Cycle bit 1
BM_T2DC1    EQU (1<<T2DC1)       

; ***** TIMER3 ***********************
; T3CNTH - Timer3 counter High Byte Register
T3CNTH0       EQU 0       ; Timer3 counter High Byte bit 0
BM_T3CNTH0    EQU (1<<T3CNTH0)       

T3CNTH1       EQU 1       ; Timer3 counter High Byte bit 1
BM_T3CNTH1    EQU (1<<T3CNTH1)       

T3CNTH2       EQU 2       ; Timer3 counter High Byte bit 2
BM_T3CNTH2    EQU (1<<T3CNTH2)       

T3CNTH3       EQU 3       ; Timer3 counter High Byte bit 3
BM_T3CNTH3    EQU (1<<T3CNTH3)       

T3CNTH4       EQU 4       ; Timer3 counter High Byte bit 4
BM_T3CNTH4    EQU (1<<T3CNTH4)       

T3CNTH5       EQU 5       ; Timer3 counter High Byte bit 5
BM_T3CNTH5    EQU (1<<T3CNTH5)       

T3CNTH6       EQU 6       ; Timer3 counter High Byte bit 6
BM_T3CNTH6    EQU (1<<T3CNTH6)       

T3CNTH7       EQU 7       ; Timer3 counter High Byte bit 7
BM_T3CNTH7    EQU (1<<T3CNTH7)       

; T3CNTL - Timer3 counter Low Byte Register
T3CNTL0       EQU 0       ; Timer3 counter Low Byte bit 0
BM_T3CNTL0    EQU (1<<T3CNTL0)       

T3CNTL1       EQU 1       ; Timer3 counter Low Byte bit 1
BM_T3CNTL1    EQU (1<<T3CNTL1)       

T3CNTL2       EQU 2       ; Timer3 counter Low Byte bit 2
BM_T3CNTL2    EQU (1<<T3CNTL2)       

T3CNTL3       EQU 3       ; Timer3 counter Low Byte bit 3
BM_T3CNTL3    EQU (1<<T3CNTL3)       

T3CNTL4       EQU 4       ; Timer3 counter Low Byte bit 4
BM_T3CNTL4    EQU (1<<T3CNTL4)       

T3CNTL5       EQU 5       ; Timer3 counter Low Byte bit 5
BM_T3CNTL5    EQU (1<<T3CNTL5)       

T3CNTL6       EQU 6       ; Timer3 counter Low Byte bit 6
BM_T3CNTL6    EQU (1<<T3CNTL6)       

T3CNTL7       EQU 7       ; Timer3 counter Low Byte bit 7
BM_T3CNTL7    EQU (1<<T3CNTL7)       

; T3CORH - Timer3 compare High Byte Register
T3CORH0       EQU 0       ; Timer3 compare High Byte bit 0
BM_T3CORH0    EQU (1<<T3CORH0)       

T3CORH1       EQU 1       ; Timer3 compare High Byte bit 1
BM_T3CORH1    EQU (1<<T3CORH1)       

T3CORH2       EQU 2       ; Timer3 compare High Byte bit 2
BM_T3CORH2    EQU (1<<T3CORH2)       

T3CORH3       EQU 3       ; Timer3 compare High Byte bit 3
BM_T3CORH3    EQU (1<<T3CORH3)       

T3CORH4       EQU 4       ; Timer3 compare High Byte bit 4
BM_T3CORH4    EQU (1<<T3CORH4)       

T3CORH5       EQU 5       ; Timer3 compare High Byte bit 5
BM_T3CORH5    EQU (1<<T3CORH5)       

T3CORH6       EQU 6       ; Timer3 compare High Byte bit 6
BM_T3CORH6    EQU (1<<T3CORH6)       

T3CORH7       EQU 7       ; Timer3 compare High Byte bit 7
BM_T3CORH7    EQU (1<<T3CORH7)       

; T3CORL - Timer3 compare Low Byte Register
T3CORL0       EQU 0       ; Timer3 compare Low Byte bit 0
BM_T3CORL0    EQU (1<<T3CORL0)       

T3CORL1       EQU 1       ; Timer3 compare Low Byte bit 1
BM_T3CORL1    EQU (1<<T3CORL1)       

T3CORL2       EQU 2       ; Timer3 compare Low Byte bit 2
BM_T3CORL2    EQU (1<<T3CORL2)       

T3CORL3       EQU 3       ; Timer3 compare Low Byte bit 3
BM_T3CORL3    EQU (1<<T3CORL3)       

T3CORL4       EQU 4       ; Timer3 compare Low Byte bit 4
BM_T3CORL4    EQU (1<<T3CORL4)       

T3CORL5       EQU 5       ; Timer3 compare Low Byte bit 5
BM_T3CORL5    EQU (1<<T3CORL5)       

T3CORL6       EQU 6       ; Timer3 compare Low Byte bit 6
BM_T3CORL6    EQU (1<<T3CORL6)       

T3CORL7       EQU 7       ; Timer3 compare Low Byte bit 7
BM_T3CORL7    EQU (1<<T3CORL7)       

; T3CR - Timer3 control Register
T3OTM       EQU 0       ; Timer3 Overflow Toggle Mask
BM_T3OTM    EQU (1<<T3OTM)       

T3CTM       EQU 1       ; Timer3 Compare Toggle Mask
BM_T3CTM    EQU (1<<T3CTM)       

T3CRM       EQU 2       ; Timer3 Compare Reset Mask
BM_T3CRM    EQU (1<<T3CRM)       

T3CPRM       EQU 3       ; Timer3 CaPture reset Mask
BM_T3CPRM    EQU (1<<T3CPRM)       

T3TOP       EQU 4       ; Timer3 Toggle Output Preset
BM_T3TOP    EQU (1<<T3TOP)       

T3RES       EQU 5       ; Timer3 Reset
BM_T3RES    EQU (1<<T3RES)       

T3TOS       EQU 6       ; Timer3 Toggle with Start
BM_T3TOS    EQU (1<<T3TOS)       

T3ENA       EQU 7       ; Timer3 Enable
BM_T3ENA    EQU (1<<T3ENA)       

; T3ICRH - Timer3 input capture High Byte Register
T3ICRH0       EQU 0       ; Timer3 input capture High Byte bit 0
BM_T3ICRH0    EQU (1<<T3ICRH0)       

T3ICRH1       EQU 1       ; Timer3 input capture High Byte bit 1
BM_T3ICRH1    EQU (1<<T3ICRH1)       

T3ICRH2       EQU 2       ; Timer3 input capture High Byte bit 2
BM_T3ICRH2    EQU (1<<T3ICRH2)       

T3ICRH3       EQU 3       ; Timer3 input capture High Byte bit 3
BM_T3ICRH3    EQU (1<<T3ICRH3)       

T3ICRH4       EQU 4       ; Timer3 input capture High Byte bit 4
BM_T3ICRH4    EQU (1<<T3ICRH4)       

T3ICRH5       EQU 5       ; Timer3 input capture High Byte bit 5
BM_T3ICRH5    EQU (1<<T3ICRH5)       

T3ICRH6       EQU 6       ; Timer3 input capture High Byte bit 6
BM_T3ICRH6    EQU (1<<T3ICRH6)       

T3ICRH7       EQU 7       ; Timer3 input capture High Byte bit 7
BM_T3ICRH7    EQU (1<<T3ICRH7)       

; T3ICRL - Timer3 input capture Low Byte Register
T3ICRL0       EQU 0       ; Timer3 input capture Low Byte bit 0
BM_T3ICRL0    EQU (1<<T3ICRL0)       

T3ICRL1       EQU 1       ; Timer3 input capture Low Byte bit 1
BM_T3ICRL1    EQU (1<<T3ICRL1)       

T3ICRL2       EQU 2       ; Timer3 input capture Low Byte bit 2
BM_T3ICRL2    EQU (1<<T3ICRL2)       

T3ICRL3       EQU 3       ; Timer3 input capture Low Byte bit 3
BM_T3ICRL3    EQU (1<<T3ICRL3)       

T3ICRL4       EQU 4       ; Timer3 input capture Low Byte bit 4
BM_T3ICRL4    EQU (1<<T3ICRL4)       

T3ICRL5       EQU 5       ; Timer3 input capture Low Byte bit 5
BM_T3ICRL5    EQU (1<<T3ICRL5)       

T3ICRL6       EQU 6       ; Timer3 input capture Low Byte bit 6
BM_T3ICRL6    EQU (1<<T3ICRL6)       

T3ICRL7       EQU 7       ; Timer3 input capture Low Byte bit 7
BM_T3ICRL7    EQU (1<<T3ICRL7)       

; T3IFR - Timer3 interrupt flag Register
T3OFF       EQU 0       ; Timer3 OverFlow Flag
BM_T3OFF    EQU (1<<T3OFF)       

T3COF       EQU 1       ; Timer3 Compare Flag
BM_T3COF    EQU (1<<T3COF)       

T3ICF       EQU 2       ; Timer3 Input Capture Flag
BM_T3ICF    EQU (1<<T3ICF)       

; T3IMR - Timer3 interrupt mask Register
T3OIM       EQU 0       ; Timer3 Overflow Interrupt Mask
BM_T3OIM    EQU (1<<T3OIM)       

T3CIM       EQU 1       ; Timer3 Compare Interrupt Mask
BM_T3CIM    EQU (1<<T3CIM)       

T3CPIM       EQU 2       ; Timer3 Capture Interrupt Mask
BM_T3CPIM    EQU (1<<T3CPIM)       

; T3MRA - Timer3 mode Register
T3CS0       EQU 0       ; Timer 3 Clock Select bit 0
BM_T3CS0    EQU (1<<T3CS0)       

T3CS1       EQU 1       ; Timer 3 Clock Select bit 1
BM_T3CS1    EQU (1<<T3CS1)       

T3PS0       EQU 2       ; Timer3 Prescaler Select bit 0
BM_T3PS0    EQU (1<<T3PS0)       

T3PS1       EQU 3       ; Timer3 Prescaler Select bit 1
BM_T3PS1    EQU (1<<T3PS1)       

T3PS2       EQU 4       ; Timer3 Prescaler Select bit 2
BM_T3PS2    EQU (1<<T3PS2)       

; T3MRB - Timer3 mode Register
T3SCE       EQU 1       ; Timer3 Software Capture Enable
BM_T3SCE    EQU (1<<T3SCE)       

T3CNC       EQU 2       ; Timer3 input Capture Noise Canceller
BM_T3CNC    EQU (1<<T3CNC)       

T3CE0       EQU 3       ; Timer3 Capture Edge select bit 0
BM_T3CE0    EQU (1<<T3CE0)       

T3CE1       EQU 4       ; Timer3 Capture Edge select bit 1
BM_T3CE1    EQU (1<<T3CE1)       

T3ICS0       EQU 5       ; Timer3 Input Capture Select bit 0
BM_T3ICS0    EQU (1<<T3ICS0)       

T3ICS1       EQU 6       ; Timer3 Input Capture Select bit 1
BM_T3ICS1    EQU (1<<T3ICS1)       

T3ICS2       EQU 7       ; Timer3 Input Capture Select bit 2
BM_T3ICS2    EQU (1<<T3ICS2)       

; ***** TIMER4 ***********************
; T4CNTH - Timer4 counter High Byte Register
T4CNTH0       EQU 0       ; Timer4 counter High Byte bit 0
BM_T4CNTH0    EQU (1<<T4CNTH0)       

T4CNTH1       EQU 1       ; Timer4 counter High Byte bit 1
BM_T4CNTH1    EQU (1<<T4CNTH1)       

T4CNTH2       EQU 2       ; Timer4 counter High Byte bit 2
BM_T4CNTH2    EQU (1<<T4CNTH2)       

T4CNTH3       EQU 3       ; Timer4 counter High Byte bit 3
BM_T4CNTH3    EQU (1<<T4CNTH3)       

T4CNTH4       EQU 4       ; Timer4 counter High Byte bit 4
BM_T4CNTH4    EQU (1<<T4CNTH4)       

T4CNTH5       EQU 5       ; Timer4 counter High Byte bit 5
BM_T4CNTH5    EQU (1<<T4CNTH5)       

T4CNTH6       EQU 6       ; Timer4 counter High Byte bit 6
BM_T4CNTH6    EQU (1<<T4CNTH6)       

T4CNTH7       EQU 7       ; Timer4 counter High Byte bit 7
BM_T4CNTH7    EQU (1<<T4CNTH7)       

; T4CNTL - Timer4 counter Low Byte Register
T4CNTL0       EQU 0       ; Timer4 counter Low Byte bit 0
BM_T4CNTL0    EQU (1<<T4CNTL0)       

T4CNTL1       EQU 1       ; Timer4 counter Low Byte bit 1
BM_T4CNTL1    EQU (1<<T4CNTL1)       

T4CNTL2       EQU 2       ; Timer4 counter Low Byte bit 2
BM_T4CNTL2    EQU (1<<T4CNTL2)       

T4CNTL3       EQU 3       ; Timer4 counter Low Byte bit 3
BM_T4CNTL3    EQU (1<<T4CNTL3)       

T4CNTL4       EQU 4       ; Timer4 counter Low Byte bit 4
BM_T4CNTL4    EQU (1<<T4CNTL4)       

T4CNTL5       EQU 5       ; Timer4 counter Low Byte bit 5
BM_T4CNTL5    EQU (1<<T4CNTL5)       

T4CNTL6       EQU 6       ; Timer4 counter Low Byte bit 6
BM_T4CNTL6    EQU (1<<T4CNTL6)       

T4CNTL7       EQU 7       ; Timer4 counter Low Byte bit 7
BM_T4CNTL7    EQU (1<<T4CNTL7)       

; T4CORH - Timer4 compare high Byte Register
T4CORH0       EQU 0       ; Timer4 compare high Byte bit 0
BM_T4CORH0    EQU (1<<T4CORH0)       

T4CORH1       EQU 1       ; Timer4 compare high Byte bit 1
BM_T4CORH1    EQU (1<<T4CORH1)       

T4CORH2       EQU 2       ; Timer4 compare high Byte bit 2
BM_T4CORH2    EQU (1<<T4CORH2)       

T4CORH3       EQU 3       ; Timer4 compare high Byte bit 3
BM_T4CORH3    EQU (1<<T4CORH3)       

T4CORH4       EQU 4       ; Timer4 compare high Byte bit 4
BM_T4CORH4    EQU (1<<T4CORH4)       

T4CORH5       EQU 5       ; Timer4 compare high Byte bit 5
BM_T4CORH5    EQU (1<<T4CORH5)       

T4CORH6       EQU 6       ; Timer4 compare high Byte bit 6
BM_T4CORH6    EQU (1<<T4CORH6)       

T4CORH7       EQU 7       ; Timer4 compare high Byte bit 7
BM_T4CORH7    EQU (1<<T4CORH7)       

; T4CORL - Timer4 compare Low Byte Register
T4CORL0       EQU 0       ; Timer4 compare Low Byte bit 0
BM_T4CORL0    EQU (1<<T4CORL0)       

T4CORL1       EQU 1       ; Timer4 compare Low Byte bit 1
BM_T4CORL1    EQU (1<<T4CORL1)       

T4CORL2       EQU 2       ; Timer4 compare Low Byte bit 2
BM_T4CORL2    EQU (1<<T4CORL2)       

T4CORL3       EQU 3       ; Timer4 compare Low Byte bit 3
BM_T4CORL3    EQU (1<<T4CORL3)       

T4CORL4       EQU 4       ; Timer4 compare Low Byte bit 4
BM_T4CORL4    EQU (1<<T4CORL4)       

T4CORL5       EQU 5       ; Timer4 compare Low Byte bit 5
BM_T4CORL5    EQU (1<<T4CORL5)       

T4CORL6       EQU 6       ; Timer4 compare Low Byte bit 6
BM_T4CORL6    EQU (1<<T4CORL6)       

T4CORL7       EQU 7       ; Timer4 compare Low Byte bit
BM_T4CORL7    EQU (1<<T4CORL7)       

; T4CR - Timer4 control Register
T4OTM       EQU 0       ; Timer4 Overflow Toggle Mask
BM_T4OTM    EQU (1<<T4OTM)       

T4CTM       EQU 1       ; Timer4 Compare Toggle Mask
BM_T4CTM    EQU (1<<T4CTM)       

T4CRM       EQU 2       ; Timer4 Compare Reset Mask
BM_T4CRM    EQU (1<<T4CRM)       

T4CPRM       EQU 3       ; Timer4 CaPture reset Mask
BM_T4CPRM    EQU (1<<T4CPRM)       

T4TOP       EQU 4       ; Timer4 Toggle Output Preset
BM_T4TOP    EQU (1<<T4TOP)       

T4RES       EQU 5       ; Timer4 Reset
BM_T4RES    EQU (1<<T4RES)       

T4TOS       EQU 6       ; Timer4 Toggle with Start
BM_T4TOS    EQU (1<<T4TOS)       

T4ENA       EQU 7       ; Timer4 Enable
BM_T4ENA    EQU (1<<T4ENA)       

; T4ICRH - Timer4 input capture High Byte Register
T4ICRH0       EQU 0       ; Timer4 input capture High Byte bit 0
BM_T4ICRH0    EQU (1<<T4ICRH0)       

T4ICRH1       EQU 1       ; Timer4 input capture High Byte bit 1
BM_T4ICRH1    EQU (1<<T4ICRH1)       

T4ICRH2       EQU 2       ; Timer4 input capture High Byte bit 2
BM_T4ICRH2    EQU (1<<T4ICRH2)       

T4ICRH3       EQU 3       ; Timer4 input capture High Byte bit 3
BM_T4ICRH3    EQU (1<<T4ICRH3)       

T4ICRH4       EQU 4       ; Timer4 input capture High Byte bit 4
BM_T4ICRH4    EQU (1<<T4ICRH4)       

T4ICRH5       EQU 5       ; Timer4 input capture High Byte bit 5
BM_T4ICRH5    EQU (1<<T4ICRH5)       

T4ICRH6       EQU 6       ; Timer4 input capture High Byte bit 6
BM_T4ICRH6    EQU (1<<T4ICRH6)       

T4ICRH7       EQU 7       ; Timer4 input capture High Byte bit 7
BM_T4ICRH7    EQU (1<<T4ICRH7)       

; T4ICRL - Timer4 input capture Low Byte Register
T4ICRL0       EQU 0       ; Timer4 input capture Low Byte bit 0
BM_T4ICRL0    EQU (1<<T4ICRL0)       

T4ICRL1       EQU 1       ; Timer4 input capture Low Byte bit 1
BM_T4ICRL1    EQU (1<<T4ICRL1)       

T4ICRL2       EQU 2       ; Timer4 input capture Low Byte bit 2
BM_T4ICRL2    EQU (1<<T4ICRL2)       

T4ICRL3       EQU 3       ; Timer4 input capture Low Byte bit 3
BM_T4ICRL3    EQU (1<<T4ICRL3)       

T4ICRL4       EQU 4       ; Timer4 input capture Low Byte bit 4
BM_T4ICRL4    EQU (1<<T4ICRL4)       

T4ICRL5       EQU 5       ; Timer4 input capture Low Byte bit 5
BM_T4ICRL5    EQU (1<<T4ICRL5)       

T4ICRL6       EQU 6       ; Timer4 input capture Low Byte bit 6
BM_T4ICRL6    EQU (1<<T4ICRL6)       

T4ICRL7       EQU 7       ; Timer4 input capture Low Byte bit 7
BM_T4ICRL7    EQU (1<<T4ICRL7)       

; T4IFR - Timer4 interrupt flag Register
T4OFF       EQU 0       ; Timer4 OverFlow Flag
BM_T4OFF    EQU (1<<T4OFF)       

T4COF       EQU 1       ; Timer4 Compare Flag
BM_T4COF    EQU (1<<T4COF)       

T4ICF       EQU 2       ; Timer4 Input Capture Flag
BM_T4ICF    EQU (1<<T4ICF)       

; T4IMR - Timer4 interrupt mask Register
T4OIM       EQU 0       ; Timer4 Overflow Interrupt Mask
BM_T4OIM    EQU (1<<T4OIM)       

T4CIM       EQU 1       ; Timer4 Compare Interrupt Mask
BM_T4CIM    EQU (1<<T4CIM)       

T4CPIM       EQU 2       ; Timer4 Capture Interrupt Mask
BM_T4CPIM    EQU (1<<T4CPIM)       

; T4MRA - Timer4 mode Register
T4CS0       EQU 0       ; Timer 4 Clock Select bit 0
BM_T4CS0    EQU (1<<T4CS0)       

T4CS1       EQU 1       ; Timer 4 Clock Select bit 1
BM_T4CS1    EQU (1<<T4CS1)       

T4PS0       EQU 2       ; Timer 4 Prescaler Select bit 0
BM_T4PS0    EQU (1<<T4PS0)       

T4PS1       EQU 3       ; Timer 4 Prescaler Select bit 1
BM_T4PS1    EQU (1<<T4PS1)       

T4PS2       EQU 4       ; Timer 4 Prescaler Select bit 2
BM_T4PS2    EQU (1<<T4PS2)       

; T4MRB - Timer4 mode Register
T4SCE       EQU 1       ; Timer4 Software Capture Enable
BM_T4SCE    EQU (1<<T4SCE)       

T4CNC       EQU 2       ; Timer4 input Capture Noise Canceller
BM_T4CNC    EQU (1<<T4CNC)       

T4CE0       EQU 3       ; Timer4 Capture Edge select bit 0
BM_T4CE0    EQU (1<<T4CE0)       

T4CE1       EQU 4       ; Timer4 Capture Edge select bit 1
BM_T4CE1    EQU (1<<T4CE1)       

T4ICS0       EQU 5       ; Timer4 Input Capture Select bit 0
BM_T4ICS0    EQU (1<<T4ICS0)       

T4ICS1       EQU 6       ; Timer4 Input Capture Select bit 1
BM_T4ICS1    EQU (1<<T4ICS1)       

T4ICS2       EQU 7       ; Timer4 Input Capture Select bit 2
BM_T4ICS2    EQU (1<<T4ICS2)       

; ***** TIMER5 ***********************
; GTCCR - General Timer/Counter Control Register
PSR10       EQU 0       ; PreScaler Reset
BM_PSR10    EQU (1<<PSR10)       

TSM       EQU 7       ; Timer/Counter Synchronization Mode
BM_TSM    EQU (1<<TSM)       

; T5CCR - Timer5 Control Register
T5CS0       EQU 0       ; Timer5 Clock Select bit 0
BM_T5CS0    EQU (1<<T5CS0)       

T5CS1       EQU 1       ; Timer5 Clock Select bit 1
BM_T5CS1    EQU (1<<T5CS1)       

T5CS2       EQU 2       ; Timer5 Clock Select bit 2
BM_T5CS2    EQU (1<<T5CS2)       

T5CTC       EQU 3       ; Clear Timer5 on Compare Match
BM_T5CTC    EQU (1<<T5CTC)       

; T5CNTH - Timer5 Counter High byte
T5CNTH0       EQU 0       ; Timer5 Counter High byte bit 0
BM_T5CNTH0    EQU (1<<T5CNTH0)       

T5CNTH1       EQU 1       ; Timer5 Counter High byte bit 1
BM_T5CNTH1    EQU (1<<T5CNTH1)       

T5CNTH2       EQU 2       ; Timer5 Counter High byte bit 2
BM_T5CNTH2    EQU (1<<T5CNTH2)       

T5CNTH3       EQU 3       ; Timer5 Counter High byte bit 3
BM_T5CNTH3    EQU (1<<T5CNTH3)       

T5CNTH4       EQU 4       ; Timer5 Counter High byte bit 4
BM_T5CNTH4    EQU (1<<T5CNTH4)       

T5CNTH5       EQU 5       ; Timer5 Counter High byte bit 5
BM_T5CNTH5    EQU (1<<T5CNTH5)       

T5CNTH6       EQU 6       ; Timer5 Counter High byte bit 6
BM_T5CNTH6    EQU (1<<T5CNTH6)       

T5CNTH7       EQU 7       ; Timer5 Counter High byte bit 7
BM_T5CNTH7    EQU (1<<T5CNTH7)       

; T5CNTL - Timer5 Counter Low byte
T5CNTL0       EQU 0       ; Timer5 Counter Low byte bit 0
BM_T5CNTL0    EQU (1<<T5CNTL0)       

T5CNTL1       EQU 1       ; Timer5 Counter Low byte bit 1
BM_T5CNTL1    EQU (1<<T5CNTL1)       

T5CNTL2       EQU 2       ; Timer5 Counter Low byte bit 2
BM_T5CNTL2    EQU (1<<T5CNTL2)       

T5CNTL3       EQU 3       ; Timer5 Counter Low byte bit 3
BM_T5CNTL3    EQU (1<<T5CNTL3)       

T5CNTL4       EQU 4       ; Timer5 Counter Low byte bit 4
BM_T5CNTL4    EQU (1<<T5CNTL4)       

T5CNTL5       EQU 5       ; Timer5 Counter Low byte bit 5
BM_T5CNTL5    EQU (1<<T5CNTL5)       

T5CNTL6       EQU 6       ; Timer5 Counter Low byte bit 6
BM_T5CNTL6    EQU (1<<T5CNTL6)       

T5CNTL7       EQU 7       ; Timer5 Counter Low byte bit 7
BM_T5CNTL7    EQU (1<<T5CNTL7)       

; T5IFR - Timer5 Interrupt Flag Register
T5OFF       EQU 0       ; Timer5 Output Overflow Flag
BM_T5OFF    EQU (1<<T5OFF)       

T5COF       EQU 1       ; Timer5 Output Compare Output Match Flag
BM_T5COF    EQU (1<<T5COF)       

; T5IMR - Timer5 Interrupt Mask Register
T5OIM       EQU 0       ; Timer5 Output Overflow Interrupt Mask
BM_T5OIM    EQU (1<<T5OIM)       

T5CIM       EQU 1       ; Timer5 Output Compare Interrupt Mask
BM_T5CIM    EQU (1<<T5CIM)       

; T5OCRH - Timer5 Output Compare Register High byte
T5OCRH0       EQU 0       ; Timer5 Output Compare Register High byte bit 0
BM_T5OCRH0    EQU (1<<T5OCRH0)       

T5OCRH1       EQU 1       ; Timer5 Output Compare Register High byte bit 1
BM_T5OCRH1    EQU (1<<T5OCRH1)       

T5OCRH2       EQU 2       ; Timer5 Output Compare Register High byte bit 2
BM_T5OCRH2    EQU (1<<T5OCRH2)       

T5OCRH3       EQU 3       ; Timer5 Output Compare Register High byte bit 3
BM_T5OCRH3    EQU (1<<T5OCRH3)       

T5OCRH4       EQU 4       ; Timer5 Output Compare Register High byte bit 4
BM_T5OCRH4    EQU (1<<T5OCRH4)       

T5OCRH5       EQU 5       ; Timer5 Output Compare Register High byte bit 5
BM_T5OCRH5    EQU (1<<T5OCRH5)       

T5OCRH6       EQU 6       ; Timer5 Output Compare Register High byte bit 6
BM_T5OCRH6    EQU (1<<T5OCRH6)       

T5OCRH7       EQU 7       ; Timer5 Output Compare Register High byte bit 7
BM_T5OCRH7    EQU (1<<T5OCRH7)       

; T5OCRL - Timer5 Output Compare Register Low byte
T5OCRL0       EQU 0       ; Timer5 Output Compare Register Low byte bit 0
BM_T5OCRL0    EQU (1<<T5OCRL0)       

T5OCRL1       EQU 1       ; Timer5 Output Compare Register Low byte bit 1
BM_T5OCRL1    EQU (1<<T5OCRL1)       

T5OCRL2       EQU 2       ; Timer5 Output Compare Register Low byte bit 2
BM_T5OCRL2    EQU (1<<T5OCRL2)       

T5OCRL3       EQU 3       ; Timer5 Output Compare Register Low byte bit 3
BM_T5OCRL3    EQU (1<<T5OCRL3)       

T5OCRL4       EQU 4       ; Timer5 Output Compare Register Low byte bit 4
BM_T5OCRL4    EQU (1<<T5OCRL4)       

T5OCRL5       EQU 5       ; Timer5 Output Compare Register Low byte bit 5
BM_T5OCRL5    EQU (1<<T5OCRL5)       

T5OCRL6       EQU 6       ; Timer5 Output Compare Register Low byte bit 6
BM_T5OCRL6    EQU (1<<T5OCRL6)       

T5OCRL7       EQU 7       ; Timer5 Output Compare Register Low byte bit 7
BM_T5OCRL7    EQU (1<<T5OCRL7)       

; ***** TXDSP ************************
; FFREQ1H - Fractional Frequency 1 Setting, High Byte
FFREQ1H0       EQU 0       ; Fractional Frequency 1 High Byte bit 0
BM_FFREQ1H0    EQU (1<<FFREQ1H0)       

FFREQ1H1       EQU 1       ; Fractional Frequency 1 High Byte bit 1
BM_FFREQ1H1    EQU (1<<FFREQ1H1)       

; FFREQ1L - Fractional Frequency 1 Setting, Low Byte
FFREQ1L0       EQU 0       ; Fractional Frequency 1 Low Byte bit 0
BM_FFREQ1L0    EQU (1<<FFREQ1L0)       

FFREQ1L1       EQU 1       ; Fractional Frequency 1 Low Byte bit 1
BM_FFREQ1L1    EQU (1<<FFREQ1L1)       

FFREQ1L2       EQU 2       ; Fractional Frequency 1 Low Byte bit 2
BM_FFREQ1L2    EQU (1<<FFREQ1L2)       

FFREQ1L3       EQU 3       ; Fractional Frequency 1 Low Byte bit 3
BM_FFREQ1L3    EQU (1<<FFREQ1L3)       

FFREQ1L4       EQU 4       ; Fractional Frequency 1 Low Byte bit 4
BM_FFREQ1L4    EQU (1<<FFREQ1L4)       

FFREQ1L5       EQU 5       ; Fractional Frequency 1 Low Byte bit 5
BM_FFREQ1L5    EQU (1<<FFREQ1L5)       

FFREQ1L6       EQU 6       ; Fractional Frequency 1 Low Byte bit 6
BM_FFREQ1L6    EQU (1<<FFREQ1L6)       

FFREQ1L7       EQU 7       ; Fractional Frequency 1 Low Byte bit 7
BM_FFREQ1L7    EQU (1<<FFREQ1L7)       

; FFREQ1M - Fractional Frequency 1 Setting, Middle Byte
FFREQ1M0       EQU 0       ; Fractional Frequency 1 Middle Byte bit 0
BM_FFREQ1M0    EQU (1<<FFREQ1M0)       

FFREQ1M1       EQU 1       ; Fractional Frequency 1 Middle Byte bit 1
BM_FFREQ1M1    EQU (1<<FFREQ1M1)       

FFREQ1M2       EQU 2       ; Fractional Frequency 1 Middle Byte bit 2
BM_FFREQ1M2    EQU (1<<FFREQ1M2)       

FFREQ1M3       EQU 3       ; Fractional Frequency 1 Middle Byte bit 3
BM_FFREQ1M3    EQU (1<<FFREQ1M3)       

FFREQ1M4       EQU 4       ; Fractional Frequency 1 Middle Byte bit 4
BM_FFREQ1M4    EQU (1<<FFREQ1M4)       

FFREQ1M5       EQU 5       ; Fractional Frequency 1 Middle Byte bit 5
BM_FFREQ1M5    EQU (1<<FFREQ1M5)       

FFREQ1M6       EQU 6       ; Fractional Frequency 1 Middle Byte bit 6
BM_FFREQ1M6    EQU (1<<FFREQ1M6)       

FFREQ1M7       EQU 7       ; Fractional Frequency 1 Middle Byte bit 7
BM_FFREQ1M7    EQU (1<<FFREQ1M7)       

; FFREQ2H - Fractional Frequency 2 Setting, High Byte
FFREQ2H0       EQU 0       ; Fractional Frequency 2 High Byte bit 0
BM_FFREQ2H0    EQU (1<<FFREQ2H0)       

FFREQ2H1       EQU 1       ; Fractional Frequency 2 High Byte bit 1
BM_FFREQ2H1    EQU (1<<FFREQ2H1)       

; FFREQ2L - Fractional Frequency 2 Setting, Low Byte
FFREQ2L0       EQU 0       ; Fractional Frequency 2 Low Byte bit 0
BM_FFREQ2L0    EQU (1<<FFREQ2L0)       

FFREQ2L1       EQU 1       ; Fractional Frequency 2 Low Byte bit 1
BM_FFREQ2L1    EQU (1<<FFREQ2L1)       

FFREQ2L2       EQU 2       ; Fractional Frequency 2 Low Byte bit 2
BM_FFREQ2L2    EQU (1<<FFREQ2L2)       

FFREQ2L3       EQU 3       ; Fractional Frequency 2 Low Byte bit 3
BM_FFREQ2L3    EQU (1<<FFREQ2L3)       

FFREQ2L4       EQU 4       ; Fractional Frequency 2 Low Byte bit 4
BM_FFREQ2L4    EQU (1<<FFREQ2L4)       

FFREQ2L5       EQU 5       ; Fractional Frequency 2 Low Byte bit 5
BM_FFREQ2L5    EQU (1<<FFREQ2L5)       

FFREQ2L6       EQU 6       ; Fractional Frequency 2 Low Byte bit 6
BM_FFREQ2L6    EQU (1<<FFREQ2L6)       

FFREQ2L7       EQU 7       ; Fractional Frequency 2 Low Byte bit 7
BM_FFREQ2L7    EQU (1<<FFREQ2L7)       

; FFREQ2M - Fractional Frequency 2 Setting, Middle Byte
FFREQ2M0       EQU 0       ; Fractional Frequency 2 Middle Byte bit 0
BM_FFREQ2M0    EQU (1<<FFREQ2M0)       

FFREQ2M1       EQU 1       ; Fractional Frequency 2 Middle Byte bit 1
BM_FFREQ2M1    EQU (1<<FFREQ2M1)       

FFREQ2M2       EQU 2       ; Fractional Frequency 2 Middle Byte bit 2
BM_FFREQ2M2    EQU (1<<FFREQ2M2)       

FFREQ2M3       EQU 3       ; Fractional Frequency 2 Middle Byte bit 3
BM_FFREQ2M3    EQU (1<<FFREQ2M3)       

FFREQ2M4       EQU 4       ; Fractional Frequency 2 Middle Byte bit 4
BM_FFREQ2M4    EQU (1<<FFREQ2M4)       

FFREQ2M5       EQU 5       ; Fractional Frequency 2 Middle Byte bit 5
BM_FFREQ2M5    EQU (1<<FFREQ2M5)       

FFREQ2M6       EQU 6       ; Fractional Frequency 2 Middle Byte bit 6
BM_FFREQ2M6    EQU (1<<FFREQ2M6)       

FFREQ2M7       EQU 7       ; Fractional Frequency 2 Middle Byte bit 7
BM_FFREQ2M7    EQU (1<<FFREQ2M7)       

; FSCR - Frequency Synthesizer Control Register
TXMOD       EQU 0       ; Tx Modulation
BM_TXMOD    EQU (1<<TXMOD)       

SFM       EQU 1       ; Select FSK Modulation
BM_SFM    EQU (1<<SFM)       

TXMS0       EQU 2       ; Tx Modulation Source bit 0
BM_TXMS0    EQU (1<<TXMS0)       

TXMS1       EQU 3       ; Tx Modulation Source bit 1
BM_TXMS1    EQU (1<<TXMS1)       

PAOER       EQU 4       ; Power Amplifier Output Enable Register
BM_PAOER    EQU (1<<PAOER)       

PAON       EQU 7       ; Power Amplifier Output is On
BM_PAON    EQU (1<<PAON)       

; FSEN - Frequency Synthesizer Enable register
SDPU       EQU 0       ; Sigma-delta Modulator Power Up
BM_SDPU    EQU (1<<SDPU)       

SDEN       EQU 1       ; Sigma-delta Modulator Enable
BM_SDEN    EQU (1<<SDEN)       

GAEN       EQU 2       ; Gauss Filtering Enable
BM_GAEN    EQU (1<<GAEN)       

PEEN       EQU 3       ; Pre-emphasis Filtering Enable
BM_PEEN    EQU (1<<PEEN)       

ASEN       EQU 4       ; ASK Shaping Enable
BM_ASEN    EQU (1<<ASEN)       

ANTT       EQU 5       ; Antenna Tuning Active
BM_ANTT    EQU (1<<ANTT)       

; FSFCR - Frequency Synthesizer Filter Control Register
BTSEL0       EQU 0       ; Gauss Filter BT Selection bit 0
BM_BTSEL0    EQU (1<<BTSEL0)       

BTSEL1       EQU 1       ; Gauss Filter BT Selection bit 1
BM_BTSEL1    EQU (1<<BTSEL1)       

ASDIV0       EQU 4       ; ASK Shaping Divider bit 0
BM_ASDIV0    EQU (1<<ASDIV0)       

ASDIV1       EQU 5       ; ASK Shaping Divider bit 1
BM_ASDIV1    EQU (1<<ASDIV1)       

ASDIV2       EQU 6       ; ASK Shaping Divider bit 2
BM_ASDIV2    EQU (1<<ASDIV2)       

ASDIV3       EQU 7       ; ASK Shaping Divider bit 3
BM_ASDIV3    EQU (1<<ASDIV3)       

; GACDIVH - Gauss Clock Divider, High Byte
GACDIVH0       EQU 0       ; Gauss Clock Divider High Byte bit 0
BM_GACDIVH0    EQU (1<<GACDIVH0)       

GACDIVH1       EQU 1       ; Gauss Clock Divider High Byte bit 1
BM_GACDIVH1    EQU (1<<GACDIVH1)       

GACDIVH2       EQU 2       ; Gauss Clock Divider High Byte bit 2
BM_GACDIVH2    EQU (1<<GACDIVH2)       

GACDIVH3       EQU 3       ; Gauss Clock Divider High Byte bit 3
BM_GACDIVH3    EQU (1<<GACDIVH3)       

GACDIVH4       EQU 4       ; Gauss Clock Divider High Byte bit 4
BM_GACDIVH4    EQU (1<<GACDIVH4)       

; GACDIVL - Gauss Clock Divider, Low Byte
GACDIVL0       EQU 0       ; Gauss Clock Divider Low Byte bit 0
BM_GACDIVL0    EQU (1<<GACDIVL0)       

GACDIVL1       EQU 1       ; Gauss Clock Divider Low Byte bit 1
BM_GACDIVL1    EQU (1<<GACDIVL1)       

GACDIVL2       EQU 2       ; Gauss Clock Divider Low Byte bit 2
BM_GACDIVL2    EQU (1<<GACDIVL2)       

GACDIVL3       EQU 3       ; Gauss Clock Divider Low Byte bit 3
BM_GACDIVL3    EQU (1<<GACDIVL3)       

GACDIVL4       EQU 4       ; Gauss Clock Divider Low Byte bit 4
BM_GACDIVL4    EQU (1<<GACDIVL4)       

GACDIVL5       EQU 5       ; Gauss Clock Divider Low Byte bit 5
BM_GACDIVL5    EQU (1<<GACDIVL5)       

GACDIVL6       EQU 6       ; Gauss Clock Divider Low Byte bit 6
BM_GACDIVL6    EQU (1<<GACDIVL6)       

GACDIVL7       EQU 7       ; Gauss Clock Divider Low Byte bit 7
BM_GACDIVL7    EQU (1<<GACDIVL7)       

; ***** TXM **************************
; TMCIH - Tx Modulator CRC Init Value, High Byte
TMCIH0       EQU 0       ; Tx Modulator CRC Init Value High Byte bit 0
BM_TMCIH0    EQU (1<<TMCIH0)       

TMCIH1       EQU 1       ; Tx Modulator CRC Init Value High Byte bit 1
BM_TMCIH1    EQU (1<<TMCIH1)       

TMCIH2       EQU 2       ; Tx Modulator CRC Init Value High Byte bit 2
BM_TMCIH2    EQU (1<<TMCIH2)       

TMCIH3       EQU 3       ; Tx Modulator CRC Init Value High Byte bit 3
BM_TMCIH3    EQU (1<<TMCIH3)       

TMCIH4       EQU 4       ; Tx Modulator CRC Init Value High Byte bit 4
BM_TMCIH4    EQU (1<<TMCIH4)       

TMCIH5       EQU 5       ; Tx Modulator CRC Init Value High Byte bit 5
BM_TMCIH5    EQU (1<<TMCIH5)       

TMCIH6       EQU 6       ; Tx Modulator CRC Init Value High Byte bit 6
BM_TMCIH6    EQU (1<<TMCIH6)       

TMCIH7       EQU 7       ; Tx Modulator CRC Init Value High Byte bit 7
BM_TMCIH7    EQU (1<<TMCIH7)       

; TMCIL - Tx Modulator CRC Init Value Low Byte
TMCIL0       EQU 0       ; Tx Modulator CRC Init Value Low Byte bit 0
BM_TMCIL0    EQU (1<<TMCIL0)       

TMCIL1       EQU 1       ; Tx Modulator CRC Init Value Low Byte bit 1
BM_TMCIL1    EQU (1<<TMCIL1)       

TMCIL2       EQU 2       ; Tx Modulator CRC Init Value Low Byte bit 2
BM_TMCIL2    EQU (1<<TMCIL2)       

TMCIL3       EQU 3       ; Tx Modulator CRC Init Value Low Byte bit 3
BM_TMCIL3    EQU (1<<TMCIL3)       

TMCIL4       EQU 4       ; Tx Modulator CRC Init Value Low Byte bit 4
BM_TMCIL4    EQU (1<<TMCIL4)       

TMCIL5       EQU 5       ; Tx Modulator CRC Init Value Low Byte bit 5
BM_TMCIL5    EQU (1<<TMCIL5)       

TMCIL6       EQU 6       ; Tx Modulator CRC Init Value Low Byte bit 6
BM_TMCIL6    EQU (1<<TMCIL6)       

TMCIL7       EQU 7       ; Tx Modulator CRC Init Value Low Byte bit 7
BM_TMCIL7    EQU (1<<TMCIL7)       

; TMCPH - Tx Modulator CRC Polynomial, High Byte
TMCPH0       EQU 0       ; Tx Modulator CRC Polynomial High Byte bit 0
BM_TMCPH0    EQU (1<<TMCPH0)       

TMCPH1       EQU 1       ; Tx Modulator CRC Polynomial High Byte bit 1
BM_TMCPH1    EQU (1<<TMCPH1)       

TMCPH2       EQU 2       ; Tx Modulator CRC Polynomial High Byte bit 2
BM_TMCPH2    EQU (1<<TMCPH2)       

TMCPH3       EQU 3       ; Tx Modulator CRC Polynomial High Byte bit 3
BM_TMCPH3    EQU (1<<TMCPH3)       

TMCPH4       EQU 4       ; Tx Modulator CRC Polynomial High Byte bit 4
BM_TMCPH4    EQU (1<<TMCPH4)       

TMCPH5       EQU 5       ; Tx Modulator CRC Polynomial High Byte bit 5
BM_TMCPH5    EQU (1<<TMCPH5)       

TMCPH6       EQU 6       ; Tx Modulator CRC Polynomial High Byte bit 6
BM_TMCPH6    EQU (1<<TMCPH6)       

TMCPH7       EQU 7       ; Tx Modulator CRC Polynomial High Byte bit 7
BM_TMCPH7    EQU (1<<TMCPH7)       

; TMCPL - Tx Modulator CRC Polynomial, Low Byte
TMCPL0       EQU 0       ; Tx Modulator CRC Polynomial Low Byte bit 0
BM_TMCPL0    EQU (1<<TMCPL0)       

TMCPL1       EQU 1       ; Tx Modulator CRC Polynomial Low Byte bit 1
BM_TMCPL1    EQU (1<<TMCPL1)       

TMCPL2       EQU 2       ; Tx Modulator CRC Polynomial Low Byte bit 2
BM_TMCPL2    EQU (1<<TMCPL2)       

TMCPL3       EQU 3       ; Tx Modulator CRC Polynomial Low Byte bit 3
BM_TMCPL3    EQU (1<<TMCPL3)       

TMCPL4       EQU 4       ; Tx Modulator CRC Polynomial Low Byte bit 4
BM_TMCPL4    EQU (1<<TMCPL4)       

TMCPL5       EQU 5       ; Tx Modulator CRC Polynomial Low Byte bit 5
BM_TMCPL5    EQU (1<<TMCPL5)       

TMCPL6       EQU 6       ; Tx Modulator CRC Polynomial Low Byte bit 6
BM_TMCPL6    EQU (1<<TMCPL6)       

TMCPL7       EQU 7       ; Tx Modulator CRC Polynomial Low Byte bit 7
BM_TMCPL7    EQU (1<<TMCPL7)       

; TMCR1 - Tx Modulator Control Register 1
TMPIS0       EQU 0       ; Tx Modulator Port Interface Select bit 0
BM_TMPIS0    EQU (1<<TMPIS0)       

TMPIS1       EQU 1       ; Tx Modulator Port Interface Select bit 1
BM_TMPIS1    EQU (1<<TMPIS1)       

TMPIS2       EQU 2       ; Tx Modulator Port Interface Select bit 2
BM_TMPIS2    EQU (1<<TMPIS2)       

TMSCS       EQU 3       ; Tx Modulator Serial Output Clock Select
BM_TMSCS    EQU (1<<TMSCS)       

TMCIM       EQU 4       ; Tx Modulator Transmission Complete Interrupt Mask
BM_TMCIM    EQU (1<<TMCIM)       

; TMCR2 - Tx Modulator Control Register 2
TMCRCE       EQU 0       ; Tx Modulator CRC Enable
BM_TMCRCE    EQU (1<<TMCRCE)       

TMCRCL0       EQU 1       ; Tx Modulator CRC Length bit 0
BM_TMCRCL0    EQU (1<<TMCRCL0)       

TMCRCL1       EQU 2       ; Tx Modulator CRC Length bit 1
BM_TMCRCL1    EQU (1<<TMCRCL1)       

TMNRZE       EQU 3       ; Tx Modulator NRZ Mode Enable
BM_TMNRZE    EQU (1<<TMNRZE)       

TMPOL       EQU 4       ; Tx Modulator Polarity
BM_TMPOL    EQU (1<<TMPOL)       

TMSSE       EQU 5       ; Tx Modulator Stop Sequence Enable
BM_TMSSE    EQU (1<<TMSSE)       

TMMSB       EQU 6       ; Tx Modulator Most Significant Bit First
BM_TMMSB    EQU (1<<TMMSB)       

; TMCRH - Tx Modulator CRC Result, High Byte
TMCRH0       EQU 0       ; Tx Modulator CRC Result High Byte bit 0
BM_TMCRH0    EQU (1<<TMCRH0)       

TMCRH1       EQU 1       ; Tx Modulator CRC Result High Byte bit 1
BM_TMCRH1    EQU (1<<TMCRH1)       

TMCRH2       EQU 2       ; Tx Modulator CRC Result High Byte bit 2
BM_TMCRH2    EQU (1<<TMCRH2)       

TMCRH3       EQU 3       ; Tx Modulator CRC Result High Byte bit 3
BM_TMCRH3    EQU (1<<TMCRH3)       

TMCRH4       EQU 4       ; Tx Modulator CRC Result High Byte bit 4
BM_TMCRH4    EQU (1<<TMCRH4)       

TMCRH5       EQU 5       ; Tx Modulator CRC Result High Byte bit 5
BM_TMCRH5    EQU (1<<TMCRH5)       

TMCRH6       EQU 6       ; Tx Modulator CRC Result High Byte bit 6
BM_TMCRH6    EQU (1<<TMCRH6)       

TMCRH7       EQU 7       ; Tx Modulator CRC Result High Byte bit 7
BM_TMCRH7    EQU (1<<TMCRH7)       

; TMCRL - Tx Modulator CRC Result, Low Byte
TMCRL0       EQU 0       ; Tx Modulator CRC Result Low Byte bit 0
BM_TMCRL0    EQU (1<<TMCRL0)       

TMCRL1       EQU 1       ; Tx Modulator CRC Result Low Byte bit 1
BM_TMCRL1    EQU (1<<TMCRL1)       

TMCRL2       EQU 2       ; Tx Modulator CRC Result Low Byte bit 2
BM_TMCRL2    EQU (1<<TMCRL2)       

TMCRL3       EQU 3       ; Tx Modulator CRC Result Low Byte bit 3
BM_TMCRL3    EQU (1<<TMCRL3)       

TMCRL4       EQU 4       ; Tx Modulator CRC Result Low Byte bit 4
BM_TMCRL4    EQU (1<<TMCRL4)       

TMCRL5       EQU 5       ; Tx Modulator CRC Result Low Byte bit 5
BM_TMCRL5    EQU (1<<TMCRL5)       

TMCRL6       EQU 6       ; Tx Modulator CRC Result Low Byte bit 6
BM_TMCRL6    EQU (1<<TMCRL6)       

TMCRL7       EQU 7       ; Tx Modulator CRC Result Low Byte bit 7
BM_TMCRL7    EQU (1<<TMCRL7)       

; TMCSB - Tx Modulator CRC Skip Bit Number
TMCSB0       EQU 0       ; Tx Modulator CRC Skip Bit Number bit 0
BM_TMCSB0    EQU (1<<TMCSB0)       

TMCSB1       EQU 1       ; Tx Modulator CRC Skip Bit Number bit 1
BM_TMCSB1    EQU (1<<TMCSB1)       

TMCSB2       EQU 2       ; Tx Modulator CRC Skip Bit Number bit 2
BM_TMCSB2    EQU (1<<TMCSB2)       

TMCSB3       EQU 3       ; Tx Modulator CRC Skip Bit Number bit 3
BM_TMCSB3    EQU (1<<TMCSB3)       

TMCSB4       EQU 4       ; Tx Modulator CRC Skip Bit Number bit 4
BM_TMCSB4    EQU (1<<TMCSB4)       

TMCSB5       EQU 5       ; Tx Modulator CRC Skip Bit Number bit 5
BM_TMCSB5    EQU (1<<TMCSB5)       

TMCSB6       EQU 6       ; Tx Modulator CRC Skip Bit Number bit 6
BM_TMCSB6    EQU (1<<TMCSB6)       

TMCSB7       EQU 7       ; Tx Modulator CRC Skip Bit Number bit 7
BM_TMCSB7    EQU (1<<TMCSB7)       

; TMFSM - Tx Modulator Finite State Machine
TMSSM0       EQU 0       ; Tx Modulator Sub State Machine bit 0
BM_TMSSM0    EQU (1<<TMSSM0)       

TMSSM1       EQU 1       ; Tx Modulator Sub State Machine bit 1
BM_TMSSM1    EQU (1<<TMSSM1)       

TMSSM2       EQU 2       ; Tx Modulator Sub State Machine bit 2
BM_TMSSM2    EQU (1<<TMSSM2)       

TMSSM3       EQU 3       ; Tx Modulator Sub State Machine bit 3
BM_TMSSM3    EQU (1<<TMSSM3)       

TMMSM0       EQU 4       ; Tx Modulator Master State Machine bit 0
BM_TMMSM0    EQU (1<<TMMSM0)       

TMMSM1       EQU 5       ; Tx Modulator Master State Machine bit 1
BM_TMMSM1    EQU (1<<TMMSM1)       

TMMSM2       EQU 6       ; Tx Modulator Master State Machine bit 2
BM_TMMSM2    EQU (1<<TMMSM2)       

; TMSHR - Tx Modulator Shift Register
TMSHR0       EQU 0       ; Tx Modulator Shift Register bit 0
BM_TMSHR0    EQU (1<<TMSHR0)       

TMSHR1       EQU 1       ; Tx Modulator Shift Register bit 1
BM_TMSHR1    EQU (1<<TMSHR1)       

TMSHR2       EQU 2       ; Tx Modulator Shift Register bit 2
BM_TMSHR2    EQU (1<<TMSHR2)       

TMSHR3       EQU 3       ; Tx Modulator Shift Register bit 3
BM_TMSHR3    EQU (1<<TMSHR3)       

TMSHR4       EQU 4       ; Tx Modulator Shift Register bit 4
BM_TMSHR4    EQU (1<<TMSHR4)       

TMSHR5       EQU 5       ; Tx Modulator Shift Register bit 5
BM_TMSHR5    EQU (1<<TMSHR5)       

TMSHR6       EQU 6       ; Tx Modulator Shift Register bit 6
BM_TMSHR6    EQU (1<<TMSHR6)       

TMSHR7       EQU 7       ; Tx Modulator Shift Register bit 7
BM_TMSHR7    EQU (1<<TMSHR7)       

; TMSR - Tx Modulator Status Register
TMTCF       EQU 0       ; Tx Modulator Transmission Complete Status Flag
BM_TMTCF    EQU (1<<TMTCF)       

; TMSSC - Tx Modulator Stop Sequence Configuration
TMSSP0       EQU 0       ; Tx Modulator Stop Sequence Pattern bit 0
BM_TMSSP0    EQU (1<<TMSSP0)       

TMSSP1       EQU 1       ; Tx Modulator Stop Sequence Pattern bit 1
BM_TMSSP1    EQU (1<<TMSSP1)       

TMSSP2       EQU 2       ; Tx Modulator Stop Sequence Pattern bit 2
BM_TMSSP2    EQU (1<<TMSSP2)       

TMSSP3       EQU 3       ; Tx Modulator Stop Sequence Pattern bit 3
BM_TMSSP3    EQU (1<<TMSSP3)       

TMSSL0       EQU 4       ; Tx Modulator Stop Sequence Length bit 0
BM_TMSSL0    EQU (1<<TMSSL0)       

TMSSL1       EQU 5       ; Tx Modulator Stop Sequence Length bit 1
BM_TMSSL1    EQU (1<<TMSSL1)       

TMSSL2       EQU 6       ; Tx Modulator Stop Sequence Length bit 2
BM_TMSSL2    EQU (1<<TMSSL2)       

TMSSH       EQU 7       ; Tx Modulator Stop Sequence Hold Mode
BM_TMSSH    EQU (1<<TMSSH)       

; TMTLH - Tx Modulator Telegram Length Register, High Byte
TMTLH0       EQU 0       ; Tx Modulator Telegram Length High Byte bit 0
BM_TMTLH0    EQU (1<<TMTLH0)       

TMTLH1       EQU 1       ; Tx Modulator Telegram Length High Byte bit 1
BM_TMTLH1    EQU (1<<TMTLH1)       

TMTLH2       EQU 2       ; Tx Modulator Telegram Length High Byte bit 2
BM_TMTLH2    EQU (1<<TMTLH2)       

TMTLH3       EQU 3       ; Tx Modulator Telegram Length High Byte bit 3
BM_TMTLH3    EQU (1<<TMTLH3)       

; TMTLL - Tx Modulator Telegram Length Register, Low Byte
TMTLL0       EQU 0       ; Tx Modulator Telegram Length Low Byte bit 0
BM_TMTLL0    EQU (1<<TMTLL0)       

TMTLL1       EQU 1       ; Tx Modulator Telegram Length Low Byte bit 1
BM_TMTLL1    EQU (1<<TMTLL1)       

TMTLL2       EQU 2       ; Tx Modulator Telegram Length Low Byte bit 2
BM_TMTLL2    EQU (1<<TMTLL2)       

TMTLL3       EQU 3       ; Tx Modulator Telegram Length Low Byte bit 3
BM_TMTLL3    EQU (1<<TMTLL3)       

TMTLL4       EQU 4       ; Tx Modulator Telegram Length Low Byte bit 4
BM_TMTLL4    EQU (1<<TMTLL4)       

TMTLL5       EQU 5       ; Tx Modulator Telegram Length Low Byte bit 5
BM_TMTLL5    EQU (1<<TMTLL5)       

TMTLL6       EQU 6       ; Tx Modulator Telegram Length Low Byte bit 6
BM_TMTLL6    EQU (1<<TMTLL6)       

TMTLL7       EQU 7       ; Tx Modulator Telegram Length Low Byte bit 7
BM_TMTLL7    EQU (1<<TMTLL7)       

; ***** LOCKSBITS ********************************************************
LB1       EQU 0       ; Lock bit
LB2       EQU 1       ; Lock bit
BLB01       EQU 2       ; Boot Lock bit
BLB02       EQU 3       ; Boot Lock bit
BLB11       EQU 4       ; Boot lock bit
BLB12       EQU 5       ; Boot lock bit
; ***** FUSES ************************************************************
; LOW fuse bits
; ***** CPU REGISTER DEFINITIONS *****************************************
;.def       XH       EQU r27
;.def       XL       EQU r26
;.def       YH       EQU r29
;.def       YL       EQU r28
;.def       ZH       EQU r31
;.def       ZL       EQU r30
; ***** DATA MEMORY DECLARATIONS *****************************************
FLASHEND       EQU 0x67ff       ; Note: Word address
IOEND       EQU 0x01ff
SRAM_START       EQU 0x0200
SRAM_SIZE       EQU 1024
RAMEND       EQU 0x05ff
XRAMEND       EQU 0x0000
E2END       EQU 0x047f
EEPROMEND       EQU 0x047f
EEADRBITS       EQU 10
; ***** BOOTLOADER DECLARATIONS ******************************************
NRWW_START_ADDR       EQU 0xc00
NRWW_STOP_ADDR       EQU 0xfff
RWW_START_ADDR       EQU 0x0
RWW_STOP_ADDR       EQU 0xbff
PAGESIZE       EQU 32
FIRSTBOOTSTART       EQU 0x4600
SECONDBOOTSTART       EQU 0x4000
THIRDBOOTSTART       EQU 0x3000
FOURTHBOOTSTART       EQU 0x2800
SMALLBOOTSTART       EQU FIRSTBOOTSTART
LARGEBOOTSTART       EQU FOURTHBOOTSTART
; ***** INTERRUPT VECTORS ************************************************
INT0addr       EQU 0x0002       ; External Interrupt Request 0
INT1addr       EQU 0x0004       ; External Interrupt Request 1
PCI0addr       EQU 0x0006       ; Pin Change Interrupt Request 0
PCI1addr       EQU 0x0008       ; Pin Change Interrupt Request 1
VMONaddr       EQU 0x000a       ; Voltage Monitoring Interrupt
AVCCRaddr       EQU 0x000c       ; AVCC Reset Interrupt
AVCCLaddr       EQU 0x000e       ; AVCC Low Interrupt
T0INTaddr       EQU 0x0010       ; Timer 0 Interval Interrupt
T1COMPaddr       EQU 0x0012       ; Timer/Counter1 Compare Match Interrupt
T1OVFaddr       EQU 0x0014       ; Timer/Counter1 Overflow Interrupt
T2COMPaddr       EQU 0x0016       ; Timer/Counter2 Compare Match Interrupt
T2OVFaddr       EQU 0x0018       ; Timer/Counter2 Overflow Interrupt
T3CAPaddr       EQU 0x001a       ; Timer/Counter3 Capture Event Interrupt
T3COMPaddr       EQU 0x001c       ; Timer/Counter3 Compare Match Interrupt
T3OVFaddr       EQU 0x001e       ; Timer/Counter3 Overflow Interrupt
T4CAPaddr       EQU 0x0020       ; Timer/Counter4 Capture Event Interrupt
T4COMPaddr       EQU 0x0022       ; Timer/Counter4 Compare Match Interrupt
T4OVFaddr       EQU 0x0024       ; Timer/Counter4 Overflow Interrupt
T5COMPaddr       EQU 0x0026       ; Timer/Counter5 Compare Match Interrupt
T5OVFaddr       EQU 0x0028       ; Timer/Counter5 Overflow Interrupt
SPIaddr       EQU 0x002a       ; SPI Serial Transfer Complete Interrupt
SRX_FIFOaddr       EQU 0x002c       ; SPI Rx Buffer Interrupt
STX_FIFOaddr       EQU 0x002e       ; SPI Tx Buffer Interrupt
SSMaddr       EQU 0x0030       ; Sequencer State Machine Interrupt
DFFLRaddr       EQU 0x0032       ; Data FIFO fill level reached Interrupt
DFOUEaddr       EQU 0x0034       ; Data FIFO overflow or underflow error Interrupt
SFFLRaddr       EQU 0x0036       ; RSSI/Preamble FIFO fill level reached Interrupt
SFOUEaddr       EQU 0x0038       ; RSSI/Preamble FIFO overflow or underflow error Interrupt
TMTCFaddr       EQU 0x003a       ; Tx Modulator Telegram Finish Interrupt
UHF_WCOBaddr       EQU 0x003c       ; UHF receiver wake up ok on Rx path B
UHF_WCOAaddr       EQU 0x003e       ; UHF receiver wake up ok on Rx path A
UHF_SOTBaddr       EQU 0x0040       ; UHF receiver start of telegram ok on Rx path B
UHF_SOTAaddr       EQU 0x0042       ; UHF receiver start of telegram ok on Rx path A
UHF_EOTBaddr       EQU 0x0044       ; UHF receiver end of telegram on Rx path B
UHF_EOTAaddr       EQU 0x0046       ; UHF receiver end of telegram on Rx path A
UHF_NBITBaddr       EQU 0x0048       ; UHF receiver new bit on Rx path B
UHF_NBITAaddr       EQU 0x004a       ; UHF receiver new bit on Rx path A
EXCMaddr       EQU 0x004c       ; External input Clock monitoring Interrupt
ERDYaddr       EQU 0x004e       ; EEPROM Ready Interrupt
SPMRaddr       EQU 0x0050       ; Store Program Memory Ready
IDFULLaddr       EQU 0x0052       ; IDSCAN Full Interrupt
INT_VECTORS_SIZE       EQU 84       ; size in words
#endif /* _REGDEF_INC_ */
; ***** END OF FILE ******************************************************
