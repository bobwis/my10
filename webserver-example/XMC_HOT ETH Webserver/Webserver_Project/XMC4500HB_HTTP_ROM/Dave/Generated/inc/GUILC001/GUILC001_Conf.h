 

/* CODE_BLOCK_BEGIN[GUILC001_Conf.h] */
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
** MODIFICATION DATE : Dec 29, 2011                                           **
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
 



#ifndef GUILC001_CONF_H_
#define GUILC001_CONF_H_


 

/**
 * @file   GUILC001_Conf.h
 *
 * @brief  This file has the App instance configurations.
 *
 */

 /**
 * @ingroup  GUILC001_publicparam
 * @{
 */

/** Mouse Support Available */
#define  GUILC001_MOUSE_SUPPORT                                        0   


/**  Read support in display controller	*/
#define  GUILC001_READ_SUPPORT                           		      0   


/** This sets the cache size to be used by GUI library */
#define GUILC001_CACHE_SIZE                    					   32768

/**
 * @}
 */

#endif /* GUILC001_CONF_H_*/
/*CODE_BLOCK_END*/


