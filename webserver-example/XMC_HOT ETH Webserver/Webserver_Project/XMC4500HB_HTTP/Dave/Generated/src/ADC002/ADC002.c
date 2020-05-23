
/*CODE_BLOCK_BEGIN[ADC002.c]*/

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
** AUTHOR   : KM                                                              **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : July 31, 2012                                          **
**                                                                            **
*******************************************************************************/


/**
 * @file ADC002.c
 *
 * @brief This file contains ADC002 App API definitions
 *
 */
/**
 * @cond INTERNAL_DOCS
 */

/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
** KM           DAVE App Developer                                           **
** --------------------------------------------------------------------------**

*******************************************************************************/

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
#include <DAVE3.h>


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
/**
 * @brief This function initializes the app.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 *
 * @return  NOne <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 */
/*This is local init function*/
static void ADC002_lInit(const ADC002_HandleType *HandlePtr );

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

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




/** This function initializes the app */
void ADC002_Init(void)
{
   /*Initialization of app 'ADCGLOB001'*/         
  ADCGLOB001_Init();  
  ADC002_lInit(&ADC002_Handle0);    
}
/* 
 * This function initializes the queue App. Local function is used to 
 * initialize all the instances of the app.
 */
static void ADC002_lInit(const ADC002_HandleType *HandlePtr )
{
  /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_UNINITIALIZED)
  {
    /* Flush the Queue */
    SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_FLUSH_Pos);
    
    /* Sets the priority of the queue request source */
    WR_REG( VADCGroupPtr->ARBPR, VADC_G_ARBPR_PRIO0_Msk, 
            VADC_G_ARBPR_PRIO0_Pos,(uint32_t)HandlePtr->kPriority);                                                        
    /*
     * Enable XTWC Bitfield so that XTMODE and XTSEL can be written 
     * Selects trigger mode .
     */
    VADCGroupPtr->QCTRL0 |= (uint32_t)
        ((((uint32_t)1 << VADC_G_QCTRL0_XTWC_Pos) & VADC_G_QCTRL0_XTWC_Msk)|\
        (((uint32_t)HandlePtr->kTriggerMode << VADC_G_QCTRL0_XTMODE_Pos) &\
         VADC_G_QCTRL0_XTMODE_Msk));
    /*
     *Selects the gating mode and enables trigger mode
     */
    VADCGroupPtr->QMR0 |=(uint32_t)
        ((((uint32_t)HandlePtr->kTriggerEn << VADC_G_QMR0_ENTR_Pos)& VADC_G_QMR0_ENTR_Msk)|\
        (((uint32_t)HandlePtr->kGatingMode << VADC_G_QMR0_ENGT_Pos)& VADC_G_QMR0_ENGT_Msk));
    /*
     * Enable Arbitration slot.
     * Select conversion start mode for request source. 
     */
    VADCGroupPtr->ARBPR |= (uint32_t)
        ((((uint32_t)HandlePtr->kAsenEnable << VADC_G_ARBPR_ASEN0_Pos)&VADC_G_ARBPR_ASEN0_Msk)|\
        (((uint32_t)HandlePtr->kStartmode << VADC_G_ARBPR_CSM0_Pos) & VADC_G_ARBPR_CSM0_Msk));
    /*
     * Enable cancel mode.
     * Sets the bit rptdis of QMR0 Register 
     */
    if(HandlePtr->kStartmode == (uint8_t)ADC002_CANCEL_INJECT_REPEAT_WITH_CANCEL)
    {
      SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_RPTDIS_Pos);
    }
    /* Set the App State to Initialized */
    HandlePtr->DynamicHandlePtr->State = ADC002_INITIALIZED;                            
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)ADC002_OPER_NOT_ALLOWED_ERROR, 0, (uint8_t*)NULL);
  }
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
}
/*This function initializes queue entries*/
status_t ADC002_InitializeQueue(const ADC002_HandleType *HandlePtr )
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;

  /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;
  uint8_t QueueEntryNum;
  uint32_t QINR0Val;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);
  
  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  { 
   /* Inserts the selected entries to the Queue. */
    for(QueueEntryNum = (uint8_t)0; QueueEntryNum <= (uint8_t)7; QueueEntryNum++)
    {
      /* Register the queue entry */
      if((&HandlePtr->kQueueEntryHandlePtr[QueueEntryNum] != NULL) &&
        (HandlePtr->kQueueEntryHandlePtr[QueueEntryNum].Active == (uint8_t)1))
      {
        QINR0Val = (uint32_t) 
             ((((uint32_t)HandlePtr->kQueueEntryHandlePtr[QueueEntryNum].ChannelNumber\
                   << VADC_G_QINR0_REQCHNR_Pos) &VADC_G_QINR0_REQCHNR_Msk ) |\
             (((uint32_t)HandlePtr->kQueueEntryHandlePtr[QueueEntryNum].Refill\
                   << VADC_G_QINR0_RF_Pos) &VADC_G_QINR0_RF_Msk)|\
             (((uint32_t)HandlePtr->kQueueEntryHandlePtr[QueueEntryNum].Interrupt\
                   << VADC_G_QINR0_ENSI_Pos) &VADC_G_QINR0_ENSI_Msk )     |\
             (((uint32_t)HandlePtr->kQueueEntryHandlePtr[QueueEntryNum].ExternalTrigger\
                   << VADC_G_QINR0_EXTR_Pos) & VADC_G_QINR0_EXTR_Msk))  ;
        VADCGroupPtr->QINR0 = QINR0Val;
      }
    }
    
    /* Generate a trigger event by software */
    WR_REG(VADCGroupPtr->QMR0, VADC_G_QMR0_TREV_Msk, VADC_G_QMR0_TREV_Pos,
                                                 (uint32_t)HandlePtr->kStart);
  
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function resets the ADC002 app */
status_t ADC002_Deinit(const ADC002_HandleType *HandlePtr )
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;

    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);
  
  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  { 
    /* Reset the queue input Register */
     VADCGroupPtr->QINR0 = (uint32_t)0x00000000; 
      
    /* Reset ARBPR Register */
     VADCGroupPtr->ARBPR &= (uint32_t)0x06000BB4;
  
    /* Reset QCTRL0 Register*/
    /* set write control bit and clear other bits*/
     VADCGroupPtr->QCTRL0 = (uint32_t)0x80008000;
     
    /* Flush the Queue */
     SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_FLUSH_Pos);
    
    /* Reset QMR0 Register */
    VADCGroupPtr->QMR0 = (uint32_t)0x00000000;
    
    /* Reset the source event flag */
    VADCGroupPtr->SEFCLR = (uint32_t)0x1;
    
    /* Set the App State to Uninitialized */
    HandlePtr->DynamicHandlePtr->State = ADC002_UNINITIALIZED;
  
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function clears the Event flag. */
status_t ADC002_ClearEvent(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Clear event flag */
    SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_CEV_Pos);
  
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function clears the queue entries. */
status_t ADC002_FlushQueue(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Clear the queue entries */
    SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_FLUSH_Pos);
    Status = (uint32_t)DAVEApp_SUCCESS;    
  }
  else    
  {
      ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function generates a trigger event.*/
status_t ADC002_TriggerEvent(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Generate a trigger event */
    SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_TREV_Pos);
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else    
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/*
 * This function clears the next pending valid queue entry in the
 * sequence and the event flag EV.
 */
status_t ADC002_ClearValidBit(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Generate a trigger event */
    SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_CLRV_Pos);
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else    
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/*
 * This function enables the gating.
 */
status_t ADC002_EnableGate(const ADC002_HandleType *HandlePtr, 
                                              uint8_t GateSelectVal)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    if(GateSelectVal <= (uint8_t)3)
    {
      /* Selects the gating functionality */
     WR_REG(VADCGroupPtr->QMR0, VADC_G_QMR0_ENGT_Msk, VADC_G_QMR0_ENGT_Pos,\
                                                     (uint32_t)GateSelectVal);
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else    
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/*
 * This function enables queue arbitration slot.
 */
status_t ADC002_EnableQueueArbitrationSlot(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Enables Queue Arbitration Slot */
    SET_BIT(VADCGroupPtr->ARBPR,VADC_G_ARBPR_ASEN0_Pos);    
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
      ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/*
 * This function disables queue arbitration slot.
 */
status_t ADC002_DisableQueueArbitrationSlot(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Disables Queue Arbitration Slot */
    CLR_BIT(VADCGroupPtr->ARBPR,VADC_G_ARBPR_ASEN0_Pos);    
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
      ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}
/*
 * This function selects the External trigger mode.
 */
status_t ADC002_SetExternalTriggerMode(const ADC002_HandleType *HandlePtr,
                                                                   uint8_t Mode)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;
  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if(HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    if(Mode <= (uint8_t)ADC002_TRIGGER_UPON_BOTH_EDGE)
    {
      if(Mode == (uint8_t)ADC002_NOTRIGGER)
      {
        /* Disables external trigger */
        CLR_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_ENTR_Pos);
      }
      else
      {
        /* Enables external trigger */
        SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_ENTR_Pos);      
      }   
  /*
   * Enable XTWC Bitfield so that XTMODE and XTSEL can be written
   * Selects trigger mode .
   */
      VADCGroupPtr->QCTRL0 = (uint32_t)
        ((((uint32_t)1 << VADC_G_QCTRL0_XTWC_Pos) & VADC_G_QCTRL0_XTWC_Msk)|\
        (((uint32_t)Mode<< VADC_G_QCTRL0_XTMODE_Pos) & VADC_G_QCTRL0_XTMODE_Msk)|\
        (VADCGroupPtr->QCTRL0 & (((uint32_t)0xF)<< VADC_G_QCTRL0_XTSEL_Pos)));

      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/*
 * This function enables external trigger.
 */
status_t ADC002_EnableExternalTrigger(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Enables external trigger */
    SET_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_ENTR_Pos);
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
      ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/*
 * This function disables external trigger.
 */
status_t ADC002_DisableExternalTrigger(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Disables external trigger */
    CLR_BIT(VADCGroupPtr->QMR0, VADC_G_QMR0_ENTR_Pos);
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
      ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function checks if there is valid entry in the queue. */
status_t ADC002_IsEmpty(const ADC002_HandleType *HandlePtr, 
                                                    uint8_t *VailidEntryPtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /*Checks if there is valid entry in the queue*/
    if(VailidEntryPtr != NULL)
    {
        *VailidEntryPtr = (uint8_t)RD_REG( VADCGroupPtr->QSR0, 
                          VADC_G_QSR0_EMPTY_Msk, VADC_G_QSR0_EMPTY_Pos);
        Status = (uint32_t)DAVEApp_SUCCESS;                          
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
      ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/* This function indicates number of valid entries in the queue. */
status_t ADC002_GetFillingLevel(const ADC002_HandleType *HandlePtr, 
                                                    uint8_t *FillLevelPtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
  /* Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;
  /* Status of valid entry in the queue */            
  uint8_t VailidEntry; 
  /* Fill level of queue */
  uint8_t FillLevelValue = (uint8_t)0;
  
  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /*Checks if there is valid entry in the queue*/
    if(FillLevelPtr != NULL)
    {
        FillLevelValue = (uint8_t)RD_REG( VADCGroupPtr->QSR0, 
                          VADC_G_QSR0_FILL_Msk, VADC_G_QSR0_FILL_Pos);
                          
        if(FillLevelValue == (uint8_t)0)
        {
          if(ADC002_IsEmpty(HandlePtr, &VailidEntry) == 
                                                      (uint32_t)DAVEApp_SUCCESS)
          {
          
            if(VailidEntry == (uint8_t)1)
            {
              /* If  VailidEntry==1 then queue is empty */
              *FillLevelPtr = (uint8_t)0;
              Status = (uint32_t)DAVEApp_SUCCESS;
            }
            else
            {
              /* If  VailidEntry==1 then queue has one valid entry */
              *FillLevelPtr = (uint8_t)1;
              Status = (uint32_t)DAVEApp_SUCCESS;
            }
          }
          else
          {
            Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
          }
        
        }
        else
        {
          /* Entries in the queue will be register read value plus one */
          *FillLevelPtr = FillLevelValue + (uint8_t)1;
          Status = (uint32_t)DAVEApp_SUCCESS;
        }
        

    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
      ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
    
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/* This function gets the current level of the selected gate input */
status_t ADC002_GetGateLevel(const ADC002_HandleType *HandlePtr, 
                                                    uint8_t *GateLevelPtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Get the input level of selected gate input */
    if(GateLevelPtr != NULL)
    {
      *GateLevelPtr = (uint8_t)RD_REG( VADCGroupPtr->QSR0, 
                          VADC_G_QSR0_REQGT_Msk, VADC_G_QSR0_REQGT_Pos);
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/*
 * This function indicates whether an event has been detected while at
 * least one valid entry has been in the queue. 
 */
status_t ADC002_IsEventDetected(const ADC002_HandleType *HandlePtr, 
                                                    uint8_t *EventPtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Get the event detection. */
    if(EventPtr != NULL)
    {
        *EventPtr = (uint8_t)RD_REG( VADCGroupPtr->QSR0, 
                                    VADC_G_QSR0_EV_Msk, VADC_G_QSR0_EV_Pos);
        Status = (uint32_t)DAVEApp_SUCCESS;                                    
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/*
 * This function makes the entry to the queue request
 */
status_t ADC002_AddQueueEntry(const ADC002_HandleType *HandlePtr, 
                               const ADC002_QueueEntryHandleType *QueueEntryPtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;
  uint32_t QINR0Val;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Register the queue entry */
    if((QueueEntryPtr != NULL) && (QueueEntryPtr->ChannelNumber <= (uint8_t)7) &&\
              (HandlePtr->kActiveChannels[QueueEntryPtr->ChannelNumber] == (uint8_t)1))
    {
      QINR0Val = (uint32_t)
        (((uint32_t)QueueEntryPtr->ChannelNumber << VADC_G_QINR0_REQCHNR_Pos) & VADC_G_QINR0_REQCHNR_Msk)  |\
        (((uint32_t)QueueEntryPtr->Refill << VADC_G_QINR0_RF_Pos) & VADC_G_QINR0_RF_Msk)|\
        (((uint32_t)QueueEntryPtr->Interrupt << VADC_G_QINR0_ENSI_Pos)& VADC_G_QINR0_ENSI_Msk)|\
        (((uint32_t)QueueEntryPtr->ExternalTrigger << VADC_G_QINR0_EXTR_Pos) & VADC_G_QINR0_EXTR_Msk);
                  
      VADCGroupPtr->QINR0 = QINR0Val;
      
      Status = (uint32_t)DAVEApp_SUCCESS;               
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/*
 * This function sets standard conversion mode.
 */
status_t ADC002_SetConversionMode(const ADC002_HandleType *HandlePtr,
                                                        uint8_t ConversionMode)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    if(HandlePtr->kGroup_HandlePtr != NULL)
    {
      /* Set standard conversion mode */
      Status = (uint32_t)ADCGROUP001_SetGroupClass0ConvMode(
                           HandlePtr->kGroup_HandlePtr,ConversionMode);
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/*
 * This function sets sample time for standard conversion.
 */
status_t ADC002_SetSampleTime(const ADC002_HandleType *HandlePtr,
                                                            uint8_t SampleTime)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    if(HandlePtr->kGroup_HandlePtr != NULL)
    {
      /* Set sample time for standard conversion. */
      Status =(uint32_t)ADCGROUP001_SetGroupClass0SampleTime(
                            HandlePtr->kGroup_HandlePtr,SampleTime);
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/*
 * This function sets EMUX conversion mode.
 */
status_t ADC002_SetEMUXConversionMode(const ADC002_HandleType *HandlePtr,
                                                      uint8_t ConversionMode)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    if(HandlePtr->kGroup_HandlePtr != NULL)
    {
      /* Set EMUX conversion mode */
      Status = (uint32_t)ADCGROUP001_SetGroupClass0EmuxConvMode(
                        HandlePtr->kGroup_HandlePtr,ConversionMode);
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/*
 * This function sets sample time for EMUX conversion.
 */
status_t ADC002_EMUXSetSampleTime(const ADC002_HandleType *HandlePtr,
                                                            uint8_t SampleTime)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    if(HandlePtr->kGroup_HandlePtr != NULL)
    {
      /* Set sample time for EMUX conversion*/
      Status = (uint32_t)ADCGROUP001_SetGroupClass0EmuxSampleTime(
                              HandlePtr->kGroup_HandlePtr,SampleTime);
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function gets the current level of the selected gate input */
status_t ADC002_GetQueueStage0Entry(const ADC002_HandleType *HandlePtr, 
                                                    uint32_t *EntryPtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Get the queue stage 0 entry 0 */
    if(EntryPtr != NULL)
    {
        *EntryPtr = (uint32_t)VADCGroupPtr->Q0R0;
        Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function gets the current level of the selected gate input */
status_t ADC002_GetQueueBackupStageEntry(const ADC002_HandleType *HandlePtr, 
                                                    uint32_t *EntryPtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Get the queue backup stage entry */
    if(EntryPtr != NULL)
    {
      *EntryPtr = (uint32_t)VADCGroupPtr->QBUR0;
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function gets the Event flag. */
status_t ADC002_GetSourceEventFlag(const ADC002_HandleType *HandlePtr, 
                                                            uint8_t *Flagptr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    if(Flagptr != NULL)
    {
      /* Gets event flag */
      *Flagptr = (uint8_t)RD_REG( VADCGroupPtr->SEFLAG, 
                               VADC_G_SEFLAG_SEV0_Msk, VADC_G_SEFLAG_SEV0_Pos);
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADC002_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/* This function sets the Event flag. */
status_t ADC002_SetSourceEventFlag(const ADC002_HandleType *HandlePtr)
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
    /* Sets event flag */
    SET_BIT(VADCGroupPtr->SEFLAG, VADC_G_SEFLAG_SEV0_Pos);
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}


/* This function clears the source Event flag. */
status_t ADC002_ClearSourceEventFlag(const ADC002_HandleType *HandlePtr) 
{
  status_t Status = (uint32_t)ADC002_OPER_NOT_ALLOWED_ERROR;
    /*Pointer to the VADC Group register structure */
  VADC_G_TypeDef *VADCGroupPtr = HandlePtr->VADCGroupPtr;
  FUNCTION_ENTRY(GID_ADC002, ADC002_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandlePtr->State == ADC002_INITIALIZED)
  {
      /* Sets event flag */
      SET_BIT(VADCGroupPtr->SEFCLR, VADC_G_SEFCLR_SEV0_Pos);
      Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADC002, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADC002, ADC002_FUNCTION_EXIT);
  return Status;
}

/**
 * @endcond
 */
/*CODE_BLOCK_END*/

