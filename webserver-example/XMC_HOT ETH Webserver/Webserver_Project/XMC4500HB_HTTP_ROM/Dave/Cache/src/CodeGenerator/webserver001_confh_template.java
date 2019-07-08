package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class webserver001_confh_template
{
  protected static String nl;
  public static synchronized webserver001_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    webserver001_confh_template result = new webserver001_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "/****************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software " + NL + " * for use with Infineon?s microcontrollers.  " + NL + " * This file can be freely distributed within development tools " + NL + " * that are supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR" + NL + " * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + " ******************************************************************************" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : DAVE App Developer                                                **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Dec 29, 2011                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** JRP          DAVE App Developer                                            **" + NL + "********************************************************************************";
  protected final String TEXT_2 = NL + " * @file   WEBSERVER001_Conf.h" + NL + " *" + NL + " * @App Version WEBSERVER001 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief  Configuration file generated based on UI settings " + NL + " *         of WEBSERVER001 App" + NL + " *" + NL + " */ " + NL + " #ifndef WEBSERVER001_H_" + NL + " #define WEBSERVER001_H_" + NL + " " + NL + " #ifndef ENABLE_HTTP" + NL + " #define ENABLE_HTTP                    1" + NL + " #endif " + NL + "" + NL + " #ifndef HTTPD_FAT_FS" + NL + " #define HTTPD_FAT_FS                   1" + NL + " #endif " + NL + " " + NL + " #endif  /* WEBSERVER001_H_ */  " + NL + "/*CODE_BLOCK_END*/" + NL + NL;
  protected final String TEXT_4 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri1 = "app/webserver001/";
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri1) );
    stringBuffer.append(TEXT_3);
    stringBuffer.append(TEXT_4);
    return stringBuffer.toString();
  }
}
