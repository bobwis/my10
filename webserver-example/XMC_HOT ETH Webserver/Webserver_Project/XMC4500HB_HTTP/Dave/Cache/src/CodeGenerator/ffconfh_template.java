package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class ffconfh_template
{
  protected static String nl;
  public static synchronized ffconfh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    ffconfh_template result = new ffconfh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[ffconf.h]*/" + NL + "/*---------------------------------------------------------------------------/" + NL + "/  FatFs - FAT file system module configuration file  R0.09  (C)ChaN, 2011" + NL + "/----------------------------------------------------------------------------/" + NL + "/" + NL + "/ CAUTION! Do not forget to make clean the project after any changes to" + NL + "/ the configuration options." + NL + "/" + NL + "*/" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers. " + NL + " * This file can be freely distributed within development" + NL + " * tools that are supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR" + NL + " * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : July 31, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL + "" + NL + "#ifndef _FFCONF" + NL + "#define _FFCONF 6502\t/* Revision ID */" + NL + NL + NL;
  protected final String TEXT_2 = NL + NL + "/*---------------------------------------------------------------------------/" + NL + "/ Functions and Buffer Configurations" + NL + "/----------------------------------------------------------------------------*/" + NL + "" + NL + "#define\t_FS_TINY\t\t";
  protected final String TEXT_3 = "\t/* 0:Normal or 1:Tiny */" + NL + "/* When _FS_TINY is set to 1, FatFs uses the sector buffer in the file system" + NL + "/  object instead of the sector buffer in the individual file object for file" + NL + "/  data transfer. This reduces memory consumption 512 bytes each file object. */" + NL + "" + NL + "" + NL + "#define _FS_READONLY\t";
  protected final String TEXT_4 = "\t/* 0:Read/Write or 1:Read only */" + NL + "/* Setting _FS_READONLY to 1 defines read only configuration. This removes" + NL + "/  writing functions, f_write, f_sync, f_unlink, f_mkdir, f_chmod, f_rename," + NL + "/  f_truncate and useless f_getfree. */" + NL + "" + NL + "" + NL + "#define _FS_MINIMIZE\t";
  protected final String TEXT_5 = "\t/* 0 to 3 */" + NL + "/* The _FS_MINIMIZE option defines minimization level to remove some functions." + NL + "/" + NL + "/   0: Full function." + NL + "/   1: f_stat, f_getfree, f_unlink, f_mkdir, f_chmod, f_truncate and f_rename" + NL + "/      are removed." + NL + "/   2: f_opendir and f_readdir are removed in addition to 1." + NL + "/   3: f_lseek is removed in addition to 2. */" + NL + "" + NL + "" + NL + "#define\t_USE_STRFUNC\t";
  protected final String TEXT_6 = "\t/* 0:Disable or 1-2:Enable */" + NL + "/* To enable string functions, set _USE_STRFUNC to 1 or 2. */" + NL + "" + NL + "" + NL + "#define\t_USE_MKFS\t";
  protected final String TEXT_7 = "\t\t/* 0:Disable or 1:Enable */" + NL + "/* To enable f_mkfs function, set _USE_MKFS to 1 and set _FS_READONLY to 0 */" + NL + "" + NL + "" + NL + "#define\t_USE_FORWARD\t";
  protected final String TEXT_8 = "\t/* 0:Disable or 1:Enable */" + NL + "/* To enable f_forward function, set _USE_FORWARD to 1 and set _FS_TINY to 1. */" + NL + "" + NL + "" + NL + "#define\t_USE_FASTSEEK\t";
  protected final String TEXT_9 = "\t/* 0:Disable or 1:Enable */" + NL + "/* To enable fast seek feature, set _USE_FASTSEEK to 1. */" + NL + "" + NL + "" + NL + "/*---------------------------------------------------------------------------/" + NL + "/ Locale and Namespace Configurations" + NL + "/----------------------------------------------------------------------------*/" + NL + "" + NL + "#define _CODE_PAGE\t";
  protected final String TEXT_10 = NL + "/* The _CODE_PAGE specifies the OEM code page to be used on the target system." + NL + "/  Incorrect setting of the code page can cause a file open failure." + NL + "/" + NL + "/   932  - Japanese Shift-JIS (DBCS, OEM, Windows)" + NL + "/   936  - Simplified Chinese GBK (DBCS, OEM, Windows)" + NL + "/   949  - Korean (DBCS, OEM, Windows)" + NL + "/   950  - Traditional Chinese Big5 (DBCS, OEM, Windows)" + NL + "/   1250 - Central Europe (Windows)" + NL + "/   1251 - Cyrillic (Windows)" + NL + "/   1252 - Latin 1 (Windows)" + NL + "/   1253 - Greek (Windows)" + NL + "/   1254 - Turkish (Windows)" + NL + "/   1255 - Hebrew (Windows)" + NL + "/   1256 - Arabic (Windows)" + NL + "/   1257 - Baltic (Windows)" + NL + "/   1258 - Vietnam (OEM, Windows)" + NL + "/   437  - U.S. (OEM)" + NL + "/   720  - Arabic (OEM)" + NL + "/   737  - Greek (OEM)" + NL + "/   775  - Baltic (OEM)" + NL + "/   850  - Multilingual Latin 1 (OEM)" + NL + "/   858  - Multilingual Latin 1 + Euro (OEM)" + NL + "/   852  - Latin 2 (OEM)" + NL + "/   855  - Cyrillic (OEM)" + NL + "/   866  - Russian (OEM)" + NL + "/   857  - Turkish (OEM)" + NL + "/   862  - Hebrew (OEM)" + NL + "/   874  - Thai (OEM, Windows)" + NL + "/\t1    - ASCII only (Valid for non LFN cfg.)" + NL + "*/" + NL + "" + NL + "" + NL + "#define\t_USE_LFN\t0\t\t\t\t\t\t/* 0 to 3 */" + NL + "#define\t_MAX_LFN\t";
  protected final String TEXT_11 = "\t\t/* Maximum LFN length to handle (12 to 255) */" + NL + "/* The _USE_LFN option switches the LFN support." + NL + "/" + NL + "/   0: Disable LFN feature. _MAX_LFN and _LFN_UNICODE have no effect." + NL + "/   1: Enable LFN with static working buffer on the BSS. Always NOT reentrant." + NL + "/   2: Enable LFN with dynamic working buffer on the STACK." + NL + "/   3: Enable LFN with dynamic working buffer on the HEAP." + NL + "/" + NL + "/  The LFN working buffer occupies (_MAX_LFN + 1) * 2 bytes. To enable LFN," + NL + "/  Unicode handling functions ff_convert() and ff_wtoupper() must be added" + NL + "/  to the project. When enable to use heap, memory control functions" + NL + "/  ff_memalloc() and ff_memfree() must be added to the project. */" + NL + "" + NL + "" + NL + "#define\t_LFN_UNICODE\t";
  protected final String TEXT_12 = "\t/* 0:ANSI/OEM or 1:Unicode */" + NL + "/* To switch the character code set on FatFs API to Unicode," + NL + "/  enable LFN feature and set _LFN_UNICODE to 1. */" + NL + "" + NL + "" + NL + "#define _FS_RPATH\t\t";
  protected final String TEXT_13 = "\t\t/* 0 to 2 */" + NL + "/* The _FS_RPATH option configures relative path feature." + NL + "/" + NL + "/   0: Disable relative path feature and remove related functions." + NL + "/   1: Enable relative path. f_chdrive() and f_chdir() are available." + NL + "/   2: f_getcwd() is available in addition to 1." + NL + "/" + NL + "/  Note that output of the f_readdir function is affected by this option. */" + NL + "" + NL + "/*---------------------------------------------------------------------------/" + NL + "/ Physical Drive Configurations" + NL + "/----------------------------------------------------------------------------*/" + NL + "" + NL + "#define _VOLUMES\t";
  protected final String TEXT_14 = NL + "/* Number of volumes (logical drives) to be used. */" + NL + "" + NL + "" + NL + "#define\t_MAX_SS\t\t512\t\t/* 512, 1024, 2048 or 4096 */" + NL + "/* Maximum sector size to be handled." + NL + "/  Always set 512 for memory card and hard disk but a larger value may be" + NL + "/  required for on-board flash memory, floppy disk and optical disk." + NL + "/  When _MAX_SS is larger than 512, it configures FatFs to variable sector size" + NL + "/  and GET_SECTOR_SIZE command must be implememted to the disk_ioctl function. */" + NL + "" + NL + "" + NL + "#define\t_MULTI_PARTITION\t";
  protected final String TEXT_15 = "\t/* 0:Single partition or 1/2:Enable multiple partition */" + NL + "/* When set to 0, each volume is bound to the same physical drive number and" + NL + "/ it can mount only first primaly partition. When it is set to 1, each volume" + NL + "/ is tied to the partitions listed in VolToPart[]. */" + NL + "" + NL + "" + NL + "#define\t_USE_ERASE\t";
  protected final String TEXT_16 = " \t/* 0:Disable or 1:Enable */" + NL + "/* To enable sector erase feature, set _USE_ERASE to 1.CTRL_ERASE_SECTOR command" + NL + "/  should be added to the disk_ioctl function. */" + NL + "" + NL + "" + NL + "" + NL + "/*---------------------------------------------------------------------------/" + NL + "/ System Configurations" + NL + "/----------------------------------------------------------------------------*/" + NL + "" + NL + "#define _WORD_ACCESS\t";
  protected final String TEXT_17 = "\t/* 0 or 1 */" + NL + "/* Set 0 first and it is always compatible with all platforms. The _WORD_ACCESS" + NL + "/  option defines which access method is used to the word data on the FAT volume." + NL + "/" + NL + "/   0: Byte-by-byte access." + NL + "/   1: Word access. Do not choose this unless following condition is met." + NL + "/" + NL + "/  When the byte order on the memory is big-endian or address miss-aligned word" + NL + "/  access results incorrect behavior, the _WORD_ACCESS must be set to 0." + NL + "/  If it is not the case, the value can also be set to 1 to improve the" + NL + "/  performance and code size. */" + NL + "" + NL + "" + NL + "/* Include a header file here to define sync object types on the O/S */" + NL + "/* #include <windows.h>, <ucos_ii.h>, <semphr.h> or ohters. */" + NL + "" + NL + "#define _FS_REENTRANT\t";
  protected final String TEXT_18 = "\t\t/* 0:Disable or 1:Enable */" + NL + "" + NL + "" + NL + "#if _FS_REENTRANT" + NL + "#include \"../../inc/RTOS001/RTOS001.h\"" + NL + "#define _FS_TIMEOUT\t\t";
  protected final String TEXT_19 = "\t/* Timeout period in unit of time ticks */" + NL + "#define\t_SYNC_t\t\t\tosMutexId\t/* O/S dependent type of sync object. e.g. HANDLE, OS_EVENT*, ID and etc.. */" + NL + "#endif" + NL + "/* The _FS_REENTRANT option switches the reentrancy of the FatFs module." + NL + "/" + NL + "/   0: Disable reentrancy. _SYNC_t and _FS_TIMEOUT have no effect." + NL + "/   1: Enable reentrancy. Also user provided synchronization handlers," + NL + "/      ff_req_grant, ff_rel_grant, ff_del_syncobj and ff_cre_syncobj" + NL + "/      function must be added to the project. */" + NL + "" + NL + "" + NL + "#define\t_FS_SHARE\t";
  protected final String TEXT_20 = "\t/* 0:Disable or >=1:Enable */" + NL + "/* To enable file sharing feature, set _FS_SHARE to 1 or greater. The value" + NL + "   defines how many files can be opened simultaneously. */" + NL + "" + NL + "" + NL + "" + NL + "#endif /* _FFCONFIG */" + NL + "" + NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_21 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/fatfs002/"; 
     int appInst = 0; 
     int  FatFsTiny = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_tiny_fs/0");
   int  FatFsReadOnly = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_readonly/0");
   int Minimize = 0;
   int UseStr = 0;
   int CodePage = 932;
   int LfnCode = 0;
   int UseRelative = 0;
   int WordAccess = 0;
   
   int  FatFsMinimize = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_minimize/0");
   if( FatFsMinimize == 1)
   {
     Minimize = 0;
   }
   FatFsMinimize = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_minimize/1");
   if( FatFsMinimize == 1)
   {
     Minimize = 1;
   }
   FatFsMinimize = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_minimize/2");
   if( FatFsMinimize == 1)
   {
     Minimize = 2;
   }
   FatFsMinimize = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_minimize/3");
   if( FatFsMinimize == 1)
   {
     Minimize = 3;
   }
    
   int  FatFsUseStr = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_use_strfunc/0");
   if( FatFsUseStr == 1)
   {
     UseStr = 0;
   }
   FatFsUseStr = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_use_strfunc/1");
   if( FatFsUseStr == 1)
   {
     UseStr = 1 ;
   }
   FatFsUseStr = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_use_strfunc/2");
   if( FatFsUseStr == 1)
   {
     UseStr = 2 ;
   }
   
   int  FatFsUseMkfs = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_use_mkfs/0");
   int  FatFsUseFwd = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_use_forward/0");
   int  FatFsUseSeek = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fast_seek/0");
   
   int  FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/0");
   if( FatFsCodePage == 1)
   {
     CodePage = 932 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/1");
   if( FatFsCodePage == 1)
   {
     CodePage = 936 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/2");
   if( FatFsCodePage == 1)
   {
     CodePage = 949 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/3");
   if( FatFsCodePage == 1)
   {
     CodePage = 950 ;
   }
   
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/4");
   if( FatFsCodePage == 1)
   {
     CodePage = 1250 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/5");
   if( FatFsCodePage == 1)
   {
     CodePage = 1251 ;
   }
   
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/6");
   if( FatFsCodePage == 1)
   {
     CodePage = 1252 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/7");
   if( FatFsCodePage == 1)
   {
     CodePage = 1253 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/8");
   if( FatFsCodePage == 1)
   {
     CodePage = 1254 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/9");
   if( FatFsCodePage == 1)
   {
     CodePage = 1255 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/10");
   if( FatFsCodePage == 1)
   {
     CodePage = 1256 ;
   }
   
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/11");
   if( FatFsCodePage == 1)
   {
     CodePage = 1257 ;
   }
   
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/12");
   if( FatFsCodePage == 1)
   {
     CodePage = 1258 ;
   }
   
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/13");
   if( FatFsCodePage == 1)
   {
     CodePage = 437 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/14");
   if( FatFsCodePage == 1)
   {
     CodePage = 720 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/15");
   if( FatFsCodePage == 1)
   {
     CodePage = 737 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/16");
   if( FatFsCodePage == 1)
   {
     CodePage = 775 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/17");
   if( FatFsCodePage == 1)
   {
     CodePage = 850 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/18");
   if( FatFsCodePage == 1)
   {
     CodePage = 858 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/19");
   if( FatFsCodePage == 1)
   {
     CodePage = 852 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/20");
   if( FatFsCodePage == 1)
   {
     CodePage = 855 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/21");
   if( FatFsCodePage == 1)
   {
     CodePage = 866 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/22");
   if( FatFsCodePage == 1)
   {
     CodePage = 857 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/23");
   if( FatFsCodePage == 1)
   {
     CodePage = 862 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/24");
   if( FatFsCodePage == 1)
   {
     CodePage = 874 ;
   }
   FatFsCodePage = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_code_page/25");
   if( FatFsCodePage == 1)
   {
     CodePage = 1 ;
   }
//   int  FatFsUseLfn = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_lfn/0");
   
   int  FatFsLfnCode = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_lfn_unicode/0");
   if( FatFsLfnCode == 1)
   {
     LfnCode = 0 ;
   }
   FatFsLfnCode = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_lfn_unicode/1");
   if( FatFsLfnCode == 1)
   {
     LfnCode = 1 ;
   }
   
   int  FatFsUseRelative = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_relative_path/0");
   if( FatFsUseRelative == 1)
   {
     UseRelative = 0;
   }
   FatFsUseRelative = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_relative_path/1");
   if( FatFsUseRelative == 1)
   {
     UseRelative = 1 ;
   } 
   FatFsUseRelative = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_relative_path/2");
   if( FatFsUseRelative == 1)
   {
     UseRelative = 2 ;
   } 
   
      
   int  FatFsMultPart = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_multi_partition/0");
   if( FatFsMultPart == 1)
   {
     FatFsMultPart = 2 ;
   }
   int  FatFsUseErase = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_erase/0");
   int  FatFsWordAccess = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_word_access/0");
   if( FatFsWordAccess == 1)
   {
     WordAccess = 0 ;
   } 
   FatFsWordAccess = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_word_access/1");
   if( FatFsWordAccess == 1)
   {
     WordAccess = 1 ;
   } 
    
   int  FatFsMaxLfn = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_max_lfn");
   
   int  FatFsMaxVol = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_volumes");
   
   int  FatFsTimeout = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_timeout");
   int  FatFsShare = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_share");
   int  FatFsReentrant = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_reentrant");
   

    stringBuffer.append(TEXT_2);
    stringBuffer.append( FatFsTiny );
    stringBuffer.append(TEXT_3);
    stringBuffer.append( FatFsReadOnly );
    stringBuffer.append(TEXT_4);
    stringBuffer.append( Minimize );
    stringBuffer.append(TEXT_5);
    stringBuffer.append( UseStr );
    stringBuffer.append(TEXT_6);
    stringBuffer.append( FatFsUseMkfs );
    stringBuffer.append(TEXT_7);
    stringBuffer.append( FatFsUseFwd );
    stringBuffer.append(TEXT_8);
    stringBuffer.append( FatFsUseSeek );
    stringBuffer.append(TEXT_9);
    stringBuffer.append( CodePage );
    stringBuffer.append(TEXT_10);
    stringBuffer.append( FatFsMaxLfn );
    stringBuffer.append(TEXT_11);
    stringBuffer.append( LfnCode );
    stringBuffer.append(TEXT_12);
    stringBuffer.append( UseRelative );
    stringBuffer.append(TEXT_13);
    stringBuffer.append( FatFsMaxVol );
    stringBuffer.append(TEXT_14);
    stringBuffer.append( FatFsMultPart );
    stringBuffer.append(TEXT_15);
    stringBuffer.append( FatFsUseErase );
    stringBuffer.append(TEXT_16);
    stringBuffer.append( WordAccess );
    stringBuffer.append(TEXT_17);
    stringBuffer.append( FatFsReentrant );
    stringBuffer.append(TEXT_18);
    stringBuffer.append( FatFsTimeout );
    stringBuffer.append(TEXT_19);
    stringBuffer.append( FatFsShare );
    stringBuffer.append(TEXT_20);
    stringBuffer.append(TEXT_21);
    return stringBuffer.toString();
  }
}
