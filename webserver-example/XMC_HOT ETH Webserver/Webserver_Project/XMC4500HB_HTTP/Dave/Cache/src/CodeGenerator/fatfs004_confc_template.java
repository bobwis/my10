package CodeGenerator;

import com.ifx.davex.appjetinteract.App2JetInterface;

public class fatfs004_confc_template
{
  protected static String nl;
  public static synchronized fatfs004_confc_template create(String lineSeparator)
  {
    nl = lineSeparator;
    fatfs004_confc_template result = new fatfs004_confc_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[FATFS004_Conf.c] */" + NL + "" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without** " + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : App Developer                                                     **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : July 31, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials    Name                                                           **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** SK          App Developer                                                  **" + NL + "*******************************************************************************/" + NL + NL;
  protected final String TEXT_2 = NL + NL + "/**" + NL + " * @file FATFS004_Conf.c" + NL + " *" + NL + " * @App Version FATFS004 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief This file contains the configurations of FATFS004 App based on the UI " + NL + " * settings. " + NL + " *" + NL + " */" + NL + " ";
  protected final String TEXT_4 = NL;
  protected final String TEXT_5 = NL + NL + NL + "#ifndef ";
  protected final String TEXT_6 = "_CONF_C_" + NL + "#define ";
  protected final String TEXT_7 = "_CONF_C_" + NL + "" + NL + "#include <DAVE3.h>" + NL + "" + NL + "/**" + NL + " * The number of element in array are equal to number of physical" + NL + " * devices supported." + NL + " */";
  protected final String TEXT_8 = " " + NL + "   const ";
  protected final String TEXT_9 = "_DeviceFuncType ";
  protected final String TEXT_10 = "_DeviceFunc[] =" + NL + "                                                {" + NL + "                                                    {";
  protected final String TEXT_11 = NL + "                                                      ";
  protected final String TEXT_12 = "_Initialize,";
  protected final String TEXT_13 = NL + "                                                      ";
  protected final String TEXT_14 = "_GetStatus,";
  protected final String TEXT_15 = NL + "                                                      ";
  protected final String TEXT_16 = "_ReadBlock,";
  protected final String TEXT_17 = NL + "                                                      ";
  protected final String TEXT_18 = "_WriteBlock,";
  protected final String TEXT_19 = NL + "                                                      ";
  protected final String TEXT_20 = "_Ioctl" + NL + "                                                    }," + NL + "                                                    {" + NL + "                                                      USBBL001_Initialize," + NL + "                                                      USBBL001_GetStatus," + NL + "                                                      USBBL001_ReadBlock," + NL + "                                                      USBBL001_WriteBlock," + NL + "                                                      USBBL001_Ioctl" + NL + "                                                    }" + NL + "                                                 };";
  protected final String TEXT_21 = NL + "   const ";
  protected final String TEXT_22 = "_DeviceFuncType ";
  protected final String TEXT_23 = "_DeviceFunc[] =" + NL + "\t                                                {" + NL + "\t                                                    {" + NL + "\t                                                      ";
  protected final String TEXT_24 = "_Initialize," + NL + "\t                                                      ";
  protected final String TEXT_25 = "_GetStatus," + NL + "\t                                                      ";
  protected final String TEXT_26 = "_ReadBlock," + NL + "\t                                                      ";
  protected final String TEXT_27 = "_WriteBlock," + NL + "\t                                                      ";
  protected final String TEXT_28 = "_Ioctl" + NL + "\t                                                    }" + NL + "                                                   };" + NL;
  protected final String TEXT_29 = NL + "    const ";
  protected final String TEXT_30 = "_DeviceFuncType ";
  protected final String TEXT_31 = "_DeviceFunc[] =" + NL + "\t                                                {" + NL + "\t                                                  {" + NL + "\t                                                    USBBL001_Initialize," + NL + "                                                          USBBL001_GetStatus," + NL + "                                                          USBBL001_ReadBlock," + NL + "                                                          USBBL001_WriteBlock," + NL + "                                                          USBBL001_Ioctl" + NL + "\t                                                  }" + NL + "                                                   };";
  protected final String TEXT_32 = NL + "\tconst ";
  protected final String TEXT_33 = "_DeviceFuncType ";
  protected final String TEXT_34 = "_DeviceFunc[1]\t= {NULL};\t\t  ";
  protected final String TEXT_35 = NL + NL + "#endif" + NL + "\t\t" + NL + "/*CODE_BLOCK_END*/" + NL + NL;
  protected final String TEXT_36 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/fatfs004/"; 
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri) );
    stringBuffer.append(TEXT_3);
     int appInst = 0; 
     int SdmmcFlag = app.getIntegerValue(AppBaseuri + appInst + "/fatfs004_devices_available/0" );
   int UsbFlag = app.getIntegerValue(AppBaseuri + appInst + "/fatfs004_usbdevice_available/0" );
   int RTOS = app.getIntegerValue(AppBaseuri + appInst + "/fatfs004_rtos_present");
   String  Module_Name = "FATFS004";
   String  Sub_Module_Name = "SDMMC001";

    stringBuffer.append(TEXT_4);
     
  if (RTOS == 1)
  {
  	 Module_Name = "FATFS005";
 	 Sub_Module_Name = "SDMMC002";
  }
  else
  {
    Module_Name = "FATFS004";
    Sub_Module_Name = "SDMMC001";
  }

    stringBuffer.append(TEXT_5);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_6);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_7);
     if ( (SdmmcFlag == 1) && (UsbFlag == 1))
   {
    stringBuffer.append(TEXT_8);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_9);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_10);
    stringBuffer.append(TEXT_11);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_12);
    stringBuffer.append(TEXT_13);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_14);
    stringBuffer.append(TEXT_15);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_16);
    stringBuffer.append(TEXT_17);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_18);
    stringBuffer.append(TEXT_19);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_20);
     } 
   else if (SdmmcFlag == 1)	
   {
    stringBuffer.append(TEXT_21);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_22);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_23);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_24);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_25);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_26);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_27);
    stringBuffer.append( Sub_Module_Name);
    stringBuffer.append(TEXT_28);
     }
    else if (UsbFlag  == 1)
    {
    stringBuffer.append(TEXT_29);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_30);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_31);
     }
	else
	{ 
    stringBuffer.append(TEXT_32);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_33);
    stringBuffer.append( Module_Name);
    stringBuffer.append(TEXT_34);
      } 
    stringBuffer.append(TEXT_35);
    stringBuffer.append(TEXT_36);
    return stringBuffer.toString();
  }
}
