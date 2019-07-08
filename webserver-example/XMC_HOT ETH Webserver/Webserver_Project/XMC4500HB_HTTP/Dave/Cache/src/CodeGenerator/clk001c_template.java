package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class clk001c_template
{
  protected static String nl;
  public static synchronized clk001c_template create(String lineSeparator)
  {
    nl = lineSeparator;
    clk001c_template result = new clk001c_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "";
  protected final String TEXT_2 = NL;
  protected final String TEXT_3 = NL;
  protected final String TEXT_4 = NL + "/*CODE_BLOCK_BEGIN[CLK001.c]*/" + NL + "" + NL + "/*******************************************************************************" + NL + " Copyright (c) 2012, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without** " + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Oct 31, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @file   CLK001.c" + NL + " *" + NL + " * @brief  SCU_Clock_CLK001 App" + NL + " *         " + NL + " *  CLK001 App is a singleton app which is used by all applications to configure " + NL + " *  the PLL as well as enable the Clock of Peripheral Units." + NL + " " + NL + " * Revision History" + NL + " * 12 Dec 2012   v1.0.1    modified to take care java.utils and basecode updates" + NL + " " + NL + " *" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Author(s) Identity                                    **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** RS           App Developer                                                 **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + " ** INCLUDE FILES                                                             **" + NL + " ******************************************************************************/" + NL + "/** Inclusion of header file */" + NL + "#include <DAVE3.h>" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Private Macro Definitions                             **" + NL + "*******************************************************************************/" + NL + "" + NL + "/* Various options for CLK tree settings*/" + NL + "" + NL + "/*Main PLL input clock options*/" + NL + "#define CLK001_CLOCK_CRYSTAL                1U" + NL + "#define CLK001_CLOCK_EXT_CLOCK              2U" + NL + "#define CLK001_CLOCK_BACK_UP_CLOCK          3U" + NL + "" + NL + "/*Options for back up clock trimming*/" + NL + "#define CLK001_CLOCK_TRIM_FACTORY           1U" + NL + "#define CLK001_CLOCK_TRIM_AUTOMATIC         2U" + NL + "" + NL + "/*options for system clock source*/" + NL + "#define CLK001_CLOCK_SRC_PLL            1U" + NL + "#define CLK001_CLOCK_SRC_BACKUP         2U" + NL + "" + NL + "/*options for PLL modes*/" + NL + "#define CLK001_CLOCK_PLL_NORMAL         1U" + NL + "#define CLK001_CLOCK_PLL_PRESCALER      2U" + NL + "" + NL + "/*options for STDBY clock source*/" + NL + "#define CLK001_HIB_CLOCK_FOSI          1U" + NL + "#define CLK001_HIB_CLOCK_OSCULP        2U" + NL + "" + NL + "" + NL + "/* MAIN PLL setup parameters */  ";
  protected final String TEXT_5 = NL;
  protected final String TEXT_6 = NL + NL + "#define   CLK001_PLL_K1DIV        ";
  protected final String TEXT_7 = "U" + NL + "#define   CLK001_PLL_K2DIV        ";
  protected final String TEXT_8 = "U      " + NL + "#define   CLK001_PLL_PDIV         ";
  protected final String TEXT_9 = "U    " + NL + "#define   CLK001_PLL_NDIV         ";
  protected final String TEXT_10 = "U  " + NL + "#define   CLK001_PLL_K2DIV_STEP_1    19  /*PLL output is 24Mhz*/  " + NL + "#define   CLK001_PLL_K2DIV_STEP_2    7  /*PLL output to 60Mhz*/  " + NL + "#define   CLK001_PLL_K2DIV_STEP_3    4  /*PLL output to 96Mhz*/  ";
  protected final String TEXT_11 = NL + "#define   CLK001_PLL_K1DIV     1U    " + NL + "#define   CLK001_PLL_K2DIV     3U      " + NL + "#define   CLK001_PLL_PDIV      1U    " + NL + "#define   CLK001_PLL_NDIV      79U  " + NL + "      " + NL + "#define   CLK001_PLL_K2DIV_STEP_1    19  /*PLL output is 24Mhz*/  " + NL + "#define   CLK001_PLL_K2DIV_STEP_2    7  /*PLL output to 60Mhz*/  " + NL + "#define   CLK001_PLL_K2DIV_STEP_3    4  /*PLL output to 96Mhz*/  ";
  protected final String TEXT_12 = NL + NL + "/* USB PLL setup parameters */" + NL + "#define   CLK001_USBPLL_PDIV      ";
  protected final String TEXT_13 = "U" + NL + "#define   CLK001_USBPLL_NDIV      ";
  protected final String TEXT_14 = "U" + NL + "#define   CLK001_USBDIV           ";
  protected final String TEXT_15 = "U" + NL + "" + NL + "" + NL + "" + NL + "/*Main PLL input clock configuration*/";
  protected final String TEXT_16 = NL + "#define  CLK001_PLL_CLOCK_INPUT  CLK001_CLOCK_CRYSTAL" + NL + "" + NL + "/*Oscillator mode = External Crystal Mode*/" + NL + "#define CLK001_OSC_HP_MODE  0x0U";
  protected final String TEXT_17 = NL + "#define  CLK001_PLL_CLOCK_INPUT  CLK001_CLOCK_EXT_CLOCK" + NL + "" + NL + "/*Oscillator mode = External Input Clock Mode*/" + NL + "#define CLK001_OSC_HP_MODE  0x2U";
  protected final String TEXT_18 = NL + "#define  CLK001_PLL_CLOCK_INPUT  CLK001_CLOCK_BACK_UP_CLOCK" + NL + "" + NL + "/*Oscillator mode = External Crystal Mode*/" + NL + "#define CLK001_OSC_HP_MODE  0x0U";
  protected final String TEXT_19 = NL + NL + "/*Standby clock source configuration*/";
  protected final String TEXT_20 = NL + "#define  CLK001_STANDBY_CLOCK  CLK001_HIB_CLOCK_OSCULP";
  protected final String TEXT_21 = NL + "#define  CLK001_STANDBY_CLOCK  CLK001_HIB_CLOCK_FOSI";
  protected final String TEXT_22 = NL + NL + "/*Back up clock trimming option*/";
  protected final String TEXT_23 = NL + "#define CLK001_TRIM_OPTION CLK001_CLOCK_TRIM_AUTOMATIC";
  protected final String TEXT_24 = NL + "#define CLK001_TRIM_OPTION CLK001_CLOCK_TRIM_FACTORY";
  protected final String TEXT_25 = NL + NL + "/*System clock source configuration*/";
  protected final String TEXT_26 = NL + "#define CLK001_CLOCK_SYS_SRC CLK001_CLOCK_SRC_PLL ";
  protected final String TEXT_27 = NL + "#define CLK001_CLOCK_SYS_SRC CLK001_CLOCK_SRC_BACKUP ";
  protected final String TEXT_28 = NL + NL + "/*PLL mode configuration*/";
  protected final String TEXT_29 = NL + "#define CLK001_CLOCK_PLL_MODE CLK001_CLOCK_PLL_NORMAL";
  protected final String TEXT_30 = NL + "#define CLK001_CLOCK_PLL_MODE CLK001_CLOCK_PLL_PRESCALER";
  protected final String TEXT_31 = NL + NL + "/*Values of various parameters based on UI selction*/" + NL + "" + NL + "/*system clock frequency*/" + NL + "#define CLK001_CLOCK_FSYS                    ";
  protected final String TEXT_32 = "U" + NL + "" + NL + "/*crystal or digital clock input frequency*/";
  protected final String TEXT_33 = NL + "#define  CLK001_CLOCK_CRYSTAL_FREQUENCY      ";
  protected final String TEXT_34 = "U     ";
  protected final String TEXT_35 = NL + "#define  CLK001_CLOCK_CRYSTAL_FREQUENCY      ";
  protected final String TEXT_36 = "U ";
  protected final String TEXT_37 = " " + NL + "#define  CLK001_CLOCK_CRYSTAL_FREQUENCY      ";
  protected final String TEXT_38 = "U ";
  protected final String TEXT_39 = NL + NL + "/*back up clock frequency*/" + NL + "#define  CLK001_CLOCK_BACK_UP                24000000U" + NL + "" + NL + "/*Reference frequency for sytem oscillator watch dog - 2.5 MHz*/" + NL + "#define  CLK001_SOSCWDG_FREF                 2500000U" + NL + "" + NL + "/*Regiser bit field mask to check if Oscillator is usable*/" + NL + "#define CLK001_PLLSTAT_OSC_USABLE_MASK       (SCU_PLL_PLLSTAT_PLLHV_Msk | \\" + NL + "                                              SCU_PLL_PLLSTAT_PLLLV_Msk | \\" + NL + "                                              SCU_PLL_PLLSTAT_PLLSP_Msk)" + NL + "" + NL + "/*delay values used in the below calculation" + NL + "these are to be used with the delay function defined in this file" + NL + "they are approximate values based on measurement*/" + NL + "#define CLK001_DELAY_CNT_50US_50MHZ        100U" + NL + "#define CLK001_DELAY_CNT_50US_90MHZ        150U" + NL + "#define CLK001_DELAY_CNT_8US_50MHZ         10U" + NL + "#define CLK001_LOOP_CNT_150MS              18000U /*150ms / 8us*/" + NL + "" + NL + "/*values for PLL frequency stepping*/" + NL + "#define CLK001_PLL_FREQ_STEP1               (24U * 1000U * 1000U)" + NL + "#define CLK001_PLL_FREQ_STEP2               (60U * 1000U * 1000U)" + NL + "#define CLK001_PLL_FREQ_STEP3               (90U * 1000U * 1000U)" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Private Type Definitions                              **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                 Private Function Declarations:" + NL + "*******************************************************************************/" + NL + "static void Delay(uint32_t time_1);";
  protected final String TEXT_40 = NL + "static void OSCULP_init(void);";
  protected final String TEXT_41 = " " + NL + "static void External_Clock_Signal_init(void);";
  protected final String TEXT_42 = NL + "static uint32_t System_Clock_valid(void);" + NL + "static uint32_t System_Clock_init(void);";
  protected final String TEXT_43 = "     " + NL + "static uint32_t\tUSB_Clock_valid(void);" + NL + "static uint32_t\tUSB_Clock_init(void);";
  protected final String TEXT_44 = NL + "static void CCU_Clock_init(void);";
  protected final String TEXT_45 = NL;
  protected final String TEXT_46 = NL + "static void EBU_Clock_init(void);";
  protected final String TEXT_47 = NL + NL;
  protected final String TEXT_48 = NL + "static void MMC_Clock_init(void);";
  protected final String TEXT_49 = NL;
  protected final String TEXT_50 = " " + NL + "static void WDT_Clock_init(void);   ";
  protected final String TEXT_51 = " " + NL + "static void RTC_Clock_init(void);";
  protected final String TEXT_52 = NL + NL + "/*******************************************************************************" + NL + "**                      Extern Declarations                                   **" + NL + "*******************************************************************************/" + NL + "extern void SystemCoreClockUpdate(void);" + NL + "/*******************************************************************************" + NL + "**                      Global Variable Definitions                           **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Private Constant Definitions                          **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                 Function like macro definitions                            **" + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Private Function Definitions                          **" + NL + "*******************************************************************************/" + NL + "/**" + NL + "  * @brief  Function to delay  " + NL + "  * @note   -  " + NL + "  * @param  number of loops" + NL + "  * @retval None" + NL + "  */" + NL + "static void Delay(uint32_t time_1)" + NL + "{" + NL + "\tuint32_t i = 0U;" + NL + "\tfor(i=0U; i < time_1;i++)" + NL + "\t{" + NL + "\t\t__NOP();__NOP();__NOP();__NOP();" + NL + "\t}" + NL + "" + NL + "}";
  protected final String TEXT_53 = NL + "static void OSCULP_init(void)" + NL + "{" + NL + "    /*enable OSCUL*/" + NL + "    SCU_HIBERNATE->OSCULCTRL &= (uint32_t)~SCU_HIBERNATE_OSCULCTRL_MODE_Msk;" + NL + "    while (SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_OSCULCTRL_Msk)" + NL + "    {}" + NL + "      " + NL + "    /*now check if the clock is OK using OSCULP Oscillator Watchdog (ULPWDG)*/" + NL + "    /*enable OSCULP WDG Alarm Enable*/" + NL + "    SCU_HIBERNATE->HDCR |= (uint32_t)SCU_HIBERNATE_HDCR_ULPWDGEN_Msk;" + NL + "    while (SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_HDCR_Msk)" + NL + "    {}" + NL + "" + NL + "    while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!=\\" + NL + "\t       SCU_INTERRUPT_SRRAW_HDCR_Msk)" + NL + "    {}" + NL + "    SCU_INTERRUPT->SRCLR |= (uint32_t)SCU_INTERRUPT_SRCLR_HDCR_Msk;" + NL + "" + NL + "    /*wait now for clock is stable */" + NL + "    do" + NL + "    {" + NL + "      SCU_HIBERNATE->HDCLR |= (uint32_t)SCU_HIBERNATE_HDCLR_ULPWDG_Msk;" + NL + "      while (SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_HDCLR_Msk)" + NL + "      {}" + NL + "      /*insert some delay */" + NL + "      Delay(CLK001_DELAY_CNT_50US_50MHZ); /*~50us @ maximum back up clock freq*/" + NL + "    } while ((SCU_HIBERNATE->HDSTAT & SCU_HIBERNATE_HDSTAT_ULPWDG_Msk)\\" + NL + "                               ==SCU_HIBERNATE_HDSTAT_ULPWDG_Msk); " + NL + "    SCU_HIBERNATE->HDCLR |= (uint32_t)SCU_HIBERNATE_HDCLR_ULPWDG_Msk;" + NL + "    while (SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_HDCLR_Msk)" + NL + "    {}" + NL + "}";
  protected final String TEXT_54 = NL + "/**" + NL + "  * @brief  Function to setup the external clock pin based on UI configuration " + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval None" + NL + "  */" + NL + "static void External_Clock_Signal_init(void){    ";
  protected final String TEXT_55 = "    " + NL + "    /* Select the External clock to be observed on Pin and" + NL + "    configure the divide value for pll clock output(if opted)*/" + NL + "  SCU_CLK->EXTCLKCR = ((uint32_t)";
  protected final String TEXT_56 = "U << SCU_CLK_EXTCLKCR_ECKSEL_Pos) |\\" + NL + "                      ((uint32_t)";
  protected final String TEXT_57 = "U << SCU_CLK_EXTCLKCR_ECKDIV_Pos);" + NL + "" + NL + "  /*Select Driver mode for the external clock pin*/                    ";
  protected final String TEXT_58 = NL + "  PORT";
  protected final String TEXT_59 = "->PDR0    &= (uint32_t)(~(PORT";
  protected final String TEXT_60 = "_PDR0_PD";
  protected final String TEXT_61 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_62 = "->PDR0    |= (((uint32_t)";
  protected final String TEXT_63 = " << PORT";
  protected final String TEXT_64 = "_PDR0_PD";
  protected final String TEXT_65 = "_Pos) & \\" + NL + "                              (uint32_t)PORT";
  protected final String TEXT_66 = "_PDR0_PD";
  protected final String TEXT_67 = "_Msk);";
  protected final String TEXT_68 = NL + "  PORT";
  protected final String TEXT_69 = "->PDR1 &= (uint32_t)(~(PORT";
  protected final String TEXT_70 = "_PDR1_PD";
  protected final String TEXT_71 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_72 = "->PDR1 |= (((uint32_t)";
  protected final String TEXT_73 = " << PORT";
  protected final String TEXT_74 = "_PDR1_PD";
  protected final String TEXT_75 = "_Pos) & \\" + NL + "                           (uint32_t)PORT";
  protected final String TEXT_76 = "_PDR1_PD";
  protected final String TEXT_77 = "_Msk);" + NL + "}" + NL + "                    ";
  protected final String TEXT_78 = " " + NL + "/**" + NL + "  * @brief  Function to check current MAIN Clock setting based on UI configuration " + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval PASS/FAIL" + NL + "  */" + NL + "static uint32_t System_Clock_valid(void)" + NL + "{" + NL + "  uint32_t MAIN_clock_status = 1U;" + NL + "" + NL + "  /* check if PLL is switched on */" + NL + "  if((SCU_PLL->PLLCON0 &(SCU_PLL_PLLCON0_VCOPWD_Msk | SCU_PLL_PLLCON0_PLLPWD_Msk))!= 0U)" + NL + "  {" + NL + "    MAIN_clock_status=0U;" + NL + "  }" + NL + "  return(MAIN_clock_status);" + NL + "}" + NL + "" + NL + "/**" + NL + "  * @brief  Function to initialize the Main Clock based on UI configuration " + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval PASS/FAIL" + NL + "  */" + NL + "static uint32_t System_Clock_init(void)" + NL + "{" + NL + "\tuint32_t Return_status = 1U;" + NL + "#if ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \\" + NL + "    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_NORMAL))" + NL + "  uint32_t VCO; " + NL + "  uint32_t stepping_K2DIV;\t" + NL + "#endif" + NL + "#if (((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \\" + NL + "    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_PRESCALER) && \\" + NL + "    (CLK001_PLL_CLOCK_INPUT != CLK001_CLOCK_BACK_UP_CLOCK))|| \\" + NL + "    ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \\" + NL + "    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_NORMAL)))" + NL + "  uint32_t timeout_count;" + NL + "#endif" + NL + "  /*Back up clock trimming*/" + NL + "#if ((CLK001_TRIM_OPTION == CLK001_CLOCK_TRIM_AUTOMATIC)&& \\" + NL + "    (CLK001_STANDBY_CLOCK == CLK001_HIB_CLOCK_FOSI))" + NL + "  {" + NL + "  " + NL + "     /* check if HIB Domain enabled  */" + NL + "     if((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk) == 0U)" + NL + "     {" + NL + "       SCU_POWER->PWRSET |= (uint32_t)SCU_POWER_PWRSET_HIB_Msk;/*enable Hibernate domain*/" + NL + "     }" + NL + "" + NL + "     /* check if HIB Domain is not in reset state  */" + NL + "     if ((SCU_RESET->RSTSTAT & SCU_RESET_RSTSTAT_HIBRS_Msk) != 0U)" + NL + "     {" + NL + "\t     /*de-assert hibernate reset*/" + NL + "       SCU_RESET->RSTCLR |= (uint32_t)SCU_RESET_RSTCLR_HIBRS_Msk;" + NL + "     }" + NL + "     SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_FOTR_Msk;" + NL + "     /*insert some delay */" + NL + "     Delay(CLK001_DELAY_CNT_50US_50MHZ); /*~50us @ maximum back up clock freq*/" + NL + "     SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_AOTREN_Msk;" + NL + "  }" + NL + "#elif((CLK001_TRIM_OPTION == CLK001_CLOCK_TRIM_AUTOMATIC)&& \\" + NL + "     (CLK001_STANDBY_CLOCK == CLK001_HIB_CLOCK_OSCULP))" + NL + "  {" + NL + "    /* check for HIB Domain enabled  */" + NL + "    if((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk) == 0U)" + NL + "    {" + NL + "      SCU_POWER->PWRSET |= (uint32_t)SCU_POWER_PWRSET_HIB_Msk;/*enable Hibernate domain*/" + NL + "    }" + NL + "" + NL + "    /* check for HIB Domain is not in reset state  */" + NL + "    if ((SCU_RESET->RSTSTAT & SCU_RESET_RSTSTAT_HIBRS_Msk) != 0U)" + NL + "    {" + NL + "      /*de-assert hibernate reset*/" + NL + "      SCU_RESET->RSTCLR |= (uint32_t)SCU_RESET_RSTCLR_HIBRS_Msk;" + NL + "    }" + NL + "    /*check OSCUL if running correct*/" + NL + "    if ((SCU_HIBERNATE->OSCULCTRL & SCU_HIBERNATE_OSCULCTRL_MODE_Msk) != 0U)" + NL + "    {" + NL + "      OSCULP_init();" + NL + "\t  /* select OSCUL clock for RTC*/" + NL + "      SCU_HIBERNATE->HDCR |= (uint32_t)SCU_HIBERNATE_HDCR_RCS_Msk;" + NL + "      while (SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_HDCR_Msk)" + NL + "      {}" + NL + "" + NL + "      while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!=\\" + NL + "\t       SCU_INTERRUPT_SRRAW_HDCR_Msk)" + NL + "      {}" + NL + "      SCU_INTERRUPT->SRCLR |= (uint32_t)SCU_INTERRUPT_SRCLR_HDCR_Msk;" + NL + "    }              " + NL + "      " + NL + "    /* now OSCULP is running and can be used*/" + NL + "    SCU_HIBERNATE->HDCR  |= (uint32_t)SCU_HIBERNATE_HDCR_STDBYSEL_Msk;" + NL + "    while((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk)!= \\" + NL + "\t       SCU_POWER_PWRSTAT_HIBEN_Msk)" + NL + "    {}" + NL + "" + NL + "    while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!= \\" + NL + "\t       SCU_INTERRUPT_SRRAW_HDCR_Msk)" + NL + "    {}" + NL + "    SCU_INTERRUPT->SRCLR |= (uint32_t)SCU_INTERRUPT_SRCLR_HDCR_Msk;" + NL + "\t" + NL + "    SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_FOTR_Msk;" + NL + "    " + NL + "    /*insert some delay */" + NL + "    Delay(CLK001_DELAY_CNT_50US_50MHZ);/*~50us @ maximum back up clock freq*/" + NL + "    SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_AOTREN_Msk;" + NL + "" + NL + "  }" + NL + "#else /*trimming option is factory trimming*/" + NL + "  {" + NL + "    SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_FOTR_Msk;" + NL + "  }" + NL + "#endif /*end of trimming options*/" + NL + "  /*insert some delay after trimming is enabled*/" + NL + "  Delay(CLK001_DELAY_CNT_50US_50MHZ);/*~50us @ maximum back up clock freq*/" + NL + "" + NL + "  /*Select system clock = back up clock (is the default configuration anyway)*/" + NL + "#if (CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_BACKUP)" + NL + "  {" + NL + "    SCU_CLK->SYSCLKCR &= (uint32_t)~(SCU_CLK_SYSCLKCR_SYSSEL_Msk);" + NL + "  }" + NL + "  /*system clock = pll */" + NL + "#else/*(CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL)*/" + NL + "  {" + NL + "    /* enable PLL first */" + NL + "    SCU_PLL->PLLCON0 &= (uint32_t)~(SCU_PLL_PLLCON0_VCOPWD_Msk | SCU_PLL_PLLCON0_PLLPWD_Msk);" + NL + "" + NL + "    /*if crystal or external digital input for PLL input*/" + NL + "#if ((CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_CRYSTAL)||\\" + NL + "    (CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_EXT_CLOCK))" + NL + "    {" + NL + "      /************************************************************************/" + NL + "      /*    Use external crystal or digital input for PLL clock input         */" + NL + "      /************************************************************************/ " + NL + "" + NL + "      /* Enable OSC_HP if not already on */" + NL + "      if ((SCU_OSC->OSCHPCTRL & SCU_OSC_OSCHPCTRL_MODE_Msk) != \\" + NL + "         ((uint32_t)CLK001_OSC_HP_MODE << SCU_OSC_OSCHPCTRL_MODE_Pos))" + NL + "      {" + NL + "        /*The OSC HP mode is guaranteed to  be = 11b at this point" + NL + "        * so we can just clear the bit(s) as per the selected mode" + NL + "        */" + NL + "        SCU_OSC->OSCHPCTRL &= (((uint32_t)(~(uint32_t)SCU_OSC_OSCHPCTRL_MODE_Msk)) | \\" + NL + "           ((uint32_t)CLK001_OSC_HP_MODE << SCU_OSC_OSCHPCTRL_MODE_Pos));" + NL + "" + NL + "        /* setup OSC WDG divider - at this point the bitfield would be 0" + NL + "        hence we can OR with the desired value*/" + NL + "        SCU_OSC->OSCHPCTRL |=" + NL + "          ((uint32_t)((CLK001_CLOCK_CRYSTAL_FREQUENCY/CLK001_SOSCWDG_FREF)-1)\\" + NL + "                                              <<SCU_OSC_OSCHPCTRL_OSCVAL_Pos);" + NL + "        /* select external OSC as PLL input */" + NL + "        SCU_PLL->PLLCON2 &= (uint32_t)~SCU_PLL_PLLCON2_PINSEL_Msk;" + NL + "        /* restart OSC Watchdog */" + NL + "        SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_OSCRES_Msk;" + NL + "" + NL + "        /*approx loop count for 150ms @ max untrimmed Backup clock freq*/" + NL + "        timeout_count = CLK001_LOOP_CNT_150MS; " + NL + "        do " + NL + "        {" + NL + "          /* time out after ~150ms  */" + NL + "          Delay(CLK001_DELAY_CNT_8US_50MHZ);  " + NL + "          timeout_count--;" + NL + "" + NL + "        }while((((SCU_PLL->PLLSTAT) & CLK001_PLLSTAT_OSC_USABLE_MASK) != \\" + NL + "              CLK001_PLLSTAT_OSC_USABLE_MASK) && (timeout_count !=0U));" + NL + "" + NL + "        if (((SCU_PLL->PLLSTAT) & CLK001_PLLSTAT_OSC_USABLE_MASK) != \\" + NL + "              CLK001_PLLSTAT_OSC_USABLE_MASK)" + NL + "        {" + NL + "           /* Return Error */" + NL + "        \tReturn_status = 0U;" + NL + "        }" + NL + "      }" + NL + "    }" + NL + "#else /*PLL clock source is back up clock */" + NL + "    {" + NL + "      /*select Backup Clock as input to PLL*/" + NL + "      SCU_PLL->PLLCON2 |= (uint32_t)SCU_PLL_PLLCON2_PINSEL_Msk;" + NL + "    }" + NL + "#endif /*end of PLL clock source check */" + NL + "    /**************************************************************************/" + NL + "    /*   Setup and lock the main PLL (PLL is in normal mode)                  */" + NL + "    /**************************************************************************/" + NL + "#if ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \\" + NL + "    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_NORMAL))" + NL + "    {" + NL + "      if ((SCU_PLL->PLLSTAT & SCU_PLL_PLLSTAT_VCOLOCK_Msk)!= \\" + NL + "\t       SCU_PLL_PLLSTAT_VCOLOCK_Msk)" + NL + "      {" + NL + "        /* System is still running from Backup clock */ " + NL + "       " + NL + "        /*Calculation for stepping*/" + NL + "#if((CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_CRYSTAL)||\\" + NL + "   (CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_EXT_CLOCK))" + NL + "        {" + NL + "          VCO = (CLK001_CLOCK_CRYSTAL_FREQUENCY/ \\" + NL + "                (CLK001_PLL_PDIV+1))*(CLK001_PLL_NDIV+1);" + NL + "        }" + NL + "#else /*PLL clcok source is back up clock in normal mode*/" + NL + "        {" + NL + "          VCO = (CLK001_CLOCK_BACK_UP/(CLK001_PLL_PDIV+1U))*(CLK001_PLL_NDIV+1U);" + NL + "        }" + NL + "#endif /*End of PLL clock source check in normal mode*/" + NL + "        stepping_K2DIV = (VCO/CLK001_PLL_FREQ_STEP1)-1U;" + NL + "           " + NL + "        /* Go to bypass the Main PLL */" + NL + "        SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_VCOBYP_Msk;" + NL + "        /* disconnect Oscillator from PLL */" + NL + "        SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_FINDIS_Msk;" + NL + "        /* Setup divider settings for main PLL */" + NL + "        SCU_PLL->PLLCON1 =(((uint32_t)CLK001_PLL_K1DIV) | \\" + NL + "               ((uint32_t)CLK001_PLL_NDIV<<SCU_PLL_PLLCON1_NDIV_Pos) | \\" + NL + "               ((uint32_t)stepping_K2DIV<<SCU_PLL_PLLCON1_K2DIV_Pos) | \\" + NL + "               ((uint32_t)CLK001_PLL_PDIV<<SCU_PLL_PLLCON1_PDIV_Pos));" + NL + "        /* Set OSCDISCDIS */" + NL + "        SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_OSCDISCDIS_Msk;" + NL + "        /* connect Oscillator to PLL */" + NL + "        SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_FINDIS_Msk;" + NL + "        /* restart PLL Lock detection */" + NL + "        SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_RESLD_Msk;" + NL + "        /* wait for PLL Lock */" + NL + "" + NL + "        /* Timeout for wait loop ~150ms */" + NL + "        /*approx loop count for 150ms @ Backup Clock freq*/" + NL + "        timeout_count = CLK001_LOOP_CNT_150MS;" + NL + "        do" + NL + "        {" + NL + "          Delay(CLK001_DELAY_CNT_8US_50MHZ);  /*~8us Delay*/" + NL + "          timeout_count--;" + NL + "        } while (((SCU_PLL->PLLSTAT & SCU_PLL_PLLSTAT_VCOLOCK_Msk)!= \\" + NL + "\t\t           SCU_PLL_PLLSTAT_VCOLOCK_Msk)&& (timeout_count !=0U));" + NL + "" + NL + "        if ((SCU_PLL->PLLSTAT & SCU_PLL_PLLSTAT_VCOLOCK_Msk)== \\" + NL + "            SCU_PLL_PLLSTAT_VCOLOCK_Msk)" + NL + "        {" + NL + "          /* Disable bypass- put pll clock back */" + NL + "          SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_VCOBYP_Msk;" + NL + "        }" + NL + "        else" + NL + "        {" + NL + "          " + NL + "        \tReturn_status =0U;" + NL + "        }" + NL + "      }" + NL + "" + NL + "    }" + NL + "#endif /*end of setting PLL is in Normal mode - first frequency stepping*/" + NL + "    /**************************************************************************/" + NL + "    /*   Setup main PLL (PLL is in prescaler mode)                            */" + NL + "    /**************************************************************************/" + NL + "#if ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \\" + NL + "    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_PRESCALER))" + NL + "    {" + NL + "      /* Program PLL for Prescaler mode*/" + NL + "      SCU_PLL->PLLCON0 |= \\" + NL + "             (SCU_PLL_PLLCON0_VCOBYP_Msk|SCU_PLL_PLLCON0_VCOPWD_Msk);" + NL + "              " + NL + "      /* wait for Prescaler mode to be entered*/" + NL + "      while ((SCU_PLL->PLLSTAT & SCU_PLL_PLLSTAT_VCOBYST_Msk)!= \\" + NL + "\t          SCU_PLL_PLLSTAT_VCOBYST_Msk)" + NL + "      {}" + NL + "       " + NL + "      /* Choose fOSC as an input to K1divider*/" + NL + "#if((CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_CRYSTAL)||\\" + NL + "   (CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_EXT_CLOCK))" + NL + "      {" + NL + "        SCU_PLL->PLLCON2 &= (uint32_t)~SCU_PLL_PLLCON2_K1INSEL_Msk;" + NL + "      }" + NL + "#else /*Input to K1 divider is back up clock*/" + NL + "      {" + NL + "        SCU_PLL->PLLCON2 |= (uint32_t)SCU_PLL_PLLCON2_K1INSEL_Msk;" + NL + "      }" + NL + "#endif /*end of input selection for K1 dividier*/" + NL + "      /* Setup K1 divider for main PLL */" + NL + "      SCU_PLL->PLLCON1 = CLK001_PLL_K1DIV;" + NL + "    }" + NL + "#endif /*end of Prescaler mode settings*/" + NL + "\t    /* Switch system clock to PLL */" + NL + "    SCU_CLK->SYSCLKCR |=  (uint32_t)1 << SCU_CLK_SYSCLKCR_SYSSEL_Pos;" + NL + "  }/*end of PLL configuration if PLL is the system clock" + NL + "    (but it is pending frequency stepping to the target frequency)*/" + NL + "#endif /*end of system clock selection - PLL Vs Back up clock*/" + NL + "  " + NL + "\t/*******************************************************************" + NL + "\tBefore scaling to final frequency we need to setup the clock dividers " + NL + "\t*******************************************************************/" + NL + "\t";
  protected final String TEXT_79 = NL + "\t/* Setup PB Clock Divider */" + NL + "\tSCU_CLK->PBCLKCR |= (uint32_t)SCU_CLK_PBCLKCR_PBDIV_Msk;" + NL + "\t";
  protected final String TEXT_80 = NL + "\t";
  protected final String TEXT_81 = NL + "\t/* Setup CPU Clock Divider */" + NL + "\tSCU_CLK->CPUCLKCR |= (uint32_t)SCU_CLK_CPUCLKCR_CPUDIV_Msk;" + NL + "\t";
  protected final String TEXT_82 = NL + "\t";
  protected final String TEXT_83 = " " + NL + "\t/* Setup CCU Clock Divider */" + NL + "\tSCU_CLK->CCUCLKCR |= (uint32_t)SCU_CLK_CCUCLKCR_CCUDIV_Msk;" + NL + "\t";
  protected final String TEXT_84 = NL + "\t";
  protected final String TEXT_85 = "    " + NL + "\t/* Set WDT Clock divide value */" + NL + "\tSCU_CLK->WDTCLKCR |= ";
  protected final String TEXT_86 = "U;" + NL + "\t";
  protected final String TEXT_87 = NL + "\t";
  protected final String TEXT_88 = "    " + NL + "\t/* Set EBU Clock divide value */" + NL + "\tSCU_CLK->EBUCLKCR |= ";
  protected final String TEXT_89 = "U;" + NL + "\t";
  protected final String TEXT_90 = NL + NL + NL + "  /***************************************************************************/" + NL + "  /*   Frequency stepping for main PLL (PLL is in normal mode)               */" + NL + "  /***************************************************************************/" + NL + "#if ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \\" + NL + "    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_NORMAL))" + NL + "  {" + NL + "" + NL + "    /* Reset OSCDISCDIS */" + NL + "    SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_OSCDISCDIS_Msk;" + NL + "" + NL + "" + NL + "" + NL + "    /*********************************************************" + NL + "    here the ramp up of the system clock to FSys < 60MHz" + NL + "    *********************************************************/" + NL + "#if (CLK001_CLOCK_FSYS > CLK001_PLL_FREQ_STEP2)" + NL + "    {" + NL + "      /*********************************************************/" + NL + "      /* Delay for next K2 step ~50?s */" + NL + "      /*********************************************************/" + NL + "      Delay(CLK001_DELAY_CNT_50US_50MHZ); /*~50us Backup clock*/" + NL + "" + NL + "      /*calculation for stepping*/" + NL + "      stepping_K2DIV = (VCO/CLK001_PLL_FREQ_STEP2)-1;\t" + NL + "" + NL + "      /*Setup divider settings for main PLL */" + NL + "      SCU_PLL->PLLCON1 =(((uint32_t)CLK001_PLL_K1DIV) | \\" + NL + "               ((uint32_t)CLK001_PLL_NDIV<<SCU_PLL_PLLCON1_NDIV_Pos)|\\" + NL + "               ((uint32_t)stepping_K2DIV<<SCU_PLL_PLLCON1_K2DIV_Pos)|\\" + NL + "               ((uint32_t)CLK001_PLL_PDIV<<SCU_PLL_PLLCON1_PDIV_Pos));" + NL + "    }" + NL + "#endif /*end of check - if PLL target frequency is greater than 60 MHz*/" + NL + "" + NL + "" + NL + "    /*********************************************************" + NL + "    here the ramp up of the system clock to FSys < 90MHz" + NL + "    *********************************************************/" + NL + "#if (CLK001_CLOCK_FSYS > CLK001_PLL_FREQ_STEP3)" + NL + "    {" + NL + "      " + NL + "      /*********************************************************/" + NL + "      /* Delay for next K2 step ~50us */" + NL + "      /*********************************************************/" + NL + "      Delay(CLK001_DELAY_CNT_50US_50MHZ); /*~50?s @ 60MHz clock*/" + NL + "      " + NL + "      /*calulation for stepping*/" + NL + "      stepping_K2DIV = (VCO/CLK001_PLL_FREQ_STEP3)-1;\t\t\t" + NL + "" + NL + "      /* Setup Divider settings for main PLL */" + NL + "" + NL + "      SCU_PLL->PLLCON1 = (((uint32_t)CLK001_PLL_K1DIV) | \\" + NL + "                        ((uint32_t)CLK001_PLL_NDIV<<SCU_PLL_PLLCON1_NDIV_Pos)| \\" + NL + "              ((uint32_t)stepping_K2DIV<<SCU_PLL_PLLCON1_K2DIV_Pos)| \\" + NL + "              ((uint32_t)CLK001_PLL_PDIV<<SCU_PLL_PLLCON1_PDIV_Pos));" + NL + "    }" + NL + "#endif /*end of check if PLL target frequency is more than 90 MHz*/" + NL + "" + NL + "    /*********************************************************/" + NL + "    /* Delay for next K2 step ~50?s */" + NL + "    /*********************************************************/" + NL + "" + NL + "    Delay(CLK001_DELAY_CNT_50US_90MHZ); /*~50us @ 90 MHz clock*/" + NL + "" + NL + "    /*********************************************************/" + NL + "" + NL + "    /* Setup Divider settings for main PLL */" + NL + "    SCU_PLL->PLLCON1 = (((uint32_t)CLK001_PLL_K1DIV) | \\" + NL + "            ((uint32_t)CLK001_PLL_NDIV<<SCU_PLL_PLLCON1_NDIV_Pos)  | \\" + NL + "            ((uint32_t)CLK001_PLL_K2DIV<<SCU_PLL_PLLCON1_K2DIV_Pos)| \\" + NL + "            ((uint32_t)CLK001_PLL_PDIV<<SCU_PLL_PLLCON1_PDIV_Pos));" + NL + "            " + NL + "    /* clear request for System OCS Watchdog Trap and System VCO Lock Trap  */" + NL + "    SCU_TRAP->TRAPCLR = SCU_TRAP_TRAPCLR_SOSCWDGT_Msk |\\" + NL + "                        SCU_TRAP_TRAPCLR_SVCOLCKT_Msk; " + NL + "  }/*end PLL frequency stepping...*/" + NL + "#endif /*end of PLL frequency stepping in case of PLL normal mode*/" + NL + "   /*return success*/" + NL + "  return Return_status;" + NL + "}" + NL;
  protected final String TEXT_91 = "     " + NL + "/**" + NL + "  * @brief  Function to check current USB Clock setting based on UI configuration " + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval PASS/FAIL" + NL + "  */" + NL + "static uint32_t\tUSB_Clock_valid(void)" + NL + "{" + NL + "  uint32_t USB_clock_status = 1U;" + NL + "  /* check if PLL is switched on */" + NL + "  if((SCU_PLL->USBPLLCON &(SCU_PLL_USBPLLCON_VCOPWD_Msk | \\" + NL + "                           SCU_PLL_USBPLLCON_PLLPWD_Msk)) != 0U)" + NL + "  {" + NL + "    USB_clock_status=0U;" + NL + "  }" + NL + "  return(USB_clock_status);" + NL + "}" + NL + "" + NL + "/**" + NL + "  * @brief  Function to initialize the USB Clock based on UI configuration " + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval PASS/FAIL" + NL + "  */" + NL + "static uint32_t\tUSB_Clock_init(void)" + NL + "{" + NL + "" + NL + "  uint32_t timeout_count;" + NL + "  uint32_t Return_status = 1U;" + NL + "  /* enable USB PLL first */" + NL + "  SCU_PLL->USBPLLCON &= (uint32_t)~(SCU_PLL_USBPLLCON_VCOPWD_Msk | \\" + NL + "                         SCU_PLL_USBPLLCON_PLLPWD_Msk);" + NL + "" + NL + "  /* check and if not already running enable OSC_HP */" + NL + "  if ((SCU_OSC->OSCHPCTRL & SCU_OSC_OSCHPCTRL_MODE_Msk) != \\" + NL + "     ((uint32_t)CLK001_OSC_HP_MODE << SCU_OSC_OSCHPCTRL_MODE_Pos))" + NL + "  {" + NL + "    /* check if Main PLL is switched on for OSC WD*/" + NL + "    if ((SCU_PLL->PLLCON0 &(SCU_PLL_PLLCON0_VCOPWD_Msk | \\" + NL + "        SCU_PLL_PLLCON0_PLLPWD_Msk)) != 0U)" + NL + "    {" + NL + "      /* enable PLL first */" + NL + "      SCU_PLL->PLLCON0 &= (uint32_t)~(SCU_PLL_PLLCON0_VCOPWD_Msk | \\" + NL + "                           SCU_PLL_PLLCON0_PLLPWD_Msk);" + NL + "    }" + NL + "" + NL + "    /*The OSC HP mode is guaranteed to  be = 11b at this point" + NL + "    * so we can just clear the bit(s) as per the selected mode" + NL + "    */" + NL + "    SCU_OSC->OSCHPCTRL &= (((uint32_t)(~(uint32_t)SCU_OSC_OSCHPCTRL_MODE_Msk)) | \\" + NL + "       ((uint32_t)CLK001_OSC_HP_MODE << SCU_OSC_OSCHPCTRL_MODE_Pos));" + NL + "   " + NL + "    /* setup OSC WDG Divider */" + NL + "    SCU_OSC->OSCHPCTRL|=" + NL + "      ((uint32_t)((CLK001_CLOCK_CRYSTAL_FREQUENCY/CLK001_SOSCWDG_FREF)-1U)\\" + NL + "                                           <<SCU_OSC_OSCHPCTRL_OSCVAL_Pos);" + NL + "   " + NL + "    /* restart OSC Watchdog */" + NL + "    SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_OSCRES_Msk;  " + NL + "" + NL + "     /* Timeout for wait loo ~150ms */" + NL + "    /********************************/\t  " + NL + "    /*approx loop count for 150ms @ Backup Clock freq*/" + NL + "    timeout_count = CLK001_LOOP_CNT_150MS;" + NL + "    do" + NL + "    {" + NL + "      Delay(CLK001_DELAY_CNT_8US_50MHZ);  /*~8us Delay*/" + NL + "      timeout_count--;" + NL + "" + NL + "    }while((((SCU_PLL->PLLSTAT) & CLK001_PLLSTAT_OSC_USABLE_MASK) != \\" + NL + "          CLK001_PLLSTAT_OSC_USABLE_MASK) && (timeout_count !=0U));" + NL + "" + NL + "    if (((SCU_PLL->PLLSTAT) & CLK001_PLLSTAT_OSC_USABLE_MASK) != \\" + NL + "          CLK001_PLLSTAT_OSC_USABLE_MASK)" + NL + "    {" + NL + "      Return_status =0U;/* Return Error */" + NL + "    }" + NL + "  }" + NL + "" + NL + "  /* Setup USB PLL */" + NL + "  /* Go to bypass the USB PLL */" + NL + "  SCU_PLL->USBPLLCON |= (uint32_t)SCU_PLL_USBPLLCON_VCOBYP_Msk;" + NL + "  /* disconnect Oscillator from USB PLL */" + NL + "  SCU_PLL->USBPLLCON |= (uint32_t)SCU_PLL_USBPLLCON_FINDIS_Msk;" + NL + "  /* Setup Divider settings for USB PLL */" + NL + "  SCU_PLL->USBPLLCON =(((uint32_t)CLK001_USBPLL_NDIV<<SCU_PLL_USBPLLCON_NDIV_Pos)|\\" + NL + "                      ((uint32_t)CLK001_USBPLL_PDIV<<SCU_PLL_USBPLLCON_PDIV_Pos));" + NL + "  /* Setup USBDIV settings USB clock */" + NL + "  SCU_CLK->USBCLKCR = CLK001_USBDIV;" + NL + "  /* Set OSCDISCDIS */" + NL + "  SCU_PLL->USBPLLCON |= (uint32_t)SCU_PLL_USBPLLCON_OSCDISCDIS_Msk;" + NL + "  /* connect Oscillator to USB PLL */" + NL + "  SCU_PLL->USBPLLCON &= (uint32_t)~SCU_PLL_USBPLLCON_FINDIS_Msk;" + NL + "  /* restart PLL Lock detection */" + NL + "  SCU_PLL->USBPLLCON |= (uint32_t)SCU_PLL_USBPLLCON_RESLD_Msk;" + NL + "" + NL + "  /* wait for PLL Lock */" + NL + "  while ((SCU_PLL->USBPLLSTAT & SCU_PLL_USBPLLSTAT_VCOLOCK_Msk)!= \\" + NL + "          SCU_PLL_USBPLLSTAT_VCOLOCK_Msk)" + NL + "  {}" + NL + "" + NL + "  /* Enable USB Clock */" + NL + "  SCU_CLK->CLKSET |= (uint32_t)SCU_CLK_CLKSET_USBCEN_Msk;" + NL + "" + NL + "  return Return_status;" + NL + "} ";
  protected final String TEXT_92 = NL;
  protected final String TEXT_93 = NL + "/**" + NL + "  * @brief  Function to enable the CCU4 and CCU8 clock " + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval None" + NL + "  */" + NL + "  static void CCU_Clock_init(void){" + NL + "  /* Enable CCU Clock */" + NL + "  SCU_CLK->CLKSET |= (uint32_t)SCU_CLK_CLKSET_CCUCEN_Msk;" + NL + "}" + NL;
  protected final String TEXT_94 = NL;
  protected final String TEXT_95 = NL + "/**" + NL + "  * @brief  Function to enable the EBU clock " + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval None" + NL + "  */" + NL + "static void EBU_Clock_init(void)" + NL + "{" + NL + "  /* Enable EBU Clock */" + NL + "  SCU_CLK->CLKSET |= (uint32_t)SCU_CLK_CLKSET_EBUCEN_Msk;" + NL + "}" + NL;
  protected final String TEXT_96 = NL;
  protected final String TEXT_97 = NL;
  protected final String TEXT_98 = NL + "/**" + NL + "  * @brief  Function to enable the MMC clock " + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval None" + NL + "  */" + NL + "static void MMC_Clock_init(void){" + NL + "  /* Enable MMC Clock */" + NL + "  SCU_CLK->CLKSET |= (uint32_t)SCU_CLK_CLKSET_MMCCEN_Msk;" + NL + "}";
  protected final String TEXT_99 = NL;
  protected final String TEXT_100 = " " + NL + "/**" + NL + "  * @brief  Function to initialize the WDT clock based on UI configuration" + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval None" + NL + "  */" + NL + "static void WDT_Clock_init(void)" + NL + "{   ";
  protected final String TEXT_101 = NL + "  if ((SCU_HIBERNATE->OSCULCTRL & SCU_HIBERNATE_OSCULCTRL_MODE_Msk)!= 0U)" + NL + "  {" + NL + "    OSCULP_init();" + NL + "  }               " + NL + "  /* Select OSC_ULP */" + NL + "  /*Selecting Standby Clock Source*/" + NL + "  SCU_HIBERNATE->HDCR |= ((1U << SCU_HIBERNATE_HDCR_STDBYSEL_Pos) & \\" + NL + "                           SCU_HIBERNATE_HDCR_STDBYSEL_Msk);     " + NL + "  while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!=\\" + NL + "\t       SCU_INTERRUPT_SRRAW_HDCR_Msk)" + NL + "  {}" + NL + "  SCU_INTERRUPT->SRCLR |= SCU_INTERRUPT_SRCLR_HDCR_Msk;" + NL + " ";
  protected final String TEXT_102 = NL + "  /* Select the WDT Clock source */" + NL + "  SCU_CLK->WDTCLKCR = (uint32_t)((uint32_t)";
  protected final String TEXT_103 = " << SCU_CLK_WDTCLKCR_WDTSEL_Pos)& SCU_CLK_WDTCLKCR_WDTSEL_Msk;" + NL + "  /* Enable WDT Clock */" + NL + "  SCU_CLK->CLKSET |= (uint32_t)SCU_CLK_CLKSET_WDTCEN_Msk;" + NL + "}" + NL;
  protected final String TEXT_104 = NL + "/**" + NL + "  * @brief  Function to initialize the RTC clock based on UI configuration" + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval None" + NL + "  */" + NL + "static void RTC_Clock_init(void)" + NL + "{" + NL + "  /*before enabling hibernate domain (if opted), check if it is already enabled." + NL + "  we do not repeat the enable if already done*/" + NL + "  if((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk) == 0U )" + NL + "  {" + NL + "    /* Enable hibernate domain */" + NL + "    SCU_POWER->PWRSET = (uint32_t)(SCU_POWER_PWRSET_HIB_Msk);" + NL + "    " + NL + "    /* Wait until hibernate enable status is set */" + NL + "    while((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk)!= \\" + NL + "         SCU_POWER_PWRSTAT_HIBEN_Msk)" + NL + "    {}" + NL + "  }" + NL + "  /* check for HIB Domain is not in reset state  */" + NL + "  if ((SCU_RESET->RSTSTAT & SCU_RESET_RSTSTAT_HIBRS_Msk) != 0U)" + NL + "  {" + NL + "\t  SCU_RESET->RSTCLR |= (uint32_t)SCU_RESET_RSTCLR_HIBRS_Msk; /*de-assert hibernate reset*/" + NL + "  }" + NL + "  /*RTC Clock Source Selection*/";
  protected final String TEXT_105 = "   ";
  protected final String TEXT_106 = NL + "  /*check OSCUL if running correct*/" + NL + "  if ((SCU_HIBERNATE->OSCULCTRL & SCU_HIBERNATE_OSCULCTRL_MODE_Msk)!= 0U)" + NL + "  {" + NL + "    OSCULP_init();" + NL + "  }              " + NL + "" + NL + "    /* Select OSC_ULP */" + NL + "    /*Selecting RTC Clock Source*/" + NL + "  SCU_HIBERNATE->HDCR |= (uint32_t)(((uint32_t)1U << SCU_HIBERNATE_HDCR_RCS_Pos) & \\" + NL + "                           SCU_HIBERNATE_HDCR_RCS_Msk);" + NL + "  while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!=\\" + NL + "       SCU_INTERRUPT_SRRAW_HDCR_Msk)" + NL + "  {}" + NL + "  SCU_INTERRUPT->SRCLR |= (uint32_t)SCU_INTERRUPT_SRCLR_HDCR_Msk;" + NL + "    ";
  protected final String TEXT_107 = NL + "    /* Enable internal slow clock */" + NL + "\t/*Selecting RTC Clock Source*/" + NL + "  SCU_HIBERNATE->HDCR |= ((0U << SCU_HIBERNATE_HDCR_RCS_Pos) & \\" + NL + "                         SCU_HIBERNATE_HDCR_RCS_Msk); " + NL + "  while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!= \\" + NL + "         SCU_INTERRUPT_SRRAW_HDCR_Msk)" + NL + "  {}" + NL + "  SCU_INTERRUPT->SRCLR |= (uint32_t)SCU_INTERRUPT_SRCLR_HDCR_Msk;";
  protected final String TEXT_108 = NL + "\t" + NL + "}" + NL + "  ";
  protected final String TEXT_109 = NL + NL + "/*******************************************************************************" + NL + "**                      Public Function Definitions                           **" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + "  * @brief  Function to initialize the Clock Tree based on UI configuration" + NL + "  * @note   -  " + NL + "  * @param  None" + NL + "  * @retval None" + NL + "  */" + NL + "void CLK001_Init(void)" + NL + "{" + NL + "  /*<<<DD_CLK001_API_1>>>*/" + NL + " /*  Function to check the clock status based on UI configuration */" + NL + "  if(System_Clock_valid() == 0U)" + NL + "  {   " + NL + "    /*  Function to initialize the System Clock based on UI configuration */" + NL + "    System_Clock_init();" + NL + "  }";
  protected final String TEXT_110 = "     " + NL + "  /*  Function to initialize the USB Clock based on UI configuration */     " + NL + "  if(USB_Clock_valid() == 0U)" + NL + "  {   " + NL + "  \tUSB_Clock_init();" + NL + "  }";
  protected final String TEXT_111 = NL + "  /*  Function to enable the CCU Clock based on UI configuration */     " + NL + "  CCU_Clock_init();";
  protected final String TEXT_112 = " ";
  protected final String TEXT_113 = NL + "  /*  Function to enable the EBU Clock based on UI configuration */     " + NL + "  EBU_Clock_init();";
  protected final String TEXT_114 = NL;
  protected final String TEXT_115 = NL;
  protected final String TEXT_116 = NL + "  /*  Function to enable the MMC Clock based on UI configuration */" + NL + "  MMC_Clock_init();";
  protected final String TEXT_117 = NL;
  protected final String TEXT_118 = " " + NL + "   /*  Function to initialize the WDT Clock based on UI configuration */     " + NL + "  WDT_Clock_init();   ";
  protected final String TEXT_119 = " " + NL + "   /*  Function to initialize the RTC Clock based on UI configuration */     " + NL + "  RTC_Clock_init();   ";
  protected final String TEXT_120 = "   " + NL + "  /*  Function to initialize the External clock pin */     " + NL + "  External_Clock_Signal_init();";
  protected final String TEXT_121 = NL + "  /* Update the clock variable */" + NL + "  SystemCoreClockUpdate();" + NL + "}" + NL + "" + NL + "/*" + NL + " * This routine is called by CMSIS startup to find out if clock tree setup should" + NL + " * be done by it. This routine is WEAKLY defined in CStart." + NL + " *" + NL + " * In the absence of clock app, the weak definition takes precedence which always" + NL + " * permits clock tree setup by CStart." + NL + " *" + NL + " * When clock app is defined, this function overrides the CStart definition.Clock" + NL + " * tree setup is launched and upon completion, control is ceded back to CStart." + NL + " *" + NL + " * CStart abstains from setting up clock tree and instead proceeds with program" + NL + " * loading." + NL + " *" + NL + " * Return 0 to disallow CStart from performing clock tree setup." + NL + " */" + NL + "uint32_t AllowPLLInitByStartup(void)" + NL + "{" + NL + "\t/*" + NL + "\t * Let the CStart know that there is no more a need to perform clock tree" + NL + "\t * initialization." + NL + "\t */" + NL + "\treturn 0U;" + NL + "}" + NL + "" + NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_122 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri = "app/clk001/0";
     String MappedUri = null; 
    stringBuffer.append(TEXT_2);
     int Is44Device = -1; 
     int Is42Device = -1; 
     int Is45Device = -1; 
     Is44Device = ((app.getSoftwareId().substring(0,2).compareTo("44")==0)?1:0); 
     Is42Device = ((app.getSoftwareId().substring(0,2).compareTo("42")==0)?1:0); 
     Is45Device = ((app.getSoftwareId().substring(0,2).compareTo("45")==0)?1:0); 
    stringBuffer.append(TEXT_3);
     int Actual = app.getIntegerValue(AppBaseuri + "/clk001_iroActualFreqSystem");
    stringBuffer.append(TEXT_4);
     MappedUri = app.getMappedUri(AppBaseuri +  "/pll"); 
     if((MappedUri != null) && (MappedUri != "")) { 
    stringBuffer.append(TEXT_5);
    int PDIV = app.getIntegerValue(AppBaseuri + "/pll/pllcon1/pdiv");
    int NDIV = app.getIntegerValue(AppBaseuri + "/pll/pllcon1/ndiv");
    int K2DIV =app.getIntegerValue(AppBaseuri + "/pll/pllcon1/k2div");
    int K1DIV =app.getIntegerValue(AppBaseuri + "/pll/pllcon1/k1div");
    stringBuffer.append(TEXT_6);
    stringBuffer.append(K1DIV - 1);
    stringBuffer.append(TEXT_7);
    stringBuffer.append(K2DIV - 1);
    stringBuffer.append(TEXT_8);
    stringBuffer.append(PDIV - 1);
    stringBuffer.append(TEXT_9);
    stringBuffer.append(NDIV - 1);
    stringBuffer.append(TEXT_10);
    }
else{
    stringBuffer.append(TEXT_11);
    }
    stringBuffer.append(TEXT_12);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_irusbpllpdiv")-1));
    stringBuffer.append(TEXT_13);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_irusbpllndiv")-1));
    stringBuffer.append(TEXT_14);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_erwUSBClkDivider")-1));
    stringBuffer.append(TEXT_15);
    if((app.getIntegerValue(AppBaseuri + "/clk001_erwPLLClkSource/0")==1)){
    stringBuffer.append(TEXT_16);
    }else if((app.getIntegerValue(AppBaseuri + "/clk001_erwPLLClkSource/1")==1)){
    stringBuffer.append(TEXT_17);
    }else{
    stringBuffer.append(TEXT_18);
    }
    stringBuffer.append(TEXT_19);
    if((app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/1")==1)||(app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/2")==1)){
    stringBuffer.append(TEXT_20);
    }else if((app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/0")==1)||(app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/2")==1)){
    stringBuffer.append(TEXT_21);
    }
    stringBuffer.append(TEXT_22);
    if((app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/1")==1)||(app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/0")==1)){
    stringBuffer.append(TEXT_23);
    }else{
    stringBuffer.append(TEXT_24);
    }
    stringBuffer.append(TEXT_25);
    if((app.getIntegerValue(AppBaseuri + "/clk001_erwSystemClockSource/0")==1)){
    stringBuffer.append(TEXT_26);
    }else{
    stringBuffer.append(TEXT_27);
    }
    stringBuffer.append(TEXT_28);
    if((app.getIntegerValue(AppBaseuri + "/clk001_erwoperatingmode/0")==1)){
    stringBuffer.append(TEXT_29);
    }else{
    stringBuffer.append(TEXT_30);
    }
    stringBuffer.append(TEXT_31);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_iroActualFreqSystem")*1000000));
    stringBuffer.append(TEXT_32);
    if((app.getIntegerValue(AppBaseuri + "/clk001_erwPLLClkSource/0")==1)){
    stringBuffer.append(TEXT_33);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_irwExtOscRefFreq")*1000000));
    stringBuffer.append(TEXT_34);
    }else if((app.getIntegerValue(AppBaseuri + "/clk001_erwPLLClkSource/1")==1)){
    stringBuffer.append(TEXT_35);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_irwDigInputRefFreq")*1000000));
    stringBuffer.append(TEXT_36);
    }else{
    stringBuffer.append(TEXT_37);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_irwExtOscRefFreq")*1000000));
    stringBuffer.append(TEXT_38);
    }
    stringBuffer.append(TEXT_39);
    if ((app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/1") ==1)||
(app.getIntegerValue(AppBaseuri + "/clk001_erwSTDBYClkSource/0") ==1) ||
(app.getIntegerValue(AppBaseuri + "/clk001_erwRTCClkSource/0") ==1))
{
    stringBuffer.append(TEXT_40);
    }
     if (app.getIntegerValue(AppBaseuri + "/clk001_erwEnableExtClk/0") ==1)
{
    stringBuffer.append(TEXT_41);
    }
    stringBuffer.append(TEXT_42);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwUSBClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_43);
    }
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwCCUClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_44);
    }
    stringBuffer.append(TEXT_45);
    if (Is45Device==1)
{
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwEBUClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_46);
    }
    }
    stringBuffer.append(TEXT_47);
    if (Is45Device==1)
{
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwMMCClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_48);
    }
    }
    stringBuffer.append(TEXT_49);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwWDTClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_50);
    }
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwEnableHibernate/0") ==1)
{
    stringBuffer.append(TEXT_51);
    }
    stringBuffer.append(TEXT_52);
    if ((app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/1") ==1)||
(app.getIntegerValue(AppBaseuri + "/clk001_erwSTDBYClkSource/0") ==1) ||
(app.getIntegerValue(AppBaseuri + "/clk001_erwRTCClkSource/0") ==1))
{
    stringBuffer.append(TEXT_53);
    }
     if (app.getIntegerValue(AppBaseuri + "/clk001_erwEnableExtClk/0") ==1)
    {
    stringBuffer.append(TEXT_54);
    int PLLClkDiv = app.getIntegerValue(AppBaseuri + "/clk001_erwExtClkPLLDiv") -1;
    stringBuffer.append(TEXT_55);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + "/rgextclk/extclkcr/ecksel"));
    stringBuffer.append(TEXT_56);
    stringBuffer.append(PLLClkDiv );
    stringBuffer.append(TEXT_57);
     String pinUri = app.getMappedUri(AppBaseuri + "/clk_extpin"); 
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     String portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     String pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
     int PDR_PD1 = app.getIntegerValue(AppBaseuri + "/clk_extpin/pdr_pd");    
     int Pin = Integer.parseInt(pinNo);
     if(Pin < 8) {
    stringBuffer.append(TEXT_58);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_59);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_60);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_61);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_62);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_63);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_64);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_65);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_66);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_67);
     } else {
    stringBuffer.append(TEXT_68);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_69);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_70);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_71);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_72);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_73);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_74);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_75);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_76);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_77);
    }}} 
    stringBuffer.append(TEXT_78);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwPBClkDivider/0") ==1)
	{
    stringBuffer.append(TEXT_79);
    }
    stringBuffer.append(TEXT_80);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwCPUClkDivider/0") ==1)
	{
    stringBuffer.append(TEXT_81);
    }
    stringBuffer.append(TEXT_82);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwCCUClkEnable/0") ==1)
	{
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwCCUClkDIV/0") ==1)
	{
    stringBuffer.append(TEXT_83);
    }
    }
    stringBuffer.append(TEXT_84);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwWDTClkEnable/0") ==1)
	{
    stringBuffer.append(TEXT_85);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_erwWDTClkDIV")-1));
    stringBuffer.append(TEXT_86);
    }
    if (Is45Device==1)
    {
    stringBuffer.append(TEXT_87);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwEBUClkEnable/0") ==1)
	{
    stringBuffer.append(TEXT_88);
    stringBuffer.append((app.getIntegerValue(AppBaseuri + "/clk001_erwEBUClkDivider")-1));
    stringBuffer.append(TEXT_89);
    }
    }
    stringBuffer.append(TEXT_90);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwUSBClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_91);
    }
    stringBuffer.append(TEXT_92);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwCCUClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_93);
    }
    stringBuffer.append(TEXT_94);
    if (Is45Device==1)
{
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwEBUClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_95);
    }
    stringBuffer.append(TEXT_96);
    }
    stringBuffer.append(TEXT_97);
    if (Is45Device==1)
{
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwMMCClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_98);
    }
    }
    stringBuffer.append(TEXT_99);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwWDTClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_100);
    if((app.getIntegerValue(AppBaseuri + "/clk001_erwWDTClkSource/1") ==1)&&
(app.getIntegerValue(AppBaseuri + "/CLK001_clksourceconf/2") ==1))
{
    if(app.getIntegerValue(AppBaseuri + "/clk001_erwSTDBYClkSource/0") ==1)
{
    stringBuffer.append(TEXT_101);
    }}
    stringBuffer.append(TEXT_102);
    stringBuffer.append(app.getIntegerValue(AppBaseuri + "/wdt/wdtclkcr/wdtsel"));
    stringBuffer.append(TEXT_103);
    }
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwEnableHibernate/0") ==1)
{
    stringBuffer.append(TEXT_104);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwEnableHibernate/0") ==1)
  {
    stringBuffer.append(TEXT_105);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwRTCClkSource/0") ==1)
  {
    stringBuffer.append(TEXT_106);
    }else {
    stringBuffer.append(TEXT_107);
    }
    }
    stringBuffer.append(TEXT_108);
    }
    stringBuffer.append(TEXT_109);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwUSBClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_110);
    }
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwCCUClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_111);
    }
    stringBuffer.append(TEXT_112);
    if (Is45Device==1)
{
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwEBUClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_113);
    }
    }
    stringBuffer.append(TEXT_114);
    if (Is45Device==1)
{
    stringBuffer.append(TEXT_115);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwMMCClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_116);
    }
    }
    stringBuffer.append(TEXT_117);
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwWDTClkEnable/0") ==1)
{
    stringBuffer.append(TEXT_118);
    }
    if (app.getIntegerValue(AppBaseuri + "/clk001_erwEnableHibernate/0") ==1)
{
    stringBuffer.append(TEXT_119);
    }
     if (app.getIntegerValue(AppBaseuri + "/clk001_erwEnableExtClk/0") ==1)
  {
    stringBuffer.append(TEXT_120);
    }
    stringBuffer.append(TEXT_121);
    stringBuffer.append(TEXT_122);
    return stringBuffer.toString();
  }
}
