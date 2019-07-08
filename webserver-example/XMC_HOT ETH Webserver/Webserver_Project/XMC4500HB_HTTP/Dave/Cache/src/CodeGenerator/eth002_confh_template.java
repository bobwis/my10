package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class eth002_confh_template
{
  protected static String nl;
  public static synchronized eth002_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    eth002_confh_template result = new eth002_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[ETH002_Conf.h]*/" + NL + " /******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers.  " + NL + " * This file can be freely distributed within development tools that are " + NL + " * supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, " + NL + " * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : DAVE App Developer                                                **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : July 27, 2012                                          **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** RS           DAVE App Developer                                            **" + NL + "********************************************************************************";
  protected final String TEXT_2 = NL + " * @file   ETH002_Conf.h" + NL + " *" + NL + " * @App Version ETH002 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief  Configuration file generated based on UI settings " + NL + " *         of ETH002 App" + NL + " *" + NL + " */ " + NL + " #ifndef ETH002_H_" + NL + " #define ETH002_H_" + NL;
  protected final String TEXT_4 = " " + NL + " /** For enabling Auto Negotiation */" + NL + " #define AUTO_NEGO ";
  protected final String TEXT_5 = " ";
  protected final String TEXT_6 = "   ";
  protected final String TEXT_7 = "     " + NL + " /** For enabling Half Duplex */" + NL + " #define HALF_DUPLEX";
  protected final String TEXT_8 = "     " + NL + " /** For enabling FULL Duplex */" + NL + " #define FULL_DUPLEX";
  protected final String TEXT_9 = "    ";
  protected final String TEXT_10 = "  " + NL + " /** For selecting 100 Mbps  */  " + NL + " #define SPEED_100";
  protected final String TEXT_11 = "  " + NL + " /** For selecting 10 Mbps  */  " + NL + " #define SPEED_10";
  protected final String TEXT_12 = " " + NL + "" + NL + " #endif /* ETH002_H_ */ " + NL + "/*CODE_BLOCK_END*/" + NL;
  protected final String TEXT_13 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri1 = "app/eth002/";
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri1) );
    stringBuffer.append(TEXT_3);
     String AppBaseuri = "app/eth002/0";
     int AutoNego = app.getIntegerValue(AppBaseuri + "/eth002_auto_negotiation/0" ); 
    stringBuffer.append(TEXT_4);
    stringBuffer.append(AutoNego);
    stringBuffer.append(TEXT_5);
     if (AutoNego == 0) { 
     int HalfDuplex = app.getIntegerValue(AppBaseuri + "/eth002_halffullduplex/" + 0); 
    stringBuffer.append(TEXT_6);
     if (HalfDuplex == 1){ 
    stringBuffer.append(TEXT_7);
    }
     if (HalfDuplex == 0){ 
    stringBuffer.append(TEXT_8);
    }
     int Speed100 = app.getIntegerValue(AppBaseuri + "/eth002_linkspeed/" + 1);
    stringBuffer.append(TEXT_9);
    if (Speed100 == 1) { 
    stringBuffer.append(TEXT_10);
    }
    if (Speed100 == 0) { 
    stringBuffer.append(TEXT_11);
    }
    } 
    stringBuffer.append(TEXT_12);
    stringBuffer.append(TEXT_13);
    return stringBuffer.toString();
  }
}
