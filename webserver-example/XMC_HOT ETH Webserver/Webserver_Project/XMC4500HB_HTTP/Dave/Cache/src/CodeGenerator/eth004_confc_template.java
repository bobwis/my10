package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class eth004_confc_template
{
  protected static String nl;
  public static synchronized eth004_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    eth004_confc_template result = new eth004_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[ETH004_Conf.c]*/" + NL + "" + NL + "/* =========================================================================== * " + NL + " * Copyright (c) 2011, Infineon Technologies AG                                *" + NL + " * All rights reserved.                                                        * " + NL + " *                                                                             *" + NL + " * Redistribution and use in source and binary forms, with or without          *" + NL + " * modification, are permitted provided that the following conditions are met: *" + NL + " * Redistributions of source code must retain the above copyright notice, this *" + NL + " * list of conditions and the following disclaimer. Redistributions in binary  *" + NL + " * form must reproduce the above copyright notice, this list of conditions and *" + NL + " * the following disclaimer in the documentation and/or other materials        *" + NL + " * provided with the distribution. Neither the name of the copyright holders   * " + NL + " * nor the names of its contributors may be used to endorse or promote         *" + NL + " * products derived from this software without specific prior written          * " + NL + " * permission.                                                                 *" + NL + " *                                                                             *" + NL + " * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" *" + NL + " * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       *" + NL + " * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      *" + NL + " * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR           *" + NL + " * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       *" + NL + " * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         * " + NL + " * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; *" + NL + " * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    *" + NL + " * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     *" + NL + " * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF      *" + NL + " * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                  *" + NL + " * To improve the quality of the software, users are encouraged to share       *" + NL + " * modifications, enhancements or bug fixes with                               *" + NL + " * Infineon Technologies AG (dave@infineon.com).                               *" + NL + " *                                                                             *" + NL + " ******************************************************************************" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : DAVE App Developer                                                **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Oct 06, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** JRP          DAVE App Developer                                            **" + NL + "********************************************************************************";
  protected final String TEXT_2 = NL + " * @file   ETH004_Conf.c" + NL + " *" + NL + " * @App Version ETH004 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief  Configuration file generated based on UI settings " + NL + " *         of ETH004 App" + NL + " *" + NL + " */ " + NL + " #ifndef ETH004_C_" + NL + " #define ETH004_C_ " + NL + " #include <DAVE3.h> ";
  protected final String TEXT_4 = "   ";
  protected final String TEXT_5 = "  " + NL + " /** For setting IP manually */";
  protected final String TEXT_6 = "   " + NL + "  uint16_t IPpos1 = ";
  protected final String TEXT_7 = ";" + NL + "  uint16_t IPpos2 = ";
  protected final String TEXT_8 = ";" + NL + "  uint16_t IPpos3 = ";
  protected final String TEXT_9 = ";" + NL + "  uint16_t IPpos4 = ";
  protected final String TEXT_10 = ";" + NL + "    " + NL + "  uint16_t Netpos1 = ";
  protected final String TEXT_11 = ";" + NL + "  uint16_t Netpos2 = ";
  protected final String TEXT_12 = ";" + NL + "  uint16_t Netpos3 = ";
  protected final String TEXT_13 = ";" + NL + "  uint16_t Netpos4 = ";
  protected final String TEXT_14 = ";" + NL + "" + NL + "  uint16_t GWpos1 = ";
  protected final String TEXT_15 = ";" + NL + "  uint16_t GWpos2 = ";
  protected final String TEXT_16 = ";" + NL + "  uint16_t GWpos3 = ";
  protected final String TEXT_17 = ";" + NL + "  uint16_t GWpos4 = ";
  protected final String TEXT_18 = "; ";
  protected final String TEXT_19 = " \t" + NL + " " + NL + " #endif /* ETH004_C_ */  " + NL + "/*CODE_BLOCK_END*/" + NL;
  protected final String TEXT_20 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri1 = "app/eth004/";
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri1) );
    stringBuffer.append(TEXT_3);
     String AppBaseuri = "app/eth004/0";
     int LWIP_DHCP = app.getIntegerValue(AppBaseuri + "/eth004_ipconfig/" + 0); 
    stringBuffer.append(TEXT_4);
     if (LWIP_DHCP == 0) { 
    stringBuffer.append(TEXT_5);
     String IP = app.getStringValue(AppBaseuri + "/eth004_ip");   
  String[] SplitIP = IP.split("\\.");
  int IPpos1  = Integer.parseInt(SplitIP[0]);
  	int IPpos2  = Integer.parseInt(SplitIP[1]);
  	int IPpos3  = Integer.parseInt(SplitIP[2]);
  	int IPpos4  = Integer.parseInt(SplitIP[3]);  
 	String NetMask = app.getStringValue(AppBaseuri + "/eth004_netmask");  
 	String SplitNet[] = NetMask.split("\\.");
 	int Netpos1 = Integer.parseInt(SplitNet[0]); 
   	int Netpos2 = Integer.parseInt(SplitNet[1]);  
  	int Netpos3 = Integer.parseInt(SplitNet[2]); 
   	int Netpos4 = Integer.parseInt(SplitNet[3]);   
   	String Gateway = app.getStringValue(AppBaseuri + "/eth004_gateway");   
   	String SplitGW[] = Gateway.split("\\.");  
   	int GWpos1 = Integer.parseInt(SplitGW[0]);  
   	int GWpos2 = Integer.parseInt(SplitGW[1]);  
   	int GWpos3 = Integer.parseInt(SplitGW[2]); 
   	int GWpos4 = Integer.parseInt(SplitGW[3]);
    stringBuffer.append(TEXT_6);
    stringBuffer.append(IPpos1);
    stringBuffer.append(TEXT_7);
    stringBuffer.append(IPpos2);
    stringBuffer.append(TEXT_8);
    stringBuffer.append(IPpos3);
    stringBuffer.append(TEXT_9);
    stringBuffer.append(IPpos4);
    stringBuffer.append(TEXT_10);
    stringBuffer.append(Netpos1);
    stringBuffer.append(TEXT_11);
    stringBuffer.append(Netpos2);
    stringBuffer.append(TEXT_12);
    stringBuffer.append(Netpos3);
    stringBuffer.append(TEXT_13);
    stringBuffer.append(Netpos4);
    stringBuffer.append(TEXT_14);
    stringBuffer.append(GWpos1);
    stringBuffer.append(TEXT_15);
    stringBuffer.append(GWpos2);
    stringBuffer.append(TEXT_16);
    stringBuffer.append(GWpos3);
    stringBuffer.append(TEXT_17);
    stringBuffer.append(GWpos4);
    stringBuffer.append(TEXT_18);
    } 
    stringBuffer.append(TEXT_19);
    stringBuffer.append(TEXT_20);
    return stringBuffer.toString();
  }
}
