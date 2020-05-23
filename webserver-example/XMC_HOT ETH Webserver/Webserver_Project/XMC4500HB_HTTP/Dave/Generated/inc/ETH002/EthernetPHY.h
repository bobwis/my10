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
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : DAVE App Developer                                                **
**                                                                            **
** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Nov 12, 2012                                          **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** RS          DAVE App Developer                                             **
********************************************************************************
 * @file   EthernetPHY.h
 *
 * @App Version ETH002 <1.0.12>
 *
 * @brief  Header file of Ethernet PHY App. 
 *
 */ 

#ifndef ETH_PHY_H_
#define ETH_PHY_H_

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
#include <DAVE3.h>
/**
 * @addtogroup EthernetPHY_publicparam
 * @{
 */


/**
 * This is Duplex mode (Half or Full).
 */
enum Mii_Duplex_Mode
{
  /** Half Duplex Mode */
  HALFDUPLEX = 1,
  /** Full Duplex Mode */
  FULLDUPLEX = 2,
};


/**
 * This is Link speed.
 */
enum Mii_Link_Speed
{
  /** 10 Mbps Speed */
  SPEED10     = 1,
  /** 100 Mbps Speed */
  SPEED100    = 2,
};

/**
 * Error code enumeration for Ethernet PHY
 */
enum PHY_ERROR
{
  /**
   * PHY Initialization failed
   */
  /**
   * @cond INTERNAL_DOCS
   * @param MODULENAME ETH002
   * @endcond
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING1 PHY_INIT_ERROR
   * @param STRCODESTRING1 PHY Initialization failed
   * @endcond
   */
   PHY_INIT_ERROR = 1,
  /**
   * The Eth PHY register read fail.
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING2 PHY_READ_ERROR
   * @param STRCODESTRING2 PHY register read fail
   * @endcond
   */
   PHY_READ_ERROR,
  /**
   * The Eth PHY register write fail.
   */  
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING3 PHY_WRITE_ERROR
   * @param STRCODESTRING3 PHY register write fail
   * @endcond
   */
   PHY_WRITE_ERROR,
  /**
   * PHY RESET FAIL
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING4 PHY_RESET_ERROR
   * @param STRCODESTRING4 PHY reset fail
   * @endcond
   */
   PHY_RESET_ERROR,
  /**
   * Error disabling PHY interrupts
   */  
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING5 PHY_DISABLE_INTR_ERROR
   * @param STRCODESTRING5 Error disabling PHY interrupts
   * @endcond
   */
   PHY_DISABLE_INTR_ERROR,
  /**
   * Error setting Duplex Mode
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING6 PHY_MODE_SET_ERROR
   * @param STRCODESTRING6 Error setting Duplex Mode
   * @endcond
   */
   PHY_MODE_SET_ERROR,
  /**
   * Error setting PHY Speed
   */  
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING7 PHY_SPEED_SET_ERROR
   * @param STRCODESTRING7 Error setting PHY Speed
   * @endcond
   */
   PHY_SPEED_SET_ERROR,
  /**
   * PHY not responding - Busy bit did not get cleared
   */  
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING8 PHY_BUSY_BIT_NOT_CLEARED
   * @param STRCODESTRING8 PHY Busy bit not cleared
   * @endcond
   */
   PHY_BUSY_BIT_NOT_CLEARED,
  /**
   * PHY Auto Negotiation complete
   */  
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING9 PHY_AUTO_NEGO_COMPLETE
   * @param STRCODESTRING9 PHY Auto Negotiation complete
   * @endcond
   */
   PHY_AUTO_NEGO_COMPLETE,
  /**
   * PHY Link is UP
   */  
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING10 PHY_LINK_UP
   * @param STRCODESTRING10 PHY Link is UP
   * @endcond
   */
   PHY_LINK_UP,
  /**
   * PHY Link is down
   */  
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING11 PHY_LINK_DOWN
   * @param STRCODESTRING11 PHY Link is down
   * @endcond
   */
   PHY_LINK_DOWN,
  /**
   * PHY Initialization successful
   */  
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING12 PHY_INIT_SUCCSS
   * @param STRCODESTRING12 PHY Initialization successful
   * @endcond
   */
   PHY_INIT_SUCCSS,
  /**
   * Debuglog Function Entry
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING13 SPI001_FUNCTION_ENTRY
   * @param STRCODESTRING13 Entered function \%s
   * @endcond
   */
   ETH002_FUNCTION_ENTRY,
  /**
   * Debuglog Function Exit
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING14 ETH002_FUNCTION_EXIT
   * @param STRCODESTRING14 Entered function \%s
   * @endcond
   */
   ETH002_FUNCTION_EXIT
};

/*GmacGmiiAddr             = 0x0010,    GMII address Register(ext. Phy) Layout          */
enum GmacGmiiAddrReg      
{
  GmiiDevMask              = 0x0000F800,     /* (PA)GMII device address                 15:11     RW         0x00    */
  GmiiDevShift             = 11,

  GmiiRegMask              = 0x000007C0,     /* (GR)GMII register in selected Phy       10:6      RW         0x00    */
  GmiiRegShift             = 6,
  
  GmiiCsrClkMask	   = 0x0000003C,     /*CSR Clock bit Mask			 5:2			     */
  GmiiCsrClk5              = 0x00000014,     /* (CR)CSR Clock Range     250-300 MHz      5:2      RW         000     */
  GmiiCsrClk4              = 0x00000010,     /*                         150-250 MHz                                  */
  GmiiCsrClk3              = 0x0000000C,     /*                         35-60 MHz                                    */
  GmiiCsrClk2              = 0x00000008,     /*                         20-35 MHz                                    */
  GmiiCsrClk1              = 0x00000004,     /*                         100-150 MHz                                  */
  GmiiCsrClk0              = 0x00000000,     /*                         60-100 MHz                                   */

  GmiiWrite                = 0x00000002,     /* (GW)Write to register                      1      RW                 */
  GmiiRead                 = 0x00000000,     /* Read from register                                            0      */

  GmiiBusy                 = 0x00000001,     /* (GB)GMII interface is busy                 0      RW          0      */
};

typedef void (*PHYTimerCallbackType)(u32 count);
 
  
/**
 * National PHY DP83848C
 */ 
#define PHY_National_DP83848C 
#define PHY_BASE_ADDRESS 0x1
#define PHY_ID1_REGISTER 0x2000

 



/**
 * @}
 */

/**
 * @addtogroup EthernetPHY_apidoc
 * @{
 */


/**
 * @brief     Initializes Ethernet PHY
 * Syntax : status_t  PHY_InitializeDevice (void)
 *
 * Service ID:  0x1
 *
 * <b>Sync/Async:  Synchronous </b>
 *
 * <b>Reentrant:  No </b> <BR>
 *
 * @return    DAVEApp_SUCCESS on success error code otherwise.
 *
 */
 /**
* @code
*  #include "DAVE3.h"
*
*  int main(void)
* {
*
*       status_t Status = ETH_OPEN_ERROR;
* 	    Status = PHY_InitializeDevice();
*
* 	      if (Status != DAVEApp_SUCCESS)
* 	      {
* 	        DBG002_ERROR(APP_GID, Status, 0, NULL);
*
* 	      }
*
*   }
* @endcode<BR> </p>
*/
status_t  PHY_InitializeDevice (void);

/**
 * @brief     The function returns Link status of Ethernet PHY
 * Syntax :   bool PHY_IsLinkUP(void)
 *
 * Service ID:  0x2
 *
 * <b>Sync/Async:  Synchronous </b>
 *
 * <b>Reentrant:  Yes </b> <BR>
 *
 * @return    true if Link is up false otherwise.
 *
 */
 /**
* @code
*  #include "DAVE3.h"
*  int main(void)
* {
*	if( PHY_IsLinkUP() == FALSE)
*    {
*    }
* }
* @endcode<BR> </p>
*/
BOOLType PHY_IsLinkUP (void);

/**
 * @}
 */

#endif /* ETH_PHY_H_ */



