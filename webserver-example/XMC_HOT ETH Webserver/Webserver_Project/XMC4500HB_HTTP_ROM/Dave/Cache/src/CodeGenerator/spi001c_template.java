package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class spi001c_template
{
  protected static String nl;
  public static synchronized spi001c_template create(String lineSeparator)
  {
    nl = lineSeparator;
    spi001c_template result = new spi001c_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*CODE_BLOCK_BEGIN[SPI001.c]*/" + NL + "/******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                **" + NL + " All rights reserved.                                                        **" + NL + "                                                                             **" + NL + " Redistribution and use in source and binary forms, with or without          **" + NL + " modification,are permitted provided that the following conditions are met:  **" + NL + "                                                                             **" + NL + " *Redistributions of source code must retain the above copyright notice,     **" + NL + " this list of conditions and the following disclaimer.                       **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,  **" + NL + " this list of conditions and the following disclaimer in the documentation   **" + NL + " and/or other materials provided with the distribution.                      **" + NL + " *Neither the name of the copyright holders nor the names of its contributors**" + NL + " may be used to endorse or promote products derived from this software       **" + NL + " without specific prior written permission.                                  **" + NL + "                                                                             **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                 **" + NL + "                                                                             **" + NL + " To improve the quality of the software, users are encouraged to share       **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG      **" + NL + " dave@infineon.com).                                                         **" + NL + "                                                                             **" + NL + "*******************************************************************************" + NL + "**                                                                           **" + NL + "**                                                                           **" + NL + "** PLATFORM : Infineon XMC4000/ XMC1000 Series                               **" + NL + "**                                                                           **" + NL + "** COMPILER : Compiler Independent                                           **" + NL + "**                                                                           **" + NL + "** AUTHOR   : App Developer                                                  **" + NL + "**                                                                           **" + NL + "** MAY BE CHANGED BY USER [yes/no]: Yes                                      **" + NL + "**                                                                           **" + NL + "** MODIFICATION DATE : May 30, 2013                                          **" + NL + "**                                                                           **" + NL + "******************************************************************************/" + NL + "/******************************************************************************" + NL + "**                      Author(s) Identity                                   **" + NL + "*******************************************************************************" + NL + "**                                                                           **" + NL + "** Initials    Name                                                          **" + NL + "** --------------------------------------------------------------------------**" + NL + "** AEP         App Developer                                                 **" + NL + "**                                                                           **" + NL + "******************************************************************************/" + NL + "" + NL + "/**";
  protected final String TEXT_2 = NL + " *" + NL + " * @file SPI001.c" + NL + " *" + NL + " * @App Version SPI001 <";
  protected final String TEXT_3 = ">" + NL + " * " + NL + " * @brief  SPI001 App provides non reentrant APIs for higher level Apps " + NL + " *         which can be used in a Non -RTOS environment. " + NL + " *         Limitations of Simple SPI App" + NL + " *         a) Read/Write functions are non reentrant." + NL + " *         b) No support for DMA mode." + NL + " */" + NL + "/*" + NL + " * Revision History" + NL + " * 01 Jun 2012 v1.0.0   Initial version" + NL + " * 26 Jul 2012 v1.0.2   Modified to support Quad mode functionalities" + NL + " * 17 Aug 2012 v1.0.4   Macro correction in USIC.h,Fix for OutputEnable for " + NL + " *                      HW controlled pins " + NL + " * 04 Feb 2013 v1.0.12  1. Modified as per coding guidelines and MISRA checks" + NL + " *                      2. Modified for baud calculation during initialization." + NL + " *                      3. Modified the macros FUNCTION_ENTRY, FUNCTION_EXIT  " + NL + " *                      and ERROR" + NL + " *                      4. The hardcoded values are replaced with macros in " + NL + " *                      SPI001_lConfigureBaudRate() function." + NL + " *                      5. The PCTQ value updation in BRG register is removed  " + NL + " *                      as the value is taken as zero." + NL + " *                      6. Updatd for revision history alignments." + NL + " *                      7. Updated function SPI001_Init() for XMC1000 devices." + NL + " * 26 Mar 2013 v1.0.16  1. Corrected the revision history." + NL + " * 30 May 2013 v1.0.18  1. HW1 control path configuration added for XMC1000 " + NL + " *                      devices in SPI001_lInit() & SPI001_Configure()." + NL + " *                      2. HW0 control path configuration added for XMC4000 " + NL + " *                      in SPI001_lInit() for MRST & MTSR pins, if operation " + NL + " *                      mode is Half Duplex/Dual/Quad mode." + NL + " *                      3. Added CCR.MODE configurations in SPI001_lInit() " + NL + " *                      & SPI001_Configure() to disable the SPI mode before " + NL + " *                      configuring USIC registers & to enable the SPI mode " + NL + " *                      after configurations to avoid unintended edges.                 " + NL + " */" + NL + "" + NL + "/******************************************************************************" + NL + " ** INCLUDE FILES                                                            **" + NL + " *****************************************************************************/" + NL + "" + NL + "#include <DAVE3.h>" + NL + "#include \"../../inc/SPI001/Usic.h\"" + NL;
  protected final String TEXT_4 = "  " + NL + "/*****************************************************************************" + NL + "              DUMMY DEFINTIONS OF DEBUG LOG MACROS" + NL + "*****************************************************************************/" + NL + "/*These definitions are included here to avoid compilation errors," + NL + " since the DBG002 app is not part of the project. All the macros are defined" + NL + " as empty*/ " + NL + "#ifndef _DBG002_H_" + NL + "" + NL + "#define DBG002_RegisterCallBack(A,B,C)" + NL + "#define DBG002_I(e) " + NL + "#define DBG002_IG(e,g) " + NL + "#define DBG002_IH(e,h) " + NL + "#define DBG002_IP(e,p) " + NL + "#define DBG002_IGH(e,g,h) " + NL + "#define DBG002_IGP(e,g,p) " + NL + "#define DBG002_IHP(e,h,p) " + NL + "#define DBG002_IGHP(e,g,h,p) " + NL + "#define DBG002_N(e) " + NL + "#define DBG002_NG(e,g) " + NL + "#define DBG002_NH(e,h) " + NL + "#define DBG002_NP(e,p) " + NL + "#define DBG002_NGH(e,g,h) " + NL + "#define DBG002_NGP(e,g,p) " + NL + "#define DBG002_NHP(e,h,p) " + NL + "#define DBG002_NGHP(e,g,h,p) " + NL + "#define DBG002_ID(e) " + NL + "#define DBG002_IS(e) " + NL + "#define DBG002_ISG(e,g) " + NL + "#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)" + NL + "#define DBG002_CRITICAL(groupid,messageid,length,value)" + NL + "#define DBG002_ERROR(groupid,messageid,length,value)" + NL + "#define DBG002_WARNING(groupid,messageid,length,value)" + NL + "#define DBG002_INFO(groupid,messageid,length,value)" + NL + "#define DBG002_TRACE(groupid,messageid,length,value)" + NL + "#define DBG002_FUNCTION_ENTRY(GID, Status) " + NL + "#define DBG002_FUNCTION_EXIT(GID, Status) " + NL + "" + NL + "#endif/* End of defintions of dummy Debug Log macros*/";
  protected final String TEXT_5 = "                  " + NL + "" + NL + "/******************************************************************************" + NL + "**                      Private Macro Definitions                            **" + NL + "******************************************************************************/";
  protected final String TEXT_6 = "      ";
  protected final String TEXT_7 = " ";
  protected final String TEXT_8 = NL + "  /* System Core clock frequency in MHz */" + NL + "#define SPI001_CLOCK                    ";
  protected final String TEXT_9 = "F" + NL;
  protected final String TEXT_10 = NL + "/* CHANNEL IS NOT MAPPED */";
  protected final String TEXT_11 = "     " + NL + "#define APP_GID                         DBG002_GID_SPI001" + NL + "#define SPI001_TRMODE_Msk               (0x18U)" + NL + "#define SPI001_TBUFINDEX_Msk            (0x07U)" + NL + "#define SPI001_FLAG_REG_Msk             (0x000000E0U)" + NL + "#define SPI001_FLAG_STATUS_Msk          (0x0000001FU)" + NL + "" + NL + "#define SPI001_MAX_VALUE                1023" + NL + "/* (DCTQ + 1) DCTQ value is 1 */" + NL + "#define SPI001_DCTQ_VALUE               0x02 " + NL + "#define SPI001_MAX_STEPVALUE            1024" + NL + "/* Intermediate step value to calculate Pdiv */" + NL + "#define SPI001_IM_STEPVALUE             500 " + NL + "" + NL + "/******************************************************************************" + NL + "**                      Private Type Definitions                             **" + NL + "******************************************************************************/" + NL + "" + NL + "" + NL + "/******************************************************************************" + NL + "**                 Private Function Declarations:" + NL + "******************************************************************************/";
  protected final String TEXT_12 = NL + "void SPI001_lInit (const SPI001_HandleType* Handle);" + NL + "/* Function to get optimized PDIV and STEP value for the given baud rate */ ";
  protected final String TEXT_13 = NL + "void SPI001_lInit (const SPI001_HandleType* Handle, \\" + NL + "                                        const uint16_t* SPI001_Baud_Values);";
  protected final String TEXT_14 = NL + "void SPI001_lConfigureBaudRate\\" + NL + "                            (uint32_t BaudRate,uint32_t* Pdiv,uint32_t* Step);" + NL + "/* Clears the IOCR.PCR value of the Port Register  */" + NL + "void SPI001_lClearPortRegs(const SPI001_HandleType* Handle);" + NL + "/* Modify the MTSR2HW_PortRegs for full duplex operation */" + NL + "void SPI001_lMTSR2_Modfn(const SPI001_HandleType* Handle);" + NL + "/* Modify the MTSR3HW_PortRegs for full duplex operation */" + NL + "void SPI001_lMTSR3_Modfn(const SPI001_HandleType* Handle);" + NL + "/* Modify the MTSR/MRST Pin PortRegs for full duplex operation */" + NL + "void SPI001_lPinModfn_Fullduplex(const SPI001_HandleType* Handle);" + NL + "/******************************************************************************" + NL + "**                      Global Constant Definitions                          **" + NL + "******************************************************************************/" + NL + "" + NL + "/******************************************************************************" + NL + "**                      Global Variable Definitions                          **" + NL + "******************************************************************************/" + NL + "" + NL + "/******************************************************************************" + NL + "**                      Private Constant Definitions                         **" + NL + "******************************************************************************/";
  protected final String TEXT_15 = NL + "/* Array to hold SPI baud parameter values as per the configuration */" + NL + "/* Array[0] = step, Array[1] = pdiv */" + NL + "const uint16_t SPI001_Baud_Parameter_Values";
  protected final String TEXT_16 = "[] = {0x";
  protected final String TEXT_17 = "U, 0x";
  protected final String TEXT_18 = "U};";
  protected final String TEXT_19 = NL + "/* CHANNEL IS NOT MAPPED */";
  protected final String TEXT_20 = NL + NL + "/******************************************************************************" + NL + "**                 Function like macro definitions                           **" + NL + "******************************************************************************/" + NL + "/******************************************************************************" + NL + "**                      Private Function Definitions                         **" + NL + "******************************************************************************/" + NL + " /* Initializes the App based on User provide configuration. */";
  protected final String TEXT_21 = NL + " void SPI001_lInit (const SPI001_HandleType* Handle)";
  protected final String TEXT_22 = NL + " void SPI001_lInit (const SPI001_HandleType* Handle, \\" + NL + "                                        const uint16_t* SPI001_Baud_Values)";
  protected final String TEXT_23 = NL + "{";
  protected final String TEXT_24 = NL + "  uint32_t Brg_PDiv = 0x00U;" + NL + "  uint32_t Fdr_Step = 0x00U;";
  protected final String TEXT_25 = NL + "  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;" + NL + "  SPI001_PORTS_TypeDef* MTSR_PortRegs = Handle->PinHandle->PinPortRegs[0];" + NL + "  SPI001_PORTS_TypeDef* MRST_PortRegs = Handle->PinHandle->PinPortRegs[1];" + NL + "  uint8_t MTSRPin = Handle->PinHandle->Pin_Num[0];" + NL + "  uint8_t MRSTPin = Handle->PinHandle->Pin_Num[1];" + NL + "  " + NL + "  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);" + NL + "  /* <<<DD_SPI_API_1>>>*/" + NL + " " + NL + "  /** SPI initialization  */" + NL + "  " + NL + "  /* Disable SPI mode before configuring all USIC registers to avoid unintended edges */ " + NL + "  USICRegs->CCR &= ~( ((uint32_t)(USIC_SPI_MODE  & USIC_CH_CCR_MODE_Msk)));" + NL + "  " + NL + "  /* Enable the USIC Channel */" + NL + "  USICRegs->KSCFG |= ((((uint32_t) 0x01 & USIC_CH_KSCFG_MODEN_Msk)) | \\" + NL + "                      (((uint32_t)0x01 << USIC_CH_KSCFG_BPMODEN_Pos) & \\" + NL + "                        USIC_CH_KSCFG_BPMODEN_Msk)); ";
  protected final String TEXT_26 = NL + "  /* Get the optimum PDIV and STEP value for the given baudrate */" + NL + "  SPI001_lConfigureBaudRate(Handle->Config->BaudRate,&Brg_PDiv,&Fdr_Step);" + NL + " " + NL + "  /* Configuration of USIC Channel Fractional Divider */" + NL + "  /* Fractional divider mode selected */" + NL + "  USICRegs->FDR |= (((uint32_t)0x02 << USIC_CH_FDR_DM_Pos) \\" + NL + "                    & USIC_CH_FDR_DM_Msk);" + NL + "  " + NL + "  /* Step value loaded */" + NL + "  USICRegs->FDR |= ((uint32_t)Fdr_Step & USIC_CH_FDR_STEP_Msk);" + NL + " " + NL + "  /* Clock phase & Clock polarity configuration */" + NL + "  /* PCTQ value is zero */" + NL + "  USICRegs->BRG |= ((((uint32_t)Handle->Config->LeadTrailDelay << \\" + NL + "                     USIC_CH_BRG_DCTQ_Pos) & USIC_CH_BRG_DCTQ_Msk) | \\" + NL + "                   (((uint32_t)Brg_PDiv << USIC_CH_BRG_PDIV_Pos) & \\" + NL + "                     USIC_CH_BRG_PDIV_Msk) | \\" + NL + "                   (((uint32_t)0x02 << USIC_CH_BRG_CTQSEL_Pos) &  \\" + NL + "                      USIC_CH_BRG_CTQSEL_Msk) | \\" + NL + "                   (((((uint32_t)(Handle->Config->ClkPol) | \\" + NL + "                    ((uint32_t)Handle->Config->ClkPh << (uint32_t) 0x01)) \\" + NL + "                     << USIC_CH_BRG_SCLKCFG_Pos) & USIC_CH_BRG_SCLKCFG_Msk))); ";
  protected final String TEXT_27 = NL + " /* Configuration of USIC Channel Fractional Divider */" + NL + "  /* Fractional divider mode selected */" + NL + "  USICRegs->FDR |= (((uint32_t)0x02 << USIC_CH_FDR_DM_Pos) \\" + NL + "                    & USIC_CH_FDR_DM_Msk);" + NL + "  " + NL + "  /* Step value loaded */" + NL + "  USICRegs->FDR |= ( *SPI001_Baud_Values & USIC_CH_FDR_STEP_Msk);" + NL + " " + NL + "  /* Clock phase & Clock polarity configuration */" + NL + "  /* PCTQ value is zero */" + NL + "  USICRegs->BRG |= ((((uint32_t)Handle->Config->LeadTrailDelay << \\" + NL + "                     USIC_CH_BRG_DCTQ_Pos) & USIC_CH_BRG_DCTQ_Msk) | \\" + NL + "                   (((uint32_t)(*(1 + SPI001_Baud_Values)) << \\" + NL + "                     USIC_CH_BRG_PDIV_Pos) & USIC_CH_BRG_PDIV_Msk) | \\" + NL + "                   (((uint32_t)0x02 << USIC_CH_BRG_CTQSEL_Pos) &  \\" + NL + "                      USIC_CH_BRG_CTQSEL_Msk) | \\" + NL + "                   (((((uint32_t)(Handle->Config->ClkPol) | \\" + NL + "                    ((uint32_t)Handle->Config->ClkPh << (uint32_t) 0x01)) \\" + NL + "                     << USIC_CH_BRG_SCLKCFG_Pos) & USIC_CH_BRG_SCLKCFG_Msk))); ";
  protected final String TEXT_28 = NL + " " + NL + "  /* Configuration of USIC Shift Control */" + NL + "  /* Transmission Mode (TRM) = 1  */" + NL + "  /* Passive Data Level (PDL) = 1 */" + NL + "  USICRegs->SCTR |= \\" + NL + "          ((((uint32_t)Handle->Config->HBMode & USIC_CH_SCTR_SDIR_Msk)) | \\" + NL + "\t\t      (((uint32_t)0x01  <<  USIC_CH_SCTR_PDL_Pos ) & \\" + NL + "\t\t            \t\t                       USIC_CH_SCTR_PDL_Msk ) | \\" + NL + "\t\t      (((uint32_t)0x01  <<  USIC_CH_SCTR_TRM_Pos ) & \\" + NL + "\t\t                       \t\t               USIC_CH_SCTR_TRM_Msk ) | \\" + NL + "          (((Handle->Config->FrameLen-(uint32_t)0x01) << USIC_CH_SCTR_FLE_Pos)\\" + NL + "                                                 & USIC_CH_SCTR_FLE_Msk ) | \\" + NL + "          (((Handle->Config->WordLen-(uint32_t)0x01) << USIC_CH_SCTR_WLE_Pos) \\" + NL + "                                                &  USIC_CH_SCTR_WLE_Msk));" + NL + "  switch(Handle->Config->Mode)" + NL + "  {" + NL + "    case SPI001_STANDARD_FULLDUPLEX:" + NL + "      USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \\" + NL + "    \t                                            USIC_CH_DX0CR_INSW_Msk));" + NL + "      break;" + NL + "    case SPI001_STANDARD_HALFDUPLEX:" + NL + "" + NL + "      /* Enable hardware port control */" + NL + "      USICRegs->CCR |= ((((uint32_t)0x01 << USIC_CH_CCR_HPCEN_Pos) & \\" + NL + "                                                       USIC_CH_CCR_HPCEN_Msk));" + NL + "      USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \\" + NL + "                                                      USIC_CH_TCSR_HPCMD_Msk);" + NL + "      /* Enable loop back mode in input stages */" + NL + "      USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_INSW_Msk) | \\" + NL + "                          ((((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_DSEL_Msk)));";
  protected final String TEXT_29 = "                                           " + NL + "      MTSR_PortRegs->HWSEL  |= ((uint32_t)2 << (MTSRPin * (uint32_t)2));  ";
  protected final String TEXT_30 = NL + "      MTSR_PortRegs->HWSEL  |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  ";
  protected final String TEXT_31 = "                                               " + NL + "      break;      " + NL + "    case SPI001_DUAL:" + NL + "      /* Enable hardware port control */" + NL + "      USICRegs->CCR |= (((uint32_t)((uint32_t)0x02 << USIC_CH_CCR_HPCEN_Pos) &\\" + NL + "                                                       USIC_CH_CCR_HPCEN_Msk));" + NL + "      USICRegs->TCSR |= ((uint32_t)((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) \\" + NL + "                                                   & (USIC_CH_TCSR_HPCMD_Msk));" + NL + "       /* Enable loop back mode in input stages */" + NL + "      USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_DSEL_Msk)); " + NL + "      USICRegs->DX3CR |= ((((uint32_t)0x01 << USIC_CH_DX3CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX3CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX3CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX3CR_DSEL_Msk)); ";
  protected final String TEXT_32 = "                                           " + NL + "      MTSR_PortRegs->HWSEL |= ((uint32_t)2 << (MTSRPin * (uint32_t)2));" + NL + "      MRST_PortRegs->HWSEL |= ((uint32_t)2 << (MRSTPin * (uint32_t)2));  ";
  protected final String TEXT_33 = NL + "      MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  " + NL + "      MRST_PortRegs->HWSEL |= ((uint32_t)1 << (MRSTPin * (uint32_t)2));";
  protected final String TEXT_34 = NL + "     " + NL + "      break;" + NL + "    case SPI001_QUAD:" + NL + "      /* Enable hardware port control */" + NL + "      USICRegs->CCR |= (((uint32_t)0x03 << USIC_CH_CCR_HPCEN_Pos) & \\" + NL + "                                                        USIC_CH_CCR_HPCEN_Msk);" + NL + "      USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \\" + NL + "                                                       USIC_CH_TCSR_HPCMD_Msk);" + NL + "       /* Enable loop back mode in input stages */" + NL + "      USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_DSEL_Msk)); " + NL + "      USICRegs->DX3CR |= ((((uint32_t)0x01 << USIC_CH_DX3CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX3CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX3CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX3CR_DSEL_Msk));  " + NL + "      USICRegs->DX4CR |= ((((uint32_t)0x01 << USIC_CH_DX4CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX4CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX4CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX4CR_DSEL_Msk));  " + NL + "      USICRegs->DX5CR |= ((((uint32_t)0x01 << USIC_CH_DX5CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX5CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX5CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX5CR_DSEL_Msk));  ";
  protected final String TEXT_35 = "                                           " + NL + "      MTSR_PortRegs->HWSEL |= ((uint32_t)2 << (MTSRPin * (uint32_t)2));" + NL + "      MRST_PortRegs->HWSEL |= ((uint32_t)2 << (MRSTPin * (uint32_t)2));  ";
  protected final String TEXT_36 = NL + "      MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  " + NL + "      MRST_PortRegs->HWSEL |= ((uint32_t)1 << (MRSTPin * (uint32_t)2));";
  protected final String TEXT_37 = " " + NL + "" + NL + "      break;" + NL + "  }" + NL + "  /* Configuration of USIC Transmit Control/Status Register */ " + NL + "  /* TBUF Data Enable (TDEN) = 1 */" + NL + "  /* TBUF Data Single Shot Mode (TDSSM) = 1 */" + NL + "\tUSICRegs->TCSR |= ((((uint32_t)0x01  << USIC_CH_TCSR_TDEN_Pos) & \\" + NL + "  USIC_CH_TCSR_TDEN_Msk ) | \\" + NL + "    (((uint32_t)0x01  << USIC_CH_TCSR_TDSSM_Pos) & USIC_CH_TCSR_TDSSM_Msk));" + NL + "" + NL + "  /* Configuration of Protocol Control Register */ " + NL + "\t/* PCTQ1 value is zero */" + NL + "  /* Parity Error Interrupt generation is disabled*/" + NL + "  USICRegs->PCR_SSCMode |= " + NL + "      ((((uint32_t)0x01 & USIC_CH_PCR_SSCMode_MSLSEN_Msk)) | \\" + NL + "      (((uint32_t)0x01 << USIC_CH_PCR_SSCMode_SELCTR_Pos) & \\" + NL + "                                            USIC_CH_PCR_SSCMode_SELCTR_Msk) | \\" + NL + "      (((uint32_t)0x01 << USIC_CH_PCR_SSCMode_SELINV_Pos) & \\" + NL + "                                            USIC_CH_PCR_SSCMode_SELINV_Msk) | \\" + NL + "      (((uint32_t)0x02 << USIC_CH_PCR_SSCMode_CTQSEL1_Pos) & \\" + NL + "                                           USIC_CH_PCR_SSCMode_CTQSEL1_Msk) | \\" + NL + "      (((uint32_t)Handle->Config->NextFrameDelay << \\" + NL + "            USIC_CH_PCR_SSCMode_DCTQ1_Pos) & USIC_CH_PCR_SSCMode_DCTQ1_Msk) | \\" + NL + "      (((uint32_t)Handle->MSLSIntrEn << USIC_CH_PCR_SSCMode_MSLSIEN_Pos) & \\" + NL + "                                           USIC_CH_PCR_SSCMode_MSLSIEN_Msk) | \\" + NL + "      ((((uint32_t)0x01 << Handle->ChipSelTable[Handle->Config->CESelected]) \\" + NL + "           << USIC_CH_PCR_SSCMode_SELO_Pos) & USIC_CH_PCR_SSCMode_SELO_Msk) | \\" + NL + "      (((uint32_t)Handle->FrmEndMode << USIC_CH_PCR_SSCMode_FEM_Pos) \\" + NL + "                                             & USIC_CH_PCR_SSCMode_FEM_Msk));" + NL + "  /* Configuration of Transmitter Buffer Control Register */ " + NL + "  USICRegs->TBCTR |= ((((uint32_t)Handle->TxLimit  << \\" + NL + "                    USIC_CH_TBCTR_LIMIT_Pos ) & USIC_CH_TBCTR_LIMIT_Msk));" + NL + "    " + NL + "  /* Configuration of Receiver Buffer Control Register */ " + NL + "  USICRegs->RBCTR |= ((((uint32_t)Handle->RxLimit  << \\" + NL + "                USIC_CH_RBCTR_LIMIT_Pos) & USIC_CH_RBCTR_LIMIT_Msk) | \\" + NL + "                (((uint32_t)0x01   << USIC_CH_RBCTR_LOF_Pos) & \\" + NL + "                    USIC_CH_RBCTR_LOF_Msk));" + NL + "   " + NL + "  /* Configuration of Channel Control Register */ " + NL + "  /* parity generation is disabled*/" + NL + "  USICRegs->CCR |= ( ((uint32_t)(USIC_SPI_MODE  & USIC_CH_CCR_MODE_Msk)));" + NL + "    " + NL + "  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);" + NL + "}" + NL + "" + NL + "" + NL + "/* Give optimized PDIV and STEP value for the given baud rate */ " + NL + "void SPI001_lConfigureBaudRate(uint32_t BaudRate,uint32_t* Pdiv,uint32_t* Step)" + NL + "{" + NL + "" + NL + "\tfloat ratio, TempBaud,TempPdiv, TempStep;" + NL + "\tTempBaud = (float)BaudRate;" + NL + "\tratio = (float)((((SPI001_CLOCK * (float)1000000)/\\" + NL + "\t                 (float)(SPI001_DCTQ_VALUE * SPI001_MAX_STEPVALUE)) * \\" + NL + "\t                 (float)SPI001_IM_STEPVALUE)/(float)TempBaud);" + NL + "\t/* Calculating optimum PDIV value */" + NL + "\tif( ratio <= (float)1)" + NL + "  {" + NL + "\t\tTempPdiv = (float)0;" + NL + "  }" + NL + "  else" + NL + "  {" + NL + "    \tTempPdiv =  ratio -(float)1;" + NL + "      if( TempPdiv > (float)SPI001_MAX_VALUE)" + NL + "      {" + NL + "    \t  TempPdiv = (float)SPI001_MAX_VALUE;" + NL + "      }" + NL + "  }" + NL + "\t*Pdiv = (uint32_t)TempPdiv;" + NL + "    /* Calculating STEP value */" + NL + "\tTempStep = (float)(((((TempBaud * (float)SPI001_MAX_STEPVALUE)/ \\" + NL + "\t                    (float)1000000) * (float)SPI001_DCTQ_VALUE ) * \\" + NL + "                      ((float)1+ (float)(*Pdiv)))/(SPI001_CLOCK));" + NL + "" + NL + "  if(TempStep > (float)SPI001_MAX_VALUE)" + NL + "  {" + NL + "   \tTempStep = (float)SPI001_MAX_VALUE;" + NL + "  }" + NL + "  *Step = (uint32_t)TempStep;" + NL + "}" + NL + "" + NL + "/* Clears the IOCR.PCR value of the Port Register  */" + NL + "void SPI001_lClearPortRegs(const SPI001_HandleType* Handle)" + NL + "{" + NL + "\tuint8_t MTSRPin = Handle->PinHandle->Pin_Num[0];" + NL + "\tSPI001_PORTS_TypeDef* MTSR_PortRegs = Handle->PinHandle->PinPortRegs[0];" + NL + "  uint8_t Msk_IOCR = 0x07U;" + NL + "" + NL + "\tif(MTSRPin < 0x04U)" + NL + "  {" + NL + "\t  MTSR_PortRegs->IOCR0 &= ~((uint32_t)Msk_IOCR << (3U + (MTSRPin * 8U)));" + NL + " \t}" + NL + " \telse if ((MTSRPin > 0x03U) && (MTSRPin < 8U))" + NL + " \t{" + NL + " \t  MTSRPin = MTSRPin - 4U;" + NL + "\t  MTSR_PortRegs->IOCR4 &= ~((uint32_t)Msk_IOCR << (3U + (MTSRPin * 8U)));" + NL + " \t} " + NL + " \telse if ((MTSRPin > 7U) && (MTSRPin < 12U)) " + NL + " \t{" + NL + " \t  MTSRPin = MTSRPin - 8U;" + NL + "\t  MTSR_PortRegs->IOCR8 &= ~((uint32_t)Msk_IOCR << (3U + (MTSRPin * 8U)));" + NL + " \t} " + NL + " \telse if ((MTSRPin > 11U) && (MTSRPin < 16U)) " + NL + " \t{" + NL + " \t  MTSRPin = MTSRPin - 12U;" + NL + "\t  MTSR_PortRegs->IOCR12 &= ~((uint32_t)Msk_IOCR << (3U + (MTSRPin * 8U)));" + NL + "\t}" + NL + " \telse" + NL + " \t{" + NL + " \t  /* Do Nothing */" + NL + " \t}" + NL + "}" + NL + "" + NL + "/* Modify the MTSR2HW_PortRegs for full duplex operation */" + NL + "void SPI001_lMTSR2_Modfn(const SPI001_HandleType* Handle)" + NL + "{" + NL + "\tuint8_t MTSR2_HWPin = Handle->PinHandle->Pin_Num[2];" + NL + "\tSPI001_PORTS_TypeDef* MTSR2HW_PortRegs = Handle->PinHandle->PinPortRegs[2];" + NL + "\tuint8_t Msk_OE = 0x18U;" + NL + "" + NL + "  if(MTSR2_HWPin < 4U) " + NL + "  {" + NL + "    MTSR2HW_PortRegs->IOCR0 &= ~((uint32_t)Msk_OE << (3U+(MTSR2_HWPin*8U)));" + NL + "  }" + NL + "  else if ((MTSR2_HWPin > 3U) && (MTSR2_HWPin < 8U)) " + NL + "  {" + NL + "    MTSR2_HWPin = MTSR2_HWPin - 4U;" + NL + "    MTSR2HW_PortRegs->IOCR4 &= ~((uint32_t)Msk_OE << (3U+(MTSR2_HWPin*8U)));" + NL + "  } " + NL + "  else if ((MTSR2_HWPin > 7U) && (MTSR2_HWPin < 12U)) " + NL + "  {" + NL + "    MTSR2_HWPin = MTSR2_HWPin - 8U;" + NL + "    MTSR2HW_PortRegs->IOCR8 &= ~((uint32_t)Msk_OE << (3U+(MTSR2_HWPin*8U)));" + NL + "  } " + NL + "  else if ((MTSR2_HWPin > 11U) && (MTSR2_HWPin < 16U)) " + NL + "  {" + NL + "    MTSR2_HWPin = MTSR2_HWPin - 12U;" + NL + "    MTSR2HW_PortRegs->IOCR12 &= ~((uint32_t)Msk_OE << (3U+(MTSR2_HWPin*8U)));" + NL + "  }" + NL + "  else " + NL + "  {" + NL + "    /* Do Nothing */\t" + NL + "  }" + NL + "}" + NL + "" + NL + "/* Modify the MTSR3HW_PortRegs for full duplex operation */" + NL + "void SPI001_lMTSR3_Modfn(const SPI001_HandleType* Handle)" + NL + "{" + NL + "\tuint8_t MTSR3_HWPin = Handle->PinHandle->Pin_Num[3];" + NL + "\tSPI001_PORTS_TypeDef* MTSR3HW_PortRegs = Handle->PinHandle->PinPortRegs[3];" + NL + "\tuint8_t Msk_OE = 0x18U;" + NL + "" + NL + "  if(MTSR3_HWPin < 4U) " + NL + "  {" + NL + "    MTSR3HW_PortRegs->IOCR0 &= ~((uint32_t)Msk_OE << (3U+(MTSR3_HWPin*8U)));" + NL + "  }" + NL + "  else if ((MTSR3_HWPin > 3U) && (MTSR3_HWPin < 8U)) " + NL + "  {" + NL + "    MTSR3_HWPin = MTSR3_HWPin - 4U;" + NL + "    MTSR3HW_PortRegs->IOCR4 &= ~((uint32_t)Msk_OE << (3U+(MTSR3_HWPin*8U)));" + NL + "  } " + NL + "  else if ((MTSR3_HWPin > 7U) && (MTSR3_HWPin < 12U))" + NL + "  {" + NL + "    MTSR3_HWPin = MTSR3_HWPin - 8U;" + NL + "    MTSR3HW_PortRegs->IOCR8 &= ~((uint32_t)Msk_OE << (3U+(MTSR3_HWPin*8U)));" + NL + "  } " + NL + "  else if ((MTSR3_HWPin > 11U) && (MTSR3_HWPin < 16U)) " + NL + "  {" + NL + "    MTSR3_HWPin = MTSR3_HWPin - 12U;" + NL + "    MTSR3HW_PortRegs->IOCR12 &= ~((uint32_t)Msk_OE << (3U+(MTSR3_HWPin*8U)));" + NL + "  }" + NL + "  else " + NL + "  {" + NL + "    /* Do Nothing */" + NL + "  }" + NL + "}" + NL + "" + NL + "/* Modify the MTSR/MRST Pin PortRegs for full duplex operation */" + NL + "void SPI001_lPinModfn_Fullduplex(const SPI001_HandleType* Handle)" + NL + "{" + NL + "\tUSIC_CH_TypeDef* USICRegs = Handle->USICRegs;" + NL + "\tSPI001_PORTS_TypeDef* MTSR_PortRegs = Handle->PinHandle->PinPortRegs[0];" + NL + "\tSPI001_PORTS_TypeDef* MRST_PortRegs = Handle->PinHandle->PinPortRegs[1];" + NL + "\tuint8_t MRSTPin_DSEL = Handle->PinHandle->MRST_DSEL;" + NL + "\tuint8_t MTSRPin_IOCR = Handle->PinHandle->MTSR_IOCR;" + NL + "\tuint8_t MTSRPin = Handle->PinHandle->Pin_Num[0];" + NL + "\tuint8_t MRSTPin = Handle->PinHandle->Pin_Num[1];" + NL + "\tuint8_t MTSR2_HWPin = Handle->PinHandle->Pin_Num[2];" + NL + "\tuint8_t MTSR2_HWPort = Handle->PinHandle->Port_Num[2];" + NL + "\tuint8_t Pin0 = 0x00U;" + NL + "\tuint8_t Msk_HWSEL = 0x03U;" + NL + "" + NL + "\tPin0 = MTSRPin;" + NL + "  if(!((MTSR2_HWPin == 0x00U) && (MTSR2_HWPort == 0x00U)))" + NL + "\t{" + NL + "    \tSPI001_lMTSR2_Modfn(Handle);" + NL + "    \tSPI001_lMTSR3_Modfn(Handle);" + NL + "\t}" + NL + "  else" + NL + "  {" + NL + "    /* Do Nothing */" + NL + "  }" + NL + "  MTSR_PortRegs->HWSEL &= ~((uint32_t)Msk_HWSEL << (MTSRPin * 2U));" + NL + "  MRST_PortRegs->HWSEL &= ~((uint32_t)Msk_HWSEL << (MRSTPin * 2U));" + NL + "  WR_REG(USICRegs->DX0CR, (uint32_t)USIC_CH_DX0CR_DSEL_Msk, \\" + NL + "                         USIC_CH_DX0CR_DSEL_Pos,(uint32_t)MRSTPin_DSEL);" + NL + "  if(Pin0 < 4U) " + NL + "  {" + NL + "    MTSR_PortRegs->IOCR0 |= ((uint32_t)MTSRPin_IOCR << (3U + (Pin0 * 8U)));" + NL + "  }" + NL + "  else if ((Pin0 > 3U) && (Pin0 < 8U)) " + NL + "  {" + NL + "    Pin0 = Pin0 - 4U;" + NL + "    MTSR_PortRegs->IOCR4 |= ((uint32_t)MTSRPin_IOCR << (3U + (Pin0 * 8U)));" + NL + "  } " + NL + "  else if ((Pin0 > 7U) && (Pin0 < 12U)) " + NL + "  {" + NL + "    Pin0 = Pin0 - 8U;" + NL + "    MTSR_PortRegs->IOCR8 |= ((uint32_t)MTSRPin_IOCR << (3U + (Pin0 * 8U)));" + NL + "  } " + NL + "  else if ((Pin0 > 11U) && (Pin0 < 16U)) " + NL + "  {" + NL + "    Pin0 = Pin0 - 12U;" + NL + "    MTSR_PortRegs->IOCR12 |= ((uint32_t)MTSRPin_IOCR << (3U + (Pin0 * 8U)));" + NL + "  }" + NL + "  else " + NL + "  {" + NL + "  \t/* Do Nothing */" + NL + "  }" + NL + "}" + NL + "/******************************************************************************" + NL + "**                      Public Function Definitions                          **" + NL + "******************************************************************************/" + NL + "/* Function to initialize SPI app instances configured through UI */" + NL + "void SPI001_Init(void)" + NL + "{";
  protected final String TEXT_38 = NL + "  /* Disable the USIC0 clock gating */" + NL + "  /* " + NL + "   * The disabling of the clock gating is applicable only for" + NL + "   * XMC4400, XMC4200 and XMC1000 devices." + NL + "   */";
  protected final String TEXT_39 = NL + "  SCU_GENERAL->PASSWD = 0x000000C0UL;" + NL + "  WR_REG(SCU_CLK->CLKCR, SCU_CLK_CLKCR_CNTADJ_Msk, \\" + NL + "                                    SCU_CLK_CLKCR_CNTADJ_Pos,CLK002_DELAYCNT);";
  protected final String TEXT_40 = NL + "  SET_BIT(SCU_CLK->CGATCLR0, SCU_CLK_CGATCLR0_USIC0_Pos);";
  protected final String TEXT_41 = NL + "  while ((SCU_CLK->CLKCR)&(SCU_CLK_CLKCR_VDDC2LOW_Msk))" + NL + "  {" + NL + "   ;" + NL + "  }" + NL + "  SCU_GENERAL->PASSWD = 0x000000C3UL;     ";
  protected final String TEXT_42 = NL + "    /* Reset the Peripheral*/" + NL + "  RESET001_DeassertReset(PER0_USIC";
  protected final String TEXT_43 = ");";
  protected final String TEXT_44 = NL + "  /* Disable the USIC1 clock gating */" + NL + "  /* " + NL + "   * The disabling of the clock gating is applicable only for" + NL + "   * XMC4400, XMC4200 and XMC1000 devices." + NL + "   */";
  protected final String TEXT_45 = NL + "  SCU_GENERAL->PASSWD = 0x000000C0UL;" + NL + "  WR_REG(SCU_CLK->CLKCR, SCU_CLK_CLKCR_CNTADJ_Msk, \\" + NL + "                                    SCU_CLK_CLKCR_CNTADJ_Pos,CLK002_DELAYCNT);";
  protected final String TEXT_46 = NL + "  SET_BIT(SCU_CLK->CGATCLR1, SCU_CLK_CGATCLR1_USIC1_Pos);";
  protected final String TEXT_47 = NL + "  while ((SCU_CLK->CLKCR)&(SCU_CLK_CLKCR_VDDC2LOW_Msk))" + NL + "  {" + NL + "   ;" + NL + "  }" + NL + "  SCU_GENERAL->PASSWD = 0x000000C3UL;     ";
  protected final String TEXT_48 = "    " + NL + "  /* Reset the Peripheral*/" + NL + "  RESET001_DeassertReset(PER1_USIC";
  protected final String TEXT_49 = "); ";
  protected final String TEXT_50 = " ";
  protected final String TEXT_51 = "  ";
  protected final String TEXT_52 = " " + NL + "  SPI001_lInit(&SPI001_Handle";
  protected final String TEXT_53 = "); ";
  protected final String TEXT_54 = NL + "  SPI001_lInit(&SPI001_Handle";
  protected final String TEXT_55 = ", SPI001_Baud_Parameter_Values";
  protected final String TEXT_56 = "); ";
  protected final String TEXT_57 = "   ";
  protected final String TEXT_58 = NL + "  /* Configuration of MTSR Pin ";
  protected final String TEXT_59 = ".";
  protected final String TEXT_60 = " based on User configuration */";
  protected final String TEXT_61 = NL + "  /* PDR_PD = ";
  protected final String TEXT_62 = "*/ ";
  protected final String TEXT_63 = NL + "  PORT";
  protected final String TEXT_64 = "->PDR0  &= (~(PORT";
  protected final String TEXT_65 = "_PDR0_PD";
  protected final String TEXT_66 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_67 = "->PDR0  |= (((uint32_t)";
  protected final String TEXT_68 = " << PORT";
  protected final String TEXT_69 = "_PDR0_PD";
  protected final String TEXT_70 = "_Pos) & PORT";
  protected final String TEXT_71 = "_PDR0_PD";
  protected final String TEXT_72 = "_Msk);";
  protected final String TEXT_73 = NL + "  PORT";
  protected final String TEXT_74 = "->PDR1 &= (~(PORT";
  protected final String TEXT_75 = "_PDR1_PD";
  protected final String TEXT_76 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_77 = "->PDR1 |= (((uint32_t)";
  protected final String TEXT_78 = " << PORT";
  protected final String TEXT_79 = "_PDR1_PD";
  protected final String TEXT_80 = "_Pos) & PORT";
  protected final String TEXT_81 = "_PDR1_PD";
  protected final String TEXT_82 = "_Msk);    ";
  protected final String TEXT_83 = " ";
  protected final String TEXT_84 = "   ";
  protected final String TEXT_85 = NL + "  /* MTSR pin is not mapped */";
  protected final String TEXT_86 = " " + NL + "    /* Configuration of MRST Pin ";
  protected final String TEXT_87 = ".";
  protected final String TEXT_88 = " based on User configuration */";
  protected final String TEXT_89 = NL + "  PORT";
  protected final String TEXT_90 = "->IOCR0 |= ((uint32_t)";
  protected final String TEXT_91 = " << ";
  protected final String TEXT_92 = ");" + NL + "\t";
  protected final String TEXT_93 = NL + "  PORT";
  protected final String TEXT_94 = "->IOCR4 |= ((uint32_t)";
  protected final String TEXT_95 = " << ";
  protected final String TEXT_96 = ");" + NL + "\t";
  protected final String TEXT_97 = NL + "  PORT";
  protected final String TEXT_98 = "->IOCR8 |= ((uint32_t)";
  protected final String TEXT_99 = " << ";
  protected final String TEXT_100 = ");" + NL + "\t";
  protected final String TEXT_101 = NL + "  PORT";
  protected final String TEXT_102 = "->IOCR12 |= ((uint32_t)";
  protected final String TEXT_103 = " << ";
  protected final String TEXT_104 = ");" + NL + "\t";
  protected final String TEXT_105 = "     ";
  protected final String TEXT_106 = NL + "  /* MRST Pin instance (no.";
  protected final String TEXT_107 = ") is not mapped to any port pin. */";
  protected final String TEXT_108 = "\t  ";
  protected final String TEXT_109 = "   ";
  protected final String TEXT_110 = NL + "  /* Configuration of MTSR";
  protected final String TEXT_111 = "HW Pin ";
  protected final String TEXT_112 = ".";
  protected final String TEXT_113 = " based on User configuration */";
  protected final String TEXT_114 = NL + "  /* PDR_PD = ";
  protected final String TEXT_115 = "*/ ";
  protected final String TEXT_116 = NL + "  PORT";
  protected final String TEXT_117 = "->PDR0  &= (~(PORT";
  protected final String TEXT_118 = "_PDR0_PD";
  protected final String TEXT_119 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_120 = "->PDR0  |= (((uint32_t)";
  protected final String TEXT_121 = " << PORT";
  protected final String TEXT_122 = "_PDR0_PD";
  protected final String TEXT_123 = "_Pos) & PORT";
  protected final String TEXT_124 = "_PDR0_PD";
  protected final String TEXT_125 = "_Msk);";
  protected final String TEXT_126 = NL + "  PORT";
  protected final String TEXT_127 = "->PDR1 &= (~(PORT";
  protected final String TEXT_128 = "_PDR1_PD";
  protected final String TEXT_129 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_130 = "->PDR1 |= (((uint32_t)";
  protected final String TEXT_131 = " << PORT";
  protected final String TEXT_132 = "_PDR1_PD";
  protected final String TEXT_133 = "_Pos) & PORT";
  protected final String TEXT_134 = "_PDR1_PD";
  protected final String TEXT_135 = "_Msk);    ";
  protected final String TEXT_136 = "    ";
  protected final String TEXT_137 = NL + "  /* MTSR HW pin not mapped */";
  protected final String TEXT_138 = "      ";
  protected final String TEXT_139 = "     ";
  protected final String TEXT_140 = "   ";
  protected final String TEXT_141 = NL + "   /* Configuration of Clock Out Pin ";
  protected final String TEXT_142 = ".";
  protected final String TEXT_143 = " based on User configuration */";
  protected final String TEXT_144 = NL + "  /* PDR_PD = ";
  protected final String TEXT_145 = " */ ";
  protected final String TEXT_146 = NL + "  PORT";
  protected final String TEXT_147 = "->PDR0  &= (~(PORT";
  protected final String TEXT_148 = "_PDR0_PD";
  protected final String TEXT_149 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_150 = "->PDR0  |= (((uint32_t)";
  protected final String TEXT_151 = " << PORT";
  protected final String TEXT_152 = "_PDR0_PD";
  protected final String TEXT_153 = "_Pos) & PORT";
  protected final String TEXT_154 = "_PDR0_PD";
  protected final String TEXT_155 = "_Msk);";
  protected final String TEXT_156 = NL + "  PORT";
  protected final String TEXT_157 = "->PDR1 &= (~(PORT";
  protected final String TEXT_158 = "_PDR1_PD";
  protected final String TEXT_159 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_160 = "->PDR1 |= (((uint32_t)";
  protected final String TEXT_161 = " << PORT";
  protected final String TEXT_162 = "_PDR1_PD";
  protected final String TEXT_163 = "_Pos) & PORT";
  protected final String TEXT_164 = "_PDR1_PD";
  protected final String TEXT_165 = "_Msk);    ";
  protected final String TEXT_166 = "  ";
  protected final String TEXT_167 = "  ";
  protected final String TEXT_168 = NL + "       /* ClockOut instance (no.";
  protected final String TEXT_169 = ") is not mapped to any port pin. */";
  protected final String TEXT_170 = "   ";
  protected final String TEXT_171 = " ";
  protected final String TEXT_172 = "   ";
  protected final String TEXT_173 = NL + "  /* Configuration of ChipSelect";
  protected final String TEXT_174 = " Pin ";
  protected final String TEXT_175 = ".";
  protected final String TEXT_176 = " based on User configuration */";
  protected final String TEXT_177 = NL + "  /* PDR_PD = ";
  protected final String TEXT_178 = "*/ ";
  protected final String TEXT_179 = NL + "  PORT";
  protected final String TEXT_180 = "->PDR0  &= (~(PORT";
  protected final String TEXT_181 = "_PDR0_PD";
  protected final String TEXT_182 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_183 = "->PDR0  |= (((uint32_t)";
  protected final String TEXT_184 = " << PORT";
  protected final String TEXT_185 = "_PDR0_PD";
  protected final String TEXT_186 = "_Pos) & PORT";
  protected final String TEXT_187 = "_PDR0_PD";
  protected final String TEXT_188 = "_Msk);";
  protected final String TEXT_189 = NL + "  PORT";
  protected final String TEXT_190 = "->PDR1 &= (~(PORT";
  protected final String TEXT_191 = "_PDR1_PD";
  protected final String TEXT_192 = "_Msk));" + NL + "  PORT";
  protected final String TEXT_193 = "->PDR1 |= (((uint32_t)";
  protected final String TEXT_194 = " << PORT";
  protected final String TEXT_195 = "_PDR1_PD";
  protected final String TEXT_196 = "_Pos) & PORT";
  protected final String TEXT_197 = "_PDR1_PD";
  protected final String TEXT_198 = "_Msk);    ";
  protected final String TEXT_199 = " ";
  protected final String TEXT_200 = "   ";
  protected final String TEXT_201 = NL + "             /* ChipSelect instance (no.";
  protected final String TEXT_202 = ") is not mapped to any port pin. */";
  protected final String TEXT_203 = "           ";
  protected final String TEXT_204 = "  ";
  protected final String TEXT_205 = NL + "/* CHANNEL IS NOT MAPPED*/";
  protected final String TEXT_206 = NL + "}" + NL + "" + NL + " /* Function provide to reset the App to default values. */" + NL + " " + NL + "void  SPI001_DeInit (const SPI001_HandleType* Handle)" + NL + "{" + NL + "  /* <<<DD_SPI_API_2>>>*/" + NL + "  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);" + NL + "  " + NL + "  /* Place holder function */      " + NL + "  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);" + NL + "}" + NL + "" + NL + "/* Function which allows to reconfigure .*/" + NL + "status_t SPI001_Configure" + NL + "( " + NL + " const SPI001_HandleType* Handle, " + NL + " const SPI001_ConfigType* Config" + NL + ")" + NL + "{" + NL + "\t" + NL + "\tuint32_t Brg_PDiv = 0x00U;" + NL + "\tuint32_t Fdr_Step = 0x00U;" + NL + "\tUSIC_CH_TypeDef* USICRegs = Handle->USICRegs;" + NL + "\tSPI001_PORTS_TypeDef* MTSR_PortRegs = Handle->PinHandle->PinPortRegs[0];" + NL + "\tSPI001_PORTS_TypeDef* MRST_PortRegs = Handle->PinHandle->PinPortRegs[1];" + NL + "\tuint8_t MTSRPin = Handle->PinHandle->Pin_Num[0];" + NL + "\tuint8_t MRSTPin = Handle->PinHandle->Pin_Num[1];" + NL + "\tstatus_t Status = (status_t)SPI001_ERROR;" + NL + "  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);" + NL + "  do" + NL + "  {" + NL + "   if((Config->Mode > SPI001_QUAD) || (Config->HBMode > SPI001_MSB) || \\" + NL + "      (Config->ClkPol > (SPI001_ClkPolType)SPI001_CLK_POL1) || \\" + NL + "      (Config->ClkPh > (SPI001_ClkPhType)SPI001_CLK_PHASE1) || \\" + NL + "      (Config->LeadTrailDelay > (SPI001_DelayType)SPI001_THREE_SCLK_PERIOD) ||\\" + NL + "      (Config->NextFrameDelay > (SPI001_DelayType)SPI001_THREE_SCLK_PERIOD) ||\\" + NL + "      (Config->WordLen > (uint8_t)16) ||(Config->FrameLen >(uint8_t)64) || \\" + NL + "      (Handle->NoOfCS > (uint32_t)7))                            " + NL + "   {                                                                   " + NL + "      Status = (status_t) SPI001_INVALID_PARAM;                          " + NL + "      DBG002_ERROR(DBG002_GID_SPI001,Status, 0, NULL);                                 " + NL + "      break;" + NL + "   }                                                                   " + NL + "                                                                         " + NL + "   /* <<<DD_SPI_API_3>>>*/                                             " + NL + "" + NL + "   /* Disable SPI mode before configuring all USIC registers to avoid unintended edges */ " + NL + "   USICRegs->CCR &= ~( ((uint32_t)(USIC_SPI_MODE  & USIC_CH_CCR_MODE_Msk)));" + NL + "   " + NL + "   /* Get the optimum PDIV and STEP value for the given baudrate */    " + NL + "   SPI001_lConfigureBaudRate(Config->BaudRate,&Brg_PDiv,&Fdr_Step);    " + NL + "                                                                        " + NL + "   /* Configuration of USIC Channel Fractional Divider */                                                                         " + NL + "   /* Step value */                                                    " + NL + "   USICRegs->FDR |= (Fdr_Step & USIC_CH_FDR_STEP_Msk);                " + NL + "" + NL + "   /* PCTQ value is zero */                                                                         " + NL + "   USICRegs->BRG = ((((uint32_t)Config->LeadTrailDelay << \\" + NL + "                       USIC_CH_BRG_DCTQ_Pos) & USIC_CH_BRG_DCTQ_Msk) | \\" + NL + "                      (((uint32_t)Brg_PDiv  << USIC_CH_BRG_PDIV_Pos) &  \\" + NL + "                                                USIC_CH_BRG_PDIV_Msk) | \\" + NL + "                      (((uint32_t)0x02  << USIC_CH_BRG_CTQSEL_Pos) &  \\" + NL + "                                          USIC_CH_BRG_CTQSEL_Msk) | \\" + NL + "                      (((uint32_t)(((uint32_t)Config->ClkPol) |  \\" + NL + "                       ((uint32_t)Config->ClkPh << (uint32_t)0x01)) << \\" + NL + "                       USIC_CH_BRG_SCLKCFG_Pos) & USIC_CH_BRG_SCLKCFG_Msk));   " + NL + "                                                                         " + NL + "   /* Configuration of USIC Shift Control */                             " + NL + "   USICRegs->SCTR &= \\" + NL + "                  (~(uint32_t)(USIC_CH_SCTR_SDIR_Msk | USIC_CH_SCTR_FLE_Msk | \\" + NL + "                     USIC_CH_SCTR_WLE_Msk | USIC_CH_SCTR_HPCDIR_Msk | \\" + NL + "                     USIC_CH_SCTR_DSM_Msk));                          " + NL + "   USICRegs->SCTR |= \\" + NL + "                      ((((uint32_t)Config->HBMode & USIC_CH_SCTR_SDIR_Msk)) | \\" + NL + "                      (((uint32_t)((uint32_t)Config->FrameLen - (uint32_t) 1)\\" + NL + "                         << USIC_CH_SCTR_FLE_Pos) & USIC_CH_SCTR_FLE_Msk ) | \\" + NL + "                        (((uint32_t)((uint32_t)Config->WordLen - (uint32_t)1)\\" + NL + "                          << USIC_CH_SCTR_WLE_Pos) & USIC_CH_SCTR_WLE_Msk)); " + NL + "   switch((uint8_t)Config->Mode)                                        " + NL + "   {                                                                    " + NL + "     case SPI001_STANDARD_FULLDUPLEX:                                   " + NL + "       USICRegs->CCR &= (((uint32_t)~USIC_CH_CCR_HPCEN_Msk));           " + NL + "       USICRegs->TCSR &= ((uint32_t)~(USIC_CH_TCSR_HPCMD_Msk));         " + NL + "       /* Clear the Input stages */                                     " + NL + "       USICRegs->DX3CR &= (~(uint32_t)(USIC_CH_DX3CR_INSW_Msk | \\" + NL + "                                             USIC_CH_DX3CR_DSEL_Msk )); " + NL + "       USICRegs->DX4CR &= (~(uint32_t)(USIC_CH_DX4CR_INSW_Msk | \\" + NL + "                                             USIC_CH_DX4CR_DSEL_Msk )); " + NL + "       USICRegs->DX5CR &= (~(uint32_t)(USIC_CH_DX5CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX5CR_DSEL_Msk )); " + NL + "       SPI001_lPinModfn_Fullduplex(Handle);" + NL + "" + NL + "     break;                                                           " + NL + "     case SPI001_STANDARD_HALFDUPLEX:                                   " + NL + "        USICRegs->CCR &= (~(USIC_CH_CCR_HPCEN_Msk));                      " + NL + "        /* Enable hardware port control */                               " + NL + "        USICRegs->CCR |= ((((uint32_t)0x01 << USIC_CH_CCR_HPCEN_Pos) & \\" + NL + "                                                       USIC_CH_CCR_HPCEN_Msk));" + NL + "        USICRegs->TCSR &= (~(USIC_CH_TCSR_HPCMD_Msk));                    " + NL + "        /* Enable automatic update of SCTR.HPCDIR & SCTR.DSM bit fields */" + NL + "        USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \\" + NL + "                                                       USIC_CH_TCSR_HPCMD_Msk);" + NL + "        USICRegs->DX0CR &= (~(uint32_t)(USIC_CH_DX0CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX0CR_DSEL_Msk )); " + NL + "        USICRegs->DX3CR &= (~(uint32_t)(USIC_CH_DX3CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX3CR_DSEL_Msk )); " + NL + "        USICRegs->DX4CR &= (~(uint32_t)(USIC_CH_DX4CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX4CR_DSEL_Msk )); " + NL + "        USICRegs->DX5CR &= (~(uint32_t)(USIC_CH_DX5CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX5CR_DSEL_Msk )); " + NL + "                                                                         " + NL + "        SPI001_lClearPortRegs(Handle); ";
  protected final String TEXT_207 = "                                           " + NL + "        MTSR_PortRegs->HWSEL |= ((uint32_t)2 << (MTSRPin * (uint32_t)2)); ";
  protected final String TEXT_208 = NL + "        MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  ";
  protected final String TEXT_209 = "                                          " + NL + "        /* Enable loop back mode */                                      " + NL + "        USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_DSEL_Msk));    " + NL + "     break;                                                           " + NL + "     case SPI001_DUAL:                                                  " + NL + "    \t  USICRegs->CCR &= (((uint32_t)~USIC_CH_CCR_HPCEN_Msk));             " + NL + "        USICRegs->CCR |= ( (((uint32_t)0x02 << USIC_CH_CCR_HPCEN_Pos) & \\" + NL + "                                                       USIC_CH_CCR_HPCEN_Msk));" + NL + "        USICRegs->TCSR &= ((uint32_t)~(USIC_CH_TCSR_HPCMD_Msk));" + NL + "        USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \\" + NL + "                                                       USIC_CH_TCSR_HPCMD_Msk);" + NL + "        USICRegs->DX0CR &= (~(uint32_t)(USIC_CH_DX0CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX0CR_DSEL_Msk )); " + NL + "        USICRegs->DX3CR &= (~(uint32_t)(USIC_CH_DX3CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX3CR_DSEL_Msk )); " + NL + "        USICRegs->DX4CR &= (~(uint32_t)(USIC_CH_DX4CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX4CR_DSEL_Msk )); " + NL + "        USICRegs->DX5CR &= (~(uint32_t)(USIC_CH_DX5CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX5CR_DSEL_Msk )); " + NL + "        SPI001_lClearPortRegs(Handle);";
  protected final String TEXT_210 = "                                           " + NL + "        MTSR_PortRegs->HWSEL |= ((uint32_t)2 << (MTSRPin * (uint32_t)2));" + NL + "        MRST_PortRegs->HWSEL |= ((uint32_t)2 << (MRSTPin * (uint32_t)2));  ";
  protected final String TEXT_211 = NL + "        MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  " + NL + "        MRST_PortRegs->HWSEL |= ((uint32_t)1 << (MRSTPin * (uint32_t)2));";
  protected final String TEXT_212 = "                                           " + NL + "        /* Enable loop back mode for input stages */                     " + NL + "        USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_DSEL_Msk));    " + NL + "        USICRegs->DX3CR |= ((((uint32_t)0x01 << USIC_CH_DX3CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX3CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX3CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX3CR_DSEL_Msk));    " + NL + "     break;                                                           " + NL + "     case SPI001_QUAD:                                                  " + NL + "    \t  USICRegs->CCR &= (((uint32_t)~USIC_CH_CCR_HPCEN_Msk));             " + NL + "        USICRegs->CCR |= ((((uint32_t)0x03 << USIC_CH_CCR_HPCEN_Pos) & \\" + NL + "                                                       USIC_CH_CCR_HPCEN_Msk));" + NL + "        USICRegs->TCSR &= ((uint32_t)~(USIC_CH_TCSR_HPCMD_Msk));         " + NL + "        USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \\" + NL + "                                                       USIC_CH_TCSR_HPCMD_Msk);" + NL + "        USICRegs->DX0CR &= (~(uint32_t)(USIC_CH_DX0CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX0CR_DSEL_Msk )); " + NL + "        USICRegs->DX3CR &= (~(uint32_t)(USIC_CH_DX3CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX3CR_DSEL_Msk )); " + NL + "        USICRegs->DX4CR &= (~(uint32_t)(USIC_CH_DX4CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX4CR_DSEL_Msk )); " + NL + "        USICRegs->DX5CR &= (~(uint32_t)(USIC_CH_DX5CR_INSW_Msk | \\" + NL + "                                              USIC_CH_DX5CR_DSEL_Msk )); " + NL + "        SPI001_lClearPortRegs(Handle);";
  protected final String TEXT_213 = "                                           " + NL + "        MTSR_PortRegs->HWSEL |= ((uint32_t)2 << (MTSRPin * (uint32_t)2));" + NL + "        MRST_PortRegs->HWSEL |= ((uint32_t)2 << (MRSTPin * (uint32_t)2));  ";
  protected final String TEXT_214 = NL + "        MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  " + NL + "        MRST_PortRegs->HWSEL |= ((uint32_t)1 << (MRSTPin * (uint32_t)2));";
  protected final String TEXT_215 = "                                             " + NL + "        /* Enable loop back mode for input stages */                     " + NL + "        USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX0CR_DSEL_Msk));    " + NL + "        USICRegs->DX3CR |= ((((uint32_t)0x01 << USIC_CH_DX3CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX3CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX3CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX3CR_DSEL_Msk));    " + NL + "        USICRegs->DX4CR |= ((((uint32_t)0x01 << USIC_CH_DX4CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX4CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX4CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX4CR_DSEL_Msk));    " + NL + "        USICRegs->DX5CR |= ((((uint32_t)0x01 << USIC_CH_DX5CR_INSW_Pos) & \\" + NL + "                                            USIC_CH_DX5CR_INSW_Msk) | \\" + NL + "                          (((uint32_t)0x06 << USIC_CH_DX5CR_DSEL_Pos) & \\" + NL + "                                            USIC_CH_DX5CR_DSEL_Msk));    " + NL + "     break;" + NL + "        " + NL + "     default:" + NL + "            /* Do nothing */\t" + NL + "     break;" + NL + "   }                                                                    " + NL + "   /* Configuration of Protocol Control Register */                     " + NL + "   USICRegs->PCR_SSCMode &= (~(uint32_t)(USIC_CH_PCR_SSCMode_DCTQ1_Msk | \\" + NL + "                  USIC_CH_PCR_SSCMode_SELO_Msk));                        " + NL + "   USICRegs->PCR_SSCMode |= ((((uint32_t)Config->NextFrameDelay << \\" + NL + "            USIC_CH_PCR_SSCMode_DCTQ1_Pos) & USIC_CH_PCR_SSCMode_DCTQ1_Msk) | \\" + NL + "            ((((uint32_t)0x01 << Handle->ChipSelTable[Config->CESelected]) << \\" + NL + "               USIC_CH_PCR_SSCMode_SELO_Pos) & USIC_CH_PCR_SSCMode_SELO_Msk)); " + NL + " " + NL + "   /* Configuration of Channel Control Register */ " + NL + "   /* parity generation is disabled*/" + NL + "   USICRegs->CCR |= ( ((uint32_t)(USIC_SPI_MODE  & USIC_CH_CCR_MODE_Msk)));" + NL + "                                                                         " + NL + "  }while(0);                                                             " + NL + "  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            " + NL + "  return Status;                                                         " + NL + "}                                                                        " + NL + "                                                                         " + NL + "                                                                         " + NL + "/* This function reads out  the content of the USIC receive FIFO Buffer. " + NL + " * Returns true in case FIFO is not empty.else  otherwise.               " + NL + " *                                                                       " + NL + " */                                                                      " + NL + "bool SPI001_ReadData(const SPI001_HandleType* Handle, uint16_t* DataPtr)" + NL + "{                                                                        " + NL + "  bool Result = (bool)FALSE;                                               " + NL + "  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;                          " + NL + "  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);                           " + NL + "  /* <<<DD_SPI_API_4>>>*/                                                " + NL + "  if(USIC_ubIsRxFIFOempty(USICRegs))                                     " + NL + "  {                                                                      " + NL + "    Result = (bool)FALSE;                                                      " + NL + "  }                                                                      " + NL + "  else                                                                   " + NL + "  {                                                                      " + NL + "     *DataPtr = (uint16_t)USICRegs->OUTR;                                " + NL + "     Result = (bool)TRUE;                                                " + NL + "  }                                                                      " + NL + "  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            " + NL + "                                                                         " + NL + "  return Result;                                                         " + NL + "}                                                                        " + NL + "                                                                         " + NL + "/* This function writes out  a word to the transmit buffer register as per " + NL + " * input transmit mode                                                         " + NL + " */                                                                      " + NL + "bool SPI001_WriteData                                                " + NL + "(                                                                        " + NL + "  const SPI001_HandleType* Handle,                                       " + NL + "  const uint16_t* DataPtr,                                               " + NL + "  SPI001_TransmitMode TrMode                                             " + NL + ")                                                                        " + NL + "{                                                                        " + NL + "  bool Result = (bool)FALSE;                                               " + NL + "  uint8_t Hpcen = 0x00U;                                                     " + NL + "  uint8_t TbufIndex = 0x00U;                                                 " + NL + "  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;                          " + NL + "  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);                           " + NL + "  /* <<<DD_SPI_API_5>>>*/                                                " + NL + "  Hpcen = \\" + NL + "   ((uint8_t)(USICRegs->CCR & USIC_CH_CCR_HPCEN_Msk) >> USIC_CH_CCR_HPCEN_Pos);" + NL + "" + NL + "  if((((uint32_t)TrMode & SPI001_TRMODE_Msk) >> 3) <= Hpcen)            " + NL + "  {                                                                      " + NL + "\t if(USIC_IsTxFIFOfull(USICRegs))                                       " + NL + "    {                                                                    " + NL + "      Result = (bool)FALSE;                                                    " + NL + "    }                                                                    " + NL + "    else                                                                 " + NL + "    {                                                                    " + NL + "      TbufIndex = (uint8_t)((uint8_t)TrMode & (uint8_t)SPI001_TBUFINDEX_Msk);             " + NL + "      USICRegs->IN[TbufIndex] = *DataPtr;                                " + NL + "      Result = (bool)TRUE;                                                     " + NL + "    }                                                                    " + NL + "  }                                                                      " + NL + "  else                                                                   " + NL + "  {                                                                      " + NL + "      Result = (bool)FALSE;                                                    " + NL + "  }                                                                      " + NL + "  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            " + NL + "  return Result;                                                         " + NL + "}                                                                        " + NL + "                                                                         " + NL + "                                                                         " + NL + "/* Checks the specified Flag status bit.*/                               " + NL + "status_t SPI001_GetFlagStatus                                            " + NL + "(                                                                        " + NL + "  const SPI001_HandleType* Handle,                                       " + NL + "  SPI001_FlagStatusType Flag                                             " + NL + ")                                                                        " + NL + "{                                                                        " + NL + "  status_t Status = (status_t)SPI001_RESET;                                        " + NL + "  uint32_t TempValue = 0x00U;                                               " + NL + "  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;                          " + NL + "                                                                         " + NL + "  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);                           " + NL + "  /* <<<DD_SPI_API_6>>>*/                                                " + NL + "  if((((uint32_t)Flag & SPI001_FLAG_REG_Msk) >> 5) == (uint32_t)1)                 " + NL + "  {                                                                      " + NL + "    TempValue = USICRegs->PSR_SSCMode;                                   " + NL + "    TempValue &= ((uint32_t)0x01 << ((uint32_t)Flag & SPI001_FLAG_STATUS_Msk));  " + NL + "  }                                                                      " + NL + "  else if((((uint32_t)Flag & SPI001_FLAG_REG_Msk) >> 5) == (uint32_t) 2)            " + NL + "  {                                                                      " + NL + "    TempValue = USICRegs->TRBSR;                                         " + NL + "    TempValue &= ((uint32_t)0x01 << ((uint32_t)Flag & SPI001_FLAG_STATUS_Msk));  " + NL + "  } " + NL + "  else" + NL + "  {" + NL + "  \t/* Do Nothing */" + NL + "  }" + NL + "  \t                                                                       " + NL + "  if(TempValue != (uint32_t)0x00)                                                    " + NL + "  {                                                                      " + NL + "    Status = (status_t)SPI001_SET;                                                 " + NL + "  }                                                                      " + NL + "  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            " + NL + "  return Status;                                                         " + NL + "}                                                                        " + NL + "                                                                         " + NL + "/* Clears the specified flag status.*/                                   " + NL + "void SPI001_ClearFlag                                                    " + NL + "(                                                                        " + NL + "  const SPI001_HandleType* Handle,                                       " + NL + "  SPI001_FlagStatusType Flag                                             " + NL + ")                                                                        " + NL + "{                                                                        " + NL + "  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;                          " + NL + "  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);                                                                         " + NL + "  /* <<<DD_SPI_API_7>>>*/                                                " + NL + "  if((((uint32_t)Flag & SPI001_FLAG_REG_Msk) >> 5) == (uint32_t) 1)" + NL + "  {                                                                      " + NL + "    USICRegs->PSCR  |= ((uint32_t)0x01 << \\" + NL + "                        ((uint32_t)Flag & SPI001_FLAG_STATUS_Msk));" + NL + "  }                                                                      " + NL + "  else if((((uint32_t)Flag & SPI001_FLAG_REG_Msk) >> 5) == (uint32_t) 2)            " + NL + "  {                                                                      " + NL + "    USICRegs->TRBSCR |= ((uint32_t)0x01 << \\" + NL + "                          ((uint32_t)Flag & SPI001_FLAG_STATUS_Msk));" + NL + "  } " + NL + "  else" + NL + "  {" + NL + "  \t /* Do Nothing */" + NL + "  }                                                                     " + NL + "                                                                         " + NL + "  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            " + NL + "}                                                                        " + NL + "/*CODE_BLOCK_END*/";
  protected final String TEXT_216 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri1 = "app/SPI001/";
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri1) );
    stringBuffer.append(TEXT_3);
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
     if (!DBGApp) { 
    stringBuffer.append(TEXT_4);
     } 
    stringBuffer.append(TEXT_5);
     String Baseuri = "app/spi001/";
     String Baseuri1 = "app/spi001/0";
     String Uarturi = "peripheral/usic/"; 
     String MappedUri = null; 
     String UnitInst = null; 
     String appInst  = null; 
     double clockfreq = 0x00; 
     int Is44Device = -1; 
     int Is42Device = -1; 
     int Is45Device = -1; 
     int Is1xDevice = -1; 
     Is44Device = ((app.getSoftwareId().substring(0,2).compareTo("44")==0)?1:0); 
     Is42Device = ((app.getSoftwareId().substring(0,2).compareTo("42")==0)?1:0); 
     Is45Device = ((app.getSoftwareId().substring(0,2).compareTo("45")==0)?1:0); 
     Is1xDevice = ((app.getSoftwareId().substring(0,1).compareTo("1")==0)?1:0); 
    stringBuffer.append(TEXT_6);
     ArrayList<String> appsList7 = (ArrayList<String>)(app.getApps("app/spi001/"));
 for (String appIns : appsList7 ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri = app.getMappedUri(Baseuri + appInst + "/channel"); 
     if((MappedUri != null) && (MappedUri != "")) {  
    stringBuffer.append(TEXT_7);
     if(Is1xDevice == 1){
  clockfreq = app.getDoubleValue (Baseuri1 + "/clockapp/clk002_irMCLK" );
  }
  else if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)){
  clockfreq = app.getDoubleValue (Baseuri1 + "/clockapp/clk001_iroActualFreqPB" );
  }
  else{}
   
    stringBuffer.append(TEXT_8);
    stringBuffer.append( clockfreq);
    stringBuffer.append(TEXT_9);
    break;
     } 
     else { 
    stringBuffer.append(TEXT_10);
     } 
    } 
    stringBuffer.append(TEXT_11);
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)){
    stringBuffer.append(TEXT_12);
    }
    else if((Is1xDevice==1)){
    stringBuffer.append(TEXT_13);
    }
    stringBuffer.append(TEXT_14);
     String AppBaseuri5 = "app/spi001/";
     String Baseuri5 = "app/spi001/";
     String Usicuri5 = "peripheral/usic/"; 
     String MappedUri5 = null; 
     String UnitInst5 = null; 
     String ChannelInst5 = null; 
     String appInst5  = null; 
     ArrayList<String> appsList5 = (ArrayList<String>)(app.getApps("app/spi001/"));
 for (String appIns : appsList5 ) {
 appInst5 = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri5 = app.getMappedUri(AppBaseuri5 + appInst5 + "/channel"); 
     if((MappedUri5 != null) && (MappedUri5 != "")) { 
     UnitInst5 = MappedUri5.substring(MappedUri5 .length()-11,MappedUri5.indexOf("/channel/")); 
     ChannelInst5 = MappedUri5.substring(MappedUri5.length()-1); 
     if(Is1xDevice == 1){
    stringBuffer.append(TEXT_15);
    stringBuffer.append( appInst5 );
    stringBuffer.append(TEXT_16);
    stringBuffer.append( Integer.toHexString(app.getIntegerValue(AppBaseuri5 + appInst5 +"/spi001_irwstepvalue")) );
    stringBuffer.append(TEXT_17);
    stringBuffer.append( Integer.toHexString(app.getIntegerValue(AppBaseuri5 + appInst5 +"/spi001_irwpdivvalue")) );
    stringBuffer.append(TEXT_18);
    }
     } 
     else { 
    stringBuffer.append(TEXT_19);
     } 
    } 
    stringBuffer.append(TEXT_20);
    if ((Is45Device==1) || (Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_21);
    }
    if ((Is1xDevice==1)) {
    stringBuffer.append(TEXT_22);
    }
    stringBuffer.append(TEXT_23);
    if ((Is45Device==1) || (Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_24);
    }
    stringBuffer.append(TEXT_25);
    if ((Is45Device==1) || (Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_26);
    }
    if ((Is1xDevice==1)){
    stringBuffer.append(TEXT_27);
    }
    stringBuffer.append(TEXT_28);
    if ((Is1xDevice==1)){
    stringBuffer.append(TEXT_29);
    } else {
    stringBuffer.append(TEXT_30);
    }
    stringBuffer.append(TEXT_31);
    if ((Is1xDevice==1)){
    stringBuffer.append(TEXT_32);
    } else {
    stringBuffer.append(TEXT_33);
    }
    stringBuffer.append(TEXT_34);
    if ((Is1xDevice==1)){
    stringBuffer.append(TEXT_35);
    } else {
    stringBuffer.append(TEXT_36);
    }
    stringBuffer.append(TEXT_37);
     ArrayList<String> appsList = (ArrayList<String>)(app.getApps("app/spi001/"));
 for (String appIns : appsList ) {
 appInst = appIns.substring(appIns.lastIndexOf("/")+1);
     MappedUri = app.getMappedUri(Baseuri + appInst + "/channel"); 
     if((MappedUri != null) && (MappedUri != "")) { 
 UnitInst = MappedUri.substring(MappedUri .length()-11,MappedUri.indexOf("/channel/")); 
 int Unit = Integer.parseInt(UnitInst); 
     if(Unit == 0)  { 
    if ((Is44Device==1)||(Is42Device==1)||(Is1xDevice==1))
  {
    stringBuffer.append(TEXT_38);
    if ((Is1xDevice==1))  {
    stringBuffer.append(TEXT_39);
    }
    stringBuffer.append(TEXT_40);
    if ((Is1xDevice==1))    {
    stringBuffer.append(TEXT_41);
    }
    }
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_42);
    stringBuffer.append(UnitInst);
    stringBuffer.append(TEXT_43);
    }
     } else { 
    if ((Is44Device==1)||(Is42Device==1))
    {
    stringBuffer.append(TEXT_44);
    if ((Is1xDevice==1))  {
    stringBuffer.append(TEXT_45);
    }
    stringBuffer.append(TEXT_46);
    if ((Is1xDevice==1)) {
    stringBuffer.append(TEXT_47);
    }
    }
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_48);
    stringBuffer.append(UnitInst);
    stringBuffer.append(TEXT_49);
     } 
    stringBuffer.append(TEXT_50);
    }
    stringBuffer.append(TEXT_51);
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_52);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_53);
    }
    if((Is1xDevice==1)) {
    stringBuffer.append(TEXT_54);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_55);
    stringBuffer.append(appInst);
    stringBuffer.append(TEXT_56);
    }
     String pinUri = app.getMappedUri(Baseuri + appInst +"/mtsr0_pin"); 
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     String portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     String pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_57);
     int PDR_PD1 = app.getIntegerValue(Baseuri + appInst +"/spi001_Mtsrpdr_pd"); 
     int Pin = Integer.parseInt(pinNo);
    stringBuffer.append(TEXT_58);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_59);
    stringBuffer.append(pinNo);
    stringBuffer.append(TEXT_60);
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_61);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_62);
     if(Pin < 8) {
    stringBuffer.append(TEXT_63);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_64);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_65);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_66);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_67);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_68);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_69);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_70);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_71);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_72);
     } else {
    stringBuffer.append(TEXT_73);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_74);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_75);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_76);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_77);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_78);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_79);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_80);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_81);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_82);
    } 
    stringBuffer.append(TEXT_83);
    }
    stringBuffer.append(TEXT_84);
    } else { 
    stringBuffer.append(TEXT_85);
    } 
     String pinUri2 = app.getMappedUri(Baseuri + appInst +"/mrst0_pin"); 
     if ((pinUri2 != null) && (pinUri2.trim() != "")) { 
     String portNo2 = pinUri2.substring(pinUri.indexOf("port/p/")+7,pinUri2.indexOf("/pad/")); 
     String pinNo2 = pinUri2.substring(pinUri.indexOf("/pad/")+5,pinUri2.length());
    stringBuffer.append(TEXT_86);
    stringBuffer.append(portNo2);
    stringBuffer.append(TEXT_87);
    stringBuffer.append(pinNo2);
    stringBuffer.append(TEXT_88);
     int Pin2 = Integer.parseInt(pinNo2);
     int IOCR_PCR = app.getIntegerValue(Baseuri + appInst +"/spi001_inputchardummy");
     if(Pin2 < 4) { 
    stringBuffer.append(TEXT_89);
    stringBuffer.append(portNo2);
    stringBuffer.append(TEXT_90);
    stringBuffer.append(IOCR_PCR);
    stringBuffer.append(TEXT_91);
    stringBuffer.append((3+(Pin2*8)));
    stringBuffer.append(TEXT_92);
    }else if (Pin2 >= 4 && Pin2 <= 7) {  
	Pin2 = Pin2 - 4; 
    stringBuffer.append(TEXT_93);
    stringBuffer.append(portNo2);
    stringBuffer.append(TEXT_94);
    stringBuffer.append(IOCR_PCR);
    stringBuffer.append(TEXT_95);
    stringBuffer.append((3+(Pin2*8)));
    stringBuffer.append(TEXT_96);
    } else if (Pin2 >= 8 && Pin2 <= 11) { 
	Pin2 = Pin2 - 8; 
    stringBuffer.append(TEXT_97);
    stringBuffer.append(portNo2);
    stringBuffer.append(TEXT_98);
    stringBuffer.append(IOCR_PCR);
    stringBuffer.append(TEXT_99);
    stringBuffer.append((3+(Pin2*8)));
    stringBuffer.append(TEXT_100);
    } else if (Pin2 >= 12 && Pin2 <= 15) { 
	Pin2 = Pin2 - 12; 
    stringBuffer.append(TEXT_101);
    stringBuffer.append(portNo2);
    stringBuffer.append(TEXT_102);
    stringBuffer.append(IOCR_PCR);
    stringBuffer.append(TEXT_103);
    stringBuffer.append((3+(Pin2*8)));
    stringBuffer.append(TEXT_104);
    }
    stringBuffer.append(TEXT_105);
    } else { 
    stringBuffer.append(TEXT_106);
    stringBuffer.append( appInst );
    stringBuffer.append(TEXT_107);
    } 
    stringBuffer.append(TEXT_108);
     for (int t=0; t< 4; t++) { 
     pinUri = app.getMappedUri(Baseuri + appInst + "/mtsr" + t + "_hwpin");
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     String portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     String pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_109);
     int PDR_PD1 = app.getIntegerValue(Baseuri + appInst +"/spi001_Mtsrpdr_pd"); 
     int Pin = Integer.parseInt(pinNo);
    stringBuffer.append(TEXT_110);
    stringBuffer.append(t);
    stringBuffer.append(TEXT_111);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_112);
    stringBuffer.append(pinNo);
    stringBuffer.append(TEXT_113);
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_114);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_115);
     if(Pin < 8) {
    stringBuffer.append(TEXT_116);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_117);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_118);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_119);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_120);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_121);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_122);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_123);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_124);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_125);
     } else {
    stringBuffer.append(TEXT_126);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_127);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_128);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_129);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_130);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_131);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_132);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_133);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_134);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_135);
    } 
    }
    stringBuffer.append(TEXT_136);
    } else { 
    stringBuffer.append(TEXT_137);
    break;
    } 
    stringBuffer.append(TEXT_138);
     } 
    stringBuffer.append(TEXT_139);
     pinUri = app.getMappedUri(Baseuri + appInst + "/clkout_pin");
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     String portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     String pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_140);
     int PDR_PD1 = app.getIntegerValue(Baseuri + appInst +"/clkout_pin/pdr_pd"); 
     int Pin = Integer.parseInt(pinNo);
    stringBuffer.append(TEXT_141);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_142);
    stringBuffer.append(pinNo);
    stringBuffer.append(TEXT_143);
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_144);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_145);
     if(Pin < 8) {
    stringBuffer.append(TEXT_146);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_147);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_148);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_149);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_150);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_151);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_152);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_153);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_154);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_155);
     } else {
    stringBuffer.append(TEXT_156);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_157);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_158);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_159);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_160);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_161);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_162);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_163);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_164);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_165);
    } 
    stringBuffer.append(TEXT_166);
    }
    stringBuffer.append(TEXT_167);
    } else { 
    stringBuffer.append(TEXT_168);
    stringBuffer.append( appInst );
    stringBuffer.append(TEXT_169);
    } 
    stringBuffer.append(TEXT_170);
     int NoofCS = app.getIntegerValue(Baseuri + appInst +"/spi001_irwSlaveSelect");
  char c = 'A';
     for (int t=0; t< NoofCS; t++,c++) {  
        pinUri = app.getMappedUri(Baseuri + appInst + "/chipselect" + c + "_pin");
    stringBuffer.append(TEXT_171);
     if ((pinUri != null) && (pinUri.trim() != "")) { 
     String portNo = pinUri.substring(pinUri.indexOf("port/p/")+7,pinUri.indexOf("/pad/")); 
     String pinNo = pinUri.substring(pinUri.indexOf("/pad/")+5,pinUri.length()); 
    stringBuffer.append(TEXT_172);
     int PDR_PD1 = app.getIntegerValue(Baseuri + appInst +"/spi001_cspdr_pd"); 
     int Pin = Integer.parseInt(pinNo);
    stringBuffer.append(TEXT_173);
    stringBuffer.append(c);
    stringBuffer.append(TEXT_174);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_175);
    stringBuffer.append(pinNo);
    stringBuffer.append(TEXT_176);
    if ((Is45Device==1)||(Is44Device==1)||(Is42Device==1)) {
    stringBuffer.append(TEXT_177);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_178);
     if(Pin < 8) {
    stringBuffer.append(TEXT_179);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_180);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_181);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_182);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_183);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_184);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_185);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_186);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_187);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_188);
     } else {
    stringBuffer.append(TEXT_189);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_190);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_191);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_192);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_193);
    stringBuffer.append(PDR_PD1);
    stringBuffer.append(TEXT_194);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_195);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_196);
    stringBuffer.append(portNo);
    stringBuffer.append(TEXT_197);
    stringBuffer.append(Pin);
    stringBuffer.append(TEXT_198);
    } 
    stringBuffer.append(TEXT_199);
    }
    stringBuffer.append(TEXT_200);
    } else { 
    stringBuffer.append(TEXT_201);
    stringBuffer.append( appInst );
    stringBuffer.append(TEXT_202);
    } 
    stringBuffer.append(TEXT_203);
     } 
    stringBuffer.append(TEXT_204);
     } 
     else { 
    stringBuffer.append(TEXT_205);
     } 
    } 
    stringBuffer.append(TEXT_206);
    if ((Is1xDevice==1)){
    stringBuffer.append(TEXT_207);
    } else {
    stringBuffer.append(TEXT_208);
    }
    stringBuffer.append(TEXT_209);
    if ((Is1xDevice==1)){
    stringBuffer.append(TEXT_210);
    } else {
    stringBuffer.append(TEXT_211);
    }
    stringBuffer.append(TEXT_212);
    if ((Is1xDevice==1)){
    stringBuffer.append(TEXT_213);
    } else {
    stringBuffer.append(TEXT_214);
    }
    stringBuffer.append(TEXT_215);
    stringBuffer.append(TEXT_216);
    return stringBuffer.toString();
  }
}
