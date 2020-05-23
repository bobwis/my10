package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class fatfs002_confc_template
{
  protected static String nl;
  public static synchronized fatfs002_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    fatfs002_confc_template result = new fatfs002_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/* CODE_BLOCK_BEGIN[FATFS002_Conf.c] */" + NL + "" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without** " + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Oct 1, 2012                                            **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL;
  protected final String TEXT_2 = NL + "/**" + NL + " * @file   FATFS002_Conf.c" + NL + " *" + NL + " * @App Version FATFS002 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief  Configuration file generated based on UI settings " + NL + " *         of FATFS002 App" + NL + " *" + NL + " * Revision History" + NL + " * 22 March 2012  v1.0.0    Initial version" + NL + " * 3 Aug 2012     v1.0.10   Cosmetic Changes." + NL + " * 1 Oct 2012     v1.0.12   Max Logical Drives changed to 4." + NL + " *                           " + NL + " */";
  protected final String TEXT_4 = NL + "/*******************************************************************************" + NL + "**                      INCLUDE FILES                                         **" + NL + "*******************************************************************************/" + NL + "#include \"../../inc/";
  protected final String TEXT_5 = "/ffconf.h\"" + NL + "#include <DAVE3.h>" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Global Variable Definitions                           **" + NL + "*******************************************************************************/" + NL + "" + NL + "#if _FS_REENTRANT" + NL + "/** Create 4 Mutex instances for each volume/logical drives. Only four " + NL + " * primary-partitions can be mounted. Extended partition is not supported." + NL + " */";
  protected final String TEXT_6 = NL;
  protected final String TEXT_7 = "_MutexInfoType ";
  protected final String TEXT_8 = "_MutexInfo[";
  protected final String TEXT_9 = "_MAX_LOGICAL_DRIVES];" + NL + "" + NL + "" + NL + "/* Mutex definations */" + NL + "osMutexDef(Drive0Mutex1);" + NL + "osMutexDef(Drive1Mutex2);" + NL + "osMutexDef(Drive2Mutex3);" + NL + "osMutexDef(Drive3Mutex4);" + NL + "" + NL + "osMutexDef(MutexToProtect);" + NL + "volatile osMutexId ";
  protected final String TEXT_10 = "_MutexProtectId;" + NL + "#endif" + NL + "" + NL + "/*******************************************************************************" + NL + "**                     Public Function Definitions                            **" + NL + "*******************************************************************************/" + NL + "/* This functions creates mutex for the file system. Since Fatfs doesn't supports " + NL + " * extended partition feature, only 4 logical partitions can be created." + NL + " */" + NL + "void ";
  protected final String TEXT_11 = "_Init()" + NL + "{" + NL + "#if _FS_REENTRANT" + NL + " /* Drive0 Mutex 1 */";
  protected final String TEXT_12 = NL + "  ";
  protected final String TEXT_13 = "_MutexInfo[0].MutexId = osMutexCreate (osMutex(Drive0Mutex1));" + NL + "  if (/* !N_DBG*/(NULL ==  ";
  protected final String TEXT_14 = "_MutexInfo[0].MutexId ))" + NL + "  {" + NL + "    ERROR(GID_";
  protected final String TEXT_15 = ", ";
  protected final String TEXT_16 = "_MUTEX_CREATE_FAILED, 0, 0);" + NL + "  }" + NL + "  ";
  protected final String TEXT_17 = NL + "  ";
  protected final String TEXT_18 = "_MutexInfo[1].MutexId = osMutexCreate (osMutex(Drive1Mutex2));" + NL + "  if (/* !N_DBG*/(NULL ==  ";
  protected final String TEXT_19 = "_MutexInfo[1].MutexId ))" + NL + "  {" + NL + "    ERROR(GID_";
  protected final String TEXT_20 = ", ";
  protected final String TEXT_21 = "_MUTEX_CREATE_FAILED, 0, 0);" + NL + "  }" + NL + "  ";
  protected final String TEXT_22 = NL + "  ";
  protected final String TEXT_23 = "_MutexInfo[2].MutexId = osMutexCreate (osMutex(Drive2Mutex3));" + NL + "  if (/* !N_DBG*/(NULL == ";
  protected final String TEXT_24 = "_MutexInfo[2].MutexId ))" + NL + "  {" + NL + "    ERROR(GID_";
  protected final String TEXT_25 = ", ";
  protected final String TEXT_26 = "_MUTEX_CREATE_FAILED, 0, 0);" + NL + "  }";
  protected final String TEXT_27 = NL + "  ";
  protected final String TEXT_28 = "_MutexInfo[3].MutexId = osMutexCreate (osMutex(Drive3Mutex4));" + NL + "  if (/* !N_DBG*/(NULL ==  ";
  protected final String TEXT_29 = "_MutexInfo[3].MutexId ))" + NL + "  {" + NL + "    ERROR(GID_";
  protected final String TEXT_30 = ", ";
  protected final String TEXT_31 = "_MUTEX_CREATE_FAILED, 0, 0);" + NL + "  }" + NL + "  ";
  protected final String TEXT_32 = NL + "  ";
  protected final String TEXT_33 = "_MutexProtectId = osMutexCreate (osMutex(MutexToProtect));" + NL + "  if (/* !N_DBG*/(NULL ==  ";
  protected final String TEXT_34 = "_MutexProtectId ))" + NL + "  {" + NL + "    ERROR(GID_";
  protected final String TEXT_35 = ", ";
  protected final String TEXT_36 = "_MUTEX_CREATE_FAILED, 0, 0);" + NL + "  }" + NL + "#endif" + NL + "}" + NL;
  protected final String TEXT_37 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/fatfs002/"; 
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri) );
    stringBuffer.append(TEXT_3);
     int appInst = 0; 
     int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/fatfs002_fs_reentrant");
   String  Module_Name = "FATFS002";

     
  if (RTOS == 1)
  {
    Module_Name = "FATFS003";
  }
  else
  {
    Module_Name = "FATFS002";
  }

    stringBuffer.append(TEXT_4);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_5);
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
    stringBuffer.append(TEXT_12);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_13);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_14);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_15);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_16);
    stringBuffer.append(TEXT_17);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_18);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_19);
    stringBuffer.append( Module_Name);
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
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_26);
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
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_33);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_34);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_35);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_36);
    stringBuffer.append(TEXT_37);
    return stringBuffer.toString();
  }
}
