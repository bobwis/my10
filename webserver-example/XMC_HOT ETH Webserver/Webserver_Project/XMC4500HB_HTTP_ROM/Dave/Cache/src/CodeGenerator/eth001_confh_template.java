package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class eth001_confh_template
{
  protected static String nl;
  public static synchronized eth001_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    eth001_confh_template result = new eth001_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "/*CODE_BLOCK_BEGIN[ETH001_Conf.h]*/" + NL + "/* =========================================================================== * " + NL + " * Copyright (c) 2011, Infineon Technologies AG                                *" + NL + " * All rights reserved.                                                        * " + NL + " *                                                                             *" + NL + " * Redistribution and use in source and binary forms, with or without          *" + NL + " * modification, are permitted provided that the following conditions are met: *" + NL + " * Redistributions of source code must retain the above copyright notice, this *" + NL + " * list of conditions and the following disclaimer. Redistributions in binary  *" + NL + " * form must reproduce the above copyright notice, this list of conditions and *" + NL + " * the following disclaimer in the documentation and/or other materials        *" + NL + " * provided with the distribution. Neither the name of the copyright holders   * " + NL + " * nor the names of its contributors may be used to endorse or promote         *" + NL + " * products derived from this software without specific prior written          * " + NL + " * permission.                                                                 *" + NL + " *                                                                             *" + NL + " * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" *" + NL + " * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       *" + NL + " * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      *" + NL + " * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR           *" + NL + " * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       *" + NL + " * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         * " + NL + " * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; *" + NL + " * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    *" + NL + " * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     *" + NL + " * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF      *" + NL + " * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                  *" + NL + " * To improve the quality of the software, users are encouraged to share       *" + NL + " * modifications, enhancements or bug fixes with                               *" + NL + " * Infineon Technologies AG (dave@infineon.com).                               *" + NL + " *                                                                             *" + NL + " * ========================================================================== *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : DAVE App Developer                                                **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Sep 11, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** JRP          DAVE App Developer                                            **" + NL + "********************************************************************************";
  protected final String TEXT_2 = NL + " * @file   ETH001_Conf.h" + NL + " *" + NL + " * @App Version ETH001 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief  Configuration file generated based on UI settings " + NL + " *         of ETH001 App" + NL + " *" + NL + " */" + NL + "/******************************************************************************/" + NL + " #ifndef ETH001_H_" + NL + " #define ETH001_H_" + NL + " " + NL + " #define ENH_DESC_8W" + NL + " #define ENH_DESC";
  protected final String TEXT_4 = "    ";
  protected final String TEXT_5 = NL + " /** For enabling checksum by hardware  */" + NL + " #define CHECKSUM_BY_HARDWARE";
  protected final String TEXT_6 = NL + " /** Interrupt Priority */" + NL + " #define ETH_INTERRUPT_PRIORITY   ";
  protected final String TEXT_7 = NL + "  /** Interrupt Sub-Priority */" + NL + " #define ETH_INTERRUPT_SUB_PRIORITY   ";
  protected final String TEXT_8 = "   ";
  protected final String TEXT_9 = "  " + NL + " /** For selecting Ethernet MAC interface  */  " + NL + " #define ETH_MAC_SEL 1";
  protected final String TEXT_10 = NL + " #define ETH_MAC_SEL 0 ";
  protected final String TEXT_11 = NL + " /** For setting MAC Address manually */";
  protected final String TEXT_12 = NL + " /** This is the IP's PHY address. This is unique address for every MAC in the universe */   \t" + NL + " #define DEFAULT_MAC_ADDRESS {0x";
  protected final String TEXT_13 = ", 0x";
  protected final String TEXT_14 = ", 0x";
  protected final String TEXT_15 = ", 0x";
  protected final String TEXT_16 = ", 0x";
  protected final String TEXT_17 = ", 0x";
  protected final String TEXT_18 = "}  ";
  protected final String TEXT_19 = "    ";
  protected final String TEXT_20 = NL + " /** for enabling multicast filter  */" + NL + " #define ENABLE_MULTICAST";
  protected final String TEXT_21 = " ";
  protected final String TEXT_22 = "    ";
  protected final String TEXT_23 = NL + " /** for enabling promiscuous mode  */" + NL + " #define ENABLE_PROMISCUOUS";
  protected final String TEXT_24 = " " + NL + " #endif /* ETH001_H_ */" + NL + "/*CODE_BLOCK_END*/" + NL + NL;
  protected final String TEXT_25 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri1 = "app/eth001/";
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri1) );
    stringBuffer.append(TEXT_3);
     String AppBaseuri = "app/eth001/0";
     int Chcksum0 = app.getIntegerValue(AppBaseuri + "/eth001_gmacconfiguration/" + 0); 
    stringBuffer.append(TEXT_4);
     if (Chcksum0 == 1)  { 
    stringBuffer.append(TEXT_5);
    } 
    stringBuffer.append(TEXT_6);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  +"/eth001_interrupt_priority/"));
    stringBuffer.append(TEXT_7);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  +"/eth001_interrupt_subpriority/"));
     int Mac = app.getIntegerValue(AppBaseuri + "/eth001_macinterfacesel/" + 0); 
    stringBuffer.append(TEXT_8);
     if (Mac == 1) { 
    stringBuffer.append(TEXT_9);
     } else {
    stringBuffer.append(TEXT_10);
    } 
    stringBuffer.append(TEXT_11);
     String MAC = app.getStringValue(AppBaseuri + "/eth001_macadd");   
   String[] SplitMAC = MAC.split("\\:"); 
    stringBuffer.append(TEXT_12);
    stringBuffer.append(SplitMAC[0]);
    stringBuffer.append(TEXT_13);
    stringBuffer.append(SplitMAC[1]);
    stringBuffer.append(TEXT_14);
    stringBuffer.append(SplitMAC[2]);
    stringBuffer.append(TEXT_15);
    stringBuffer.append(SplitMAC[3]);
    stringBuffer.append(TEXT_16);
    stringBuffer.append(SplitMAC[4]);
    stringBuffer.append(TEXT_17);
    stringBuffer.append(SplitMAC[5]);
    stringBuffer.append(TEXT_18);
     int multicast = app.getIntegerValue(AppBaseuri + "/eth001_multicastfilter/" + 0); 
    stringBuffer.append(TEXT_19);
     if (multicast == 1)  { 
    stringBuffer.append(TEXT_20);
    } 
    stringBuffer.append(TEXT_21);
     int Prmode = app.getIntegerValue(AppBaseuri + "/eth001_promiscuous/" + 0); 
    stringBuffer.append(TEXT_22);
     if (Prmode == 1)  { 
    stringBuffer.append(TEXT_23);
    } 
    stringBuffer.append(TEXT_24);
    stringBuffer.append(TEXT_25);
    return stringBuffer.toString();
  }
}
