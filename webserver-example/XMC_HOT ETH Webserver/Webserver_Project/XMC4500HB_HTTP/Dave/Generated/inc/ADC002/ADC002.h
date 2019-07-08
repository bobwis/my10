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
** KM           DAVE App Developer                                            **
*******************************************************************************/
/**
 * @file  ADC002.h
 *
 * @brief This file contains all public data structures,enums and function
 *        prototypes for ADC002 App.
 *
 */

#ifndef _ADC002_H_
#define _ADC002_H_
/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/

#include <DAVE3.h>

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/**
  * @ingroup ADC002_publicparam
  * @{
  */
/**
 * This will enumerate the error codes which will be returned from a function.
 */
typedef enum ADC002_ErrorCodesType
{
  /**
   * This code would be returned when any operation is not possible cause that
   * operation was tried in invalid state
   */
    /*
    GROUPID  #41
    MODULENAME = ADC002
    */
    /*
    ERRCODESTRING = ADC002_OPER_NOT_ALLOWED_ERROR
    STRCODESTRING = Function execution is not allowed in the current state
    */  
  ADC002_OPER_NOT_ALLOWED_ERROR = 1,
  /**
   * This code is returned when parameter passed to API are invalid
   */
  /*
  ERRCODESTRING = ADC002_INVALID_PARAM_ERROR
  STRCODESTRING = Input parameter is not valid
  */ 
  ADC002_INVALID_PARAM_ERROR,
  /**
   * This code is returned when number of events exceed limit.
   */
  /*
  ERRCODESTRING = ADC002_OUT_OF_RANGE_ERROR
  STRCODESTRING = number of events exceeds limit
  */  
  ADC002_OUT_OF_RANGE_ERROR,

  /** Debug log messages */
  /**
   * Message Id for function Entry
   */
  /*
  ERRCODESTRING = ADC002_FUN_ENTRY
  STRCODESTRING = Function entered
  */ 
  ADC002_FUNCTION_ENTRY,
  /**
   * Message ID for function exit
   */
  /*
  ERRCODESTRING = ADC002_FUN_EXIT
  STRCODESTRING = Function exited
  */ 
  ADC002_FUNCTION_EXIT,
}ADC002_ErrorCodesType;

typedef enum ADC002_GatingMode
{
 /**
   * Gating Disabled.
   */
  ADC002_GATING_DISABLED=0,
  /**
   * Gating is Always Enabled.
   */
  ADC002_GATING_ENABLED_ALWAYS=1,
  /**
   * Gating is enabled for high signal .
   */
  ADC002_GATING_ENABLED_FOR_HIGH=2,
  /**
   * Gating is enabled for low signal .
   */
  ADC002_GATING_ENABLED_FOR_LOW=3,
}ADC002_GatingMode;

typedef enum ADC002_TriggerMode
{
  /**
   * No External trigger.
   */
  ADC002_NOTRIGGER=0,
  /**
   * External trigger occurs on falling edge.
   */
  ADC002_TRIGGER_UPON_FALLING_EDGE=1,
  /**
   * External trigger occurs on rising edge.
   */
  ADC002_TRIGGER_UPON_RISING_EDGE=2,
  /**
   * External trigger occurs on both the edges.
   */
  ADC002_TRIGGER_UPON_BOTH_EDGE=3,
}ADC002_TriggerMode;

typedef enum ADC002_Priority
{
  /**
   * This is priority 0.
   */
  ADC002_PRIORITY0=0,
  /**
   * This is priority 1.
   */
  ADC002_PRIORITY1=1,
  /**
   * This is priority 2.
   */
  ADC002_PRIORITY2=2,
  /**
   * This is priority 3.
   */
  ADC002_PRIORITY3=3,
}ADC002_Priority;

typedef enum ADC002_StartMode
{
  /**
   * Wait for start mode
   * The requested channel is sampled after the current conversion 
   * has finished
   */
  ADC002_WAIT_FOR_START=0,
  /**
   * Cancel inject Repeat mode
   * After an injected conversion has finished,the interrupted conversion 
   * request is injected into the pipeline,hence the measurement is repeated.
   */
  ADC002_CANCEL_INJECT_REPEAT=1,
  /**
   * Cancel inject Repeat mode with cancel mode
   * In case of an ongoing conversion, this conversion is cancelled, the requested
   * channel is sampled and converted immediately.
   */
   ADC002_CANCEL_INJECT_REPEAT_WITH_CANCEL=2,
}ADC002_StartMode;

/**
 * This enumerates the queue entry Activer or InActive
 */
typedef enum ADC002_QueueEntryActive
{
  /**
   * Queue Entry Inctive
   */
  ADC002_ENTRY_INACTIVE = 0,
  /**
   * Queue Entry active
   */
  ADC002_ENTRY_ACTIVE
}ADC002_QueueEntryActive;


/**
 * This enumerates the queue entry refill enable or disable
 */
typedef enum ADC002_QueueEntryRefill
{
  /**
   * Disable refill.
   */
  ADC002_REFILL_DISABLE = 0,
  /**
   * Enable refill.
   * The processed entry is automatically reloaded into the queue.
   */
  ADC002_REFILL_ENABLE
}ADC002_QueueEntryRefill;


/**
 * This enumerates the queue entry external trigger enable or disable
 */
typedef enum ADC002_QueueEntryExtTrigger
{
  /**
   * Disable external trigger.
   */
  ADC002_EXT_TRIGGER_DISABLE = 0,
  /**
   * Enable external trigger.
   * This synchronizes the request source activation with external events, 
   * such as a trigger pulse from a timer generating a PWM signal or from a port pin.
   */
  ADC002_EXT_TRIGGER_ENABLE
}ADC002_QueueEntryExtTrigger;

/**
 * This enumerates the start conversion after initialization.
 */
typedef enum ADC002_ConversionAfterInit
{
  /**
   * Disable start conversion after initialization
   */
  ADC002_START_CONV_DISABLE = 0,
  /**
   * Enable conversion after initialization
   */
  ADC002_START_CONV_ENABLE
}ADC002_ConversionAfterInit;


/**
 * This enumerates the enable or disable of associated arbitration slot.
 */
typedef enum ADC002_ArbitrationSlot
{
  /**
   * Disable start conversion after initialization
   */
  ADC002_ARBITRATION_SLOT_DISABLE = 0,
  /**
   * Enable arbitration slot 0
   * Arbitration slot 0 is for queue request source
   */
  ADC002_ARBITRATION_SLOT_ENABLE
}ADC002_ArbitrationSlot;


/**
 * This enumerates the queue entry interrupt enable or disable
 */
typedef enum ADC002_QueueEntryInterrupt
{
  /**
   * Source Event Interrupt Disable
   */
  ADC002_INTERRUPT_DISABLE = 0,
  /**
   * Source Event Interrupt enable
   */
  ADC002_INTERRUPT_ENABLE
}ADC002_QueueEntryInterrupt;


/**
 * This enumerates the state of the App.
 */
typedef enum ADC002_StateType
{
  /**
   * This is the Default state of an APP after power on reset.
   */
  ADC002_UNINITIALIZED,
  /**
   * This is the INITIALIZED state in which APP is initialized as per selected
   * parameters.
   */
  ADC002_INITIALIZED,
}ADC002_StateType;


/**
 * This structure holds the parameters which change at run time.
 */
typedef struct ADC002_DynamicDataType
{
  /**
   * This enumerates the state of the App.
   */
  ADC002_StateType State;

}ADC002_DynamicDataType;
/**
 * This structure holds the Queue Entry parameters.
 */
typedef struct ADC002_QueueEntryHandleType
{
  uint8_t Active;
  /**
   * The channel Number
   */
  uint8_t ChannelNumber;
  /**
   * The refill option for the channel
   */
  uint8_t Refill;
  /**
   * The External Trigger Enable Option
   */
  uint8_t ExternalTrigger;
  /**
   * The Interrupt Enable Option
   */
  uint8_t Interrupt;
}ADC002_QueueEntryHandleType;
/**
 * This structure holds the GUI configurable parameters of this app.
 */
typedef struct ADC002_HandleType
{
  /* Associated ADC group number */
  uint8_t kGroupNo;
  
  /* Number of channels selected  */
  uint8_t kNChannels;
  /**
   * The default queue initialized by user at configuration time.
   */
  ADC002_QueueEntryHandleType *kQueueEntryHandlePtr;

  /**
   * Gating mode
   */
  uint8_t kGatingMode;
  /**
   * Trigger Enable
   * This will set enable external trigger bit in QMR0 if any of trigger mode(other than No external trigger)
   * is selected
   */
  uint8_t kTriggerEn;
  /**
   * This is Trigger mode
   * 00 No external trigger
   * 01 Trigger event upon a falling edge
   * 10 Trigger event upon a rising edge
   * 11 Trigger event upon any edge
   */
  uint8_t kTriggerMode;
  /**
   * Priority of Queue request source 0:Lowest,3:Highest
   */
  uint8_t kPriority;
  /**
   * The control register of the queue source selects the external gate and/or
   * trigger signals.
   */
  uint8_t kStartmode;
  /**
   * Arbitration slot 0 enable/disable
   */
  uint8_t kAsenEnable;
  /**
   * This is used to generate Software trigger by setting TREV bit of QMR0 Reg
   */
  uint8_t kStart;
  
  /**
   * This tells the Active channels
   */
  uint8_t kActiveChannels[8];
  
  /**
   * Logical Channel A 
   * This Variable is for user to get to know what actual channel is assigned 
   * which logical channel
   */
  uint8_t kChannelA;
  
  /**
   * Logical Channel B 
   * This Variable is for user to get to know what actual channel is assigned 
   * which logical channel
   */
  uint8_t kChannelB;
  
  /**
   * Logical Channel C 
   * This Variable is for user to get to know what actual channel is assigned 
   * which logical channel
   */
  uint8_t kChannelC;
  
  /**
   * Logical Channel D 
   * This Variable is for user to get to know what actual channel is assigned 
   * which logical channel
   */
  uint8_t kChannelD;
  
  /**
   * Logical Channel E 
   * This Variable is for user to get to know what actual channel is assigned 
   * which logical channel
   */
  uint8_t kChannelE;
  
  /**
   * Logical Channel F 
   * This Variable is for user to get to know what actual channel is assigned 
   * which logical channel
   */
  uint8_t kChannelF;
  
  /**
   * Logical Channel G 
   * This Variable is for user to get to know what actual channel is assigned 
   * which logical channel
   */
  uint8_t kChannelG;
  
  /**
   * Logical Channel H 
   * This Variable is for user to get to know what actual channel is assigned 
   * which logical channel
   */
  uint8_t kChannelH;

 /**
   * Sync Channel A
   *This variable stores the physical channel number which is assigned to the Syncchannel A.
   */
  uint8_t kSyncChannelA;
  
  /**
   * Sync Channel B
   * This variable stores the physical channel number which is assigned to the Syncchannel B.
   */
  uint8_t kSyncChannelB;
  
  /**
   * Sync Channel C
   * This variable stores the physical channel number which is assigned to the Syncchannel C.
   */
  uint8_t kSyncChannelC;
  
  /**
   * Sync Channel D
   * This variable stores the physical channel number which is assigned to the Syncchannel D.
   */
  uint8_t kSyncChannelD;
  
  /**
   * Sync Channel E
   * This variable stores the physical channel number which is assigned to the Syncchannel E.
   */
  uint8_t kSyncChannelE;
  
  /**
   * Sync Channel F
   * This variable stores the physical channel number which is assigned to the Syncchannel F.
   */
  uint8_t kSyncChannelF;
  
  /**
   * Sync Channel G
   * This variable stores the physical channel number which is assigned to the Syncchannel G.
   */
  uint8_t kSyncChannelG;
  
  /**
   * Sync Channel H
   * This variable stores the physical channel number which is assigned to the Syncchannel H.
   */
  uint8_t kSyncChannelH;
    
  /**
   * This is the pointer to the structure which holds the parameters which change
   * at run time.
   */
  ADC002_DynamicDataType* const DynamicHandlePtr;
  
  /**
   * Pointer to the associated group app handle.
   */  
  const ADCGROUP001_HandleType* kGroup_HandlePtr;
  
  /**
   * Pointer to the associated channel A app handle.
   */  
  const void* kChAHandlerPtr;
  
  /**
   * Pointer to the associated channel B app handle.
   */  
  const void* kChBHandlerPtr;

  /**
   * Pointer to the associated channel C app handle.
   */  
  const void* kChCHandlerPtr;
  
  /**
   * Pointer to the associated channel D app handle.
   */  
  const void* kChDHandlerPtr;
  
  /**
   * Pointer to the associated channel E app handle.
   */  
  const void* kChEHandlerPtr;
  
  /**
   * Pointer to the associated channel F app handle.
   */  
  const void* kChFHandlerPtr;
  
  /**
   * Pointer to the associated channel G app handle.
   */  
  const void* kChGHandlerPtr;
  
  /**
   * Pointer to the associated channel H app handle.
   */  
  const void* kChHHandlerPtr;

  /**
   * Pointer to the associated Sync App handle.
   */  
  const void* kSyncChPtr;

  /**
   * This is the pointer to the VADC Global Registers.
   */
  VADC_GLOBAL_TypeDef* VADCGlobalPtr;

  /**
   * This is the pointer to the VADC group Registers.
   */
  VADC_G_TypeDef* VADCGroupPtr;  
}ADC002_HandleType;
/**
 * @}
 */
/**
 * @ingroup ADC002_apidoc
 * @{
 */
/*******************************************************************************
** FUNCTION PROTOTYPES                                                        **
*******************************************************************************/


/**
 * @brief This function initializes the ADC Queue with the configured
 * parameters. <BR>
 *
 * @return None <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    DAVE_Init(); //ADC002_Init is called within DAVE_Init
 *    return 0;
 * }
 @endcode
 */
void ADC002_Init(void);

/**
 * @brief This function will reset the App.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful.<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    //Call the deinit function to reset the app to default values.
 *    Status = 
 *          ADC002_Deinit((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_Deinit(const ADC002_HandleType* HandlePtr);
/**
 * @brief This function initializes the ADC Queue with the configured
 * parameters. <BR>
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful.<BR><BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    DAVE_Init(); //ADC002_Init is called within DAVE_Init
 *    ADC002_InitializeQueue((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 @endcode
 */
status_t ADC002_InitializeQueue(const ADC002_HandleType *HandlePtr );
/**
 * @brief This function clears the Event flag EV.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_ClearEvent((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_ClearEvent(const ADC002_HandleType *HandlePtr);

/**
 * @brief This Function Clear all queue entries (including backup
 * stage) and the event flag EV. The queue  contains no more valid entry.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_FlushQueue((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */

status_t ADC002_FlushQueue(const ADC002_HandleType *HandlePtr);

/**
 * @brief This function generates a trigger event by software,
 * so that conversion request will get issued
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_TriggerEvent((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_TriggerEvent(const ADC002_HandleType *HandlePtr);

/**
 * @brief This Function clears next pending valid queue entry in the sequence and the event flag EV.
 * If there is a valid entry in the queue backupregister (QBUR.V = 1), this entry is cleared,
 * otherwise the entry in queue register 0 is cleared.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_ClearValidBit((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_ClearValidBit(const ADC002_HandleType *HandlePtr);

/**
 * @brief This function Selects the gating functionality for source.
 * The Gate selection value should be from 0 to 3
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[in] GateSelectVal Holds the gate select value<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If Input value is out of range<BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_EnableGate((ADC002_HandleType*)&ADC002_Handle0,2);//Gate select value holds 0/1/2/3
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_EnableGate(
                    const ADC002_HandleType *HandlePtr,uint8_t GateSelectVal);

/**
 * @brief This Function enables the queue arbitration slot of an arbiter round.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *      ADC002_EnableQueueArbitrationSlot((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_EnableQueueArbitrationSlot(
                        const ADC002_HandleType *HandlePtr);
/**
 * @brief This Function disables the queue arbitration slot of an arbiter round.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *      ADC002_DisableQueueArbitrationSlot((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_DisableQueueArbitrationSlot(
                        const ADC002_HandleType *HandlePtr);
                        
/**
 * @brief This function will select the external trigger mode.
 * This API will disable external trigger if mode value is 0,
 * otherwise it enables the external trigger.
 * The mode selection value should be from 0 to 3.
 * @param[in] HandlePtr Pointer to the Instance variable<BR>
 * @param[in] Mode      Mode selection value<BR>
 * 00->No trigger<BR>
 * 01->Trigger event upon a falling edge<BR>
 * 10->Trigger event upon a rising edge<BR>
 * 11->Trigger event upon a both edge<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If Input value is out of range<BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *      ADC002_SetExternalTriggerMode((ADC002_HandleType*)&ADC002_Handle0,1);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_SetExternalTriggerMode(const ADC002_HandleType *HandlePtr,
		                                                        uint8_t Mode);	


/**
 * @brief This Function will set the external trigger. Conversion will start when edge is
 * detected on the configured signal.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_EnableExternalTrigger((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_EnableExternalTrigger(
                        const ADC002_HandleType *HandlePtr);
                        
/**
 * @brief This Function will Disables the external trigger.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_DisableExternalTrigger((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_DisableExternalTrigger(
                        const ADC002_HandleType *HandlePtr);

/**
 * @brief This Function checks if there is valid entries in the queue,
 * It returns 1 if queue is empty.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] ValidEntryPtr Pointer to instance of Variable that<BR>
 * will contain the return value.<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If Pointer is NULL<BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint8_t validPtr=0;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_IsEmpty((ADC002_HandleType*)&ADC002_Handle0,&validPtr);//Valid Ptr will hold the status of queue
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_IsEmpty(const ADC002_HandleType *HandlePtr,uint8_t *ValidEntryPtr);

/**
 * @brief Indicates the number of valid queue entries.It is incremented each time
 * a new entry is written to QINRx or by an enabled refill mechanism. It is
 * decremented each time a requested conversion has been started.A new entry
 * is ignored if the filling level has reached its maximum value.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] FillLevelPtr this will hold the filling level of queue<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint8_t FillPtr=0;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_GetFillingLevel((ADC002_HandleType*)&ADC002_Handle0,&FillPtr);//FillPtr will hold the filling level of queue
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_GetFillingLevel(
      const ADC002_HandleType *HandlePtr,uint8_t *FillLevelPtr);

/**
 * @brief This function gets the current level of the selected gate input.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] GateLevelPtr is Pointer to instance of Variable<BR>
 * this will hold the Gate level of queue<BR>
 * 0->low,
 * 1->high
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If pointer is null<BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint8_t GatePtr=0;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_GetGateLevel((ADC002_HandleType*)&ADC002_Handle0,&GatePtr);//GatePtr will hold the Gate level of queue
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */

status_t ADC002_GetGateLevel(
          const ADC002_HandleType *HandlePtr,uint8_t *GateLevelPtr);

/**
 * @brief This function Indicates that an event has been detected while at least
 * one valid entry has been in the queue (queue register 0 or backup stage).
 * Once set, this bit is cleared automatically when the requested conversion
 * is started.It gives value 1 if event is detected else gives value 0.
 * least one valid entry has been in the queue
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] EventPtr is pointer to the Instance variable<BR>
 * this will hold the status of event<BR>
 * 0->No event detected,
 * 1->Event has been detected.
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If pointer is NULL<BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint8_t EvtPtr=0;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_IsEventDetected((ADC002_HandleType*)&ADC002_Handle0,&EvtPtr);//EvtPtr will hold the status of event
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_IsEventDetected(const ADC002_HandleType *HandlePtr,
                                                           uint8_t *EventPtr);
/**
 * @brief This function makes the entry to the queue request.
 * The function should not be called when conversion is ongoing. It will not have any effect.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[in] QueueEntryPtr pointer to the Instance variable<BR>
 * This will hold the queue entry parameters<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If Pointer value is NULL<BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    ADC002_QueueEntryHandleType ADC002_QueueEntryHandle = {
 *	    .Active = 1,
 *	    .ChannelNumber =  2,
 *	    .Refill =  0 ,
 *	    .ExternalTrigger =  0 ,
 *	    .Interrupt = 0 ,
 *	};
 *	DAVE_Init();Initialization of DAVE Apps	
 *	ADC002_AddQueueEntry((ADC002_HandleType*)&ADC002_Handle0,&ADC002_QueueEntryHandle);
 *	while(1); 
 *  return 0;
 * }
 * @endcode
 */
status_t ADC002_AddQueueEntry(const ADC002_HandleType *HandlePtr,
                              const ADC002_QueueEntryHandleType *QueueEntryPtr);
/**
 * @brief This function sets standard conversion mode.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[in] ConversionMode Conversion mode value should be 0/1/2/5<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If Input value is out of range<BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_SetConversionMode((ADC002_HandleType*)&ADC002_Handle0,1);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_SetConversionMode(const ADC002_HandleType *HandlePtr,
                                                     uint8_t ConversionMode);

/**
 * @brief This function sets sample time for standard conversion.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[in] SampleTime Sample time value should be from 0 to 31 <BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If Input value is out of range<BR>
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_SetSampleTime((ADC002_HandleType*)&ADC002_Handle0,12);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_SetSampleTime(const ADC002_HandleType *HandlePtr,
													uint8_t SampleTime);

/**
 * @brief This function sets EMUX conversion mode
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[in] ConversionMode This Selects the appropriate conversion mode its value should be 0/1/2/5<BR>
 * @return <b>status_t</b><BR> 
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If Input value is out of range<BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_SetEMUXConversionMode((ADC002_HandleType*)&ADC002_Handle0,5);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_SetEMUXConversionMode(const ADC002_HandleType *HandlePtr,
                                                    uint8_t ConversionMode);

/**
 * @brief This function sets sample time for EMUX conversion.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[in] SampleTime Sample time value should be from 0 to 31<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR:If Input value is out of range<BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_EMUXSetSampleTime((ADC002_HandleType*)&ADC002_Handle0,24);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_EMUXSetSampleTime(const ADC002_HandleType *HandlePtr,
                                                      uint8_t SampleTime);
/**
 * @brief This function monitors the status of the pending request (queue stage 0)
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] EntryPtr pointer to the Instance variable<BR>
 * This holds the status of the pending request (queue stage 0)<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR: If the Pointer value is NULL<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint32_t EntryPtr=0;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_GetQueueStage0Entry((ADC002_HandleType*)&ADC002_Handle0,&EntryPtr);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */

status_t ADC002_GetQueueStage0Entry(const ADC002_HandleType *HandlePtr, 
                                                    uint32_t *EntryPtr);
/**
 * @brief This function monitors the status of an aborted queued request.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] EntryPtr pointer to the Instance variable<BR>
 * This holds the status of the aborted queued request(queue stage 0)<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR: If the Pointer value is NULL<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint32_t EntryPtr=0;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_GetQueueBackupStageEntry((ADC002_HandleType*)&ADC002_Handle0,&EntryPtr);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_GetQueueBackupStageEntry(const ADC002_HandleType *HandlePtr,
                                                    uint32_t *EntryPtr);
/**
 * @brief This function gets the Source Event flag.
 * If it is 1 source event has occured otherwise no source event
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @param[out] Flagptr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 * ADC002_INVALID_PARAM_ERROR: If the Pointer value is NULL<BR><BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint8_t FlagPtr=0;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_GetSourceEventFlag((ADC002_HandleType*)&ADC002_Handle0,&FlagPtr);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_GetSourceEventFlag(const ADC002_HandleType *HandlePtr,
                                              uint8_t *Flagptr);
/**
 * @brief This function sets the Source Event flag.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *        ADC002_SetSourceEventFlag((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t ADC002_SetSourceEventFlag(const ADC002_HandleType *HandlePtr);
/**
 * @brief This function Clears the Source Event Flag.
 * @param[in] HandlePtr pointer to the Instance variable<BR>
 * @return <b>status_t</b><BR>
 *
 * DAVEApp_SUCCESS: if the function is successful <BR>
 * ADC002_OPER_NOT_ALLOWED: If the function is called when in
 * ADC002_UNINITIALIZED State. <BR>
 *
 * <b>Reentrant: yes</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();//ADC002_Init is called within DAVE_Init
 *    Status =
 *          ADC002_ClearSourceEventFlag((ADC002_HandleType*)&ADC002_Handle0);
 *    while(1);
 *    return 0;
 * }
 * void sourceeventISR(void)
 *{
 * //Do something
 * ADC002_ClearSourceEventFlag((ADC002_HandleType*)&ADC002_Handle0);
 *}
 * 
 * @endcode
 */
status_t ADC002_ClearSourceEventFlag(const ADC002_HandleType *HandlePtr);
/**
 * @}
 */
#include "ADC002_Conf.h" 
#endif /* ADC002_H_ */
