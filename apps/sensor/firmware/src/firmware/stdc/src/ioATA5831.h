#ifndef IOATA5831_H_OVERALL
#define IOATA5831_H_OVERALL
/****** THIS IS A MACHINE GENERATED FILE - DO NOT EDIT ******************** */
/****** Created: 2013-07-22 09:11 ******* Source: ATA5831.xml ************* */
/**************************************************************************
 *
 * - File Name          : "ioATA5831.h"
 * - Title              : Register/Bit Definitions for the ATA5831
 * - Date               : 2013-07-22
 * - Version            : 2.25
 * - Support E-Mail     : avr@atmel.com
 * - Target MCU         : ATA5831
 *
 * - Compiler           : IAR Embedded Workbench - iccAVR and aAVR.
 *
 **************************************************************************
 */


#include "iomacro.h"

#if TID_GUARD(3)
#error This file should only be compiled with iccavr or aavr whith processor option -v3
#endif /* TID_GUARD(3) */

/* Include the SFR part if this file has not been included before,
* OR this file is included by the assembler (SFRs must be defined in
* each assembler module). */
#if !defined(__IOATA5831_H) || defined(__IAR_SYSTEMS_ASM__)

#pragma language=extended

/*==========================*/
/* Predefined SFR Addresses */
/*==========================*/


/* ***** SPECIFY DEVICE *************************************************** */
/*#define  PART_NAME       ATA5831 */
#define    SIGNATURE_000   0x1e
#define    SIGNATURE_001   0x95
#define    SIGNATURE_002   0x61



/* ***** I/O REGISTER DEFINITIONS ***************************************** */
/* NOTE:
 * Definitions marked "MEMORY MAPPED"are extended I/O ports
 * and cannot be used with IN/OUT instructions
 */
SFR_B(PRR0,	0x01)
SFR_B(PRR1,	0x02)
SFR_B(PRR2,	0x03)
SFR_B(RDPR,	0x04)
SFR_B(PINB,	0x05)
SFR_B(DDRB,	0x06)
SFR_B(PORTB,	0x07)
SFR_B(PINC,	0x08)
SFR_B(DDRC,	0x09)
SFR_B(PORTC,	0x0a)
SFR_B(FSCR,	0x0b)
SFR_B(RDSIFR,	0x0d)
SFR_B(MCUCR,	0x0e)
SFR_B(PCIFR,	0x0f)
SFR_B(T0CR,	0x10)
SFR_B(T1CR,	0x11)
SFR_B(T2CR,	0x12)
SFR_B(T3CR,	0x13)
SFR_B(T4CR,	0x14)
SFR_B(T1IFR,	0x15)
SFR_B(T2IFR,	0x16)
SFR_B(T3IFR,	0x17)
SFR_B(T4IFR,	0x18)
SFR_B(T5IFR,	0x19)
SFR_B(GPIOR0,	0x1a)
SFR_B(GPIOR3,	0x1b)
SFR_B(GPIOR4,	0x1c)
SFR_B(GPIOR5,	0x1d)
SFR_B(GPIOR6,	0x1e)
SFR_B(EECR,	0x1f)
SFR_B(EEDR,	0x20)
SFR_B(EEARL,	0x21)
SFR_B(EEARH,	0x22)
SFR_B(EEPR,	0x23)
SFR_B(GPIOR1,	0x24)
SFR_B(GPIOR2,	0x25)
SFR_B(PCICR,	0x26)
SFR_B(EIMSK,	0x27)
SFR_B(EIFR,	0x28)
SFR_B(CRCDIR,	0x29)
SFR_B(VMCSR,	0x2a)
SFR_B(MCUSR,	0x2b)
SFR_B(SPCR,	0x2c)
SFR_B(SPSR,	0x2d)
SFR_B(SPDR,	0x2e)
SFR_B(T0IFR,	0x2f)
SFR_B(DWDR,	0x31)
SFR_B(RDCR,	0x33)
SFR_B(EOTSA,	0x34)
SFR_B(EOTCA,	0x35)
SFR_B(EOTSB,	0x36)
SFR_B(EOTCB,	0x37)
SFR_B(SMCR,	0x38)
SFR_B(CMCR,	0x39)
SFR_B(CMIMR,	0x3a)
SFR_B(CLPR,	0x3b)
SFR_B(SPMCSR,	0x3c)
SFR_B(SPL,	0x3d)
SFR_B(SPH,	0x3e)
SFR_B(SREG,	0x3f)
SFR_B(FSEN,	0x60)
SFR_B(FSFCR,	0x61)
SFR_B(GACDIVL,	0x62)
SFR_B(GACDIVH,	0x63)
SFR_B(FFREQ1L,	0x64)
SFR_B(FFREQ1M,	0x65)
SFR_B(FFREQ1H,	0x66)
SFR_B(FFREQ2L,	0x67)
SFR_B(FFREQ2M,	0x68)
SFR_B(FFREQ2H,	0x69)
SFR_B(EICRA,	0x6b)
SFR_B(PCMSK0,	0x6c)
SFR_B(PCMSK1,	0x6d)
SFR_B(WDTCR,	0x6e)
SFR_B(T1CNT,	0x6f)
SFR_B(T1COR,	0x70)
SFR_B(T1MR,	0x71)
SFR_B(T1IMR,	0x72)
SFR_B(T2CNT,	0x73)
SFR_B(T2COR,	0x74)
SFR_B(T2MR,	0x75)
SFR_B(T2IMR,	0x76)
SFR_B(T3CNTL,	0x77)
SFR_B(T3CNTH,	0x78)
SFR_B(T3CORL,	0x79)
SFR_B(T3CORH,	0x7a)
SFR_B(T3ICRL,	0x7b)
SFR_B(T3ICRH,	0x7c)
SFR_B(T3MRA,	0x7d)
SFR_B(T3MRB,	0x7e)
SFR_B(T3IMR,	0x7f)
SFR_B(T4CNTL,	0x80)
SFR_B(T4CNTH,	0x81)
SFR_B(T4CORL,	0x82)
SFR_B(T4CORH,	0x83)
SFR_B(T4ICRL,	0x84)
SFR_B(T4ICRH,	0x85)
SFR_B(T4MRA,	0x86)
SFR_B(T4MRB,	0x87)
SFR_B(T4IMR,	0x88)
SFR_B(T5OCRL,	0x8a)
SFR_B(T5OCRH,	0x8b)
SFR_B(T5CCR,	0x8c)
SFR_B(T5CNTL,	0x8d)
SFR_B(T5CNTH,	0x8e)
SFR_B(T5IMR,	0x8f)
SFR_B(GTCCR,	0x90)
SFR_B(SOTSB,	0x91)
SFR_B(SOTSA,	0x92)
SFR_B(SOTCB,	0x93)
SFR_B(SOTCA,	0x94)
SFR_B(TESRB,	0x95)
SFR_B(TESRA,	0x96)
SFR_B(RDSIMR,	0x98)
SFR_B(RDOCR,	0x99)
SFR_B(TEMPL,	0x9b)
SFR_B(TEMPH,	0x9c)
SFR_B(SYCB,	0x9d)
SFR_B(SYCA,	0x9e)
SFR_B(RXFOB,	0x9f)
SFR_B(RXFOA,	0xa0)
SFR_B(DMMB,	0xa1)
SFR_B(DMMA,	0xa2)
SFR_B(DMCDB,	0xa3)
SFR_B(DMCDA,	0xa4)
SFR_B(DMCRB,	0xa5)
SFR_B(DMCRA,	0xa6)
SFR_B(DMDRB,	0xa7)
SFR_B(DMDRA,	0xa8)
SFR_B(CHCR,	0xa9)
SFR_B(CHDN,	0xaa)
SFR_B(SFIDCB,	0xab)
SFR_B(SFIDLB,	0xac)
SFR_B(WUPTB,	0xad)
SFR_B(WUPLB,	0xae)
SFR_B(SFID1B,	0xaf)
SFR_B(SFID2B,	0xb0)
SFR_B(SFID3B,	0xb1)
SFR_B(SFID4B,	0xb2)
SFR_B(WUP1B,	0xb3)
SFR_B(WUP2B,	0xb4)
SFR_B(WUP3B,	0xb5)
SFR_B(WUP4B,	0xb6)
SFR_B(SFIDCA,	0xb7)
SFR_B(SFIDLA,	0xb8)
SFR_B(WUPTA,	0xb9)
SFR_B(WUPLA,	0xba)
SFR_B(SFID1A,	0xbb)
SFR_B(SFID2A,	0xbc)
SFR_B(SFID3A,	0xbd)
SFR_B(SFID4A,	0xbe)
SFR_B(WUP1A,	0xbf)
SFR_B(WUP2A,	0xc0)
SFR_B(WUP3A,	0xc1)
SFR_B(WUP4A,	0xc2)
SFR_B(CLKOD,	0xc3)
SFR_B(CLKOCR,	0xc4)
SFR_B(XFUSE,	0xc5)
SFR_B(SRCCAL,	0xc6)
SFR_B(FRCCAL,	0xc7)
SFR_B(CMSR,	0xc8)
SFR_B(CMOCR,	0xc9)
SFR_B(SUPFR,	0xca)
SFR_B(SUPCR,	0xcb)
SFR_B(SUPCA1,	0xcc)
SFR_B(SUPCA2,	0xcd)
SFR_B(SUPCA3,	0xce)
SFR_B(SUPCA4,	0xcf)
SFR_B(CALRDY,	0xd0)
SFR_B(VMCAL,	0xd1)
SFR_B(DFS,	0xd2)
SFR_B(DFTLL,	0xd3)
SFR_B(DFTLH,	0xd4)
SFR_B(DFL,	0xd5)
SFR_B(DFWP,	0xd6)
SFR_B(DFRP,	0xd7)
SFR_B(DFD,	0xd8)
SFR_B(DFI,	0xd9)
SFR_B(DFC,	0xda)
SFR_B(SFS,	0xdb)
SFR_B(SFL,	0xdc)
SFR_B(SFWP,	0xdd)
SFR_B(SFRP,	0xde)
SFR_B(SFD,	0xdf)
SFR_B(SFI,	0xe0)
SFR_B(SFC,	0xe1)
SFR_B(SSMCR,	0xe2)
SFR_B(SSMRCR,	0xe3)
SFR_B(SSMFBR,	0xe4)
SFR_B(SSMRR,	0xe5)
SFR_B(SSMSR,	0xe6)
SFR_B(SSMIFR,	0xe7)
SFR_B(SSMIMR,	0xe8)
SFR_B(MSMSTR,	0xe9)
SFR_B(SSMSTR,	0xea)
SFR_B(SSMXSR,	0xeb)
SFR_B(MSMCR1,	0xec)
SFR_B(MSMCR2,	0xed)
SFR_B(MSMCR3,	0xee)
SFR_B(MSMCR4,	0xef)
SFR_B(GTCR,	0xf0)
SFR_B(SOTC1A,	0xf1)
SFR_B(SOTC2A,	0xf2)
SFR_B(SOTC1B,	0xf3)
SFR_B(SOTC2B,	0xf4)
SFR_B(EOTC1A,	0xf5)
SFR_B(EOTC2A,	0xf6)
SFR_B(EOTC3A,	0xf7)
SFR_B(EOTC1B,	0xf8)
SFR_B(EOTC2B,	0xf9)
SFR_B(EOTC3B,	0xfa)
SFR_B(WCOTOA,	0xfb)
SFR_B(WCOTOB,	0xfc)
SFR_B(SOTTOA,	0xfd)
SFR_B(SOTTOB,	0xfe)
SFR_B(SSMFCR,	0xff)
SFR_B_EXT_IO_R(0x100,	FESR)
SFR_B_EXT_IO_R(0x101,	FEEN1)
SFR_B_EXT_IO_R(0x102,	FEEN2)
SFR_B_EXT_IO_R(0x103,	FELNA)
SFR_B_EXT_IO_R(0x104,	FEAT)
SFR_B_EXT_IO_R(0x105,	FEPAC)
SFR_B_EXT_IO_R(0x106,	FEVCT)
SFR_B_EXT_IO_R(0x107,	FEBT)
SFR_B_EXT_IO_R(0x108,	FEMS)
SFR_B_EXT_IO_R(0x109,	FETN4)
SFR_B_EXT_IO_R(0x10a,	FECR)
SFR_B_EXT_IO_R(0x10b,	FEVCO)
SFR_B_EXT_IO_R(0x10c,	FEALR)
SFR_B_EXT_IO_R(0x10d,	FEANT)
SFR_B_EXT_IO_R(0x10e,	FEBIA)
SFR_B_EXT_IO_R(0x120,	TMFSM)
SFR_B_EXT_IO_R(0x121,	TMCRL)
SFR_B_EXT_IO_R(0x122,	TMCRH)
SFR_B_EXT_IO_R(0x123,	TMCSB)
SFR_B_EXT_IO_R(0x124,	TMCIL)
SFR_B_EXT_IO_R(0x125,	TMCIH)
SFR_B_EXT_IO_R(0x126,	TMCPL)
SFR_B_EXT_IO_R(0x127,	TMCPH)
SFR_B_EXT_IO_R(0x128,	TMSHR)
SFR_B_EXT_IO_R(0x129,	TMTLL)
SFR_B_EXT_IO_R(0x12a,	TMTLH)
SFR_B_EXT_IO_R(0x12b,	TMSSC)
SFR_B_EXT_IO_R(0x12c,	TMSR)
SFR_B_EXT_IO_R(0x12d,	TMCR2)
SFR_B_EXT_IO_R(0x12e,	TMCR1)
SFR_B_EXT_IO_R(0x12f,	RXBC1)
SFR_B_EXT_IO_R(0x130,	RXBC2)
SFR_B_EXT_IO_R(0x131,	RXTLLB)
SFR_B_EXT_IO_R(0x132,	RXTLHB)
SFR_B_EXT_IO_R(0x133,	RXCRLB)
SFR_B_EXT_IO_R(0x134,	RXCRHB)
SFR_B_EXT_IO_R(0x135,	RXCSBB)
SFR_B_EXT_IO_R(0x136,	RXCILB)
SFR_B_EXT_IO_R(0x137,	RXCIHB)
SFR_B_EXT_IO_R(0x138,	RXCPLB)
SFR_B_EXT_IO_R(0x139,	RXCPHB)
SFR_B_EXT_IO_R(0x13a,	RXDSB)
SFR_B_EXT_IO_R(0x13b,	RXTLLA)
SFR_B_EXT_IO_R(0x13c,	RXTLHA)
SFR_B_EXT_IO_R(0x13d,	RXCRLA)
SFR_B_EXT_IO_R(0x13e,	RXCRHA)
SFR_B_EXT_IO_R(0x13f,	RXCSBA)
SFR_B_EXT_IO_R(0x140,	RXCILA)
SFR_B_EXT_IO_R(0x141,	RXCIHA)
SFR_B_EXT_IO_R(0x142,	RXCPLA)
SFR_B_EXT_IO_R(0x143,	RXCPHA)
SFR_B_EXT_IO_R(0x144,	RXDSA)
SFR_B_EXT_IO_R(0x145,	CRCCR)
SFR_B_EXT_IO_R(0x146,	CRCDOR)
SFR_B_EXT_IO_R(0x147,	IDB0)
SFR_B_EXT_IO_R(0x148,	IDB1)
SFR_B_EXT_IO_R(0x149,	IDB2)
SFR_B_EXT_IO_R(0x14a,	IDB3)
SFR_B_EXT_IO_R(0x14b,	IDC)
SFR_B_EXT_IO_R(0x14c,	IDS)
SFR_B_EXT_IO_R(0x14d,	RSSAV)
SFR_B_EXT_IO_R(0x14e,	RSSPK)
SFR_B_EXT_IO_R(0x14f,	RSSL)
SFR_B_EXT_IO_R(0x150,	RSSH)
SFR_B_EXT_IO_R(0x151,	RSSC)
SFR_B_EXT_IO_R(0x152,	DBCR)
SFR_B_EXT_IO_R(0x153,	DBTC)
SFR_B_EXT_IO_R(0x154,	DBENB)
SFR_B_EXT_IO_R(0x155,	DBENC)
SFR_B_EXT_IO_R(0x156,	DBGSW)
SFR_B_EXT_IO_R(0x157,	SFFR)
SFR_B_EXT_IO_R(0x158,	SFIR)
SFR_B_EXT_IO_R(0x159,	EECR2)
SFR_B_EXT_IO_R(0x15a,	PGMST)
SFR_B_EXT_IO_R(0x15b,	EEST)
SFR_B_EXT_IO_R(0x15c,	RSIFG)
SFR_B_EXT_IO_R(0x15d,	RSLDV)
SFR_B_EXT_IO_R(0x15e,	RSHDV)
SFR_B_EXT_IO_R(0x15f,	RSCOM)



#ifndef __IOATA5831_H
#define __IOATA5831_H

#ifdef __IAR_SYSTEMS_ASM__ 
#ifndef ENABLE_BIT_DEFINITIONS
#define  ENABLE_BIT_DEFINITIONS
#endif /* ENABLE_BIT_DEFINITIONS */
#endif /* __IAR_SYSTEMS_ASM__ */

#ifdef ENABLE_BIT_DEFINITIONS
/* ***** BIT DEFINITIONS ************************************************** */

/* ***** CHFLT ************************ */
/* CHCR - Channel Filter Configuration Register */
#define    BWM0            0       /* Bandwidth Mode bit 0 */
#define    BM_BWM0	(uint8_t)(1U<<BWM0)
#define    BWM1            1       /* Bandwidth Mode bit 1 */
#define    BM_BWM1	(uint8_t)(1U<<BWM1)
#define    BWM2            2       /* Bandwidth Mode bit 2 */
#define    BM_BWM2	(uint8_t)(1U<<BWM2)
#define    BWM3            3       /* Bandwidth Mode bit 3 */
#define    BM_BWM3	(uint8_t)(1U<<BWM3)

/* CHDN - Channel Filter Down Sampling Register */
#define    BBDN0           0       /* Baseband Filter Down Sampling Ratio bit 0 */
#define    BM_BBDN0	(uint8_t)(1U<<BBDN0)
#define    BBDN1           1       /* Baseband Filter Down Sampling Ratio bit 1 */
#define    BM_BBDN1	(uint8_t)(1U<<BBDN1)
#define    BBDN2           2       /* Baseband Filter Down Sampling Ratio bit 2 */
#define    BM_BBDN2	(uint8_t)(1U<<BBDN2)
#define    BBDN3           3       /* Baseband Filter Down Sampling Ratio bit 3 */
#define    BM_BBDN3	(uint8_t)(1U<<BBDN3)
#define    BBDN4           4       /* Baseband Filter Down Sampling Ratio bit 4 */
#define    BM_BBDN4	(uint8_t)(1U<<BBDN4)
#define    ADCDN           5       /* ADC Down Sampling Configuration */
#define    BM_ADCDN	(uint8_t)(1U<<ADCDN)


/* ***** CLK ************************** */
/* CLKOCR - Clock output control Register */
#define    CLKOS0          0       /* Clock output source bit 0 */
#define    BM_CLKOS0	(uint8_t)(1U<<CLKOS0)
#define    CLKOS1          1       /* Clock output source bit 1 */
#define    BM_CLKOS1	(uint8_t)(1U<<CLKOS1)
#define    CLKOEN          2       /* Clock output driver enable */
#define    BM_CLKOEN	(uint8_t)(1U<<CLKOEN)

/* CLKOD - Clock output divider settings Register */
#define    CLKOD0          0       /* Clock output divider bit 0 */
#define    BM_CLKOD0	(uint8_t)(1U<<CLKOD0)
#define    CLKOD1          1       /* Clock output divider bit 1 */
#define    BM_CLKOD1	(uint8_t)(1U<<CLKOD1)
#define    CLKOD2          2       /* Clock output divider bit 2 */
#define    BM_CLKOD2	(uint8_t)(1U<<CLKOD2)
#define    CLKOD3          3       /* Clock output divider bit 3 */
#define    BM_CLKOD3	(uint8_t)(1U<<CLKOD3)
#define    CLKOD4          4       /* Clock output divider bit 4 */
#define    BM_CLKOD4	(uint8_t)(1U<<CLKOD4)
#define    CLKOD5          5       /* Clock output divider bit 5 */
#define    BM_CLKOD5	(uint8_t)(1U<<CLKOD5)
#define    CLKOD6          6       /* Clock output divider bit 6 */
#define    BM_CLKOD6	(uint8_t)(1U<<CLKOD6)
#define    CLKOD7          7       /* Clock output divider bit 7 */
#define    BM_CLKOD7	(uint8_t)(1U<<CLKOD7)

/* CMOCR - Clock management override control register */
#define    FRCAO           0       /* FRC Always On */
#define    BM_FRCAO	(uint8_t)(1U<<FRCAO)
#define    SRCAO           1       /* SRC Always On */
#define    BM_SRCAO	(uint8_t)(1U<<SRCAO)
#define    FRCACT          2       /* FRC Active */
#define    BM_FRCACT	(uint8_t)(1U<<FRCACT)
#define    SRCACT          3       /* SRC Active */
#define    BM_SRCACT	(uint8_t)(1U<<SRCACT)

/* CMSR - Clock management status Register */
#define    ECF             0       /* External clock fail */
#define    BM_ECF	(uint8_t)(1U<<ECF)

/* FRCCAL - Fast RC oscillator calibration Register */
#define    FRCCAL0         0       /* Fast RC oscillator calibration bit 0 */
#define    BM_FRCCAL0	(uint8_t)(1U<<FRCCAL0)
#define    FRCCAL1         1       /* Fast RC oscillator calibration bit 1 */
#define    BM_FRCCAL1	(uint8_t)(1U<<FRCCAL1)
#define    FRCCAL2         2       /* Fast RC oscillator calibration bit 2 */
#define    BM_FRCCAL2	(uint8_t)(1U<<FRCCAL2)
#define    FRCCAL3         3       /* Fast RC oscillator calibration bit 3 */
#define    BM_FRCCAL3	(uint8_t)(1U<<FRCCAL3)
#define    FRCCAL4         4       /* Fast RC oscillator calibration bit 4 */
#define    BM_FRCCAL4	(uint8_t)(1U<<FRCCAL4)
#define    FRCTC           5       /* Fast RC oscillator temperature compensation */
#define    BM_FRCTC	(uint8_t)(1U<<FRCTC)

/* PRR0 - Power reduction Register 0 */
#define    PRSPI           0       /* Power Reduction Serial Peripheral Interface */
#define    BM_PRSPI	(uint8_t)(1U<<PRSPI)
#define    PRRXDC          1       /* Power Reduction Receive DSP Control */
#define    BM_PRRXDC	(uint8_t)(1U<<PRRXDC)
#define    PRTXDC          2       /* Power Reduction Transmit DSP Control */
#define    BM_PRTXDC	(uint8_t)(1U<<PRTXDC)
#define    PRCRC           3       /* Power Reduction CRC */
#define    BM_PRCRC	(uint8_t)(1U<<PRCRC)
#define    PRVM            4       /* Power Reduction Voltage Monitor */
#define    BM_PRVM	(uint8_t)(1U<<PRVM)
#define    PRCO            5       /* Power Reduction Clock Output */
#define    BM_PRCO	(uint8_t)(1U<<PRCO)

/* PRR1 - Power reduction Register 1 */
#define    PRT1            0       /* Power Reduction Timer 1 */
#define    BM_PRT1	(uint8_t)(1U<<PRT1)
#define    PRT2            1       /* Power Reduction Timer 2 */
#define    BM_PRT2	(uint8_t)(1U<<PRT2)
#define    PRT3            2       /* Power Reduction Timer 3 */
#define    BM_PRT3	(uint8_t)(1U<<PRT3)
#define    PRT4            3       /* Power Reduction Timer 4 */
#define    BM_PRT4	(uint8_t)(1U<<PRT4)
#define    PRT5            4       /* Power Reduction Timer 5 */
#define    BM_PRT5	(uint8_t)(1U<<PRT5)

/* PRR2 - Power reduction register 2 */
#define    PRXB            0       /* Power Reduction Rx Buffer B */
#define    BM_PRXB	(uint8_t)(1U<<PRXB)
#define    PRXA            1       /* Power Reduction Rx Buffer A */
#define    BM_PRXA	(uint8_t)(1U<<PRXA)
#define    PRSF            2       /* Power Reduction Preamble/RSSI FIFO */
#define    BM_PRSF	(uint8_t)(1U<<PRSF)
#define    PRDF            3       /* Power Reduction Data FIFO */
#define    BM_PRDF	(uint8_t)(1U<<PRDF)
#define    PRIDS           4       /* Power Reduction ID scan */
#define    BM_PRIDS	(uint8_t)(1U<<PRIDS)
#define    PRRS            5       /* Power Reduction RSSI Buffer */
#define    BM_PRRS	(uint8_t)(1U<<PRRS)
#define    PRTM            6       /* Power Reduction Tx Modulator */
#define    BM_PRTM	(uint8_t)(1U<<PRTM)
#define    PRSSM           7       /* Power Reduction Sequencer State Machine */
#define    BM_PRSSM	(uint8_t)(1U<<PRSSM)

/* RDPR - Rx DSP power reduction register */
#define    PRPTB           0       /* Power reduction register for the demodulator and receiving path A */
#define    BM_PRPTB	(uint8_t)(1U<<PRPTB)
#define    PRPTA           1       /* Power reduction register for the demodulator and receiving path B */
#define    BM_PRPTA	(uint8_t)(1U<<PRPTA)
#define    PRFLT           2       /* Power reduction register for the digital channel filter */
#define    BM_PRFLT	(uint8_t)(1U<<PRFLT)
#define    PRTMP           3       /* Power reduction register for temperature measurement */
#define    BM_PRTMP	(uint8_t)(1U<<PRTMP)
#define    APRPTB          4       /* Automatic Power Reduction of Path B */
#define    BM_APRPTB	(uint8_t)(1U<<APRPTB)
#define    APRPTA          5       /* Automatic Power Reduction of Path A */
#define    BM_APRPTA	(uint8_t)(1U<<APRPTA)
#define    ARDPRF          6       /* Automatic Rx DSP Power Reduction Flag */
#define    BM_ARDPRF	(uint8_t)(1U<<ARDPRF)
#define    RDPRF           7       /* Rx DSP power reduction register(RDPR) busy flag */
#define    BM_RDPRF	(uint8_t)(1U<<RDPRF)

/* SRCCAL - Slow RC oscillator calibration Register */
#define    SRCCAL0         0       /* Slow RC oscillator calibration bit 0 */
#define    BM_SRCCAL0	(uint8_t)(1U<<SRCCAL0)
#define    SRCCAL1         1       /* Slow RC oscillator calibration bit 1 */
#define    BM_SRCCAL1	(uint8_t)(1U<<SRCCAL1)
#define    SRCCAL2         2       /* Slow RC oscillator calibration bit 2 */
#define    BM_SRCCAL2	(uint8_t)(1U<<SRCCAL2)
#define    SRCCAL3         3       /* Slow RC oscillator calibration bit 3 */
#define    BM_SRCCAL3	(uint8_t)(1U<<SRCCAL3)
#define    SRCCAL4         4       /* Slow RC oscillator calibration bit 4 */
#define    BM_SRCCAL4	(uint8_t)(1U<<SRCCAL4)
#define    SRCCAL5         5       /* Slow RC oscillator calibration bit 5 */
#define    BM_SRCCAL5	(uint8_t)(1U<<SRCCAL5)
#define    SRCTC0          6       /* Slow RC oscillator temperature compensation bit 0 */
#define    BM_SRCTC0	(uint8_t)(1U<<SRCTC0)
#define    SRCTC1          7       /* Slow RC oscillator temperature compensation bit 1 */
#define    BM_SRCTC1	(uint8_t)(1U<<SRCTC1)

/* XFUSE -  */


/* ***** CPU ************************** */
/* CLPR - Clock Prescaler Register */
#define    CLKPS0          0       /* System Clock Prescaler Select bit 0 */
#define    BM_CLKPS0	(uint8_t)(1U<<CLKPS0)
#define    CLKPS1          1       /* System Clock Prescaler Select bit 1 */
#define    BM_CLKPS1	(uint8_t)(1U<<CLKPS1)
#define    CLKPS2          2       /* System Clock Prescaler Select bit 2 */
#define    BM_CLKPS2	(uint8_t)(1U<<CLKPS2)
#define    CLTPS0          3       /* Timer Clock Prescaler Select bit 0 */
#define    BM_CLTPS0	(uint8_t)(1U<<CLTPS0)
#define    CLTPS1          4       /* Timer Clock Prescaler Select bit 1 */
#define    BM_CLTPS1	(uint8_t)(1U<<CLTPS1)
#define    CLTPS2          5       /* Timer Clock Prescaler Select bit 2 */
#define    BM_CLTPS2	(uint8_t)(1U<<CLTPS2)
#define    CLPCE           7       /* Clock Prescaler Change Enable */
#define    BM_CLPCE	(uint8_t)(1U<<CLPCE)

/* CMCR - Clock Management Control Register */
#define    CMM0            0       /* Clock Management Mode bit 0 */
#define    BM_CMM0	(uint8_t)(1U<<CMM0)
#define    CMM1            1       /* Clock Management Mode bit 1 */
#define    BM_CMM1	(uint8_t)(1U<<CMM1)
#define    CMM2            2       /* Clock Management Mode bit 2 */
#define    BM_CMM2	(uint8_t)(1U<<CMM2)
#define    CCS             3       /* Core Clock Select */
#define    BM_CCS	(uint8_t)(1U<<CCS)
#define    SRCD            4       /* Slow RC oscillator disable */
#define    BM_SRCD	(uint8_t)(1U<<SRCD)
#define    CMONEN          6       /* Clock monitor enable */
#define    BM_CMONEN	(uint8_t)(1U<<CMONEN)
#define    CMCCE           7       /* Clock management control change enable */
#define    BM_CMCCE	(uint8_t)(1U<<CMCCE)

/* CMIMR - Clock interrupt mask Register */
#define    ECIE            0       /* External clock interrupt enable */
#define    BM_ECIE	(uint8_t)(1U<<ECIE)

/* DWDR - Debug Wire Data Register */
#define    DWDR0           0       /* Debug Wire Data Register bit 0 */
#define    BM_DWDR0	(uint8_t)(1U<<DWDR0)
#define    DWDR1           1       /* Debug Wire Data Register bit 1 */
#define    BM_DWDR1	(uint8_t)(1U<<DWDR1)
#define    DWDR2           2       /* Debug Wire Data Register bit 2 */
#define    BM_DWDR2	(uint8_t)(1U<<DWDR2)
#define    DWDR3           3       /* Debug Wire Data Register bit 3 */
#define    BM_DWDR3	(uint8_t)(1U<<DWDR3)
#define    DWDR4           4       /* Debug Wire Data Register bit 4 */
#define    BM_DWDR4	(uint8_t)(1U<<DWDR4)
#define    DWDR5           5       /* Debug Wire Data Register bit 5 */
#define    BM_DWDR5	(uint8_t)(1U<<DWDR5)
#define    DWDR6           6       /* Debug Wire Data Register bit 6 */
#define    BM_DWDR6	(uint8_t)(1U<<DWDR6)
#define    DWDR7           7       /* Debug Wire Data Register bit 7 */
#define    BM_DWDR7	(uint8_t)(1U<<DWDR7)

/* MCUCR - MCU control Register */
#define    IVCE            0       /* Interrupt Vector Change Enable */
#define    BM_IVCE	(uint8_t)(1U<<IVCE)
#define    IVSEL           1       /* Interrupt Vector Select */
#define    BM_IVSEL	(uint8_t)(1U<<IVSEL)
#define    SPIIO           2       /* SPI Interrupt Only */
#define    BM_SPIIO	(uint8_t)(1U<<SPIIO)
#define    ENPS            3       /* Enable Port Settings */
#define    BM_ENPS	(uint8_t)(1U<<ENPS)
#define    PUD             4       /* Pull-up Resistors Disable */
#define    BM_PUD	(uint8_t)(1U<<PUD)
#define    PB4HS           5       /* Port B4 High Side Driver enable */
#define    BM_PB4HS	(uint8_t)(1U<<PB4HS)
#define    PB7LS           6       /* Port B7 Low Side Driver enable */
#define    BM_PB7LS	(uint8_t)(1U<<PB7LS)
#define    PB7HS           7       /* Port B7 High Side Driver enable */
#define    BM_PB7HS	(uint8_t)(1U<<PB7HS)

/* MCUSR - MCU Status Register */
#define    PORF            0       /* Power-On Reset Flag */
#define    BM_PORF	(uint8_t)(1U<<PORF)
#define    EXTRF           1       /* External Reset Flag */
#define    BM_EXTRF	(uint8_t)(1U<<EXTRF)
#define    WDRF            3       /* Watchdog Reset Flag */
#define    BM_WDRF	(uint8_t)(1U<<WDRF)

/* SMCR - Sleep mode control Register */
#define    SE              0       /* Sleep Enable */
#define    BM_SE	(uint8_t)(1U<<SE)
#define    SM0             1       /* Sleep Mode Select bit 0 */
#define    BM_SM0	(uint8_t)(1U<<SM0)
#define    SM1             2       /* Sleep Mode Select bit 1 */
#define    BM_SM1	(uint8_t)(1U<<SM1)
#define    SM2             3       /* Sleep Mode Select bit 2 */
#define    BM_SM2	(uint8_t)(1U<<SM2)

/* SPH - Stack Pointer High */
#define    SP8             0       /* Stack pointer bit 8 */
#define    BM_SP8	(uint8_t)(1U<<SP8)
#define    SP9             1       /* Stack pointer bit 9 */
#define    BM_SP9	(uint8_t)(1U<<SP9)
#define    SP10            2       /* Stack pointer bit 10 */
#define    BM_SP10	(uint8_t)(1U<<SP10)

/* SPL - Stack Pointer Low */
#define    SP0             0       /* Stack pointer bit 0 */
#define    BM_SP0	(uint8_t)(1U<<SP0)
#define    SP1             1       /* Stack pointer bit 1 */
#define    BM_SP1	(uint8_t)(1U<<SP1)
#define    SP2             2       /* Stack pointer bit 2 */
#define    BM_SP2	(uint8_t)(1U<<SP2)
#define    SP3             3       /* Stack pointer bit 3 */
#define    BM_SP3	(uint8_t)(1U<<SP3)
#define    SP4             4       /* Stack pointer bit 4 */
#define    BM_SP4	(uint8_t)(1U<<SP4)
#define    SP5             5       /* Stack pointer bit 5 */
#define    BM_SP5	(uint8_t)(1U<<SP5)
#define    SP6             6       /* Stack pointer bit 6 */
#define    BM_SP6	(uint8_t)(1U<<SP6)
#define    SP7             7       /* Stack pointer bit 7 */
#define    BM_SP7	(uint8_t)(1U<<SP7)

/* SPMCSR - Store Program Memory Control and Status Register */
#define    SELFPRGEN       0       /* Self Programming Enable */
#define    BM_SELFPRGEN	(uint8_t)(1U<<SELFPRGEN)
#define    PGERS           1       /* Page Erase */
#define    BM_PGERS	(uint8_t)(1U<<PGERS)
#define    PGWRT           2       /* Page Write */
#define    BM_PGWRT	(uint8_t)(1U<<PGWRT)
#define    BLBSET          3       /* Boot Lock Bit Set */
#define    BM_BLBSET	(uint8_t)(1U<<BLBSET)
#define    SPMIE           7       /* SPM Interrupt Enable */
#define    BM_SPMIE	(uint8_t)(1U<<SPMIE)

/* SREG - Status Register */
#define    SREG_C          0       /* Carry Flag */
#define    BM_SREG_C	(uint8_t)(1U<<SREG_C)
#define    SREG_Z          1       /* Zero Flag */
#define    BM_SREG_Z	(uint8_t)(1U<<SREG_Z)
#define    SREG_N          2       /* Negative Flag */
#define    BM_SREG_N	(uint8_t)(1U<<SREG_N)
#define    SREG_V          3       /* Two's Complement Overflow Flag */
#define    BM_SREG_V	(uint8_t)(1U<<SREG_V)
#define    SREG_S          4       /* Sign Bit */
#define    BM_SREG_S	(uint8_t)(1U<<SREG_S)
#define    SREG_H          5       /* Half Carry Flag */
#define    BM_SREG_H	(uint8_t)(1U<<SREG_H)
#define    SREG_T          6       /* Bit Copy Storage */
#define    BM_SREG_T	(uint8_t)(1U<<SREG_T)
#define    SREG_I          7       /* Global Interrupt Enable */
#define    BM_SREG_I	(uint8_t)(1U<<SREG_I)


/* ***** CRC ************************** */
/* CRCCR - CRC Control Register */
#define    CRCRS           0       /* CRC Data Register Reset */
#define    BM_CRCRS	(uint8_t)(1U<<CRCRS)
#define    REFLI           1       /* Reflect Data Input Byte */
#define    BM_REFLI	(uint8_t)(1U<<REFLI)
#define    REFLO           2       /* Reflect Data Output Byte */
#define    BM_REFLO	(uint8_t)(1U<<REFLO)

/* CRCDIR - CRC Data Input Register */
#define    CRCDIR0         0       /* CRC Data Input Register bit 0 */
#define    BM_CRCDIR0	(uint8_t)(1U<<CRCDIR0)
#define    CRCDIR1         1       /* CRC Data Input Register bit 1 */
#define    BM_CRCDIR1	(uint8_t)(1U<<CRCDIR1)
#define    CRCDIR2         2       /* CRC Data Input Register bit 2 */
#define    BM_CRCDIR2	(uint8_t)(1U<<CRCDIR2)
#define    CRCDIR3         3       /* CRC Data Input Register bit 3 */
#define    BM_CRCDIR3	(uint8_t)(1U<<CRCDIR3)
#define    CRCDIR4         4       /* CRC Data Input Register bit 4 */
#define    BM_CRCDIR4	(uint8_t)(1U<<CRCDIR4)
#define    CRCDIR5         5       /* CRC Data Input Register bit 5 */
#define    BM_CRCDIR5	(uint8_t)(1U<<CRCDIR5)
#define    CRCDIR6         6       /* CRC Data Input Register bit 6 */
#define    BM_CRCDIR6	(uint8_t)(1U<<CRCDIR6)
#define    CRCDIR7         7       /* CRC Data Input Register bit 7 */
#define    BM_CRCDIR7	(uint8_t)(1U<<CRCDIR7)

/* CRCDOR - CRC Data Output Register */
#define    CRCDOR0         0       /* CRC Data Output Register bit 0 */
#define    BM_CRCDOR0	(uint8_t)(1U<<CRCDOR0)
#define    CRCDOR1         1       /* CRC Data Output Register bit 1 */
#define    BM_CRCDOR1	(uint8_t)(1U<<CRCDOR1)
#define    CRCDOR2         2       /* CRC Data Output Register bit 2 */
#define    BM_CRCDOR2	(uint8_t)(1U<<CRCDOR2)
#define    CRCDOR3         3       /* CRC Data Output Register bit 3 */
#define    BM_CRCDOR3	(uint8_t)(1U<<CRCDOR3)
#define    CRCDOR4         4       /* CRC Data Output Register bit 4 */
#define    BM_CRCDOR4	(uint8_t)(1U<<CRCDOR4)
#define    CRCDOR5         5       /* CRC Data Output Register bit 5 */
#define    BM_CRCDOR5	(uint8_t)(1U<<CRCDOR5)
#define    CRCDOR6         6       /* CRC Data Output Register bit 6 */
#define    BM_CRCDOR6	(uint8_t)(1U<<CRCDOR6)
#define    CRCDOR7         7       /* CRC Data Output Register bit 7 */
#define    BM_CRCDOR7	(uint8_t)(1U<<CRCDOR7)


/* ***** DEBOUNCE ********************* */
/* DBCR - DeBounce Control Register */
#define    DBMD            0       /* Debounce Mode */
#define    BM_DBMD	(uint8_t)(1U<<DBMD)
#define    DBCS            1       /* Debounce Clock Select */
#define    BM_DBCS	(uint8_t)(1U<<DBCS)
#define    DBTMS           2       /* Debounce Timer Mask Select */
#define    BM_DBTMS	(uint8_t)(1U<<DBTMS)
#define    DBHA            3       /* Debounce Handshake Active */
#define    BM_DBHA	(uint8_t)(1U<<DBHA)

/* DBENB - DeBounce Enable Port B */
#define    DBENB0          0       /* DeBounce Enable Port B Pin 0 */
#define    BM_DBENB0	(uint8_t)(1U<<DBENB0)
#define    DBENB1          1       /* DeBounce Enable Port B Pin 1 */
#define    BM_DBENB1	(uint8_t)(1U<<DBENB1)
#define    DBENB2          2       /* DeBounce Enable Port B Pin 2 */
#define    BM_DBENB2	(uint8_t)(1U<<DBENB2)
#define    DBENB3          3       /* DeBounce Enable Port B Pin 3 */
#define    BM_DBENB3	(uint8_t)(1U<<DBENB3)
#define    DBENB4          4       /* DeBounce Enable Port B Pin 4 */
#define    BM_DBENB4	(uint8_t)(1U<<DBENB4)
#define    DBENB5          5       /* DeBounce Enable Port B Pin 5 */
#define    BM_DBENB5	(uint8_t)(1U<<DBENB5)
#define    DBENB6          6       /* DeBounce Enable Port B Pin 6 */
#define    BM_DBENB6	(uint8_t)(1U<<DBENB6)
#define    DBENB7          7       /* DeBounce Enable Port B Pin 7 */
#define    BM_DBENB7	(uint8_t)(1U<<DBENB7)

/* DBENC - DeBounce Enable Port C */
#define    DBENC0          0       /* DeBounce Enable Port C Pin 0 */
#define    BM_DBENC0	(uint8_t)(1U<<DBENC0)
#define    DBENC1          1       /* DeBounce Enable Port C Pin 1 */
#define    BM_DBENC1	(uint8_t)(1U<<DBENC1)
#define    DBENC2          2       /* DeBounce Enable Port C Pin 2 */
#define    BM_DBENC2	(uint8_t)(1U<<DBENC2)
#define    DBENC3          3       /* DeBounce Enable Port C Pin 3 */
#define    BM_DBENC3	(uint8_t)(1U<<DBENC3)
#define    DBENC4          4       /* DeBounce Enable Port C Pin 4 */
#define    BM_DBENC4	(uint8_t)(1U<<DBENC4)
#define    DBENC5          5       /* DeBounce Enable Port C Pin 5 */
#define    BM_DBENC5	(uint8_t)(1U<<DBENC5)

/* DBTC - Debounce Timer Compare Register */
#define    DBTC0           0       /* Debounce Timer Compare bit 0 */
#define    BM_DBTC0	(uint8_t)(1U<<DBTC0)
#define    DBTC1           1       /* Debounce Timer Compare bit 1 */
#define    BM_DBTC1	(uint8_t)(1U<<DBTC1)
#define    DBTC2           2       /* Debounce Timer Compare bit 2 */
#define    BM_DBTC2	(uint8_t)(1U<<DBTC2)
#define    DBTC3           3       /* Debounce Timer Compare bit 3 */
#define    BM_DBTC3	(uint8_t)(1U<<DBTC3)
#define    DBTC4           4       /* Debounce Timer Compare bit 4 */
#define    BM_DBTC4	(uint8_t)(1U<<DBTC4)
#define    DBTC5           5       /* Debounce Timer Compare bit 5 */
#define    BM_DBTC5	(uint8_t)(1U<<DBTC5)
#define    DBTC6           6       /* Debounce Timer Compare bit 6 */
#define    BM_DBTC6	(uint8_t)(1U<<DBTC6)
#define    DBTC7           7       /* Debounce Timer Compare bit 7 */
#define    BM_DBTC7	(uint8_t)(1U<<DBTC7)


/* ***** DEBUG ************************ */
/* DBGSW - Debugging Support Switch */
#define    DBGGS0          0       /* Debugging Support Group Select bit 0 */
#define    BM_DBGGS0	(uint8_t)(1U<<DBGGS0)
#define    DBGGS1          1       /* Debugging Support Group Select bit 1 */
#define    BM_DBGGS1	(uint8_t)(1U<<DBGGS1)
#define    DBGGS2          2       /* Debugging Support Group Select bit 2 */
#define    BM_DBGGS2	(uint8_t)(1U<<DBGGS2)
#define    DBGGS3          3       /* Debugging Support Group Select bit 3 */
#define    BM_DBGGS3	(uint8_t)(1U<<DBGGS3)
#define    CPBFOS0         4       /* CPU Busy Flag Output Select bit 0 */
#define    BM_CPBFOS0	(uint8_t)(1U<<CPBFOS0)
#define    CPBFOS1         5       /* CPU Busy Flag Output Select bit 1 */
#define    BM_CPBFOS1	(uint8_t)(1U<<CPBFOS1)
#define    CPBF            6       /* CPU Busy Flag */
#define    BM_CPBF	(uint8_t)(1U<<CPBF)
#define    DBGSE           7       /* Debugging Support Switch Enable */
#define    BM_DBGSE	(uint8_t)(1U<<DBGSE)


/* ***** DEMOD ************************ */
/* DMCDA - Demodulator Carrier Detect for path A */
#define    DMCLA0          0       /* Demodulator Carrier Detect Limit for path A bit 0 */
#define    BM_DMCLA0	(uint8_t)(1U<<DMCLA0)
#define    DMCLA1          1       /* Demodulator Carrier Detect Limit for path A bit 1 */
#define    BM_DMCLA1	(uint8_t)(1U<<DMCLA1)
#define    DMCLA2          2       /* Demodulator Carrier Detect Limit for path A bit 2 */
#define    BM_DMCLA2	(uint8_t)(1U<<DMCLA2)
#define    DMCLA3          3       /* Demodulator Carrier Detect Limit for path A bit 3 */
#define    BM_DMCLA3	(uint8_t)(1U<<DMCLA3)
#define    DMCLA4          4       /* Demodulator Carrier Detect Limit for path A bit 4 */
#define    BM_DMCLA4	(uint8_t)(1U<<DMCLA4)
#define    DMCTA0          5       /* Demodulator Carrier Detect Time for path A bit 0 */
#define    BM_DMCTA0	(uint8_t)(1U<<DMCTA0)
#define    DMCTA1          6       /* Demodulator Carrier Detect Time for path A bit 1 */
#define    BM_DMCTA1	(uint8_t)(1U<<DMCTA1)
#define    DMCTA2          7       /* Demodulator Carrier Detect Time for path A bit 2 */
#define    BM_DMCTA2	(uint8_t)(1U<<DMCTA2)

/* DMCDB - Demodulator Carrier Detect for path B */
#define    DMCLB0          0       /* Demodulator Carrier Detect Limit for path B bit 0 */
#define    BM_DMCLB0	(uint8_t)(1U<<DMCLB0)
#define    DMCLB1          1       /* Demodulator Carrier Detect Limit for path B bit 1 */
#define    BM_DMCLB1	(uint8_t)(1U<<DMCLB1)
#define    DMCLB2          2       /* Demodulator Carrier Detect Limit for path B bit 2 */
#define    BM_DMCLB2	(uint8_t)(1U<<DMCLB2)
#define    DMCLB3          3       /* Demodulator Carrier Detect Limit for path B bit 3 */
#define    BM_DMCLB3	(uint8_t)(1U<<DMCLB3)
#define    DMCLB4          4       /* Demodulator Carrier Detect Limit for path B bit 4 */
#define    BM_DMCLB4	(uint8_t)(1U<<DMCLB4)
#define    DMCTB0          5       /* Demodulator Carrier Detect Time for path B bit 0 */
#define    BM_DMCTB0	(uint8_t)(1U<<DMCTB0)
#define    DMCTB1          6       /* Demodulator Carrier Detect Time for path B bit 1 */
#define    BM_DMCTB1	(uint8_t)(1U<<DMCTB1)
#define    DMCTB2          7       /* Demodulator Carrier Detect Time for path B bit 2 */
#define    BM_DMCTB2	(uint8_t)(1U<<DMCTB2)

/* DMCRA - Demodulator Control Register for path A */
#define    DMPGA0          0       /* Demodulator PLL loop gain for path A bit 0 */
#define    BM_DMPGA0	(uint8_t)(1U<<DMPGA0)
#define    DMPGA1          1       /* Demodulator PLL loop gain for path A bit 1 */
#define    BM_DMPGA1	(uint8_t)(1U<<DMPGA1)
#define    DMPGA2          2       /* Demodulator PLL loop gain for path A bit 2 */
#define    BM_DMPGA2	(uint8_t)(1U<<DMPGA2)
#define    DMPGA3          3       /* Demodulator PLL loop gain for path A bit 3 */
#define    BM_DMPGA3	(uint8_t)(1U<<DMPGA3)
#define    DMPGA4          4       /* Demodulator PLL loop gain for path A bit 4 */
#define    BM_DMPGA4	(uint8_t)(1U<<DMPGA4)
#define    SASKA           5       /* Select ASK input for path A */
#define    BM_SASKA	(uint8_t)(1U<<SASKA)
#define    SY1TA           6       /* Symbol check with only 1T on path A */
#define    BM_SY1TA	(uint8_t)(1U<<SY1TA)
#define    DMARA           7       /* Demodulator automatic restart on path A */
#define    BM_DMARA	(uint8_t)(1U<<DMARA)

/* DMCRB - Demodulator Control Register for path B */
#define    DMPGB0          0       /* Demodulator PLL loop gain for path B bit 0 */
#define    BM_DMPGB0	(uint8_t)(1U<<DMPGB0)
#define    DMPGB1          1       /* Demodulator PLL loop gain for path B bit 1 */
#define    BM_DMPGB1	(uint8_t)(1U<<DMPGB1)
#define    DMPGB2          2       /* Demodulator PLL loop gain for path B bit 2 */
#define    BM_DMPGB2	(uint8_t)(1U<<DMPGB2)
#define    DMPGB3          3       /* Demodulator PLL loop gain for path B bit 3 */
#define    BM_DMPGB3	(uint8_t)(1U<<DMPGB3)
#define    DMPGB4          4       /* Demodulator PLL loop gain for path B bit 4 */
#define    BM_DMPGB4	(uint8_t)(1U<<DMPGB4)
#define    SASKB           5       /* Select ASK input for path B */
#define    BM_SASKB	(uint8_t)(1U<<SASKB)
#define    SY1TB           6       /* Symbol check with only 1T on path B */
#define    BM_SY1TB	(uint8_t)(1U<<SY1TB)
#define    DMARB           7       /* Demodulator automatic restart on path B */
#define    BM_DMARB	(uint8_t)(1U<<DMARB)

/* DMDRA - Demodulator Data Rate on path A */
#define    DMAA0           0       /* Demodulator Moving Average Data Rate factor on path A bit 0 */
#define    BM_DMAA0	(uint8_t)(1U<<DMAA0)
#define    DMAA1           1       /* Demodulator Moving Average Data Rate factor on path A bit 1 */
#define    BM_DMAA1	(uint8_t)(1U<<DMAA1)
#define    DMAA2           2       /* Demodulator Moving Average Data Rate factor on path A bit 2 */
#define    BM_DMAA2	(uint8_t)(1U<<DMAA2)
#define    DMAA3           3       /* Demodulator Moving Average Data Rate factor on path A bit 3 */
#define    BM_DMAA3	(uint8_t)(1U<<DMAA3)
#define    DMDNA0          4       /* Demodulator Downsampling on path A bit 0 */
#define    BM_DMDNA0	(uint8_t)(1U<<DMDNA0)
#define    DMDNA1          5       /* Demodulator Downsampling on path A bit 1 */
#define    BM_DMDNA1	(uint8_t)(1U<<DMDNA1)
#define    DMDNA2          6       /* Demodulator Downsampling on path A bit 2 */
#define    BM_DMDNA2	(uint8_t)(1U<<DMDNA2)
#define    DMDNA3          7       /* Demodulator Downsampling on path A bit 3 */
#define    BM_DMDNA3	(uint8_t)(1U<<DMDNA3)

/* DMDRB - Demodulator Data Rate on path B */
#define    DMAB0           0       /* Demodulator Moving Average Data Rate factor on path B bit 0 */
#define    BM_DMAB0	(uint8_t)(1U<<DMAB0)
#define    DMAB1           1       /* Demodulator Moving Average Data Rate factor on path B bit 1 */
#define    BM_DMAB1	(uint8_t)(1U<<DMAB1)
#define    DMAB2           2       /* Demodulator Moving Average Data Rate factor on path B bit 2 */
#define    BM_DMAB2	(uint8_t)(1U<<DMAB2)
#define    DMAB3           3       /* Demodulator Moving Average Data Rate factor on path B bit 3 */
#define    BM_DMAB3	(uint8_t)(1U<<DMAB3)
#define    DMDNB0          4       /* Demodulator Downsampling on path B bit 0 */
#define    BM_DMDNB0	(uint8_t)(1U<<DMDNB0)
#define    DMDNB1          5       /* Demodulator Downsampling on path B bit 1 */
#define    BM_DMDNB1	(uint8_t)(1U<<DMDNB1)
#define    DMDNB2          6       /* Demodulator Downsampling on path B bit 2 */
#define    BM_DMDNB2	(uint8_t)(1U<<DMDNB2)
#define    DMDNB3          7       /* Demodulator Downsampling on path B bit 3 */
#define    BM_DMDNB3	(uint8_t)(1U<<DMDNB3)

/* DMMA - Demodulator Mode for path A */
#define    DMATA0          0       /* Demodulator Amplitude Threshold for path A bit 0 */
#define    BM_DMATA0	(uint8_t)(1U<<DMATA0)
#define    DMATA1          1       /* Demodulator Amplitude Threshold for path A bit 1 */
#define    BM_DMATA1	(uint8_t)(1U<<DMATA1)
#define    DMATA2          2       /* Demodulator Amplitude Threshold for path A bit 2 */
#define    BM_DMATA2	(uint8_t)(1U<<DMATA2)
#define    DMATA3          3       /* Demodulator Amplitude Threshold for path A bit 3 */
#define    BM_DMATA3	(uint8_t)(1U<<DMATA3)
#define    DMATA4          4       /* Demodulator Amplitude Threshold for path A bit 4 */
#define    BM_DMATA4	(uint8_t)(1U<<DMATA4)
#define    DMPA            5       /* Demodulator Data Polarity Selection for path A */
#define    BM_DMPA	(uint8_t)(1U<<DMPA)
#define    DMHA            6       /* Demodulator Hold Mode for path A */
#define    BM_DMHA	(uint8_t)(1U<<DMHA)
#define    DMNEA           7       /* Demodulator NRZ Enable for path A */
#define    BM_DMNEA	(uint8_t)(1U<<DMNEA)

/* DMMB - Demodulator Mode for Path B */
#define    DMATB0          0       /* Demodulator Amplitude Threshold for path B bit 0 */
#define    BM_DMATB0	(uint8_t)(1U<<DMATB0)
#define    DMATB1          1       /* Demodulator Amplitude Threshold for path B bit 1 */
#define    BM_DMATB1	(uint8_t)(1U<<DMATB1)
#define    DMATB2          2       /* Demodulator Amplitude Threshold for path B bit 2 */
#define    BM_DMATB2	(uint8_t)(1U<<DMATB2)
#define    DMATB3          3       /* Demodulator Amplitude Threshold for path B bit 3 */
#define    BM_DMATB3	(uint8_t)(1U<<DMATB3)
#define    DMATB4          4       /* Demodulator Amplitude Threshold for path B bit 4 */
#define    BM_DMATB4	(uint8_t)(1U<<DMATB4)
#define    DMPB            5       /* Demodulator Data Polarity Selection for path B */
#define    BM_DMPB	(uint8_t)(1U<<DMPB)
#define    DMHB            6       /* Demodulator Hold Mode for path B */
#define    BM_DMHB	(uint8_t)(1U<<DMHB)
#define    DMNEB           7       /* Demodulator NRZ Enable for path B */
#define    BM_DMNEB	(uint8_t)(1U<<DMNEB)

/* RXFOA - Received Frequency Offset vs Intermediate Frequency on path A */
#define    RXFOA0          0       /* Received frequency offset for path A bit 0 */
#define    BM_RXFOA0	(uint8_t)(1U<<RXFOA0)
#define    RXFOA1          1       /* Received frequency offset for path A bit 1 */
#define    BM_RXFOA1	(uint8_t)(1U<<RXFOA1)
#define    RXFOA2          2       /* Received frequency offset for path A bit 2 */
#define    BM_RXFOA2	(uint8_t)(1U<<RXFOA2)
#define    RXFOA3          3       /* Received frequency offset for path A bit 3 */
#define    BM_RXFOA3	(uint8_t)(1U<<RXFOA3)
#define    RXFOA4          4       /* Received frequency offset for path A bit 4 */
#define    BM_RXFOA4	(uint8_t)(1U<<RXFOA4)
#define    RXFOA5          5       /* Received frequency offset for path A bit 5 */
#define    BM_RXFOA5	(uint8_t)(1U<<RXFOA5)
#define    RXFOA6          6       /* Received frequency offset for path A bit 6 */
#define    BM_RXFOA6	(uint8_t)(1U<<RXFOA6)
#define    RXFOA7          7       /* Received frequency offset for path A bit 7 */
#define    BM_RXFOA7	(uint8_t)(1U<<RXFOA7)

/* RXFOB - Received Frequency Offset vs Intermediate Frequency on path B */
#define    RXFOB0          0       /* Received frequency offset for path B bit 0 */
#define    BM_RXFOB0	(uint8_t)(1U<<RXFOB0)
#define    RXFOB1          1       /* Received frequency offset for path B bit 1 */
#define    BM_RXFOB1	(uint8_t)(1U<<RXFOB1)
#define    RXFOB2          2       /* Received frequency offset for path B bit 2 */
#define    BM_RXFOB2	(uint8_t)(1U<<RXFOB2)
#define    RXFOB3          3       /* Received frequency offset for path B bit 3 */
#define    BM_RXFOB3	(uint8_t)(1U<<RXFOB3)
#define    RXFOB4          4       /* Received frequency offset for path B bit 4 */
#define    BM_RXFOB4	(uint8_t)(1U<<RXFOB4)
#define    RXFOB5          5       /* Received frequency offset for path B bit 5 */
#define    BM_RXFOB5	(uint8_t)(1U<<RXFOB5)
#define    RXFOB6          6       /* Received frequency offset for path B bit 6 */
#define    BM_RXFOB6	(uint8_t)(1U<<RXFOB6)
#define    RXFOB7          7       /* Received frequency offset for path B bit 7 */
#define    BM_RXFOB7	(uint8_t)(1U<<RXFOB7)


/* ***** DFIFO ************************ */
/* DFC - Data FIFO Configuration Register */
#define    DFFLC0          0       /* Data FIFO Fill-Level Configuration bit 0 */
#define    BM_DFFLC0	(uint8_t)(1U<<DFFLC0)
#define    DFFLC1          1       /* Data FIFO Fill-Level Configuration bit 1 */
#define    BM_DFFLC1	(uint8_t)(1U<<DFFLC1)
#define    DFFLC2          2       /* Data FIFO Fill-Level Configuration bit 2 */
#define    BM_DFFLC2	(uint8_t)(1U<<DFFLC2)
#define    DFFLC3          3       /* Data FIFO Fill-Level Configuration bit 3 */
#define    BM_DFFLC3	(uint8_t)(1U<<DFFLC3)
#define    DFFLC4          4       /* Data FIFO Fill-Level Configuration bit 4 */
#define    BM_DFFLC4	(uint8_t)(1U<<DFFLC4)
#define    DFFLC5          5       /* Data FIFO Fill-Level Configuration bit 5 */
#define    BM_DFFLC5	(uint8_t)(1U<<DFFLC5)
#define    DFDRA           7       /* Data FIFO Direct Read Access Operational Mode */
#define    BM_DFDRA	(uint8_t)(1U<<DFDRA)

/* DFI - Data FIFO Interrupt Mask Register */
#define    DFFLIM          0       /* Data FIFO Fill-level Interrupt Mask */
#define    BM_DFFLIM	(uint8_t)(1U<<DFFLIM)
#define    DFERIM          1       /* Data FIFO Error Interrupt Mask */
#define    BM_DFERIM	(uint8_t)(1U<<DFERIM)

/* DFL - Data FIFO Fill Level Register */
#define    DFFLS0          0       /* Data FIFO Fill Level Status bit 0 */
#define    BM_DFFLS0	(uint8_t)(1U<<DFFLS0)
#define    DFFLS1          1       /* Data FIFO Fill Level Status bit 1 */
#define    BM_DFFLS1	(uint8_t)(1U<<DFFLS1)
#define    DFFLS2          2       /* Data FIFO Fill Level Status bit 2 */
#define    BM_DFFLS2	(uint8_t)(1U<<DFFLS2)
#define    DFFLS3          3       /* Data FIFO Fill Level Status bit 3 */
#define    BM_DFFLS3	(uint8_t)(1U<<DFFLS3)
#define    DFFLS4          4       /* Data FIFO Fill Level Status bit 4 */
#define    BM_DFFLS4	(uint8_t)(1U<<DFFLS4)
#define    DFFLS5          5       /* Data FIFO Fill Level Status bit 5 */
#define    BM_DFFLS5	(uint8_t)(1U<<DFFLS5)
#define    DFCLR           7       /* Data FIFO Clear */
#define    BM_DFCLR	(uint8_t)(1U<<DFCLR)

/* DFRP - Data FIFO Read Pointer */
#define    DFRP0           0       /* Data FIFO Read Pointer bit 0 */
#define    BM_DFRP0	(uint8_t)(1U<<DFRP0)
#define    DFRP1           1       /* Data FIFO Read Pointer bit 1 */
#define    BM_DFRP1	(uint8_t)(1U<<DFRP1)
#define    DFRP2           2       /* Data FIFO Read Pointer bit 2 */
#define    BM_DFRP2	(uint8_t)(1U<<DFRP2)
#define    DFRP3           3       /* Data FIFO Read Pointer bit 3 */
#define    BM_DFRP3	(uint8_t)(1U<<DFRP3)
#define    DFRP4           4       /* Data FIFO Read Pointer bit 4 */
#define    BM_DFRP4	(uint8_t)(1U<<DFRP4)
#define    DFRP5           5       /* Data FIFO Read Pointer bit 5 */
#define    BM_DFRP5	(uint8_t)(1U<<DFRP5)

/* DFS - Data FIFO Status Register */
#define    DFFLRF          0       /* Data FIFO Fill-Level Reached Status Flag */
#define    BM_DFFLRF	(uint8_t)(1U<<DFFLRF)
#define    DFUFL           1       /* Data FIFO Underflow Flag */
#define    BM_DFUFL	(uint8_t)(1U<<DFUFL)
#define    DFOFL           2       /* Data FIFO Overflow Flag */
#define    BM_DFOFL	(uint8_t)(1U<<DFOFL)

/* DFTLH - Data FIFO Telegram Length High Byte */
#define    DFTLH0          0       /* Data FIFO Telegram Length High Byte bit 0 */
#define    BM_DFTLH0	(uint8_t)(1U<<DFTLH0)
#define    DFTLH1          1       /* Data FIFO Telegram Length High Byte bit 1 */
#define    BM_DFTLH1	(uint8_t)(1U<<DFTLH1)
#define    DFTLH2          2       /* Data FIFO Telegram Length High Byte bit 2 */
#define    BM_DFTLH2	(uint8_t)(1U<<DFTLH2)
#define    DFTLH3          3       /* Data FIFO Telegram Length High Byte bit 3 */
#define    BM_DFTLH3	(uint8_t)(1U<<DFTLH3)

/* DFTLL - Data FIFO Telegram Length Low Byte */
#define    DFTLL0          0       /* Data FIFO Telegram Length Low Byte bit 0 */
#define    BM_DFTLL0	(uint8_t)(1U<<DFTLL0)
#define    DFTLL1          1       /* Data FIFO Telegram Length Low Byte bit 1 */
#define    BM_DFTLL1	(uint8_t)(1U<<DFTLL1)
#define    DFTLL2          2       /* Data FIFO Telegram Length Low Byte bit 2 */
#define    BM_DFTLL2	(uint8_t)(1U<<DFTLL2)
#define    DFTLL3          3       /* Data FIFO Telegram Length Low Byte bit 3 */
#define    BM_DFTLL3	(uint8_t)(1U<<DFTLL3)
#define    DFTLL4          4       /* Data FIFO Telegram Length Low Byte bit 4 */
#define    BM_DFTLL4	(uint8_t)(1U<<DFTLL4)
#define    DFTLL5          5       /* Data FIFO Telegram Length Low Byte bit 5 */
#define    BM_DFTLL5	(uint8_t)(1U<<DFTLL5)
#define    DFTLL6          6       /* Data FIFO Telegram Length Low Byte bit 6 */
#define    BM_DFTLL6	(uint8_t)(1U<<DFTLL6)
#define    DFTLL7          7       /* Data FIFO Telegram Length Low Byte bit 7 */
#define    BM_DFTLL7	(uint8_t)(1U<<DFTLL7)

/* DFWP - Data FIFO Write Pointer */
#define    DFWP0           0       /* Data FIFO Write Pointer bit 0 */
#define    BM_DFWP0	(uint8_t)(1U<<DFWP0)
#define    DFWP1           1       /* Data FIFO Write Pointer bit 1 */
#define    BM_DFWP1	(uint8_t)(1U<<DFWP1)
#define    DFWP2           2       /* Data FIFO Write Pointer bit 2 */
#define    BM_DFWP2	(uint8_t)(1U<<DFWP2)
#define    DFWP3           3       /* Data FIFO Write Pointer bit 3 */
#define    BM_DFWP3	(uint8_t)(1U<<DFWP3)
#define    DFWP4           4       /* Data FIFO Write Pointer bit 4 */
#define    BM_DFWP4	(uint8_t)(1U<<DFWP4)
#define    DFWP5           5       /* Data FIFO Write Pointer bit 5 */
#define    BM_DFWP5	(uint8_t)(1U<<DFWP5)


/* ***** EEPROM *********************** */
/* EEARH - EEPROM Address Register High Byte */
#define    EEAR8           0       /* EEPROM Read/Write Address bit 8 */
#define    BM_EEAR8	(uint8_t)(1U<<EEAR8)
#define    EEAR9           1       /* EEPROM Read/Write Address bit 9 */
#define    BM_EEAR9	(uint8_t)(1U<<EEAR9)
#define    EEAR10          2       /* EEPROM Read/Write Address bit 10 */
#define    BM_EEAR10	(uint8_t)(1U<<EEAR10)

/* EEARL - EEPROM Address Register Low Byte */
#define    EEAR0           0       /* EEPROM Read/Write Address bit 0 */
#define    BM_EEAR0	(uint8_t)(1U<<EEAR0)
#define    EEAR1           1       /* EEPROM Read/Write Address bit 1 */
#define    BM_EEAR1	(uint8_t)(1U<<EEAR1)
#define    EEAR2           2       /* EEPROM Read/Write Address bit 2 */
#define    BM_EEAR2	(uint8_t)(1U<<EEAR2)
#define    EEAR3           3       /* EEPROM Read/Write Address bit 3 */
#define    BM_EEAR3	(uint8_t)(1U<<EEAR3)
#define    EEAR4           4       /* EEPROM Read/Write Address bit 4 */
#define    BM_EEAR4	(uint8_t)(1U<<EEAR4)
#define    EEAR5           5       /* EEPROM Read/Write Address bit 5 */
#define    BM_EEAR5	(uint8_t)(1U<<EEAR5)
#define    EEAR6           6       /* EEPROM Read/Write Address bit 6 */
#define    BM_EEAR6	(uint8_t)(1U<<EEAR6)
#define    EEAR7           7       /* EEPROM Read/Write Address bit 7 */
#define    BM_EEAR7	(uint8_t)(1U<<EEAR7)

/* EECR - EEPROM Control Register */
#define    EERE            0       /* EEPROM Read Enable */
#define    BM_EERE	(uint8_t)(1U<<EERE)
#define    EEWE            1       /* EEPROM Write Enable */
#define    BM_EEWE	(uint8_t)(1U<<EEWE)
#define    EEMWE           2       /* EEPROM Master Write Enable */
#define    BM_EEMWE	(uint8_t)(1U<<EEMWE)
#define    EERIE           3       /* EEPROM Ready Interrupt Enable */
#define    BM_EERIE	(uint8_t)(1U<<EERIE)
#define    EEPM0           4       /* EEPROM Programming Mode bit 0 */
#define    BM_EEPM0	(uint8_t)(1U<<EEPM0)
#define    EEPM1           5       /* EEPROM Programming Mode bit 1 */
#define    BM_EEPM1	(uint8_t)(1U<<EEPM1)
#define    EEPAGE          6       /* EEPROM page access (multiple bytes access mode) */
#define    BM_EEPAGE	(uint8_t)(1U<<EEPAGE)
#define    NVMBSY          7       /* Non-volatile memory busy */
#define    BM_NVMBSY	(uint8_t)(1U<<NVMBSY)

/* EECR2 - EEPROM Control Register 2 */
#define    EEBRE           0       /* EEPROM Burst Read Enable */
#define    BM_EEBRE	(uint8_t)(1U<<EEBRE)

/* EEPR - EEPROM Protection Register */
#define    EEAP0           0       /* EEPROM Access Protection bit 0 */
#define    BM_EEAP0	(uint8_t)(1U<<EEAP0)
#define    EEAP1           1       /* EEPROM Access Protection bit 1 */
#define    BM_EEAP1	(uint8_t)(1U<<EEAP1)
#define    EEAP2           2       /* EEPROM Access Protection bit 2 */
#define    BM_EEAP2	(uint8_t)(1U<<EEAP2)
#define    EEAP3           3       /* EEPROM Access Protection bit 3 */
#define    BM_EEAP3	(uint8_t)(1U<<EEAP3)


/* ***** FE *************************** */
/* FEALR - Front-End Antenna Level Detector Range */
#define    RNGE0           0       /* Range of the ANT_TUNE level detector bit 0 */
#define    BM_RNGE0	(uint8_t)(1U<<RNGE0)
#define    RNGE1           1       /* Range of the ANT_TUNE level detector bit 1 */
#define    BM_RNGE1	(uint8_t)(1U<<RNGE1)

/* FEANT - Front-End ANTenna */
#define    LVLC0           0       /* antenna signal LeVeL bit 0 */
#define    BM_LVLC0	(uint8_t)(1U<<LVLC0)
#define    LVLC1           1       /* antenna signal LeVeL bit 1 */
#define    BM_LVLC1	(uint8_t)(1U<<LVLC1)
#define    LVLC2           2       /* antenna signal LeVeL bit 2 */
#define    BM_LVLC2	(uint8_t)(1U<<LVLC2)
#define    LVLC3           3       /* antenna signal LeVeL bit 3 */
#define    BM_LVLC3	(uint8_t)(1U<<LVLC3)

/* FEAT - Front-End Antenna Tuning */
#define    ANTN0           0       /* Antenna Tuning bit 0 */
#define    BM_ANTN0	(uint8_t)(1U<<ANTN0)
#define    ANTN1           1       /* Antenna Tuning bit 1 */
#define    BM_ANTN1	(uint8_t)(1U<<ANTN1)
#define    ANTN2           2       /* Antenna Tuning bit 2 */
#define    BM_ANTN2	(uint8_t)(1U<<ANTN2)
#define    ANTN3           3       /* Antenna Tuning bit 3 */
#define    BM_ANTN3	(uint8_t)(1U<<ANTN3)

/* FEBIA - Front-End IF Amplifier BIAS */
#define    IFAEN           7       /* IF Amplifier Enable */
#define    BM_IFAEN	(uint8_t)(1U<<IFAEN)

/* FEBT - Front-End RC Tuning Register */
#define    CTN20           0       /* Capacitor Tuning bit 0 */
#define    BM_CTN20	(uint8_t)(1U<<CTN20)
#define    CTN21           1       /* Capacitor Tuning bit 1 */
#define    BM_CTN21	(uint8_t)(1U<<CTN21)
#define    RTN20           2       /* Resistor Tuning bit 0 */
#define    BM_RTN20	(uint8_t)(1U<<RTN20)
#define    RTN21           3       /* Resistor Tuning bit 1 */
#define    BM_RTN21	(uint8_t)(1U<<RTN21)

/* FECR - Front-End Control Register */
#define    LBNHB           0       /* Select Low-Band Not High-Band */
#define    BM_LBNHB	(uint8_t)(1U<<LBNHB)
#define    S4N3            1       /* Select 433 Not 315MHz Band */
#define    BM_S4N3	(uint8_t)(1U<<S4N3)
#define    ANDP            2       /* Antenna Damping */
#define    BM_ANDP	(uint8_t)(1U<<ANDP)
#define    ADHS            3       /* ADC High Sample Rate */
#define    BM_ADHS	(uint8_t)(1U<<ADHS)
#define    PLCKG           4       /* PLL Lock Detect Gate */
#define    BM_PLCKG	(uint8_t)(1U<<PLCKG)
#define    ANPS            5       /* ASK Not DPSK Switch */
#define    BM_ANPS	(uint8_t)(1U<<ANPS)

/* FEEN1 - Front-End Enable Register 1 */
#define    PLEN            0       /* PLL enable */
#define    BM_PLEN	(uint8_t)(1U<<PLEN)
#define    PLCAL           1       /* PLL calibration mode */
#define    BM_PLCAL	(uint8_t)(1U<<PLCAL)
#define    XTOEN           2       /* Cristal Oscillator enable */
#define    BM_XTOEN	(uint8_t)(1U<<XTOEN)
#define    LNAEN           3       /* Low Noise Amplifier enable */
#define    BM_LNAEN	(uint8_t)(1U<<LNAEN)
#define    ADEN            4       /* Analog Digital Converter enable */
#define    BM_ADEN	(uint8_t)(1U<<ADEN)
#define    ADCLK           5       /* ADC Clock enable */
#define    BM_ADCLK	(uint8_t)(1U<<ADCLK)
#define    PLSP1           6       /* PLL Speedup 1 */
#define    BM_PLSP1	(uint8_t)(1U<<PLSP1)
#define    ATEN            7       /* Antenna Tuning Enable */
#define    BM_ATEN	(uint8_t)(1U<<ATEN)

/* FEEN2 - Front-End Enable Register 2 */
#define    SDRX            0       /* Single Pole Double Throw (SPDT) Switch RX */
#define    BM_SDRX	(uint8_t)(1U<<SDRX)
#define    SDTX            1       /* Single Pole Double Throw (SPDT) Switch TX */
#define    BM_SDTX	(uint8_t)(1U<<SDTX)
#define    PAEN            2       /* Power Amplifier enable */
#define    BM_PAEN	(uint8_t)(1U<<PAEN)
#define    TMPM            3       /* Temperature measurement */
#define    BM_TMPM	(uint8_t)(1U<<TMPM)
#define    PLPEN           4       /* PLL Post En IQ divider */
#define    BM_PLPEN	(uint8_t)(1U<<PLPEN)
#define    XTPEN           5       /* XTO VPump enable */
#define    BM_XTPEN	(uint8_t)(1U<<XTPEN)
#define    CPBIA           6       /* Cap Array Bias */
#define    BM_CPBIA	(uint8_t)(1U<<CPBIA)

/* FELNA - Front-End LNA Bias Register */
#define    LBH0            0       /* LNA Bias High band bit 0 */
#define    BM_LBH0	(uint8_t)(1U<<LBH0)
#define    LBH1            1       /* LNA Bias High band bit 1 */
#define    BM_LBH1	(uint8_t)(1U<<LBH1)
#define    LBH2            2       /* LNA Bias High band bit 2 */
#define    BM_LBH2	(uint8_t)(1U<<LBH2)
#define    LBH3            3       /* LNA Bias High band bit 3 */
#define    BM_LBH3	(uint8_t)(1U<<LBH3)
#define    LBL0            4       /* LNA Bias Low band bit 0 */
#define    BM_LBL0	(uint8_t)(1U<<LBL0)
#define    LBL1            5       /* LNA Bias Low band bit 1 */
#define    BM_LBL1	(uint8_t)(1U<<LBL1)
#define    LBL2            6       /* LNA Bias Low band bit 2 */
#define    BM_LBL2	(uint8_t)(1U<<LBL2)
#define    LBL3            7       /* LNA Bias Low band bit 3 */
#define    BM_LBL3	(uint8_t)(1U<<LBL3)

/* FEMS - Front-End Main and Swallow Control Register */
#define    PLLS0           0       /* PLL Swallow bit 0 */
#define    BM_PLLS0	(uint8_t)(1U<<PLLS0)
#define    PLLS1           1       /* PLL Swallow bit 1 */
#define    BM_PLLS1	(uint8_t)(1U<<PLLS1)
#define    PLLS2           2       /* PLL Swallow bit 2 */
#define    BM_PLLS2	(uint8_t)(1U<<PLLS2)
#define    PLLS3           3       /* PLL Swallow bit 3 */
#define    BM_PLLS3	(uint8_t)(1U<<PLLS3)
#define    PLLM0           4       /* PLL Mode bit 0 */
#define    BM_PLLM0	(uint8_t)(1U<<PLLM0)
#define    PLLM1           5       /* PLL Mode bit 1 */
#define    BM_PLLM1	(uint8_t)(1U<<PLLM1)
#define    PLLM2           6       /* PLL Mode bit 2 */
#define    BM_PLLM2	(uint8_t)(1U<<PLLM2)
#define    PLLM3           7       /* PLL Mode bit 3 */
#define    BM_PLLM3	(uint8_t)(1U<<PLLM3)

/* FEPAC - Front-End Power Amplifier Control Register */
#define    PACR0           0       /* Power Amplifier Control Register bit 0 */
#define    BM_PACR0	(uint8_t)(1U<<PACR0)
#define    PACR1           1       /* Power Amplifier Control Register bit 1 */
#define    BM_PACR1	(uint8_t)(1U<<PACR1)
#define    PACR2           2       /* Power Amplifier Control Register bit 2 */
#define    BM_PACR2	(uint8_t)(1U<<PACR2)
#define    PACR3           3       /* Power Amplifier Control Register bit 3 */
#define    BM_PACR3	(uint8_t)(1U<<PACR3)
#define    PACR4           4       /* Power Amplifier Control Register bit 4 */
#define    BM_PACR4	(uint8_t)(1U<<PACR4)
#define    PACR5           5       /* Power Amplifier Control Register bit 5 */
#define    BM_PACR5	(uint8_t)(1U<<PACR5)
#define    PACR6           6       /* Power Amplifier Control Register bit 6 */
#define    BM_PACR6	(uint8_t)(1U<<PACR6)
#define    PACR7           7       /* Power Amplifier Control Register bit 7 */
#define    BM_PACR7	(uint8_t)(1U<<PACR7)

/* FESR - Front-End Status Register */
#define    LBSAT           0       /* LNA Low band saturated */
#define    BM_LBSAT	(uint8_t)(1U<<LBSAT)
#define    HBSAT           1       /* LNA High band saturated */
#define    BM_HBSAT	(uint8_t)(1U<<HBSAT)
#define    XRDY            2       /* XTO ready */
#define    BM_XRDY	(uint8_t)(1U<<XRDY)
#define    PLCK            3       /* PLL locked */
#define    BM_PLCK	(uint8_t)(1U<<PLCK)
#define    ANTS            4       /* Antenna saturated */
#define    BM_ANTS	(uint8_t)(1U<<ANTS)

/* FETN4 - Front-End RC Tuning 4bit Register */
#define    CTN40           0       /* 4 bit Capacitor Tuning bit 0 */
#define    BM_CTN40	(uint8_t)(1U<<CTN40)
#define    CTN41           1       /* 4 bit Capacitor Tuning bit 1 */
#define    BM_CTN41	(uint8_t)(1U<<CTN41)
#define    CTN42           2       /* 4 bit Capacitor Tuning bit 2 */
#define    BM_CTN42	(uint8_t)(1U<<CTN42)
#define    CTN43           3       /* 4 bit Capacitor Tuning bit 3 */
#define    BM_CTN43	(uint8_t)(1U<<CTN43)
#define    RTN40           4       /* 4 bit Resistor Tuning bit 0 */
#define    BM_RTN40	(uint8_t)(1U<<RTN40)
#define    RTN41           5       /* 4 bit Resistor Tuning bit 1 */
#define    BM_RTN41	(uint8_t)(1U<<RTN41)
#define    RTN42           6       /* 4 bit Resistor Tuning bit 2 */
#define    BM_RTN42	(uint8_t)(1U<<RTN42)
#define    RTN43           7       /* 4 bit Resistor Tuning bit 3 */
#define    BM_RTN43	(uint8_t)(1U<<RTN43)

/* FEVCO - Front-End VCO and PLL control */
#define    CPCC0           0       /* Charge pump current control bit 0 */
#define    BM_CPCC0	(uint8_t)(1U<<CPCC0)
#define    CPCC1           1       /* Charge pump current control bit 1 */
#define    BM_CPCC1	(uint8_t)(1U<<CPCC1)
#define    CPCC2           2       /* Charge pump current control bit 2 */
#define    BM_CPCC2	(uint8_t)(1U<<CPCC2)
#define    CPCC3           3       /* Charge pump current control bit 3 */
#define    BM_CPCC3	(uint8_t)(1U<<CPCC3)
#define    VCOB0           4       /* VCO Bias bit 0 */
#define    BM_VCOB0	(uint8_t)(1U<<VCOB0)
#define    VCOB1           5       /* VCO Bias bit 1 */
#define    BM_VCOB1	(uint8_t)(1U<<VCOB1)
#define    VCOB2           6       /* VCO Bias bit 2 */
#define    BM_VCOB2	(uint8_t)(1U<<VCOB2)
#define    VCOB3           7       /* VCO Bias bit 3 */
#define    BM_VCOB3	(uint8_t)(1U<<VCOB3)

/* FEVCT - Front-End VCO Tuning Register */
#define    FEVCT0          0       /* Front-End VCO Tuning Register bit 0 */
#define    BM_FEVCT0	(uint8_t)(1U<<FEVCT0)
#define    FEVCT1          1       /* Front-End VCO Tuning Register bit 1 */
#define    BM_FEVCT1	(uint8_t)(1U<<FEVCT1)
#define    FEVCT2          2       /* Front-End VCO Tuning Register bit 2 */
#define    BM_FEVCT2	(uint8_t)(1U<<FEVCT2)
#define    FEVCT3          3       /* Front-End VCO Tuning Register bit 3 */
#define    BM_FEVCT3	(uint8_t)(1U<<FEVCT3)


/* ***** FRSYNC *********************** */
/* SFID1A - Start-Frame ID byte 1 for data path A */
#define    SFID1A0         0       /* Start-Frame ID byte 1 for data path A bit 0 */
#define    BM_SFID1A0	(uint8_t)(1U<<SFID1A0)
#define    SFID1A1         1       /* Start-Frame ID byte 1 for data path A bit 1 */
#define    BM_SFID1A1	(uint8_t)(1U<<SFID1A1)
#define    SFID1A2         2       /* Start-Frame ID byte 1 for data path A bit 2 */
#define    BM_SFID1A2	(uint8_t)(1U<<SFID1A2)
#define    SFID1A3         3       /* Start-Frame ID byte 1 for data path A bit 3 */
#define    BM_SFID1A3	(uint8_t)(1U<<SFID1A3)
#define    SFID1A4         4       /* Start-Frame ID byte 1 for data path A bit 4 */
#define    BM_SFID1A4	(uint8_t)(1U<<SFID1A4)
#define    SFID1A5         5       /* Start-Frame ID byte 1 for data path A bit 5 */
#define    BM_SFID1A5	(uint8_t)(1U<<SFID1A5)
#define    SFID1A6         6       /* Start-Frame ID byte 1 for data path A bit 6 */
#define    BM_SFID1A6	(uint8_t)(1U<<SFID1A6)
#define    SFID1A7         7       /* Start-Frame ID byte 1 for data path A bit 7 */
#define    BM_SFID1A7	(uint8_t)(1U<<SFID1A7)

/* SFID1B - Start-Frame ID byte 1 for data path B */
#define    SFID1B0         0       /* Start-Frame ID byte 1 for data path B bit 0 */
#define    BM_SFID1B0	(uint8_t)(1U<<SFID1B0)
#define    SFID1B1         1       /* Start-Frame ID byte 1 for data path B bit 1 */
#define    BM_SFID1B1	(uint8_t)(1U<<SFID1B1)
#define    SFID1B2         2       /* Start-Frame ID byte 1 for data path B bit 2 */
#define    BM_SFID1B2	(uint8_t)(1U<<SFID1B2)
#define    SFID1B3         3       /* Start-Frame ID byte 1 for data path B bit 3 */
#define    BM_SFID1B3	(uint8_t)(1U<<SFID1B3)
#define    SFID1B4         4       /* Start-Frame ID byte 1 for data path B bit 4 */
#define    BM_SFID1B4	(uint8_t)(1U<<SFID1B4)
#define    SFID1B5         5       /* Start-Frame ID byte 1 for data path B bit 5 */
#define    BM_SFID1B5	(uint8_t)(1U<<SFID1B5)
#define    SFID1B6         6       /* Start-Frame ID byte 1 for data path B bit 6 */
#define    BM_SFID1B6	(uint8_t)(1U<<SFID1B6)
#define    SFID1B7         7       /* Start-Frame ID byte 1 for data path B bit 7 */
#define    BM_SFID1B7	(uint8_t)(1U<<SFID1B7)

/* SFID2A - Start-Frame ID byte 2 for data path A */
#define    SFID2A0         0       /* Start-Frame ID byte 2 for data path A bit 0 */
#define    BM_SFID2A0	(uint8_t)(1U<<SFID2A0)
#define    SFID2A1         1       /* Start-Frame ID byte 2 for data path A bit 1 */
#define    BM_SFID2A1	(uint8_t)(1U<<SFID2A1)
#define    SFID2A2         2       /* Start-Frame ID byte 2 for data path A bit 2 */
#define    BM_SFID2A2	(uint8_t)(1U<<SFID2A2)
#define    SFID2A3         3       /* Start-Frame ID byte 2 for data path A bit 3 */
#define    BM_SFID2A3	(uint8_t)(1U<<SFID2A3)
#define    SFID2A4         4       /* Start-Frame ID byte 2 for data path A bit 4 */
#define    BM_SFID2A4	(uint8_t)(1U<<SFID2A4)
#define    SFID2A5         5       /* Start-Frame ID byte 2 for data path A bit 5 */
#define    BM_SFID2A5	(uint8_t)(1U<<SFID2A5)
#define    SFID2A6         6       /* Start-Frame ID byte 2 for data path A bit 6 */
#define    BM_SFID2A6	(uint8_t)(1U<<SFID2A6)
#define    SFID2A7         7       /* Start-Frame ID byte 2 for data path A bit 7 */
#define    BM_SFID2A7	(uint8_t)(1U<<SFID2A7)

/* SFID2B - Start-Frame ID byte 2 for data path B */
#define    SFID2B0         0       /* Start-Frame ID byte 2 for data path B bit 0 */
#define    BM_SFID2B0	(uint8_t)(1U<<SFID2B0)
#define    SFID2B1         1       /* Start-Frame ID byte 2 for data path B bit 1 */
#define    BM_SFID2B1	(uint8_t)(1U<<SFID2B1)
#define    SFID2B2         2       /* Start-Frame ID byte 2 for data path B bit 2 */
#define    BM_SFID2B2	(uint8_t)(1U<<SFID2B2)
#define    SFID2B3         3       /* Start-Frame ID byte 2 for data path B bit 3 */
#define    BM_SFID2B3	(uint8_t)(1U<<SFID2B3)
#define    SFID2B4         4       /* Start-Frame ID byte 2 for data path B bit 4 */
#define    BM_SFID2B4	(uint8_t)(1U<<SFID2B4)
#define    SFID2B5         5       /* Start-Frame ID byte 2 for data path B bit 5 */
#define    BM_SFID2B5	(uint8_t)(1U<<SFID2B5)
#define    SFID2B6         6       /* Start-Frame ID byte 2 for data path B bit 6 */
#define    BM_SFID2B6	(uint8_t)(1U<<SFID2B6)
#define    SFID2B7         7       /* Start-Frame ID byte 2 for data path B bit 7 */
#define    BM_SFID2B7	(uint8_t)(1U<<SFID2B7)

/* SFID3A - Start-Frame ID byte 3 for data path A */
#define    SFID3A0         0       /* Start-Frame ID byte 3 for data path A bit 0 */
#define    BM_SFID3A0	(uint8_t)(1U<<SFID3A0)
#define    SFID3A1         1       /* Start-Frame ID byte 3 for data path A bit 1 */
#define    BM_SFID3A1	(uint8_t)(1U<<SFID3A1)
#define    SFID3A2         2       /* Start-Frame ID byte 3 for data path A bit 2 */
#define    BM_SFID3A2	(uint8_t)(1U<<SFID3A2)
#define    SFID3A3         3       /* Start-Frame ID byte 3 for data path A bit 3 */
#define    BM_SFID3A3	(uint8_t)(1U<<SFID3A3)
#define    SFID3A4         4       /* Start-Frame ID byte 3 for data path A bit 4 */
#define    BM_SFID3A4	(uint8_t)(1U<<SFID3A4)
#define    SFID3A5         5       /* Start-Frame ID byte 3 for data path A bit 5 */
#define    BM_SFID3A5	(uint8_t)(1U<<SFID3A5)
#define    SFID3A6         6       /* Start-Frame ID byte 3 for data path A bit 6 */
#define    BM_SFID3A6	(uint8_t)(1U<<SFID3A6)
#define    SFID3A7         7       /* Start-Frame ID byte 3 for data path A bit 7 */
#define    BM_SFID3A7	(uint8_t)(1U<<SFID3A7)

/* SFID3B - Start-Frame ID byte 3 for data path B */
#define    SFID3B0         0       /* Start-Frame ID byte 3 for data path B bit 0 */
#define    BM_SFID3B0	(uint8_t)(1U<<SFID3B0)
#define    SFID3B1         1       /* Start-Frame ID byte 3 for data path B bit 1 */
#define    BM_SFID3B1	(uint8_t)(1U<<SFID3B1)
#define    SFID3B2         2       /* Start-Frame ID byte 3 for data path B bit 2 */
#define    BM_SFID3B2	(uint8_t)(1U<<SFID3B2)
#define    SFID3B3         3       /* Start-Frame ID byte 3 for data path B bit 3 */
#define    BM_SFID3B3	(uint8_t)(1U<<SFID3B3)
#define    SFID3B4         4       /* Start-Frame ID byte 3 for data path B bit 4 */
#define    BM_SFID3B4	(uint8_t)(1U<<SFID3B4)
#define    SFID3B5         5       /* Start-Frame ID byte 3 for data path B bit 5 */
#define    BM_SFID3B5	(uint8_t)(1U<<SFID3B5)
#define    SFID3B6         6       /* Start-Frame ID byte 3 for data path B bit 6 */
#define    BM_SFID3B6	(uint8_t)(1U<<SFID3B6)
#define    SFID3B7         7       /* Start-Frame ID byte 3 for data path B bit 7 */
#define    BM_SFID3B7	(uint8_t)(1U<<SFID3B7)

/* SFID4A - Start-Frame ID byte 4 for data path A */
#define    SFID4A0         0       /* Start-Frame ID byte 4 for data path A bit 0 */
#define    BM_SFID4A0	(uint8_t)(1U<<SFID4A0)
#define    SFID4A1         1       /* Start-Frame ID byte 4 for data path A bit 1 */
#define    BM_SFID4A1	(uint8_t)(1U<<SFID4A1)
#define    SFID4A2         2       /* Start-Frame ID byte 4 for data path A bit 2 */
#define    BM_SFID4A2	(uint8_t)(1U<<SFID4A2)
#define    SFID4A3         3       /* Start-Frame ID byte 4 for data path A bit 3 */
#define    BM_SFID4A3	(uint8_t)(1U<<SFID4A3)
#define    SFID4A4         4       /* Start-Frame ID byte 4 for data path A bit 4 */
#define    BM_SFID4A4	(uint8_t)(1U<<SFID4A4)
#define    SFID4A5         5       /* Start-Frame ID byte 4 for data path A bit 5 */
#define    BM_SFID4A5	(uint8_t)(1U<<SFID4A5)
#define    SFID4A6         6       /* Start-Frame ID byte 4 for data path A bit 6 */
#define    BM_SFID4A6	(uint8_t)(1U<<SFID4A6)
#define    SFID4A7         7       /* Start-Frame ID byte 4 for data path A bit 7 */
#define    BM_SFID4A7	(uint8_t)(1U<<SFID4A7)

/* SFID4B - Start-Frame ID byte 4 for data path B */
#define    SFID4B0         0       /* Start-Frame ID byte 4 for data path B bit 0 */
#define    BM_SFID4B0	(uint8_t)(1U<<SFID4B0)
#define    SFID4B1         1       /* Start-Frame ID byte 4 for data path B bit 1 */
#define    BM_SFID4B1	(uint8_t)(1U<<SFID4B1)
#define    SFID4B2         2       /* Start-Frame ID byte 4 for data path B bit 2 */
#define    BM_SFID4B2	(uint8_t)(1U<<SFID4B2)
#define    SFID4B3         3       /* Start-Frame ID byte 4 for data path B bit 3 */
#define    BM_SFID4B3	(uint8_t)(1U<<SFID4B3)
#define    SFID4B4         4       /* Start-Frame ID byte 4 for data path B bit 4 */
#define    BM_SFID4B4	(uint8_t)(1U<<SFID4B4)
#define    SFID4B5         5       /* Start-Frame ID byte 4 for data path B bit 5 */
#define    BM_SFID4B5	(uint8_t)(1U<<SFID4B5)
#define    SFID4B6         6       /* Start-Frame ID byte 4 for data path B bit 6 */
#define    BM_SFID4B6	(uint8_t)(1U<<SFID4B6)
#define    SFID4B7         7       /* Start-Frame ID byte 4 for data path B bit 7 */
#define    BM_SFID4B7	(uint8_t)(1U<<SFID4B7)

/* SFIDCA - Start-Frame ID Control for data path A */
#define    SFIDTA0         0       /* Start-Frame ID threshold for data path A bit 0 */
#define    BM_SFIDTA0	(uint8_t)(1U<<SFIDTA0)
#define    SFIDTA1         1       /* Start-Frame ID threshold for data path A bit 1 */
#define    BM_SFIDTA1	(uint8_t)(1U<<SFIDTA1)
#define    SFIDTA2         2       /* Start-Frame ID threshold for data path A bit 2 */
#define    BM_SFIDTA2	(uint8_t)(1U<<SFIDTA2)
#define    SFIDTA3         3       /* Start-Frame ID threshold for data path A bit 3 */
#define    BM_SFIDTA3	(uint8_t)(1U<<SFIDTA3)
#define    SFIDTA4         4       /* Start-Frame ID threshold for data path A bit 4 */
#define    BM_SFIDTA4	(uint8_t)(1U<<SFIDTA4)
#define    SEMEA           7       /* Serial mode enable for data path A */
#define    BM_SEMEA	(uint8_t)(1U<<SEMEA)

/* SFIDCB - Start-Frame ID Control for data path B */
#define    SFIDTB0         0       /* Start-Frame ID threshold for data path B bit 0 */
#define    BM_SFIDTB0	(uint8_t)(1U<<SFIDTB0)
#define    SFIDTB1         1       /* Start-Frame ID threshold for data path B bit 1 */
#define    BM_SFIDTB1	(uint8_t)(1U<<SFIDTB1)
#define    SFIDTB2         2       /* Start-Frame ID threshold for data path B bit 2 */
#define    BM_SFIDTB2	(uint8_t)(1U<<SFIDTB2)
#define    SFIDTB3         3       /* Start-Frame ID threshold for data path B bit 3 */
#define    BM_SFIDTB3	(uint8_t)(1U<<SFIDTB3)
#define    SFIDTB4         4       /* Start-Frame ID threshold for data path B bit 4 */
#define    BM_SFIDTB4	(uint8_t)(1U<<SFIDTB4)
#define    SEMEB           7       /* Serial mode enable for data path B */
#define    BM_SEMEB	(uint8_t)(1U<<SEMEB)

/* SFIDLA - Start-Frame ID Length for data path A */
#define    SFIDLA0         0       /* Start-Frame ID Length for data path A bit 0 */
#define    BM_SFIDLA0	(uint8_t)(1U<<SFIDLA0)
#define    SFIDLA1         1       /* Start-Frame ID Length for data path A bit 1 */
#define    BM_SFIDLA1	(uint8_t)(1U<<SFIDLA1)
#define    SFIDLA2         2       /* Start-Frame ID Length for data path A bit 2 */
#define    BM_SFIDLA2	(uint8_t)(1U<<SFIDLA2)
#define    SFIDLA3         3       /* Start-Frame ID Length for data path A bit 3 */
#define    BM_SFIDLA3	(uint8_t)(1U<<SFIDLA3)
#define    SFIDLA4         4       /* Start-Frame ID Length for data path A bit 4 */
#define    BM_SFIDLA4	(uint8_t)(1U<<SFIDLA4)
#define    SFIDLA5         5       /* Start-Frame ID Length for data path A bit 5 */
#define    BM_SFIDLA5	(uint8_t)(1U<<SFIDLA5)

/* SFIDLB - Start-Frame ID Length for data path B */
#define    SFIDLB0         0       /* Start-Frame ID Length for data path B bit 0 */
#define    BM_SFIDLB0	(uint8_t)(1U<<SFIDLB0)
#define    SFIDLB1         1       /* Start-Frame ID Length for data path B bit 1 */
#define    BM_SFIDLB1	(uint8_t)(1U<<SFIDLB1)
#define    SFIDLB2         2       /* Start-Frame ID Length for data path B bit 2 */
#define    BM_SFIDLB2	(uint8_t)(1U<<SFIDLB2)
#define    SFIDLB3         3       /* Start-Frame ID Length for data path B bit 3 */
#define    BM_SFIDLB3	(uint8_t)(1U<<SFIDLB3)
#define    SFIDLB4         4       /* Start-Frame ID Length for data path B bit 4 */
#define    BM_SFIDLB4	(uint8_t)(1U<<SFIDLB4)
#define    SFIDLB5         5       /* Start-Frame ID Length for data path B bit 5 */
#define    BM_SFIDLB5	(uint8_t)(1U<<SFIDLB5)

/* WUP1A - Wake-Up Pattern byte 1 for data path A */
#define    WUP1A0          0       /* Wake-Up Pattern byte 1 for data path A bit 0 */
#define    BM_WUP1A0	(uint8_t)(1U<<WUP1A0)
#define    WUP1A1          1       /* Wake-Up Pattern byte 1 for data path A bit 1 */
#define    BM_WUP1A1	(uint8_t)(1U<<WUP1A1)
#define    WUP1A2          2       /* Wake-Up Pattern byte 1 for data path A bit 2 */
#define    BM_WUP1A2	(uint8_t)(1U<<WUP1A2)
#define    WUP1A3          3       /* Wake-Up Pattern byte 1 for data path A bit 3 */
#define    BM_WUP1A3	(uint8_t)(1U<<WUP1A3)
#define    WUP1A4          4       /* Wake-Up Pattern byte 1 for data path A bit 4 */
#define    BM_WUP1A4	(uint8_t)(1U<<WUP1A4)
#define    WUP1A5          5       /* Wake-Up Pattern byte 1 for data path A bit 5 */
#define    BM_WUP1A5	(uint8_t)(1U<<WUP1A5)
#define    WUP1A6          6       /* Wake-Up Pattern byte 1 for data path A bit 6 */
#define    BM_WUP1A6	(uint8_t)(1U<<WUP1A6)
#define    WUP1A7          7       /* Wake-Up Pattern byte 1 for data path A bit 7 */
#define    BM_WUP1A7	(uint8_t)(1U<<WUP1A7)

/* WUP1B - Wake-Up Pattern byte 1 for data path B */
#define    WUP1B0          0       /* Wake-Up Pattern byte 1 for data path B bit 0 */
#define    BM_WUP1B0	(uint8_t)(1U<<WUP1B0)
#define    WUP1B1          1       /* Wake-Up Pattern byte 1 for data path B bit 1 */
#define    BM_WUP1B1	(uint8_t)(1U<<WUP1B1)
#define    WUP1B2          2       /* Wake-Up Pattern byte 1 for data path B bit 2 */
#define    BM_WUP1B2	(uint8_t)(1U<<WUP1B2)
#define    WUP1B3          3       /* Wake-Up Pattern byte 1 for data path B bit 3 */
#define    BM_WUP1B3	(uint8_t)(1U<<WUP1B3)
#define    WUP1B4          4       /* Wake-Up Pattern byte 1 for data path B bit 4 */
#define    BM_WUP1B4	(uint8_t)(1U<<WUP1B4)
#define    WUP1B5          5       /* Wake-Up Pattern byte 1 for data path B bit 5 */
#define    BM_WUP1B5	(uint8_t)(1U<<WUP1B5)
#define    WUP1B6          6       /* Wake-Up Pattern byte 1 for data path B bit 6 */
#define    BM_WUP1B6	(uint8_t)(1U<<WUP1B6)
#define    WUP1B7          7       /* Wake-Up Pattern byte 1 for data path B bit 7 */
#define    BM_WUP1B7	(uint8_t)(1U<<WUP1B7)

/* WUP2A - Wake-Up Pattern byte 2 for data path A */
#define    WUP2A0          0       /* Wake-Up Pattern byte 2 for data path A bit 0 */
#define    BM_WUP2A0	(uint8_t)(1U<<WUP2A0)
#define    WUP2A1          1       /* Wake-Up Pattern byte 2 for data path A bit 1 */
#define    BM_WUP2A1	(uint8_t)(1U<<WUP2A1)
#define    WUP2A2          2       /* Wake-Up Pattern byte 2 for data path A bit 2 */
#define    BM_WUP2A2	(uint8_t)(1U<<WUP2A2)
#define    WUP2A3          3       /* Wake-Up Pattern byte 2 for data path A bit 3 */
#define    BM_WUP2A3	(uint8_t)(1U<<WUP2A3)
#define    WUP2A4          4       /* Wake-Up Pattern byte 2 for data path A bit 4 */
#define    BM_WUP2A4	(uint8_t)(1U<<WUP2A4)
#define    WUP2A5          5       /* Wake-Up Pattern byte 2 for data path A bit 5 */
#define    BM_WUP2A5	(uint8_t)(1U<<WUP2A5)
#define    WUP2A6          6       /* Wake-Up Pattern byte 2 for data path A bit 6 */
#define    BM_WUP2A6	(uint8_t)(1U<<WUP2A6)
#define    WUP2A7          7       /* Wake-Up Pattern byte 2 for data path A bit 7 */
#define    BM_WUP2A7	(uint8_t)(1U<<WUP2A7)

/* WUP2B - Wake-Up Pattern byte 2 for data path B */
#define    WUP2B0          0       /* Wake-Up Pattern byte 2 for data path B bit 0 */
#define    BM_WUP2B0	(uint8_t)(1U<<WUP2B0)
#define    WUP2B1          1       /* Wake-Up Pattern byte 2 for data path B bit 1 */
#define    BM_WUP2B1	(uint8_t)(1U<<WUP2B1)
#define    WUP2B2          2       /* Wake-Up Pattern byte 2 for data path B bit 2 */
#define    BM_WUP2B2	(uint8_t)(1U<<WUP2B2)
#define    WUP2B3          3       /* Wake-Up Pattern byte 2 for data path B bit 3 */
#define    BM_WUP2B3	(uint8_t)(1U<<WUP2B3)
#define    WUP2B4          4       /* Wake-Up Pattern byte 2 for data path B bit 4 */
#define    BM_WUP2B4	(uint8_t)(1U<<WUP2B4)
#define    WUP2B5          5       /* Wake-Up Pattern byte 2 for data path B bit 5 */
#define    BM_WUP2B5	(uint8_t)(1U<<WUP2B5)
#define    WUP2B6          6       /* Wake-Up Pattern byte 2 for data path B bit 6 */
#define    BM_WUP2B6	(uint8_t)(1U<<WUP2B6)
#define    WUP2B7          7       /* Wake-Up Pattern byte 2 for data path B bit 7 */
#define    BM_WUP2B7	(uint8_t)(1U<<WUP2B7)

/* WUP3A - Wake-Up Pattern byte 3 for data path A */
#define    WUP3A0          0       /* Wake-Up Pattern byte 3 for data path A bit 0 */
#define    BM_WUP3A0	(uint8_t)(1U<<WUP3A0)
#define    WUP3A1          1       /* Wake-Up Pattern byte 3 for data path A bit 1 */
#define    BM_WUP3A1	(uint8_t)(1U<<WUP3A1)
#define    WUP3A2          2       /* Wake-Up Pattern byte 3 for data path A bit 2 */
#define    BM_WUP3A2	(uint8_t)(1U<<WUP3A2)
#define    WUP3A3          3       /* Wake-Up Pattern byte 3 for data path A bit 3 */
#define    BM_WUP3A3	(uint8_t)(1U<<WUP3A3)
#define    WUP3A4          4       /* Wake-Up Pattern byte 3 for data path A bit 4 */
#define    BM_WUP3A4	(uint8_t)(1U<<WUP3A4)
#define    WUP3A5          5       /* Wake-Up Pattern byte 3 for data path A bit 5 */
#define    BM_WUP3A5	(uint8_t)(1U<<WUP3A5)
#define    WUP3A6          6       /* Wake-Up Pattern byte 3 for data path A bit 6 */
#define    BM_WUP3A6	(uint8_t)(1U<<WUP3A6)
#define    WUP3A7          7       /* Wake-Up Pattern byte 3 for data path A bit 7 */
#define    BM_WUP3A7	(uint8_t)(1U<<WUP3A7)

/* WUP3B - Wake-Up Pattern byte 3 for data path B */
#define    WUP3B0          0       /* Wake-Up Pattern byte 3 for data path B bit 0 */
#define    BM_WUP3B0	(uint8_t)(1U<<WUP3B0)
#define    WUP3B1          1       /* Wake-Up Pattern byte 3 for data path B bit 1 */
#define    BM_WUP3B1	(uint8_t)(1U<<WUP3B1)
#define    WUP3B2          2       /* Wake-Up Pattern byte 3 for data path B bit 2 */
#define    BM_WUP3B2	(uint8_t)(1U<<WUP3B2)
#define    WUP3B3          3       /* Wake-Up Pattern byte 3 for data path B bit 3 */
#define    BM_WUP3B3	(uint8_t)(1U<<WUP3B3)
#define    WUP3B4          4       /* Wake-Up Pattern byte 3 for data path B bit 4 */
#define    BM_WUP3B4	(uint8_t)(1U<<WUP3B4)
#define    WUP3B5          5       /* Wake-Up Pattern byte 3 for data path B bit 5 */
#define    BM_WUP3B5	(uint8_t)(1U<<WUP3B5)
#define    WUP3B6          6       /* Wake-Up Pattern byte 3 for data path B bit 6 */
#define    BM_WUP3B6	(uint8_t)(1U<<WUP3B6)
#define    WUP3B7          7       /* Wake-Up Pattern byte 3 for data path B bit 7 */
#define    BM_WUP3B7	(uint8_t)(1U<<WUP3B7)

/* WUP4A - Wake-Up Pattern byte 4 for data path A */
#define    WUP4A0          0       /* Wake-Up Pattern byte 4 for data path A bit 0 */
#define    BM_WUP4A0	(uint8_t)(1U<<WUP4A0)
#define    WUP4A1          1       /* Wake-Up Pattern byte 4 for data path A bit 1 */
#define    BM_WUP4A1	(uint8_t)(1U<<WUP4A1)
#define    WUP4A2          2       /* Wake-Up Pattern byte 4 for data path A bit 2 */
#define    BM_WUP4A2	(uint8_t)(1U<<WUP4A2)
#define    WUP4A3          3       /* Wake-Up Pattern byte 4 for data path A bit 3 */
#define    BM_WUP4A3	(uint8_t)(1U<<WUP4A3)
#define    WUP4A4          4       /* Wake-Up Pattern byte 4 for data path A bit 4 */
#define    BM_WUP4A4	(uint8_t)(1U<<WUP4A4)
#define    WUP4A5          5       /* Wake-Up Pattern byte 4 for data path A bit 5 */
#define    BM_WUP4A5	(uint8_t)(1U<<WUP4A5)
#define    WUP4A6          6       /* Wake-Up Pattern byte 4 for data path A bit 6 */
#define    BM_WUP4A6	(uint8_t)(1U<<WUP4A6)
#define    WUP4A7          7       /* Wake-Up Pattern byte 4 for data path A bit 7 */
#define    BM_WUP4A7	(uint8_t)(1U<<WUP4A7)

/* WUP4B - Wake-Up Pattern byte 4 for data path B */
#define    WUP4B0          0       /* Wake-Up Pattern byte 4 for data path B bit 0 */
#define    BM_WUP4B0	(uint8_t)(1U<<WUP4B0)
#define    WUP4B1          1       /* Wake-Up Pattern byte 4 for data path B bit 1 */
#define    BM_WUP4B1	(uint8_t)(1U<<WUP4B1)
#define    WUP4B2          2       /* Wake-Up Pattern byte 4 for data path B bit 2 */
#define    BM_WUP4B2	(uint8_t)(1U<<WUP4B2)
#define    WUP4B3          3       /* Wake-Up Pattern byte 4 for data path B bit 3 */
#define    BM_WUP4B3	(uint8_t)(1U<<WUP4B3)
#define    WUP4B4          4       /* Wake-Up Pattern byte 4 for data path B bit 4 */
#define    BM_WUP4B4	(uint8_t)(1U<<WUP4B4)
#define    WUP4B5          5       /* Wake-Up Pattern byte 4 for data path B bit 5 */
#define    BM_WUP4B5	(uint8_t)(1U<<WUP4B5)
#define    WUP4B6          6       /* Wake-Up Pattern byte 4 for data path B bit 6 */
#define    BM_WUP4B6	(uint8_t)(1U<<WUP4B6)
#define    WUP4B7          7       /* Wake-Up Pattern byte 4 for data path B bit 7 */
#define    BM_WUP4B7	(uint8_t)(1U<<WUP4B7)

/* WUPLA - Wake-Up Pattern Length for data path A */
#define    WUPLA0          0       /* Wake-Up Pattern Length for data path A bit 0 */
#define    BM_WUPLA0	(uint8_t)(1U<<WUPLA0)
#define    WUPLA1          1       /* Wake-Up Pattern Length for data path A bit 1 */
#define    BM_WUPLA1	(uint8_t)(1U<<WUPLA1)
#define    WUPLA2          2       /* Wake-Up Pattern Length for data path A bit 2 */
#define    BM_WUPLA2	(uint8_t)(1U<<WUPLA2)
#define    WUPLA3          3       /* Wake-Up Pattern Length for data path A bit 3 */
#define    BM_WUPLA3	(uint8_t)(1U<<WUPLA3)
#define    WUPLA4          4       /* Wake-Up Pattern Length for data path A bit 4 */
#define    BM_WUPLA4	(uint8_t)(1U<<WUPLA4)
#define    WUPLA5          5       /* Wake-Up Pattern Length for data path A bit 5 */
#define    BM_WUPLA5	(uint8_t)(1U<<WUPLA5)

/* WUPLB - Wake-Up Pattern Length for data path B */
#define    WUPLB0          0       /* Wake-Up Pattern Length for data path B bit 0 */
#define    BM_WUPLB0	(uint8_t)(1U<<WUPLB0)
#define    WUPLB1          1       /* Wake-Up Pattern Length for data path B bit 1 */
#define    BM_WUPLB1	(uint8_t)(1U<<WUPLB1)
#define    WUPLB2          2       /* Wake-Up Pattern Length for data path B bit 2 */
#define    BM_WUPLB2	(uint8_t)(1U<<WUPLB2)
#define    WUPLB3          3       /* Wake-Up Pattern Length for data path B bit 3 */
#define    BM_WUPLB3	(uint8_t)(1U<<WUPLB3)
#define    WUPLB4          4       /* Wake-Up Pattern Length for data path B bit 4 */
#define    BM_WUPLB4	(uint8_t)(1U<<WUPLB4)
#define    WUPLB5          5       /* Wake-Up Pattern Length for data path B bit 5 */
#define    BM_WUPLB5	(uint8_t)(1U<<WUPLB5)

/* WUPTA - Wake-Up Pattern Threshold for data path A */
#define    WUPTA0          0       /* Wake-Up Pattern Threshold for data path A bit 0 */
#define    BM_WUPTA0	(uint8_t)(1U<<WUPTA0)
#define    WUPTA1          1       /* Wake-Up Pattern Threshold for data path A bit 1 */
#define    BM_WUPTA1	(uint8_t)(1U<<WUPTA1)
#define    WUPTA2          2       /* Wake-Up Pattern Threshold for data path A bit 2 */
#define    BM_WUPTA2	(uint8_t)(1U<<WUPTA2)
#define    WUPTA3          3       /* Wake-Up Pattern Threshold for data path A bit 3 */
#define    BM_WUPTA3	(uint8_t)(1U<<WUPTA3)
#define    WUPTA4          4       /* Wake-Up Pattern Threshold for data path A bit 4 */
#define    BM_WUPTA4	(uint8_t)(1U<<WUPTA4)

/* WUPTB - Wake-Up Pattern Threshold for data path B */
#define    WUPTB0          0       /* Wake-Up Pattern Threshold for data path B bit 0 */
#define    BM_WUPTB0	(uint8_t)(1U<<WUPTB0)
#define    WUPTB1          1       /* Wake-Up Pattern Threshold for data path B bit 1 */
#define    BM_WUPTB1	(uint8_t)(1U<<WUPTB1)
#define    WUPTB2          2       /* Wake-Up Pattern Threshold for data path B bit 2 */
#define    BM_WUPTB2	(uint8_t)(1U<<WUPTB2)
#define    WUPTB3          3       /* Wake-Up Pattern Threshold for data path B bit 3 */
#define    BM_WUPTB3	(uint8_t)(1U<<WUPTB3)
#define    WUPTB4          4       /* Wake-Up Pattern Threshold for data path B bit 4 */
#define    BM_WUPTB4	(uint8_t)(1U<<WUPTB4)


/* ***** GPIOREGS ********************* */
/* GPIOR0 - General Purpose I/O Register 0 */
#define    GPIOR00         0       /*  */
#define    BM_GPIOR00	(uint8_t)(1U<<GPIOR00)
#define    GPIOR01         1       /*  */
#define    BM_GPIOR01	(uint8_t)(1U<<GPIOR01)
#define    GPIOR02         2       /*  */
#define    BM_GPIOR02	(uint8_t)(1U<<GPIOR02)
#define    GPIOR03         3       /*  */
#define    BM_GPIOR03	(uint8_t)(1U<<GPIOR03)
#define    GPIOR04         4       /*  */
#define    BM_GPIOR04	(uint8_t)(1U<<GPIOR04)
#define    GPIOR05         5       /*  */
#define    BM_GPIOR05	(uint8_t)(1U<<GPIOR05)
#define    GPIOR06         6       /*  */
#define    BM_GPIOR06	(uint8_t)(1U<<GPIOR06)
#define    GPIOR07         7       /*  */
#define    BM_GPIOR07	(uint8_t)(1U<<GPIOR07)

/* GPIOR1 - General Purpose I/O Register 1 */
#define    GPIOR10         0       /*  */
#define    BM_GPIOR10	(uint8_t)(1U<<GPIOR10)
#define    GPIOR11         1       /*  */
#define    BM_GPIOR11	(uint8_t)(1U<<GPIOR11)
#define    GPIOR12         2       /*  */
#define    BM_GPIOR12	(uint8_t)(1U<<GPIOR12)
#define    GPIOR13         3       /*  */
#define    BM_GPIOR13	(uint8_t)(1U<<GPIOR13)
#define    GPIOR14         4       /*  */
#define    BM_GPIOR14	(uint8_t)(1U<<GPIOR14)
#define    GPIOR15         5       /*  */
#define    BM_GPIOR15	(uint8_t)(1U<<GPIOR15)
#define    GPIOR16         6       /*  */
#define    BM_GPIOR16	(uint8_t)(1U<<GPIOR16)
#define    GPIOR17         7       /*  */
#define    BM_GPIOR17	(uint8_t)(1U<<GPIOR17)

/* GPIOR2 - General Purpose I/O Register 2 */
#define    GPIOR20         0       /*  */
#define    BM_GPIOR20	(uint8_t)(1U<<GPIOR20)
#define    GPIOR21         1       /*  */
#define    BM_GPIOR21	(uint8_t)(1U<<GPIOR21)
#define    GPIOR22         2       /*  */
#define    BM_GPIOR22	(uint8_t)(1U<<GPIOR22)
#define    GPIOR23         3       /*  */
#define    BM_GPIOR23	(uint8_t)(1U<<GPIOR23)
#define    GPIOR24         4       /*  */
#define    BM_GPIOR24	(uint8_t)(1U<<GPIOR24)
#define    GPIOR25         5       /*  */
#define    BM_GPIOR25	(uint8_t)(1U<<GPIOR25)
#define    GPIOR26         6       /*  */
#define    BM_GPIOR26	(uint8_t)(1U<<GPIOR26)
#define    GPIOR27         7       /*  */
#define    BM_GPIOR27	(uint8_t)(1U<<GPIOR27)

/* GPIOR3 - General Purpose I/O Register 3 */
#define    GPIOR30         0       /*  */
#define    BM_GPIOR30	(uint8_t)(1U<<GPIOR30)
#define    GPIOR31         1       /*  */
#define    BM_GPIOR31	(uint8_t)(1U<<GPIOR31)
#define    GPIOR32         2       /*  */
#define    BM_GPIOR32	(uint8_t)(1U<<GPIOR32)
#define    GPIOR33         3       /*  */
#define    BM_GPIOR33	(uint8_t)(1U<<GPIOR33)
#define    GPIOR34         4       /*  */
#define    BM_GPIOR34	(uint8_t)(1U<<GPIOR34)
#define    GPIOR35         5       /*  */
#define    BM_GPIOR35	(uint8_t)(1U<<GPIOR35)
#define    GPIOR36         6       /*  */
#define    BM_GPIOR36	(uint8_t)(1U<<GPIOR36)
#define    GPIOR37         7       /*  */
#define    BM_GPIOR37	(uint8_t)(1U<<GPIOR37)

/* GPIOR4 - General Purpose I/O Register 4 */
#define    GPIOR40         0       /*  */
#define    BM_GPIOR40	(uint8_t)(1U<<GPIOR40)
#define    GPIOR41         1       /*  */
#define    BM_GPIOR41	(uint8_t)(1U<<GPIOR41)
#define    GPIOR42         2       /*  */
#define    BM_GPIOR42	(uint8_t)(1U<<GPIOR42)
#define    GPIOR43         3       /*  */
#define    BM_GPIOR43	(uint8_t)(1U<<GPIOR43)
#define    GPIOR44         4       /*  */
#define    BM_GPIOR44	(uint8_t)(1U<<GPIOR44)
#define    GPIOR45         5       /*  */
#define    BM_GPIOR45	(uint8_t)(1U<<GPIOR45)
#define    GPIOR46         6       /*  */
#define    BM_GPIOR46	(uint8_t)(1U<<GPIOR46)
#define    GPIOR47         7       /*  */
#define    BM_GPIOR47	(uint8_t)(1U<<GPIOR47)

/* GPIOR5 - General Purpose I/O Register 5 */
#define    GPIOR50         0       /*  */
#define    BM_GPIOR50	(uint8_t)(1U<<GPIOR50)
#define    GPIOR51         1       /*  */
#define    BM_GPIOR51	(uint8_t)(1U<<GPIOR51)
#define    GPIOR52         2       /*  */
#define    BM_GPIOR52	(uint8_t)(1U<<GPIOR52)
#define    GPIOR53         3       /*  */
#define    BM_GPIOR53	(uint8_t)(1U<<GPIOR53)
#define    GPIOR54         4       /*  */
#define    BM_GPIOR54	(uint8_t)(1U<<GPIOR54)
#define    GPIOR55         5       /*  */
#define    BM_GPIOR55	(uint8_t)(1U<<GPIOR55)
#define    GPIOR56         6       /*  */
#define    BM_GPIOR56	(uint8_t)(1U<<GPIOR56)
#define    GPIOR57         7       /*  */
#define    BM_GPIOR57	(uint8_t)(1U<<GPIOR57)

/* GPIOR6 - General Purpose I/O Register 6 */
#define    GPIOR60         0       /*  */
#define    BM_GPIOR60	(uint8_t)(1U<<GPIOR60)
#define    GPIOR61         1       /*  */
#define    BM_GPIOR61	(uint8_t)(1U<<GPIOR61)
#define    GPIOR62         2       /*  */
#define    BM_GPIOR62	(uint8_t)(1U<<GPIOR62)
#define    GPIOR63         3       /*  */
#define    BM_GPIOR63	(uint8_t)(1U<<GPIOR63)
#define    GPIOR64         4       /*  */
#define    BM_GPIOR64	(uint8_t)(1U<<GPIOR64)
#define    GPIOR65         5       /*  */
#define    BM_GPIOR65	(uint8_t)(1U<<GPIOR65)
#define    GPIOR66         6       /*  */
#define    BM_GPIOR66	(uint8_t)(1U<<GPIOR66)
#define    GPIOR67         7       /*  */
#define    BM_GPIOR67	(uint8_t)(1U<<GPIOR67)


/* ***** IDSCAN *********************** */
/* IDB0 - ID Byte 0 */
#define    IDB00           0       /* ID Byte 0 bit 0 */
#define    BM_IDB00	(uint8_t)(1U<<IDB00)
#define    IDB01           1       /* ID Byte 0 bit 1 */
#define    BM_IDB01	(uint8_t)(1U<<IDB01)
#define    IDB02           2       /* ID Byte 0 bit 2 */
#define    BM_IDB02	(uint8_t)(1U<<IDB02)
#define    IDB03           3       /* ID Byte 0 bit 3 */
#define    BM_IDB03	(uint8_t)(1U<<IDB03)
#define    IDB04           4       /* ID Byte 0 bit 4 */
#define    BM_IDB04	(uint8_t)(1U<<IDB04)
#define    IDB05           5       /* ID Byte 0 bit 5 */
#define    BM_IDB05	(uint8_t)(1U<<IDB05)
#define    IDB06           6       /* ID Byte 0 bit 6 */
#define    BM_IDB06	(uint8_t)(1U<<IDB06)
#define    IDB07           7       /* ID Byte 0 bit 7 */
#define    BM_IDB07	(uint8_t)(1U<<IDB07)

/* IDB1 - ID Byte 1 */
#define    IDB10           0       /* ID Byte 1 bit 0 */
#define    BM_IDB10	(uint8_t)(1U<<IDB10)
#define    IDB11           1       /* ID Byte 1 bit 1 */
#define    BM_IDB11	(uint8_t)(1U<<IDB11)
#define    IDB12           2       /* ID Byte 1 bit 2 */
#define    BM_IDB12	(uint8_t)(1U<<IDB12)
#define    IDB13           3       /* ID Byte 1 bit 3 */
#define    BM_IDB13	(uint8_t)(1U<<IDB13)
#define    IDB14           4       /* ID Byte 1 bit 4 */
#define    BM_IDB14	(uint8_t)(1U<<IDB14)
#define    IDB15           5       /* ID Byte 1 bit 5 */
#define    BM_IDB15	(uint8_t)(1U<<IDB15)
#define    IDB16           6       /* ID Byte 1 bit 6 */
#define    BM_IDB16	(uint8_t)(1U<<IDB16)
#define    IDB17           7       /* ID Byte 1 bit 7 */
#define    BM_IDB17	(uint8_t)(1U<<IDB17)

/* IDB2 - ID Byte 2 */
#define    IDB20           0       /* ID Byte 2 bit 0 */
#define    BM_IDB20	(uint8_t)(1U<<IDB20)
#define    IDB21           1       /* ID Byte 2 bit 1 */
#define    BM_IDB21	(uint8_t)(1U<<IDB21)
#define    IDB22           2       /* ID Byte 2 bit 2 */
#define    BM_IDB22	(uint8_t)(1U<<IDB22)
#define    IDB23           3       /* ID Byte 2 bit 3 */
#define    BM_IDB23	(uint8_t)(1U<<IDB23)
#define    IDB24           4       /* ID Byte 2 bit 4 */
#define    BM_IDB24	(uint8_t)(1U<<IDB24)
#define    IDB25           5       /* ID Byte 2 bit 5 */
#define    BM_IDB25	(uint8_t)(1U<<IDB25)
#define    IDB26           6       /* ID Byte 2 bit 6 */
#define    BM_IDB26	(uint8_t)(1U<<IDB26)
#define    IDB27           7       /* ID Byte 2 bit 7 */
#define    BM_IDB27	(uint8_t)(1U<<IDB27)

/* IDB3 - ID Byte 3 */
#define    IDB30           0       /* ID Byte 3 bit 0 */
#define    BM_IDB30	(uint8_t)(1U<<IDB30)
#define    IDB31           1       /* ID Byte 3 bit 1 */
#define    BM_IDB31	(uint8_t)(1U<<IDB31)
#define    IDB32           2       /* ID Byte 3 bit 2 */
#define    BM_IDB32	(uint8_t)(1U<<IDB32)
#define    IDB33           3       /* ID Byte 3 bit 3 */
#define    BM_IDB33	(uint8_t)(1U<<IDB33)
#define    IDB34           4       /* ID Byte 3 bit 4 */
#define    BM_IDB34	(uint8_t)(1U<<IDB34)
#define    IDB35           5       /* ID Byte 3 bit 5 */
#define    BM_IDB35	(uint8_t)(1U<<IDB35)
#define    IDB36           6       /* ID Byte 3 bit 6 */
#define    BM_IDB36	(uint8_t)(1U<<IDB36)
#define    IDB37           7       /* ID Byte 3 bit 7 */
#define    BM_IDB37	(uint8_t)(1U<<IDB37)

/* IDC - ID Configuration */
#define    IDL0            0       /* ID Length bit 0 */
#define    BM_IDL0	(uint8_t)(1U<<IDL0)
#define    IDL1            1       /* ID Length bit 1 */
#define    BM_IDL1	(uint8_t)(1U<<IDL1)
#define    IDBO0           2       /* ID Byte Offset bit 0 */
#define    BM_IDBO0	(uint8_t)(1U<<IDBO0)
#define    IDBO1           3       /* ID Byte Offset bit 1 */
#define    BM_IDBO1	(uint8_t)(1U<<IDBO1)
#define    IDFIM           5       /* ID Full Interrupt Mask */
#define    BM_IDFIM	(uint8_t)(1U<<IDFIM)
#define    IDCLR           6       /* ID Clear */
#define    BM_IDCLR	(uint8_t)(1U<<IDCLR)
#define    IDCE            7       /* ID Check Execute */
#define    BM_IDCE	(uint8_t)(1U<<IDCE)

/* IDS - ID Status */
#define    IDOK            0       /* ID Scan Ok Flag */
#define    BM_IDOK	(uint8_t)(1U<<IDOK)
#define    IDFULL          1       /* ID Full Flag */
#define    BM_IDFULL	(uint8_t)(1U<<IDFULL)


/* ***** INT ************************** */
/* EICRA - External Interrupt control Register */
#define    ISC00           0       /* Interrupt Sense Control 0 bit 0 */
#define    BM_ISC00	(uint8_t)(1U<<ISC00)
#define    ISC01           1       /* Interrupt Sense Control 0 bit 1 */
#define    BM_ISC01	(uint8_t)(1U<<ISC01)
#define    ISC10           2       /* Interrupt Sense Control 1 bit 0 */
#define    BM_ISC10	(uint8_t)(1U<<ISC10)
#define    ISC11           3       /* Interrupt Sense Control 1 bit 1 */
#define    BM_ISC11	(uint8_t)(1U<<ISC11)

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       /* External Interrupt Flag 0 */
#define    BM_INTF0	(uint8_t)(1U<<INTF0)
#define    INTF1           1       /* External Interrupt Flag 1 */
#define    BM_INTF1	(uint8_t)(1U<<INTF1)

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       /* External Interrupt Request 0 Enable */
#define    BM_INT0	(uint8_t)(1U<<INT0)
#define    INT1            1       /* External Interrupt Request 1 Enable */
#define    BM_INT1	(uint8_t)(1U<<INT1)

/* PCICR - Pin change Interrupt control Register */
#define    PCIE0           0       /* Pin Change Interrupt Enable 0 */
#define    BM_PCIE0	(uint8_t)(1U<<PCIE0)
#define    PCIE1           1       /* Pin Change Interrupt Enable 1 */
#define    BM_PCIE1	(uint8_t)(1U<<PCIE1)

/* PCIFR - Pin change Interrupt flag Register */
#define    PCIF0           0       /* Pin Change Interrupt Flag 0 */
#define    BM_PCIF0	(uint8_t)(1U<<PCIF0)
#define    PCIF1           1       /* Pin Change Interrupt Flag 1 */
#define    BM_PCIF1	(uint8_t)(1U<<PCIF1)

/* PCMSK0 - Pin change Mask Register 0 */
#define    PCINT0          0       /* Pin Change Enable Mask bit 0 */
#define    BM_PCINT0	(uint8_t)(1U<<PCINT0)
#define    PCINT1          1       /* Pin Change Enable Mask bit 1 */
#define    BM_PCINT1	(uint8_t)(1U<<PCINT1)
#define    PCINT2          2       /* Pin Change Enable Mask bit 2 */
#define    BM_PCINT2	(uint8_t)(1U<<PCINT2)
#define    PCINT3          3       /* Pin Change Enable Mask bit 3 */
#define    BM_PCINT3	(uint8_t)(1U<<PCINT3)
#define    PCINT4          4       /* Pin Change Enable Mask bit 4 */
#define    BM_PCINT4	(uint8_t)(1U<<PCINT4)
#define    PCINT5          5       /* Pin Change Enable Mask bit 5 */
#define    BM_PCINT5	(uint8_t)(1U<<PCINT5)
#define    PCINT6          6       /* Pin Change Enable Mask bit 6 */
#define    BM_PCINT6	(uint8_t)(1U<<PCINT6)
#define    PCINT7          7       /* Pin Change Enable Mask bit 7 */
#define    BM_PCINT7	(uint8_t)(1U<<PCINT7)

/* PCMSK1 - Pin change Mask Register 1 */
#define    PCINT8          0       /* Pin Change Enable Mask bit 8 */
#define    BM_PCINT8	(uint8_t)(1U<<PCINT8)
#define    PCINT9          1       /* Pin Change Enable Mask bit 9 */
#define    BM_PCINT9	(uint8_t)(1U<<PCINT9)
#define    PCINT10         2       /* Pin Change Enable Mask bit 10 */
#define    BM_PCINT10	(uint8_t)(1U<<PCINT10)
#define    PCINT11         3       /* Pin Change Enable Mask bit 11 */
#define    BM_PCINT11	(uint8_t)(1U<<PCINT11)
#define    PCINT12         4       /* Pin Change Enable Mask bit 12 */
#define    BM_PCINT12	(uint8_t)(1U<<PCINT12)
#define    PCINT13         5       /* Pin Change Enable Mask bit 13 */
#define    BM_PCINT13	(uint8_t)(1U<<PCINT13)


/* ***** MEM ************************** */
/* EEST - EEPROM Status Register */
#define    EESYN0          0       /* EEPROM Syndrome bit 0 */
#define    BM_EESYN0	(uint8_t)(1U<<EESYN0)
#define    EESYN1          1       /* EEPROM Syndrome bit 1 */
#define    BM_EESYN1	(uint8_t)(1U<<EESYN1)
#define    EESYN2          2       /* EEPROM Syndrome bit 2 */
#define    BM_EESYN2	(uint8_t)(1U<<EESYN2)
#define    EESYN3          3       /* EEPROM Syndrome bit 3 */
#define    BM_EESYN3	(uint8_t)(1U<<EESYN3)

/* PGMST - Program Memory Status Register */
#define    PGMSYN0         0       /* Program Memory Syndrome bit 0 */
#define    BM_PGMSYN0	(uint8_t)(1U<<PGMSYN0)
#define    PGMSYN1         1       /* Program Memory Syndrome bit 1 */
#define    BM_PGMSYN1	(uint8_t)(1U<<PGMSYN1)
#define    PGMSYN2         2       /* Program Memory Syndrome bit 2 */
#define    BM_PGMSYN2	(uint8_t)(1U<<PGMSYN2)
#define    PGMSYN3         3       /* Program Memory Syndrome bit 3 */
#define    BM_PGMSYN3	(uint8_t)(1U<<PGMSYN3)
#define    PGMSYN4         4       /* Program Memory Syndrome bit 4 */
#define    BM_PGMSYN4	(uint8_t)(1U<<PGMSYN4)


/* ***** PORTB ************************ */
/* DDRB - Port B Data Direction Register */
#define    DDRB0           0       /* Port B Data Direction Register bit 0 */
#define    BM_DDRB0	(uint8_t)(1U<<DDRB0)
#define    DDRB1           1       /* Port B Data Direction Register bit 1 */
#define    BM_DDRB1	(uint8_t)(1U<<DDRB1)
#define    DDRB2           2       /* Port B Data Direction Register bit 2 */
#define    BM_DDRB2	(uint8_t)(1U<<DDRB2)
#define    DDRB3           3       /* Port B Data Direction Register bit 3 */
#define    BM_DDRB3	(uint8_t)(1U<<DDRB3)
#define    DDRB4           4       /* Port B Data Direction Register bit 4 */
#define    BM_DDRB4	(uint8_t)(1U<<DDRB4)
#define    DDRB5           5       /* Port B Data Direction Register bit 5 */
#define    BM_DDRB5	(uint8_t)(1U<<DDRB5)
#define    DDRB6           6       /* Port B Data Direction Register bit 6 */
#define    BM_DDRB6	(uint8_t)(1U<<DDRB6)
#define    DDRB7           7       /* Port B Data Direction Register bit 7 */
#define    BM_DDRB7	(uint8_t)(1U<<DDRB7)

/* PINB - Port B Input Pins */
#define    PINB0           0       /* Port B Input Pins bit 0 */
#define    BM_PINB0	(uint8_t)(1U<<PINB0)
#define    PINB1           1       /* Port B Input Pins bit 1 */
#define    BM_PINB1	(uint8_t)(1U<<PINB1)
#define    PINB2           2       /* Port B Input Pins bit 2 */
#define    BM_PINB2	(uint8_t)(1U<<PINB2)
#define    PINB3           3       /* Port B Input Pins bit 3 */
#define    BM_PINB3	(uint8_t)(1U<<PINB3)
#define    PINB4           4       /* Port B Input Pins bit 4 */
#define    BM_PINB4	(uint8_t)(1U<<PINB4)
#define    PINB5           5       /* Port B Input Pins bit 5 */
#define    BM_PINB5	(uint8_t)(1U<<PINB5)
#define    PINB6           6       /* Port B Input Pins bit 6 */
#define    BM_PINB6	(uint8_t)(1U<<PINB6)
#define    PINB7           7       /* Port B Input Pins bit 7 */
#define    BM_PINB7	(uint8_t)(1U<<PINB7)

/* PORTB - Port B Data Register */
#define    PORTB0          0       /* Port B Data Register bit 0 */
#define    BM_PORTB0	(uint8_t)(1U<<PORTB0)
#define    PB0             0       /* For compatibility */
#define    BM_PB0	(uint8_t)(1U<<PB0)
#define    PORTB1          1       /* Port B Data Register bit 1 */
#define    BM_PORTB1	(uint8_t)(1U<<PORTB1)
#define    PB1             1       /* For compatibility */
#define    BM_PB1	(uint8_t)(1U<<PB1)
#define    PORTB2          2       /* Port B Data Register bit 2 */
#define    BM_PORTB2	(uint8_t)(1U<<PORTB2)
#define    PB2             2       /* For compatibility */
#define    BM_PB2	(uint8_t)(1U<<PB2)
#define    PORTB3          3       /* Port B Data Register bit 3 */
#define    BM_PORTB3	(uint8_t)(1U<<PORTB3)
#define    PB3             3       /* For compatibility */
#define    BM_PB3	(uint8_t)(1U<<PB3)
#define    PORTB4          4       /* Port B Data Register bit 4 */
#define    BM_PORTB4	(uint8_t)(1U<<PORTB4)
#define    PB4             4       /* For compatibility */
#define    BM_PB4	(uint8_t)(1U<<PB4)
#define    PORTB5          5       /* Port B Data Register bit 5 */
#define    BM_PORTB5	(uint8_t)(1U<<PORTB5)
#define    PB5             5       /* For compatibility */
#define    BM_PB5	(uint8_t)(1U<<PB5)
#define    PORTB6          6       /* Port B Data Register bit 6 */
#define    BM_PORTB6	(uint8_t)(1U<<PORTB6)
#define    PB6             6       /* For compatibility */
#define    BM_PB6	(uint8_t)(1U<<PB6)
#define    PORTB7          7       /* Port B Data Register bit 7 */
#define    BM_PORTB7	(uint8_t)(1U<<PORTB7)
#define    PB7             7       /* For compatibility */
#define    BM_PB7	(uint8_t)(1U<<PB7)


/* ***** PORTC ************************ */
/* DDRC - Port C Data Direction Register */
#define    DDRC0           0       /* Port C Data Direction Register bit 0 */
#define    BM_DDRC0	(uint8_t)(1U<<DDRC0)
#define    DDRC1           1       /* Port C Data Direction Register bit 1 */
#define    BM_DDRC1	(uint8_t)(1U<<DDRC1)
#define    DDRC2           2       /* Port C Data Direction Register bit 2 */
#define    BM_DDRC2	(uint8_t)(1U<<DDRC2)
#define    DDRC3           3       /* Port C Data Direction Register bit 3 */
#define    BM_DDRC3	(uint8_t)(1U<<DDRC3)
#define    DDRC4           4       /* Port C Data Direction Register bit 4 */
#define    BM_DDRC4	(uint8_t)(1U<<DDRC4)
#define    DDRC5           5       /* Port C Data Direction Register bit 5 */
#define    BM_DDRC5	(uint8_t)(1U<<DDRC5)

/* PINC - Port C Input Pins */
#define    PINC0           0       /* Port C Input Pins bit 0 */
#define    BM_PINC0	(uint8_t)(1U<<PINC0)
#define    PINC1           1       /* Port C Input Pins bit 1 */
#define    BM_PINC1	(uint8_t)(1U<<PINC1)
#define    PINC2           2       /* Port C Input Pins bit 2 */
#define    BM_PINC2	(uint8_t)(1U<<PINC2)
#define    PINC3           3       /* Port C Input Pins bit 3 */
#define    BM_PINC3	(uint8_t)(1U<<PINC3)
#define    PINC4           4       /* Port C Input Pins bit 4 */
#define    BM_PINC4	(uint8_t)(1U<<PINC4)
#define    PINC5           5       /* Port C Input Pins bit 5 */
#define    BM_PINC5	(uint8_t)(1U<<PINC5)

/* PORTC - Port C Data Register */
#define    PORTC0          0       /* Port C Data Register bit 0 */
#define    BM_PORTC0	(uint8_t)(1U<<PORTC0)
#define    PC0             0       /* For compatibility */
#define    BM_PC0	(uint8_t)(1U<<PC0)
#define    PORTC1          1       /* Port C Data Register bit 1 */
#define    BM_PORTC1	(uint8_t)(1U<<PORTC1)
#define    PC1             1       /* For compatibility */
#define    BM_PC1	(uint8_t)(1U<<PC1)
#define    PORTC2          2       /* Port C Data Register bit 2 */
#define    BM_PORTC2	(uint8_t)(1U<<PORTC2)
#define    PC2             2       /* For compatibility */
#define    BM_PC2	(uint8_t)(1U<<PC2)
#define    PORTC3          3       /* Port C Data Register bit 3 */
#define    BM_PORTC3	(uint8_t)(1U<<PORTC3)
#define    PC3             3       /* For compatibility */
#define    BM_PC3	(uint8_t)(1U<<PC3)
#define    PORTC4          4       /* Port C Data Register bit 4 */
#define    BM_PORTC4	(uint8_t)(1U<<PORTC4)
#define    PC4             4       /* For compatibility */
#define    BM_PC4	(uint8_t)(1U<<PC4)
#define    PORTC5          5       /* Port C Data Register bit 5 */
#define    BM_PORTC5	(uint8_t)(1U<<PORTC5)
#define    PC5             5       /* For compatibility */
#define    BM_PC5	(uint8_t)(1U<<PC5)


/* ***** RSSIB ************************ */
/* RSCOM - RSSI Compensation Register */
#define    RSDC            0       /* RSSI Damping Compensation */
#define    BM_RSDC	(uint8_t)(1U<<RSDC)
#define    RSIFC           1       /* RSSI IF Amplifier Compensation */
#define    BM_RSIFC	(uint8_t)(1U<<RSIFC)

/* RSHDV - RSSI High Band Damping Value */
#define    RSHDV0          0       /*  */
#define    BM_RSHDV0	(uint8_t)(1U<<RSHDV0)
#define    RSHDV1          1       /*  */
#define    BM_RSHDV1	(uint8_t)(1U<<RSHDV1)
#define    RSHDV2          2       /*  */
#define    BM_RSHDV2	(uint8_t)(1U<<RSHDV2)
#define    RSHDV3          3       /*  */
#define    BM_RSHDV3	(uint8_t)(1U<<RSHDV3)
#define    RSHDV4          4       /*  */
#define    BM_RSHDV4	(uint8_t)(1U<<RSHDV4)
#define    RSHDV5          5       /*  */
#define    BM_RSHDV5	(uint8_t)(1U<<RSHDV5)
#define    RSHDV6          6       /*  */
#define    BM_RSHDV6	(uint8_t)(1U<<RSHDV6)
#define    RSHDV7          7       /*  */
#define    BM_RSHDV7	(uint8_t)(1U<<RSHDV7)

/* RSIFG - RSSI High IF Amplifier Gain */
#define    RSIFG0          0       /*  */
#define    BM_RSIFG0	(uint8_t)(1U<<RSIFG0)
#define    RSIFG1          1       /*  */
#define    BM_RSIFG1	(uint8_t)(1U<<RSIFG1)
#define    RSIFG2          2       /*  */
#define    BM_RSIFG2	(uint8_t)(1U<<RSIFG2)
#define    RSIFG3          3       /*  */
#define    BM_RSIFG3	(uint8_t)(1U<<RSIFG3)
#define    RSIFG4          4       /*  */
#define    BM_RSIFG4	(uint8_t)(1U<<RSIFG4)
#define    RSIFG5          5       /*  */
#define    BM_RSIFG5	(uint8_t)(1U<<RSIFG5)
#define    RSIFG6          6       /*  */
#define    BM_RSIFG6	(uint8_t)(1U<<RSIFG6)
#define    RSIFG7          7       /*  */
#define    BM_RSIFG7	(uint8_t)(1U<<RSIFG7)

/* RSLDV - RSSI Low Band Damping Value */
#define    RSLDV0          0       /*  */
#define    BM_RSLDV0	(uint8_t)(1U<<RSLDV0)
#define    RSLDV1          1       /*  */
#define    BM_RSLDV1	(uint8_t)(1U<<RSLDV1)
#define    RSLDV2          2       /*  */
#define    BM_RSLDV2	(uint8_t)(1U<<RSLDV2)
#define    RSLDV3          3       /*  */
#define    BM_RSLDV3	(uint8_t)(1U<<RSLDV3)
#define    RSLDV4          4       /*  */
#define    BM_RSLDV4	(uint8_t)(1U<<RSLDV4)
#define    RSLDV5          5       /*  */
#define    BM_RSLDV5	(uint8_t)(1U<<RSLDV5)
#define    RSLDV6          6       /*  */
#define    BM_RSLDV6	(uint8_t)(1U<<RSLDV6)
#define    RSLDV7          7       /*  */
#define    BM_RSLDV7	(uint8_t)(1U<<RSLDV7)

/* RSSAV - RSSI Average Value */
#define    RSSAV0          0       /* RSSI Average Value bit 0 */
#define    BM_RSSAV0	(uint8_t)(1U<<RSSAV0)
#define    RSSAV1          1       /* RSSI Average Value bit 1 */
#define    BM_RSSAV1	(uint8_t)(1U<<RSSAV1)
#define    RSSAV2          2       /* RSSI Average Value bit 2 */
#define    BM_RSSAV2	(uint8_t)(1U<<RSSAV2)
#define    RSSAV3          3       /* RSSI Average Value bit 3 */
#define    BM_RSSAV3	(uint8_t)(1U<<RSSAV3)
#define    RSSAV4          4       /* RSSI Average Value bit 4 */
#define    BM_RSSAV4	(uint8_t)(1U<<RSSAV4)
#define    RSSAV5          5       /* RSSI Average Value bit 5 */
#define    BM_RSSAV5	(uint8_t)(1U<<RSSAV5)
#define    RSSAV6          6       /* RSSI Average Value bit 6 */
#define    BM_RSSAV6	(uint8_t)(1U<<RSSAV6)
#define    RSSAV7          7       /* RSSI Average Value bit 7 */
#define    BM_RSSAV7	(uint8_t)(1U<<RSSAV7)

/* RSSC - RSSI Configuration Register */
#define    RSUP0           0       /* RSSI Update Period bit 0 */
#define    BM_RSUP0	(uint8_t)(1U<<RSUP0)
#define    RSUP1           1       /* RSSI Update Period bit 1 */
#define    BM_RSUP1	(uint8_t)(1U<<RSUP1)
#define    RSUP2           2       /* RSSI Update Period bit 2 */
#define    BM_RSUP2	(uint8_t)(1U<<RSUP2)
#define    RSUP3           3       /* RSSI Update Period bit 3 */
#define    BM_RSUP3	(uint8_t)(1U<<RSUP3)
#define    RSWLH           4       /* RSSI within Low and High Limits */
#define    BM_RSWLH	(uint8_t)(1U<<RSWLH)
#define    RSHRX           5       /* RSSI High Band Reception */
#define    BM_RSHRX	(uint8_t)(1U<<RSHRX)
#define    RSPKF           6       /* RSSI Peak Values to SFIFO */
#define    BM_RSPKF	(uint8_t)(1U<<RSPKF)

/* RSSH - RSSI High Threshold for Signal Check */
#define    RSSH0           0       /* RSSI High Threshold for Signal Check bit 0 */
#define    BM_RSSH0	(uint8_t)(1U<<RSSH0)
#define    RSSH1           1       /* RSSI High Threshold for Signal Check bit 1 */
#define    BM_RSSH1	(uint8_t)(1U<<RSSH1)
#define    RSSH2           2       /* RSSI High Threshold for Signal Check bit 2 */
#define    BM_RSSH2	(uint8_t)(1U<<RSSH2)
#define    RSSH3           3       /* RSSI High Threshold for Signal Check bit 3 */
#define    BM_RSSH3	(uint8_t)(1U<<RSSH3)
#define    RSSH4           4       /* RSSI High Threshold for Signal Check bit 4 */
#define    BM_RSSH4	(uint8_t)(1U<<RSSH4)
#define    RSSH5           5       /* RSSI High Threshold for Signal Check bit 5 */
#define    BM_RSSH5	(uint8_t)(1U<<RSSH5)
#define    RSSH6           6       /* RSSI High Threshold for Signal Check bit 6 */
#define    BM_RSSH6	(uint8_t)(1U<<RSSH6)
#define    RSSH7           7       /* RSSI High Threshold for Signal Check bit 7 */
#define    BM_RSSH7	(uint8_t)(1U<<RSSH7)

/* RSSL - RSSI Low Threshold for Signal Check */
#define    RSSL0           0       /* RSSI Low Threshold for Signal Check bit 0 */
#define    BM_RSSL0	(uint8_t)(1U<<RSSL0)
#define    RSSL1           1       /* RSSI Low Threshold for Signal Check bit 1 */
#define    BM_RSSL1	(uint8_t)(1U<<RSSL1)
#define    RSSL2           2       /* RSSI Low Threshold for Signal Check bit 2 */
#define    BM_RSSL2	(uint8_t)(1U<<RSSL2)
#define    RSSL3           3       /* RSSI Low Threshold for Signal Check bit 3 */
#define    BM_RSSL3	(uint8_t)(1U<<RSSL3)
#define    RSSL4           4       /* RSSI Low Threshold for Signal Check bit 4 */
#define    BM_RSSL4	(uint8_t)(1U<<RSSL4)
#define    RSSL5           5       /* RSSI Low Threshold for Signal Check bit 5 */
#define    BM_RSSL5	(uint8_t)(1U<<RSSL5)
#define    RSSL6           6       /* RSSI Low Threshold for Signal Check bit 6 */
#define    BM_RSSL6	(uint8_t)(1U<<RSSL6)
#define    RSSL7           7       /* RSSI Low Threshold for Signal Check bit 7 */
#define    BM_RSSL7	(uint8_t)(1U<<RSSL7)

/* RSSPK - RSSI Peak Value */
#define    RSSPK0          0       /* RSSI Peak Value bit 0 */
#define    BM_RSSPK0	(uint8_t)(1U<<RSSPK0)
#define    RSSPK1          1       /* RSSI Peak Value bit 1 */
#define    BM_RSSPK1	(uint8_t)(1U<<RSSPK1)
#define    RSSPK2          2       /* RSSI Peak Value bit 2 */
#define    BM_RSSPK2	(uint8_t)(1U<<RSSPK2)
#define    RSSPK3          3       /* RSSI Peak Value bit 3 */
#define    BM_RSSPK3	(uint8_t)(1U<<RSSPK3)
#define    RSSPK4          4       /* RSSI Peak Value bit 4 */
#define    BM_RSSPK4	(uint8_t)(1U<<RSSPK4)
#define    RSSPK5          5       /* RSSI Peak Value bit 5 */
#define    BM_RSSPK5	(uint8_t)(1U<<RSSPK5)
#define    RSSPK6          6       /* RSSI Peak Value bit 6 */
#define    BM_RSSPK6	(uint8_t)(1U<<RSSPK6)
#define    RSSPK7          7       /* RSSI Peak Value bit 7 */
#define    BM_RSSPK7	(uint8_t)(1U<<RSSPK7)


/* ***** RXBUF ************************ */
/* RXBC1 - Rx Buffer configuration register 1 */
#define    RXCEA           0       /* RX CRC Enable data path A */
#define    BM_RXCEA	(uint8_t)(1U<<RXCEA)
#define    RXCBLA0         1       /* Receive CRC Bit Lengths setting for data path A bit 0 */
#define    BM_RXCBLA0	(uint8_t)(1U<<RXCBLA0)
#define    RXCBLA1         2       /* Receive CRC Bit Lengths setting for data path A bit 1 */
#define    BM_RXCBLA1	(uint8_t)(1U<<RXCBLA1)
#define    RXMSBA          3       /* Receive Data MSB-first for data path A */
#define    BM_RXMSBA	(uint8_t)(1U<<RXMSBA)
#define    RXCEB           4       /* RX CRC Enable data path B */
#define    BM_RXCEB	(uint8_t)(1U<<RXCEB)
#define    RXCBLB0         5       /* Receive CRC Bit Lengths setting for data path B bit 0 */
#define    BM_RXCBLB0	(uint8_t)(1U<<RXCBLB0)
#define    RXCBLB1         6       /* Receive CRC Bit Lengths setting for data path B bit 1 */
#define    BM_RXCBLB1	(uint8_t)(1U<<RXCBLB1)
#define    RXMSBB          7       /* Receive Data MSB-first for data path B */
#define    BM_RXMSBB	(uint8_t)(1U<<RXMSBB)

/* RXBC2 - Rx Buffer configuration register 2 */
#define    RXBPB           0       /* RX Buffer Path B select signal */
#define    BM_RXBPB	(uint8_t)(1U<<RXBPB)
#define    RXBF            1       /* RX Buffer Finish */
#define    BM_RXBF	(uint8_t)(1U<<RXBF)
#define    RXBCLR          2       /* RX Buffer Clear */
#define    BM_RXBCLR	(uint8_t)(1U<<RXBCLR)

/* RXCIHA - Rx CRC Init value high byte for data path A */
#define    RXCIHA0         0       /* Rx CRC Init value (16-bit RXCI) High byte for data path A bit 0 */
#define    BM_RXCIHA0	(uint8_t)(1U<<RXCIHA0)
#define    RXCIHA1         1       /* Rx CRC Init value (16-bit RXCI) High byte for data path A bit 1 */
#define    BM_RXCIHA1	(uint8_t)(1U<<RXCIHA1)
#define    RXCIHA2         2       /* Rx CRC Init value (16-bit RXCI) High byte for data path A bit 2 */
#define    BM_RXCIHA2	(uint8_t)(1U<<RXCIHA2)
#define    RXCIHA3         3       /* Rx CRC Init value (16-bit RXCI) High byte for data path A bit 3 */
#define    BM_RXCIHA3	(uint8_t)(1U<<RXCIHA3)
#define    RXCIHA4         4       /* Rx CRC Init value (16-bit RXCI) High byte for data path A bit 4 */
#define    BM_RXCIHA4	(uint8_t)(1U<<RXCIHA4)
#define    RXCIHA5         5       /* Rx CRC Init value (16-bit RXCI) High byte for data path A bit 5 */
#define    BM_RXCIHA5	(uint8_t)(1U<<RXCIHA5)
#define    RXCIHA6         6       /* Rx CRC Init value (16-bit RXCI) High byte for data path A bit 6 */
#define    BM_RXCIHA6	(uint8_t)(1U<<RXCIHA6)
#define    RXCIHA7         7       /* Rx CRC Init value (16-bit RXCI) High byte for data path A bit 7 */
#define    BM_RXCIHA7	(uint8_t)(1U<<RXCIHA7)

/* RXCIHB - Rx CRC Init value high byte for data path B */
#define    RXCIHB0         0       /* Rx CRC Init value (16-bit RXCI) High byte for data path B bit 0 */
#define    BM_RXCIHB0	(uint8_t)(1U<<RXCIHB0)
#define    RXCIHB1         1       /* Rx CRC Init value (16-bit RXCI) High byte for data path B bit 1 */
#define    BM_RXCIHB1	(uint8_t)(1U<<RXCIHB1)
#define    RXCIHB2         2       /* Rx CRC Init value (16-bit RXCI) High byte for data path B bit 2 */
#define    BM_RXCIHB2	(uint8_t)(1U<<RXCIHB2)
#define    RXCIHB3         3       /* Rx CRC Init value (16-bit RXCI) High byte for data path B bit 3 */
#define    BM_RXCIHB3	(uint8_t)(1U<<RXCIHB3)
#define    RXCIHB4         4       /* Rx CRC Init value (16-bit RXCI) High byte for data path B bit 4 */
#define    BM_RXCIHB4	(uint8_t)(1U<<RXCIHB4)
#define    RXCIHB5         5       /* Rx CRC Init value (16-bit RXCI) High byte for data path B bit 5 */
#define    BM_RXCIHB5	(uint8_t)(1U<<RXCIHB5)
#define    RXCIHB6         6       /* Rx CRC Init value (16-bit RXCI) High byte for data path B bit 6 */
#define    BM_RXCIHB6	(uint8_t)(1U<<RXCIHB6)
#define    RXCIHB7         7       /* Rx CRC Init value (16-bit RXCI) High byte for data path B bit 7 */
#define    BM_RXCIHB7	(uint8_t)(1U<<RXCIHB7)

/* RXCILA - Rx CRC Init value low byte for data path A */
#define    RXCILA0         0       /* Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 0 */
#define    BM_RXCILA0	(uint8_t)(1U<<RXCILA0)
#define    RXCILA1         1       /* Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 1 */
#define    BM_RXCILA1	(uint8_t)(1U<<RXCILA1)
#define    RXCILA2         2       /* Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 2 */
#define    BM_RXCILA2	(uint8_t)(1U<<RXCILA2)
#define    RXCILA3         3       /* Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 3 */
#define    BM_RXCILA3	(uint8_t)(1U<<RXCILA3)
#define    RXCILA4         4       /* Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 4 */
#define    BM_RXCILA4	(uint8_t)(1U<<RXCILA4)
#define    RXCILA5         5       /* Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 5 */
#define    BM_RXCILA5	(uint8_t)(1U<<RXCILA5)
#define    RXCILA6         6       /* Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 6 */
#define    BM_RXCILA6	(uint8_t)(1U<<RXCILA6)
#define    RXCILA7         7       /* Rx CRC Init value (16-bit RXCI) Low byte for data path A bit 7 */
#define    BM_RXCILA7	(uint8_t)(1U<<RXCILA7)

/* RXCILB - Rx CRC Init value low byte for data path B */
#define    RXCILB0         0       /* Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 0 */
#define    BM_RXCILB0	(uint8_t)(1U<<RXCILB0)
#define    RXCILB1         1       /* Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 1 */
#define    BM_RXCILB1	(uint8_t)(1U<<RXCILB1)
#define    RXCILB2         2       /* Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 2 */
#define    BM_RXCILB2	(uint8_t)(1U<<RXCILB2)
#define    RXCILB3         3       /* Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 3 */
#define    BM_RXCILB3	(uint8_t)(1U<<RXCILB3)
#define    RXCILB4         4       /* Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 4 */
#define    BM_RXCILB4	(uint8_t)(1U<<RXCILB4)
#define    RXCILB5         5       /* Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 5 */
#define    BM_RXCILB5	(uint8_t)(1U<<RXCILB5)
#define    RXCILB6         6       /* Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 6 */
#define    BM_RXCILB6	(uint8_t)(1U<<RXCILB6)
#define    RXCILB7         7       /* Rx CRC Init value (16-bit RXCI) Low byte for data path B bit 7 */
#define    BM_RXCILB7	(uint8_t)(1U<<RXCILB7)

/* RXCPHA - Rx CRC polynomial high byte for data path A */
#define    RXCPHA0         0       /* Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 0 */
#define    BM_RXCPHA0	(uint8_t)(1U<<RXCPHA0)
#define    RXCPHA1         1       /* Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 1 */
#define    BM_RXCPHA1	(uint8_t)(1U<<RXCPHA1)
#define    RXCPHA2         2       /* Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 2 */
#define    BM_RXCPHA2	(uint8_t)(1U<<RXCPHA2)
#define    RXCPHA3         3       /* Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 3 */
#define    BM_RXCPHA3	(uint8_t)(1U<<RXCPHA3)
#define    RXCPHA4         4       /* Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 4 */
#define    BM_RXCPHA4	(uint8_t)(1U<<RXCPHA4)
#define    RXCPHA5         5       /* Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 5 */
#define    BM_RXCPHA5	(uint8_t)(1U<<RXCPHA5)
#define    RXCPHA6         6       /* Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 6 */
#define    BM_RXCPHA6	(uint8_t)(1U<<RXCPHA6)
#define    RXCPHA7         7       /* Rx CRC Polynomial (15 bit RXCPA) High byte for data path A bit 7 */
#define    BM_RXCPHA7	(uint8_t)(1U<<RXCPHA7)

/* RXCPHB - Rx CRC polynomial high byte for data path B */
#define    RXCPHB0         0       /* Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 0 */
#define    BM_RXCPHB0	(uint8_t)(1U<<RXCPHB0)
#define    RXCPHB1         1       /* Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 1 */
#define    BM_RXCPHB1	(uint8_t)(1U<<RXCPHB1)
#define    RXCPHB2         2       /* Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 2 */
#define    BM_RXCPHB2	(uint8_t)(1U<<RXCPHB2)
#define    RXCPHB3         3       /* Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 3 */
#define    BM_RXCPHB3	(uint8_t)(1U<<RXCPHB3)
#define    RXCPHB4         4       /* Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 4 */
#define    BM_RXCPHB4	(uint8_t)(1U<<RXCPHB4)
#define    RXCPHB5         5       /* Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 5 */
#define    BM_RXCPHB5	(uint8_t)(1U<<RXCPHB5)
#define    RXCPHB6         6       /* Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 6 */
#define    BM_RXCPHB6	(uint8_t)(1U<<RXCPHB6)
#define    RXCPHB7         7       /* Rx CRC Polynomial (15 bit RXCPB) High Byte for data path B bit 7 */
#define    BM_RXCPHB7	(uint8_t)(1U<<RXCPHB7)

/* RXCPLA - Rx CRC polynomial low byte for data path A */
#define    RXCPLA1         1       /* Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 1 */
#define    BM_RXCPLA1	(uint8_t)(1U<<RXCPLA1)
#define    RXCPLA2         2       /* Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 2 */
#define    BM_RXCPLA2	(uint8_t)(1U<<RXCPLA2)
#define    RXCPLA3         3       /* Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 3 */
#define    BM_RXCPLA3	(uint8_t)(1U<<RXCPLA3)
#define    RXCPLA4         4       /* Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 4 */
#define    BM_RXCPLA4	(uint8_t)(1U<<RXCPLA4)
#define    RXCPLA5         5       /* Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 5 */
#define    BM_RXCPLA5	(uint8_t)(1U<<RXCPLA5)
#define    RXCPLA6         6       /* Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 6 */
#define    BM_RXCPLA6	(uint8_t)(1U<<RXCPLA6)
#define    RXCPLA7         7       /* Rx CRC Polynomial (15 bit RXCPA) Low byte for data path A bit 7 */
#define    BM_RXCPLA7	(uint8_t)(1U<<RXCPLA7)

/* RXCPLB - Rx CRC polynomial low byte for data path B */
#define    RXCPLB1         1       /* Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 1 */
#define    BM_RXCPLB1	(uint8_t)(1U<<RXCPLB1)
#define    RXCPLB2         2       /* Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 2 */
#define    BM_RXCPLB2	(uint8_t)(1U<<RXCPLB2)
#define    RXCPLB3         3       /* Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 3 */
#define    BM_RXCPLB3	(uint8_t)(1U<<RXCPLB3)
#define    RXCPLB4         4       /* Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 4 */
#define    BM_RXCPLB4	(uint8_t)(1U<<RXCPLB4)
#define    RXCPLB5         5       /* Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 5 */
#define    BM_RXCPLB5	(uint8_t)(1U<<RXCPLB5)
#define    RXCPLB6         6       /* Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 6 */
#define    BM_RXCPLB6	(uint8_t)(1U<<RXCPLB6)
#define    RXCPLB7         7       /* Rx CRC Polynomial (15 bit RXCPB) Low Byte for data path B bit 7 */
#define    BM_RXCPLB7	(uint8_t)(1U<<RXCPLB7)

/* RXCRHA - Rx CRC result register high byte for data path A */
#define    RXCRHA0         0       /* Rx CRC Result register High byte for data path A bit 0 */
#define    BM_RXCRHA0	(uint8_t)(1U<<RXCRHA0)
#define    RXCRHA1         1       /* Rx CRC Result register High byte for data path A bit 1 */
#define    BM_RXCRHA1	(uint8_t)(1U<<RXCRHA1)
#define    RXCRHA2         2       /* Rx CRC Result register High byte for data path A bit 2 */
#define    BM_RXCRHA2	(uint8_t)(1U<<RXCRHA2)
#define    RXCRHA3         3       /* Rx CRC Result register High byte for data path A bit 3 */
#define    BM_RXCRHA3	(uint8_t)(1U<<RXCRHA3)
#define    RXCRHA4         4       /* Rx CRC Result register High byte for data path A bit 4 */
#define    BM_RXCRHA4	(uint8_t)(1U<<RXCRHA4)
#define    RXCRHA5         5       /* Rx CRC Result register High byte for data path A bit 5 */
#define    BM_RXCRHA5	(uint8_t)(1U<<RXCRHA5)
#define    RXCRHA6         6       /* Rx CRC Result register High byte for data path A bit 6 */
#define    BM_RXCRHA6	(uint8_t)(1U<<RXCRHA6)
#define    RXCRHA7         7       /* Rx CRC Result register High byte for data path A bit 7 */
#define    BM_RXCRHA7	(uint8_t)(1U<<RXCRHA7)

/* RXCRHB - Rx CRC result register high byte for data path B */
#define    RXCRHB0         0       /* Rx CRC Result register High Byte for data path B bit 0 */
#define    BM_RXCRHB0	(uint8_t)(1U<<RXCRHB0)
#define    RXCRHB1         1       /* Rx CRC Result register High Byte for data path B bit 1 */
#define    BM_RXCRHB1	(uint8_t)(1U<<RXCRHB1)
#define    RXCRHB2         2       /* Rx CRC Result register High Byte for data path B bit 2 */
#define    BM_RXCRHB2	(uint8_t)(1U<<RXCRHB2)
#define    RXCRHB3         3       /* Rx CRC Result register High Byte for data path B bit 3 */
#define    BM_RXCRHB3	(uint8_t)(1U<<RXCRHB3)
#define    RXCRHB4         4       /* Rx CRC Result register High Byte for data path B bit 4 */
#define    BM_RXCRHB4	(uint8_t)(1U<<RXCRHB4)
#define    RXCRHB5         5       /* Rx CRC Result register High Byte for data path B bit 5 */
#define    BM_RXCRHB5	(uint8_t)(1U<<RXCRHB5)
#define    RXCRHB6         6       /* Rx CRC Result register High Byte for data path B bit 6 */
#define    BM_RXCRHB6	(uint8_t)(1U<<RXCRHB6)
#define    RXCRHB7         7       /* Rx CRC Result register High Byte for data path B bit 7 */
#define    BM_RXCRHB7	(uint8_t)(1U<<RXCRHB7)

/* RXCRLA - Rx CRC result register low byte for data path A */
#define    RXCRLA0         0       /* Rx CRC Result register Low byte for data path A bit 0 */
#define    BM_RXCRLA0	(uint8_t)(1U<<RXCRLA0)
#define    RXCRLA1         1       /* Rx CRC Result register Low byte for data path A bit 1 */
#define    BM_RXCRLA1	(uint8_t)(1U<<RXCRLA1)
#define    RXCRLA2         2       /* Rx CRC Result register Low byte for data path A bit 2 */
#define    BM_RXCRLA2	(uint8_t)(1U<<RXCRLA2)
#define    RXCRLA3         3       /* Rx CRC Result register Low byte for data path A bit 3 */
#define    BM_RXCRLA3	(uint8_t)(1U<<RXCRLA3)
#define    RXCRLA4         4       /* Rx CRC Result register Low byte for data path A bit 4 */
#define    BM_RXCRLA4	(uint8_t)(1U<<RXCRLA4)
#define    RXCRLA5         5       /* Rx CRC Result register Low byte for data path A bit 5 */
#define    BM_RXCRLA5	(uint8_t)(1U<<RXCRLA5)
#define    RXCRLA6         6       /* Rx CRC Result register Low byte for data path A bit 6 */
#define    BM_RXCRLA6	(uint8_t)(1U<<RXCRLA6)
#define    RXCRLA7         7       /* Rx CRC Result register Low byte for data path A bit 7 */
#define    BM_RXCRLA7	(uint8_t)(1U<<RXCRLA7)

/* RXCRLB - Rx CRC result register low byte for data path B */
#define    RXCRLB0         0       /* Rx CRC Result register Low Byte for data path B bit 0 */
#define    BM_RXCRLB0	(uint8_t)(1U<<RXCRLB0)
#define    RXCRLB1         1       /* Rx CRC Result register Low Byte for data path B bit 1 */
#define    BM_RXCRLB1	(uint8_t)(1U<<RXCRLB1)
#define    RXCRLB2         2       /* Rx CRC Result register Low Byte for data path B bit 2 */
#define    BM_RXCRLB2	(uint8_t)(1U<<RXCRLB2)
#define    RXCRLB3         3       /* Rx CRC Result register Low Byte for data path B bit 3 */
#define    BM_RXCRLB3	(uint8_t)(1U<<RXCRLB3)
#define    RXCRLB4         4       /* Rx CRC Result register Low Byte for data path B bit 4 */
#define    BM_RXCRLB4	(uint8_t)(1U<<RXCRLB4)
#define    RXCRLB5         5       /* Rx CRC Result register Low Byte for data path B bit 5 */
#define    BM_RXCRLB5	(uint8_t)(1U<<RXCRLB5)
#define    RXCRLB6         6       /* Rx CRC Result register Low Byte for data path B bit 6 */
#define    BM_RXCRLB6	(uint8_t)(1U<<RXCRLB6)
#define    RXCRLB7         7       /* Rx CRC Result register Low Byte for data path B bit 7 */
#define    BM_RXCRLB7	(uint8_t)(1U<<RXCRLB7)

/* RXCSBA - Rx CRC skip bit number for data path A */
#define    RXCSBA0         0       /* Rx CRC Skip Bit number for data path A bit 0 */
#define    BM_RXCSBA0	(uint8_t)(1U<<RXCSBA0)
#define    RXCSBA1         1       /* Rx CRC Skip Bit number for data path A bit 1 */
#define    BM_RXCSBA1	(uint8_t)(1U<<RXCSBA1)
#define    RXCSBA2         2       /* Rx CRC Skip Bit number for data path A bit 2 */
#define    BM_RXCSBA2	(uint8_t)(1U<<RXCSBA2)
#define    RXCSBA3         3       /* Rx CRC Skip Bit number for data path A bit 3 */
#define    BM_RXCSBA3	(uint8_t)(1U<<RXCSBA3)
#define    RXCSBA4         4       /* Rx CRC Skip Bit number for data path A bit 4 */
#define    BM_RXCSBA4	(uint8_t)(1U<<RXCSBA4)
#define    RXCSBA5         5       /* Rx CRC Skip Bit number for data path A bit 5 */
#define    BM_RXCSBA5	(uint8_t)(1U<<RXCSBA5)
#define    RXCSBA6         6       /* Rx CRC Skip Bit number for data path A bit 6 */
#define    BM_RXCSBA6	(uint8_t)(1U<<RXCSBA6)
#define    RXCSBA7         7       /* Rx CRC Skip Bit number for data path A bit 7 */
#define    BM_RXCSBA7	(uint8_t)(1U<<RXCSBA7)

/* RXCSBB - Rx CRC skip bit number for data path B */
#define    RXCSBB0         0       /* Rx CRC Skip Bit number for data path B bit 0 */
#define    BM_RXCSBB0	(uint8_t)(1U<<RXCSBB0)
#define    RXCSBB1         1       /* Rx CRC Skip Bit number for data path B bit 1 */
#define    BM_RXCSBB1	(uint8_t)(1U<<RXCSBB1)
#define    RXCSBB2         2       /* Rx CRC Skip Bit number for data path B bit 2 */
#define    BM_RXCSBB2	(uint8_t)(1U<<RXCSBB2)
#define    RXCSBB3         3       /* Rx CRC Skip Bit number for data path B bit 3 */
#define    BM_RXCSBB3	(uint8_t)(1U<<RXCSBB3)
#define    RXCSBB4         4       /* Rx CRC Skip Bit number for data path B bit 4 */
#define    BM_RXCSBB4	(uint8_t)(1U<<RXCSBB4)
#define    RXCSBB5         5       /* Rx CRC Skip Bit number for data path B bit 5 */
#define    BM_RXCSBB5	(uint8_t)(1U<<RXCSBB5)
#define    RXCSBB6         6       /* Rx CRC Skip Bit number for data path B bit 6 */
#define    BM_RXCSBB6	(uint8_t)(1U<<RXCSBB6)
#define    RXCSBB7         7       /* Rx CRC Skip Bit number for data path B bit 7 */
#define    BM_RXCSBB7	(uint8_t)(1U<<RXCSBB7)

/* RXDSA - Rx data shift register for data path A */
#define    RXDSA0          0       /* Receive Data Shift register for data path A bit 0 */
#define    BM_RXDSA0	(uint8_t)(1U<<RXDSA0)
#define    RXDSA1          1       /* Receive Data Shift register for data path A bit 1 */
#define    BM_RXDSA1	(uint8_t)(1U<<RXDSA1)
#define    RXDSA2          2       /* Receive Data Shift register for data path A bit 2 */
#define    BM_RXDSA2	(uint8_t)(1U<<RXDSA2)
#define    RXDSA3          3       /* Receive Data Shift register for data path A bit 3 */
#define    BM_RXDSA3	(uint8_t)(1U<<RXDSA3)
#define    RXDSA4          4       /* Receive Data Shift register for data path A bit 4 */
#define    BM_RXDSA4	(uint8_t)(1U<<RXDSA4)
#define    RXDSA5          5       /* Receive Data Shift register for data path A bit 5 */
#define    BM_RXDSA5	(uint8_t)(1U<<RXDSA5)
#define    RXDSA6          6       /* Receive Data Shift register for data path A bit 6 */
#define    BM_RXDSA6	(uint8_t)(1U<<RXDSA6)
#define    RXDSA7          7       /* Receive Data Shift register for data path A bit 7 */
#define    BM_RXDSA7	(uint8_t)(1U<<RXDSA7)

/* RXDSB - Rx data shift register for data path B */
#define    RXDSB0          0       /* Receive Data Shift register for data path B bit 0 */
#define    BM_RXDSB0	(uint8_t)(1U<<RXDSB0)
#define    RXDSB1          1       /* Receive Data Shift register for data path B bit 1 */
#define    BM_RXDSB1	(uint8_t)(1U<<RXDSB1)
#define    RXDSB2          2       /* Receive Data Shift register for data path B bit 2 */
#define    BM_RXDSB2	(uint8_t)(1U<<RXDSB2)
#define    RXDSB3          3       /* Receive Data Shift register for data path B bit 3 */
#define    BM_RXDSB3	(uint8_t)(1U<<RXDSB3)
#define    RXDSB4          4       /* Receive Data Shift register for data path B bit 4 */
#define    BM_RXDSB4	(uint8_t)(1U<<RXDSB4)
#define    RXDSB5          5       /* Receive Data Shift register for data path B bit 5 */
#define    BM_RXDSB5	(uint8_t)(1U<<RXDSB5)
#define    RXDSB6          6       /* Receive Data Shift register for data path B bit 6 */
#define    BM_RXDSB6	(uint8_t)(1U<<RXDSB6)
#define    RXDSB7          7       /* Receive Data Shift register for data path B bit 7 */
#define    BM_RXDSB7	(uint8_t)(1U<<RXDSB7)

/* RXTLHA - Rx data telegram length register high byte for data path A */
#define    RXTLHA0         0       /* RXTL (Receive Telegram Length) register High byte for data path A bit 0 */
#define    BM_RXTLHA0	(uint8_t)(1U<<RXTLHA0)
#define    RXTLHA1         1       /* RXTL (Receive Telegram Length) register High byte for data path A bit 1 */
#define    BM_RXTLHA1	(uint8_t)(1U<<RXTLHA1)
#define    RXTLHA2         2       /* RXTL (Receive Telegram Length) register High byte for data path A bit 2 */
#define    BM_RXTLHA2	(uint8_t)(1U<<RXTLHA2)
#define    RXTLHA3         3       /* RXTL (Receive Telegram Length) register High byte for data path A bit 3 */
#define    BM_RXTLHA3	(uint8_t)(1U<<RXTLHA3)

/* RXTLHB - Rx data telegram length register high byte for data path B */
#define    RXTLHB0         0       /* RXTL (Receive Telegram Length) register High byte for data path B bit 0 */
#define    BM_RXTLHB0	(uint8_t)(1U<<RXTLHB0)
#define    RXTLHB1         1       /* RXTL (Receive Telegram Length) register High byte for data path B bit 1 */
#define    BM_RXTLHB1	(uint8_t)(1U<<RXTLHB1)
#define    RXTLHB2         2       /* RXTL (Receive Telegram Length) register High byte for data path B bit 2 */
#define    BM_RXTLHB2	(uint8_t)(1U<<RXTLHB2)
#define    RXTLHB3         3       /* RXTL (Receive Telegram Length) register High byte for data path B bit 3 */
#define    BM_RXTLHB3	(uint8_t)(1U<<RXTLHB3)

/* RXTLLA - Rx data telegram length register low byte for data path A */
#define    RXTLLA0         0       /* RXTL (Receive Telegram Length) register Low value for data path A bit 0 */
#define    BM_RXTLLA0	(uint8_t)(1U<<RXTLLA0)
#define    RXTLLA1         1       /* RXTL (Receive Telegram Length) register Low value for data path A bit 1 */
#define    BM_RXTLLA1	(uint8_t)(1U<<RXTLLA1)
#define    RXTLLA2         2       /* RXTL (Receive Telegram Length) register Low value for data path A bit 2 */
#define    BM_RXTLLA2	(uint8_t)(1U<<RXTLLA2)
#define    RXTLLA3         3       /* RXTL (Receive Telegram Length) register Low value for data path A bit 3 */
#define    BM_RXTLLA3	(uint8_t)(1U<<RXTLLA3)
#define    RXTLLA4         4       /* RXTL (Receive Telegram Length) register Low value for data path A bit 4 */
#define    BM_RXTLLA4	(uint8_t)(1U<<RXTLLA4)
#define    RXTLLA5         5       /* RXTL (Receive Telegram Length) register Low value for data path A bit 5 */
#define    BM_RXTLLA5	(uint8_t)(1U<<RXTLLA5)
#define    RXTLLA6         6       /* RXTL (Receive Telegram Length) register Low value for data path A bit 6 */
#define    BM_RXTLLA6	(uint8_t)(1U<<RXTLLA6)
#define    RXTLLA7         7       /* RXTL (Receive Telegram Length) register Low value for data path A bit 7 */
#define    BM_RXTLLA7	(uint8_t)(1U<<RXTLLA7)

/* RXTLLB - Rx data telegram length register low byte for data path B */
#define    RXTLLB0         0       /* RXTL (Receive Telegram Length) register Low byte for data path B bit 0 */
#define    BM_RXTLLB0	(uint8_t)(1U<<RXTLLB0)
#define    RXTLLB1         1       /* RXTL (Receive Telegram Length) register Low byte for data path B bit 1 */
#define    BM_RXTLLB1	(uint8_t)(1U<<RXTLLB1)
#define    RXTLLB2         2       /* RXTL (Receive Telegram Length) register Low byte for data path B bit 2 */
#define    BM_RXTLLB2	(uint8_t)(1U<<RXTLLB2)
#define    RXTLLB3         3       /* RXTL (Receive Telegram Length) register Low byte for data path B bit 3 */
#define    BM_RXTLLB3	(uint8_t)(1U<<RXTLLB3)
#define    RXTLLB4         4       /* RXTL (Receive Telegram Length) register Low byte for data path B bit 4 */
#define    BM_RXTLLB4	(uint8_t)(1U<<RXTLLB4)
#define    RXTLLB5         5       /* RXTL (Receive Telegram Length) register Low byte for data path B bit 5 */
#define    BM_RXTLLB5	(uint8_t)(1U<<RXTLLB5)
#define    RXTLLB6         6       /* RXTL (Receive Telegram Length) register Low byte for data path B bit 6 */
#define    BM_RXTLLB6	(uint8_t)(1U<<RXTLLB6)
#define    RXTLLB7         7       /* RXTL (Receive Telegram Length) register Low byte for data path B bit 7 */
#define    BM_RXTLLB7	(uint8_t)(1U<<RXTLLB7)


/* ***** RXDSP ************************ */
/* EOTCA - End Of Telegram Conditions for path A */
#define    CARFEA          0       /* CARrier check Failed Enable for path A */
#define    BM_CARFEA	(uint8_t)(1U<<CARFEA)
#define    AMPFEA          1       /* AMPlitude Failed Enable for path A */
#define    BM_AMPFEA	(uint8_t)(1U<<AMPFEA)
#define    SYTFEA          2       /* SYmbol Timing check Failed Enable for path A */
#define    BM_SYTFEA	(uint8_t)(1U<<SYTFEA)
#define    MANFEA          3       /* MANchester Coding Failed Enable for path A */
#define    BM_MANFEA	(uint8_t)(1U<<MANFEA)
#define    TMOFEA          4       /* Time-Out Fail Enable on path A */
#define    BM_TMOFEA	(uint8_t)(1U<<TMOFEA)
#define    TELREA          5       /* Telegram Length Reached Enable on path A */
#define    BM_TELREA	(uint8_t)(1U<<TELREA)
#define    RRFEA           6       /* RSSI Range Fail Enable on path A */
#define    BM_RRFEA	(uint8_t)(1U<<RRFEA)
#define    EOTBFE          7       /* End Of Telegram on path B Fail Enable */
#define    BM_EOTBFE	(uint8_t)(1U<<EOTBFE)

/* EOTCB - End Of Telegram Conditions for path B */
#define    CARFEB          0       /* CARrier check Failed Enable for path B */
#define    BM_CARFEB	(uint8_t)(1U<<CARFEB)
#define    AMPFEB          1       /* AMPlitude Failed Enable for path B */
#define    BM_AMPFEB	(uint8_t)(1U<<AMPFEB)
#define    SYTFEB          2       /* SYmbol Timing check Failed Enable for path B */
#define    BM_SYTFEB	(uint8_t)(1U<<SYTFEB)
#define    MANFEB          3       /* MANchester Coding Failed Enable for path B */
#define    BM_MANFEB	(uint8_t)(1U<<MANFEB)
#define    TMOFEB          4       /* Time-Out Fail Enable on path B */
#define    BM_TMOFEB	(uint8_t)(1U<<TMOFEB)
#define    TELREB          5       /* Telegram Length Reached Enable on path B */
#define    BM_TELREB	(uint8_t)(1U<<TELREB)
#define    RRFEB           6       /* RSSI Range Fail Enable on path B */
#define    BM_RRFEB	(uint8_t)(1U<<RRFEB)
#define    EOTAFE          7       /* End Of Telegram on path B Fail Enable */
#define    BM_EOTAFE	(uint8_t)(1U<<EOTAFE)

/* EOTSA - End Of Telegram Status on path A */
#define    CARFA           0       /* CARrier check Failed on path A */
#define    BM_CARFA	(uint8_t)(1U<<CARFA)
#define    AMPFA           1       /* AMPlitude Failed on path A */
#define    BM_AMPFA	(uint8_t)(1U<<AMPFA)
#define    SYTFA           2       /* SYmbol Timing check Failed on path A */
#define    BM_SYTFA	(uint8_t)(1U<<SYTFA)
#define    MANFA           3       /* MANchester coding Failed on path A */
#define    BM_MANFA	(uint8_t)(1U<<MANFA)
#define    TMOFA           4       /* Time-Out Fail on path A */
#define    BM_TMOFA	(uint8_t)(1U<<TMOFA)
#define    TELRA           5       /* Telegram Length Reached on path A */
#define    BM_TELRA	(uint8_t)(1U<<TELRA)
#define    RRFA            6       /* RSSI Range Fail on path A */
#define    BM_RRFA	(uint8_t)(1U<<RRFA)
#define    EOTBF           7       /* End Of Telegram on path B Flag */
#define    BM_EOTBF	(uint8_t)(1U<<EOTBF)

/* EOTSB - End Of Telegram Status on path B */
#define    CARFB           0       /* CARrier check Failed on path B */
#define    BM_CARFB	(uint8_t)(1U<<CARFB)
#define    AMPFB           1       /* AMPlitude Failed on path B */
#define    BM_AMPFB	(uint8_t)(1U<<AMPFB)
#define    SYTFB           2       /* SYmbol Timing check Failed on path B */
#define    BM_SYTFB	(uint8_t)(1U<<SYTFB)
#define    MANFB           3       /* MANchester coding Failed on path B */
#define    BM_MANFB	(uint8_t)(1U<<MANFB)
#define    TMOFB           4       /* Time-Out Fail on path B */
#define    BM_TMOFB	(uint8_t)(1U<<TMOFB)
#define    TELRB           5       /* Telegram Length Reached on path B */
#define    BM_TELRB	(uint8_t)(1U<<TELRB)
#define    RRFB            6       /* RSSI Range Fail on path B */
#define    BM_RRFB	(uint8_t)(1U<<RRFB)
#define    EOTAF           7       /* End Of Telegram on path A Flag */
#define    BM_EOTAF	(uint8_t)(1U<<EOTAF)

/* RDCR - Rx DSP control register */
#define    RDPU            0       /* Rx DSP Power Up */
#define    BM_RDPU	(uint8_t)(1U<<RDPU)
#define    ADIVEN          1       /* Divided ADC clock enable */
#define    BM_ADIVEN	(uint8_t)(1U<<ADIVEN)
#define    RDEN            2       /* Rx DSP enable */
#define    BM_RDEN	(uint8_t)(1U<<RDEN)

/* RDOCR - Rx DSP output control */
#define    TMDS0           1       /* Transparent Mode Data Select bit 0 */
#define    BM_TMDS0	(uint8_t)(1U<<TMDS0)
#define    TMDS1           2       /* Transparent Mode Data Select bit 1 */
#define    BM_TMDS1	(uint8_t)(1U<<TMDS1)
#define    ETRPA           3       /* Enable Transparent Path A */
#define    BM_ETRPA	(uint8_t)(1U<<ETRPA)
#define    ETRPB           4       /* Enable Transparent Path B */
#define    BM_ETRPB	(uint8_t)(1U<<ETRPB)
#define    RDSIDA          5       /* Rx DSP Start bit Is Data for path A */
#define    BM_RDSIDA	(uint8_t)(1U<<RDSIDA)
#define    RDSIDB          6       /* Rx DSP Start bit Is Data for path B */
#define    BM_RDSIDB	(uint8_t)(1U<<RDSIDB)

/* RDSIFR - Rx DSP status interrupt flag register */
#define    NBITA           0       /* New Bit on Rx path A */
#define    BM_NBITA	(uint8_t)(1U<<NBITA)
#define    NBITB           1       /* New Bit on Rx path B */
#define    BM_NBITB	(uint8_t)(1U<<NBITB)
#define    EOTA            2       /* End Of Telegram on path A */
#define    BM_EOTA	(uint8_t)(1U<<EOTA)
#define    EOTB            3       /* End Of Telegram on path B */
#define    BM_EOTB	(uint8_t)(1U<<EOTB)
#define    SOTA            4       /* Start Of Telegram on path A */
#define    BM_SOTA	(uint8_t)(1U<<SOTA)
#define    SOTB            5       /* Start Of Telegram on path B */
#define    BM_SOTB	(uint8_t)(1U<<SOTB)
#define    WCOA            6       /* Wake Conditions Ok on path A */
#define    BM_WCOA	(uint8_t)(1U<<WCOA)
#define    WCOB            7       /* Wake Conditions Ok on path B */
#define    BM_WCOB	(uint8_t)(1U<<WCOB)

/* RDSIMR - Rx DSP status interrupt mask register */
#define    NBITAM          0       /* New bit on Rx path A interrupt mask register */
#define    BM_NBITAM	(uint8_t)(1U<<NBITAM)
#define    NBITBM          1       /* New bit on Rx path B interrupt mask register */
#define    BM_NBITBM	(uint8_t)(1U<<NBITBM)
#define    EOTAM           2       /* End Of Telegram on Rx path A interrupt mask register */
#define    BM_EOTAM	(uint8_t)(1U<<EOTAM)
#define    EOTBM           3       /* End Of Telegram on Rx path B interrupt mask register */
#define    BM_EOTBM	(uint8_t)(1U<<EOTBM)
#define    SOTAM           4       /* Start Of Telegram on Rx path A interrupt mask register */
#define    BM_SOTAM	(uint8_t)(1U<<SOTAM)
#define    SOTBM           5       /* Start Of Telegram on Rx path B interrupt mask register */
#define    BM_SOTBM	(uint8_t)(1U<<SOTBM)
#define    WCOAM           6       /* Wake Conditions Ok on path A interrupt mask register */
#define    BM_WCOAM	(uint8_t)(1U<<WCOAM)
#define    WCOBM           7       /* Wake Conditions Ok on path B interrupt mask register */
#define    BM_WCOBM	(uint8_t)(1U<<WCOBM)

/* SOTCA - Start Of Telegram Conditions for path A */
#define    CAROEA          0       /* CARrier check Ok Enabled for path A */
#define    BM_CAROEA	(uint8_t)(1U<<CAROEA)
#define    AMPOEA          1       /* AMPlitude Ok Enabled for path A */
#define    BM_AMPOEA	(uint8_t)(1U<<AMPOEA)
#define    SYTOEA          2       /* Symbol Timing Ok Enabled for path A */
#define    BM_SYTOEA	(uint8_t)(1U<<SYTOEA)
#define    MANOEA          3       /* Manchester Coding Ok Enabled for path A */
#define    BM_MANOEA	(uint8_t)(1U<<MANOEA)
#define    WUPEA           4       /* Wake Up Pattern match Enabled for path A */
#define    BM_WUPEA	(uint8_t)(1U<<WUPEA)
#define    SFIDEA          5       /* Start of Frame IDentifier match Enabled for path A */
#define    BM_SFIDEA	(uint8_t)(1U<<SFIDEA)
#define    RROEA           6       /* RSSI Range OK Enable for path A */
#define    BM_RROEA	(uint8_t)(1U<<RROEA)
#define    WCOBOE          7       /* Wake Check OK from path B Ok Enable */
#define    BM_WCOBOE	(uint8_t)(1U<<WCOBOE)

/* SOTCB - Start Of Telegram Conditions for path B */
#define    CAROEB          0       /* CARrier check Ok Enabled for path B */
#define    BM_CAROEB	(uint8_t)(1U<<CAROEB)
#define    AMPOEB          1       /* AMPlitude Ok Enabled for path B */
#define    BM_AMPOEB	(uint8_t)(1U<<AMPOEB)
#define    SYTOEB          2       /* Symbol Timing Ok Enabled for path B */
#define    BM_SYTOEB	(uint8_t)(1U<<SYTOEB)
#define    MANOEB          3       /* Manchester Coding Ok Enabled for path B */
#define    BM_MANOEB	(uint8_t)(1U<<MANOEB)
#define    WUPEB           4       /* Wake Up Pattern match Enabled for path B */
#define    BM_WUPEB	(uint8_t)(1U<<WUPEB)
#define    SFIDEB          5       /* Start of Frame IDentifier match Enabled for path B */
#define    BM_SFIDEB	(uint8_t)(1U<<SFIDEB)
#define    RROEB           6       /* RSSI Range OK Enable for path B */
#define    BM_RROEB	(uint8_t)(1U<<RROEB)
#define    WCOAOE          7       /* Wake Check OK from path A Ok Enable */
#define    BM_WCOAOE	(uint8_t)(1U<<WCOAOE)

/* SOTSA - Start Of Telegram Status for path A */
#define    CAROA           0       /* CARrier check Ok on path A */
#define    BM_CAROA	(uint8_t)(1U<<CAROA)
#define    AMPOA           1       /* AMPlitude Ok on path A */
#define    BM_AMPOA	(uint8_t)(1U<<AMPOA)
#define    SYTOA           2       /* Symbol Timing Ok on path A */
#define    BM_SYTOA	(uint8_t)(1U<<SYTOA)
#define    MANOA           3       /* Manchester Coding Ok on path A */
#define    BM_MANOA	(uint8_t)(1U<<MANOA)
#define    WUPOA           4       /* Wake Up Pattern matched on path A */
#define    BM_WUPOA	(uint8_t)(1U<<WUPOA)
#define    SFIDOA          5       /* Start of Frame IDentifier matched on path A */
#define    BM_SFIDOA	(uint8_t)(1U<<SFIDOA)
#define    RROA            6       /* RSSI Range Ok on Path A */
#define    BM_RROA	(uint8_t)(1U<<RROA)
#define    WCOBO           7       /* Wake Check Ok on path B Ok */
#define    BM_WCOBO	(uint8_t)(1U<<WCOBO)

/* SOTSB - Start Of Telegram Status for path B */
#define    CAROB           0       /* CARrier check Ok on path B */
#define    BM_CAROB	(uint8_t)(1U<<CAROB)
#define    AMPOB           1       /* AMPlitude Ok on path B */
#define    BM_AMPOB	(uint8_t)(1U<<AMPOB)
#define    SYTOB           2       /* Symbol Timing Ok on path B */
#define    BM_SYTOB	(uint8_t)(1U<<SYTOB)
#define    MANOB           3       /* Manchester Coding Ok on path B */
#define    BM_MANOB	(uint8_t)(1U<<MANOB)
#define    WUPOB           4       /* Wake Up Pattern matched on path B */
#define    BM_WUPOB	(uint8_t)(1U<<WUPOB)
#define    SFIDOB          5       /* Start of Frame IDentifier matched on path B */
#define    BM_SFIDOB	(uint8_t)(1U<<SFIDOB)
#define    RROB            6       /* RSSI Range Ok on Path B */
#define    BM_RROB	(uint8_t)(1U<<RROB)
#define    WCOAO           7       /* Wake Check Ok on path A Ok */
#define    BM_WCOAO	(uint8_t)(1U<<WCOAO)

/* TESRA - Telegram Status Register on Path A */
#define    CRCOA           0       /* Cyclic Redundancy Check Ok on path A */
#define    BM_CRCOA	(uint8_t)(1U<<CRCOA)
#define    EOTLA0          1       /* End of Telegram Location on path A bit 0 */
#define    BM_EOTLA0	(uint8_t)(1U<<EOTLA0)
#define    EOTLA1          2       /* End of Telegram Location on path A bit 1 */
#define    BM_EOTLA1	(uint8_t)(1U<<EOTLA1)

/* TESRB - Telegram Status Register on Path B */
#define    CRCOB           0       /* Cyclic Redundancy Check Ok on path B */
#define    BM_CRCOB	(uint8_t)(1U<<CRCOB)
#define    EOTLB0          1       /* End of Telegram Location on path B bit 0 */
#define    BM_EOTLB0	(uint8_t)(1U<<EOTLB0)
#define    EOTLB1          2       /* End of Telegram Location on path B bit 1 */
#define    BM_EOTLB1	(uint8_t)(1U<<EOTLB1)


/* ***** SFIFO ************************ */
/* SFC - Support FIFO Configuration Register */
#define    SFFLC0          0       /* Support FIFO Fill-Level Configuration bit 0 */
#define    BM_SFFLC0	(uint8_t)(1U<<SFFLC0)
#define    SFFLC1          1       /* Support FIFO Fill-Level Configuration bit 1 */
#define    BM_SFFLC1	(uint8_t)(1U<<SFFLC1)
#define    SFFLC2          2       /* Support FIFO Fill-Level Configuration bit 2 */
#define    BM_SFFLC2	(uint8_t)(1U<<SFFLC2)
#define    SFFLC3          3       /* Support FIFO Fill-Level Configuration bit 3 */
#define    BM_SFFLC3	(uint8_t)(1U<<SFFLC3)
#define    SFFLC4          4       /* Support FIFO Fill-Level Configuration bit 4 */
#define    BM_SFFLC4	(uint8_t)(1U<<SFFLC4)
#define    SFDRA           7       /* Support FIFO Direct Read Access Operational Mode */
#define    BM_SFDRA	(uint8_t)(1U<<SFDRA)

/* SFI - Support FIFO Interrupt Mask Register */
#define    SFFLIM          0       /* Support FIFO Fill-level Interrupt Mask */
#define    BM_SFFLIM	(uint8_t)(1U<<SFFLIM)
#define    SFERIM          1       /* Support FIFO Error Interrupt Mask */
#define    BM_SFERIM	(uint8_t)(1U<<SFERIM)

/* SFL - Support FIFO Fill Level Register */
#define    SFFLS0          0       /* Support FIFO Fill Level Status bit 0 */
#define    BM_SFFLS0	(uint8_t)(1U<<SFFLS0)
#define    SFFLS1          1       /* Support FIFO Fill Level Status bit 1 */
#define    BM_SFFLS1	(uint8_t)(1U<<SFFLS1)
#define    SFFLS2          2       /* Support FIFO Fill Level Status bit 2 */
#define    BM_SFFLS2	(uint8_t)(1U<<SFFLS2)
#define    SFFLS3          3       /* Support FIFO Fill Level Status bit 3 */
#define    BM_SFFLS3	(uint8_t)(1U<<SFFLS3)
#define    SFFLS4          4       /* Support FIFO Fill Level Status bit 4 */
#define    BM_SFFLS4	(uint8_t)(1U<<SFFLS4)
#define    SFCLR           7       /* Support FIFO Clear */
#define    BM_SFCLR	(uint8_t)(1U<<SFCLR)

/* SFRP - Support FIFO Read Pointer */
#define    SFRP0           0       /* Support FIFO Read Pointer bit 0 */
#define    BM_SFRP0	(uint8_t)(1U<<SFRP0)
#define    SFRP1           1       /* Support FIFO Read Pointer bit 1 */
#define    BM_SFRP1	(uint8_t)(1U<<SFRP1)
#define    SFRP2           2       /* Support FIFO Read Pointer bit 2 */
#define    BM_SFRP2	(uint8_t)(1U<<SFRP2)
#define    SFRP3           3       /* Support FIFO Read Pointer bit 3 */
#define    BM_SFRP3	(uint8_t)(1U<<SFRP3)
#define    SFRP4           4       /* Support FIFO Read Pointer bit 4 */
#define    BM_SFRP4	(uint8_t)(1U<<SFRP4)

/* SFS - Support FIFO Status Register */
#define    SFFLRF          0       /* Support FIFO Fill-Level Reached Status Flag */
#define    BM_SFFLRF	(uint8_t)(1U<<SFFLRF)
#define    SFUFL           1       /* Support FIFO Underflow Flag */
#define    BM_SFUFL	(uint8_t)(1U<<SFUFL)
#define    SFOFL           2       /* Support FIFO Overflow Flag */
#define    BM_SFOFL	(uint8_t)(1U<<SFOFL)

/* SFWP - Support FIFO Write Pointer */
#define    SFWP0           0       /* Support FIFO Write Pointer bit 0 */
#define    BM_SFWP0	(uint8_t)(1U<<SFWP0)
#define    SFWP1           1       /* Support FIFO Write Pointer bit 1 */
#define    BM_SFWP1	(uint8_t)(1U<<SFWP1)
#define    SFWP2           2       /* Support FIFO Write Pointer bit 2 */
#define    BM_SFWP2	(uint8_t)(1U<<SFWP2)
#define    SFWP3           3       /* Support FIFO Write Pointer bit 3 */
#define    BM_SFWP3	(uint8_t)(1U<<SFWP3)
#define    SFWP4           4       /* Support FIFO Write Pointer bit 4 */
#define    BM_SFWP4	(uint8_t)(1U<<SFWP4)


/* ***** SPI ************************** */
/* SFFR - SPI FIFO Fill Status Register */
#define    RFL0            0       /* Receive Buffer Fill Level bit 0 */
#define    BM_RFL0	(uint8_t)(1U<<RFL0)
#define    RFL1            1       /* Receive Buffer Fill Level bit 1 */
#define    BM_RFL1	(uint8_t)(1U<<RFL1)
#define    RFL2            2       /* Receive Buffer Fill Level bit 2 */
#define    BM_RFL2	(uint8_t)(1U<<RFL2)
#define    RFC             3       /* Rx Buffer Clear */
#define    BM_RFC	(uint8_t)(1U<<RFC)
#define    TFL0            4       /* Transmit Buffer Fill Level bit 0 */
#define    BM_TFL0	(uint8_t)(1U<<TFL0)
#define    TFL1            5       /* Transmit Buffer Fill Level bit 1 */
#define    BM_TFL1	(uint8_t)(1U<<TFL1)
#define    TFL2            6       /* Transmit Buffer Fill Level bit 02 */
#define    BM_TFL2	(uint8_t)(1U<<TFL2)
#define    TFC             7       /* SPI Tx Buffer Clear */
#define    BM_TFC	(uint8_t)(1U<<TFC)

/* SFIR - SPI FIFO Interrupt Register */
#define    RIL0            0       /* Receive Buffer Interrupt Level bit 0 */
#define    BM_RIL0	(uint8_t)(1U<<RIL0)
#define    RIL1            1       /* Receive Buffer Interrupt Level bit 1 */
#define    BM_RIL1	(uint8_t)(1U<<RIL1)
#define    RIL2            2       /* Receive Buffer Interrupt Level bit 2 */
#define    BM_RIL2	(uint8_t)(1U<<RIL2)
#define    SRIE            3       /* Rx Buffer Interrupt Enable */
#define    BM_SRIE	(uint8_t)(1U<<SRIE)
#define    TIL0            4       /* Transmit Buffer Interrupt Level bit 0 */
#define    BM_TIL0	(uint8_t)(1U<<TIL0)
#define    TIL1            5       /* Transmit Buffer Interrupt Level bit 1 */
#define    BM_TIL1	(uint8_t)(1U<<TIL1)
#define    TIL2            6       /* Transmit Buffer Interrupt Level bit 2 */
#define    BM_TIL2	(uint8_t)(1U<<TIL2)
#define    STIE            7       /* SPI Tx Buffer Interrupt Enable */
#define    BM_STIE	(uint8_t)(1U<<STIE)

/* SPCR - SPI control Register */
#define    SPR0            0       /* SPI Clock Rate Select 0 */
#define    BM_SPR0	(uint8_t)(1U<<SPR0)
#define    SPR1            1       /* SPI Clock Rate Select 1 */
#define    BM_SPR1	(uint8_t)(1U<<SPR1)
#define    CPHA            2       /* Clock Phase */
#define    BM_CPHA	(uint8_t)(1U<<CPHA)
#define    CPOL            3       /* Clock Polarity */
#define    BM_CPOL	(uint8_t)(1U<<CPOL)
#define    MSTR            4       /* Master/Slave Select */
#define    BM_MSTR	(uint8_t)(1U<<MSTR)
#define    DORD            5       /* Data Order */
#define    BM_DORD	(uint8_t)(1U<<DORD)
#define    SPE             6       /* SPI Enable */
#define    BM_SPE	(uint8_t)(1U<<SPE)
#define    SPIE            7       /* Spe Interrupt Enable */
#define    BM_SPIE	(uint8_t)(1U<<SPIE)

/* SPSR - SPI Status Register */
#define    SPI2X           0       /* Double SPI Speed Bit */
#define    BM_SPI2X	(uint8_t)(1U<<SPI2X)
#define    RXIF            4       /* Rx Buffer Interrupt Flag */
#define    BM_RXIF	(uint8_t)(1U<<RXIF)
#define    TXIF            5       /* Tx Buffer Interrupt Flag */
#define    BM_TXIF	(uint8_t)(1U<<TXIF)
#define    SPIF            7       /* SPI Interrupt Flag */
#define    BM_SPIF	(uint8_t)(1U<<SPIF)


/* ***** SSM ************************** */
/* EOTC1A - End Of Telegram Conditions 1 for Path A */
#define    CARFEA1         0       /* CARrier check Failed Enable for path A */
#define    BM_CARFEA1	(uint8_t)(1U<<CARFEA1)
#define    AMPFEA1         1       /* AMPlitude Failed Enable for path A */
#define    BM_AMPFEA1	(uint8_t)(1U<<AMPFEA1)
#define    SYTFEA1         2       /* SYmbol Timing check Failed Enable for Path A */
#define    BM_SYTFEA1	(uint8_t)(1U<<SYTFEA1)
#define    MANFEA1         3       /* MANchester Coding Failed Enable for Path A */
#define    BM_MANFEA1	(uint8_t)(1U<<MANFEA1)
#define    TMOFEA1         4       /* Time-Out Fail Enable on Path A */
#define    BM_TMOFEA1	(uint8_t)(1U<<TMOFEA1)
#define    TELREA1         5       /* Telegram Length Reached Enable on Path A */
#define    BM_TELREA1	(uint8_t)(1U<<TELREA1)
#define    RRFEA1          6       /* RSSI Range Fail Enable on Path A */
#define    BM_RRFEA1	(uint8_t)(1U<<RRFEA1)
#define    EOTBFE1         7       /* End Of Telegram on Path B Fail Enable */
#define    BM_EOTBFE1	(uint8_t)(1U<<EOTBFE1)

/* EOTC1B - End Of Telegram Conditions 1 for Path B */
#define    CARFEB1         0       /* CARrier check Failed Enable for path B */
#define    BM_CARFEB1	(uint8_t)(1U<<CARFEB1)
#define    AMPFEB1         1       /* AMPlitude Failed Enable for path B */
#define    BM_AMPFEB1	(uint8_t)(1U<<AMPFEB1)
#define    SYTFEB1         2       /* SYmbol Timing check Failed Enable for Path B */
#define    BM_SYTFEB1	(uint8_t)(1U<<SYTFEB1)
#define    MANFEB1         3       /* MANchester Coding Failed Enable for Path B */
#define    BM_MANFEB1	(uint8_t)(1U<<MANFEB1)
#define    TMOFEB1         4       /* Time-Out Fail Enable on Path B */
#define    BM_TMOFEB1	(uint8_t)(1U<<TMOFEB1)
#define    TELREB1         5       /* Telegram Length Reached Enable on Path B */
#define    BM_TELREB1	(uint8_t)(1U<<TELREB1)
#define    RRFEB1          6       /* RSSI Range Fail Enable on Path B */
#define    BM_RRFEB1	(uint8_t)(1U<<RRFEB1)
#define    EOTAFE1         7       /* End Of Telegram on Path B Fail Enable */
#define    BM_EOTAFE1	(uint8_t)(1U<<EOTAFE1)

/* EOTC2A - End Of Telegram Conditions 2 for Path A */
#define    CARFEA2         0       /* CARrier check Failed Enable for path A */
#define    BM_CARFEA2	(uint8_t)(1U<<CARFEA2)
#define    AMPFEA2         1       /* AMPlitude Failed Enable for path A */
#define    BM_AMPFEA2	(uint8_t)(1U<<AMPFEA2)
#define    SYTFEA2         2       /* SYmbol Timing check Failed Enable for Path A */
#define    BM_SYTFEA2	(uint8_t)(1U<<SYTFEA2)
#define    MANFEA2         3       /* MANchester Coding Failed Enable for Path A */
#define    BM_MANFEA2	(uint8_t)(1U<<MANFEA2)
#define    TMOFEA2         4       /* Time-Out Fail Enable on Path A */
#define    BM_TMOFEA2	(uint8_t)(1U<<TMOFEA2)
#define    TELREA2         5       /* Telegram Length Reached Enable on Path A */
#define    BM_TELREA2	(uint8_t)(1U<<TELREA2)
#define    RRFEA2          6       /* RSSI Range Fail Enable on Path A */
#define    BM_RRFEA2	(uint8_t)(1U<<RRFEA2)
#define    EOTBFE2         7       /* End Of Telegram on Path B Fail Enable */
#define    BM_EOTBFE2	(uint8_t)(1U<<EOTBFE2)

/* EOTC2B - End Of Telegram Conditions 2 for Path B */
#define    CARFEB2         0       /* CARrier check Failed Enable for path B */
#define    BM_CARFEB2	(uint8_t)(1U<<CARFEB2)
#define    AMPFEB2         1       /* AMPlitude Failed Enable for path B */
#define    BM_AMPFEB2	(uint8_t)(1U<<AMPFEB2)
#define    SYTFEB2         2       /* SYmbol Timing check Failed Enable for Path B */
#define    BM_SYTFEB2	(uint8_t)(1U<<SYTFEB2)
#define    MANFEB2         3       /* MANchester Coding Failed Enable for Path B */
#define    BM_MANFEB2	(uint8_t)(1U<<MANFEB2)
#define    TMOFEB2         4       /* Time-Out Fail Enable on Path B */
#define    BM_TMOFEB2	(uint8_t)(1U<<TMOFEB2)
#define    TELREB2         5       /* Telegram Length Reached Enable on Path B */
#define    BM_TELREB2	(uint8_t)(1U<<TELREB2)
#define    RRFEB2          6       /* RSSI Range Fail Enable on Path B */
#define    BM_RRFEB2	(uint8_t)(1U<<RRFEB2)
#define    EOTAFE2         7       /* End Of Telegram on Path B Fail Enable */
#define    BM_EOTAFE2	(uint8_t)(1U<<EOTAFE2)

/* EOTC3A - End Of Telegram Conditions 3 for Path A */
#define    CARFEA3         0       /* CARrier check Failed Enable for path A */
#define    BM_CARFEA3	(uint8_t)(1U<<CARFEA3)
#define    AMPFEA3         1       /* AMPlitude Failed Enable for path A */
#define    BM_AMPFEA3	(uint8_t)(1U<<AMPFEA3)
#define    SYTFEA3         2       /* SYmbol Timing check Failed Enable for Path A */
#define    BM_SYTFEA3	(uint8_t)(1U<<SYTFEA3)
#define    MANFEA3         3       /* MANchester Coding Failed Enable for Path A */
#define    BM_MANFEA3	(uint8_t)(1U<<MANFEA3)
#define    TMOFEA3         4       /* Time-Out Fail Enable on Path A */
#define    BM_TMOFEA3	(uint8_t)(1U<<TMOFEA3)
#define    TELREA3         5       /* Telegram Length Reached Enable on Path A */
#define    BM_TELREA3	(uint8_t)(1U<<TELREA3)
#define    RRFEA3          6       /* RSSI Range Fail Enable on Path A */
#define    BM_RRFEA3	(uint8_t)(1U<<RRFEA3)
#define    EOTBFE3         7       /* End Of Telegram on Path B Fail Enable */
#define    BM_EOTBFE3	(uint8_t)(1U<<EOTBFE3)

/* EOTC3B - End Of Telegram Conditions 3 for Path B */
#define    CARFEB3         0       /* CARrier check Failed Enable for path B */
#define    BM_CARFEB3	(uint8_t)(1U<<CARFEB3)
#define    AMPFEB3         1       /* AMPlitude Failed Enable for path B */
#define    BM_AMPFEB3	(uint8_t)(1U<<AMPFEB3)
#define    SYTFEB3         2       /* SYmbol Timing check Failed Enable for Path B */
#define    BM_SYTFEB3	(uint8_t)(1U<<SYTFEB3)
#define    MANFEB3         3       /* MANchester Coding Failed Enable for Path B */
#define    BM_MANFEB3	(uint8_t)(1U<<MANFEB3)
#define    TMOFEB3         4       /* Time-Out Fail Enable on Path B */
#define    BM_TMOFEB3	(uint8_t)(1U<<TMOFEB3)
#define    TELREB3         5       /* Telegram Length Reached Enable on Path B */
#define    BM_TELREB3	(uint8_t)(1U<<TELREB3)
#define    RRFEB3          6       /* RSSI Range Fail Enable on Path B */
#define    BM_RRFEB3	(uint8_t)(1U<<RRFEB3)
#define    EOTAFE3         7       /* End Of Telegram on Path B Fail Enable */
#define    BM_EOTAFE3	(uint8_t)(1U<<EOTAFE3)

/* GTCR - Get Telegram Control Register */
#define    RXTEHA          0       /* Rx Telegram End Handling Path A */
#define    BM_RXTEHA	(uint8_t)(1U<<RXTEHA)
#define    GAPMA           1       /* Gap Mode Path A */
#define    BM_GAPMA	(uint8_t)(1U<<GAPMA)
#define    DARA            2       /* Demodulator Automatic Restart on Path A */
#define    BM_DARA	(uint8_t)(1U<<DARA)
#define    IWUPA           3       /* Intermittent WUP Mode Path A */
#define    BM_IWUPA	(uint8_t)(1U<<IWUPA)
#define    RXTEHB          4       /* Rx Telegram End Handling Path B */
#define    BM_RXTEHB	(uint8_t)(1U<<RXTEHB)
#define    GAPMB           5       /* Gap Mode Path B */
#define    BM_GAPMB	(uint8_t)(1U<<GAPMB)
#define    DARB            6       /* Demodulator Automatic Restart on Path B */
#define    BM_DARB	(uint8_t)(1U<<DARB)
#define    IWUPB           7       /* Intermittent WUP Mode Path B */
#define    BM_IWUPB	(uint8_t)(1U<<IWUPB)

/* MSMCR1 - Master State Machine Control Register 1 */
#define    MSMSM00         0       /* Master State Machine SubState Machine Select 0 bit 0 */
#define    BM_MSMSM00	(uint8_t)(1U<<MSMSM00)
#define    MSMSM01         1       /* Master State Machine SubState Machine Select 0 bit 1 */
#define    BM_MSMSM01	(uint8_t)(1U<<MSMSM01)
#define    MSMSM02         2       /* Master State Machine SubState Machine Select 0 bit 2 */
#define    BM_MSMSM02	(uint8_t)(1U<<MSMSM02)
#define    MSMSM03         3       /* Master State Machine SubState Machine Select 0 bit 3 */
#define    BM_MSMSM03	(uint8_t)(1U<<MSMSM03)
#define    MSMSM10         4       /* Master State Machine SubState Machine Select 1 bit 0 */
#define    BM_MSMSM10	(uint8_t)(1U<<MSMSM10)
#define    MSMSM11         5       /* Master State Machine SubState Machine Select 1 bit 1 */
#define    BM_MSMSM11	(uint8_t)(1U<<MSMSM11)
#define    MSMSM12         6       /* Master State Machine SubState Machine Select 1 bit 2 */
#define    BM_MSMSM12	(uint8_t)(1U<<MSMSM12)
#define    MSMSM13         7       /* Master State Machine SubState Machine Select 1 bit 3 */
#define    BM_MSMSM13	(uint8_t)(1U<<MSMSM13)

/* MSMCR2 - Master State Machine Control Register 2 */
#define    MSMSM20         0       /* Master State Machine SubState Machine Select 2 bit 0 */
#define    BM_MSMSM20	(uint8_t)(1U<<MSMSM20)
#define    MSMSM21         1       /* Master State Machine SubState Machine Select 2 bit 1 */
#define    BM_MSMSM21	(uint8_t)(1U<<MSMSM21)
#define    MSMSM22         2       /* Master State Machine SubState Machine Select 2 bit 2 */
#define    BM_MSMSM22	(uint8_t)(1U<<MSMSM22)
#define    MSMSM23         3       /* Master State Machine SubState Machine Select 2 bit 3 */
#define    BM_MSMSM23	(uint8_t)(1U<<MSMSM23)
#define    MSMSM30         4       /* Master State Machine SubState Machine Select 3 bit 0 */
#define    BM_MSMSM30	(uint8_t)(1U<<MSMSM30)
#define    MSMSM31         5       /* Master State Machine SubState Machine Select 3 bit 1 */
#define    BM_MSMSM31	(uint8_t)(1U<<MSMSM31)
#define    MSMSM32         6       /* Master State Machine SubState Machine Select 3 bit 2 */
#define    BM_MSMSM32	(uint8_t)(1U<<MSMSM32)
#define    MSMSM33         7       /* Master State Machine SubState Machine Select 3 bit 3 */
#define    BM_MSMSM33	(uint8_t)(1U<<MSMSM33)

/* MSMCR3 - Master State Machine Control Register 3 */
#define    MSMSM40         0       /* Master State Machine SubState Machine Select 4 bit 0 */
#define    BM_MSMSM40	(uint8_t)(1U<<MSMSM40)
#define    MSMSM41         1       /* Master State Machine SubState Machine Select 4 bit 1 */
#define    BM_MSMSM41	(uint8_t)(1U<<MSMSM41)
#define    MSMSM42         2       /* Master State Machine SubState Machine Select 4 bit 2 */
#define    BM_MSMSM42	(uint8_t)(1U<<MSMSM42)
#define    MSMSM43         3       /* Master State Machine SubState Machine Select 4 bit 3 */
#define    BM_MSMSM43	(uint8_t)(1U<<MSMSM43)
#define    MSMSM50         4       /* Master State Machine SubState Machine Select 5 bit 0 */
#define    BM_MSMSM50	(uint8_t)(1U<<MSMSM50)
#define    MSMSM51         5       /* Master State Machine SubState Machine Select 5 bit 1 */
#define    BM_MSMSM51	(uint8_t)(1U<<MSMSM51)
#define    MSMSM52         6       /* Master State Machine SubState Machine Select 5 bit 2 */
#define    BM_MSMSM52	(uint8_t)(1U<<MSMSM52)
#define    MSMSM53         7       /* Master State Machine SubState Machine Select 5 bit 3 */
#define    BM_MSMSM53	(uint8_t)(1U<<MSMSM53)

/* MSMCR4 - Master State Machine Control Register 4 */
#define    MSMSM60         0       /* Master State Machine SubState Machine Select 6 bit 0 */
#define    BM_MSMSM60	(uint8_t)(1U<<MSMSM60)
#define    MSMSM61         1       /* Master State Machine SubState Machine Select 6 bit 1 */
#define    BM_MSMSM61	(uint8_t)(1U<<MSMSM61)
#define    MSMSM62         2       /* Master State Machine SubState Machine Select 6 bit 2 */
#define    BM_MSMSM62	(uint8_t)(1U<<MSMSM62)
#define    MSMSM63         3       /* Master State Machine SubState Machine Select 6 bit 3 */
#define    BM_MSMSM63	(uint8_t)(1U<<MSMSM63)
#define    MSMSM70         4       /* Master State Machine SubState Machine Select 7 bit 0 */
#define    BM_MSMSM70	(uint8_t)(1U<<MSMSM70)
#define    MSMSM71         5       /* Master State Machine SubState Machine Select 7 bit 1 */
#define    BM_MSMSM71	(uint8_t)(1U<<MSMSM71)
#define    MSMSM72         6       /* Master State Machine SubState Machine Select 7 bit 2 */
#define    BM_MSMSM72	(uint8_t)(1U<<MSMSM72)
#define    MSMSM73         7       /* Master State Machine SubState Machine Select 7 bit 3 */
#define    BM_MSMSM73	(uint8_t)(1U<<MSMSM73)

/* MSMSTR - Master State Machine state register */
#define    SSMMST0         0       /* Sequencer State Machine Master State bit 0 */
#define    BM_SSMMST0	(uint8_t)(1U<<SSMMST0)
#define    SSMMST1         1       /* Sequencer State Machine Master State bit 1 */
#define    BM_SSMMST1	(uint8_t)(1U<<SSMMST1)
#define    SSMMST2         2       /* Sequencer State Machine Master State bit 2 */
#define    BM_SSMMST2	(uint8_t)(1U<<SSMMST2)
#define    SSMMST3         3       /* Sequencer State Machine Master State bit 3 */
#define    BM_SSMMST3	(uint8_t)(1U<<SSMMST3)
#define    SSMMST4         4       /* Sequencer State Machine Master State bit 4 */
#define    BM_SSMMST4	(uint8_t)(1U<<SSMMST4)

/* SOTC1A - Start Of Telegram Conditions 1 for Path A */
#define    CAROEA1         0       /* CARrier check Ok Enabled for path A */
#define    BM_CAROEA1	(uint8_t)(1U<<CAROEA1)
#define    AMPOEA1         1       /* AMPlitude Ok Enabled for path A */
#define    BM_AMPOEA1	(uint8_t)(1U<<AMPOEA1)
#define    SYTOEA1         2       /* Symbol Timing Ok Enabled for path A */
#define    BM_SYTOEA1	(uint8_t)(1U<<SYTOEA1)
#define    MANOEA1         3       /* Manchester Coding Ok Enabled for path A */
#define    BM_MANOEA1	(uint8_t)(1U<<MANOEA1)
#define    WUPEA1          4       /* Wake Up Pattern match Enabled for path A */
#define    BM_WUPEA1	(uint8_t)(1U<<WUPEA1)
#define    SFIDEA1         5       /* Start of Frame IDentifier match Enabled for path A */
#define    BM_SFIDEA1	(uint8_t)(1U<<SFIDEA1)
#define    RROEA1          6       /* RSSI Range OK Enable for path A */
#define    BM_RROEA1	(uint8_t)(1U<<RROEA1)
#define    WCOBOE1         7       /* Wake Check OK from path B Ok Enable */
#define    BM_WCOBOE1	(uint8_t)(1U<<WCOBOE1)

/* SOTC1B - Start Of Telegram Conditions 1 for Path B */
#define    CAROEB1         0       /* CARrier check Ok Enabled for path B */
#define    BM_CAROEB1	(uint8_t)(1U<<CAROEB1)
#define    AMPOEB1         1       /* AMPlitude Ok Enabled for path B */
#define    BM_AMPOEB1	(uint8_t)(1U<<AMPOEB1)
#define    SYTOEB1         2       /* Symbol Timing Ok Enabled for path B */
#define    BM_SYTOEB1	(uint8_t)(1U<<SYTOEB1)
#define    MANOEB1         3       /* Manchester Coding Ok Enabled for path B */
#define    BM_MANOEB1	(uint8_t)(1U<<MANOEB1)
#define    WUPEB1          4       /* Wake Up Pattern match Enabled for path B */
#define    BM_WUPEB1	(uint8_t)(1U<<WUPEB1)
#define    SFIDEB1         5       /* Start of Frame IDentifier match Enabled for path B */
#define    BM_SFIDEB1	(uint8_t)(1U<<SFIDEB1)
#define    RROEB1          6       /* RSSI Range Ok on Path A */
#define    BM_RROEB1	(uint8_t)(1U<<RROEB1)
#define    WCOAOE1         7       /* Wake Check Ok on path B Ok */
#define    BM_WCOAOE1	(uint8_t)(1U<<WCOAOE1)

/* SOTC2A - Start Of Telegram Conditions 2 for Path A */
#define    CAROEA2         0       /* CARrier check Ok Enabled for path A */
#define    BM_CAROEA2	(uint8_t)(1U<<CAROEA2)
#define    AMPOEA2         1       /* AMPlitude Ok Enabled for path A */
#define    BM_AMPOEA2	(uint8_t)(1U<<AMPOEA2)
#define    SYTOEA2         2       /* Symbol Timing Ok Enabled for path A */
#define    BM_SYTOEA2	(uint8_t)(1U<<SYTOEA2)
#define    MANOEA2         3       /* Manchester Coding Ok Enabled for path A */
#define    BM_MANOEA2	(uint8_t)(1U<<MANOEA2)
#define    WUPEA2          4       /* Wake Up Pattern match Enabled for path A */
#define    BM_WUPEA2	(uint8_t)(1U<<WUPEA2)
#define    SFIDEA2         5       /* Start of Frame IDentifier match Enabled for path A */
#define    BM_SFIDEA2	(uint8_t)(1U<<SFIDEA2)
#define    RROEA2          6       /* RSSI Range OK Enable for path A */
#define    BM_RROEA2	(uint8_t)(1U<<RROEA2)
#define    WCOBOE2         7       /* Wake Check OK from path B Ok Enable */
#define    BM_WCOBOE2	(uint8_t)(1U<<WCOBOE2)

/* SOTC2B - Start Of Telegram Conditions 2 for Path B */
#define    CAROEB2         0       /* CARrier check Ok Enabled for path B */
#define    BM_CAROEB2	(uint8_t)(1U<<CAROEB2)
#define    AMPOEB2         1       /* AMPlitude Ok Enabled for path B */
#define    BM_AMPOEB2	(uint8_t)(1U<<AMPOEB2)
#define    SYTOEB2         2       /* Symbol Timing Ok Enabled for path B */
#define    BM_SYTOEB2	(uint8_t)(1U<<SYTOEB2)
#define    MANOEB2         3       /* Manchester Coding Ok Enabled for path B */
#define    BM_MANOEB2	(uint8_t)(1U<<MANOEB2)
#define    WUPEB2          4       /* Wake Up Pattern match Enabled for path B */
#define    BM_WUPEB2	(uint8_t)(1U<<WUPEB2)
#define    SFIDEB2         5       /* Start of Frame IDentifier match Enabled for path B */
#define    BM_SFIDEB2	(uint8_t)(1U<<SFIDEB2)
#define    RROEB2          6       /* RSSI Range Ok on Path A */
#define    BM_RROEB2	(uint8_t)(1U<<RROEB2)
#define    WCOAOE2         7       /* Wake Check Ok on path B Ok */
#define    BM_WCOAOE2	(uint8_t)(1U<<WCOAOE2)

/* SOTTOA - Start Of Telegram Time Out for path A */
#define    SOTTOA0         0       /* Start of telegram time out for path A bit 0 */
#define    BM_SOTTOA0	(uint8_t)(1U<<SOTTOA0)
#define    SOTTOA1         1       /* Start of telegram time out for path A bit 1 */
#define    BM_SOTTOA1	(uint8_t)(1U<<SOTTOA1)
#define    SOTTOA2         2       /* Start of telegram time out for path A bit 2 */
#define    BM_SOTTOA2	(uint8_t)(1U<<SOTTOA2)
#define    SOTTOA3         3       /* Start of telegram time out for path A bit 3 */
#define    BM_SOTTOA3	(uint8_t)(1U<<SOTTOA3)
#define    SOTTOA4         4       /* Start of telegram time out for path A bit 4 */
#define    BM_SOTTOA4	(uint8_t)(1U<<SOTTOA4)
#define    SOTTOA5         5       /* Start of telegram time out for path A bit 5 */
#define    BM_SOTTOA5	(uint8_t)(1U<<SOTTOA5)
#define    SOTTOA6         6       /* Start of telegram time out for path A bit 6 */
#define    BM_SOTTOA6	(uint8_t)(1U<<SOTTOA6)
#define    SOTTOA7         7       /* Start of telegram time out for path A bit 7 */
#define    BM_SOTTOA7	(uint8_t)(1U<<SOTTOA7)

/* SOTTOB - Start Of Telegram Time Out for path B */
#define    SOTTOB0         0       /* Start of telegram time out for path B bit 0 */
#define    BM_SOTTOB0	(uint8_t)(1U<<SOTTOB0)
#define    SOTTOB1         1       /* Start of telegram time out for path B bit 1 */
#define    BM_SOTTOB1	(uint8_t)(1U<<SOTTOB1)
#define    SOTTOB2         2       /* Start of telegram time out for path B bit 2 */
#define    BM_SOTTOB2	(uint8_t)(1U<<SOTTOB2)
#define    SOTTOB3         3       /* Start of telegram time out for path B bit 3 */
#define    BM_SOTTOB3	(uint8_t)(1U<<SOTTOB3)
#define    SOTTOB4         4       /* Start of telegram time out for path B bit 4 */
#define    BM_SOTTOB4	(uint8_t)(1U<<SOTTOB4)
#define    SOTTOB5         5       /* Start of telegram time out for path B bit 5 */
#define    BM_SOTTOB5	(uint8_t)(1U<<SOTTOB5)
#define    SOTTOB6         6       /* Start of telegram time out for path B bit 6 */
#define    BM_SOTTOB6	(uint8_t)(1U<<SOTTOB6)
#define    SOTTOB7         7       /* Start of telegram time out for path B bit 7 */
#define    BM_SOTTOB7	(uint8_t)(1U<<SOTTOB7)

/* SSMCR - SSM Control Register */
#define    SSMTX           0       /* Sequencer State Machine Tx */
#define    BM_SSMTX	(uint8_t)(1U<<SSMTX)
#define    SSMTM           1       /* Sequencer State Machine Temperature Measurement */
#define    BM_SSMTM	(uint8_t)(1U<<SSMTM)
#define    SSMTGE          2       /* Sequencer State Machine Tx Gauss Enable */
#define    BM_SSMTGE	(uint8_t)(1U<<SSMTGE)
#define    SSMTPE          3       /* Sequencer State Machine Tx Preemphasis Enable */
#define    BM_SSMTPE	(uint8_t)(1U<<SSMTPE)
#define    SSMPVE          4       /* Sequencer State Machine PV Enable */
#define    BM_SSMPVE	(uint8_t)(1U<<SSMPVE)
#define    SSMTAE          5       /* Sequencer State Machine Tx Ask-Shaping Enable */
#define    BM_SSMTAE	(uint8_t)(1U<<SSMTAE)
#define    SETRPA          6       /* Sequencer State Machine Enable Transparent Path A */
#define    BM_SETRPA	(uint8_t)(1U<<SETRPA)
#define    SETRPB          7       /* Sequencer State Machine Enable Transparent Path B */
#define    BM_SETRPB	(uint8_t)(1U<<SETRPB)

/* SSMFBR - SSM Filter Bandwidth Register */
#define    SSMFID0         0       /* Sequencer State Machine Filter Delay bit 0 */
#define    BM_SSMFID0	(uint8_t)(1U<<SSMFID0)
#define    SSMFID1         1       /* Sequencer State Machine Filter Delay bit 1 */
#define    BM_SSMFID1	(uint8_t)(1U<<SSMFID1)
#define    SSMFID2         2       /* Sequencer State Machine Filter Delay bit 2 */
#define    BM_SSMFID2	(uint8_t)(1U<<SSMFID2)
#define    SSMDFDT         3       /* Sequencer State Machine Double Filter Delay Time */
#define    BM_SSMDFDT	(uint8_t)(1U<<SSMDFDT)
#define    SSMHADT         4       /* Sequencer State Machine Half Antennadamping Delay Time */
#define    BM_SSMHADT	(uint8_t)(1U<<SSMHADT)
#define    SSMPLDT         5       /* Sequencer State Machine PLL Lock Delay Time */
#define    BM_SSMPLDT	(uint8_t)(1U<<SSMPLDT)

/* SSMFCR - SSM Flow Control Register */
#define    SSMIDSO         0       /* Sequencer State Machine ID Scan OK */
#define    BM_SSMIDSO	(uint8_t)(1U<<SSMIDSO)
#define    SSMIDSF         1       /* Sequencer State Machine ID Scan Fail */
#define    BM_SSMIDSF	(uint8_t)(1U<<SSMIDSF)

/* SSMIFR - SSM Interrupt Flag Register */
#define    SSMIF           0       /* Sequencer State Machine Interrupt Flag */
#define    BM_SSMIF	(uint8_t)(1U<<SSMIF)

/* SSMIMR - SSM interrupt mask register */
#define    SSMIM           0       /* Sequencer State Machine Interrupt Mask */
#define    BM_SSMIM	(uint8_t)(1U<<SSMIM)

/* SSMRCR - SSM Rx Control Register */
#define    SSMPA           0       /* Sequencer State Machine Path A */
#define    BM_SSMPA	(uint8_t)(1U<<SSMPA)
#define    SSMPB           1       /* Sequencer State Machine Path B */
#define    BM_SSMPB	(uint8_t)(1U<<SSMPB)
#define    SSMADA          2       /* Sequencer State Machine Antenna Damping Disable Path A */
#define    BM_SSMADA	(uint8_t)(1U<<SSMADA)
#define    SSMADB          3       /* Sequencer State Machine Antenna Damping Disable Path B */
#define    BM_SSMADB	(uint8_t)(1U<<SSMADB)
#define    SSMPVS          4       /* Sequencer State Machine Path Valid After SOT */
#define    BM_SSMPVS	(uint8_t)(1U<<SSMPVS)
#define    SSMIFA          5       /* Sequencer State Machine IF Amplifier Enable */
#define    BM_SSMIFA	(uint8_t)(1U<<SSMIFA)
#define    SSMIDSE         6       /* Sequencer State Machine ID Scan Enable */
#define    BM_SSMIDSE	(uint8_t)(1U<<SSMIDSE)
#define    SSMTMOE         7       /* Sequencer State Machine Transparent Mode Output Enable */
#define    BM_SSMTMOE	(uint8_t)(1U<<SSMTMOE)

/* SSMRR - SSM Run Register */
#define    SSMR            0       /* Sequencer State Machine Run */
#define    BM_SSMR	(uint8_t)(1U<<SSMR)
#define    SSMST           1       /* Sequencer State Machine Stop */
#define    BM_SSMST	(uint8_t)(1U<<SSMST)

/* SSMSR - SSM Status Register */
#define    SSMESM0         0       /* Sequencer State Machine Error State Machine bit 0 */
#define    BM_SSMESM0	(uint8_t)(1U<<SSMESM0)
#define    SSMESM1         1       /* Sequencer State Machine Error State Machine bit 1 */
#define    BM_SSMESM1	(uint8_t)(1U<<SSMESM1)
#define    SSMESM2         2       /* Sequencer State Machine Error State Machine bit 2 */
#define    BM_SSMESM2	(uint8_t)(1U<<SSMESM2)
#define    SSMESM3         3       /* Sequencer State Machine Error State Machine bit 3 */
#define    BM_SSMESM3	(uint8_t)(1U<<SSMESM3)
#define    SSMERR          7       /* Sequencer State Machine Error */
#define    BM_SSMERR	(uint8_t)(1U<<SSMERR)

/* SSMSTR - SSM State Register */
#define    SSMSTA0         0       /* Sequencer State Machine State A bit 0 */
#define    BM_SSMSTA0	(uint8_t)(1U<<SSMSTA0)
#define    SSMSTA1         1       /* Sequencer State Machine State A bit 1 */
#define    BM_SSMSTA1	(uint8_t)(1U<<SSMSTA1)
#define    SSMSTA2         2       /* Sequencer State Machine State A bit 2 */
#define    BM_SSMSTA2	(uint8_t)(1U<<SSMSTA2)
#define    SSMSTA3         3       /* Sequencer State Machine State A bit 3 */
#define    BM_SSMSTA3	(uint8_t)(1U<<SSMSTA3)
#define    SSMSTA4         4       /* Sequencer State Machine State A bit 4 */
#define    BM_SSMSTA4	(uint8_t)(1U<<SSMSTA4)
#define    SSMSTA5         5       /* Sequencer State Machine State A bit 5 */
#define    BM_SSMSTA5	(uint8_t)(1U<<SSMSTA5)

/* SSMXSR - SSM extended State Register */
#define    SSMSTB0         0       /* Sequencer State Machine State B bit 0 */
#define    BM_SSMSTB0	(uint8_t)(1U<<SSMSTB0)
#define    SSMSTB1         1       /* Sequencer State Machine State B bit 1 */
#define    BM_SSMSTB1	(uint8_t)(1U<<SSMSTB1)
#define    SSMSTB2         2       /* Sequencer State Machine State B bit 2 */
#define    BM_SSMSTB2	(uint8_t)(1U<<SSMSTB2)
#define    SSMSTB3         3       /* Sequencer State Machine State B bit 3 */
#define    BM_SSMSTB3	(uint8_t)(1U<<SSMSTB3)
#define    SSMSTB4         4       /* Sequencer State Machine State B bit 4 */
#define    BM_SSMSTB4	(uint8_t)(1U<<SSMSTB4)
#define    SSMSTB5         5       /* Sequencer State Machine State B bit 5 */
#define    BM_SSMSTB5	(uint8_t)(1U<<SSMSTB5)

/* WCOTOA - Wait check ok time out for path A */
#define    WCOTOA0         0       /* Wait check ok time out for path A bit 0 */
#define    BM_WCOTOA0	(uint8_t)(1U<<WCOTOA0)
#define    WCOTOA1         1       /* Wait check ok time out for path A bit 1 */
#define    BM_WCOTOA1	(uint8_t)(1U<<WCOTOA1)
#define    WCOTOA2         2       /* Wait check ok time out for path A bit 2 */
#define    BM_WCOTOA2	(uint8_t)(1U<<WCOTOA2)
#define    WCOTOA3         3       /* Wait check ok time out for path A bit 3 */
#define    BM_WCOTOA3	(uint8_t)(1U<<WCOTOA3)
#define    WCOTOA4         4       /* Wait check ok time out for path A bit 4 */
#define    BM_WCOTOA4	(uint8_t)(1U<<WCOTOA4)
#define    WCOTOA5         5       /* Wait check ok time out for path A bit 5 */
#define    BM_WCOTOA5	(uint8_t)(1U<<WCOTOA5)
#define    WCOTOA6         6       /* Wait check ok time out for path A bit 6 */
#define    BM_WCOTOA6	(uint8_t)(1U<<WCOTOA6)
#define    WCOTOA7         7       /* Wait check ok time out for path A bit 7 */
#define    BM_WCOTOA7	(uint8_t)(1U<<WCOTOA7)

/* WCOTOB - Wait check ok time out for path B */
#define    WCOTOB0         0       /* Wait check ok time out for path B bit 0 */
#define    BM_WCOTOB0	(uint8_t)(1U<<WCOTOB0)
#define    WCOTOB1         1       /* Wait check ok time out for path B bit 1 */
#define    BM_WCOTOB1	(uint8_t)(1U<<WCOTOB1)
#define    WCOTOB2         2       /* Wait check ok time out for path B bit 2 */
#define    BM_WCOTOB2	(uint8_t)(1U<<WCOTOB2)
#define    WCOTOB3         3       /* Wait check ok time out for path B bit 3 */
#define    BM_WCOTOB3	(uint8_t)(1U<<WCOTOB3)
#define    WCOTOB4         4       /* Wait check ok time out for path B bit 4 */
#define    BM_WCOTOB4	(uint8_t)(1U<<WCOTOB4)
#define    WCOTOB5         5       /* Wait check ok time out for path B bit 5 */
#define    BM_WCOTOB5	(uint8_t)(1U<<WCOTOB5)
#define    WCOTOB6         6       /* Wait check ok time out for path B bit 6 */
#define    BM_WCOTOB6	(uint8_t)(1U<<WCOTOB6)
#define    WCOTOB7         7       /* Wait check ok time out for path B bit 7 */
#define    BM_WCOTOB7	(uint8_t)(1U<<WCOTOB7)


/* ***** SUP ************************** */
/* CALRDY - Calibration ready signature */
#define    CALRDY0         0       /* Calibration ready signature bit 0 */
#define    BM_CALRDY0	(uint8_t)(1U<<CALRDY0)
#define    CALRDY1         1       /* Calibration ready signature bit 1 */
#define    BM_CALRDY1	(uint8_t)(1U<<CALRDY1)
#define    CALRDY2         2       /* Calibration ready signature bit 2 */
#define    BM_CALRDY2	(uint8_t)(1U<<CALRDY2)
#define    CALRDY3         3       /* Calibration ready signature bit 3 */
#define    BM_CALRDY3	(uint8_t)(1U<<CALRDY3)
#define    CALRDY4         4       /* Calibration ready signature bit 4 */
#define    BM_CALRDY4	(uint8_t)(1U<<CALRDY4)
#define    CALRDY5         5       /* Calibration ready signature bit 5 */
#define    BM_CALRDY5	(uint8_t)(1U<<CALRDY5)
#define    CALRDY6         6       /* Calibration ready signature bit 6 */
#define    BM_CALRDY6	(uint8_t)(1U<<CALRDY6)
#define    CALRDY7         7       /* Calibration ready signature bit 7 */
#define    BM_CALRDY7	(uint8_t)(1U<<CALRDY7)

/* SUPCA1 - Supply calibration register 1 */
#define    PV22            2       /* Power Amplifier Voltage 2.2V */
#define    BM_PV22	(uint8_t)(1U<<PV22)
#define    PVDIC           3       /* Power Amplifier Regulator Double Internal Current */
#define    BM_PVDIC	(uint8_t)(1U<<PVDIC)
#define    PVCAL0          4       /* Power Amplifier Regulator Calibration bit 0 */
#define    BM_PVCAL0	(uint8_t)(1U<<PVCAL0)
#define    PVCAL1          5       /* Power Amplifier Regulator Calibration bit 1 */
#define    BM_PVCAL1	(uint8_t)(1U<<PVCAL1)
#define    PVCAL2          6       /* Power Amplifier Regulator Calibration bit 2 */
#define    BM_PVCAL2	(uint8_t)(1U<<PVCAL2)
#define    PVCAL3          7       /* Power Amplifier Regulator Calibration bit 3 */
#define    BM_PVCAL3	(uint8_t)(1U<<PVCAL3)

/* SUPCA2 - Supply calibration register 2 */
#define    BGCAL0          0       /* Band Gap Calibration bit 0 */
#define    BM_BGCAL0	(uint8_t)(1U<<BGCAL0)
#define    BGCAL1          1       /* Band Gap Calibration bit 1 */
#define    BM_BGCAL1	(uint8_t)(1U<<BGCAL1)
#define    BGCAL2          2       /* Band Gap Calibration bit 2 */
#define    BM_BGCAL2	(uint8_t)(1U<<BGCAL2)
#define    BGCAL3          3       /* Band Gap Calibration bit 3 */
#define    BM_BGCAL3	(uint8_t)(1U<<BGCAL3)

/* SUPCA3 - Supply calibration register 3 */
#define    ACAL4           0       /* AVCC Reset Threshold Calibration bit 4 */
#define    BM_ACAL4	(uint8_t)(1U<<ACAL4)
#define    ACAL5           1       /* AVCC Reset Threshold Calibration bit 5 */
#define    BM_ACAL5	(uint8_t)(1U<<ACAL5)
#define    ACAL6           2       /* AVCC Reset Threshold Calibration bit 6 */
#define    BM_ACAL6	(uint8_t)(1U<<ACAL6)
#define    ACAL7           3       /* AVCC Reset Threshold Calibration bit 7 */
#define    BM_ACAL7	(uint8_t)(1U<<ACAL7)
#define    DCAL4           4       /* DVCC Reset Threshold Calibration bit 4 */
#define    BM_DCAL4	(uint8_t)(1U<<DCAL4)
#define    DCAL5           5       /* DVCC Reset Threshold Calibration bit 5 */
#define    BM_DCAL5	(uint8_t)(1U<<DCAL5)
#define    DCAL6           6       /* DVCC Reset Threshold Calibration bit 6 */
#define    BM_DCAL6	(uint8_t)(1U<<DCAL6)

/* SUPCA4 - Supply calibration register 4 */
#define    ACAL0           0       /* AVCC Regulator Output Voltage Calibration bit 0 */
#define    BM_ACAL0	(uint8_t)(1U<<ACAL0)
#define    ACAL1           1       /* AVCC Regulator Output Voltage Calibration bit 1 */
#define    BM_ACAL1	(uint8_t)(1U<<ACAL1)
#define    ACAL2           2       /* AVCC Regulator Output Voltage Calibration bit 2 */
#define    BM_ACAL2	(uint8_t)(1U<<ACAL2)
#define    ACAL3           3       /* AVCC Regulator Output Voltage Calibration bit 3 */
#define    BM_ACAL3	(uint8_t)(1U<<ACAL3)
#define    DCAL0           4       /* DVCC Regulator Output Voltage Calibration bit 0 */
#define    BM_DCAL0	(uint8_t)(1U<<DCAL0)
#define    DCAL1           5       /* DVCC Regulator Output Voltage Calibration bit 1 */
#define    BM_DCAL1	(uint8_t)(1U<<DCAL1)
#define    DCAL2           6       /* DVCC Regulator Output Voltage Calibration bit 2 */
#define    BM_DCAL2	(uint8_t)(1U<<DCAL2)
#define    DCAL3           7       /* DVCC Regulator Output Voltage Calibration bit 3 */
#define    BM_DCAL3	(uint8_t)(1U<<DCAL3)

/* SUPCR - Supply Control Register */
#define    AVCCRM          0       /* AVCC Reset Interrupt Mask Bit */
#define    BM_AVCCRM	(uint8_t)(1U<<AVCCRM)
#define    AVCCLM          1       /* AVCC Low Interrupt Mask Bit */
#define    BM_AVCCLM	(uint8_t)(1U<<AVCCLM)
#define    PVEN            2       /* Power amplifier Voltage supply Enable */
#define    BM_PVEN	(uint8_t)(1U<<PVEN)
#define    DVDIS           4       /* DVCC Disable */
#define    BM_DVDIS	(uint8_t)(1U<<DVDIS)
#define    AVEN            5       /* AVCC Enable */
#define    BM_AVEN	(uint8_t)(1U<<AVEN)
#define    AVDIC           6       /* AVCC Double Internal Current */
#define    BM_AVDIC	(uint8_t)(1U<<AVDIC)

/* SUPFR - Supply Interrupt Flag Register */
#define    AVCCRF          0       /* AVCC reset interrupt flag */
#define    BM_AVCCRF	(uint8_t)(1U<<AVCCRF)
#define    AVCCLF          1       /* AVCC low interrupt flag */
#define    BM_AVCCLF	(uint8_t)(1U<<AVCCLF)

/* VMCAL - Voltage Monitor Calibration register */
#define    VMCAL0          0       /* Voltage monitor calibration bit 0 */
#define    BM_VMCAL0	(uint8_t)(1U<<VMCAL0)
#define    VMCAL1          1       /* Voltage monitor calibration bit 1 */
#define    BM_VMCAL1	(uint8_t)(1U<<VMCAL1)
#define    VMCAL2          2       /* Voltage monitor calibration bit 2 */
#define    BM_VMCAL2	(uint8_t)(1U<<VMCAL2)

/* VMCSR - Voltage Monitor Control and Status Register */
#define    VMLS0           0       /* Voltage Monitor Level Select bit 0 */
#define    BM_VMLS0	(uint8_t)(1U<<VMLS0)
#define    VMLS1           1       /* Voltage Monitor Level Select bit 1 */
#define    BM_VMLS1	(uint8_t)(1U<<VMLS1)
#define    VMLS2           2       /* Voltage Monitor Level Select bit 2 */
#define    BM_VMLS2	(uint8_t)(1U<<VMLS2)
#define    VMLS3           3       /* Voltage Monitor Level Select bit 3 */
#define    BM_VMLS3	(uint8_t)(1U<<VMLS3)
#define    VMIM            4       /* Voltage Monitor Interrupt Mask */
#define    BM_VMIM	(uint8_t)(1U<<VMIM)
#define    VMF             5       /* Voltage Monitor Flag */
#define    BM_VMF	(uint8_t)(1U<<VMF)


/* ***** SYMCH ************************ */
/* SYCA - Symbol check configuration for data path A */
#define    SYCSA0          0       /* Symbol Check check size for data path A bit 0 */
#define    BM_SYCSA0	(uint8_t)(1U<<SYCSA0)
#define    SYCSA1          1       /* Symbol Check check size for data path A bit 1 */
#define    BM_SYCSA1	(uint8_t)(1U<<SYCSA1)
#define    SYCSA2          2       /* Symbol Check check size for data path A bit 2 */
#define    BM_SYCSA2	(uint8_t)(1U<<SYCSA2)
#define    SYCSA3          3       /* Symbol Check check size for data path A bit 3 */
#define    BM_SYCSA3	(uint8_t)(1U<<SYCSA3)
#define    SYTLA0          4       /* Symbol timing limit for path A bit 0 */
#define    BM_SYTLA0	(uint8_t)(1U<<SYTLA0)
#define    SYTLA1          5       /* Symbol timing limit for path A bit 1 */
#define    BM_SYTLA1	(uint8_t)(1U<<SYTLA1)
#define    SYTLA2          6       /* Symbol timing limit for path A bit 2 */
#define    BM_SYTLA2	(uint8_t)(1U<<SYTLA2)
#define    SYTLA3          7       /* Symbol timing limit for path A bit 3 */
#define    BM_SYTLA3	(uint8_t)(1U<<SYTLA3)

/* SYCB - Symbol check configuration for data path B */
#define    SYCSB0          0       /* Symbol Check check size for data path B bit 0 */
#define    BM_SYCSB0	(uint8_t)(1U<<SYCSB0)
#define    SYCSB1          1       /* Symbol Check check size for data path B bit 1 */
#define    BM_SYCSB1	(uint8_t)(1U<<SYCSB1)
#define    SYCSB2          2       /* Symbol Check check size for data path B bit 2 */
#define    BM_SYCSB2	(uint8_t)(1U<<SYCSB2)
#define    SYCSB3          3       /* Symbol Check check size for data path B bit 3 */
#define    BM_SYCSB3	(uint8_t)(1U<<SYCSB3)
#define    SYTLB0          4       /* Symbol timing limit for path B bit 0 */
#define    BM_SYTLB0	(uint8_t)(1U<<SYTLB0)
#define    SYTLB1          5       /* Symbol timing limit for path B bit 1 */
#define    BM_SYTLB1	(uint8_t)(1U<<SYTLB1)
#define    SYTLB2          6       /* Symbol timing limit for path B bit 2 */
#define    BM_SYTLB2	(uint8_t)(1U<<SYTLB2)
#define    SYTLB3          7       /* Symbol timing limit for path B bit 3 */
#define    BM_SYTLB3	(uint8_t)(1U<<SYTLB3)


/* ***** TEMPER *********************** */
/* TEMPH - Temperature High byte */
#define    TEMPH0          0       /* Temperature High byte bit 0 */
#define    BM_TEMPH0	(uint8_t)(1U<<TEMPH0)
#define    TEMPH1          1       /* Temperature High byte bit 1 */
#define    BM_TEMPH1	(uint8_t)(1U<<TEMPH1)
#define    TEMPH2          2       /* Temperature High byte bit 2 */
#define    BM_TEMPH2	(uint8_t)(1U<<TEMPH2)
#define    TEMPH3          3       /* Temperature High byte bit 3 */
#define    BM_TEMPH3	(uint8_t)(1U<<TEMPH3)
#define    TEMPH4          4       /* Temperature High byte bit 4 */
#define    BM_TEMPH4	(uint8_t)(1U<<TEMPH4)
#define    TEMPH5          5       /* Temperature High byte bit 5 */
#define    BM_TEMPH5	(uint8_t)(1U<<TEMPH5)
#define    TEMPH6          6       /* Temperature High byte bit 6 */
#define    BM_TEMPH6	(uint8_t)(1U<<TEMPH6)
#define    TEMPH7          7       /* Temperature High byte bit 7 */
#define    BM_TEMPH7	(uint8_t)(1U<<TEMPH7)

/* TEMPL - Temperature Low byte */
#define    TEMPL0          0       /* Temperature Low byte bit 0 */
#define    BM_TEMPL0	(uint8_t)(1U<<TEMPL0)
#define    TEMPL1          1       /* Temperature Low byte bit 1 */
#define    BM_TEMPL1	(uint8_t)(1U<<TEMPL1)
#define    TEMPL2          2       /* Temperature Low byte bit 2 */
#define    BM_TEMPL2	(uint8_t)(1U<<TEMPL2)
#define    TEMPL3          3       /* Temperature Low byte bit 3 */
#define    BM_TEMPL3	(uint8_t)(1U<<TEMPL3)
#define    TEMPL4          4       /* Temperature Low byte bit 4 */
#define    BM_TEMPL4	(uint8_t)(1U<<TEMPL4)
#define    TEMPL5          5       /* Temperature Low byte bit 5 */
#define    BM_TEMPL5	(uint8_t)(1U<<TEMPL5)
#define    TEMPL6          6       /* Temperature Low byte bit 6 */
#define    BM_TEMPL6	(uint8_t)(1U<<TEMPL6)
#define    TEMPL7          7       /* Temperature Low byte bit 7 */
#define    BM_TEMPL7	(uint8_t)(1U<<TEMPL7)


/* ***** TIMER0_WDT ******************* */
/* T0CR - Timer0 Control Register */
#define    T0PS0           0       /* Timer 0 Prescaler Select bit 0 */
#define    BM_T0PS0	(uint8_t)(1U<<T0PS0)
#define    T0PS1           1       /* Timer 0 Prescaler Select bit 1 */
#define    BM_T0PS1	(uint8_t)(1U<<T0PS1)
#define    T0PS2           2       /* Timer 0 Prescaler Select bit 2 */
#define    BM_T0PS2	(uint8_t)(1U<<T0PS2)
#define    T0IE            3       /* Timer 0 Interrupt Enable */
#define    BM_T0IE	(uint8_t)(1U<<T0IE)
#define    T0PR            4       /* Timer 0 Prescaler Reset */
#define    BM_T0PR	(uint8_t)(1U<<T0PR)

/* T0IFR - Timer0 Interrupt Flag Register */
#define    T0F             0       /* Timer0 Flag */
#define    BM_T0F	(uint8_t)(1U<<T0F)

/* WDTCR - Watchdog Timer0 control Register */
#define    WDPS0           0       /* Watchdog Prescaler Select bit 0 */
#define    BM_WDPS0	(uint8_t)(1U<<WDPS0)
#define    WDPS1           1       /* Watchdog Prescaler Select bit 1 */
#define    BM_WDPS1	(uint8_t)(1U<<WDPS1)
#define    WDPS2           2       /* Watchdog Prescaler Select bit 2 */
#define    BM_WDPS2	(uint8_t)(1U<<WDPS2)
#define    WDE             3       /* Watchdog System Reset Enable */
#define    BM_WDE	(uint8_t)(1U<<WDE)
#define    WDCE            4       /* Watchdog Change Enable */
#define    BM_WDCE	(uint8_t)(1U<<WDCE)


/* ***** TIMER1 *********************** */
/* T1CNT - Timer1 Counter Register */
#define    T1CNT0          0       /* Timer1 Counter bit 0 */
#define    BM_T1CNT0	(uint8_t)(1U<<T1CNT0)
#define    T1CNT1          1       /* Timer1 Counter bit 1 */
#define    BM_T1CNT1	(uint8_t)(1U<<T1CNT1)
#define    T1CNT2          2       /* Timer1 Counter bit 2 */
#define    BM_T1CNT2	(uint8_t)(1U<<T1CNT2)
#define    T1CNT3          3       /* Timer1 Counter bit 3 */
#define    BM_T1CNT3	(uint8_t)(1U<<T1CNT3)
#define    T1CNT4          4       /* Timer1 Counter bit 4 */
#define    BM_T1CNT4	(uint8_t)(1U<<T1CNT4)
#define    T1CNT5          5       /* Timer1 Counter bit 5 */
#define    BM_T1CNT5	(uint8_t)(1U<<T1CNT5)
#define    T1CNT6          6       /* Timer1 Counter bit 6 */
#define    BM_T1CNT6	(uint8_t)(1U<<T1CNT6)
#define    T1CNT7          7       /* Timer1 Counter bit 7 */
#define    BM_T1CNT7	(uint8_t)(1U<<T1CNT7)

/* T1COR - Timer1 Compare Register */
#define    T1COR0          0       /* Timer1 Compare bit 0 */
#define    BM_T1COR0	(uint8_t)(1U<<T1COR0)
#define    T1COR1          1       /* Timer1 Compare bit 1 */
#define    BM_T1COR1	(uint8_t)(1U<<T1COR1)
#define    T1COR2          2       /* Timer1 Compare bit 2 */
#define    BM_T1COR2	(uint8_t)(1U<<T1COR2)
#define    T1COR3          3       /* Timer1 Compare bit 3 */
#define    BM_T1COR3	(uint8_t)(1U<<T1COR3)
#define    T1COR4          4       /* Timer1 Compare bit 4 */
#define    BM_T1COR4	(uint8_t)(1U<<T1COR4)
#define    T1COR5          5       /* Timer1 Compare bit 5 */
#define    BM_T1COR5	(uint8_t)(1U<<T1COR5)
#define    T1COR6          6       /* Timer1 Compare bit 6 */
#define    BM_T1COR6	(uint8_t)(1U<<T1COR6)
#define    T1COR7          7       /* Timer1 Compare bit 7 */
#define    BM_T1COR7	(uint8_t)(1U<<T1COR7)

/* T1CR - Timer1 control Register */
#define    T1OTM           0       /* Timer1 Overflow Toggle Mask */
#define    BM_T1OTM	(uint8_t)(1U<<T1OTM)
#define    T1CTM           1       /* Timer1 Compare Toggle Mask */
#define    BM_T1CTM	(uint8_t)(1U<<T1CTM)
#define    T1CRM           2       /* Timer1 Compare Reset Mask */
#define    BM_T1CRM	(uint8_t)(1U<<T1CRM)
#define    T1TOP           4       /* Timer1 Toggle Output Preset */
#define    BM_T1TOP	(uint8_t)(1U<<T1TOP)
#define    T1RES           5       /* Timer1 Reset */
#define    BM_T1RES	(uint8_t)(1U<<T1RES)
#define    T1TOS           6       /* Timer1 Toggle with Start */
#define    BM_T1TOS	(uint8_t)(1U<<T1TOS)
#define    T1ENA           7       /* Timer1 Enable */
#define    BM_T1ENA	(uint8_t)(1U<<T1ENA)

/* T1IFR - Timer1 Interrupt Flag Register */
#define    T1OFF           0       /* Timer1 Overflow Flag */
#define    BM_T1OFF	(uint8_t)(1U<<T1OFF)
#define    T1COF           1       /* Timer1 Compare Flag */
#define    BM_T1COF	(uint8_t)(1U<<T1COF)

/* T1IMR - Timer1 Interrupt Mask Register */
#define    T1OIM           0       /* Timer1 Overflow Interrupt Mask */
#define    BM_T1OIM	(uint8_t)(1U<<T1OIM)
#define    T1CIM           1       /* Timer1 Compare Interrupt Mask */
#define    BM_T1CIM	(uint8_t)(1U<<T1CIM)

/* T1MR - Timer1 Mode Register */
#define    T1CS0           0       /* Timer1 Clock Select bit 0 */
#define    BM_T1CS0	(uint8_t)(1U<<T1CS0)
#define    T1CS1           1       /* Timer1 Clock Select bit 1 */
#define    BM_T1CS1	(uint8_t)(1U<<T1CS1)
#define    T1PS0           2       /* Timer1 Prescaler Select bit 0 */
#define    BM_T1PS0	(uint8_t)(1U<<T1PS0)
#define    T1PS1           3       /* Timer1 Prescaler Select bit 1 */
#define    BM_T1PS1	(uint8_t)(1U<<T1PS1)
#define    T1PS2           4       /* Timer1 Prescaler Select bit 2 */
#define    BM_T1PS2	(uint8_t)(1U<<T1PS2)
#define    T1PS3           5       /* Timer1 Prescaler Select bit 3 */
#define    BM_T1PS3	(uint8_t)(1U<<T1PS3)
#define    T1DC0           6       /* Timer1 Duty Cycle bit 0 */
#define    BM_T1DC0	(uint8_t)(1U<<T1DC0)
#define    T1DC1           7       /* Timer1 Duty Cycle bit 1 */
#define    BM_T1DC1	(uint8_t)(1U<<T1DC1)


/* ***** TIMER2 *********************** */
/* T2CNT - Timer2 Counter Register */
#define    T2CNT0          0       /* Timer2 Counter bit 0 */
#define    BM_T2CNT0	(uint8_t)(1U<<T2CNT0)
#define    T2CNT1          1       /* Timer2 Counter bit 1 */
#define    BM_T2CNT1	(uint8_t)(1U<<T2CNT1)
#define    T2CNT2          2       /* Timer2 Counter bit 2 */
#define    BM_T2CNT2	(uint8_t)(1U<<T2CNT2)
#define    T2CNT3          3       /* Timer2 Counter bit 3 */
#define    BM_T2CNT3	(uint8_t)(1U<<T2CNT3)
#define    T2CNT4          4       /* Timer2 Counter bit 4 */
#define    BM_T2CNT4	(uint8_t)(1U<<T2CNT4)
#define    T2CNT5          5       /* Timer2 Counter bit 5 */
#define    BM_T2CNT5	(uint8_t)(1U<<T2CNT5)
#define    T2CNT6          6       /* Timer2 Counter bit 6 */
#define    BM_T2CNT6	(uint8_t)(1U<<T2CNT6)
#define    T2CNT7          7       /* Timer2 Counter bit 7 */
#define    BM_T2CNT7	(uint8_t)(1U<<T2CNT7)

/* T2COR - Timer2 Compare Register */
#define    T2COR0          0       /* Timer2 Compare bit 0 */
#define    BM_T2COR0	(uint8_t)(1U<<T2COR0)
#define    T2COR1          1       /* Timer2 Compare bit 1 */
#define    BM_T2COR1	(uint8_t)(1U<<T2COR1)
#define    T2COR2          2       /* Timer2 Compare bit 2 */
#define    BM_T2COR2	(uint8_t)(1U<<T2COR2)
#define    T2COR3          3       /* Timer2 Compare bit 3 */
#define    BM_T2COR3	(uint8_t)(1U<<T2COR3)
#define    T2COR4          4       /* Timer2 Compare bit 4 */
#define    BM_T2COR4	(uint8_t)(1U<<T2COR4)
#define    T2COR5          5       /* Timer2 Compare bit 5 */
#define    BM_T2COR5	(uint8_t)(1U<<T2COR5)
#define    T2COR6          6       /* Timer2 Compare bit 6 */
#define    BM_T2COR6	(uint8_t)(1U<<T2COR6)
#define    T2COR7          7       /* Timer2 Compare bit 7 */
#define    BM_T2COR7	(uint8_t)(1U<<T2COR7)

/* T2CR - Timer2 Control Register */
#define    T2OTM           0       /* Timer2 Overflow Toggle Mask */
#define    BM_T2OTM	(uint8_t)(1U<<T2OTM)
#define    T2CTM           1       /* Timer2 Compare Toggle Mask */
#define    BM_T2CTM	(uint8_t)(1U<<T2CTM)
#define    T2CRM           2       /* Timer2 Compare Reset Mask */
#define    BM_T2CRM	(uint8_t)(1U<<T2CRM)
#define    T2TOP           4       /* Timer2 Toggle Output Preset */
#define    BM_T2TOP	(uint8_t)(1U<<T2TOP)
#define    T2RES           5       /* Timer2 Reset */
#define    BM_T2RES	(uint8_t)(1U<<T2RES)
#define    T2TOS           6       /* Timer2 Toggle with Start */
#define    BM_T2TOS	(uint8_t)(1U<<T2TOS)
#define    T2ENA           7       /* Timer2 Enable */
#define    BM_T2ENA	(uint8_t)(1U<<T2ENA)

/* T2IFR - Timer2 Interrupt Flag Register */
#define    T2OFF           0       /* Timer2 Overflow Flag */
#define    BM_T2OFF	(uint8_t)(1U<<T2OFF)
#define    T2COF           1       /* Timer2 Compare Flag */
#define    BM_T2COF	(uint8_t)(1U<<T2COF)

/* T2IMR - Timer2 Interrupt Mask Register */
#define    T2OIM           0       /* Timer2 Overflow Interrupt Mask */
#define    BM_T2OIM	(uint8_t)(1U<<T2OIM)
#define    T2CIM           1       /* Timer2 Compare Interrupt Mask */
#define    BM_T2CIM	(uint8_t)(1U<<T2CIM)

/* T2MR - Timer2 Mode Register */
#define    T2CS0           0       /* Timer2 Clock Select bit 0 */
#define    BM_T2CS0	(uint8_t)(1U<<T2CS0)
#define    T2CS1           1       /* Timer2 Clock Select bit 1 */
#define    BM_T2CS1	(uint8_t)(1U<<T2CS1)
#define    T2PS0           2       /* Timer2 Prescaler Select bit 0 */
#define    BM_T2PS0	(uint8_t)(1U<<T2PS0)
#define    T2PS1           3       /* Timer2 Prescaler Select bit 1 */
#define    BM_T2PS1	(uint8_t)(1U<<T2PS1)
#define    T2PS2           4       /* Timer2 Prescaler Select bit 2 */
#define    BM_T2PS2	(uint8_t)(1U<<T2PS2)
#define    T2PS3           5       /* Timer2 Prescaler Select bit 3 */
#define    BM_T2PS3	(uint8_t)(1U<<T2PS3)
#define    T2DC0           6       /* Timer2 Duty Cycle bit 0 */
#define    BM_T2DC0	(uint8_t)(1U<<T2DC0)
#define    T2DC1           7       /* Timer2 Duty Cycle bit 1 */
#define    BM_T2DC1	(uint8_t)(1U<<T2DC1)


/* ***** TIMER3 *********************** */
/* T3CNTH - Timer3 counter High Byte Register */
#define    T3CNTH0         0       /* Timer3 counter High Byte bit 0 */
#define    BM_T3CNTH0	(uint8_t)(1U<<T3CNTH0)
#define    T3CNTH1         1       /* Timer3 counter High Byte bit 1 */
#define    BM_T3CNTH1	(uint8_t)(1U<<T3CNTH1)
#define    T3CNTH2         2       /* Timer3 counter High Byte bit 2 */
#define    BM_T3CNTH2	(uint8_t)(1U<<T3CNTH2)
#define    T3CNTH3         3       /* Timer3 counter High Byte bit 3 */
#define    BM_T3CNTH3	(uint8_t)(1U<<T3CNTH3)
#define    T3CNTH4         4       /* Timer3 counter High Byte bit 4 */
#define    BM_T3CNTH4	(uint8_t)(1U<<T3CNTH4)
#define    T3CNTH5         5       /* Timer3 counter High Byte bit 5 */
#define    BM_T3CNTH5	(uint8_t)(1U<<T3CNTH5)
#define    T3CNTH6         6       /* Timer3 counter High Byte bit 6 */
#define    BM_T3CNTH6	(uint8_t)(1U<<T3CNTH6)
#define    T3CNTH7         7       /* Timer3 counter High Byte bit 7 */
#define    BM_T3CNTH7	(uint8_t)(1U<<T3CNTH7)

/* T3CNTL - Timer3 counter Low Byte Register */
#define    T3CNTL0         0       /* Timer3 counter Low Byte bit 0 */
#define    BM_T3CNTL0	(uint8_t)(1U<<T3CNTL0)
#define    T3CNTL1         1       /* Timer3 counter Low Byte bit 1 */
#define    BM_T3CNTL1	(uint8_t)(1U<<T3CNTL1)
#define    T3CNTL2         2       /* Timer3 counter Low Byte bit 2 */
#define    BM_T3CNTL2	(uint8_t)(1U<<T3CNTL2)
#define    T3CNTL3         3       /* Timer3 counter Low Byte bit 3 */
#define    BM_T3CNTL3	(uint8_t)(1U<<T3CNTL3)
#define    T3CNTL4         4       /* Timer3 counter Low Byte bit 4 */
#define    BM_T3CNTL4	(uint8_t)(1U<<T3CNTL4)
#define    T3CNTL5         5       /* Timer3 counter Low Byte bit 5 */
#define    BM_T3CNTL5	(uint8_t)(1U<<T3CNTL5)
#define    T3CNTL6         6       /* Timer3 counter Low Byte bit 6 */
#define    BM_T3CNTL6	(uint8_t)(1U<<T3CNTL6)
#define    T3CNTL7         7       /* Timer3 counter Low Byte bit 7 */
#define    BM_T3CNTL7	(uint8_t)(1U<<T3CNTL7)

/* T3CORH - Timer3 compare High Byte Register */
#define    T3CORH0         0       /* Timer3 compare High Byte bit 0 */
#define    BM_T3CORH0	(uint8_t)(1U<<T3CORH0)
#define    T3CORH1         1       /* Timer3 compare High Byte bit 1 */
#define    BM_T3CORH1	(uint8_t)(1U<<T3CORH1)
#define    T3CORH2         2       /* Timer3 compare High Byte bit 2 */
#define    BM_T3CORH2	(uint8_t)(1U<<T3CORH2)
#define    T3CORH3         3       /* Timer3 compare High Byte bit 3 */
#define    BM_T3CORH3	(uint8_t)(1U<<T3CORH3)
#define    T3CORH4         4       /* Timer3 compare High Byte bit 4 */
#define    BM_T3CORH4	(uint8_t)(1U<<T3CORH4)
#define    T3CORH5         5       /* Timer3 compare High Byte bit 5 */
#define    BM_T3CORH5	(uint8_t)(1U<<T3CORH5)
#define    T3CORH6         6       /* Timer3 compare High Byte bit 6 */
#define    BM_T3CORH6	(uint8_t)(1U<<T3CORH6)
#define    T3CORH7         7       /* Timer3 compare High Byte bit 7 */
#define    BM_T3CORH7	(uint8_t)(1U<<T3CORH7)

/* T3CORL - Timer3 compare Low Byte Register */
#define    T3CORL0         0       /* Timer3 compare Low Byte bit 0 */
#define    BM_T3CORL0	(uint8_t)(1U<<T3CORL0)
#define    T3CORL1         1       /* Timer3 compare Low Byte bit 1 */
#define    BM_T3CORL1	(uint8_t)(1U<<T3CORL1)
#define    T3CORL2         2       /* Timer3 compare Low Byte bit 2 */
#define    BM_T3CORL2	(uint8_t)(1U<<T3CORL2)
#define    T3CORL3         3       /* Timer3 compare Low Byte bit 3 */
#define    BM_T3CORL3	(uint8_t)(1U<<T3CORL3)
#define    T3CORL4         4       /* Timer3 compare Low Byte bit 4 */
#define    BM_T3CORL4	(uint8_t)(1U<<T3CORL4)
#define    T3CORL5         5       /* Timer3 compare Low Byte bit 5 */
#define    BM_T3CORL5	(uint8_t)(1U<<T3CORL5)
#define    T3CORL6         6       /* Timer3 compare Low Byte bit 6 */
#define    BM_T3CORL6	(uint8_t)(1U<<T3CORL6)
#define    T3CORL7         7       /* Timer3 compare Low Byte bit 7 */
#define    BM_T3CORL7	(uint8_t)(1U<<T3CORL7)

/* T3CR - Timer3 control Register */
#define    T3OTM           0       /* Timer3 Overflow Toggle Mask */
#define    BM_T3OTM	(uint8_t)(1U<<T3OTM)
#define    T3CTM           1       /* Timer3 Compare Toggle Mask */
#define    BM_T3CTM	(uint8_t)(1U<<T3CTM)
#define    T3CRM           2       /* Timer3 Compare Reset Mask */
#define    BM_T3CRM	(uint8_t)(1U<<T3CRM)
#define    T3CPRM          3       /* Timer3 CaPture reset Mask */
#define    BM_T3CPRM	(uint8_t)(1U<<T3CPRM)
#define    T3TOP           4       /* Timer3 Toggle Output Preset */
#define    BM_T3TOP	(uint8_t)(1U<<T3TOP)
#define    T3RES           5       /* Timer3 Reset */
#define    BM_T3RES	(uint8_t)(1U<<T3RES)
#define    T3TOS           6       /* Timer3 Toggle with Start */
#define    BM_T3TOS	(uint8_t)(1U<<T3TOS)
#define    T3ENA           7       /* Timer3 Enable */
#define    BM_T3ENA	(uint8_t)(1U<<T3ENA)

/* T3ICRH - Timer3 input capture High Byte Register */
#define    T3ICRH0         0       /* Timer3 input capture High Byte bit 0 */
#define    BM_T3ICRH0	(uint8_t)(1U<<T3ICRH0)
#define    T3ICRH1         1       /* Timer3 input capture High Byte bit 1 */
#define    BM_T3ICRH1	(uint8_t)(1U<<T3ICRH1)
#define    T3ICRH2         2       /* Timer3 input capture High Byte bit 2 */
#define    BM_T3ICRH2	(uint8_t)(1U<<T3ICRH2)
#define    T3ICRH3         3       /* Timer3 input capture High Byte bit 3 */
#define    BM_T3ICRH3	(uint8_t)(1U<<T3ICRH3)
#define    T3ICRH4         4       /* Timer3 input capture High Byte bit 4 */
#define    BM_T3ICRH4	(uint8_t)(1U<<T3ICRH4)
#define    T3ICRH5         5       /* Timer3 input capture High Byte bit 5 */
#define    BM_T3ICRH5	(uint8_t)(1U<<T3ICRH5)
#define    T3ICRH6         6       /* Timer3 input capture High Byte bit 6 */
#define    BM_T3ICRH6	(uint8_t)(1U<<T3ICRH6)
#define    T3ICRH7         7       /* Timer3 input capture High Byte bit 7 */
#define    BM_T3ICRH7	(uint8_t)(1U<<T3ICRH7)

/* T3ICRL - Timer3 input capture Low Byte Register */
#define    T3ICRL0         0       /* Timer3 input capture Low Byte bit 0 */
#define    BM_T3ICRL0	(uint8_t)(1U<<T3ICRL0)
#define    T3ICRL1         1       /* Timer3 input capture Low Byte bit 1 */
#define    BM_T3ICRL1	(uint8_t)(1U<<T3ICRL1)
#define    T3ICRL2         2       /* Timer3 input capture Low Byte bit 2 */
#define    BM_T3ICRL2	(uint8_t)(1U<<T3ICRL2)
#define    T3ICRL3         3       /* Timer3 input capture Low Byte bit 3 */
#define    BM_T3ICRL3	(uint8_t)(1U<<T3ICRL3)
#define    T3ICRL4         4       /* Timer3 input capture Low Byte bit 4 */
#define    BM_T3ICRL4	(uint8_t)(1U<<T3ICRL4)
#define    T3ICRL5         5       /* Timer3 input capture Low Byte bit 5 */
#define    BM_T3ICRL5	(uint8_t)(1U<<T3ICRL5)
#define    T3ICRL6         6       /* Timer3 input capture Low Byte bit 6 */
#define    BM_T3ICRL6	(uint8_t)(1U<<T3ICRL6)
#define    T3ICRL7         7       /* Timer3 input capture Low Byte bit 7 */
#define    BM_T3ICRL7	(uint8_t)(1U<<T3ICRL7)

/* T3IFR - Timer3 interrupt flag Register */
#define    T3OFF           0       /* Timer3 OverFlow Flag */
#define    BM_T3OFF	(uint8_t)(1U<<T3OFF)
#define    T3COF           1       /* Timer3 Compare Flag */
#define    BM_T3COF	(uint8_t)(1U<<T3COF)
#define    T3ICF           2       /* Timer3 Input Capture Flag */
#define    BM_T3ICF	(uint8_t)(1U<<T3ICF)

/* T3IMR - Timer3 interrupt mask Register */
#define    T3OIM           0       /* Timer3 Overflow Interrupt Mask */
#define    BM_T3OIM	(uint8_t)(1U<<T3OIM)
#define    T3CIM           1       /* Timer3 Compare Interrupt Mask */
#define    BM_T3CIM	(uint8_t)(1U<<T3CIM)
#define    T3CPIM          2       /* Timer3 Capture Interrupt Mask */
#define    BM_T3CPIM	(uint8_t)(1U<<T3CPIM)

/* T3MRA - Timer3 mode Register */
#define    T3CS0           0       /* Timer 3 Clock Select bit 0 */
#define    BM_T3CS0	(uint8_t)(1U<<T3CS0)
#define    T3CS1           1       /* Timer 3 Clock Select bit 1 */
#define    BM_T3CS1	(uint8_t)(1U<<T3CS1)
#define    T3PS0           2       /* Timer3 Prescaler Select bit 0 */
#define    BM_T3PS0	(uint8_t)(1U<<T3PS0)
#define    T3PS1           3       /* Timer3 Prescaler Select bit 1 */
#define    BM_T3PS1	(uint8_t)(1U<<T3PS1)
#define    T3PS2           4       /* Timer3 Prescaler Select bit 2 */
#define    BM_T3PS2	(uint8_t)(1U<<T3PS2)

/* T3MRB - Timer3 mode Register */
#define    T3SCE           1       /* Timer3 Software Capture Enable */
#define    BM_T3SCE	(uint8_t)(1U<<T3SCE)
#define    T3CNC           2       /* Timer3 input Capture Noise Canceller */
#define    BM_T3CNC	(uint8_t)(1U<<T3CNC)
#define    T3CE0           3       /* Timer3 Capture Edge select bit 0 */
#define    BM_T3CE0	(uint8_t)(1U<<T3CE0)
#define    T3CE1           4       /* Timer3 Capture Edge select bit 1 */
#define    BM_T3CE1	(uint8_t)(1U<<T3CE1)
#define    T3ICS0          5       /* Timer3 Input Capture Select bit 0 */
#define    BM_T3ICS0	(uint8_t)(1U<<T3ICS0)
#define    T3ICS1          6       /* Timer3 Input Capture Select bit 1 */
#define    BM_T3ICS1	(uint8_t)(1U<<T3ICS1)
#define    T3ICS2          7       /* Timer3 Input Capture Select bit 2 */
#define    BM_T3ICS2	(uint8_t)(1U<<T3ICS2)


/* ***** TIMER4 *********************** */
/* T4CNTH - Timer4 counter High Byte Register */
#define    T4CNTH0         0       /* Timer4 counter High Byte bit 0 */
#define    BM_T4CNTH0	(uint8_t)(1U<<T4CNTH0)
#define    T4CNTH1         1       /* Timer4 counter High Byte bit 1 */
#define    BM_T4CNTH1	(uint8_t)(1U<<T4CNTH1)
#define    T4CNTH2         2       /* Timer4 counter High Byte bit 2 */
#define    BM_T4CNTH2	(uint8_t)(1U<<T4CNTH2)
#define    T4CNTH3         3       /* Timer4 counter High Byte bit 3 */
#define    BM_T4CNTH3	(uint8_t)(1U<<T4CNTH3)
#define    T4CNTH4         4       /* Timer4 counter High Byte bit 4 */
#define    BM_T4CNTH4	(uint8_t)(1U<<T4CNTH4)
#define    T4CNTH5         5       /* Timer4 counter High Byte bit 5 */
#define    BM_T4CNTH5	(uint8_t)(1U<<T4CNTH5)
#define    T4CNTH6         6       /* Timer4 counter High Byte bit 6 */
#define    BM_T4CNTH6	(uint8_t)(1U<<T4CNTH6)
#define    T4CNTH7         7       /* Timer4 counter High Byte bit 7 */
#define    BM_T4CNTH7	(uint8_t)(1U<<T4CNTH7)

/* T4CNTL - Timer4 counter Low Byte Register */
#define    T4CNTL0         0       /* Timer4 counter Low Byte bit 0 */
#define    BM_T4CNTL0	(uint8_t)(1U<<T4CNTL0)
#define    T4CNTL1         1       /* Timer4 counter Low Byte bit 1 */
#define    BM_T4CNTL1	(uint8_t)(1U<<T4CNTL1)
#define    T4CNTL2         2       /* Timer4 counter Low Byte bit 2 */
#define    BM_T4CNTL2	(uint8_t)(1U<<T4CNTL2)
#define    T4CNTL3         3       /* Timer4 counter Low Byte bit 3 */
#define    BM_T4CNTL3	(uint8_t)(1U<<T4CNTL3)
#define    T4CNTL4         4       /* Timer4 counter Low Byte bit 4 */
#define    BM_T4CNTL4	(uint8_t)(1U<<T4CNTL4)
#define    T4CNTL5         5       /* Timer4 counter Low Byte bit 5 */
#define    BM_T4CNTL5	(uint8_t)(1U<<T4CNTL5)
#define    T4CNTL6         6       /* Timer4 counter Low Byte bit 6 */
#define    BM_T4CNTL6	(uint8_t)(1U<<T4CNTL6)
#define    T4CNTL7         7       /* Timer4 counter Low Byte bit 7 */
#define    BM_T4CNTL7	(uint8_t)(1U<<T4CNTL7)

/* T4CORH - Timer4 compare high Byte Register */
#define    T4CORH0         0       /* Timer4 compare high Byte bit 0 */
#define    BM_T4CORH0	(uint8_t)(1U<<T4CORH0)
#define    T4CORH1         1       /* Timer4 compare high Byte bit 1 */
#define    BM_T4CORH1	(uint8_t)(1U<<T4CORH1)
#define    T4CORH2         2       /* Timer4 compare high Byte bit 2 */
#define    BM_T4CORH2	(uint8_t)(1U<<T4CORH2)
#define    T4CORH3         3       /* Timer4 compare high Byte bit 3 */
#define    BM_T4CORH3	(uint8_t)(1U<<T4CORH3)
#define    T4CORH4         4       /* Timer4 compare high Byte bit 4 */
#define    BM_T4CORH4	(uint8_t)(1U<<T4CORH4)
#define    T4CORH5         5       /* Timer4 compare high Byte bit 5 */
#define    BM_T4CORH5	(uint8_t)(1U<<T4CORH5)
#define    T4CORH6         6       /* Timer4 compare high Byte bit 6 */
#define    BM_T4CORH6	(uint8_t)(1U<<T4CORH6)
#define    T4CORH7         7       /* Timer4 compare high Byte bit 7 */
#define    BM_T4CORH7	(uint8_t)(1U<<T4CORH7)

/* T4CORL - Timer4 compare Low Byte Register */
#define    T4CORL0         0       /* Timer4 compare Low Byte bit 0 */
#define    BM_T4CORL0	(uint8_t)(1U<<T4CORL0)
#define    T4CORL1         1       /* Timer4 compare Low Byte bit 1 */
#define    BM_T4CORL1	(uint8_t)(1U<<T4CORL1)
#define    T4CORL2         2       /* Timer4 compare Low Byte bit 2 */
#define    BM_T4CORL2	(uint8_t)(1U<<T4CORL2)
#define    T4CORL3         3       /* Timer4 compare Low Byte bit 3 */
#define    BM_T4CORL3	(uint8_t)(1U<<T4CORL3)
#define    T4CORL4         4       /* Timer4 compare Low Byte bit 4 */
#define    BM_T4CORL4	(uint8_t)(1U<<T4CORL4)
#define    T4CORL5         5       /* Timer4 compare Low Byte bit 5 */
#define    BM_T4CORL5	(uint8_t)(1U<<T4CORL5)
#define    T4CORL6         6       /* Timer4 compare Low Byte bit 6 */
#define    BM_T4CORL6	(uint8_t)(1U<<T4CORL6)
#define    T4CORL7         7       /* Timer4 compare Low Byte bit */
#define    BM_T4CORL7	(uint8_t)(1U<<T4CORL7)

/* T4CR - Timer4 control Register */
#define    T4OTM           0       /* Timer4 Overflow Toggle Mask */
#define    BM_T4OTM	(uint8_t)(1U<<T4OTM)
#define    T4CTM           1       /* Timer4 Compare Toggle Mask */
#define    BM_T4CTM	(uint8_t)(1U<<T4CTM)
#define    T4CRM           2       /* Timer4 Compare Reset Mask */
#define    BM_T4CRM	(uint8_t)(1U<<T4CRM)
#define    T4CPRM          3       /* Timer4 CaPture reset Mask */
#define    BM_T4CPRM	(uint8_t)(1U<<T4CPRM)
#define    T4TOP           4       /* Timer4 Toggle Output Preset */
#define    BM_T4TOP	(uint8_t)(1U<<T4TOP)
#define    T4RES           5       /* Timer4 Reset */
#define    BM_T4RES	(uint8_t)(1U<<T4RES)
#define    T4TOS           6       /* Timer4 Toggle with Start */
#define    BM_T4TOS	(uint8_t)(1U<<T4TOS)
#define    T4ENA           7       /* Timer4 Enable */
#define    BM_T4ENA	(uint8_t)(1U<<T4ENA)

/* T4ICRH - Timer4 input capture High Byte Register */
#define    T4ICRH0         0       /* Timer4 input capture High Byte bit 0 */
#define    BM_T4ICRH0	(uint8_t)(1U<<T4ICRH0)
#define    T4ICRH1         1       /* Timer4 input capture High Byte bit 1 */
#define    BM_T4ICRH1	(uint8_t)(1U<<T4ICRH1)
#define    T4ICRH2         2       /* Timer4 input capture High Byte bit 2 */
#define    BM_T4ICRH2	(uint8_t)(1U<<T4ICRH2)
#define    T4ICRH3         3       /* Timer4 input capture High Byte bit 3 */
#define    BM_T4ICRH3	(uint8_t)(1U<<T4ICRH3)
#define    T4ICRH4         4       /* Timer4 input capture High Byte bit 4 */
#define    BM_T4ICRH4	(uint8_t)(1U<<T4ICRH4)
#define    T4ICRH5         5       /* Timer4 input capture High Byte bit 5 */
#define    BM_T4ICRH5	(uint8_t)(1U<<T4ICRH5)
#define    T4ICRH6         6       /* Timer4 input capture High Byte bit 6 */
#define    BM_T4ICRH6	(uint8_t)(1U<<T4ICRH6)
#define    T4ICRH7         7       /* Timer4 input capture High Byte bit 7 */
#define    BM_T4ICRH7	(uint8_t)(1U<<T4ICRH7)

/* T4ICRL - Timer4 input capture Low Byte Register */
#define    T4ICRL0         0       /* Timer4 input capture Low Byte bit 0 */
#define    BM_T4ICRL0	(uint8_t)(1U<<T4ICRL0)
#define    T4ICRL1         1       /* Timer4 input capture Low Byte bit 1 */
#define    BM_T4ICRL1	(uint8_t)(1U<<T4ICRL1)
#define    T4ICRL2         2       /* Timer4 input capture Low Byte bit 2 */
#define    BM_T4ICRL2	(uint8_t)(1U<<T4ICRL2)
#define    T4ICRL3         3       /* Timer4 input capture Low Byte bit 3 */
#define    BM_T4ICRL3	(uint8_t)(1U<<T4ICRL3)
#define    T4ICRL4         4       /* Timer4 input capture Low Byte bit 4 */
#define    BM_T4ICRL4	(uint8_t)(1U<<T4ICRL4)
#define    T4ICRL5         5       /* Timer4 input capture Low Byte bit 5 */
#define    BM_T4ICRL5	(uint8_t)(1U<<T4ICRL5)
#define    T4ICRL6         6       /* Timer4 input capture Low Byte bit 6 */
#define    BM_T4ICRL6	(uint8_t)(1U<<T4ICRL6)
#define    T4ICRL7         7       /* Timer4 input capture Low Byte bit 7 */
#define    BM_T4ICRL7	(uint8_t)(1U<<T4ICRL7)

/* T4IFR - Timer4 interrupt flag Register */
#define    T4OFF           0       /* Timer4 OverFlow Flag */
#define    BM_T4OFF	(uint8_t)(1U<<T4OFF)
#define    T4COF           1       /* Timer4 Compare Flag */
#define    BM_T4COF	(uint8_t)(1U<<T4COF)
#define    T4ICF           2       /* Timer4 Input Capture Flag */
#define    BM_T4ICF	(uint8_t)(1U<<T4ICF)

/* T4IMR - Timer4 interrupt mask Register */
#define    T4OIM           0       /* Timer4 Overflow Interrupt Mask */
#define    BM_T4OIM	(uint8_t)(1U<<T4OIM)
#define    T4CIM           1       /* Timer4 Compare Interrupt Mask */
#define    BM_T4CIM	(uint8_t)(1U<<T4CIM)
#define    T4CPIM          2       /* Timer4 Capture Interrupt Mask */
#define    BM_T4CPIM	(uint8_t)(1U<<T4CPIM)

/* T4MRA - Timer4 mode Register */
#define    T4CS0           0       /* Timer 4 Clock Select bit 0 */
#define    BM_T4CS0	(uint8_t)(1U<<T4CS0)
#define    T4CS1           1       /* Timer 4 Clock Select bit 1 */
#define    BM_T4CS1	(uint8_t)(1U<<T4CS1)
#define    T4PS0           2       /* Timer 4 Prescaler Select bit 0 */
#define    BM_T4PS0	(uint8_t)(1U<<T4PS0)
#define    T4PS1           3       /* Timer 4 Prescaler Select bit 1 */
#define    BM_T4PS1	(uint8_t)(1U<<T4PS1)
#define    T4PS2           4       /* Timer 4 Prescaler Select bit 2 */
#define    BM_T4PS2	(uint8_t)(1U<<T4PS2)

/* T4MRB - Timer4 mode Register */
#define    T4SCE           1       /* Timer4 Software Capture Enable */
#define    BM_T4SCE	(uint8_t)(1U<<T4SCE)
#define    T4CNC           2       /* Timer4 input Capture Noise Canceller */
#define    BM_T4CNC	(uint8_t)(1U<<T4CNC)
#define    T4CE0           3       /* Timer4 Capture Edge select bit 0 */
#define    BM_T4CE0	(uint8_t)(1U<<T4CE0)
#define    T4CE1           4       /* Timer4 Capture Edge select bit 1 */
#define    BM_T4CE1	(uint8_t)(1U<<T4CE1)
#define    T4ICS0          5       /* Timer4 Input Capture Select bit 0 */
#define    BM_T4ICS0	(uint8_t)(1U<<T4ICS0)
#define    T4ICS1          6       /* Timer4 Input Capture Select bit 1 */
#define    BM_T4ICS1	(uint8_t)(1U<<T4ICS1)
#define    T4ICS2          7       /* Timer4 Input Capture Select bit 2 */
#define    BM_T4ICS2	(uint8_t)(1U<<T4ICS2)


/* ***** TIMER5 *********************** */
/* GTCCR - General Timer/Counter Control Register */
#define    PSR10           0       /* PreScaler Reset */
#define    BM_PSR10	(uint8_t)(1U<<PSR10)
#define    TSM             7       /* Timer/Counter Synchronization Mode */
#define    BM_TSM	(uint8_t)(1U<<TSM)

/* T5CCR - Timer5 Control Register */
#define    T5CS0           0       /* Timer5 Clock Select bit 0 */
#define    BM_T5CS0	(uint8_t)(1U<<T5CS0)
#define    T5CS1           1       /* Timer5 Clock Select bit 1 */
#define    BM_T5CS1	(uint8_t)(1U<<T5CS1)
#define    T5CS2           2       /* Timer5 Clock Select bit 2 */
#define    BM_T5CS2	(uint8_t)(1U<<T5CS2)
#define    T5CTC           3       /* Clear Timer5 on Compare Match */
#define    BM_T5CTC	(uint8_t)(1U<<T5CTC)

/* T5CNTH - Timer5 Counter High byte */
#define    T5CNTH0         0       /* Timer5 Counter High byte bit 0 */
#define    BM_T5CNTH0	(uint8_t)(1U<<T5CNTH0)
#define    T5CNTH1         1       /* Timer5 Counter High byte bit 1 */
#define    BM_T5CNTH1	(uint8_t)(1U<<T5CNTH1)
#define    T5CNTH2         2       /* Timer5 Counter High byte bit 2 */
#define    BM_T5CNTH2	(uint8_t)(1U<<T5CNTH2)
#define    T5CNTH3         3       /* Timer5 Counter High byte bit 3 */
#define    BM_T5CNTH3	(uint8_t)(1U<<T5CNTH3)
#define    T5CNTH4         4       /* Timer5 Counter High byte bit 4 */
#define    BM_T5CNTH4	(uint8_t)(1U<<T5CNTH4)
#define    T5CNTH5         5       /* Timer5 Counter High byte bit 5 */
#define    BM_T5CNTH5	(uint8_t)(1U<<T5CNTH5)
#define    T5CNTH6         6       /* Timer5 Counter High byte bit 6 */
#define    BM_T5CNTH6	(uint8_t)(1U<<T5CNTH6)
#define    T5CNTH7         7       /* Timer5 Counter High byte bit 7 */
#define    BM_T5CNTH7	(uint8_t)(1U<<T5CNTH7)

/* T5CNTL - Timer5 Counter Low byte */
#define    T5CNTL0         0       /* Timer5 Counter Low byte bit 0 */
#define    BM_T5CNTL0	(uint8_t)(1U<<T5CNTL0)
#define    T5CNTL1         1       /* Timer5 Counter Low byte bit 1 */
#define    BM_T5CNTL1	(uint8_t)(1U<<T5CNTL1)
#define    T5CNTL2         2       /* Timer5 Counter Low byte bit 2 */
#define    BM_T5CNTL2	(uint8_t)(1U<<T5CNTL2)
#define    T5CNTL3         3       /* Timer5 Counter Low byte bit 3 */
#define    BM_T5CNTL3	(uint8_t)(1U<<T5CNTL3)
#define    T5CNTL4         4       /* Timer5 Counter Low byte bit 4 */
#define    BM_T5CNTL4	(uint8_t)(1U<<T5CNTL4)
#define    T5CNTL5         5       /* Timer5 Counter Low byte bit 5 */
#define    BM_T5CNTL5	(uint8_t)(1U<<T5CNTL5)
#define    T5CNTL6         6       /* Timer5 Counter Low byte bit 6 */
#define    BM_T5CNTL6	(uint8_t)(1U<<T5CNTL6)
#define    T5CNTL7         7       /* Timer5 Counter Low byte bit 7 */
#define    BM_T5CNTL7	(uint8_t)(1U<<T5CNTL7)

/* T5IFR - Timer5 Interrupt Flag Register */
#define    T5OFF           0       /* Timer5 Output Overflow Flag */
#define    BM_T5OFF	(uint8_t)(1U<<T5OFF)
#define    T5COF           1       /* Timer5 Output Compare Output Match Flag */
#define    BM_T5COF	(uint8_t)(1U<<T5COF)

/* T5IMR - Timer5 Interrupt Mask Register */
#define    T5OIM           0       /* Timer5 Output Overflow Interrupt Mask */
#define    BM_T5OIM	(uint8_t)(1U<<T5OIM)
#define    T5CIM           1       /* Timer5 Output Compare Interrupt Mask */
#define    BM_T5CIM	(uint8_t)(1U<<T5CIM)

/* T5OCRH - Timer5 Output Compare Register High byte */
#define    T5OCRH0         0       /* Timer5 Output Compare Register High byte bit 0 */
#define    BM_T5OCRH0	(uint8_t)(1U<<T5OCRH0)
#define    T5OCRH1         1       /* Timer5 Output Compare Register High byte bit 1 */
#define    BM_T5OCRH1	(uint8_t)(1U<<T5OCRH1)
#define    T5OCRH2         2       /* Timer5 Output Compare Register High byte bit 2 */
#define    BM_T5OCRH2	(uint8_t)(1U<<T5OCRH2)
#define    T5OCRH3         3       /* Timer5 Output Compare Register High byte bit 3 */
#define    BM_T5OCRH3	(uint8_t)(1U<<T5OCRH3)
#define    T5OCRH4         4       /* Timer5 Output Compare Register High byte bit 4 */
#define    BM_T5OCRH4	(uint8_t)(1U<<T5OCRH4)
#define    T5OCRH5         5       /* Timer5 Output Compare Register High byte bit 5 */
#define    BM_T5OCRH5	(uint8_t)(1U<<T5OCRH5)
#define    T5OCRH6         6       /* Timer5 Output Compare Register High byte bit 6 */
#define    BM_T5OCRH6	(uint8_t)(1U<<T5OCRH6)
#define    T5OCRH7         7       /* Timer5 Output Compare Register High byte bit 7 */
#define    BM_T5OCRH7	(uint8_t)(1U<<T5OCRH7)

/* T5OCRL - Timer5 Output Compare Register Low byte */
#define    T5OCRL0         0       /* Timer5 Output Compare Register Low byte bit 0 */
#define    BM_T5OCRL0	(uint8_t)(1U<<T5OCRL0)
#define    T5OCRL1         1       /* Timer5 Output Compare Register Low byte bit 1 */
#define    BM_T5OCRL1	(uint8_t)(1U<<T5OCRL1)
#define    T5OCRL2         2       /* Timer5 Output Compare Register Low byte bit 2 */
#define    BM_T5OCRL2	(uint8_t)(1U<<T5OCRL2)
#define    T5OCRL3         3       /* Timer5 Output Compare Register Low byte bit 3 */
#define    BM_T5OCRL3	(uint8_t)(1U<<T5OCRL3)
#define    T5OCRL4         4       /* Timer5 Output Compare Register Low byte bit 4 */
#define    BM_T5OCRL4	(uint8_t)(1U<<T5OCRL4)
#define    T5OCRL5         5       /* Timer5 Output Compare Register Low byte bit 5 */
#define    BM_T5OCRL5	(uint8_t)(1U<<T5OCRL5)
#define    T5OCRL6         6       /* Timer5 Output Compare Register Low byte bit 6 */
#define    BM_T5OCRL6	(uint8_t)(1U<<T5OCRL6)
#define    T5OCRL7         7       /* Timer5 Output Compare Register Low byte bit 7 */
#define    BM_T5OCRL7	(uint8_t)(1U<<T5OCRL7)


/* ***** TXDSP ************************ */
/* FFREQ1H - Fractional Frequency 1 Setting, High Byte */
#define    FFREQ1H0        0       /* Fractional Frequency 1 High Byte bit 0 */
#define    BM_FFREQ1H0	(uint8_t)(1U<<FFREQ1H0)
#define    FFREQ1H1        1       /* Fractional Frequency 1 High Byte bit 1 */
#define    BM_FFREQ1H1	(uint8_t)(1U<<FFREQ1H1)

/* FFREQ1L - Fractional Frequency 1 Setting, Low Byte */
#define    FFREQ1L0        0       /* Fractional Frequency 1 Low Byte bit 0 */
#define    BM_FFREQ1L0	(uint8_t)(1U<<FFREQ1L0)
#define    FFREQ1L1        1       /* Fractional Frequency 1 Low Byte bit 1 */
#define    BM_FFREQ1L1	(uint8_t)(1U<<FFREQ1L1)
#define    FFREQ1L2        2       /* Fractional Frequency 1 Low Byte bit 2 */
#define    BM_FFREQ1L2	(uint8_t)(1U<<FFREQ1L2)
#define    FFREQ1L3        3       /* Fractional Frequency 1 Low Byte bit 3 */
#define    BM_FFREQ1L3	(uint8_t)(1U<<FFREQ1L3)
#define    FFREQ1L4        4       /* Fractional Frequency 1 Low Byte bit 4 */
#define    BM_FFREQ1L4	(uint8_t)(1U<<FFREQ1L4)
#define    FFREQ1L5        5       /* Fractional Frequency 1 Low Byte bit 5 */
#define    BM_FFREQ1L5	(uint8_t)(1U<<FFREQ1L5)
#define    FFREQ1L6        6       /* Fractional Frequency 1 Low Byte bit 6 */
#define    BM_FFREQ1L6	(uint8_t)(1U<<FFREQ1L6)
#define    FFREQ1L7        7       /* Fractional Frequency 1 Low Byte bit 7 */
#define    BM_FFREQ1L7	(uint8_t)(1U<<FFREQ1L7)

/* FFREQ1M - Fractional Frequency 1 Setting, Middle Byte */
#define    FFREQ1M0        0       /* Fractional Frequency 1 Middle Byte bit 0 */
#define    BM_FFREQ1M0	(uint8_t)(1U<<FFREQ1M0)
#define    FFREQ1M1        1       /* Fractional Frequency 1 Middle Byte bit 1 */
#define    BM_FFREQ1M1	(uint8_t)(1U<<FFREQ1M1)
#define    FFREQ1M2        2       /* Fractional Frequency 1 Middle Byte bit 2 */
#define    BM_FFREQ1M2	(uint8_t)(1U<<FFREQ1M2)
#define    FFREQ1M3        3       /* Fractional Frequency 1 Middle Byte bit 3 */
#define    BM_FFREQ1M3	(uint8_t)(1U<<FFREQ1M3)
#define    FFREQ1M4        4       /* Fractional Frequency 1 Middle Byte bit 4 */
#define    BM_FFREQ1M4	(uint8_t)(1U<<FFREQ1M4)
#define    FFREQ1M5        5       /* Fractional Frequency 1 Middle Byte bit 5 */
#define    BM_FFREQ1M5	(uint8_t)(1U<<FFREQ1M5)
#define    FFREQ1M6        6       /* Fractional Frequency 1 Middle Byte bit 6 */
#define    BM_FFREQ1M6	(uint8_t)(1U<<FFREQ1M6)
#define    FFREQ1M7        7       /* Fractional Frequency 1 Middle Byte bit 7 */
#define    BM_FFREQ1M7	(uint8_t)(1U<<FFREQ1M7)

/* FFREQ2H - Fractional Frequency 2 Setting, High Byte */
#define    FFREQ2H0        0       /* Fractional Frequency 2 High Byte bit 0 */
#define    BM_FFREQ2H0	(uint8_t)(1U<<FFREQ2H0)
#define    FFREQ2H1        1       /* Fractional Frequency 2 High Byte bit 1 */
#define    BM_FFREQ2H1	(uint8_t)(1U<<FFREQ2H1)

/* FFREQ2L - Fractional Frequency 2 Setting, Low Byte */
#define    FFREQ2L0        0       /* Fractional Frequency 2 Low Byte bit 0 */
#define    BM_FFREQ2L0	(uint8_t)(1U<<FFREQ2L0)
#define    FFREQ2L1        1       /* Fractional Frequency 2 Low Byte bit 1 */
#define    BM_FFREQ2L1	(uint8_t)(1U<<FFREQ2L1)
#define    FFREQ2L2        2       /* Fractional Frequency 2 Low Byte bit 2 */
#define    BM_FFREQ2L2	(uint8_t)(1U<<FFREQ2L2)
#define    FFREQ2L3        3       /* Fractional Frequency 2 Low Byte bit 3 */
#define    BM_FFREQ2L3	(uint8_t)(1U<<FFREQ2L3)
#define    FFREQ2L4        4       /* Fractional Frequency 2 Low Byte bit 4 */
#define    BM_FFREQ2L4	(uint8_t)(1U<<FFREQ2L4)
#define    FFREQ2L5        5       /* Fractional Frequency 2 Low Byte bit 5 */
#define    BM_FFREQ2L5	(uint8_t)(1U<<FFREQ2L5)
#define    FFREQ2L6        6       /* Fractional Frequency 2 Low Byte bit 6 */
#define    BM_FFREQ2L6	(uint8_t)(1U<<FFREQ2L6)
#define    FFREQ2L7        7       /* Fractional Frequency 2 Low Byte bit 7 */
#define    BM_FFREQ2L7	(uint8_t)(1U<<FFREQ2L7)

/* FFREQ2M - Fractional Frequency 2 Setting, Middle Byte */
#define    FFREQ2M0        0       /* Fractional Frequency 2 Middle Byte bit 0 */
#define    BM_FFREQ2M0	(uint8_t)(1U<<FFREQ2M0)
#define    FFREQ2M1        1       /* Fractional Frequency 2 Middle Byte bit 1 */
#define    BM_FFREQ2M1	(uint8_t)(1U<<FFREQ2M1)
#define    FFREQ2M2        2       /* Fractional Frequency 2 Middle Byte bit 2 */
#define    BM_FFREQ2M2	(uint8_t)(1U<<FFREQ2M2)
#define    FFREQ2M3        3       /* Fractional Frequency 2 Middle Byte bit 3 */
#define    BM_FFREQ2M3	(uint8_t)(1U<<FFREQ2M3)
#define    FFREQ2M4        4       /* Fractional Frequency 2 Middle Byte bit 4 */
#define    BM_FFREQ2M4	(uint8_t)(1U<<FFREQ2M4)
#define    FFREQ2M5        5       /* Fractional Frequency 2 Middle Byte bit 5 */
#define    BM_FFREQ2M5	(uint8_t)(1U<<FFREQ2M5)
#define    FFREQ2M6        6       /* Fractional Frequency 2 Middle Byte bit 6 */
#define    BM_FFREQ2M6	(uint8_t)(1U<<FFREQ2M6)
#define    FFREQ2M7        7       /* Fractional Frequency 2 Middle Byte bit 7 */
#define    BM_FFREQ2M7	(uint8_t)(1U<<FFREQ2M7)

/* FSCR - Frequency Synthesizer Control Register */
#define    TXMOD           0       /* Tx Modulation */
#define    BM_TXMOD	(uint8_t)(1U<<TXMOD)
#define    SFM             1       /* Select FSK Modulation */
#define    BM_SFM	(uint8_t)(1U<<SFM)
#define    TXMS0           2       /* Tx Modulation Source bit 0 */
#define    BM_TXMS0	(uint8_t)(1U<<TXMS0)
#define    TXMS1           3       /* Tx Modulation Source bit 1 */
#define    BM_TXMS1	(uint8_t)(1U<<TXMS1)
#define    PAOER           4       /* Power Amplifier Output Enable Register */
#define    BM_PAOER	(uint8_t)(1U<<PAOER)
#define    PAON            7       /* Power Amplifier Output is On */
#define    BM_PAON	(uint8_t)(1U<<PAON)

/* FSEN - Frequency Synthesizer Enable register */
#define    SDPU            0       /* Sigma-delta Modulator Power Up */
#define    BM_SDPU	(uint8_t)(1U<<SDPU)
#define    SDEN            1       /* Sigma-delta Modulator Enable */
#define    BM_SDEN	(uint8_t)(1U<<SDEN)
#define    GAEN            2       /* Gauss Filtering Enable */
#define    BM_GAEN	(uint8_t)(1U<<GAEN)
#define    PEEN            3       /* Pre-emphasis Filtering Enable */
#define    BM_PEEN	(uint8_t)(1U<<PEEN)
#define    ASEN            4       /* ASK Shaping Enable */
#define    BM_ASEN	(uint8_t)(1U<<ASEN)
#define    ANTT            5       /* Antenna Tuning Active */
#define    BM_ANTT	(uint8_t)(1U<<ANTT)

/* FSFCR - Frequency Synthesizer Filter Control Register */
#define    BTSEL0          0       /* Gauss Filter BT Selection bit 0 */
#define    BM_BTSEL0	(uint8_t)(1U<<BTSEL0)
#define    BTSEL1          1       /* Gauss Filter BT Selection bit 1 */
#define    BM_BTSEL1	(uint8_t)(1U<<BTSEL1)
#define    ASDIV0          4       /* ASK Shaping Divider bit 0 */
#define    BM_ASDIV0	(uint8_t)(1U<<ASDIV0)
#define    ASDIV1          5       /* ASK Shaping Divider bit 1 */
#define    BM_ASDIV1	(uint8_t)(1U<<ASDIV1)
#define    ASDIV2          6       /* ASK Shaping Divider bit 2 */
#define    BM_ASDIV2	(uint8_t)(1U<<ASDIV2)
#define    ASDIV3          7       /* ASK Shaping Divider bit 3 */
#define    BM_ASDIV3	(uint8_t)(1U<<ASDIV3)

/* GACDIVH - Gauss Clock Divider, High Byte */
#define    GACDIVH0        0       /* Gauss Clock Divider High Byte bit 0 */
#define    BM_GACDIVH0	(uint8_t)(1U<<GACDIVH0)
#define    GACDIVH1        1       /* Gauss Clock Divider High Byte bit 1 */
#define    BM_GACDIVH1	(uint8_t)(1U<<GACDIVH1)
#define    GACDIVH2        2       /* Gauss Clock Divider High Byte bit 2 */
#define    BM_GACDIVH2	(uint8_t)(1U<<GACDIVH2)
#define    GACDIVH3        3       /* Gauss Clock Divider High Byte bit 3 */
#define    BM_GACDIVH3	(uint8_t)(1U<<GACDIVH3)
#define    GACDIVH4        4       /* Gauss Clock Divider High Byte bit 4 */
#define    BM_GACDIVH4	(uint8_t)(1U<<GACDIVH4)

/* GACDIVL - Gauss Clock Divider, Low Byte */
#define    GACDIVL0        0       /* Gauss Clock Divider Low Byte bit 0 */
#define    BM_GACDIVL0	(uint8_t)(1U<<GACDIVL0)
#define    GACDIVL1        1       /* Gauss Clock Divider Low Byte bit 1 */
#define    BM_GACDIVL1	(uint8_t)(1U<<GACDIVL1)
#define    GACDIVL2        2       /* Gauss Clock Divider Low Byte bit 2 */
#define    BM_GACDIVL2	(uint8_t)(1U<<GACDIVL2)
#define    GACDIVL3        3       /* Gauss Clock Divider Low Byte bit 3 */
#define    BM_GACDIVL3	(uint8_t)(1U<<GACDIVL3)
#define    GACDIVL4        4       /* Gauss Clock Divider Low Byte bit 4 */
#define    BM_GACDIVL4	(uint8_t)(1U<<GACDIVL4)
#define    GACDIVL5        5       /* Gauss Clock Divider Low Byte bit 5 */
#define    BM_GACDIVL5	(uint8_t)(1U<<GACDIVL5)
#define    GACDIVL6        6       /* Gauss Clock Divider Low Byte bit 6 */
#define    BM_GACDIVL6	(uint8_t)(1U<<GACDIVL6)
#define    GACDIVL7        7       /* Gauss Clock Divider Low Byte bit 7 */
#define    BM_GACDIVL7	(uint8_t)(1U<<GACDIVL7)


/* ***** TXM ************************** */
/* TMCIH - Tx Modulator CRC Init Value, High Byte */
#define    TMCIH0          0       /* Tx Modulator CRC Init Value High Byte bit 0 */
#define    BM_TMCIH0	(uint8_t)(1U<<TMCIH0)
#define    TMCIH1          1       /* Tx Modulator CRC Init Value High Byte bit 1 */
#define    BM_TMCIH1	(uint8_t)(1U<<TMCIH1)
#define    TMCIH2          2       /* Tx Modulator CRC Init Value High Byte bit 2 */
#define    BM_TMCIH2	(uint8_t)(1U<<TMCIH2)
#define    TMCIH3          3       /* Tx Modulator CRC Init Value High Byte bit 3 */
#define    BM_TMCIH3	(uint8_t)(1U<<TMCIH3)
#define    TMCIH4          4       /* Tx Modulator CRC Init Value High Byte bit 4 */
#define    BM_TMCIH4	(uint8_t)(1U<<TMCIH4)
#define    TMCIH5          5       /* Tx Modulator CRC Init Value High Byte bit 5 */
#define    BM_TMCIH5	(uint8_t)(1U<<TMCIH5)
#define    TMCIH6          6       /* Tx Modulator CRC Init Value High Byte bit 6 */
#define    BM_TMCIH6	(uint8_t)(1U<<TMCIH6)
#define    TMCIH7          7       /* Tx Modulator CRC Init Value High Byte bit 7 */
#define    BM_TMCIH7	(uint8_t)(1U<<TMCIH7)

/* TMCIL - Tx Modulator CRC Init Value Low Byte */
#define    TMCIL0          0       /* Tx Modulator CRC Init Value Low Byte bit 0 */
#define    BM_TMCIL0	(uint8_t)(1U<<TMCIL0)
#define    TMCIL1          1       /* Tx Modulator CRC Init Value Low Byte bit 1 */
#define    BM_TMCIL1	(uint8_t)(1U<<TMCIL1)
#define    TMCIL2          2       /* Tx Modulator CRC Init Value Low Byte bit 2 */
#define    BM_TMCIL2	(uint8_t)(1U<<TMCIL2)
#define    TMCIL3          3       /* Tx Modulator CRC Init Value Low Byte bit 3 */
#define    BM_TMCIL3	(uint8_t)(1U<<TMCIL3)
#define    TMCIL4          4       /* Tx Modulator CRC Init Value Low Byte bit 4 */
#define    BM_TMCIL4	(uint8_t)(1U<<TMCIL4)
#define    TMCIL5          5       /* Tx Modulator CRC Init Value Low Byte bit 5 */
#define    BM_TMCIL5	(uint8_t)(1U<<TMCIL5)
#define    TMCIL6          6       /* Tx Modulator CRC Init Value Low Byte bit 6 */
#define    BM_TMCIL6	(uint8_t)(1U<<TMCIL6)
#define    TMCIL7          7       /* Tx Modulator CRC Init Value Low Byte bit 7 */
#define    BM_TMCIL7	(uint8_t)(1U<<TMCIL7)

/* TMCPH - Tx Modulator CRC Polynomial, High Byte */
#define    TMCPH0          0       /* Tx Modulator CRC Polynomial High Byte bit 0 */
#define    BM_TMCPH0	(uint8_t)(1U<<TMCPH0)
#define    TMCPH1          1       /* Tx Modulator CRC Polynomial High Byte bit 1 */
#define    BM_TMCPH1	(uint8_t)(1U<<TMCPH1)
#define    TMCPH2          2       /* Tx Modulator CRC Polynomial High Byte bit 2 */
#define    BM_TMCPH2	(uint8_t)(1U<<TMCPH2)
#define    TMCPH3          3       /* Tx Modulator CRC Polynomial High Byte bit 3 */
#define    BM_TMCPH3	(uint8_t)(1U<<TMCPH3)
#define    TMCPH4          4       /* Tx Modulator CRC Polynomial High Byte bit 4 */
#define    BM_TMCPH4	(uint8_t)(1U<<TMCPH4)
#define    TMCPH5          5       /* Tx Modulator CRC Polynomial High Byte bit 5 */
#define    BM_TMCPH5	(uint8_t)(1U<<TMCPH5)
#define    TMCPH6          6       /* Tx Modulator CRC Polynomial High Byte bit 6 */
#define    BM_TMCPH6	(uint8_t)(1U<<TMCPH6)
#define    TMCPH7          7       /* Tx Modulator CRC Polynomial High Byte bit 7 */
#define    BM_TMCPH7	(uint8_t)(1U<<TMCPH7)

/* TMCPL - Tx Modulator CRC Polynomial, Low Byte */
#define    TMCPL0          0       /* Tx Modulator CRC Polynomial Low Byte bit 0 */
#define    BM_TMCPL0	(uint8_t)(1U<<TMCPL0)
#define    TMCPL1          1       /* Tx Modulator CRC Polynomial Low Byte bit 1 */
#define    BM_TMCPL1	(uint8_t)(1U<<TMCPL1)
#define    TMCPL2          2       /* Tx Modulator CRC Polynomial Low Byte bit 2 */
#define    BM_TMCPL2	(uint8_t)(1U<<TMCPL2)
#define    TMCPL3          3       /* Tx Modulator CRC Polynomial Low Byte bit 3 */
#define    BM_TMCPL3	(uint8_t)(1U<<TMCPL3)
#define    TMCPL4          4       /* Tx Modulator CRC Polynomial Low Byte bit 4 */
#define    BM_TMCPL4	(uint8_t)(1U<<TMCPL4)
#define    TMCPL5          5       /* Tx Modulator CRC Polynomial Low Byte bit 5 */
#define    BM_TMCPL5	(uint8_t)(1U<<TMCPL5)
#define    TMCPL6          6       /* Tx Modulator CRC Polynomial Low Byte bit 6 */
#define    BM_TMCPL6	(uint8_t)(1U<<TMCPL6)
#define    TMCPL7          7       /* Tx Modulator CRC Polynomial Low Byte bit 7 */
#define    BM_TMCPL7	(uint8_t)(1U<<TMCPL7)

/* TMCR1 - Tx Modulator Control Register 1 */
#define    TMPIS0          0       /* Tx Modulator Port Interface Select bit 0 */
#define    BM_TMPIS0	(uint8_t)(1U<<TMPIS0)
#define    TMPIS1          1       /* Tx Modulator Port Interface Select bit 1 */
#define    BM_TMPIS1	(uint8_t)(1U<<TMPIS1)
#define    TMPIS2          2       /* Tx Modulator Port Interface Select bit 2 */
#define    BM_TMPIS2	(uint8_t)(1U<<TMPIS2)
#define    TMSCS           3       /* Tx Modulator Serial Output Clock Select */
#define    BM_TMSCS	(uint8_t)(1U<<TMSCS)
#define    TMCIM           4       /* Tx Modulator Transmission Complete Interrupt Mask */
#define    BM_TMCIM	(uint8_t)(1U<<TMCIM)

/* TMCR2 - Tx Modulator Control Register 2 */
#define    TMCRCE          0       /* Tx Modulator CRC Enable */
#define    BM_TMCRCE	(uint8_t)(1U<<TMCRCE)
#define    TMCRCL0         1       /* Tx Modulator CRC Length bit 0 */
#define    BM_TMCRCL0	(uint8_t)(1U<<TMCRCL0)
#define    TMCRCL1         2       /* Tx Modulator CRC Length bit 1 */
#define    BM_TMCRCL1	(uint8_t)(1U<<TMCRCL1)
#define    TMNRZE          3       /* Tx Modulator NRZ Mode Enable */
#define    BM_TMNRZE	(uint8_t)(1U<<TMNRZE)
#define    TMPOL           4       /* Tx Modulator Polarity */
#define    BM_TMPOL	(uint8_t)(1U<<TMPOL)
#define    TMSSE           5       /* Tx Modulator Stop Sequence Enable */
#define    BM_TMSSE	(uint8_t)(1U<<TMSSE)
#define    TMMSB           6       /* Tx Modulator Most Significant Bit First */
#define    BM_TMMSB	(uint8_t)(1U<<TMMSB)

/* TMCRH - Tx Modulator CRC Result, High Byte */
#define    TMCRH0          0       /* Tx Modulator CRC Result High Byte bit 0 */
#define    BM_TMCRH0	(uint8_t)(1U<<TMCRH0)
#define    TMCRH1          1       /* Tx Modulator CRC Result High Byte bit 1 */
#define    BM_TMCRH1	(uint8_t)(1U<<TMCRH1)
#define    TMCRH2          2       /* Tx Modulator CRC Result High Byte bit 2 */
#define    BM_TMCRH2	(uint8_t)(1U<<TMCRH2)
#define    TMCRH3          3       /* Tx Modulator CRC Result High Byte bit 3 */
#define    BM_TMCRH3	(uint8_t)(1U<<TMCRH3)
#define    TMCRH4          4       /* Tx Modulator CRC Result High Byte bit 4 */
#define    BM_TMCRH4	(uint8_t)(1U<<TMCRH4)
#define    TMCRH5          5       /* Tx Modulator CRC Result High Byte bit 5 */
#define    BM_TMCRH5	(uint8_t)(1U<<TMCRH5)
#define    TMCRH6          6       /* Tx Modulator CRC Result High Byte bit 6 */
#define    BM_TMCRH6	(uint8_t)(1U<<TMCRH6)
#define    TMCRH7          7       /* Tx Modulator CRC Result High Byte bit 7 */
#define    BM_TMCRH7	(uint8_t)(1U<<TMCRH7)

/* TMCRL - Tx Modulator CRC Result, Low Byte */
#define    TMCRL0          0       /* Tx Modulator CRC Result Low Byte bit 0 */
#define    BM_TMCRL0	(uint8_t)(1U<<TMCRL0)
#define    TMCRL1          1       /* Tx Modulator CRC Result Low Byte bit 1 */
#define    BM_TMCRL1	(uint8_t)(1U<<TMCRL1)
#define    TMCRL2          2       /* Tx Modulator CRC Result Low Byte bit 2 */
#define    BM_TMCRL2	(uint8_t)(1U<<TMCRL2)
#define    TMCRL3          3       /* Tx Modulator CRC Result Low Byte bit 3 */
#define    BM_TMCRL3	(uint8_t)(1U<<TMCRL3)
#define    TMCRL4          4       /* Tx Modulator CRC Result Low Byte bit 4 */
#define    BM_TMCRL4	(uint8_t)(1U<<TMCRL4)
#define    TMCRL5          5       /* Tx Modulator CRC Result Low Byte bit 5 */
#define    BM_TMCRL5	(uint8_t)(1U<<TMCRL5)
#define    TMCRL6          6       /* Tx Modulator CRC Result Low Byte bit 6 */
#define    BM_TMCRL6	(uint8_t)(1U<<TMCRL6)
#define    TMCRL7          7       /* Tx Modulator CRC Result Low Byte bit 7 */
#define    BM_TMCRL7	(uint8_t)(1U<<TMCRL7)

/* TMCSB - Tx Modulator CRC Skip Bit Number */
#define    TMCSB0          0       /* Tx Modulator CRC Skip Bit Number bit 0 */
#define    BM_TMCSB0	(uint8_t)(1U<<TMCSB0)
#define    TMCSB1          1       /* Tx Modulator CRC Skip Bit Number bit 1 */
#define    BM_TMCSB1	(uint8_t)(1U<<TMCSB1)
#define    TMCSB2          2       /* Tx Modulator CRC Skip Bit Number bit 2 */
#define    BM_TMCSB2	(uint8_t)(1U<<TMCSB2)
#define    TMCSB3          3       /* Tx Modulator CRC Skip Bit Number bit 3 */
#define    BM_TMCSB3	(uint8_t)(1U<<TMCSB3)
#define    TMCSB4          4       /* Tx Modulator CRC Skip Bit Number bit 4 */
#define    BM_TMCSB4	(uint8_t)(1U<<TMCSB4)
#define    TMCSB5          5       /* Tx Modulator CRC Skip Bit Number bit 5 */
#define    BM_TMCSB5	(uint8_t)(1U<<TMCSB5)
#define    TMCSB6          6       /* Tx Modulator CRC Skip Bit Number bit 6 */
#define    BM_TMCSB6	(uint8_t)(1U<<TMCSB6)
#define    TMCSB7          7       /* Tx Modulator CRC Skip Bit Number bit 7 */
#define    BM_TMCSB7	(uint8_t)(1U<<TMCSB7)

/* TMFSM - Tx Modulator Finite State Machine */
#define    TMSSM0          0       /* Tx Modulator Sub State Machine bit 0 */
#define    BM_TMSSM0	(uint8_t)(1U<<TMSSM0)
#define    TMSSM1          1       /* Tx Modulator Sub State Machine bit 1 */
#define    BM_TMSSM1	(uint8_t)(1U<<TMSSM1)
#define    TMSSM2          2       /* Tx Modulator Sub State Machine bit 2 */
#define    BM_TMSSM2	(uint8_t)(1U<<TMSSM2)
#define    TMSSM3          3       /* Tx Modulator Sub State Machine bit 3 */
#define    BM_TMSSM3	(uint8_t)(1U<<TMSSM3)
#define    TMMSM0          4       /* Tx Modulator Master State Machine bit 0 */
#define    BM_TMMSM0	(uint8_t)(1U<<TMMSM0)
#define    TMMSM1          5       /* Tx Modulator Master State Machine bit 1 */
#define    BM_TMMSM1	(uint8_t)(1U<<TMMSM1)
#define    TMMSM2          6       /* Tx Modulator Master State Machine bit 2 */
#define    BM_TMMSM2	(uint8_t)(1U<<TMMSM2)

/* TMSHR - Tx Modulator Shift Register */
#define    TMSHR0          0       /* Tx Modulator Shift Register bit 0 */
#define    BM_TMSHR0	(uint8_t)(1U<<TMSHR0)
#define    TMSHR1          1       /* Tx Modulator Shift Register bit 1 */
#define    BM_TMSHR1	(uint8_t)(1U<<TMSHR1)
#define    TMSHR2          2       /* Tx Modulator Shift Register bit 2 */
#define    BM_TMSHR2	(uint8_t)(1U<<TMSHR2)
#define    TMSHR3          3       /* Tx Modulator Shift Register bit 3 */
#define    BM_TMSHR3	(uint8_t)(1U<<TMSHR3)
#define    TMSHR4          4       /* Tx Modulator Shift Register bit 4 */
#define    BM_TMSHR4	(uint8_t)(1U<<TMSHR4)
#define    TMSHR5          5       /* Tx Modulator Shift Register bit 5 */
#define    BM_TMSHR5	(uint8_t)(1U<<TMSHR5)
#define    TMSHR6          6       /* Tx Modulator Shift Register bit 6 */
#define    BM_TMSHR6	(uint8_t)(1U<<TMSHR6)
#define    TMSHR7          7       /* Tx Modulator Shift Register bit 7 */
#define    BM_TMSHR7	(uint8_t)(1U<<TMSHR7)

/* TMSR - Tx Modulator Status Register */
#define    TMTCF           0       /* Tx Modulator Transmission Complete Status Flag */
#define    BM_TMTCF	(uint8_t)(1U<<TMTCF)

/* TMSSC - Tx Modulator Stop Sequence Configuration */
#define    TMSSP0          0       /* Tx Modulator Stop Sequence Pattern bit 0 */
#define    BM_TMSSP0	(uint8_t)(1U<<TMSSP0)
#define    TMSSP1          1       /* Tx Modulator Stop Sequence Pattern bit 1 */
#define    BM_TMSSP1	(uint8_t)(1U<<TMSSP1)
#define    TMSSP2          2       /* Tx Modulator Stop Sequence Pattern bit 2 */
#define    BM_TMSSP2	(uint8_t)(1U<<TMSSP2)
#define    TMSSP3          3       /* Tx Modulator Stop Sequence Pattern bit 3 */
#define    BM_TMSSP3	(uint8_t)(1U<<TMSSP3)
#define    TMSSL0          4       /* Tx Modulator Stop Sequence Length bit 0 */
#define    BM_TMSSL0	(uint8_t)(1U<<TMSSL0)
#define    TMSSL1          5       /* Tx Modulator Stop Sequence Length bit 1 */
#define    BM_TMSSL1	(uint8_t)(1U<<TMSSL1)
#define    TMSSL2          6       /* Tx Modulator Stop Sequence Length bit 2 */
#define    BM_TMSSL2	(uint8_t)(1U<<TMSSL2)
#define    TMSSH           7       /* Tx Modulator Stop Sequence Hold Mode */
#define    BM_TMSSH	(uint8_t)(1U<<TMSSH)

/* TMTLH - Tx Modulator Telegram Length Register, High Byte */
#define    TMTLH0          0       /* Tx Modulator Telegram Length High Byte bit 0 */
#define    BM_TMTLH0	(uint8_t)(1U<<TMTLH0)
#define    TMTLH1          1       /* Tx Modulator Telegram Length High Byte bit 1 */
#define    BM_TMTLH1	(uint8_t)(1U<<TMTLH1)
#define    TMTLH2          2       /* Tx Modulator Telegram Length High Byte bit 2 */
#define    BM_TMTLH2	(uint8_t)(1U<<TMTLH2)
#define    TMTLH3          3       /* Tx Modulator Telegram Length High Byte bit 3 */
#define    BM_TMTLH3	(uint8_t)(1U<<TMTLH3)

/* TMTLL - Tx Modulator Telegram Length Register, Low Byte */
#define    TMTLL0          0       /* Tx Modulator Telegram Length Low Byte bit 0 */
#define    BM_TMTLL0	(uint8_t)(1U<<TMTLL0)
#define    TMTLL1          1       /* Tx Modulator Telegram Length Low Byte bit 1 */
#define    BM_TMTLL1	(uint8_t)(1U<<TMTLL1)
#define    TMTLL2          2       /* Tx Modulator Telegram Length Low Byte bit 2 */
#define    BM_TMTLL2	(uint8_t)(1U<<TMTLL2)
#define    TMTLL3          3       /* Tx Modulator Telegram Length Low Byte bit 3 */
#define    BM_TMTLL3	(uint8_t)(1U<<TMTLL3)
#define    TMTLL4          4       /* Tx Modulator Telegram Length Low Byte bit 4 */
#define    BM_TMTLL4	(uint8_t)(1U<<TMTLL4)
#define    TMTLL5          5       /* Tx Modulator Telegram Length Low Byte bit 5 */
#define    BM_TMTLL5	(uint8_t)(1U<<TMTLL5)
#define    TMTLL6          6       /* Tx Modulator Telegram Length Low Byte bit 6 */
#define    BM_TMTLL6	(uint8_t)(1U<<TMTLL6)
#define    TMTLL7          7       /* Tx Modulator Telegram Length Low Byte bit 7 */
#define    BM_TMTLL7	(uint8_t)(1U<<TMTLL7)



/* ***** LOCKSBITS ******************************************************** */
#define    LB1             0       /* Lock bit */
#define    LB2             1       /* Lock bit */
#define    BLB01           2       /* Boot Lock bit */
#define    BLB02           3       /* Boot Lock bit */
#define    BLB11           4       /* Boot lock bit */
#define    BLB12           5       /* Boot lock bit */


/* ***** FUSES ************************************************************ */
/* LOW fuse bits */



/* ***** CPU REGISTER DEFINITIONS ***************************************** */
#define    XH              r27
#define    XL              r26
#define    YH              r29
#define    YL              r28
#define    ZH              r31
#define    ZL              r30



/* ***** DATA MEMORY DECLARATIONS ***************************************** */
#define    FLASHEND        0xcfff  /* Note: Byte address */
#define    IOEND           0x01ff
#define    SRAM_START      0x0200
#define    SRAM_SIZE       1024
#define    RAMEND          0x05ff
#define    XRAMEND         0x0000
#define    E2END           0x047f
#define    EEPROMEND       0x047f
#define    EEADRBITS       10



/* ***** BOOTLOADER DECLARATIONS ****************************************** */
#define    NRWW_START_ADDR 0xc00
#define    NRWW_STOP_ADDR  0xfff
#define    RWW_START_ADDR  0x0
#define    RWW_STOP_ADDR   0xbff
#define    PAGESIZE        32
#define    FIRSTBOOTSTART  0x4600
#define    SECONDBOOTSTART 0x4000
#define    THIRDBOOTSTART  0x3000
#define    FOURTHBOOTSTART 0x2800
#define    SMALLBOOTSTART  FIRSTBOOTSTART
#define    LARGEBOOTSTART  FOURTHBOOTSTART

#endif /* ENABLE_BIT_DEFINITIONS */



/* ***** INTERRUPT VECTORS ************************************************ */
#define    RESET_vect      (0x00)  /* External Pin, Power-on Reset, Brown-out Reset and Watchdog Reset */
#define    INT0_vect       (0x04)  /* External Interrupt Request 0 */
#define    INT1_vect       (0x08)  /* External Interrupt Request 1 */
#define    PCINT0_vect     (0x0c)  /* Pin Change Interrupt Request 0 */
#define    PCINT1_vect     (0x10)  /* Pin Change Interrupt Request 1 */
#define    VMON_vect       (0x14)  /* Voltage Monitoring Interrupt */
#define    AVCCR_vect      (0x18)  /* AVCC Reset Interrupt */
#define    AVCCL_vect      (0x1c)  /* AVCC Low Interrupt */
#define    T0INT_vect      (0x20)  /* Timer 0 Interval Interrupt */
#define    T1COMP_vect     (0x24)  /* Timer/Counter1 Compare Match Interrupt */
#define    T1OVF_vect      (0x28)  /* Timer/Counter1 Overflow Interrupt */
#define    T2COMP_vect     (0x2c)  /* Timer/Counter2 Compare Match Interrupt */
#define    T2OVF_vect      (0x30)  /* Timer/Counter2 Overflow Interrupt */
#define    T3CAP_vect      (0x34)  /* Timer/Counter3 Capture Event Interrupt */
#define    T3COMP_vect     (0x38)  /* Timer/Counter3 Compare Match Interrupt */
#define    T3OVF_vect      (0x3c)  /* Timer/Counter3 Overflow Interrupt */
#define    T4CAP_vect      (0x40)  /* Timer/Counter4 Capture Event Interrupt */
#define    T4COMP_vect     (0x44)  /* Timer/Counter4 Compare Match Interrupt */
#define    T4OVF_vect      (0x48)  /* Timer/Counter4 Overflow Interrupt */
#define    T5COMP_vect     (0x4c)  /* Timer/Counter5 Compare Match Interrupt */
#define    T5OVF_vect      (0x50)  /* Timer/Counter5 Overflow Interrupt */
#define    SPI_STC_vect    (0x54)  /* SPI Serial Transfer Complete Interrupt */
#define    SRX_FIFO_vect   (0x58)  /* SPI Rx Buffer Interrupt */
#define    STX_FIFO_vect   (0x5c)  /* SPI Tx Buffer Interrupt */
#define    SSM_vect        (0x60)  /* Sequencer State Machine Interrupt */
#define    DFFLR_vect      (0x64)  /* Data FIFO fill level reached Interrupt */
#define    DFOUE_vect      (0x68)  /* Data FIFO overflow or underflow error Interrupt */
#define    SFFLR_vect      (0x6c)  /* RSSI/Preamble FIFO fill level reached Interrupt */
#define    SFOUE_vect      (0x70)  /* RSSI/Preamble FIFO overflow or underflow error Interrupt */
#define    TMTCF_vect      (0x74)  /* Tx Modulator Telegram Finish Interrupt */
#define    UHF_WCOB_vect   (0x78)  /* UHF receiver wake up ok on Rx path B */
#define    UHF_WCOA_vect   (0x7c)  /* UHF receiver wake up ok on Rx path A */
#define    UHF_SOTB_vect   (0x80)  /* UHF receiver start of telegram ok on Rx path B */
#define    UHF_SOTA_vect   (0x84)  /* UHF receiver start of telegram ok on Rx path A */
#define    UHF_EOTB_vect   (0x88)  /* UHF receiver end of telegram on Rx path B */
#define    UHF_EOTA_vect   (0x8c)  /* UHF receiver end of telegram on Rx path A */
#define    UHF_NBITB_vect  (0x90)  /* UHF receiver new bit on Rx path B */
#define    UHF_NBITA_vect  (0x94)  /* UHF receiver new bit on Rx path A */
#define    EXCM_vect       (0x98)  /* External input Clock monitoring Interrupt */
#define    ERDY_vect       (0x9c)  /* EEPROM Ready Interrupt */
#define    SPM_RDY_vect    (0xa0)  /* Store Program Memory Ready */
#define    IDFULL_vect     (0xa4)  /* IDSCAN Full Interrupt */



#endif /* __IOATA5831_H (define part) */

#pragma language=default

#endif  /* __IOATA5831_H (SFR part)*/

/* ***** END OF FILE ****************************************************** */
#endif /* IOATA5831_H_OVERALL */
