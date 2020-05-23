package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class guilc001c_template
{
  protected static String nl;
  public static synchronized guilc001c_template create(String lineSeparator)
  {
    nl = lineSeparator;
    guilc001c_template result = new guilc001c_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[GUILC001.c]*/" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                           \t\t\t  **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Dec 12, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                      Author(s) Identity                                    **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK           App Developer                                                 **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "" + NL + "/**" + NL + " * @file   GUILC001.c" + NL + " *" + NL + " * @brief  This file contains the private and public function definitions" + NL + " * of Compact Color App of GUI." + NL + " * Revision History: 12-12-12 GID_COMPACTCOLOR macro is replaced with DBG002_GID_GUILC001" + NL + " *                            and ERROR macro is prefixed with DBG002" + NL + " * 13-12-12 Dummy macros for DBG002 are added                            " + NL + " *" + NL + " */" + NL + "" + NL + "/*****************************************************************************" + NL + " *                          INCLUDE FILES" + NL + " *****************************************************************************/" + NL + "#include \"DAVE3.h\"" + NL;
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL + "const SPI001_HandleType* GUILC001_SPIHandle = &SPI001_Handle";
  protected final String TEXT_4 = ";";
  protected final String TEXT_5 = NL + "SPI001 App Not Mapped";
  protected final String TEXT_6 = NL;
  protected final String TEXT_7 = NL + "#define GUILC001_IOHandle (IO004_Handle";
  protected final String TEXT_8 = ")";
  protected final String TEXT_9 = NL + "IO004 App Not Mapped";
  protected final String TEXT_10 = NL;
  protected final String TEXT_11 = NL;
  protected final String TEXT_12 = "  " + NL + "/*****************************************************************************" + NL + "              DUMMY DEFINTIONS OF DEBUG LOG MACROS" + NL + "*****************************************************************************/" + NL + "/*These definitions are included here to avoid compilation errors," + NL + " since the DBG002 app is not part of the project. All the macros are defined" + NL + " as empty*/ " + NL + "#ifndef _DBG002_H_" + NL + "" + NL + "#define DBG002_RegisterCallBack(A,B,C)" + NL + "#define DBG002_I(e) " + NL + "#define DBG002_IG(e,g) " + NL + "#define DBG002_IH(e,h) " + NL + "#define DBG002_IP(e,p) " + NL + "#define DBG002_IGH(e,g,h) " + NL + "#define DBG002_IGP(e,g,p) " + NL + "#define DBG002_IHP(e,h,p) " + NL + "#define DBG002_IGHP(e,g,h,p) " + NL + "#define DBG002_N(e) " + NL + "#define DBG002_NG(e,g) " + NL + "#define DBG002_NH(e,h) " + NL + "#define DBG002_NP(e,p) " + NL + "#define DBG002_NGH(e,g,h) " + NL + "#define DBG002_NGP(e,g,p) " + NL + "#define DBG002_NHP(e,h,p) " + NL + "#define DBG002_NGHP(e,g,h,p) " + NL + "#define DBG002_ID(e) " + NL + "#define DBG002_IS(e) " + NL + "#define DBG002_ISG(e,g) " + NL + "#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)" + NL + "#define DBG002_CRITICAL(groupid,messageid,length,value)" + NL + "#define DBG002_ERROR(groupid,messageid,length,value)" + NL + "#define DBG002_WARNING(groupid,messageid,length,value)" + NL + "#define DBG002_INFO(groupid,messageid,length,value)" + NL + "#define DBG002_TRACE(groupid,messageid,length,value)" + NL + "#define DBG002_FUNCTION_ENTRY(GID, Status) " + NL + "#define DBG002_FUNCTION_EXIT(GID, Status) " + NL + "" + NL + "#endif/* End of defintions of dummy Debug Log macros*/";
  protected final String TEXT_13 = "                  " + NL + "" + NL + "#define APP_GID DBG002_GID_GUILC001" + NL + "" + NL + "/**" + NL + " * @cond INTERNAL_DOCS" + NL + " */" + NL + "/*******************************************************************************" + NL + "**                      Public Function Definitions                           **" + NL + "*******************************************************************************/" + NL + "/* Init function required by DAVE app. */" + NL + "void GUILC001_Init(void)" + NL + "{" + NL + "" + NL + "}" + NL + "" + NL + "" + NL + "/* <<<DD_GUILC001_API_1>>> */" + NL + "/*" + NL + " *  This routine should be called from your application program  to configure" + NL + " *  the SPI bus at the run-time." + NL + " *" + NL + " */" + NL + "void LCD_X_Serial_Init()" + NL + "{" + NL + "" + NL + "}" + NL + "" + NL + "/* Sends one byte of data to the OLED through SPI */" + NL + "void LCD_X_Send1(uint8_t Data)" + NL + "{" + NL + "  status_t Status;" + NL + "  uint16_t Shadow_Data = Data;" + NL + "  SPI001_ClearFlag(GUILC001_SPIHandle,SPI001_TRANS_SHIFT_IND_FLAG);" + NL + "  Status = SPI001_WriteData(GUILC001_SPIHandle, &Shadow_Data, SPI001_STANDARD_FULLDUPLEX);" + NL + "  if (Status != TRUE)" + NL + "  {" + NL + "    DBG002_ERROR(DBG002_GID_GUILC001,GUILC001_SPI001_ERROR,0,0);" + NL + "  } /* End of \"if (Status != TRUE)\" */" + NL + "  while(SPI001_SET != SPI001_GetFlagStatus(GUILC001_SPIHandle,SPI001_TRANS_SHIFT_IND_FLAG));" + NL + "}" + NL + "" + NL + "/* Reads one byte of data from the OLED through SPI */" + NL + "unsigned char LCD_X_Read1(void)" + NL + "{" + NL + "  uint16_t LastWord = 0;" + NL + "  uint16_t Shadow_Data=0xFFFF;" + NL + "  SPI001_ClearFlag(&SPI001_Handle0,SPI001_RECV_IND_FLAG);" + NL + "  SPI001_WriteData(GUILC001_SPIHandle, &Shadow_Data, SPI001_STANDARD_FULLDUPLEX);" + NL + "  //while(!SPI001_GetFlagStatus(&SPI001_Handle0,SPI001_FIFO_STD_RECV_BUF_FLAG));" + NL + "  while(!SPI001_GetFlagStatus(&SPI001_Handle0,SPI001_RECV_IND_FLAG));" + NL + "" + NL + "  SPI001_ReadData(&SPI001_Handle0,&LastWord);" + NL + "" + NL + "  return (unsigned char)LastWord;" + NL + "}" + NL + "" + NL + "/* <<<DD_GUILC001_API_2>>> */" + NL + "/*" + NL + " *  This routine Writes to display controller using SPI bus, with A0 = 0" + NL + " *" + NL + " */" + NL + "void LCD_X_Serial_8_Write00(uint8_t Cmd)" + NL + "{" + NL + "  /* Clear the A0 pin */" + NL + "  IO004_ResetPin(GUILC001_IOHandle);" + NL + "  /* Write to the SPI Bus */" + NL + "/* <<<DD_GUILC001_API_2_1>>> */" + NL + "  LCD_X_Send1(Cmd);" + NL + "}" + NL + "" + NL + "/* <<<DD_GUILC001_API_3>>> */" + NL + "/*" + NL + " *  This routine Writes to display controller using SPI bus, with A0 = 1" + NL + " *" + NL + " */" + NL + "void LCD_X_Serial_8_Write01(uint8_t Data)" + NL + "{" + NL + "  /* Set the A0 pin*/" + NL + "  IO004_SetPin(GUILC001_IOHandle);" + NL + "" + NL + "/* <<<DD_GUILC001_API_3>>> */" + NL + "  LCD_X_Send1(Data);" + NL + "}" + NL + "" + NL + "/* <<<DD_GUILC001_API_4>>> */" + NL + "/*" + NL + " *  This routine writes multiple bytes to display controller using SPI bus," + NL + " *  with A0 = 1." + NL + " *" + NL + " */" + NL + "void LCD_X_Serial_M8_Write01(uint8_t *Data, int NumItems)" + NL + "{" + NL + "  uint8_t  DataCopy;" + NL + "" + NL + "  /* Set the A0 pin*/" + NL + "\tIO004_SetPin(GUILC001_IOHandle);" + NL + "\tdo" + NL + "\t{" + NL + "\t  DataCopy = *Data;" + NL + "\t  LCD_X_Send1(DataCopy);" + NL + "\t  Data++;" + NL + "\t}while(--NumItems);" + NL + "}" + NL + "" + NL + "" + NL + "/* <<<DD_GUILC001_API_5>>> */" + NL + "/*" + NL + " *  This routine read multiple bytes from display controller using SPI bus," + NL + " *  with A0 = 1." + NL + " *" + NL + " */" + NL + "void LCD_X_Serial_M8_Read01(uint8_t *Data, int NumItems)" + NL + "{" + NL + "  IO004_SetPin(GUILC001_IOHandle);" + NL + "  for (; NumItems; NumItems--)" + NL + "  {" + NL + "    *Data++ = LCD_X_Read1();" + NL + "  }" + NL + "}" + NL + "" + NL + "/**" + NL + " * @endcond" + NL + " */" + NL + "" + NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_14 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/guilc001/";
     String SPIHandle = null; 
     String SPIHandleUri = null; 
    stringBuffer.append(TEXT_2);
     SPIHandleUri = app.getMappedUri(AppBaseuri + "0/spi"); 
     if ((SPIHandleUri != null) && (SPIHandleUri.trim() != "")) { 
     SPIHandle = SPIHandleUri.substring(SPIHandleUri.length() -1); 
    stringBuffer.append(TEXT_3);
    stringBuffer.append( SPIHandle);
    stringBuffer.append(TEXT_4);
    } else {
    stringBuffer.append(TEXT_5);
    }
    stringBuffer.append(TEXT_6);
     SPIHandleUri = app.getMappedUri(AppBaseuri + "0/io004"); 
     if ((SPIHandleUri != null) && (SPIHandleUri.trim() != "")) { 
     SPIHandle = SPIHandleUri.substring(SPIHandleUri.length() -1); 
    stringBuffer.append(TEXT_7);
    stringBuffer.append( SPIHandle);
    stringBuffer.append(TEXT_8);
    } else {
    stringBuffer.append(TEXT_9);
    }
    stringBuffer.append(TEXT_10);
     String TempApps = null;
   String MyAppName = null;
   ArrayList<String> apps;
   String TempLowerApps = null; 
   boolean DBGApp = false;   
   apps=(ArrayList<String>)(app.getApps());
        for (int k = 0; k < apps.size(); k++) {
              TempApps = apps.get(k);
//            if(app.isAppInitProvider(apps.get(k)) == true) {
              MyAppName = TempApps.substring(TempApps.indexOf("/app/") + 5, TempApps.lastIndexOf("/"));
              TempLowerApps = MyAppName.toLowerCase();
              if (TempLowerApps.equalsIgnoreCase("dbg002")) {DBGApp = true;}   
//   }  
  } 
    stringBuffer.append(TEXT_11);
     if (!DBGApp) { 
    stringBuffer.append(TEXT_12);
     } 
    stringBuffer.append(TEXT_13);
    stringBuffer.append(TEXT_14);
    return stringBuffer.toString();
  }
}
