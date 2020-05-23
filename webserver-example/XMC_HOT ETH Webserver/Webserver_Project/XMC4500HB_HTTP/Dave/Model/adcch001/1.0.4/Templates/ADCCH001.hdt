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
** PM           DAVE App Developer                                            **
*******************************************************************************/

/**
 * @file ADCCH001.h
 *
 * @brief This file contains the data structures and the function prototypes of the 
 * ADCCH001 App. 
 */

#ifndef ADCCH001_H_
#define ADCCH001_H_

/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include <DAVE3.h>


/**
  * @ingroup ADCCH001_publicparam
  * @{
  */
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*******************************************************************************
 *                                ENUMERATIONS                                **
 ******************************************************************************/
/**
 * This enumerates the the input class selection for the channel
 */
typedef enum ADCCH001_InputClassType
{
  /**
   * Input class is a Group Class 0
   */
  ADCCH001_GROUP0,
  /**
   * Input class is a Group Class 1
   */
  ADCCH001_GROUP1,
  /**
   * Input class is a Global Class 0
   */
  ADCCH001_GLOBAL0,
  /**
   * Input class is a Global Class 1
   */
  ADCCH001_GLOBAL1
}ADCCH001_InputClassType;


/**
 * This enumerates the the input class selection for the channel
 */
typedef enum ADCCH001_BoundaryType
{
  /**
   * Input class is a Group Class 0
   */
  ADCCH001_GROUPBOUNDARY0,
  /**
   * Input class is a Group Class 1
   */
  ADCCH001_GROUPBOUNDARY1,
  /**
   * Input class is a Global Class 0
   */
  ADCCH001_GLOBALBOUNDARY0,
  /**
   * Input class is a Global Class 1
   */
  ADCCH001_GLOBALBOUNDARY1
}ADCCH001_BoundaryType;

/**
 * This enumerates the condition which generates the channel event.
 */
typedef enum ADCCH001_ChanEvtModeType
{
  /**
   * Channel Event is disabled. 
   */
  ADCCH001_DISABLE,
  /**
   * Channel event is generated when result is greater than the lower boundary
   * and less than the upper boundary.
   */
  ADCCH001_INSIDE,
  /**
   * Channel event is generated when result is less than the lower boundary
   * and greater than the upper boundary.
   */
  ADCCH001_OUTSIDE,
  /**
   * Channel event is generated every time channel conversion is completed. 
   * Limit checking is not done.
   */
  ADCCH001_ALWAYS
}ADCCH001_ChanEvtModeType;


typedef enum ADCCH001_BWDType
{
  /**
   * VAGND is the broken wire detection channel
   */
  ADCCH001_VAGND,
  /**
   * VAREF is the broken wire detection channel
   */
  ADCCH001_VAREF
}ADCCH001_BWDType;

/**
 * This enumerates the app state.
 */

typedef enum ADCCH001_StateType
{
  /**
   * This is the default state after power on reset. App goes to UNINITIALIZED state
   * after execution of the Deinit function.
   */
  ADCCH001_UNINITIALIZED,
  /**
   * App is in INITIALIZED state after execution of the Init function
   */
  ADCCH001_INITIALIZED,

}ADCCH001_StateType;


/**
 * This enumerates the error codes of the app which can be occured during run-time. 
 */
typedef enum ADCCH001_ErrorType
 {
  /**
   * This indicates that the function execution is not allowed in the current App State
   */
  /*
  GROUPID  #101
  MODULENAME = ADCCH001
  */
  /*
  ERRCODESTRING = ADCCH001_OPERATION_NOT_ALLOWED
  STRCODESTRING = Function execution is not allowed in the current App State
  */  
  ADCCH001_OPERATION_NOT_ALLOWED = 1,
  /**
   * This indicates that input parameter is out of range. 
   */
  /*
  ERRCODESTRING = ADCCH001_INVALID_PARAM
  STRCODESTRING = Input parameter is not valid
  */
  ADCCH001_INVALID_PARAM,
  /**
   * This indicates that the result is invalid or old. 
   */
  /*
  ERRCODESTRING = ADCCH001_INVALID_RESULT
  STRCODESTRING = Conversion result is invalid
  */  
  ADCCH001_INVALID_RESULT,
   /**
    * Function Entry
    */
   /*
   ERRCODESTRING = ADCCH001_FUN_ENTRY
   STRCODESTRING = Entered function %s
   */
   ADCCH001_FUN_ENTRY,
   /**
    *  Function Exit
    */
   /*
   ERRCODESTRING = ADCCH001_FUN_EXIT
   STRCODESTRING = Exited function %s
   */
   ADCCH001_FUN_EXIT   

 }ADCCH001_ErrorType;
 


 
 /*******************************************************************************
  *                             STRUCTURES                                     **
  ******************************************************************************/
 /**
  * This structure holds the parameters which change at run
  * time.
  */
typedef struct ADCCH001_DynamicHandleType
{
  /** This is the result of the conversion */
  uint16_t Result;
  /**This is the binary result of the fast comparison */
  uint8_t FastCompResult;
  /**This is the state of the app.*/
  ADCCH001_StateType State;
}ADCCH001_DynamicHandleType;

/**
 * This structure holds the GUI configurable parameters of this app.
 */
typedef struct ADCCH001_HandleType
{
  /**
   * This is the CMSIS structure pointer of the ADC group.
   */
  VADC_G_TypeDef* const ADCGrPtr;
  /**
   * This is the pointer to the dynamic handle of the app
   */
  ADCCH001_DynamicHandleType* const DynamicHandlePtr;
  /**
   * This tells whether this channel is priority channel.
   */
  const uint8_t kPrioChannel;
  /**
   * This selects the input class for this channel.  
   */
  const uint8_t kIpClassSel;   
  /**
   * This selects the lower and upper boundary for limit checking and boundary flag setting.
   * Boundaries are selected from the Group specific boundary 0 or 1 or global boundary 0 or 1. 
   * This is 4-bit value (UBoundary << 2 | LBoundary)
   */
  const uint8_t kBoundarySel;
  /**
   * This saves the configuration for the channel event generation.
   */  
  const uint8_t kChEvtmode;
  /**
   * This saves the reference input value for the ADC conversion.
   */
  const uint8_t kRefInput;
  /**
   * This saves the alignment of the result. 
   * 0: Left-Aligned
   * 1: Right-Aligned
   */
  const uint8_t kResultControl;  
  /**
   * This saves the result data modification mode. 
   * This is 6-bit value (DMM << 2 | DRCTR)
   */
  const uint8_t kDataModification;
  /**
   * This saves the result writing mode.
   * 0: Overwrite mode
   * 1: Wait for read mode
   */
  const uint8_t kWaitForRead;
  /**
   * This tells whether result FIFO is enabled.
   */
  const uint8_t kFIFOEnable;
  /**
   * This tells whether to enable result event
   */
  const uint8_t kResultEvtEnable;  
  /**
   * This tells whether to enable the boundary flag. 
   */
  const uint8_t kBoundaryFlagEnable;
  /**
   * This is the starting result register no for FIFO. 
   * If FIFO is not enabled, this parameter is not used.
   */
  const uint8_t kStartResultRegNo;
  /**
   * This is the end result register no which gives the final result of the conversion.
   * Result is always read from this result register.
   */
  const uint8_t kEndResultRegNo;
  /**
   * This tells whether to enable the external multiplexer control for this channel. 
   */
  const uint8_t kExtMuxControl;
  /**
   * This is the channel number consumed by this app 
   */
  const uint8_t kChannelNo;
  /**
   * This tells whether fast compare mode is enabled.
   */
  const uint8_t kCompareMode; 
  /**
   * This is the result compare value used in fast compare mode.
   * It is written in the register as 10-bit left-aligned value, 
   * bits 11-2 are considered and bits 1-0 are ignored.
   */
  const uint16_t kResultCompVal;
}ADCCH001_HandleType;

/**
 * @}
 */


/**
 * @ingroup ADCCH001_apidoc
 * @{
 */

/********************************************************************************************
          FUNCTION PROTOTYPES
********************************************************************************************/
/**
 * @brief This function will initialize ADC channel registers and result registers
 * as per user configured values. 
 * @param[in] none 
 * @return void
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     while(1);
     return 0;
   }
 * @endcode 
 */
void ADCCH001_Init(void);


/**
 * @brief This function will de-initialize ADC channel registers and result registers
 * as per user configured values. 
 * @param[in] HandlePtr Handle of the ADCCH001 App 
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     ADCCH001_Denit(&ADCCH001_Handle0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_Deinit(const ADCCH001_HandleType* HandlePtr);

/**
 * @brief This function will set the alias channel number. Same input channel 
 * will be converted by CH0 or CH1 and by the Alias channel number. 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] ChannelNo Alias channel number
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 *                                         OR if App is not configured for the Alias feature
 *         ADCCH001_INVALID_PARAM: If ChannelNo is greater than 7 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SetAlias(&ADCCH001_Handle0, 5);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SetAlias(const ADCCH001_HandleType* HandlePtr, uint8_t ChannelNo);

/**
 * @brief This function will enable the boundary flag for result registers
 * 0, 1, 2 or 3. \n
 * <b>Please make sure that the same result register is used for writing the channel conversion
 * result. </b> 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] FlagNo This is the boundary flag number 0 to 3.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCCH001_INVALID_PARAM: If FlagNo > 3
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_EnableBoundaryFlag(&ADCCH001_Handle0, 2);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_EnableBoundaryFlag(const ADCCH001_HandleType* HandlePtr, uint8_t FlagNo);

/**
 * @brief This function will disable the boundary flag for result registers
 * 0, 1, 2 or 3. \n
 * <b>Please make sure that the same result register is used for writing the channel conversion
 * result. </b> 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] FlagNo This is the boundary flag number 0 to 3.
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCCH001_INVALID_PARAM: If FlagNo > 3
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_DisableBoundaryFlag(&ADCCH001_Handle0, 2);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_DisableBoundaryFlag(const ADCCH001_HandleType* HandlePtr, uint8_t FlagNo);

/**
 * @brief This function will set the input class for this channel. Input class 
 * defines the channel parameters like conversion mode and sample time.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] Class This is the input class - Group specific class 0/1 <BR>
 *                                             Global Class 0/1
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCCH001_INVALID_PARAM: If Class > 3
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SelectInputClass(&ADCCH001_Handle0, ADCCH001_GROUP0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SelectInputClass(const ADCCH001_HandleType* HandlePtr, ADCCH001_InputClassType Class);
/**
 * @brief This function will select the channel event mode setting. Channel event can be generated when conversion result is 
 * inside or outside the boundary or for every conversion. \n
 * <b>For Fast Compare mode: Channel Event can be generated when conversion result is above or below
 * the compare value or for every conversion. </b>
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] Mode Channel event configuration mode
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *         ADCCH001_INVALID_PARAM: If Mode > 3
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SelectChEvtMode(&ADCCH001_Handle0, ADCCH001_OUTSIDE);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SelectChEvtMode(const ADCCH001_HandleType* HandlePtr, ADCCH001_ChanEvtModeType Mode);
/**
 * @brief This function will select the upper boundary from the available 4 boundaries. 
 * Actual value of the upper boundary is configured in the Group boundary 0, 1 or
 * Global boundary 0 , 1. \n
 * <b>For Fast Compare mode: This will set the upper delta value. </b>
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] UBoundary Upper Boundary selection as per Group or global boundaries
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state 
 *                                          OR if Fast Compare Mode is set<BR>
 *         ADCCH001_INVALID_PARAM: If UBoundary > 3
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SelectUpperBoundary(&ADCCH001_Handle0, ADCCH001_GROUPBOUNDARY0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SelectUpperBoundary(const ADCCH001_HandleType* HandlePtr, ADCCH001_BoundaryType UBoundary);
/**
 * @brief This function will select the lower boundary from the available 4 boundaries. 
 * Actual value of the lower boundary is configured in the Group boundary 0, 1 or
 * Global boundary 0 , 1. \n
 * <b>For Fast Compare mode: This will set the lower delta value. </b>
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] LBoundary Lower Boundary selection as per Group or global boundaries
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state 
 *                                          OR if Fast Compare Mode is set<BR>
 *         ADCCH001_INVALID_PARAM: If LBoundary > 3
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SelectLowerBoundary(&ADCCH001_Handle0, ADCCH001_GROUPBOUNDARY0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SelectLowerBoundary(const ADCCH001_HandleType* HandlePtr, ADCCH001_BoundaryType LBoundary);
/**
 * @brief This function will return the ADC conversion result value if result is valid. If 
 * available result is not valid, old result is returned.\n
 * <b>This function can be used only in the Standard conversin Mode. For Fast
 * Compare Mode, use ADCCH001_GetFastCompareResult API. </b> \n
 * <b>Note: Result is returned as the 16-bit raw value as per Conversion Mode, Result Alignment and
 * Data Modification Mode. User should take care of the shifting and how many bits to discard to get the 
 * correct result value. </b> 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[out] ResultPtr ADC Conversion Result
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 *                                         OR if Fast Compare Mode is set <BR>
 *         ADCCH001_INVALID_RESULT: If valid falg is not set
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     uint16_t Result;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_GetResult(&ADCCH001_Handle0, &Result);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_GetResult(const ADCCH001_HandleType* HandlePtr, uint16_t* ResultPtr);

/**
 * @brief This function will return the binary conversion result whether result is above the or below
 * the compare value. If available result is not valid, old result is returned.\n
 * <b>This function can be used only in the Fast Compare Mode. For Standard conversin Mode, 
 * use ADCCH001_GetResult API. </b>
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[out] ResultPtr Binary Conversion Result
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 *                                         OR if Fast Compare Mode is NOT set <BR>
 *         ADCCH001_INVALID_RESULT: If valid falg is not set
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     uint8_t Result;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_GetFastCompareResult(&ADCCH001_Handle0, &Result);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_GetFastCompareResult(const ADCCH001_HandleType* HandlePtr, uint8_t* ResultPtr);

/**
 * @brief This function will set the result compare value for the fast compare mode comparisions. 
 * Given value is left-shifted by 2 before writing to the result register. Bits 11-2 are used for the 
 * comparison. 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] CompVal Compare Value (10-bit) for the fast conversions
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 *                                         OR if Fast Compare Mode is NOT set <BR>
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SetCompareValue(&ADCCH001_Handle0, 0xFF);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SetCompareValue(const ADCCH001_HandleType* HandlePtr, uint16_t CompVal);

/**
 * @brief This function will enable the priority channel. It will assign the consumed channel to this group's request sources (queue/scan).
 * And thus it can not be a part of the background scan request source.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_EnablePriorityChannel(&ADCCH001_Handle0);

     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_EnablePriorityChannel(const ADCCH001_HandleType* HandlePtr);

/**
 * @brief This function will disable the priority channel.  
 * And thus it can be a part of the background scan request source.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_DisablePriorityChannel(&ADCCH001_Handle0);

     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_DisablePriorityChannel(const ADCCH001_HandleType* HandlePtr);

/**
 * @brief This function will enable the result event. This will enable the result event for the
 * lowest index result register in FIFO mode. \n 
 * Result event is not available in fast compare mode.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 *                                          OR if Fast Compare Mode is set 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_EnableResultEvt(&ADCCH001_Handle0);

     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_EnableResultEvt(const ADCCH001_HandleType* HandlePtr);

/**
 * @brief This function will disable the result event. This will disable the result event for the
 * lowest index result register in FIFO mode. \n  
 * Result event is not available in fast compare mode.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 *                                          OR if Fast Compare Mode is set 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_DisableResultEvt(&ADCCH001_Handle0);

     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_DisableResultEvt(const ADCCH001_HandleType* HandlePtr);

/**
 * @brief This function will check whether result event is set.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[out] EvtStatus Status of the event \n 
 * 0: Not set <BR>
 * 1: Set<BR>
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *                                         OR if Fast Compare Mode is NOT set
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     uint8_t EvtStatus;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_GetResultEvtFlag(&ADCCH001_Handle0, &EvtStatus);
     if((Status == DAVEApp_SUCCESS) && (EvtStatus == 0x01))
     {
       //Do something
     }
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_GetResultEvtFlag(const ADCCH001_HandleType* HandlePtr, uint8_t* EvtStatus);
/**
 * @brief This function will check whether channel event is set.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[out] EvtStatus Status of the event \n 
 * 0: Not set <BR>
 * 1: Set<BR>
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     uint8_t EvtStatus;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_GetChannelEvtFlag(&ADCCH001_Handle0, &EvtStatus);
     if((Status == DAVEApp_SUCCESS) && (EvtStatus == 0x01))
     {
       //Do something
     }
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_GetChannelEvtFlag(const ADCCH001_HandleType* HandlePtr, uint8_t* EvtStatus);
/**
 * @brief This function will set the result event by software. It is recommended
 * to NOT use this function inside the interrupt handler to avoid infinite loop.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *                                          OR if Fast Compare Mode is NOT set
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SetResultEvtFlag(&ADCCH001_Handle0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SetResultEvtFlag(const ADCCH001_HandleType* HandlePtr);
/**
 * @brief This function will set the channel event by software. It is recommended
 * to NOT use this function inside the interrupt handler to avoid infinite loop.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SetChannelEvtFlag(&ADCCH001_Handle0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SetChannelEvtFlag(const ADCCH001_HandleType* HandlePtr);
/**
 * @brief This function will clear the pending result event. 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state <BR>
 *                                         OR if Fast Compare Mode is NOT set
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     while(1);
     return 0;
   }
   //Result event interrupt handler
   void ResultISR(void)
   {
     uint8_t EvtStatus;
     Status = ADCCH001_GetResultEvtFlag(&ADCCH001_Handle0, &EvtStatus);
     if((Status == DAVEApp_SUCCESS) && (EvtStatus == 0x01))
     {
       //Do something
       Status = ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle0);
     }
   }
 * @endcode 
 */
status_t ADCCH001_ClearResultEvtFlag(const ADCCH001_HandleType* HandlePtr);
/**
 * @brief This function will clear the pending channel event. 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     while(1);
     return 0;
   }
   //Channel event interrupt handler
   void ChannelISR(void)
   {
     uint8_t EvtStatus;
     Status = ADCCH001_GetChannelEvtFlag(&ADCCH001_Handle0, &EvtStatus);
     if((Status == DAVEApp_SUCCESS) && (EvtStatus == 0x01))
     {
       //Do something
       Status = ADCCH001_ClearChannelEvtFlag(&ADCCH001_Handle0);
     }
   }
 * @endcode 
 */
status_t ADCCH001_ClearChannelEvtFlag(const ADCCH001_HandleType* HandlePtr);
/**
 * @brief This function will set the broken wire detection channel.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @param[in] BWDChannel broken wire detection channel \n
 * 0: VAGND \n 
 * 1: VAREF \n
 * @return  status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_SetBWDChannel(&ADCCH001_Handle0, ADCCH001_VAGND);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_SetBWDChannel(const ADCCH001_HandleType* HandlePtr, ADCCH001_BWDType BWDChannel);
/**
 * @brief This function will enable the broken wire detection safety feature. This enables the
 * additional preparation phase.
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_EnableBWD(&ADCCH001_Handle0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_EnableBWD(const ADCCH001_HandleType* HandlePtr);
/**
 * @brief This function will disable the broken wire detection safety feature. 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_DisableBWD(&ADCCH001_Handle0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_DisableBWD(const ADCCH001_HandleType* HandlePtr);

/**
 * @brief This function will enable the wait for read mode of the result register 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_EnableWaitForRead(&ADCCH001_Handle0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_EnableWaitForRead(const ADCCH001_HandleType* HandlePtr);
/**
 * @brief This function will disable the wait for read mode of the result register 
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return status_t <BR>
 *         DAVEApp_SUCCESS : If function is successful <BR>
 *         ADCCH001_OPERATION_NOT_ALLOWED: If function is called from the UNINITIALIZED state 
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
   #include <DAVE3.h>
   int main (void)
   {
     status_t Status;
     DAVE_Init();   //ADCCH001_Init is called within DAVE_Init()
     Status = ADCCH001_DisableWaitForRead(&ADCCH001_Handle0);
     while(1);
     return 0;
   }
 * @endcode 
 */
status_t ADCCH001_DisableWaitForRead(const ADCCH001_HandleType* HandlePtr);

#include "ADCCH001_Conf.h"

/**
 * @}
 */

#endif /* ADCCH001_H_ */

