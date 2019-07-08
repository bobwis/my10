/*CODE_BLOCK_BEGIN[ETH004_Conf.h]*/
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
** MODIFICATION DATE : Sep 18, 2012                                           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** JJ           DAVE App Developer                                            **
********************************************************************************
 * @file   ETH004_Conf.h
 *
 * @App Version ETH004 <1.0.12>
 *
 * @brief  Configuration file generated based on UI settings 
 *         of ETH004 App
 *
 */ 
 
 #ifndef ETH004_H_
 #define ETH004_H_
 
 #define NO_SYS                         1
 #define LWIP_NETCONN                   0
 #define LWIP_SOCKET                    0
     
 #ifndef LWIP_DHCP
 #define LWIP_DHCP                      0
 #endif
 #ifndef MEM_SIZE
 #define MEM_SIZE                       16384
 #endif

 #ifndef IP_DEFAULT_TTL
 #define IP_DEFAULT_TTL                 255
 #endif

 #ifndef LWIP_ICMP
 #define LWIP_ICMP                      1
 #endif
   
 #ifndef LWIP_BROADCAST_PING
 #define LWIP_BROADCAST_PING            1
 #endif
 
 #ifndef LWIP_MULTICAST_PING	
 #define LWIP_MULTICAST_PING            1
 #endif
  
 #ifndef LWIP_UDP
 #define LWIP_UDP                       1
 #endif
  
 #ifndef LWIP_TCP
 #define LWIP_TCP                       1
 #endif
 
 #ifndef LWIP_DNS
 #define LWIP_DNS                       1
 #endif
 
 #ifndef DNS_TABLE_SIZE
 #define DNS_TABLE_SIZE                 4
 #endif

 #ifndef DNS_MAX_SERVERS
 #define DNS_MAX_SERVERS                2
 #endif

 #ifndef DNS_SERVER_ADDRESS             
 #define DNS_SERVER_ADDRESS             inet_addr("208.67.222.222") 
 #endif 

 #ifndef LWIP_NETIF_HOSTNAME
 #define LWIP_NETIF_HOSTNAME            0
 #endif

 #ifndef LWIP_NETIF_STATUS_CALLBACK
 #define LWIP_NETIF_STATUS_CALLBACK     0
 #endif

 #ifndef LWIP_NETIF_LINK_CALLBACK
 #define LWIP_NETIF_LINK_CALLBACK       0
 #endif

 #ifndef LWIP_IGMP
 #define LWIP_IGMP                      1 
 #endif
 
 #ifndef LWIP_CHECKSUM_BY_HARDWARE
 #define LWIP_CHECKSUM_BY_HARDWARE      1   
 #endif 
  
 /* For Enabling SNMP by SNMP-APP*/
 #ifndef LWIP_SNMP
 #define LWIP_SNMP                     0 
 #endif
 
 /*For Enabling PPP by PPP-APP*/ 
 #ifndef PPP_SUPPORT
 #define PPP_SUPPORT                   0
 #endif
 
 /*For Enabling PPP over Ethernet Support by PPP-APP*/
 #ifndef PPPOE_SUPPORT
 #define PPPOE_SUPPORT                 0
 #endif
 
 #endif /* ETH004_H_ */  
/*CODE_BLOCK_END*/



