/*CODE_BLOCK_BEGIN[ETH001_Conf.h]*/
/* =========================================================================== * 
 * Copyright (c) 2011, Infineon Technologies AG                                *
 * All rights reserved.                                                        * 
 *                                                                             *
 * Redistribution and use in source and binary forms, with or without          *
 * modification, are permitted provided that the following conditions are met: *
 * Redistributions of source code must retain the above copyright notice, this *
 * list of conditions and the following disclaimer. Redistributions in binary  *
 * form must reproduce the above copyright notice, this list of conditions and *
 * the following disclaimer in the documentation and/or other materials        *
 * provided with the distribution. Neither the name of the copyright holders   * 
 * nor the names of its contributors may be used to endorse or promote         *
 * products derived from this software without specific prior written          * 
 * permission.                                                                 *
 *                                                                             *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       *
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      *
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR           *
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       *
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         * 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; *
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    *
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     *
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF      *
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                  *
 * To improve the quality of the software, users are encouraged to share       *
 * modifications, enhancements or bug fixes with                               *
 * Infineon Technologies AG (dave@infineon.com).                               *
 *                                                                             *
 * ========================================================================== *
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
** MODIFICATION DATE : Sep 11, 2012                                           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** JRP          DAVE App Developer                                            **
********************************************************************************
 * @file   ETH001_Conf.h
 *
 * @App Version ETH001 <1.0.16>
 *
 * @brief  Configuration file generated based on UI settings 
 *         of ETH001 App
 *
 */
/******************************************************************************/
 #ifndef ETH001_H_
 #define ETH001_H_
 
 #define ENH_DESC_8W
 #define ENH_DESC    
 /** For enabling checksum by hardware  */
 #define CHECKSUM_BY_HARDWARE
 /** Interrupt Priority */
 #define ETH_INTERRUPT_PRIORITY   63
  /** Interrupt Sub-Priority */
 #define ETH_INTERRUPT_SUB_PRIORITY   0     
 /** For selecting Ethernet MAC interface  */  
 #define ETH_MAC_SEL 1
 /** For setting MAC Address manually */
 /** This is the IP's PHY address. This is unique address for every MAC in the universe */   	
 #define DEFAULT_MAC_ADDRESS {0x00, 0x03, 0x19, 0x45, 0x00, 0x00}      
 /** for enabling multicast filter  */
 #define ENABLE_MULTICAST      
 #endif /* ETH001_H_ */
/*CODE_BLOCK_END*/



