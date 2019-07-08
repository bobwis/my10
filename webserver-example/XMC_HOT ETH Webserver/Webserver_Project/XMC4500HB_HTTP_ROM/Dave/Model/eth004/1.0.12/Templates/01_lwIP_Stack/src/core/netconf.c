/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.

 * =========================================================================== *
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
 * ========================================================================== *
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon <Microcontroller name, step>                           **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [yes/Yes]: Ys                                       **
**                                                                            **
** MODIFICATION DATE : Dec 12, 2012                                           **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** JN         App Developer                                                   **
*******************************************************************************/

/**
 *
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
#include "lwip/memp.h"
#include "lwip/dns.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "netif/etharp.h"
#include "lwip/dhcp.h"
#include "lwip/ip_addr.h"
#include "ethernetif.h"
#include "netconf.h"
#include "lwip/netif.h"
#include "lwip/init.h"
#include "lwip/tcpip.h"
#include "lwip/autoip.h"
#include "lwip/igmp.h"
//todo:sagar
#include "lwip/ip_frag.h"
/** Include for C Standard types */
#include <DAVE3.h>


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


void LwIP_Periodic_Timer_CallBack(void* Temp);
void PHY_RegisterTimerCallback(PHYTimerCallbackType Callback);
void synopGMAC_RegisterPeriodicTimerCallback(SynopGMACPeriodicTimerCallbackType Callback);
void synopGMAC_RegisterOneShotTimerCallback(SynopGMACTimerCallbackType Callback);
void synopGMAC_RegisterDeleteTimerCallback(SynopGMACDeletePeriodicTimerType Callback);
#if ENABLE_HTTP
void httpd_init(void) ;
#endif
/**
 * @cond INTERNAL_DOCS
 */
/**
 * @file netconf.c
 *
 * @brief  This file contains public APIs for lwIP stack Init/Deinit APIs.
 *
 */

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
extern handle_t  lwIPStackSem;
handle_t Eth_TimerHandle;
struct netif netif;
uint32_t lwip250mStimer; 												 
volatile bool EthernetTimer = TRUE;
void *LinkCallback = NULL;
void *StatusCallback = NULL;

__IO uint32_t TCPTimer = 0;
__IO uint32_t ARPTimer = 0;

#if LWIP_DHCP
__IO uint32_t DHCPfineTimer = 0;
__IO uint32_t DHCPcoarseTimer = 0;
#endif

/**
 * @addtogroup lwIP_apidoc
 * @{
 */

/**
 * @brief
 * The function initializes the lwIP stack
 *
 * @param [in] None
 *
 * @return DAVEApp_SUCCESS on success error code otherwise

*/

void Periodic_Timer_CallBack()
{
  LwIP_Periodic_Timer_CallBack(NULL);
}

void  Ethernetwait_Timer_CallBack(void* Temp)
{
    EthernetTimer = FALSE;
}

void OneShotTimerCallback(u32 count)
{
#if !NO_SYS
  RTOS001_TaskDelay(count);
#else
  handle_t TimerId;
  status_t Status = 10;
    EthernetTimer = TRUE;
  TimerId = SYSTM001_CreateTimer(count,SYSTM001_ONE_SHOT, Ethernetwait_Timer_CallBack,NULL);
      if(TimerId != 0)
      {
        Status = SYSTM001_StartTimer(TimerId);
        if(Status == DAVEApp_SUCCESS)
        {
          while(EthernetTimer);
        }
				SYSTM001_DeleteTimer(TimerId);
      }
 #endif
    return ;
}

void PeriodicTimerCallback(u32 count, synopGMACdevice *synopGMACdev)
{
#if !NO_SYS
   Eth_TimerHandle = RTOS001_CreateTimer(count, PERIODIC,
                                         synopGMAC_cable_unplug_function,
                                         synopGMACdev); 
    /* Start the Timer */
   RTOS001_StartTimer(Eth_TimerHandle);
#endif
    return ;
}

void DeletePeriodicTimer()
{
#if !NO_SYS
  RTOS001_DeleteTimer(Eth_TimerHandle);
#else
  SYSTM001_DeleteTimer(Eth_TimerHandle);
#endif

}
//void lwipProcessTimers(void);

status_t lwIPStack_init(void)
{
  /* <<<DD_LWIP_PORT_1_1>>> */
  handle_t TimerId;
  struct ip_addr ipaddr;
  struct ip_addr netmask;
  struct ip_addr gw;
#if LWIP_DHCP
  ipaddr.addr = 0;
  netmask.addr = 0;
  gw.addr = 0;
#else
  /* <<<DD_LWIP_PORT_1_5>>> */
  /* Set the IP address here. The IP address should be set by GUI */
	extern int IPpos1;
	extern int IPpos2;
	extern int IPpos3;
	extern int IPpos4;

	extern int Netpos1;
	extern int Netpos2;
	extern int Netpos3;
	extern int Netpos4;
	
	extern int GWpos1;
	extern int GWpos2;
	extern int GWpos3;
	extern int GWpos4;

	IP4_ADDR(&ipaddr, IPpos1, IPpos2, IPpos3, IPpos4);
    IP4_ADDR(&netmask, Netpos1, Netpos2, Netpos3, Netpos4);
    IP4_ADDR(&gw, GWpos1, GWpos2, GWpos3, GWpos4);
#endif
	
	PHY_RegisterTimerCallback(OneShotTimerCallback);
	synopGMAC_RegisterOneShotTimerCallback(OneShotTimerCallback);	
	synopGMAC_RegisterPeriodicTimerCallback(PeriodicTimerCallback);	
	synopGMAC_RegisterDeleteTimerCallback(DeletePeriodicTimer);

#if NO_SYS
  /* Initialize the LwIP stack */
  /* <<<DD_LWIP_PORT_1_2>>> */
//  SysTick_Config(50000);
  lwip_init();
#if ENABLE_HTTP
  httpd_init() ;
#endif
#else
  /* <<<DD_LWIP_PORT_1_3>>> */
  /* Call this function to start a new TCP/IP thread */
  tcpip_init(NULL, NULL);
#endif

  /* Add a new network interface */
  netif_add(&netif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init,
      &ethernet_input);

  /* Registers the default network interface.*/
  netif_set_default(&netif);

#if LWIP_DHCP
  /* <<<DD_LWIP_PORT_1_4>>> */
  /* Creates a new DHCP client for this interface on the first call.
  Note: you must call dhcp_fine_tmr() and dhcp_coarse_tmr() at
  the predefined regular intervals after starting the client.
  You can peek in the netif->dhcp struct for the actual DHCP status.*/
  dhcp_start(&netif);
#endif

#if LWIP_NETIF_LINK_CALLBACK
  netif_set_link_callback(&netif, LinkCallback);
#endif

#if LWIP_NETIF_STATUS_CALLBACK
	netif_set_status_callback(&netif, StatusCallback);
#endif

  /* When the netif is fully configured this function must be called.*/
  netif_set_up(&netif);

  TimerId = SYSTM001_CreateTimer(250, SYSTM001_PERIODIC, Periodic_Timer_CallBack, NULL);
  if(TimerId != 0)
  {
  	  SYSTM001_StartTimer(TimerId);
  }

  /* Wait till TCP Main thread is ready */
  /* sys_sem_wait(TCPMainThreadSem);*/
#if !NO_SYS
  sys_sem_signal(lwIPStackSem);

  sys_thread_stop(0);
#endif
  /* TODO: Add code for initialization of TCP applications */
  return DAVEApp_SUCCESS;
}

#if LWIP_NETIF_LINK_CALLBACK
void Register_NetLink_Callback(void (* link_callback)(struct netif *netif ))
{
	LinkCallback = link_callback;
}
#endif

#if LWIP_NETIF_STATUS_CALLBACK
void Register_NetStatus_Callback(void (* status_callback)(struct netif *netif ))
{
	StatusCallback = status_callback;
}
#endif

// To be called by user at an interval of 250 microseconds
void LwIP_Periodic_Timer_CallBack(void* Temp)	
{
    lwip250mStimer += 250;
#if LWIP_TCP
    if( (lwip250mStimer % TCP_TMR_INTERVAL) == 0 ) { tcp_tmr(); }
#endif
    if( (lwip250mStimer % ARP_TMR_INTERVAL) == 0 ) { etharp_tmr(); }
#if IP_REASSEMBLY
    if( (lwip250mStimer % IP_TMR_INTERVAL) == 0 ) { ip_reass_tmr(); }
#endif
#if LWIP_AUTOIP
    if( (lwip250mStimer % AUTOIP_TMR_INTERVAL ) == 0 ) { autoip_tmr(); }
#endif
#if LWIP_IGMP
    if( (lwip250mStimer % IGMP_TMR_INTERVAL ) == 0 ) { igmp_tmr(); } 
#endif
#if LWIP_DHCP
    if( (lwip250mStimer % DHCP_FINE_TIMER_MSECS ) == 0 ) { dhcp_fine_tmr(); }
    if( (lwip250mStimer % (DHCP_COARSE_TIMER_SECS*1000) ) == 0 ) { dhcp_coarse_tmr(); }
#endif
#if LWIP_DNS
    if( (lwip250mStimer % DNS_TMR_INTERVAL) == 0 ) { dns_tmr(); }
#endif

}

/**
 * @brief
 * The function de-initializes the lwIP stack
 *
 * @param [in] None
 *
 * @return DAVEApp_SUCCESS on success error code otherwise
 */
status_t lwIPStack_UnInit(void)
{
  status_t Status = lwIP_UNINIT_ERROR;
  /* <<<DD_LWIP_PORT_16_1>>> */
#if !NO_SYS
  /* Call this function to start a new TCP/IP thread */
  //todo: sagar Added
    sys_thread_stop(0);

#endif

  /* Disconnect netif */
  // netif_set_down(&netif); // added to test link/status callback when set down is called
  /* Remove the network interface */
  netif_remove(&netif);

  /* Close Ethernet Interface */
  Status = Eth_CloseNetworkInterface();

  if (Status != DAVEApp_SUCCESS)
  {
    DBG002_WARNING(GID_LWIP, lwIP_UNINIT_ERROR, 0, NULL);
  }
  /* Exit from the Ethernet Interface */
  Eth_ExitNetworkInterface();

  return DAVEApp_SUCCESS;
}
/**
 * @}
 */
/**
 * @cond
 */
