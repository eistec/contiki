/*
 * Copyright (c) 2014, Eistec AB.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * This file is part of the Mulle platform port of the Contiki operating system.
 *
 */

/**
 * \file
 *         K60 hardware register header wrapper.
 * \author
 *         Joakim Gebart <joakim.gebart@eistec.se>
 */

#ifndef K60_H_
#define K60_H_

#include "config-board.h"

#ifdef __cplusplus
/* MK60D10.h or MK60DZ10.h will be included within extern "C", this is OK. */
extern "C" {
#endif

#if K60_CPU_REV == 2

/* K60 CPU silicon version 2.x */
#include "MK60D10.h"

/** The expected CPUID value, can be used to implement a check that we are
 * running on the right hardware */
#define K60_EXPECTED_CPUID 0x410fc241u

#elif K60_CPU_REV == 1

/* K60 CPU silicon version 1.x */

#include "MK60DZ10.h"

/** The expected CPUID value, can be used to implement a check that we are
 * running on the right hardware */
#define K60_EXPECTED_CPUID 0x410fc240u

/* Some compatibility defines to minimize the ifdefs needed for the register
 * name changes */

#define SIM_SCGC6_SPI0_MASK SIM_SCGC6_DSPI0_MASK
#define SIM_SCGC6_SPI0_SHIFT SIM_SCGC6_DSPI0_SHIFT

#define MCG_C2_RANGE0_MASK MCG_C2_RANGE_MASK
#define MCG_C5_PRDIV0_MASK MCG_C5_PRDIV_MASK
#define MCG_C6_VDIV0_MASK MCG_C6_VDIV_MASK

/* The base array initializers are missing from the older MK60DZ10.h header. */
/* Copy and paste from MK60D10.h: */
#define ADC_BASE_PTRS                                { ADC0, ADC1 }
#define AIPS_BASE_PTRS                               { AIPS0, AIPS1 }
#define AXBS_BASE_PTRS                               { AXBS }
#define CAN_BASE_PTRS                                { CAN0, CAN1 }
#define CAU_BASE_PTRS                                { CAU }
#define CMP_BASE_PTRS                                { CMP0, CMP1, CMP2 }
#define CMT_BASE_PTRS                                { CMT }
#define CRC_BASE_PTRS                                { CRC0 }
#define DAC_BASE_PTRS                                { DAC0, DAC1 }
#define DMA_BASE_PTRS                                { DMA0 }
#define DMAMUX_BASE_PTRS                             { DMAMUX }
#define ENET_BASE_PTRS                               { ENET }
#define EWM_BASE_PTRS                                { EWM }
#define FB_BASE_PTRS                                 { FB }
#define FMC_BASE_PTRS                                { FMC }
#define FTFL_BASE_PTRS                               { FTFL }
#define FTM_BASE_PTRS                                { FTM0, FTM1, FTM2 }
#define GPIO_BASE_PTRS                               { PTA, PTB, PTC, PTD, PTE }
#define I2C_BASE_PTRS                                { I2C0, I2C1 }
#define I2S_BASE_PTRS                                { I2S0 }
#define LLWU_BASE_PTRS                               { LLWU }
#define LPTMR_BASE_PTRS                              { LPTMR0 }
#define MCG_BASE_PTRS                                { MCG }
#define MCM_BASE_PTRS                                { MCM }
#define MPU_BASE_PTRS                                { MPU }
#define NV_BASE_PTRS                                 { FTFL_FlashConfig }
#define OSC_BASE_PTRS                                { OSC }
#define PDB_BASE_PTRS                                { PDB0 }
#define PIT_BASE_PTRS                                { PIT }
#define PMC_BASE_PTRS                                { PMC }
#define PORT_BASE_PTRS                               { PORTA, PORTB, PORTC, PORTD, PORTE }
/* No RCM in MK60DZ10.h */
/* #define RCM_BASE_PTRS                                { RCM } */
#define RFSYS_BASE_PTRS                              { RFSYS }
#define RFVBAT_BASE_PTRS                             { RFVBAT }
#define RNG_BASE_PTRS                                { RNG }
#define RTC_BASE_PTRS                                { RTC }
#define SDHC_BASE_PTRS                               { SDHC }
#define SIM_BASE_PTRS                                { SIM }
/* MC->SMC in rev.1 to rev.2 conversion */
#define MC_BASE_PTRS                                 { MC }
#define SPI_BASE_PTRS                                { SPI0, SPI1, SPI2 }
#define TSI_BASE_PTRS                                { TSI0 }
#define UART_BASE_PTRS                               { UART0, UART1, UART2, UART3, UART4, UART5 }
#define USB_BASE_PTRS                                { USB0 }
#define USBDCD_BASE_PTRS                             { USBDCD }
#define VREF_BASE_PTRS                               { VREF }
#define WDOG_BASE_PTRS                               { WDOG }

#else
#error K60_CPU_REV must be set to the correct CPU revision!
#endif

extern ADC_Type * const ADC[];
extern AIPS_Type * const AIPS[];
extern CAN_Type * const CAN[];
extern CMP_Type * const CMP[];
extern CRC_Type * const CRC[];
extern DAC_Type * const DAC[];
extern DMA_Type * const DMA[];
extern FTM_Type * const FTM[];
extern GPIO_Type * const GPIO[]; /* 0 = A, 1 = B ... */
extern I2C_Type * const I2C[];
extern I2S_Type * const I2S[];
extern LPTMR_Type * const LPTMR[];
extern PDB_Type * const PDB[];
extern PORT_Type * const PORT[]; /* 0 = A, 1 = B ... */
extern SPI_Type * const SPI[];
extern TSI_Type * const TSI[];
extern UART_Type * const UART[];
extern USB_Type * const USB[];

#define K60_RUNNING_CPU_REVISION (SCB_CPUID & SCB_CPUID_REVISION_MASK)

/* Helpers for the below macro, used to expand the sig variable to a numeric
 * string, even if it is defined as a macro constant. */
#define K60_H_EXPAND_AND_STRINGIFY(s) K60_H_STRINGIFY(s)
#define K60_H_STRINGIFY(s) #s

/**
 * Make the CPU signal to the debugger and break execution by issuing a bkpt
 * instruction.
 */
#define DEBUGGER_BREAK(sig) asm volatile ("bkpt #" K60_H_EXPAND_AND_STRINGIFY(sig) "\n")

/*
 * These are constants that can be used to identify the signal to
 * DEBUGGER_BREAK(). These can not be converted to an enum because
 * DEBUGGER_BREAK() is a macro and not a function
 */
#define BREAK_FAULT_HANDLER 0
#define BREAK_INVALID_PARAM 1
#define BREAK_EXIT 2
#define BREAK_MEMORY_CORRUPTION 3
#define BREAK_WRONG_K60_CPU_REV 99
/* Do not use 0xAB, it is reserved for ARM semihosting environment. */
#define BREAK_SEMIHOSTING 0xAB

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* K60_H_ */
