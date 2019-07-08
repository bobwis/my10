package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class sltha001h_template
{
  protected static String nl;
  public static synchronized sltha001h_template create(String lineSeparator)
  {
    nl = lineSeparator;
    sltha001h_template result = new sltha001h_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + NL + "/*CODE_BLOCK_BEGIN[SLTHA001.h]*/" + NL + "" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers.This file can be freely distributed within development" + NL + " * tools that are supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR" + NL + " * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : July 31, 2012                                          **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL;
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + "/**" + NL + " * @file ";
  protected final String TEXT_4 = ".h" + NL + " *" + NL + " * @brief This file contains all the public and private function type declarations" + NL + " * of Standard Lib App." + NL + " *" + NL + " */" + NL + "" + NL + "#ifndef ";
  protected final String TEXT_5 = "_H_" + NL + "#define ";
  protected final String TEXT_6 = "_H_" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Include Files                                         **" + NL + "*******************************************************************************/" + NL + "#include \"../../inc/FATFS002/FATFS002.h\"" + NL + "#include <DAVE3.h>" + NL + "#include <stdio.h>" + NL + "#include <stdlib.h>" + NL + "#include <string.h>" + NL + "#include <errno.h>" + NL + "" + NL + "#if defined (__GNUC__) || defined (__TASKING__)" + NL + "  #include <fcntl.h>" + NL + "  #include <unistd.h>" + NL + "#endif" + NL + "" + NL + "#ifdef __GNUC__" + NL + "  #include <reent.h>" + NL + "#elif __CC_ARM" + NL + "  #include <rt_sys.h>" + NL + "  #include <RTL.h>" + NL + "#elif __ICCARM__" + NL + " #include <yfuns.h>" + NL + "#elif __TASKING__" + NL + " #include <io.h>" + NL + "#endif" + NL + "" + NL + "" + NL + "/**" + NL + " * @ingroup ";
  protected final String TEXT_7 = "_publicparam" + NL + " * @{" + NL + " */" + NL + "/*******************************************************************************" + NL + "**                      Global Macro Definitions                              **" + NL + "*******************************************************************************/" + NL + "/* File creation Flags */" + NL + "#if defined(__GNUC__) || defined(__TASKING__)" + NL + "  #define       ";
  protected final String TEXT_8 = "_RDONLY       O_RDONLY" + NL + "  #define       ";
  protected final String TEXT_9 = "_WRONLY       O_WRONLY" + NL + "  #define       ";
  protected final String TEXT_10 = "_RDWR         O_RDWR" + NL + "  #define       ";
  protected final String TEXT_11 = "_APPEND       O_APPEND" + NL + "  #define       ";
  protected final String TEXT_12 = "_CREAT        O_CREAT" + NL + "  #define       ";
  protected final String TEXT_13 = "_TRUNC        O_TRUNC" + NL + "  #define       ";
  protected final String TEXT_14 = "_EXCL         O_EXCL" + NL + "  #define       ";
  protected final String TEXT_15 = "_SYNC         O_SYNC" + NL + "  #define       ";
  protected final String TEXT_16 = "_NONBLOCK     O_NONBLOCK" + NL + "  #define       ";
  protected final String TEXT_17 = "_NOCTTY       O_NOCTTY" + NL + "  #define       ";
  protected final String TEXT_18 = "_RDWRMASK     O_ACCMODE" + NL + "" + NL + "#elif defined __CC_ARM" + NL + "  #define       ";
  protected final String TEXT_19 = "_RDONLY       OPEN_R" + NL + "  #define       ";
  protected final String TEXT_20 = "_WRONLY       OPEN_W" + NL + "  #define       ";
  protected final String TEXT_21 = "_RDWR         OPEN_PLUS" + NL + "  #define       ";
  protected final String TEXT_22 = "_APPEND       OPEN_A" + NL + "" + NL + "#elif defined __ICCARM__" + NL + "  #define       ";
  protected final String TEXT_23 = "_RDONLY       _LLIO_RDONLY" + NL + "  #define       ";
  protected final String TEXT_24 = "_WRONLY       _LLIO_WRONLY" + NL + "  #define       ";
  protected final String TEXT_25 = "_RDWR         _LLIO_RDWR" + NL + "  #define       ";
  protected final String TEXT_26 = "_APPEND       _LLIO_APPEND" + NL + "  #define       ";
  protected final String TEXT_27 = "_CREAT        _LLIO_CREAT" + NL + "  #define       ";
  protected final String TEXT_28 = "_TRUNC        _LLIO_TRUNC" + NL + "  #define       ";
  protected final String TEXT_29 = "_EXCL         _LLIO_EXCL" + NL + "  #define       ";
  protected final String TEXT_30 = "_RDWRMASK     _LLIO_RDWRMASK" + NL + "#endif" + NL + "" + NL + "" + NL + "/** Standard Input File Descriptor */" + NL + "#define STDIN_HANDLE                                      0" + NL + "/** Standard Output File Descriptor */" + NL + "#define STDOUT_HANDLE                                     1" + NL + "/** Standard Error File Descriptor */" + NL + "#define STDERR_HANDLE                                     2" + NL + "" + NL + "#ifdef __GNUC__" + NL + "/** Maximum Number of Files that can be opened.*/" + NL + "  #define MAX_OPEN_FILES                                    FOPEN_MAX" + NL + "#elif __CC_ARM" + NL + "  #define MAX_OPEN_FILES                                    _SYS_OPEN" + NL + "#elif __ICCARM__" + NL + "  #define MAX_OPEN_FILES                                    FOPEN_MAX" + NL + "#elif __TASKING__" + NL + "  #define MAX_OPEN_FILES \t\t\t\t\t\t\t\t    FOPEN_MAX" + NL + "#endif" + NL + "" + NL + "" + NL + "/** Empty Slot Value */" + NL + "#define EMPTY_SLOT                                         (-1)" + NL + "/**Fat Fs Handle  Value adjusted to stay away from Internal Handles. */" + NL + "#define MONITOR_FATFS                                      (3)" + NL + "/** File System Wrapper Error */" + NL + "#define FILE_WRAPPER_ERROR                                 (-1)   " + NL + "" + NL + "#if defined (__CC_ARM) || (__ICCARM__)" + NL + "typedef short  mode_t   ;" + NL + "#elif defined (__TASKING__)" + NL + "typedef unsigned char  mode_t;" + NL + "#endif" + NL + "" + NL + "#ifdef __CC_ARM" + NL + "#pragma import(__use_no_semihosting_swi)" + NL + "/* The following macro definitions may be used to translate this file:" + NL + "   STDIO - use standard Input/Output device default is NOT used) */" + NL + "/** Standard IO device handles. */" + NL + "#define STDIN   0x8001" + NL + "#define STDOUT  0x8002" + NL + "#define STDERR  0x8003" + NL + "" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "/**" + NL + " * @cond INTERNAL_DOCS" + NL + " */" + NL + "" + NL + "/**" + NL + " * @ingroup ";
  protected final String TEXT_31 = "_privateparam" + NL + " * @{" + NL + " */" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Structures                                            **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * Structure containing all the file details." + NL + " */" + NL + "typedef struct ";
  protected final String TEXT_32 = "_FileHandleStruct" + NL + "{" + NL + "  int Fd;" + NL + "  int CurrentPos;" + NL + "  int Flags;" + NL + "  FIL *FatFsPtr;" + NL + "  char *FilePath;" + NL + "} ";
  protected final String TEXT_33 = "_FileHandleStruct;" + NL + "" + NL + "" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "/**" + NL + " * @endcond" + NL + " */" + NL + "" + NL + "/**" + NL + " * @ingroup ";
  protected final String TEXT_34 = "_apidoc" + NL + " * @{" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + " ** FUNCTION PROTOTYPES                                                       **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @brief  This function opens the file specified by the Path in the mode " + NL + " * specified by the Flags." + NL + " * @param[in] Path File name or File Path." + NL + " * @param[in] Flags Modes in which to open a file." + NL + " * @return  int" + NL + " * File Descriptor: If Successful<BR> " + NL + " * -1: If file open fails.<BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#ifdef __GNUC__" + NL + "int _open(const TCHAR *Path, int Flags,...);" + NL + "#elif __CC_ARM" + NL + "FILEHANDLE _sys_open" + NL + "(" + NL + "  const char  *Path," + NL + "  int Flags" + NL + ");" + NL + "#elif __TASKING__" + NL + "_err_t _open" + NL + "(" + NL + "  const char *Path," + NL + "  _open_flags_t Flags" + NL + ");" + NL + "#elif __ICCARM__" + NL + "int __open" + NL + "(" + NL + "  const char * Path," + NL + "  int Flags" + NL + ");" + NL + "#endif" + NL + "/**" + NL + " * @brief  This function closes the file specified by the File descriptor." + NL + " * @param[in] Fd File Descriptor" + NL + " * @return int <BR>" + NL + " * DAVEApp_SUCCESS: if successful.<BR> " + NL + " * FILE_WRAPPER_ERROR: If function fails.<BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#ifdef __GNUC__" + NL + "  int _close(int Fd);" + NL + "#elif __CC_ARM" + NL + "  int _sys_close(FILEHANDLE Fd);" + NL + "#elif __TASKING__" + NL + "  _err_t  _close(_fd_t Fd);" + NL + "#elif __ICCARM__" + NL + "  int __close(int Fd);" + NL + "#endif" + NL + "/**" + NL + " * @brief  This function reads Length bytes of data from the file specified" + NL + " * by the File descriptor." + NL + " * @param[in] r Re-entrancy pointer" + NL + " * @param[in] Fd File Descriptor" + NL + " * @param[in] BufferPtr Buffer to write data into." + NL + " * @param[in] Length No of Bytes of Data to read." + NL + " * @return  int <BR>" + NL + " * No of Bytes read: If successful.<BR> " + NL + " * FILE_WRAPPER_ERROR(-1): If error.<BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#ifdef __GNUC__" + NL + "_ssize_t _read_r" + NL + "(" + NL + "  struct _reent *r," + NL + "  int Fd," + NL + "  void *BufferPtr," + NL + "  size_t Length" + NL + ");" + NL + "#elif __CC_ARM" + NL + "int _sys_read" + NL + "(" + NL + "  FILEHANDLE Fd," + NL + "  U8 *BufferPtr," + NL + "  U32 Length," + NL + "  int mode" + NL + ");" + NL + "#elif __TASKING__" + NL + "int _read" + NL + "(" + NL + "  _fd_t Fd," + NL + "  void *BufferPtr," + NL + "  size_t Length" + NL + ");" + NL + "#elif __ICCARM__" + NL + "size_t __read" + NL + "(" + NL + "  int handle," + NL + "  unsigned char *BufferPtr," + NL + "  size_t Length" + NL + ");" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function writes Length bytes of data into the file specified" + NL + " * by the File descriptor." + NL + " * @param[in] r Re-entrancy pointer" + NL + " * @param[in] Fd File Descriptor" + NL + " * @param[in] BufferPtr Buffer from where to take data to write." + NL + " * @param[in] Length No of Bytes of Data to Write." + NL + " * @return int <BR>" + NL + " * No of Bytes written if successful.<BR>" + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#ifdef __GNUC__" + NL + "_ssize_t _write_r" + NL + "(" + NL + " struct _reent *r," + NL + "  int Fd," + NL + "  const void *BufferPtr," + NL + "  size_t Length" + NL + ");" + NL + "#elif __CC_ARM" + NL + "int _sys_write" + NL + "(" + NL + "  FILEHANDLE Fd," + NL + "  const U8 *BufferPtr," + NL + "  U32 Length," + NL + "  int Mode" + NL + ");" + NL + "#elif __TASKING__" + NL + "int _write" + NL + "(" + NL + "  _fd_t Fd," + NL + "  const void *BufferPtr," + NL + "  size_t Length" + NL + ");" + NL + "#elif __ICCARM__" + NL + "size_t __write" + NL + "(" + NL + "  int Fd," + NL + "  const unsigned char * BufferPtr," + NL + "  size_t Length" + NL + ");" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function Move file pointer of a file object specified by the" + NL + " * File Descriptor." + NL + " * @param[in] Fd File Descriptor" + NL + " * @param[in] Offset The value of offset determines the new position." + NL + " * @param[in] DirMode  " + NL + " * SEEK_SET: Offset from the beginning of the file desired." + NL + " * SEEK_CUR: Offset is relative to the current file position. " + NL + " * EEK_END: Offset is relative to the current end of file. " + NL + " * @return  int <BR>" + NL + " * Current File Pointer Position:  If Success.<BR>  " + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR> " + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#ifdef __GNUC__" + NL + "int _lseek" + NL + "(" + NL + "  int Fd," + NL + "  long Offset," + NL + "  int DirMode" + NL + ");" + NL + "#elif __CC_ARM" + NL + "int _sys_seek" + NL + "(" + NL + "  FILEHANDLE Fd," + NL + "  long Offset" + NL + ");" + NL + "#elif __TASKING__" + NL + "long  _lseek" + NL + "(" + NL + "  _fd_t Fd," + NL + "  long Offset," + NL + "  _whence_t DirMode" + NL + ");" + NL + "#elif __ICCARM__" + NL + "long __lseek" + NL + "(" + NL + "  int Fd," + NL + "  long Offset," + NL + "  int DirMode" + NL + ");" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function Delete an existing file or directory." + NL + " * @param[in] Path File name or File Path." + NL + " * @return int  " + NL + " * FR_OK: If Successful <BR>" + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#ifdef __GNUC__" + NL + "  int _unlink (const char  *Path);" + NL + "#elif __CC_ARM" + NL + "  int remove(const char *Path);" + NL + "#elif __TASKING__" + NL + "  int _unlink (const char *Path);" + NL + "#elif __ICCARM__" + NL + "  int remove(const char * Path);" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function gets file status on basis of file descriptor passed." + NL + " * @param[in] Fd File Descriptor." + NL + " * @param[out] FileStatusPtr: Stat Structure to return Status into. " + NL + " * @return  int <BR>" + NL + " * FR_OK: if Successful <BR>" + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#if defined __GNUC__ || defined __TASKING__" + NL + "int _fstat(int Fd, struct stat *FileStatusPtr);" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function gets file status on basis of file path " + NL + " * @param[in] Path File name or File Path." + NL + " * @param[out] FileStatusPtr Stat Structure to return Status into. " + NL + " * @return int <BR>" + NL + " * FR_OK if Successful else Error." + NL + " */" + NL + "#if defined __GNUC__ || defined __TASKING__" + NL + "int _stat(const char *Path,  struct stat *FileStatusPtr);" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function rename/move a file or directory " + NL + " * @param[in] OldPath Old File name or File Path." + NL + " * @param[in] NewPath New File Name or File Path." + NL + " * @return int <BR>" + NL + " * FR_OK: if Successfull.<BR>" + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#if defined __GNUC__ || defined __TASKING__" + NL + "  int _rename( const char *OldPath,  const char *NewPath);" + NL + "#elif __CC_ARM" + NL + "  int rename(const char *OldPath, const char *NewPath);" + NL + "#elif __ICCARM__" + NL + "  int rename(const char *OldPath, const char *NewPath);" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function change attributes of the file/dir " + NL + " * @param[in] Path File name or File Path." + NL + " * @param[in] Mode Attribute bits" + NL + " * @return  int <BR>" + NL + " * FR_OK: if Successful <BR>" + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#if defined __GNUC__" + NL + "int _chmod (const char *Path, mode_t Mode);" + NL + "#elif defined __CC_ARM || defined __ICCARM__ || defined __TASKING__" + NL + "int chmod (const char *Path, mode_t Mode);" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function creates a new directory" + NL + " * @param[in] Path File name or File Path." + NL + " * @param[in] Mode Attribute bits" + NL + " * @return  int <BR>" + NL + " * FR_OK: if Successful <BR>" + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#if defined __GNUC__" + NL + "int _mkdir (const char *Path, mode_t Mode);" + NL + "#elif defined __CC_ARM || defined __ICCARM__ || defined __TASKING__" + NL + "int mkdir (const char *Path, mode_t Mode);" + NL + "#endif" + NL + "" + NL + "/**" + NL + " * @brief  This function flush cached data of a writing file" + NL + " * @return void<BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#if defined __GNUC__" + NL + "void  _sync (void);" + NL + "#elif defined __CC_ARM || defined __ICCARM__ || defined __TASKING__" + NL + "void  sync (void);" + NL + "#endif" + NL + "" + NL + "" + NL + "" + NL + "#if _USE_MKFS" + NL + "/**" + NL + " * @brief  This function creates the file system on the drive.This should be " + NL + " * used only when USE_MKFS option is seleted from FATFS GUI." + NL + " * @param[in] DriveNumber Logical drive number (0-9) to be formatted. " + NL + " * @param[in] PartitioningRule Specifies partitioning rule, FDISK(0) or SFD(1). " + NL + " * This argument is ignored on some case. " + NL + " * @param[in] AllocSize Force the allocation unit (cluter) size in unit of byte." + NL + " * @return  int" + NL + " * FR_OK: if Successful <BR>" + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + " " + NL + "int mkfs( uint8_t DriveNumber, uint8_t PartitioningRule,uint32_t AllocSize);" + NL + "#endif" + NL + "/**" + NL + " * @brief This function registers/unregisters a work area." + NL + " * @param[in] DriveNumber Logical drive number (0-9) to register/unregister the work area." + NL + " * @param[in] FatFSObj Pointer to the work area (file system object) to be registered. " + NL + " * @return : int" + NL + " * FR_OK: if Successful <BR>" + NL + " * FILE_WRAPPER_ERROR(-1) : If function fails. <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "int mount( uint8_t DriveNumber, FATFS *FatFSObj);" + NL + "" + NL + "" + NL + "/**" + NL + " * @brief  This function querries whether output stream is a terminal. " + NL + " * @param[in] Fd File Descriptor " + NL + " * @return : int<BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "#if defined(__GNUC__)  || defined (__CC_ARM)" + NL + "#if defined(__GNUC__)" + NL + "int _isatty(int Fd);" + NL + "#elif defined (__CC_ARM)" + NL + "int _sys_istty(FILEHANDLE Fd);" + NL + "#endif" + NL + "#endif" + NL + "" + NL + "" + NL + "" + NL + "/**" + NL + " * @brief  This function initializes all the local variables of Standard Library App." + NL + " * It should be called first inorder to use SLTHA001 App " + NL + " * @return : void<BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "void ";
  protected final String TEXT_35 = "_Init(void);" + NL + "" + NL + "" + NL + "#if defined(__GNUC__)" + NL + "" + NL + "/**" + NL + " * @brief This function establish a new name for an existing file. This " + NL + " * function is not supported by Fat File system." + NL + " * @param[in] OldName Old file name" + NL + " * @param[in] NewName New file name  " + NL + " * @return : void <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "int _link (char *OldName, char *NewName);" + NL + "" + NL + "#endif" + NL + "/**" + NL + " * @brief This function creates a partition table into the physical drive(Master Boot Recorder-MBR).<BR>" + NL + " * 1. The partitioning rule is in generic FDISK format hence it can create only upto" + NL + " * four primary partitions.<BR>" + NL + " * 2. Extended partition is not supported. <BR>" + NL + " * 3. The Partitions[] specifies how to divide the physical drive.The first item " + NL + " *    specifies the size of first primary partition and fourth item specifies the " + NL + " *    fourth primary partition. there are 2 methods to define partitions.<BR>" + NL + " *    Method 1: % based. If the value is less than or equal to 100, " + NL + " *    it means percentage of the partition in the entire disk space. <BR>" + NL + " *    Method 2: Sector Based.If it is larger than 100, it means partition size in unit of sector.<BR>" + NL + " * Eg: To create 4 partitions of equal size where physical drive has 10,000 sectors." + NL + " *    <BR>Method 1: Partitions[] = {25,25,25,25};" + NL + " *    <BR>Method 1: Partitions[] = {2500,2500,2500,2500};<BR>" + NL + " *  Apart from these, User also needs to define Logical to Physical drive mapping." + NL + " *  For this, an array  VolToPart[] needs to be defined as:<BR>" + NL + " *  PARTITION VolToPart[] = { <BR>" + NL + " *            {0, 1},   // Logical drive 0 ==> Physical drive 0(SDMMC), 1st partition  <BR> " + NL + " *            {0, 2},   // Logical drive 1 ==> Physical drive 0(SDMMC), 2nd partition  <BR> " + NL + " *            {1, 0}    // Logical drive 2 ==> Physical drive 1(USB), auto detection  <BR>" + NL + " *            } <BR>" + NL + " * NOTE: The Partitions created is not visible in Windows. Linux supports the visibility of the partitions" + NL + " * created by this function." + NL + " * @param[in] DriveNumber Specifies the physical drive to be divided. " + NL + " * @param[in] Partitions Partition map table. It must have four items." + NL + " * @param[in] Work Pointer to the function work area. The size must be at least" + NL + " * FatFs GUI configuration  _MAX_SS bytes. <BR>" + NL + " * @return: int<BR>" + NL + " * FILE_WRAPPER_ERROR: If function fails." + NL + " * DAVEApp_SUCCESS: If function succeeds." + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "int fdisk( uint8_t DriveNumber, const uint32_t Partitions[], void * Work);" + NL + "" + NL + "#if defined ( __ICCARM__)" + NL + "size_t __dwrite(int Fd,const unsigned char *BufferPtr, size_t Length);" + NL + "#endif" + NL + "" + NL + "" + NL + "#ifdef ";
  protected final String TEXT_36 = "_ELUA_IN_USE" + NL + "pid_t _getpid(void);" + NL + "" + NL + "void _exit( int Status );" + NL + "" + NL + "int _kill( int Pid, int Sig );" + NL + "" + NL + "void* fatfs_opendir_r( struct _reent *r, const char* DirName );" + NL + "" + NL + "struct dm_dirent* fatfs_readdir_r( struct _reent *r, void *d );" + NL + "" + NL + "int fatfs_closedir_r( struct _reent *r, void *d );" + NL + "" + NL + "#endif" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "" + NL + "#endif /* ";
  protected final String TEXT_37 = "_H_ */" + NL + "" + NL + "/*CODE_BLOCK_END*/" + NL + NL;
  protected final String TEXT_38 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/sltha001/"; 
     int appInst = 0; 
     int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/sltha001_rtos_present");
   String  Module_Name = "SLTHA001";

    stringBuffer.append(TEXT_2);
     
  if (RTOS == 1)
  {
    Module_Name = "SLTHA002";
  }
  else
  {
    Module_Name = "SLTHA001";
  }

    stringBuffer.append(TEXT_3);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_4);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_6);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_7);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_8);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_9);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_10);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_11);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_12);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_13);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_14);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_15);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_16);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_17);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_18);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_19);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_20);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_21);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_22);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_23);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_24);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_25);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_26);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_27);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_28);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_29);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_30);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_31);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_32);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_33);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_34);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_35);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_36);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_37);
    stringBuffer.append(TEXT_38);
    return stringBuffer.toString();
  }
}
