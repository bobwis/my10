package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class reset001h_template
{
  protected static String nl;
  public static synchronized reset001h_template create(String lineSeparator)
  {
    nl = lineSeparator;
    reset001h_template result = new reset001h_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "/**************************************************************************//**" + NL + " *" + NL + " * Copyright (C) 2012 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with" + NL + " * Infineon's microcontrollers." + NL + " * This file can be freely distributed within development tools that are" + NL + " * supporting such microcontrollers." + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL," + NL + " * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series   \t\t\t                          **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Nov 22, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** BT         App Developer                                                   **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * @file RESET001.h" + NL + " *" + NL + " * @brief  Reset App implementation header file." + NL + " *" + NL + " */" + NL + "" + NL + " #ifndef RESET001_H_" + NL + " #define RESET001_H_" + NL + " /*******************************************************************************" + NL + "**                      Include Files                                         **" + NL + "*******************************************************************************/" + NL + "" + NL + "" + NL + "#include <DAVE3.h>" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Global Macro Definitions                              **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * @ingroup RESET001_publicparam" + NL + " * @{" + NL + " */" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Global Type Definitions                               **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * @brief This enumeration contains Reset Info Type" + NL + " */" + NL + "typedef enum RESET001_InfoType{" + NL + "  /** Power on reset */" + NL + "   POWER_ON_RESET = 0x00000001U," + NL + "  /** SWD reset  */" + NL + "   SWD_RESET = 0x00000002U," + NL + "  /** PVC reset */" + NL + "   PVC_RESET = 0x00000004U," + NL + "  /** CPU system reset */" + NL + "   CPU_SYS_RESET = 0x00000008U," + NL + "  /** CPU lockup reset */" + NL + "   CPU_LOCKUP_RESET = 0x00000010U," + NL + "  /** WDT reset */" + NL + "   WDT_RESET = 0x00000020U," + NL + "  /** TCU reset */" + NL + "   TCU_RESET = 0x00000040U," + NL + "  /** Parity error reset */" + NL + "   PARITY_ERROR_RESET = 0x00000080U" + NL + "}RESET001_InfoType;" + NL + "" + NL + "/**" + NL + " * @brief This enumeration contains Peripheral ID Type" + NL + " */" + NL + "typedef enum RESET001_ResetnType{" + NL + "  " + NL + "   /** ADC peripheral module */" + NL + "   PER0_VADC = 0x00000001U,   ";
  protected final String TEXT_2 = NL + "   /** DSD peripheral module */" + NL + "   PER0_DSD = 0x00000002U,";
  protected final String TEXT_3 = "   " + NL + "   /** CCU4x peripheral module */" + NL + "   PER0_CCU40 = 0x00000004U," + NL + "   /** CCU4x peripheral module */" + NL + "   PER0_CCU41 = 0x00000008U,";
  protected final String TEXT_4 = NL + "   /** CCU4x peripheral module */" + NL + "   PER0_CCU42 = 0x00000010U,";
  protected final String TEXT_5 = " " + NL + "   /** CCU8x peripheral module  */" + NL + "   PER0_CCU80 = 0x00000080U,";
  protected final String TEXT_6 = NL + "   /** CCU8x peripheral module */" + NL + "   PER0_CCU81 = 0x00000100U,";
  protected final String TEXT_7 = "   " + NL + "   /** POSIF peripheral module */" + NL + "   PER0_POSIF0 = 0x00000200U,";
  protected final String TEXT_8 = NL + "   /** POSIF peripheral module */" + NL + "   PER0_POSIF1 = 0x00000400U,";
  protected final String TEXT_9 = " " + NL + "   /** USIC0 peripheral module */" + NL + "   PER0_USIC0 = 0x00000800U," + NL + "   /** ERU peripheral module */" + NL + "   PER0_ERU1 = 0x00010000U, ";
  protected final String TEXT_10 = NL + "   /** HRPWM peripheral module */" + NL + "   PER0_HRPWM0 = 0x00800000U,";
  protected final String TEXT_11 = NL + "   /** CCU4x peripheral module */" + NL + "   PER1_CCU43 = 0x10000001U ,";
  protected final String TEXT_12 = "   " + NL + "   /** LED TS peripheral module */" + NL + "   PER1_LEDTSCU = 0x10000008U," + NL + "   /** MCAN peripheral module */" + NL + "   PER1_MCAN0 = 0x10000010U," + NL + "   /** DAC peripheral module */" + NL + "   PER1_DAC = 0x10000020U,";
  protected final String TEXT_13 = NL + "   /** MMC peripheral module */" + NL + "   PER1_MMC = 0x10000040U,";
  protected final String TEXT_14 = NL + "   /** USICx peripheral module */" + NL + "   PER1_USIC1 = 0x10000080U,  ";
  protected final String TEXT_15 = NL + "   /** USICx peripheral module */" + NL + "   PER1_USIC2 = 0x10000100U,";
  protected final String TEXT_16 = NL + "   /** Port &amp; Pins peripheral module */" + NL + "   PER1_PPORTS = 0x10000200U," + NL + "   /** Watch Dog peripheral module */" + NL + "   PER2_WDT = 0x20000002U,";
  protected final String TEXT_17 = NL + "   /** Ethernet peripheral module */" + NL + "   PER2_ETH0 = 0x20000004U,";
  protected final String TEXT_18 = " " + NL + "   /** DMA Unit 0 peripheral module */" + NL + "   PER2_DMA0 = 0x20000010U, ";
  protected final String TEXT_19 = NL + "   /** DMA Unit 1 peripheral module */" + NL + "   PER2_DMA1 = 0x20000020U,";
  protected final String TEXT_20 = NL + "   /** FCE peripheral module */" + NL + "   PER2_FCE = 0x20000040U,  ";
  protected final String TEXT_21 = NL + "   /** USB peripheral module */" + NL + "   PER2_USB = 0x20000080U,\t\t\t\t" + NL + "   /** EBU peripheral module */" + NL + "   PER3_EBU = 0x20000080U";
  protected final String TEXT_22 = NL + "   /** USB peripheral module */" + NL + "   PER2_USB = 0x20000080U";
  protected final String TEXT_23 = NL + "}RESET001_ResetnType;" + NL + "" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Global Constant Declarations                          **" + NL + "*******************************************************************************/" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Extern Variables                                      **" + NL + "*******************************************************************************/" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                     FUNCTION PROTOTYPES                                    **" + NL + "*******************************************************************************/" + NL + "" + NL + "" + NL + "/**" + NL + " * @ingroup RESET001_apidoc" + NL + " * @{" + NL + " */" + NL + "" + NL + "/**" + NL + " * @brief       This function is to enable reset of peripheral by software" + NL + " *" + NL + " * @param [in]  Resetn Peripheral ID" + NL + " *" + NL + " * @return     void" + NL + " *" + NL + " * <b>Reentrant: NO </b><BR>" + NL + " * <BR><P ALIGN=\"LEFT\"><B>Example:</B>" + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *    uint32_t status = 0;" + NL + " *    DAVE_Init();" + NL + " *    // Assert the module" + NL + " *    RESET001_AssertReset(PER0_ERU1);" + NL + " *    // Get the status  of the module" + NL + " *    status = RESET001_GetStatus(PER0_ERU1);" + NL + " *    if(status == 1)" + NL + " *    {" + NL + " *      // De-assert the module" + NL + " *      RESET001_DeassertReset(PER0_ERU1);" + NL + " *    }" + NL + " *  }" + NL + " * @endcode<BR> </p>" + NL + " *" + NL + " */" + NL + "void RESET001_AssertReset(RESET001_ResetnType Resetn);" + NL + "" + NL + "/**" + NL + " * @brief      This function is used to clear the  Reset of the desired peripheral ( de-assert reset)." + NL + " *" + NL + " * @param[in]  Resetn Peripheral ID" + NL + " *" + NL + " * @return     void" + NL + " *" + NL + " * <b>Reentrant: NO </b><BR>" + NL + " * <BR><P ALIGN=\"LEFT\"><B>Example:</B>" + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *    uint32_t status = 0;" + NL + " *    DAVE_Init();" + NL + " *    // Assert the module" + NL + " *    RESET001_AssertReset(PER0_ERU1);" + NL + " *    // Get the status  of the module" + NL + " *    status = RESET001_GetStatus(PER0_ERU1);" + NL + " *    if(status == 1)" + NL + " *    {" + NL + " *      // De-assert the module" + NL + " *      RESET001_DeassertReset(PER0_ERU1);" + NL + " *    }" + NL + " *  }" + NL + " * @endcode<BR> </p>" + NL + " *" + NL + " */" + NL + "void RESET001_DeassertReset(RESET001_ResetnType Resetn);" + NL + "" + NL + "" + NL + "/**" + NL + " * @brief      API to get the  reason of last reset." + NL + " *" + NL + " * @return     RESET001_InfoType enum  value" + NL + " *" + NL + " * <b>Reentrant: NO </b><BR>" + NL + " * <BR><P ALIGN=\"LEFT\"><B>Example:</B>" + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *    RESET001_InfoType ResetInfo;" + NL + " *    DAVE_Init();" + NL + " *    // Get the Information about last reset" + NL + " *    ResetInfo = RESET001_GetResetInfo();" + NL + " *  }" + NL + " * @endcode<BR> </p>" + NL + " *" + NL + " */" + NL + "RESET001_InfoType RESET001_GetResetInfo(void);" + NL + "" + NL + "" + NL + "/**" + NL + " * @brief      Get the reset status of the peripheral" + NL + " *" + NL + " * @param[in]   Resetn Peripheral ID" + NL + " *" + NL + " * @return     status_t" + NL + " *" + NL + " * <b>Reentrant: NO </b><BR>" + NL + " * <BR><P ALIGN=\"LEFT\"><B>Example:</B>" + NL + " * @code" + NL + " * #include <DAVE3.h>" + NL + " * int main(void)" + NL + " * {" + NL + " *    uint32_t status = 0;" + NL + " *    DAVE_Init();" + NL + " *    // Assert the module" + NL + " *    RESET001_AssertReset(PER0_ERU1);" + NL + " *    // Get the status  of the module" + NL + " *    status = RESET001_GetStatus(PER0_ERU1);" + NL + " *    if(status == 1)" + NL + " *    {" + NL + " *      // De-assert the module" + NL + " *      RESET001_DeassertReset(PER0_ERU1);" + NL + " *    }" + NL + " *  }" + NL + " * @endcode<BR> </p>" + NL + " *" + NL + " */" + NL + "status_t RESET001_GetStatus(RESET001_ResetnType Resetn);" + NL + "" + NL + "" + NL + "/**" + NL + " *@}" + NL + " */" + NL + "" + NL + "#endif /* RESET001_H_ */";
  protected final String TEXT_24 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
     String AppBaseuri = "app/reset001/"; 
     int Is44Device = -1; 
     int Is42Device = -1; 
     int Is45Device = -1; 
     Is44Device = ((app.getSoftwareId().substring(0,2).compareTo("44")==0)?1:0); 
     Is42Device = ((app.getSoftwareId().substring(0,2).compareTo("42")==0)?1:0); 
     Is45Device = ((app.getSoftwareId().substring(0,2).compareTo("45")==0)?1:0); 
    stringBuffer.append(TEXT_1);
    if((Is44Device==1)||(Is45Device==1))
   {
    stringBuffer.append(TEXT_2);
    }
    stringBuffer.append(TEXT_3);
    if((Is44Device==1)||(Is45Device==1))
   {
    stringBuffer.append(TEXT_4);
    }
    stringBuffer.append(TEXT_5);
    if((Is44Device==1)||(Is45Device==1))
   {
    stringBuffer.append(TEXT_6);
    }
    stringBuffer.append(TEXT_7);
    if((Is44Device==1)||(Is45Device==1))
   {
    stringBuffer.append(TEXT_8);
    }
    stringBuffer.append(TEXT_9);
    if((Is44Device==1)||(Is42Device==1))
   {
    stringBuffer.append(TEXT_10);
    }
    if((Is44Device==1)||(Is45Device==1))
   {
    stringBuffer.append(TEXT_11);
    }
    stringBuffer.append(TEXT_12);
    if (Is45Device==1)
   {
    stringBuffer.append(TEXT_13);
    }
    stringBuffer.append(TEXT_14);
    if (Is45Device==1)
   {
    stringBuffer.append(TEXT_15);
    }
    stringBuffer.append(TEXT_16);
    if((Is44Device==1)||(Is45Device==1))
   {
    stringBuffer.append(TEXT_17);
    }
    stringBuffer.append(TEXT_18);
    if (Is45Device==1)
   {
    stringBuffer.append(TEXT_19);
    }
    stringBuffer.append(TEXT_20);
    if (Is45Device==1)
   {
    stringBuffer.append(TEXT_21);
    }
     else 
   {
    stringBuffer.append(TEXT_22);
    }
    stringBuffer.append(TEXT_23);
    stringBuffer.append(TEXT_24);
    return stringBuffer.toString();
  }
}
