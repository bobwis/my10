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
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                           			  **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **
**                                                                            **
** MODIFICATION DATE : April 20, 2011                                         **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** SK           App Developer                                                 **
*******************************************************************************/
/**
 * @file   GUILC001.h
 *
 * @brief  This file contains the function prototypes and type declarations of
 *         GUI Compact Color App
 *
 */

#ifndef GUILC001_H_
#define GUILC001_H_


/******************************************************************************
 *                         INCLUDE FILES
 ******************************************************************************/
#include "DAVE3.h"
#include "GUILC001_Conf.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/**
 * @ingroup GUILC001_publicparam
 * @{
 */

/** USIC Channel Selected from the GUI. */
#define USIC_CHANNEL_SELECTED                                      (1)


/*******************************************************************************
 *                                ENUMERATIONS                                **
******************************************************************************/
/**
 * This enumerates GUILC001 App Errors.
 */

typedef enum GUILC001_ErrorCodesType
{
  /**
   * SPI001 Module Error  (1)
   */
  /*
  GROUPID  #22
  MODULENAME = GUI Compact Color App
  */
  /*
  ERRCODESTRING = GUILC001_SPI001_ERROR
  STRCODESTRING = Error in SPI001 App.
  */
  GUILC001_SPI001_ERROR
} GUILC001_ErrorCodesType;

/**
 * @}
 */

/**
 * @ingroup GUILC001_apidoc
 * @{
 */
/*******************************************************************************
**                        FUNCTION PROTOTYPES                                 **
*******************************************************************************/
/**
 * @brief The function configures the SPI bus at the run-time.
 * @return void
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void LCD_X_Serial_Init(void);

/**
 * @brief This routine writes to display controller using SPI bus, with A0 = 0
 * @param[in] Cmd Command to be sent to the display driver.
 * @return void
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void LCD_X_Serial_8_Write00(uint8_t Cmd);

/**
 * @brief This routine Writes to display controller using SPI bus, with A0 = 1
 * @param[in] Data Single byte of data to be displayed at the display driver.
 * @return void
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void LCD_X_Serial_8_Write01(uint8_t Data);
/**
 * @brief This routine Writes to display controller using SPI bus, with A0 = 1
 * @param[in] Data Multiple bytes of data to be displayed at the display driver.
 * @param[in] NumItems Number of bytes to be displayed.
 * @return void
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void LCD_X_Serial_M8_Write01(uint8_t *Data, int NumItems);
/**
 * @brief This routine reads from display controller using SPI bus, with A0 = 1
 * @param[in] Data Multiple bytes of data to be read from the display driver.
 * @param[in] NumItems Number of bytes to be read.
 * @return void
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void LCD_X_Serial_M8_Read01(uint8_t *Data, int NumItems);

/**
 * @brief The function is the App init function.
 * @return void
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void GUILC001_Init(void);
/**
 * @}
 */
#endif /* GUILC001_H_ */
