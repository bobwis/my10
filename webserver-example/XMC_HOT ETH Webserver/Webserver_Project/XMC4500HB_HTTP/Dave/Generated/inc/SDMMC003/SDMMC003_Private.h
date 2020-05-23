
/*CODE_BLOCK_BEGIN[SDMMC003_Private.h]*/

/******************************************************************************
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with 
 * Infineon's microcontrollers.
 * This file can be freely distributed within development 
 * tools that are supporting such microcontrollers. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **
**                                                                            **
** MODIFICATION DATE : Oct 1, 2012                                         **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials    Name                                                           **
** ---------------------------------------------------------------------------**
** SK          App Developer                                                  **
*******************************************************************************/



#ifndef SDMMC003_PRIVATE_H_
#define SDMMC003_PRIVATE_H_


/**
 * @file SDMMC003_Private.h
 *
 * @App Version SDMMC003 <1.0.14>
 *
 * @brief  This file contains all the private functions prototypes and type 
 * declarations in Non-Rtos Environment.
 *
 * Revision History
 * 22 March 2012  v1.0.0    Initial version
 * 3 Aug 2012     v1.0.12   Erase optimizations introduced.
 *                          Make File System(MKFS) through software issue fixed. 
 * 1 Oct 2012     v1.0.14   Delays reduced.
 *                          Removed RTOS specific code. 
 */


#include <DAVE3.h>

/**
 * @cond INTERNAL_DOCS
 */

/**
 * @ingroup SDMMC003_privateparam
 * @{
 */
/*******************************************************************************
**                       Macro Definitions                                    **
*******************************************************************************/



/** All Normal Interrupt Status Enable & Error Int Status Enable bit fields
 * except Auto Cmd Error,Block Gap Event, DMA Int, Card Interrupt, ADMA Error,
 *  Vendor specific
 */
#define SDMMC003_NORMAL_INT_STATUS_ENABLE                     (0x00F3U)
#define SDMMC003_ERROR_INT_STATUS_ENABLE                      (0xE0FFU)

#define SDMMC003_NORMAL_INT_STATUS_BITS            (0x7fffU)
/* Command line Interrupt errors status bitmask    */
#define SDMMC003_ERROR_CMD_STATUS_BITMASK                     (0x000FU)
/* Data line Error status  bitmask      */
#define SDMMC003_ERROR_DATA_STATUS_BITMASK                    (0x0070U)

/*All Data lines High Status Value in Present State Register */
#define SDMMC003_ALL_DATA_LINES_HIGH                      (0xFU)
/* Error Interrupt Status Bitmask         */
#define SDMMC003_ALL_ERROR_STATUS_BITMASK                 (0xFFFFU)


/* All Normal Interrupt Signal Enable & Error Int Signal Enable bit fields
 * except Block Gap Event, DMA Int, Card Interrupt, ADMA Error, Vendor specific
 */
/* Enable this macro if card detection feature available */
#if SDMMC_CARD_DETECTION_SUPPORT
#define SDMMC003_NORMAL_INT_SIGNAL_ENABLE                     (0x00F3U)
#else
#define SDMMC003_NORMAL_INT_SIGNAL_ENABLE                     (0x0033U)
#endif
#define SDMMC003_ERROR_INT_SIGNAL_ENABLE                      (0xE0FFU)



/* SDCLK frequency Select value in ClockControl Register */
#define SDMMC003_CTRL_SDCLK_FREQ_SEL_VALUE                   (0x1U)

/* Data Timeout counter value in Timeout Control Register */
#define SDMMC003_CTRL_DAT_TIMEOUT_CNT_VAL_VALUE               (0xeU)

/* SD Bus Voltage value in Power Control Register */
#define SDMMC003_CTRL_SD_BUS_VOLTAGE_SEL_VALUE                (0x07U)


/* Switch function bitmask */
#define SDMMC003_SWITCH_FUNC_GRP1_STATUS_BITMASK           (0x0000000FU)
#define SDMMC003_SWITCH_FUNC_GRP1_STATUS_BITPOS            (0x0U)

/* Transfer Block Register */
#define SDMMC003_TX_BLOCK_SIZE_VALUE                       (0x0200U)

/* Card's OCR register  */
#define SDMMC003_OCR_POWER_STATUS_BITMASK                  (0x80000000U)
#define SDMMC003_OCR_CCS_BITMASK                           (0x40000000U)
#define SDMMC003_MMC_OCR_ACCESS_MODE_BITMASK               (0x60000000U)
#define SDMMC003_MMC_OCR_ACCESS_MODE_BITPOS                (0x1DU)

/* Response Register */
#define SDMMC003_HC_RESPONSE1_BITPOS                       (0x10U)

/*  SD Card's CMD8 response R7 bit positions */
#define SDMMC003_SD_CMD8_CHECK_PATTERN_VALUE               (0xAAU)
#define SDMMC003_SD_CMD8_CHECK_PATTERN_BITMASK             (0xFFU)
#define SDMMC003_SD_CMD8_CHECK_PATTERN_BITPOS              (0x00U)
#define SDMMC003_SD_CMD8_VHS_BITPOS                        (0x8U)
#define SDMMC003_SD_CMD8_VHS_BITMASK                       (0xFU)
#define SDMMC003_SD_VHS_PATTERN_2_7_3_6_VALUE              (0x1U)

/* RCA Register */
#define SDMMC003_MMC_DEFAULT_RCA                           (0x0001U)
#define SDMMC003_ARG_RCA_BITPOS                            (0x10U)

/* SD Status */
#define SDMMC003_SD_CARD_TYPE_BITMASK                      (0xFFFFU)

/* SCR Register Bitmask */
#define SDMMC003_SCR_BUS_WIDTH4_BITMASK                    (0x4U)

/* Start of Card Status Register i.e CSR Error Bits Bitmask */
#define SDMMC003_CSR_OUT_OF_RANGE_BITMASK                  (0x80000000U)
#define SDMMC003_CSR_ADDRESS_ERROR_BITMASK                 (0x40000000U)
#define SDMMC003_CSR_BLOCK_LEN_ERROR_BITMASK               (0x20000000U)
#define SDMMC003_CSR_ERASE_SEQ_ERROR_BITMASK               (0x10000000U)
#define SDMMC003_CSR_ERASE_PARAM_BITMASK                   (0x08000000U)
#define SDMMC003_CSR_WP_VIOLATION_BITMASK                  (0x04000000U)
#define SDMMC003_CSR_LOCK_UNLOCK_FAILED_BITMASK            (0x01000000U)
#define SDMMC003_CSR_COM_CRC_ERROR_BITMASK                 (0x00800000U)
#define SDMMC003_CSR_ILLEGAL_COMMAND_BITMASK               (0x00400000U)
#define SDMMC003_CSR_CARD_ECC_FAILED_BITMASK               (0x00200000U)
#define SDMMC003_CSR_CC_ERROR_BITMASK                      (0x00100000U)
#define SDMMC003_CSR_ERROR_BITMASK                         (0x00080000U)
#define SDMMC003_CSR_CSD_OVERWRITE_BITMASK                 (0x00010000U)
#define SDMMC003_CSR_WP_ERASE_SKIP_BITMASK                 (0x00008000U)
#define SDMMC003_SWITCH_ERROR_BITMASK                      (0x00000080U)
#define SDMMC003_CSR_ASK_SEQ_ERROR_BITMASK                 (0x00000008U)
#define SDMMC003_CSR_CARD_IS_LOCKED_BITMASK                (0x02000000U)
#define SDMMC003_CSR_CURRENT_STATE_BITMASK                 (0x00001D00U)
#define SDMMC003_CSR_CURRENT_STATE_BITPOS                  (0x9U)
#define SDMMC003_CSR_CURRENT_STATE_TRANS_VALUE             (0x4U)
#define SDMMC003_CSR_CARD_IS_LOCKED_BITMASK                (0x02000000U)
/* End of Card Status Register i.e CSR Error Bits */


/* Some Command's static Arguments */
#define SDMMC003_ARGUMENT0                                 (0x00000000U)
#define SDMMC003_SD_CMD8_ARG                               (0x000001AAU)
#define SDMMC003_SD_ACMD41_F80_ARG                         (0x00100000U)
#define SDMMC003_SD_ACMD41_F81_ARG                         (0x40100000U)
#define SDMMC003_MMC_CMD1_ARG                              (0x40FF8000U)
#define SDMMC003_MMC_4BUS_WIDTH_ARG                        (0x03B70100U)
#define SDMMC003_SD_4BUS_WIDTH_ARG                         (0x00000002U)
#define SDMMC003_MMC_HIGH_SPEED_ARG                        (0x03B90100U)
#define SDMMC003_SD_HIGH_SPEED_ARG                         (0x80000001U)

/**
 * Delay Macros
 */
#define SDMMC003_CARD_POWER_DELAY                                	 20
#define SDMMC003_DELAY_IN_TRANSFER                                1000
#define SDMMC003_RESET_In_DATA_TRANSFER                           1000
#define SDMMC003_DELAY_IN_COMMAND                                 1000
#define SDMMC003_RESET_DELAY                                      500
#define SDMMC003_CLOCK_STABLE_DELAY                               1000

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/* This macro is is used to  enable the signal bits in
 * Normal Signal Enable register*/
#define SDMMC003_ENABLE_INT_SIGNAL(Mask)\
{ \
  (SDMMC->EN_INT_SIGNAL &= ~Mask ); \
  (SDMMC->EN_INT_SIGNAL |= Mask ); \
}
/* This macro is is used to  disable the signal bits in
 * Normal Signal Enable register*/
#define SDMMC003_DISABLE_INT_SIGNAL(Mask)  (SDMMC->EN_INT_SIGNAL &= ~Mask)

/* Number of Reset retries during card initialization */
#define SDMMC003_NUM_CARD_RESET_RETRIES     2
/* Block Size in bytes */
#define SDMMC003_BLOCK_SIZE                 512UL
/* Block size in Quad bytes.  */
#define SDMMC003_NUM_QUADLETS_IN_BLOCK      SDMMC003_BLOCK_SIZE >> 2


/*******************************************************************************
 *                                STRUCTURES                                  **
 ******************************************************************************/
/**
 * @brief This structure stores the command register fields.
 */
typedef struct SDMMC003_CommandType
{
  /**
   * This variable determine Response types
   *  00 No Response
   *  01 Response Length 136
   *  10 Response Length 48
   *  11 Response Length 48,  check Busy after response
   */
   uint16_t ResponseTypeSelect : 2;

  /**
   * Reserved bits
   */
   uint16_t  Rsvd1 : 1;

  /**
   * If this variable stores value 1, the Host Controller shall check the CRC
   * field in the response. If an error is detected, it is reported as a
   * Command CRC Error.If this bit is set to 0, the CRC field is not checked
   */
  uint16_t CrcCheckEnable : 1;
  /**
   * If this variable stores value 1, the Host Controller shall check the Index
   * field in the response to see if it has the same value as the command index.
   * If it is not, it is reported as a Command Index Error. If this bit is set
   * to 0,the Index field is not checked.
   */
  uint16_t IndexCheckEnable : 1 ;
  /**
   * This variable stores the value 0 or  1 to indicate that data is present and
   * shall be transferred using the DAT line or not
   */
  uint16_t DataPresentSelect : 1 ;
  /**
   * There are three types of special commands: Suspend, Resume and Abort. 11b Abort
   * 10b Resume 01b Suspend 00b Normal
   */
  uint16_t CommandType : 2;
  /**
   * These variable shall be set to the command number (CMD0-63, ACMD0-63) which
   * describes the command to be issued
   */
  uint16_t CommandIndex : 6 ;
  /**
   * Reserved
   */
  uint16_t  Rsvd2 : 2;
} SDMMC003_CommandType;

/**
 * @brief This structure stores the card's register content information.
 */
typedef struct SDMMC003_CardInfoType
{
  /**
   * This variable stores Card's  OCR register contents
   */
  uint32_t Ocr;
  /**
   * This structure variable stores Card's CID Register contents
   */
  uint32_t CidArray[4];
  /**
   * This structure variable stores Card's CSD register contents
   */
  uint32_t CsdArray[4];
  /**
   * This  variable stores Card's SCR register contents
   */
  SDMMC003_SCRType Scr;
  /**
   * This  variable stores Card's Relative address
   */
  uint16_t Rca;
} SDMMC003_CardInfoType;

/**
 * @brief This structure stores the Interrupt Context Information.
 */
typedef struct SDMMC003_InterruptContext
{
  /** InterruptStatusShadow stores the  Interrupt status register status bits*/
  uint16_t InterruptStatusShadow;
  /** CmdFlag is set when any command related interrupt occurs.*/
  uint8_t CmdFlag;
  /** DataFlag is set when any data transfer error interrupt occurs.  */
  uint8_t DataFlag;
  /** TransferFlag is set when Transfer complete interrupt occurs . */
  uint8_t TransferFlag;
} SDMMC003_InterruptContext;


/*******************************************************************************
 *                                ENUMERATIONS                                **
*******************************************************************************/

/**
 * @brief This enumerates the Response Types.
 */
typedef enum SDMMC003_ResponseType
{
  /**
   * No Response
   */
  SDMMC003_NO_RESPONSE,
  /**
   * Response Type R1
   */
  SDMMC003_RESPONSE_R1,
  /**
   * Response Type R1b
   */
  SDMMC003_RESPONSE_R1b,
  /**
   * Response Type 2
   */
  SDMMC003_RESPONSE_R2,
  /**
   * Response Type 3
   */
  SDMMC003_RESPONSE_R3,
  /**
   * Response Type 6
   */
  SDMMC003_RESPONSE_R6,
  /**
   * Response Type R7
   */
  SDMMC003_RESPONSE_R7
} SDMMC003_ResponseType;



/**
 * @}
 */



/**
 * @ingroup SDMMC003_privatefunc
 * @{
 */

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/

/**
 * @brief This function will Set the bit in Software Reset register to reset the
 * Host Controller Registers.
 * @param[in]  Reset Bitmask of the field to be set in the SW Reset Register
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * SDMMC003_ERROR: If reset fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t SDMMC003_lReset(uint8_t Reset);

/**
 * @brief This function sends the command to the SD/MMC card.
 * @param[in] CommandPtr Command to issue.
 * @param[in] Argument  Argument to the command
 * @param[in] ResponseType Type of the response expected.
 * @param[out] ResponsePtr Pointer to store response received.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * SDMMC003_ERROR: If send command fails.<BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t SDMMC003_lSendCommand
(
  const SDMMC003_CommandType *CommandPtr,
  uint32_t Argument,
  SDMMC003_ResponseType ResponseType,
  void *ResponsePtr
);

/**
 * @brief This function  reads the response as per the response type.
 * @param[in]  CommandPtr Command whose response to read.
 * @param[in]  ResponseType Type of the response expected.
 * @param[out] ResponsePtr Pointer to store response received.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t  SDMMC003_lReadResponse
( 
  const SDMMC003_CommandType *CommandPtr,
  SDMMC003_ResponseType ResponseType,
  void *ResponsePtr
);

/**
 * @brief This function checks for the errors in the response.
 * @param[in]  CardStatusPtr Status to check errors in.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t  SDMMC003_lCheckErrorInResponse( const uint32_t  *CardStatusPtr );

/**
 * @brief This function will initialize the SD card.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t SDMMC003_lInitializeCard(void);

#if SDMMC003_MMC_CARD
/**
 * @brief This function will initialize the MMC card.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t SDMMC003_lInitializeMmcCard(void);
#endif /* SDMMC003_MMC_CARD */

/**
 * @brief This function configures the registers for Single Block Transfer.
 * @param[in] CommandPtr Single Transfer Command
 * @param[in] Argument Argument to the command
 * @param[in] BlockSize Block Size in Bytes.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t SDMMC003_lConfigureForSingleTransfer
(
  const SDMMC003_CommandType *CommandPtr,
  uint32_t Argument,
  uint16_t BlockSize
);

/**
 * @brief This function configures the registers for Multi Block Transfer.
 * @param[in] TmpAddrPtr Address to be set in the Argument resgister
 * @param[in] NumberOfBlocks Number of Blocks.
 * @param[in] CommandPtr Multi Block Transfer Command
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t SDMMC003_lConfigureRegForMultiTransfer
(
  uint32_t *TmpAddrPtr,
  uint32_t NumberOfBlocks,
  const SDMMC003_CommandType *CommandPtr
);

/**
 * @brief This function queries the voltage operating condition from the card.
 * i.e Send CMD8 and checks the response
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t SDMMC003_lQueryOperatingCond(void);

/**
 * @brief This function queries the card's voltage window
 * i.e Send ACMD41 and checks the response
 * @param[in] Argument Rca in the Argument.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 */
status_t SDMMC003_lQueryVoltage(uint32_t Argument);

/**
 * @brief This function identifies the card type information and update it
 * accordingly in the  Handle structure .
 * @return <b>void</b><BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SDMMC003_lWriteCardType(void);

/**
 * @brief This function reads the card registers like  CSD, SCR and write
 * protection info. 
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * SDMMC003_ERROR: If function fails.<BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lReadCardRegisters(void);

/**
 * @brief This function checks for Argument related errors like Out of Range,
 * Address Error, Block length error, Write Protection
 * @param[in] CardStatusPtr Status in which error to Check
 * @param[in] ErrorPtr Flag to set to 1, if any error detected.
 * @return <b>void</b><BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SDMMC003_lCheckArgumentError
(
  const uint32_t  *CardStatusPtr,
  uint8_t *ErrorPtr
);

/**
 * @brief This function checks for Erase related errors like Erase Sequence,
 * Erase Skip error, Erase Param error
 * @param[in] CardStatusPtr Status in which error to Check
 * @param[in] ErrorPtr Flag to set to 1, if any error detected.
 * @return <b>void</b><BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SDMMC003_lCheckEraseError
(
  const uint32_t *CardStatusPtr,
  uint8_t *ErrorPtr
);

/**
 * @brief This function checks response error types in card's internal
 *  error category
 * @param[in] CardStatusPtr Status in which error to Check
 * @param[in] ErrorPtr Flag to set to 1, if any error detected.
 * @return <b>void</b><BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SDMMC003_lCheckCardError
(
  const uint32_t *CardStatusPtr,
  uint8_t *ErrorPtr
);

/**
 * @brief This function sets the voltage window in OCR register.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails. <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t  SDMMC003_lSetVoltageWindow(void);


/**
 * @brief This function reads the  Relative card address of the card.
 * @return <b>status_t</b><BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails <BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lReadRca(void);

/**
 * @brief This function finds out the Write protection status of the card.
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails <BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lSetWriteProtect(void);

/**
 * @brief This function checks whether the CMD and DATA lines are free before
 *  issuing any command.
 * @param[in] CommandPtr Command for which CMD and DATA  lines needs to check.
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails <BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lCheckDatCmdline ( const SDMMC003_CommandType *CommandPtr);

/**
 * @brief This function clears the card related structures and stops the SD clock.
 * @return void <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SDMMC003_lCardCleanUp(void);

/**
 * @brief This function switches the bus width to 4-bit if is supported.
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lSwitchBusWidth(void);

/**
 * @brief This function is use to switch the card state to transferring state
 * if the card is not in the transferring state.
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No</b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lSwitchToTransferState(void);

/**
 * @brief This function switches the card speed to high speed if is supported.
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t  SDMMC003_lSwitchSpeed(void);

/**
 * @brief This function reads the card registers after the card is initialized.
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lAfterCardInitialize(void);


/**
 * @brief This function checks the Lock Status.
 * @param[in] OperationMode Lock or Unlock Status to verify
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lCheckLockStatus(SDMMC003_CardLockMode OperationMode);

/**
 * @brief This function handles the Interrupt in Normal Interrupt Status
 * Register.
 * @param[in] IntStatus Interrupt Status in the Status register
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lNormalInterruptHandler(uint16_t IntStatus);
/**
 * @brief This function handles the Interrupt in Error Interrupt Status Register.
 * @param[in] IntStatus Interrupt Status in the Normal Interrupt Status register
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lErrorInterruptHandler(uint16_t IntStatus);

/**
 * @brief This function performs the recovery task if any error interrupt occurs.
 * @param[in] InterruptStatus Interrupt Status in the Error Interrupt Status register
 * @return status_t<BR>
 * SDMMC003_RECOVERABLE_ERROR: If the error is recoverable <BR>
 * SDMMC003_NONRECOVERABLE_ERROR: Non recoverable error <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lErrorInterruptRecovery(uint16_t InterruptStatus, uint8_t IssueAbort);

/**
 * @brief This function performs the data transfer to/from the card .
 * @param[in] BufferPtr Buffer to read into or write data from.
 * @param[in] TransferMode Direction of data transfer.
 * @param[in] QuadBytes Number of Quad bytes.
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lDataTransfer
(
  uint32_t *BufferPtr,\
  SDMMC003_DataTrasferType TransferMode, \
  uint32_t QuadBytes
);

/**
 * @brief This function performs the ACMD 12 error Recovery.
 * @return void<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */

void SDMMC003_lAcmdErrorRecovery(void);

/**
 * @brief This function performs the  Multiple Block Transfer.
 * @param[in] AddrPtr Card Address from where to read or write data into
 * @param[in] NumberOfBlocks Number of blocks to transfer
 * @param[in] CommandPtr Multi Block Transfer Command.
 * @param[in] BufferPtr Buffer to read into or write data from.
 * @param[in] TransferMode Transfer direction .
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lMultiBlockTransfer
(
  uint32_t *AddrPtr,\
  uint32_t NumberOfBlocks,\
  const SDMMC003_CommandType *CommandPtr, \
  uint32_t *BufferPtr,SDMMC003_DataTrasferType TransferMode 
);

/**
 * @brief This function performs the  Single Block Transfer.
 * @param[in] CommandPtr Single Block Transfer Command.
 * @param[in] Argument Card Address from where to read or write data into
 * @param[in] BlockSize Number of bytes to transfer
 * @param[in] BufferPtr Buffer to read into or write data from.
 * @param[in] TransferMode Transfer direction .
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lSingleBlockTransfer
(
  const SDMMC003_CommandType *CommandPtr,
  uint32_t Argument,
  uint16_t BlockSize,
  uint32_t *BufferPtr,
  SDMMC003_DataTrasferType TransferMode
);

/**
 * @brief This function is used to put some delay wherever required .
 * @param[in] DelayTime Delay Time in Mili seconds.
 * @return void
 */
void SDMMC003_lDelay(uint32_t DelayTime);
/**
 * @brief This function is SDMMC Interrupt Handler function.
 * @return void
 */
void SDMMC0_0_IRQHandler(void);
/**
 * @brief This function is SDMMC Interrupt Handler function.
 * @return status_t<BR>
 * osOK: correct execution: operation completed<BR>
 * osEventSignal:signal event occured<BR>
 * osEventMessage: message event occured<BR>
 * osEventMail: mail event occured<BR>
 * osEventTimeout: timeout occured<BR>
 * osErrorParameter:parameter error: A mandantory parameter was missing, out of range, or specified an incorrect object.<BR>
 * osErrorResource: resource not available: a specified resource was not available.<BR>
 * osErrorTimeoutResource: resource not available within given time: a specified resource was not available within the timeout period.<BR>
 * osErrorIRQ: not allowed in IRQ context: the function cannot be called from interrrupt service routines.<BR>
 * osErrorNoMemory: system is out of memory: it was impossible to allocate or reserve memory for the operation.<BR> 
 */
status_t SDMMC003_lCreateOSResources(void);

/**
 * @brief  This function performs the card initialization and identification operation.
 * @return  status_t <BR>
 * DAVEApp_SUCCESS: If card initialization and identification  is success.<BR>
 * SDMMC003_ERROR: If error occurs.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lCardIdentificationProcess(void);


/**
 * @brief  This function stops and delete the timer in NON-RTOS environment.
 * @return  void <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SDMMC003_lStopTimer(handle_t TimerId);
/**
 * @brief  This function creates and starts the timer for the DelayTime time in 
 * miliseconds in NON-RTOS environment.
 * @param[in] DelayTime Timer time period in miliseconds.
 * @return  handle_t <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
handle_t SDMMC003_lStartTimer(uint32_t DelayTime);


/**
 * @brief This function is used to check the sector address is out of bound or not.
 * @param[in] SectorNumberParam Sector Number.
 * @param[in] SectorCountParam Sector Count.
 * @return status_t<BR>
 * DAVEApp_SUCCESS: If the function is successful<BR>
 * SDMMC003_SECTOR_OUT_OF_BOUND: If Sector number is out of bound.<BR>
 * SDMMC003_ERROR: If function fails<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lCheckSectorBound(uint32_t SectorNumberParam, \
                                             uint32_t SectorCountParam);

/**
 * @brief This is the local function which does the actual erase operation on the card.
 * @param[in] StartAddr Start Erase Sector Address 
 * @param[in] EndAddr Erase Sector Address.
 * @param[in] TimeoutVal Erase Timeout Value for AU chunk in one Erase Operation.
 * @return status_t<BR>
 * DAVEApp_SUCCESS:  If erase is successful.<BR>
 * SDMMC003_ERROR: If erase fails.<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lLocalErase
(
  uint32_t StartAddr,
  uint32_t EndAddr,
  uint32_t TimeoutVal
);
/**
 * @brief This is the local function which updates the handle with the lock/unlock state of the card
 * @param[in] CardStatus 32-bit Card Status response recieved.
 * @param[in] CommandIndex Command Index.
 * @return void<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SDMMC003_lGetCardLockState(uint32_t CardStatus, uint16_t CommandIndex);

/**
 * @brief This is the local function to introduce the delay in data transfer.
 * @param[in] DelayTime Delay Time in miliseconds.
 * @return void<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lTransferDelay(uint32_t DelayTime);

/**
 * @brief This is the local function to introduce the delay in command transfer.
 * @param[in] DelayTime Delay Time in miliseconds.
 * @return void<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
status_t SDMMC003_lCommandDelay(uint32_t DelayTime);

/**
 * @brief This function checks the PCMD flag.
 * @param[in] PCMDFlag of ACMD register.
 * @return void<BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void SDMMC003_CheckPCMDFlag(status_t PCMDFlag);


/**
 * @brief This function is the call back function for System timer to be used in
 * the Non-RTOS enviroment.
 * @param[in] Temp Argument pointer.
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void Timer_CallBack(void* Temp);

#endif /* SDMMC003_PRIVATE_H_ */


/**
 * @}
 */

/**
 * @endcond
 */
/*CODE_BLOCK_END*/





