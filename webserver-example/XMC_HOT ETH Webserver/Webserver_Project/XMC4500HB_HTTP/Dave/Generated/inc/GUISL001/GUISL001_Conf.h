 

/* CODE_BLOCK_BEGIN[GUISL001_Conf.h] */
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
** MODIFICATION DATE : Dec 11, 2012                                           **
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
 



#ifndef GUISL001_CONF_H_
#define GUISL001_CONF_H_


 

/**
 * @file   GUISL001_Conf.h
 *
 * @App Version GUISL001 <1.0.16>
 
 * @brief  This file has the App instance configurations.
 *
 * Revision History
 * 19 Jul 2012 v1.0.8 Initial version
 * 27 Nov 2012 v1.0.10 Version updated
 * 11 Dec 2012 v1.0.12 Added GUISL001 as a prefix to all macros
 */
 

/**
 * @ingroup GUISL001_publicparam
 * @{
 */
 
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/ 
/** RTOS or Non-RTOS environment */
#define GUISL001_RTOS_PRESENT                            0

/** Mouse Support Enabled/Disabled 	*/
#define  GUISL001_SUPPORT_MOUSE                          0   


/** Windows Manager Supported Enabled/Disabled*/
#define GUISL001_WINSUPPORT							  0

/**
 * @}
 */

#endif

/*CODE_BLOCK_END*/


