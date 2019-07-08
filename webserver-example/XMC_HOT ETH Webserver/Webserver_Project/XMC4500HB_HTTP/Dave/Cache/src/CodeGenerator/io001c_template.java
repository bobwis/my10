package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class io001c_template
{
  protected static String nl;
  public static synchronized io001c_template create(String lineSeparator)
  {
    nl = lineSeparator;
    io001c_template result = new io001c_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "/*CODE_BLOCK_BEGIN[IO001.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2012, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4XXX Series/XMC1XXX Series                          **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Feb 07, 2013                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                      Author(s) Identity                                    **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** PAE        App Developer                                                   **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @file   IO001.c" + NL + " *" + NL + " * @brief  IO_Analog_IO001 App" + NL + " *" + NL + " * Revision History - " + NL + " * 7 Feb 2013 v1.0.11 Replaced \"/pin/iocr_pcr\" resource with \"/IO001_inputchardummy\"" + NL + " * \t\t\t\t\t\tresource to get the IOCR_PCR value." + NL + " *" + NL + " */" + NL + "/*******************************************************************************" + NL + " ** INCLUDE FILES                                                             **" + NL + " ******************************************************************************/" + NL + "" + NL + "/** Inclusion of header file */" + NL + "#include <DAVE3.h>" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Private Macro Definitions                             **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Private Type Definitions                              **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                 Private Function Declarations:" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Global Constant Definitions                           **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Global Variable Definitions                           **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Private Constant Definitions                          **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                 Function like macro definitions                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                      Private Function Definitions                          **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Public Function Definitions                           **" + NL + "*******************************************************************************/" + NL + "" + NL + "" + NL + "/** @ingroup IO001_Func" + NL + " * @{" + NL + " */" + NL + "" + NL + "void IO001_Init(void)" + NL + "{" + NL + "   /* <<<DD_IO001_API_1>>> */";
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + "  /* Configuration of Port ";
  protected final String TEXT_4 = " Pin ";
  protected final String TEXT_5 = " based on User configuration */";
  protected final String TEXT_6 = NL + "  /* Enable Digital Pad Input*/" + NL + "  IO001_Handle";
  protected final String TEXT_7 = ".PortRegs->PDISC  &= (~((uint32_t)0x1U << ";
  protected final String TEXT_8 = "));" + NL + "  /*configure the Digital Input characteristics in IOCR register*/";
  protected final String TEXT_9 = NL + "  IO001_Handle";
  protected final String TEXT_10 = ".PortRegs->IOCR0 |= (";
  protected final String TEXT_11 = "U << ";
  protected final String TEXT_12 = ");";
  protected final String TEXT_13 = NL + "  IO001_Handle";
  protected final String TEXT_14 = ".PortRegs->IOCR4 |= (";
  protected final String TEXT_15 = "U << ";
  protected final String TEXT_16 = ");";
  protected final String TEXT_17 = NL + "  IO001_Handle";
  protected final String TEXT_18 = ".PortRegs->IOCR8 |= (";
  protected final String TEXT_19 = "U << ";
  protected final String TEXT_20 = ");";
  protected final String TEXT_21 = NL + "  IO001_Handle";
  protected final String TEXT_22 = ".PortRegs->IOCR12 |= (";
  protected final String TEXT_23 = "U << ";
  protected final String TEXT_24 = ");";
  protected final String TEXT_25 = NL + "  /*Disable Digital Pad Input*/" + NL + "  IO001_Handle";
  protected final String TEXT_26 = ".PortRegs->PDISC  |= (0x1U << ";
  protected final String TEXT_27 = ");";
  protected final String TEXT_28 = NL + "  /* PIN App instance (no.";
  protected final String TEXT_29 = ") is not mapped to any port pin. */";
  protected final String TEXT_30 = NL + "}" + NL + "" + NL + "void IO001_EnableDigitalInput(const IO001_HandleType* Handle,IO001_InputModeType Mode)" + NL + "{" + NL + "  uint8_t Pin = Handle->PortPin;" + NL + "  /* <<<DD_IO001_API_2>>> */" + NL + "     " + NL + "  /* Enable Digital Mode */" + NL + "  Handle->PortRegs->PDISC  =  (uint32_t)(Handle->PortRegs->PDISC & ~(1UL << (Pin)));" + NL + "  if(Pin < 4U)" + NL + "  {" + NL + "    Handle->PortRegs->IOCR0  =  (uint32_t)(Handle->PortRegs->IOCR0 & ~(0x0000001FUL << (3U+(Pin*8U))));" + NL + "    Handle->PortRegs->IOCR0 |= (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));" + NL + "  } else if ((Pin >= 4U) && (Pin <= 7U))" + NL + "  {" + NL + "    Pin = Pin - 4U;" + NL + "    Handle->PortRegs->IOCR4  =  (uint32_t)(Handle->PortRegs->IOCR4 & ~(0x0000001FUL << (3U+(Pin*8U))));" + NL + "    Handle->PortRegs->IOCR4 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));" + NL + "  } else if ((Pin >= 8U) && (Pin <= 11U))" + NL + "  {" + NL + "    Pin = Pin - 8U;" + NL + "    Handle->PortRegs->IOCR8  =  (uint32_t)(Handle->PortRegs->IOCR8 & ~(0x0000001FUL << (3U+(Pin*8U))));" + NL + "    Handle->PortRegs->IOCR8 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));" + NL + "  } else if ((Pin >= 12U) && (Pin <= 15U))" + NL + "  {" + NL + "    Pin = Pin - 12U;" + NL + "    Handle->PortRegs->IOCR12  =  (uint32_t)(Handle->PortRegs->IOCR12 & ~(0x0000001FUL << (3U+(Pin*8U))));" + NL + "    Handle->PortRegs->IOCR12 |=  (uint32_t)(((uint32_t)Mode & 0x1FUL) << (3U+(Pin*8U)));" + NL + "  }" + NL + "  else" + NL + "  {" + NL + "   /*Not supposed to be here */" + NL + "  }" + NL + "}" + NL + "" + NL + "void IO001_DisableDigitalInput(const IO001_HandleType* Handle)" + NL + "{" + NL + "  /* <<<DD_IO001_API_3>>> */" + NL + "  /* Disable Digital Mode */" + NL + "  Handle->PortRegs->PDISC  |=  (uint32_t)(1UL << Handle->PortPin);" + NL + "}" + NL + "" + NL + "" + NL + "/**" + NL + "*@}" + NL + "*/  " + NL + "" + NL + "/*CODE_BLOCK_END*/" + NL;
  protected final String TEXT_31 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
     String AppBaseuri = "app/io001/"; 
    stringBuffer.append(TEXT_1);
     String appInst  = null; 
    stringBuffer.append(TEXT_2);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/io001/"));
   for (String appIns : appsList ) {
   appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     String pinUri = app.getMappedUri(AppBaseuri + appInst +"/pin"); 
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     String portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     String pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
     int PDISC = app.getIntegerValue(AppBaseuri + appInst +"/IO001_DigitalModedummy");
  int IOCR_PCR2 = app.getIntegerValue(AppBaseuri + appInst +"/IO001_inputchardummy");  
     int Pin = Integer.parseInt(pinNo);
    stringBuffer.append(TEXT_3);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_4);
    stringBuffer.append(pinNo);
    stringBuffer.append(TEXT_5);
     if(PDISC == 1 ) { 
    stringBuffer.append(TEXT_6);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_7);
    stringBuffer.append(pinNo);
    stringBuffer.append(TEXT_8);
     if(Pin < 4) { 
    stringBuffer.append(TEXT_9);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_10);
    stringBuffer.append(IOCR_PCR2);
    stringBuffer.append(TEXT_11);
    stringBuffer.append((3+(Pin*8)));
    stringBuffer.append(TEXT_12);
    }else if (Pin >= 4 && Pin <= 7) {  
    Pin = Pin - 4; 
    stringBuffer.append(TEXT_13);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_14);
    stringBuffer.append(IOCR_PCR2);
    stringBuffer.append(TEXT_15);
    stringBuffer.append((3+(Pin*8)));
    stringBuffer.append(TEXT_16);
    } else if (Pin >= 8 && Pin <= 11) { 
  Pin = Pin - 8; 
    stringBuffer.append(TEXT_17);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_18);
    stringBuffer.append(IOCR_PCR2);
    stringBuffer.append(TEXT_19);
    stringBuffer.append((3+(Pin*8)));
    stringBuffer.append(TEXT_20);
    } else if (Pin >= 12 && Pin <= 15) { 
    Pin = Pin - 12; 
    stringBuffer.append(TEXT_21);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_22);
    stringBuffer.append(IOCR_PCR2);
    stringBuffer.append(TEXT_23);
    stringBuffer.append((3+(Pin*8)));
    stringBuffer.append(TEXT_24);
    }
    } else { 
    stringBuffer.append(TEXT_25);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_26);
    stringBuffer.append(pinNo);
    stringBuffer.append(TEXT_27);
    }
    } else { 
    stringBuffer.append(TEXT_28);
    stringBuffer.append( appInst );
    stringBuffer.append(TEXT_29);
    }} 
    stringBuffer.append(TEXT_30);
    stringBuffer.append(TEXT_31);
    return stringBuffer.toString();
  }
}
