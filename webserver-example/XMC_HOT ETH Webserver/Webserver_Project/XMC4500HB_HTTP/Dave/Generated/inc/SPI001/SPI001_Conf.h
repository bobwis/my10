
/*CODE_BLOCK_BEGIN[SPI001_Conf.h]*/
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
** MODIFICATION DATE : Feb 04, 2013                                          **
**                                                                           **
******************************************************************************/
 
/******************************************************************************
**                       Author(s) Identity                                  **
*******************************************************************************
**                                                                           **
** Initials    Name                                                          **
** --------------------------------------------------------------------------**
** AEP         DAVE App Developer                                            **
******************************************************************************/

/**
 *
 * @file   SPI001_Conf.h
 *
 * @App Version SPI001 <1.0.18>
 *
 * @brief  Configuration header file generated based on UI settings 
 *         of SPI001 App
 *
 */
/*
 * Revision History
 * 01 Jun 2012 v1.0.0   Initial version
 * 26 Jul 2012 v1.0.2   Modified to support Quad mode functionalities
 * 17 Aug 2012 v1.0.4   Macro correction in USIC.h,Fix for OutputEnable for
 *                      HW controlled pins 
 * 04 Feb 2013 v1.0.12  1. Coding guidelines and MISRA fixes
 *                      2. Updated for comments and coding guidelines.
 *                      3. Updatd for revision history alignments.
 *                      4. Updated for XMC1000 devices.
 *                      5. Alignment of the revision history 
 */

#ifndef _CONF_SPI001_H_
#define _CONF_SPI001_H_

#include <DAVE3.h>


/*Base Address of mapped USIC Module for App Instance 0 */
#define SPI001_0_USIC 	  USIC0
/*Base Address of mapped USIC Channel for App Instance 0 */
#define SPI001_0_USIC_CH  USIC0_CH1
extern const SPI001_HandleType SPI001_Handle0;  


#endif /* End of _CONF_SPI001_H_ */
/*CODE_BLOCK_END*/

