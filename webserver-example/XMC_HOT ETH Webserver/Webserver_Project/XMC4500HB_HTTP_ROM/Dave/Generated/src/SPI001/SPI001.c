
/*CODE_BLOCK_BEGIN[SPI001.c]*/
/******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                **
 All rights reserved.                                                        **
                                                                             **
 Redistribution and use in source and binary forms, with or without          **
 modification,are permitted provided that the following conditions are met:  **
                                                                             **
 *Redistributions of source code must retain the above copyright notice,     **
 this list of conditions and the following disclaimer.                       **
 *Redistributions in binary form must reproduce the above copyright notice,  **
 this list of conditions and the following disclaimer in the documentation   **
 and/or other materials provided with the distribution.                      **
 *Neither the name of the copyright holders nor the names of its contributors**
 may be used to endorse or promote products derived from this software       **
 without specific prior written permission.                                  **
                                                                             **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  **
 POSSIBILITY OF SUCH DAMAGE.                                                 **
                                                                             **
 To improve the quality of the software, users are encouraged to share       **
 modifications, enhancements or bug fixes with Infineon Technologies AG      **
 dave@infineon.com).                                                         **
                                                                             **
*******************************************************************************
**                                                                           **
**                                                                           **
** PLATFORM : Infineon XMC4000/ XMC1000 Series                               **
**                                                                           **
** COMPILER : Compiler Independent                                           **
**                                                                           **
** AUTHOR   : App Developer                                                  **
**                                                                           **
** MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                           **
** MODIFICATION DATE : May 30, 2013                                          **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials    Name                                                          **
** --------------------------------------------------------------------------**
** AEP         App Developer                                                 **
**                                                                           **
******************************************************************************/

/**
 *
 * @file SPI001.c
 *
 * @App Version SPI001 <1.0.18>
 * 
 * @brief  SPI001 App provides non reentrant APIs for higher level Apps 
 *         which can be used in a Non -RTOS environment. 
 *         Limitations of Simple SPI App
 *         a) Read/Write functions are non reentrant.
 *         b) No support for DMA mode.
 */
/*
 * Revision History
 * 01 Jun 2012 v1.0.0   Initial version
 * 26 Jul 2012 v1.0.2   Modified to support Quad mode functionalities
 * 17 Aug 2012 v1.0.4   Macro correction in USIC.h,Fix for OutputEnable for 
 *                      HW controlled pins 
 * 04 Feb 2013 v1.0.12  1. Modified as per coding guidelines and MISRA checks
 *                      2. Modified for baud calculation during initialization.
 *                      3. Modified the macros FUNCTION_ENTRY, FUNCTION_EXIT  
 *                      and ERROR
 *                      4. The hardcoded values are replaced with macros in 
 *                      SPI001_lConfigureBaudRate() function.
 *                      5. The PCTQ value updation in BRG register is removed  
 *                      as the value is taken as zero.
 *                      6. Updatd for revision history alignments.
 *                      7. Updated function SPI001_Init() for XMC1000 devices.
 * 26 Mar 2013 v1.0.16  1. Corrected the revision history.
 * 30 May 2013 v1.0.18  1. HW1 control path configuration added for XMC1000 
 *                      devices in SPI001_lInit() & SPI001_Configure().
 *                      2. HW0 control path configuration added for XMC4000 
 *                      in SPI001_lInit() for MRST & MTSR pins, if operation 
 *                      mode is Half Duplex/Dual/Quad mode.
 *                      3. Added CCR.MODE configurations in SPI001_lInit() 
 *                      & SPI001_Configure() to disable the SPI mode before 
 *                      configuring USIC registers & to enable the SPI mode 
 *                      after configurations to avoid unintended edges.                 
 */

/******************************************************************************
 ** INCLUDE FILES                                                            **
 *****************************************************************************/

#include <DAVE3.h>
#include "../../inc/SPI001/Usic.h"
  
/*****************************************************************************
              DUMMY DEFINTIONS OF DEBUG LOG MACROS
*****************************************************************************/
/*These definitions are included here to avoid compilation errors,
 since the DBG002 app is not part of the project. All the macros are defined
 as empty*/ 
#ifndef _DBG002_H_

#define DBG002_RegisterCallBack(A,B,C)
#define DBG002_I(e) 
#define DBG002_IG(e,g) 
#define DBG002_IH(e,h) 
#define DBG002_IP(e,p) 
#define DBG002_IGH(e,g,h) 
#define DBG002_IGP(e,g,p) 
#define DBG002_IHP(e,h,p) 
#define DBG002_IGHP(e,g,h,p) 
#define DBG002_N(e) 
#define DBG002_NG(e,g) 
#define DBG002_NH(e,h) 
#define DBG002_NP(e,p) 
#define DBG002_NGH(e,g,h) 
#define DBG002_NGP(e,g,p) 
#define DBG002_NHP(e,h,p) 
#define DBG002_NGHP(e,g,h,p) 
#define DBG002_ID(e) 
#define DBG002_IS(e) 
#define DBG002_ISG(e,g) 
#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)
#define DBG002_CRITICAL(groupid,messageid,length,value)
#define DBG002_ERROR(groupid,messageid,length,value)
#define DBG002_WARNING(groupid,messageid,length,value)
#define DBG002_INFO(groupid,messageid,length,value)
#define DBG002_TRACE(groupid,messageid,length,value)
#define DBG002_FUNCTION_ENTRY(GID, Status) 
#define DBG002_FUNCTION_EXIT(GID, Status) 

#endif/* End of defintions of dummy Debug Log macros*/                  

/******************************************************************************
**                      Private Macro Definitions                            **
******************************************************************************/       
  /* System Core clock frequency in MHz */
#define SPI001_CLOCK                    120.0F
     
#define APP_GID                         DBG002_GID_SPI001
#define SPI001_TRMODE_Msk               (0x18U)
#define SPI001_TBUFINDEX_Msk            (0x07U)
#define SPI001_FLAG_REG_Msk             (0x000000E0U)
#define SPI001_FLAG_STATUS_Msk          (0x0000001FU)

#define SPI001_MAX_VALUE                1023
/* (DCTQ + 1) DCTQ value is 1 */
#define SPI001_DCTQ_VALUE               0x02 
#define SPI001_MAX_STEPVALUE            1024
/* Intermediate step value to calculate Pdiv */
#define SPI001_IM_STEPVALUE             500 

/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/


/******************************************************************************
**                 Private Function Declarations:
******************************************************************************/
void SPI001_lInit (const SPI001_HandleType* Handle);
/* Function to get optimized PDIV and STEP value for the given baud rate */ 
void SPI001_lConfigureBaudRate\
                            (uint32_t BaudRate,uint32_t* Pdiv,uint32_t* Step);
/* Clears the IOCR.PCR value of the Port Register  */
void SPI001_lClearPortRegs(const SPI001_HandleType* Handle);
/* Modify the MTSR2HW_PortRegs for full duplex operation */
void SPI001_lMTSR2_Modfn(const SPI001_HandleType* Handle);
/* Modify the MTSR3HW_PortRegs for full duplex operation */
void SPI001_lMTSR3_Modfn(const SPI001_HandleType* Handle);
/* Modify the MTSR/MRST Pin PortRegs for full duplex operation */
void SPI001_lPinModfn_Fullduplex(const SPI001_HandleType* Handle);
/******************************************************************************
**                      Global Constant Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Global Variable Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Private Constant Definitions                         **
******************************************************************************/

/******************************************************************************
**                 Function like macro definitions                           **
******************************************************************************/
/******************************************************************************
**                      Private Function Definitions                         **
******************************************************************************/
 /* Initializes the App based on User provide configuration. */
 void SPI001_lInit (const SPI001_HandleType* Handle)
{
  uint32_t Brg_PDiv = 0x00U;
  uint32_t Fdr_Step = 0x00U;
  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;
  SPI001_PORTS_TypeDef* MTSR_PortRegs = Handle->PinHandle->PinPortRegs[0];
  SPI001_PORTS_TypeDef* MRST_PortRegs = Handle->PinHandle->PinPortRegs[1];
  uint8_t MTSRPin = Handle->PinHandle->Pin_Num[0];
  uint8_t MRSTPin = Handle->PinHandle->Pin_Num[1];
  
  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);
  /* <<<DD_SPI_API_1>>>*/
 
  /** SPI initialization  */
  
  /* Disable SPI mode before configuring all USIC registers to avoid unintended edges */ 
  USICRegs->CCR &= ~( ((uint32_t)(USIC_SPI_MODE  & USIC_CH_CCR_MODE_Msk)));
  
  /* Enable the USIC Channel */
  USICRegs->KSCFG |= ((((uint32_t) 0x01 & USIC_CH_KSCFG_MODEN_Msk)) | \
                      (((uint32_t)0x01 << USIC_CH_KSCFG_BPMODEN_Pos) & \
                        USIC_CH_KSCFG_BPMODEN_Msk)); 
  /* Get the optimum PDIV and STEP value for the given baudrate */
  SPI001_lConfigureBaudRate(Handle->Config->BaudRate,&Brg_PDiv,&Fdr_Step);
 
  /* Configuration of USIC Channel Fractional Divider */
  /* Fractional divider mode selected */
  USICRegs->FDR |= (((uint32_t)0x02 << USIC_CH_FDR_DM_Pos) \
                    & USIC_CH_FDR_DM_Msk);
  
  /* Step value loaded */
  USICRegs->FDR |= ((uint32_t)Fdr_Step & USIC_CH_FDR_STEP_Msk);
 
  /* Clock phase & Clock polarity configuration */
  /* PCTQ value is zero */
  USICRegs->BRG |= ((((uint32_t)Handle->Config->LeadTrailDelay << \
                     USIC_CH_BRG_DCTQ_Pos) & USIC_CH_BRG_DCTQ_Msk) | \
                   (((uint32_t)Brg_PDiv << USIC_CH_BRG_PDIV_Pos) & \
                     USIC_CH_BRG_PDIV_Msk) | \
                   (((uint32_t)0x02 << USIC_CH_BRG_CTQSEL_Pos) &  \
                      USIC_CH_BRG_CTQSEL_Msk) | \
                   (((((uint32_t)(Handle->Config->ClkPol) | \
                    ((uint32_t)Handle->Config->ClkPh << (uint32_t) 0x01)) \
                     << USIC_CH_BRG_SCLKCFG_Pos) & USIC_CH_BRG_SCLKCFG_Msk))); 
 
  /* Configuration of USIC Shift Control */
  /* Transmission Mode (TRM) = 1  */
  /* Passive Data Level (PDL) = 1 */
  USICRegs->SCTR |= \
          ((((uint32_t)Handle->Config->HBMode & USIC_CH_SCTR_SDIR_Msk)) | \
		      (((uint32_t)0x01  <<  USIC_CH_SCTR_PDL_Pos ) & \
		            		                       USIC_CH_SCTR_PDL_Msk ) | \
		      (((uint32_t)0x01  <<  USIC_CH_SCTR_TRM_Pos ) & \
		                       		               USIC_CH_SCTR_TRM_Msk ) | \
          (((Handle->Config->FrameLen-(uint32_t)0x01) << USIC_CH_SCTR_FLE_Pos)\
                                                 & USIC_CH_SCTR_FLE_Msk ) | \
          (((Handle->Config->WordLen-(uint32_t)0x01) << USIC_CH_SCTR_WLE_Pos) \
                                                &  USIC_CH_SCTR_WLE_Msk));
  switch(Handle->Config->Mode)
  {
    case SPI001_STANDARD_FULLDUPLEX:
      USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \
    	                                            USIC_CH_DX0CR_INSW_Msk));
      break;
    case SPI001_STANDARD_HALFDUPLEX:

      /* Enable hardware port control */
      USICRegs->CCR |= ((((uint32_t)0x01 << USIC_CH_CCR_HPCEN_Pos) & \
                                                       USIC_CH_CCR_HPCEN_Msk));
      USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \
                                                      USIC_CH_TCSR_HPCMD_Msk);
      /* Enable loop back mode in input stages */
      USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \
                                            USIC_CH_DX0CR_INSW_Msk) | \
                          ((((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \
                                            USIC_CH_DX0CR_DSEL_Msk)));
      MTSR_PortRegs->HWSEL  |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));                                                 
      break;      
    case SPI001_DUAL:
      /* Enable hardware port control */
      USICRegs->CCR |= (((uint32_t)((uint32_t)0x02 << USIC_CH_CCR_HPCEN_Pos) &\
                                                       USIC_CH_CCR_HPCEN_Msk));
      USICRegs->TCSR |= ((uint32_t)((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) \
                                                   & (USIC_CH_TCSR_HPCMD_Msk));
       /* Enable loop back mode in input stages */
      USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \
                                            USIC_CH_DX0CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \
                                            USIC_CH_DX0CR_DSEL_Msk)); 
      USICRegs->DX3CR |= ((((uint32_t)0x01 << USIC_CH_DX3CR_INSW_Pos) & \
                                            USIC_CH_DX3CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX3CR_DSEL_Pos) & \
                                            USIC_CH_DX3CR_DSEL_Msk)); 
      MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  
      MRST_PortRegs->HWSEL |= ((uint32_t)1 << (MRSTPin * (uint32_t)2));
     
      break;
    case SPI001_QUAD:
      /* Enable hardware port control */
      USICRegs->CCR |= (((uint32_t)0x03 << USIC_CH_CCR_HPCEN_Pos) & \
                                                        USIC_CH_CCR_HPCEN_Msk);
      USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \
                                                       USIC_CH_TCSR_HPCMD_Msk);
       /* Enable loop back mode in input stages */
      USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \
                                            USIC_CH_DX0CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \
                                            USIC_CH_DX0CR_DSEL_Msk)); 
      USICRegs->DX3CR |= ((((uint32_t)0x01 << USIC_CH_DX3CR_INSW_Pos) & \
                                            USIC_CH_DX3CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX3CR_DSEL_Pos) & \
                                            USIC_CH_DX3CR_DSEL_Msk));  
      USICRegs->DX4CR |= ((((uint32_t)0x01 << USIC_CH_DX4CR_INSW_Pos) & \
                                            USIC_CH_DX4CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX4CR_DSEL_Pos) & \
                                            USIC_CH_DX4CR_DSEL_Msk));  
      USICRegs->DX5CR |= ((((uint32_t)0x01 << USIC_CH_DX5CR_INSW_Pos) & \
                                            USIC_CH_DX5CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX5CR_DSEL_Pos) & \
                                            USIC_CH_DX5CR_DSEL_Msk));  
      MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  
      MRST_PortRegs->HWSEL |= ((uint32_t)1 << (MRSTPin * (uint32_t)2)); 

      break;
  }
  /* Configuration of USIC Transmit Control/Status Register */ 
  /* TBUF Data Enable (TDEN) = 1 */
  /* TBUF Data Single Shot Mode (TDSSM) = 1 */
	USICRegs->TCSR |= ((((uint32_t)0x01  << USIC_CH_TCSR_TDEN_Pos) & \
  USIC_CH_TCSR_TDEN_Msk ) | \
    (((uint32_t)0x01  << USIC_CH_TCSR_TDSSM_Pos) & USIC_CH_TCSR_TDSSM_Msk));

  /* Configuration of Protocol Control Register */ 
	/* PCTQ1 value is zero */
  /* Parity Error Interrupt generation is disabled*/
  USICRegs->PCR_SSCMode |= 
      ((((uint32_t)0x01 & USIC_CH_PCR_SSCMode_MSLSEN_Msk)) | \
      (((uint32_t)0x01 << USIC_CH_PCR_SSCMode_SELCTR_Pos) & \
                                            USIC_CH_PCR_SSCMode_SELCTR_Msk) | \
      (((uint32_t)0x01 << USIC_CH_PCR_SSCMode_SELINV_Pos) & \
                                            USIC_CH_PCR_SSCMode_SELINV_Msk) | \
      (((uint32_t)0x02 << USIC_CH_PCR_SSCMode_CTQSEL1_Pos) & \
                                           USIC_CH_PCR_SSCMode_CTQSEL1_Msk) | \
      (((uint32_t)Handle->Config->NextFrameDelay << \
            USIC_CH_PCR_SSCMode_DCTQ1_Pos) & USIC_CH_PCR_SSCMode_DCTQ1_Msk) | \
      (((uint32_t)Handle->MSLSIntrEn << USIC_CH_PCR_SSCMode_MSLSIEN_Pos) & \
                                           USIC_CH_PCR_SSCMode_MSLSIEN_Msk) | \
      ((((uint32_t)0x01 << Handle->ChipSelTable[Handle->Config->CESelected]) \
           << USIC_CH_PCR_SSCMode_SELO_Pos) & USIC_CH_PCR_SSCMode_SELO_Msk) | \
      (((uint32_t)Handle->FrmEndMode << USIC_CH_PCR_SSCMode_FEM_Pos) \
                                             & USIC_CH_PCR_SSCMode_FEM_Msk));
  /* Configuration of Transmitter Buffer Control Register */ 
  USICRegs->TBCTR |= ((((uint32_t)Handle->TxLimit  << \
                    USIC_CH_TBCTR_LIMIT_Pos ) & USIC_CH_TBCTR_LIMIT_Msk));
    
  /* Configuration of Receiver Buffer Control Register */ 
  USICRegs->RBCTR |= ((((uint32_t)Handle->RxLimit  << \
                USIC_CH_RBCTR_LIMIT_Pos) & USIC_CH_RBCTR_LIMIT_Msk) | \
                (((uint32_t)0x01   << USIC_CH_RBCTR_LOF_Pos) & \
                    USIC_CH_RBCTR_LOF_Msk));
   
  /* Configuration of Channel Control Register */ 
  /* parity generation is disabled*/
  USICRegs->CCR |= ( ((uint32_t)(USIC_SPI_MODE  & USIC_CH_CCR_MODE_Msk)));
    
  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);
}


/* Give optimized PDIV and STEP value for the given baud rate */ 
void SPI001_lConfigureBaudRate(uint32_t BaudRate,uint32_t* Pdiv,uint32_t* Step)
{

	float ratio, TempBaud,TempPdiv, TempStep;
	TempBaud = (float)BaudRate;
	ratio = (float)((((SPI001_CLOCK * (float)1000000)/\
	                 (float)(SPI001_DCTQ_VALUE * SPI001_MAX_STEPVALUE)) * \
	                 (float)SPI001_IM_STEPVALUE)/(float)TempBaud);
	/* Calculating optimum PDIV value */
	if( ratio <= (float)1)
  {
		TempPdiv = (float)0;
  }
  else
  {
    	TempPdiv =  ratio -(float)1;
      if( TempPdiv > (float)SPI001_MAX_VALUE)
      {
    	  TempPdiv = (float)SPI001_MAX_VALUE;
      }
  }
	*Pdiv = (uint32_t)TempPdiv;
    /* Calculating STEP value */
	TempStep = (float)(((((TempBaud * (float)SPI001_MAX_STEPVALUE)/ \
	                    (float)1000000) * (float)SPI001_DCTQ_VALUE ) * \
                      ((float)1+ (float)(*Pdiv)))/(SPI001_CLOCK));

  if(TempStep > (float)SPI001_MAX_VALUE)
  {
   	TempStep = (float)SPI001_MAX_VALUE;
  }
  *Step = (uint32_t)TempStep;
}

/* Clears the IOCR.PCR value of the Port Register  */
void SPI001_lClearPortRegs(const SPI001_HandleType* Handle)
{
	uint8_t MTSRPin = Handle->PinHandle->Pin_Num[0];
	SPI001_PORTS_TypeDef* MTSR_PortRegs = Handle->PinHandle->PinPortRegs[0];
  uint8_t Msk_IOCR = 0x07U;

	if(MTSRPin < 0x04U)
  {
	  MTSR_PortRegs->IOCR0 &= ~((uint32_t)Msk_IOCR << (3U + (MTSRPin * 8U)));
 	}
 	else if ((MTSRPin > 0x03U) && (MTSRPin < 8U))
 	{
 	  MTSRPin = MTSRPin - 4U;
	  MTSR_PortRegs->IOCR4 &= ~((uint32_t)Msk_IOCR << (3U + (MTSRPin * 8U)));
 	} 
 	else if ((MTSRPin > 7U) && (MTSRPin < 12U)) 
 	{
 	  MTSRPin = MTSRPin - 8U;
	  MTSR_PortRegs->IOCR8 &= ~((uint32_t)Msk_IOCR << (3U + (MTSRPin * 8U)));
 	} 
 	else if ((MTSRPin > 11U) && (MTSRPin < 16U)) 
 	{
 	  MTSRPin = MTSRPin - 12U;
	  MTSR_PortRegs->IOCR12 &= ~((uint32_t)Msk_IOCR << (3U + (MTSRPin * 8U)));
	}
 	else
 	{
 	  /* Do Nothing */
 	}
}

/* Modify the MTSR2HW_PortRegs for full duplex operation */
void SPI001_lMTSR2_Modfn(const SPI001_HandleType* Handle)
{
	uint8_t MTSR2_HWPin = Handle->PinHandle->Pin_Num[2];
	SPI001_PORTS_TypeDef* MTSR2HW_PortRegs = Handle->PinHandle->PinPortRegs[2];
	uint8_t Msk_OE = 0x18U;

  if(MTSR2_HWPin < 4U) 
  {
    MTSR2HW_PortRegs->IOCR0 &= ~((uint32_t)Msk_OE << (3U+(MTSR2_HWPin*8U)));
  }
  else if ((MTSR2_HWPin > 3U) && (MTSR2_HWPin < 8U)) 
  {
    MTSR2_HWPin = MTSR2_HWPin - 4U;
    MTSR2HW_PortRegs->IOCR4 &= ~((uint32_t)Msk_OE << (3U+(MTSR2_HWPin*8U)));
  } 
  else if ((MTSR2_HWPin > 7U) && (MTSR2_HWPin < 12U)) 
  {
    MTSR2_HWPin = MTSR2_HWPin - 8U;
    MTSR2HW_PortRegs->IOCR8 &= ~((uint32_t)Msk_OE << (3U+(MTSR2_HWPin*8U)));
  } 
  else if ((MTSR2_HWPin > 11U) && (MTSR2_HWPin < 16U)) 
  {
    MTSR2_HWPin = MTSR2_HWPin - 12U;
    MTSR2HW_PortRegs->IOCR12 &= ~((uint32_t)Msk_OE << (3U+(MTSR2_HWPin*8U)));
  }
  else 
  {
    /* Do Nothing */	
  }
}

/* Modify the MTSR3HW_PortRegs for full duplex operation */
void SPI001_lMTSR3_Modfn(const SPI001_HandleType* Handle)
{
	uint8_t MTSR3_HWPin = Handle->PinHandle->Pin_Num[3];
	SPI001_PORTS_TypeDef* MTSR3HW_PortRegs = Handle->PinHandle->PinPortRegs[3];
	uint8_t Msk_OE = 0x18U;

  if(MTSR3_HWPin < 4U) 
  {
    MTSR3HW_PortRegs->IOCR0 &= ~((uint32_t)Msk_OE << (3U+(MTSR3_HWPin*8U)));
  }
  else if ((MTSR3_HWPin > 3U) && (MTSR3_HWPin < 8U)) 
  {
    MTSR3_HWPin = MTSR3_HWPin - 4U;
    MTSR3HW_PortRegs->IOCR4 &= ~((uint32_t)Msk_OE << (3U+(MTSR3_HWPin*8U)));
  } 
  else if ((MTSR3_HWPin > 7U) && (MTSR3_HWPin < 12U))
  {
    MTSR3_HWPin = MTSR3_HWPin - 8U;
    MTSR3HW_PortRegs->IOCR8 &= ~((uint32_t)Msk_OE << (3U+(MTSR3_HWPin*8U)));
  } 
  else if ((MTSR3_HWPin > 11U) && (MTSR3_HWPin < 16U)) 
  {
    MTSR3_HWPin = MTSR3_HWPin - 12U;
    MTSR3HW_PortRegs->IOCR12 &= ~((uint32_t)Msk_OE << (3U+(MTSR3_HWPin*8U)));
  }
  else 
  {
    /* Do Nothing */
  }
}

/* Modify the MTSR/MRST Pin PortRegs for full duplex operation */
void SPI001_lPinModfn_Fullduplex(const SPI001_HandleType* Handle)
{
	USIC_CH_TypeDef* USICRegs = Handle->USICRegs;
	SPI001_PORTS_TypeDef* MTSR_PortRegs = Handle->PinHandle->PinPortRegs[0];
	SPI001_PORTS_TypeDef* MRST_PortRegs = Handle->PinHandle->PinPortRegs[1];
	uint8_t MRSTPin_DSEL = Handle->PinHandle->MRST_DSEL;
	uint8_t MTSRPin_IOCR = Handle->PinHandle->MTSR_IOCR;
	uint8_t MTSRPin = Handle->PinHandle->Pin_Num[0];
	uint8_t MRSTPin = Handle->PinHandle->Pin_Num[1];
	uint8_t MTSR2_HWPin = Handle->PinHandle->Pin_Num[2];
	uint8_t MTSR2_HWPort = Handle->PinHandle->Port_Num[2];
	uint8_t Pin0 = 0x00U;
	uint8_t Msk_HWSEL = 0x03U;

	Pin0 = MTSRPin;
  if(!((MTSR2_HWPin == 0x00U) && (MTSR2_HWPort == 0x00U)))
	{
    	SPI001_lMTSR2_Modfn(Handle);
    	SPI001_lMTSR3_Modfn(Handle);
	}
  else
  {
    /* Do Nothing */
  }
  MTSR_PortRegs->HWSEL &= ~((uint32_t)Msk_HWSEL << (MTSRPin * 2U));
  MRST_PortRegs->HWSEL &= ~((uint32_t)Msk_HWSEL << (MRSTPin * 2U));
  WR_REG(USICRegs->DX0CR, (uint32_t)USIC_CH_DX0CR_DSEL_Msk, \
                         USIC_CH_DX0CR_DSEL_Pos,(uint32_t)MRSTPin_DSEL);
  if(Pin0 < 4U) 
  {
    MTSR_PortRegs->IOCR0 |= ((uint32_t)MTSRPin_IOCR << (3U + (Pin0 * 8U)));
  }
  else if ((Pin0 > 3U) && (Pin0 < 8U)) 
  {
    Pin0 = Pin0 - 4U;
    MTSR_PortRegs->IOCR4 |= ((uint32_t)MTSRPin_IOCR << (3U + (Pin0 * 8U)));
  } 
  else if ((Pin0 > 7U) && (Pin0 < 12U)) 
  {
    Pin0 = Pin0 - 8U;
    MTSR_PortRegs->IOCR8 |= ((uint32_t)MTSRPin_IOCR << (3U + (Pin0 * 8U)));
  } 
  else if ((Pin0 > 11U) && (Pin0 < 16U)) 
  {
    Pin0 = Pin0 - 12U;
    MTSR_PortRegs->IOCR12 |= ((uint32_t)MTSRPin_IOCR << (3U + (Pin0 * 8U)));
  }
  else 
  {
  	/* Do Nothing */
  }
}
/******************************************************************************
**                      Public Function Definitions                          **
******************************************************************************/
/* Function to initialize SPI app instances configured through UI */
void SPI001_Init(void)
{
    /* Reset the Peripheral*/
  RESET001_DeassertReset(PER0_USIC0);   
  SPI001_lInit(&SPI001_Handle0);    
  /* Configuration of MTSR Pin 3.13 based on User configuration */
  /* PDR_PD = 0*/ 
  PORT3->PDR1 &= (~(PORT3_PDR1_PD13_Msk));
  PORT3->PDR1 |= (((uint32_t)0 << PORT3_PDR1_PD13_Pos) & PORT3_PDR1_PD13_Msk);         
    /* Configuration of MRST Pin 2.5 based on User configuration */
  PORT2->IOCR4 |= ((uint32_t)0 << 11);
	     	  
  /* MTSR HW pin not mapped */        
   /* Configuration of Clock Out Pin 3.0 based on User configuration */
  /* PDR_PD = 0 */ 
  PORT3->PDR0  &= (~(PORT3_PDR0_PD0_Msk));
  PORT3->PDR0  |= (((uint32_t)0 << PORT3_PDR0_PD0_Pos) & PORT3_PDR0_PD0_Msk);           
  /* Configuration of ChipSelectA Pin 3.12 based on User configuration */
  /* PDR_PD = 0*/ 
  PORT3->PDR1 &= (~(PORT3_PDR1_PD12_Msk));
  PORT3->PDR1 |= (((uint32_t)0 << PORT3_PDR1_PD12_Pos) & PORT3_PDR1_PD12_Msk);                     
}

 /* Function provide to reset the App to default values. */
 
void  SPI001_DeInit (const SPI001_HandleType* Handle)
{
  /* <<<DD_SPI_API_2>>>*/
  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);
  
  /* Place holder function */      
  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);
}

/* Function which allows to reconfigure .*/
status_t SPI001_Configure
( 
 const SPI001_HandleType* Handle, 
 const SPI001_ConfigType* Config
)
{
	
	uint32_t Brg_PDiv = 0x00U;
	uint32_t Fdr_Step = 0x00U;
	USIC_CH_TypeDef* USICRegs = Handle->USICRegs;
	SPI001_PORTS_TypeDef* MTSR_PortRegs = Handle->PinHandle->PinPortRegs[0];
	SPI001_PORTS_TypeDef* MRST_PortRegs = Handle->PinHandle->PinPortRegs[1];
	uint8_t MTSRPin = Handle->PinHandle->Pin_Num[0];
	uint8_t MRSTPin = Handle->PinHandle->Pin_Num[1];
	status_t Status = (status_t)SPI001_ERROR;
  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);
  do
  {
   if((Config->Mode > SPI001_QUAD) || (Config->HBMode > SPI001_MSB) || \
      (Config->ClkPol > (SPI001_ClkPolType)SPI001_CLK_POL1) || \
      (Config->ClkPh > (SPI001_ClkPhType)SPI001_CLK_PHASE1) || \
      (Config->LeadTrailDelay > (SPI001_DelayType)SPI001_THREE_SCLK_PERIOD) ||\
      (Config->NextFrameDelay > (SPI001_DelayType)SPI001_THREE_SCLK_PERIOD) ||\
      (Config->WordLen > (uint8_t)16) ||(Config->FrameLen >(uint8_t)64) || \
      (Handle->NoOfCS > (uint32_t)7))                            
   {                                                                   
      Status = (status_t) SPI001_INVALID_PARAM;                          
      DBG002_ERROR(DBG002_GID_SPI001,Status, 0, NULL);                                 
      break;
   }                                                                   
                                                                         
   /* <<<DD_SPI_API_3>>>*/                                             

   /* Disable SPI mode before configuring all USIC registers to avoid unintended edges */ 
   USICRegs->CCR &= ~( ((uint32_t)(USIC_SPI_MODE  & USIC_CH_CCR_MODE_Msk)));
   
   /* Get the optimum PDIV and STEP value for the given baudrate */    
   SPI001_lConfigureBaudRate(Config->BaudRate,&Brg_PDiv,&Fdr_Step);    
                                                                        
   /* Configuration of USIC Channel Fractional Divider */                                                                         
   /* Step value */                                                    
   USICRegs->FDR |= (Fdr_Step & USIC_CH_FDR_STEP_Msk);                

   /* PCTQ value is zero */                                                                         
   USICRegs->BRG = ((((uint32_t)Config->LeadTrailDelay << \
                       USIC_CH_BRG_DCTQ_Pos) & USIC_CH_BRG_DCTQ_Msk) | \
                      (((uint32_t)Brg_PDiv  << USIC_CH_BRG_PDIV_Pos) &  \
                                                USIC_CH_BRG_PDIV_Msk) | \
                      (((uint32_t)0x02  << USIC_CH_BRG_CTQSEL_Pos) &  \
                                          USIC_CH_BRG_CTQSEL_Msk) | \
                      (((uint32_t)(((uint32_t)Config->ClkPol) |  \
                       ((uint32_t)Config->ClkPh << (uint32_t)0x01)) << \
                       USIC_CH_BRG_SCLKCFG_Pos) & USIC_CH_BRG_SCLKCFG_Msk));   
                                                                         
   /* Configuration of USIC Shift Control */                             
   USICRegs->SCTR &= \
                  (~(uint32_t)(USIC_CH_SCTR_SDIR_Msk | USIC_CH_SCTR_FLE_Msk | \
                     USIC_CH_SCTR_WLE_Msk | USIC_CH_SCTR_HPCDIR_Msk | \
                     USIC_CH_SCTR_DSM_Msk));                          
   USICRegs->SCTR |= \
                      ((((uint32_t)Config->HBMode & USIC_CH_SCTR_SDIR_Msk)) | \
                      (((uint32_t)((uint32_t)Config->FrameLen - (uint32_t) 1)\
                         << USIC_CH_SCTR_FLE_Pos) & USIC_CH_SCTR_FLE_Msk ) | \
                        (((uint32_t)((uint32_t)Config->WordLen - (uint32_t)1)\
                          << USIC_CH_SCTR_WLE_Pos) & USIC_CH_SCTR_WLE_Msk)); 
   switch((uint8_t)Config->Mode)                                        
   {                                                                    
     case SPI001_STANDARD_FULLDUPLEX:                                   
       USICRegs->CCR &= (((uint32_t)~USIC_CH_CCR_HPCEN_Msk));           
       USICRegs->TCSR &= ((uint32_t)~(USIC_CH_TCSR_HPCMD_Msk));         
       /* Clear the Input stages */                                     
       USICRegs->DX3CR &= (~(uint32_t)(USIC_CH_DX3CR_INSW_Msk | \
                                             USIC_CH_DX3CR_DSEL_Msk )); 
       USICRegs->DX4CR &= (~(uint32_t)(USIC_CH_DX4CR_INSW_Msk | \
                                             USIC_CH_DX4CR_DSEL_Msk )); 
       USICRegs->DX5CR &= (~(uint32_t)(USIC_CH_DX5CR_INSW_Msk | \
                                              USIC_CH_DX5CR_DSEL_Msk )); 
       SPI001_lPinModfn_Fullduplex(Handle);

     break;                                                           
     case SPI001_STANDARD_HALFDUPLEX:                                   
        USICRegs->CCR &= (~(USIC_CH_CCR_HPCEN_Msk));                      
        /* Enable hardware port control */                               
        USICRegs->CCR |= ((((uint32_t)0x01 << USIC_CH_CCR_HPCEN_Pos) & \
                                                       USIC_CH_CCR_HPCEN_Msk));
        USICRegs->TCSR &= (~(USIC_CH_TCSR_HPCMD_Msk));                    
        /* Enable automatic update of SCTR.HPCDIR & SCTR.DSM bit fields */
        USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \
                                                       USIC_CH_TCSR_HPCMD_Msk);
        USICRegs->DX0CR &= (~(uint32_t)(USIC_CH_DX0CR_INSW_Msk | \
                                              USIC_CH_DX0CR_DSEL_Msk )); 
        USICRegs->DX3CR &= (~(uint32_t)(USIC_CH_DX3CR_INSW_Msk | \
                                              USIC_CH_DX3CR_DSEL_Msk )); 
        USICRegs->DX4CR &= (~(uint32_t)(USIC_CH_DX4CR_INSW_Msk | \
                                              USIC_CH_DX4CR_DSEL_Msk )); 
        USICRegs->DX5CR &= (~(uint32_t)(USIC_CH_DX5CR_INSW_Msk | \
                                              USIC_CH_DX5CR_DSEL_Msk )); 
                                                                         
        SPI001_lClearPortRegs(Handle); 
        MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));                                            
        /* Enable loop back mode */                                      
        USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \
                                            USIC_CH_DX0CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \
                                            USIC_CH_DX0CR_DSEL_Msk));    
     break;                                                           
     case SPI001_DUAL:                                                  
    	  USICRegs->CCR &= (((uint32_t)~USIC_CH_CCR_HPCEN_Msk));             
        USICRegs->CCR |= ( (((uint32_t)0x02 << USIC_CH_CCR_HPCEN_Pos) & \
                                                       USIC_CH_CCR_HPCEN_Msk));
        USICRegs->TCSR &= ((uint32_t)~(USIC_CH_TCSR_HPCMD_Msk));
        USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \
                                                       USIC_CH_TCSR_HPCMD_Msk);
        USICRegs->DX0CR &= (~(uint32_t)(USIC_CH_DX0CR_INSW_Msk | \
                                              USIC_CH_DX0CR_DSEL_Msk )); 
        USICRegs->DX3CR &= (~(uint32_t)(USIC_CH_DX3CR_INSW_Msk | \
                                              USIC_CH_DX3CR_DSEL_Msk )); 
        USICRegs->DX4CR &= (~(uint32_t)(USIC_CH_DX4CR_INSW_Msk | \
                                              USIC_CH_DX4CR_DSEL_Msk )); 
        USICRegs->DX5CR &= (~(uint32_t)(USIC_CH_DX5CR_INSW_Msk | \
                                              USIC_CH_DX5CR_DSEL_Msk )); 
        SPI001_lClearPortRegs(Handle);
        MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  
        MRST_PortRegs->HWSEL |= ((uint32_t)1 << (MRSTPin * (uint32_t)2));                                           
        /* Enable loop back mode for input stages */                     
        USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \
                                            USIC_CH_DX0CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \
                                            USIC_CH_DX0CR_DSEL_Msk));    
        USICRegs->DX3CR |= ((((uint32_t)0x01 << USIC_CH_DX3CR_INSW_Pos) & \
                                            USIC_CH_DX3CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX3CR_DSEL_Pos) & \
                                            USIC_CH_DX3CR_DSEL_Msk));    
     break;                                                           
     case SPI001_QUAD:                                                  
    	  USICRegs->CCR &= (((uint32_t)~USIC_CH_CCR_HPCEN_Msk));             
        USICRegs->CCR |= ((((uint32_t)0x03 << USIC_CH_CCR_HPCEN_Pos) & \
                                                       USIC_CH_CCR_HPCEN_Msk));
        USICRegs->TCSR &= ((uint32_t)~(USIC_CH_TCSR_HPCMD_Msk));         
        USICRegs->TCSR |= (((uint32_t)0x01 << USIC_CH_TCSR_HPCMD_Pos) & \
                                                       USIC_CH_TCSR_HPCMD_Msk);
        USICRegs->DX0CR &= (~(uint32_t)(USIC_CH_DX0CR_INSW_Msk | \
                                              USIC_CH_DX0CR_DSEL_Msk )); 
        USICRegs->DX3CR &= (~(uint32_t)(USIC_CH_DX3CR_INSW_Msk | \
                                              USIC_CH_DX3CR_DSEL_Msk )); 
        USICRegs->DX4CR &= (~(uint32_t)(USIC_CH_DX4CR_INSW_Msk | \
                                              USIC_CH_DX4CR_DSEL_Msk )); 
        USICRegs->DX5CR &= (~(uint32_t)(USIC_CH_DX5CR_INSW_Msk | \
                                              USIC_CH_DX5CR_DSEL_Msk )); 
        SPI001_lClearPortRegs(Handle);
        MTSR_PortRegs->HWSEL |= ((uint32_t)1 << (MTSRPin * (uint32_t)2));  
        MRST_PortRegs->HWSEL |= ((uint32_t)1 << (MRSTPin * (uint32_t)2));                                             
        /* Enable loop back mode for input stages */                     
        USICRegs->DX0CR |= ((((uint32_t)0x01 << USIC_CH_DX0CR_INSW_Pos) & \
                                            USIC_CH_DX0CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX0CR_DSEL_Pos) & \
                                            USIC_CH_DX0CR_DSEL_Msk));    
        USICRegs->DX3CR |= ((((uint32_t)0x01 << USIC_CH_DX3CR_INSW_Pos) & \
                                            USIC_CH_DX3CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX3CR_DSEL_Pos) & \
                                            USIC_CH_DX3CR_DSEL_Msk));    
        USICRegs->DX4CR |= ((((uint32_t)0x01 << USIC_CH_DX4CR_INSW_Pos) & \
                                            USIC_CH_DX4CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX4CR_DSEL_Pos) & \
                                            USIC_CH_DX4CR_DSEL_Msk));    
        USICRegs->DX5CR |= ((((uint32_t)0x01 << USIC_CH_DX5CR_INSW_Pos) & \
                                            USIC_CH_DX5CR_INSW_Msk) | \
                          (((uint32_t)0x06 << USIC_CH_DX5CR_DSEL_Pos) & \
                                            USIC_CH_DX5CR_DSEL_Msk));    
     break;
        
     default:
            /* Do nothing */	
     break;
   }                                                                    
   /* Configuration of Protocol Control Register */                     
   USICRegs->PCR_SSCMode &= (~(uint32_t)(USIC_CH_PCR_SSCMode_DCTQ1_Msk | \
                  USIC_CH_PCR_SSCMode_SELO_Msk));                        
   USICRegs->PCR_SSCMode |= ((((uint32_t)Config->NextFrameDelay << \
            USIC_CH_PCR_SSCMode_DCTQ1_Pos) & USIC_CH_PCR_SSCMode_DCTQ1_Msk) | \
            ((((uint32_t)0x01 << Handle->ChipSelTable[Config->CESelected]) << \
               USIC_CH_PCR_SSCMode_SELO_Pos) & USIC_CH_PCR_SSCMode_SELO_Msk)); 
 
   /* Configuration of Channel Control Register */ 
   /* parity generation is disabled*/
   USICRegs->CCR |= ( ((uint32_t)(USIC_SPI_MODE  & USIC_CH_CCR_MODE_Msk)));
                                                                         
  }while(0);                                                             
  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            
  return Status;                                                         
}                                                                        
                                                                         
                                                                         
/* This function reads out  the content of the USIC receive FIFO Buffer. 
 * Returns true in case FIFO is not empty.else  otherwise.               
 *                                                                       
 */                                                                      
bool SPI001_ReadData(const SPI001_HandleType* Handle, uint16_t* DataPtr)
{                                                                        
  bool Result = (bool)FALSE;                                               
  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;                          
  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);                           
  /* <<<DD_SPI_API_4>>>*/                                                
  if(USIC_ubIsRxFIFOempty(USICRegs))                                     
  {                                                                      
    Result = (bool)FALSE;                                                      
  }                                                                      
  else                                                                   
  {                                                                      
     *DataPtr = (uint16_t)USICRegs->OUTR;                                
     Result = (bool)TRUE;                                                
  }                                                                      
  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            
                                                                         
  return Result;                                                         
}                                                                        
                                                                         
/* This function writes out  a word to the transmit buffer register as per 
 * input transmit mode                                                         
 */                                                                      
bool SPI001_WriteData                                                
(                                                                        
  const SPI001_HandleType* Handle,                                       
  const uint16_t* DataPtr,                                               
  SPI001_TransmitMode TrMode                                             
)                                                                        
{                                                                        
  bool Result = (bool)FALSE;                                               
  uint8_t Hpcen = 0x00U;                                                     
  uint8_t TbufIndex = 0x00U;                                                 
  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;                          
  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);                           
  /* <<<DD_SPI_API_5>>>*/                                                
  Hpcen = \
   ((uint8_t)(USICRegs->CCR & USIC_CH_CCR_HPCEN_Msk) >> USIC_CH_CCR_HPCEN_Pos);

  if((((uint32_t)TrMode & SPI001_TRMODE_Msk) >> 3) <= Hpcen)            
  {                                                                      
	 if(USIC_IsTxFIFOfull(USICRegs))                                       
    {                                                                    
      Result = (bool)FALSE;                                                    
    }                                                                    
    else                                                                 
    {                                                                    
      TbufIndex = (uint8_t)((uint8_t)TrMode & (uint8_t)SPI001_TBUFINDEX_Msk);             
      USICRegs->IN[TbufIndex] = *DataPtr;                                
      Result = (bool)TRUE;                                                     
    }                                                                    
  }                                                                      
  else                                                                   
  {                                                                      
      Result = (bool)FALSE;                                                    
  }                                                                      
  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            
  return Result;                                                         
}                                                                        
                                                                         
                                                                         
/* Checks the specified Flag status bit.*/                               
status_t SPI001_GetFlagStatus                                            
(                                                                        
  const SPI001_HandleType* Handle,                                       
  SPI001_FlagStatusType Flag                                             
)                                                                        
{                                                                        
  status_t Status = (status_t)SPI001_RESET;                                        
  uint32_t TempValue = 0x00U;                                               
  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;                          
                                                                         
  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);                           
  /* <<<DD_SPI_API_6>>>*/                                                
  if((((uint32_t)Flag & SPI001_FLAG_REG_Msk) >> 5) == (uint32_t)1)                 
  {                                                                      
    TempValue = USICRegs->PSR_SSCMode;                                   
    TempValue &= ((uint32_t)0x01 << ((uint32_t)Flag & SPI001_FLAG_STATUS_Msk));  
  }                                                                      
  else if((((uint32_t)Flag & SPI001_FLAG_REG_Msk) >> 5) == (uint32_t) 2)            
  {                                                                      
    TempValue = USICRegs->TRBSR;                                         
    TempValue &= ((uint32_t)0x01 << ((uint32_t)Flag & SPI001_FLAG_STATUS_Msk));  
  } 
  else
  {
  	/* Do Nothing */
  }
  	                                                                       
  if(TempValue != (uint32_t)0x00)                                                    
  {                                                                      
    Status = (status_t)SPI001_SET;                                                 
  }                                                                      
  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            
  return Status;                                                         
}                                                                        
                                                                         
/* Clears the specified flag status.*/                                   
void SPI001_ClearFlag                                                    
(                                                                        
  const SPI001_HandleType* Handle,                                       
  SPI001_FlagStatusType Flag                                             
)                                                                        
{                                                                        
  USIC_CH_TypeDef* USICRegs = Handle->USICRegs;                          
  DBG002_FUNCTION_ENTRY(DBG002_GID_SPI001,SPI001_FUNCTION_ENTRY);                                                                         
  /* <<<DD_SPI_API_7>>>*/                                                
  if((((uint32_t)Flag & SPI001_FLAG_REG_Msk) >> 5) == (uint32_t) 1)
  {                                                                      
    USICRegs->PSCR  |= ((uint32_t)0x01 << \
                        ((uint32_t)Flag & SPI001_FLAG_STATUS_Msk));
  }                                                                      
  else if((((uint32_t)Flag & SPI001_FLAG_REG_Msk) >> 5) == (uint32_t) 2)            
  {                                                                      
    USICRegs->TRBSCR |= ((uint32_t)0x01 << \
                          ((uint32_t)Flag & SPI001_FLAG_STATUS_Msk));
  } 
  else
  {
  	 /* Do Nothing */
  }                                                                     
                                                                         
  DBG002_FUNCTION_EXIT(DBG002_GID_SPI001,SPI001_FUNCTION_EXIT);                            
}                                                                        
/*CODE_BLOCK_END*/

