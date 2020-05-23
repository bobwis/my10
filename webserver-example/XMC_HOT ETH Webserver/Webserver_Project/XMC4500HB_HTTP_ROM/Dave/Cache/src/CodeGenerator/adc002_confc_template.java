package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class adc002_confc_template
{
  protected static String nl;
  public static synchronized adc002_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    adc002_confc_template result = new adc002_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + NL + "/*CODE_BLOCK_BEGIN[ADC002_Conf.c]*/" + NL + "" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4500 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : DAVE App Developer                                              **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                      **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : July 25, 2012                                          **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** KM           DAVE App Developer                                            **" + NL + "*******************************************************************************/";
  protected final String TEXT_2 = NL + "/**" + NL + " * @file  ADC002_Conf.c" + NL + " * @App Version ADC002 <";
  protected final String TEXT_3 = ">" + NL + " * @brief This file contains App parameter data as per GUI configurations" + NL + " */" + NL + " " + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_4 = NL;
  protected final String TEXT_5 = NL;
  protected final String TEXT_6 = NL + "ADC002_QueueEntryHandleType ADC002_QueueEntryHandle";
  protected final String TEXT_7 = "[8] = {" + NL;
  protected final String TEXT_8 = NL + "  {";
  protected final String TEXT_9 = NL + "    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,";
  protected final String TEXT_10 = NL + "    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,";
  protected final String TEXT_11 = NL + "    .ChannelNumber = (uint8_t)";
  protected final String TEXT_12 = ",  " + NL + "    .Refill = (uint8_t)";
  protected final String TEXT_13 = " ADC002_REFILL_ENABLE ";
  protected final String TEXT_14 = " ADC002_REFILL_DISABLE ";
  protected final String TEXT_15 = ", " + NL + "    .ExternalTrigger = (uint8_t)";
  protected final String TEXT_16 = " ADC002_EXT_TRIGGER_ENABLE ";
  protected final String TEXT_17 = " ADC002_EXT_TRIGGER_DISABLE ";
  protected final String TEXT_18 = ",  " + NL + "    .Interrupt = (uint8_t)";
  protected final String TEXT_19 = " ADC002_INTERRUPT_ENABLE ";
  protected final String TEXT_20 = " ADC002_INTERRUPT_DISABLE ";
  protected final String TEXT_21 = ", " + NL + "  },";
  protected final String TEXT_22 = NL + "};" + NL + "" + NL + "" + NL + "ADC002_DynamicDataType ADC002_DynamicHandle";
  protected final String TEXT_23 = " =" + NL + "{" + NL + "  .State = ADC002_UNINITIALIZED" + NL + "};" + NL + "" + NL + "" + NL + "const ADC002_HandleType ADC002_Handle";
  protected final String TEXT_24 = " =" + NL + "{" + NL + "  .kGroupNo = (uint8_t)";
  protected final String TEXT_25 = "," + NL + "  .kNChannels = (uint8_t)";
  protected final String TEXT_26 = "," + NL + "  .kAsenEnable = (uint8_t)";
  protected final String TEXT_27 = "ADC002_ARBITRATION_SLOT_ENABLE,";
  protected final String TEXT_28 = "ADC002_ARBITRATION_SLOT_DISABLE,";
  protected final String TEXT_29 = NL + "  .kStart = (uint8_t)";
  protected final String TEXT_30 = "ADC002_START_CONV_ENABLE,";
  protected final String TEXT_31 = "ADC002_START_CONV_DISABLE,";
  protected final String TEXT_32 = NL + "  .kPriority = (uint8_t)";
  protected final String TEXT_33 = "ADC002_PRIORITY0,";
  protected final String TEXT_34 = "ADC002_PRIORITY1,";
  protected final String TEXT_35 = "ADC002_PRIORITY2,";
  protected final String TEXT_36 = "ADC002_PRIORITY3,";
  protected final String TEXT_37 = NL + "  .kStartmode = (uint8_t)";
  protected final String TEXT_38 = "ADC002_WAIT_FOR_START,";
  protected final String TEXT_39 = "ADC002_CANCEL_INJECT_REPEAT,";
  protected final String TEXT_40 = "ADC002_CANCEL_INJECT_REPEAT_WITH_CANCEL,";
  protected final String TEXT_41 = NL + "  .kTriggerMode = (uint8_t)";
  protected final String TEXT_42 = "ADC002_NOTRIGGER,";
  protected final String TEXT_43 = "ADC002_TRIGGER_UPON_FALLING_EDGE,";
  protected final String TEXT_44 = "ADC002_TRIGGER_UPON_RISING_EDGE,";
  protected final String TEXT_45 = "ADC002_TRIGGER_UPON_BOTH_EDGE,";
  protected final String TEXT_46 = NL + "  .kTriggerEn = (uint8_t)";
  protected final String TEXT_47 = "1,";
  protected final String TEXT_48 = "0,";
  protected final String TEXT_49 = NL + "  .kGatingMode = (uint8_t)";
  protected final String TEXT_50 = "ADC002_GATING_DISABLED,";
  protected final String TEXT_51 = "ADC002_GATING_ENABLED_ALWAYS,";
  protected final String TEXT_52 = "ADC002_GATING_ENABLED_FOR_HIGH,";
  protected final String TEXT_53 = "ADC002_GATING_ENABLED_FOR_LOW,";
  protected final String TEXT_54 = "     ";
  protected final String TEXT_55 = NL + "  .kChannelA = (uint8_t)";
  protected final String TEXT_56 = ",";
  protected final String TEXT_57 = NL + "  .kChAHandlerPtr = &ADCCH001_Handle";
  protected final String TEXT_58 = ",";
  protected final String TEXT_59 = NL + "  .kChAHandlerPtr = NULL,";
  protected final String TEXT_60 = NL + "  .kChannelA = (uint8_t)8," + NL + "  .kChAHandlerPtr = NULL,";
  protected final String TEXT_61 = NL + "  .kChannelB = (uint8_t)";
  protected final String TEXT_62 = ",";
  protected final String TEXT_63 = NL + "  .kChBHandlerPtr = &ADCCH001_Handle";
  protected final String TEXT_64 = ",";
  protected final String TEXT_65 = NL + "  .kChBHandlerPtr = NULL,";
  protected final String TEXT_66 = NL + "  .kChannelB = (uint8_t)8," + NL + "  .kChBHandlerPtr = NULL,";
  protected final String TEXT_67 = NL + "  .kChannelC = (uint8_t)";
  protected final String TEXT_68 = ",";
  protected final String TEXT_69 = NL + "  .kChCHandlerPtr = &ADCCH001_Handle";
  protected final String TEXT_70 = ",";
  protected final String TEXT_71 = NL + "  .kChCHandlerPtr = NULL,";
  protected final String TEXT_72 = NL + "  .kChannelC = (uint8_t)8," + NL + "  .kChCHandlerPtr = NULL,";
  protected final String TEXT_73 = NL + "  .kChannelD = (uint8_t)";
  protected final String TEXT_74 = ",";
  protected final String TEXT_75 = NL + "  .kChDHandlerPtr = &ADCCH001_Handle";
  protected final String TEXT_76 = ",";
  protected final String TEXT_77 = NL + "  .kChDHandlerPtr = NULL,";
  protected final String TEXT_78 = NL + "  .kChannelD = (uint8_t)8," + NL + "  .kChDHandlerPtr = NULL,";
  protected final String TEXT_79 = NL + "  .kChannelE = (uint8_t)";
  protected final String TEXT_80 = ",";
  protected final String TEXT_81 = NL + "  .kChEHandlerPtr = &ADCCH001_Handle";
  protected final String TEXT_82 = ",";
  protected final String TEXT_83 = NL + "  .kChEHandlerPtr = NULL,";
  protected final String TEXT_84 = NL + "  .kChannelE = (uint8_t)8," + NL + "  .kChEHandlerPtr =  NULL,";
  protected final String TEXT_85 = NL + "  .kChannelF = (uint8_t)";
  protected final String TEXT_86 = ",";
  protected final String TEXT_87 = NL + "  .kChFHandlerPtr = &ADCCH001_Handle";
  protected final String TEXT_88 = ",";
  protected final String TEXT_89 = NL + "  .kChFHandlerPtr = NULL,";
  protected final String TEXT_90 = NL + "  .kChannelF = (uint8_t)8," + NL + "  .kChFHandlerPtr = NULL,";
  protected final String TEXT_91 = NL + "  .kChannelG = (uint8_t)";
  protected final String TEXT_92 = ",";
  protected final String TEXT_93 = NL + "  .kChGHandlerPtr = &ADCCH001_Handle";
  protected final String TEXT_94 = ",";
  protected final String TEXT_95 = NL + "  .kChGHandlerPtr = NULL,";
  protected final String TEXT_96 = NL + "  .kChannelG = (uint8_t)8," + NL + "  .kChGHandlerPtr = NULL,";
  protected final String TEXT_97 = NL + "  .kChannelH = (uint8_t)";
  protected final String TEXT_98 = ",";
  protected final String TEXT_99 = NL + "  .kChHHandlerPtr = &ADCCH001_Handle";
  protected final String TEXT_100 = ",";
  protected final String TEXT_101 = NL + "  .kChHHandlerPtr = NULL,";
  protected final String TEXT_102 = NL + "  .kChannelH = (uint8_t)8," + NL + "  .kChHHandlerPtr = NULL,";
  protected final String TEXT_103 = NL + "  .kSyncChPtr=&ADCSYNC001_Handle";
  protected final String TEXT_104 = "," + NL + "  .kSyncChannelA = (uint8_t)";
  protected final String TEXT_105 = ",";
  protected final String TEXT_106 = NL + "  .kSyncChPtr= NULL," + NL + "  .kSyncChannelA = (uint8_t)8,";
  protected final String TEXT_107 = NL + "  .kSyncChannelB = (uint8_t)";
  protected final String TEXT_108 = ",";
  protected final String TEXT_109 = NL + "  .kSyncChannelB = (uint8_t)8,";
  protected final String TEXT_110 = NL + "  .kSyncChannelC = (uint8_t)";
  protected final String TEXT_111 = ",";
  protected final String TEXT_112 = NL + "  .kSyncChannelC = (uint8_t)8,";
  protected final String TEXT_113 = NL + "  .kSyncChannelD = (uint8_t)";
  protected final String TEXT_114 = ",";
  protected final String TEXT_115 = NL + "  .kSyncChannelD = (uint8_t)8,";
  protected final String TEXT_116 = NL + "  .kSyncChannelE = (uint8_t)";
  protected final String TEXT_117 = ",";
  protected final String TEXT_118 = NL + "  .kSyncChannelE = (uint8_t)8,";
  protected final String TEXT_119 = NL + "  .kSyncChannelF = (uint8_t)";
  protected final String TEXT_120 = ",";
  protected final String TEXT_121 = NL + "  .kSyncChannelF = (uint8_t)8,";
  protected final String TEXT_122 = NL + "  .kSyncChannelG = (uint8_t)";
  protected final String TEXT_123 = ",";
  protected final String TEXT_124 = NL + "  .kSyncChannelG = (uint8_t)8,";
  protected final String TEXT_125 = NL + "  .kSyncChannelH = (uint8_t)";
  protected final String TEXT_126 = ",";
  protected final String TEXT_127 = NL + "  .kSyncChannelH = (uint8_t)8,";
  protected final String TEXT_128 = " " + NL + "  .kActiveChannels = {(uint8_t)";
  protected final String TEXT_129 = ", " + NL + "              (uint8_t)";
  protected final String TEXT_130 = ", " + NL + "              (uint8_t)";
  protected final String TEXT_131 = ", " + NL + "              (uint8_t)";
  protected final String TEXT_132 = ", " + NL + "              (uint8_t)";
  protected final String TEXT_133 = ", " + NL + "              (uint8_t)";
  protected final String TEXT_134 = ", " + NL + "              (uint8_t)";
  protected final String TEXT_135 = ", " + NL + "              (uint8_t)";
  protected final String TEXT_136 = " }," + NL + "  .kQueueEntryHandlePtr =  &ADC002_QueueEntryHandle";
  protected final String TEXT_137 = "[0]," + NL + "  .kGroup_HandlePtr = &ADCGROUP001_Handle";
  protected final String TEXT_138 = "," + NL + "  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC," + NL + "  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G";
  protected final String TEXT_139 = "," + NL + "  .DynamicHandlePtr= &ADC002_DynamicHandle";
  protected final String TEXT_140 = NL + " };" + NL;
  protected final String TEXT_141 = NL + NL + NL + NL;
  protected final String TEXT_142 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/ADC002/"; 
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri));
    stringBuffer.append(TEXT_3);
     String AppBaseuri1 = "app/io002/"; 
     String Periuri = "http://www.infineon.com/0.1.31/Peripheral/vadc/"; 
     String queuexUri = null; 
     String channelxUri = null; 
     String configxUri = null; 
     String groupx = null; 
     String channelx = null; 
     String configx = null; 
     int G = 0; 
     int ChIdx = 0; 
     int QEntry = 0; 
     int QActive = 1; 
     int QChIdx = 1; 
     int activech = 0; 
     int activesy = 0; 
     String kernelNo = null; 
     String appInst  = null; 
     String logchanuri = null;
     String chidxuri = null;
     String ChANum = null;
     String ChBNum = null;
     String ChCNum = null;
     String ChDNum = null;
     String ChENum = null;
     String ChFNum = null;
     String ChGNum = null;
     String ChHNum = null;
     String SyANum = null;
     String SyBNum = null;
     String SyCNum = null;
     String SyDNum = null;
     String SyENum = null;
     String SyFNum = null;
     String SyGNum = null;
     String SyHNum = null;
     String ChAInstance = null;
     String ChBInstance = null;
     String ChCInstance = null;
     String ChDInstance = null;
     String ChEInstance = null;
     String ChFInstance = null;
     String ChGInstance = null;
     String ChHInstance = null;
    stringBuffer.append(TEXT_4);
     String SyAInstance = null;
     String SyBInstance = null;
     String SyCInstance = null;
     String SyDInstance = null;
     String SyEInstance = null;
     String SyFInstance = null;
     String SyGInstance = null;
     String SyHInstance = null;
     String GroupUri  = null; 
     String GroupInst  = null; 
     String SolverCh = null; 
     String SyncInstance = null; 
    stringBuffer.append(TEXT_5);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/ADC002/"));
for (String appIns : appsList ) {
appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     queuexUri  = app.getMappedUri(AppBaseuri + appInst +"/queueri"); 
     if ((queuexUri != null) && (queuexUri.trim() != "")) { 
     kernelNo = queuexUri.substring(Periuri.length(),queuexUri.indexOf("/group/")); 
     groupx = queuexUri.substring(Periuri.length()+8,queuexUri.indexOf("/queue")); 
     }
     GroupUri = app.getMappedUri(AppBaseuri + appInst +"/adcgroupapp"); 
     if ((GroupUri != null) && (GroupUri.trim() != "")) { 
     GroupInst = GroupUri.substring(GroupUri.lastIndexOf("/") + 1);
     }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable") != 1) { 
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 0) { 
     String Ch0AppUri = null;
String Ch0Uri = null;
Ch0AppUri = app.getMappedUri(AppBaseuri + appInst +"/chan_app0");
ChAInstance= Ch0AppUri.substring(Ch0AppUri.lastIndexOf("/")+1);
Ch0Uri = app.getMappedUri(Ch0AppUri +"/adcch");
ChANum = Ch0Uri.substring(Ch0Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 1) { 
     String Ch1AppUri = null;
String Ch1Uri = null; 
Ch1AppUri = app.getMappedUri(AppBaseuri + appInst +"/chan_app1");
ChBInstance= Ch1AppUri.substring(Ch1AppUri.lastIndexOf("/")+1);
Ch1Uri = app.getMappedUri(Ch1AppUri +"/adcch");
ChBNum = Ch1Uri.substring(Ch1Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 2) { 
     String Ch2AppUri = null;
String Ch2Uri = null; 
Ch2AppUri = app.getMappedUri(AppBaseuri + appInst +"/chan_app2");
ChCInstance= Ch2AppUri.substring(Ch2AppUri.lastIndexOf("/")+1);
Ch2Uri = app.getMappedUri(Ch2AppUri +"/adcch");
ChCNum = Ch2Uri.substring(Ch2Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 3) { 
     String Ch3AppUri = null;
String Ch3Uri = null; 
Ch3AppUri = app.getMappedUri(AppBaseuri + appInst +"/chan_app3");
ChDInstance= Ch3AppUri.substring(Ch3AppUri.lastIndexOf("/")+1);
Ch3Uri = app.getMappedUri(Ch3AppUri +"/adcch");
ChDNum = Ch3Uri.substring(Ch3Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 4) { 
     String Ch4AppUri = null;
String Ch4Uri = null; 
Ch4AppUri = app.getMappedUri(AppBaseuri + appInst +"/chan_app4");
ChEInstance= Ch4AppUri.substring(Ch4AppUri.lastIndexOf("/")+1);
Ch4Uri = app.getMappedUri(Ch4AppUri +"/adcch");
ChENum = Ch4Uri.substring(Ch4Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 5) { 
     String Ch5AppUri = null;
String Ch5Uri = null; 
Ch5AppUri = app.getMappedUri(AppBaseuri + appInst +"/chan_app5");
ChFInstance= Ch5AppUri.substring(Ch5AppUri.lastIndexOf("/")+1);
Ch5Uri = app.getMappedUri(Ch5AppUri +"/adcch");
ChFNum = Ch5Uri.substring(Ch5Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 6) { 
     String Ch6AppUri = null;
String Ch6Uri = null; 
Ch6AppUri = app.getMappedUri(AppBaseuri + appInst +"/chan_app6");
ChGInstance= Ch6AppUri.substring(Ch6AppUri.lastIndexOf("/")+1);
Ch6Uri = app.getMappedUri(Ch6AppUri +"/adcch");
ChGNum = Ch6Uri.substring(Ch6Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 7) { 
     String Ch7AppUri = null;
String Ch7Uri = null; 
Ch7AppUri = app.getMappedUri(AppBaseuri + appInst +"/chan_app7");
ChHInstance= Ch7AppUri.substring(Ch7AppUri.lastIndexOf("/")+1);
Ch7Uri = app.getMappedUri(Ch7AppUri +"/adcch");
ChHNum = Ch7Uri.substring(Ch7Uri.lastIndexOf("/")+1);
}
    }else{
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 0) { 
     String Ch0AppUri = null;
String Ch0Uri = null;
Ch0AppUri = app.getMappedUri(AppBaseuri + appInst +"/comp_app0");
Ch0Uri = app.getMappedUri(Ch0AppUri +"/adcch");
ChANum = Ch0Uri.substring(Ch0Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 1) { 
     String Ch1AppUri = null;
String Ch1Uri = null; 
Ch1AppUri = app.getMappedUri(AppBaseuri + appInst +"/comp_app1");
Ch1Uri = app.getMappedUri(Ch1AppUri +"/adcch");
ChBNum = Ch1Uri.substring(Ch1Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 2) { 
     String Ch2AppUri = null;
String Ch2Uri = null; 
Ch2AppUri = app.getMappedUri(AppBaseuri + appInst +"/comp_app2");
Ch2Uri = app.getMappedUri(Ch2AppUri +"/adcch");
ChCNum = Ch2Uri.substring(Ch2Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 3) { 
     String Ch3AppUri = null;
String Ch3Uri = null; 
Ch3AppUri = app.getMappedUri(AppBaseuri + appInst +"/comp_app3");
Ch3Uri = app.getMappedUri(Ch3AppUri +"/adcch");
ChDNum = Ch3Uri.substring(Ch3Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 4) { 
     String Ch4AppUri = null;
String Ch4Uri = null; 
Ch4AppUri = app.getMappedUri(AppBaseuri + appInst +"/comp_app4");
Ch4Uri = app.getMappedUri(Ch4AppUri +"/adcch");
ChENum = Ch4Uri.substring(Ch4Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 5) { 
     String Ch5AppUri = null;
String Ch5Uri = null; 
Ch5AppUri = app.getMappedUri(AppBaseuri + appInst +"/comp_app5");
Ch5Uri = app.getMappedUri(Ch5AppUri +"/adcch");
ChFNum = Ch5Uri.substring(Ch5Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 6) { 
     String Ch6AppUri = null;
String Ch6Uri = null; 
Ch6AppUri = app.getMappedUri(AppBaseuri + appInst +"/comp_app6");
Ch6Uri = app.getMappedUri(Ch6AppUri +"/adcch");
ChGNum = Ch6Uri.substring(Ch6Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 7) { 
     String Ch7AppUri = null;
String Ch7Uri = null; 
Ch7AppUri = app.getMappedUri(AppBaseuri + appInst +"/comp_app7");
Ch7Uri = app.getMappedUri(Ch7AppUri +"/adcch");
ChHNum = Ch7Uri.substring(Ch7Uri.lastIndexOf("/")+1);
}
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 0) { 
     String Sy0AppUri = null;
String Sy0Uri = null;
Sy0AppUri = app.getMappedUri(AppBaseuri + appInst +"/sync_app0");
SyncInstance= Sy0AppUri.substring(Sy0AppUri.lastIndexOf("/")+1);
Sy0Uri = app.getMappedUri(Sy0AppUri +"/msynca");
SyANum = Sy0Uri.substring(Sy0Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 1) { 
     String Sy1AppUri = null;
String Sy1Uri = null; 
Sy1AppUri = app.getMappedUri(AppBaseuri + appInst +"/sync_app0");
Sy1Uri = app.getMappedUri(Sy1AppUri +"/msyncb");
SyBNum = Sy1Uri.substring(Sy1Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 2) { 
     String Sy2AppUri = null;
String Sy2Uri = null; 
Sy2AppUri = app.getMappedUri(AppBaseuri + appInst +"/sync_app0");
Sy2Uri = app.getMappedUri(Sy2AppUri +"/msyncc");
SyCNum = Sy2Uri.substring(Sy2Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 3) { 
     String Sy3AppUri = null;
String Sy3Uri = null; 
Sy3AppUri = app.getMappedUri(AppBaseuri + appInst +"/sync_app0");
Sy3Uri = app.getMappedUri(Sy3AppUri +"/msyncd");
SyDNum = Sy3Uri.substring(Sy3Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 4) { 
     String Sy4AppUri = null;
String Sy4Uri = null; 
Sy4AppUri = app.getMappedUri(AppBaseuri + appInst +"/sync_app0");
Sy4Uri = app.getMappedUri(Sy4AppUri +"/msynce");
SyENum = Sy4Uri.substring(Sy4Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 5) { 
     String Sy5AppUri = null;
String Sy5Uri = null; 
Sy5AppUri = app.getMappedUri(AppBaseuri + appInst +"/sync_app0");
Sy5Uri = app.getMappedUri(Sy5AppUri +"/msyncf");
SyFNum = Sy5Uri.substring(Sy5Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 6) { 
     String Sy6AppUri = null;
String Sy6Uri = null; 
Sy6AppUri = app.getMappedUri(AppBaseuri + appInst +"/sync_app0");
Sy6Uri = app.getMappedUri(Sy6AppUri +"/msyncg");
SyGNum = Sy6Uri.substring(Sy6Uri.lastIndexOf("/")+1);
}
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 7) { 
     String Sy7AppUri = null;
String Sy7Uri = null; 
Sy7AppUri = app.getMappedUri(AppBaseuri + appInst +"/sync_app0");
Sy7Uri = app.getMappedUri(Sy7AppUri +"/msynch");
SyHNum = Sy7Uri.substring(Sy7Uri.lastIndexOf("/")+1);
}
    if(ChANum != null){
    activech = ((1<<Integer.valueOf(ChANum)));
    }
    if(ChBNum != null){
    activech |= ((1<<Integer.valueOf(ChBNum)));
    }
    if(ChCNum != null){
    activech |= ((1<<Integer.valueOf(ChCNum)));
    }
    if(ChDNum != null){
    activech |= ((1<<Integer.valueOf(ChDNum)));
    }
    if(ChENum != null){
    activech |= ((1<<Integer.valueOf(ChENum)));
    }
    if(ChFNum != null){
    activech |= ((1<<Integer.valueOf(ChFNum)));
    }
    if(ChGNum != null){
    activech |= ((1<<Integer.valueOf(ChGNum)));
    }
    if(ChHNum != null){
    activech |= ((1<<Integer.valueOf(ChHNum)));
    }
    if(SyANum != null){
    activesy = ((1<<Integer.valueOf(SyANum)));
    }
    if(SyBNum != null){
    activesy |= ((1<<Integer.valueOf(SyBNum)));
    }
    if(SyCNum != null){
    activesy |= ((1<<Integer.valueOf(SyCNum)));
    }
    if(SyDNum != null){
    activesy |= ((1<<Integer.valueOf(SyDNum)));
    }
    if(SyENum != null){
    activesy |= ((1<<Integer.valueOf(SyENum)));
    }
    if(SyFNum != null){
    activesy |= ((1<<Integer.valueOf(SyFNum)));
    }
    if(SyGNum != null){
    activesy |= ((1<<Integer.valueOf(SyGNum)));
    }
    if(SyHNum != null){
    activesy |= ((1<<Integer.valueOf(SyHNum)));
    }
    activech |= activesy;
    stringBuffer.append(TEXT_6);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_7);
    for(QEntry=0;QEntry<=7;QEntry++){
     if (QActive == 1) { 
    stringBuffer.append(TEXT_8);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/ch" + Integer.toString(0 + (10 * (QEntry+1)))) == 1){
    SolverCh = ChANum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/ch" + Integer.toString(1 + (10 * (QEntry+1)))) == 1){
    SolverCh = ChBNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/ch" + Integer.toString(2 + (10 * (QEntry+1)))) == 1){
    SolverCh = ChCNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/ch" + Integer.toString(3 + (10 * (QEntry+1)))) == 1){
    SolverCh = ChDNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/ch" + Integer.toString(4 + (10 * (QEntry+1)))) == 1){
    SolverCh = ChENum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/ch" + Integer.toString(5 + (10 * (QEntry+1)))) == 1){
    SolverCh = ChFNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/ch" + Integer.toString(6 + (10 * (QEntry+1)))) == 1){
    SolverCh = ChGNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/ch" + Integer.toString(7 + (10 * (QEntry+1)))) == 1){
    SolverCh = ChHNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/sy" + Integer.toString(0 + (10 * (QEntry+1)))) == 1){
    SolverCh = SyANum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/sy" + Integer.toString(1 + (10 * (QEntry+1)))) == 1){
    SolverCh = SyBNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/sy" + Integer.toString(2 + (10 * (QEntry+1)))) == 1){
    SolverCh = SyCNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/sy" + Integer.toString(3 + (10 * (QEntry+1)))) == 1){
    SolverCh = SyDNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/sy" + Integer.toString(4 + (10 * (QEntry+1)))) == 1){
    SolverCh = SyENum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/sy" + Integer.toString(5 + (10 * (QEntry+1)))) == 1){
    SolverCh = SyFNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/sy" + Integer.toString(6 + (10 * (QEntry+1)))) == 1){
    SolverCh = SyGNum;
    }
     else if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/sy" + Integer.toString(7 + (10 * (QEntry+1)))) == 1){
    SolverCh = SyHNum;
    } else{
    SolverCh = Integer.toString(8);
    }
     if ((app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry) + "/" + Integer.toString(QEntry)) == 1) ||
          (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwchannellogical" + Integer.toString(QEntry)) == 0) ||
          (Integer.valueOf(SolverCh) == 8))       
    {
    stringBuffer.append(TEXT_9);
    } else{
    stringBuffer.append(TEXT_10);
    }
    stringBuffer.append(TEXT_11);
    stringBuffer.append(SolverCh);
    stringBuffer.append(TEXT_12);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwrefill" + Integer.toString(QEntry) + "/rf" + Integer.toString(QEntry)) == 1){
    stringBuffer.append(TEXT_13);
    } else{
    stringBuffer.append(TEXT_14);
    }
    stringBuffer.append(TEXT_15);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwextrigger" + Integer.toString(QEntry) + "/et" + Integer.toString(QEntry)) == 1){
    stringBuffer.append(TEXT_16);
    } else{
    stringBuffer.append(TEXT_17);
    }
    stringBuffer.append(TEXT_18);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwintenable" + Integer.toString(QEntry) + "/int" + Integer.toString(QEntry)) == 1){
    stringBuffer.append(TEXT_19);
    } else{
    stringBuffer.append(TEXT_20);
    }
    stringBuffer.append(TEXT_21);
    }
    }
    stringBuffer.append(TEXT_22);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_23);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_24);
    stringBuffer.append(groupx);
    stringBuffer.append(TEXT_25);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/adc002_irwchannelnum") );
    stringBuffer.append(TEXT_26);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwenreqsrc/qenable") == 1){
    stringBuffer.append(TEXT_27);
    }  else {
    stringBuffer.append(TEXT_28);
    } 
    stringBuffer.append(TEXT_29);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwstartconv/strtconv") == 1){
    stringBuffer.append(TEXT_30);
    }  else {
    stringBuffer.append(TEXT_31);
    } 
    stringBuffer.append(TEXT_32);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwadcprio/0") == 1){
    stringBuffer.append(TEXT_33);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwadcprio/1") == 1){
    stringBuffer.append(TEXT_34);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwadcprio/2") == 1){
    stringBuffer.append(TEXT_35);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwadcprio/3") == 1){
    stringBuffer.append(TEXT_36);
    } 
    stringBuffer.append(TEXT_37);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwstartmode/wfsmode") == 1){
    stringBuffer.append(TEXT_38);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwstartmode/cimode") == 1){
    stringBuffer.append(TEXT_39);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwstartmode/cancelmode") == 1){
    stringBuffer.append(TEXT_40);
    }
    stringBuffer.append(TEXT_41);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwtrgmode/0") == 1){
    stringBuffer.append(TEXT_42);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwtrgmode/1") == 1){
    stringBuffer.append(TEXT_43);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwtrgmode/2") == 1){
    stringBuffer.append(TEXT_44);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwtrgmode/3") == 1){
    stringBuffer.append(TEXT_45);
    } 
    stringBuffer.append(TEXT_46);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwtrgmode") > 0){
    stringBuffer.append(TEXT_47);
    } else {
    stringBuffer.append(TEXT_48);
    }
    stringBuffer.append(TEXT_49);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwgatmode/0") == 1){
    stringBuffer.append(TEXT_50);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwgatmode/1") == 1){
    stringBuffer.append(TEXT_51);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwgatmode/2") == 1){
    stringBuffer.append(TEXT_52);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwgatmode/3") == 1){
    stringBuffer.append(TEXT_53);
    } 
    stringBuffer.append(TEXT_54);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 0) { 
    stringBuffer.append(TEXT_55);
    stringBuffer.append(ChANum);
    stringBuffer.append(TEXT_56);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable/0") == 1) { 
    stringBuffer.append(TEXT_57);
    stringBuffer.append(ChAInstance);
    stringBuffer.append(TEXT_58);
    } else{ 
    stringBuffer.append(TEXT_59);
    }
    } else{ 
    stringBuffer.append(TEXT_60);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 1) { 
    stringBuffer.append(TEXT_61);
    stringBuffer.append(ChBNum);
    stringBuffer.append(TEXT_62);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable/0") == 1) { 
    stringBuffer.append(TEXT_63);
    stringBuffer.append(ChBInstance);
    stringBuffer.append(TEXT_64);
    } else{ 
    stringBuffer.append(TEXT_65);
    }
    } else{ 
    stringBuffer.append(TEXT_66);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 2) { 
    stringBuffer.append(TEXT_67);
    stringBuffer.append(ChCNum);
    stringBuffer.append(TEXT_68);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable/0") == 1) { 
    stringBuffer.append(TEXT_69);
    stringBuffer.append(ChCInstance);
    stringBuffer.append(TEXT_70);
    } else{ 
    stringBuffer.append(TEXT_71);
    }
    } else{ 
    stringBuffer.append(TEXT_72);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 3) { 
    stringBuffer.append(TEXT_73);
    stringBuffer.append(ChDNum);
    stringBuffer.append(TEXT_74);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable/0") == 1) { 
    stringBuffer.append(TEXT_75);
    stringBuffer.append(ChDInstance);
    stringBuffer.append(TEXT_76);
    } else{ 
    stringBuffer.append(TEXT_77);
    }
    } else{ 
    stringBuffer.append(TEXT_78);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 4) { 
    stringBuffer.append(TEXT_79);
    stringBuffer.append(ChENum);
    stringBuffer.append(TEXT_80);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable/0") == 1) { 
    stringBuffer.append(TEXT_81);
    stringBuffer.append(ChEInstance);
    stringBuffer.append(TEXT_82);
    } else{ 
    stringBuffer.append(TEXT_83);
    }
    } else{ 
    stringBuffer.append(TEXT_84);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 5) { 
    stringBuffer.append(TEXT_85);
    stringBuffer.append(ChFNum);
    stringBuffer.append(TEXT_86);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable/0") == 1) { 
    stringBuffer.append(TEXT_87);
    stringBuffer.append(ChFInstance);
    stringBuffer.append(TEXT_88);
    } else{ 
    stringBuffer.append(TEXT_89);
    }
    } else{ 
    stringBuffer.append(TEXT_90);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 6) { 
    stringBuffer.append(TEXT_91);
    stringBuffer.append(ChGNum);
    stringBuffer.append(TEXT_92);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable/0") == 1) { 
    stringBuffer.append(TEXT_93);
    stringBuffer.append(ChGInstance);
    stringBuffer.append(TEXT_94);
    } else{ 
    stringBuffer.append(TEXT_95);
    }
    } else{ 
    stringBuffer.append(TEXT_96);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwchannelnum") > 7) { 
    stringBuffer.append(TEXT_97);
    stringBuffer.append(ChHNum);
    stringBuffer.append(TEXT_98);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_erwfastcompenable/0") == 1) { 
    stringBuffer.append(TEXT_99);
    stringBuffer.append(ChHInstance);
    stringBuffer.append(TEXT_100);
    } else{ 
    stringBuffer.append(TEXT_101);
    }
    } else{ 
    stringBuffer.append(TEXT_102);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 0) { 
    stringBuffer.append(TEXT_103);
    stringBuffer.append(SyncInstance);
    stringBuffer.append(TEXT_104);
    stringBuffer.append(SyANum);
    stringBuffer.append(TEXT_105);
    } else{ 
    stringBuffer.append(TEXT_106);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 1) { 
    stringBuffer.append(TEXT_107);
    stringBuffer.append(SyBNum);
    stringBuffer.append(TEXT_108);
    } else{ 
    stringBuffer.append(TEXT_109);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 2) { 
    stringBuffer.append(TEXT_110);
    stringBuffer.append(SyCNum);
    stringBuffer.append(TEXT_111);
    } else{ 
    stringBuffer.append(TEXT_112);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 3) { 
    stringBuffer.append(TEXT_113);
    stringBuffer.append(SyDNum);
    stringBuffer.append(TEXT_114);
    } else{ 
    stringBuffer.append(TEXT_115);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 4) { 
    stringBuffer.append(TEXT_116);
    stringBuffer.append(SyENum);
    stringBuffer.append(TEXT_117);
    } else{ 
    stringBuffer.append(TEXT_118);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 5) { 
    stringBuffer.append(TEXT_119);
    stringBuffer.append(SyFNum);
    stringBuffer.append(TEXT_120);
    } else{ 
    stringBuffer.append(TEXT_121);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 6) { 
    stringBuffer.append(TEXT_122);
    stringBuffer.append(SyGNum);
    stringBuffer.append(TEXT_123);
    } else{ 
    stringBuffer.append(TEXT_124);
    }
     if (app.getIntegerValue(AppBaseuri + appInst + "/adc002_irwsyncnum") > 7) { 
    stringBuffer.append(TEXT_125);
    stringBuffer.append(SyHNum);
    stringBuffer.append(TEXT_126);
    } else{ 
    stringBuffer.append(TEXT_127);
    }
    stringBuffer.append(TEXT_128);
    stringBuffer.append( ((activech >> 0 ) & 1));
    stringBuffer.append(TEXT_129);
    stringBuffer.append( ((activech >> 1 ) & 1));
    stringBuffer.append(TEXT_130);
    stringBuffer.append( ((activech >> 2 ) & 1));
    stringBuffer.append(TEXT_131);
    stringBuffer.append( ((activech >> 3 ) & 1));
    stringBuffer.append(TEXT_132);
    stringBuffer.append( ((activech >> 4 ) & 1));
    stringBuffer.append(TEXT_133);
    stringBuffer.append( ((activech >> 5 ) & 1));
    stringBuffer.append(TEXT_134);
    stringBuffer.append( ((activech >> 6 ) & 1));
    stringBuffer.append(TEXT_135);
    stringBuffer.append( ((activech >> 7 ) & 1));
    stringBuffer.append(TEXT_136);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_137);
    stringBuffer.append(GroupInst);
    stringBuffer.append(TEXT_138);
    stringBuffer.append( groupx);
    stringBuffer.append(TEXT_139);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_140);
    }
    stringBuffer.append(TEXT_141);
    stringBuffer.append(TEXT_142);
    return stringBuffer.toString();
  }
}
