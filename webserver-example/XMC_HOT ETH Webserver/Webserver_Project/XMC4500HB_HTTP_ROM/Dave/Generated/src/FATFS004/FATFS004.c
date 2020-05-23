
/*CODE_BLOCK_BEGIN[FATFS004.c]*/
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
/*******************************************************************************
**                      INCLUDE FILES                                         **
*******************************************************************************/




/**
 * @file   FATFS004.c
 *
 * @brief This file contains definitions of all public functions
 *        of Device Abstraction Layer App.
 */
#include <DAVE3.h>

/**
 * Number of Devices attached
 */
   #define FATFS004_MAX_DRIVES                        1
   


/**
 * @cond INTERNAL_DOCS
 */

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

DRESULT FATFS004_ErrorCodes[5] = {
                                            RES_OK ,   RES_ERROR,
                                            RES_WRPRT, RES_NOTRDY,
                                            RES_PARERR
                                          };

DSTATUS FATFS004_StatusCodes[5] = 
                                     {
                                       0, STA_NOINIT,
                                       STA_NODISK, FATFS004_NODISK_NOINIT,
                                       STA_PROTECT
                                     };

/**
 * Extern the DeviceFunction pointers initialized in config file.
 */
extern  FATFS004_DeviceFuncType FATFS004_DeviceFunc[FATFS004_MAX_DRIVES];

/**
 * Dummy Variable to hold the status.
 */
 status_t FATFS004_UnusedStatus;


/*******************************************************************************
**                     Public Function Definitions                            **
*******************************************************************************/

/*<<<DD_FATFS004_API_1>>>*/
/*
 * The function performs the disk initialization.
 */
DSTATUS disk_initialize(BYTE Drive)
{
  DSTATUS DStatus = 0;
  uint8_t Status;
  FUNCTION_ENTRY(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_ENTRY);
  do
  {
/*<<<DD_FATFS004_API_1_1>>*/
/* If drive number is greater than the maximum drives allowed  */
    if (Drive >= FATFS004_MAX_DRIVES)
    {
      DStatus = (STA_NODISK | STA_NOINIT);
      break;
    }
    /* Call the Initialize function. */
/*<<<DD_FATFS004_API_1_2>>*/
    Status = FATFS004_DeviceFunc[Drive].InitializePtr();
/* Fatfs to Block Layer Error Code Mapping */
    DStatus = FATFS004_StatusCodes[Status];
  } while (0);
  FUNCTION_EXIT(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_EXIT);
  return DStatus;
}

/*<<<DD_FATFS004_API_2>>>  */
/*
 * The function gets the disk status information.
 */
DSTATUS disk_status(BYTE Drive)
{
  DSTATUS DStatus;
  uint8_t Status;
  FUNCTION_ENTRY(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_ENTRY);
  do
  {
/*  <<<DD_FATFS004_API_2_1>>>  */
/* If drive number is greater than the maximum drives allowed  */
    if (Drive >= FATFS004_MAX_DRIVES)
    {
      DStatus = (STA_NODISK | STA_NOINIT);
      break;
    }
    /* Call the Initialize function.*/
/*<<<DD_FATFS004_API_2_2>>>  */
    Status = FATFS004_DeviceFunc[Drive].GetStatusPtr();
/* Fatfs to Block Layer Error Code Mapping */
    DStatus = FATFS004_StatusCodes[Status];
  } while (0);
  ERROR(GID_FATFS004,FATFS004_SDMMC002_ERROR,0,0);
  FUNCTION_EXIT(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_EXIT);
  return DStatus;
}

/*  <<<DD_FATFS004_API_3>>>  */
/*
 * The function reads the blocks of data from the disk.
 */
DRESULT disk_read
(
  BYTE Drive,
  BYTE *Buffer,
  DWORD SectorNumber,
  BYTE SectorCount
)
{
  DRESULT DResult;
  uint32_t Result;
  FUNCTION_ENTRY(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_ENTRY);
  do
  {
/*<<<DD_FATFS004_API_3_1>>>*/
/* If drive number is greater than the maximum drives allowed  */
    if (Drive >= FATFS004_MAX_DRIVES )
    {
      DResult = RES_PARERR;
      break;
    }
/*<<<DD_FATFS004_API_3_2>>>*/
    /* If sector count is less than 1. Minimum 1 sector is needed*/
    if (SectorCount < 1)
    {
      DResult = RES_PARERR;
      break;
    }
/*<<<DD_FATFS004_API_3_3>>>*/
    /* For BufferPtr not aligned */
    if (((uint32_t)Buffer % 4UL) != 0UL)
    {
      DResult = RES_PARERR;
      break;
    }
/*<<<DD_FATFS004_API_3_4>>>*/
    /*Call the ReadBlkPtr function.*/
    Result = FATFS004_DeviceFunc[Drive].ReadBlkPtr(Buffer, SectorNumber, \
                                                    SectorCount);
/* Fatfs to Block Layer Error Code Mapping */
    DResult = FATFS004_ErrorCodes[Result];                                               
  } while (0);
  ERROR(GID_FATFS004,FATFS004_SDMMC001_ERROR,0,0);
  FUNCTION_EXIT(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_EXIT);
  return DResult;
}

/*<<<DD_FATFS004_API_4>>>*/
/*
 * The function writes the blocks of data on the disk.
 */
DRESULT disk_write
(
  BYTE Drive,
  const BYTE*  Buffer,
  DWORD SectorNumber,
  BYTE  SectorCount
)
{
  DRESULT DResult;
  uint32_t Result;
  FUNCTION_ENTRY(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_ENTRY);
  do
  {
/*<<<DD_FATFS004_API_4_1>>>*/
    /* If drive number is greater than the maximum drives allowed  */
    if (Drive >= FATFS004_MAX_DRIVES)
    {
      DResult = RES_PARERR;
      break;
    }
/*<<<DD_FATFS004_API_4_2>>> */
    /* If sector count is less than 1. Minimum 1 sector is needed*/
    if (SectorCount < 1)
    {
      DResult = RES_PARERR;
      break;
    }
/*<<<DD_FATFS004_API_4_3>>> */
    /* for BufferPtr not aligned */
    if (((uint32_t)Buffer % 4UL) != 0UL)
    {
      DResult = RES_PARERR;
      break;
    }
/*<<<DD_FATFS004_API_4_4>>> */
    /*Call the WriteBlkPtr function.*/
    Result = FATFS004_DeviceFunc[Drive].WriteBlkPtr(Buffer, SectorNumber, SectorCount);
/* Fatfs to Block Layer Error Code Mapping */
    DResult = FATFS004_ErrorCodes[Result];  
  } while (0);
  ERROR(GID_FATFS004,FATFS004_SDMMC002_ERROR,0,0);
  FUNCTION_EXIT(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_EXIT);
  return DResult;
}

/*<<<DD_FATFS004_API_5>>>*/
/*
 * The function performs the various IOCTL operation.
 */
DRESULT  disk_ioctl(BYTE Drive, BYTE Command, void * Buffer)
{
  DRESULT DResult;
  uint32_t Result;
  FUNCTION_ENTRY(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_ENTRY);
  do
  {
/*<<<DD_FATFS004_API_5_1>>>*/
    if (Drive >= FATFS004_MAX_DRIVES)
    {
      DResult = RES_PARERR;
      break;
    }
    /* for BufferPtr not aligned */
/*<<<DD_FATFS004_API_5_2>>>*/
    if (((uint32_t)Buffer % 4UL) != 0UL)
    {
      DResult = RES_PARERR;
      break;
    }
/*<<<DD_FATFS004_API_5_3>>>*/
    /*Call the Ioctl function.*/
    Result = FATFS004_DeviceFunc[Drive].IoctlPtr(Command, Buffer);
/* Fatfs to Block Layer Error Code Mapping */
    DResult = FATFS004_ErrorCodes[Result];  
  } while (0);
  ERROR(GID_FATFS004,FATFS004_SDMMC002_ERROR,0,0);
  FUNCTION_EXIT(GID_FATFS004, (uint32_t)FATFS004_FUNCTION_EXIT);
  return DResult;
}

/*<<<DD_FATFS004_API_6>>> */
/**
 * This is a real time clock service to be called from
 * FatFs module.This function is not required in read-only cfg
 */
DWORD get_fattime()
{
  RTC001_TimeHandle Time = {0};  
  FATFS004_UnusedStatus = RTC001_Clock_GetTime(&Time);
/* Pack date and time into a DWORD variable */
  return    ((DWORD)(Time.Year - 1980) << 25)
      | ((DWORD)Time.Month << 21)
      | ((DWORD)Time.Days << 16)
      | ((DWORD)Time.Hours << 11)
      | ((DWORD)Time.Min << 5)
      | ((DWORD)Time.Sec >> 1);
}


/**
 * @endcond
 */
/*CODE_BLOCK_END*/




