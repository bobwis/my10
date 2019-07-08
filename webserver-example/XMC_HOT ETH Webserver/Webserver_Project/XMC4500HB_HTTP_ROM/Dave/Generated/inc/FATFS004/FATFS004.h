
/*CODE_BLOCK_BEGIN[FATFS004.h]*/
/******************************************************************************
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with 
 * Infineon's microcontrollers.
 * This file can be freely distributed within development
 * tools that are supporting such microcontrollers. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
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
 * @file  FATFS004.h
 *
 * @brief This file contains all public data structures,enums and function
 *        prototypes for Device Abstraction Layer App.
 *
 */

#ifndef  FATFS004_H_
#define  FATFS004_H_


/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include <DAVE3.h>
#include "diskio.h"


/**
 * @ingroup  FATFS004_publicparam
 * @{
 */

/**
 *  Combination of Status Flags indicating No Disk & No Initialization
 */
#define  FATFS004_NODISK_NOINIT 								3

/*******************************************************************************
**                       ENUMERATIONS                                         **
*******************************************************************************/
/**
 * This enumerates the error codes of Device Abstraction Layer App
 */
typedef enum FATFS004_ErrorCodesType
{
  /**
   * SDMMC001 Module Error  (1)
   */
  /*
  GROUPID  #19
  MODULENAME = Device Abstraction Layer App
  */
  /*
  ERRCODESTRING = FATFS004_ERROR
  STRCODESTRING = Error in SDMMC001 App.
  */
  FATFS004_ERROR = 1,
  /**
   * SDMMC Block Layer Module Error  (1)
   */
  /*
  GROUPID  #19
  MODULENAME = Device Abstraction Layer App
  */
  /*
  ERRCODESTRING = FATFS004_SDMMC001_ERROR
  STRCODESTRING = Error in Sdmmc Block Layer App. Error is propagated to FAT FS
  so is returned in FAT FS error format
  */
  FATFS004_SDMMC001_ERROR,
  /**
   * Debug log codes starts here  (0)
   */
  /**
   * DebugLog Message Id for Function Entry
   */
  /*
  ERRCODESTRING = FATFS004_FUNCTION_ENTRY
  STRCODESTRING = Function Entered %s
  */
	FATFS004_FUNCTION_ENTRY,
  /**
   * DebugLog Message Id for Function Exit (1)
   */
  /*
  ERRCODESTRING = FATFS004_FUNCTION_EXIT
  STRCODESTRING = Function Exited %s
  */
	FATFS004_FUNCTION_EXIT
} FATFS004_ErrorCodesType;

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/**
 * Function Pointer pointing to the Block Layer's disk initialize function. 
 */
typedef uint8_t (*InitializeFunc) (void);
/**
 * Function Pointer pointing to the Block Layer's  get disk status function. 
 */
typedef uint8_t (*GetStatusFunc) (void);
/**
 * Function Pointer pointing to the Block Layer's read block function.
 */
typedef uint32_t (*ReadBlkFunc) (uint8_t*, uint32_t, uint8_t);
/**
 * Function Pointer pointing to the Block Layer's write block function. 
 */
typedef uint32_t (*WriteBlkFunc)(const uint8_t*, uint32_t, uint8_t);
/**
 * Function Pointer pointing to the Block Layer's IOCTL function. 
 */
typedef uint32_t (*IoctlFunc) (uint8_t, void * );
/*******************************************************************************
**                       STRUCTURES                                           **
*******************************************************************************/
/**
 * This structure holds the block layers' devices' function pointers data type 
 * as member fields
 */
typedef struct FATFS004_DeviceFuncType
{
/**
 * Disk Initialize function pointer
 */
  InitializeFunc InitializePtr;
/**
 * Get Disk Status function pointer
 */
  GetStatusFunc GetStatusPtr;
/**
 * Read Blocks of data from disk  function pointer
 */
  ReadBlkFunc ReadBlkPtr;
/**
 * Write Blocks of data on disk Function Pointer
 */
  WriteBlkFunc WriteBlkPtr;
/**
 * Ioctl Function Pointer
 */
  IoctlFunc IoctlPtr;
} FATFS004_DeviceFuncType;


/**
 * @}
 */

/**
 * @ingroup FATFS004_apidoc
 * @{
 */

/*******************************************************************************
 **							FUNCTION PROTOTYPES                 **
*******************************************************************************/
/**
 * @brief This function initializes a physical drive and put it
 * ready to read/write. Application program should not call this function, or
 * FAT structure on the volume can be collapted. To re-initialize the file system,
 * use f_mount function.This function is called on volume mount process in the
 * FatFs module to manage the media change.
 * @param[in] Drive Specifies the physical drive number to initialize. 
 * @return DSTATUS\n
 * Returns Disk status as the result.\n
 * Refer disk_status function for details of status flags.\n
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   DSTATUS DStatus;
 *   // DAVE Initialization.
 *   DAVE_Init();
 *   // SDMMC drive number will be at '0' drive 
 *   DStatus =  disk_initialize(0);
 *   if (DStatus == (STA_NODISK | STA_NOINIT))
 *   {
 *     //No card Present;
 *   }
 *   if (DStatus == STA_NOINIT)
 *   {
 *    //Card Present but not initialized.
 *   }
 *   if (DStatus == STA_PROTECT)
 *   {
 *     //Card is Write Protected .
 *   } 
 *   return 0;
 * }
 * @endcode
 */
DSTATUS disk_initialize(BYTE Drive);

/**
 * @brief The disk_status function returns the current disk status.
 * @param[in] Drive Specifies the physical drive number to be confirmed.
 * @return DSTATUS\n
 * Returns disk status as the result.\n
 * <b>STA_NOINIT:</b> Indicates that the disk drive has not been initialized. 
 * This flag is set on: system reset, disk removal and disk_initialize function failed,
 * and cleared on: disk_initialize function succeeded. \n
 * <b>STA_NODISK:</b>Indicates that no medium in the drive. This is always cleared on fixed disk drive.\n
 * <b>STA_PROTECTED:</b>Indicates that the medium is write protected. This is always 
 * cleared on the drive that does not support write protect notch. Not valid when STA_NODISK is set. \n
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   DSTATUS DStatus;
 *   // DAVE Initialization.
 *   DAVE_Init();
 *   // SDMMC drive number will be at '0' drive  
 *   DStatus =  disk_status(0);
 *   if (DStatus == (STA_NODISK | STA_NOINIT))
 *   {
 *     //No card Present;
 *   }
 *   if (DStatus == STA_NOINIT)
 *   {
 *     //Card Present but not initialized.
 *   }
 *   if (DStatus == STA_PROTECT)
 *   {
 *     //Card is Write Protected .
 *   } 
 *   return 0;
 * }
 * @endcode
 */
DSTATUS disk_status(BYTE Drive);

/**
 * @brief The disk_read function reads sector(s) from the disk drive. Note that 
 * the specified memory address to store read data is not that always aligned to word boundary.
 * If the hardware does not support misaligned data transfer, it must be solved
 * in this function. 
 * @param[in] Drive Physical drive number 
 * @param[in] Buffer Pointer to the byte array to store the read data.
 * The buffer size of number of bytes to be read, sector size * sector count, is required. 
 * @param[in] SectorNumber Specifies the start sector number in logical block address (LBA). 
 * @param[in] SectorCount Specifies number of sectors to read. The value can be 1 to 128. 
 * Generally, a multiple sector transfer request must not be split into single 
 * sector transactions to the device, or you may not get good read performance. 
 * @return DRESULT \n
 * RES_OK The function succeeded.\n
 * RES_ERROR Any hard error occurred during the read operation and could
 * not recover it.\n
 * RES_PARERR Invalid parameter\n
 * RES_NOTRDY The disk drive has not been initialized.\n
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   uint32_t Counter = 0;
 *   uint32_t Count = 0;
 *   DRESULT DResult;
 *    // NOTE: This buffer has to be aligned to 4-byte boundary !!!!!!!
 *   uint32_t ReadData[256] = {0};
 *   uint32_t WriteData[256] = {0};
 *   // DAVE Initialization.
 *   DAVE_Init();
 *   // Write some data to be written on the card 
 *   for(Counter=0;Counter<256;Counter++)
 *   {
 *     WriteData[Counter] = Counter * 10;
 *   }
 *   // Write functionality 
 *   DResult =  disk_write(0,(uint8_t*)WriteData,200, 2);
 *   if(DResult == RES_OK)
 *   {
 *     // Read functionality 
 *     DResult =  disk_read(0, (uint8_t*)ReadData, 200, 2);
 *     // Write and Read data validation
 *     for( Count=0; Count<256; Count++)
 *     {
 *       if( ReadData[Count] != WriteData[Count])
 *       {
 *         // Read and Write Data doesn't match.
 *       }
 *     }
 *   }
 *   return 0;
 * }
 * @endcode
 */
DRESULT disk_read
(
  BYTE Drive,
  BYTE *Buffer,
  DWORD SectorNumber,
  BYTE SectorCount
);

/**
 * @brief The disk_write writes sector(s) to the disk.Note that the specified memory 
 * address from where to write data is not that always aligned to word boundary. 
 * If the hardware does not support misaligned data transfer, it must be solved
 * in this function.This function is not required in read only configuration.
 * @param[in] Drive Specifies the physical drive number
 * @param[in] Buffer Pointer to the byte array to be written. 
 * @param[in] SectorNumber Specifies the start sector number in logical block address (LBA). 
 * @param[in] SectorCount Specifies the number of sectors to write. The value can
 * be 1 to 128. Generally, a multiple sector transfer request must not be split
 * into single sector transactions to the device, or you will never get good 
 * write performance.
 * @return
 * RES_OK The function succeeded.\n
 * RES_ERROR Any hard error occured during the write operation and could not recover it.\n
 * RES_PARERR Invalid parameter\n
 * RES_NOTRDY The disk drive has not been initialized.\n
 * RES_WRPRT The medium is write protected.\n
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   DRESULT DResult;
 *   uint32_t Counter = 0;
 *   uint32_t Count = 0;
 *    // NOTE: This buffer has to be aligned to 4-byte boundary !!!!!!!
 *   uint32_t ReadData[256] = {0};
 *   uint32_t WriteData[256] = {0};
 *   // DAVE Initialization.
 *   DAVE_Init();
 *   for(Counter=0;Counter<256;Counter++)
 *   {
 *     WriteData[Counter] = Counter * 10;
 *   }
 *   // Write functionality 
 *   DResult =  disk_write(0,(uint8_t*)WriteData,200, 2);
 *   if(DResult == RES_OK)
 *   {
 *     // Read data from card to verify the data written. 
 *     DResult =  disk_read(0, (uint8_t*)ReadData, 200, 2);
 *     for( Count=0; Count<256; Count++)
 *     {
 *       if( ReadData[Count] != WriteData[Count])
 *       {
 *         // Read and Write Data doesn't match.
 *       }
 *     }
 *   }
 *   return 0;
 * }
 * @endcode
 */
DRESULT disk_write
(
  BYTE Drive,
  const BYTE*  Buffer,
  DWORD SectorNumber,
  BYTE  SectorCount
);

/**
 * @brief  The disk_ioctl function controls device specified features and
 * miscellaneous functions other than disk read/write. The FatFs module uses
 * only device independent commands described below. Any device dependent function is not used.
 * @param[in] Drive Specifies the drive number (0-9). 
 * @param[in] Command Specifies the command code. 
 * @param[in] Buffer Pointer to the parameter buffer depends on the command code. 
 * When it is not used, specify a NULL pointer.  
 * @return DRESULT \n
 * RES_OK The function succeeded.\n
 * RES_ERROR Any error occurred.\n
 * RES_PARERR Invalid command code.\n
 * RES_NOTRDY The disk drive has not been initialized.\n
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 * <BR><P ALIGN="LEFT">
 * <b>Generic command (defined for FatFs)  </b>\n
 * <p> CTRL_SYNC: Flush disk cache (for write functions) \n
 *  GET_SECTOR_COUNT: Get media size (for only f_mkfs())  \n
 *  GET_SECTOR_SIZE: Get sector size (for multiple sector size (_MAX_SS >= 1024)) \n
 *  GET_BLOCK_SIZE: Get erase block size (for only f_mkfs()) \n
 *  CTRL_ERASE_SECTOR:  Force erased a block of sectors (for only _USE_ERASE) \n
 *  </p> \n
 * <b> Generic command </b> \n
 * <p> CTRL_EJECT: Eject media </p>\n
 * <b> MMC/SDC specific ioctl commands </b> \n
 * <p> MMC_GET_TYPE: Get card type \n
 *  MMC_GET_CSD: Get CSD \n
 *  MMC_GET_CID: Get CID \n
 *  MMC_GET_OCR: Get OCR \n
 *  MMC_GET_SDSTAT:  Get SD status \n
 * </p>
 * </p>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   DRESULT Result;
 *   uint32_t Buffer;
 *   // Get Sector Count
 *   Result = disk_ioctl(0,GET_SECTOR_COUNT,(void *)&Buffer);
 *   if (Result == RES_OK)
 *   {
 *     // Get Card Type
 *     Result = disk_ioctl( 0,MMC_GET_TYPE,(void *)&Buffer);
 *     if (Result == RES_OK )
 *     {
 *       if( Buffer & SDMMC003_SD_STANDARD_CAPACITY_V2)
 *       {
 *         // Standard Capacity Card version2
 *       }
 *       if( Buffer & SDMMC003_SD_STANDARD_CAPACITY_V1x)
 *       {
 *         // Standard Capacity Card version1.
 *       } 
 *       if( Buffer & SDMMC003_SD_HIGH_CAPACITY)
 *       {
 *         // High Capacity Card.
 *       }
 *     }
 *   }
 *   // Eject card //
 *   Result = disk_ioctl(0,CTRL_EJECT,NULL);
 *   return 0;
 * }
 * @endcode
 */
DRESULT  disk_ioctl(BYTE Drive, BYTE Command, void * Buffer);

/**
 * @brief  The get_fattime function gets current time.The get_fattime function 
 * must return any valid time even if the system does not support a real time clock. 
 * If a zero is returned, the file will not have a valid time. This fucntion is
 * not required in read only configuration.
 * @return Current time is returned with packed into a DWORD value. The bit
 * field is as follows:\n
 * bit31:25: Year from 1980 (0..127)\n
 * bit24:21: Month (1..12)\n
 * bit20:16: Day in month(1..31)\n
 * bit15:11: Hour (0..23)\n
 * bit10:5: Minute (0..59)\n
 * bit4:0: Second / 2 (0..29)\n
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   uint32_t Time;
 *   Time = get_fattime();
 *   return 0;
 * }
 * @endcode
 */
DWORD get_fattime(void);

/**
 * @}
 */

#endif /* FATFS004_H_ */

/*CODE_BLOCK_END*/



