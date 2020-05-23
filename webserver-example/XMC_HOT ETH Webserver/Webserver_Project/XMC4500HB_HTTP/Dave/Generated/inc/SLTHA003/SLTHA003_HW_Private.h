
/**************************************************************************//**
 *
 * Copyright (C) 2013 Infineon Technologies AG. All rights reserved.
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
** PLATFORM : Infineon <Microcontroller name, step>                           **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** MODIFICATION DATE : February 11, 2013                                      **
**                                                                            **
*******************************************************************************/

/**
 * @file  SLTHA003HW_Private.h
 *
 * @brief This file contains macros related to Controller specific parameters
 *        
 *
 */



#ifndef _SLTHA003_HW_PRIVATE_H_
#define _SLTHA003_HW_PRIVATE_H_


#ifndef  __TARGET_DEVICE__

#ifndef XMC45
#define XMC45 45
#endif
#ifndef XMC44
#define XMC44 44
#endif
#ifndef XMC42
#define XMC42 42
#endif

#define __TARGET_DEVICE__ XMC45

#endif

#endif 

