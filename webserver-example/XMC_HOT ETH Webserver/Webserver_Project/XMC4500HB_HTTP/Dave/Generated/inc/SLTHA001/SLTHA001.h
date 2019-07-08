

/*CODE_BLOCK_BEGIN[SLTHA001.h]*/

/******************************************************************************
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with 
 * Infineon's microcontrollers.This file can be freely distributed within development
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
** MODIFICATION DATE : July 31, 2012                                          **
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
 * @file SLTHA001.h
 *
 * @brief This file contains all the public and private function type declarations
 * of Standard Lib App.
 *
 */

#ifndef SLTHA001_H_
#define SLTHA001_H_

/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include "../../inc/FATFS002/FATFS002.h"
#include <DAVE3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#if defined (__GNUC__) || defined (__TASKING__)
  #include <fcntl.h>
  #include <unistd.h>
#endif

#ifdef __GNUC__
  #include <reent.h>
#elif __CC_ARM
  #include <rt_sys.h>
  #include <RTL.h>
#elif __ICCARM__
 #include <yfuns.h>
#elif __TASKING__
 #include <io.h>
#endif


/**
 * @ingroup SLTHA001_publicparam
 * @{
 */
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* File creation Flags */
#if defined(__GNUC__) || defined(__TASKING__)
  #define       SLTHA001_RDONLY       O_RDONLY
  #define       SLTHA001_WRONLY       O_WRONLY
  #define       SLTHA001_RDWR         O_RDWR
  #define       SLTHA001_APPEND       O_APPEND
  #define       SLTHA001_CREAT        O_CREAT
  #define       SLTHA001_TRUNC        O_TRUNC
  #define       SLTHA001_EXCL         O_EXCL
  #define       SLTHA001_SYNC         O_SYNC
  #define       SLTHA001_NONBLOCK     O_NONBLOCK
  #define       SLTHA001_NOCTTY       O_NOCTTY
  #define       SLTHA001_RDWRMASK     O_ACCMODE

#elif defined __CC_ARM
  #define       SLTHA001_RDONLY       OPEN_R
  #define       SLTHA001_WRONLY       OPEN_W
  #define       SLTHA001_RDWR         OPEN_PLUS
  #define       SLTHA001_APPEND       OPEN_A

#elif defined __ICCARM__
  #define       SLTHA001_RDONLY       _LLIO_RDONLY
  #define       SLTHA001_WRONLY       _LLIO_WRONLY
  #define       SLTHA001_RDWR         _LLIO_RDWR
  #define       SLTHA001_APPEND       _LLIO_APPEND
  #define       SLTHA001_CREAT        _LLIO_CREAT
  #define       SLTHA001_TRUNC        _LLIO_TRUNC
  #define       SLTHA001_EXCL         _LLIO_EXCL
  #define       SLTHA001_RDWRMASK     _LLIO_RDWRMASK
#endif


/** Standard Input File Descriptor */
#define STDIN_HANDLE                                      0
/** Standard Output File Descriptor */
#define STDOUT_HANDLE                                     1
/** Standard Error File Descriptor */
#define STDERR_HANDLE                                     2

#ifdef __GNUC__
/** Maximum Number of Files that can be opened.*/
  #define MAX_OPEN_FILES                                    FOPEN_MAX
#elif __CC_ARM
  #define MAX_OPEN_FILES                                    _SYS_OPEN
#elif __ICCARM__
  #define MAX_OPEN_FILES                                    FOPEN_MAX
#elif __TASKING__
  #define MAX_OPEN_FILES 								    FOPEN_MAX
#endif


/** Empty Slot Value */
#define EMPTY_SLOT                                         (-1)
/**Fat Fs Handle  Value adjusted to stay away from Internal Handles. */
#define MONITOR_FATFS                                      (3)
/** File System Wrapper Error */
#define FILE_WRAPPER_ERROR                                 (-1)   

#if defined (__CC_ARM) || (__ICCARM__)
typedef short  mode_t   ;
#elif defined (__TASKING__)
typedef unsigned char  mode_t;
#endif

#ifdef __CC_ARM
#pragma import(__use_no_semihosting_swi)
/* The following macro definitions may be used to translate this file:
   STDIO - use standard Input/Output device default is NOT used) */
/** Standard IO device handles. */
#define STDIN   0x8001
#define STDOUT  0x8002
#define STDERR  0x8003

#endif

/**
 * @}
 */

/**
 * @cond INTERNAL_DOCS
 */

/**
 * @ingroup SLTHA001_privateparam
 * @{
 */


/*******************************************************************************
**                      Structures                                            **
*******************************************************************************/
/**
 * Structure containing all the file details.
 */
typedef struct SLTHA001_FileHandleStruct
{
  int Fd;
  int CurrentPos;
  int Flags;
  FIL *FatFsPtr;
  char *FilePath;
} SLTHA001_FileHandleStruct;


/**
 * @}
 */

/**
 * @endcond
 */

/**
 * @ingroup SLTHA001_apidoc
 * @{
 */

/*******************************************************************************
 ** FUNCTION PROTOTYPES                                                       **
*******************************************************************************/
/**
 * @brief  This function opens the file specified by the Path in the mode 
 * specified by the Flags.
 * @param[in] Path File name or File Path.
 * @param[in] Flags Modes in which to open a file.
 * @return  int
 * File Descriptor: If Successful<BR> 
 * -1: If file open fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#ifdef __GNUC__
int _open(const TCHAR *Path, int Flags,...);
#elif __CC_ARM
FILEHANDLE _sys_open
(
  const char  *Path,
  int Flags
);
#elif __TASKING__
_err_t _open
(
  const char *Path,
  _open_flags_t Flags
);
#elif __ICCARM__
int __open
(
  const char * Path,
  int Flags
);
#endif
/**
 * @brief  This function closes the file specified by the File descriptor.
 * @param[in] Fd File Descriptor
 * @return int <BR>
 * DAVEApp_SUCCESS: if successful.<BR> 
 * FILE_WRAPPER_ERROR: If function fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#ifdef __GNUC__
  int _close(int Fd);
#elif __CC_ARM
  int _sys_close(FILEHANDLE Fd);
#elif __TASKING__
  _err_t  _close(_fd_t Fd);
#elif __ICCARM__
  int __close(int Fd);
#endif
/**
 * @brief  This function reads Length bytes of data from the file specified
 * by the File descriptor.
 * @param[in] r Re-entrancy pointer
 * @param[in] Fd File Descriptor
 * @param[in] BufferPtr Buffer to write data into.
 * @param[in] Length No of Bytes of Data to read.
 * @return  int <BR>
 * No of Bytes read: If successful.<BR> 
 * FILE_WRAPPER_ERROR(-1): If error.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#ifdef __GNUC__
_ssize_t _read_r
(
  struct _reent *r,
  int Fd,
  void *BufferPtr,
  size_t Length
);
#elif __CC_ARM
int _sys_read
(
  FILEHANDLE Fd,
  U8 *BufferPtr,
  U32 Length,
  int mode
);
#elif __TASKING__
int _read
(
  _fd_t Fd,
  void *BufferPtr,
  size_t Length
);
#elif __ICCARM__
size_t __read
(
  int handle,
  unsigned char *BufferPtr,
  size_t Length
);
#endif

/**
 * @brief  This function writes Length bytes of data into the file specified
 * by the File descriptor.
 * @param[in] r Re-entrancy pointer
 * @param[in] Fd File Descriptor
 * @param[in] BufferPtr Buffer from where to take data to write.
 * @param[in] Length No of Bytes of Data to Write.
 * @return int <BR>
 * No of Bytes written if successful.<BR>
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#ifdef __GNUC__
_ssize_t _write_r
(
 struct _reent *r,
  int Fd,
  const void *BufferPtr,
  size_t Length
);
#elif __CC_ARM
int _sys_write
(
  FILEHANDLE Fd,
  const U8 *BufferPtr,
  U32 Length,
  int Mode
);
#elif __TASKING__
int _write
(
  _fd_t Fd,
  const void *BufferPtr,
  size_t Length
);
#elif __ICCARM__
size_t __write
(
  int Fd,
  const unsigned char * BufferPtr,
  size_t Length
);
#endif

/**
 * @brief  This function Move file pointer of a file object specified by the
 * File Descriptor.
 * @param[in] Fd File Descriptor
 * @param[in] Offset The value of offset determines the new position.
 * @param[in] DirMode  
 * SEEK_SET: Offset from the beginning of the file desired.
 * SEEK_CUR: Offset is relative to the current file position. 
 * EEK_END: Offset is relative to the current end of file. 
 * @return  int <BR>
 * Current File Pointer Position:  If Success.<BR>  
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR> 
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#ifdef __GNUC__
int _lseek
(
  int Fd,
  long Offset,
  int DirMode
);
#elif __CC_ARM
int _sys_seek
(
  FILEHANDLE Fd,
  long Offset
);
#elif __TASKING__
long  _lseek
(
  _fd_t Fd,
  long Offset,
  _whence_t DirMode
);
#elif __ICCARM__
long __lseek
(
  int Fd,
  long Offset,
  int DirMode
);
#endif

/**
 * @brief  This function Delete an existing file or directory.
 * @param[in] Path File name or File Path.
 * @return int  
 * FR_OK: If Successful <BR>
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#ifdef __GNUC__
  int _unlink (const char  *Path);
#elif __CC_ARM
  int remove(const char *Path);
#elif __TASKING__
  int _unlink (const char *Path);
#elif __ICCARM__
  int remove(const char * Path);
#endif

/**
 * @brief  This function gets file status on basis of file descriptor passed.
 * @param[in] Fd File Descriptor.
 * @param[out] FileStatusPtr: Stat Structure to return Status into. 
 * @return  int <BR>
 * FR_OK: if Successful <BR>
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#if defined __GNUC__ || defined __TASKING__
int _fstat(int Fd, struct stat *FileStatusPtr);
#endif

/**
 * @brief  This function gets file status on basis of file path 
 * @param[in] Path File name or File Path.
 * @param[out] FileStatusPtr Stat Structure to return Status into. 
 * @return int <BR>
 * FR_OK if Successful else Error.
 */
#if defined __GNUC__ || defined __TASKING__
int _stat(const char *Path,  struct stat *FileStatusPtr);
#endif

/**
 * @brief  This function rename/move a file or directory 
 * @param[in] OldPath Old File name or File Path.
 * @param[in] NewPath New File Name or File Path.
 * @return int <BR>
 * FR_OK: if Successfull.<BR>
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#if defined __GNUC__ || defined __TASKING__
  int _rename( const char *OldPath,  const char *NewPath);
#elif __CC_ARM
  int rename(const char *OldPath, const char *NewPath);
#elif __ICCARM__
  int rename(const char *OldPath, const char *NewPath);
#endif

/**
 * @brief  This function change attributes of the file/dir 
 * @param[in] Path File name or File Path.
 * @param[in] Mode Attribute bits
 * @return  int <BR>
 * FR_OK: if Successful <BR>
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#if defined __GNUC__
int _chmod (const char *Path, mode_t Mode);
#elif defined __CC_ARM || defined __ICCARM__ || defined __TASKING__
int chmod (const char *Path, mode_t Mode);
#endif

/**
 * @brief  This function creates a new directory
 * @param[in] Path File name or File Path.
 * @param[in] Mode Attribute bits
 * @return  int <BR>
 * FR_OK: if Successful <BR>
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#if defined __GNUC__
int _mkdir (const char *Path, mode_t Mode);
#elif defined __CC_ARM || defined __ICCARM__ || defined __TASKING__
int mkdir (const char *Path, mode_t Mode);
#endif

/**
 * @brief  This function flush cached data of a writing file
 * @return void<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#if defined __GNUC__
void  _sync (void);
#elif defined __CC_ARM || defined __ICCARM__ || defined __TASKING__
void  sync (void);
#endif



#if _USE_MKFS
/**
 * @brief  This function creates the file system on the drive.This should be 
 * used only when USE_MKFS option is seleted from FATFS GUI.
 * @param[in] DriveNumber Logical drive number (0-9) to be formatted. 
 * @param[in] PartitioningRule Specifies partitioning rule, FDISK(0) or SFD(1). 
 * This argument is ignored on some case. 
 * @param[in] AllocSize Force the allocation unit (cluter) size in unit of byte.
 * @return  int
 * FR_OK: if Successful <BR>
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
 
int mkfs( uint8_t DriveNumber, uint8_t PartitioningRule,uint32_t AllocSize);
#endif
/**
 * @brief This function registers/unregisters a work area.
 * @param[in] DriveNumber Logical drive number (0-9) to register/unregister the work area.
 * @param[in] FatFSObj Pointer to the work area (file system object) to be registered. 
 * @return : int
 * FR_OK: if Successful <BR>
 * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
int mount( uint8_t DriveNumber, FATFS *FatFSObj);


/**
 * @brief  This function querries whether output stream is a terminal. 
 * @param[in] Fd File Descriptor 
 * @return : int<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#if defined(__GNUC__)  || defined (__CC_ARM)
#if defined(__GNUC__)
int _isatty(int Fd);
#elif defined (__CC_ARM)
int _sys_istty(FILEHANDLE Fd);
#endif
#endif



/**
 * @brief  This function initializes all the local variables of Standard Library App.
 * It should be called first inorder to use SLTHA001 App 
 * @return : void<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SLTHA001_Init(void);


#if defined(__GNUC__)

/**
 * @brief This function establish a new name for an existing file. This 
 * function is not supported by Fat File system.
 * @param[in] OldName Old file name
 * @param[in] NewName New file name  
 * @return : void <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
int _link (char *OldName, char *NewName);

#endif
/**
 * @brief This function creates a partition table into the physical drive(Master Boot Recorder-MBR).<BR>
 * 1. The partitioning rule is in generic FDISK format hence it can create only upto
 * four primary partitions.<BR>
 * 2. Extended partition is not supported. <BR>
 * 3. The Partitions[] specifies how to divide the physical drive.The first item 
 *    specifies the size of first primary partition and fourth item specifies the 
 *    fourth primary partition. there are 2 methods to define partitions.<BR>
 *    Method 1: % based. If the value is less than or equal to 100, 
 *    it means percentage of the partition in the entire disk space. <BR>
 *    Method 2: Sector Based.If it is larger than 100, it means partition size in unit of sector.<BR>
 * Eg: To create 4 partitions of equal size where physical drive has 10,000 sectors.
 *    <BR>Method 1: Partitions[] = {25,25,25,25};
 *    <BR>Method 1: Partitions[] = {2500,2500,2500,2500};<BR>
 *  Apart from these, User also needs to define Logical to Physical drive mapping.
 *  For this, an array  VolToPart[] needs to be defined as:<BR>
 *  PARTITION VolToPart[] = { <BR>
 *            {0, 1},   // Logical drive 0 ==> Physical drive 0(SDMMC), 1st partition  <BR> 
 *            {0, 2},   // Logical drive 1 ==> Physical drive 0(SDMMC), 2nd partition  <BR> 
 *            {1, 0}    // Logical drive 2 ==> Physical drive 1(USB), auto detection  <BR>
 *            } <BR>
 * NOTE: The Partitions created is not visible in Windows. Linux supports the visibility of the partitions
 * created by this function.
 * @param[in] DriveNumber Specifies the physical drive to be divided. 
 * @param[in] Partitions Partition map table. It must have four items.
 * @param[in] Work Pointer to the function work area. The size must be at least
 * FatFs GUI configuration  _MAX_SS bytes. <BR>
 * @return: int<BR>
 * FILE_WRAPPER_ERROR: If function fails.
 * DAVEApp_SUCCESS: If function succeeds.
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
int fdisk( uint8_t DriveNumber, const uint32_t Partitions[], void * Work);

#if defined ( __ICCARM__)
size_t __dwrite(int Fd,const unsigned char *BufferPtr, size_t Length);
#endif


#ifdef SLTHA001_ELUA_IN_USE
pid_t _getpid(void);

void _exit( int Status );

int _kill( int Pid, int Sig );

void* fatfs_opendir_r( struct _reent *r, const char* DirName );

struct dm_dirent* fatfs_readdir_r( struct _reent *r, void *d );

int fatfs_closedir_r( struct _reent *r, void *d );

#endif
/**
 * @}
 */


#endif /* SLTHA001_H_ */

/*CODE_BLOCK_END*/



