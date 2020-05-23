

/*CODE_BLOCK_BEGIN[ADC002_Conf.c]*/

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
** MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                            **
** MODIFICATION DATE : July 25, 2012                                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** KM           DAVE App Developer                                            **
*******************************************************************************/
/**
 * @file  ADC002_Conf.c
 * @App Version ADC002 <1.0.4>
 * @brief This file contains App parameter data as per GUI configurations
 */
 
#include <DAVE3.h>



ADC002_QueueEntryHandleType ADC002_QueueEntryHandle0[8] = {

  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)0,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
};


ADC002_DynamicDataType ADC002_DynamicHandle0 =
{
  .State = ADC002_UNINITIALIZED
};


const ADC002_HandleType ADC002_Handle0 =
{
  .kGroupNo = (uint8_t)0,
  .kNChannels = (uint8_t)1,
  .kAsenEnable = (uint8_t)ADC002_ARBITRATION_SLOT_ENABLE,
  .kStart = (uint8_t)ADC002_START_CONV_DISABLE,
  .kPriority = (uint8_t)ADC002_PRIORITY0,
  .kStartmode = (uint8_t)ADC002_WAIT_FOR_START,
  .kTriggerMode = (uint8_t)ADC002_NOTRIGGER,
  .kTriggerEn = (uint8_t)0,
  .kGatingMode = (uint8_t)ADC002_GATING_ENABLED_ALWAYS,     
  .kChannelA = (uint8_t)0,
  .kChAHandlerPtr = &ADCCH001_Handle0,
  .kChannelB = (uint8_t)8,
  .kChBHandlerPtr = NULL,
  .kChannelC = (uint8_t)8,
  .kChCHandlerPtr = NULL,
  .kChannelD = (uint8_t)8,
  .kChDHandlerPtr = NULL,
  .kChannelE = (uint8_t)8,
  .kChEHandlerPtr =  NULL,
  .kChannelF = (uint8_t)8,
  .kChFHandlerPtr = NULL,
  .kChannelG = (uint8_t)8,
  .kChGHandlerPtr = NULL,
  .kChannelH = (uint8_t)8,
  .kChHHandlerPtr = NULL,
  .kSyncChPtr= NULL,
  .kSyncChannelA = (uint8_t)8,
  .kSyncChannelB = (uint8_t)8,
  .kSyncChannelC = (uint8_t)8,
  .kSyncChannelD = (uint8_t)8,
  .kSyncChannelE = (uint8_t)8,
  .kSyncChannelF = (uint8_t)8,
  .kSyncChannelG = (uint8_t)8,
  .kSyncChannelH = (uint8_t)8, 
  .kActiveChannels = {(uint8_t)1, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)0 },
  .kQueueEntryHandlePtr =  &ADC002_QueueEntryHandle0[0],
  .kGroup_HandlePtr = &ADCGROUP001_Handle0,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G0,
  .DynamicHandlePtr= &ADC002_DynamicHandle0
 };






