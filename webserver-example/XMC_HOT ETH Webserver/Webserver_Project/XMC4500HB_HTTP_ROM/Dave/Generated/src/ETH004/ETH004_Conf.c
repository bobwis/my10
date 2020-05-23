
/*CODE_BLOCK_BEGIN[ETH004_Conf.c]*/

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
 ******************************************************************************
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
** MODIFICATION DATE : Oct 06, 2012                                           **
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
 * @file   ETH004_Conf.c
 *
 * @App Version ETH004 <1.0.12>
 *
 * @brief  Configuration file generated based on UI settings 
 *         of ETH004 App
 *
 */ 
 #ifndef ETH004_C_
 #define ETH004_C_ 
 #include <DAVE3.h>      
 /** For setting IP manually */   
  uint16_t IPpos1 = 192;
  uint16_t IPpos2 = 168;
  uint16_t IPpos3 = 0;
  uint16_t IPpos4 = 10;
    
  uint16_t Netpos1 = 255;
  uint16_t Netpos2 = 255;
  uint16_t Netpos3 = 255;
  uint16_t Netpos4 = 0;

  uint16_t GWpos1 = 192;
  uint16_t GWpos2 = 168;
  uint16_t GWpos3 = 0;
  uint16_t GWpos4 = 10;  	
 
 #endif /* ETH004_C_ */  
/*CODE_BLOCK_END*/


