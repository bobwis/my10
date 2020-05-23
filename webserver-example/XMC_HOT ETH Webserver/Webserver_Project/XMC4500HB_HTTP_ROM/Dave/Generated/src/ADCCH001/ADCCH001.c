
/*CODE_BLOCK_BEGIN[ADCCH001.c]*/
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
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : 8 August 2012                                        **
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
 * @file ADCCH001.c
 *
 * @brief   This file contains the implementation of all public and private functions of the
 *          ADCCH001 App.   
 */

/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include <DAVE3.h>

/**
 * @cond INTERNAL_DOCS
 */



/*************************************************************************
 *                 Private Function declarations
 ***************************************************************************/

/**
 * @brief This function initializes ADC channel and result registers \n
 * @param[in] HandlePtr Handle of the ADCCH001 App
 * @return void
 * <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 */
static void ADCCH001_lInit(const ADCCH001_HandleType* HandlePtr);


/********************************************************************************
 *                 LOCAL FUNCTIONS DEFINITIONS
 **********************************************************************************/
/**
 * This function initializes ADC channel and result registers as per UI configurations. 
 */
static void ADCCH001_lInit(const ADCCH001_HandleType* HandlePtr)
{
  VADC_G_TypeDef* GroupPtr = HandlePtr->ADCGrPtr;
  uint8_t Index = (uint8_t)0;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCCH001_UNINITIALIZED))
  {
    /* Priority Channel */
    WR_REG( GroupPtr->CHASS, 
            ((uint32_t)0x01 << HandlePtr->kChannelNo),
            HandlePtr->kChannelNo,
            (uint32_t)HandlePtr->kPrioChannel
           );    
    /* Input class */
    WR_REG( GroupPtr->CHCTR[HandlePtr->kChannelNo],
            VADC_G_CHCTR_ICLSEL_Msk,
            VADC_G_CHCTR_ICLSEL_Pos,
            (uint32_t)HandlePtr->kIpClassSel
           );
    /* Channel event mode */
    WR_REG( GroupPtr->CHCTR[HandlePtr->kChannelNo],
            VADC_G_CHCTR_CHEVMODE_Msk,
            VADC_G_CHCTR_CHEVMODE_Pos,
            (uint32_t)HandlePtr->kChEvtmode
           );    
    /* reference input selection */
    WR_REG( GroupPtr->CHCTR[HandlePtr->kChannelNo],
            VADC_G_CHCTR_REFSEL_Msk,
            VADC_G_CHCTR_REFSEL_Pos,
            (uint32_t)HandlePtr->kRefInput
           );
    /* XMC4500: EMUXCSS is not present.  */
    if(HandlePtr->kExtMuxControl == (uint8_t)1)
    {
      /*WR_REG( GroupPtr->EMUXCTR,
              VADC_G_EMUXCTR_EMXCSS_Msk,
              VADC_G_EMUXCTR_EMXCSS_Pos,
              (0x01)
             );     */
      WR_REG( GroupPtr->EMUXCTR,
              VADC_G_EMUXCTR_EMUXCH_Msk,
              VADC_G_EMUXCTR_EMUXCH_Pos,
              (uint32_t)(HandlePtr->kChannelNo)
             );  
    }
    /*Configure result registers if Fast Compare Mode is not selected */
    if(HandlePtr->kCompareMode == (uint8_t)0)
    {
      /* Upper and Lower Boundary Select */ 
      WR_REG( GroupPtr->CHCTR[HandlePtr->kChannelNo],
              ((uint32_t)0xF << VADC_G_CHCTR_BNDSELL_Pos),
              VADC_G_CHCTR_BNDSELL_Pos,
              (uint32_t)HandlePtr->kBoundarySel
             ); 
      /*Result Alignment */
      WR_REG( GroupPtr->CHCTR[HandlePtr->kChannelNo],
              VADC_G_CHCTR_RESPOS_Msk,
              VADC_G_CHCTR_RESPOS_Pos,
              (uint32_t)HandlePtr->kResultControl
             );
      /* Data modification mode */
      WR_REG( GroupPtr->RCR[HandlePtr->kStartResultRegNo],
              ((uint32_t)0x3F << VADC_G_RCR_DRCTR_Pos),
              VADC_G_RCR_DRCTR_Pos,
              (uint32_t)HandlePtr->kDataModification
             );
      /* Wait for read mode */
      WR_REG( GroupPtr->RCR[HandlePtr->kStartResultRegNo],
              VADC_G_RCR_WFR_Msk,
              VADC_G_RCR_WFR_Pos,
              (uint32_t)HandlePtr->kWaitForRead
             );
  /* result interrupt */    
      WR_REG( GroupPtr->RCR[HandlePtr->kEndResultRegNo],
              VADC_G_RCR_SRGEN_Msk,
              VADC_G_RCR_SRGEN_Pos,
              (uint32_t)HandlePtr->kResultEvtEnable
             );
  /* Setting FEN bit in all result registers except start result register */    
      if(HandlePtr->kFIFOEnable == (uint8_t)1)
      {
        for(Index = (HandlePtr->kEndResultRegNo); Index <= (HandlePtr->kStartResultRegNo -(uint8_t)1); Index++)
        {
           WR_REG( GroupPtr->RCR[Index],
                   VADC_G_RCR_FEN_Msk,
                   VADC_G_RCR_FEN_Pos,
                   (uint32_t)0x1
                 );
        }
      }
    }
/* Write compare value in the result register for the Fast Compare Mode */    
    else
    {
      WR_REG( GroupPtr->RES[HandlePtr->kStartResultRegNo],
              VADC_G_RES_RESULT_Msk,
              VADC_G_RES_RESULT_Pos,
              (uint32_t)(HandlePtr->kResultCompVal)
            );      
    }
    /* Set boundary flag for all the advanced result registers */
    if(HandlePtr->kBoundaryFlagEnable == (uint8_t)1)
    {
      WR_REG( GroupPtr->BFL,
              ((uint32_t)0x01 << (HandlePtr->kStartResultRegNo + (uint8_t)16)),
              (HandlePtr->kStartResultRegNo + (uint8_t)16),
              (uint32_t)(0x1)
            );
    }
    /* change the state to the Initialized */
    HandlePtr->DynamicHandlePtr->State = ADCCH001_INITIALIZED;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)ADCCH001_OPERATION_NOT_ALLOWED, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
}

/******************************************************************************************************
 *                 API DEFINITION
 *******************************************************************************************************/

/**
 * This function initializes all instances of the ADCCH001 App
 */
void ADCCH001_Init(void)
{
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);  
  ADCGLOB001_Init();
/* Call the local function with the handle pointer for each instance */
  ADCCH001_lInit(&ADCCH001_Handle0);
  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
}

/**
 * This function resets all the channel and result registers. 
 */
status_t ADCCH001_Deinit(const ADCCH001_HandleType* HandlePtr)
{
  VADC_G_TypeDef* GroupPtr = HandlePtr->ADCGrPtr;
  uint8_t Index;
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCCH001_INITIALIZED))
  {
    GroupPtr->CHCTR[HandlePtr->kChannelNo] = (uint32_t)0x00;
    WR_REG( GroupPtr->EMUXCTR, 
            VADC_G_EMUXCTR_EMUXCH_Msk,
            VADC_G_EMUXCTR_EMUXCH_Pos,
            (uint32_t)0x00
          );
  
    for(Index = (HandlePtr->kEndResultRegNo); Index <= (HandlePtr->kStartResultRegNo); Index++)
    {
      GroupPtr->RCR[Index] = (uint32_t)0x00;
      GroupPtr->RES[Index] = (uint32_t)0x00;
    }
    if(HandlePtr->kBoundaryFlagEnable == (uint8_t)1)
    {
      CLR_BIT(GroupPtr->BFL, (((uint32_t)16 + (uint32_t)HandlePtr->kStartResultRegNo)));
    }
    HandlePtr->DynamicHandlePtr->State = ADCCH001_UNINITIALIZED;
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }
  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function assigns the alias channel number
 */
status_t ADCCH001_SetAlias(const ADCCH001_HandleType* HandlePtr, uint8_t ChannelNo)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((ChannelNo > (uint8_t)7))
  {
    Status = (uint32_t)ADCCH001_INVALID_PARAM;
    ERROR(GID_ADCCH001, (uint8_t)ADCCH001_INVALID_PARAM, 0, (uint8_t*) NULL);    
  }
  else if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      ((HandlePtr->kChannelNo == (uint8_t)0) || (HandlePtr->kChannelNo == (uint8_t)1)))
  {
    HandlePtr->ADCGrPtr->ALIAS &= ~((uint32_t)0x1F << (HandlePtr->kChannelNo * (uint8_t)8));
    HandlePtr->ADCGrPtr->ALIAS |= ((uint32_t)ChannelNo << (HandlePtr->kChannelNo * (uint8_t)8));
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);  
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}



/**
 * This function enables the boundary flag for result register 0, 1, 2 or 3.
 */
status_t ADCCH001_EnableBoundaryFlag(const ADCCH001_HandleType* HandlePtr, uint8_t FlagNo)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((FlagNo > (uint8_t)3))
  {
    Status = (uint32_t)ADCCH001_INVALID_PARAM;
    ERROR(GID_ADCCH001, (uint8_t)ADCCH001_INVALID_PARAM, 0, (uint8_t*) NULL);    
  }
  else if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED))
  {
    SET_BIT(HandlePtr->ADCGrPtr->BFL, ((uint32_t)FlagNo + (uint32_t)16));
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);  
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function disables the boundary flag for result register 0, 1, 2 or 3.
 */
status_t ADCCH001_DisableBoundaryFlag(const ADCCH001_HandleType* HandlePtr, uint8_t FlagNo)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  
  if((FlagNo > (uint8_t)3))
  {
    Status = (uint32_t)ADCCH001_INVALID_PARAM;
    ERROR(GID_ADCCH001, (uint8_t)ADCCH001_INVALID_PARAM, 0, (uint8_t*) NULL);    
  }
  else if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED))
  {
    CLR_BIT(HandlePtr->ADCGrPtr->BFL, ((uint32_t)FlagNo + (uint32_t)16));
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);  
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;  
}


/**
 * This function selects the input class for the channel. 
 */
status_t ADCCH001_SelectInputClass(const ADCCH001_HandleType* HandlePtr, ADCCH001_InputClassType Class)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  
  if((Class > (ADCCH001_InputClassType)3))
  {
    Status = (uint32_t)ADCCH001_INVALID_PARAM;
    ERROR(GID_ADCCH001, (uint8_t)ADCCH001_INVALID_PARAM, 0, (uint8_t*) NULL);    
  }  
  else if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) && 
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    WR_REG( HandlePtr->ADCGrPtr->CHCTR[HandlePtr->kChannelNo], 
            VADC_G_CHCTR_ICLSEL_Msk,
            VADC_G_CHCTR_ICLSEL_Pos,
            (uint32_t)Class
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}


/**
 * This function configures the channel event mode to generate the channel interrupt
 */
status_t ADCCH001_SelectChEvtMode(const ADCCH001_HandleType* HandlePtr, ADCCH001_ChanEvtModeType Mode)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((Mode > (ADCCH001_ChanEvtModeType)3))
  {
    Status = (uint32_t)ADCCH001_INVALID_PARAM;
    ERROR(GID_ADCCH001, (uint8_t)ADCCH001_INVALID_PARAM, 0, (uint8_t*) NULL);    
  }   
  else if(HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED)
  {
    WR_REG( HandlePtr->ADCGrPtr->CHCTR[HandlePtr->kChannelNo], 
            VADC_G_CHCTR_CHEVMODE_Msk,
            VADC_G_CHCTR_CHEVMODE_Pos,
            (uint32_t)Mode
          );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function selects the upper boundary for limit checking function. 
 * This is the upper delta for Fast Compare Mode.
 */
status_t ADCCH001_SelectUpperBoundary(const ADCCH001_HandleType* HandlePtr, ADCCH001_BoundaryType UBoundary)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((UBoundary > (ADCCH001_BoundaryType)3))
  {
    Status = (uint32_t)ADCCH001_INVALID_PARAM;
    ERROR(GID_ADCCH001, (uint8_t)ADCCH001_INVALID_PARAM, 0, (uint8_t*) NULL);    
  }   
  else if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    WR_REG( HandlePtr->ADCGrPtr->CHCTR[HandlePtr->kChannelNo], 
            VADC_G_CHCTR_BNDSELU_Msk,
            VADC_G_CHCTR_BNDSELU_Pos,
            (uint32_t)UBoundary
          );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT); 
  return Status;
}

/**
 * This function selects the lower boundary for limit checking function. 
 * This is the lower delta for Fast Compare Mode.
 */
status_t ADCCH001_SelectLowerBoundary(const ADCCH001_HandleType* HandlePtr, ADCCH001_BoundaryType LBoundary)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((LBoundary > (ADCCH001_BoundaryType)3))
  {
    Status = (uint32_t)ADCCH001_INVALID_PARAM;
    ERROR(GID_ADCCH001, (uint8_t)ADCCH001_INVALID_PARAM, 0, (uint8_t*) NULL);    
  }   
  else if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    WR_REG( HandlePtr->ADCGrPtr->CHCTR[HandlePtr->kChannelNo], 
            VADC_G_CHCTR_BNDSELL_Msk,
            VADC_G_CHCTR_BNDSELL_Pos,
            (uint32_t)LBoundary
          );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function returns the result of the normal mode ADC conversion. 
 */
status_t ADCCH001_GetResult(const ADCCH001_HandleType* HandlePtr, uint16_t* ResultPtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  VADC_G_TypeDef* GroupPtr = HandlePtr->ADCGrPtr;
  uint32_t TempResult;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    TempResult = GroupPtr->RES[HandlePtr->kEndResultRegNo];
    /* If valid flag is set */
    if(((TempResult & VADC_G_RES_VF_Msk) >> VADC_G_RES_VF_Pos) == (uint32_t)1)
    {
      HandlePtr->DynamicHandlePtr->Result = 
          (uint16_t)(TempResult & VADC_G_RES_RESULT_Msk);
      *ResultPtr = HandlePtr->DynamicHandlePtr->Result;
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    /* If data is old, then send error as invalid result */
    else
    {
      *ResultPtr = HandlePtr->DynamicHandlePtr->Result;
      Status = (uint32_t)ADCCH001_INVALID_RESULT;
      ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);
    }
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function returns the result of the fast compare ADC conversion. 
 */
status_t ADCCH001_GetFastCompareResult(const ADCCH001_HandleType* HandlePtr, uint8_t* ResultPtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  VADC_G_TypeDef* GroupPtr = HandlePtr->ADCGrPtr;
  uint32_t TempResult;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)1))
  {
    TempResult = GroupPtr->RES[HandlePtr->kEndResultRegNo];
    /* If valid flag is set */
    if(((TempResult & VADC_G_RES_VF_Msk) >> VADC_G_RES_VF_Pos) == (uint32_t)1)
    {
      HandlePtr->DynamicHandlePtr->FastCompResult = (uint8_t)RD_REG(TempResult, 
                                                    VADC_G_RES_FCR_Msk,
                                                    VADC_G_RES_FCR_Pos
                                                   );
      *ResultPtr = HandlePtr->DynamicHandlePtr->FastCompResult;
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    /* If data is old, then send error as invalid result */
    else
    {
      *ResultPtr = HandlePtr->DynamicHandlePtr->FastCompResult;
      Status = (uint32_t)ADCCH001_INVALID_RESULT;
      ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);
    }
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function sets the compare value for the Fast Compare Mode. 
 * Compare value should 10-bit value.
 */
status_t ADCCH001_SetCompareValue(const ADCCH001_HandleType* HandlePtr, uint16_t CompVal)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if(CompVal > (uint16_t)0x3FF)
  {
    Status = (uint32_t)ADCCH001_INVALID_PARAM;
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL); 
  }
  else if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      ((HandlePtr->kCompareMode == (uint8_t)1)))
  {
    WR_REG( HandlePtr->ADCGrPtr->RES[HandlePtr->kStartResultRegNo], 
            VADC_G_RES_RESULT_Msk,
            VADC_G_RES_RESULT_Pos,
            ((uint32_t)CompVal << (uint8_t)2)
          );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function enables the channel as a priority channel. 
 */
status_t ADCCH001_EnablePriorityChannel(const ADCCH001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED))
  {
    SET_BIT(HandlePtr->ADCGrPtr->CHASS, (HandlePtr->kChannelNo));
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;  
}

/**
 * This function disables the channel as a priority channel. 
 */
status_t ADCCH001_DisablePriorityChannel(const ADCCH001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED))
  {
    CLR_BIT(HandlePtr->ADCGrPtr->CHASS, (HandlePtr->kChannelNo));  
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;  
}

/**
 * This function enables the  Result event. 
 */
status_t ADCCH001_EnableResultEvt(const ADCCH001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    SET_BIT( HandlePtr->ADCGrPtr->RCR[HandlePtr->kEndResultRegNo],
             VADC_G_RCR_SRGEN_Pos
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function disables the  Result event. 
 */
status_t ADCCH001_DisableResultEvt(const ADCCH001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    CLR_BIT( HandlePtr->ADCGrPtr->RCR[HandlePtr->kEndResultRegNo],
             VADC_G_RCR_SRGEN_Pos
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}


/**
 * This function checks whether Result event flag is set.
 */
status_t ADCCH001_GetResultEvtFlag(const ADCCH001_HandleType* HandlePtr, uint8_t* EvtStatus)
{

  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    *EvtStatus = (uint8_t)RD_REG( HandlePtr->ADCGrPtr->REFLAG, 
                        ((uint32_t)0x01 << HandlePtr->kEndResultRegNo), 
                        (uint32_t)HandlePtr->kEndResultRegNo
                 );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function checks whether Channel event flag is set.
 */
status_t ADCCH001_GetChannelEvtFlag(const ADCCH001_HandleType* HandlePtr, uint8_t* EvtStatus)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if(HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED)
  {
    *EvtStatus = (uint8_t)RD_REG(HandlePtr->ADCGrPtr->CEFLAG, 
                        ((uint32_t)0x01 << HandlePtr->kChannelNo), 
                        (uint32_t)HandlePtr->kChannelNo
                 );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This will set the result event flag through software.
 */
status_t ADCCH001_SetResultEvtFlag(const ADCCH001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    SET_BIT( HandlePtr->ADCGrPtr->REFLAG, 
             HandlePtr->kEndResultRegNo
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This will set the channel event flagv through software
 */
status_t ADCCH001_SetChannelEvtFlag(const ADCCH001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if(HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED)
  {
    SET_BIT( HandlePtr->ADCGrPtr->CEFLAG, 
             HandlePtr->kChannelNo
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This will clear the pending result event flag
 */
status_t ADCCH001_ClearResultEvtFlag(const ADCCH001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    SET_BIT( HandlePtr->ADCGrPtr->REFCLR, 
             HandlePtr->kEndResultRegNo
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This will clear the pending channel event flag
 */
status_t ADCCH001_ClearChannelEvtFlag(const ADCCH001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);
  if(HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED)
  {
    SET_BIT( HandlePtr->ADCGrPtr->CEFCLR, 
             HandlePtr->kChannelNo
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This function slects the Broken Wire Detection Channel. 
 */
status_t ADCCH001_SetBWDChannel(const ADCCH001_HandleType* HandlePtr, ADCCH001_BWDType BWDChannel)
{
  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    WR_REG( HandlePtr->ADCGrPtr->CHCTR[HandlePtr->kChannelNo], 
            VADC_G_CHCTR_BWDCH_Msk,
            VADC_G_CHCTR_BWDCH_Pos,
            (uint32_t)BWDChannel
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This will enable the Broken Wire Detection feature.
 */
status_t ADCCH001_EnableBWD(const ADCCH001_HandleType* HandlePtr)
{

  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    SET_BIT( HandlePtr->ADCGrPtr->CHCTR[HandlePtr->kChannelNo], 
             VADC_G_CHCTR_BWDEN_Pos
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This will disable the Broken Wire Detection feature.
 */
status_t ADCCH001_DisableBWD(const ADCCH001_HandleType* HandlePtr)
{

  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
    CLR_BIT( HandlePtr->ADCGrPtr->CHCTR[HandlePtr->kChannelNo], 
             VADC_G_CHCTR_BWDEN_Pos
           );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * This will enable wait for read mode of the result register
 */
status_t ADCCH001_EnableWaitForRead(const ADCCH001_HandleType* HandlePtr)
{

  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
      WR_REG( HandlePtr->ADCGrPtr->RCR[HandlePtr->kStartResultRegNo],
              VADC_G_RCR_WFR_Msk,
              VADC_G_RCR_WFR_Pos,
              (uint32_t)0x1
             );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}


/**
 * This will disable wait for read mode of the result register
 */
status_t ADCCH001_DisableWaitForRead(const ADCCH001_HandleType* HandlePtr)
{

  status_t Status = (uint32_t)ADCCH001_OPERATION_NOT_ALLOWED;
  FUNCTION_ENTRY(GID_ADCCH001, (uint32_t)ADCCH001_FUN_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State != ADCCH001_UNINITIALIZED) &&
      (HandlePtr->kCompareMode == (uint8_t)0))
  {
      WR_REG( HandlePtr->ADCGrPtr->RCR[HandlePtr->kStartResultRegNo],
              VADC_G_RCR_WFR_Msk,
              VADC_G_RCR_WFR_Pos,
              (uint32_t)0x0
             );
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCCH001, (uint8_t)Status, 0, (uint8_t*) NULL);    
  }

  FUNCTION_EXIT(GID_ADCCH001, (uint32_t)ADCCH001_FUN_EXIT);  
  return Status;
}

/**
 * @endcond
 */


