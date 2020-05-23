/*CODE_BLOCK_BEGIN[SYSTM001.c]*/
/*******************************************************************************
 Copyright (c) 2013, Infineon Technologies AG                                 **
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
** PLATFORM : Infineon XMC4000/XMC1xxx Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Jan 13, 2013                                            **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** Yogesh       App Developer                                                 **
*******************************************************************************/
/* Revision History
 *****************************************************************************
 *Date           Version     Remarks
 *13/1/2013       1.0.10      XMC1xxx device support added
 *
 *
*/
/**
 * @file   SYSTM001.c
 *
 * @App Version SYSTM001 <1.0.10>
 *
 * @brief  SCU_SystemTimer_SYSTM001 App implementation file. This App provides
 * API's for create, start, stop and delete software timers.
 *
 */
/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/

/* Inclusion of header file */
#include <DAVE3.h>

  
/*****************************************************************************
              DUMMY DEFINTIONS OF DEBUG LOG MACROS
*****************************************************************************/
/*These definitions are included here to avoid compilation errors,
 since the DBG002 app is not part of the project. All the macros are defined
 as empty*/ 
#ifndef _DBG002_H_

#define DBG002_RegisterCallBack(A,B,C)
#define DBG002_I(e) 
#define DBG002_IG(e,g) 
#define DBG002_IH(e,h) 
#define DBG002_IP(e,p) 
#define DBG002_IGH(e,g,h) 
#define DBG002_IGP(e,g,p) 
#define DBG002_IHP(e,h,p) 
#define DBG002_IGHP(e,g,h,p) 
#define DBG002_N(e) 
#define DBG002_NG(e,g) 
#define DBG002_NH(e,h) 
#define DBG002_NP(e,p) 
#define DBG002_NGH(e,g,h) 
#define DBG002_NGP(e,g,p) 
#define DBG002_NHP(e,h,p) 
#define DBG002_NGHP(e,g,h,p) 
#define DBG002_ID(e) 
#define DBG002_IS(e) 
#define DBG002_ISG(e,g) 
#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)
#define DBG002_CRITICAL(groupid,messageid,length,value)
#define DBG002_ERROR(groupid,messageid,length,value)
#define DBG002_WARNING(groupid,messageid,length,value)
#define DBG002_INFO(groupid,messageid,length,value)
#define DBG002_TRACE(groupid,messageid,length,value)
#define DBG002_FUNCTION_ENTRY(GID, Status) 
#define DBG002_FUNCTION_EXIT(GID, Status) 

#endif/* End of defintions of dummy Debug Log macros*/                  


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define APP_GID DBG002_GID_SYSTM001
#define HW_TIMER_ADDITIONAL_CNT (1U)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/

 
/**
 * @brief      This function is called to insert a timer into the timer list.  
 *        
 * @param[in]  Index Timer ID
 * @return     none
 *      
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 */
static void  SYSTM001_lInsertTimerList (uint32_t Index);


/*
 * @brief      This function is called to remove a timer from the timer list. 
 *              
 * @param[in]  Index Timer ID
 * @return     none
 *      
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 */
static void  SYSTM001_lRemoveTimerList(uint32_t Index);

/*
 * @brief      Handler function  called from Systick event handler. 
 *              
 * @return     void 
 *      
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 */
static void  SYSTM001_lTimerHandler (void);

/*
 * @brief      Systick  handler
 *              
 * @return     void 
 *      
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 */
void  SysTick_Handler (void);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/



/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/** Table which save timer control block. */
SYSTM001_TimerObject TimerTbl[SYSTM001_CFG_MAX_TMR];

/** The header of the Timer Control list.      */
SYSTM001_TimerObject*  TimerList = 0;

 /**   Timer ID Tracker  */
uint32_t TimerTracker = 0UL;

/** SysTick Counter */
uint32_t SysTickCount = 0UL;


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/



/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/



/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*
 * This function is called to insert a timer into the timer list.
 */
static void  SYSTM001_lInsertTimerList (uint32_t Index)
{
  SYSTM001_TimerObject* TmrObjPtr;
  int32_t DeltaTicks;
  uint32_t TempTmrCnt;
   /* Get timer time */
  TempTmrCnt = TimerTbl[Index].TimerCount;
  /* Check if timer count is zero */
  /* <<<DD_SYSTM001_PRIV _API_1>>> */

  /* Check if Timer list is NULL */
  if(TimerList == NULL)
  {
      /* Set this as first Timer */
      TimerList = &TimerTbl[Index];
  }
  /* IF Not, find the correct place ,and insert the specified timer */
  else
  {
    TmrObjPtr = TimerList;
    /* Get timer tick */
    DeltaTicks = (int32_t)TempTmrCnt;
    /* Find correct place for inserting the timer */
    while(TmrObjPtr != NULL)
    {
      /* Get timer Count Difference  */
      DeltaTicks -= (int32_t)TmrObjPtr->TimerCount;
      /* Is delta ticks<0? */
      if(DeltaTicks < 0)
      {
        /*  Check If head item */
        if(TmrObjPtr->TimerPrev!= NULL)
        {
          /* If Insert to list */
          TmrObjPtr->TimerPrev->TimerNext = &TimerTbl[Index];
          TimerTbl[Index].TimerPrev = TmrObjPtr->TimerPrev;
          TimerTbl[Index].TimerNext = TmrObjPtr;
          TmrObjPtr->TimerPrev = &TimerTbl[Index];
        }
        else
        {
          /* Set Timer as first item */
          TimerTbl[Index].TimerNext = TimerList;
          TimerList->TimerPrev = &TimerTbl[Index];
          TimerList = &TimerTbl[Index];
        }
        TimerTbl[Index].TimerCount = \
                TimerTbl[Index].TimerNext->TimerCount + (uint32_t)DeltaTicks;
        TimerTbl[Index].TimerNext->TimerCount  -= TimerTbl[Index].TimerCount;
        break;
      }
      /* Is last item in list? */
      else
      {
        if((DeltaTicks >= 0) && (TmrObjPtr->TimerNext == NULL))
        {
          /* Yes,insert into */
          TimerTbl[Index].TimerPrev = TmrObjPtr;
          TmrObjPtr->TimerNext = &TimerTbl[Index];
          TimerTbl[Index].TimerCount = (uint32_t)DeltaTicks;
          break;
        }
      }
      /* Get the next item in timer list    */
      TmrObjPtr = TmrObjPtr->TimerNext;
    }
  }
}


/*
 * This function is called to remove a timer from the timer list. 
 */
static void  SYSTM001_lRemoveTimerList(uint32_t Index)
{
  SYSTM001_TimerObject* TmrObjPtr;
  TmrObjPtr = &TimerTbl[Index];
  /* Check whether only one timer available */
  /* <<<DD_SYSTM001_PRIV _API_2>>> */
  if((TmrObjPtr->TimerPrev == NULL) && (TmrObjPtr->TimerNext == NULL))
  {
    /* set timer list as NULL */ 
    TimerList = NULL;                 	
  }
   /* Check if the first item in timer list   */
  else if(TmrObjPtr->TimerPrev == NULL)     
  {   
    /* Remove timer from list,and reset timer list */
    TimerList  = TmrObjPtr->TimerNext;
    TimerList->TimerPrev = NULL;
    TmrObjPtr->TimerNext->TimerCount += TmrObjPtr->TimerCount;
    TmrObjPtr->TimerNext    = NULL;  
  }
  /* Check if the last item in timer list   */
  else if(TmrObjPtr->TimerNext == NULL)      
  {
    /* Remove timer from list */
    TmrObjPtr->TimerPrev->TimerNext = NULL;	
    TmrObjPtr->TimerPrev = NULL;
  }
  else                                /*  remove timer from list         */
  {
    /*  Remove timer from list */
    TmrObjPtr->TimerPrev->TimerNext  =  TmrObjPtr->TimerNext;
    TmrObjPtr->TimerNext->TimerPrev  =  TmrObjPtr->TimerPrev;
    TmrObjPtr->TimerNext->TimerCount  += TmrObjPtr->TimerCount;
    TmrObjPtr->TimerNext = NULL;
    TmrObjPtr->TimerPrev = NULL;
  }
}

/*
 * Handler function  called from Systick event handler. 
 */
static void  SYSTM001_lTimerHandler (void)
{
  SYSTM001_TimerObject* TmrObjPtr;
   /* Get first item of timer list       */
  TmrObjPtr = TimerList;         
  /* <<<DD_SYSTM001_PRIV _API_3>>> */  
  while((TmrObjPtr != NULL) && (TmrObjPtr->TimerCount == 0UL) )
  {	
    /* Check whether timer is a one shot timer */
    if(TmrObjPtr->TimerType == SYSTM001_ONE_SHOT)
    {
      /* Yes,remove this timer from timer list */
      SYSTM001_lRemoveTimerList(TmrObjPtr->TimerID);
      /* Set timer status as SYSTM001_STATE_STOPPED */
      TmrObjPtr->TimerState = SYSTM001_STATE_STOPPED;
      /* Call timer callback function */
      (TmrObjPtr->TimerCallBack)(TmrObjPtr->ParamToCallBack);
    }
    /* Check whether timer is SYSTM001_PERIODIC */
    else if(TmrObjPtr->TimerType == SYSTM001_PERIODIC)
    {
      /* Yes,remove this timer from timer list */
      SYSTM001_lRemoveTimerList(TmrObjPtr->TimerID);
      /* Reset timer tick             */
      TmrObjPtr->TimerCount = TmrObjPtr->TimerReload;
        /* Insert timer into timer list */
      SYSTM001_lInsertTimerList(TmrObjPtr->TimerID);
      /* Call timer callback function */
      (TmrObjPtr->TimerCallBack)(TmrObjPtr->ParamToCallBack);
    }
    else
    {
      break;
    }
    /* Get first item of timer list */
    TmrObjPtr = TimerList;
  }
}

/*
 *  SysTick Event Handler 
 */
void  SysTick_Handler(void)
{ 
  SYSTM001_TimerObject* TmrObjPtr;
  TmrObjPtr = TimerList;
  /* <<<DD_SYSTM001_PRIV _API_4>>> */
  SysTickCount++;

  if(TmrObjPtr == NULL)
  {
    /* Not supposed to be here */
    DBG002_ERROR(APP_GID,SYSTM001_INVALID_HANDLE_ERROR, 0, NULL);
  }
  else
  {
    if(TmrObjPtr->TimerCount > 1UL)
    {
      TmrObjPtr->TimerCount--;
    }
    else
    { 
      TmrObjPtr->TimerCount = 0;
      SYSTM001_lTimerHandler();
    }
  }
}

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/


/** @ingroup Simple_System_Timer_App PublicFunc
 * @{
 */
 
/*
 *  Initialization function which initializes the App internal data
 *  structures to default values. 
 */
void  SYSTM001_Init( void)
{
    uint32_t Status = 0UL;
  DBG002_FUNCTION_ENTRY(APP_GID,SYSTM001_FUNCTION_ENTRY);
   /* <<<DD_SYSTM001 _API_1>>> */
  /** Initialize the header of the list */
  TimerList = NULL;
  /* Clock Initialization */
  CLK001_Init();     
  /**   Initialize timer tracker  */
  Status = SysTick_Config((uint32_t)(SYSTM001_SYSTICK_INTERVAL * SYSTM001_SYS_CORE_CLOCK * 1000U));
  if(Status == 1U)
  {
        DBG002_ERROR(APP_GID,SYSTM001_ERROR, 0, NULL);
  }
    NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10,0));
  TimerTracker = 0UL;
  DBG002_FUNCTION_EXIT(APP_GID,SYSTM001_FUNCTION_EXIT);
}

/*
 *  Interface for creating a new software Timer instance.
 *  Note: Because of invocation of SYSTM001_Init() : Timer reload value 
 *  programmed, Hardware System Timer started. Software Timer will be created
 *  using SYSTM001_CreateTimer(). Due to time at which SW timer creation asked
 *  by user will not be in sync with HW timer, the count value used below with
 *  SW Timer, will not create starting/initial period same as expected value.
 *  To SW timer period (Initial one) equal to more than expected, it is decided
 *  to add one extra count(HW_TIMER_ADDITIONAL_CNT) with Software timer.
 *
 *  Impact: Impact of this additional count(HW_TIMER_ADDITIONAL_CNT) is,
 *  First SW Timer period is always equal to or more than expected/configured. 
 */
handle_t SYSTM001_CreateTimer
(
  uint32_t Period,
  SYSTM001_TimerType TimerType, 
  SYSTM001_TimerCallBackPtr TimerCallBack, 
  void  * pCallBackArgPtr
)
{
  uint32_t TimerID = 0UL;
  uint32_t Count = 0UL;
  uint32_t Error = 0UL;  
  /* <<<DD_SYSTM001 _API_2>>> */
  DBG002_FUNCTION_ENTRY(APP_GID,SYSTM001_FUNCTION_ENTRY);
  /* Check for input parameter */
    if((TimerType != SYSTM001_ONE_SHOT) && (TimerType != SYSTM001_PERIODIC))
    {
      DBG002_ERROR(GID_SYSTM001,SYSTM001_INVALID_HANDLE_ERROR, 0, NULL);
      Error=(uint32_t)1UL;
    }
    if(Period < (uint32_t)SYSTM001_SYSTICK_INTERVAL)
    {
      DBG002_ERROR(GID_SYSTM001,SYSTM001_INVALID_HANDLE_ERROR, 0, NULL);
      Error=(uint32_t)1UL;
    }
    if(Period == 0)          /* Timer with '0' time is not allowed. */
    {
      DBG002_ERROR(GID_SYSTM001,SYSTM001_INVALID_HANDLE_ERROR, 0, NULL);
      Error=(uint32_t)1UL;
    }

    if(TimerCallBack == NULL)
    {
      DBG002_ERROR(GID_SYSTM001,SYSTM001_INVALID_HANDLE_ERROR, 0, NULL);
      Error=(uint32_t)1UL;
    }
    if (!Error)	
    {
       for(Count = 0UL; Count < SYSTM001_CFG_MAX_TMR; Count++)
       {
           /* Check for free timer ID */
           if((TimerTracker & ((uint32_t)1U << Count)) == 0U)
           {
               /* If yes,assign ID to this timer      */
               TimerTracker |= ((uint32_t)1U << Count);
               /* Initialize timer as per input values */
               TimerTbl[Count].TimerID     = Count;
               TimerTbl[Count].TimerType   = TimerType;
               TimerTbl[Count].TimerState  = SYSTM001_STATE_STOPPED;
             TimerTbl[Count].TimerCount  = ((Period / SYSTM001_SYSTICK_INTERVAL)\
                                                    +HW_TIMER_ADDITIONAL_CNT);
               TimerTbl[Count].TimerReload	= (Period / SYSTM001_SYSTICK_INTERVAL);
               TimerTbl[Count].TimerCallBack = TimerCallBack;
               TimerTbl[Count].ParamToCallBack = pCallBackArgPtr;
               TimerTbl[Count].TimerPrev   = NULL;
               TimerTbl[Count].TimerNext   = NULL;
               TimerID = Count + 1U;
               break;
            }
        }
    }
  DBG002_FUNCTION_EXIT(APP_GID,SYSTM001_FUNCTION_EXIT);
  return (handle_t)TimerID;
}  

/*
 *  Interface to start the software timer .
 */
status_t SYSTM001_StartTimer(handle_t  Handle) 
{
  status_t Error = (status_t )DAVEApp_SUCCESS;
  /* <<<DD_SYSTM001 _API_3>>> */
  DBG002_FUNCTION_ENTRY(APP_GID,SYSTM001_FUNCTION_ENTRY);

  /* Check validity of parameter */
  if(Handle > SYSTM001_CFG_MAX_TMR)
  {
    Error = (status_t)SYSTM001_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID,Error, 0, NULL);
  }
  if( (TimerTracker & (1UL << (uint32_t)(Handle - 1U))) == 0UL)
  {
    Error = (status_t) SYSTM001_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID,Error, 0, NULL);
  }
  /* Any timer with time '0', can't start again. */
  if(TimerTbl[Handle - 1U].TimerCount == 0UL)
  {
    Error = (status_t) SYSTM001_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID,Error, 0, NULL);
  }
  
  
  if(Error == (status_t)DAVEApp_SUCCESS)
  {
    /* Check if timer is running */
    if(TimerTbl[(Handle - 1U)].TimerState != SYSTM001_STATE_RUNNING)
    {
      /* set timer status as SYSTM001_STATE_RUNNING */
      TimerTbl[(Handle - 1U)].TimerState = SYSTM001_STATE_RUNNING;
      /* Insert this timer into timer list  */
      SYSTM001_lInsertTimerList((Handle - 1U));
    }
  }

  DBG002_FUNCTION_EXIT(APP_GID,SYSTM001_FUNCTION_EXIT);
  return Error;
}


/*
 *  Interface to stop the software timer.
 */
status_t SYSTM001_StopTimer(handle_t Handle) 
{
  status_t Error = (status_t )DAVEApp_SUCCESS;
  /* <<<DD_SYSTM001 _API_4>>> */
  DBG002_FUNCTION_ENTRY(APP_GID,SYSTM001_FUNCTION_ENTRY);

  /* Check validity of parameter        */
  if(Handle > SYSTM001_CFG_MAX_TMR)
  {
    Error = (status_t) SYSTM001_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID,Error, 0, NULL);
  }
  if( (TimerTracker & (1UL << (uint32_t)(Handle - 1U))) == 0UL)
  {
    Error = (status_t) SYSTM001_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID,Error, 0, NULL);
  }

  if(Error == (status_t)DAVEApp_SUCCESS)
  {
    /* Check whether Timer is in Stop state */
    if(TimerTbl[(Handle - 1U)].TimerState != SYSTM001_STATE_STOPPED)
    {
      /* remove Timer from node list */
      SYSTM001_lRemoveTimerList((Handle - 1U));

      /* Set timer status as SYSTM001_STATE_STOPPED  */
      TimerTbl[(Handle - 1U)].TimerState = SYSTM001_STATE_STOPPED;
    }
  }

  DBG002_FUNCTION_EXIT(APP_GID,SYSTM001_FUNCTION_EXIT);
  return Error;
}

/*
 *  Function to delete the Timer instance.
 */
status_t SYSTM001_DeleteTimer(handle_t Handle) 
{
  status_t Error = (status_t )DAVEApp_SUCCESS;
  /* <<<DD_SYSTM001 _API_5>>> */
  DBG002_FUNCTION_ENTRY(APP_GID,SYSTM001_FUNCTION_ENTRY);

  /* Check validity of parameter        */
  if(Handle > SYSTM001_CFG_MAX_TMR)
  {
    Error = (status_t) SYSTM001_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID,Error, 0, NULL);
  }
  if( (TimerTracker & (1UL << (uint32_t)(Handle - 1U))) == 0UL)
  {
    Error = (status_t) SYSTM001_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID,Error, 0, NULL);
  }

  if(Error == (status_t)DAVEApp_SUCCESS)
  {
    /* Check if timer is running */
    if(TimerTbl[(Handle - 1U)].TimerState == SYSTM001_STATE_RUNNING)
    {
      /* Yes,remove this timer from timer list*/
      SYSTM001_lRemoveTimerList((Handle - 1U));
    }

    /* Release resource that this timer hold*/
    TimerTracker &=~((uint32_t)1U << (Handle - 1U));
  }

  DBG002_FUNCTION_EXIT(APP_GID,SYSTM001_FUNCTION_EXIT);
  return Error;

}

/*
 *  Interface to get the current system time.
 */
uint32_t  SYSTM001_GetTime(void)
{
  /* <<<DD_SYSTM001 _API_6>>> */
  return CONVERT_SYSTICK_COUNT_TO_MSEC(SysTickCount);
}

/*
 *  Utility function to get the no of system ticks for the 
 *  specified period.
 */
uint32_t  SYSTM001_GetSysTickCount(uint32_t Period ) 
{
  /* <<<DD_SYSTM001 _API_7>>> */
  uint32_t	Count  = CONVERT_MSEC_TO_SYSICK_COUNT(Period);
  return Count;
}




/*CODE_BLOCK_END*/


