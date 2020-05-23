package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class fatfs004c_template
{
  protected static String nl;
  public static synchronized fatfs004c_template create(String lineSeparator)
  {
    nl = lineSeparator;
    fatfs004c_template result = new fatfs004c_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[FATFS004.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without** " + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : July 31, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                      INCLUDE FILES                                         **" + NL + "*******************************************************************************/" + NL + NL;
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + NL + "/**" + NL + " * @file   ";
  protected final String TEXT_4 = ".c" + NL + " *" + NL + " * @brief This file contains definitions of all public functions" + NL + " *        of Device Abstraction Layer App." + NL + " */" + NL + "#include <DAVE3.h>" + NL + "" + NL + "/**" + NL + " * Number of Devices attached" + NL + " */";
  protected final String TEXT_5 = " " + NL + "   #define ";
  protected final String TEXT_6 = "_MAX_DRIVES                        2";
  protected final String TEXT_7 = NL + "   #define ";
  protected final String TEXT_8 = "_MAX_DRIVES                        1";
  protected final String TEXT_9 = NL + "   #define ";
  protected final String TEXT_10 = "_MAX_DRIVES                        0";
  protected final String TEXT_11 = NL + "   " + NL + "" + NL + "" + NL + "/**" + NL + " * @cond INTERNAL_DOCS" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Global Variable Definitions                           **" + NL + "*******************************************************************************/" + NL + "" + NL + "DRESULT ";
  protected final String TEXT_12 = "_ErrorCodes[5] = {" + NL + "                                            RES_OK ,   RES_ERROR," + NL + "                                            RES_WRPRT, RES_NOTRDY," + NL + "                                            RES_PARERR" + NL + "                                          };" + NL + "" + NL + "DSTATUS ";
  protected final String TEXT_13 = "_StatusCodes[5] = " + NL + "                                     {" + NL + "                                       0, STA_NOINIT," + NL + "                                       STA_NODISK, ";
  protected final String TEXT_14 = "_NODISK_NOINIT," + NL + "                                       STA_PROTECT" + NL + "                                     };" + NL + "" + NL + "/**" + NL + " * Extern the DeviceFunction pointers initialized in config file." + NL + " */" + NL + "extern  ";
  protected final String TEXT_15 = "_DeviceFuncType ";
  protected final String TEXT_16 = "_DeviceFunc[";
  protected final String TEXT_17 = "_MAX_DRIVES];" + NL + "" + NL + "/**" + NL + " * Dummy Variable to hold the status." + NL + " */" + NL + " status_t ";
  protected final String TEXT_18 = "_UnusedStatus;" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                     Public Function Definitions                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*<<<DD_";
  protected final String TEXT_19 = "_API_1>>>*/" + NL + "/*" + NL + " * The function performs the disk initialization." + NL + " */" + NL + "DSTATUS disk_initialize(BYTE Drive)" + NL + "{" + NL + "  DSTATUS DStatus = 0;" + NL + "  uint8_t Status;" + NL + "  FUNCTION_ENTRY(GID_";
  protected final String TEXT_20 = ", (uint32_t)";
  protected final String TEXT_21 = "_FUNCTION_ENTRY);" + NL + "  do" + NL + "  {" + NL + "/*<<<DD_";
  protected final String TEXT_22 = "_API_1_1>>*/" + NL + "/* If drive number is greater than the maximum drives allowed  */" + NL + "    if (Drive >= ";
  protected final String TEXT_23 = "_MAX_DRIVES)" + NL + "    {" + NL + "      DStatus = (STA_NODISK | STA_NOINIT);" + NL + "      break;" + NL + "    }" + NL + "    /* Call the Initialize function. */" + NL + "/*<<<DD_";
  protected final String TEXT_24 = "_API_1_2>>*/" + NL + "    Status = ";
  protected final String TEXT_25 = "_DeviceFunc[Drive].InitializePtr();" + NL + "/* Fatfs to Block Layer Error Code Mapping */" + NL + "    DStatus = ";
  protected final String TEXT_26 = "_StatusCodes[Status];" + NL + "  } while (0);" + NL + "  FUNCTION_EXIT(GID_";
  protected final String TEXT_27 = ", (uint32_t)";
  protected final String TEXT_28 = "_FUNCTION_EXIT);" + NL + "  return DStatus;" + NL + "}" + NL + "" + NL + "/*<<<DD_";
  protected final String TEXT_29 = "_API_2>>>  */" + NL + "/*" + NL + " * The function gets the disk status information." + NL + " */" + NL + "DSTATUS disk_status(BYTE Drive)" + NL + "{" + NL + "  DSTATUS DStatus;" + NL + "  uint8_t Status;" + NL + "  FUNCTION_ENTRY(GID_";
  protected final String TEXT_30 = ", (uint32_t)";
  protected final String TEXT_31 = "_FUNCTION_ENTRY);" + NL + "  do" + NL + "  {" + NL + "/*  <<<DD_";
  protected final String TEXT_32 = "_API_2_1>>>  */" + NL + "/* If drive number is greater than the maximum drives allowed  */" + NL + "    if (Drive >= ";
  protected final String TEXT_33 = "_MAX_DRIVES)" + NL + "    {" + NL + "      DStatus = (STA_NODISK | STA_NOINIT);" + NL + "      break;" + NL + "    }" + NL + "    /* Call the Initialize function.*/" + NL + "/*<<<DD_";
  protected final String TEXT_34 = "_API_2_2>>>  */" + NL + "    Status = ";
  protected final String TEXT_35 = "_DeviceFunc[Drive].GetStatusPtr();" + NL + "/* Fatfs to Block Layer Error Code Mapping */" + NL + "    DStatus = ";
  protected final String TEXT_36 = "_StatusCodes[Status];" + NL + "  } while (0);" + NL + "  ERROR(GID_";
  protected final String TEXT_37 = ",";
  protected final String TEXT_38 = "_SDMMC002_ERROR,0,0);" + NL + "  FUNCTION_EXIT(GID_";
  protected final String TEXT_39 = ", (uint32_t)";
  protected final String TEXT_40 = "_FUNCTION_EXIT);" + NL + "  return DStatus;" + NL + "}" + NL + "" + NL + "/*  <<<DD_";
  protected final String TEXT_41 = "_API_3>>>  */" + NL + "/*" + NL + " * The function reads the blocks of data from the disk." + NL + " */" + NL + "DRESULT disk_read" + NL + "(" + NL + "  BYTE Drive," + NL + "  BYTE *Buffer," + NL + "  DWORD SectorNumber," + NL + "  BYTE SectorCount" + NL + ")" + NL + "{" + NL + "  DRESULT DResult;" + NL + "  uint32_t Result;" + NL + "  FUNCTION_ENTRY(GID_";
  protected final String TEXT_42 = ", (uint32_t)";
  protected final String TEXT_43 = "_FUNCTION_ENTRY);" + NL + "  do" + NL + "  {" + NL + "/*<<<DD_";
  protected final String TEXT_44 = "_API_3_1>>>*/" + NL + "/* If drive number is greater than the maximum drives allowed  */" + NL + "    if (Drive >= ";
  protected final String TEXT_45 = "_MAX_DRIVES )" + NL + "    {" + NL + "      DResult = RES_PARERR;" + NL + "      break;" + NL + "    }" + NL + "/*<<<DD_";
  protected final String TEXT_46 = "_API_3_2>>>*/" + NL + "    /* If sector count is less than 1. Minimum 1 sector is needed*/" + NL + "    if (SectorCount < 1)" + NL + "    {" + NL + "      DResult = RES_PARERR;" + NL + "      break;" + NL + "    }" + NL + "/*<<<DD_";
  protected final String TEXT_47 = "_API_3_3>>>*/" + NL + "    /* For BufferPtr not aligned */" + NL + "    if (((uint32_t)Buffer % 4UL) != 0UL)" + NL + "    {" + NL + "      DResult = RES_PARERR;" + NL + "      break;" + NL + "    }" + NL + "/*<<<DD_";
  protected final String TEXT_48 = "_API_3_4>>>*/" + NL + "    /*Call the ReadBlkPtr function.*/" + NL + "    Result = ";
  protected final String TEXT_49 = "_DeviceFunc[Drive].ReadBlkPtr(Buffer, SectorNumber, \\" + NL + "                                                    SectorCount);" + NL + "/* Fatfs to Block Layer Error Code Mapping */" + NL + "    DResult = ";
  protected final String TEXT_50 = "_ErrorCodes[Result];                                               " + NL + "  } while (0);" + NL + "  ERROR(GID_";
  protected final String TEXT_51 = ",";
  protected final String TEXT_52 = "_SDMMC001_ERROR,0,0);" + NL + "  FUNCTION_EXIT(GID_";
  protected final String TEXT_53 = ", (uint32_t)";
  protected final String TEXT_54 = "_FUNCTION_EXIT);" + NL + "  return DResult;" + NL + "}" + NL + "" + NL + "/*<<<DD_";
  protected final String TEXT_55 = "_API_4>>>*/" + NL + "/*" + NL + " * The function writes the blocks of data on the disk." + NL + " */" + NL + "DRESULT disk_write" + NL + "(" + NL + "  BYTE Drive," + NL + "  const BYTE*  Buffer," + NL + "  DWORD SectorNumber," + NL + "  BYTE  SectorCount" + NL + ")" + NL + "{" + NL + "  DRESULT DResult;" + NL + "  uint32_t Result;" + NL + "  FUNCTION_ENTRY(GID_";
  protected final String TEXT_56 = ", (uint32_t)";
  protected final String TEXT_57 = "_FUNCTION_ENTRY);" + NL + "  do" + NL + "  {" + NL + "/*<<<DD_";
  protected final String TEXT_58 = "_API_4_1>>>*/" + NL + "    /* If drive number is greater than the maximum drives allowed  */" + NL + "    if (Drive >= ";
  protected final String TEXT_59 = "_MAX_DRIVES)" + NL + "    {" + NL + "      DResult = RES_PARERR;" + NL + "      break;" + NL + "    }" + NL + "/*<<<DD_";
  protected final String TEXT_60 = "_API_4_2>>> */" + NL + "    /* If sector count is less than 1. Minimum 1 sector is needed*/" + NL + "    if (SectorCount < 1)" + NL + "    {" + NL + "      DResult = RES_PARERR;" + NL + "      break;" + NL + "    }" + NL + "/*<<<DD_";
  protected final String TEXT_61 = "_API_4_3>>> */" + NL + "    /* for BufferPtr not aligned */" + NL + "    if (((uint32_t)Buffer % 4UL) != 0UL)" + NL + "    {" + NL + "      DResult = RES_PARERR;" + NL + "      break;" + NL + "    }" + NL + "/*<<<DD_";
  protected final String TEXT_62 = "_API_4_4>>> */" + NL + "    /*Call the WriteBlkPtr function.*/" + NL + "    Result = ";
  protected final String TEXT_63 = "_DeviceFunc[Drive].WriteBlkPtr(Buffer, SectorNumber, SectorCount);" + NL + "/* Fatfs to Block Layer Error Code Mapping */" + NL + "    DResult = ";
  protected final String TEXT_64 = "_ErrorCodes[Result];  " + NL + "  } while (0);" + NL + "  ERROR(GID_";
  protected final String TEXT_65 = ",";
  protected final String TEXT_66 = "_SDMMC002_ERROR,0,0);" + NL + "  FUNCTION_EXIT(GID_";
  protected final String TEXT_67 = ", (uint32_t)";
  protected final String TEXT_68 = "_FUNCTION_EXIT);" + NL + "  return DResult;" + NL + "}" + NL + "" + NL + "/*<<<DD_";
  protected final String TEXT_69 = "_API_5>>>*/" + NL + "/*" + NL + " * The function performs the various IOCTL operation." + NL + " */" + NL + "DRESULT  disk_ioctl(BYTE Drive, BYTE Command, void * Buffer)" + NL + "{" + NL + "  DRESULT DResult;" + NL + "  uint32_t Result;" + NL + "  FUNCTION_ENTRY(GID_";
  protected final String TEXT_70 = ", (uint32_t)";
  protected final String TEXT_71 = "_FUNCTION_ENTRY);" + NL + "  do" + NL + "  {" + NL + "/*<<<DD_";
  protected final String TEXT_72 = "_API_5_1>>>*/" + NL + "    if (Drive >= ";
  protected final String TEXT_73 = "_MAX_DRIVES)" + NL + "    {" + NL + "      DResult = RES_PARERR;" + NL + "      break;" + NL + "    }" + NL + "    /* for BufferPtr not aligned */" + NL + "/*<<<DD_";
  protected final String TEXT_74 = "_API_5_2>>>*/" + NL + "    if (((uint32_t)Buffer % 4UL) != 0UL)" + NL + "    {" + NL + "      DResult = RES_PARERR;" + NL + "      break;" + NL + "    }" + NL + "/*<<<DD_";
  protected final String TEXT_75 = "_API_5_3>>>*/" + NL + "    /*Call the Ioctl function.*/" + NL + "    Result = ";
  protected final String TEXT_76 = "_DeviceFunc[Drive].IoctlPtr(Command, Buffer);" + NL + "/* Fatfs to Block Layer Error Code Mapping */" + NL + "    DResult = ";
  protected final String TEXT_77 = "_ErrorCodes[Result];  " + NL + "  } while (0);" + NL + "  ERROR(GID_";
  protected final String TEXT_78 = ",";
  protected final String TEXT_79 = "_SDMMC002_ERROR,0,0);" + NL + "  FUNCTION_EXIT(GID_";
  protected final String TEXT_80 = ", (uint32_t)";
  protected final String TEXT_81 = "_FUNCTION_EXIT);" + NL + "  return DResult;" + NL + "}" + NL + "" + NL + "/*<<<DD_";
  protected final String TEXT_82 = "_API_6>>> */" + NL + "/**" + NL + " * This is a real time clock service to be called from" + NL + " * FatFs module.This function is not required in read-only cfg" + NL + " */" + NL + "DWORD get_fattime()" + NL + "{" + NL + "  RTC001_TimeHandle Time = {0};  ";
  protected final String TEXT_83 = NL + "  ";
  protected final String TEXT_84 = "_UnusedStatus = RTC001_Clock_GetTime(&Time);" + NL + "/* Pack date and time into a DWORD variable */" + NL + "  return    ((DWORD)(Time.Year - 1980) << 25)" + NL + "      | ((DWORD)Time.Month << 21)" + NL + "      | ((DWORD)Time.Days << 16)" + NL + "      | ((DWORD)Time.Hours << 11)" + NL + "      | ((DWORD)Time.Min << 5)" + NL + "      | ((DWORD)Time.Sec >> 1);" + NL + "}" + NL + "" + NL + "" + NL + "/**" + NL + " * @endcond" + NL + " */" + NL + "/*CODE_BLOCK_END*/" + NL + NL + NL;
  protected final String TEXT_85 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/fatfs004/"; 
     int appInst = 0; 
     int SdmmcFlag = app.getIntegerValue(AppBaseuri + appInst + "/fatfs004_devices_available/0" );
   int UsbFlag = app.getIntegerValue(AppBaseuri + appInst + "/fatfs004_usbdevice_available/0" );
   int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/fatfs004_rtos_present");
   String  Module_Name = "FATFS004";
   String  Sub_Module_Name = "SDMMC001";

    stringBuffer.append(TEXT_2);
     
  if (RTOS == 1)
  {
     Module_Name = "FATFS005";
    Sub_Module_Name = "SDMMC002";
  }
  else
  {
    Module_Name = "FATFS004";
    Sub_Module_Name = "SDMMC001";
  }

    stringBuffer.append(TEXT_3);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_4);
     if ( (SdmmcFlag == 1) && (UsbFlag == 1))
   {
    stringBuffer.append(TEXT_5);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_6);
     } 
   else if((SdmmcFlag == 1) || (UsbFlag  == 1))
   {
    stringBuffer.append(TEXT_7);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_8);
     }
   else
   { 
    stringBuffer.append(TEXT_9);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_10);
     } 
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
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_49);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_50);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_51);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_52);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_53);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_54);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_55);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_56);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_57);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_58);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_59);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_60);
    stringBuffer.append( Module_Name);
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
    stringBuffer.append(TEXT_83);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_84);
    stringBuffer.append(TEXT_85);
    return stringBuffer.toString();
  }
}
