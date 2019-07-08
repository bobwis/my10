package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class adcch001_confc_template
{
  protected static String nl;
  public static synchronized adcch001_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    adcch001_confc_template result = new adcch001_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[ADCCH001_Conf.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4500 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : DAVE App Developer                                              **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE :  31 July 2012                                        **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** PM           DAVE App Developer                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * @file ADCCH001_Conf.c" + NL + " *" + NL + " * @brief This file contains the configuration parameters for all instances of the" + NL + " * ADCCH001 App" + NL + " */" + NL + "" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + "    ";
  protected final String TEXT_4 = " ";
  protected final String TEXT_5 = " ";
  protected final String TEXT_6 = " ";
  protected final String TEXT_7 = " ";
  protected final String TEXT_8 = " ";
  protected final String TEXT_9 = " ";
  protected final String TEXT_10 = " ";
  protected final String TEXT_11 = " ";
  protected final String TEXT_12 = " ";
  protected final String TEXT_13 = " ";
  protected final String TEXT_14 = " ";
  protected final String TEXT_15 = " ";
  protected final String TEXT_16 = " ";
  protected final String TEXT_17 = " ";
  protected final String TEXT_18 = " ";
  protected final String TEXT_19 = " ";
  protected final String TEXT_20 = " ";
  protected final String TEXT_21 = " ";
  protected final String TEXT_22 = " ";
  protected final String TEXT_23 = " ";
  protected final String TEXT_24 = " ";
  protected final String TEXT_25 = " ";
  protected final String TEXT_26 = " ";
  protected final String TEXT_27 = " ";
  protected final String TEXT_28 = " ";
  protected final String TEXT_29 = " ";
  protected final String TEXT_30 = " ";
  protected final String TEXT_31 = " ";
  protected final String TEXT_32 = " ";
  protected final String TEXT_33 = " ";
  protected final String TEXT_34 = " ";
  protected final String TEXT_35 = " ";
  protected final String TEXT_36 = NL;
  protected final String TEXT_37 = NL + NL + NL + "ADCCH001_DynamicHandleType ADCCH001_DynamicHandle";
  protected final String TEXT_38 = " = " + NL + "{" + NL + "  .Result = (uint16_t)0," + NL + "  .FastCompResult = (uint8_t)0," + NL + "  .State = ADCCH001_UNINITIALIZED," + NL + "};" + NL + "" + NL + "const ADCCH001_HandleType ADCCH001_Handle";
  protected final String TEXT_39 = " = " + NL + "{" + NL + "  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G";
  protected final String TEXT_40 = "," + NL + "  .DynamicHandlePtr = &ADCCH001_DynamicHandle";
  protected final String TEXT_41 = " ," + NL + "  .kPrioChannel = (uint8_t)";
  protected final String TEXT_42 = "," + NL + "  .kIpClassSel = ";
  protected final String TEXT_43 = "(uint8_t)ADCCH001_GROUP0";
  protected final String TEXT_44 = " (uint8_t)ADCCH001_GROUP1 ";
  protected final String TEXT_45 = " (uint8_t)ADCCH001_GLOBAL0 ";
  protected final String TEXT_46 = " (uint8_t)ADCCH001_GLOBAL1 ";
  protected final String TEXT_47 = "," + NL + "  .kBoundarySel = (uint8_t)0x";
  protected final String TEXT_48 = "," + NL + "  .kChEvtmode = ";
  protected final String TEXT_49 = "(uint8_t)ADCCH001_DISABLE";
  protected final String TEXT_50 = " (uint8_t)ADCCH001_INSIDE ";
  protected final String TEXT_51 = " (uint8_t)ADCCH001_OUTSIDE ";
  protected final String TEXT_52 = " (uint8_t)ADCCH001_ALWAYS ";
  protected final String TEXT_53 = "," + NL + "  .kRefInput = (uint8_t)";
  protected final String TEXT_54 = " 0 ";
  protected final String TEXT_55 = " 1 ";
  protected final String TEXT_56 = "," + NL + "  .kResultControl = (uint8_t)";
  protected final String TEXT_57 = "," + NL + "  .kDataModification = (uint8_t)0x";
  protected final String TEXT_58 = " ," + NL + "  .kWaitForRead= (uint8_t)";
  protected final String TEXT_59 = "," + NL + "  .kFIFOEnable = (uint8_t)";
  protected final String TEXT_60 = "," + NL + "  .kResultEvtEnable= (uint8_t)";
  protected final String TEXT_61 = ",  " + NL + "  .kBoundaryFlagEnable = (uint8_t)";
  protected final String TEXT_62 = "," + NL + "  .kStartResultRegNo = (uint8_t)";
  protected final String TEXT_63 = "," + NL + "  .kEndResultRegNo = (uint8_t)";
  protected final String TEXT_64 = "," + NL + "  .kExtMuxControl = (uint8_t)";
  protected final String TEXT_65 = "," + NL + "  .kChannelNo = (uint8_t)";
  protected final String TEXT_66 = "," + NL + "  .kCompareMode = (uint8_t)";
  protected final String TEXT_67 = "," + NL + "  .kResultCompVal = (uint16_t)";
  protected final String TEXT_68 = "," + NL + "};" + NL;
  protected final String TEXT_69 = NL + "//Result register is not mapped";
  protected final String TEXT_70 = NL;
  protected final String TEXT_71 = NL + "//ADC Channel is not mapped";
  protected final String TEXT_72 = NL + NL + NL;
  protected final String TEXT_73 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/ADCCH001/"; 
     String Periuri = "http://www.infineon.com/45.0.2/peripheral/vadc/0/group/"; 
     String appInst  = null; 
     String ChannelUri = null; 
     String ChannelNo = null; 
     String GroupNo = null; 
     String StartResultUri = null; 
     String EndResultUri = null; 
     String StartResultNo = null; 
     String EndResultNo = null; 
    stringBuffer.append(TEXT_2);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/ADCCH001/"));
for (String appIns : appsList ) {
  appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     ChannelUri = app.getMappedUri(AppBaseuri + appInst +"/adcch"); 
     if ((ChannelUri != null) && (ChannelUri.trim() != "")) { 
     GroupNo = ChannelUri.substring(Periuri.length(),ChannelUri.indexOf("/ch/")); 
     ChannelNo = ChannelUri.substring(ChannelUri.length() -1); 
    stringBuffer.append(TEXT_3);
     StartResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_a"); 
     if ((StartResultUri != null) && (StartResultUri.trim() != "")) { 
     StartResultNo = StartResultUri.substring(StartResultUri.length() - 2); 
    if(StartResultNo.startsWith("/") == true){
        StartResultNo = StartResultNo.substring(StartResultNo.length() - 1);
       }
    int fifo_no = app.getIntegerValue(AppBaseuri + appInst + "/adcch001_irwfifono");
    if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwfifo/0")) == 0){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_a"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
              }
    stringBuffer.append(TEXT_4);
    }
    stringBuffer.append(TEXT_5);
    }
    else if(fifo_no == 2){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_b"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                 EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
               }
    stringBuffer.append(TEXT_6);
    }
    stringBuffer.append(TEXT_7);
    }
    else if(fifo_no == 3){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_c"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                  EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                }
    stringBuffer.append(TEXT_8);
    }
    stringBuffer.append(TEXT_9);
    }
    else if(fifo_no == 4){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_d"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                   EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                 }
    stringBuffer.append(TEXT_10);
    }
    stringBuffer.append(TEXT_11);
    }
    else if(fifo_no == 5){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_e"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                    EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                  }
    stringBuffer.append(TEXT_12);
    }
    stringBuffer.append(TEXT_13);
    }
    else if(fifo_no == 6){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_f"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                     EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                   }
    stringBuffer.append(TEXT_14);
    }
    stringBuffer.append(TEXT_15);
    }
    else if(fifo_no == 7){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_g"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                      EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                    }
    stringBuffer.append(TEXT_16);
    }
    stringBuffer.append(TEXT_17);
    }
    else if(fifo_no == 8){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_h"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                       EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                     }
    stringBuffer.append(TEXT_18);
    }
    stringBuffer.append(TEXT_19);
    }
    else if(fifo_no == 9){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_i"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                        EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                      }
    stringBuffer.append(TEXT_20);
    }
    stringBuffer.append(TEXT_21);
    }
    else if(fifo_no == 10){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_j"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                         EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                       }
    stringBuffer.append(TEXT_22);
    }
    stringBuffer.append(TEXT_23);
    }
    else if(fifo_no == 11){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_k"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                          EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                        }
    stringBuffer.append(TEXT_24);
    }
    stringBuffer.append(TEXT_25);
    }
    else if(fifo_no == 12){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_l"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                           EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                         }
    stringBuffer.append(TEXT_26);
    }
    stringBuffer.append(TEXT_27);
    }
    else if(fifo_no == 13){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_m"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                            EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                          }
    stringBuffer.append(TEXT_28);
    }
    stringBuffer.append(TEXT_29);
    }
    else if(fifo_no == 14){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_n"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                             EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                           }
    stringBuffer.append(TEXT_30);
    }
    stringBuffer.append(TEXT_31);
    }
    else if(fifo_no == 15){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_o"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                              EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                            }
    stringBuffer.append(TEXT_32);
    }
    stringBuffer.append(TEXT_33);
    }
    else if(fifo_no == 16){
     EndResultUri = app.getMappedUri(AppBaseuri + appInst +"/result_p"); 
     if ((EndResultUri != null) && (EndResultUri.trim() != "")) { 
     EndResultNo = EndResultUri.substring(EndResultUri.length() -2); 
    if(EndResultNo.startsWith("/") == true){
                               EndResultNo = EndResultNo.substring(EndResultNo.length() - 1);
                             }
    stringBuffer.append(TEXT_34);
    }
    stringBuffer.append(TEXT_35);
    }
    stringBuffer.append(TEXT_36);
    
int upper_boundary = 0;
int lower_boundary = 0; 
 if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwubselect/0") == 1))
     {upper_boundary = 0;}
 else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwubselect/1") == 1)) 
    {upper_boundary = 1; }
 else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwubselect/2") == 1)) 
    {upper_boundary = 2; }
 else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwubselect/3") == 1)) 
    {upper_boundary = 3; }
if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwlbselect/0") == 1))
    {lower_boundary = 0;}
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwlbselect/1") == 1)) 
   {lower_boundary = 1; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwlbselect/2") == 1)) 
   {lower_boundary = 2; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwlbselect/3") == 1)) 
   {lower_boundary = 3; }
int boundary = (upper_boundary << 2) |  lower_boundary;

int res_write = 0;
int res_align = 0;
if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwwaitforread/0") == 1))
    {res_write = 0;}
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwwaitforread/1") == 1)) 
   {res_write = 1; }
if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwresultpos/0") == 1))
    {res_align = 0;}
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwresultpos/1") == 1)) 
   {res_align = 1; }

int dmm = 0;
int drctr = 0;
if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/0") == 1))
   {dmm = 0; drctr = 0; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/1") == 1)) 
   {dmm = 0; drctr = 1; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/2") == 1)) 
   {dmm = 0; drctr = 2; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/3") == 1)) 
   {dmm = 0; drctr = 3; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/4") == 1)) 
   {dmm = 2; drctr = 0; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/5") == 1)) 
   {dmm = 1; drctr = 0; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/6") == 1)) 
   {dmm = 1; drctr = 1; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/7") == 1)) 
   {dmm = 1; drctr = 2; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/8") == 1)) 
   {dmm = 1; drctr = 3; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/9") == 1)) 
   {dmm = 1; drctr = 4; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/10") == 1)) 
   {dmm = 1; drctr = 5; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/11") == 1)) 
   {dmm = 1; drctr = 6; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/12") == 1)) 
   {dmm = 1; drctr = 7; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/13") == 1)) 
   {dmm = 1; drctr = 8; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/14") == 1)) 
   {dmm = 1; drctr = 9; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/15") == 1)) 
   {dmm = 1; drctr = 10; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/16") == 1)) 
   {dmm = 1; drctr = 11; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/17") == 1)) 
   {dmm = 1; drctr = 12; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/18") == 1)) 
   {dmm = 1; drctr = 13; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/19") == 1)) 
   {dmm = 1; drctr = 14; }
else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwdatamodf/20") == 1)) 
   {dmm = 1; drctr = 15; }

    stringBuffer.append(TEXT_37);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_38);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_39);
    stringBuffer.append( GroupNo);
    stringBuffer.append(TEXT_40);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_41);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwprioch/0"));
    stringBuffer.append(TEXT_42);
     if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwinputclass/0") == 1)){
    stringBuffer.append(TEXT_43);
    }
    else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwinputclass/1") == 1)) {
    stringBuffer.append(TEXT_44);
    }
    else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwinputclass/2") == 1)) {
    stringBuffer.append(TEXT_45);
    }
    else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwinputclass/3") == 1)) {
    stringBuffer.append(TEXT_46);
    }
    stringBuffer.append(TEXT_47);
    stringBuffer.append( Integer.toHexString(boundary));
    stringBuffer.append(TEXT_48);
     if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwchevtmode/0") == 1)){
    stringBuffer.append(TEXT_49);
    }
      else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwchevtmode/1") == 1)) {
    stringBuffer.append(TEXT_50);
    }
      else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwchevtmode/2") == 1)) {
    stringBuffer.append(TEXT_51);
    }
      else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwchevtmode/3") == 1)) {
    stringBuffer.append(TEXT_52);
    }
    stringBuffer.append(TEXT_53);
     if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwrefinput/0") == 1)){
    stringBuffer.append(TEXT_54);
    }
      else if((app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwrefinput/1") == 1)) {
    stringBuffer.append(TEXT_55);
    }
    stringBuffer.append(TEXT_56);
    stringBuffer.append( res_align);
    stringBuffer.append(TEXT_57);
    stringBuffer.append( Integer.toHexString((dmm << 4) | drctr) );
    stringBuffer.append(TEXT_58);
    stringBuffer.append( res_write);
    stringBuffer.append(TEXT_59);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwfifo/0"));
    stringBuffer.append(TEXT_60);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwenableresevt/0"));
    stringBuffer.append(TEXT_61);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwenableboundaryflag/0"));
    stringBuffer.append(TEXT_62);
    stringBuffer.append(StartResultNo);
    stringBuffer.append(TEXT_63);
    stringBuffer.append(EndResultNo);
    stringBuffer.append(TEXT_64);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwmuxcontrol/0"));
    stringBuffer.append(TEXT_65);
    stringBuffer.append(ChannelNo );
    stringBuffer.append(TEXT_66);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst + "/adcch001_erwcomparator/0"));
    stringBuffer.append(TEXT_67);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst + "/adcch001_irwcompvalue") << 2);
    stringBuffer.append(TEXT_68);
    } else {
    stringBuffer.append(TEXT_69);
    }
    stringBuffer.append(TEXT_70);
    } else {
    stringBuffer.append(TEXT_71);
    }
    }
    stringBuffer.append(TEXT_72);
    stringBuffer.append(TEXT_73);
    return stringBuffer.toString();
  }
}
