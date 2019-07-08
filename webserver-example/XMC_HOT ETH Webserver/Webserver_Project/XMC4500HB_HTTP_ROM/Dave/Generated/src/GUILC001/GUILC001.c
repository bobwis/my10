
/*CODE_BLOCK_BEGIN[GUILC001.c]*/
/*******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                           			  **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Dec 12, 2012                                           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** SK           App Developer                                                 **
**                                                                            **
*******************************************************************************/


/**
 * @file   GUILC001.c
 *
 * @brief  This file contains the private and public function definitions
 * of Compact Color App of GUI.
 * Revision History: 12-12-12 GID_COMPACTCOLOR macro is replaced with DBG002_GID_GUILC001
 *                            and ERROR macro is prefixed with DBG002
 * 13-12-12 Dummy macros for DBG002 are added                            
 *
 */

/*****************************************************************************
 *                          INCLUDE FILES
 *****************************************************************************/
#include "DAVE3.h"


const SPI001_HandleType* GUILC001_SPIHandle = &SPI001_Handle0;

#define GUILC001_IOHandle (IO004_Handle1)

  
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

#define APP_GID DBG002_GID_GUILC001

/**
 * @cond INTERNAL_DOCS
 */
/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
/* Init function required by DAVE app. */
void GUILC001_Init(void)
{

}


/* <<<DD_GUILC001_API_1>>> */
/*
 *  This routine should be called from your application program  to configure
 *  the SPI bus at the run-time.
 *
 */
void LCD_X_Serial_Init()
{

}

/* Sends one byte of data to the OLED through SPI */
void LCD_X_Send1(uint8_t Data)
{
  status_t Status;
  uint16_t Shadow_Data = Data;
  SPI001_ClearFlag(GUILC001_SPIHandle,SPI001_TRANS_SHIFT_IND_FLAG);
  Status = SPI001_WriteData(GUILC001_SPIHandle, &Shadow_Data, SPI001_STANDARD_FULLDUPLEX);
  if (Status != TRUE)
  {
    DBG002_ERROR(DBG002_GID_GUILC001,GUILC001_SPI001_ERROR,0,0);
  } /* End of "if (Status != TRUE)" */
  while(SPI001_SET != SPI001_GetFlagStatus(GUILC001_SPIHandle,SPI001_TRANS_SHIFT_IND_FLAG));
}

/* Reads one byte of data from the OLED through SPI */
unsigned char LCD_X_Read1(void)
{
  uint16_t LastWord = 0;
  uint16_t Shadow_Data=0xFFFF;
  SPI001_ClearFlag(&SPI001_Handle0,SPI001_RECV_IND_FLAG);
  SPI001_WriteData(GUILC001_SPIHandle, &Shadow_Data, SPI001_STANDARD_FULLDUPLEX);
  //while(!SPI001_GetFlagStatus(&SPI001_Handle0,SPI001_FIFO_STD_RECV_BUF_FLAG));
  while(!SPI001_GetFlagStatus(&SPI001_Handle0,SPI001_RECV_IND_FLAG));

  SPI001_ReadData(&SPI001_Handle0,&LastWord);

  return (unsigned char)LastWord;
}

/* <<<DD_GUILC001_API_2>>> */
/*
 *  This routine Writes to display controller using SPI bus, with A0 = 0
 *
 */
void LCD_X_Serial_8_Write00(uint8_t Cmd)
{
  /* Clear the A0 pin */
  IO004_ResetPin(GUILC001_IOHandle);
  /* Write to the SPI Bus */
/* <<<DD_GUILC001_API_2_1>>> */
  LCD_X_Send1(Cmd);
}

/* <<<DD_GUILC001_API_3>>> */
/*
 *  This routine Writes to display controller using SPI bus, with A0 = 1
 *
 */
void LCD_X_Serial_8_Write01(uint8_t Data)
{
  /* Set the A0 pin*/
  IO004_SetPin(GUILC001_IOHandle);

/* <<<DD_GUILC001_API_3>>> */
  LCD_X_Send1(Data);
}

/* <<<DD_GUILC001_API_4>>> */
/*
 *  This routine writes multiple bytes to display controller using SPI bus,
 *  with A0 = 1.
 *
 */
void LCD_X_Serial_M8_Write01(uint8_t *Data, int NumItems)
{
  uint8_t  DataCopy;

  /* Set the A0 pin*/
	IO004_SetPin(GUILC001_IOHandle);
	do
	{
	  DataCopy = *Data;
	  LCD_X_Send1(DataCopy);
	  Data++;
	}while(--NumItems);
}


/* <<<DD_GUILC001_API_5>>> */
/*
 *  This routine read multiple bytes from display controller using SPI bus,
 *  with A0 = 1.
 *
 */
void LCD_X_Serial_M8_Read01(uint8_t *Data, int NumItems)
{
  IO004_SetPin(GUILC001_IOHandle);
  for (; NumItems; NumItems--)
  {
    *Data++ = LCD_X_Read1();
  }
}

/**
 * @endcond
 */

/*CODE_BLOCK_END*/

