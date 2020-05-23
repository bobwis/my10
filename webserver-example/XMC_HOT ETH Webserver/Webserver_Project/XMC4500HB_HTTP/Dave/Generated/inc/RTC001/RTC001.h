/******************************************************************************
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with
 * Infineon?s microcontrollers.
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
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [Yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Feb 12, 2013                                           **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** RP         App Developer                                                   **
*******************************************************************************/ 
/**
 * @file RTC001.h
 *
 * @App Version RTC001 <1.0.22>
 *
 * @brief  Real Time Clock App implementation header file.
 *
 */

 #ifndef RTC001_H_
 #define RTC001_H_
 /*******************************************************************************
**                      Include Files                                          **
*******************************************************************************/
#include <DAVE3.h>

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#if defined (__GNUC__)
#include <sys/time.h>
#elif defined(__TASKING__)
#include <time.h>
#endif


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/**
 * @ingroup RTC001_publicparam
 * @{
 */


/**
 * This enumeration defines RTC001 App error and status values.
 */

typedef enum RTC001_ErrorType
{
/**
  * @cond INTERNAL_DOCS
  * @param MODULENAME RTC001
  * @endcond
  */
/**
  * Invalid handle or parameter
  */
/**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING1 RTC001_INVALID_HANDLE
  * @param STRCODESTRING1 Invalid Handle or Parameter
  * @endcond
  */

  RTC001_INVALID_HANDLE = 1,
/**
  * Undefined Error
  */
/**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING2 RTC001_ERROR
  * @param STRCODESTRING2 Undefined Error
  * @endcond
  */
  RTC001_ERROR,
/**
  * Flag is set
  */  
/**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING2 RTC001_SET
  * @param STRCODESTRING2 Flag is Set
  * @endcond
  */
  RTC001_SET,
/**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING2 RTC001_RESET
  * @param STRCODESTRING2 Flag is Reset
  * @endcond
  */
/**
  * Flag is reset
  */  
  RTC001_RESET,
/**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING2 RTC001_FUNCTION_ENTRY
  * @param STRCODESTRING2 Entered function \%s
  * @endcond
  */
  RTC001_FUNCTION_ENTRY,
/**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING3 RTC001_FUNCTION_EXIT
  * @param STRCODESTRING3 Exited function \%s
  * @endcond
  */
  RTC001_FUNCTION_EXIT
}RTC001_ErrorType;


/**
 * The below set of flags are used to indicate RTC module's
 * Alarm and Periodic Timer event status. They can be
 * used while clearing the status as well.
 */

typedef enum RTC001_FlagType
{
  /** The Seconds flag in RTC */
  SECONDS_FLAG = 0x1U,
  /** The Minutes flag in RTC */
  MINUTES_FLAG = 0x2U,
  /** The Hours flag in RTC */
  HOURS_FLAG = 0x4U,
  /** The Days flag in RTC */
  DAYS_FLAG = 0x8U,
  /** The Months flag in RTC */
  MONTHS_FLAG = 0x20U,
  /** The Years flag in RTC */
  YEARS_FLAG = 0x40U,
  /** The Alarm flag in RTC */
  ALARM_FLAG = 0x100U
}RTC001_FlagType;


/**
 * Type of Call back function for Alarm Event.
 * A uint32_t argument can be optionally used.
 */
typedef void (*AlarmCallBackPtr)(uint32_t CbArg);

/**
 * Type of Call back function for Periodic Timer Event.
 * A (void *) argument can be optionally used.
 *
 */
typedef void (*RTC001_TimerCallBackPtr)(void*);

/**
 * Structure for RTC Time configuration.
 */
typedef struct RTC001_TimeHandle
{
  /** Time value to be entered in seconds field */
  uint8_t Sec;
  /** Time value to be entered in minutes field*/
  uint8_t Min;
  /** Time value to be entered in hours field*/
  uint8_t Hours;
  /** Time value to be entered in days field */
  uint8_t Days;
  /** Time value to be entered in days of week field*/
  uint8_t DaWe;
  /** Time value to be entered in months field*/
  uint8_t Month;
  /** Time value to be entered in years field*/
  uint16_t Year;
}RTC001_TimeHandle;


/**
* RTC001 App Handle structure. Stores a few parameters configured in App UI.
 */

typedef struct  RTC001_HandleType
{
 /** If value of this flag is 1, then RTC time value will be initialized
  * only once even after system reset
  */
  bool RTCInitOnce;
  /** Clock divider value */
  uint16_t DividerValue;
}RTC001_HandleType;

/**
 *@}
 */


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Extern Variables                                      **
*******************************************************************************/


/*******************************************************************************
**                     FUNCTION PROTOTYPES                                    **
*******************************************************************************/
/**
 * @ingroup RTC001_apidoc
 * @{
 */

 /**
 * Initialization function for the App.
 * This function configures the RTC module registers as per options given in App UI and enables the RTC module.
 *
 *
 *
 * @return     void
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *    // Initialize Apps
 *    DAVE_Init(); // RTC001_Init() will be called within DAVE_Init()
 *    // ... infinite loop ...
 *    while(1)
 *    {}
 *  }
 * @endcode<BR> </p> 
 */
void  RTC001_Init(void);


 /**
 * Deinitialization function for the app. Current version of the function is empty.
 *
 * @return     void
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *    // Initialize Apps
 *    DAVE_Init(); // RTC001_Init() will be called within DAVE_Init()
 *    RTC001_DeInit();
 *    // ... infinite loop ...
 *    while(1)
 *    {}
 *  }
 * @endcode<BR> </p> 
 */
void  RTC001_DeInit(void);


 /**
 * Enables the RTC module. May be called if RTC module is disabled previously.
 *
 *
 * @return     status <br>
 *             DAVEApp_SUCCESS	: for success <br>
 *             RTC001_ERROR  	: for failure case <br>
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code 
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *    // Initialize Apps
 *    DAVE_Init(); // RTC001_Init() will be called within DAVE_Init()
 *    RTC001_Enable();
 *    // ... infinite loop ...
 *    while(1)
 *    {}
 *  }
 * @endcode<BR> </p> 
 */
status_t  RTC001_Enable(void);


 /**
 * This function disables the RTC Module.
 * Time and Alarm registers are cleared. Can be used to Disable RTC module before configuring RTC Time.
 *
 * @return     status <br>
 *             DAVEApp_SUCCESS	: If Disable successful <br>
 *             RTC001_ERROR  	: If any error during Disable <br>
 *
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code 
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *    // Initialize Apps
 *    DAVE_Init(); // RTC001_Init() will be called within DAVE_Init()
 *    RTC001_Disable();
 *    // ... infinite loop ...
 *    while(1)
 *    {}
 *  }
 * @endcode<BR> </p> 
 */
status_t  RTC001_Disable(void);


 /**
 * This function clears the given RTC flag.
 *
 * @param[in]  Flag Indicates which flag to clear. Use the symbolic constants enumerated by RTC001_FlagType.
 * @return     void
 *
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code 
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *    // Initialize Apps
 *    DAVE_Init(); // RTC001_Init() will be called within DAVE_Init()
 *    RTC001_Enable();
 *    while(!RTC001_GetFlagStatus(HOURS_FLAG))
 *    {
 *      // Hour event happened
 *      RTC001_ClearFlagStatus(HOURS_FLAG);
 *    }
 *    // ... infinite loop ...
 *    while(1)
 *    {}
 *  }
 * @endcode<BR> </p> 
 */
void  RTC001_ClearFlagStatus(RTC001_FlagType Flag);


 /**
 * Get the status of specified flag.
 *
 * @param[in]  Flag Indicates which Flag to be checked. Use the symbolic constants enumerated by RTC001_FlagType.
 *
 * @return     status <br>
 *             RTC001_SET	    : Flag is set <br>
 *             RTC001_RESET  	: Flag is reset <br>
 *
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code 
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   // Initialize Apps
 *   DAVE_Init(); // RTC001_Init() will be called within DAVE_Init()
 *   RTC001_Enable();
 *   while(!RTC001_GetFlagStatus(HOURS_FLAG))
 *   {
 *     // Hour event happened
 *     RTC001_ClearFlagStatus(HOURS_FLAG);
 *   }
 *   // ... infinite loop ...
 *   while(1)
 *   {}
 * }
 * @endcode<BR> </p> 
 */
status_t  RTC001_GetFlagStatus(RTC001_FlagType Flag);


/**
 * This function configures the RTC001 Alarm.
 * If the Alarm Event interrupt is connected to SCU, then optionally a call
 * back function can be registered for the interrupt.
 *
 * @param[in] Handle RTC app Handle<BR>
 * @param[in] timeptr Pointer to structure which contains Alarm Time <BR>
 *           
 * @param[in] CallBack Alarm event call back function.
 *            If the Alarm Event is connected to SCU, the call back will be registered with NVIC_SCU001 app.
 *            If NULL is given, then call back is not registered<BR>
 * @param[in] CbArg (Optional) argument to be passed to the call back function<BR>
 *
 * @return     status_t<BR>
 *             DAVEApp_SUCCESS : if Alarm configuration is successful<BR>
 *             RTC001_INVALID_HANDLE: If any of the parameter is invalid<BR>
 *             RTC001_ERROR    : If any error during Alarm configuration <BR>
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code 
 * #include <DAVE3.h>
 * static volatile bool AlarmEvent;
 * void Alarm_CallBack(uint32_t Temp)
 * {
 *   AlarmEvent = TRUE;
 * }
 * int main(void)
 * {
 *   uint32_t Status;
 *   RTC001_TimeHandle Alarm_Time;
 *    // ... Initializes Apps ...
 *   DAVE_Init();
 *   Alarm_Time.Sec = 32;
 *   Alarm_Time.Min = 30;
 *   Alarm_Time.Hours = 4;
 *   Alarm_Time.Days = 15;
 *   Alarm_Time.Month = 5;
 *   Alarm_Time.Year = 2012;
 *   Status = RTC001_ConfigAlarm(&RTC001_Handle,&Alarm_Time,Alarm_CallBack,0);
 *   if(Status == DAVEApp_SUCCESS)
 *   {
 *     //Alarm is created successfully
 *   }
 *   // ... infinite loop ...
 *   while(1)
 *   {}
 * }
 * @endcode<BR> </p> 
 */
status_t RTC001_ConfigAlarm (const RTC001_HandleType* Handle, RTC001_TimeHandle* timeptr, AlarmCallBackPtr CallBack,uint32_t CbArg) ;


/**
 * This function gets the current time from RTC.
 *
 * @param[in] timeptr Pointer to structure in which current time is returned<BR>
 * @return     status_t<BR>
 *             DAVEApp_SUCCESS : If RTC time is read successfully<BR>
 *             RTC001_ERROR    : If any error during reading<BR>
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code 
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   RTC001_TimeHandle CurrentTime;
 *   // Initialize Apps
 *   DAVE_Init(); // RTC001_Init() will be called within DAVE_Init()
 *   RTC001_Enable();
 *   while(!RTC001_GetFlagStatus(HOURS_FLAG))
 *   {
 *     // Read current time
 *     RTC001_Clock_GetTime(&CurrentTime);
 *   }
 *   // ... infinite loop ...
 *   while(1)
 *   {}
 * }
 * @endcode<BR> </p> 
 */
status_t RTC001_Clock_GetTime (RTC001_TimeHandle* timeptr);

/**
 * This function sets the RTC time. It is recommended to Disable RTC module before using this function.
 *
 * @param[in] timeptr Pointer to structure which contains time 
 * 					  values to be configured<BR>
 * @return     status_t<BR>
 *             DAVEApp_SUCCESS : If the RTC time is successfully configured<BR>
 *             RTC001_ERROR    : If any error during reading the time<BR>
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code 
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   RTC001_TimeHandle SetTime;
 *   uint32_t Status;
 *   // Initialize Apps
 *   DAVE_Init(); // RTC001_Init() will be called within DAVE_Init()
 *   RTC001_Disable();
 *   SetTime.Sec = 32;
 *   SetTime.Min = 30;
 *   SetTime.Hours = 4;
 *   SetTime.Days = 15;
 *   SetTime.Month = 5;
 *   SetTime.Year = 2012;
 *   Status = RTC001_Clock_SetTime(&SetTime);
 *   if(Status == DAVEApp_SUCCESS)
 *   {
 *     //Success
 *   }
 *   RTC001_Enable();
 *   // ... infinite loop ...
 *   while(1)
 *   {}
 * }
 * @endcode<BR> </p> 
 */
status_t RTC001_Clock_SetTime(RTC001_TimeHandle* timeptr);


/**
 * This function returns the time in seconds since the epoch time(01/01/1970).
 *
 * @param[in] time_value Pointer to an object of type time_t, 
 *                   for returning the time.  <BR>
 *
 * 
 * @return     status_t<BR>
 *             DAVEApp_SUCCESS : if time value is calculated successfully<BR>
 *             RTC001_ERROR    : If any error<BR>
 *                 
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code 
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   status_t status = RTC001_ERROR;
 *   time_t Time_Sec;
 *   // ... Initializes Apps ...
 *   DAVE_Init();
 *   status = RTC001_Time(&Time_Sec);
 *   if(status != DAVEApp_SUCCESS)
 *   {
 *	   //error
 *   }
 *   RTC001_Disable();
 *   // ... infinite loop ...
 *   while(1)
 *   {}
 * }
 * @endcode<BR> </p> 
 */
status_t RTC001_Time(time_t* time_value) ;

  
/**
 *@}
 */


/** Include App config file */
#include "RTC001_Conf.h"

#endif /* RTC001_H_ */


