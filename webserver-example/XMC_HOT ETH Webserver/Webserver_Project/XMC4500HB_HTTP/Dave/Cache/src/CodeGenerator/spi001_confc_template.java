package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class spi001_confc_template
{
  protected static String nl;
  public static synchronized spi001_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    spi001_confc_template result = new spi001_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[SPI001_Conf.c]*/" + NL + "/******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                **" + NL + " All rights reserved.                                                        **" + NL + "                                                                             **" + NL + " Redistribution and use in source and binary forms, with or without          **" + NL + " modification,are permitted provided that the following conditions are met:  **" + NL + "                                                                             **" + NL + " *Redistributions of source code must retain the above copyright notice,     **" + NL + " this list of conditions and the following disclaimer.                       **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,  **" + NL + " this list of conditions and the following disclaimer in the documentation   **" + NL + " and/or other materials provided with the distribution.                      **" + NL + " *Neither the name of the copyright holders nor the names of its contributors**" + NL + " may be used to endorse or promote products derived from this software       ** " + NL + " without specific prior written permission.                                  **" + NL + "                                                                             **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                 **" + NL + "                                                                             **" + NL + " To improve the quality of the software, users are encouraged to share       **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG      **" + NL + " dave@infineon.com).                                                         **" + NL + "                                                                             **" + NL + "*******************************************************************************" + NL + "**                                                                           **" + NL + "**                                                                           **" + NL + "** PLATFORM : Infineon XMC4000/ XMC1000 Series                               **" + NL + "**                                                                           **" + NL + "** COMPILER : Compiler Independent                                           **" + NL + "**                                                                           **" + NL + "** AUTHOR   : App Developer                                                  **" + NL + "**                                                                           **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                      **" + NL + "**                                                                           **" + NL + "** MODIFICATION DATE : Mar 26, 2013                                          **" + NL + "**                                                                           **" + NL + "******************************************************************************/" + NL + " " + NL + "/******************************************************************************" + NL + "**                       Author(s) Identity                                  **" + NL + "*******************************************************************************" + NL + "**                                                                           **" + NL + "** Initials    Name                                                          **" + NL + "** --------------------------------------------------------------------------**" + NL + "** AEP         DAVE App Developer                                            **" + NL + "******************************************************************************/" + NL + "" + NL + "/**";
  protected final String TEXT_2 = NL + " *" + NL + " * @file   SPI001_Conf.c" + NL + " *" + NL + " * @App Version SPI001 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief  Configuration file generated based on UI settings " + NL + " *         of SPI001 App" + NL + " *" + NL + " */" + NL + "/*" + NL + " * Revision History" + NL + " * 01 Jun 2012 v1.0.0   Initial version" + NL + " * 26 Jul 2012 v1.0.2   Modified to support Quad mode functionalities" + NL + " * 17 Aug 2012 v1.0.4   Macro correction in USIC.h,Fix for OutputEnable for " + NL + " *                      HW controlled pins " + NL + " * 04 Feb 2013 v1.0.12  1. Coding guidelines and MISRA fixes" + NL + " *                      2. Typecasting for the handle parameter for MISRA Checks" + NL + " *                      3. Generation of macros from numbers and the generation" + NL + " *                      of chipselect array modified." + NL + " *                      4. Updated fix for UTP MCSW300000589 - Trigger Limit " + NL + " *                      Receive-Transmit in SPI001 [1.0.4] interchanged." + NL + " *                      5. Updatd for revision history alignments. " + NL + " *                      6. Updated for XMC1000 devices." + NL + " *                      7. Alignment of the revision history  " + NL + " * 26 Mar 2013 v1.0.16  1. Updated for alignment in Revision history." + NL + " */" + NL + "" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_4 = NL + NL + "SPI001_ConfigType SPI001_Config";
  protected final String TEXT_5 = " =" + NL + "{";
  protected final String TEXT_6 = NL + " \t";
  protected final String TEXT_7 = NL + "    " + NL + "   .Mode = ";
  protected final String TEXT_8 = "SPI001_QUAD";
  protected final String TEXT_9 = "SPI001_DUAL";
  protected final String TEXT_10 = "SPI001_STANDARD_HALFDUPLEX";
  protected final String TEXT_11 = "SPI001_STANDARD_FULLDUPLEX";
  protected final String TEXT_12 = ",/* SPI Mode */" + NL + "   .HBMode = ";
  protected final String TEXT_13 = "SPI001_MSB";
  protected final String TEXT_14 = "SPI001_LSB";
  protected final String TEXT_15 = ", /* Transmit LSB/MSB */" + NL + "   .ClkPol =  ";
  protected final String TEXT_16 = "SPI001_CLK_POL1";
  protected final String TEXT_17 = "SPI001_CLK_POL0";
  protected final String TEXT_18 = ", /* Clock Polarity */" + NL + "   .ClkPh =  ";
  protected final String TEXT_19 = "SPI001_CLK_PHASE1";
  protected final String TEXT_20 = "SPI001_CLK_PHASE0";
  protected final String TEXT_21 = ", /* Clock Phase */" + NL + "   .BaudRate = (uint32_t) ";
  protected final String TEXT_22 = ",/* Baud Rate */" + NL + "   .LeadTrailDelay =  ";
  protected final String TEXT_23 = "SPI001_THREE_SCLK_PERIOD";
  protected final String TEXT_24 = "SPI001_TWO_SCLK_PERIOD";
  protected final String TEXT_25 = "SPI001_ONE_SCLK_PERIOD";
  protected final String TEXT_26 = ",/* Leading/TrailingDelay */" + NL + "   .NextFrameDelay = ";
  protected final String TEXT_27 = "SPI001_THREE_SCLK_PERIOD";
  protected final String TEXT_28 = "SPI001_TWO_SCLK_PERIOD";
  protected final String TEXT_29 = "SPI001_ONE_SCLK_PERIOD";
  protected final String TEXT_30 = ",/* NextFrameDelay */" + NL + "   .WordLen = (uint8_t) ";
  protected final String TEXT_31 = ",/* Wordlength */" + NL + "   .FrameLen = (uint8_t) ";
  protected final String TEXT_32 = ",/* Framelength */   " + NL + "   .CESelected = (uint8_t) CE_A /* Default Chip Select line selection */" + NL + "};" + NL + "" + NL + "SPI001_PinHandleType SPI001_PinHandle";
  protected final String TEXT_33 = "  =" + NL + "{ ";
  protected final String TEXT_34 = " ";
  protected final String TEXT_35 = NL + " ";
  protected final String TEXT_36 = " ";
  protected final String TEXT_37 = "  ";
  protected final String TEXT_38 = " ";
  protected final String TEXT_39 = " ";
  protected final String TEXT_40 = " ";
  protected final String TEXT_41 = NL + "   .Port_Num = {(uint8_t) ";
  protected final String TEXT_42 = ", (uint8_t) ";
  protected final String TEXT_43 = ", (uint8_t) ";
  protected final String TEXT_44 = ", (uint8_t) ";
  protected final String TEXT_45 = "}," + NL + "   .Pin_Num  = {(uint8_t) ";
  protected final String TEXT_46 = ", (uint8_t) ";
  protected final String TEXT_47 = ",(uint8_t) ";
  protected final String TEXT_48 = ", (uint8_t) ";
  protected final String TEXT_49 = "}," + NL + "    /* Pin Port Base Address */" + NL + "   .PinPortRegs = {(SPI001_PORTS_TypeDef*)PORT";
  protected final String TEXT_50 = "_BASE, " + NL + "                   (SPI001_PORTS_TypeDef*)PORT";
  protected final String TEXT_51 = "_BASE, " + NL + "                   (SPI001_PORTS_TypeDef*)PORT";
  protected final String TEXT_52 = "_BASE, " + NL + "                   (SPI001_PORTS_TypeDef*)PORT";
  protected final String TEXT_53 = "_BASE" + NL + "                  }," + NL + "   .MRST_DSEL  = (uint8_t) ";
  protected final String TEXT_54 = ", /* DSEL Value */" + NL + "   .MTSR_IOCR  = (uint8_t) ";
  protected final String TEXT_55 = "  /* IOCR_PCR value */   ";
  protected final String TEXT_56 = NL + "};" + NL + "" + NL + "" + NL + "const SPI001_HandleType SPI001_Handle";
  protected final String TEXT_57 = "  = " + NL + "{" + NL + "   .USICRegs = USIC";
  protected final String TEXT_58 = "_CH";
  protected final String TEXT_59 = ", /* Usic Channel offset value */ " + NL + "   .FrmEndMode = ";
  protected final String TEXT_60 = "SPI001_ENABLE_FEM";
  protected final String TEXT_61 = "SPI001_DISABLE_FEM";
  protected final String TEXT_62 = ",/* Frame End mode Selection*/" + NL + "   .Config = &SPI001_Config";
  protected final String TEXT_63 = "," + NL + "   .NoOfCS = (uint8_t) ";
  protected final String TEXT_64 = ", /* No of ChipSelect line */";
  protected final String TEXT_65 = NL + "   .ChipSelTable = {(uint8_t) ";
  protected final String TEXT_66 = "0";
  protected final String TEXT_67 = ", (uint8_t) ";
  protected final String TEXT_68 = "0";
  protected final String TEXT_69 = ", (uint8_t) ";
  protected final String TEXT_70 = "0";
  protected final String TEXT_71 = ", (uint8_t) ";
  protected final String TEXT_72 = "0";
  protected final String TEXT_73 = "," + NL + "                    (uint8_t) ";
  protected final String TEXT_74 = "0";
  protected final String TEXT_75 = ", (uint8_t) ";
  protected final String TEXT_76 = "0";
  protected final String TEXT_77 = ", (uint8_t) ";
  protected final String TEXT_78 = "0";
  protected final String TEXT_79 = ", (uint8_t) ";
  protected final String TEXT_80 = "0";
  protected final String TEXT_81 = NL + "                   }," + NL + "   .TxLimit = (uint8_t) ";
  protected final String TEXT_82 = ",/* FIFO Tigger Level */" + NL + "   .RxLimit = (uint8_t) ";
  protected final String TEXT_83 = ",/* FIFO Tigger Level */" + NL + "   .TxFifoSize = (uint8_t) ";
  protected final String TEXT_84 = ",/* Tx FIFO Size */" + NL + "   .RxFifoSize = (uint8_t) ";
  protected final String TEXT_85 = ",/* Rx FIFO Size */" + NL + "   .MSLSIntrEn = (bool) ";
  protected final String TEXT_86 = ",/* MSLS Event enable */" + NL + "   .PinHandle = &SPI001_PinHandle";
  protected final String TEXT_87 = NL + "};";
  protected final String TEXT_88 = NL + "/* CHANNEL IS NOT MAPPED */";
  protected final String TEXT_89 = NL + NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_90 = NL;

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
     String Baseuri = "app/spi001/";
     String Usicuri = "peripheral/usic/"; 
     String MappedUri = null; 
     String MappedUri2 = null; 
     String UnitInst = null; 
     String ChannelInst = null; 
     String appInst  = null; 
     String CS = null; 
     String CS0 = null; 
     String CS1 = null; 
     String CS2 = null; 
     String CS3 = null; 
     String CS4 = null; 
     String CS5 = null; 
     String CS6 = null; 
     String CS7 = null; 
     int HBmode= 0; 
     int ClkPol= 0; 
     int ClkPhase= 0; 
     int LeadDelay= 0; 
     int NextFrDelay= 0; 
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/spi001/"));
 for (String appIns : appsList ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri = app.getMappedUri(AppBaseuri + appInst + "/channel"); 
     if((MappedUri != null) && (MappedUri != "")) { 
     UnitInst = MappedUri.substring(MappedUri .length()-11,MappedUri.indexOf("/channel/")); 
     ChannelInst = MappedUri.substring(MappedUri.length()-1); 
    stringBuffer.append(TEXT_4);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_5);
      for (int t=0; t< 2; t++) { 
	  int opmode = app.getIntegerValue(AppBaseuri + appInst + "/spi001_erwHBMode/" + t);   
	  if (opmode == 1) {  
	  HBmode = t ;
	} 
    } 
      for (int t=0; t< 2; t++) { 
	  int opmode = app.getIntegerValue(AppBaseuri + appInst + "/spi001_erwClockPolarity/" + t);   
	  if (opmode == 1) {  
	  ClkPol = t ;
	} 
    } 
      for (int t=0; t< 2; t++) { 
	  int opmode = app.getIntegerValue(AppBaseuri + appInst + "/spi001_erwClockPhase/" + t);   
	  if (opmode == 1) {  
	  ClkPhase = t ;
	} 
    } 
    stringBuffer.append(TEXT_6);
      for (int t=0; t< 3; t++) { 
	  int opmode = app.getIntegerValue(AppBaseuri + appInst + "/spi001_erwLeadTrailDelay/" + t);   
	  if (opmode == 1) {  
	  LeadDelay = t ;
	} 
    } 
      for (int t=0; t< 3; t++) { 
	  int opmode = app.getIntegerValue(AppBaseuri + appInst + "/spi001_erwNextFrameDelay/" + t);   
	  if (opmode == 1) {  
	  NextFrDelay = t ;
	} 
    } 
    stringBuffer.append(TEXT_7);
     if (app.getIntegerValue(AppBaseuri + appInst + "/Mode_dummy") == 3){
    stringBuffer.append(TEXT_8);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/Mode_dummy") == 2){
    stringBuffer.append(TEXT_9);
    } else if  (app.getIntegerValue(AppBaseuri + appInst + "/Mode_dummy") == 1){
    stringBuffer.append(TEXT_10);
    } else {
    stringBuffer.append(TEXT_11);
    }
    stringBuffer.append(TEXT_12);
    if (HBmode == 1){
    stringBuffer.append(TEXT_13);
    } else {
    stringBuffer.append(TEXT_14);
    }
    stringBuffer.append(TEXT_15);
    if (app.getIntegerValue(AppBaseuri + appInst + "/spi001_tempclkpolarity") == 1){
    stringBuffer.append(TEXT_16);
    } else {
    stringBuffer.append(TEXT_17);
    } 
    stringBuffer.append(TEXT_18);
    if (ClkPhase == 1){
    stringBuffer.append(TEXT_19);
    } else {
    stringBuffer.append(TEXT_20);
    }
    stringBuffer.append(TEXT_21);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/spi001_irwbaudrate") );
    stringBuffer.append(TEXT_22);
    if (LeadDelay == 2){
    stringBuffer.append(TEXT_23);
    } else if  (LeadDelay == 1){
    stringBuffer.append(TEXT_24);
    } else {
    stringBuffer.append(TEXT_25);
    } 
    stringBuffer.append(TEXT_26);
    if (NextFrDelay == 2){
    stringBuffer.append(TEXT_27);
    } else if  (NextFrDelay == 1){
    stringBuffer.append(TEXT_28);
    } else {
    stringBuffer.append(TEXT_29);
    } 
    stringBuffer.append(TEXT_30);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/channel/sctr/wle") );
    stringBuffer.append(TEXT_31);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/channel/sctr/fle") );
    stringBuffer.append(TEXT_32);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_33);
     String P = "http://www.infineon.com/0.1.28/port/p/"; 
    stringBuffer.append(TEXT_34);
     { int Port0=0;
      int Port1=0;
      int Port2=0;
      int Port3=0;
      int Pin0=0;
      int Pin1=0; 
      int Pin2=0;
      int Pin3=0;
      String portNo=null;
      String pinNo=null;
      String uriPORT=null;
     String pinUri = app.getMappedUri(Baseuri + appInst + "/mtsr0_pin");
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
    stringBuffer.append(TEXT_35);
     pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_36);
     Port0 = Integer.parseInt(portNo); 
     Pin0 = Integer.parseInt(pinNo);   
     uriPORT = "port/p/" + Port0 + "/pad/" + Pin0 + "/iocr_pcr"; 
    } 
    stringBuffer.append(TEXT_37);
     pinUri = app.getMappedUri(Baseuri + appInst + "/mrst0_pin");
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_38);
     Port1 = Integer.parseInt(portNo); 
     Pin1 = Integer.parseInt(pinNo);   
    } 
     if ((pinUri == null) || (pinUri.trim() == "")) { 
     Port1 = 0; 
     Pin1 = 0;  
    } 
     pinUri = app.getMappedUri(Baseuri + appInst + "/mtsr2_hwpin");
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_39);
     Port2 = Integer.parseInt(portNo); 
     Pin2 = Integer.parseInt(pinNo);   
    } 
     if ((pinUri == null) || (pinUri.trim() == "")) { 
     Port2 = 0; 
     Pin2 = 0;  
    } 
     pinUri = app.getMappedUri(Baseuri + appInst + "/mtsr3_hwpin");
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_40);
     Port3 = Integer.parseInt(portNo); 
     Pin3 = Integer.parseInt(pinNo);   
    } 
     if ((pinUri == null) || (pinUri.trim() == "")) { 
     Port3 = 0; 
     Pin3 = 0;  
    } 
    stringBuffer.append(TEXT_41);
    stringBuffer.append(Port0);
    stringBuffer.append(TEXT_42);
    stringBuffer.append(Port1);
    stringBuffer.append(TEXT_43);
    stringBuffer.append(Port2);
    stringBuffer.append(TEXT_44);
    stringBuffer.append(Port3);
    stringBuffer.append(TEXT_45);
    stringBuffer.append(Pin0);
    stringBuffer.append(TEXT_46);
    stringBuffer.append(Pin1);
    stringBuffer.append(TEXT_47);
    stringBuffer.append(Pin2);
    stringBuffer.append(TEXT_48);
    stringBuffer.append(Pin3);
    stringBuffer.append(TEXT_49);
    stringBuffer.append(Port0);
    stringBuffer.append(TEXT_50);
    stringBuffer.append(Port1);
    stringBuffer.append(TEXT_51);
    stringBuffer.append(Port2);
    stringBuffer.append(TEXT_52);
    stringBuffer.append(Port3);
    stringBuffer.append(TEXT_53);
    stringBuffer.append(app.getMuxValue("peripheral/usic/" + UnitInst + "/channel/" + ChannelInst +"/dx0cr_dsel") );
    stringBuffer.append(TEXT_54);
    stringBuffer.append(app.getMuxValue(uriPORT) );
    stringBuffer.append(TEXT_55);
    } 
    stringBuffer.append(TEXT_56);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_57);
    stringBuffer.append( UnitInst );
    stringBuffer.append(TEXT_58);
    stringBuffer.append( ChannelInst );
    stringBuffer.append(TEXT_59);
    if (app.getIntegerValue(AppBaseuri + appInst + "/channel/pcr/ctr3") == 1){
    stringBuffer.append(TEXT_60);
    } else {
    stringBuffer.append(TEXT_61);
    } 
    stringBuffer.append(TEXT_62);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_63);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/spi001_irwSlaveSelect") );
    stringBuffer.append(TEXT_64);
     int NoofCS = app.getIntegerValue(AppBaseuri + appInst +"/spi001_irwSlaveSelect");
      for (int t=0; t< NoofCS; t++) { 
 	 MappedUri2 = app.getMappedUri(AppBaseuri + appInst + "/spi001_selo" + t + "_vs"); 
 	 CS = MappedUri2.substring(MappedUri2.length()-1);
 	 if (t==0){CS0 = CS;} else if (t==1){CS1 = CS;} else if (t==2){CS2 = CS;} else if(t==3){CS3 = CS;} else if(t==4){CS4 = CS;} else if(t==5){CS5 = CS;} else  if(t==6){CS6 = CS;} else if(t==7){CS7 = CS;} else{;} 
    } 
    stringBuffer.append(TEXT_65);
    if(CS0 == null){
    stringBuffer.append(TEXT_66);
    }else{
    stringBuffer.append(Integer.parseInt(CS0));
    }
    stringBuffer.append(TEXT_67);
    if(CS1 == null){
    stringBuffer.append(TEXT_68);
    }else{
    stringBuffer.append(Integer.parseInt(CS1));
    }
    stringBuffer.append(TEXT_69);
    if(CS2 == null){
    stringBuffer.append(TEXT_70);
    }else{
    stringBuffer.append(Integer.parseInt(CS2));
    }
    stringBuffer.append(TEXT_71);
    if(CS3 == null){
    stringBuffer.append(TEXT_72);
    }else{
    stringBuffer.append(Integer.parseInt(CS3));
    }
    stringBuffer.append(TEXT_73);
    if(CS4 == null){
    stringBuffer.append(TEXT_74);
    }else{
    stringBuffer.append(Integer.parseInt(CS4));
    }
    stringBuffer.append(TEXT_75);
    if(CS5 == null){
    stringBuffer.append(TEXT_76);
    }else{
    stringBuffer.append(Integer.parseInt(CS5));
    }
    stringBuffer.append(TEXT_77);
    if(CS6 == null){
    stringBuffer.append(TEXT_78);
    }else{
    stringBuffer.append(Integer.parseInt(CS6));
    }
    stringBuffer.append(TEXT_79);
    if(CS7 == null){
    stringBuffer.append(TEXT_80);
    }else{
    stringBuffer.append(Integer.parseInt(CS7));
    }
    stringBuffer.append(TEXT_81);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/channel/tbctr/limit") );
    stringBuffer.append(TEXT_82);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/channel/rbctr/limit") );
    stringBuffer.append(TEXT_83);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/channel/tbctr_size") );
    stringBuffer.append(TEXT_84);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/channel/rbctr_size") );
    stringBuffer.append(TEXT_85);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + appInst +"/channel/pcr/ctr14") );
    stringBuffer.append(TEXT_86);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_87);
     } 
     else { 
    stringBuffer.append(TEXT_88);
     } 
    } 
    stringBuffer.append(TEXT_89);
    stringBuffer.append(TEXT_90);
    return stringBuffer.toString();
  }
}
