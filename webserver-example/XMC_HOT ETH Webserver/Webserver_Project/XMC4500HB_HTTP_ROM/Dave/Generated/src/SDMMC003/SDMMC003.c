
/* CODE_BLOCK_BEGIN[SDMMC003.c]*/

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
** MODIFICATION DATE : Oct 1, 2012                                         **
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
 * @file   SDMMC003.c
 *
 * @App Version SDMMC003 <1.0.14>
 *
 * @brief  This file contains of all public function definations of SDMMC LLD App.
 *
 * Revision History
 * 22 March 2012  v1.0.0    Initial version
 * 3 Aug 2012     v1.0.12   Erase optimizations introduced.
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




/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


#if SDMMC_UVP_TEST
extern Test_TriggerInterruptType Test_TriggerInterrupt;
#endif

/** Handle Structure containing all the run-time card information  */
volatile SDMMC003_HandleType SDMMC003_Handle = {0};

extern SDMMC003_CardInfoType SDMMC003_CardInfo ;
 
extern const SDMMC003_CommandType SDMMC003_Command[40];
extern const uint8_t  SDMMC003_SDHashTable[65];

#if SDMMC_SUPPORT_MMC_CARD
extern const uint8_t SDMMC003_MMCHashTable[64] ;
#endif /* SDMMC_SUPPORT_MMC_CARD */



/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/

/*<<<DD_SDMMC_API_1>>> */
/*
 * The function initializes the Host Controller with the reset values and
 * configure values in the Host Controller registers.
 */
status_t SDMMC003_HostControllerInit(void)
{
  status_t Status = (uint32_t) DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
/*<<<DD_SDMMC_API_1_1>>> */
    /* Check Host Controller is initialized or not */
    if ((SDMMC003_Handle.State & SDMMC003_STATE_HC_INITIALIZED) != 0)
    {
      Status = (uint32_t)SDMMC003_HOST_CONTROLLER_INITIALIZED;
      break;
    }
    /* 1. Reset the registers to default values in Software Reset Control
     * Register
     */
/*<<<DD_SDMMC_API_1_2>>> */
    Status  = SDMMC003_lReset( SDMMC_SW_RESET_SW_RST_ALL_Msk );
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /* Set Clock Control  register */
    SDMMC->CLOCK_CTRL |= ((SDMMC_CLOCK_CTRL_SDCLK_FREQ_SEL_Msk & \
                          (SDMMC003_CTRL_SDCLK_FREQ_SEL_VALUE << \
                          SDMMC_CLOCK_CTRL_SDCLK_FREQ_SEL_Pos)) | \
                          (SDMMC_CLOCK_CTRL_INTERNAL_CLOCK_EN_Msk) \
    );
    /* Set Normal Interrupt Status Enable & Error Interrupt Status Enable register */
    SDMMC->EN_INT_STATUS_NORM = SDMMC003_NORMAL_INT_STATUS_ENABLE;
    SDMMC->EN_INT_STATUS_ERR = SDMMC003_ERROR_INT_STATUS_ENABLE ;

    /* Set Interrupt Signal Enable & Error Interrupt Signal Enable register*/
    SDMMC->EN_INT_SIGNAL_NORM = SDMMC003_NORMAL_INT_SIGNAL_ENABLE;
    SDMMC->EN_INT_SIGNAL_ERR = SDMMC003_ERROR_INT_SIGNAL_ENABLE;

    /* Set Timeout Control Register */
    SDMMC->TIMEOUT_CTRL |= ( SDMMC_TIMEOUT_CTRL_DAT_TIMEOUT_CNT_VAL_Msk &\
                                 ( SDMMC003_CTRL_DAT_TIMEOUT_CNT_VAL_VALUE << \
                                    SDMMC_TIMEOUT_CTRL_DAT_TIMEOUT_CNT_VAL_Pos )\
                                 );
   /* Set bus voltage in the Power Control Register */
    SDMMC->POWER_CTRL |= ( SDMMC_POWER_CTRL_SD_BUS_VOLTAGE_SEL_Msk &\
                           (SDMMC003_CTRL_SD_BUS_VOLTAGE_SEL_VALUE  << \
                            SDMMC_POWER_CTRL_SD_BUS_VOLTAGE_SEL_Pos )
                          );
    /* Update the state status to card initialized  */
    SDMMC003_Handle.State |= (SDMMC003_STATE_HC_INITIALIZED | SDMMC003_STATE_NO_CARD) ;
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_API_2 >>> */
/*
 * The function de-initialize the Host Controller to the reset values.
 */
status_t  SDMMC003_HostControllerDeInit(void)
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
/* <<<DD_SDMMC_API_2_1>>> */
    /* Check the host controller is initialized or not */
    if((SDMMC003_Handle.State & SDMMC003_STATE_HC_INITIALIZED) == 0)
    {
      break;
    }/*End of"if((SDMMC003_Handle.State & SDMMC003_STATE_HC_INITIALIZED)== 0)"*/
    /* Cleanup the card. */
    SDMMC003_lCardCleanUp();
    /* Reset the Host Controller registers */
/* <<<DD_SDMMC_API_2_2>>> */
    Status = SDMMC003_lReset( SDMMC_SW_RESET_SW_RST_ALL_Msk );
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    Status = (uint32_t)DAVEApp_SUCCESS;
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_API_3>>> */
/*
 * The function is used to read multiple blocks of data from the card.
 */
status_t SDMMC003_CardReadMultipleBlocks
(
  uint32_t  *ReadBufPtr,
  uint32_t  ReadAddr,
  uint32_t  NumberOfBlocks
)
{
  status_t Status = (uint32_t)SDMMC003_READ_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    SDMMC003_Handle.CommandInterruptError = SDMMC003_ERROR;
    SDMMC003_Handle.DataInterruptError = SDMMC003_ERROR;
    SDMMC003_Handle.TransferInterruptError = SDMMC003_ERROR;
/* <<<DD_SDMMC_API_3_1>>> */    
    /*Check Whether Initialization Process is successful */
    if (SDMMC003_Handle.InitializeFlag != 1 )
    {
      Status = (uint32_t)SDMMC003_INIT_FAIL;     
      break;
    }
/* <<<DD_SDMMC_API_3_2>>> */
    /* Check Sector number is not out of bound */
    Status = SDMMC003_lCheckSectorBound(ReadAddr,NumberOfBlocks);
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /* Set transfer direction select in the Transfer Mode Register */
    SET_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_TX_DIR_SELECT_Pos);
/* <<<DD_SDMMC_API_3_3>>> */
    /* Send Multiple Block  Read Command i.e CMD18 */
    Status = SDMMC003_lMultiBlockTransfer( &ReadAddr, \
                                           NumberOfBlocks, \
                                           &(SDMMC003_COMMON_COMMAND(18)), \
                                           ReadBufPtr, \
                                           SDMMC003_READ_FROM_BUFF);
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_API_4>>> */
/*
 * The function is used to read single block of data from the card.
 */
status_t SDMMC003_CardReadSingleBlock
(
  uint32_t *ReadBufPtr,
  uint32_t  ReadAddr
)
{
  status_t Status = (uint32_t)SDMMC003_READ_ERROR;
  uint32_t SectorCount = 1UL;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
/* <<<DD_SDMMC_API_4_1>>> */
    /*Check Whether Initialization Process is successful */
    if (SDMMC003_Handle.InitializeFlag != 1 )
    {
      Status = (uint32_t)SDMMC003_INIT_FAIL;
      break;
    }
/* <<<DD_SDMMC_API_4_2>>> */
    /* Check Sector number is not out of bound */
    Status = SDMMC003_lCheckSectorBound(ReadAddr,SectorCount);
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* <<<DD_SDMMC_API_4_3>>> */
    /* Block Addressing or Byte Addressing */
    if ((SDMMC003_Handle.CardType & SDMMC003_BLOCK_ADDRESSING) == 0UL)
    {
      ReadAddr *= 512UL;
    } /*End of "if((SDMMC003_Handle.CardType & SDMMC003_BLOCK_ADDRESSING)== 0UL)"*/
    /* Set Direction select in transfer mode register */
    SET_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_TX_DIR_SELECT_Pos);
    /* Perform the Single block transfer operation */
/* <<<DD_SDMMC_API_4_4>>> */
    Status = SDMMC003_lSingleBlockTransfer( &(SDMMC003_COMMON_COMMAND(17)), \
                                            ReadAddr, \
                                            SDMMC003_BLOCK_SIZE, \
                                            ReadBufPtr, \
                                            SDMMC003_READ_FROM_BUFF  );
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_API_5>>> */
/*
 * The function is used to write multiple blocks of data on the card.
 */
status_t SDMMC003_CardWriteMultipleBlocks
(
  const uint32_t *WriteBufPtr,
  uint32_t WriteAddr,
  uint32_t NumberOfBlocks
)
{
  status_t Status = (uint32_t)SDMMC003_WRITE_ERROR; 
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    SDMMC003_Handle.CommandInterruptError = SDMMC003_ERROR;
    SDMMC003_Handle.DataInterruptError = SDMMC003_ERROR;
    SDMMC003_Handle.TransferInterruptError = SDMMC003_ERROR;
/* <<<DD_SDMMC_API_5_1>>> */    
    /*Check Whether Initialization Process is successfull */
    if (SDMMC003_Handle.InitializeFlag != 1 )
    {
      Status = (uint32_t)SDMMC003_INIT_FAIL;
      break;
    }
/* <<<DD_SDMMC_API_5_2>>> */       
    /* Check Sector number is not out of bound */
    Status = SDMMC003_lCheckSectorBound(WriteAddr,NumberOfBlocks);
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* Clear transfer direction select in Transfer Mode Register */
    CLR_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_TX_DIR_SELECT_Pos);

/* Send Multiple Block  Write  Command i.e CMD25 */
/* <<<DD_SDMMC_API_5_3>>> */
    Status = SDMMC003_lMultiBlockTransfer( &WriteAddr, \
                                           NumberOfBlocks,\
                                           &(SDMMC003_COMMON_COMMAND(25)),\
                                           (uint32_t *)WriteBufPtr,\
                                           SDMMC003_WRITE_INTO_BUFF);
    } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_API_6>>> */
/*
 * The function is used to write single block of data on the card.
 */
status_t SDMMC003_CardWriteSingleBlock
(
  const uint32_t *WriteBufPtr,
  uint32_t WriteAddr
)
{
  status_t Status = (uint32_t)SDMMC003_WRITE_ERROR;
  uint32_t SectorCount = 1UL;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
/* <<<DD_SDMMC_API_6_1>>> */    
    /*Check Whether Initialization Process is successful */
    if (SDMMC003_Handle.InitializeFlag != 1 )
    {
      Status = (uint32_t)SDMMC003_INIT_FAIL;
      break;
    }
/* <<<DD_SDMMC_API_6_2>>> */    
    /* Check Sector number is not out of bound */
    Status = SDMMC003_lCheckSectorBound(WriteAddr,SectorCount);
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /* If not Block Addressing then multiply by 512 bytes. */
/* <<<DD_SDMMC_API_6_3>>> */
    if ((SDMMC003_Handle.CardType & SDMMC003_BLOCK_ADDRESSING) == 0UL)
    {
      WriteAddr *= 512UL;
    } /*End of "if((SDMMC003_Handle.CardType & SDMMC003_BLOCK_ADDRESSING) == 0UL)"*/
    /* Clear Transfer Direction Select bit in Transfer Mode Register */
    CLR_BIT( SDMMC->TRANSFER_MODE,SDMMC_TRANSFER_MODE_TX_DIR_SELECT_Pos);
    /* Single Block Transfer function */
/* <<<DD_SDMMC_API_6_4>>> */
    Status = SDMMC003_lSingleBlockTransfer( &(SDMMC003_COMMON_COMMAND(24)), \
                                            WriteAddr, \
                                            SDMMC003_BLOCK_SIZE, \
                                            (uint32_t *)WriteBufPtr, \
                                            SDMMC003_WRITE_INTO_BUFF);
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_API_7>>> */
/*
 * The function is used to erase data from the card.
 */
status_t SDMMC003_EraseBlock
(
  uint32_t StartAddr,
  uint32_t EndAddr
)
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  uint32_t NumOfSectors = 0;
 /* Alocation Unit to No. of Sectors in 1 AU table mapping*/
  uint32_t AuToSectors[10] = { 0,   32,  64,  128,  256,
                               512, 1024, 2048, 4096, 8192
                             };
  uint16_t EraseSize = 0;
  uint8_t EraseOffset = 0;
  uint8_t EraseTimeout = 0;
  uint8_t AUSize = 0;
  uint32_t SectorsInAu = 0;
  uint32_t SectorsInEraseCluster = 0;
  /* Read SD Status  */
  uint32_t SdStatus[16] = {0};
  uint32_t EraseTimeoutPerCluster = 0;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  SDMMC003_Handle.CommandInterruptError = SDMMC003_ERROR;
  SDMMC003_Handle.DataInterruptError = SDMMC003_ERROR;
  SDMMC003_Handle.TransferInterruptError = SDMMC003_ERROR;
  do
  {
/* <<<DD_SDMMC_API_7_1>>> */
    /*Check Whether Initialization Process is successful */
    if (SDMMC003_Handle.InitializeFlag != 1 )
    {
      Status = (uint32_t)SDMMC003_INIT_FAIL;
      break;
    }
    NumOfSectors = EndAddr - StartAddr;
/* <<<DD_SDMMC_API_7_2>>> */    
    /* Check Sector number is not out of bound */
    Status = SDMMC003_lCheckSectorBound(StartAddr,NumOfSectors);
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* Erase Timeout Calculation */
/* Get SD Status */
    Status  = SDMMC003_GetSdStatus((void*)&(SdStatus[0]));
/* <<<DD_SDMMC_API_7_3>>> */
    if (Status != DAVEApp_SUCCESS)
    {
      break;
    }
    /* Bits 400-401 in SD status is Erase Offset */
    EraseOffset =  ((SdStatus[3] & 0x00000300)) >> 8;
    /* Bits 402-407 in SD status is Erase Timeout */
    EraseTimeout = ((SdStatus[3] & 0x0000FC00)) >> 10;
    /* Bits 408-423 in SD status is Erase Size */
    EraseSize = ( (((SdStatus[2] & 0xFF000000) >> 24) << 8) | \
                   (SdStatus[3] & 0x000000FF) );
    /* Bits 428-431 in SD status is Allocation unit Size*/              
    AUSize  =    (( SdStatus[2] & 0x00F00000) >> 20);
    /* Erase Timeout Calculations */
    EraseTimeoutPerCluster = (EraseTimeout/EraseSize) +  EraseOffset  ;
    /* Number of Sectors in 1AU */
    SectorsInAu = AuToSectors[AUSize];
    SectorsInEraseCluster = SectorsInAu * EraseSize;
#if SDMMC_UVP_TEST
  if (Test_TriggerInterrupt.Trigger_TC23_1Error == TRUE)
  {
    Test_TriggerInterrupt.Trigger_EraseStartError = TRUE;
  }
  if (Test_TriggerInterrupt.Trigger_TC23_1Error == TRUE)
  {
    Test_TriggerInterrupt.Trigger_EraseEndError = TRUE;
  }
#endif
    while (NumOfSectors > SectorsInEraseCluster)
    {
      Status = SDMMC003_lLocalErase(StartAddr,(StartAddr + SectorsInEraseCluster), \
                                    EraseTimeoutPerCluster);
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
      StartAddr  = StartAddr + SectorsInEraseCluster;
      NumOfSectors = NumOfSectors - SectorsInEraseCluster;
    }
    if (NumOfSectors != 0 )
    {
      Status = SDMMC003_lLocalErase(StartAddr,EndAddr,EraseTimeoutPerCluster);
      if (Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
    }
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_8 >>> */
/*
 * The function is used to perform the security operations on the card i.e Set,
 * clear password, lock/unlock card
 */
status_t  SDMMC003_LockUnlockCard
(
  SDMMC003_LocalLockStructType  *LockPtr,
  SDMMC003_CardLockMode OperationMode
)
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
    /*  Select the Card before proceeding */
    Status = SDMMC003_lSwitchToTransferState();
/* <<< DD_SDMMC_API_8_1 >>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }/* End of "if(Status != DAVEApp_SUCCESS)" */
/*  Send Cmd42 and write the Lock data structure */
/*  Set Transfer Mode Register */
    CLR_BIT( SDMMC->TRANSFER_MODE, SDMMC_TRANSFER_MODE_TX_DIR_SELECT_Pos);
    Status = SDMMC003_lSingleBlockTransfer( &(SDMMC003_COMMON_COMMAND(42)),\
                                            SDMMC003_ARGUMENT0, 512, \
                                            (uint32_t *)LockPtr,\
                                            SDMMC003_WRITE_INTO_BUFF);
/* <<< DD_SDMMC_API_8_2 >>> */
    if(Status == (uint32_t)DAVEApp_SUCCESS)
    {
      Status = SDMMC003_lCheckLockStatus(OperationMode);
    }/* End of "if(Status == DAVEApp_SUCCESS)" */
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_9 >>> */
/*
 * The function is used to get the lock status from the card.
 */
status_t  SDMMC003_GetLockStatus( uint32_t *LockStatusPtr)
{
  uint32_t CardStatus = 0UL;
  uint32_t Argument = 0;
  status_t Status = (uint32_t)SDMMC003_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {      
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_LockStatusError == TRUE)
    {
      /* Forcefully trigger the Command Timeout Error Interrupt */
      SDMMC->FORCE_EVENT_ERR_STATUS = 0x0001 ;
      /* Disable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~( SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
      /* Disable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk );
    }
#endif
    Argument |= SDMMC003_CardInfo.Rca << SDMMC003_ARG_RCA_BITPOS;
    /* Send Cmd13 to read card status  */
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(13)), Argument, \
                                    SDMMC003_RESPONSE_R1, &CardStatus);
/* <<< DD_SDMMC_API_9_1 >>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
/* <<< DD_SDMMC_API_9_2 >>> */
    /* Lock/Unlock Status bit in the CSR Register */
    if ((CardStatus & SDMMC003_CSR_CARD_IS_LOCKED_BITMASK) != 0)
    {
      *LockStatusPtr = (uint32_t)SDMMC003_CARD_IS_LOCKED;
    }/* End of "if ((CardStatus & SDMMC003_CSR_CARD_IS_LOCKED_BITMASK) != 0)"*/
/* <<< DD_SDMMC_API_9_3 >>> */
    else
    {
      *LockStatusPtr = (uint32_t)SDMMC003_CARD_UNLOCKED;
    }
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_10 >>> */
/*
 * This function is use to  get card's current state.
 */
status_t SDMMC003_GetCurrentState()
{
  status_t Status = (uint32_t)SDMMC003_STATE_NO_CARD;
  FUNCTION_ENTRY(GID_SDMMC00x,(uint32_t)SDMMC003_FUNCTION_ENTRY);
/* <<<DD_SDMMC_API_10_1>>> */
  if ((SDMMC003_Handle.State & SDMMC003_STATE_CARD_INITIALIZED))
  {
    Status &= ~(SDMMC003_STATE_NO_CARD);
    Status |= SDMMC003_STATE_CARD_INITIALIZED;
  }
/* <<<DD_SDMMC_API_10_2>>> */
  if ((SDMMC003_Handle.State & SDMMC003_STATE_CARD_WRITE_PROTECT) != 0)
  {
    Status |= SDMMC003_STATE_CARD_WRITE_PROTECT;
  }
/* <<<DD_SDMMC_API_10_3>>> */
  if ((SDMMC003_Handle.State & SDMMC003_STATE_CARD_LOCKED) != 0)
  {
    Status |= SDMMC003_STATE_CARD_LOCKED;
  }
/* <<<DD_SDMMC_API_10_4>>> */
  if ((SDMMC003_Handle.State & SDMMC003_STATE_HC_INITIALIZED) != 0)
  {
    Status |= SDMMC003_STATE_HC_INITIALIZED;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}


/* <<< DD_SDMMC_API_11 >>> */
/*
 * This function is use to  get card type information
 */
status_t SDMMC003_GetCardType(uint32_t* CardTypePtr)
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* <<< DD_SDMMC_API_11_1 >>> */  
  /*Check Whether Initialization Process is successful */
  if (SDMMC003_Handle.InitializeFlag != 1 )
  {
    Status = (uint32_t)SDMMC003_INIT_FAIL;
  }
/* <<< DD_SDMMC_API_11_2 >>> */  
  else
  {
    *CardTypePtr = SDMMC003_Handle.CardType;
  } 
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_12 >>> */
/* This function is use to Get CID register information of card */
status_t SDMMC003_GetCid (void *Buffer)
{
  SDMMC003_SDCIDType* Tmp = (SDMMC003_SDCIDType*)Buffer;
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* <<< DD_SDMMC_API_12_1 >>> */
  /*Check Whether Initialization Process is successful */
  if (SDMMC003_Handle.InitializeFlag != 1 )
  {
    Status = (uint32_t)SDMMC003_INIT_FAIL;
  }
/* <<< DD_SDMMC_API_12_2 >>> */  
  else
  {
    Tmp->ManufacturingDate = (SDMMC003_CardInfo.CidArray[0])&0xFFF;
    Tmp->ProductSerialNum =  (SDMMC003_CardInfo.CidArray[1]<<16)| \
                             (SDMMC003_CardInfo.CidArray[0]>>16);
    Tmp->ProductRev =  (SDMMC003_CardInfo.CidArray[1]>>16)&0xff;
    Tmp->ProductName[0] =  (SDMMC003_CardInfo.CidArray[2]>>24)&0xff;
    Tmp->ProductName[1] =  (SDMMC003_CardInfo.CidArray[2]>>16)&0xff;
    Tmp->ProductName[2] =  (SDMMC003_CardInfo.CidArray[2]>>8)&0xff;
    Tmp->ProductName[3] =  (SDMMC003_CardInfo.CidArray[2]>>0)&0xff;
    Tmp->ProductName[4] =  (SDMMC003_CardInfo.CidArray[1]>>24)&0xff;
    Tmp->AppOEMId[0] = (SDMMC003_CardInfo.CidArray[3]>>8)&0xff;
    Tmp->AppOEMId[1] = (SDMMC003_CardInfo.CidArray[3])&0xff;
    Tmp->ManufacturerId = (SDMMC003_CardInfo.CidArray[3]>>16)&0xff;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_13>>> */
/*
 * This function is use to  Get OCR information on the card
 */
status_t SDMMC003_GetOcr (void *Buffer)
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* <<< DD_SDMMC_API_13_1>>> */  
  /*Check Whether Initialization Process is successful */
  if (SDMMC003_Handle.InitializeFlag != 1 )
  {
    Status = (uint32_t)SDMMC003_INIT_FAIL;
  }
/* <<< DD_SDMMC_API_13_2>>> */  
  else
  {
    *(uint32_t *)Buffer = SDMMC003_CardInfo.Ocr;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_14>>> */
/* This function is use to get CSD information on the card */
status_t SDMMC003_GetCsd (void *Buffer)
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  /*Check Whether Initialization Process is successful */
/* <<< DD_SDMMC_API_14_1>>> */    
  if (SDMMC003_Handle.InitializeFlag != 1 )
  {
    Status = (uint32_t)SDMMC003_INIT_FAIL;
  }
/* <<< DD_SDMMC_API_14_2>>> */    
  else
  {
    /* Csd Structure includes 7-bit CRC  1-bit fixed bit which is not sent by the card.
     So while copying skip one byte and copy in the structure*/
    memcpy(((uint8_t *)Buffer + 1),(void *)SDMMC003_CardInfo.CsdArray,15);
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_15 >>> */
/*
 * This function is use to get number of sectors present on the card.
 */
status_t SDMMC003_GetSectorCount( void *Buffer )
{
  uint32_t Mult = 0;
  status_t Status ;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);

  do
  {
/*<<<DD_SDMMC_API_15_1>>> */    
    /*Check Whether Initialization Process is successful */
    if (SDMMC003_Handle.InitializeFlag != 1 )
    {
      Status = (uint32_t)SDMMC003_INIT_FAIL;
      break;
    }
/* <<< DD_SDMMC_API_15_2 >>> */
    if ((SDMMC003_Handle.CardType & SDMMC003_SD_HIGH_CAPACITY)!= 0)
    {
      SDMMC003_CSDV2Type TmpCsdV2 = {0};
      /*Get CSD function */
      Status = SDMMC003_GetCsd((void *)&TmpCsdV2);
/* <<< DD_SDMMC_API_15_3 >>> */
      if( Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      } /* End of "if( Status != DAVEApp_SUCCESS)" */
      /* For High Capacity SD card, (C_SIZE field value + 1) * 1024
        gives the sector count*/
      *(uint32_t *)Buffer = (((TmpCsdV2.DeviceSizeHigh << 16UL) |   \
                               (TmpCsdV2.DeviceSizeLower ) )+ 1 ) << 10;
    }/* End of "if((SDMMC003_Handle.CardType & SDMMC003_SD_HIGH_CAPACITY)!= 0)"*/

    /* For Standard SD card & MMC card  ,
     * Sector Count =  (Device Size + 1) * Mult, where Mult =  2 ^ C_SIZE_MULT*/
#if SDMMC_SUPPORT_MMC_CARD
/* <<< DD_SDMMC_API_15_4 >>> */
    else if( (uint8_t)(SDMMC003_Handle.CardType == SDMMC003_MMC) != 0)
    {
      SDMMC003_MMCCSDType TmpMmcCsd = {0};
      /*Get csd function */
      Status = SDMMC003_GetCsd((void *)&TmpMmcCsd);
/* <<< DD_SDMMC_API_15_5 >>> */
      if( Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
      /* As per Specs Sector Count is:
       * BLOCKNR = (C_SIZE+1) * MULT  , where MULT = 2^C_SIZE_MULT+2 (C_SIZE_MULT < 8)*/
      Mult = 1 << (TmpMmcCsd.DeviceSizeMult + 2) ;
      *(uint32_t *)Buffer = (((TmpMmcCsd.DeviceSizeHigh << 10UL) |  \
                              (TmpMmcCsd.DeviceSizeLower ))+ 1) * Mult ;
    }
#endif
    /* Standard SD card */
/* <<< DD_SDMMC_API_15_6 >>> */
    else
    {
      SDMMC003_CSDV1Type TmpCsdV1 = {0};
      /*Get csd function */
      Status = SDMMC003_GetCsd((void *)&TmpCsdV1);
/* <<< DD_SDMMC_API_15_7 >>> */
      if( Status != (uint32_t)DAVEApp_SUCCESS)
      {
        break;
      }
      /* Left Shift evaluates 1* 2^(TmpMmcCsd.DeviceSizeMult + 2)*/
      Mult = (TmpCsdV1.DeviceSizeMult + TmpCsdV1.ReadBlkLen - 7);
      /* Sector Count = Device_size * Mult.*/
      *(uint32_t *)Buffer = (((TmpCsdV1.DeviceSizeHigh << 2) |   \
                                  (TmpCsdV1.DeviceSizeLower ))+ 1) <<  Mult;
    } /* End of "Else SD card " */
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_16 >>> */
/*
 * This function is use to get Sector Size info from the card
 */
status_t SDMMC003_GetSectorSize(void *Buffer)
{
  status_t Status = (uint32_t) DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* <<< DD_SDMMC_API_16_1 >>> */  
  /*Check Whether Initialization Process is successfull */
  if (SDMMC003_Handle.InitializeFlag != 1 )
  {
    Status = (uint32_t)SDMMC003_INIT_FAIL;
  }
/* <<< DD_SDMMC_API_16_2 >>> */  
  else
  {
    /* Sector Size is fixed to 512bytes.*/
    *(uint16_t *)Buffer = 512UL;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_17 >>> */
/*
 *  This function returns erase block size of the card in unit of sector into
 *  the DWORD variable pointed by Buffer
 */

status_t SDMMC003_GetBlockSize(void *Buffer)
{
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* <<< DD_SDMMC_API_17_1 >>> */  
  /*Check Whether Initialization Process is successful */
  if (SDMMC003_Handle.InitializeFlag != 1 )
  {
    Status = (uint32_t)SDMMC003_INIT_FAIL;
  }
  /* SD High capacity card i.e. CSD V2*/
/* <<< DD_SDMMC_API_17_2 >>> */
  else if ((SDMMC003_Handle.CardType & SDMMC003_SD_HIGH_CAPACITY) != 0)
  {
    SDMMC003_CSDV2Type TmpCsdV2 = {0};
    /*Get CSD function */
    Status = SDMMC003_GetCsd((void *)&TmpCsdV2);
    *(uint32_t *)Buffer = TmpCsdV2.EraseSectorSize + 1;
  }
#if SDMMC_SUPPORT_MMC_CARD
  /* SDMMC_MMC card */
/* <<< DD_SDMMC_API_17_3 >>> */
  else if ((SDMMC003_Handle.CardType & SDMMC003_MMC )!= 0)
  {
    SDMMC003_MMCCSDType TmpMmcCsd = {0};
    /*Get csd function */
    Status = SDMMC003_GetCsd((void *)&TmpMmcCsd);
    *(uint32_t *)Buffer =  (TmpMmcCsd.EraseGrpSize + 1) *   \
                   (TmpMmcCsd.EraseGrpMult + 1);
  }
#endif
  /* SD standard capacity card i.e. CSD V1*/
/* <<< DD_SDMMC_API_17_4 >>> */
  else
  {
    SDMMC003_CSDV1Type TmpCsdV1  = {0};
    /*Get csd function */
    Status = SDMMC003_GetCsd((void *)&TmpCsdV1);
    *(uint32_t *)Buffer = TmpCsdV1.EraseSectorSize + 1;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
 return  Status;
}

/* <<< DD_SDMMC_API_18 >>> */
/*
 *  This function Flushes Disk Cache from the card
 */
status_t SDMMC003_FlushDiskWriteCache()
{
  status_t Status  = (uint32_t)DAVEApp_SUCCESS;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
/* <<< DD_SDMMC_API_18_1 >>> */  
  /*Check Whether Initialization Process is successful */
  if (SDMMC003_Handle.InitializeFlag != 1 )
  {
    Status = (uint32_t)SDMMC003_INIT_FAIL;
  }
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<<DD_SDMMC_API_19>>> */
/*
 * This function is use to Get SD Status Information
 */
status_t SDMMC003_GetSdStatus(void *Buffer)
{
  uint32_t Argument = 0;
  uint32_t CardStatus = 0;
  status_t Status = (uint32_t)SDMMC003_ERROR;
  FUNCTION_ENTRY(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_ENTRY);
  do
  {
#if SDMMC_UVP_TEST
    if (Test_TriggerInterrupt.Trigger_CommandErrorInterrupt== TRUE)
    {
      /* Disable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~( SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
      /* Disable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk );
    }
#endif
    /* Select the card ie.cmd7 */
    Status = SDMMC003_lSwitchToTransferState();
/* <<<DD_SDMMC_API_19_1>>> */
    if( Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /* Send the Application Specific Command i.e. Command 55.*/
#if SDMMC_UVP_TEST
   if (Test_TriggerInterrupt.Trigger_Cmd55_TC54 == TRUE)
    {
      Test_TriggerInterrupt.Trigger_Cmd55Error = TRUE;
    }
    if (Test_TriggerInterrupt.Trigger_Cmd55Error == TRUE)
    {
      /* Disable the Command Complete Status Interrupt */
      SDMMC->EN_INT_STATUS_NORM &= ~( SDMMC_EN_INT_STATUS_NORM_CMD_COMPLETE_EN_Msk);
      /* Disable the Command Complete Signal Interrupt */
      SDMMC->EN_INT_SIGNAL_NORM &= ~( SDMMC_EN_INT_SIGNAL_NORM_CMD_COMPLETE_EN_Msk );
    }
#endif
    Argument |= SDMMC003_CardInfo.Rca << SDMMC003_ARG_RCA_BITPOS;
    Status = SDMMC003_lSendCommand(&(SDMMC003_COMMON_COMMAND(55)),Argument, \
                                    SDMMC003_RESPONSE_R1,&CardStatus);
/* <<<DD_SDMMC_API_19_2>>> */
    if( Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /*  Set Transfer Mode Register */
    SET_BIT( SDMMC->TRANSFER_MODE, SDMMC_TRANSFER_MODE_TX_DIR_SELECT_Pos);
    /* Read the SD status from the data line */
/* <<<DD_SDMMC_API_19_3>>> */
    Status = SDMMC003_lSingleBlockTransfer( &(SDMMC003_SD_COMMAND(59)),\
                                            SDMMC003_ARGUMENT0,64,\
                                            (uint32_t*)Buffer,\
                                            SDMMC003_READ_FROM_BUFF);
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC00x, (uint32_t)SDMMC003_FUNCTION_EXIT);
  return Status;
}

/* <<< DD_SDMMC_API_20 >>> */
/*
 * This function is use to  de-activate the  Card
 */
status_t SDMMC003_EjectCard()
{
  status_t Status = (uint32_t)SDMMC003_ERROR;
  uint32_t Argument = 0;
  do
  {
/* <<< DD_SDMMC_API_20_1 >>> */
    if (SDMMC003_Handle.State & SDMMC003_STATE_NO_CARD )
    {
      break;
    }/* End of "if ((SDMMC003_Handle.State & SDMMC003_STATE_NO_CARD )!= 1)" */
    /* Send Command 15 to de-activate the card */
    Argument |= SDMMC003_CardInfo.Rca << SDMMC003_ARG_RCA_BITPOS;
    Status = SDMMC003_lSendCommand( &(SDMMC003_COMMON_COMMAND(15)), Argument, \
                                    SDMMC003_NO_RESPONSE,  NULL);
/* <<< DD_SDMMC_API_20_2 >>> */
    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      break;
    }
    /* Card Cleanup */
    SDMMC003_lCardCleanUp();
    SDMMC003_Handle.InitializeFlag = 0;
  } while(0);
  /* Debug Log message .*/
  INFO(GID_SDMMC00x,Status,0,0);
  return Status; 
}

/* <<< DD_SDMMC_API_22 >>> */
/*
 * This function brings the SDMMC peripheral out of reset.
 */
void SDMMC003_Init()
{
  RESET001_DeassertReset(PER1_MMC);
}

/* <<< DD_SDMMC_API_23 >>> */
/*
 * This function performs the SDMMC LLD App Initialization which includes Host Controller Initialization,
 * Card Initialization and Reading Card Registers.
 */
status_t SDMMC003_Start()
{
  status_t Status =  (uint32_t)SDMMC003_HOST_CONTROLLER_INITIALIZED;
/* <<< DD_SDMMC_API_23_1 >>> */  
  /* Check If Host controller is already Initialized */
  if ( (SDMMC003_Handle.State & SDMMC003_STATE_HC_INITIALIZED) == 0)
  {
    /* Enable Interrupt */
    NVIC_SetPriority(SDMMC0_0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), \
                                                        SDMMC_PREEMPTION_PRIORITY,\
                                                        SDMMC_SUB_PRIORITY));
    NVIC_ClearPendingIRQ(SDMMC0_0_IRQn);
    NVIC_EnableIRQ(SDMMC0_0_IRQn);
/* <<< DD_SDMMC_API_23_1 >>> */
    /* Host Controller Initialize */
    Status = SDMMC003_HostControllerInit();
  }
  return Status;
}

/* <<< DD_SDMMC_API_24 >>> */
/*
 * This function performs the SDMMC LLD App Initialization which includes Host Controller Initialization,
 * Card Initialization and Reading Card Registers.
 */
status_t SDMMC003_CardDetectionSupport()
{
  status_t Status;
/* <<< DD_SDMMC_API_24_1 >>> */
  Status = SDMMC003_lCardIdentificationProcess();
  if (Status == (uint32_t)DAVEApp_SUCCESS)
  {
    SDMMC003_Handle.InitializeFlag = 1;  
  }
  return Status;
}
#if SDMMC_CARD_DETECTION_SUPPORT
/* <<< DD_SDMMC_API_25 >>> */
/*
 * This function registers the call back function of upper layer which will be 
 * invoked from low-level driver if card is inserted or removed in the kit
 * supporting Card detection mechanism.
 */ 
status_t SDMMC003_RegisterCallBack(SDMMC003_PtrToCallBackFunction \
                                            CallbackFunction)
{
  status_t Status = SDMMC003_ERROR;
  do
  {
/* Check Function Pointer is Not Null */
/* <<< DD_SDMMC_API_25_1 >>> */
    if (CallbackFunction == NULL )
    {  
      break;
    }
    SDMMC003_Handle.CallBackPtr = CallbackFunction; 
    Status = (uint32_t)DAVEApp_SUCCESS;
  } while(0);
  return Status;
}
#endif

/*CODE_BLOCK_END*/




