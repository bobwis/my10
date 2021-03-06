package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class sdmmc001h_template
{
  protected static String nl;
  public static synchronized sdmmc001h_template create(String lineSeparator)
  {
    nl = lineSeparator;
    sdmmc001h_template result = new sdmmc001h_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/* CODE_BLOCK_BEGIN[SDMMC001.h]*/" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers. " + NL + " * This file can be freely distributed within development" + NL + " * tools that are supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR" + NL + " * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : July 31, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL + " ";
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + "#ifndef ";
  protected final String TEXT_4 = "_H_" + NL + "#define ";
  protected final String TEXT_5 = "_H_" + NL + "" + NL + "" + NL + "/**" + NL + " * @file  ";
  protected final String TEXT_6 = ".h" + NL + " *" + NL + " * @brief This file contains all public data structures,enums and function" + NL + " *        prototypes for Sdmmc Block Layer App." + NL + " *" + NL + " */" + NL + "/*******************************************************************************" + NL + "**                      INCLUDE FILES                                         **" + NL + "*******************************************************************************/" + NL + "#include <DAVE3.h>" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Global Macro Definitions                              **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * @ingroup ";
  protected final String TEXT_7 = "_publicparam" + NL + " * @{" + NL + " */" + NL + " " + NL + "/* IOCTL code for Sdmmc Module */" + NL + "" + NL + "/* Command code for disk_ioctrl fucntion */" + NL + "" + NL + "/* Generic command (defined for FatFs) */" + NL + "/** Flush disk cache (for write functions) */" + NL + "#define ";
  protected final String TEXT_8 = "_CTRL_SYNC               0 " + NL + "" + NL + "/** Get media size (for only f_mkfs()) */" + NL + "#define ";
  protected final String TEXT_9 = "_GET_SECTOR_COUNT        1 " + NL + "" + NL + "/** Get sector size (for multiple sector size (_MAX_SS >= 1024)) */" + NL + "#define ";
  protected final String TEXT_10 = "_GET_SECTOR_SIZE         2 " + NL + "" + NL + "/** Get erase block size (for only f_mkfs()) */" + NL + "#define ";
  protected final String TEXT_11 = "_GET_BLOCK_SIZE          3 " + NL + "" + NL + "/** Force erased a block of sectors (for only _USE_ERASE) */" + NL + "#define ";
  protected final String TEXT_12 = "_CTRL_ERASE_SECTOR       4 " + NL + "" + NL + "/* Generic command */" + NL + "/** Get/Set power status */" + NL + "#define ";
  protected final String TEXT_13 = "_CTRL_POWER              5 " + NL + "" + NL + "/** Lock/Unlock media removal */" + NL + "#define ";
  protected final String TEXT_14 = "_CTRL_LOCK               6 " + NL + "" + NL + "/** Eject media */" + NL + "#define ";
  protected final String TEXT_15 = "_CTRL_EJECT              7 " + NL + "" + NL + "/* MMC/SDC specific ioctl command */" + NL + "" + NL + "/** Get card type */" + NL + "#define ";
  protected final String TEXT_16 = "_MMC_GET_TYPE            10 " + NL + "" + NL + "/** Get CSD */" + NL + "#define ";
  protected final String TEXT_17 = "_MMC_GET_CSD             11 " + NL + "" + NL + "/** Get CID */" + NL + "#define ";
  protected final String TEXT_18 = "_MMC_GET_CID             12 " + NL + "" + NL + "/** Get OCR */" + NL + "#define ";
  protected final String TEXT_19 = "_MMC_GET_OCR             13  " + NL + "" + NL + "/** Get SD status */" + NL + "#define ";
  protected final String TEXT_20 = "_MMC_GET_SDSTAT          14  " + NL + "" + NL + "/* NAND specific ioctl command */" + NL + "/** Create physical format */" + NL + "#define ";
  protected final String TEXT_21 = "_NAND_FORMAT             30  " + NL + "/**" + NL + " * Lock the card. " + NL + " */" + NL + "#define  ";
  protected final String TEXT_22 = "_MMC_LOCK_CARD    (";
  protected final String TEXT_23 = "_NAND_FORMAT + 1 )" + NL + "/**" + NL + " * Unlock the card. " + NL + " */" + NL + "#define  ";
  protected final String TEXT_24 = "_MMC_UNLOCK_CARD (";
  protected final String TEXT_25 = "_MMC_LOCK_CARD + 1)" + NL + "/**" + NL + " * Set/Reset the password. Card gets locked in the next power cycle." + NL + " */" + NL + "#define  ";
  protected final String TEXT_26 = "_MMC_SET_PASSWD (";
  protected final String TEXT_27 = "_MMC_UNLOCK_CARD + 1)" + NL + "/**" + NL + " * Clear the password. To remove the Password from the card" + NL + " */" + NL + "#define  ";
  protected final String TEXT_28 = "_MMC_CLEAR_PASSWD (";
  protected final String TEXT_29 = "_MMC_SET_PASSWD + 1)" + NL + "/**" + NL + " * Sets the password and Lock the card immediately." + NL + " */" + NL + "#define  ";
  protected final String TEXT_30 = "_MMC_SET_LOCK    (";
  protected final String TEXT_31 = "_MMC_CLEAR_PASSWD + 1)" + NL + "/**" + NL + " * Read  the current Lock Status of the card " + NL + " */" + NL + "#define  ";
  protected final String TEXT_32 = "_MMC_READ_LOCK_STATUS  (";
  protected final String TEXT_33 = "_MMC_SET_LOCK + 1)" + NL + "/**" + NL + " * Erase the Password forcefully. Useful when user forgets the password." + NL + " */" + NL + "#define  ";
  protected final String TEXT_34 = "_MMC_FORCE_ERASE   (";
  protected final String TEXT_35 = "_MMC_READ_LOCK_STATUS + 1)" + NL + "" + NL + "" + NL + "/**" + NL + " * Maximum Length of the password " + NL + " */" + NL + "#define ";
  protected final String TEXT_36 = "_MAX_PASSWD_LEN                        16" + NL + "" + NL + "/* SDMMC Block Layer Error Codes */" + NL + "/** Successful */" + NL + "#define ";
  protected final String TEXT_37 = "_RES_OK                               0" + NL + "/**  R/W Error */" + NL + "#define ";
  protected final String TEXT_38 = "_RES_ERROR                            1" + NL + "/**  Write Protected  */" + NL + "#define ";
  protected final String TEXT_39 = "_RES_WRPRT                            2" + NL + "/** Not Ready  */" + NL + "#define ";
  protected final String TEXT_40 = "_RES_NOTRDY                           3" + NL + "/** Invalid Parameter */" + NL + "#define ";
  protected final String TEXT_41 = "_RES_PARERR                           4" + NL + "" + NL + "/** Drive not initialized */" + NL + "#define ";
  protected final String TEXT_42 = "_STA_NOINIT                         0x01  " + NL + "/** No medium in the drive */" + NL + "#define ";
  protected final String TEXT_43 = "_STA_NODISK                         0x02  " + NL + "/** Write protected */" + NL + "#define ";
  protected final String TEXT_44 = "_STA_PROTECT                        0x04  " + NL + "" + NL + "/*******************************************************************************" + NL + "**                       ENUMERATIONS                                         **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * This enumerates the error codes of this APP" + NL + " */" + NL + "typedef enum ";
  protected final String TEXT_45 = "_ErrorCodesType" + NL + "{" + NL + "  /**" + NL + "   * ";
  protected final String TEXT_46 = " Module Error  (1)" + NL + "   */" + NL + "  /*" + NL + "  GROUPID  #20" + NL + "  MODULENAME = SDMMC Block Layer App" + NL + "  */" + NL + "  /*" + NL + "  ERRCODESTRING = ";
  protected final String TEXT_47 = "_ERROR" + NL + "  STRCODESTRING = Error in ";
  protected final String TEXT_48 = " App." + NL + "  */";
  protected final String TEXT_49 = NL + "  ";
  protected final String TEXT_50 = "_ERROR = 1," + NL + "  /**" + NL + "   * SDMMC LLD Module Error  (2)" + NL + "   */" + NL + "  /*" + NL + "  GROUPID  #20" + NL + "  MODULENAME = SDMMC Block Layer App" + NL + "  */" + NL + "  /*" + NL + "  ERRCODESTRING = ";
  protected final String TEXT_51 = "_SDMMC00x_ERROR" + NL + "  STRCODESTRING = Error in Sdmmc LLD App." + NL + "  */";
  protected final String TEXT_52 = NL + "  ";
  protected final String TEXT_53 = "_SDMMC00x_ERROR," + NL + "  " + NL + "   /**" + NL + "   * SDMMC Device Is locked (3)" + NL + "   */" + NL + "  /*" + NL + "  GROUPID  #20" + NL + "  MODULENAME = SDMMC Block Layer App" + NL + "  */" + NL + "  /*" + NL + "  ERRCODESTRING = ";
  protected final String TEXT_54 = "_DISK_LOCKED" + NL + "  STRCODESTRING = SDMMC Device is locked." + NL + "  */";
  protected final String TEXT_55 = NL + "  ";
  protected final String TEXT_56 = "_DISK_LOCKED," + NL + "  /**" + NL + "   * Debug log codes starts here  (0)" + NL + "   */" + NL + "  /**" + NL + "   * DebugLog Message Id for Function Entry" + NL + "   */" + NL + "  /*" + NL + "  ERRCODESTRING = ";
  protected final String TEXT_57 = "_FUNCTION_ENTRY" + NL + "  STRCODESTRING = Function Entered %s" + NL + "  */";
  protected final String TEXT_58 = NL + "    ";
  protected final String TEXT_59 = "_FUNCTION_ENTRY," + NL + "    /**" + NL + "   * DebugLog Message Id for Function Exit (1)" + NL + "   */" + NL + "  /*" + NL + "  ERRCODESTRING = ";
  protected final String TEXT_60 = "_FUNCTION_EXIT" + NL + "  STRCODESTRING = Function Exited %s" + NL + "  */";
  protected final String TEXT_61 = NL + "    ";
  protected final String TEXT_62 = "_FUNCTION_EXIT" + NL + "} ";
  protected final String TEXT_63 = "_ErrorCodesType;" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      STRUCTURES                                            **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * This structure contains the Password details. User needs to provide the password information" + NL + " * in this structure inorder to use the card's security feature. " + NL + " */" + NL + "typedef struct ";
  protected final String TEXT_64 = "_PasswdType" + NL + "{" + NL + "/**" + NL + " * Old Password. User needs to set this field if setting password for the first time or  " + NL + " * if locking/unlocking the card." + NL + " *" + NL + " */" + NL + "  uint8_t OldPassword[";
  protected final String TEXT_65 = "_MAX_PASSWD_LEN];" + NL + "/**" + NL + " * New Password. User needs to set this field at the time of replacing the old" + NL + " * password with  the new one. Sets to 0 if not replacing the password. " + NL + " */" + NL + "  uint8_t NewPassword[";
  protected final String TEXT_66 = "_MAX_PASSWD_LEN];" + NL + "/**" + NL + " * Old Password Lenth." + NL + " */" + NL + "  uint8_t OldPwdLength;" + NL + "/**" + NL + " * New Password Length. Set to 0 if not setting the password." + NL + " */" + NL + "  uint8_t NewPwdLength;" + NL + "} ";
  protected final String TEXT_67 = "_PasswdType;" + NL + "" + NL + "/**" + NL + " * This is the structure for  Erase Address details. " + NL + " */" + NL + "typedef struct ";
  protected final String TEXT_68 = "_EraseAddrType" + NL + "{" + NL + "/**" + NL + " * Erase Block Start Address" + NL + " */" + NL + "    uint32_t StartAddress;" + NL + "/**" + NL + " * Erase Block Start Address" + NL + " */" + NL + "    uint32_t EndAddress;" + NL + "} ";
  protected final String TEXT_69 = "_EraseAddrType ;" + NL + "" + NL + "/**" + NL + " * @}" + NL + " */" + NL + " " + NL + " /**" + NL + " * @ingroup ";
  protected final String TEXT_70 = "_apidoc" + NL + " * @{" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + " **                           FUNCTION PROTOTYPES                             **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @brief This function initializes the SD/MMC card and returns the " + NL + " * initialization status of the card. A initialization flag is set to 1 if the " + NL + " * card is initialized properly. It returns values in the combination of flags." + NL + " * This function is called directly by FAT File System. " + NL + " * @return uint8_t \\n" + NL + " * ";
  protected final String TEXT_71 = "_STA_NOINIT: Not Initialized\\n" + NL + " * ";
  protected final String TEXT_72 = "_STA_NODISK: No card\\n" + NL + " * ";
  protected final String TEXT_73 = "_STA_PROTECT: Card is write protected\\n" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *   uint8_t DStatus;" + NL + " *   // DAVE Initialization." + NL + " *   DAVE_Init();" + NL + " *   DStatus =  ";
  protected final String TEXT_74 = "_Initialize();" + NL + " *   if (DStatus == (";
  protected final String TEXT_75 = "_STA_NODISK | ";
  protected final String TEXT_76 = "_STA_NOINIT))" + NL + " *   {" + NL + " *     //No card Present;" + NL + " *   }" + NL + " *   if (DStatus == ";
  protected final String TEXT_77 = "_STA_NOINIT)" + NL + " *   {" + NL + " *      //Card Present but not initialized." + NL + " *   }" + NL + " *   if (DStatus == ";
  protected final String TEXT_78 = "_STA_PROTECT)" + NL + " *   {" + NL + " *      //Card is Write Protected ." + NL + " *   } " + NL + " *   return 0;" + NL + " * }" + NL + " * @endcode" + NL + " */" + NL + "uint8_t ";
  protected final String TEXT_79 = "_Initialize(void);" + NL + "" + NL + "/**" + NL + " * @brief This function gets the current card's status like" + NL + " * whether device is initialized, whether device is inserted or is it write" + NL + " * protected etc. The disk status is returned in combination of flags." + NL + " * @return uint8_t \\n" + NL + " * ";
  protected final String TEXT_80 = "_STA_NOINIT: Not Initialized\\n" + NL + " * ";
  protected final String TEXT_81 = "_STA_NODISK: No card\\n" + NL + " * ";
  protected final String TEXT_82 = "_STA_PROTECT: Card is write protected\\n" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *   uint8_t DStatus;" + NL + " *   // DAVE Initialization." + NL + " *   DAVE_Init();" + NL + " *   DStatus =  ";
  protected final String TEXT_83 = "_GetStatus();" + NL + " *   if (DStatus == (";
  protected final String TEXT_84 = "_STA_NODISK | ";
  protected final String TEXT_85 = "_STA_NOINIT))" + NL + " *   {" + NL + " *     //No card Present;" + NL + " *   }" + NL + " *   if (DStatus == ";
  protected final String TEXT_86 = "_STA_NOINIT)" + NL + " *   {" + NL + " *     //Card Present but not initialized." + NL + " *   }" + NL + " *   if (DStatus == ";
  protected final String TEXT_87 = "_STA_PROTECT)" + NL + " *   {" + NL + " *     //Card is Write Protected ." + NL + " *   } " + NL + " *   return 0;" + NL + " * }" + NL + " * @endcode" + NL + " */" + NL + "uint8_t  ";
  protected final String TEXT_88 = "_GetStatus(void);" + NL + "" + NL + "/**" + NL + " * @brief This function reads blocks of data from the card. Block read can be single" + NL + " * or multiple blocks. It is mandatory to pass aligned buffer to store the data read" + NL + " * from the card otherwise the read operation fails." + NL + " * @param[out] ReadBuf Read Aligned Buffer pointer to store data read from the card." + NL + " * @param[in] SectorNumber Card sector address in sector number form where to read." + NL + " * @param[in] SectorCount Number of sectors to read. 1 sector = 512 bytes." + NL + " * @return uint32_t\\n" + NL + " * ";
  protected final String TEXT_89 = "_RES_OK: If  read  operation is successfully completed.\\n" + NL + " * ";
  protected final String TEXT_90 = "_RES_NOTRDY: Card is not initialized.\\n" + NL + " * ";
  protected final String TEXT_91 = "_RES_ERROR: If  read operation fails.\\n" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *   uint32_t DResult;" + NL + " *   uint32_t Count = 0;" + NL + " *   uint32_t Counter = 0;" + NL + " *   uint8_t  WriteData[1536];" + NL + " *   uint8_t  ReadData[1536];" + NL + " *   // DAVE Initialization." + NL + " *   DAVE_Init();" + NL + " *   for(Counter=0;Counter<384;Counter++)" + NL + " *   {" + NL + " *     WriteData[Counter] = Counter * 10;" + NL + " *   }" + NL + " *   // Write functionality " + NL + " *   DResult =  ";
  protected final String TEXT_92 = "_WriteBlock( WriteData, 200, 3);" + NL + " *   if(DResult == ";
  protected final String TEXT_93 = "_RES_OK)" + NL + " *   {" + NL + " *     // Read functionality " + NL + " *     DResult =  ";
  protected final String TEXT_94 = "_ReadBlock( ReadData, 200, 3);" + NL + " *     for( Count=0; Count<1536; Count++)" + NL + " *     {" + NL + " *       if( ReadData[Count] != WriteData[Count])" + NL + " *       {" + NL + " *         // Read and Write Data doesn't match." + NL + " *       }" + NL + " *     }" + NL + " *    }" + NL + " *   return 0;" + NL + " * }" + NL + " * @endcode" + NL + " */" + NL + "uint32_t ";
  protected final String TEXT_95 = "_ReadBlock" + NL + "(" + NL + "  uint8_t * ReadBuf," + NL + "  uint32_t SectorNumber," + NL + "  uint8_t SectorCount" + NL + ");" + NL + "" + NL + "/**" + NL + " * @brief This function writes the data blocks onto the card from the host" + NL + " * system. Write operation may be for single or multiple blocks. Based on block" + NL + " * count parameter, single or multiple write block api is called from LLD App." + NL + " * @param[in] WriteBuf Write buffer pointer from where to store data on the card." + NL + " * @param[in] SectorNumber Card Sector address in sector number on where to write." + NL + " * @param[in] SectorCount Number of sectors to write. 1 sector = 512 bytes." + NL + " * @return uint32_t \\n" + NL + " * ";
  protected final String TEXT_96 = "_RES_OK: If  write  operation is successfully completed.\\n" + NL + " * ";
  protected final String TEXT_97 = "_RES_NOTRDY: Card is not initialized.\\n" + NL + " * ";
  protected final String TEXT_98 = "_RES_ERROR: If card write operation fails.\\n" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *   uint32_t DResult;" + NL + " *   uint32_t Count = 0;" + NL + " *   uint32_t Counter = 0;" + NL + " *   uint8_t  WriteData[1536];" + NL + " *   uint8_t  ReadData[1536];" + NL + " *   status_t Status =(uint32_t)DAVEApp_SUCCESS;" + NL + " *   // DAVE Initialization." + NL + " *   DAVE_Init();" + NL + " *   for(Counter=0;Counter<384;Counter++)" + NL + " *   {" + NL + " *     WriteData[Counter] = Counter * 10;" + NL + " *   }" + NL + " *   // Write functionality " + NL + " *   DResult =  ";
  protected final String TEXT_99 = "_WriteBlock( WriteData, 200, 3);" + NL + " *   if(DResult == ";
  protected final String TEXT_100 = "_RES_OK)" + NL + " *   {" + NL + " *     // Read functionality " + NL + " *     DResult =  ";
  protected final String TEXT_101 = "_ReadBlock( ReadData, 200, 3);" + NL + " *     for( Count=0; Count<1536; Count++)" + NL + " *     {" + NL + " *       if( ReadData[Count] != WriteData[Count])" + NL + " *       {" + NL + " *         Status = ";
  protected final String TEXT_102 = "_ERROR;" + NL + " *         // Read and Write Data doesn't match." + NL + " *       }" + NL + " *     }" + NL + " *   }" + NL + " *   return Status;" + NL + " * }" + NL + " * @endcode" + NL + " */" + NL + "uint32_t  ";
  protected final String TEXT_103 = "_WriteBlock" + NL + "(" + NL + "  const uint8_t *WriteBuf," + NL + "  uint32_t SectorNumber," + NL + "  uint8_t SectorCount" + NL + ");" + NL + "" + NL + "/**" + NL + " * @brief This function controls SDMMC device specified features and the device" + NL + " * independent miscellaneous functions other than disk read/write." + NL + " * For Locking features user must provide the password information in the" + NL + " * Passwd structure provided to the user." + NL + " * @param[in] Command specifies the command code. " + NL + " * @param[in] Buffer Pointer to the parameter buffer depends on the command code.\\n" + NL + " * When it is not used, specify a NULL pointer." + NL + " * @return uint32_t\\n" + NL + " * ";
  protected final String TEXT_104 = "_RES_OK: If device specific functionality is done successfully.\\n" + NL + " * ";
  protected final String TEXT_105 = "_RES_NOTRDY: Card is not initialized.\\n" + NL + " * ";
  protected final String TEXT_106 = "_RES_WRPRT  : Card is read only.\\n" + NL + " * ";
  protected final String TEXT_107 = "_RES_ERROR: If device specific functionality fails.\\n" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " * <BR><P>" + NL + " * <b>Ioctl Command's used are : </b>\\n" + NL + " * Generic commands (defined for FatFs) \\n" + NL + " * ";
  protected final String TEXT_108 = "_CTRL_SYNC: Flush disk cache (for write functions) \\n" + NL + " * ";
  protected final String TEXT_109 = "_GET_SECTOR_COUNT: Get media size (for only f_mkfs()) \\n " + NL + " * ";
  protected final String TEXT_110 = "_GET_SECTOR_SIZE: Get sector size (for multiple sector size (_MAX_SS >= 1024)) \\n" + NL + " * ";
  protected final String TEXT_111 = "_GET_BLOCK_SIZE: Get erase block size (for only f_mkfs()) \\n" + NL + " * ";
  protected final String TEXT_112 = "_CTRL_ERASE_SECTOR:  Force erased a block of sectors (for only _USE_ERASE) \\n" + NL + " * ";
  protected final String TEXT_113 = "_CTRL_EJECT: Eject media \\n" + NL + " * MMC/SDC specific ioctl commands \\n" + NL + " * ";
  protected final String TEXT_114 = "_MMC_GET_TYPE: Get card type ie. Standard Capacity v2/v1x or High Capacity card. \\n" + NL + " * ";
  protected final String TEXT_115 = "_MMC_GET_CSD: Get Card's Specific Data register \\n" + NL + " * ";
  protected final String TEXT_116 = "_MMC_GET_CID: Get Card's Identification Number \\n" + NL + " * ";
  protected final String TEXT_117 = "_MMC_GET_OCR: Get Card's Operating Condition Register  \\n" + NL + " * ";
  protected final String TEXT_118 = "_MMC_GET_SDSTAT:  Get 512-bit SD bus status information.  \\n" + NL + " * The following Ioctl command's needs to be called directly from this layer as" + NL + " * Fat File system doesn't support these security Ioctl's. \\n" + NL + " *  ";
  protected final String TEXT_119 = "_MMC_LOCK_CARD: Locks the card. \\n" + NL + " *  ";
  protected final String TEXT_120 = "_MMC_UNLOCK_CARD: Unlocks the card. \\n" + NL + " *  ";
  protected final String TEXT_121 = "_MMC_SET_PASSWD: Set/replace the password. \\n" + NL + " *  ";
  protected final String TEXT_122 = "_MMC_CLEAR_PASSWD: Clear the password. \\n" + NL + " *  ";
  protected final String TEXT_123 = "_MMC_SET_LOCK: Sets the password and locks the card in the same power cycle. \\n" + NL + " *  ";
  protected final String TEXT_124 = "_MMC_READ_LOCK_STATUS: Reads the current lock status of the card. \\n" + NL + " *  ";
  protected final String TEXT_125 = "_MMC_FORCE_ERASE: Force erase the password. It is useful when user forgets the password. \\n" + NL + " </p>" + NL + " " + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *   ";
  protected final String TEXT_126 = "_PasswdType PasswdInfo  ;" + NL + " *   uint32_t Result;" + NL + " *   uint32_t Buffer;" + NL + " *   // The same api will be called for all lock related api's. " + NL + " *   //Just take care of the parameters passed." + NL + " *   // SET PASSWORD & LOCK the CARD //" + NL + " *   strcpy(PasswdInfo.OldPassword, \"IFX\");" + NL + " *   PasswdInfo.OldPwdLength = 3;" + NL + " *   Result = ";
  protected final String TEXT_127 = "_Ioctl( ";
  protected final String TEXT_128 = "_MMC_SET_LOCK,(void *)&PasswdInfo);" + NL + " *   if (Result == ";
  protected final String TEXT_129 = "_RES_OK)" + NL + " *   {" + NL + " *     // READ LOCK STATUS. Status returned should be card is locked  " + NL + " *     Result = ";
  protected final String TEXT_130 = "_Ioctl(";
  protected final String TEXT_131 = "_MMC_READ_LOCK_STATUS,(void *)&Buffer);" + NL + " *     if (Result == ";
  protected final String TEXT_132 = "_RES_OK )" + NL + " *     {" + NL + " *       if (Buffer == SDMMC003_CARD_IS_LOCKED)" + NL + " *       {" + NL + " *         // Force Erase the Password. " + NL + " *          Result = ";
  protected final String TEXT_133 = "_Ioctl( ";
  protected final String TEXT_134 = "_MMC_FORCE_ERASE,NULL);" + NL + " *       }" + NL + " *     }" + NL + " *     // Eject card //" + NL + " *     Result = ";
  protected final String TEXT_135 = "_Ioctl(";
  protected final String TEXT_136 = "_CTRL_EJECT,NULL);" + NL + " *   }" + NL + " *   return 0;" + NL + " * }" + NL + " * @endcode" + NL + " */" + NL + " uint32_t  ";
  protected final String TEXT_137 = "_Ioctl" + NL + "(" + NL + "    uint8_t Command," + NL + "    void * Buffer" + NL + ");" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "#endif /* ";
  protected final String TEXT_138 = "_H_ */" + NL + "" + NL + "/*CODE_BLOCK_END*/" + NL;
  protected final String TEXT_139 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/sdmmc001/"; 
     int appInst = 0; 
     int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/sdmmc001_rtos_present");
   String  Module_Name = "SDMMC001";

    stringBuffer.append(TEXT_2);
     
  if (RTOS == 1)
  {
    Module_Name = "SDMMC002";
  }
  else
  {
    Module_Name = "SDMMC001";
  }

    stringBuffer.append(TEXT_3);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_4);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_6);
    stringBuffer.append(Module_Name);
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
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_38);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_39);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_40);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_41);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_42);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_43);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_44);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_45);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_46);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_47);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_48);
    stringBuffer.append(TEXT_49);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_50);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_51);
    stringBuffer.append(TEXT_52);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_53);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_54);
    stringBuffer.append(TEXT_55);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_56);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_57);
    stringBuffer.append(TEXT_58);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_59);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_60);
    stringBuffer.append(TEXT_61);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_62);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_63);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_64);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_65);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_66);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_67);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_68);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_69);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_70);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_71);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_72);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_73);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_74);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_75);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_76);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_77);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_78);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_79);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_80);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_81);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_82);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_83);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_84);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_85);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_86);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_87);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_88);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_89);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_90);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_91);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_92);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_93);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_94);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_95);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_96);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_97);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_98);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_99);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_100);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_101);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_102);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_103);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_104);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_105);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_106);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_107);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_108);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_109);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_110);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_111);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_112);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_113);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_114);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_115);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_116);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_117);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_118);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_119);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_120);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_121);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_122);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_123);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_124);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_125);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_126);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_127);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_128);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_129);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_130);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_131);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_132);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_133);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_134);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_135);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_136);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_137);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_138);
    stringBuffer.append(TEXT_139);
    return stringBuffer.toString();
  }
}
