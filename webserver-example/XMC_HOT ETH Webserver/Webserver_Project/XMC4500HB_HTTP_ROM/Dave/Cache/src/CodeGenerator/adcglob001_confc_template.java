package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class adcglob001_confc_template
{
  protected static String nl;
  public static synchronized adcglob001_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    adcglob001_confc_template result = new adcglob001_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[ADCGLOB001_Conf.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4500 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : DAVE App Developer                                              **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE :  13 july 2012                                        **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** prashana           DAVE App Developer                                      **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * @file ADCGLOBAL001_Conf.c" + NL + " *" + NL + " * @brief This file contains the configuration parameters for all instances of the" + NL + " * ADC GLOBAL App" + NL + " */" + NL + "" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + NL + NL + "ADCGLOB001_DynamicDataType ADCGLOB001_DynamicData";
  protected final String TEXT_4 = " =" + NL + "{" + NL + "  .StateType = ADCGLOB001_UNINITIALIZED" + NL + "};    " + NL + "    " + NL + "        " + NL + "const ADCGLOB001_HandleType ADCGLOB001_Handle";
  protected final String TEXT_5 = " = " + NL + "{" + NL + "  .kGlobalPtr          = (VADC_GLOBAL_TypeDef*)(void*)VADC," + NL + "        " + NL + "  .kDynamicDataPtr      = &ADCGLOB001_DynamicData";
  protected final String TEXT_6 = "," + NL + "      " + NL + "  .KGlobBoundary0        = (uint16_t) ";
  protected final String TEXT_7 = "," + NL + "      " + NL + "  .KGlobBoundary1        = (uint16_t) ";
  protected final String TEXT_8 = "," + NL + "      " + NL + "  .kAnalogClkDivider      = (uint8_t) ";
  protected final String TEXT_9 = "," + NL + "          " + NL + "  .kArbiterClkDivider     = (uint8_t) ";
  protected final String TEXT_10 = "," + NL + "      " + NL + "  .kSampleTimeControlClass0  = (uint8_t) ";
  protected final String TEXT_11 = "," + NL + "            " + NL + "  .kSampleTimeControlClass1   = (uint8_t) ";
  protected final String TEXT_12 = "," + NL + "          " + NL + "  .kEMUXSampleTimeControlClass0= (uint8_t) ";
  protected final String TEXT_13 = "," + NL + "                " + NL + "  .kEMUXSampleTimeControlClass1= (uint8_t) ";
  protected final String TEXT_14 = "," + NL + "           " + NL + "  .kConversionModeClass0    = (uint8_t) ";
  protected final String TEXT_15 = "ADCGLOB001_12BIT,";
  protected final String TEXT_16 = "ADCGLOB001_10BIT,";
  protected final String TEXT_17 = "ADCGLOB001_8BIT,";
  protected final String TEXT_18 = "ADCGLOB001_10BITFAST,";
  protected final String TEXT_19 = NL + "             " + NL + "  .kConversionModeClass1     = (uint8_t) ";
  protected final String TEXT_20 = "ADCGLOB001_12BIT,";
  protected final String TEXT_21 = "ADCGLOB001_10BIT,";
  protected final String TEXT_22 = "ADCGLOB001_8BIT,";
  protected final String TEXT_23 = "ADCGLOB001_10BITFAST,";
  protected final String TEXT_24 = NL + "        " + NL + "  .kEMUXConversionModeClass0   = (uint8_t) ";
  protected final String TEXT_25 = "ADCGLOB001_12BIT,";
  protected final String TEXT_26 = "ADCGLOB001_10BIT,";
  protected final String TEXT_27 = "ADCGLOB001_8BIT,";
  protected final String TEXT_28 = "ADCGLOB001_10BITFAST,";
  protected final String TEXT_29 = NL + "          " + NL + "  .kEMUXConversionModeClass1   = (uint8_t) ";
  protected final String TEXT_30 = "ADCGLOB001_12BIT,";
  protected final String TEXT_31 = "ADCGLOB001_10BIT,";
  protected final String TEXT_32 = "ADCGLOB001_8BIT,";
  protected final String TEXT_33 = "ADCGLOB001_10BITFAST,";
  protected final String TEXT_34 = NL + "          " + NL + "  .keStartCalib           = (uint8_t) ";
  protected final String TEXT_35 = "," + NL + "          " + NL + "  .keDoubleClkMSBConver     = (uint8_t) ";
  protected final String TEXT_36 = NL + " " + NL + "};" + NL + "  ";
  protected final String TEXT_37 = NL + NL + NL;
  protected final String TEXT_38 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/adcglob001/"; 
     String Periuri = "http://www.infineon.com/45.0.2/peripheral/vadc/"; 
     String appInst  = null; 
    stringBuffer.append(TEXT_2);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/adcglob001/"));

for (String appIns : appsList ) {
    appInst = appIns.substring(appIns.lastIndexOf("/")+1);
    stringBuffer.append(TEXT_3);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_4);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( appInst);
    stringBuffer.append(TEXT_6);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_irwglobboundary0"));
    stringBuffer.append(TEXT_7);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_irwglobboundary1"));
    stringBuffer.append(TEXT_8);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_irwanalogclockdivider"));
    stringBuffer.append(TEXT_9);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_irwdigitalclockdivider"));
    stringBuffer.append(TEXT_10);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_irwclass0stcsvalue"));
    stringBuffer.append(TEXT_11);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_irwclass1stcsvalue"));
    stringBuffer.append(TEXT_12);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_irwclass0stcevalue"));
    stringBuffer.append(TEXT_13);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_irwclass1stcevalue"));
    stringBuffer.append(TEXT_14);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwconmodeclass0") == 0){
    stringBuffer.append(TEXT_15);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwconmodeclass0") == 1){
    stringBuffer.append(TEXT_16);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwconmodeclass0") == 2){
    stringBuffer.append(TEXT_17);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwconmodeclass0") == 5){
    stringBuffer.append(TEXT_18);
    } 
    stringBuffer.append(TEXT_19);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwconmodeclass1") == 0){
    stringBuffer.append(TEXT_20);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwconmodeclass1") == 1){
    stringBuffer.append(TEXT_21);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwconmodeclass1") == 2){
    stringBuffer.append(TEXT_22);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwconmodeclass1") == 5){
    stringBuffer.append(TEXT_23);
    } 
    stringBuffer.append(TEXT_24);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwextmuxclass0") == 0){
    stringBuffer.append(TEXT_25);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwextmuxclass0") == 1){
    stringBuffer.append(TEXT_26);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwextmuxclass0") == 2){
    stringBuffer.append(TEXT_27);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwextmuxclass0") == 5){
    stringBuffer.append(TEXT_28);
    } 
    stringBuffer.append(TEXT_29);
     if (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwextmuxclass1") == 0){
    stringBuffer.append(TEXT_30);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwextmuxclass1") == 1){
    stringBuffer.append(TEXT_31);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwextmuxclass1") == 2){
    stringBuffer.append(TEXT_32);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/adcglob001001_erwextmuxclass1") == 5){
    stringBuffer.append(TEXT_33);
    } 
    stringBuffer.append(TEXT_34);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_erwstartupcalibration"));
    stringBuffer.append(TEXT_35);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + appInst + "/adcglob001_erwdblclockmsb"));
    stringBuffer.append(TEXT_36);
    }
    stringBuffer.append(TEXT_37);
    stringBuffer.append(TEXT_38);
    return stringBuffer.toString();
  }
}
