package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class spi001_confh_template
{
  protected static String nl;
  public static synchronized spi001_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    spi001_confh_template result = new spi001_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[SPI001_Conf.h]*/" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers.  " + NL + " * This file can be freely distributed within development tools that are " + NL + " * supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, " + NL + " * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "*******************************************************************************" + NL + "**                                                                           **" + NL + "**                                                                           **" + NL + "** PLATFORM : Infineon XMC4000/ XMC1000 Series                               **" + NL + "**                                                                           **" + NL + "** COMPILER : Compiler Independent                                           **" + NL + "**                                                                           **" + NL + "** AUTHOR   : App Developer                                                  **" + NL + "**                                                                           **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                      **" + NL + "**                                                                           **" + NL + "** MODIFICATION DATE : Feb 04, 2013                                          **" + NL + "**                                                                           **" + NL + "******************************************************************************/" + NL + " " + NL + "/******************************************************************************" + NL + "**                       Author(s) Identity                                  **" + NL + "*******************************************************************************" + NL + "**                                                                           **" + NL + "** Initials    Name                                                          **" + NL + "** --------------------------------------------------------------------------**" + NL + "** AEP         DAVE App Developer                                            **" + NL + "******************************************************************************/" + NL + "" + NL + "/**";
  protected final String TEXT_2 = NL + " *" + NL + " * @file   SPI001_Conf.h" + NL + " *" + NL + " * @App Version SPI001 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief  Configuration header file generated based on UI settings " + NL + " *         of SPI001 App" + NL + " *" + NL + " */" + NL + "/*" + NL + " * Revision History" + NL + " * 01 Jun 2012 v1.0.0   Initial version" + NL + " * 26 Jul 2012 v1.0.2   Modified to support Quad mode functionalities" + NL + " * 17 Aug 2012 v1.0.4   Macro correction in USIC.h,Fix for OutputEnable for" + NL + " *                      HW controlled pins " + NL + " * 04 Feb 2013 v1.0.12  1. Coding guidelines and MISRA fixes" + NL + " *                      2. Updated for comments and coding guidelines." + NL + " *                      3. Updatd for revision history alignments." + NL + " *                      4. Updated for XMC1000 devices." + NL + " *                      5. Alignment of the revision history " + NL + " */" + NL + "" + NL + "#ifndef _CONF_SPI001_H_" + NL + "#define _CONF_SPI001_H_" + NL + "" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_4 = NL;
  protected final String TEXT_5 = NL + "/*Base Address of mapped USIC Module for App Instance ";
  protected final String TEXT_6 = " */" + NL + "#define SPI001_";
  protected final String TEXT_7 = "_USIC \t  USIC";
  protected final String TEXT_8 = NL + "/*Base Address of mapped USIC Channel for App Instance ";
  protected final String TEXT_9 = " */" + NL + "#define SPI001_";
  protected final String TEXT_10 = "_USIC_CH  USIC";
  protected final String TEXT_11 = "_CH";
  protected final String TEXT_12 = NL + "/*  CHANNEL IS NOT MAPPED */";
  protected final String TEXT_13 = NL + "extern const SPI001_HandleType SPI001_Handle";
  protected final String TEXT_14 = ";  ";
  protected final String TEXT_15 = NL + "/*  CHANNEL IS NOT MAPPED */";
  protected final String TEXT_16 = NL;
  protected final String TEXT_17 = NL + NL + "#endif /* End of _CONF_SPI001_H_ */" + NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_18 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri1 = "app/SPI001/";
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri1) );
    stringBuffer.append(TEXT_3);
     String AppBaseuri = "app/spi001/";
     String Uarturi = "peripheral/usic/"; 
     String MappedUri = null; 
     String appInst  = null; 
     String UnitInst = null; 
     String ChannelInst = null; 
    stringBuffer.append(TEXT_4);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/spi001/")); 
      for (String appIns : appsList ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri = app.getMappedUri(AppBaseuri + appInst + "/channel"); 
     if((MappedUri != null) && (MappedUri != "")) { 
     UnitInst = MappedUri.substring(MappedUri .length()-11,MappedUri.indexOf("/channel/")); 
     ChannelInst = MappedUri.substring(MappedUri.length()-1); 
    stringBuffer.append(TEXT_5);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_6);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_7);
    stringBuffer.append(UnitInst);
    stringBuffer.append(TEXT_8);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_9);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_10);
    stringBuffer.append( UnitInst );
    stringBuffer.append(TEXT_11);
    stringBuffer.append( ChannelInst );
     } 
     else { 
    stringBuffer.append(TEXT_12);
     } 
    } 
      for (String appIns : appsList ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri = app.getMappedUri(AppBaseuri + appInst + "/channel"); 
     if((MappedUri != null) && (MappedUri != "")) { 
    stringBuffer.append(TEXT_13);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_14);
     } 
     else { 
    stringBuffer.append(TEXT_15);
     } 
    stringBuffer.append(TEXT_16);
    } 
    stringBuffer.append(TEXT_17);
    stringBuffer.append(TEXT_18);
    return stringBuffer.toString();
  }
}
