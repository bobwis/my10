package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class io001_confc_template
{
  protected static String nl;
  public static synchronized io001_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    io001_confc_template result = new io001_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "/*CODE_BLOCK_BEGIN[IO001_Conf.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without** " + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000/XMC1xxx Series                                 **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Jan 07, 2013                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @file   IO001_Conf.c" + NL + " *  " + NL + " * @brief  Configuration file generated based on UI settings " + NL + " *         of IO001 App" + NL + " *" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + " ** INCLUDE FILES                                                             **" + NL + " ******************************************************************************/" + NL + "#include <DAVE3.h>" + NL;
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = "   " + NL + "" + NL + "const IO001_HandleType IO001_Handle";
  protected final String TEXT_4 = " = {";
  protected final String TEXT_5 = NL + "   ";
  protected final String TEXT_6 = "U , /* Mapped Port */";
  protected final String TEXT_7 = NL + "  ";
  protected final String TEXT_8 = "U,   /* Mapped Pin */" + NL + "   (IO001_PORTS_TypeDef*)PORT";
  protected final String TEXT_9 = "_BASE /* Port Base Address*/\t\t\t" + NL + "};" + NL;
  protected final String TEXT_10 = NL + "/* IO001 App instance (no.";
  protected final String TEXT_11 = ") is not mapped to any Port Pad. */";
  protected final String TEXT_12 = NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_13 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
     String AppBaseuri = "app/io001/"; 
    stringBuffer.append(TEXT_1);
     String P = "http://www.infineon.com/0.1.28/port/p/"; 
     String appInst  = null; 
    stringBuffer.append(TEXT_2);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/io001/"));
 for (String appIns : appsList ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     String pinUri = app.getMappedUri(AppBaseuri + appInst +"/pin"); 
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     String portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     String pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_3);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_4);
    stringBuffer.append(TEXT_5);
    stringBuffer.append( portNo);
    stringBuffer.append(TEXT_6);
    stringBuffer.append(TEXT_7);
    stringBuffer.append( pinNo);
    stringBuffer.append(TEXT_8);
    stringBuffer.append( portNo);
    stringBuffer.append(TEXT_9);
     } else { 
    stringBuffer.append(TEXT_10);
    stringBuffer.append( appInst );
    stringBuffer.append(TEXT_11);
     }} 
    stringBuffer.append(TEXT_12);
    stringBuffer.append(TEXT_13);
    return stringBuffer.toString();
  }
}
