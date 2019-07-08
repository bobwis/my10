
/**************************************************************************//**
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
** PLATFORM : Infineon <Microcontroller name, step>                           **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** MODIFICATION DATE : February 12, 2013                                      **
**                                                                            **
*******************************************************************************/

/**
 * @file  DAVE3.h
 *
 * @brief This file contains all public data structures,enums and function
 *        prototypes
 *
 */

#ifndef _DAVE3_H_
#define _DAVE3_H_

//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void DAVE_Init(void);

void SystemInit_DAVE3(void);
      
//****************************************************************************
// @Project Includes
//****************************************************************************


#include <XMC4500.h>

#include "../../inc/LIBS/types.h"
	
#include "../../inc/DAVESupport/MULTIPLEXER.h"


// #include APP HEADER FILES.
	#include "../../inc/LIBS/LIBS.h" 
	#include "../../inc/DBG001/DBG001.h" 
	#include "../../inc/CLK001/CLK001.h" 
	#include "../../inc/SYSTM001/SYSTM001.h" 
	#include "../../inc/ETH002/ETH002.h" 
	#include "../../inc/RESET001/RESET001.h" 
	#include "../../inc/ETH001/ETH001.h" 
	#include "../../inc/ETH004/ETH004.h" 
	#include "../../inc/SDMMC003/SDMMC003.h" 
	#include "../../inc/SDMMC001/SDMMC001.h" 
	#include "../../inc/NVIC_SCU001/NVIC_SCU001.h" 
	#include "../../inc/RTC001/RTC001.h" 
	#include "../../inc/FATFS004/FATFS004.h" 
	#include "../../inc/FATFS002/FATFS002.h" 
	#include "../../inc/LMM001/LMM001.h" 
	#include "../../inc/GMM001/GMM001.h" 
	#include "../../inc/SLTHA003/SLTHA003.h" 
	#include "../../inc/SLTHA001/SLTHA001.h" 
	#include "../../inc/WEBSERVER001/WEBSERVER001.h" 
	#include "../../inc/ADCGLOB001/ADCGLOB001.h" 
	#include "../../inc/ADCGROUP001/ADCGROUP001.h" 
	#include "../../inc/IO001/IO001.h" 
	#include "../../inc/ADCCH001/ADCCH001.h" 
	#include "../../inc/ADC002/ADC002.h" 
	#include "../../inc/MOTORLIBS/MOTORLIBS.h" 
	#include "../../inc/SPI001/SPI001.h" 
	#include "../../inc/IO004/IO004.h" 
	#include "../../inc/GUILC001/GUILC001.h" 
	#include "../../inc/GUISL001/GUISL001.h" 

                         
#endif  /** ifndef _DAVE3_H_ */

