
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
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                            **
** MODIFICATION DATE : July 31, 2012                                         **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials           Name                                                    **
** ---------------------------------------------------------------------------**
** PrashanA           App Developer                                           **
*******************************************************************************/

/**
 * @file ADCGLOB001.c
 *
 * @brief
 * This is global ADC App which allows the sharing of global ADC resources.
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/

#include <DAVE3.h>


/**
 * @cond INTERNAL_DOCS
 */
/*******************************************************************************
**                              API DEFINITION
*******************************************************************************/

/**
 *This function initialize all VADC Global registers based on GUI configuration.
 */
void ADCGLOB001_Init(void)
{
  FUNCTION_ENTRY(GID_ADCGLOB001,(uint32_t)ADCGLOB001_FUNCTION_ENTRY);
  
  if(ADCGLOB001_Handle0.kDynamicDataPtr->StateType == ADCGLOB001_UNINITIALIZED )
  {
      
    /* Initialise clock init.*/
    CLK001_Init();  
        
    /* Bring ADC Module Out of Reset */
    RESET001_DeassertReset(PER0_VADC);
      
    /* Bring the module out of disabled state.*/
    CLR_BIT( ADCGLOB001_Handle0.kGlobalPtr->CLC, VADC_CLC_DISR_Pos);
    /** 
     * Make divider bit fields writable.
     * Configure Divider Factor for the Analog Internal Clock.
     * Configure Divider Factor for the Arbiter Clock.
     * Configure Double Clock for the MSB Conversion.
     */
    ADCGLOB001_Handle0.kGlobalPtr->GLOBCFG = \
                (uint32_t)(((uint32_t)1<<VADC_GLOBCFG_DIVWC_Pos)| \
                (((uint32_t)ADCGLOB001_Handle0.kArbiterClkDivider <<VADC_GLOBCFG_DIVD_Pos) & VADC_GLOBCFG_DIVD_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.keDoubleClkMSBConver <<VADC_GLOBCFG_DCMSB_Pos)&VADC_GLOBCFG_DCMSB_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.kAnalogClkDivider <<VADC_GLOBCFG_DIVA_Pos)&VADC_GLOBCFG_DIVA_Msk));
    /* Make the divider bit fields write protected */
    CLR_BIT( ADCGLOB001_Handle0.kGlobalPtr->GLOBCFG, VADC_GLOBCFG_DIVWC_Pos);
                    
    /** 
     * Configure Class0 Sample Time Control for Standard Conversion.
     * Configure Class0 Sample Time Control for EMUX Conversion.
     * Configure Class0 Conversion Mode for Standard Conversion.
     * Configure Class0 Conversion Mode for EMUX Conversion.
     */
    ADCGLOB001_Handle0.kGlobalPtr->GLOBICLASS[0] = \
                (uint32_t)((((uint32_t)ADCGLOB001_Handle0.kEMUXConversionModeClass0 << VADC_GLOBICLASS_CME_Pos)&VADC_GLOBICLASS_CME_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.kEMUXSampleTimeControlClass0 <<VADC_GLOBICLASS_STCE_Pos)&VADC_GLOBICLASS_STCE_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.kConversionModeClass0 <<VADC_GLOBICLASS_CMS_Pos)&VADC_GLOBICLASS_CMS_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.kSampleTimeControlClass0 <<VADC_GLOBICLASS_STCS_Pos)&VADC_GLOBICLASS_STCS_Msk));
    /** 
     * Configure Class1 Sample Time Control for Standard Conversion.
     * Configure Class1 Sample Time Control for EMUX Conversion.
     * Configure Class1 Conversion Mode for Standard Conversion.
     * Configure Class1 Conversion Mode for EMUX Conversion.
     */    
    ADCGLOB001_Handle0.kGlobalPtr->GLOBICLASS[1] = \
                (uint32_t)((((uint32_t)ADCGLOB001_Handle0.kEMUXConversionModeClass1 << VADC_GLOBICLASS_CME_Pos)&VADC_GLOBICLASS_CME_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.kEMUXSampleTimeControlClass1 <<VADC_GLOBICLASS_STCE_Pos)&VADC_GLOBICLASS_STCE_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.kConversionModeClass1 <<VADC_GLOBICLASS_CMS_Pos)&VADC_GLOBICLASS_CMS_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.kSampleTimeControlClass1<<VADC_GLOBICLASS_STCS_Pos)&VADC_GLOBICLASS_STCS_Msk));
          
    /* Configure the lower and upper boundary based on the GUI configuration.*/
    ADCGLOB001_Handle0.kGlobalPtr->GLOBBOUND = \
                (uint32_t)((((uint32_t)ADCGLOB001_Handle0.KGlobBoundary1 <<VADC_GLOBBOUND_BOUNDARY1_Pos)&VADC_GLOBBOUND_BOUNDARY1_Msk)| \
                (((uint32_t)ADCGLOB001_Handle0.KGlobBoundary0 <<VADC_GLOBBOUND_BOUNDARY0_Pos)&VADC_GLOBBOUND_BOUNDARY0_Msk));
             
    ADCGLOB001_Handle0.kDynamicDataPtr->StateType = ADCGLOB001_INITIALIZED;
  } else {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
}

/**
 * This function will de-initialize VADC Global registers.
 */
status_t ADCGLOB001_DeInit(const ADCGLOB001_HandleType * HandlePtr)
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;
  
  FUNCTION_ENTRY(GID_ADCGLOB001,(uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if(HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED )
  {
    /* Bring the module out of disabled state */
    CLR_BIT( HandlePtr->kGlobalPtr->CLC, VADC_CLC_DISR_Pos);
        
    /* Make divider bit fields writable and deconfigure Analog Internal Clock, 
     Arbiter Clock & MSB Conversion bits.*/
    HandlePtr->kGlobalPtr->GLOBCFG = \
                    (((uint32_t)1<<VADC_GLOBCFG_DIVWC_Pos)|((~(VADC_GLOBCFG_DIVD_Msk))& \
                    (~(VADC_GLOBCFG_DCMSB_Msk)) & (~(VADC_GLOBCFG_DIVA_Msk))));
        
    /* Again make the divider bit fields write protected */
    CLR_BIT( HandlePtr->kGlobalPtr->GLOBCFG, VADC_GLOBCFG_DIVWC_Pos);  
        
    /* 
     * Configure Class0 Sample Time Control for Standard Conversion into default
     *  mode.
     * Configure Class0 Conversion Mode for Standard Conversion into default mode.
     * Configure Class0 Sample Time Control for EMUX Conversion into default mode.
     * Configure Class0  Conversion Mode for EMUX Conversion into default mode.
     */
    HandlePtr->kGlobalPtr->GLOBICLASS[0] = \
                ((~(VADC_GLOBICLASS_CME_Msk))&(~(VADC_GLOBICLASS_STCE_Msk))& \
                (~(VADC_GLOBICLASS_CMS_Msk))&(~(VADC_GLOBICLASS_STCS_Msk)));  
    /* 
     * Configure Class1 Sample Time Control for Standard Conversion into default
     *  mode.
     * Configure Class1 Conversion Mode for Standard Conversion into default mode.
     * Configure Class1 Sample Time Control for EMUX Conversion into default mode.
     * Configure Class1  Conversion Mode for EMUX Conversion into default mode.
     */
    HandlePtr->kGlobalPtr->GLOBICLASS[1] = \
                    ((~(VADC_GLOBICLASS_CME_Msk))&(~(VADC_GLOBICLASS_STCE_Msk))& \
                    (~(VADC_GLOBICLASS_CMS_Msk))&(~(VADC_GLOBICLASS_STCS_Msk)));
        
    /* Configure global lower and upper boundary value into default value.*/
    HandlePtr->kGlobalPtr->GLOBBOUND = \
                    ((~(VADC_GLOBBOUND_BOUNDARY1_Msk))&(~(VADC_GLOBBOUND_BOUNDARY0_Msk)));
         
    HandlePtr->kDynamicDataPtr->StateType = ADCGLOB001_UNINITIALIZED;
    Status = (uint32_t)DAVEApp_SUCCESS;
  } else {
      ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  
  return Status;
}

/**
 * This function disable the control of the module.
 */
status_t ADCGLOB001_CLKRequestDisable(const ADCGLOB001_HandleType * HandlePtr)
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    
    /* Bring the module in disabled state
    * Module Disable Request Bit
    * 0 : enable the module clock  
    * 1 : stop the module clock */
      
    SET_BIT( HandlePtr->kGlobalPtr->CLC, VADC_CLC_DISR_Pos);

    Status = (uint32_t)DAVEApp_SUCCESS;

  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function enable the control of the module.
 */
status_t ADCGLOB001_CLKRequestEnable(const ADCGLOB001_HandleType * HandlePtr)
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    /* Bring the module out of disabled state */
      
    CLR_BIT( HandlePtr->kGlobalPtr->CLC, VADC_CLC_DISR_Pos);

    Status = (uint32_t)DAVEApp_SUCCESS;
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function Initiate the start-up calibration phase.
 */

status_t ADCGLOB001_SetStartUpCalibration(
    const ADCGLOB001_HandleType *HandlePtr
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;
  uint32_t  CalibrationStatus;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    /* Initiate Start-Up Calibration */
      
    SET_BIT( HandlePtr->kGlobalPtr->GLOBCFG, VADC_GLOBCFG_SUCAL_Pos);
    
    /*Wait for calibration to be finished*/
    
    do{
        CalibrationStatus= (HandlePtr->kGlobalPtr->GLOBCFG & 0x80000000);
    }while (CalibrationStatus!=(uint32_t)0);
    Status = (uint32_t)DAVEApp_SUCCESS;
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function Initialise the calibration based based on GUI configuration.
 */
status_t ADCGLOB001_StartUpCalibrationInit(void)
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;
  uint32_t  CalibrationStatus;
    
  FUNCTION_ENTRY(GID_ADCGLOB001,(uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if(ADCGLOB001_Handle0.kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED )
  {
    /* Initialise Calibration */
        
      if(ADCGLOB001_Handle0.keStartCalib == (uint8_t)1)
      {
          /* Initiate Start-Up Calibration */
          SET_BIT( 
              ADCGLOB001_Handle0.kGlobalPtr->GLOBCFG,
              VADC_GLOBCFG_SUCAL_Pos
              ); 
          /*Wait for calibration to be finished*/ 
          do{
              CalibrationStatus= \
                  (ADCGLOB001_Handle0.kGlobalPtr->GLOBCFG & 0x80000000);
          }while (CalibrationStatus!=(uint32_t)0);
      } 
      
    Status = (uint32_t)DAVEApp_SUCCESS; 
  }
    
  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  
  return Status;
}

/**
 * This function Enables Sleep Mode Control.Which is used to control module?s 
 * reaction to sleep mode.
 */
status_t ADCGLOB001_EnableSleepModeControl(
    const ADCGLOB001_HandleType * HandlePtr
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
      /* Reset  Sleep Mode Enable Control bit*/
      CLR_BIT( HandlePtr->kGlobalPtr->CLC, VADC_CLC_EDIS_Pos);

    Status = (uint32_t)DAVEApp_SUCCESS;
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function disregards Sleep Mode Control.
 */
status_t ADCGLOB001_DisregardSleepModeControl(
    const ADCGLOB001_HandleType * HandlePtr
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    /* set  Sleep Mode Enable Control bit*/
    SET_BIT( HandlePtr->kGlobalPtr->CLC, VADC_CLC_EDIS_Pos);

    Status = (uint32_t)DAVEApp_SUCCESS;
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}

/**
 * This function configure the class 0 conversion mode for standard conversions.
 */
status_t ADCGLOB001_SetGlobClass0ConvMode(
    const ADCGLOB001_HandleType * HandlePtr,
    ADCGLOB001_ConversionMode ConversionModeVal
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
      if((ConversionModeVal < (ADCGLOB001_ConversionMode)3) || 
          (ConversionModeVal ==(ADCGLOB001_ConversionMode)5)) { 
        /* Set the global class0 conversion mode */
        WR_REG( HandlePtr->kGlobalPtr->GLOBICLASS[0],
                VADC_GLOBICLASS_CMS_Msk,
                VADC_GLOBICLASS_CMS_Pos,
                (uint32_t)ConversionModeVal
              );

        Status = (uint32_t)DAVEApp_SUCCESS;
      } else {
        Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
      }       
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function configure the class 0 Sample Time Control for Standard 
 * Conversions.
 */

status_t ADCGLOB001_SetGlobClass0SampleTime(
    const ADCGLOB001_HandleType * HandlePtr,
    uint8_t SampleTime
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    if(SampleTime < (uint8_t)32){ 
      /* Set the global class0 Sample Time */
      WR_REG( HandlePtr->kGlobalPtr->GLOBICLASS[0],
              VADC_GLOBICLASS_STCS_Msk,
              VADC_GLOBICLASS_STCS_Pos,
              (uint32_t)SampleTime
            );

      Status = (uint32_t)DAVEApp_SUCCESS;
    } else {
      Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
    } 
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;

}
/**
 * This function configure the class 0 Conversion Mode for EMUX Conversions.
 */
status_t ADCGLOB001_SetGlobClass0EmuxConvMode(
    const ADCGLOB001_HandleType * HandlePtr,
    ADCGLOB001_ConversionMode ConversionModeVal
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {  
    if((ConversionModeVal < (ADCGLOB001_ConversionMode)3) || 
        (ConversionModeVal ==(ADCGLOB001_ConversionMode)5)) { 
      /* Set the global class0 External Multiplexer conversion mode*/
      WR_REG( HandlePtr->kGlobalPtr->GLOBICLASS[0],
              VADC_GLOBICLASS_CME_Msk,
              VADC_GLOBICLASS_CME_Pos,
              (uint32_t)ConversionModeVal
            );
      Status = (uint32_t)DAVEApp_SUCCESS;
              
    } else {
      Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
    }           
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;

}

/**
 * This function configure the class 0 Sample Time Control for EMUX Conversions.
 */
status_t ADCGLOB001_SetGlobClass0EmuxSampleTime(
    const ADCGLOB001_HandleType * HandlePtr,
    uint8_t SampleTime
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    if(SampleTime < (uint8_t)32){
         
      /* Set the global class0 External Multiplexer Sample Time */
      WR_REG( HandlePtr->kGlobalPtr->GLOBICLASS[0],
              VADC_GLOBICLASS_STCE_Msk,
              VADC_GLOBICLASS_STCE_Pos,
              (uint32_t)SampleTime
             );

      Status = (uint32_t)DAVEApp_SUCCESS;
         
     } else {
         
       Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
     }    
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}

/**
 * This function configure the class 1 conversion mode for standard conversions.
 */
status_t ADCGLOB001_SetGlobClass1ConvMode(
    const ADCGLOB001_HandleType * HandlePtr,
    ADCGLOB001_ConversionMode ConversionModeVal
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
      if((ConversionModeVal < (ADCGLOB001_ConversionMode)3) ||
          (ConversionModeVal ==(ADCGLOB001_ConversionMode)5)) { 
      /* Set the global class 1 conversion mode */
       WR_REG( HandlePtr->kGlobalPtr->GLOBICLASS[1],
               VADC_GLOBICLASS_CMS_Msk,
               VADC_GLOBICLASS_CMS_Pos,
               (uint32_t)ConversionModeVal
             );

       Status = (uint32_t)DAVEApp_SUCCESS;
              
          } else {
                   Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
          }      
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function configure the class 1 Sample Time Control for Standard
 * Conversions.
 */
status_t ADCGLOB001_SetGlobClass1SampleTime(
    const ADCGLOB001_HandleType * HandlePtr,
    uint8_t SampleTime
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
      
      if(SampleTime < (uint8_t)32){
        /* Write the global class 1 Sample Time */        
        WR_REG( HandlePtr->kGlobalPtr->GLOBICLASS[1],
                VADC_GLOBICLASS_STCS_Msk,
                VADC_GLOBICLASS_STCS_Pos,
                (uint32_t)SampleTime
              );
        
        Status = (uint32_t)DAVEApp_SUCCESS;      
        
      } else {
          
        Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
      }      
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}

/**
 * This function configure the class 1 Conversion Mode for EMUX Conversions.
 */
status_t ADCGLOB001_SetGlobClass1EmuxConvMode(
    const ADCGLOB001_HandleType * HandlePtr,
    ADCGLOB001_ConversionMode ConversionModeVal
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    if((ConversionModeVal < (ADCGLOB001_ConversionMode)3) ||
        (ConversionModeVal ==(ADCGLOB001_ConversionMode)5)) { 
        /* Write the global class1 External Multiplexer conversion mode */
              
            WR_REG( HandlePtr->kGlobalPtr->GLOBICLASS[1],
                    VADC_GLOBICLASS_CME_Msk,
                    VADC_GLOBICLASS_CME_Pos,
                    (uint32_t)ConversionModeVal
                  );
            Status = (uint32_t)DAVEApp_SUCCESS;
     } else {
                Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
     }     
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}

/**
 * This function configure the class 1 Sample Time Control for EMUX Conversions.
 */
status_t ADCGLOB001_SetGlobClass1EmuxSampleTime(
    const ADCGLOB001_HandleType * HandlePtr,
    uint8_t SampleTime
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {      
      if(SampleTime < (uint8_t)32){
        /* Write the global class1 External Multiplexer Sample Time */
        WR_REG( HandlePtr->kGlobalPtr->GLOBICLASS[1],
                VADC_GLOBICLASS_STCE_Msk,
                VADC_GLOBICLASS_STCE_Pos,
                (uint32_t)SampleTime
              );
        Status = (uint32_t)DAVEApp_SUCCESS;
         
      } else {
        
        Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
      }  
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function gives the status of Module Disable bit.
 */
status_t ADCGLOB001_GetDisableBitStatus(
    const ADCGLOB001_HandleType * HandlePtr,
    uint8_t *StatusValue
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
      /*Read the status value */
      
      *StatusValue = (uint8_t) RD_REG( HandlePtr->kGlobalPtr->CLC,
                                       VADC_CLC_DISS_Msk,
                                       VADC_CLC_DISS_Pos
                                     );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function gives the Id Value.
 */

status_t ADCGLOB001_GetIdValue(
    const ADCGLOB001_HandleType * HandlePtr,
    uint32_t *IDValue
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    /*Read the ID value */
    *IDValue =(uint32_t)HandlePtr->kGlobalPtr->ID;     
    
    Status = (uint32_t)DAVEApp_SUCCESS;
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}

/**
 * This function configure the group number to be used for converter diagnostics
 * conversions.
 */

status_t ADCGLOB001_GTFRConvtrDiagnoGrp(const ADCGLOB001_HandleType * HandlePtr,
    uint8_t GroupValue
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {      
    if(GroupValue < (uint8_t)16){
      /*clear the group number.*/  
      HandlePtr->kGlobalPtr->GLOBTF = (VADC_GLOBTF_CDWC_Msk|
              ((HandlePtr->kGlobalPtr->GLOBTF)& (~(VADC_GLOBTF_CDGR_Msk))));
      /*Write the group number to be used for converter diagnostics conversions.*/ 
      HandlePtr->kGlobalPtr->GLOBTF |= (VADC_GLOBTF_CDWC_Msk |
              (((uint32_t)GroupValue << VADC_GLOBTF_CDGR_Pos) & VADC_GLOBTF_CDGR_Msk));
            
      /*Clear the Write Control for Conversion Diagnostics*/   
      CLR_BIT(HandlePtr->kGlobalPtr->GLOBTF, VADC_GLOBTF_CDWC_Pos);        
      Status = (uint32_t)DAVEApp_SUCCESS;             
    } else {      
      Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
    }             
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function configure the Converter Diagnostics pull devices connected as 
 * selected by bitfield CDSEL.
 */
status_t ADCGLOB001_GTFRConvtrDiagnoEnable(
    const ADCGLOB001_HandleType * HandlePtr
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    /*Enable the Converter Diagnostics*/
    HandlePtr->kGlobalPtr->GLOBTF |= 
        (VADC_GLOBTF_CDWC_Msk | VADC_GLOBTF_CDEN_Msk);
    /*Clear the Write Control for Conversion Diagnostics*/   
    CLR_BIT(HandlePtr->kGlobalPtr->GLOBTF, VADC_GLOBTF_CDWC_Pos);      
    Status = (uint32_t)DAVEApp_SUCCESS;
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * This function configure the Converter Diagnostics Pull-Devices Select value.
 */
status_t ADCGLOB001_GTFRConvtrDiagnoPullDevicesSelect(
    const ADCGLOB001_HandleType * HandlePtr,
    uint8_t SelectValue
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  {
    if(SelectValue < (uint8_t)4){
      /*Clear Converter Diagnostics Pull-Devices Select value  */  
       HandlePtr->kGlobalPtr->GLOBTF = (VADC_GLOBTF_CDWC_Msk|
               ((HandlePtr->kGlobalPtr->GLOBTF)& (~(VADC_GLOBTF_CDSEL_Msk))));
              
      /* Write the Converter Diagnostics Pull-Devices Select value */
       HandlePtr->kGlobalPtr->GLOBTF |= (VADC_GLOBTF_CDWC_Msk |
               (((uint32_t)SelectValue << VADC_GLOBTF_CDSEL_Pos) & VADC_GLOBTF_CDSEL_Msk));
      /*Clear the Write Control for Conversion Diagnostics*/    
       
       CLR_BIT(HandlePtr->kGlobalPtr->GLOBTF, VADC_GLOBTF_CDWC_Pos);    
       Status = (uint32_t)DAVEApp_SUCCESS;    
     } else {          
        Status = (uint32_t)ADCGLOB001_INVALID_PARAM_ERROR;
     }     
  }
  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}

/**
 * This function configure the Pull-Down Diagnostics Enable register.
 */
status_t ADCGLOB001_GTFRPullDwnDiagnoEnable(
    const ADCGLOB001_HandleType * HandlePtr
    )
{
  status_t Status = (uint32_t)ADCGLOB001_OPER_NOT_ALLOWED;

  FUNCTION_ENTRY(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_ENTRY);

  if (HandlePtr->kDynamicDataPtr->StateType == ADCGLOB001_INITIALIZED)
  { 
   /*Enable the Pull-Down Diagnostics */  
    HandlePtr->kGlobalPtr->GLOBTF |=
        (VADC_GLOBTF_MDWC_Msk | VADC_GLOBTF_PDD_Msk);
    /*Clear the Write Control for Multiplexer Diagnostics*/  
    CLR_BIT(HandlePtr->kGlobalPtr->GLOBTF, VADC_GLOBTF_MDWC_Pos);    
    
    Status = (uint32_t)DAVEApp_SUCCESS;
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
    ERROR(GID_ADCGLOB001, (uint8_t)Status, 0, NULL);
  }
  FUNCTION_EXIT(GID_ADCGLOB001, (uint32_t)ADCGLOB001_FUNCTION_EXIT);
  return Status;
}
/**
 * @endcond
 */

