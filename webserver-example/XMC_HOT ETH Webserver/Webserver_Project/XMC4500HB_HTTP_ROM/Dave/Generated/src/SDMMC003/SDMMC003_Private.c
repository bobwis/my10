

/*CODE_BLOCK_BEGIN[SDMMC003_Private.c]*/

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
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Oct 1, 2012                                            **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials    Name                                                           **
** ---------------------------------------------------------------------------**
** SK          App Developer                                                  **
*******************************************************************************/


/**
 * @file   SDMMC003_Private.c
 *
 * @App Version SDMMC003 <1.0.14>
 *
 * @brief  This file contains definitions of all private type definitions and
 * functions of SDMMC LLD App.
 *
 * Revision History
 * 22 March 2012  v1.0.0    Initial version
 * 3 Aug 2012     v1.0.12   Erase optimizations  introduced.
 *                          Make File System(MKFS) through software issue fixed. 
 * 1 Oct 2012     v1.0.14   Delays reduced.
 *                          Removed RTOS specific code. 
 */
/*******************************************************************************
 *                            INCLUDE FILES                                   **
 ******************************************************************************/
#include "../../inc/SDMMC003/SDMMC003_Conf.h"
#include <DAVE3.h>
#include "../../inc/SDMMC003/SDMMC003_Private.h"



/**
 * @cond INTERNAL_DOCS
 */

/*******************************************************************************
 **                      Global Variable Definitions                          **
 *******************************************************************************/
extern volatile SDMMC003_HandleType SDMMC003_Handle ;
/**  Card Information Structure */
SDMMC003_CardInfoType SDMMC003_CardInfo ;
/** Structure containing the Interrupt related variables */
volatile SDMMC003_InterruptContext SDMMC003_ISRContext;

/* Dummy Variable to store return status */
status_t SDMMC003_ReturnStatus;

#if SDMMC_UVP_TEST
  extern Test_TriggerInterruptType Test_TriggerInterrupt;
#endif /* SDMMC_UVP_TEST */

/** Stores Normal Interrupt Status Register */
volatile  uint16_t NormalIntStatus;
/** Stores Error Interrupt Status Register */
volatile  uint16_t ErrorIntStatus;

/*******************************************************************************
 *                                ARRAYS                                      **
 ******************************************************************************/
/**
 * Command Structure defining SD, MMC and Application specific commands 
 */
const SDMMC003_CommandType SDMMC003_Command[40] =
{
  /* SD  Card Commands */
  { 0,0,0,0,0,0,SDMMC003_GO_IDLE_STATE,0 },     /*0*/
  { 1,0,1,0,0,0,SDMMC003_ALL_SEND_CID,0 },      /*1*/
  { 2,0,1,1,0,0,SDMMC003_SEND_RELATIVE_ADDR,0}, /*2*/
  { 0,0,0,0,0,0,SDMMC003_SET_DSR,0 },           /*3*/
  { 2,0,1,1,1,0,SDMMC003_SWITCH_FUNC,0},        /*4*/
  { 3,0,1,1,0,0,SDMMC003_SELECT_DESELECT_CARD,0},/*5*/
  { 2,0,1,1,0,0,SDMMC003_SD_SEND_IF_COND,0},    /*6*/
  { 1,0,1,0,0,0,SDMMC003_SEND_CSD,0},           /*7*/
  { 1,0,1,0,0,0,SDMMC003_SEND_CID,0},           /*8*/
  { 3,0,1,1,0,0,SDMMC003_STOP_TRANSMISSION,0},  /*9*/
  { 2,0,1,1,0,0,SDMMC003_SEND_STATUS,0 },       /*10*/
  { 0,0,0,0,0,0,SDMMC003_GO_INACTIVE_STATE,0},  /*11*/
  { 2,0,1,1,0,0,SDMMC003_SET_BLOCKLEN,0},       /*12*/
  { 2,0,1,1,1,0,SDMMC003_READ_SINGLE_BLOCK,0},  /*13*/
  { 2,0,1,1,1,0,SDMMC003_READ_MULTIPLE_BLOCK,0},/*14*/
  { 2,0,1,1,1,0,SDMMC003_WRITE_BLOCK,0 },       /*15*/
  { 2,0,1,1,1,0,SDMMC003_WRITE_MULTIPLE_BLOCK,0},/*16*/
  { 2,0,1,1,1,0,SDMMC003_PROGRAM_CSD,0},        /*17*/
  { 2,0,1,1,0,0,SDMMC003_SET_WRITE_PROT,0},     /*18*/
  { 2,0,1,1,0,0,SDMMC003_CLR_WRITE_PROT,0},     /*19*/
  { 2,0,1,1,1,0,SDMMC003_SEND_WRITE_PROT,0},    /*20*/
  { 2,0,1,1,0,0,SDMMC003_ERASE_WR_BLK_START,0}, /*21*/
  { 2,0,1,1,0,0,SDMMC003_ERASE_WR_BLK_END,0},   /*22*/
  { 3,0,1,1,0,0,SDMMC003_ERASE,0},              /*23*/
  { 2,0,1,1,1,0,SDMMC003_LOCK_UNLOCK,0},        /*24*/
  { 2,0,1,1,0,0,SDMMC003_APP_CMD,0},            /*25*/
  { 2,0,1,1,1,0,SDMMC003_GEN_CMD,0},            /*26*/
  /*  End of SD card commands */
  /* Start of Application Specific commands */
  { 2,0,1,1,0,0,SDMMC003_SET_BUS_WIDTH,0},      /*27*/
  { 2,0,1,1,1,0,SDMMC003_SD_STATUS,0},          /*28*/
  { 2,0,1,1,1,0,SDMMC003_SEND_NUM_WR_BLOCKS,0}, /*29*/
  { 2,0,1,1,0,0,SDMMC003_SET_WR_BLK_ERASE_COUNT,0},/*30*/
  { 2,0,0,0,0,0,SDMMC003_SD_SEND_OP_COND,0},    /*31*/
  { 2,0,1,1,0,0,SDMMC003_SET_CLR_CARD_DETECT,0},/*32*/
  { 2,0,1,1,1,0,SDMMC003_SEND_SCR,0 },          /*33*/
  /* End of Application Specific Commands */
  /* Start of SDMMC_MMC Card  specific commands */
  { 2,0,0,1,0,0,SDMMC003_MMC_SEND_OP_COND,0},   /*34*/
  { 3,0,1,1,0,0,SDMMC003_MMC_SLEEP_AWAKE,0},    /*35*/
  { 3,0,1,1,0,0,SDMMC003_SWITCH_FUNC,0},        /*36*/
  { 2,0,1,1,1,0,SDMMC003_MMC_SEND_EXT_CSD,0},   /*37*/
  { 2,0,1,1,0,0,SDMMC003_ERASE_GROUP_START,0},  /*38*/
  { 2,0,1,1,0,0,SDMMC003_ERASE_GROUP_END,0},    /*39*/
  /* End of SDMMC_MMC  Card specific commands */
};

/* Sd Card's Command Index Hash Table having index of the command structure
 * Array Index 0-57 is for SD general Commands and Array Index 58-64 is for
 * Application Specific Commands.
 */
const uint8_t SDMMC003_SDHashTable[65] =
{
  0, 0xFF,1,2,3,0xFF,4,5,6,7,8,0xFF,9,10,0xFF,\
  11, 12, 13, 14,0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
  15, 16, 0xFF, 17, 18, 19, 20, 0xFF, 21, 22,\
  0xFF, 0xFF, 0xFF, 0xFF, 23, 0xFF, 0xFF, 0xFF,\
  24, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 25, 26, 0xFF, \
  27, 28, 29,30,31,32,33
};

#if SDMMC_SUPPORT_MMC_CARD
const uint8_t SDMMC003_MMCHashTable[64] =
{
  0,34,1,2,3,35,36,5,37,7,8,0xFF,9,10,0xFF,11,12,\
  13,14,0xFF,0xFF,0xFF,0xFF,0xFF,15,16,0xFF,17,\
  18,19,20,0xFF,0xFF,0xFF,0xFF,38,39,0xFF,23,\
  0xFF,0xFF,0xFF,24,0xFF,0xFF,0xFF,0xFF,0xFF,\
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,25,26,0xFF,\
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};
#endif

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*<<<DD_SDMMC_nonAPI_1>>> */
/*
 * This function resets the Host Controller's register depending on the
 * parameter passed.
 */
status_t SDMMC003_lReset( uint8_t Reset )
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  handle_t TimerId;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  SDMMC->SW_RESET =  (SDMMC->SW_RESET | Reset);
  /* The Host Controller takes some time to complete software reset*/
  /* Wait till host controller clears each bit */
/* <<<DD_SDMMC_nonAPI_1_1>>>*/
  TimerId = SDMMC003_lStartTimer(SDMMC003_RESET_DELAY);
  if(0 == TimerId)
  {
    Status = (uint32_t) SDMMC003_START_TIMER_FAILED;
    ERROR(GID_SDMMC00x, Status, 0, NULL);    
  }
  else
  {
    do
    {
      if (SDMMC003_Handle.TimerExpire == 0)
      {
        Status = (uint32_t)SDMMC003_TIMEOUT_OCCURED;
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }
    } while (SDMMC->SW_RESET & Reset);
    SDMMC003_lStopTimer(TimerId);
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}
/* <<<DD_SDMMC_nonAPI_2>>> */
/*
 * This function clears the card related structures and stops the SD clock.
 */
void SDMMC003_lCardCleanUp()
{
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  memset((void*)&SDMMC003_CardInfo,0,sizeof(SDMMC003_CardInfo));
  SDMMC003_Handle.CardType = 0;
  SDMMC003_Handle.f8 = 0;
  SDMMC003_Handle.CommandInterruptError = SDMMC003_ERROR;
  SDMMC003_Handle.DataInterruptError = SDMMC003_ERROR;
  SDMMC003_Handle.ErrorRecoveryStatus = SDMMC003_ERROR;
  SDMMC003_Handle.TransferInterruptError = SDMMC003_ERROR;
  SDMMC003_Handle.State  = 0;
  /* Stop the SD Clock Enable */
  CLR_BIT( SDMMC->CLOCK_CTRL,SDMMC_CLOCK_CTRL_SDCLOCK_EN_Pos  );
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
}

/* <<<DD_SDMMC_nonAPI_3>>> */
/*
 * This function checks whether the CMD and DATA lines are free before issuing
 * any command.
 */
status_t SDMMC003_lCheckDatCmdline(const SDMMC003_CommandType *CommandPtr)
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
#if SDMMC_UVP_TEST
    if( Test_TriggerInterrupt.Trigger_DataCmdLineBusy == TRUE)
    {
      Status = (uint32_t)SDMMC003_CMD_LINE_BUSY;
      break;
    }
#endif
/* Read from Present state register to Check Cmd line is free */
/* <<<DD_SDMMC_nonAPI_3_1>>> */
    if ( SDMMC->PRESENT_STATE  & SDMMC_PRESENT_STATE_COMMAND_INHIBIT_CMD_Msk)
    {
      Status = (uint32_t)SDMMC003_CMD_LINE_BUSY;
      break;
    }
/* Check for  data line for Send Status command  and all those commands using  
   data line */
/* <<<DD_SDMMC_nonAPI_3_2>>> */
    if (( 1UL == CommandPtr->DataPresentSelect) ||  \
        ( (SDMMC003_SEND_STATUS == CommandPtr->CommandIndex) || \
          (3UL == CommandPtr->ResponseTypeSelect) )
       )
    {
/* <<<DD_SDMMC_nonAPI_3_3>>> */
      /* Read from Present state register to Check data line is free */
      if ( (SDMMC->PRESENT_STATE  & SDMMC_PRESENT_STATE_COMMAND_INHIBIT_DAT_Msk )!= 0)
      {
        Status = (uint32_t)SDMMC003_DATA_LINE_BUSY;
        break;
      }
/* <<<DD_SDMMC_nonAPI_3_4>>> */
      else
      {
        /* Update the data line state to active */
        if( (1UL == CommandPtr->DataPresentSelect) || \
            (3UL == CommandPtr->ResponseTypeSelect) )
        {
          SDMMC003_Handle.State |=(uint32_t)SDMMC003_STATE_DATA_ACTIVE;
        }
      }
    }
    /* Update the Command line state to active */
    SDMMC003_Handle.State |=(uint32_t)SDMMC003_STATE_CMD_ACTIVE;
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_4>>> */
/*
 * This function checks response error types in Command's Arguments category
 */
void SDMMC003_lCheckArgumentError
(
  const uint32_t  *CardStatusPtr,
  uint8_t *ErrorPtr
)
{
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* The command's argument was out of the allowed range for this card.*/
/* <<<DD_SDMMC_nonAPI_4_1>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_OUT_OF_RANGE_BITMASK ) != 0)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x, SDMMC003_OUT_OF_RANGE_ERROR,0,NULL);
  } /*End of "if( *CardStatusPtr & CSR_OUT_OF_RANGE_BITMASK ) "*/

  /* A mis-aligned address which did not match the block length was used in
   * the command.*/
/* <<<DD_SDMMC_nonAPI_4_2>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_ADDRESS_ERROR_BITMASK) != 0)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x, SDMMC003_ADDRESS_ERROR,0,NULL);
  } /*End of " if ( *CardStatusPtr & CSR_ADDRESS_ERROR_BITMASK) "*/

  /* The transferred block length is not allowed for this card, or the number
   * of transferred bytes does not match the block length.*/
/* <<<DD_SDMMC_nonAPI_4_3>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_BLOCK_LEN_ERROR_BITMASK) != 0)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_BLOCK_LEN_ERROR,0,NULL);
  }/*End of " if (*CardStatusPtr & CSR_BLOCK_LEN_ERROR_BITMASK) "*/

  /* Set when the host attempts to write to a protected block or to the
     temporary or permanent write protected card.*/
/* <<<DD_SDMMC_nonAPI_4_4>>> */
  if (( *CardStatusPtr & SDMMC003_CSR_WP_VIOLATION_BITMASK ) != 0)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_WP_VIOLATION_ERROR,0,NULL);
  }/*End of "if ( *CardStatusPtr & CSR_WP_VIOLATION_BITMASK ) "*/
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
}

/* <<<DD_SDMMC_nonAPI_5>>> */
/*
 * This function checks response error types in Erase category
 */
void SDMMC003_lCheckEraseError
(
  const uint32_t *CardStatusPtr,
  uint8_t *ErrorPtr
)
{
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  /* An error in the sequence of erase commands occurred.*/
/* <<<DD_SDMMC_nonAPI_5_1>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_ERASE_SEQ_ERROR_BITMASK) != 0)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_ERASE_SEQ_ERROR,0,NULL);
  }
  /* An invalid selection of write-blocks for erase occurred.*/
/* <<<DD_SDMMC_nonAPI_5_2>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_ERASE_PARAM_BITMASK) != 0)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_ERASE_PARAM_ERROR,0,NULL);
  }
  /* Set when only partial address space was erased due to existing
   * write protected blocks or the temporary or permanent write protected card
   *  was erased.*/
/* <<<DD_SDMMC_nonAPI_5_3>>> */
  if (( *CardStatusPtr & SDMMC003_CSR_WP_ERASE_SKIP_BITMASK) != 0)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_WP_ERASE_SKIP_ERROR,0,NULL);
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
}

/* <<<DD_SDMMC_nonAPI_6>>> */
/*
 * This function checks response error types in card's internal error category
 */
void SDMMC003_lCheckCardError
(
  const uint32_t *CardStatusPtr,
  uint8_t *ErrorPtr
)
{
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* Card internal ECC was applied but failed to correct the data.*/
/* <<<DD_SDMMC_nonAPI_6_1>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_CARD_ECC_FAILED_BITMASK) != 0UL)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_CARD_ECC_ERROR,0,NULL);
  }
  /* Internal card controller error*/
/* <<<DD_SDMMC_nonAPI_6_2>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_CC_ERROR_BITMASK) != 0UL)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_CC_ERROR,0,NULL);
  }
/* <<<DD_SDMMC_nonAPI_6_3>>> */
  /* A general or an unknown error occurred during the operation.*/
  if ((*CardStatusPtr & SDMMC003_CSR_ERROR_BITMASK) != 0)
  {
    *ErrorPtr = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_UNKNOWN_ERROR,0,NULL);
  }
  /* Debug Log message .*/
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
}

/*<<<DD_SDMMC_nonAPI_7>>> */
/*
 * This function checks for any error in the command's response received.
 */
status_t SDMMC003_lCheckErrorInResponse( const uint32_t *CardStatusPtr)
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  uint8_t ErrorStatus = 0;      /* No Error */
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  /* Argument Related Error Function */
  SDMMC003_lCheckArgumentError( CardStatusPtr, &ErrorStatus );

  /* Erase Related Error function  */
  SDMMC003_lCheckEraseError( CardStatusPtr, &ErrorStatus);

  /* Card Related Error function */
  SDMMC003_lCheckCardError(CardStatusPtr, &ErrorStatus);

  /* Set when a sequence or password error has been detected in lock/unlock
   * card command.*/
/*<<<DD_SDMMC_nonAPI_7_1>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_LOCK_UNLOCK_FAILED_BITMASK) != 0)
  {
    ErrorStatus = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_LOCK_UNLOCK_ERROR,0,NULL);
  }
  /* Can be either one of the following errors:
   * The read only section of the CSD does not match the card content.
   *  An attempt to reverse the copy  or permanent WP  bits was made.
   */
/*<<<DD_SDMMC_nonAPI_7_4>>> */
  if ((*CardStatusPtr & SDMMC003_CSR_CSD_OVERWRITE_BITMASK) != 0)
  {
    ErrorStatus = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_CSD_OVERWRITE,0,NULL);
  }
/*<<<DD_SDMMC_nonAPI_7_5>>> */
  /* Error in the sequence of the authentication process*/
  if ((*CardStatusPtr & SDMMC003_CSR_ASK_SEQ_ERROR_BITMASK) != 0)
  {
    ErrorStatus = 1UL;
    ERROR(GID_SDMMC00x,SDMMC003_ASK_SEQ_ERROR,0,NULL);
  }
  /* Below Additional condition is because some SD cards treat CMD55 as Illegal
   * Command and gives this error in response */
/*<<<DD_SDMMC_nonAPI_7_6>>> */
  if (ErrorStatus == 1UL) 
  {
    Status = (uint32_t) SDMMC003_ERROR;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/*
 * This function checks for lock status of SDMMC card.
 */
void SDMMC003_lGetCardLockState(uint32_t CardStatus, uint16_t CommandIndex)
{
  if (((CardStatus & SDMMC003_CSR_CARD_IS_LOCKED_BITMASK) != 0) &&
      (CommandIndex != SDMMC003_SEND_RELATIVE_ADDR ))
  {
    SDMMC003_Handle.State |= SDMMC003_STATE_CARD_LOCKED ;
  }
  else
  {
    SDMMC003_Handle.State &= ~SDMMC003_STATE_CARD_LOCKED ;
  }
}

/*
 * This function provide the delay in transfer.
 */
status_t SDMMC003_lTransferDelay(uint32_t DelayTime)
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  handle_t TimerId;
  SDMMC003_Handle.TimerExpire = 1;
  TimerId = SDMMC003_lStartTimer(DelayTime);
  if(0 == TimerId)
  {
    Status = (uint32_t) SDMMC003_START_TIMER_FAILED;
  }
  if(Status != (uint32_t) SDMMC003_START_TIMER_FAILED)
  {
    do
    {
      if (SDMMC003_Handle.TimerExpire == 0)
      {
        Status = (uint32_t)SDMMC003_TIMEOUT_OCCURED;
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }
    } while (SDMMC003_ISRContext.TransferFlag == 0);
    SDMMC003_ISRContext.TransferFlag = 0;
    SDMMC003_lStopTimer(TimerId);
  }
/* <<<DD_SDMMC_nonAPI_22_6>>> */
  if( SDMMC003_Handle.TransferInterruptError != SDMMC003_TRANSFER_COMPLETE)
  {
    Status = (uint32_t)SDMMC003_Handle.DataInterruptError;
  }
  return Status;
}

/*<<<DD_SDMMC_nonAPI_8>>> */
/*
 * This function reads for the response received for the command issued.
 */
status_t  SDMMC003_lReadResponse
(
   const SDMMC003_CommandType *CommandPtr,
   SDMMC003_ResponseType ResponseType,
   void *ResponsePtr
)
{
  uint32_t CardStatus = 0;
  uint32_t ErrorStatus = 0;
  uint32_t *TmpPtr;
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  /* Check for  No response type commands */
/*<<<DD_SDMMC_nonAPI_8_1>>> */
  if (CommandPtr->CommandIndex == SDMMC003_GO_IDLE_STATE || \
      CommandPtr->CommandIndex == SDMMC003_GO_INACTIVE_STATE)
  {
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
/*<<<DD_SDMMC_nonAPI_8_2>>> */
  else
  {
    TmpPtr = (uint32_t *)ResponsePtr;
    CardStatus = SDMMC->RESPONSE0;
    /* Check Lock Status */
/*<<<DD_SDMMC_nonAPI_8_3>>> */
    SDMMC003_lGetCardLockState(CardStatus, CommandPtr->CommandIndex);
   /* Check response type*/
    switch( ResponseType )
    {
      /* Response R1*/
/*<<<DD_SDMMC_nonAPI_8_4>>> */
      case SDMMC003_RESPONSE_R1:
        /* check the error bits in the response */
         *TmpPtr = CardStatus;
/*<<<DD_SDMMC_nonAPI_8_5>>> */
        Status = SDMMC003_lCheckErrorInResponse(&CardStatus);
        break;
      /* Response R1b*/
/*<<<DD_SDMMC_nonAPI_8_6>>> */
      case SDMMC003_RESPONSE_R1b:
        *TmpPtr = CardStatus;
        /* check the error bits in the response */
         Status = SDMMC003_lCheckErrorInResponse(&CardStatus);
         if (Status != (uint32_t)DAVEApp_SUCCESS)
         {
           break;
         }
#if SDMMC_UVP_TEST
        if (Test_TriggerInterrupt.Trigger_TransferInterruptError == TRUE)
        {
          SDMMC003_ISRContext.TransferFlag = 1;
          SDMMC003_Handle.TransferInterruptError = SDMMC003_ERROR;
        }
#endif  /* SDMMC_UVP_TEST*/
        /* Wait for transfer complete Interrupt */
/*<<<DD_SDMMC_nonAPI_8_7>>> */
        Status = SDMMC003_lTransferDelay(SDMMC003_DELAY_IN_TRANSFER);
        if(Status != (uint32_t) DAVEApp_SUCCESS)
        {
          ERROR(GID_SDMMC00x, Status, 0, NULL);
          break;
        }
#if SDMMC_UVP_TEST
        if (Test_TriggerInterrupt.Trigger_TransferInterruptError == TRUE)
        {
          /* Enable the Transfer Complete Status Interrupt */
          SDMMC->EN_INT_STATUS_NORM |= SDMMC_EN_INT_STATUS_NORM_TX_COMPLETE_EN_Msk;
          /*  Enable the Transfer Complete Signal Interrupt */
          SDMMC->EN_INT_SIGNAL_NORM |= SDMMC_EN_INT_SIGNAL_NORM_TX_COMPLETE_EN_Msk;
        }
#endif     /* SDMMC_UVP_TEST*/
        /* If busy status received successfully  in the data line for R1b */
/*<<<DD_SDMMC_nonAPI_8_8>>> */
        break;
      /* Response R2*/
/*<<<DD_SDMMC_nonAPI_8_9>>> */
      case SDMMC003_RESPONSE_R2:
        /* Response register R0-R7 */
        *TmpPtr = CardStatus;
        TmpPtr++;

        *TmpPtr = SDMMC->RESPONSE2;
        TmpPtr++;

        *TmpPtr = SDMMC->RESPONSE4;
        TmpPtr++;

        *TmpPtr = SDMMC->RESPONSE6;
        break;
      /* Response R3*/
/*<<<DD_SDMMC_nonAPI_8_10>>> */
      case SDMMC003_RESPONSE_R3:

      /* Response R7*/
/*<<<DD_SDMMC_nonAPI_8_11>>> */
      case SDMMC003_RESPONSE_R7:
        *TmpPtr = CardStatus;
         break;

      /* Response R6*/
/*<<<DD_SDMMC_nonAPI_8_12>>> */
      case SDMMC003_RESPONSE_R6:
        ErrorStatus  = CardStatus & SDMMC_RESPONSE0_RESPONSE0_Msk;
        Status = SDMMC003_lCheckErrorInResponse(&ErrorStatus);
/*<<<DD_SDMMC_nonAPI_8_13>>> */
        /* Read the 16bit RCA received in Response R1 register */
        *TmpPtr =(uint16_t)((CardStatus & SDMMC_RESPONSE0_RESPONSE1_Msk) >> \
                              SDMMC003_HC_RESPONSE1_BITPOS );
        break;

      /* No response*/
/*<<<DD_SDMMC_nonAPI_8_14>>> */
      case SDMMC003_NO_RESPONSE:
        Status = DAVEApp_SUCCESS;
        break;

      default:
        Status = (uint32_t)SDMMC003_ERROR;
        break;
    } /* End of " switch( ResponseType )"*/
  }/* End of " if (CommandPtr->CommandIndex == SDMMC003_GO_IDLE_STATE || 
               CommandPtr->CommandIndex == SDMMC003_GO_INACTIVE_STATE)"*/
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_SDMMC_nonAPI_9>>> */
/*
 * This function issues the command.
 */
status_t SDMMC003_lSendCommand
( 
  const SDMMC003_CommandType *CommandPtr,
  uint32_t Argument,
  SDMMC003_ResponseType ResponseType,
  void *ResponsePtr
)
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  handle_t TimerId;
  SDMMC003_Handle.IssueAbort = 0UL;  
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    SDMMC003_Handle.CommandInterruptError = SDMMC003_ERROR;
    SDMMC003_Handle.DataInterruptError = SDMMC003_ERROR;
    /* Data or Command line free */
/*<<<DD_SDMMC_nonAPI_9_1>>>*/
    Status = SDMMC003_lCheckDatCmdline(CommandPtr);
    if ((Status == (uint32_t)SDMMC003_DATA_LINE_BUSY) ||
        (Status == (uint32_t)SDMMC003_CMD_LINE_BUSY))
    {
      break;
    }
      /* Set argument register */
    SDMMC->ARGUMENT1 = Argument;
    /* Set command register */
    SDMMC->COMMAND = (uint16_t)(*(uint16_t *)CommandPtr);
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_CommandErrorInterrupt == TRUE)
    {
      /* Forcefully trigger the Command Timeout Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0001 ;
    }
    if (Test_TriggerInterrupt.Trigger_EraseStartError == TRUE)
    {
        /* Forcefully trigger the Command Index Error Interrupt */
        SDMMC->FORCE_EVENT_ERR_STATUS = 0x0008 ;
    }
    if (Test_TriggerInterrupt.Trigger_EraseEndError == TRUE)
    {
      /* Forcefully trigger the Command Index Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0008 ;
    }
    if (Test_TriggerInterrupt.Trigger_Cmd55Error == TRUE)
    {
      /* Forcefully trigger the Command Timeout Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0001 ;
    }
    if (Test_TriggerInterrupt.Trigger_Command42Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = FALSE;
    }
#endif  /*SDMMC_UVP_TEST*/   
/* Blocking until any of the bit in the Interrupt Status Register gets set */
/*<<<DD_SDMMC_nonAPI_9_2>>>*/
    TimerId = SDMMC003_lStartTimer(SDMMC003_DELAY_IN_COMMAND);
    if(0 == TimerId)
    {
      Status = (uint32_t) SDMMC003_START_TIMER_FAILED;
      ERROR(GID_SDMMC00x, Status, 0, NULL);    
      break;
    }
    do
    {
      if (SDMMC003_Handle.TimerExpire == 0)
      {
        ERROR(GID_SDMMC00x, SDMMC003_TIMEOUT_OCCURED, 0, NULL);
        break;
      }
    } while (SDMMC003_ISRContext.CmdFlag == 0);
    SDMMC003_ISRContext.CmdFlag = 0;
    SDMMC003_lStopTimer(TimerId);
   /* Check for any errors */
/*<<<DD_SDMMC_nonAPI_9_3>>> */
    if( SDMMC003_Handle.CommandInterruptError == SDMMC003_COMMAND_COMPLETE )
    {
#if SDMMC_UVP_TEST
      if(Test_TriggerInterrupt.Trigger_CommandResponseError == TRUE)
      {
        Status = (uint32_t)SDMMC003_ERROR;
        break;
      }
#endif
      /* Read response received. */
/*<<<DD_SDMMC_nonAPI_9_4>>>*/
      Status = SDMMC003_lReadResponse(CommandPtr,ResponseType,ResponsePtr);
      break;
    }
/*<<<DD_SDMMC_nonAPI_9_5>>>*/
    /* For Cmd8, check for  Command Timeout Interrupt */
    else if ((CommandPtr->CommandIndex == SDMMC003_SD_SEND_IF_COND) &&
             (SDMMC003_Handle.CommandInterruptError == \
                                             SDMMC003_COMMAND_TIMEOUT_ERROR))
    {
      Status = (uint32_t)SDMMC003_COMMAND_TIMEOUT_ERROR;
      break;
    }
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_CommandErrorInterrupt == TRUE)
    {
      /* Enable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM |= SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk;
      /* Enable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM |= SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk;
      SDMMC->EN_INT_STATUS_NORM |= (SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM |= (SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);

      SDMMC->EN_INT_STATUS_NORM |= (SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM |= (SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);

      SDMMC->EN_INT_STATUS_NORM |= (SDMMC_EN_INT_STATUS_NORM_TX_COMPLETE_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM |= (SDMMC_EN_INT_SIGNAL_NORM_TX_COMPLETE_EN_Msk);
    }
    if (Test_TriggerInterrupt.Trigger_Cmd55Error == TRUE)
    {
        /* Enable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM |= SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk;
      /* Enable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM |= SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk;

       SDMMC->EN_INT_STATUS_NORM |= (SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM |= (SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);

      SDMMC->EN_INT_STATUS_NORM |= (SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM |= (SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);

      SDMMC->EN_INT_STATUS_NORM |= (SDMMC_EN_INT_STATUS_NORM_TX_COMPLETE_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM |= (SDMMC_EN_INT_SIGNAL_NORM_TX_COMPLETE_EN_Msk);
    }
    if (Test_TriggerInterrupt.Trigger_Command42Error == TRUE)
    {
      /* Enable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM |= SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk;
      /* Enable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM |= SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk;
    }

    if (Test_TriggerInterrupt.Trigger_EraseEndError == TRUE)
    {
      /* Enable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM |= SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk;
      /* Enable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM |= SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk;
    }
    if (Test_TriggerInterrupt.Trigger_EraseStartError == TRUE)
    {
      /* Enable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM |=  SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk;
        /* Disable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM |=  SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk ;
    }
#endif  /*SDMMC_UVP_TEST*/

#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_TC8Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = FALSE;
    }
    if (Test_TriggerInterrupt.Trigger_TC10Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = FALSE;
    }
    if (Test_TriggerInterrupt.Trigger_TC13Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = FALSE;
    }
    if (Test_TriggerInterrupt.Trigger_TC17Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = FALSE;
    }
    if (Test_TriggerInterrupt.Trigger_TC20Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = FALSE;
    }
#endif /* SDMMC_UVP_TEST  */
/*<<<DD_SDMMC_nonAPI_9_6>>>*/
    if (CommandPtr->DataPresentSelect == 1)
    {
      SDMMC003_Handle.IssueAbort = 1UL;
    }    
    /* Error Recovery for the failed command  */
    Status = SDMMC003_lErrorInterruptRecovery( \
                                   SDMMC003_ISRContext.InterruptStatusShadow, \
                                   SDMMC003_Handle.IssueAbort);
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_SDMMC_nonAPI_10>>> */
/*
 * This function sets the voltage window in OCR register
 */
status_t  SDMMC003_lSetVoltageWindow()
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  uint32_t CardStatus = 0;
  uint32_t Argument = 0;
  uint32_t LoopCount= 0;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* <<<DD_SDMMC_nonAPI_10_1>>> */
  /* For Standard Capacity Card  */
  if (SDMMC003_Handle.f8 == 0)
  {
    /* Set HCS = 0  */
    Argument = SDMMC003_SD_ACMD41_F80_ARG;
  }
/* <<<DD_SDMMC_nonAPI_10_2>>> */
  /* For High Capacity Card */
  else
  {
    /* Set  HCS = 1 */
    Argument = SDMMC003_SD_ACMD41_F81_ARG;
  }
  do
  {
    /*Send Command55 for Application Specific Command with default RCA as 0*/
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(55)), \
                                     SDMMC003_ARGUMENT0, SDMMC003_RESPONSE_R1,\
                                     &CardStatus);
/* <<<DD_SDMMC_nonAPI_10_3>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* Send ACMD41 to Set the card's voltage window */
    Status = SDMMC003_lSendCommand( &(SDMMC003_SD_COMMAND(62)), Argument,\
                                  SDMMC003_RESPONSE_R3,&(SDMMC003_CardInfo.Ocr));
/* <<<DD_SDMMC_nonAPI_10_4>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS && \
       (Status != (uint32_t)SDMMC003_ILLEGAL_COMMAND_ERROR))
    {
      break;
    }
    Status = (uint32_t)DAVEApp_SUCCESS;
    /* Cards takes some time to set power status bit. Card must repsond 
    within 1 sec. */
    /* Timeout of 10ms.*/
    SDMMC003_lDelay(SDMMC003_CARD_POWER_DELAY);
/* Check for busy bit in the OCR content i.e response */
  } while(!(SDMMC003_CardInfo.Ocr & SDMMC003_OCR_POWER_STATUS_BITMASK) &&\
           ( (LoopCount++)<50 ) );
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_SDMMC_nonAPI_11>>> */
/*
 * This function queries Voltage operating condition of the card.
 */
status_t SDMMC003_lQueryOperatingCond()
{
  uint32_t ResponseData = 0;
  status_t Status;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  /*Query voltage operating condition i.e. cmd8 */
  Status = SDMMC003_lSendCommand(&(SDMMC003_SD_COMMAND(8)),SDMMC003_SD_CMD8_ARG,\
                                  SDMMC003_RESPONSE_R7, &ResponseData );
  do
  {
/*<<<DD_SDMMC_nonAPI_11_1>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS )
    {
/*<<<DD_SDMMC_nonAPI_11_2>>> */
      /*  No response is received for Standard Capacity SD cards or MMC card. */
      if (SDMMC003_Handle.CommandInterruptError ==SDMMC003_COMMAND_TIMEOUT_ERROR)
      {
        SDMMC003_Handle.f8 = 0;
        Status = (uint32_t)DAVEApp_SUCCESS;
      }
      /*<<<DD_SDMMC_nonAPI_11_3>>> */
      else
      {
        break;
      }
    }
    /* Response received i.e. High Capacity cards. */
/*<<<DD_SDMMC_nonAPI_11_4>>> */
    else
    {
/*<<<DD_SDMMC_nonAPI_11_5>>> */
      /* Check whether Check pattern matches in the Argument and Response */
      if (((ResponseData >> SDMMC003_SD_CMD8_CHECK_PATTERN_BITPOS) &\
             SDMMC003_SD_CMD8_CHECK_PATTERN_BITMASK) != \
            (SDMMC003_SD_CMD8_CHECK_PATTERN_VALUE)
         )
      {
        Status  = (uint32_t)SDMMC003_BAD_RESPONSE;
        break;
      }
/*<<<DD_SDMMC_nonAPI_11_6>>> */
      /* Check the Voltage Supplied is Accepted by the card in the response  */
      if( ((uint8_t)( ResponseData >> SDMMC003_SD_CMD8_VHS_BITPOS) &\
                     SDMMC003_SD_CMD8_VHS_BITMASK)!=  \
                     ( SDMMC003_SD_VHS_PATTERN_2_7_3_6_VALUE ) )
      {
        Status = (uint32_t)SDMMC003_BAD_RESPONSE;
        break;
      }
      /* Set Flag f8 */
      SDMMC003_Handle.f8 = 1;
    }
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_SDMMC_nonAPI_12>>> */
/*
 * This function queries voltage supported from the card.
 */
status_t SDMMC003_lQueryVoltage (uint32_t Argument)
{
  uint32_t CardStatus = 0;
  status_t Status;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    /* Send Command55 for Application Specific Command with default RCA as 0*/
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(55)), Argument,\
                                    SDMMC003_RESPONSE_R1, &CardStatus);
/* <<<DD_SDMMC_nonAPI_12_1>>> */
    if (Status != DAVEApp_SUCCESS )
    {
      /* Some SD cards which doesn't supports CMD8 treat cmd55 as illegal so
       * ignore this error */
/*<<<DD_SDMMC_nonAPI_12_2>>> */
      if (!( (Status == (uint32_t)SDMMC003_ILLEGAL_COMMAND_ERROR) && \
             (SDMMC003_Handle.f8 == 0) ))
      {
        break;
      }
    }
    /* Send ACMD41 to query the card's voltage window */
    Status = SDMMC003_lSendCommand( &(SDMMC003_SD_COMMAND(62)), Argument,\
                                   SDMMC003_RESPONSE_R3,&(SDMMC003_CardInfo.Ocr));
/*<<<DD_SDMMC_nonAPI_12_3>>> */
    if ( (Status != (uint32_t)DAVEApp_SUCCESS) &&\
         (Status != (uint32_t)SDMMC003_ILLEGAL_COMMAND_ERROR))
    {
      /* No response means SDMMC_MMC card */
#if SDMMC_SUPPORT_MMC_CARD
/*<<<DD_SDMMC_nonAPI_12_4>>> */
      if (Status == (uint32_t) SDMMC003_COMMAND_TIMEOUT_ERROR)
      {
        Status  =  (uint32_t)SDMMC003_lInitializeMmcCard();
        break;
      }
      else
#endif /* SDMMC_SUPPORT_MMC_CARD */
      {
        break;
      }
    }
    /* Send ACMD41 with voltage window argument set */
/*<<<DD_SDMMC_nonAPI_12_5>>> */
    Status = SDMMC003_lSetVoltageWindow();
    if( Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /* SD Card Type */
/*<<<DD_SDMMC_nonAPI_12_6>>> */
    SDMMC003_lWriteCardType();
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_SDMMC_nonAPI_13>>> */
/*
 * This function reads the card registers after the card is initialized.
 */
status_t SDMMC003_lAfterCardInitialize()
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
   /* Read CSD & SCR Register & Card Write Protection Flags. */
    Status = SDMMC003_lReadCardRegisters();
/*<<<DD_SDMMC_nonAPI_13_1>>> */
    if(Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
#if SDMMC_SUPPORT_4_BUS_WIDTH
    /* Switch  to 4-bit bus width if supported */
    Status = SDMMC003_lSwitchBusWidth();
/*<<<DD_SDMMC_nonAPI_13_2>>> */
    if( Status != (uint32_t)DAVEApp_SUCCESS )
    {
      /* Change bus width to default in the Host Controller */
      CLR_BIT( SDMMC->HOST_CTRL,SDMMC_HOST_CTRL_DATA_TX_WIDTH_Pos);
    }
    /* Switch  to High Speed Mode */
    Status = SDMMC003_lSwitchSpeed();
/*<<<DD_SDMMC_nonAPI_13_3>>> */
    if( Status != (uint32_t)DAVEApp_SUCCESS )
    {
      /* Change Speed mode to default in the Host Controller */
      CLR_BIT( SDMMC->HOST_CTRL,SDMMC_HOST_CTRL_HIGH_SPEED_EN_Pos );
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
#endif
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_14>>> */
/*
 * This function initializes the SD card.
 */
status_t SDMMC003_lInitializeCard()
{
  status_t Status;
  uint32_t LockStatus ;
  uint8_t Count= 0;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
/* <<<DD_SDMMC_nonAPI_14_1>>> */
    /* Repeat the below steps 2 times if bad response is received.    */
    do
    {
      /* Reset the card. i.e cmd0 */
      Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(0)), \
                                        SDMMC003_ARGUMENT0, \
                                        SDMMC003_NO_RESPONSE, \
                                        NULL);
/* <<<DD_SDMMC_nonAPI_14_2>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }/* End of "if(Status != DAVEApp_SUCCESS )" */
      /* Query the Operation Condition Info from the card.*/
/* <<<DD_SDMMC_nonAPI_14_3>>> */
      Status = SDMMC003_lQueryOperatingCond();
      Count++;
    } while(( Count < SDMMC003_NUM_CARD_RESET_RETRIES) && \
            ( Status == (uint32_t)SDMMC003_BAD_RESPONSE));
/* <<<DD_SDMMC_nonAPI_14_4>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }/* End of "if(Status != DAVEApp_SUCCESS )" */
    /* Query & Set voltage window  */

    Status = SDMMC003_lQueryVoltage(SDMMC003_CardInfo.Rca);
/* <<<DD_SDMMC_nonAPI_14_5>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /* Read CID */
    Status = SDMMC003_lSendCommand(&(SDMMC003_COMMON_COMMAND(2)), \
                                     SDMMC003_ARGUMENT0,SDMMC003_RESPONSE_R2, \
                                     (void *)SDMMC003_CardInfo.CidArray);
/* <<<DD_SDMMC_nonAPI_14_6>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /* Read RCA */
    Status = SDMMC003_lReadRca();
/* <<<DD_SDMMC_nonAPI_14_7>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    } 
    /* Check the card Lock/ Unlock Status */
    Status = SDMMC003_GetLockStatus(&LockStatus);
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* <<<DD_SDMMC_nonAPI_14_8>> */
    if (LockStatus == (uint32_t)SDMMC003_CARD_IS_LOCKED)
    {
      SDMMC003_Handle.State |= SDMMC003_STATE_CARD_LOCKED ;
      Status = (uint32_t)SDMMC003_INITIALIZED_BUT_LOCKED;     
    }
    /* Update card initialization Status */
    SDMMC003_Handle.State |= SDMMC003_STATE_CARD_INITIALIZED;
    SDMMC003_Handle.State &=  ~(SDMMC003_STATE_NO_CARD);
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_15>>> */
/*
 * This function finds out the card Type information.
 */
void SDMMC003_lWriteCardType()
{
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  /* If F8 =0 , Standard Capacity V1 Card */
/* <<<DD_SDMMC_nonAPI_15_1>>> */
  if ( SDMMC003_Handle.f8 == 0)
  {
    SDMMC003_Handle.CardType |= SDMMC003_SD_STANDARD_CAPACITY_V1x;
  }
  /* If F8 =1 , Standard Capacity V2 or High Capacity Card */
/* <<<DD_SDMMC_nonAPI_15_2>>> */
  else
  {
    /* Check CCS bit in the OCR register, CCS=1 means High Capacity  card*/
/* <<<DD_SDMMC_nonAPI_15_3>>> */
    if ((SDMMC003_CardInfo.Ocr & SDMMC003_OCR_CCS_BITMASK ) != 0)
    {
      SDMMC003_Handle.CardType |= SDMMC003_SD_HIGH_CAPACITY | \
                                  SDMMC003_BLOCK_ADDRESSING;
    }
/* <<<DD_SDMMC_nonAPI_15_4>>> */
    /* CCS=0 means Standard Capacity Version2*/
    else
    {
      SDMMC003_Handle.CardType |= SDMMC003_SD_STANDARD_CAPACITY_V2;
    }
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
}

/* <<<DD_SDMMC_nonAPI_16>>> */
/*
 * This function finds out the Write protection status of the card.
 */
status_t SDMMC003_lSetWriteProtect (void)
{
  uint32_t SdStatus[16] = {0};
  uint32_t WriteProtect;
  status_t Status = (uint32_t)SDMMC003_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
#if SDMMC_SUPPORT_MMC_CARD
    SDMMC003_MMCCSDType *TmpMmcCsdPtr;
/* <<<DD_SDMMC_nonAPI_16_1>>> */
    if ((SDMMC003_Handle.CardType & SDMMC003_MMC) != 0)
    {
      TmpMmcCsdPtr = (SDMMC003_MMCCSDType *)&SDMMC003_CardInfo.CsdArray;
      /* Read Write Protection bits from CSD Register i.e both Temp & Permanent */
/* <<<DD_SDMMC_nonAPI_16_2>>> */
      if ( ((TmpMmcCsdPtr->TempWriteProtect) != 0) || \
           ((TmpMmcCsdPtr->PermWriteProtect) != 0))
      {
        SDMMC003_Handle.State |=(uint32_t)SDMMC003_STATE_CARD_WRITE_PROTECT;
      }
    }
    else
#endif
    {
      /* SD Card Write Protection.  */
      Status  = SDMMC003_GetSdStatus((void*)&(SdStatus[0]));
/* <<<DD_SDMMC_nonAPI_16_3>>> */
      if (Status != DAVEApp_SUCCESS)
      {
        break;
      }
/* <<<DD_SDMMC_nonAPI_16_4>>> */
      /* Bits 480:495 in the SD status gives the Write Protection Information */
      WriteProtect = ((SdStatus[0] & 0xFF000000) >> 24 ) | 
                     (((SdStatus[0] & 0x00FF0000) >> 16 ) << 8) ;
      if ( (WriteProtect & SDMMC003_SD_CARD_TYPE_BITMASK) != 0 )
      {
        SDMMC003_Handle.State |=(uint32_t)SDMMC003_STATE_CARD_WRITE_PROTECT;
      }
    }
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_17>>> */
/*
 * This function reads the  Relative card address of the card.
 */
status_t SDMMC003_lReadRca()
{
  status_t Status ;
#if SDMMC_SUPPORT_MMC_CARD
  uint32_t CardStatus = 0;
#endif /* SDMMC_SUPPORT_MMC_CARD */
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  /*  Read RCA for MMC card */
#if SDMMC_SUPPORT_MMC_CARD
/* <<<DD_SDMMC_nonAPI_17_1>>> */
  if ((SDMMC003_Handle.CardType & SDMMC003_MMC) != 0)
  {
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(3)),
                                    (uint32_t)SDMMC003_MMC_DEFAULT_RCA,  \
                                    SDMMC003_RESPONSE_R1, &CardStatus);
    SDMMC003_CardInfo.Rca = SDMMC003_MMC_DEFAULT_RCA;
  }
  /*  Read RCA for SD  */
  else
#endif
  {
/* <<<DD_SDMMC_nonAPI_17_2>>> */
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(3)), \
                                    SDMMC003_ARGUMENT0, \
                                    SDMMC003_RESPONSE_R6, \
                                    &(SDMMC003_CardInfo.Rca));
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_18>>> */
/*
 * This function initializes the MMC card.
 */
#if SDMMC_SUPPORT_MMC_CARD
/* SDMMC_MMC Initialize */
status_t SDMMC003_lInitializeMmcCard()
{
  status_t Status;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    /* Reset the card. i.e cmd0 */
    Status = (uint32_t)SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(0)), \
                                                SDMMC003_ARGUMENT0,  \
                                                SDMMC003_NO_RESPONSE, NULL);
/* <<<DD_SDMMC_nonAPI_18_1>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS )
    {
      break;
    }/* End of "if(Status != DAVEApp_SUCCESS )" */
   /*Command1 indicating support for high capacity cards & voltage 2.7 to 3.6v */
    do
    {
      Status = SDMMC003_lSendCommand(&(SDMMC003_MMC_COMMAND(1)), \
                                        MMC_CMD1_ARG ,SDMMC003_RESPONSE_R3,\
                                        &(SDMMC003_CardInfo.Ocr) );
/* <<<DD_SDMMC_nonAPI_18_2>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS )
      {
        break;
      }/* End of "if(Status != DAVEApp_SUCCESS )" */
    } while(SDMMC003_CardInfo.Ocr & SDMMC003_OCR_POWER_STATUS_BITMASK );
   /* Check mode. 00b (byte mode) & 10b (sector mode)*/
/* <<<DD_SDMMC_nonAPI_18_3>>> */
    if( ((SDMMC003_CardInfo.Ocr & SDMMC003_MMC_OCR_ACCESS_MODE_BITMASK) >> \
       (SDMMC003_MMC_OCR_ACCESS_MODE_BITPOS) != 0))
    {
      SDMMC003_Handle.CardType |= SDMMC003_BLOCK_ADDRESSING;
    }
    SDMMC003_Handle.CardType |= SDMMC003_MMC;
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}
#endif

/* <<<DD_SDMMC_nonAPI_19>>> */
/*
 * This function reads the CSD, SCR and Write protection status of the card.
 */
status_t SDMMC003_lReadCardRegisters (void)
{
  uint32_t Argument = 0;
  uint32_t CardStatus = 0;
  status_t Status;
  SDMMC003_SCRType ScrContent = {0};
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    /* Read CSD Register  */
    Argument |= SDMMC003_CardInfo.Rca << SDMMC003_ARG_RCA_BITPOS;
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(9)),Argument, \
                                     SDMMC003_RESPONSE_R2, \
                                     (void *)SDMMC003_CardInfo.CsdArray);
/* <<<DD_SDMMC_nonAPI_19_1>>> */
    if( Status != (uint32_t)DAVEApp_SUCCESS )
    {
      break;
    }
    /* Set Write protection flags */
    Status = SDMMC003_lSetWriteProtect();
/* <<<DD_SDMMC_nonAPI_19_2>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* <<<DD_SDMMC_nonAPI_19_3>>> */
    /* Read SCR register for SD card */
    if ((SDMMC003_Handle.CardType & SDMMC003_MMC) == 0)
    {
      /* Switch to Transferring State. */
      Status = SDMMC003_lSwitchToTransferState();
/* <<<DD_SDMMC_nonAPI_19_4>>> */
      if( Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }   
      /*Send the Application Specific Command i.e. Command 55.*/
      Argument |= SDMMC003_CardInfo.Rca << SDMMC003_ARG_RCA_BITPOS;
      Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(55)),Argument, \
                                      SDMMC003_RESPONSE_R1, &CardStatus );
/* <<<DD_SDMMC_nonAPI_19_5>>> */
      if( Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
      /* Set Direction Select bit in the Transfer Mode register */
      SET_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_TX_DIR_SELECT_Pos);
      /* Read the transferred SCR data*/
      Status = SDMMC003_lSingleBlockTransfer( &(SDMMC003_SD_COMMAND(64)), \
                                              SDMMC003_ARGUMENT0,8, \
                                              (uint32_t *)&ScrContent, \
                                              SDMMC003_READ_FROM_BUFF);
      SDMMC003_CardInfo.Scr  =   ScrContent;
/* <<<DD_SDMMC_nonAPI_19_6>>> */
      if( Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      } 
    } /* End of " if ((SDMMC003_Handle.CardType & SDMMC003_MMC) == 0)"*/
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_20>>> */
/*
 * This function configures the registers for Single Block Transfer.
 */
status_t SDMMC003_lConfigureForSingleTransfer
(
  const SDMMC003_CommandType *CommandPtr,
  uint32_t Argument,
  uint16_t BlockSize
)
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  uint32_t CardStatus = 0;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    /* Set Block Size Register */
    WR_REG( SDMMC->BLOCK_SIZE,SDMMC_BLOCK_SIZE_TX_BLOCK_SIZE_Msk , \
            SDMMC_BLOCK_SIZE_TX_BLOCK_SIZE_Pos,BlockSize );
    /* Clear the Multi Block Select bit */
    CLR_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_MULTI_BLOCK_SELECT_Pos);
    /* Clear the ACMD Enable bit*/
    CLR_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_ACMD_EN_Pos);
    /* Clear the Block Count Enable bit*/
    CLR_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_BLOCK_COUNT_EN_Pos);

#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_TC13Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt =TRUE ;
    }
    if (Test_TriggerInterrupt.Trigger_TC20Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt =TRUE ;
    }
    if (Test_TriggerInterrupt.Trigger_Command42Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt =TRUE ;
    }
    if (Test_TriggerInterrupt.Trigger_CommandErrorInterrupt == TRUE)
    {
      /* Disable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
      /* Disable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk);

      /* Disable the Buffer Ready Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      /* Disable the Buffer Write  Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
       /* Disable the Transfer Complete  Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_TX_COMPLETE_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_SIGNAL_NORM_TX_COMPLETE_EN_Msk);
    }
    if (Test_TriggerInterrupt.Trigger_DataErrorInterrupt == TRUE)
    {
      /* Disable the Buffer Ready Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      /* Disable the Buffer Ready Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
    }
#endif
    /* Send Single Block Transfer Command */
    Status = (uint32_t)SDMMC003_lSendCommand( CommandPtr, Argument, \
                                              SDMMC003_RESPONSE_R1, &CardStatus);
/* <<<DD_SDMMC_nonAPI_20_1>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_21>>> */
/*
 * This function configures the registers for Multiple Block Transfer.
 */
status_t SDMMC003_lConfigureRegForMultiTransfer
(
  uint32_t *TmpAddrPtr,
  uint32_t NumberOfBlocks,
  const SDMMC003_CommandType *CommandPtr
)
{
  status_t Status;
  uint32_t CardStatus = 0;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    /* Block Addressing */
    /* <<<DD_SDMMC_nonAPI_21_1>>> */
    if ((SDMMC003_Handle.CardType & SDMMC003_BLOCK_ADDRESSING) == 0UL)
    {
      *TmpAddrPtr *= 512UL;
    }
    /* Set Block Size Register */
    WR_REG( SDMMC->BLOCK_SIZE,SDMMC_BLOCK_SIZE_TX_BLOCK_SIZE_Msk , \
            SDMMC_BLOCK_SIZE_TX_BLOCK_SIZE_Pos,SDMMC003_TX_BLOCK_SIZE_VALUE);
    /* Set Transfer Mode Register */
    SET_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_MULTI_BLOCK_SELECT_Pos);
    SET_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_ACMD_EN_Pos);
    SET_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_BLOCK_COUNT_EN_Pos);

    /* Set Block Count Register */
    WR_REG( SDMMC->BLOCK_COUNT, SDMMC_BLOCK_COUNT_BLOCK_COUNT_Msk ,   \
            SDMMC_BLOCK_COUNT_BLOCK_COUNT_Pos, NumberOfBlocks);

    /* Enable ACMD 12 Interrupt Signal  */
    SDMMC->EN_INT_SIGNAL_ERR &= ~SDMMC_EN_INT_SIGNAL_ERR_ACMD_ERR_EN_Msk;
    SDMMC->EN_INT_SIGNAL_ERR |= SDMMC_EN_INT_SIGNAL_ERR_ACMD_ERR_EN_Msk;

#if SDMMC_UVP_TEST 
    if ( Test_TriggerInterrupt.Trigger_TC8Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = TRUE;
    }
    if ( Test_TriggerInterrupt.Trigger_TC10Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = TRUE;
    }
    if ( Test_TriggerInterrupt.Trigger_TC17Error == TRUE)
    {
      Test_TriggerInterrupt.Trigger_CommandErrorInterrupt = TRUE;
    }

    if (Test_TriggerInterrupt.Trigger_CommandErrorInterrupt == TRUE)
    {
      /* Disable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
      /* Disable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk);
      /* Disable the Buffer Ready Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      /* Disable the Buffer Write Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
      /* Disable the Transfer Complete Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_TX_COMPLETE_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_SIGNAL_NORM_TX_COMPLETE_EN_Msk);
    }
    if (Test_TriggerInterrupt.Trigger_DataErrorInterrupt == TRUE)
    {
      /* Disable the Buffer Ready Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk);

       /* Disable the Buffer Ready Status & Signal Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk);
    }
#endif
   /* Send Multiple Block  Transfer Command */
    Status = SDMMC003_lSendCommand( CommandPtr,  *TmpAddrPtr, \
                                    SDMMC003_RESPONSE_R1, &CardStatus );
/* <<<DD_SDMMC_nonAPI_21_2>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_22>>> */
/*
 * This function is used to transfer multiple blocks of data.
 */
status_t SDMMC003_lMultiBlockTransfer( uint32_t *AddrPtr,uint32_t NumberOfBlocks,\
                                       const SDMMC003_CommandType *CommandPtr, \
                                       uint32_t *BufferPtr, \
                                       SDMMC003_DataTrasferType TransferMode
                                     )
{
  status_t Status ;
  SDMMC003_Handle.TransferInterruptError = SDMMC003_ERROR;
  do
  {
    /* Configure Registers for Multi block transfer*/
    Status = SDMMC003_lConfigureRegForMultiTransfer( AddrPtr, \
                                                    NumberOfBlocks,CommandPtr );
/* <<<DD_SDMMC_nonAPI_22_1>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
       break;
    }
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_DataErrorInterrupt == TRUE)
    {
      /* Forcefully trigger the Data Crc Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0020 ;
    }
#endif
 /* Read/Write  Block Data  */
/* <<<DD_SDMMC_nonAPI_22_2>>> */
    while( NumberOfBlocks > 0 )
    {
      /* Perform Transfer */
      Status = SDMMC003_lDataTransfer( BufferPtr, TransferMode,  \
                                       SDMMC003_NUM_QUADLETS_IN_BLOCK);
/* <<<DD_SDMMC_nonAPI_22_3>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
      /* Decrement Number of blocks Variable */
      NumberOfBlocks--;
      /* Pointer pointing to the next Block Pointer*/
      BufferPtr += SDMMC003_NUM_QUADLETS_IN_BLOCK;
    }/* End of " while( NumberOfBlocks > 0 )"*/
/* <<<DD_SDMMC_nonAPI_22_4>>> */
    if ( Status == (uint32_t)DAVEApp_SUCCESS)
    {
     /* Block on Transfer Complete Interrupt */
/* <<<DD_SDMMC_nonAPI_22_5>>> */      
      /* Timeout of 5ms.*/
      Status = SDMMC003_lTransferDelay(SDMMC003_DELAY_IN_TRANSFER);
      if(Status != (uint32_t) DAVEApp_SUCCESS)
      {
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }
/* <<<DD_SDMMC_nonAPI_22_6>>> */
    }/* End of " if ( Status == (uint32_t)DAVEApp_SUCCESS)"*/
    /* Check Transfer Completed Successfully */
/* Check ACMD status*/
/* <<<DD_SDMMC_nonAPI_22_7>>> */
    if(SDMMC003_Handle.AcmdInterruptError == SDMMC003_ACMD12_ERROR)
    {
      /* Call ACMD12 Error Recovery */
      SDMMC003_lAcmdErrorRecovery();
    }
  } while(0);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_23>>> */
/*
 * This function performs the  Single Block Transfer.
 */
status_t SDMMC003_lSingleBlockTransfer
(
  const SDMMC003_CommandType *CommandPtr,
  uint32_t Argument,
  uint16_t BlockSize,
  uint32_t *BufferPtr,
  SDMMC003_DataTrasferType TransferMode
)
{
  status_t Status;
  handle_t TimerId;
  do
  {
    /* Configure Register  for Single Block Transfer */
    Status = SDMMC003_lConfigureForSingleTransfer(CommandPtr,Argument,BlockSize);
/* <<<DD_SDMMC_nonAPI_23_1>>> */
    if ((uint32_t)DAVEApp_SUCCESS != Status)
    {
      break;
    }
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_DataErrorInterrupt == TRUE)
    {
      /* Forcefully trigger the Data Crc Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0020 ;
    }
#endif
    /* Perform Data Transfer */
    Status = SDMMC003_lDataTransfer(BufferPtr,TransferMode,(BlockSize/4));
/* <<<DD_SDMMC_nonAPI_23_2>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* Block on Transfer Complete Interrupt */
    /* Timeout of 5ms.*/
    TimerId = SDMMC003_lStartTimer (SDMMC003_DELAY_IN_TRANSFER);
    if(0 == TimerId)
    {
      Status = (uint32_t) SDMMC003_START_TIMER_FAILED;
      ERROR(GID_SDMMC00x, Status, 0, NULL);   
      break; 
    }
    do
    {
      if (SDMMC003_Handle.TimerExpire == 0)
      {
        Status = (uint32_t)SDMMC003_TIMEOUT_OCCURED;
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }
    } while (SDMMC003_ISRContext.TransferFlag == 0);
    SDMMC003_lStopTimer(TimerId);
    SDMMC003_ISRContext.TransferFlag = 0;
    /* Check Transfer Complete Status */
/* <<<DD_SDMMC_nonAPI_23_4>>> */
    if (SDMMC003_Handle.TransferInterruptError == SDMMC003_TRANSFER_COMPLETE )
    {
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
/* <<<DD_SDMMC_nonAPI_23_5>>> */
    else
    {
      SDMMC003_Handle.IssueAbort = 1;
      Status = SDMMC003_lErrorInterruptRecovery(\
                                    SDMMC003_ISRContext.InterruptStatusShadow, \
                                    SDMMC003_Handle.IssueAbort);
      break;
    }
  } while(0);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_24>>> */
/*
 * This function checks the Lock Status .
 */
status_t SDMMC003_lCheckLockStatus( SDMMC003_CardLockMode OperationMode )
{
  status_t Status ;
  uint32_t LockStatus = 0;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  Status =  SDMMC003_GetLockStatus(&LockStatus);
  /* For Lock, Card State must be locked */
/* <<<DD_SDMMC_nonAPI_24_1>>> */
  if (Status == (uint32_t)DAVEApp_SUCCESS)
  {
    if ((LockStatus == (uint32_t)SDMMC003_CARD_IS_LOCKED) && \
                        (OperationMode == SDMMC003_LOCK) )
    {
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
/* <<<DD_SDMMC_nonAPI_24_2>>> */
    /* For UnLock, Card State must be unlock */
    else if( (LockStatus == (uint32_t)SDMMC003_CARD_UNLOCKED) && \
             (OperationMode == SDMMC003_UNLOCK) )
    {
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    /* Some Error */
    else
    {
      Status = (uint32_t)SDMMC003_LOCK_UNLOCK_ERROR;
    }
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_25>>> */
/*
 * This function switches the bus width to 4-bit if is supported.
 */
status_t SDMMC003_lSwitchBusWidth(void)
{
  uint32_t Argument = 0;
  status_t Status = (uint32_t)SDMMC003_ERROR;
  uint32_t CardStatus = 0;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    /* Switch to transfer state i.e. CMD7 */
    Status = SDMMC003_lSwitchToTransferState();
/* <<<DD_SDMMC_nonAPI_25_1>>> */
    if( Status != (uint32_t)DAVEApp_SUCCESS )
    {
      break;
    }
    /* Disable Card Interrupt */
    CLR_BIT( SDMMC->EN_INT_SIGNAL_NORM, SDMMC_EN_INT_STATUS_NORM_CARD_INS_EN_Pos );
    /* MMC Card */
/* <<<DD_SDMMC_nonAPI_25_2>>> */
#if SDMMC_SUPPORT_MMC_CARD
    if ((SDMMC003_Handle.CardType & SDMMC003_MMC) != 0)
    {
      Status = SDMMC003_lSendCommand (&(SDMMC003_MMC_COMMAND(6)), \
                                      MMC_4BUS_WIDTH_ARG,\
                                      SDMMC003_RESPONSE_R1, &CardStatus);
/* <<<DD_SDMMC_nonAPI_25_3>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
    }
/* SD card */
    else
#endif /* SDMMC_SUPPORT_MMC_CARD*/
    {
/* <<<DD_SDMMC_nonAPI_25_4>>> */
      /* Check the Data Transfer width supported in SCR Register */
      if( !(SDMMC003_CardInfo.Scr.SdBusWidth & SDMMC003_SCR_BUS_WIDTH4_BITMASK))
      {
        break;
      }
      /* Set the Argument.*/
      Argument |= SDMMC003_CardInfo.Rca << SDMMC003_ARG_RCA_BITPOS;
      /* Send Application Specific Command */
      Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(55)), \
                                      Argument, SDMMC003_RESPONSE_R1, \
                                      &CardStatus);
/* <<<DD_SDMMC_nonAPI_25_5>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
      /* Send ACMD6 to switch the bus width. */
      Status = SDMMC003_lSendCommand( &(SDMMC003_SD_COMMAND(58)), \
                                      SDMMC003_SD_4BUS_WIDTH_ARG, \
                                      SDMMC003_RESPONSE_R1, \
                                      &CardStatus);
/* <<<DD_SDMMC_nonAPI_25_6>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
    }
    /* Set Data Transfer Width  in Host Control Register. */
    SET_BIT( SDMMC->HOST_CTRL,SDMMC_HOST_CTRL_DATA_TX_WIDTH_Pos);
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_26>>> */
/*
 * This function switches the card speed to high speed if is supported.
 */
status_t  SDMMC003_lSwitchSpeed( void)
{
#if SDMMC_SUPPORT_MMC_CARD
uint32_t CardStatus;
#endif
  uint32_t SwitchStatus[16] = {0 };
  status_t Status = (uint32_t)SDMMC003_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
#if SDMMC_SUPPORT_MMC_CARD
/* <<<DD_SDMMC_nonAPI_26_1>>> */
    if ((SDMMC003_Handle.CardType & SDMMC003_MMC) != 0)
    {
      /* Switch to transfer state i.e. CMD7 */
      Status = SDMMC003_lSwitchToTransferState();
      if( Status != DAVEApp_SUCCESS )
      {
        break;
      }
      Status = SDMMC003_lSendCommand(&(SDMMC003_MMC_COMMAND(6)),
                                       MMC_HIGH_SPEED_ARG,\
                                       SDMMC003_RESPONSE_R1,&CardStatus);
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
    }
    /* SD card */
    else
#endif /* SDMMC_SUPPORT_MMC_CARD */
    {
/* <<<DD_SDMMC_nonAPI_26_2>>> */
      /* Check CMD6 support in SCR register*/
      if ( SDMMC003_CardInfo.Scr.SdSpec == 0 )
      {
        break;
      }
      /* Switch to transfer state i.e. CMD7 */
      Status = SDMMC003_lSwitchToTransferState();
/* <<<DD_SDMMC_nonAPI_26_3>>> */
      if( Status != (uint32_t)DAVEApp_SUCCESS )
      {
        break;
      }
      /* Send the Switch function  command and read the transferred block of
       * data from the card */
      Status = SDMMC003_lSingleBlockTransfer( &(SDMMC003_SD_COMMAND(6)), \
                                               SDMMC003_SD_HIGH_SPEED_ARG,64, \
                                               (uint32_t*)SwitchStatus, \
                                               SDMMC003_READ_FROM_BUFF
                                            );
/* <<<DD_SDMMC_nonAPI_26_4>>> */
      if ( Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
/* <<<DD_SDMMC_nonAPI_26_5>>> */
      if ( ((SwitchStatus[4] & SDMMC003_SWITCH_FUNC_GRP1_STATUS_BITMASK)>>
            SDMMC003_SWITCH_FUNC_GRP1_STATUS_BITPOS) != 1UL )
      {
        Status = (uint32_t)SDMMC003_ERROR;
        break;
      }
      /* Change Speed mode in the Host Controller */
      SET_BIT( SDMMC->HOST_CTRL,SDMMC_HOST_CTRL_HIGH_SPEED_EN_Pos );
    }
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/*
 * This function provides delay in command execution.
 */
status_t SDMMC003_lCommandDelay(uint32_t DelayTime)
{
  handle_t TimerId;
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  SDMMC003_Handle.TimerExpire = 1;
  TimerId = SDMMC003_lStartTimer(DelayTime);
  if(0 == TimerId)
  {
    Status = (uint32_t) SDMMC003_START_TIMER_FAILED;
  }
  if(Status != (uint32_t) SDMMC003_START_TIMER_FAILED)
  {
    do
    {
      /* If any error interrupt bit is set, then break*/
      if (SDMMC->INT_STATUS_NORM &  SDMMC_INT_STATUS_NORM_ERR_INT_Msk )
      {
        break;
      }
      if (SDMMC003_Handle.TimerExpire == 0)
      {
        Status = (uint32_t)SDMMC003_TIMEOUT_OCCURED;
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }
    } while (!(SDMMC003_ISRContext.CmdFlag  || \
             SDMMC003_ISRContext.DataFlag ));
  }
  SDMMC003_lStopTimer(TimerId);
  SDMMC003_ISRContext.CmdFlag = 0;
  SDMMC003_ISRContext.DataFlag = 0;
  return Status;
}


/* <<<DD_SDMMC_nonAPI_27>>> */
/*
 * This function performs the recovery task if any error interrupt occurs.
 */
status_t SDMMC003_lErrorInterruptRecovery(uint16_t InterruptStatus,
                                                    uint8_t IssueAbort)
{
  status_t Status =  (uint32_t)SDMMC003_NONRECOVERABLE_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    /* Disable the Error Interrupt Signal  */
    SDMMC->EN_INT_SIGNAL_ERR = 0;
    /* Check Error Interrupt Status bits D0-D3 for CMD line errors */
/* <<<DD_SDMMC_nonAPI_27_1>>> */
    if ( ((InterruptStatus & SDMMC003_ERROR_CMD_STATUS_BITMASK) != 0 ) ||  \
         ( SDMMC->PRESENT_STATE  & SDMMC_PRESENT_STATE_COMMAND_INHIBIT_CMD_Msk ))
    {
      /* Set Software Reset for CMD Line  */
      Status = SDMMC003_lReset(SDMMC_SW_RESET_SW_RST_CMD_LINE_Msk);
    }
/* <<<DD_SDMMC_nonAPI_27_2>>> */
    /* Check Error Interrupt Status bits D4-D6 for Data line errors */
    if ( ((InterruptStatus & SDMMC003_ERROR_DATA_STATUS_BITMASK) != 0 ) ||   \
         ( SDMMC->PRESENT_STATE  & SDMMC_PRESENT_STATE_COMMAND_INHIBIT_DAT_Msk ))
    {
      /*  Set Software Reset for Data Line */
/* <<<DD_SDMMC_nonAPI_27_3>>> */
      Status = SDMMC003_lReset( SDMMC_SW_RESET_SW_RST_DAT_LINE_Msk);
    }
    /*  Clear previous error status  */
    SDMMC->INT_STATUS_ERR = SDMMC003_ALL_ERROR_STATUS_BITMASK ;
    if (IssueAbort == 1)
    {   
      /*  Issue Abort Command.  */
      /*  Set argument register */
      SDMMC->ARGUMENT1 = SDMMC003_ARGUMENT0;
      SDMMC->COMMAND = (uint16_t)(*(uint16_t*)&(SDMMC003_COMMON_COMMAND(12)));  
/* Wait for any Interrupt status  bit to set */
/* <<<DD_SDMMC_nonAPI_27_4>>> */    
    /* Timeout of 5ms.*/
      Status =SDMMC003_lCommandDelay(SDMMC003_DELAY_IN_COMMAND);
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
    /* If error status bit is set in the Status register */
/* <<<DD_SDMMC_nonAPI_27_5>>> */
      if (SDMMC->INT_STATUS_ERR )
      {
        Status = (uint32_t)SDMMC003_NONRECOVERABLE_ERROR;
        SDMMC->INT_STATUS_ERR = SDMMC003_ALL_ERROR_STATUS_BITMASK ;
        SDMMC->INT_STATUS_NORM = SDMMC003_ALL_ERROR_STATUS_BITMASK ;
         /* Set Software Reset for CMD Line and Data Line  */
        SDMMC003_ReturnStatus = SDMMC003_lReset(SDMMC_SW_RESET_SW_RST_CMD_LINE_Msk | \
                                SDMMC_SW_RESET_SW_RST_DAT_LINE_Msk );
        break;
      }
    }
    /* Check Data lines status in present status register  */
/* <<<DD_SDMMC_nonAPI_27_6>>> */
    if (( (SDMMC->PRESENT_STATE  & SDMMC_PRESENT_STATE_DAT_3_0_PIN_LEVEL_Msk) >> \
           SDMMC_PRESENT_STATE_DAT_3_0_PIN_LEVEL_Pos) == SDMMC003_ALL_DATA_LINES_HIGH)
    {
      Status = (uint32_t)SDMMC003_RECOVERABLE_ERROR;
    }
    else
    {
      Status =  (uint32_t)SDMMC003_NONRECOVERABLE_ERROR;
    }
  } while(0);
  /* Enable the Error Interrupt signal */
  SDMMC->EN_INT_SIGNAL_ERR |= SDMMC003_ERROR_INT_SIGNAL_ENABLE;

  /* Global Error Recovery Variable */
  SDMMC003_Handle.ErrorRecoveryStatus = (SDMMC003_ErrorCodesType)Status;
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_28>>> */
/*
 * This function handles the Interrupt in Normal Interrupt Status Register.
 */
status_t SDMMC003_lNormalInterruptHandler (uint16_t IntStatus)
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
#if SDMMC_CARD_DETECTION_SUPPORT
/* <<<DD_SDMMC_nonAPI_28_1>>> */
  /* CARD REMOVAL INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_NORM_CARD_REMOVAL_Msk) != 0)
  {
    /* Confirm that the Card Insertion bit is clear in Present State Status*/
    do
    {
    } while(( SDMMC->PRESENT_STATE &  SDMMC_PRESENT_STATE_CARD_INSERTED_Msk)!= 0);
    /* Clear the Interrupt Status bit */
    SDMMC->INT_STATUS_NORM = SDMMC_INT_STATUS_NORM_CARD_REMOVAL_Msk;
    
    /* Call back to upper layer function for card removal interrupt*/
    if (SDMMC003_Handle.CallBackPtr != NULL)
    {
      SDMMC003_Handle.CallBackPtr(SDMMC003_CARD_REMOVAL); 
    }
    else
    {
      Status = SDMMC003_NULL_POINTER;
      ERROR(GID_SDMMC00x, Status,0,0);
    }
  }
/* <<<DD_SDMMC_nonAPI_28_2>>> */
  /* CARD INSERTION INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_NORM_CARD_INS_Msk) != 0)
  {
    /* Confirm that the Card Insertion bit is set in Present State Status*/
    do
    {
    } while((SDMMC->PRESENT_STATE & SDMMC_PRESENT_STATE_CARD_INSERTED_Msk) == 0);
    /* Clear the Interrupt Status */
    SDMMC->INT_STATUS_NORM = SDMMC_INT_STATUS_NORM_CARD_INS_Msk;

    /* Call back to upper layer function for card insertion interrupt*/
    if (SDMMC003_Handle.CallBackPtr != NULL)
    {
      SDMMC003_Handle.CallBackPtr(SDMMC003_CARD_INSERTION); 
    }
    else
    {
      Status = SDMMC003_NULL_POINTER;
      ERROR(GID_SDMMC00x, Status,0,0);
    }
  }
#endif
/* <<<DD_SDMMC_nonAPI_28_3>>> */
  /* BUFFER READ READY INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_NORM_BUFF_READ_READY_Msk) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.DataInterruptError = SDMMC003_BUFFER_READY;
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_NORM = SDMMC_INT_STATUS_NORM_BUFF_READ_READY_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.DataFlag = 1;
  }

/* <<<DD_SDMMC_nonAPI_28_4>>> */
  /* BUFFER WRITE READY INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_NORM_BUFF_WRITE_READY_Msk) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.DataInterruptError = SDMMC003_BUFFER_READY;
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_NORM = SDMMC_INT_STATUS_NORM_BUFF_WRITE_READY_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.DataFlag = 1;
  }
/* <<<DD_SDMMC_nonAPI_28_5>>> */
  /* TRANSFER COMPLETE INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_NORM_TX_COMPLETE_Msk ) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.TransferInterruptError = SDMMC003_TRANSFER_COMPLETE;
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_NORM = SDMMC_INT_STATUS_NORM_TX_COMPLETE_Msk;
    /* Change the data line Status  to be free */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_DATA_ACTIVE;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.TransferFlag = 1;
  }
  
/* <<<DD_SDMMC_nonAPI_28_6>>> */
  /* COMMAND COMPLETE INTERRUPT */
  if ((IntStatus &  SDMMC_INT_STATUS_NORM_CMD_COMPLETE_Msk) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.CommandInterruptError = SDMMC003_COMMAND_COMPLETE;
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_NORM = SDMMC_INT_STATUS_NORM_CMD_COMPLETE_Msk;
    /* Change the Command Line Status to free */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_CMD_ACTIVE;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.CmdFlag = 1;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return (uint32_t)Status;
}
/* <<<DD_SDMMC_nonAPI_29>>> */
/*
 * This function handles the Interrupt in Error Interrupt Status Register.
 */

status_t SDMMC003_lErrorInterruptHandler(uint16_t IntStatus)
{
  status_t Status = (uint32_t)SDMMC003_ERROR;

  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  SDMMC003_ISRContext.InterruptStatusShadow = IntStatus;
/* <<<DD_SDMMC_nonAPI_29_1>>> */
  /* COMMAND TIMEOUT ERROR INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_ERR_CMD_TIMEOUT_ERR_Msk)!= 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.CommandInterruptError = SDMMC003_COMMAND_TIMEOUT_ERROR;
    /* Change the Command Line Status to free */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_CMD_ACTIVE;
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_CommandErrorInterrupt == TRUE)
    {
      /* Forcefully disable the Command Timeout Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0000 ;
    }
   
    if (Test_TriggerInterrupt.Trigger_Cmd55Error == TRUE)
    {
     /* Forcefully disable the Command Timeout Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0000 ;
    }
    if (Test_TriggerInterrupt.Trigger_Command42Error == TRUE)
    {
     /* Forcefully disable the Command Timeout Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0000 ;
    }
#endif  /*SDMMC_UVP_TEST*/
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_ERR =  SDMMC_INT_STATUS_ERR_CMD_TIMEOUT_ERR_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.CmdFlag = 1;
  }
/* <<<DD_SDMMC_nonAPI_29_2>>> */
/* COMMAND CRC ERROR INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_ERR_CMD_CRC_ERR_Msk ) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.CommandInterruptError = SDMMC003_COMMAND_CRC_ERROR;
   /* Change the Command Line Status to free */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_CMD_ACTIVE;
   /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_ERR = SDMMC_INT_STATUS_ERR_CMD_CRC_ERR_Msk;
   /* Update the Interrupt variable */
    SDMMC003_ISRContext.CmdFlag = 1;
  }
/* <<<DD_SDMMC_nonAPI_29_3>>> */
  /* COMMAND END BIT ERROR INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_ERR_CMD_END_BIT_ERR_Msk ) != 0)
  {
   /* Update the Global Variable */
    SDMMC003_Handle.CommandInterruptError = SDMMC003_COMMAND_ENDBIT_ERROR;
   /* Change the Command Line Status to free */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_CMD_ACTIVE;
   /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_ERR = SDMMC_INT_STATUS_ERR_CMD_END_BIT_ERR_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.CmdFlag = 1;
  }
/* <<<DD_SDMMC_nonAPI_29_4>>> */
  /* COMMAND INDEX ERROR INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_ERR_CMD_IND_ERR_Msk ) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.CommandInterruptError = SDMMC003_COMMAND_INDEX_ERROR;
    /* Change the Command Line Status to free */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_CMD_ACTIVE;

#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_EraseEndError == TRUE)
    {
      /* Forcefully disable the Command Index Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0000 ;
    }
    if (Test_TriggerInterrupt.Trigger_EraseStartError == TRUE)
    {
      /* Forcefully disable the Command Index Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0000 ;
    }
#endif  /*SDMMC_UVP_TEST*/
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_ERR = SDMMC_INT_STATUS_ERR_CMD_IND_ERR_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.CmdFlag = 1;
  }
/* <<<DD_SDMMC_nonAPI_29_5>>> */
  /* DATA TIMEOUT ERROR INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_ERR_DATA_TIMEOUT_ERR_Msk) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.DataInterruptError = SDMMC003_DATA_TIMEOUT_ERROR;
    /* Change the Data line to free  */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_DATA_ACTIVE;
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_ERR = SDMMC_INT_STATUS_ERR_DATA_TIMEOUT_ERR_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.DataFlag = 1;
  }
/* <<<DD_SDMMC_nonAPI_29_6>>> */
  /* DATA CRC ERROR INTERRUPT  */
  if ((IntStatus & SDMMC_INT_STATUS_ERR_DATA_CRC_ERR_Msk) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.DataInterruptError = SDMMC003_DATA_CRC_ERROR;
    /* Change the Data line to free  */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_DATA_ACTIVE;
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_DataErrorInterrupt == TRUE)
    {
      /* Forcefully trigger the Data Crc Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0000 ;
      /* Enable the Buffer Ready Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM |= SDMMC_EN_INT_STATUS_NORM_BUFF_READ_READY_EN_Msk;
      SDMMC->EN_INT_SIGNAL_NORM |= SDMMC_EN_INT_SIGNAL_NORM_BUFF_READ_READY_EN_Msk;

       /* Enable the Buffer Ready Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM |= SDMMC_EN_INT_STATUS_NORM_BUFF_WRITE_READY_EN_Msk;
      SDMMC->EN_INT_SIGNAL_NORM |= SDMMC_EN_INT_SIGNAL_NORM_BUFF_WRITE_READY_EN_Msk;
    }
#endif
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_ERR = SDMMC_INT_STATUS_ERR_DATA_CRC_ERR_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.DataFlag = 1;
  }
/* <<<DD_SDMMC_nonAPI_29_7>>> */
  /*DATA END BIT ERROR INTERRUPT */
  if ((IntStatus & SDMMC_INT_STATUS_ERR_DATA_END_BIT_ERR_Msk) != 0)
  {
   /* Update the Global Variable */
   SDMMC003_Handle.DataInterruptError = SDMMC003_DATA_ENDBIT_ERROR;
   /* Change the Data line to free  */
   SDMMC003_Handle.State &= ~SDMMC003_STATE_DATA_ACTIVE;
   /* Clear the Interrupt Status Bit */
   SDMMC->INT_STATUS_ERR = SDMMC_INT_STATUS_ERR_DATA_END_BIT_ERR_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.DataFlag = 1;
  }
/* <<<DD_SDMMC_nonAPI_29_8>>> */
  /* ACMD12 ERROR INTERUPT */
  if ((IntStatus & SDMMC_INT_STATUS_ERR_ACMD_ERR_Msk) != 0)
  {
    /* Update the Global Variable */
    SDMMC003_Handle.AcmdInterruptError = SDMMC003_ACMD12_ERROR;
    /* Change the Cmd line to free  */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_CMD_ACTIVE;
    /* Change the Data line to free  */
    SDMMC003_Handle.State &= ~SDMMC003_STATE_DATA_ACTIVE;
    /* Clear the Interrupt Status Bit */
    SDMMC->INT_STATUS_ERR = SDMMC_INT_STATUS_ERR_ACMD_ERR_Msk;
    /* Update the Interrupt variable */
    SDMMC003_ISRContext.CmdFlag = 1;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_30>>> */
/*
 * This function is use to switch the card state to transferring state if the
 * card is not in the transferring state.
 */

status_t SDMMC003_lSwitchToTransferState()
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  uint32_t Argument = 0;
  uint32_t CardStatus = 0UL;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  /* Check the current state of the card */
  do
  { 
     Argument |= SDMMC003_CardInfo.Rca << SDMMC003_ARG_RCA_BITPOS;
    /* Send Cmd13 to read card status  */
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(13)),Argument, \
                                      SDMMC003_RESPONSE_R1,&CardStatus);
/* <<<DD_SDMMC_nonAPI_30_1>>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* <<<DD_SDMMC_nonAPI_30_2>>> */
    /* Check if it is in transferring state */
    if( (( CardStatus & SDMMC003_CSR_CURRENT_STATE_BITMASK) >>\
                               SDMMC003_CSR_CURRENT_STATE_BITPOS ) ==  \
                               SDMMC003_CSR_CURRENT_STATE_TRANS_VALUE )
    {
#if SDMMC_UVP_TEST
      if ( Test_TriggerInterrupt.Trigger_TransferStateError == TRUE)
      {
         /* Toggle to the Standby state.*/
        Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(7)),Argument, \
                                        SDMMC003_RESPONSE_R1b, &CardStatus);
        break;
      }
#endif
      Status = (uint32_t)DAVEApp_SUCCESS;
      break;
    }
    /* Switch to transfer state i.e. CMD7 */
/* <<<DD_SDMMC_nonAPI_30_3>>> */
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(7)),Argument, \
                                   SDMMC003_RESPONSE_R1b, &CardStatus);
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_nonAPI_31>>> */
/*
 * This function performs the data transfer to/from the card .
 */
status_t SDMMC003_lDataTransfer( uint32_t *BufferPtr, \
                              SDMMC003_DataTrasferType TransferMode, \
                              uint32_t QuadBytes)
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  handle_t TimerId;
  uint32_t Count = 0;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
/* Block on Buffer Read/Write Ready Interrupt */
/* <<<DD_SDMMC_nonAPI_31_1>>> */
    TimerId = SDMMC003_lStartTimer(SDMMC003_RESET_In_DATA_TRANSFER);
    if(0 == TimerId)
    {
      Status = (uint32_t) SDMMC003_START_TIMER_FAILED;
      ERROR(GID_SDMMC00x, Status, 0, NULL);  
      break;  
    }
    do
    {
      if (SDMMC003_Handle.TimerExpire == 0)
      {
        Status = (uint32_t)SDMMC003_TIMEOUT_OCCURED;
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }
    } while( SDMMC003_ISRContext.DataFlag == 0);
    SDMMC003_lStopTimer(TimerId);
    SDMMC003_ISRContext.DataFlag = 0;
    /* Check Buffer is ready */
/* <<<DD_SDMMC_nonAPI_31_2>>> */
    if (SDMMC003_Handle.DataInterruptError == SDMMC003_BUFFER_READY)
    {
     /* Non-DMA transfer */
/*<<<DD_SDMMC_nonAPI_31_7>>> */
      /* Data transfer 4bytes in each iteration  */
      for (Count=0; Count<QuadBytes; Count++)
      {
/*<<<DD_SDMMC_nonAPI_31_8>>> */
        if (TransferMode == SDMMC003_READ_FROM_BUFF)
        {
          *BufferPtr  = SDMMC->DATA_BUFFER;
        }
/*<<<DD_SDMMC_nonAPI_31_9>>> */
        if(TransferMode == SDMMC003_WRITE_INTO_BUFF)
        {
          SDMMC->DATA_BUFFER = *BufferPtr;
        }
        BufferPtr++;
      }
      Status = (uint32_t)DAVEApp_SUCCESS;
    }/* End of "if (SDMMC_Handle.DataInterruptError == SDMMC003_BUFFER_READY)" */
/*<<<DD_SDMMC_nonAPI_31_10>>> */
    else
    {
      SDMMC003_Handle.IssueAbort = 1;
      Status = SDMMC003_lErrorInterruptRecovery(\
                              SDMMC003_ISRContext.InterruptStatusShadow, \
                              SDMMC003_Handle.IssueAbort);
    }
  } while(0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/*
 * This function checks the PCMD flag.
 */
void SDMMC003_CheckPCMDFlag(status_t PCMDFlag)
{
  SDMMC003_ReturnStatus  = 1UL;
  if (PCMDFlag == 1)
  {
    ERROR(GID_SDMMC00x, SDMMC003_ACMD_BOTH_ERROR,0,0);
  }
  else
  {
    ERROR(GID_SDMMC00x, SDMMC003_ACMD_SD_TRANSFER_ERROR,0,0);
  }
}

/* <<<DD_SDMMC_nonAPI_32>>> */
/*
 * This function performs the ACMD error Recovery.
 */
void SDMMC003_lAcmdErrorRecovery()
{
  status_t Status;
  status_t PCMDFlag = 0;
  uint32_t CardStatus = 0;
  do
  {
/* <<<DD_SDMMC_nonAPI_32_1>>> */
    /** Check Auto CMD12 Not Executed Err in Auto CMd12 Error Status Register */
    if ( ((SDMMC->ACMD_ERR_STATUS & SDMMC_ACMD_ERR_STATUS_ACMD12_NOT_EXEC_ERR_Msk) >> \
            SDMMC_ACMD_ERR_STATUS_ACMD12_NOT_EXEC_ERR_Pos)  == 1)
    {
      /* Set PCMDFlag to 1*/
      PCMDFlag = 1;
      /* Check Return Status of Recovery function of CMD_wo_DAT command */
/* <<<DD_SDMMC_nonAPI_32_2>>> */
      if (SDMMC003_Handle.ErrorRecoveryStatus != SDMMC003_RECOVERABLE_ERROR)
      {
        ERROR(GID_SDMMC00x, SDMMC003_NONRECOVERABLE_ERROR,0,0);
        break;
      }
      /* For recoverable error, issue CMD12 */
      Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(12)), \
                                      SDMMC003_ARGUMENT0, \
                                      SDMMC003_RESPONSE_R1, &CardStatus);
      /* No Error */
/* <<<DD_SDMMC_nonAPI_32_3>>> */
      if (Status == (uint32_t)DAVEApp_SUCCESS)
      {
        ERROR(GID_SDMMC00x, SDMMC003_ACMD_CMD_wo_DAT_ERROR,0,0);
        break;
      }
/* <<<DD_SDMMC_nonAPI_32_4>>> */
      /* Non Recoverable Error */
      if (Status == (uint32_t)SDMMC003_NONRECOVERABLE_ERROR)
      {
        ERROR(GID_SDMMC00x, Status,0,0);
        break;
      }
    }
/* <<<DD_SDMMC_nonAPI_32_5>>> */
    else
    {
      /* Set software reset for CMD line */
      Status = SDMMC003_lReset(SDMMC_SW_RESET_SW_RST_CMD_LINE_Msk);
      if ( Status !=(uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
      /* Issue Cmd 12*/
/* <<<DD_SDMMC_nonAPI_32_6>>> */
      Status = SDMMC003_lSendCommand(  &(SDMMC003_COMMON_COMMAND(12)), \
                                      SDMMC003_ARGUMENT0, \
                                      SDMMC003_RESPONSE_R1, \
                                      &CardStatus);
      /* Non Recoverable Error */
/* <<<DD_SDMMC_nonAPI_32_7>>> */
      if (Status == (uint32_t)SDMMC003_NONRECOVERABLE_ERROR)
      {
        ERROR(GID_SDMMC00x, Status,0,0);
        break;
      }
    }
    /*Set Software Reset for  Data line*/
    Status = SDMMC003_lReset(SDMMC_SW_RESET_SW_RST_DAT_LINE_Msk);
    if ( Status !=(uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* <<<DD_SDMMC_nonAPI_32_8>>> */
    /*Check Command Not issued by Auto CMD12 Error */
    if (((SDMMC->ACMD_ERR_STATUS & SDMMC_ACMD_ERR_STATUS_CMD_NOT_ISSUED_BY_ACMD12_ERR_Msk) >> \
            SDMMC_ACMD_ERR_STATUS_CMD_NOT_ISSUED_BY_ACMD12_ERR_Pos) == 1)
    {
      ERROR(GID_SDMMC00x, SDMMC003_ACMD_CMD_wo_DAT_NOT_ISSUED,0,0);
    }
/* <<<DD_SDMMC_nonAPI_32_9>>> */
    else
    {
     /* Check PCMD flag.If 1 means that An error occurred in CMD_wo_DAT,
      *  and also occurred in the SD memory transfer */
      SDMMC003_CheckPCMDFlag(PCMDFlag);
    }
  } while(0);
}

void Timer_CallBack(void* Temp)
{
  if (Temp != NULL)
  {
    SDMMC003_ReturnStatus = (status_t)Temp;
  }
  SDMMC003_Handle.TimerExpire =0;
}


/* <<< DD_SDMMC_nonAPI_33 >>> */
/**
 * This function is used to some delay.
 */
void SDMMC003_lDelay(uint32_t DelayTime)
{
  handle_t TimerId;
  status_t Status;
  SDMMC003_Handle.TimerExpire = 1;
  TimerId = SYSTM001_CreateTimer(DelayTime,SYSTM001_ONE_SHOT,Timer_CallBack,NULL);
  if(TimerId != 0)
  {
    /* Timer is created successfully */
    Status = SYSTM001_StartTimer(TimerId);
    if(Status == DAVEApp_SUCCESS)
    {
      /* Wait in infinite loop till the timer expires */
      while(SDMMC003_Handle.TimerExpire)
      {
      }
      /* stop the timer */
      Status = SYSTM001_StopTimer(TimerId);
      /* Delete the Timer*/
      if(Status == DAVEApp_SUCCESS)
      {
        SDMMC003_ReturnStatus = SYSTM001_DeleteTimer(TimerId);
      } /* End of " if(Status == DAVEApp_SUCCESS)"*/
    } /* End of " if(Status == DAVEApp_SUCCESS)"*/
  }/* End of "if(TimerId != 0)" */
}

/* <<< DD_SDMMC_nonAPI_34 >>>
 *  SDMMC Interrupt Handler */
void SDMMC0_0_IRQHandler()
{
  uint32_t Status;
  NormalIntStatus = SDMMC->INT_STATUS_NORM;
  ErrorIntStatus  = SDMMC->INT_STATUS_ERR;
/* <<< DD_SDMMC_nonAPI_34_1 >>> */
  if (NormalIntStatus & SDMMC_INT_STATUS_NORM_ERR_INT_Msk)
  {
    Status = SDMMC003_lErrorInterruptHandler( ErrorIntStatus );
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      ERROR(GID_SDMMC00x, Status,0,0);
    }
  }
/* <<< DD_SDMMC_nonAPI_34_2 >>> */
  if(NormalIntStatus & SDMMC003_NORMAL_INT_STATUS_BITS)
  {
    Status = SDMMC003_lNormalInterruptHandler( NormalIntStatus);
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      ERROR(GID_SDMMC00x, Status,0,0);
    }
  }
}


/* <<< DD_SDMMC_nonAPI_36 >>> */
/*
 * This function performs the card initialization and identification operation.
 */
status_t SDMMC003_lCardIdentificationProcess()
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  handle_t TimerId = 0;
  /* Silicon Testing Added */
  do
  {
/* <<< DD_SDMMC_nonAPI_36_1 >>> */
   /* Wait till the Internal clock gets Stable.*/
    TimerId = SDMMC003_lStartTimer(SDMMC003_CLOCK_STABLE_DELAY);
    if(0 == TimerId)
    {
      Status = (uint32_t) SDMMC003_START_TIMER_FAILED;
      ERROR(GID_SDMMC00x, Status, 0, NULL);  
      break; 
    }
    do
    {
      if (SDMMC003_Handle.TimerExpire == 0)
      {
        Status = (uint32_t)SDMMC003_TIMEOUT_OCCURED;
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }
    } while((SDMMC->CLOCK_CTRL & SDMMC_CLOCK_CTRL_INTERNAL_CLOCK_STABLE_Msk ) == 0);
    SDMMC003_lStopTimer(TimerId);    
    if (Status == (uint32_t)SDMMC003_TIMEOUT_OCCURED )
    {
      break; 
    }
    /* Enable the SD clock */
    SDMMC->CLOCK_CTRL |= SDMMC_CLOCK_CTRL_SDCLOCK_EN_Msk;
    /* Set Power Control Register */
    SET_BIT( SDMMC->POWER_CTRL, SDMMC_POWER_CTRL_SD_BUS_POWER_Pos);
/* <<< DD_SDMMC_nonAPI_36_2 >>> */    
    if(SDMMC003_Handle.InitializeFlag == 0)
    {
      Status  = SDMMC003_lInitializeCard();
/* <<< DD_SDMMC_nonAPI_36_3 >>> */    
      if( Status != (uint32_t)DAVEApp_SUCCESS )
      {
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }/* End of " if( Status != DAVEApp_SUCCESS )"*/
      Status = SDMMC003_lAfterCardInitialize();
/* <<< DD_SDMMC_nonAPI_36_4 >>> */  
      if( Status != (uint32_t)DAVEApp_SUCCESS )
      {
        ERROR(GID_SDMMC00x, Status, 0, NULL);
        break;
      }/* End of "if(Status != DAVEApp_SUCCESS )" */
    }/* End of "if((SDMMC003_Handle.State & SDMMC003_STATE_CARD_INITIALIZED)== 0 )"*/
  } while(0);
  return Status;
}

/* <<< DD_SDMMC_nonAPI_37 >>> */
/**
 * This function is used to create and start timer in NON-RTOS environment.
 */
handle_t SDMMC003_lStartTimer(uint32_t DelayTime)
{
  handle_t TimerId;
  status_t Status;
  SDMMC003_Handle.TimerExpire = 1;
  TimerId = SYSTM001_CreateTimer(DelayTime,SYSTM001_ONE_SHOT,Timer_CallBack,NULL);
/* <<< DD_SDMMC_nonAPI_37_1 >>> */
  if(TimerId != 0)
  {
    /* Timer is created successfully */
    Status = SYSTM001_StartTimer(TimerId);
/* <<< DD_SDMMC_nonAPI_37_2 >>> */
    if(DAVEApp_SUCCESS != Status)
    {
      /*Delete Timer*/
      SDMMC003_ReturnStatus = SYSTM001_DeleteTimer(TimerId);
      TimerId = 0;
    }
  }
  return TimerId;
}

/* <<< DD_SDMMC_nonAPI_38 >>> */
/**
 * This function is used to stop timer in NON-RTOS environment.
 */
void SDMMC003_lStopTimer(handle_t TimerId)
{
  status_t Status;
  /* stop the timer */
  Status = SYSTM001_StopTimer(TimerId);
  /* Delete the Timer*/
/* <<< DD_SDMMC_nonAPI_38_1 >>> */
  if(Status == DAVEApp_SUCCESS)
  {
    SDMMC003_ReturnStatus = SYSTM001_DeleteTimer(TimerId);
  }
}


/* <<< DD_SDMMC_nonAPI_39 >>> */
/**
 * This function is used to check the sector address is out of bound or not.
 */
status_t SDMMC003_lCheckSectorBound (uint32_t SectorNumberParam, \
                                     uint32_t SectorCountParam)
{
  status_t Status;
  uint32_t SectorCount = 0;
  do
  {
/* Get Sector Count function   */  
/* <<< DD_SDMMC_nonAPI_39_1 >>> */
    Status = SDMMC003_GetSectorCount((void *)&SectorCount);
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* <<< DD_SDMMC_nonAPI_39_2 >>> */
/* Check the Sector Count limit */
    if((SectorNumberParam + SectorCountParam) >= SectorCount)
    {
      Status = (uint32_t)SDMMC003_SECTOR_OUT_OF_BOUND;
    }
  } while(0);
  return Status;
}

/*
 * The function performs the actual erase operation.
 */
status_t SDMMC003_lLocalErase
(
  uint32_t StartAddr,
  uint32_t EndAddr,
  uint32_t TimeoutVal
)
{
  /* Stores the response received  */
  uint32_t CardStatus = 0;
  status_t Status = (uint32_t)SDMMC003_ERROR;
  do
  {
  /* <<<DD_SDMMC_API_7_3>>> */
    if ((SDMMC003_Handle.CardType & SDMMC003_BLOCK_ADDRESSING) == 0UL)
    {
      StartAddr *= 512UL;
      EndAddr *=  512UL;
    }/*End of "if((SDMMC003_Handle.CardType & SDMMC003_BLOCK_ADDRESSING) == 0UL)" */
  /* MMC Card */
#if SDMMC_SUPPORT_MMC_CARD
/* <<<DD_SDMMC_API_7_4>>> */
    if ((SDMMC003_Handle.CardType & SDMMC003_MMC) != 0 )
    {
/* Erase Start Command */
#if SDMMC_UVP_TEST
      if (Test_TriggerInterrupt.Trigger_EraseStartError == TRUE)
      {
        /* Forcefully trigger the Command Index Error Interrupt */
        /* Disable the Command Complete Status Interrupt */
        SDMMC->EN_INT_STATUS_NORM &= ~( SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
        /* Disable the Command Complete Signal Interrupt */
        SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk );
      }
#endif
      Status = SDMMC003_lSendCommand( &(SDMMC003_MMC_COMMAND(35)),\
                                              StartAddr, RESPONSE_R1, &CardStatus );
/* <<<DD_SDMMC_API_7_5>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
      /* Erase End Command */
#if SDMMC_UVP_TEST
      if (Test_TriggerInterrupt.Trigger_EraseEndError == TRUE)
      {
        /* Disable the Command Complete Status Interrupt */
        SDMMC->EN_INT_STATUS_NORM &= ~( SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
        /* Disable the Command Complete Signal Interrupt */
        SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk );
      }
#endif
      Status = SDMMC003_lSendCommand( &(SDMMC003_MMC_COMMAND(36)),EndAddr, \
                                             RESPONSE_R1,&CardStatus );
/* <<<DD_SDMMC_API_7_6>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
         break;
      }
    }
    /* SD Card */
    else
#endif /* SDMMC_SUPPORT_MMC_CARD */
    {
#if SDMMC_UVP_TEST
      if (Test_TriggerInterrupt.Trigger_EraseStartError == TRUE)
      {
        /* Forcefully trigger the Command Index Error Interrupt */
      //  SDMMC->FORCE_EVENT_ERR_STATUS = 0x0004 ;
        /* Disable the Command Complete Status Interrupt */
        SDMMC->EN_INT_STATUS_NORM &= ~( SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
        /* Disable the Command Complete Signal Interrupt */
        SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk );
      }
#endif
/* <<<DD_SDMMC_API_7_7>>> */
      /* SD Erase Start Command */
      Status = SDMMC003_lSendCommand( &(SDMMC003_SD_COMMAND(32)), \
                                              StartAddr, SDMMC003_RESPONSE_R1, &CardStatus);
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
         break;
      } /* if (Status != (uint32_t)DAVEApp_SUCCESS) */
      /* SD Erase End Command */
#if SDMMC_UVP_TEST
      if (Test_TriggerInterrupt.Trigger_EraseEndError == TRUE)
      {
        /* Forcefully trigger the Command Index Error Interrupt */
     //   SDMMC->FORCE_EVENT_ERR_STATUS = 0x0004 ;
        /* Disable the Command Complete Status Interrupt */
        SDMMC->EN_INT_STATUS_NORM &= ~( SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
        /* Disable the Command Complete Signal Interrupt */
        SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk );
      }
#endif
      Status = SDMMC003_lSendCommand( &(SDMMC003_SD_COMMAND(33)),EndAddr, \
                                      SDMMC003_RESPONSE_R1, &CardStatus);
/* <<<DD_SDMMC_API_7_8>>> */
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
         break;
      }/* End of " if (Status != (uint32_t)DAVEApp_SUCCESS)"*/
    }/* End of "if SD card"*/
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_DataErrorInterrupt == TRUE)
    {
      /* Disable the Transfer Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_TX_COMPLETE_EN_Msk);
      /* Disable the Transfer Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_SIGNAL_NORM_TX_COMPLETE_EN_Msk  );
    }

    if (Test_TriggerInterrupt.Trigger_TransferInterruptError == TRUE)
    {
      /* Disable the Transfer Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~(SDMMC_EN_INT_STATUS_NORM_TX_COMPLETE_EN_Msk);
      /* Disable the Transfer Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM &= ~(SDMMC_EN_INT_SIGNAL_NORM_TX_COMPLETE_EN_Msk  );
    }
#endif
    Status = SDMMC003_lSendCommand( &(SDMMC003_SD_COMMAND(38)),
                                    SDMMC003_ARGUMENT0,
                                    SDMMC003_RESPONSE_R1b,
                                    &CardStatus);   
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
       break;
    }/* End of " if (Status != (uint32_t)DAVEApp_SUCCESS)"*/
    SDMMC003_lDelay(TimeoutVal * 1000);
  } while(0);
  return Status;
}

/**
 * @endcond
 */
/*CODE_BLOCK_END*/







