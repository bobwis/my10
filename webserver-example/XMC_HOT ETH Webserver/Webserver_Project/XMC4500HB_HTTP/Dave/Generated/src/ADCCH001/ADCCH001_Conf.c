
/*CODE_BLOCK_BEGIN[ADCCH001_Conf.c]*/
/*******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4500 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : DAVE App Developer                                              **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE :  31 July 2012                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PM           DAVE App Developer                                            **
*******************************************************************************/

/**
 * @file ADCCH001_Conf.c
 *
 * @brief This file contains the configuration parameters for all instances of the
 * ADCCH001 App
 */

#include <DAVE3.h>


      



ADCCH001_DynamicHandleType ADCCH001_DynamicHandle0 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle0 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G0,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle0 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE,
  .kRefInput = (uint8_t) 0 ,
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x0 ,
  .kWaitForRead= (uint8_t)0,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)15,
  .kEndResultRegNo = (uint8_t)15,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)0,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};






