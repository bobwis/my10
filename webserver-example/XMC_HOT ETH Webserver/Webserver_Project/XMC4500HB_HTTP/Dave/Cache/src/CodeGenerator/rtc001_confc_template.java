package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class rtc001_confc_template
{
  protected static String nl;
  public static synchronized rtc001_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    rtc001_confc_template result = new rtc001_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + NL + "/*CODE_BLOCK_BEGIN[RTC001_Conf.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : $Author: Auto Generated                                           **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "*******************************************************************************/";
  protected final String TEXT_2 = NL + "/**" + NL + " ****************************************************************************************" + NL + " *" + NL + " * @file RTC001_Conf.c" + NL + " *" + NL + " * @App Version RTC001 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief Handle definitions based on UI configuration for rtc001 App " + NL + " *        Instances." + NL + "*/" + NL + "" + NL + "/*******************************************************************************" + NL + " ** INCLUDE FILES                                                             **" + NL + " ******************************************************************************/" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_4 = NL + NL + "const RTC001_HandleType RTC001_Handle  = " + NL + "{";
  protected final String TEXT_5 = "\t\t\t\t\t" + NL + "   .SoftwareTimerSel = ";
  protected final String TEXT_6 = ",// Software timer";
  protected final String TEXT_7 = NL + "   .RTCInitOnce =  ";
  protected final String TEXT_8 = "U," + NL + "   .DividerValue = 0x";
  protected final String TEXT_9 = "U,/*DividerValue*/" + NL + "     " + NL + "};" + NL + "" + NL + "/* User Set Calendar Date manually */" + NL + "   RTC001_TimeHandle timeptr1 =" + NL + "  { ";
  protected final String TEXT_10 = NL + "   \t";
  protected final String TEXT_11 = NL + "   " + NL + "  /* User Set Time manually */";
  protected final String TEXT_12 = NL + "  ";
  protected final String TEXT_13 = NL + NL + "    /* Second provided in GUI */" + NL + "    .Sec = ";
  protected final String TEXT_14 = "U," + NL + "    /* Minute provided in GUI */" + NL + "    .Min = ";
  protected final String TEXT_15 = "U,    " + NL + "  \t/* Hour provided in GUI */" + NL + "    .Hours = ";
  protected final String TEXT_16 = "U,    " + NL + "    /* Day provided in GUI */" + NL + "    .Days = ";
  protected final String TEXT_17 = "U," + NL + "    /* Month provided in GUI */" + NL + "    .Month = ";
  protected final String TEXT_18 = "U," + NL + "    /* Year provided in GUI */" + NL + "    .Year = ";
  protected final String TEXT_19 = "U,   " + NL + "  };" + NL + "  ";
  protected final String TEXT_20 = NL + "  /* User Set Alarm Configurations */" + NL + "  /* Alarm Date configuration */" + NL + "  RTC001_TimeHandle Alarmptr1 = " + NL + "  {  ";
  protected final String TEXT_21 = NL + "   \t";
  protected final String TEXT_22 = " " + NL + "  " + NL + "  /* Alarm time configuration */ ";
  protected final String TEXT_23 = NL + "  ";
  protected final String TEXT_24 = NL + "       " + NL + "    /* Alarm seconds provided in GUI */" + NL + "    .Sec = ";
  protected final String TEXT_25 = "U," + NL + "    /* Alarm minutes provided in GUI */" + NL + "    .Min = ";
  protected final String TEXT_26 = "U," + NL + "    /* Alarm hours provided in GUI */" + NL + "    .Hours = ";
  protected final String TEXT_27 = "U," + NL + "    /* Alarm day provided in GUI */" + NL + "    .Days = ";
  protected final String TEXT_28 = "U," + NL + "    /* Alarm month provided in GUI */" + NL + "    .Month = ";
  protected final String TEXT_29 = "U," + NL + "    /* Alarm year provided in GUI */" + NL + "    .Year = ";
  protected final String TEXT_30 = "U," + NL + "    };";
  protected final String TEXT_31 = "    " + NL + " " + NL + "  " + NL + "/*CODE_BLOCK_END*/ ";
  protected final String TEXT_32 = NL;

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
     if ((app.getIntegerValue(AppBaseuri + "/RTC001_erwSoftwareTimer/0") == 1)) {
    stringBuffer.append(TEXT_5);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + "/RTC001_erwSoftwareTimer/0") );
    stringBuffer.append(TEXT_6);
     } else {
    }
    stringBuffer.append(TEXT_7);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + "/RTC001_erwTimeInitialisation/0") );
    stringBuffer.append(TEXT_8);
    stringBuffer.append( app.getHexValue(AppBaseuri + "/rtc/ctr/div") );
    stringBuffer.append(TEXT_9);
    String Date = app.getStringValue(AppBaseuri + "/RTC001_srwDateValue");   
   	String[] SplitDate = Date.split("\\/"); 
    stringBuffer.append(TEXT_10);
    int Datemm  = Integer.parseInt(SplitDate[0]); 
   int Datedd  = Integer.parseInt(SplitDate[1]); 
   int Dateyyyy  = Integer.parseInt(SplitDate[2]); 
    stringBuffer.append(TEXT_11);
     String Time = app.getStringValue(AppBaseuri + "/RTC001_srwTimeValue");   
   	String[] SplitTime = Time.split("\\:"); 
    stringBuffer.append(TEXT_12);
    int Timehh  = Integer.parseInt(SplitTime[0]);
  	int Timemm  = Integer.parseInt(SplitTime[1]);
  	int Timess  = Integer.parseInt(SplitTime[2]); 
    stringBuffer.append(TEXT_13);
    stringBuffer.append(Timess);
    stringBuffer.append(TEXT_14);
    stringBuffer.append(Timemm);
    stringBuffer.append(TEXT_15);
    stringBuffer.append(Timehh);
    stringBuffer.append(TEXT_16);
    stringBuffer.append(Datedd);
    stringBuffer.append(TEXT_17);
    stringBuffer.append(Datemm);
    stringBuffer.append(TEXT_18);
    stringBuffer.append(Dateyyyy);
    stringBuffer.append(TEXT_19);
     if (app.getIntegerValue(AppBaseuri + "/RTC001_erwAlarmIntrptEna/0") == 1) { 
    stringBuffer.append(TEXT_20);
    String AlarmDate = app.getStringValue(AppBaseuri + "/RTC001_srwAlarmDate");   
   	String[] SplitAlarmDate = AlarmDate.split("\\/"); 
    stringBuffer.append(TEXT_21);
    int Alarmmm1  = Integer.parseInt(SplitAlarmDate[0]);  
   int Alarmdd  = Integer.parseInt(SplitAlarmDate[1]); 
   int Alarmyyyy  = Integer.parseInt(SplitAlarmDate[2]); 
    stringBuffer.append(TEXT_22);
     String AlarmTime = app.getStringValue(AppBaseuri + "/RTC001_srwAlarmTime");   
   	String[] SplitAlarmTime = AlarmTime.split("\\:"); 
    stringBuffer.append(TEXT_23);
    int Alarmhh  = Integer.parseInt(SplitAlarmTime[0]);
  	int Alarmmm2  = Integer.parseInt(SplitAlarmTime[1]);
  	int Alarmss  = Integer.parseInt(SplitAlarmTime[2]); 
    stringBuffer.append(TEXT_24);
    stringBuffer.append(Alarmss);
    stringBuffer.append(TEXT_25);
    stringBuffer.append(Alarmmm2);
    stringBuffer.append(TEXT_26);
    stringBuffer.append(Alarmhh);
    stringBuffer.append(TEXT_27);
    stringBuffer.append(Alarmdd);
    stringBuffer.append(TEXT_28);
    stringBuffer.append(Alarmmm1);
    stringBuffer.append(TEXT_29);
    stringBuffer.append(Alarmyyyy);
    stringBuffer.append(TEXT_30);
     } 
    stringBuffer.append(TEXT_31);
    stringBuffer.append(TEXT_32);
    return stringBuffer.toString();
  }
}
