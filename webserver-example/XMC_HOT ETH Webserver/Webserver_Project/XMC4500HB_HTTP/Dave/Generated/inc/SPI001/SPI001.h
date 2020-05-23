/******************************************************************************
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with 
 * Infineon's microcontrollers.  
 * This file can be freely distributed within development tools that are 
 * supporting such microcontrollers. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
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
** MODIFICATION DATE : Mar 26, 2013                                          **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                       Author(s) Identity                                  **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
** --------------------------------------------------------------------------**
** PAE         App Developer                                                 **
******************************************************************************/

/**
 * @file SPI001.h
 *
 * @brief  Header file for SPI001 App
 *
 */
/*
 * Revision History
 * 01 Jun 2012 v1.0.0   Initial version
 * 26 Jul 2012 v1.0.2   Modified to support Quad mode functionalities
 * 17 Aug 2012 v1.0.4   Macro correction in USIC.h,Fix for OutputEnable for 
 *                      HW controlled pins 
 * 04 Feb 2013 v1.0.12  1. Coding guidelines and MISRA fixes
 *                      2. Updated for Coding guidelines and syntax correction 
 *                      for the enum SPI001_ModeType, SPI001_HBModeType,  
 *                      SPI001_ClkPolType, SPI001_ClkPhType and 
 *                      SPI001_FlagStatusType. 
 *                      3. Removed the inclusion of usic.h file and added in 
 *                      SPI001.c file
 *                      4. Updatd for revision history alignments.
 *                      5. Updated example code for SPI001_GetFlagStatus API
 * 26 Mar 2013 v1.0.16  1. Corrected Revision History
 */

#ifndef SPI001_H_
#define SPI001_H_

/******************************************************************************
**                      Include Files                                        **
******************************************************************************/

#include <DAVE3.h>

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
/**
 * @ingroup SPI001_apidoc
 * @{
 */

 
/* Macro function to enable start of frame bit. It indicates that the data word
 * in FIFO buffer is considered as the first word of new SSC frame. This Macro
 * functions can be used if frame length is controlled by software.
 *
 * @param[in] Handle: SPI Channel instance handle
 *
 * */
#define EnableStartOfFrame(Handle) \
                               (Handle.USICRegs->TCSR |= USIC_CH_TCSR_SOF_Msk)


/* Macro function to enable End of frame bit. It indicates that the data word
 * in FIFO buffer is considered as the last word of an SSC frame. This Macro
 * functions can be used if frame length is controlled by software.
 *
 * @param[in] Handle: SPI Channel instance handle
 *
 * */
#define EnableEndOfFrame(Handle) \
                               (Handle.USICRegs->TCSR |= USIC_CH_TCSR_EOF_Msk)

/**
 * @}
 */
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/**
 * @ingroup SPI001_publicparam
 * @{
 */

/**
 * @brief Enum type which defines the status code returned by SPI001 APIs
 */
typedef enum SPI001_StatusType
{
  /**
   * Indicates Flag is not set
   */
   /**
	* @cond INTERNAL_DOCS
	* @param MODULENAME SPI001
	* @endcond
	*/
   /**
	* @cond INTERNAL_DOCS
	* @param ERRCODESTRING1 SPI001_RESET
	* @param STRCODESTRING1 Flag is not set
	* @endcond
	*/
  SPI001_RESET = 1,
  /**
   * Indicates Flag is set
   */
   /**
	* @cond INTERNAL_DOCS
	* @param ERRCODESTRING2 SPI001_SET
	* @param STRCODESTRING2 Flag is set
	* @endcond
	*/
  SPI001_SET,
  /**
   * Invalid parameter
   */
   /**
	* @cond INTERNAL_DOCS
	* @param ERRCODESTRING3 SPI001_INVALID_PARAM
	* @param STRCODESTRING3 Invalid parameter
	* @endcond
	*/
  SPI001_INVALID_PARAM,
  /**
   * Unkown error
   */
   /**
	* @cond INTERNAL_DOCS
	* @param ERRCODESTRING4 SPI001_ERROR
	* @param STRCODESTRING4 Unkown error
	* @endcond
	*/
  SPI001_ERROR,
  /**
   * Debuglog Function Entry
   */
   /**
	* @cond INTERNAL_DOCS
	* @param ERRCODESTRING5 SPI001_FUNCTION_ENTRY
	* @param STRCODESTRING5 Entered function \%s
	* @endcond
	*/
  SPI001_FUNCTION_ENTRY,
  /**
   *  Debuglog Function Exit
   */
   /**
	* @cond INTERNAL_DOCS
	* @param ERRCODESTRING6 SPI001_FUNCTION_EXIT
	* @param STRCODESTRING6 Entered function \%s
	* @endcond
	*/
  SPI001_FUNCTION_EXIT
}SPI001_StatusType;

/**
 * @brief Enum type which defines SPI operation modes
 *
 */
typedef enum SPI001_ModeType
{
  /** Standard full duplex SPI */
  SPI001_STANDARD_FULLDUPLEX,
  /** Standard half duplex SPI */
  SPI001_STANDARD_HALFDUPLEX,
  /** Dual Mode Operation */  
  SPI001_DUAL,   
  /** Quad Mode Operation */
  SPI001_QUAD   
}SPI001_ModeType;


/**
 * @brief Enum types which defines SPI HB mode.
 */
typedef enum SPI001_HBModeType
{
  /** Transmit LSB first */
  SPI001_LSB,    
  /** Transmit MSB first */
  SPI001_MSB    
}SPI001_HBModeType;

/**
 * @brief Enum type which defines clock polarity values.
 */
typedef enum SPI001_ClkPolType
{
  /** No Polarity inversion  */
  SPI001_CLK_POL0,   
  /**  Polarity Inversion*/
  SPI001_CLK_POL1   
}SPI001_ClkPolType;


/**
 * @brief Enum type which defines clock phase values
 */
typedef enum SPI001_ClkPhType
{
  /** No Delay */
  SPI001_CLK_PHASE0,    
  /** 1/2 clock delay */
  SPI001_CLK_PHASE1    
}SPI001_ClkPhType;


/**
 * @brief Enum type which defines slave select line delay values
 */
typedef enum SPI001_DelayType
{
  /**1 SCLK Period  */
  SPI001_ONE_SCLK_PERIOD,   
   /** 2 SCLK Period */ 
  SPI001_TWO_SCLK_PERIOD,   
   /**  3 SCLK Period */
  SPI001_THREE_SCLK_PERIOD  
}SPI001_DelayType;

/**
 * @brief This Enum defines different transmit mode for SPI protocol
 */
typedef enum SPI001_TransmitMode
{
  /** SPI Standard mode with Full duplex communication*/ 
  SPI001_STANDARD = 0, 
  /** SPI Standard mode with hardware port control enabled(Half duplex) 
       and pin configured in input mode */
  SPI001_STANDARD_HPC_INPUTMODE = 8,
 /** SPI Standard mode with hardware port control enabled(Half duplex) 
       and pin configured in output mode */
  SPI001_STANDARD_HPC_OUTPUTMODE = 12,
 /** SPI Dual mode with hardware port control enabled(Half duplex) 
       and pin configured in input mode */
  SPI001_DUALMODE_HPC_INPUTMODE = 18,
  /** SPI Dual mode with hardware port control enabled(Half duplex) 
       and pin configured in output mode */
  SPI001_DUALMODE_HPC_OUTPUTMODE = 22,
  /** SPI Quad mode with hardware port control enabled(Half duplex) 
       and pin configured in input mode */
  SPI001_QUADMODE_HPC_INPUTMODE = 27,
  /** SPI Quad mode with hardware port control enabled(Half duplex) 
       and pin configured in output mode */
  SPI001_QUADMODE_HPC_OUTPUTMODE = 31   
}SPI001_TransmitMode;

/**
 * @brief This enum defines Chip Select lines.
 */
typedef enum SPI001_CSLineType
{
  /** Chip Select line A */
  CE_A,
  /** Chip Select line B */
  CE_B,
  /** Chip Select line C */
  CE_C,
  /** Chip Select line D */
  CE_D,
  /** Chip Select line E */
  CE_E,
  /** Chip Select line F */
  CE_F,
  /** Chip Select line G */
  CE_G,
  /** Chip Select line H */
  CE_H
}SPI001_CSLineType;

/**
 * @brief Enum type which defines clock phase values
 */
typedef enum SPI001_FrmEndModeType
{
  /** Disable frame end mode */
  SPI001_DISABLE_FEM,    
  /** Enable frame end mode */
  SPI001_ENABLE_FEM   
}SPI001_FrmEndModeType;


/**
 * @brief This data type describes the available SPI Status flags
 */
typedef enum SPI001_FlagStatusType
{
  /** MSLS Status */
  SPI001_MSLS_STATUS_FLAG    = 32,
  /** DX2S Status */
  SPI001_DX2S_STATUS_FLAG    = 33,
  /** MSLS Event Detected */
  SPI001_MSLS_EVENT_FLAG     = 34,
  /** DX2T Event Detected */
  SPI001_DX2TEV_EVENT_FLAG   = 35,
  /** Parity Error Event */
  SPI001_PARERR_EVENT_FLAG   = 36,
  /** Receiver Start Indication Flag */
  SPI001_RECV_START_IND_FLAG = 42,
  /** Data Lost Indication Flag */
  SPI001_DATA_LOST_IND_FLAG  = 43,
  /** Transmit Shift Indication Flag */
  SPI001_TRANS_SHIFT_IND_FLAG= 44,
  /** Transmit Buffer Indication Flag */
  SPI001_TRANS_BUFFER_IND_FLAG=45,
  /** Receive Indication Flag */
  SPI001_RECV_IND_FLAG		  =46,
  /** Alternative Receive Indication Flag */
  SPI001_ALT_RECV_IND_FLAG	  =47,
  /** Alternative Receive Indication Flag */
  SPI001_BAUDRATE_GEN_IND_FLAG =48,
  /** Standard Receive Buffer Event */
  SPI001_FIFO_STD_RECV_BUF_FLAG=64,
    /** Receive Buffer Error Event */  
  SPI001_FIFO_RECV_BUF_ERR_FLAG=65,
     /** Alternative Receive Buffer Event */  
  SPI001_FIFO_ALTRECV_BUF_FLAG=66,
  /** Standard Transmit Buffer Event */
  SPI001_FIFO_STD_TRANSMIT_BUF_FLAG=72,
   /** Transmit Buffer Error Event */  
  SPI001_FIFO_TRANSMIT_BUF_ERR_FLAG=73
}SPI001_FlagStatusType;

/**
 * @brief The data structure defines all SPI Channel Configuration Parameters
 *
 */
typedef struct SPI001_ConfigType
{
   /** SPI Mode of operation selection ( Standard/Dual/Quad) */
  SPI001_ModeType Mode;       
  /** LSB/MSB first shift configuration */  
  SPI001_HBModeType  HBMode; 
  /** Clock Polarity selection */  
  SPI001_ClkPolType ClkPol;  
  /** Clock Phase Selection */
  SPI001_ClkPhType  ClkPh;     
  /** Baud Rate in baud/Sec */
  uint32_t BaudRate;           
  /** Leading/Trailing Delay selection */
  SPI001_DelayType LeadTrailDelay; 
  /** Next frame Delay selection */
  SPI001_DelayType NextFrameDelay;
  /** Word length specified in Bits */  
  uint8_t WordLen;             
  /** Frame length specified in Bits */
  uint8_t FrameLen;            
  /** Chip Select line no */
  uint8_t CESelected;          
}SPI001_ConfigType; 

/**
* PORTS
*/
typedef struct {
__IO uint32_t   OUT;          /*!<   Port Output Register Offset  0x00000000   */
__O uint32_t    OMR;          /*!<   Port Output Modification Register Offset  0x00000004   */
__I  uint32_t   RESERVED1[2]; 
__IO uint32_t   IOCR0;        /*!<   Port Input/Output Control Register 0 Offset  0x00000010   */
__IO uint32_t   IOCR4;        /*!<   Port Input/Output Control Register 4 Offset  0x00000014   */
__IO uint32_t   IOCR8;        /*!<   Port Input/Output Control Register 8 Offset  0x00000018   */
__IO uint32_t   IOCR12;       /*!<   Port Input/Output Control Register 12 Offset  0x0000001C   */
__I  uint32_t   RESERVED2[1];  
__I uint32_t    IN;           /*!<   Port Input Register Offset  0x00000024   */
__I  uint32_t   RESERVED3[6];  
__IO uint32_t   PDR0;         /*!<   Port Pad Driver Mode 0 Register Offset  0x00000040   */
__IO uint32_t   PDR1;         /*!<   Port Pad Driver Mode 1 Register Offset  0x00000044   */
__I  uint32_t   RESERVED4[6];
__IO uint32_t   PDISC;        /*!<   Port Pin Function Decision Control Register Offset  0x00000060   */
__I  uint32_t   RESERVED5[3]; 
__IO uint32_t   PPS;          /*!<   Port Pin Power Safe Register Offset  0x00000070   */
__IO uint32_t   HWSEL;        /*!<   Port Pin Hardware Select Register Offset  0x00000074   */
}SPI001_PORTS_TypeDef;

/**
 *This data type describes the Pin Handle
 */
typedef struct SPI001_PinHandleType
{
  /** Port Numbers */
  uint8_t Port_Num[4];
  /** Port pins */
  uint8_t Pin_Num[4];
  /** Port Registers for Pins*/
  SPI001_PORTS_TypeDef* PinPortRegs[4];
  /** MRST Pin DSEL value */
  uint8_t MRST_DSEL;
  /** MTSR Pin IOCR_PCR value */
  uint8_t MTSR_IOCR;
}SPI001_PinHandleType; 

/**
 * @brief This data type describes SPI handle
 */
typedef struct SPI001_HandleType
{
  /** Mapped usic channel register offset value */
  USIC_CH_TypeDef* USICRegs;
  /** Frame End mode selection */
  SPI001_FrmEndModeType FrmEndMode;
  /** SPI Channel configuration structure */
  SPI001_ConfigType* Config;
  /** Chip Select Table */
  uint8_t ChipSelTable[8];
  /** No of Chip Select line selected */
  uint8_t NoOfCS;
  /** TX FIFO Trigger level */
  uint8_t TxLimit;
  /** RX FIFO Triger level */
  uint8_t RxLimit;
  /** Tx FIFO Size  */
  uint8_t TxFifoSize;
  /** Rx FIFO Size  */
  uint8_t RxFifoSize;
  /** Enable/Disable MSLS interrupt */
  bool MSLSIntrEn;
  /** Pin Handle */
  SPI001_PinHandleType* PinHandle;
}SPI001_HandleType;


/**
 * @}
 */
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Extern Variables                                      **
*******************************************************************************/


/*******************************************************************************
** FUNCTION PROTOTYPES                                                        **
*******************************************************************************/


/**
 * @ingroup SPI001_apidoc
 * @{
 */

/**
 * Initializes all the App instances based on User provided configuration.
 *
 * @param[in]  None
 *
 * @return     None
 *
 * <b>Reentrant: Yes </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>SPI001_Handle0</b></I> is a global structure of type
 * SPI001_HandleType which will be configured in SPI001_Conf.c file using
 * UI parameters.
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *   // ... Initializes Apps configurations ...
 *   DAVE_Init(); // SPI001_Init() will be called inside DAVE_Init()
 *   while(1)
 *   {
 * 
 *   }
 *  }
 * @endcode<BR> </p>
 */
void  SPI001_Init (void);

/**
 * @brief      Function provided to reset the App to default values.
 *
 * @param[in]  Handle: SPI handle generated
 *
 * @return     void
 *
 * <b>Reentrant:Yes </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>SPI001_Handle0</b></I> is a global structure of type
 * SPI001_HandleType which will be configured in SPI001_Conf.c file using
 * UI parameters.
 * @code
 * #include <DAVE3.h>
 * int main(void)
 *   {
 *    // ... Initializes Apps configurations ...
 *    DAVE_Init(); // SPI001_Init() will be called inside DAVE_Init()
 *    SPI001_DeInit(&SPI001_Handle0);
 *    while(1)
 *    {
 * 
 *    }
 *  }
 * @endcode<BR> </p>
 */
void  SPI001_DeInit (const SPI001_HandleType* Handle);

/**
 * Reconfigures SPI channel with input values.
 *
 * Service ID: 0x03
 *
 * @param[in]  Handle: Spi channel handle
 * @param[in]  Config: Input structure which contains SPI channel configuration
 *
 * @return     status
 *             DAVEApp_SUCCESS for success
 *             SPI001_INVALID_PARAM If input configuration is invalid
 *
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>SPI001_Handle0</b></I> is a global structure of type
 * SPI001_HandleType which will be configured in SPI001_Conf.c file using
 * UI parameters.
 * @code
 * #include <DAVE3.h>
 * int main(void)
 *   {
 *    SPI001_ConfigType SPIConfig;
 *    // ... Initializes Apps configurations ...
 *     DAVE_Init(); // SPI001_Init() will be called inside DAVE_Init()
 *     SPIConfig.Mode = SPI001_STANDARD_FULLDUPLEX;      
 *     SPIConfig.HBMode = SPI001_LSB;  
 *     SPIConfig.ClkPol = SPI001_CLK_POL0;  
 *     SPIConfig.ClkPh = SPI001_CLK_PHASE0;     
 *     SPIConfig.BaudRate = 500000;           
 *     SPIConfig.LeadTrailDelay = SPI001_ONE_SCLK_PERIOD; 
 *     SPIConfig.NextFrameDelay = SPI001_ONE_SCLK_PERIOD;
 *     SPIConfig.WordLen = 8;           
 *     SPIConfig.FrameLen = 8;            
 *     SPIConfig.CESelected = 3; 
 *     SPI001_Configure(&SPI001_Handle0,&SPIConfig);
 *    while(1)
 *    {
 * 
 *    }
 *  }
 * @endcode<BR> </p>
 */
status_t SPI001_Configure
(
  const SPI001_HandleType* Handle,
  const SPI001_ConfigType* Config
);
  
/**
 * Reads out the content of the USIC receive FIFO Buffer. 
 * Returns true in case FIFO is not empty else otherwise.
 *
 * Service ID: 0x04
 *
 * @param[in]  Handle: SPI001 App instance handle
 * @param[out] DataPtr:  Pointer to data in which value is written
 *
 * @return     bool
 *             TRUE   if FIFO is not empty
 *             FALSE  if FIFO is empty
 *
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>SPI001_Handle0</b></I> is a global structure of type
 * SPI001_HandleType which will be configured in SPI001_Conf.c file using
 * UI parameters.
 * @code
 * #include <DAVE3.h>
 *
 * int main(void)
 * {
 *  uint16_t ReadData = 0;
 *  // ... Initializes Apps configurations ...
 *  DAVE_Init();
 *  //wait till standard receive buffer event is occurred
 *  while((SPI001_GetFlagStatus(&SPI001_Handle0,\
 *         SPI001_FIFO_STD_RECV_BUF_FLAG))!=SPI001_SET)
 *  {}
 *  //Read data
 *  SPI001_ReadData(&SPI001_Handle0,&ReadData);
 *  // ... infinite loop ...
 *  while(1)
 *  {
 *  }
 *  }
 * @endcode<BR> </p>
 */
bool SPI001_ReadData(const SPI001_HandleType* Handle,uint16_t* DataPtr);

/**
 * Writes out a word to the USIC FIFO transmit buffer register 
 * as per input transmit mode. 
 *
 * Reentrant : No
 *
 * @param[in]  Handle:  App handle
 * @param[in]  DataPtr: Pointer to data
 * @param[in]  TrMode: SPI Transmission modes
 *                     Note: Refer Enumeration type SPI001_TransmitMode 
                             for input values 
 *
 * @return     bool
 *             TRUE   if FIFO is not empty
 *             FALSE  if FIFO is full
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>SPI001_Handle0</b></I> is a global structure of type
 * SPI001_HandleType which will be configured in SPI001_Conf.c file using
 * UI parameters.
 * @code
 * #include <DAVE3.h>
 * 
 * int main(void)
 * {
 *  uint16_t SendData = 0x40;
 *  // ... Initializes Apps configurations ...
 *  DAVE_Init();
 *  // write data to tbuf depending on transmit mode
 *  SPI001_WriteData(&SPI001_Handle0,&SendData,SPI001_STANDARD);
 *  // ... infinite loop ...
 *  while(1)
 *  {
 * 
 *  }
 * }
 * @endcode<BR> </p>
 */
bool SPI001_WriteData
(
  const SPI001_HandleType* Handle,
  const uint16_t* DataPtr,
  SPI001_TransmitMode TrMode
);


/**
 * Returns input flag status. It returns SPI001_SET if the 
 * corresponding flag is set else otherwise.
 *
 * Service ID: 0x06
 *
 * @param[in]  Handle App handle
 * @param[in]  Flag   Flag which needs to be checked
 *                    Note: Refer Enumeration type SPI001_FlagStatusType
 *                          for input flag status.
 *
 * @return     status
 *             SPI001_SET    indicates Flag is set.
 *             SPI001_RESET  indicates Flag is reset.
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>SPI001_Handle0</b></I> is a global structure of type
 * SPI001_HandleType which will be configured in SPI001_Conf.c file using
 * UI parameters.
 * @code
 * #include <DAVE3.h>
 *
 * int main(void)
 * {
 *  uint16_t ReadData = 0;
 *  // ... Initializes Apps configurations ...
 *  DAVE_Init();
 *  //wait till standard receive buffer event is occurred
 *  while((SPI001_GetFlagStatus(&SPI001_Handle0,\
 *         SPI001_FIFO_STD_RECV_BUF_FLAG))!=SPI001_SET)
 *  {}
 *  //Read data
 *  SPI001_ReadData(&SPI001_Handle0,&ReadData);
 *  // ... infinite loop ...
 *  while(1)
 *  {
 *  }
 * }
 * @endcode<BR> </p>
 */
status_t SPI001_GetFlagStatus 
(
  const SPI001_HandleType* Handle,
  SPI001_FlagStatusType Flag
);

/**
 * Clears the specified flag status.
 *
 * Service ID: 0x07
 *
 * @param[in]  Handle App handle
 * @param[in]  Flag   SPI001 Flag which needs to be cleared
 *
 * @return    void
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>SPI001_Handle0</b></I> is a global structure of type
 * SPI001_HandleType which will be configured in SPI001_Conf.c file using
 * UI parameters.
 * @code
 * #include <DAVE3.h>
 *
 * int main(void)
 * {
 *  uint16_t ReadData = 0;
 *  // ... Initializes Apps configurations ...
 *  DAVE_Init();
 *  //wait till standard receive buffer event is occurred
 *  while((SPI001_GetFlagStatus(&SPI001_Handle0,\
 *         SPI001_FIFO_STD_RECV_BUF_FLAG))!=SPI001_SET)
 *  {}
 *  SPI001_ClearFlag(&SPI001_Handle0,SPI001_FIFO_STD_RECV_BUF_FLAG);
 *  //Read data
 *  SPI001_ReadData(&SPI001_Handle0,&ReadData);
 *  // ... infinite loop ...
 *  while(1)
 *  {
 *  }
 * }
 * @endcode<BR> </p>
 */
void SPI001_ClearFlag
(
  const SPI001_HandleType* Handle,
  SPI001_FlagStatusType Flag
);

/* Inclusion of configuration file */
#include "SPI001_Conf.h"

#endif /* SPI001_H_ */

