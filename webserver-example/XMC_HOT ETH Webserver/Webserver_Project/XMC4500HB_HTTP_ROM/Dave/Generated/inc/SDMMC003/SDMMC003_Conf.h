 

/* CODE_BLOCK_BEGIN[SDMMC003_Conf.h] */
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
** MODIFICATION DATE : Aug 3, 2012                                            **
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
 

#ifndef SDMMC003_CONF_H_
#define SDMMC003_CONF_H_


/**
 * @file   SDMMC003_Conf.h
 *
 * @App Version SDMMC003 <1.0.14>
 * 
 * @brief  This file has the App instance configurations.
 *
 * Revision History
 * 22 March 2012  v1.0.0    Initial version
 * 03 Aug 2012    v1.0.12   Cosmetic Changes
 */

/* RTOS or Non-RTOS environment */
#define SDMMC_RTOS_PRESENT                                                 	  0

/* Card Detection signal supported/not supported  by the kit/board  	*/
#define SDMMC_CARD_DETECTION_SUPPORT                             			        0   
/* 4-data lines option enabled or disabled */
#define SDMMC_SUPPORT_4_BUS_WIDTH											                        1

/* MMC card support */
#define SDMMC_SUPPORT_MMC_CARD                                                0

#define SDMMC_PREEMPTION_PRIORITY                                 40
#define SDMMC_SUB_PRIORITY                                     0

#endif
/*CODE_BLOCK_END*/




