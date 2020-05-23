
/*CODE_BLOCK_BEGIN[NVIC_SCU001.c]*/

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
** PLATFORM : Infineon XMC4XXX Series   			                          **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Jan 21, 2013                                          **
**                                                                            **
*******************************************************************************/
/**
 * @file   NVIC_SCU001.c
 * 
 * @brief  NVIC_SCU001 App
 *
 * Revision History
 * 
 * 21 Jan 2013  v1.0.10    Removed DBG002_FUNCTION_ENTRY &  DBG002_FUNCTION_EXIT
 *							invocation from IRQ handler.
 * 
 */

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PAE        App Developer                                                   **
*******************************************************************************/

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
/** Inclusion of header file */

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

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
#define APP_GID DBG002_GID_NVIC_SCU001
/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
void SCU_0_IRQHandler(void);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
NVIC_SCU001_HandleType NVIC_SCU001_Handle0;
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/

/*  Function to configure SCU Interrupts based on  user configuration.
 * 
 */
void NVIC_SCU001_Init()
{
 DBG002_FUNCTION_ENTRY(APP_GID,NVIC_SCU001_FUNC_ENTRY);
  NVIC_SetPriority((IRQn_Type)64, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),63,0));
  /* Enable Interrupt */
  NVIC_EnableIRQ((IRQn_Type)64); 
 
  DBG002_FUNCTION_EXIT(APP_GID,NVIC_SCU001_FUNC_EXIT);
}

/*  Utility function to register Event Handler for a given event.
 * 
 */
void NVIC_SCU001_RegisterCallback
(
  NVIC_SCU001_InterruptType IntID,
  NVIC_SCU001_CallbackType userFunction,
  uint32_t CbArgs
 )
{
  /*<<<DD_NVIC_SCU001_API_2>>>*/
  NVIC_SCU001_HandleType* Handle = &NVIC_SCU001_Handle0;
  DBG002_FUNCTION_ENTRY(APP_GID,NVIC_SCU001_FUNC_ENTRY);
  Handle->SCU[IntID].CbListener = userFunction;
  Handle->SCU[IntID].CbArg = CbArgs;
   DBG002_FUNCTION_EXIT(APP_GID,NVIC_SCU001_FUNC_EXIT);
}


/*  SCU Interrupt Handler.
 * 
 */
void SCU_0_IRQHandler(void)
{
  NVIC_SCU001_CallbackType UserCallback;
  NVIC_SCU001_HandleType* Handle = &NVIC_SCU001_Handle0;
  uint32_t callbackArg = 0;
  uint32_t IrqActive= 0;
  /* read the interrupt status Register */
  IrqActive = SCU_INTERRUPT->SRSTAT;
  
  
  /* WDT pre-warning Interrupt */
  if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_PRWARN_Msk, SCU_INTERRUPT_SRSTAT_PRWARN_Pos))
  {
    /* run the listener function */
    if(Handle->SCU[NVIC_SCU001_PRWARN].CbListener != NULL)
    {
      UserCallback = Handle->SCU[NVIC_SCU001_PRWARN].CbListener;
      callbackArg = Handle->SCU[NVIC_SCU001_PRWARN].CbArg;
      UserCallback(callbackArg);
    }
    /* clear the interrupt */
    SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_PRWARN_Msk;
  }
  /* RTC Periodic Interrupt */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_PI_Msk, SCU_INTERRUPT_SRSTAT_PI_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_PI].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_PI].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_PI].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_PI_Msk;
  }
  /* RTC Alarm Interrupt  */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_AI_Msk, SCU_INTERRUPT_SRSTAT_AI_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_AI].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_AI].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_AI].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_AI_Msk;
  }
  /* DLR Request Overrun Interrupt  */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_DLROVR_Msk, SCU_INTERRUPT_SRSTAT_DLROVR_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_DLROVR].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_DLROVR].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_DLROVR].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_DLROVR_Msk;
  }
  /* HDSTAT Mirror Register Update Status  */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_HDSTAT_Msk, SCU_INTERRUPT_SRSTAT_HDSTAT_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_HDSTAT].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_HDSTAT].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_HDSTAT].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_HDSTAT_Msk;
  }
  /* HDCLR Mirror Register Update  */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_HDCLR_Msk, SCU_INTERRUPT_SRSTAT_HDCLR_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_HDCLR].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_HDCLR].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_HDCLR].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_HDCLR_Msk;
	
  }
  /* HDSET Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_HDSET_Msk, SCU_INTERRUPT_SRSTAT_HDSET_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_HDSET].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_HDSET].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_HDSET].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_HDSET_Msk;
	
  } 
  /* HDCR Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_HDCR_Msk, SCU_INTERRUPT_SRSTAT_HDCR_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_HDCR].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_HDCR].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_HDCR].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_HDCR_Msk;
	
  }
  /* OSCSICTRL Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_OSCSICTRL_Msk, SCU_INTERRUPT_SRSTAT_OSCSICTRL_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_OSCSICTRL].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_OSCSICTRL].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_OSCSICTRL].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_OSCSICTRL_Msk;
	
  } 
  /* OSCULSTAT Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_OSCULSTAT_Msk, SCU_INTERRUPT_SRSTAT_OSCULSTAT_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_OSCULSTAT].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_OSCULSTAT].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_OSCULSTAT].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_OSCULSTAT_Msk;
	
  }
  /* OSCULCTRL Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_OSCULCTRL_Msk, SCU_INTERRUPT_SRSTAT_OSCULCTRL_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_OSCULCTRL].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_OSCULCTRL].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_OSCULCTRL].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_OSCULCTRL_Msk;
	
  } 
  /* RTC_CTR Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_RTC_CTR_Msk, SCU_INTERRUPT_SRSTAT_RTC_CTR_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_RTC_CTR].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_RTC_CTR].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_RTC_CTR].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_CTR_Msk;
	
  } 
  /* RTC_ATIM0 Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_RTC_ATIM0_Msk, SCU_INTERRUPT_SRSTAT_RTC_ATIM0_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_RTC_ATIM0].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_RTC_ATIM0].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_RTC_ATIM0].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_ATIM0_Msk;
	
  }
  /* RTC_ATIM1 Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_RTC_ATIM1_Msk, SCU_INTERRUPT_SRSTAT_RTC_ATIM1_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_RTC_ATIM1].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_RTC_ATIM1].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_RTC_ATIM1].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_ATIM1_Msk;
	
  }
  /* RTC_TIM0 Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_RTC_TIM0_Msk, SCU_INTERRUPT_SRSTAT_RTC_TIM0_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_RTC_TIM0].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_RTC_TIM0].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_RTC_TIM0].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_TIM0_Msk;
	
  }
  /* RTC_TIM1 Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_RTC_TIM1_Msk, SCU_INTERRUPT_SRSTAT_RTC_TIM1_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_RTC_TIM1].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_RTC_TIM1].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_RTC_TIM1].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RTC_TIM1_Msk;
	
  }
  /* Retention Memory Mirror Register Update Status */
  else if(RD_REG(IrqActive,SCU_INTERRUPT_SRSTAT_RMX_Msk, SCU_INTERRUPT_SRSTAT_RMX_Pos))
  {
	/* run the listener function */
	if(Handle->SCU[NVIC_SCU001_RMX].CbListener != NULL)
	{
	  UserCallback = Handle->SCU[NVIC_SCU001_RMX].CbListener;
	  callbackArg = Handle->SCU[NVIC_SCU001_RMX].CbArg;
	  UserCallback(callbackArg);
	}
	/* clear the interrupt */
	SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_RMX_Msk;
	
  }
  else
  {
    /* If we've reached this point, either the enabling and
     * disabling of SCU interrupts is not being handled
     * properly or this function is being called unnecessarily.
     */
  }
  
  
}


/*CODE_BLOCK_END*/

