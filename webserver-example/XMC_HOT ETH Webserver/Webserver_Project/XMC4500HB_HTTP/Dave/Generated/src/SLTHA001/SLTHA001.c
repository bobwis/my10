
/* CODE_BLOCK_BEGIN[SLTHA001.c]*/
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
 * @file   SLTHA001.c
 *
 * @brief  This file contains definitions of all private and public
 *         functions of Standard Library App.
 */

/*****************************************************************************
 * INCLUDE FILES
 *****************************************************************************/
#include <DAVE3.h>

#ifdef SLTHA001_ELUA_IN_USE
#include "../../src/LUA001/elua0.8/inc/newlib/devman.h"
#include "../../src/LUA001/elua0.8/inc/newlib/genstd.h"

#endif

/**
 * @cond INTERNAL_DOCS
 */
/**
 * @ingroup SLTHA001_privatefunc
 * @{
 */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/**
 * @brief  This function finds whether the file is already opened and also assign a slot for any new 
 * file to open.
 * @param[in] FileDesc File Descriptor for which slot to find.
 * @return : uint32_t <BR>
 * Slot Number: Allocated Slot Number.
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
uint32_t  SLTHA001_lFindAvailableSlot(int FileDesc);

/**
 * @brief Function to Initialize all the local variables and file descriptors. This function should be
 * called at the very first .
 * @return : void <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SLTHA001_lLocalInitialize(void);

#if _FS_MINIMIZE == 0
#if defined (__GNUC__) || defined ( __TASKING__)
/**
 * @brief  This function finds whether the file is already opened and also assign a slot for any new 
 * file to open.
 * @param[in] FatFsInfoPtr Pointer to File Info Structure.
 * @return : time_t <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
static time_t SLTHA001_lTimeFormat(FILINFO *FatFsInfoPtr);



/**
 * @brief  Function to store the file information in the file status pointer 
 * @param[out] FileStatusPtr Pointer to stat Structure.
 * @param[in] FatFsInfoPtr Pointer to File Info Structure.
 * @return : void <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
static void SLTHA001_lFatInfoToStatus(struct stat *FileStatusPtr, \
                                      FILINFO *FatFsInfoPtr);

#endif
#endif
/**
 * @brief  This function set the file access modes .
 * @param[in] FlagsPtr Flags passed by the user
 * @param[out] FatFsFlagPtr Pointer to Fat file system flags type.
 * @return : status_t/_err_t  <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
#ifdef  __TASKING__
  static _err_t SLTHA001_lSetFlagsAccessModes( _open_flags_t *FlagsPtr, \
                                            BYTE *FatFsFlagPtr );
#else
  static status_t SLTHA001_lSetFlagsAccessModes( int *FlagsPtr, \
                                                 BYTE *FatFsFlagPtr );
#endif
/**
 * @}
 */

/**
 * @endcond
 */


/*******************************************************************************
 *                                ARRAYS                                      **
 ******************************************************************************/
#if defined(__GNUC__) || defined(__TASKING__)
uint32_t ErrorCodes[19] = {
                             DAVEApp_SUCCESS,  FILE_WRAPPER_ERROR,
                             FILE_WRAPPER_ERROR, EIO,
                             ENOENT,             ENOENT,
                             EINVAL,             EACCES,
                             EEXIST,             EBADF,
                             EACCES,             ENODEV,
                             EIO,                EIO,
                             FILE_WRAPPER_ERROR, FILE_WRAPPER_ERROR,
                             FILE_WRAPPER_ERROR, FILE_WRAPPER_ERROR,
                             FILE_WRAPPER_ERROR
                          };
#elif defined __CC_ARM
uint32_t ErrorCodes[19] = { EINVAL };
#elif defined __ICCARM__
uint32_t ErrorCodes[19] = {_LLIO_ERROR};
#endif
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
SLTHA001_FileHandleStruct FileHandle[MAX_OPEN_FILES] = {{0}};
#ifdef SLTHA001_ELUA_IN_USE
static DIR SLTHA001_MmcDir;

extern struct dm_dirent dm_shared_dirent;
extern char dm_shared_fname[ DM_MAX_FNAME_LENGTH + 1 ];
#endif


#ifdef __CC_ARM
/** Standard IO device name defines. */
const char __stdin_name[]  = "STDIN";
const char __stdout_name[] = "STDOUT";
const char __stderr_name[] = "STDERR";
#endif
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/**
 * @cond INTERNAL_DOCS
 */
/* <<<DD_SLTHA001_nonAPI_1>>> */
/* 
 * Function to find whether the file is already opened and also assign a slot for any new 
 * file to open.
 */
uint32_t  SLTHA001_lFindAvailableSlot(int FileDesc)
{
  static int Slot;
  static int LastAllocFileHandle = -1;
  do
  {
/* <<<DD_SLTHA001_nonAPI_1_1>>> */
    /* Check if the File handle is the last allocated one */
    if( (FileDesc != -1)  && (FileDesc == LastAllocFileHandle))
    {
      break;
    }
/* <<<DD_SLTHA001_nonAPI_1_2>>> */
    /* Check the FileHandle array to find the match for the File Handle*/
    for (Slot=0; Slot< MAX_OPEN_FILES; Slot++)
    {
      if(FileHandle[Slot].Fd == FileDesc)
      break;
    }
    /* Save the last Allocated File Handle.*/
    LastAllocFileHandle = FileDesc;
  } while(0);
  return Slot;
}

/*<<<DD_SLTHA001_nonAPI_2>>>*/
/*
 * Function to Initialize all the local variables and file descriptors. This function should be
 * called very first .
 */
void SLTHA001_lLocalInitialize()
{
  int Slot;
/* Initialize Handle in the FileHandle Structure to -1*/
  for(Slot=0; Slot<MAX_OPEN_FILES; Slot++)
  {
    FileHandle[Slot].Fd = -1;
  }
/* Preserve the 0th, 1th and 2nd File Handles for Standard I/O and Error.*/
  FileHandle [0].Fd = STDIN_HANDLE;
  FileHandle [1].Fd = STDOUT_HANDLE;
  FileHandle [2].Fd = STDERR_HANDLE;
}


#if _FS_MINIMIZE == 0
#if defined (__GNUC__) || defined ( __TASKING__)
/* <<<DD_SLTHA001_nonAPI_4>>> */
/*
 * This function converts the time format 
 */
static time_t SLTHA001_lTimeFormat(FILINFO *FatFsInfoPtr)
{
  struct tm TimeStruct;
  TimeStruct.tm_sec  = (FatFsInfoPtr->ftime & 0x001f) << 1;
  TimeStruct.tm_min  = (FatFsInfoPtr->ftime & 0x07e0) >> 5;
  TimeStruct.tm_hour = (FatFsInfoPtr->ftime & 0xf800) >> 11;
  TimeStruct.tm_mday = (FatFsInfoPtr->fdate & 0x001f);
  TimeStruct.tm_mon  = ((FatFsInfoPtr->fdate & 0x01e0) >> 5) - 1;
  TimeStruct.tm_year = ((FatFsInfoPtr->fdate & 0xfe00) >> 9) + 80;
  TimeStruct.tm_isdst = 0;
  return mktime(&TimeStruct);
}
#endif

/* <<<DD_SLTHA001_nonAPI_5>>> */
/*
 *  Function to store the file information in the file status pointer 
 */
#if defined (__GNUC__) || defined ( __TASKING__)
static void SLTHA001_lFatInfoToStatus(struct stat *FileStatusPtr, \
                                      FILINFO *FatFsInfoPtr)
{
  memset(FileStatusPtr, 0, sizeof(*FileStatusPtr));
  /*Populate the Argument Status Pointer with the Fat FS status Pointer*/
  FileStatusPtr->st_mode |= (FatFsInfoPtr->fattrib & AM_DIR) ? \
                                                            S_IFDIR : S_IFREG;
  
#if defined (__GNUC__)
  FileStatusPtr->st_mode |= (FatFsInfoPtr->fattrib & AM_RDO) ? \
                                                 ((S_IRWXU & ~S_IWUSR) | \
                                                 (S_IRWXG & ~S_IWGRP) | \
                                                 (S_IRWXO & ~S_IWOTH)) : \
                                                 (S_IRWXU | S_IRWXG | S_IRWXO);
#else

  FileStatusPtr->st_mode |= (FatFsInfoPtr->fattrib & AM_RDO) ? \
                                                    (~_S_IWRITE)  : \
                                                    (_S_IWRITE);
#endif
  FileStatusPtr->st_size = FatFsInfoPtr->fsize;
  FileStatusPtr->st_ctime = SLTHA001_lTimeFormat(FatFsInfoPtr);
  FileStatusPtr->st_mtime = FileStatusPtr->st_ctime;
  FileStatusPtr->st_atime = FileStatusPtr->st_ctime;
#if defined (__GNUC__)
  FileStatusPtr->st_blksize = 512;
#endif
}
#endif
#endif

/*<<<DD_SLTHA001_nonAPI_6>>> */
/*
 * This function set the file access modes 
 */
#ifdef  __TASKING__
  static _err_t SLTHA001_lSetFlagsAccessModes( _open_flags_t *FlagsPtr, \
                                            BYTE *FatFsFlagPtr )
#else
  static status_t SLTHA001_lSetFlagsAccessModes( int *FlagsPtr, \
                                                 BYTE *FatFsFlagPtr )
#endif
{
#ifdef  __TASKING__
  _err_t Status = FILE_WRAPPER_ERROR;
#else
  int Status = FILE_WRAPPER_ERROR;
#endif
  do
  {
#if defined(__GNUC__) || defined( __TASKING__) || defined(__ICCARM__ )
/*<<<DD_SLTHA001_nonAPI_6_1>>> */
     /*  Append and Truncate flags cannot be set together */
    if (*FlagsPtr & SLTHA001_APPEND)
    {
      *FlagsPtr &= ~SLTHA001_TRUNC ;
    }
/*<<<DD_SLTHA001_nonAPI_6_2>>> */
    /* Create & Truncate & Access mode is Write */
    if ( ((*FlagsPtr & (SLTHA001_CREAT | SLTHA001_TRUNC)) ==
         (SLTHA001_CREAT | SLTHA001_TRUNC)) && (*FlagsPtr & (SLTHA001_RDWR | \
                                                             SLTHA001_WRONLY)))
    {
#if _FS_READONLY
      break;
#else
      *FatFsFlagPtr = FA_CREATE_ALWAYS;
#endif
    }
    /* O_EXCL  When used with O_CREAT, if the file already exists it is an error
    *  and the open() will fail. */
/*<<<DD_SLTHA001_nonAPI_6_3>>> */
    else if ((*FlagsPtr & (SLTHA001_CREAT | SLTHA001_EXCL)) ==
                          (SLTHA001_CREAT | SLTHA001_EXCL))
    {
      *FatFsFlagPtr = FA_OPEN_EXISTING;
    }
/*<<<DD_SLTHA001_nonAPI_6_4>>> */
    /* Only create flag is set, opens the file if exist else creates a new file */
    else if ((*FlagsPtr & SLTHA001_CREAT) == SLTHA001_CREAT)
    {
#if _FS_READONLY
       break;
#else
      *FatFsFlagPtr = FA_OPEN_ALWAYS;
#endif
    }
/*<<<DD_SLTHA001_nonAPI_6_5>>> */
    /* Opens the file if any of the read, write or r/w flags are only set*/
    else if ((*FlagsPtr == SLTHA001_RDONLY) || (*FlagsPtr == SLTHA001_WRONLY)
                                            || (*FlagsPtr == SLTHA001_RDWR))
    {
      *FatFsFlagPtr = FA_OPEN_EXISTING;
    }
/*<<<DD_SLTHA001_nonAPI_6_6>>> */
    else
    {
#if defined(__GNUC__) || defined( __TASKING__)
      errno = EINVAL;
#elif defined( __ICCARM__)                              
      errno = _LLIO_ERROR;
#endif
      break;
    }
#endif
/*<<<DD_SLTHA001_nonAPI_6_7>>> */
    /* Check the access mode */
#if defined(__GNUC__) || defined( __TASKING__) || defined( __ICCARM__ )
    if ((*FlagsPtr & SLTHA001_RDWRMASK) == SLTHA001_RDONLY)
#elif defined __CC_ARM
    if (*FlagsPtr &  SLTHA001_RDONLY)
#endif
    {
      *FatFsFlagPtr |= FA_READ;
    }
/*<<<DD_SLTHA001_nonAPI_6_8>>> */
#if defined(__GNUC__) || defined( __TASKING__) || defined( __ICCARM__ )
    else if ((*FlagsPtr & SLTHA001_RDWRMASK) == SLTHA001_WRONLY)
#elif defined __CC_ARM
    else if(*FlagsPtr &  SLTHA001_WRONLY)
#endif
    {
#if _FS_READONLY
      break;
#else
      *FatFsFlagPtr |= FA_WRITE;
#endif
    }
/*<<<DD_SLTHA001_nonAPI_6_9>>> */
#if defined(__GNUC__) || defined( __TASKING__) || defined( __ICCARM__ )
    else if ((*FlagsPtr & SLTHA001_RDWRMASK) == SLTHA001_RDWR)
#elif defined __CC_ARM
    else if (*FlagsPtr & SLTHA001_RDWR)
#endif
    {
#if _FS_READONLY
      break;
#else
      *FatFsFlagPtr |= (FA_READ | FA_WRITE);
#endif
    }
/*<<<DD_SLTHA001_nonAPI_6_10>>> */
    else
    {
#if defined(__GNUC__) || defined( __TASKING__)
      errno = EINVAL;
#elif defined  __ICCARM__
      errno = _LLIO_ERROR;
#elif defined __CC_ARM
      errno = EINVAL;
#endif
      break;
    }
    Status = DAVEApp_SUCCESS;
  } while(0);
  return Status;
}

/**
 * @endcond
 */

/******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
/* <<<DD_SLTHA001_API_1>>> */
/*
 * This function opens the file specified by the Path in the mode 
 */
#ifdef __GNUC__
int _open
(
   const TCHAR *Path,
   int Flags,...
)
#elif __CC_ARM

FILEHANDLE _sys_open
(
  const char  *Path,
  int Flags
)
#elif  __TASKING__
_err_t _open
(
  const char *Path,
  _open_flags_t Flags
)
#elif  __ICCARM__
int __open
(
  const char * Path,
  int Flags
)
#endif
{
#ifdef  __TASKING__
  _err_t Status = FILE_WRAPPER_ERROR;
  _err_t FileDesc = 0;
#else
  int Status = FILE_WRAPPER_ERROR;
  int FileDesc = 0;
#endif
  int  SlotNumber;
  uint32_t PathLen = 0;
  BYTE FatFsFlags = FA_OPEN_EXISTING;
  FRESULT Result;
  do
  {
/* <<<DD_SLTHA001_API_1_1>>> */
/*  Check free slot is available to open the file. If not then return error. */
    SlotNumber = SLTHA001_lFindAvailableSlot(EMPTY_SLOT);
    if (SlotNumber == MAX_OPEN_FILES)
    {
#if defined(__GNUC__) || defined( __TASKING__)
      errno = ENFILE;
#elif defined __CC_ARM
      errno =  EINVAL;
#elif defined  __ICCARM__
      errno = _LLIO_ERROR;
#endif
      break;
    }/* End of "if (SlotNumber == MAX_OPEN_FILES)"*/
    
    /* Check the file path name should not exceed the maximum value*/
    PathLen = strlen(Path);
    if (PathLen > FILENAME_MAX )
    {
      break;
    }
/* <<<DD_SLTHA001_API_1_2>>> */
/* Check and Set Flags Accordingly */
    Status = SLTHA001_lSetFlagsAccessModes(&Flags,&FatFsFlags);
    if( Status != DAVEApp_SUCCESS)
    {
      FileDesc = -1;
      break;
    } /* End of "if ( Status != DAVEApp_SUCCESS))"*/
    /* Allocate memory to store the file path name.*/
    FileHandle[SlotNumber].FilePath = (char *)malloc(PathLen+1);
    if( FileHandle[SlotNumber].FilePath  == NULL )
    {
      break;
    }
    /* Store the file path name */
    strcpy(FileHandle[SlotNumber].FilePath ,Path);
/* Set File Handle to -1 and error no variable to default EIO */
    FileDesc = -1;
#if defined(__GNUC__) || defined( __TASKING__)
    errno = EIO;
#elif defined __CC_ARM
    errno =  EINVAL;
#elif  __ICCARM__
    errno = _LLIO_ERROR;
#endif
/* <<<DD_SLTHA001_API_1_3>>> */
    /* If File Pointer is NULL, then allocate the memory to open a file  */
    if (FileHandle[SlotNumber].FatFsPtr == NULL)
    {
      FileHandle[SlotNumber].FatFsPtr = (FIL *)calloc(1, sizeof(FIL));
/* <<<DD_SLTHA001_API_1_4>>> */
      if (FileHandle[SlotNumber].FatFsPtr == NULL)
      {
        Status = FILE_WRAPPER_ERROR;
        break;
      } /* End of "if (FileHandle[SlotNumber].FatFsPtr == NULL))"*/
    } /* End of "if (FileHandle[SlotNumber].FatFsPtr == NULL)"*/
/* Call the f_open function */
   Result = f_open(FileHandle[SlotNumber].FatFsPtr,Path,FatFsFlags);
/* <<<DD_SLTHA001_API_1_5>>> */
   if( Result != FR_OK)
   {
     errno = ErrorCodes[ Result];
     break;
   } /* End of "if( Result != FR_OK)"*/
   FileDesc = SlotNumber + MONITOR_FATFS;
   FileHandle[SlotNumber].Fd = FileDesc;
   FileHandle[SlotNumber].Flags = Flags;
   FileHandle[SlotNumber].CurrentPos = 0;
/* <<<DD_SLTHA001_API_1_6>>> */
/* if Append flag set, Get the end position by using FatFS lseek function */
   if (Flags & SLTHA001_APPEND)
   {
#if _FS_MINIMIZE == 3
     Result = FR_DENIED;
#else
     Result = f_lseek( FileHandle[SlotNumber].FatFsPtr, \
                       FileHandle[SlotNumber].FatFsPtr->fsize );
#endif
/* <<<DD_SLTHA001_API_1_7>>> */
     if (Result != FR_OK)
     {
       FileDesc = -1;
       break;
     }/* End of "if( Result != FR_OK)"*/
     FileHandle[SlotNumber].CurrentPos = FileHandle[SlotNumber].FatFsPtr->fptr;
   } /* End of "if(Flags & SLTHA001_APPEND)"*/
 } while(0);
  Status = FileDesc;
/* <<<DD_SLTHA001_API_1_8>>> */
/* Free the memory if File Handle is -1 and Valid FatFsPtr exists */
 if ((FileDesc < 0) &&  FileHandle[SlotNumber].FatFsPtr )
 {
   free (FileHandle[SlotNumber].FilePath);
   free (FileHandle [SlotNumber].FatFsPtr);
   FileHandle[SlotNumber].FilePath = NULL;
   FileHandle [SlotNumber].FatFsPtr = NULL;
 } /* End of "if((FileDesc < 0) &&  FileHandle[SlotNumber].FatFsPtr )"*/
 return Status;
}

/* <<<DD_SLTHA001_API_2>>> */
/*
 * This function closes the file specified by the File descriptor.
 */
#if defined __GNUC__
int _close(int Fd)
#elif defined __CC_ARM
int _sys_close(FILEHANDLE Fd)
#elif defined  __TASKING__
_err_t  _close(_fd_t Fd)
#elif defined  __ICCARM__
int __close(int Fd)
#endif
{
#ifdef  __TASKING__
  _err_t Status = FILE_WRAPPER_ERROR;
#else
  int Status = FILE_WRAPPER_ERROR;
#endif
  int SlotNumber;
  FRESULT Result;
  do
  {
    /* Find the Slot number */
    SlotNumber = SLTHA001_lFindAvailableSlot(Fd);
/* <<<DD_SLTHA001_API_2_1>>> */
    if (SlotNumber == MAX_OPEN_FILES)
    {
#if defined(__GNUC__) || defined( __TASKING__)
      errno = EBADF;
#elif defined __CC_ARM
      errno = EINVAL;
#elif defined  __ICCARM__
      errno = _LLIO_ERROR;
#endif
      break;
    }
 /* Set the handle in the file info structure to -1 */
    FileHandle [SlotNumber].Fd = -1;
/* Check FilePtr is not Null */
/* <<<DD_SLTHA001_API_2_2>>> */
    if (FileHandle [SlotNumber].FatFsPtr != NULL )
    {
      Result = f_close (FileHandle[SlotNumber].FatFsPtr);
      if (Result != FR_OK)
      {
        errno = ErrorCodes[ Result];
        break;
      }
      free (FileHandle[SlotNumber].FilePath);
      free (FileHandle[SlotNumber].FatFsPtr);
      FileHandle [SlotNumber].FatFsPtr = NULL;
/* <<<DD_SLTHA001_API_2_3>>> */
      Status = DAVEApp_SUCCESS;
    }
  } while(0);
  return Status;
}

/* <<<DD_SLTHA001_API_3>>> */
/*
 * This function reads Length bytes of data from the file specified
 */ 
#if defined __GNUC__

//_ssize_t _read_r( struct _reent *r, int file, void *ptr, size_t len )
_ssize_t _read_r
(
  struct _reent *r,
  int Fd,
  void *BufferPtr,
  size_t Length
)
#elif defined __CC_ARM
int _sys_read
(
  FILEHANDLE Fd,
  U8 *BufferPtr,
  U32 Length,
  int mode
)
#elif defined  __TASKING__
int _read
(
  _fd_t Fd,
  void *BufferPtr,
  size_t Length
)
#elif defined __ICCARM__
size_t __read
(
  int Fd,
  unsigned char *BufferPtr,
  size_t Length
)
#endif
{
  int SlotNumber;
  int BytesRead = 0;
  int BytesUnRead = -1;
  FRESULT Result;
  do
  {
#if SLTHA001_ELUA_IN_USE
	   if(Fd == STDIN_HANDLE)
	   {
		   return std_read( r,DM_GET_FD(Fd), BufferPtr, Length );
	   }
#endif
/* Re-map the adjusted File Handle  */
/* Find the Slot number occupied by the file to read from.*/
    SlotNumber = SLTHA001_lFindAvailableSlot(Fd);
/* <<<DD_SLTHA001_API_3_1>>> */
/* Check If write only flag is set  or Max Files are opened.*/
    if ( (SlotNumber == MAX_OPEN_FILES) || 
		     ((FileHandle[SlotNumber].Flags & SLTHA001_WRONLY) != 0UL ))
    {
#if defined(__GNUC__) || defined( __TASKING__)
      errno = EBADF;
#elif defined __CC_ARM
      errno = EINVAL;
#elif defined __ICCARM__
      errno = _LLIO_ERROR;
#endif
      BytesRead = -1;
      break;
    }
/* Switch as per the file descriptor.*/
   switch(Fd)
   {
     case STDIN_HANDLE:
          break;

     case STDOUT_HANDLE:
           break;

     case STDERR_HANDLE:
           break;

     default:
/* <<<DD_SLTHA001_API_3_2>>> */
       if (FileHandle[SlotNumber].FatFsPtr != NULL)
       {
/* Call the Fat FS f_read function */
         Result = f_read(FileHandle [SlotNumber].FatFsPtr, BufferPtr, Length,
                          (UINT *)&BytesRead);
/* <<<DD_SLTHA001_API_3_3>>> */
         if (Result != FR_OK)
         {
           errno = ErrorCodes[ Result];
           BytesRead = -1;
           break;
         }
         BytesUnRead = Length - BytesRead;
       }
       break;
    }
/* <<<DD_SLTHA001_API_3_4>>> */
    if (BytesUnRead < 0)
    {
      BytesRead = -1;
      break;
    }
    FileHandle[SlotNumber].CurrentPos += (Length - BytesUnRead);
  } while(0);
  return BytesRead;
}

/* <<<DD_SLTHA001_API_4>>> */
/*
 * This function writes Length bytes of data into the file specified.
 */
#if defined __GNUC__


_ssize_t _write_r
(
 struct _reent *r,
  int Fd,
  const void *BufferPtr,
  size_t Length
)
#elif defined __CC_ARM
int _sys_write
(
  FILEHANDLE Fd,
  const U8 *BufferPtr,
  U32 Length,
  int Mode
)
#elif defined  __TASKING__
int _write
(
  _fd_t Fd,
  const void *BufferPtr,
  size_t Length
)
#elif defined  __ICCARM__
size_t __write
(
  int Fd,
  const unsigned char * BufferPtr,
  size_t Length
)
#endif
{
  int SlotNumber;
  int BytesWritten = 0;
  int BytesUnWritten = -1;
#if !_FS_READONLY
  FRESULT Result;
#endif
  do
  {
#if SLTHA001_ELUA_IN_USE
	  if(Fd == STDOUT_HANDLE)
	  {
		  return std_write( r,DM_GET_FD(Fd), BufferPtr, Length );
	  }
#endif
/* Find the Slot number occupied by the file to read from.*/
    SlotNumber = SLTHA001_lFindAvailableSlot(Fd);
/* <<<DD_SLTHA001_API_4_1>>> */
/* Check If read only flag is set or Max Files are opened. */
    if ( (SlotNumber == MAX_OPEN_FILES) || 
		   ((FileHandle[SlotNumber].Flags & SLTHA001_RDONLY ) == 1UL ))
    {
#if defined(__GNUC__) || defined( __TASKING__)
      errno = EBADF;
#elif defined  __CC_ARM
      errno = EINVAL;
#elif defined  __ICCARM__
      errno = _LLIO_ERROR;
#endif
      break;
    }
/* Switch as per the file descriptor.*/
    switch(Fd)
    {
      case STDIN_HANDLE:
           break;

      case STDOUT_HANDLE:
           break;

      case STDERR_HANDLE:
           break;

      default:
#if _FS_READONLY   
    break;
#else 
/* <<<DD_SLTHA001_API_4_2>>> */
        if (FileHandle[SlotNumber].FatFsPtr != NULL)
        {
          /* Call the Fat FS f_write function */
          Result = f_write(FileHandle [SlotNumber].FatFsPtr, BufferPtr, Length,
                        (UINT *)&BytesWritten);
/* <<<DD_SLTHA001_API_4_3>>> */
          if (Result != FR_OK)
          {
            errno = ErrorCodes[Result];
            break;
          }
          BytesUnWritten = Length - BytesWritten;
        }
        break;
#endif
    }
  } while(0);
/* <<<DD_SLTHA001_API_4_4>>> */
  if((BytesUnWritten  == -1) || (BytesUnWritten == Length))
  {
    BytesWritten = -1;
  }
/* <<<DD_SLTHA001_API_4_5>>> */
  else
  {
    FileHandle[SlotNumber].CurrentPos += (Length - BytesUnWritten);
  }
  return BytesWritten;
}

/* <<<DD_SLTHA001_API_5>>> */
/*
 * This function Move file pointer of a file object specified by the
 * File Descriptor.
 */
#ifdef __GNUC__
int _lseek
(
  int Fd,
  long Offset,
  int DirMode
)
#elif __CC_ARM
int _sys_seek
(
  FILEHANDLE Fd,
  long Offset
)
#elif  __TASKING__
long _lseek
(
  _fd_t Fd,
  long Offset,
  _whence_t DirMode
)
#elif  __ICCARM__
long __lseek
(
  int Fd,
  long Offset,
  int DirMode
)
#endif
{
  int FileOffset = -1;
#if _FS_MINIMIZE != 3 
  int SlotNumber;
  FRESULT Result;
#endif
  do
  {
#if _FS_MINIMIZE == 3
    break;
#else
    /* Find the Slot number occupied by the file to read from.*/
    SlotNumber = SLTHA001_lFindAvailableSlot(Fd);
/* <<<DD_SLTHA001_API_5_1>>> */
    if ( (SlotNumber == MAX_OPEN_FILES) ||
         (FileHandle[SlotNumber].FatFsPtr == NULL))
    {
#if defined(__GNUC__) || defined( __TASKING__)
      errno = EBADF;
#elif defined __CC_ARM
      errno = EINVAL;
#elif defined  __ICCARM__
      errno = _LLIO_ERROR;
#endif
      break;
    }
#if defined(__GNUC__) || defined( __TASKING__) || defined( __ICCARM__ )
    /* Check Direction Mode */
/* <<<DD_SLTHA001_API_5_2>>> */
    if (DirMode == SEEK_SET)
    {
      Result = f_lseek (FileHandle[SlotNumber].FatFsPtr, Offset);
    }
/* <<<DD_SLTHA001_API_5_3>>> */
    else if (DirMode == SEEK_CUR)
    {
      Result = f_lseek (FileHandle[SlotNumber].FatFsPtr,  \
                     FileHandle [SlotNumber].FatFsPtr->fptr + Offset);
    }
/* <<<DD_SLTHA001_API_5_4>>> */
    else if (DirMode == SEEK_END)
    {
      Result = f_lseek (FileHandle[SlotNumber].FatFsPtr,  \
                        FileHandle [SlotNumber].FatFsPtr->fsize + Offset);
    }
    else
      break;
#elif __CC_ARM
/* <<<DD_SLTHA001_API_5_5>>> */
    Result= f_lseek (FileHandle[SlotNumber].FatFsPtr,Offset);
#endif
    /* If Fat FS Function call returns Error*/
/* <<<DD_SLTHA001_API_5_6>>> */
    if (Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    FileHandle[SlotNumber].CurrentPos = FileHandle [SlotNumber].FatFsPtr->fptr;
    FileOffset = FileHandle[SlotNumber].CurrentPos;
#endif
  } while(0);
  return FileOffset;
}

/* <<<DD_SLTHA001_API_6>>> */
/* 
 * This function Delete an existing file or directory.
 */
#ifdef __GNUC__
int _unlink (const char  *Path)
#elif __CC_ARM
int remove(const char *Path)
#elif  __TASKING__
int remove (const char *Path)
#elif __ICCARM__
int remove(const char * Path)
#endif
{
  int Status = FILE_WRAPPER_ERROR;
#if ((!_FS_READONLY ) && ( _FS_MINIMIZE == 0) ) 
  FRESULT Result;
#endif
  do
  {
#if ((_FS_READONLY) || ( _FS_MINIMIZE != 0))   
    break;
#else  
    /* Call the Fat FS unlink function */
    Result = f_unlink (Path);
/* <<<DD_SLTHA001_API_6_1>>> */
    if( Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    Status = DAVEApp_SUCCESS;
#endif
  } while(0);
  return Status;
}

/* <<<DD_SLTHA001_API_7>>> */
/*
 * This function gets file status on basis of file descriptor passed.
 */

#if defined  (__GNUC__) || defined (  __TASKING__)
#if defined (__GNUC__)
int _fstat(int Fd, struct stat *FileStatusPtr)
#elif  defined (  __TASKING__)
int fstat(int Fd, struct stat *FileStatusPtr)
#endif
{
  int Status = FILE_WRAPPER_ERROR;
#if _FS_MINIMIZE == 0   
  FILINFO FatFsInfoStruct = {0};
  FRESULT Result;
  int SlotNumber;
 
  do
  {

  if( ( Fd >= STDIN_HANDLE ) && ( Fd <= STDERR_HANDLE ) )
	{
	  FileStatusPtr->st_mode = S_IFCHR;
	  return 0;
	}
    /* Find the Slot number occupied by the file to read the status*/
    SlotNumber = SLTHA001_lFindAvailableSlot(Fd);
    /* Call the Fat FS Status function */
    Result = f_stat(FileHandle[SlotNumber].FilePath, &FatFsInfoStruct);
/* <<<DD_SLTHA001_API_7_1>>> */
    if (Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    SLTHA001_lFatInfoToStatus(FileStatusPtr,&FatFsInfoStruct);
    Status = DAVEApp_SUCCESS;
  } while(0);
#endif
  return Status;
}


/* <<<DD_SLTHA001_API_8>>> */
/*
 * This function gets file status on basis of file path 
 */
#if defined (__GNUC__)
int _stat(const char *Path,  struct stat *FileStatusPtr)
#elif  defined (  __TASKING__)
int stat(const char *Path,  struct stat *FileStatusPtr)
#endif
{
  int Status = FILE_WRAPPER_ERROR;
#if _FS_MINIMIZE == 0 
  FILINFO FatFsInfoStruct = {0};
  FRESULT Result;
  do
  {
    /* Call the Fat FS Status function */
    Result = f_stat (Path, &FatFsInfoStruct);
/* <<<DD_SLTHA001_API_8_1>>> */
    if( Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    SLTHA001_lFatInfoToStatus(FileStatusPtr,&FatFsInfoStruct);
    Status = DAVEApp_SUCCESS;
  } while(0);
#endif
  return Status;
}
#endif


/* <<<DD_SLTHA001_API_9>>> */
/*
 * This function rename/move a file or directory.
 */
#if defined (__GNUC__) || defined ( __TASKING__)
int rename( const char *OldPath,  const char *NewPath)
#elif __CC_ARM
int rename(const char *OldPath, const char *NewPath)
#elif  __ICCARM__
int rename(const char *OldPath, const char *NewPath)
#endif
{
#if ((!_FS_READONLY) && ( _FS_MINIMIZE == 0))
  FRESULT Result;
#endif
  int Status = FILE_WRAPPER_ERROR;
  do
  {
#if ((_FS_READONLY) || ( _FS_MINIMIZE != 0))
    break;
#else   
    /* Call the Fat FS Status function */
    Result = f_rename(OldPath, NewPath);
/* <<<DD_SLTHA001_API_9_1>>> */
    if( Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    Status = DAVEApp_SUCCESS;
#endif
  } while(0);
  return Status;
}

/* <<<DD_SLTHA001_API_10>>> */
/*
 * This function change attributes of the file/dir 
 */
#if defined __GNUC__
int _chmod (const char *Path, mode_t Mode)
#elif defined __CC_ARM || defined  __TASKING__ || defined  __ICCARM__
int chmod (const char *Path, mode_t Mode)
#endif
{
#if ((!_FS_READONLY) && ( _FS_MINIMIZE == 0))
  FRESULT Result;
#endif
  int Status = FILE_WRAPPER_ERROR;
  do
  {
#if ((_FS_READONLY) || ( _FS_MINIMIZE != 0))
    break;
#else  
    /* Call the Fat FS Status function */
    Result = f_chmod(Path, Mode, AM_RDO);
/* <<<DD_SLTHA001_API_10_1>>> */
    if( Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    Status = DAVEApp_SUCCESS;
#endif
  } while(0);
  return Status;
}

/* <<<DD_SLTHA001_API_11>>> */
/*
 * This function creates a new directory.
 */
#if defined __GNUC__
int _mkdir (const char *Path, mode_t Mode)
#elif defined __CC_ARM || defined  __TASKING__ || defined  __ICCARM__
int mkdir (const char *Path, mode_t Mode)
#endif
{
#if ((!_FS_READONLY) && ( _FS_MINIMIZE == 0))  
  FRESULT Result;
#endif
  int Status = FILE_WRAPPER_ERROR;
  do
  {
#if ((_FS_READONLY) || ( _FS_MINIMIZE != 0))  
    break;
#else 
    /* Call the Fat FS Mkdir function */
    Result = f_mkdir(Path);
/* <<<DD_SLTHA001_API_11_1>>> */
    if( Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    Status = DAVEApp_SUCCESS;
#endif
  } while(0);
  return Status;
}

/* <<<DD_SLTHA001_API_12>>> */
/*
 *  This function flush cached data of a writing file.
 */
#if defined (__GNUC__) || defined ( __TASKING__)
void  _sync (void)
#elif defined (__CC_ARM) || defined ( __ICCARM__)
void  sync (void)
#endif
{
#if !_FS_READONLY 
  int SlotNumber;
  for( SlotNumber = 0; SlotNumber < MAX_OPEN_FILES; SlotNumber++ )
  {
/* <<<DD_SLTHA001_API_12_1>>> */
    if (FileHandle[SlotNumber].FatFsPtr)
      f_sync (FileHandle[SlotNumber].FatFsPtr);
  }
#endif
}


/* <<<DD_SLTHA001_API_13>>> */
/*
 * This function creates the file system on the drive.
 */
int mkfs( uint8_t DriveNumber, uint8_t PartitioningRule,uint32_t AllocSize)
{
  int Status = FILE_WRAPPER_ERROR;
#if _USE_MKFS
  FRESULT Result;
  do
  {
    Result = f_mkfs(DriveNumber,PartitioningRule,AllocSize);
/* <<<DD_SLTHA001_API_13_1>>> */
    if(Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    Status = DAVEApp_SUCCESS;
  }while(0);
#endif
  return Status;
}


/* <<<DD_SLTHA001_API_14>>> */
/*
 * This function registers/unregisters a work area.
 */
int mount( uint8_t DriveNumber, FATFS *FatFSObj)
{
  FRESULT Result;
  int Status = FILE_WRAPPER_ERROR;
  do
  {
    Result = f_mount(DriveNumber,FatFSObj);
/* <<<DD_SLTHA001_API_14_1>>> */
    if(Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    Status = DAVEApp_SUCCESS;
  }while(0);
  return  Status;
}

/*
 * This function querries whether output stream is a terminal. 
 */
 /* <<<DD_SLTHA001_API_15>>> */

#if defined(__GNUC__)  || defined (__CC_ARM)
#if defined(__GNUC__)
int _isatty(int Fd)
#elif defined (__CC_ARM)
int _sys_istty(FILEHANDLE Fd)
#endif
{
  return (Fd <= 2) ? 1 : 0;  /* one of stdin, stdout, stderr */
}
#endif


/*
 *  Function to Initialize all the local variables of Standard Librarry App 
 */
/* <<<DD_SLTHA001_API_16>>> */
void SLTHA001_Init()
{
   SLTHA001_lLocalInitialize();
}


#if defined(__GNUC__)
/* This function establish a new name for an existing file. This function is
 * not supported by Fat File system.
 */
/* <<<DD_SLTHA001_API_17>>> */
int _link (char *OldName, char *NewName)
{
  errno = EMLINK;
  return -1;
}
#endif

/* This function creates a partition table into the MBR of the physical drive.
 */
/* <<<DD_SLTHA001_API_18>>> */
int fdisk( uint8_t DriveNumber, const uint32_t Partitions[], void * Work)
{
  int Status = FILE_WRAPPER_ERROR;
#if _MULTI_PARTITION
  FRESULT Result;
  do
  {
    Result = f_fdisk(DriveNumber,Partitions, Work);
/* <<<DD_SLTHA001_API_18_1>>> */
    if(Result != FR_OK)
    {
      errno = ErrorCodes[Result];
      break;
    }
    Status = DAVEApp_SUCCESS;
  } while(0);
#endif
  return  Status;
}

/* 
 * IAR internally calls __dwrite for write system call .
 */
#if defined ( __ICCARM__)
size_t __dwrite(int Fd,const unsigned char *BufferPtr, size_t Length)
{
  return  __write(Fd,BufferPtr,Length);
}
#endif

/*
 * Keil compiler searches for the following system calls while retargetting is 
 * done.
 */
#if defined (__CC_ARM)
void _ttywrch (int ch) {

}

int _sys_ensure (FILEHANDLE Fh) {
    Fh = Fh;
    return (0);
}

long _sys_flen (FILEHANDLE Fh) {
    Fh = Fh;
    return (0);
}

int _sys_tmpnam (char *Name, int Sig, unsigned Maxlen)
{
  *Name = *Name;
  Sig = Sig;
  Maxlen = Maxlen;
  return (0);
}

char *_sys_command_string (char *Cmd, int Len)
{
  *Cmd = *Cmd;
  Len = Len;
  return (0);
}

void _sys_exit (int return_code)
{
  /* Endless loop. */
  while (1);
}

#endif

#ifdef SLTHA001_ELUA_IN_USE
/* System calls used in Elua implementation */
pid_t _getpid()
{
  return 0;
}

void _exit( int Status )
{
  while( 1 );
}

int _kill( int Pid, int Sig )
{
  return -1;
}

_fini()
{

}

/* This function allows eLua to list all the files in the file systems used by eLua
 */
void* fatfs_opendir_r( struct _reent *r, const char* DirName )
{
  void *ResPtr = NULL;
  if( (!DirName)  || (strlen( DirName ) == 0 ) || \
      (strlen( DirName ) == 1 && !strcmp( DirName, "/" ) ) 
    )
  {
    ResPtr = f_opendir( &SLTHA001_MmcDir, "/" ) != FR_OK ? NULL : &SLTHA001_MmcDir;
  }
  return ResPtr;
}
/* This function allows eLua to print the content of (usually text) files on the console.
 */
struct dm_dirent* fatfs_readdir_r( struct _reent *r, void *d )
{
  DIR *pdir = (DIR*)d;
  FILINFO mmc_file_info;
  struct dm_dirent* pent = &dm_shared_dirent;
  char *fn;
#if _USE_LFN
  static char lfn[_MAX_LFN * (_DF1S ? 2 : 1) + 1];
  mmc_file_info.lfname = lfn;
  mmc_file_info.lfsize = sizeof(lfn);
#endif
/* loop until we get a file, error, or end of directory */
  while( 1 ) 
  {
    /* return NULL on read error if read dir fails */
    if( f_readdir( pdir, &mmc_file_info ) != FR_OK ) 
      return NULL;
    /* return NULL when listing is done */  
    if( mmc_file_info.fname[ 0 ] == '\0' ) 
      return NULL;
    /* if we have a file, exit loop */
    if( ( mmc_file_info.fattrib & AM_DIR ) == 0 ) 
      break;
  }
#if _USE_LFN
  fn = *mmc_file_info.lfname ? mmc_file_info.lfname : mmc_file_info.fname;
#else
  fn = mmc_file_info.fname;
#endif
  strncpy( dm_shared_fname, fn, DM_MAX_FNAME_LENGTH );
  pent->fname = dm_shared_fname;
  pent->fsize = mmc_file_info.fsize;
  pent->ftime = mmc_file_info.ftime;
  return pent;
}

/* This function closes the files in the filesystem used by elua. */
int fatfs_closedir_r( struct _reent *r, void *d )
{
  return 0;
}
#endif



/*CODE_BLOCK_END*/



