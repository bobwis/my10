/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2009  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
*********************************************************************/
/* =========================================================================== * 
 * Copyright (c) 2011, Infineon Technologies AG                                *
 * All rights reserved.                                                        * 
 *                                                                             *
 * Redistribution and use in source and binary forms, with or without          *
 * modification, are permitted provided that the following conditions are met: *
 * Redistributions of source code must retain the above copyright notice, this *
 * list of conditions and the following disclaimer. Redistributions in binary  *
 * form must reproduce the above copyright notice, this list of conditions and *
 * the following disclaimer in the documentation and/or other materials        *
 * provided with the distribution. Neither the name of the copyright holders   * 
 * nor the names of its contributors may be used to endorse or promote         *
 * products derived from this software without specific prior written          * 
 * permission.                                                                 *
 *                                                                             *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       *
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      *
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR           *
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       *
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         * 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; *
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    *
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     *
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF      *
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                  *
 * To improve the quality of the software, users are encouraged to share       *
 * modifications, enhancements or bug fixes with                               *
 * Infineon Technologies AG (dave@infineon.com).                               *
 *                                                                             *
 * ========================================================================== */
/*
----------------------------------------------------------------------
File        : LCDConf.c
Purpose     : Sample display controller configuration

              Controller:     Syncoam SEPS525
              Display driver: GUIDRV_FlexColor
              Operation mode: 16bpp, 8 bit interface

---------------------------END-OF-HEADER------------------------------
*/

#include "GUI.h"

#ifndef WIN32
  #include "../../inc/GUILC001/GUILC001.h"
#endif
#include "GUIDRV_FlexColor.h"

/*********************************************************************
*
*       Layer configuration
*
**********************************************************************
*/
//
// Physical display size
//
#define XSIZE_PHYS 160
#define YSIZE_PHYS 128

//
// Color conversion
//
#define COLOR_CONVERSION GUICC_M565

//
// Display driver
//
#define DISPLAY_DRIVER GUIDRV_FLEXCOLOR

//
// Orientation
//
//#define DISPLAY_ORIENTATION (GUI_MIRROR_X | GUI_SWAP_XY)


/*********************************************************************
*
*       Configuration checking
*
**********************************************************************
*/
#ifndef   VXSIZE_PHYS
  #define VXSIZE_PHYS XSIZE_PHYS
#endif
#ifndef   VYSIZE_PHYS
  #define VYSIZE_PHYS YSIZE_PHYS
#endif
#ifndef   XSIZE_PHYS
  #error Physical X size of display is not defined!
#endif
#ifndef   YSIZE_PHYS
  #error Physical Y size of display is not defined!
#endif
#ifndef   COLOR_CONVERSION
  #error Color conversion not defined!
#endif
#ifndef   DISPLAY_DRIVER
  #error No display driver defined!
#endif
#ifndef   DISPLAY_ORIENTATION
  #define DISPLAY_ORIENTATION 0
#endif

/*********************************************************************
*
*       Display controller register definitions
*
**********************************************************************
*/
#define REG_OSC_CTL                 0x02
#define REG_CLOCK_DIV               0x03
#define REG_REDUCE_CURRENT          0x04
#define REG_DISP_ON_OFF             0x06
#define REG_PRECHARGE_TIME_R        0x08
#define REG_PRECHARGE_TIME_G        0x09
#define REG_PRECHARGE_TIME_B        0x0A
#define REG_PRECHARGE_Current_R     0x0B
#define REG_PRECHARGE_Current_G     0x0C
#define REG_PRECHARGE_Current_B     0x0D
#define REG_DRIVING_CURRENT_R       0x10
#define REG_DRIVING_CURRENT_G       0x11
#define REG_DRIVING_CURRENT_B       0x12
#define REG_DISPLAY_MODE_SET        0x13
#define REG_RGB_IF                  0x14
#define REG_MEMORY_WRITE_MODE       0x16
#define REG_MX1_ADDR                0x17
#define REG_MX2_ADDR                0x18
#define REG_MY1_ADDR                0x19
#define REG_MY2_ADDR                0x1A
#define REG_MEMORY_ACCESS_POINTER_X 0x20
#define REG_MEMORY_ACCESS_POINTER_Y 0x21
#define REG_DDRAM_DATA_ACCESS_PORT  0x22
#define REG_DUTY                    0x28
#define REG_DSL                     0x29
#define REG_D1_DDRAM_FAC            0x2E
#define REG_D1_DDRAM_FAR            0x2F
#define REG_D2_DDRAM_SAC            0x31
#define REG_D2_DDRAM_SAR            0x32
#define REG_SCR1_FX1                0x33
#define REG_SCR1_FX2                0x34
#define REG_SCR1_FY1                0x35
#define REG_SCR1_FY2                0x36
#define REG_SCR2_SX1                0x37
#define REG_SCR2_SX2                0x38
#define REG_SCR2_SY1                0x39
#define REG_SCR2_SY2                0x3A
#define REG_SCREEN_SAVER_CONTEROL   0x3B
#define REG_SCREEN_SAVER_MODE       0x3D
#define REG_SS_SCR1_FU              0x3E
#define REG_SS_SCR1_MXY             0x3F
#define REG_SS_SCR2_FU              0x40
#define REG_SS_SCR2_MXY             0x41
#define REG_SS_SCR2_SX1             0x47
#define REG_SS_SCR2_SX2             0x48
#define REG_SS_SCR2_SY1             0x49
#define REG_SS_SCR2_SY2             0x4A
#define REG_IREF                    0x80


/*********************************************************************
*
*       OLED_SPI_WriteCommand
*/
#ifndef WIN32
static void OLED_SPI_WriteCommand(U8 Reg, U8 Para) {
  LCD_X_Serial_8_Write00(Reg);
  LCD_X_Serial_8_Write01(Para);
}
#endif

/*********************************************************************
*
*       OLED_InitController
*
* Purpose:
*   Initializes the display controller
*/
static void OLED_SPI_InitController(void) {
  #ifndef WIN32
//  GUI_X_Delay(10);
  LCD_X_Serial_Init();
  OLED_SPI_WriteCommand(REG_DISP_ON_OFF, 0x00);
  OLED_SPI_WriteCommand(5, 0x00);
  OLED_SPI_WriteCommand(REG_REDUCE_CURRENT, 0x03);
  //DelayMS(10);
  OLED_SPI_WriteCommand(REG_REDUCE_CURRENT, 0x00);          // Reg:04h Action: Normal current and PS OFF
  //DelayMS(10);
  OLED_SPI_WriteCommand(REG_SCREEN_SAVER_CONTEROL, 0x00);   // Reg:3Bh Action: Screen Saver OFF
  OLED_SPI_WriteCommand(REG_OSC_CTL, 0x01);                 // Reg:02h Action: Export1 internal clock/OSC with external resister/Internal OSC ON
  OLED_SPI_WriteCommand(REG_CLOCK_DIV, 0x90);               // Reg:03h Action: FR=120Hz DIV=1
  OLED_SPI_WriteCommand(REG_IREF, 0x00);                    // Reg:80h Action: PDAC OFF, DDAC OFF/Reference Volt.control with external resister
  OLED_SPI_WriteCommand(REG_PRECHARGE_TIME_R, 0x01);        // Reg:08h Action: set color R precharge time
  OLED_SPI_WriteCommand(REG_PRECHARGE_TIME_G, 0x01);        // Reg:09h Action: set color G precharge time
  OLED_SPI_WriteCommand(REG_PRECHARGE_TIME_B, 0x01);        // Reg:0Ah Action: set color B precharge tiem
  OLED_SPI_WriteCommand(REG_PRECHARGE_Current_R, 0x0a);     // Reg:0Bh Action: set color R precharge current
  OLED_SPI_WriteCommand(REG_PRECHARGE_Current_G, 0x0a);     // Reg:0Ch Action: set color G precharge current
  OLED_SPI_WriteCommand(REG_PRECHARGE_Current_B, 0x0a);     // Reg:0Dh Action: set color B precharge current
  OLED_SPI_WriteCommand(REG_DRIVING_CURRENT_R, 0x46);       // Reg:10h Action: set color R dot driving current
  OLED_SPI_WriteCommand(REG_DRIVING_CURRENT_G, 0x38);       // Reg:11h Action: set color G dot driving current
  OLED_SPI_WriteCommand(REG_DRIVING_CURRENT_B, 0x3A);       // Reg:12h Action: set color B dot driving current
  OLED_SPI_WriteCommand(REG_DISPLAY_MODE_SET, 0x00);        // Reg:13h Action: Col D0 to D159/col normal display
  OLED_SPI_WriteCommand(REG_RGB_IF, 0x31);                  // Reg:14h Action: MPU mode
  OLED_SPI_WriteCommand(15, 0x00);
  OLED_SPI_WriteCommand(REG_MEMORY_WRITE_MODE, 0x66);       // Reg:16h Action: 8bits dual transfer, 65K support, TRI=0: 16 Bit Data Write
  OLED_SPI_WriteCommand(REG_MX1_ADDR, 0x00);                // Reg:17h Action: Memory addr.X start
  OLED_SPI_WriteCommand(REG_MX2_ADDR, 0x9f);                // Reg:18h Action: Memory addr.X end
  OLED_SPI_WriteCommand(REG_MY1_ADDR, 0x00);                // Reg:18h Action: Memory addr.Y start
  OLED_SPI_WriteCommand(REG_MY2_ADDR, 0x7f);                // Reg:1Ah Action: Memory addr.Y end
  OLED_SPI_WriteCommand(REG_MEMORY_ACCESS_POINTER_X, 0x00); // Reg:20h Action: Memory X start addr.
  OLED_SPI_WriteCommand(REG_MEMORY_ACCESS_POINTER_Y, 0x00); // Reg:21h Action: Memory Y start addr.
  OLED_SPI_WriteCommand(REG_DUTY, 0x7f);                    // Reg:28h Action: Display duty ratio
  OLED_SPI_WriteCommand(REG_DSL, 0x00);                     // Reg:29h Action: Display start line
  OLED_SPI_WriteCommand(REG_D1_DDRAM_FAC, 0x00);            // Reg:2Eh Action: Display First screen X start point
  OLED_SPI_WriteCommand(REG_D1_DDRAM_FAR, 0x00);            // Reg:2Fh Action: Display First screen Y start point
  OLED_SPI_WriteCommand(REG_D2_DDRAM_SAC, 0x00);            // Reg:31h Action: Display Second screen X start point
  OLED_SPI_WriteCommand(REG_D2_DDRAM_SAR, 0x00);            // Reg:32h Action: Display Second screen Y start point
  OLED_SPI_WriteCommand(REG_SCR1_FX1, 0x00);                // Reg:33h Action: Display size X start
  OLED_SPI_WriteCommand(REG_SCR1_FX2, 0x9f);                // Reg:34h Action: Display size X end
  OLED_SPI_WriteCommand(REG_SCR1_FY1, 0x00);                // Reg:35h Action: Display size Y start
  OLED_SPI_WriteCommand(REG_SCR1_FY2, 0x7f);                // Reg:36h Action: Display size Y end
  //DelayMS(100);
  OLED_SPI_WriteCommand(REG_DISP_ON_OFF, 0x01);             // Reg:06h Action: Scan signal is high level at precharge period/Dispaly ON
  #endif
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       LCD_X_Config
*
* Purpose:
*   Called during the initialization process in order to set up the
*   display driver configuration.
*   
*/
void LCD_X_Config(void) {
  GUI_DEVICE * pDevice;
  GUI_PORT_API PortAPI = {0};
  CONFIG_FLEXCOLOR Config = {0};

  //
  // Set display driver and color conversion for 1st layer
  //
  pDevice = GUI_DEVICE_CreateAndLink(DISPLAY_DRIVER, COLOR_CONVERSION, 0, 0);
  //
  // Display size configuration
  //
  LCD_SetSizeEx (0, XSIZE_PHYS,  YSIZE_PHYS);
  LCD_SetVSizeEx(0, VXSIZE_PHYS, VYSIZE_PHYS);
  //
  // Function selection, hardware routines (PortAPI) and operation mode (bus, bpp and cache)
  //
  #ifndef WIN32
    PortAPI.pfWrite8_A0  = LCD_X_Serial_8_Write00;
    PortAPI.pfWrite8_A1  = LCD_X_Serial_8_Write01;
    PortAPI.pfWriteM8_A1 = LCD_X_Serial_M8_Write01;
    PortAPI.pfReadM8_A1  = LCD_X_Serial_M8_Read01;
#if GUILC001_MOUSE_SUPPORT
  #if GUILC001_READ_SUPPORT   
    GUIDRV_FlexColor_SetFunc(pDevice, &PortAPI, GUIDRV_FLEXCOLOR_F66718, GUIDRV_FLEXCOLOR_M16C0B8);
  #else
    GUIDRV_FlexColor_SetFunc(pDevice, &PortAPI, GUIDRV_FLEXCOLOR_F66718, GUIDRV_FLEXCOLOR_M16C1B8);
 #endif
#else
    GUIDRV_FlexColor_SetFunc(pDevice, &PortAPI, GUIDRV_FLEXCOLOR_F66718, GUIDRV_FLEXCOLOR_M16C0B8);
#endif
    //
    // Orientation
    //
    Config.Orientation  = DISPLAY_ORIENTATION;
    Config.RegEntryMode = 0x60;
    GUIDRV_FlexColor_Config(pDevice, &Config);
  #endif
}

/*********************************************************************
*
*       LCD_X_DisplayDriver
*
* Purpose:
*   This function is called by the display driver for several purposes.
*   To support the according task the routine needs to be adapted to
*   the display controller. Please note that the commands marked with
*   'optional' are not cogently required and should only be adapted if 
*   the display controller supports these features.
*
* Parameter:
*   LayerIndex - Index of layer to be configured
*   Cmd        - Please refer to the details in the switch statement below
*   pData      - Pointer to a LCD_X_DATA structure
*/
int LCD_X_DisplayDriver(unsigned LayerIndex, unsigned Cmd, void * pData) {
  int r;

  GUI_USE_PARA(LayerIndex);
  GUI_USE_PARA(pData);
  switch (Cmd) {
  //
  // Required
  //
  case LCD_X_INITCONTROLLER: {
    //
    // Called during the initialization process in order to set up the
    // display controller and put it into operation. If the display
    // controller is not initialized by any external routine this needs
    // to be adapted by the customer...
    //
    OLED_SPI_InitController();
    return 0;
  }
  default:
    r = -1;
  }
  return r;
}

/*************************** End of file ****************************/
