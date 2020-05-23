/**************************************************************************//**
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
** MODIFICATION DATE :  30 July 2012                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PA           DAVE App Developer                                      **
*******************************************************************************/

/**
 * @file ADCGlob001.h
 * @brief  This file contains interfaces for the global ADC App.
 */

#ifndef ADCGLOB001_H_
#define ADCGLOB001_H_

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/

#include <DAVE3.h>


/**
  * @ingroup ADCGLOB001_publicparam
  * @{
  */
/*******************************************************************************
 *                                ENUMERATIONS                                **
 ******************************************************************************/
/**
 * This enumerates the error codes of the ADC Global App
 */
typedef enum ADCGlob001_ErrorType
{
  /**
   * The operation is not allowed.
   */
  ADCGLOB001_OPER_NOT_ALLOWED = 1,
  /**
   * This error code means that the parameters passed to an API are invalid
   */

  ADCGLOB001_INVALID_PARAM_ERROR,

  /**
   * Debug log code for function entry
   */
  ADCGLOB001_FUNCTION_ENTRY,

  /**
   * Debug log code for function exit
   */
  ADCGLOB001_FUNCTION_EXIT,
  
}ADCGlob001_ErrorType;

/**
 *This enumerates the app state.
 */
typedef enum ADCGLOB001_StateType{
  /**
   * This is the default state after power on reset
   */
  ADCGLOB001_UNINITIALIZED,
  /**
   * This is the INITIALIZED state in which APP is initialized as per selected
   * parameters.
  */
  ADCGLOB001_INITIALIZED,

} ADCGLOB001_StateType;

/**
 * This enumerates the conversion mode
 */
typedef enum ADCGLOB001_ConversionMode{
    /**
     * 12-bit conversion
     */
  ADCGLOB001_12BIT = 0,
    /**
     * 10-bit conversion
     */
  ADCGLOB001_10BIT=1,
    /**
     * 8-bit conversion
     */
  ADCGLOB001_8BIT=2,
    /**
     * 10-bit fast compare mode
     */    
  ADCGLOB001_10BITFAST = 5
  
}ADCGLOB001_ConversionMode;


/*******************************************************************************
 *                             STRUCTURES                                     **
 ******************************************************************************/
/**
 * This structure holds the VADC Global parameters which change at run
 * time.
 */

typedef struct ADCGLOB001_DynamicDataType{

  /**
   * This parameter tells the state of App.
   */ 
  ADCGLOB001_StateType StateType;

}ADCGLOB001_DynamicDataType;

/**
 * This structure holds the GUI configurable parameters of this app.
 */
typedef struct ADCGLOB001_HandleType{
/**
 * This is the register structure pointer to the VADC kernel.
 */
  VADC_GLOBAL_TypeDef* const kGlobalPtr;
/**
 * This is the pointer to the Dynamic Handle of the App.
 */
  ADCGLOB001_DynamicDataType * const kDynamicDataPtr;
  
/**
 * Boundary Value 0 for Limit Checking.\n
 * Range:12 Bits
 */
  
  const uint16_t KGlobBoundary0;
 /**
  * Boundary Value 1 for Limit Checking.\n
  * Range:12 Bits
  */  
  const uint16_t KGlobBoundary1;
  /**
   * Divider Factor for the Analog Internal Clock\n
   * 0  :fADCI = fADC/2;\n
   * 1  :fADCI = fADC/2;\n
   * 2  :fADCI = fADC/3;\n
   * ...\n
   * 1F :fADCI= fADC/32;
   */    
  const uint8_t kAnalogClkDivider;
  /**
   * Divider Factor for the Arbiter Clock\n
   * 0 :fADCD = fADC;\n
   * 1 :fADCD = fADC/2;\n
   * 2 :fADCD = fADC/3;\n
   * 3 :fADCD = fADC/4;
   */  
  const uint8_t kArbiterClkDivider ;
/**
 * Class 0 Sample Time Control for Standard Conversions\n
 * Range:[4:0] Bits 
 */  
  const uint8_t kSampleTimeControlClass0;
  /**
   * Class 1 Sample Time Control for Standard Conversions\n
   * Range:[4:0] Bits 
   */      
  const uint8_t kSampleTimeControlClass1 ;
  /**
   * Class 0 Sample Time Control for EMUX Conversions\n
   * Range:[4:0] Bits 
   */    
  const uint8_t kEMUXSampleTimeControlClass0;
  /**
   * Class 1 Sample Time Control for EMUX Conversions\n
   * Range:[4:0] Bits 
   */        
  const uint8_t kEMUXSampleTimeControlClass1 ;
  /**
   * Class 0 Conversion Mode for Standard Conversions\n
   * 0 :12-bit conversion\n
   * 1 :10-bit conversion\n
   * 2 :8-bit conversion\n
   * 5 :10-bit fast compare mode\n
   * 3,4,6,7 :Reserved
   */  
  const uint8_t kConversionModeClass0;
    /**
       * Class 1 Conversion Mode for Standard Conversions\n
       * 0 :12-bit conversion\n
       * 1 :10-bit conversion\n
       * 2 :8-bit conversion\n
       * 5 :10-bit fast compare mode\n
       * 3,4,6,7 :Reserved
       */  
    const uint8_t kConversionModeClass1;
  /**
   * Class 0 Conversion Mode for EMUX Conversions\n
   * 0 :12-bit conversion\n
   * 1 :10-bit conversion\n
   * 2 :8-bit conversion\n
   * 5 :10-bit fast compare mode\n
   * 3,4,6,7 :Reserved
   */   
  const uint8_t kEMUXConversionModeClass0;
  /**
   *  Class 1 Conversion Mode for EMUX Conversions\n
   * 0 :12-bit conversion\n
   * 1 :10-bit conversion\n
   * 2 :8-bit conversion\n
   * 5 :10-bit fast compare mode\n
   * 3,4,6,7 :Reserved
   */  
  const uint8_t kEMUXConversionModeClass1;
  /**
   * Variable to configure the Start-Up Calibration\n
   * 0: No action\n
   * 1: Initiate the start-up calibration phase
   */  
  const uint8_t keStartCalib;
  /**
   * Variable to configure the Double Clock for the MSB Conversion\n
   * 0: 1 clock cycles for the MSB (standard)\n
   * 1: 2 clock cycles for the MSB (fADCI > 20 MHz)
   */    
  const uint8_t keDoubleClkMSBConver;
     
}ADCGLOB001_HandleType;

/**
 * @}
 */

/**
 * @ingroup ADCGLOB001_apidoc
 * @{
 */

/*******************************************************************************
 **FUNCTION PROTOTYPES                                                        **
*******************************************************************************/
/**
 * @brief This function will initialize VADC Global registers with user configured values.
 * @param[in] none
 * @return void
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     while(1);
     return 0;
   }
 * @endcode 
 */
void ADCGLOB001_Init(void);
/**
 * @brief This function will de-initialize VADC Global registers.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     //Do something
     ADCGLOB001_Deinit(); //Deinit function call.
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCGLOB001_DeInit(const ADCGLOB001_HandleType * HandlePtr);
/**
 * @brief This function will disable the control of the VADC module.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_CLKRequestDisable(&ADCGLOB001_Handle0); //called to disable the control of the module
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_CLKRequestDisable(const ADCGLOB001_HandleType * HandlePtr);
/**
 * @brief This function will enable the control of the VADC module.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_CLKRequestEnable(&ADCGLOB001_Handle0); //called to enable the control of the module
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_CLKRequestEnable(const ADCGLOB001_HandleType * HandlePtr);

/**
 * @brief This function will initiate the startup calibration phase.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetStartUpCalibration(&ADCGLOB001_Handle0); //Initiate the start-up calibration
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetStartUpCalibration(const ADCGLOB001_HandleType *HandlePtr);

/**
 * @brief This function will enable the sleep mode control.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_EnableSleepModeControl(&ADCGLOB001_Handle0); //Enables Sleep Mode Control
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_EnableSleepModeControl(const ADCGLOB001_HandleType * HandlePtr);
/**
 * @brief This function will disregard the sleep mode control.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
* @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_DisregardSleepModeControl(&ADCGLOB001_Handle0); //called to disregards Sleep Mode Control
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_DisregardSleepModeControl(const ADCGLOB001_HandleType * HandlePtr);
/**
 * @brief This function will configure the class 0 conversion mode for standard conversions.\n
 * ADCGLOB001_12BIT 12-bit conversion\n
 * ADCGLOB001_10BIT 10-bit conversion\n
 * ADCGLOB001_8BIT 8-bit conversion \n
 * ADCGLOB001_10BITFAST 10-bit fast compare mode\n
 * and remaining bits are reserved for future use.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] ConversionModeVal This is the enum type which need to be configured in the GLOBICLASS[0] register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: If ConversionModeVal is not equal ADCGLOB001_12BIT,ADCGLOB001_10BIT,ADCGLOB001_8BIT and ADCGLOB001_10BITFAST
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetGlobClass0ConvMode(&ADCGLOB001_Handle0,ADCGLOB001_12BIT); //configure the class 0 conversion mode value to 10-bit
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetGlobClass0ConvMode(const ADCGLOB001_HandleType * HandlePtr , ADCGLOB001_ConversionMode ConversionModeVal);

/**
 * @brief This function will configure the class 0 Sample Time Control for Standard Conversions.\n
 *  Sample time is the actual register bit field (STCS) value and it's range is from 0 to 31.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] SampleTime SampleTime value which need to be configure in the GLOBICLASS[0] register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: If SampleTime < 0 or SampleTime > 31
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     uint8_t stcsvalue=15;
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetGlobClass0SampleTime(&ADCGLOB001_Handle0,stcsvalue); //configure the class 0 Sample Time Control for Standard Conversions
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetGlobClass0SampleTime(const ADCGLOB001_HandleType * HandlePtr, uint8_t SampleTime);

/**
 * @brief This function will configure the class 0 Sample Time Control for EMUX Conversions.\n
 *  Sample time is the actual register bit field (STCS) value and it's range is from 0 to 31.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] SampleTime SampleTime value which need to be configure in the GLOBICLASS[0] register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: If SampleTime < 0 or SampleTime > 31
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     uint8_t stcevalue=15;
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetGlobClass0EmuxSampleTime(&ADCGLOB001_Handle0,stcevalue); //configure the class 0 Sample Time Control for EMUX Conversions.
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetGlobClass0EmuxSampleTime(const ADCGLOB001_HandleType * HandlePtr,uint8_t SampleTime);

/**
 * @brief This function will configure the class 0 Conversion Mode for EMUX Conversions.\n
 * ADCGLOB001_12BIT 12-bit conversion\n
 * ADCGLOB001_10BIT 10-bit conversion\n
 * ADCGLOB001_8BIT 8-bit conversion \n
 * ADCGLOB001_10BITFAST 10-bit fast compare mode \n
 * and remaining bits are reserved for future use.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] ConversionModeVal This is the enum type which need to be configure in the GLOBICLASS[0] register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: If ConversionModeVal is not equal ADCGLOB001_12BIT,ADCGLOB001_10BIT,ADCGLOB001_8BIT and ADCGLOB001_10BITFAST
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetGlobClass0EmuxConvMode(&ADCGLOB001_Handle0,ADCGLOB001_10BIT); //configure the class 0 Conversion Mode for EMUX Conversions as 10 bits.
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetGlobClass0EmuxConvMode(const ADCGLOB001_HandleType * HandlePtr,ADCGLOB001_ConversionMode ConversionModeVal);

/**
 * @brief This function will configure the class 1 conversion mode for standard conversions.\n
 * ADCGLOB001_12BIT 12-bit conversion\n
 * ADCGLOB001_10BIT 10-bit conversion\n
 * ADCGLOB001_8BIT 8-bit conversion \n
 * ADCGLOB001_10BITFAST 10-bit fast compare mode \n
 * and remaining bits are reserved for future use.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] ConversionModeVal This is the enum type which need to be configure in the GLOBICLASS[1] register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: If ConversionModeVal is not equal ADCGLOB001_12BIT,ADCGLOB001_10BIT,ADCGLOB001_8BIT and ADCGLOB001_10BITFAST
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetGlobClass1ConvMode(&ADCGLOB001_Handle0,ADCGLOB001_8BIT); //configure the class 1 conversion mode value to 10-bit
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetGlobClass1ConvMode(const ADCGLOB001_HandleType * HandlePtr , ADCGLOB001_ConversionMode ConversionModeVal);

/**
 * @brief This function will configure the class 1 Sample Time Control for Standard Conversions.\n
 *  Sample time is the actual register bit field (STCS) value and it's range is from 0 to 31.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] SampleTime SampleTime value which need to be configure in the GLOBICLASS[1] register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: If SampleTime < 0 or SampleTime > 31
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     uint8_t stcsvalue=15;
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetGlobClass1SampleTime(&ADCGLOB001_Handle0,stcsvalue); //configure the class 1 Sample Time Control for Standard Conversions
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetGlobClass1SampleTime(const ADCGLOB001_HandleType * HandlePtr, uint8_t SampleTime);

/**
 * @brief This function will configure the class 1 Sample Time Control for EMUX Conversions.\n
 *  Sample time is the actual register bit field (STCE) value and it's range is from 0 to 31.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] SampleTime SampleTime value which need to be configure in the GLOBICLASS[1] register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: If SampleTime < 0 or SampleTime > 31
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     uint8_t stcevalue=15;
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetGlobClass1EmuxSampleTime(&ADCGLOB001_Handle0,stcevalue); //configure the class 1 Sample Time Control for EMUX Conversions.
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetGlobClass1EmuxSampleTime(const ADCGLOB001_HandleType * HandlePtr,uint8_t SampleTime);

/**
 * @brief This function vconfigure the class 1 Conversion Mode for EMUX Conversions.\n
 * ADCGLOB001_12BIT 12-bit conversion\n
 * ADCGLOB001_10BIT 10-bit conversion\n
 * ADCGLOB001_8BIT 8-bit conversion \n
 * ADCGLOB001_10BITFAST 10-bit fast compare mode \n
 * and remaining bits are reserved for future use.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] ConversionModeVal This is the enum type which need to be configure in the GLOBICLASS[1] register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: If ConversionModeVal is not equal ADCGLOB001_12BIT,ADCGLOB001_10BIT,ADCGLOB001_8BIT and ADCGLOB001_10BITFAST
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_SetGlobClass1EmuxConvMode(&ADCGLOB001_Handle0,ADCGLOB001_10BITFAST); //configure the class 1 Conversion Mode for EMUX Conversions as 10 bits.
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_SetGlobClass1EmuxConvMode(const ADCGLOB001_HandleType * HandlePtr,ADCGLOB001_ConversionMode ConversionModeVal);

/**
 * @brief This function will give the status of Module Disable bit.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[out] StatusValue Its pointer to uint8_t which return the status value.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     uint8_t variable=0;
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_GetDisableBitStatus(&ADCGLOB001_Handle0,&variable); //variable holds the status of Module Disable bit..
     while(1);
     return 0;
   }
 * @endcode
 */

status_t ADCGLOB001_GetDisableBitStatus(const ADCGLOB001_HandleType * HandlePtr, uint8_t *StatusValue);

/**
 * @brief This function will give the VADC module Id Value.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[out] IDValue Its pointer to uint8_t which return the Id value.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
  * @code
   #include <DAVE3.h>
   int main (void)
   {
     uint32_t IdValue=0;
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_GetIdValue(&ADCGLOB001_Handle0,&IdValue); //IdValue holds the ID Value.
     while(1);
     return 0;
   }
 * @endcode
 */

status_t ADCGLOB001_GetIdValue(const ADCGLOB001_HandleType * HandlePtr, uint32_t *IDValue);

/**
 * @brief This function will configure the group number to be used for converter diagnostics conversions.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] GroupValue Value which need to be configure in the GLOBTF register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: if GroupValue > 15
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     uint8_t cdgrvalue=5;
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_GTFRConvtrDiagnoGrp(&ADCGLOB001_Handle0,cdgrvalue); //configure the group number to be used for converter diagnostics conversions.
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_GTFRConvtrDiagnoGrp(const ADCGLOB001_HandleType * HandlePtr, uint8_t GroupValue);

/**
 * @brief This function will configure the Converter Diagnostics pull devices connected as selected
 * by bitfield CDSEL.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>        
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_GTFRConvtrDiagnoEnable(&ADCGLOB001_Handle0); //configure the Converter Diagnostics pull devices enable bit.
     while(1);
     return 0;
   }
 * @endcode
 */

status_t ADCGLOB001_GTFRConvtrDiagnoEnable(const ADCGLOB001_HandleType * HandlePtr);
/**
 * @brief This function will configure the Converter Diagnostics Pull-Devices Select value.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @param[in] SelectValue Value which need to be configure in the GLOBTF register.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCGLOB001_INVALID_PARAM_ERROR: if SelectValue > 3
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     uint8_t cdselvalue=1;
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_GTFRConvtrDiagnoPullDevicesSelect(&ADCGLOB001_Handle0,cdselvalue); //Connected to VAGND
     while(1);
     return 0;
   }
 * @endcode
 */

status_t ADCGLOB001_GTFRConvtrDiagnoPullDevicesSelect(const ADCGLOB001_HandleType * HandlePtr, uint8_t SelectValue);
/**
 * @brief This function will configure the Pull-Down Diagnostics Enable register.
 * @param[in] HandlePtr Handle of the ADCGLOB001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_GTFRPullDwnDiagnoEnable(&ADCGLOB001_Handle0); //Enable the Pull-Down Diagnostics Enable register.
     while(1);
     return 0;
   }
 * @endcode
 */

status_t ADCGLOB001_GTFRPullDwnDiagnoEnable(const ADCGLOB001_HandleType * HandlePtr);

/**
 * @brief This function will initiate the startup calibration phase based on the GUI configurations.
 * It is called after ADCGROUP001 App Init function.
 * @param[in] none
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCGLOB001_OPER_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 * <BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCGLOB001_Init is called within DAVE_Init()
     
     ADCGLOB001_StartUpCalibrationInit(); //Initiate the start-up calibration based on GUI configuration.
     while(1);
     return 0;
   }
 * @endcode
 */
status_t ADCGLOB001_StartUpCalibrationInit(void);
/**
 * @}
 */

#include "ADCGlob001_Conf.h"

#endif /* ADCGLOB_H_ */
