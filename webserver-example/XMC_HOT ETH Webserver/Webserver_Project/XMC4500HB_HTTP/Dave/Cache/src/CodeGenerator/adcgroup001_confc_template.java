package CodeGenerator;

import java.util.*;
import java.text.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class adcgroup001_confc_template
{
  protected static String nl;
  public static synchronized adcgroup001_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    adcgroup001_confc_template result = new adcgroup001_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[ADCGROUP001Conf.c]*/" + NL + "" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : DAVE App Developer                                              **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : July 25, 2012                                          **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** CM           DAVE App Developer                                            **" + NL + "*******************************************************************************/";
  protected final String TEXT_2 = NL + "/**" + NL + " * @file  ADCGROUP001_Conf.c" + NL + " * @App Version ADCGROUP001 <";
  protected final String TEXT_3 = ">" + NL + " * @brief This file contains App parameter data as per GUI configurations" + NL + " */" + NL + "" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_4 = NL + NL;
  protected final String TEXT_5 = NL + NL + NL + "ADCGROUP001_DynamicDataType ADCGROUP001_DynamicHandle";
  protected final String TEXT_6 = " =" + NL + "{" + NL + "  .State = ADCGROUP001_UNINITIALIZED" + NL + "};" + NL + "" + NL + "" + NL + "const ADCGROUP001_HandleType ADCGROUP001_Handle";
  protected final String TEXT_7 = " =" + NL + "{" + NL + "  .kGroupNo = (uint8_t)";
  protected final String TEXT_8 = "," + NL + "  .kPostCalibration = (uint8_t)";
  protected final String TEXT_9 = "ADCGROUP001_AUTOPOSTCALIBRATION,";
  protected final String TEXT_10 = "ADCGROUP001_POSTCALIBRATIONDISABLE,";
  protected final String TEXT_11 = NL + "  .kArbitrationMode = (uint8_t)";
  protected final String TEXT_12 = "ADCGROUP001_RUNSPERMANENTLY,";
  protected final String TEXT_13 = "ADCGROUP001_RUNSONREQUEST,";
  protected final String TEXT_14 = NL + "  .kGrpBoundary0 = (uint16_t)";
  protected final String TEXT_15 = ",  " + NL + "  .kGrpBoundary1 = (uint16_t)";
  protected final String TEXT_16 = ", " + NL + "  .kEMUXCodeScheme = (uint8_t)";
  protected final String TEXT_17 = "ADCGROUP001_BINARYCODE,";
  protected final String TEXT_18 = "ADCGROUP001_GRAYCODE,";
  protected final String TEXT_19 = " " + NL + "  .kEMUXStartSelect = (uint8_t)";
  protected final String TEXT_20 = ",";
  protected final String TEXT_21 = "0,";
  protected final String TEXT_22 = NL + "  .kEMUXMode = (uint8_t)";
  protected final String TEXT_23 = "ADCGROUP001_SOFTWARECONTROLMODE,";
  protected final String TEXT_24 = "ADCGROUP001_STEADYMODE,";
  protected final String TEXT_25 = "ADCGROUP001_SINGLESTEPMODE,";
  protected final String TEXT_26 = "ADCGROUP001_SEQUENCEMODE,";
  protected final String TEXT_27 = NL + "  .kAnalogConverterCtrl = (uint8_t)ADCGROUP001_ANALOG_CONVERTER_ON, " + NL + "  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC," + NL + "  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G";
  protected final String TEXT_28 = "," + NL + "  .DynamicHandlePtr= &ADCGROUP001_DynamicHandle";
  protected final String TEXT_29 = "," + NL + "  .kConversionModeClass0 = (uint8_t)";
  protected final String TEXT_30 = "ADCGROUP001_12BIT,";
  protected final String TEXT_31 = "ADCGROUP001_10BIT,";
  protected final String TEXT_32 = "ADCGROUP001_8BIT,";
  protected final String TEXT_33 = "ADCGROUP001_10BITFAST,";
  protected final String TEXT_34 = NL + "  .kConversionModeClass1 = (uint8_t)";
  protected final String TEXT_35 = "ADCGROUP001_12BIT,";
  protected final String TEXT_36 = "ADCGROUP001_10BIT,";
  protected final String TEXT_37 = "ADCGROUP001_8BIT,";
  protected final String TEXT_38 = "ADCGROUP001_10BITFAST,";
  protected final String TEXT_39 = NL + "  .kEMUXConversionModeClass0 = (uint8_t)";
  protected final String TEXT_40 = "ADCGROUP001_12BIT,";
  protected final String TEXT_41 = "ADCGROUP001_10BIT,";
  protected final String TEXT_42 = "ADCGROUP001_8BIT,";
  protected final String TEXT_43 = "ADCGROUP001_10BITFAST,";
  protected final String TEXT_44 = NL + "  .kEMUXConversionModeClass1 = (uint8_t)";
  protected final String TEXT_45 = "ADCGROUP001_12BIT,";
  protected final String TEXT_46 = "ADCGROUP001_10BIT,";
  protected final String TEXT_47 = "ADCGROUP001_8BIT,";
  protected final String TEXT_48 = "ADCGROUP001_10BITFAST,";
  protected final String TEXT_49 = NL + "  .kSampleTimeControlClass0 = (uint8_t)";
  protected final String TEXT_50 = "," + NL + "  .kSampleTimeControlClass1 = (uint8_t)";
  protected final String TEXT_51 = "," + NL + "  .kEMUXSampleTimeControlClass0 = (uint8_t)";
  protected final String TEXT_52 = "," + NL + "  .kEMUXSampleTimeControlClass1 = (uint8_t)";
  protected final String TEXT_53 = NL + " };" + NL;
  protected final String TEXT_54 = NL + "// This app is not mapped to any Group";
  protected final String TEXT_55 = NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_56 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/adcgroup001/"; 
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri));
    stringBuffer.append(TEXT_3);
     String Periuri = "http://www.infineon.com/0.1.31/Peripheral/vadc/"; 
     String appInst  = null; 
     String ConfigUri = null; 
     String kernelUri = null; 
     String kernelNo = null; 
    stringBuffer.append(TEXT_4);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/adcgroup001/"));

for (String appIns : appsList ) {
    appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     ConfigUri = app.getMappedUri(AppBaseuri + appInst +"/adcgroupconfig"); 
     if ((ConfigUri != null) && (ConfigUri.trim() != "")) { 
     kernelUri = ConfigUri.substring(Periuri.length(),ConfigUri.indexOf("/config")); 
     kernelNo = kernelUri.substring(kernelUri.length() -1); 
    stringBuffer.append(TEXT_5);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_6);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_7);
    stringBuffer.append(kernelNo);
    stringBuffer.append(TEXT_8);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwdatapostcalibration/0") == 1){
    stringBuffer.append(TEXT_9);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwdatapostcalibration/0") == 0){
    stringBuffer.append(TEXT_10);
    } 
    stringBuffer.append(TEXT_11);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwdataarbitrationmode/0") == 1){
    stringBuffer.append(TEXT_12);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwdataarbitrationmode/1") == 1){
    stringBuffer.append(TEXT_13);
    } 
    stringBuffer.append(TEXT_14);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/adcgroup001_irwgrpboundary0") );
    stringBuffer.append(TEXT_15);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/adcgroup001_irwgrpboundary1") );
    stringBuffer.append(TEXT_16);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxcodingscheme/0") == 1){
    stringBuffer.append(TEXT_17);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxcodingscheme/1") == 1){
    stringBuffer.append(TEXT_18);
    } 
    stringBuffer.append(TEXT_19);
    if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxmode/0") != 1){
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/adcgroup001_irwemuxset") );
    stringBuffer.append(TEXT_20);
    } else{
    stringBuffer.append(TEXT_21);
    }
    stringBuffer.append(TEXT_22);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxmode/0") == 1){
    stringBuffer.append(TEXT_23);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxmode/1") == 1){
    stringBuffer.append(TEXT_24);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxmode/2") == 1){
    stringBuffer.append(TEXT_25);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxmode/3") == 1){
    stringBuffer.append(TEXT_26);
    } 
    stringBuffer.append(TEXT_27);
    stringBuffer.append( kernelNo);
    stringBuffer.append(TEXT_28);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_29);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwconversionmodeclass0/0") == 1){
    stringBuffer.append(TEXT_30);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwconversionmodeclass0/1") == 1){
    stringBuffer.append(TEXT_31);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwconversionmodeclass0/2") == 1){
    stringBuffer.append(TEXT_32);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwconversionmodeclass0/3") == 1){
    stringBuffer.append(TEXT_33);
    } 
    stringBuffer.append(TEXT_34);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwconversionmodeclass1/0") == 1){
    stringBuffer.append(TEXT_35);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwconversionmodeclass1/1") == 1){
    stringBuffer.append(TEXT_36);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwconversionmodeclass1/2") == 1){
    stringBuffer.append(TEXT_37);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwconversionmodeclass1/3") == 1){
    stringBuffer.append(TEXT_38);
    } 
    stringBuffer.append(TEXT_39);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxconversionmodeclass0/0") == 1){
    stringBuffer.append(TEXT_40);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxconversionmodeclass0/1") == 1){
    stringBuffer.append(TEXT_41);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxconversionmodeclass0/2") == 1){
    stringBuffer.append(TEXT_42);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxconversionmodeclass0/3") == 1){
    stringBuffer.append(TEXT_43);
    } 
    stringBuffer.append(TEXT_44);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxconversionmodeclass1/0") == 1){
    stringBuffer.append(TEXT_45);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxconversionmodeclass1/1") == 1){
    stringBuffer.append(TEXT_46);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxconversionmodeclass1/2") == 1){
    stringBuffer.append(TEXT_47);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcgroup001_erwemuxconversionmodeclass1/3") == 1){
    stringBuffer.append(TEXT_48);
    } 
    stringBuffer.append(TEXT_49);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/adcgroup001_irwactualsampletimecontrolclass0") );
    stringBuffer.append(TEXT_50);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/adcgroup001_irwactualsampletimecontrolclass1") );
    stringBuffer.append(TEXT_51);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/adcgroup001_irwemuxactualsampletimecontrolclass0") );
    stringBuffer.append(TEXT_52);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/adcgroup001_irwemuxactualsampletimecontrolclass1") );
    stringBuffer.append(TEXT_53);
    }
    else {
    stringBuffer.append(TEXT_54);
    }
    }
    stringBuffer.append(TEXT_55);
    stringBuffer.append(TEXT_56);
    return stringBuffer.toString();
  }
}
