
/*CODE_BLOCK_BEGIN[SPI001_Conf.c]*/
/******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                **
 All rights reserved.                                                        **
                                                                             **
 Redistribution and use in source and binary forms, with or without          **
 modification,are permitted provided that the following conditions are met:  **
                                                                             **
 *Redistributions of source code must retain the above copyright notice,     **
 this list of conditions and the following disclaimer.                       **
 *Redistributions in binary form must reproduce the above copyright notice,  **
 this list of conditions and the following disclaimer in the documentation   **
 and/or other materials provided with the distribution.                      **
 *Neither the name of the copyright holders nor the names of its contributors**
 may be used to endorse or promote products derived from this software       ** 
 without specific prior written permission.                                  **
                                                                             **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  **
 POSSIBILITY OF SUCH DAMAGE.                                                 **
                                                                             **
 To improve the quality of the software, users are encouraged to share       **
 modifications, enhancements or bug fixes with Infineon Technologies AG      **
 dave@infineon.com).                                                         **
                                                                             **
*******************************************************************************
**                                                                           **
**                                                                           **
** PLATFORM : Infineon XMC4000/ XMC1000 Series                               **
**                                                                           **
** COMPILER : Compiler Independent                                           **
**                                                                           **
** AUTHOR   : App Developer                                                  **
**                                                                           **
** MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                           **
** MODIFICATION DATE : Mar 26, 2013                                          **
**                                                                           **
******************************************************************************/
 
/******************************************************************************
**                       Author(s) Identity                                  **
*******************************************************************************
**                                                                           **
** Initials    Name                                                          **
** --------------------------------------------------------------------------**
** AEP         DAVE App Developer                                            **
******************************************************************************/

/**
 *
 * @file   SPI001_Conf.c
 *
 * @App Version SPI001 <1.0.18>
 *
 * @brief  Configuration file generated based on UI settings 
 *         of SPI001 App
 *
 */
/*
 * Revision History
 * 01 Jun 2012 v1.0.0   Initial version
 * 26 Jul 2012 v1.0.2   Modified to support Quad mode functionalities
 * 17 Aug 2012 v1.0.4   Macro correction in USIC.h,Fix for OutputEnable for 
 *                      HW controlled pins 
 * 04 Feb 2013 v1.0.12  1. Coding guidelines and MISRA fixes
 *                      2. Typecasting for the handle parameter for MISRA Checks
 *                      3. Generation of macros from numbers and the generation
 *                      of chipselect array modified.
 *                      4. Updated fix for UTP MCSW300000589 - Trigger Limit 
 *                      Receive-Transmit in SPI001 [1.0.4] interchanged.
 *                      5. Updatd for revision history alignments. 
 *                      6. Updated for XMC1000 devices.
 *                      7. Alignment of the revision history  
 * 26 Mar 2013 v1.0.16  1. Updated for alignment in Revision history.
 */

#include <DAVE3.h>


SPI001_ConfigType SPI001_Config0 =
{
 	
    
   .Mode = SPI001_STANDARD_FULLDUPLEX,/* SPI Mode */
   .HBMode = SPI001_MSB, /* Transmit LSB/MSB */
   .ClkPol =  SPI001_CLK_POL1, /* Clock Polarity */
   .ClkPh =  SPI001_CLK_PHASE0, /* Clock Phase */
   .BaudRate = (uint32_t) 10000000,/* Baud Rate */
   .LeadTrailDelay =  SPI001_ONE_SCLK_PERIOD,/* Leading/TrailingDelay */
   .NextFrameDelay = SPI001_ONE_SCLK_PERIOD,/* NextFrameDelay */
   .WordLen = (uint8_t) 8,/* Wordlength */
   .FrameLen = (uint8_t) 8,/* Framelength */   
   .CESelected = (uint8_t) CE_A /* Default Chip Select line selection */
};

SPI001_PinHandleType SPI001_PinHandle0  =
{  
     
   .Port_Num = {(uint8_t) 3, (uint8_t) 2, (uint8_t) 0, (uint8_t) 0},
   .Pin_Num  = {(uint8_t) 13, (uint8_t) 5,(uint8_t) 0, (uint8_t) 0},
    /* Pin Port Base Address */
   .PinPortRegs = {(SPI001_PORTS_TypeDef*)PORT3_BASE, 
                   (SPI001_PORTS_TypeDef*)PORT2_BASE, 
                   (SPI001_PORTS_TypeDef*)PORT0_BASE, 
                   (SPI001_PORTS_TypeDef*)PORT0_BASE
                  },
   .MRST_DSEL  = (uint8_t) 1, /* DSEL Value */
   .MTSR_IOCR  = (uint8_t) 2  /* IOCR_PCR value */   
};


const SPI001_HandleType SPI001_Handle0  = 
{
   .USICRegs = USIC0_CH1, /* Usic Channel offset value */ 
   .FrmEndMode = SPI001_DISABLE_FEM,/* Frame End mode Selection*/
   .Config = &SPI001_Config0,
   .NoOfCS = (uint8_t) 1, /* No of ChipSelect line */
   .ChipSelTable = {(uint8_t) 1, (uint8_t) 0, (uint8_t) 0, (uint8_t) 0,
                    (uint8_t) 0, (uint8_t) 0, (uint8_t) 0, (uint8_t) 0
                   },
   .TxLimit = (uint8_t) 1,/* FIFO Tigger Level */
   .RxLimit = (uint8_t) 1,/* FIFO Tigger Level */
   .TxFifoSize = (uint8_t) 1,/* Tx FIFO Size */
   .RxFifoSize = (uint8_t) 1,/* Rx FIFO Size */
   .MSLSIntrEn = (bool) 0,/* MSLS Event enable */
   .PinHandle = &SPI001_PinHandle0
};

/*CODE_BLOCK_END*/

