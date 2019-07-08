
/* CODE_BLOCK_BEGIN[SDMMC001.c] */

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
** MODIFICATION DATE : July 31, 2012                                           **
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
 * @file   SDMMC001.c
 *
 * @brief  This file contains definitions of all private and public functions
 *         of SDMMC Block Layer App in Non-RTOS environment
 *
 */
 

/*******************************************************************************
**                      INCLUDE FILES                                         **
*******************************************************************************/
#include <DAVE3.h>

/**
 * @cond INTERNAL_DOCS
 */
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/**
 * @ingroup SDMMC001_privateparam
 * @{
 */
/**
 * Global variable to hold SDMMC device initialization status. It is set to 1 if
 * SDMMC device is initialized.
 */
static uint8_t SDMMC001_InitializeFlag;
/**
 * Global variable to hold SDMMC device lock flag status. It is set to 1 if
 * SDMMC device is initialized but is locked.
 */
static uint8_t SDMMC001_LockFlag;
#ifdef SDMMC001_UVP_TEST
  bool  CardNotInit = FALSE;
#endif
/**
 * @}
 */
/**
 * @ingroup SDMMC001_privatefunc
 * @{
 */
/*******************************************************************************
**                     Private Function Declarations                           **
*******************************************************************************/
/**
 * @brief This function gets the Current Disk Status.
 * @return uint8_t \n
 * STA_NOINIT: Not Initialized\n
 * STA_NODISK: No card\n
 * STA_PROTECT: Card is write protected\n
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 * @return <b>uint8_t</b><BR>
 */
uint8_t SDMMC001_lFindDiskStatus(void);

/**
 * @}
 */
/*******************************************************************************
**                     Private Function Definitions                           **
*******************************************************************************/
/*<<<DD_SDMMC001_nonAPI_1>>>*/
uint8_t SDMMC001_lFindDiskStatus()
{
  status_t Status;
  uint8_t DiskStatus = 0;
/* Get the Status Information */
  do
  {
 /* Get the Current State information . */
    Status = SDMMC003_GetCurrentState();
/*<<<DD_SDMMC001_nonAPI_1_1>>>*/
    if (Status & (uint32_t)SDMMC003_STATE_NO_CARD )
    {
      DiskStatus = (SDMMC001_STA_NOINIT | SDMMC001_STA_NODISK);
      break;
    }/* End of "if ((Status & SDMMC003_STATE_CARD_INSERTED) == 0)"		*/
/*<<<DD_SDMMC001_nonAPI_1_2>>>*/
    if ((Status & (uint32_t)SDMMC003_STATE_CARD_INITIALIZED) == 0)
    {
      DiskStatus |= SDMMC001_STA_NOINIT;
      break;
    }/* End of "if ((Status & SDMMC003_STATE_CARD_INITIALIZED) == 0)"	*/
    if (( Status & (uint32_t)SDMMC003_STATE_CARD_LOCKED) != 0 )
    {
      SDMMC001_LockFlag = 1;
      DiskStatus |= SDMMC001_STA_NOINIT;
      break;
    }/* End of "if ((Status & (uint32_t)SDMMC003_STATE_CARD_LOCKED) == 0)" */
/*<<<DD_SDMMC001_nonAPI_1_3>>>*/
    if ((Status & (uint32_t)SDMMC003_STATE_CARD_WRITE_PROTECT) != 0)
    {
      DiskStatus |= SDMMC001_STA_PROTECT;
    }/* End of "if ((Status & SDMMC003_STATE_CARD_WRITE_PROTECT) != 0)"	*/
  } while(0);
  return DiskStatus;
}


/**
 * @endcond
 */
/*******************************************************************************
**                     Public Function Definitions                            **
*******************************************************************************/

/*<<<DD_SDMMC001_API_1>>>*/
/*
 * The function checks and returns the initialization status of the card .
 */
uint8_t SDMMC001_Initialize(void)
{
  status_t Status;
  uint8_t DiskStatus ;
  FUNCTION_ENTRY(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_ENTRY);
  do
  {
#ifdef SDMMC001_UVP_TEST
    if (CardNotInit == TRUE)
    {
      SDMMC001_InitializeFlag =1 ;
    }
#endif
    /* Check the device initialization status. If SDMMC device is
     * already initialized, Skip this step else initialize Sdmmc device */
    if ( SDMMC001_InitializeFlag == 0)
    {
      Status = SDMMC003_Start();
      if ( (Status != (uint32_t)DAVEApp_SUCCESS) &&  \
           (Status != (uint32_t)SDMMC003_HOST_CONTROLLER_INITIALIZED))
      {
        break;
      }
      Status = SDMMC003_CardDetectionSupport();
      if (Status != (uint32_t)DAVEApp_SUCCESS )
      {
        if (Status == (uint32_t)SDMMC003_INITIALIZED_BUT_LOCKED)
        {
          SDMMC001_LockFlag = 1;
        }
        break;
      }
      SDMMC001_InitializeFlag = 1; 
    }
  } while(0);
/* Debug Log Message */
  DiskStatus =  SDMMC001_lFindDiskStatus();
  ERROR(GID_SDMMC001,Status,0,0);
  FUNCTION_EXIT(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_EXIT);
  return DiskStatus;
}

/*<<<DD_SDMMC001_API_2>>>*/
/*
 * The function gets the status of the card whether the card is initialized,
 * inserted or write protected.
 */
uint8_t SDMMC001_GetStatus(void)
{
  uint8_t  DiskStatus;
  FUNCTION_ENTRY(GID_SDMMC001,(uint32_t)SDMMC001_FUNCTION_ENTRY);
  DiskStatus  = SDMMC001_Initialize();
  FUNCTION_EXIT(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_EXIT);
  return DiskStatus;
}

/* <<<DD_SDMMC001_API_3>>>*/
/*
 * The function reads the data from the card.
 */
uint32_t SDMMC001_ReadBlock
(
  uint8_t *ReadBuf,
  uint32_t SectorNumber,
  uint8_t  SectorCount
)
{
  status_t Status;
  uint8_t DiskStatus;
  uint32_t Result;
  FUNCTION_ENTRY(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_ENTRY);
/* Check the status before reading data */
  DiskStatus = SDMMC001_GetStatus();
/*<<<DD_SDMMC001_API_3_1>>>*/
  if ((DiskStatus & (uint8_t)SDMMC001_STA_NOINIT) != 0)
  {
    Result = SDMMC001_RES_NOTRDY;
    ERROR(GID_SDMMC001,Result,0,0);
  }
  else
  {
/*Check for single block read or multiple block read based on sector count */
/*<<<DD_SDMMC001_API_3_2>>>*/
    if (SectorCount == 1)
    {
      Status = SDMMC003_CardReadSingleBlock( (uint32_t *)ReadBuf, SectorNumber);
    }
/*<<<DD_SDMMC001_API_3_3>>>*/
    else
    {
      Status = SDMMC003_CardReadMultipleBlocks((uint32_t *)ReadBuf,SectorNumber, \
                                                SectorCount);
    }/*End of "if (SectorCount == 1)"*/
/*<<<DD_SDMMC001_API_3_4>>>*/
    if (Status == (uint32_t)DAVEApp_SUCCESS)
    {
      Result = SDMMC001_RES_OK;
    }
/*<<<DD_SDMMC001_API_3_5>>>*/
    else
    {
      Result = SDMMC001_RES_ERROR;
      ERROR(GID_SDMMC001,SDMMC001_SDMMC00x_ERROR,sizeof(int),Status);
    }/* End of "if (Status == (uint32_t)DAVEApp_SUCCESS)"*/
  }/* End of " if ((DiskStatus & (uint8_t)STA_NOINIT) != 0)"*/
  FUNCTION_EXIT(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_EXIT);
  return Result;
}

/*<<<DD_SDMMC001_API_4>>>*/
/*
 * The function writes the data on the card.
 */
uint32_t SDMMC001_WriteBlock
(
  const uint8_t *WriteBuf,
  uint32_t SectorNumber,
  uint8_t SectorCount
)
{
  status_t Status ;
  uint8_t DiskStatus;
  uint32_t Result;
  FUNCTION_ENTRY(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_ENTRY);

  do
  {
    DiskStatus = SDMMC001_GetStatus ();
/*<<<DD_SDMMC001_API_4_1>>>*/
/* If the card is not initialized */
    if ((DiskStatus & SDMMC001_STA_NOINIT) != 0)
    {
      Result = SDMMC001_RES_NOTRDY;
      ERROR(GID_SDMMC001,Result,0,0);
      break;
    }/* End of "if ((DiskStatus & SDMMC001_STA_NOINIT) != 0)"*/
/* If the card is read only or write protected */
/*<<<DD_SDMMC001_API_4_2>>>*/
    if ((DiskStatus & SDMMC001_STA_PROTECT) != 0)
    {
      Result = SDMMC001_RES_WRPRT;
      ERROR(GID_SDMMC001,Result,0,0);
      break;
    }/* End of "if ((DiskStatus & SDMMC001_STA_PROTECT) != 0)"*/
/*Check for single block write or multiple block write.*/
/*<<<DD_SDMMC001_API_4_3>>>*/
    if (SectorCount == 1)
    {
      Status = SDMMC003_CardWriteSingleBlock((uint32_t *)WriteBuf, SectorNumber);
    }
/*<<<DD_SDMMC001_API_4_4>>>*/
    else
    {
      Status = SDMMC003_CardWriteMultipleBlocks((uint32_t *)WriteBuf,\
                                                 SectorNumber, SectorCount );
    } /* End of "if (SectorCount == 1)"*/
/*<<<DD_SDMMC001_API_4_5>>>*/
    if (Status == (uint32_t)DAVEApp_SUCCESS)
    {
      Result = SDMMC001_RES_OK;
    }
/*<<<DD_SDMMC001_API_4_6>>>*/
    else
    {
      Result = SDMMC001_RES_ERROR;
      ERROR(GID_SDMMC001,SDMMC001_SDMMC00x_ERROR,0,0);
    } /* End of "if (Status == (uint32_t)DAVEApp_SUCCESS)"*/
  } while(0);
  FUNCTION_EXIT(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_EXIT);
  return Result;
}

/*<<<DD_SDMMC001_API_5>>>*/
/*
 * The function performs the various IOCTL operation.
 */
uint32_t SDMMC001_Ioctl
(
  uint8_t Command,
  void *Buffer
)
{
  status_t Status = (uint32_t)SDMMC001_ERROR;
  uint8_t DiskStatus;
  uint32_t Result;
  SDMMC001_EraseAddrType *ErasePtr;
  const SDMMC001_PasswdType *PasswdPtr;
  SDMMC003_LocalLockStructType LockStruct = {0};
  FUNCTION_ENTRY(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_ENTRY);
  do
  {
    DiskStatus = SDMMC001_GetStatus();
/*<<<DD_SDMMC001_API_5_1>>>*/
/* If card is not initialized or inserted */
    if ((DiskStatus & (uint8_t)SDMMC001_STA_NOINIT) != 0)
    {
      if (SDMMC001_LockFlag == 1UL)
      {
        Status = (uint32_t)SDMMC001_DISK_LOCKED;
        if ( (Command != SDMMC001_MMC_UNLOCK_CARD) &&
           (Command != SDMMC001_MMC_SET_PASSWD) &&
           (Command != SDMMC001_MMC_CLEAR_PASSWD) &&
           (Command != SDMMC001_MMC_SET_LOCK) &&
           (Command != SDMMC001_MMC_READ_LOCK_STATUS) &&
           (Command != SDMMC001_MMC_FORCE_ERASE) &&
           (Command != SDMMC001_CTRL_EJECT) )
        {
          ERROR(GID_SDMMC001,Status,0,0);
          break;
        }
      }
      else
      {
        Status = (uint32_t)SDMMC001_RES_NOTRDY;
        ERROR(GID_SDMMC001,Status,0,0);
        break;
      }
    }
/* Switch to the respective IOCTL command */
    switch (Command)
    {
/*<<<DD_SDMMC001_API_5_2>>>*/
      case SDMMC001_CTRL_SYNC:
        Status = SDMMC003_FlushDiskWriteCache();
        break;

      case SDMMC001_GET_SECTOR_SIZE:
        Status = SDMMC003_GetSectorSize(Buffer);
		break;
		 
/*<<<DD_SDMMC001_API_5_3>>>*/
      case SDMMC001_GET_SECTOR_COUNT:
        Status = SDMMC003_GetSectorCount( Buffer );
        break;

/*<<<DD_SDMMC001_API_5_4>>>*/
      case SDMMC001_CTRL_ERASE_SECTOR:
        ErasePtr = (SDMMC001_EraseAddrType *) Buffer;
        Status = SDMMC003_EraseBlock( (ErasePtr->StartAddress),
                                      (ErasePtr->EndAddress));
        break;

/*<<<DD_SDMMC001_API_5_5>>>*/
      case SDMMC001_GET_BLOCK_SIZE:
        Status = SDMMC003_GetBlockSize(Buffer);
        break;

/*<<<DD_SDMMC001_API_5_6>>>*/
      case SDMMC001_MMC_GET_TYPE:
        Status = SDMMC003_GetCardType(Buffer);
        break;

/*<<<DD_SDMMC001_API_5_7>>>*/
      case SDMMC001_MMC_GET_CSD:
        Status = SDMMC003_GetCsd(Buffer);
        break;

/*<<<DD_SDMMC001_API_5_8>>>*/
      case SDMMC001_MMC_GET_CID:
        Status = SDMMC003_GetCid(Buffer);
        break;

/*<<<DD_SDMMC001_API_5_8>>>*/
      case SDMMC001_MMC_GET_OCR:
        Status = SDMMC003_GetOcr(Buffer);
        break;

/*<<<DD_SDMMC001_API_5_10>>>*/
      case SDMMC001_MMC_GET_SDSTAT:
        Status = SDMMC003_GetSdStatus(Buffer);
        break;

/*<<<DD_SDMMC001_API_5_11>>>*/
      case SDMMC001_MMC_LOCK_CARD:
        LockStruct.Mode = 0x04UL;
        PasswdPtr = (const SDMMC001_PasswdType *)Buffer;
        /* Check password length doesn't exceeds the permitted length */
        /*<<<DD_SDMMC001_API_5_11_1>>>*/
        if( PasswdPtr->OldPwdLength > SDMMC001_MAX_PASSWD_LEN )
        {
          break;
        }
        LockStruct.PwdLen = PasswdPtr->OldPwdLength;
        memcpy(LockStruct.PwdData, PasswdPtr->OldPassword, \
               (uint32_t)LockStruct.PwdLen);
        Status = SDMMC003_LockUnlockCard(&LockStruct, SDMMC003_LOCK);
        break;

/*<<<DD_SDMMC001_API_5_12>>>*/
      case SDMMC001_MMC_UNLOCK_CARD:
        LockStruct.Mode = 0x00UL;
        PasswdPtr = (const SDMMC001_PasswdType *)Buffer;
        /* Check password length doesn't exceeds the permitted length */
        /*<<<DD_SDMMC001_API_5_12_1>>>*/
        if( PasswdPtr->OldPwdLength > SDMMC001_MAX_PASSWD_LEN )
        {
          break;
        }
        LockStruct.PwdLen = PasswdPtr->OldPwdLength;
        memcpy(LockStruct.PwdData,PasswdPtr->OldPassword, LockStruct.PwdLen);
        Status  = SDMMC003_LockUnlockCard(&LockStruct,  \
                                          SDMMC003_UNLOCK);
        break;

/*<<<DD_SDMMC001_API_5_13>>>*/
      case SDMMC001_MMC_SET_PASSWD:
/*Fill the local lock structure with the information provided*/
        LockStruct.Mode  = 0x01UL;
        PasswdPtr = (const SDMMC001_PasswdType *)Buffer;
        /* Check password length doesn't exceeds the permitted length */
        /*<<<DD_SDMMC001_API_5_13_1>>>*/
        if( (PasswdPtr->OldPwdLength > SDMMC001_MAX_PASSWD_LEN) ||
            (PasswdPtr->NewPwdLength > SDMMC001_MAX_PASSWD_LEN ))
        {
          break;
        }
        LockStruct.PwdLen = PasswdPtr->OldPwdLength + PasswdPtr->NewPwdLength;

        memcpy(LockStruct.PwdData, PasswdPtr->OldPassword, \
                PasswdPtr->OldPwdLength );
        memcpy(LockStruct.PwdData + PasswdPtr->OldPwdLength, \
               PasswdPtr->NewPassword, PasswdPtr->NewPwdLength );

        Status = SDMMC003_LockUnlockCard(&LockStruct, \
                                          SDMMC003_UNLOCK);
        break;

/*<<<DD_SDMMC001_API_5_14>>>*/
      case SDMMC001_MMC_CLEAR_PASSWD:
        LockStruct.Mode  = 0x02UL;
        PasswdPtr = (const SDMMC001_PasswdType *)Buffer;
        /* Check password length doesn't exceeds the permitted length */
        /*<<<DD_SDMMC001_API_5_14_1>>>*/
        if( PasswdPtr->OldPwdLength > SDMMC001_MAX_PASSWD_LEN )
        {
          break;
        }
        LockStruct.PwdLen =  PasswdPtr->OldPwdLength;
        memcpy(LockStruct.PwdData, PasswdPtr ->OldPassword, \
               LockStruct.PwdLen);
        Status = SDMMC003_LockUnlockCard(&LockStruct,SDMMC003_UNLOCK);
        break;

/*<<<DD_SDMMC001_API_5_15>>>*/
      case SDMMC001_MMC_SET_LOCK:
        LockStruct.Mode  = 0x05UL;
        PasswdPtr = (const SDMMC001_PasswdType *)Buffer;
        /*<<<DD_SDMMC001_API_5_15_1>>>*/
        /* Check password length doesn't exceeds the permitted length */
        if( PasswdPtr->OldPwdLength > SDMMC001_MAX_PASSWD_LEN )
        {
          break;
        }
        LockStruct.PwdLen =  PasswdPtr->OldPwdLength + PasswdPtr->NewPwdLength;
        memcpy(LockStruct.PwdData, PasswdPtr->OldPassword,PasswdPtr->OldPwdLength );
        memcpy(LockStruct.PwdData + PasswdPtr->OldPwdLength, \
                       PasswdPtr->NewPassword, PasswdPtr->NewPwdLength );
        Status  = SDMMC003_LockUnlockCard(&LockStruct, SDMMC003_LOCK);
        break;

/*<<<DD_SDMMC001_API_5_16>>>*/
      case SDMMC001_MMC_READ_LOCK_STATUS:
        Status = SDMMC003_GetLockStatus((uint32_t *)Buffer);
        break;

/*<<<DD_SDMMC001_API_5_17>>>*/
      case SDMMC001_MMC_FORCE_ERASE:
        LockStruct.Mode = 0x08UL;
        Status = SDMMC003_LockUnlockCard(&LockStruct, SDMMC003_UNLOCK);
        break;

/*<<<DD_SDMMC001_API_5_18>>>*/
      case SDMMC001_CTRL_EJECT:
        Status = SDMMC003_EjectCard();
        break;

      default:
        Result = SDMMC001_RES_PARERR;
        break;
     }
  } while (0);

/*<<<DD_SDMMC001_API_5_18>>>*/
  if (Status == (uint32_t)DAVEApp_SUCCESS)
  {
    Result = SDMMC001_RES_OK;
  }
/*<<<DD_SDMMC001_API_5_19>>>*/
  else
  {
    Result = SDMMC001_RES_ERROR;
    ERROR(GID_SDMMC001,SDMMC001_SDMMC00x_ERROR,sizeof(int),Status);
  }
  FUNCTION_EXIT(GID_SDMMC001, (uint32_t)SDMMC001_FUNCTION_EXIT);
  return Result;
}

/*CODE_BLOCK_END*/





