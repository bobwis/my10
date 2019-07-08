/* ===================================================================================
 * Copyright (c) <2009> Synopsys, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software annotated with this license and associated documentation files 
 * (the "Software"), to deal in the Software without restriction, including without 
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * =================================================================================== */
/******************************************************************************
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with
 * Infineon's microcontrollers.
 * This file can be freely distributed within development tools that are
 * supporting such microcontrollers.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ********************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : DAVE App Developer                                                **
**                                                                            **
** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Dec 12, 2012                                           **
**                                                                            **
*******************************************************************************/
 
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** JRP        DAVE App Developer                                              **
*******************************************************************************/

/**\file
 *  This file serves as the wrapper for the platform/OS dependent functions
 *  It is needed to modify these functions accordingly based on the platform and the
 *  OS. Whenever the synopsys GMAC driver ported on to different platform, this file
 *  should be handled at most care.
 *  The corresponding function definitions for non-inline functions are available in 
 *  synopGMAC_plat.c file.
 * \internal
 * -------------------------------------REVISION HISTORY---------------------------
 * Synopsys 				01/Aug/2007		 	   Created
 *
 * Infineon                 12/Dec/2012            DBG002 related macro is used
 */
 
 
#ifndef SYNOP_GMAC_PLAT_H
#define SYNOP_GMAC_PLAT_H 1

#include <DAVE3.h>

/**
 * @cond INTERNAL_DOCS
 */
#if 0
typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t u8;


typedef signed long  s32;
typedef signed short s16;
typedef int8_t  s8;
typedef uint32_t dma_addr_t;
#endif
#define CABLE_STATUS_PERIOD 5

#define TR(message) \
{ \
	DBG002_INFO(DBG002_GID_ETH001, ETH_SYNOPSYS_MSG, sizeof(message), message); \
}

#define DEFAULT_DELAY_VARIABLE  10

/* There are platform related endian conversions
 *
 */
#define LE32_TO_CPU	__le32_to_cpu
#define BE32_TO_CPU	__be32_to_cpu
#define CPU_TO_LE32	__cpu_to_le32

/* Error Codes */
#define ESYNOPGMACNOERR   0
#define ESYNOPGMACNOMEM   1
#define ESYNOPGMACPHYERR  2
#define ESYNOPGMACBUSY    3

/**
  * These are the wrapper function prototypes for OS/platform related routines
  */ 
#ifdef LINUX_CODE
void * plat_alloc_memory(u32 );
void   plat_free_memory(void *);
#endif

void   plat_delay(u32);
u32 synopGMACReadReg(u32 *RegBase, u32 RegOffset);
void  synopGMACWriteReg(u32 *RegBase, u32 RegOffset, u32 RegData);
void synopGMACSetBits(u32 *RegBase, u32 RegOffset, u32 BitPos);
void synopGMACClearBits(u32 *RegBase, u32 RegOffset, u32 BitPos);
bool synopGMACCheckBits(u32 *RegBase, u32 RegOffset, u32 BitPos);

/**
 * @endcond
 */

#endif

