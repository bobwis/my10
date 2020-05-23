
/*CODE_BLOCK_BEGIN[RTC001.c]*/

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
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Feb 12, 2013                                           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** RP        App Developer                                                    **
**                                                                            **
*******************************************************************************/ 


/**
 * @file RTC001.c
 *
 * @App Version RTC001 <1.0.22>
 *
 * @brief  Real Time Clock App Implementation.
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
 
#define APP_GID DBG002_GID_RTC001
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/

/*
 * Function to check whether the date is valid
 *              
 * @return     void 
 *      
 * <b>Reentrant: NO </b><BR>
 *
 */
static uint32_t RTC001_ldatevalid(uint16_t m, uint16_t d, uint16_t y);


/*
 * Function to calculate day of the week
 *              
 * @return     void 
 *      
 * <b>Reentrant: NO </b><BR>
 *
 */
static uint32_t RTC001_lweekday(uint16_t m, uint16_t d, uint16_t y);

/*
 *  Initialization function for the app. Configures the registers
 *  based on options selected in UI.
 *
 * @return     void
 *
 * <b>Reentrant: NO </b><BR>
 *
 */
static void  RTC001_lInit(const RTC001_HandleType* Handle);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/



/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
const uint32_t RTC001_DAYS_IN_MONTH[13] =
{
   /* Index from 1, hence skip 0*/
    0U,
    /*Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec*/
       31U,28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U
};
#define RTC001_DAYS_IN_AN_YEAR     (365U)
#define RTC001_SECONDS_IN_A_DAY    (24U * 60U * 60U)
#define RTC001_SECONDS_IN_AN_HOUR  (60U * 60U)
#define RTC001_SECONDS_IN_A_MINUTE (60U)
#define RTC001_EPOCH_YEAR          (1970U)
/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/



/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
 

/*
 *  Initialization function for the app. Configures the registers
 *  based on options selected in UI.
 */ 

static void  RTC001_lInit(const RTC001_HandleType* Handle)
{

  status_t status = (uint32_t) DAVEApp_SUCCESS;  	  
   /* <<<DD_RTC001_API_1>>> */
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY); 
   	  

  /* Clear Mirror register update status of RTC registers in SCU*/
  SCU_INTERRUPT->SRCLR = \
      (SCU_INTERRUPT_SRCLR_RTC_CTR_Msk | SCU_INTERRUPT_SRCLR_RTC_ATIM0_Msk | \
  		SCU_INTERRUPT_SRCLR_RTC_ATIM1_Msk | SCU_INTERRUPT_SRCLR_RTC_TIM0_Msk |\
  		SCU_INTERRUPT_SRCLR_RTC_TIM1_Msk);
  
  if ((((RTC->CTR & RTC_CTR_ENB_Msk) >> RTC_CTR_ENB_Pos) == 0U ) ||\
    (Handle->RTCInitOnce != 1U))
  {
     /* RTC disabled to set the time */
     status = RTC001_Disable();
     /*assert status = DAVEApp_SUCCESS*/
     DBG002_I (status = DAVEApp_SUCCESS);
     /* Calendar time and date set in RTC registers */
     status |= RTC001_Clock_SetTime(&timeptr1);
     /*assert status = DAVEApp_SUCCESS*/
     DBG002_I (status = DAVEApp_SUCCESS);

  }
  
  /* Enable the RTC module */
  RTC->CTR |= ((uint32_t)(RTC_CTR_ENB_Msk));
  /* Wait for Mirror register update and clear the update indication */
  while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_RTC_CTR_Msk) == 0U) 
  {}
  SCU_INTERRUPT->SRCLR = SCU_INTERRUPT_SRRAW_RTC_CTR_Msk;	
  
		
	  
      
  /* Enable RTC alarm interrupt in SCU */
  SCU_INTERRUPT->SRMSK |= SCU_INTERRUPT_SRMSK_AI_Msk; 
     	
	
  /*configure RTC prescaler*/
  WR_REGHIB(RTC->CTR, RTC_CTR_DIV_Msk, RTC_CTR_DIV_Pos, \
           (uint32_t)Handle->DividerValue, SCU_INTERRUPT_SRRAW_RTC_CTR_Msk);	    	     
 	 
  /* Enable RTC periodic interrupt in SCU */
  SCU_INTERRUPT->SRMSK |= (uint32_t)SCU_INTERRUPT_SRMSK_PI_Msk;     
  if (status != (uint32_t)DAVEApp_SUCCESS)
  {
    DBG002_ERROR(APP_GID,status, 0, NULL);
  }
  DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
}


/**
 *@}
 */

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/


/** @ingroup RTC001_publicparam
 * @{
 */

/*
 *  Initialization function for the app. Configures the registers
 *  based on options selected in UI.
 */
void RTC001_Init()
{
	RTC001_lInit(&RTC001_Handle);

}

/*
 *  Deinitialization function which initializes the App internal data
 *  structures to default values. 
 */
void  RTC001_DeInit(void)
{
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);
   /* <<<DD_RTC001_API_2>>> */
	
  DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
}


/*
 *  The function enables the RTC module.
 */
status_t  RTC001_Enable(void)
{
  status_t status = (uint32_t) RTC001_ERROR;
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);
   /* <<<DD_RTC001_API_3>>> */
 
  /* Clear Mirror register update status of RTC registers in SCU*/
  SCU_INTERRUPT->SRCLR |= (uint32_t)\
    (SCU_INTERRUPT_SRCLR_RTC_CTR_Msk | SCU_INTERRUPT_SRCLR_RTC_ATIM0_Msk |\
  	SCU_INTERRUPT_SRCLR_RTC_ATIM1_Msk | SCU_INTERRUPT_SRCLR_RTC_TIM0_Msk |\
  								SCU_INTERRUPT_SRCLR_RTC_TIM1_Msk);
  /* Enable RTC module */
  RTC->CTR |= (uint32_t)(RTC_CTR_ENB_Msk);
  /* Wait for Mirror register update and clear the update indication */
  while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_RTC_CTR_Msk) == 0U) 
  {}
  SCU_INTERRUPT->SRCLR = SCU_INTERRUPT_SRRAW_RTC_CTR_Msk;	
  
  status = (uint32_t) DAVEApp_SUCCESS;	
  DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
  return status;
}


/*
 *  The function disables the RTC module.
 */
 
status_t  RTC001_Disable(void)	
{
  status_t status = (uint32_t) RTC001_ERROR;
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);
   /* <<<DD_RTC001_API_4>>> */

  /* Disable the RTC module*/
  RTC->CTR &= (uint32_t) (~(RTC_CTR_ENB_Msk));
  /* Wait for Mirror register update and clear the update indication */
  while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_RTC_CTR_Msk) == 0U) 
  {}
  SCU_INTERRUPT->SRCLR = SCU_INTERRUPT_SRRAW_RTC_CTR_Msk;	

  /* Clear the RTC Time registers */  
  while((SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_RTC_TIM0_Msk)!= 0x0U)
  {}
  RTC->TIM0 = 0x00000000U;
  while((SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_RTC_TIM1_Msk)!= 0x0U)
  {}
  RTC->TIM1 = 0x00000000U;  
  /* Clear the Alarm registers */
  while((SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_RTC_ATIM0_Msk)!= 0x0U)
  {}
  RTC->ATIM0 = 0x00000000U;
  while((SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_RTC_ATIM1_Msk)!= 0x0U)
  {}
  RTC->ATIM1 = 0x00000000U; 	
  /* Clear Mirror register update status of RTC registers in SCU*/
  SCU_INTERRUPT->SRCLR |= (uint32_t)\
    (SCU_INTERRUPT_SRCLR_RTC_CTR_Msk | SCU_INTERRUPT_SRCLR_RTC_ATIM0_Msk |\
  	SCU_INTERRUPT_SRCLR_RTC_ATIM1_Msk | SCU_INTERRUPT_SRCLR_RTC_TIM0_Msk |\
  	SCU_INTERRUPT_SRCLR_RTC_TIM1_Msk);    
  							
  status = (uint32_t)DAVEApp_SUCCESS;
  DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
  return status;
}


/*
 *  The function gets RTC status flag for Alarm and Periodic Timer Events.
 */	
status_t  RTC001_GetFlagStatus(RTC001_FlagType Flag)
{
  status_t status = (uint32_t) RTC001_RESET;
  uint32_t TempValue = 0U;
  /* <<<DD_RTC001_API_6>>> */
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);

  /*read the Status Service Request Register*/
  TempValue = RTC->STSSR;
  
  /*check the given flag*/
	if((TempValue & (uint32_t) Flag) != 0U)
	{
	  status = (uint32_t) RTC001_SET;
	}

	DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
	return status;
}


/*
 *  The function clears RTC status flag for Alarm and Periodic Timer Events.
 */
void  RTC001_ClearFlagStatus(RTC001_FlagType Flag)
{
  /* <<<DD_RTC001_API_5>>> */
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);
  
  /*write to the Clear Service Request Register*/
  RTC->CLRSR |= (uint32_t)Flag;

	DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
}


/*
 *  Interface to configure the RTC alarm.
 */

status_t RTC001_ConfigAlarm (const RTC001_HandleType* Handle, 
    RTC001_TimeHandle* timeptr, AlarmCallBackPtr CallBack,uint32_t CbArg)
{
  uint16_t m1 = 0U,y1 = 0U,d1 = 0U;
  status_t status = (uint32_t)RTC001_ERROR;
  /* <<<DD_RTC001_API_11>>> */
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);
  do
  {
    /* <<<DD_RTC001 _API_4>>> */
    /* Clear Mirror register update status of RTC registers in SCU*/
    SCU_INTERRUPT->SRCLR = (uint32_t)\
      (SCU_INTERRUPT_SRCLR_RTC_CTR_Msk | SCU_INTERRUPT_SRCLR_RTC_ATIM0_Msk | \
  		SCU_INTERRUPT_SRCLR_RTC_ATIM1_Msk | SCU_INTERRUPT_SRCLR_RTC_TIM0_Msk |\
  		SCU_INTERRUPT_SRCLR_RTC_TIM1_Msk);  	

    /* Register the call back function with NVIC_SCU001 */		
    if(CallBack != NULL)
    {    
	    
	    NVIC_SCU001_RegisterCallback(NVIC_SCU001_AI,CallBack,CbArg);
	    
	  } 
    /*   Write values into ATIM0 and ATIM1 registers  */
    m1 = timeptr->Month;
    y1 = timeptr->Year;
    d1 = timeptr->Days;
    /* Check whether the date entered is valid */
    if (RTC001_ldatevalid(m1,d1,y1))
    { 
      /*Wait until any transfer over serial interface to ATIM0 is completed*/   
      while((SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_RTC_ATIM0_Msk)!= 0x0U)
      {}   
      /*Configure the Alarm Time Register 0 */
      RTC->ATIM0 = (uint32_t)\
               (((timeptr->Sec) & (uint32_t)RTC_ATIM0_ASE_Msk) | \
              ((((uint32_t)timeptr->Min) << RTC_ATIM0_AMI_Pos) & \
                                  (uint32_t)RTC_ATIM0_AMI_Msk) | \
            ((((uint32_t)timeptr->Hours) << RTC_ATIM0_AHO_Pos) & \
                                  (uint32_t)RTC_ATIM0_AHO_Msk) | \
        (((((uint32_t)timeptr->Days)-1U) << RTC_ATIM0_ADA_Pos) & \
                                  (uint32_t)RTC_ATIM0_ADA_Msk));

      /*Wait until any transfer over serial interface to ATIM1 is completed*/        
      while((SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_RTC_ATIM1_Msk)!= 0x0U)
      {}   
      /*Configure the Alarm Time Register 1 */
      RTC->ATIM1 = (uint32_t)\
           ((((((uint32_t)timeptr->Month)-1U) << RTC_ATIM1_AMO_Pos) & \
                                       (uint32_t)RTC_ATIM1_AMO_Msk) | \
        ((uint32_t)(((uint32_t)timeptr->Year) << RTC_ATIM1_AYE_Pos) & \
                                       (uint32_t)RTC_ATIM1_AYE_Msk)); 				       
      status = (uint32_t)DAVEApp_SUCCESS;   
    }  
    else /*date is not valid*/
    {
      status = (uint32_t)RTC001_INVALID_HANDLE;
      DBG002_ERROR(APP_GID,status, 0, NULL);
    }
 
  }while(0);
  DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
  return status;
}
	

/*
 *  Function to read the current RTC time
 */
 
status_t RTC001_Clock_GetTime (RTC001_TimeHandle* timeptr)
{
  status_t status = (uint32_t)RTC001_ERROR;
  uint32_t temp0,temp1;
  temp0 = RTC->TIM0;
  temp1 = RTC->TIM1;
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);
   /* <<<DD_RTC001_API_12>>> */

  /*   Read values from TIM0 and TIM1 registers  */
  /*   Days of Week value  */
	timeptr->DaWe = (uint8_t)(temp1 & RTC_TIM1_DAWE_Msk);
  /*   Month value  */
	timeptr->Month = \
          (uint8_t)(((temp1 & RTC_TIM1_MO_Msk) >> RTC_TIM1_MO_Pos) + 1U);
  /*   Year value  */
	timeptr->Year = (uint16_t)((temp1 & RTC_TIM1_YE_Msk) >> RTC_TIM1_YE_Pos);

  /*   Seconds value  */
	timeptr->Sec =  (uint8_t)((temp0 & RTC_TIM0_SE_Msk));
  /*   Minutes value  */
	timeptr->Min = (uint8_t)(((temp0 & RTC_TIM0_MI_Msk) >> RTC_TIM0_MI_Pos));
  /*   Hours value  */
	timeptr->Hours = (uint8_t)(((temp0 & RTC_TIM0_HO_Msk) >> RTC_TIM0_HO_Pos));
  /*   Days value starting from the 1st day of the month */
	timeptr->Days = \
          (uint8_t)(((temp0 & RTC_TIM0_DA_Msk) >> RTC_TIM0_DA_Pos) + 1U);
	status = (uint32_t)DAVEApp_SUCCESS;
  DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
  return status;
}


/*
 *  This function is to set the time.
 */
status_t RTC001_Clock_SetTime(RTC001_TimeHandle* timeptr)
{
  uint16_t m1 = 0U,y1 = 0U,d1 = 0U;
  uint32_t weekDay = 0U;
  status_t status = (uint32_t)RTC001_ERROR;
  
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);
   /* <<<DD_RTC001_API_13>>> */
  


  /* Clear Mirror register update status of RTC registers in SCU*/
  SCU_INTERRUPT->SRCLR = \
      (SCU_INTERRUPT_SRCLR_RTC_CTR_Msk | SCU_INTERRUPT_SRCLR_RTC_ATIM0_Msk | \
  		SCU_INTERRUPT_SRCLR_RTC_ATIM1_Msk | SCU_INTERRUPT_SRCLR_RTC_TIM0_Msk |\
  		SCU_INTERRUPT_SRCLR_RTC_TIM1_Msk);
 
  /*   Days of Week value  */
  m1 = timeptr->Month;
  y1 = timeptr->Year;
  d1 = timeptr->Days;
  
  do
  {    
    if (RTC001_ldatevalid(m1,d1,y1))
    { 
      weekDay = ((uint32_t)(RTC001_lweekday(m1,d1,y1)));
      if(weekDay < 6U)
      {
        weekDay += 1U;
      }
      else if(weekDay == 6U)
      {
        weekDay = 0U;
      }
      else
      {
        status = (uint32_t)RTC001_INVALID_HANDLE;
        DBG002_ERROR(APP_GID,RTC001_INVALID_HANDLE, 0, NULL);
        break;
      }
      /*Write values into TIM0 and TIM1 registers  */
      /*wait until any serial transaction is completed*/      
      while((SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_RTC_TIM0_Msk)!= 0x0U)
      {}
      /*Configure RTC Time register 0*/
      RTC->TIM0 = (uint32_t)\
               (((timeptr->Sec) & (uint32_t)RTC_TIM0_SE_Msk) | \
              ((((uint32_t)timeptr->Min) << RTC_TIM0_MI_Pos) & \
                                  (uint32_t)RTC_TIM0_MI_Msk) | \
            ((((uint32_t)timeptr->Hours) << RTC_TIM0_HO_Pos) & \
                                  (uint32_t)RTC_TIM0_HO_Msk) | \
      ((((((uint32_t)timeptr->Days)-1U)) << RTC_TIM0_DA_Pos) & \
                                  (uint32_t)RTC_TIM0_DA_Msk));      
      /*wait until any serial transaction is completed*/
      while((SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_RTC_TIM1_Msk)!= 0x0U)
      {}     
      /*Configure RTC Time register 1*/
      RTC->TIM1 = (uint32_t) (weekDay |\
                   (((((uint32_t)timeptr->Month)-1U) << RTC_TIM1_MO_Pos) & \
                                              (uint32_t)RTC_TIM1_MO_Msk) | \
                         ((((uint32_t)timeptr->Year) << RTC_TIM1_YE_Pos) & \
                                              (uint32_t)RTC_TIM1_YE_Msk));      
      status = (uint32_t) DAVEApp_SUCCESS;
    }  
    else
    {
      status = (uint32_t) RTC001_INVALID_HANDLE;
      DBG002_ERROR(APP_GID,status, 0, NULL);
    }
  }while(0);

  DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
  return status;
}


/*
 *  This function is to get the time in seconds calculated from Epoch time (01/01/1970).
 */

status_t RTC001_Time(time_t* time_value)
{

  uint32_t CurrentYear = 0U, ElapsedYear = 0U;
  uint32_t CurrentMonth = 0U, ElapsedMonth = 0U;
  uint32_t CurrentDay = 0U, ElapsedDays = 0U;
  uint32_t CurrentHour = 0U;
  uint32_t CurrentMin = 0U;
  uint32_t CurrentSec = 0U;
  uint32_t ElapsedSeconds = 0U;
  status_t Status = (uint32_t)RTC001_ERROR; 
  
  DBG002_FUNCTION_ENTRY(APP_GID,RTC001_FUNCTION_ENTRY);
   /* <<<DD_RTC001_API_15>>> */
  
  /*check if RTC module is enabled and no NULL pointer*/
  if(((RTC->CTR & (RTC_CTR_ENB_Msk)) != 0U) && (time_value != NULL))
  {

    /*   Read values from TIM0 and TIM1 registers  */
    CurrentYear = ((uint32_t)((RTC->TIM1 & RTC_TIM1_YE_Msk) >> 16U));
    CurrentMonth = 	((uint32_t)(((RTC->TIM1 & RTC_TIM1_MO_Msk) >> 8U) + 1U));
    CurrentDay = ((uint32_t)(((RTC->TIM0 & RTC_TIM0_DA_Msk) >> 24U) + 1U));
    CurrentHour = ((uint32_t)(((RTC->TIM0 & RTC_TIM0_HO_Msk) >> 16U)));
    CurrentMin = ((uint32_t)(((RTC->TIM0 & RTC_TIM0_MI_Msk) >> 8U)));
    CurrentSec = ((uint32_t)((RTC->TIM0 & RTC_TIM0_SE_Msk)));
    
    /*Count number of Days for Elapsed Years since Epoch*/
    ElapsedDays = (uint32_t)(CurrentYear - RTC001_EPOCH_YEAR) *\
                  (uint32_t) RTC001_DAYS_IN_AN_YEAR;

    /* Add the number of days to be adjusted for leap years, 
    start from previous year and check backwords */
    for (ElapsedYear=(CurrentYear-1U); ElapsedYear>= 1970U; ElapsedYear--)
    {
      if((((ElapsedYear) % 400U) == 0U) || \
        ((((ElapsedYear) % 100U) != 0U) && (((ElapsedYear) %4U) == 0U)))
      {
        ElapsedDays++;
      }
    }
    /*if current year is leap year add 1 only if March or later*/
    if((((CurrentYear) % 400U) == 0U) || \
      ((((CurrentYear) % 100U) != 0U) && (((CurrentYear) %4U) == 0U)))
    {
      if(CurrentMonth > 2U)
      {
        ElapsedDays++;
      }
    }
    
    /*Add number of Days from Elapsed months from current year*/
    for (ElapsedMonth = (CurrentMonth - 1U); ElapsedMonth != 0U; ElapsedMonth--)
    {
      ElapsedDays += RTC001_DAYS_IN_MONTH[ElapsedMonth];  
    } 
    
    /*add Elapsed days from current month*/
    ElapsedDays += CurrentDay - 1U;
    
    /*Accumulate the total seconds for ElapsedDays*/
    ElapsedSeconds = (ElapsedDays * RTC001_SECONDS_IN_A_DAY);

    /*Add seconds for current hour, minute and seconds*/
    ElapsedSeconds += (CurrentHour * RTC001_SECONDS_IN_AN_HOUR);   
    ElapsedSeconds += (CurrentMin * RTC001_SECONDS_IN_A_MINUTE); 
    ElapsedSeconds += CurrentSec; 

    *time_value = (time_t) ElapsedSeconds;
    Status = (uint32_t) DAVEApp_SUCCESS;
    
  }
  DBG002_FUNCTION_EXIT(APP_GID,RTC001_FUNCTION_EXIT);
  return Status;
}
/* return 1 if date is valid, 0 otherwise.	*/
static uint32_t RTC001_ldatevalid(uint16_t m,uint16_t d,uint16_t y)
{
  uint32_t valid = 0U;

  if ((m == 0U) || (m > 12U) )
  {
    valid = 0U;
  }
  else  if ((m != 2U) || (d < 29U))
  {
     if (d <= RTC001_DAYS_IN_MONTH[m])
     {
       valid = 1U;
     }
  }
  else /*reaches here only if m = February and day = 29*/
  {
    /*check if it is leap year*/
    if ((((y) % 400U) == 0U) || ((((y) % 100U) != 0U) && (((y) %4U) == 0U)))
    {
      if (d == 29U)
      { 
        valid = 1U;
      }
    }
  }
  return valid;
}

/* given month, day, year, returns day of week, eg. Monday = 0 etc.
*/ 

static uint32_t RTC001_lweekday(uint16_t m,uint16_t d,uint16_t y)
{
  uint16_t vx, tx, ix, feb;
  const uint8_t vx_list[] = 
  {
      0U, 20U, 0U, 16U, 24U, 20U, 0U, 24U, 4U, 12U, 8U, 16U, 12U
  };

  vx = vx_list[m];
  if(y > 1900U)
  {
    y = y - 1900U;
  }
  feb = (m  > 2U)? 1U : 0U;
/* take care of February */
  ix = ((y - 21U) % 28U) + vx + feb;
/* take care of leap year */
  tx = ((ix + (ix / 4U)) % 7U) + d;
  tx = tx % 7U;
  return ((uint32_t)tx);
}

/**
 *@}
 */

/*CODE_BLOCK_END*/

