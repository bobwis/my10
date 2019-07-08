package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class rtc001_confh_template
{
  protected static String nl;
  public static synchronized rtc001_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    rtc001_confh_template result = new rtc001_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[RTC001_Conf.h]*/" + NL + "" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with" + NL + " * Infineon?s microcontrollers." + NL + " * This file can be freely distributed within development tools that are" + NL + " * supporting such microcontrollers." + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL," + NL + " * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : $Author: Auto Generated                                           **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "*******************************************************************************/";
  protected final String TEXT_2 = NL + "/*******************************************************************************" + NL + " *" + NL + " * @file RTC001_Conf.h" + NL + " *" + NL + " * @App Version RTC001 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief Handle definitions are based on UI configuration for rtc001 App " + NL + " *        Instances." + NL + "*/" + NL + "" + NL + "#ifndef _CONF_RTC001_H_" + NL + "#define _CONF_RTC001_H_" + NL + "" + NL + "/*****************************************************************************" + NL + " * @Project Includes                                                         *" + NL + " *****************************************************************************/" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_4 = NL + NL + "extern const RTC001_HandleType RTC001_Handle;" + NL + "extern RTC001_TimeHandle timeptr1;";
  protected final String TEXT_5 = NL + "extern RTC001_TimeHandle Alarmptr1;";
  protected final String TEXT_6 = " " + NL;
  protected final String TEXT_7 = NL + "/**" + NL + " * User defined function for Timer interrupt." + NL + " *" + NL + " *" + NL + " * @return     void" + NL + " *" + NL + " * <b>Reentrant: NO </b><BR>" + NL + " *" + NL + " */" + NL + "" + NL + "extern void ";
  protected final String TEXT_8 = "(uint32_t CbArg);";
  protected final String TEXT_9 = NL + " ";
  protected final String TEXT_10 = NL + "/**" + NL + " * User defined function for Alarm interrupt." + NL + " *" + NL + " *" + NL + " * @return     void" + NL + " *" + NL + " * <b>Reentrant: NO </b><BR>" + NL + " *" + NL + " */" + NL + "" + NL + "extern void ";
  protected final String TEXT_11 = "(uint32_t CbArg2);";
  protected final String TEXT_12 = NL + "\t" + NL + "#endif  /* ifndef _CONF_RTC001_H_ */" + NL + "/*CODE_BLOCK_END*/ ";
  protected final String TEXT_13 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/RTC001/0";
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri) );
    stringBuffer.append(TEXT_3);
     int clksel= 0; 
    stringBuffer.append(TEXT_4);
     if (app.getIntegerValue(AppBaseuri + "/RTC001_erwAlarmIntrptEna/0") == 1) { 
    stringBuffer.append(TEXT_5);
     } 
    stringBuffer.append(TEXT_6);
    String EventHandlerTimer = app.getStringValue(AppBaseuri +"/RTC001_srwTimerUserFunction");
  if((EventHandlerTimer != null) && (EventHandlerTimer != "")) { 
    stringBuffer.append(TEXT_7);
    stringBuffer.append(EventHandlerTimer);
    stringBuffer.append(TEXT_8);
     } 
    stringBuffer.append(TEXT_9);
    String EventHandlerAlarm = app.getStringValue(AppBaseuri +"/RTC001_srwAlarmUserFunction");
  if((EventHandlerAlarm != null) && (EventHandlerAlarm != "")) { 
    stringBuffer.append(TEXT_10);
    stringBuffer.append(EventHandlerAlarm);
    stringBuffer.append(TEXT_11);
     } 
    stringBuffer.append(TEXT_12);
    stringBuffer.append(TEXT_13);
    return stringBuffer.toString();
  }
}
