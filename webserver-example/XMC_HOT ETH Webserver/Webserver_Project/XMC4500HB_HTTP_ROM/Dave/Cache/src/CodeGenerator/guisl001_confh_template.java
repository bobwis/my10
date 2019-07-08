package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class guisl001_confh_template
{
  protected static String nl;
  public static synchronized guisl001_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    guisl001_confh_template result = new guisl001_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = " ";
  protected final String TEXT_2 = NL + NL + "/* CODE_BLOCK_BEGIN[GUISL001_Conf.h] */" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers." + NL + " * This file can be freely distributed within development " + NL + " * tools that are supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR" + NL + " * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Dec 11, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL + " ";
  protected final String TEXT_3 = NL + NL;
  protected final String TEXT_4 = NL + NL + "#ifndef ";
  protected final String TEXT_5 = "_CONF_H_" + NL + "#define ";
  protected final String TEXT_6 = "_CONF_H_" + NL + "" + NL + "" + NL + " " + NL + "" + NL + "/**" + NL + " * @file   ";
  protected final String TEXT_7 = "_Conf.h" + NL + " *" + NL + " * @App Version GUISL001 <";
  protected final String TEXT_8 = ">" + NL + " " + NL + " * @brief  This file has the App instance configurations." + NL + " *" + NL + " * Revision History" + NL + " * 19 Jul 2012 v1.0.8 Initial version" + NL + " * 27 Nov 2012 v1.0.10 Version updated" + NL + " * 11 Dec 2012 v1.0.12 Added ";
  protected final String TEXT_9 = " as a prefix to all macros" + NL + " */" + NL + " " + NL + "" + NL + "/**" + NL + " * @ingroup ";
  protected final String TEXT_10 = "_publicparam" + NL + " * @{" + NL + " */" + NL + " " + NL + "/*******************************************************************************" + NL + "**                      Global Macro Definitions                              **" + NL + "*******************************************************************************/ " + NL + "/** RTOS or Non-RTOS environment */";
  protected final String TEXT_11 = NL + "#define ";
  protected final String TEXT_12 = "_RTOS_PRESENT                            1";
  protected final String TEXT_13 = NL + "#define ";
  protected final String TEXT_14 = "_RTOS_PRESENT                            0";
  protected final String TEXT_15 = NL + NL + "/** Mouse Support Enabled/Disabled \t*/";
  protected final String TEXT_16 = NL + "#define ";
  protected final String TEXT_17 = "_SUPPORT_MOUSE \t\t\t\t\t\t  1";
  protected final String TEXT_18 = NL + "#define  ";
  protected final String TEXT_19 = "_SUPPORT_MOUSE                          0   ";
  protected final String TEXT_20 = NL + NL + NL + "/** Windows Manager Supported Enabled/Disabled*/";
  protected final String TEXT_21 = NL + "#define ";
  protected final String TEXT_22 = "_WINSUPPORT                    \t\t  1";
  protected final String TEXT_23 = NL + "#define ";
  protected final String TEXT_24 = "_WINSUPPORT\t\t\t\t\t\t\t  0";
  protected final String TEXT_25 = NL + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "#endif" + NL + "" + NL + "/*CODE_BLOCK_END*/" + NL;
  protected final String TEXT_26 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
    stringBuffer.append(TEXT_1);
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_2);
     String AppBaseuri = "app/guisl001/"; 
     int appInst = 0; 
     String  Module_Name = null; 
     int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/guisl001_rtos_present");
   int MouseSupport = app.getIntegerValue(AppBaseuri + appInst + "/guisl001_erwusbdevices/0");
   int WinSupport = app.getIntegerValue(AppBaseuri + appInst + "/guisl001_erwwinsupport/0");
   Module_Name = "GUISL001";

    stringBuffer.append(TEXT_3);
     
  if (RTOS == 1)
  {
    Module_Name = "GUISL002";
  }
  else
  {
    Module_Name = "GUISL001";
  }

    stringBuffer.append(TEXT_4);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_6);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_7);
    stringBuffer.append(app.getAppVersion(AppBaseuri) );
    stringBuffer.append(TEXT_8);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_9);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_10);
     
if (RTOS == 1)
{
    stringBuffer.append(TEXT_11);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_12);
     }
else
{ 
    stringBuffer.append(TEXT_13);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_14);
     } 
    stringBuffer.append(TEXT_15);
     
if (MouseSupport == 1)
{ 
    stringBuffer.append(TEXT_16);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_17);
     }
else
{ 
    stringBuffer.append(TEXT_18);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_19);
     } 
    stringBuffer.append(TEXT_20);
     
if (WinSupport == 1)
{
    stringBuffer.append(TEXT_21);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_22);
    }
else
{ 
    stringBuffer.append(TEXT_23);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_24);
    }
    stringBuffer.append(TEXT_25);
    stringBuffer.append(TEXT_26);
    return stringBuffer.toString();
  }
}
