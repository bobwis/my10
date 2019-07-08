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
** MODIFICATION DATE : July 27, 2012                                          **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** RS         DAVE App Developer                                              **
*******************************************************************************/
/**
 *
 */

/**
 * @file EthernetPHY_Private.h
 *
 * @brief  This file contains private data structures and enums.
 *
 */

#ifndef ETHERNETPHY_PRIVATE_H_
#define ETHERNETPHY_PRIVATE_H_

#include <DAVE3.h>

/**
 * @ingroup EthernetPHY_privateparam
 * @{
 */

/**
 * Below is Basic MII Register.
 */

enum BasicMiiRegisters
{
    /** Basic Mode Control Register */
    BASIC_MODE_CONTROL_REG           = 0x0000,

    /** Basic Mode Status Register */
    BASIC_MODE_STATUS_REG            = 0x0001,

    /** PHY Identifier Register # 1 */
    PHY_ID_REG_1          = 0x0002,

    /** PHY Identifier Register # 2 */
    PHY_ID_REG_2          = 0x0003,

    /** Auto-Negotiation Advertisement Register */
    AN_ADV_REG            = 0x0004,

    /** Link Partner Ability Register (Base Page) */
    LNK_PART_ABl_REG      = 0x0005,

    /** Auto-Negotiation Expansion Register */
    AN_EXP_REG            = 0x0006,

    /** Next Page Transmit Register */
    AN_NXT_PAGE_TX_REG    = 0x0007,

};

/**
 *  This is Control register layout. Control register is of 16 bit wide.
 */

enum Mii_GEN_CTRL
{                                /* Description       bits      */
  Mii_RESET    = 0x8000,
    Mii_SPEED_10       = 0x0000,     /* 10   Mbps     bits 6:13       */
  Mii_SPEED_100      = 0x2000,     /* 100  Mbps     bits 6:13       */
  Mii_SPEED_1000     = 0x0040,     /* 1000 Mbit/s   bits 6:13       */

  Mii_DUPLEX         = 0x0100,     /* Full Duplex mode  bit 8 */

  Mii_MANUAL_MASTER_CONFIG = 0x0800, /* Manual Master Config  bit 11  */

  Mii_LOOPBACK       = 0x4000,     /* Enable Loop back  bit 14      */
  Mii_NOLOOPBACK     = 0x0000,     /* Enable Loop back  bit 14      */

  Mii_AUTONEGO = 0x1000,
};

/**
 * The PHY Speed, Mode and Link status values
 */
enum Mii_Phy_Status
{
  Mii_PHY_STATUS_SPEED_10   = 0x0000,
  Mii_PHY_STATUS_SPEED_100    = 0x4000,
  Mii_PHY_STATUS_SPEED_1000 = 0x8000,

  Mii_PHY_STATUS_FULL_DUPLEX  = 0x2000,
  Mii_PHY_STATUS_HALF_DUPLEX  = 0x0000,

  Mii_PHY_STATUS_LINK_UP    = 0x0400,
};

/**
 * This is Status register layout. Status register is of 16 bit wide.
 */
enum Mii_GEN_STATUS
{
  Mii_AUTO_NEGO_COMPLETE = 0x0020,   /** Auto negotiation completed */
  Mii_LINK_STATUS        = 0x0004,   /** Link status */
};


#ifdef PHY_National_DP83848C
/**
 * Below is "DP83848YB PHYTER from National" Extended Register and their layouts.
 */

enum DP83848YB_ExtendedMiiRegisters
{
    /** Phy status register */
    PHY_STATUS_REG        = 0x0010,

    /** MII Interrupt Control Register */
    MII_INTERRUPT_CONTROL_REG = 0x0011,

    /** MII Interrupt Status Register */
    MII_INTERRUPT_STATUS_REG = 0x0012,

    /** False Carrier Sense Counter Register*/
    FALSE_CARRIER_SENSE_COUNTER_REG  = 0x0014,

    /** Receive Error Counter Register */
    RECV_ERR_COUNTER_REG      = 0x0015,

    /** PCS Sub-Layer Configuration and Status Register */
    PCS_SL_CONF_STATUS_REG     = 0x0016,

    /** RMII and Bypass Register */
    RMII_AND_BYPASS_REG = 0x0017,

    /** LED Direct Control Register */
    LED_DIRECT_CONTROL_REG = 0x0018,

    /** 10Base-T Status/Control Register */
    STATUS_CONTROL_REG_10BASE_T     = 0x001a,

    /** CD Test Control Register and BIST Extensions Register */
    CDCTRL1    = 0x001b,

    /** Energy Detect Control Register */
    ENERGY_DETECT_CONTROL_REG     = 0x001d,

};

/**
 * This is link status (Up or Down).
 */
enum Mii_Link_Status
{
  LINKDOWN  = 0, /** Link Up */
  LINKUP    = 1, /** Link Down */
};

/**
 * Enums to control Interrupt enable/disable
 */
enum Mii_Intr_Control
{
    Mii_INTR_ENABLE = 0x0002,
    Mii_INTR_DISABLE = 0x0000
};

/**
 * @}
 */


#endif

#endif /* ETHERNETPHY_PRIVATE_H_ */
