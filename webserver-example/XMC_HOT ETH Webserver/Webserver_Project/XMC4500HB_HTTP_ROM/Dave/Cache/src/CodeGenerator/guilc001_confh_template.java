package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class guilc001_confh_template
{
  protected static String nl;
  public static synchronized guilc001_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    guilc001_confh_template result = new guilc001_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = " ";
  protected final String TEXT_2 = NL + NL + "/* CODE_BLOCK_BEGIN[GUILC001_Conf.h] */" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers." + NL + " * This file can be freely distributed within development " + NL + " * tools that are supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR" + NL + " * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Dec 29, 2011                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL + " ";
  protected final String TEXT_3 = NL + NL + NL + NL + "#ifndef GUILC001_CONF_H_" + NL + "#define GUILC001_CONF_H_" + NL + "" + NL + "" + NL + " " + NL + "" + NL + "/**" + NL + " * @file   GUILC001_Conf.h" + NL + " *" + NL + " * @brief  This file has the App instance configurations." + NL + " *" + NL + " */" + NL + "" + NL + " /**" + NL + " * @ingroup  GUILC001_publicparam" + NL + " * @{" + NL + " */" + NL + "" + NL + "/** Mouse Support Available */";
  protected final String TEXT_4 = NL + "#define GUILC001_MOUSE_SUPPORT                                        1";
  protected final String TEXT_5 = NL + "#define  GUILC001_MOUSE_SUPPORT                                        0   ";
  protected final String TEXT_6 = NL + NL + NL + "/**  Read support in display controller\t*/";
  protected final String TEXT_7 = NL + "#define GUILC001_READ_SUPPORT \t\t\t\t\t\t\t              1";
  protected final String TEXT_8 = NL + "#define  GUILC001_READ_SUPPORT                           \t\t      0   ";
  protected final String TEXT_9 = NL + NL + NL + "/** This sets the cache size to be used by GUI library */" + NL + "#define GUILC001_CACHE_SIZE                    \t\t\t\t\t   ";
  protected final String TEXT_10 = NL + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "#endif /* GUILC001_CONF_H_*/" + NL + "/*CODE_BLOCK_END*/" + NL;
  protected final String TEXT_11 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
    stringBuffer.append(TEXT_1);
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_2);
     String AppBaseuri = "app/guilc001/"; 
     int appInst = 0; 
     
   int ReadSupport = app.getIntegerValue(AppBaseuri + appInst + "/guilc001_erwreaddisplayoption/0");
   int CacheSize = app.getIntegerValue(AppBaseuri + appInst + "/guilc001_erwcachesize");
   int MouseEnable = app.getIntegerValue(AppBaseuri + appInst + "/guilc001_erwcmousesupport");

    stringBuffer.append(TEXT_3);
     
if (MouseEnable == 1)
{ 
    stringBuffer.append(TEXT_4);
     }
else
{ 
    stringBuffer.append(TEXT_5);
     } 
    stringBuffer.append(TEXT_6);
     
if (ReadSupport == 1)
{ 
    stringBuffer.append(TEXT_7);
     }
else
{ 
    stringBuffer.append(TEXT_8);
     } 
    stringBuffer.append(TEXT_9);
    stringBuffer.append(CacheSize );
    stringBuffer.append(TEXT_10);
    stringBuffer.append(TEXT_11);
    return stringBuffer.toString();
  }
}
