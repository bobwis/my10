
/*CODE_BLOCK_BEGIN[ADCGLOB001_Conf.c]*/
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
** MODIFICATION DATE :  13 july 2012                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** prashana           DAVE App Developer                                      **
*******************************************************************************/

/**
 * @file ADCGLOBAL001_Conf.c
 *
 * @brief This file contains the configuration parameters for all instances of the
 * ADC GLOBAL App
 */

#include <DAVE3.h>




ADCGLOB001_DynamicDataType ADCGLOB001_DynamicData0 =
{
  .StateType = ADCGLOB001_UNINITIALIZED
};    
    
        
const ADCGLOB001_HandleType ADCGLOB001_Handle0 = 
{
  .kGlobalPtr          = (VADC_GLOBAL_TypeDef*)(void*)VADC,
        
  .kDynamicDataPtr      = &ADCGLOB001_DynamicData0,
      
  .KGlobBoundary0        = (uint16_t) 0,
      
  .KGlobBoundary1        = (uint16_t) 0,
      
  .kAnalogClkDivider      = (uint8_t) 3,
          
  .kArbiterClkDivider     = (uint8_t) 0,
      
  .kSampleTimeControlClass0  = (uint8_t) 0,
            
  .kSampleTimeControlClass1   = (uint8_t) 0,
          
  .kEMUXSampleTimeControlClass0= (uint8_t) 0,
                
  .kEMUXSampleTimeControlClass1= (uint8_t) 0,
           
  .kConversionModeClass0    = (uint8_t) ADCGLOB001_12BIT,
             
  .kConversionModeClass1     = (uint8_t) ADCGLOB001_12BIT,
        
  .kEMUXConversionModeClass0   = (uint8_t) ADCGLOB001_12BIT,
          
  .kEMUXConversionModeClass1   = (uint8_t) ADCGLOB001_12BIT,
          
  .keStartCalib           = (uint8_t) 1,
          
  .keDoubleClkMSBConver     = (uint8_t) 0
 
};
  




