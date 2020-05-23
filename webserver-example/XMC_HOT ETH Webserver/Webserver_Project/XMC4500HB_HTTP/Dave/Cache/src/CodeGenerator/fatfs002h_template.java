package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class fatfs002h_template
{
  protected static String nl;
  public static synchronized fatfs002h_template create(String lineSeparator)
  {
    nl = lineSeparator;
    fatfs002h_template result = new fatfs002h_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/* CODE_BLOCK_BEGIN[FATFS002.h]*/" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers. " + NL + " * This file can be freely distributed within development" + NL + " * tools that are supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR" + NL + " * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Oct 1, 2012                                            **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL + " ";
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + NL + "#ifndef ";
  protected final String TEXT_4 = "_H_" + NL + "#define ";
  protected final String TEXT_5 = "_H_" + NL + "" + NL + "/**" + NL + " * @file  ";
  protected final String TEXT_6 = ".h" + NL + " *" + NL + " * @App Version FATFS002 <";
  protected final String TEXT_7 = ">" + NL + " *" + NL + " * @brief This file contains public data structures,enums and function" + NL + " *        prototypes for Fat file system App." + NL + " *" + NL + " * 22 March 2012  v1.0.0    Initial version" + NL + " * 3 Aug 2012     v1.0.10   Cosmetic Changes." + NL + " * 1 Oct 2012     v1.0.12   Max Logical Drives changed to 4." + NL + " */" + NL + "/*******************************************************************************" + NL + "**                      INCLUDE FILES                                         **" + NL + "*******************************************************************************/" + NL + "" + NL + "#include \"../../src/";
  protected final String TEXT_8 = "/Src/ff.h\"" + NL + "#include \"../../Inc/";
  protected final String TEXT_9 = "/integer.h\"" + NL + "#include \"../../Inc/";
  protected final String TEXT_10 = "/diskio.h\"" + NL + "#include \"ffconf.h\"" + NL + "" + NL + "" + NL + "/**" + NL + " * @ingroup ";
  protected final String TEXT_11 = "_publicparam" + NL + " * @{" + NL + " */" + NL + "/*******************************************************************************" + NL + "**                      Global Type Definitions                               **" + NL + "*******************************************************************************/ " + NL + " /**" + NL + "  * Maximum Logical partitions created using the Multi-partition feature" + NL + "  */" + NL + " #define ";
  protected final String TEXT_12 = "_MAX_LOGICAL_DRIVES                                 4" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      ENUMERATIONS                                          **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * This enumerates the FAT file system error codes" + NL + " */" + NL + "typedef enum ";
  protected final String TEXT_13 = "_ErrorCodeType" + NL + "{" + NL + "/**" + NL + " * Mutex creation failed" + NL + " */";
  protected final String TEXT_14 = NL + "  ";
  protected final String TEXT_15 = "_MUTEX_CREATE_FAILED = 1," + NL + "/**" + NL + " * Mutex release failed" + NL + " */  ";
  protected final String TEXT_16 = NL + "  ";
  protected final String TEXT_17 = "_MUTEX_RELEASE_FAILED" + NL + "} ";
  protected final String TEXT_18 = "_ErrorCodeType;" + NL + "" + NL + "" + NL + "#if _FS_REENTRANT" + NL + "/**" + NL + " * This enumerates the Mutex Availability Status. " + NL + " */" + NL + "typedef enum ";
  protected final String TEXT_19 = "_MutexStatusType" + NL + "{" + NL + "  /**" + NL + "   * Mutex is available to use." + NL + "   */";
  protected final String TEXT_20 = NL + "  ";
  protected final String TEXT_21 = "_FREE = 0," + NL + " /**" + NL + "  * Mutex is busy." + NL + "  */";
  protected final String TEXT_22 = NL + "  ";
  protected final String TEXT_23 = "_BUSY " + NL + "} ";
  protected final String TEXT_24 = "_MutexStatusType;" + NL + "" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      STRUCTURES                                          **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * This structure contains the Mutex Information like Mutex Id and the status of" + NL + " * corresponding Mutrex whether it is free or busy." + NL + " */" + NL + "typedef struct ";
  protected final String TEXT_25 = "_MutexInfoType" + NL + "{" + NL + "  /** Stores Mutex ID **/" + NL + "  osMutexId MutexId;" + NL + "  /** Status of the Mutex whether it is free or acquired. **/";
  protected final String TEXT_26 = NL + "  ";
  protected final String TEXT_27 = "_MutexStatusType MutexStatus;" + NL + "} ";
  protected final String TEXT_28 = "_MutexInfoType;" + NL + "" + NL + "#endif" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "/**" + NL + " * @ingroup ";
  protected final String TEXT_29 = "_apidoc" + NL + " * @{" + NL + " */" + NL + "/*******************************************************************************" + NL + "**                       FUNCTION PROTOTYPES                                  **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @brief This function initializes the FAT File System App." + NL + " * @return void <BR>" + NL + " * <b>Reentrant: No </b><BR>" + NL + " * <b>Sync/Async: Synchronous</b>" + NL + " */" + NL + "void ";
  protected final String TEXT_30 = "_Init(void);" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "#endif /* ";
  protected final String TEXT_31 = "_H_ */";
  protected final String TEXT_32 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/fatfs002/"; 
     int appInst = 0; 
     int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_reentrant");
   String  Module_Name = "FATFS002";
   String  Sub_Module = "FATFS005";

    stringBuffer.append(TEXT_2);
     
  if (RTOS == 1)
  {
    Module_Name = "FATFS003";
    Sub_Module  = "FATFS005";
  }
  else
  {
    Module_Name = "FATFS002";
    Sub_Module  = "FATFS004";
  }

    stringBuffer.append(TEXT_3);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_4);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_6);
    stringBuffer.append(app.getAppVersion(AppBaseuri) );
    stringBuffer.append(TEXT_7);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_8);
    stringBuffer.append( Sub_Module);
    stringBuffer.append(TEXT_9);
    stringBuffer.append( Sub_Module);
    stringBuffer.append(TEXT_10);
    stringBuffer.append(Module_Name);
    stringBuffer.append(TEXT_11);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_12);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_13);
    stringBuffer.append(TEXT_14);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_15);
    stringBuffer.append(TEXT_16);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_17);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_18);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_19);
    stringBuffer.append(TEXT_20);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_21);
    stringBuffer.append(TEXT_22);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_23);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_24);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_25);
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
    stringBuffer.append(TEXT_32);
    return stringBuffer.toString();
  }
}
