package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class sdmmc003_confh_template
{
  protected static String nl;
  public static synchronized sdmmc003_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    sdmmc003_confh_template result = new sdmmc003_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = " ";
  protected final String TEXT_2 = NL + NL + "/* CODE_BLOCK_BEGIN[SDMMC003_Conf.h] */" + NL + "/******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers." + NL + " * This file can be freely distributed within development " + NL + " * tools that are supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR" + NL + " * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Aug 3, 2012                                            **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL + " ";
  protected final String TEXT_3 = NL + NL + "#ifndef ";
  protected final String TEXT_4 = "_CONF_H_" + NL + "#define ";
  protected final String TEXT_5 = "_CONF_H_" + NL + "" + NL + "" + NL + "/**" + NL + " * @file   ";
  protected final String TEXT_6 = "_Conf.h" + NL + " *" + NL + " * @App Version SDMMC003 <";
  protected final String TEXT_7 = ">" + NL + " * " + NL + " * @brief  This file has the App instance configurations." + NL + " *" + NL + " * Revision History" + NL + " * 22 March 2012  v1.0.0    Initial version" + NL + " * 03 Aug 2012    v1.0.12   Cosmetic Changes" + NL + " */" + NL + "" + NL + "/* RTOS or Non-RTOS environment */";
  protected final String TEXT_8 = NL + "#define SDMMC_RTOS_PRESENT                                                    1";
  protected final String TEXT_9 = NL + "#define SDMMC_RTOS_PRESENT                                                 \t  0";
  protected final String TEXT_10 = NL + NL + "/* Card Detection signal supported/not supported  by the kit/board  \t*/";
  protected final String TEXT_11 = NL + "#define SDMMC_CARD_DETECTION_SUPPORT\t\t\t\t\t\t\t \t\t\t                      1";
  protected final String TEXT_12 = NL + "#define SDMMC_CARD_DETECTION_SUPPORT                             \t\t\t        0   ";
  protected final String TEXT_13 = NL + "/* 4-data lines option enabled or disabled */";
  protected final String TEXT_14 = NL + "#define SDMMC_SUPPORT_4_BUS_WIDTH\t\t\t\t\t\t\t\t\t\t\t                        1";
  protected final String TEXT_15 = NL + "#define SDMMC_SUPPORT_4_BUS_WIDTH\t\t\t\t\t\t\t\t\t\t\t                        0";
  protected final String TEXT_16 = NL + NL + "/* MMC card support */" + NL + "#define SDMMC_SUPPORT_MMC_CARD                                                0" + NL + "" + NL + "#define SDMMC_PREEMPTION_PRIORITY                                 ";
  protected final String TEXT_17 = NL + "#define SDMMC_SUB_PRIORITY                                     ";
  protected final String TEXT_18 = NL + NL + "#endif" + NL + "/*CODE_BLOCK_END*/" + NL + NL + NL;
  protected final String TEXT_19 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
    stringBuffer.append(TEXT_1);
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_2);
     String AppBaseuri = "app/sdmmc003/"; 
     int appInst = 0; 
     String  Module_Name = null; 
     int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/sdmmc003_rtos_present");
   int SDCD = app.getIntegerValue(AppBaseuri + appInst + "/sdmmc003_card_detection/0");
   int BusWidth4 = app.getIntegerValue(AppBaseuri + appInst + "/sdmmc003_use_4_data_lines/0");
   int Priority = app.getIntegerValue(AppBaseuri + appInst +"/sdmmc003_irwinterruptpriority");
   int SubPriority = app.getIntegerValue(AppBaseuri + appInst +"/sdmmc003_irwinterruptsubpriority");
   Module_Name = "SDMMC003";

    stringBuffer.append(TEXT_3);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_4);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_6);
    stringBuffer.append(app.getAppVersion(AppBaseuri) );
    stringBuffer.append(TEXT_7);
     
if (RTOS == 1)
{
    stringBuffer.append(TEXT_8);
     }
else
{ 
    stringBuffer.append(TEXT_9);
     } 
    stringBuffer.append(TEXT_10);
     
if ( SDCD == 1)
{ 
    stringBuffer.append(TEXT_11);
     }
else
{ 
    stringBuffer.append(TEXT_12);
     } 
    stringBuffer.append(TEXT_13);
     
if (BusWidth4 == 1)
{
    stringBuffer.append(TEXT_14);
    }
else
{ 
    stringBuffer.append(TEXT_15);
    }
    stringBuffer.append(TEXT_16);
    stringBuffer.append( Priority);
    stringBuffer.append(TEXT_17);
    stringBuffer.append( SubPriority);
    stringBuffer.append(TEXT_18);
    stringBuffer.append(TEXT_19);
    return stringBuffer.toString();
  }
}
