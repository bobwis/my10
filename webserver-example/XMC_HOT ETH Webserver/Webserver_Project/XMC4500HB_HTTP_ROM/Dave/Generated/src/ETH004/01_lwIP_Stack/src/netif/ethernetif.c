/**
 * @file
 * Ethernet Interface Skeleton
 *
 */

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
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
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
 * ==========================================================================  *
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **
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
** JN          App Developer                                                  **
*******************************************************************************/
/*
 * This file is a skeleton for developing Ethernet network interface
 * drivers for lwIP. Add code to the low_level functions and do a
 * search-and-replace for the word "ethernetif" to replace it with
 * something that better describes your network interface.
 */

#include "lwip/opt.h"


#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include "lwip/sys.h"
#include <lwip/stats.h>
#include <lwip/snmp.h>
#include "netif/etharp.h"
#include "netif/ppp_oe.h"
#include "ethernetif.h"
#include "netconf.h"
#include <string.h>

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


extern struct netif netif;

/* MAC Address */
u8_t MACaddr[6];

/* Define those to better describe your network interface. */
#define IFNAME0 'e'
#define IFNAME1 'n'

/**
 * Helper struct to hold private data used to operate your ethernet interface.
 * Keeping the ethernet address of the MAC in this struct is not necessary
 * as it is already kept in the struct netif.
 * But this is only an example, anyway...
 */
struct ethernetif {
  struct eth_addr *ethaddr;
  /* Add whatever per-interface state that is needed here. */
};


/**
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void
low_level_init(struct netif *netif)
{
  /* <<<DD_LWIP_PORT_2_1>>> */
  status_t Status = DAVEApp_SUCCESS;
  Eth_IoctlParamType GetMacParams;

  GetMacParams.Address = (uint32_t) netif->hwaddr;

  /* set MAC hardware address length */
  netif->hwaddr_len = ETHARP_HWADDR_LEN;

  /* device capabilities */
  /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
  netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

  /* maximum transfer unit */
  netif->mtu = MAX_MTU_SIZE;

  /* Do whatever else is needed to initialize interface. */
  Status = Eth_InitNetworkInterface();
  if (Status != DAVEApp_SUCCESS)
  {
	  DBG002_ERROR(GID_LWIP, lwIP_INIT_ERROR, 0, NULL);
  }
  Status = Eth_OpenNetworkInterface();
  if (Status != DAVEApp_SUCCESS)
  {
    DBG002_ERROR(GID_LWIP, lwIP_INIT_ERROR, 0, NULL);
  }
  /* Get MAC hardware address */
  Status = Eth_PerformIoctl(IOCTL_GET_MAC_ADDRESS, &GetMacParams);
  if (Status != DAVEApp_SUCCESS)
  {
    DBG002_ERROR(GID_LWIP, lwIP_INIT_ERROR, 0, NULL);
  }
  return;
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet could be sent
 *         an err_t value if the packet couldn't be sent
 *
 * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
 *       strange results. You might consider waiting for space in the DMA queue
 *       to become availale since the stack doesn't retry to send a packet
 *       dropped because of memory failure (except for the TCP timers).
 */
extern status_t Eth_GetTxBuffer(uint8_t** Buffer);
static err_t
low_level_output(struct netif *netif, struct pbuf *p)
{
  /* <<<DD_LWIP_PORT_3_1>>> */
  /* struct ethernetif *ethernetif = netif->state; */
  struct pbuf *q;
  status_t Status = lwIP_INIT_ERROR;
  uint8_t* GetBuffer;
  uint8_t* Temp;
  uint32_t TxLength;
  q=p;
  TxLength = q->tot_len;

  Eth_GetTxBuffer(&GetBuffer);
  Temp = GetBuffer;
#if ETH_PAD_SIZE
  pbuf_header(p, -ETH_PAD_SIZE); /* drop the padding word */
#endif
  if(TxLength > 1500)
  {
    TxLength = 0;    
  }
  else
  {
    for(q = p; q != NULL; q = q->next)
    {
  
      /* Send the data from the pbuf to the interface, one pbuf at a
         time. The size of the data in each pbuf is kept in the ->len
         variable. */
        memcpy(Temp,q->payload,q->len);
        Temp += q->len;
    }
    Status = Eth_TransmitFrames(GetBuffer, TxLength);
    if (Status != DAVEApp_SUCCESS)
    {
      DBG002_WARNING(GID_LWIP, lwIP_INFO_MSG, sizeof("TX FAILE"), "TX FAILE");
    }
  }
#if ETH_PAD_SIZE
  pbuf_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif
  
  LINK_STATS_INC(link.xmit);

  return ERR_OK;
}

/**
 * This function should be called when a packet is ready to be read
 * from the interface. It uses the function low_level_input() that
 * should handle the actual reception of bytes from the network
 * interface. Then the type of the received packet is determined and
 * the appropriate input function is called.
 *
 * @param netif the lwip network interface structure for this ethernetif
 */
void lwip_Input(unsigned char *PacketBuffer, uint32_t PacketLength)
{
  /* <<<DD_LWIP_PORT_4_1>>> */
  struct pbuf *p, *q;
  uint32_t Length =0;
  struct eth_hdr *ethhdr;

  /* We allocate a pbuf chain of pbufs from the pool. */
  p = pbuf_alloc(PBUF_RAW, PacketLength, PBUF_POOL);

  if (p != NULL)
  {
	for (q = p; q != NULL; q = q->next)
	{
	  memcpy((u8_t*)q->payload, (u8_t*)&PacketBuffer[Length], q->len);
	  Length = Length + q->len;
	}
  }
  else
  {
	  DBG002_ERROR(GID_LWIP, lwIP_OUT_OF_MEM, 0, NULL);
	  return;
  }

  /* points to packet payload, which starts with an Ethernet header */
  ethhdr = p->payload;

  switch (htons(ethhdr->type))
  {
    /* IP or ARP packet? */
    case ETHTYPE_IP:
    case ETHTYPE_ARP:

#if PPPOE_SUPPORT
    /* PPPoE packet? */
    case ETHTYPE_PPPOEDISC:
    case ETHTYPE_PPPOE:
#endif /* PPPOE_SUPPORT */

    /* full packet send to tcpip_thread to process */
    if ((&(netif))->input(p, &netif) != ERR_OK)
    {
      LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_input: IP input error\n"));
      pbuf_free(p);
      p = NULL;
    }
    break;

    default:
    {
      pbuf_free(p);
      p = NULL;
      break;
    }
  }/* End switch */

  return;
}

/*
 * This function is used to initialize the netif structure. It initializes the
 * ethernet lld.
 */
err_t
ethernetif_init(struct netif *netif)
{
	/* <<<DD_LWIP_PORT_5_1>>> */
	  struct ethernetif *ethernetif;

	  LWIP_ASSERT("netif != NULL", (netif != NULL));

	  ethernetif = mem_malloc(sizeof(struct ethernetif));

	  if (ethernetif == NULL)
	  {
	    LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_init: out of memory\n"));
	    return ERR_MEM;
	  }

	#if LWIP_NETIF_HOSTNAME
	  /* Initialize interface hostname */
	  netif->hostname = "lwip";
	#endif /* LWIP_NETIF_HOSTNAME */

	  /*
	   * Initialize the snmp variables and counters inside the struct netif.
	   * The last argument should be replaced with your link speed, in units
	   * of bits per second.
	   */
	  //todo:to be moved to proper place
	#define LINK_SPEED_OF_YOUR_NETIF_IN_BPS 10000000
	  NETIF_INIT_SNMP(netif, snmp_ifType_ethernet_csmacd, LINK_SPEED_OF_YOUR_NETIF_IN_BPS);

	  netif->state = ethernetif;
	  netif->name[0] = IFNAME0;
	  netif->name[1] = IFNAME1;

	  /* We directly use etharp_output() here to save a function call.
	   * You can instead declare your own function an call etharp_output()
	   * from it if you have to do some checks before sending (e.g. if link
	   * is available...) */
	  netif->output = etharp_output;
	  netif->linkoutput = low_level_output;
	  ethernetif->ethaddr = (struct eth_addr *)&(netif->hwaddr[0]);

	  /* initialize the hardware */
	  low_level_init(netif);

	  return ERR_OK;
}
/*
 * This handler function is used to handle the Ethernet Packet. Here the Packet
 * is passed to the lwIP stack
 */
void Eth_Received_Data_Handler(uint32_t PacketBuffer, uint32_t PacketLength)
{
	 lwip_Input((u8*)PacketBuffer, PacketLength);

}
