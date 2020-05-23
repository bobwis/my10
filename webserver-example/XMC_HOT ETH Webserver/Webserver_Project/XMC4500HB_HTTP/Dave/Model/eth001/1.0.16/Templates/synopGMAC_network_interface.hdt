/* ===================================================================================
 * Copyright (c) <2009> Synopsys, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software annotated with this license and associated documentation files 
 * (the "Software"), to deal in the Software without restriction, including without 
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * =================================================================================== */
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
** MODIFICATION DATE : Dec 29, 2011                                           **
**                                                                            **
*******************************************************************************/
 
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** JRP          DAVE App Developer                                            **
*******************************************************************************/
/** \file
 * Header file for the nework dependent functionality.
 * The function prototype listed here are linux dependent.
 *   
 * \internal
 * ---------------------------REVISION HISTORY-------------------
 * Synopsys 			01/Aug/2007		Created
 */
 
 
 
#ifndef SYNOP_GMAC_NETWORK_INTERFACE_H
#define SYNOP_GMAC_NETWORK_INTERFACE_H 1

#include <DAVE3.h>

/**
 * @cond INTERNAL_DOCS
 */

#define NET_IF_TIMEOUT (10*HZ)
#define CHECK_TIME (HZ)

#define MAC_ADDR_LEN 6

#define ETH_PACKET_SIZE MAX_MTU_SIZE + ETHERNET_HEADER + ETHERNET_CRC + 2

#ifdef LINUX_CODE
err_t synopGMAC_init_network_interface(struct netif *netdev);
err_t synopGMAC_init_hw(struct netif *netdev);

void  synopGMAC_exit_network_interface(void);

s32 synopGMAC_linux_open(struct net_device *);
s32 synopGMAC_linux_close(struct net_device *);
s32 synopGMAC_xmit_frames(struct sk_buff *, struct net_device *);
struct net_device_stats * synopGMAC_linux_get_stats(struct net_device *);

#endif

void synopGMAC_powerup_mac(synopGMACdevice *gmacdev);
void synop_handle_transmit_over(synopGMACdevice * synopGMACdev);
s32 synopGMAC_setup_tx_desc_queue(synopGMACdevice *gmacdev, u32 no_of_desc, u32 desc_mode);
s32 synopGMAC_setup_rx_desc_queue(synopGMACdevice * gmacdev, u32 no_of_desc, u32 desc_mode);
void synopGMAC_cable_unplug_function(void *synopGMACdev);
void synopGMAC_giveup_rx_desc_queue(synopGMACdevice * gmacdev, u32 desc_mode);
void synopGMAC_giveup_tx_desc_queue(synopGMACdevice *gmacdev, u32 desc_mode);

void synopGMAC_linux_set_multicast_list(synopGMACdevice * synopGMACdev);
s32 synopGMAC_set_mac_address(synopGMACdevice *synopGMACdev, void *);
s32 synopGMAC_change_mtu(synopGMACdevice * synopGMACdev, s32);
void synopGMAC_linux_tx_timeout(synopGMACdevice * synopGMACdev);

/**
 * @endcond
 */
 
#endif /* End of file */


