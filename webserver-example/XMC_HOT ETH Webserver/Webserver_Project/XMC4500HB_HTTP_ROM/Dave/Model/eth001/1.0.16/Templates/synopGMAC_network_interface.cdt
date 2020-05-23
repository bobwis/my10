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
** AUTHOR : DAVE App Developer                                                **
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
** JRP         DAVE App Developer                                             **
*******************************************************************************/

/** \file
 * This is the network dependent layer to handle network related functionality.
 * This file is tightly coupled to neworking frame work of linux 2.6.xx kernel.
 * The functionality carried out in this file should be treated as an example only
 * if the underlying operating system is not Linux. 
 * 
 * \note Many of the functions other than the device specific functions
 *  changes for operating system other than Linux 2.6.xx
 * \internal 
 *-----------------------------REVISION HISTORY-----------------------------------
 * Synopsys			01/Aug/2007				Created
 *
 * Infineon         12/Dec/2012             DBG002 related macros are used   
 */

#include <DAVE3.h>
/**
 * @cond INTERNAL_DOCS
 */

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
/**
 * @addtogoup Ethernet_privateparam
 * @ {
 */

/** Rx DMA Descriptot List */
extern DmaDesc Eth_RxDMADescList[RECEIVE_DESC_SIZE];

/** Tx DMA Descriptot List */
extern DmaDesc Eth_TxDMADescList[TRANSMIT_DESC_SIZE];

/* WIPRO: We do not need AV support in our driver */

#define APP_GID            DBG002_GID_ETH001

#ifdef AVB_SUPPORT
//#define IOCTL_AVB_SET_CONFIG SIOCDEVPRIVATE+7
//#define IOCTL_AVB_RUN_TEST   SIOCDEVPRIVATE+8
//#define IOCTL_AVB_GET_RESULT SIOCDEVPRIVATE+9

static u32 global_avb_debug_enable;
static u32 global_avb_tx_count_debug[3];

#define IOCTL_AVB_TEST     SIOCDEVPRIVATE+7
#define AVB_SET_CONFIG     0x00000001
#define AVB_CONFIG_HW      0x00000002
#define AVB_RUN_TEST       0x00000003
#define AVB_GET_RESULT     0x00000004
#define AVB_DEBUG_ENABLE   0x00000005
#define AVB_DEBUG_DISABLE  0x00000006
#define AVB_TX_FRAMES      0x00000007

static struct timer_list synopGMAC_AVB_test_timer;

#define FRAME_PATTERN_CH2   0xAAAAAAAA
#define FRAME_PATTERN_CH1   0x55555555
#define FRAME_PATTERN_CH0   0x11223344

static int frame_header_ch2[] = {
        0x73560D00, //   DST: 00:0D:56:73:D0:F3
        0x5500F3D0, //   SRC: 00:55:7B:B5:7D:F7
        0xF77DB57B,

        0x00A00081 //   Eth type: 0x8100 VID = 0x0000 CFI=0 PCP =5
                   //   AVTYPE is read from the #define and used while creating a frame 
        
};
static int frame_header_ch1[] = {
        0x73560D00, //   DST: 00:0D:56:73:D0:F3
        0x5500F3D0, //   SRC: 00:55:7B:B5:7D:F7
        0xF77DB57B,

        0x00800081  //   Eth type: 0x8100 VID = 0x0000 CFI=0 PCP =4
                    //   AVTYPE is read from the #define and used while creating a frame 
};
static int frame_header_ch0[] = { //BEST EFFORT ETHERNET HEADER
        0x73560D00, //   DST: 00:0D:56:73:D0:F3
        0x5500F3D0, //   SRC: 00:55:7B:B5:7D:F7
        0xF77DB57B,

        0x00000008  //   Eth type: 0x0800        
};

#endif

/* These are the global pointers for their respective structures */
extern synopGMACdevice	          *synopGMACdev;

#ifdef AVB_SUPPORT
extern synopGMACavbStruct         *synopGMACavb;
#endif

extern u32 GMAC_Power_down;

static __INLINE int is_valid_ether_addr(const unsigned char *MacAddr);
/**
 * @}
 */

/**
 * @addtogroup Ethernet_privatefunc
 * @{
 */

status_t synopGMAC_IsEtherAddrsValid(unsigned char* MacAddress)
{
   status_t Status = DAVEApp_SUCCESS;
   
   if(!is_valid_ether_addr((unsigned char*)MacAddress))
   {
    Status = ETH_INVALID_MAC_ADDR;
   }
   return Status;
}



/**
 * Function used to power up the GMAC.
 * @param[in] gmacdev pointer to GMAC device structure.
 *
 * \return returns void.
 */
void synopGMAC_powerup_mac (synopGMACdevice *gmacdev)
{
  GMAC_Power_down = 0;  // Let ISR know that MAC is out of power down now

  if (synopGMAC_is_magic_packet_received(gmacdev))
  {
    TR("GMAC wokeup due to Magic Pkt Received\n");
  }

  if (synopGMAC_is_wakeup_frame_received(gmacdev))
  {
    TR("GMAC wokeup due to Wakeup Frame Received\n");
  }

  /* Disable the assertion of PMT interrupt */
  synopGMAC_pmt_int_disable(gmacdev);

  /* Enable the mac and Dma rx and tx paths */
  synopGMAC_rx_enable(gmacdev);

  synopGMAC_enable_dma_rx(gmacdev);

  synopGMAC_tx_enable(gmacdev);

  synopGMAC_enable_dma_tx(gmacdev);

  return;
}

#ifdef LINUX_CODE
/**
 * Function used to power down the GMAC.
 * @param[in] pointer to GMAC device structure.
 * \return returns void.
 * \note This function is tightly coupled with IOCTL Calls.
 * \callgraph
 */
static void synopGMAC_powerdown_mac(synopGMACdevice *gmacdev)
{
  TR0("Put the GMAC to power down mode..\n");

  // Disable the Dma engines in tx path
  GMAC_Power_down = 1;  // Let ISR know that Mac is going to be in the power down mode
  synopGMAC_disable_dma_tx(gmacdev);

  plat_delay(10000);    //allow any pending transmission to complete

  // Disable the Mac for both tx and rx
  synopGMAC_tx_disable(gmacdev);
  synopGMAC_rx_disable(gmacdev);

  plat_delay(10000);     //Allow any pending buffer to be read by host

  //Disable the Dma in rx path
  synopGMAC_disable_dma_rx(gmacdev);

  //enable the power down mode
  //synopGMAC_pmt_unicast_enable(gmacdev);

  //prepare the gmac for magic packet reception and wake up frame reception
  synopGMAC_magic_packet_enable(gmacdev);
  synopGMAC_write_wakeup_frame_register(gmacdev, synopGMAC_wakeup_filter_config3);

  synopGMAC_wakeup_frame_enable(gmacdev);

  //gate the application and transmit clock inputs to the code. This is not done in this driver :).

  //enable the Mac for reception
  synopGMAC_rx_enable(gmacdev);

  //Enable the assertion of PMT interrupt
  synopGMAC_pmt_int_enable(gmacdev);

  //enter the power down mode
  synopGMAC_power_down_enable(gmacdev);

  return;
}
#endif

/**
 * Function used to detect the cable plugging and unplugging.
 * This function gets scheduled once in every second and polls
 * the PHY register for network cable plug/unplug. Once the
 * connection is back the GMAC device is configured as per
 * new Duplex mode and Speed of the connection.
 *
 * @param[in] synopGMACdev Pointer to device specific structure.
 *
 * @return void.
 *
 */
void synopGMAC_cable_unplug_function (void *synopGMACdev)
{
  /* <<<DD_ETH_PORT_9>>> */
  status_t Status = DAVEApp_SUCCESS;

  synopGMACdevice *GMACdev = (synopGMACdevice *)synopGMACdev;

  /* Check if PHY Link is up */
  if( PHY_IsLinkUP() == FALSE)
  {
    TR("No Link: \n");
    GMACdev->LinkState = 0;
    GMACdev->DuplexMode = 0;
    GMACdev->Speed = 0;
    GMACdev->LoopBackMode = 0;
  }
  else
  {
    TR("Link UP: \n");
    if(!GMACdev->LinkState)
    {
      Status = PHY_InitializeDevice();
      if (Status != DAVEApp_SUCCESS)
      {
    	  DBG002_WARNING(APP_GID, Status, 0, NULL);
      }
      synopGMAC_mac_init(GMACdev);
      synopGMAC_promisc_enable(GMACdev);
    }
  }
}


/**
  * This sets up the receive Descriptor queue in ring or chain mode.
  * This function is tightly coupled to the platform and operating system
  * Device is interested only after the descriptors are setup. Therefore this function
  * is not included in the device driver API. This function should be treated as an
  * example code to design the descriptor structures in ring mode or chain mode.
  * This function depends on the pcidev structure for allocation of consistent dma-able memory in case of linux.
  * This limitation is due to the fact that linux uses pci structure to allocate a dmable memory
  *  - Allocates the memory for the descriptors.
  *  - Initialize the Busy and Next descriptors indices to 0(Indicating first descriptor).
  *  - Initialize the Busy and Next descriptors to first descriptor address.
  *   - Initialize the last descriptor with the endof ring in case of ring mode.
  *  - Initialize the descriptors in chain mode.
  *
  * @param[in] gmacdev pointer to synopGMACdevice.
  * @param[in] no_of_desc number of descriptor expected in rx descriptor queue.
  * @param[in] desc_mode whether descriptors to be created in RING mode or CHAIN mode.
  *
  * @return 0 upon success. Error code upon failure.
  *
  * \note This function fails if allocation fails for required number of descriptors in Ring mode, but in chain mode
  *  function returns -ESYNOPGMACNOMEM in the process of descriptor chain creation. once returned from this function
  *  user should for gmacdev->RxDescCount to see how many descriptors are there in the chain. Should continue further
  *  only if the number of descriptors in the chain meets the requirements
  */
s32 synopGMAC_setup_rx_desc_queue(synopGMACdevice * gmacdev, u32 no_of_desc, u32 desc_mode)
{
  /* <<<DD_ETH_PORT_10>>> */
  s32 i;
  DmaDesc *first_desc = NULL;
  DmaDesc *second_desc = NULL;
  DmaDesc *temp_desc = NULL;
  //dma_addr_t dma_addr;

  gmacdev->RxDescCount = 0;

  if(desc_mode == RINGMODE)
  {
    gmacdev->RxDescCount = no_of_desc;
    gmacdev->RxDesc      = Eth_RxDMADescList;
    gmacdev->RxDescDma   = (dma_addr_t )Eth_RxDMADescList;

    for(i = 0; i < gmacdev->RxDescCount; i++)
    {
      synopGMAC_rx_desc_init_ring(gmacdev->RxDesc + i, i == gmacdev->RxDescCount-1);
    }
  }
  else
  {
    gmacdev->RxDesc       = Eth_RxDMADescList;
    gmacdev->RxDescDma    = (dma_addr_t)Eth_RxDMADescList;

    TR("Rx===============================================================Rx\n");

    first_desc->buffer2   = gmacdev->RxDescDma;
    first_desc->data2     = (u32) gmacdev->RxDesc;

    gmacdev->RxDescCount = 1;

    //dma_addr  =   (dma_addr_t)Eth_RxDMADescList;
    temp_desc = (DmaDesc *)Eth_RxDMADescList;

    for(i = 0; i < (no_of_desc-1); i++)
    {
      first_desc->buffer2  = (dma_addr_t) (temp_desc + i);
      first_desc->data2    = (u32)second_desc;

      second_desc->buffer2 = gmacdev->RxDescDma;
      second_desc->data2   = (u32)gmacdev->RxDesc;

      synopGMAC_rx_desc_init_chain(first_desc);
      gmacdev->RxDescCount += 1;
      first_desc = second_desc;
    }

    synopGMAC_rx_desc_init_chain(first_desc);
    TR("Rx===================================================================Rx\n");
  }

  gmacdev->RxNext = 0;
  gmacdev->RxBusy = 0;
  gmacdev->RxNextDesc = gmacdev->RxDesc;
  gmacdev->RxBusyDesc = gmacdev->RxDesc;

  gmacdev->BusyRxDesc   = 0;

  return -ESYNOPGMACNOERR;
}

/**
  * This gives up the receive Descriptor queue in ring or chain mode.
  * This function is tightly coupled to the platform and operating system
  * Once device's Dma is stopped the memory descriptor memory and the buffer memory deallocation,
  * is completely handled by the operating system, this call is kept outside the device driver Api.
  * This function should be treated as an example code to de-allocate the descriptor structures in ring mode or chain mode
  * and network buffer deallocation.
  * This function depends on the pcidev structure for dma-able memory deallocation for both descriptor memory and the
  * network buffer memory under linux.
  * The responsibility of this function is to
  *     - Free the network buffer memory if any.
  *  - Fee the memory allocated for the descriptors.
  *
  * @param[in] gmacdev pointer to synopGMACdevice.
  * @param[in] desc_mode whether descriptors to be created in RING mode or CHAIN mode.
  *
  * @return void.
  * \note No referece should be made to descriptors once this function is called. This function is invoked when the device is closed.
  */
void synopGMAC_giveup_rx_desc_queue (synopGMACdevice * gmacdev, u32 desc_mode)
{
  s32 i;

  DmaDesc *first_desc = NULL;
  //dma_addr_t first_desc_dma_addr;
  u32 status;
  dma_addr_t dma_addr1;
  dma_addr_t dma_addr2;
  u32 length1;
  u32 length2;
  u32 data1;
  u32 data2;

  if(desc_mode == RINGMODE)
  {
    for(i = 0; i < gmacdev->RxDescCount; i++)
    {
      synopGMAC_get_desc_data(gmacdev->RxDesc + i, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2);

      if((length1 != 0) && (data1 != 0))
      {
        //TR("(Ring mode) rx buffer1 %08x of size %d from %d rx descriptor is given back\n",data1, length1, i);
      }

      if((length2 != 0) && (data2 != 0))
      {
        //TR("(Ring mode) rx buffer2 %08x of size %d from %d rx descriptor is given back\n",data2, length2, i);
      }
    }
  }
  else
  {
    TR("rx-------------------------------------------------------------------rx\n");

    first_desc          = gmacdev->RxDesc;
    //first_desc_dma_addr = gmacdev->RxDescDma;

    for(i = 0; i < gmacdev->RxDescCount; i++)
    {
      synopGMAC_get_desc_data(first_desc, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2);
      //TR("%02d %08x %08x %08x %08x %08x %08x %08x\n",i,(u32)first_desc,first_desc->status,first_desc->length,first_desc->buffer1,first_desc->buffer2,first_desc->data1,first_desc->data2);

      if((length1 != 0) && (data1 != 0))
      {
        //TR("(Chain mode) rx buffer1 %08x of size %d from %d rx descriptor is given back\n",data1, length1, i);
      }

      first_desc = (DmaDesc *)data2;
      //first_desc_dma_addr = dma_addr2;
    }

    TR("rx-------------------------------------------------------------------rx\n");
  }

  gmacdev->RxDesc    = NULL;
  gmacdev->RxDescDma = 0;
  return;
}

/**
  * This sets up the transmit Descriptor queue in ring or chain mode.
  * This function is tightly coupled to the platform and operating system
  * Device is interested only after the descriptors are setup. Therefore this function
  * is not included in the device driver API. This function should be treated as an
  * example code to design the descriptor structures for ring mode or chain mode.
  * This function depends on the pcidev structure for allocation consistent dma-able memory in case of linux.
  * This limitation is due to the fact that linux uses pci structure to allocate a dmable memory
  *  - Allocates the memory for the descriptors.
  *  - Initialize the Busy and Next descriptors indices to 0(Indicating first descriptor).
  *  - Initialize the Busy and Next descriptors to first descriptor address.
  *   - Initialize the last descriptor with the endof ring in case of ring mode.
  *  - Initialize the descriptors in chain mode.
  *
  * @param[in] gmacdev pointer to synopGMACdevice.
  * @param[in] no_of_desc number of descriptor expected in tx descriptor queue.
  * @param[in] desc_mode whether descriptors to be created in RING mode or CHAIN mode.
  *
  * @return 0 upon success. Error code upon failure.
  * \note This function fails if allocation fails for required number of descriptors in Ring mode, but in chain mode
  *  function returns -ESYNOPGMACNOMEM in the process of descriptor chain creation. once returned from this function
  *  user should for gmacdev->TxDescCount to see how many descriptors are there in the chain. Should continue further
  *  only if the number of descriptors in the chain meets the requirements
  */

s32 synopGMAC_setup_tx_desc_queue(synopGMACdevice *gmacdev, u32 no_of_desc, u32 desc_mode)
{
  /* <<<DD_ETH_PORT_11>>> */
  s32 i;

  DmaDesc *first_desc = NULL;
  DmaDesc *second_desc = NULL;

  DmaDesc *temp_desc = NULL;
  //dma_addr_t dma_addr;

  gmacdev->TxDescCount = 0;

  if(desc_mode == RINGMODE)
  {
    gmacdev->TxDescCount = no_of_desc;
    gmacdev->TxDesc      = Eth_TxDMADescList;
    gmacdev->TxDescDma   = (unsigned long)Eth_TxDMADescList;

    for(i = 0; i < gmacdev->TxDescCount; i++)
    {
      synopGMAC_tx_desc_init_ring(gmacdev->TxDesc + i, i == gmacdev->TxDescCount-1);
    }
  }
  else
  {
    gmacdev->TxDesc       = Eth_TxDMADescList;
    gmacdev->TxDescDma    = (dma_addr_t)Eth_TxDMADescList;

    TR("Tx===================================================================Tx\n");

    first_desc->buffer2   = gmacdev->TxDescDma;
    first_desc->data2     = (u32)gmacdev->TxDesc;

    gmacdev->TxDescCount = 1;

    //dma_addr  = (dma_addr_t)Eth_TxDMADescList;
    temp_desc = (DmaDesc *)Eth_TxDMADescList;

    for(i = 0; i < (no_of_desc-1); i++)
    {
      first_desc->buffer2 =  (dma_addr_t) (temp_desc + i);
      first_desc->data2    = (u32)second_desc;

      second_desc->buffer2 = gmacdev->TxDescDma;
      second_desc->data2   = (u32)gmacdev->TxDesc;

      synopGMAC_tx_desc_init_chain(first_desc);

      gmacdev->TxDescCount += 1;
      first_desc = second_desc;
    }

    synopGMAC_tx_desc_init_chain(first_desc);
    TR("Tx===================================================================Tx\n");
  }

  gmacdev->TxNext = 0;
  gmacdev->TxBusy = 0;
  gmacdev->TxNextDesc = gmacdev->TxDesc;
  gmacdev->TxBusyDesc = gmacdev->TxDesc;
  gmacdev->BusyTxDesc  = 0;

  return -ESYNOPGMACNOERR;
}

/**
  * This gives up the transmit Descriptor queue in ring or chain mode.
  * This function is tightly coupled to the platform and operating system
  * Once device's Dma is stopped the memory descriptor memory and the buffer memory deallocation,
  * is completely handled by the operating system, this call is kept outside the device driver Api.
  * This function should be treated as an example code to de-allocate the descriptor structures in ring mode or chain mode
  * and network buffer deallocation.
  * The responsibility of this function is to
  *  - Free the network buffer memory if any.
  *  - Fee the memory allocated for the descriptors.
  *
  * @param[in] gmacdev pointer to synopGMACdevice.
  * @param[in] desc_mode Descriptor mode.
  *
  * @return void
  * \note No reference should be made to descriptors once this function is called. This function is invoked when the device is closed.
  */
void synopGMAC_giveup_tx_desc_queue(synopGMACdevice *gmacdev, u32 desc_mode)
{
  s32 i;

  DmaDesc *first_desc = NULL;
  //dma_addr_t first_desc_dma_addr;
  u32 status;
  dma_addr_t dma_addr1;
  dma_addr_t dma_addr2;
  u32 length1;
  u32 length2;
  u32 data1;
  u32 data2;

  if(desc_mode == RINGMODE)
  {
    for(i =0; i < gmacdev -> TxDescCount; i++)
    {
      synopGMAC_get_desc_data(gmacdev->TxDesc + i,&status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2);

      if((length1 != 0) && (data1 != 0))
      {
        //TR("(Ring mode) tx buffer1 %08x of size %d from %d rx descriptor is given back\n",data1, length1, i);
      }

      if((length2 != 0) && (data2 != 0))
      {
        //TR("(Ring mode) tx buffer2 %08x of size %d from %d rx descriptor is given back\n",data2, length2, i);
      }
    }

    //TR("Memory allocated %08x for Tx Desriptors (ring) is given back\n",(u32)gmacdev->TxDesc);
  }
  else
  {
    TR("tx-------------------------------------------------------------------tx\n");

    first_desc          = gmacdev->TxDesc;
    //first_desc_dma_addr = gmacdev->TxDescDma;

    for(i =0; i < gmacdev -> TxDescCount; i++)
    {
      synopGMAC_get_desc_data(first_desc, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2);
      // TR("%02d %08x %08x %08x %08x %08x %08x %08x\n",i,(u32)first_desc,first_desc->status,first_desc->length,first_desc->buffer1,first_desc->buffer2,first_desc->data1,first_desc->data2);

      if((length1 != 0) && (data1 != 0))
      {
        // TR("(Chain mode) tx buffer1 %08x of size %d from %d rx descriptor is given back\n",data1, length1, i);
      }

      // TR("Memory allocated %08x for Tx Descriptor (chain) at  %d is given back\n",data2,i);

      first_desc = (DmaDesc *)data2;
      //first_desc_dma_addr = dma_addr2;
    }
    TR("tx-------------------------------------------------------------------tx\n");
  }

  gmacdev->TxDesc    = NULL;
  gmacdev->TxDescDma = 0;
  return;
}

#ifdef AVB_SUPPORT
static void populate_tx_avb_data (u32 dma_index, u32 avb_frame_size, u32 * skb_data, synopGMACavbStruct * gmacavb)
{
        u32 data_count;
  u32 avtype;

        if(dma_index == 0){
           * skb_data++ = frame_header_ch0[0];
           * skb_data++ = frame_header_ch0[1];
           * skb_data++ = frame_header_ch0[2];
           * skb_data++ = frame_header_ch0[3]; //Ethernet header ends here
           for(data_count = 0; data_count < avb_frame_size;){
               * skb_data++ = FRAME_PATTERN_CH0;
               data_count += 4;// increment by 4 since we are writing one word at a time
           }
        }

        if(dma_index == 1){
           * skb_data++ = frame_header_ch1[0];
           * skb_data++ = frame_header_ch1[1];
           * skb_data++ = frame_header_ch1[2];
           * skb_data++ = frame_header_ch1[3];

     avtype = gmacavb->AvType;
     avtype = ((avtype << 8) | (avtype >> 8)) & 0x0000FFFF;
           * skb_data++ = (FRAME_PATTERN_CH1 <<16) | avtype; //AVB header ends here

           for(data_count = 0; data_count < avb_frame_size;){
               * skb_data++ = FRAME_PATTERN_CH1;
               data_count += 4;// increment by 4 since we are writing one word at a time
           }
        }
        if(dma_index == 2){
           * skb_data++ = frame_header_ch2[0];
           * skb_data++ = frame_header_ch2[1];
           * skb_data++ = frame_header_ch2[2];
           * skb_data++ = frame_header_ch2[3];

     avtype = gmacavb->AvType;
     avtype = ((avtype << 8) | (avtype >> 8)) & 0x0000FFFF;
           * skb_data++ = (FRAME_PATTERN_CH2 <<16) | avtype; //AVB header ends here

           for(data_count = 0; data_count < avb_frame_size;){
               * skb_data++ = FRAME_PATTERN_CH2;
               data_count += 4;// increment by 4 since we are writing one word at a time
           }
        }
}

static void synopGMAC_prepare_hw_for_avb_test (synopGMACNetworkAdapter *adapter)//synopGMACconfigureAvb
{
  synopGMACdevice *gmacdev;
  synopGMACdevice * gmacdev_ch[3]; // [0] for Best Effor Ethernet, [1] For DMA CH 1, [2] For DMA CH 2
  u8 ch_tx_desc_slot_no;
  u8 ch_tx_desc_slot_no_skip;

  synopGMACavbStruct    *gmacavb;
  u32 avb_frame_size,dma_index,desc_count;
  u32 status;
  u32 dma_addr1, dma_addr2;
  u32 length1, length2;
  u32 data1, data2;

  struct sk_buff *skb;

  gmacdev_ch[0] = adapter->synopGMACdev;
  gmacdev_ch[1] = adapter->synopGMACdev_ch1;
  gmacdev_ch[2] = adapter->synopGMACdev_ch2;

  gmacavb       = adapter->synopGMACavb;


  gmacdev=gmacdev_ch[0];
  synopGMACsetAvType(gmacdev,gmacavb->AvType);       //Set the AvType in Avmac register
  synopGMACsetAvPrio(gmacdev,gmacavb->PrioTagForAV); //set the Avpriority tag
  synopGMACsetAvCtrlCh(gmacdev,gmacavb->AvControlCh);//set the Av control Channel
  synopGMACsetAvPTPCh(gmacdev,gmacavb->PTPCh);       //set the PTP Channel

  //Channel 0 Specific Configuration

  synopGMACsetChPrioWts(gmacdev,gmacavb->Ch0PrioWts);
  synopGMACsetTxRxPrioPolicy(gmacdev,gmacavb->Ch0_tx_rx_prio_policy); //1=>RR 0=>Strict prioriyt
  synopGMACsetTxRxPrio(gmacdev,gmacavb->Ch0_use_tx_high_prio);        //1 => tx has high prio over rx
  synopGMACsetTxRxPrioRatio(gmacdev,gmacavb->Ch0_tx_rx_prio_ratio);   //tx-rx priority weights

  synopGMAC_TS_subsecond_init(gmacdev, 0x1E); //Because of 33MHz PCI clock
  synopGMAC_TS_digital_rollover_enable(gmacdev);
  synopGMAC_TS_enable(gmacdev);
  synopGMAC_TS_timestamp_init(gmacdev, 0x00, 0x00);

  //Channel 1 Specific Configuration
  gmacdev=gmacdev_ch[1];

  synopGMACsetChPrioWts(gmacdev,gmacavb->Ch1PrioWts);

  if(gmacavb->Ch1_EnableSlotCheck){
     synopGMACAvbEnSlot(gmacdev);
  }
  else {
     synopGMACAvbDisSlot(gmacdev);
     synopGMACAvbDisSlotInterrupt(gmacdev);
  }
  synopGMACAvbSetSlotCount(gmacdev,gmacavb->Ch1SlotCount);
  //synopGMACAvbEnSlotInterrupt(gmacdev);

  if(gmacavb->Ch1_AdvSlotInterval)
     synopGMACAvbEnAdvSlotInt(gmacdev);
  else
     synopGMACAvbDisAdvSlotInt(gmacdev);

  if(gmacavb->Ch1CrSh == 0){// when zero we need to disable creditshape algorithm
     synopGMACAvbDisableCrSh(gmacdev);
     synopGMACAvbDisableCrControl(gmacdev);
  }
  else{
        synopGMACAvbEnableCrSh(gmacdev);

  if(gmacavb->Ch1CreditControl)
    synopGMACAvbEnableCrControl(gmacdev);
  else
         synopGMACAvbDisableCrControl(gmacdev);

        synopGMACsetAvbSendSlope(gmacdev,gmacavb->Ch1SendSlope);
        synopGMACsetAvbIdleSlope(gmacdev,gmacavb->Ch1IdleSlope);
        synopGMACsetAvbHiCredit(gmacdev,gmacavb->Ch1HiCredit);
        synopGMACsetAvbLoCredit(gmacdev,gmacavb->Ch1LoCredit);
  }

  synopGMACsetTxRxPrioPolicy(gmacdev,gmacavb->Ch1_tx_rx_prio_policy); //1=>RR 0=>Strict prioriyt
  synopGMACsetTxRxPrio(gmacdev,gmacavb->Ch1_use_tx_high_prio); //1 => tx has high prio over rx
  synopGMACsetTxRxPrioRatio(gmacdev,gmacavb->Ch1_tx_rx_prio_ratio);//tx-rx priority weights

  //Channel 2 Specific Configuration
  gmacdev=gmacdev_ch[2];

  synopGMACsetChPrioWts(gmacdev,gmacavb->Ch2PrioWts);

  if(gmacavb->Ch2_EnableSlotCheck){
     synopGMACAvbEnSlot(gmacdev);
  }
  else {
     synopGMACAvbDisSlot(gmacdev);
     synopGMACAvbDisSlotInterrupt(gmacdev);
  }
  synopGMACAvbSetSlotCount(gmacdev,gmacavb->Ch2SlotCount);
  //synopGMACAvbEnSlotInterrupt(gmacdev);

  if(gmacavb->Ch2_AdvSlotInterval)
     synopGMACAvbEnAdvSlotInt(gmacdev);
  else
     synopGMACAvbDisAdvSlotInt(gmacdev);

  if(gmacavb->Ch2CrSh == 0){// when zero we need to disable creditshape algorithm
     synopGMACAvbDisableCrSh(gmacdev);
     synopGMACAvbDisableCrControl(gmacdev);
  }
  else{
        synopGMACAvbEnableCrSh(gmacdev);

  if(gmacavb->Ch2CreditControl)
    synopGMACAvbEnableCrControl(gmacdev);
  else
         synopGMACAvbDisableCrControl(gmacdev);

        synopGMACsetAvbSendSlope(gmacdev,gmacavb->Ch2SendSlope);
        synopGMACsetAvbIdleSlope(gmacdev,gmacavb->Ch2IdleSlope);
        synopGMACsetAvbHiCredit(gmacdev,gmacavb->Ch2HiCredit);
        synopGMACsetAvbLoCredit(gmacdev,gmacavb->Ch2LoCredit);
  }


  synopGMACsetTxRxPrioPolicy(gmacdev,gmacavb->Ch2_tx_rx_prio_policy); //1=>RR 0=>Strict prioriyt
  synopGMACsetTxRxPrio(gmacdev,gmacavb->Ch2_use_tx_high_prio);        //1 => tx has high prio over rx
  synopGMACsetTxRxPrioRatio(gmacdev,gmacavb->Ch2_tx_rx_prio_ratio);   //tx-rx priority weights


  TR("ChSelMask = %02x\n",gmacavb->ChSelMask);
  TR("DurationOfExp= %02x\n",gmacavb->DurationOfExp);
  TR("AvControlCh= %02x\n",gmacavb->AvControlCh);
  TR("PTPCh= %02x\n",gmacavb->PTPCh);
  TR("PrioTagForAV= %02x\n",gmacavb->PrioTagForAV);
  TR("AvType= %04x\n",gmacavb->AvType);

  TR("Ch2PrioWts = %08x\n",gmacavb->Ch2PrioWts);
  TR("Ch2Bw= %02x\n",gmacavb->Ch2Bw);
  TR("Ch2_frame_size= %08x\n",gmacavb->Ch2_frame_size);
  TR("Ch2_EnableSlotCheck= %02x\n",gmacavb->Ch2_EnableSlotCheck);
  TR("Ch2_AdvSlotInterval= %02x\n",gmacavb->Ch2_AdvSlotInterval);
  TR("Ch2CrSh= %02x\n",gmacavb->Ch2CrSh);
  TR("Ch2SlotCount= %02x\n",gmacavb->Ch2SlotCount);
  TR("Ch2AvgBitsPerSlot= %08x\n",gmacavb->Ch2AvgBitsPerSlot);
  TR("Ch2AvgBitsPerSlotAccH= %08x\n",gmacavb->Ch2AvgBitsPerSlotAccH);
  TR("Ch2AvgBitsPerSlotAccL= %08x\n",gmacavb->Ch2AvgBitsPerSlotAccL);
  TR("Ch2CreditControl= %02x\n",gmacavb->Ch2CreditControl);
  TR("Ch2_tx_rx_prio_policy= %02x\n",gmacavb->Ch2_tx_rx_prio_policy);
  TR("Ch2_use_tx_high_prio= %02x\n",gmacavb->Ch2_use_tx_high_prio);
  TR("Ch2_tx_rx_prio_ratio= %02x\n",gmacavb->Ch2_tx_rx_prio_ratio);
  TR("Ch2SendSlope= %08x\n",gmacavb->Ch2SendSlope);
  TR("Ch2IdleSlope= %08x\n",gmacavb->Ch2IdleSlope);
  TR("Ch2HiCredit= %08x\n",gmacavb->Ch2HiCredit);
  TR("Ch2LoCredit= %08x\n",gmacavb->Ch2LoCredit);
  TR("Ch2FramecountTx= %08x\n",gmacavb->Ch2FramecountTx);
  TR("Ch2FramecountRx= %08x\n",gmacavb->Ch2FramecountRx);

  TR("Ch1PrioWts = %08x\n",gmacavb->Ch1PrioWts);
  TR("Ch1Bw= %02x\n",gmacavb->Ch1Bw);
  TR("Ch1_frame_size= %08x\n",gmacavb->Ch1_frame_size);
  TR("Ch1_EnableSlotCheck= %02x\n",gmacavb->Ch1_EnableSlotCheck);
  TR("Ch1_AdvSlotInterval= %02x\n",gmacavb->Ch1_AdvSlotInterval);
  TR("Ch1CrSh= %02x\n",gmacavb->Ch1CrSh);
  TR("Ch1SlotCount= %02x\n",gmacavb->Ch1SlotCount);
  TR("Ch1AvgBitsPerSlot= %08x\n",gmacavb->Ch1AvgBitsPerSlot);
  TR("Ch1AvgBitsPerSlotAccH= %08x\n",gmacavb->Ch1AvgBitsPerSlotAccH);
  TR("Ch1AvgBitsPerSlotAccL= %08x\n",gmacavb->Ch1AvgBitsPerSlotAccL);
  TR("Ch1CreditControl= %02x\n",gmacavb->Ch1CreditControl);
  TR("Ch1_tx_rx_prio_policy= %02x\n",gmacavb->Ch1_tx_rx_prio_policy);
  TR("Ch1_use_tx_high_prio= %02x\n",gmacavb->Ch1_use_tx_high_prio);
  TR("Ch1_tx_rx_prio_ratio= %02x\n",gmacavb->Ch1_tx_rx_prio_ratio);
  TR("Ch1SendSlope= %08x\n",gmacavb->Ch1SendSlope);
  TR("Ch1IdleSlope= %08x\n",gmacavb->Ch1IdleSlope);
  TR("Ch1HiCredit= %08x\n",gmacavb->Ch1HiCredit);
  TR("Ch1LoCredit= %08x\n",gmacavb->Ch1LoCredit);
  TR("Ch1FramecountTx= %08x\n",gmacavb->Ch1FramecountTx);
  TR("Ch1FramecountRx= %08x\n",gmacavb->Ch1FramecountRx);

  TR("Ch0PrioWts = %08x\n",gmacavb->Ch0PrioWts);
  TR("Ch0_frame_size= %08x\n",gmacavb->Ch0_frame_size);
  TR("Ch0_tx_rx_prio_policy= %02x\n",gmacavb->Ch0_tx_rx_prio_policy);
  TR("Ch0_use_tx_high_prio= %02x\n",gmacavb->Ch0_use_tx_high_prio);
  TR("Ch0_tx_rx_prio_ratio= %02x\n",gmacavb->Ch0_tx_rx_prio_ratio);
  TR("Ch0FramecountTx= %08x\n",gmacavb->Ch0FramecountTx);
  TR("Ch0FramecountRx= %08x\n",gmacavb->Ch0FramecountRx);

   //Descriptor Memory Allocation for Transmission.
  avb_frame_size = 0;//Initialized to remove compiler warning
  for(dma_index = 0; dma_index<3; dma_index++){
  gmacdev = gmacdev_ch[dma_index];
  if(dma_index == 0)
    avb_frame_size = gmacavb->Ch0_frame_size;
  else if (dma_index == 1)
    avb_frame_size = gmacavb->Ch1_frame_size;
  else if (dma_index == 2)
    avb_frame_size = gmacavb->Ch2_frame_size;

  TR("avb_frame_size of %2d channel = %d\n",dma_index,avb_frame_size);
/*
   for(desc_count = 0; desc_count < gmacdev->TxDescCount; desc_count++  ){
    TR("dma_index = %02d desc_count = %02d\n",dma_index,desc_count);
    synopGMAC_get_desc_data(gmacdev->TxDesc + desc_count, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2);
    TR("status=%08x,dma_addr1 = %08x, length1 = %08x, data1 = %08x, dma_addr2 = %08x, length2 = %08x, data2 = %08x\n",
                    status, dma_addr1,length1,data1,dma_addr2,length2,data2 );
    status = 0;
    if(((struct sk_buff *)data1) != NULL){
      TR("data1 is not NULL\n");
      skb = (struct sk_buff *) data1;
      populate_tx_avb_data (dma_index, avb_frame_size, (u32 *)skb->data, gmacavb);
      synopGMAC_set_desc_data(gmacdev->TxDesc + desc_count, status, dma_addr1, avb_frame_size,data1, dma_addr2,length2, data2);
    }
    }

*/


    ch_tx_desc_slot_no = 0;
    ch_tx_desc_slot_no_skip = 0;
  if(dma_index == 1){//For channel 1
    ch_tx_desc_slot_no       = gmacavb->Ch1_tx_desc_slot_no_start;
          ch_tx_desc_slot_no_skip  = gmacavb->Ch1_tx_desc_slot_no_skip;
  }
  if(dma_index == 2){//For channel 2
    ch_tx_desc_slot_no       = gmacavb->Ch2_tx_desc_slot_no_start;
          ch_tx_desc_slot_no_skip  = gmacavb->Ch2_tx_desc_slot_no_skip;
  }


   for(desc_count = 0; desc_count < gmacdev->TxDescCount; desc_count++  ){

    TR("dma_index = %02d desc_count = %02d\n",dma_index,desc_count);
    synopGMAC_get_desc_data(gmacdev->TxDesc + desc_count, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2);
    TR("status=%08x,dma_addr1 = %08x, length1 = %08x, data1 = %08x, dma_addr2 = %08x, length2 = %08x, data2 = %08x\n",
                    status, dma_addr1,length1,data1,dma_addr2,length2,data2 );
    status = 0;
    if(((struct sk_buff *)data1) != NULL){
      TR("data1 is not NULL\n");
      skb = (struct sk_buff *) data1;
      printk(KERN_CRIT "dma_index = %02d desc_count=%03d ch_tx_desc_slot_no = %01x\n",dma_index,desc_count,ch_tx_desc_slot_no);
      if(dma_index !=0){
        status = (ch_tx_desc_slot_no << 3);
        if(ch_tx_desc_slot_no_skip != 0){
          if(((desc_count + 1) % ch_tx_desc_slot_no_skip) == 0){
                                 ch_tx_desc_slot_no ++;
            ch_tx_desc_slot_no = ch_tx_desc_slot_no & 0xF;
          }
        }
      }
      populate_tx_avb_data (dma_index, avb_frame_size, (u32 *)skb->data, gmacavb);
      synopGMAC_set_desc_data(gmacdev->TxDesc + desc_count, status, dma_addr1, avb_frame_size,data1, dma_addr2,length2, data2);
    }
    }

  }

}

static void synopGMAC_AVB_timer_expired(u32 notused)
{
  u32 dma_index;
  synopGMACdevice       *gmacdev   ;
  synopGMACdevice * gmacdev_ch[3]; // [0] for Best Effor Ethernet, [1] For DMA CH 1, [2] For DMA CH 2

  synopGMACNetworkAdapter *adapter = (synopGMACNetworkAdapter *)synopGMAC_AVB_test_timer.data;

  gmacdev_ch[0] = adapter->synopGMACdev;
  gmacdev_ch[1] = adapter->synopGMACdev_ch1;
  gmacdev_ch[2] = adapter->synopGMACdev_ch2;

  for(dma_index=0;dma_index <3; dma_index ++){
        gmacdev= gmacdev_ch[dma_index];
  synopGMAC_disable_dma_tx(gmacdev);// Disable transmission
  if(dma_index !=0){
          synopGMACAvbDisSlotInterrupt(gmacdev);// Disable the Slot interrupt if enabled for channel 1
          synopGMACAvbDisSlotInterrupt(gmacdev);// Disable the Slot interrupt if enabled for channel 2
  }
  }

    plat_delay(10000);     //Allow any pending buffer to be read by host
    printk(KERN_CRIT "AVB Experiment is Complete... You can Retrieve the Report\n");
}

static void synopGMAC_AVB_setup_timer(struct netif *netdev)
{
    synopGMACNetworkAdapter *adapter = netdev->state;
    synopGMACavbStruct         *gmacavb = adapter->synopGMACavb;

    TR("Setting up the AVB Timer\n");
    RTOS001_Create_Timer(&synopGMAC_AVB_test_timer);
    synopGMAC_AVB_test_timer.function = (void *) synopGMAC_AVB_timer_expired;
    synopGMAC_AVB_test_timer.data     = (u32) adapter;
//    synopGMAC_AVB_test_timer.expires = (CHECK_TIME * 2) + jiffies;
      synopGMAC_AVB_test_timer.expires = (CHECK_TIME * (gmacavb->DurationOfExp)) + jiffies;
//    synopGMAC_AVB_test_timer.expires = (HZ * (gmacavb->DurationOfExp) * 60) + jiffies;
}



static void synopGMAC_AVB_run_test(struct netif *netdev, u32 start_or_continue)
{
  u32 dma_index;
  synopGMACNetworkAdapter * adapter;
  synopGMACavbStruct         * gmacavb;

  synopGMACdevice       *gmacdev   ;
  synopGMACdevice       *gmacdev_ch[3]; // [0] for Best Effor Ethernet, [1] For DMA CH 1, [2] For DMA CH 2

  adapter =  (synopGMACNetworkAdapter *) netdev->state;
  gmacavb =  (synopGMACavbStruct *)adapter->synopGMACavb;

  gmacdev_ch[0] = adapter->synopGMACdev;
  gmacdev_ch[1] = adapter->synopGMACdev_ch1;
  gmacdev_ch[2] = adapter->synopGMACdev_ch2;

  if(start_or_continue) //If start then only start the timer, For continue test timer is not started
    RTOS001_Start_Timer(&synopGMAC_AVB_test_timer);// Start the experiment timer before enabling the DMA's

    for(dma_index = 0; dma_index<3; dma_index++){
      gmacdev = gmacdev_ch[dma_index];
  if((gmacavb->ChSelMask) & (1 << dma_index)){ // Enable only that channel for which Enable is set
    TR("Enabling the DMA Channel[%02d]\n",dma_index);
  //  synopGMAC_clear_interrupt(gmacdev);      //Clear all pending interrupts
      synopGMACAvbEnSlotInterrupt(gmacdev);
    synopGMAC_enable_dma_tx(gmacdev);                 //Enable Dma Tx for all channels
  }
    }

}

#endif

/**
 * Function to handle housekeeping after a packet is transmitted over the wire.
 * After the transmission of a packet DMA generates corresponding interrupt 
 * (if it is enabled).
 *
 * @param[in] synopGMACdev pointer to synopGMACdevice structure.
 *
 * @return void.
 * \note This function runs in interrupt context
 */

void synop_handle_transmit_over(synopGMACdevice * synopGMACdev)
{
  /* <<<DD_ETH_PORT_12>>> */
  s32 desc_index;
  u32 data1, data2;
  u32 status;
  u32 length1, length2;
  u32 dma_addr1, dma_addr2;

#ifdef ENH_DESC_8W
  u32 ext_status;
  u32 time_stamp_high;
  u32 time_stamp_low;
#endif

  if(synopGMACdev == NULL)
  {
    TR("GMAC device structure is missing\n");
    return;
  }

    /*Handle the transmit Descriptors*/
  do
  {

#ifdef ENH_DESC_8W
    desc_index = synopGMAC_get_tx_qptr(synopGMACdev, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2,&ext_status,&time_stamp_high,&time_stamp_low);
        //synopGMAC_TS_read_timestamp_higher_val(synopGMACdev, &time_stamp_higher);
#else
    desc_index = synopGMAC_get_tx_qptr(synopGMACdev, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2);
#endif
    //desc_index = synopGMAC_get_tx_qptr(gmacdev, &status, &dma_addr, &length, &data1);
    if(desc_index >= 0 && data1 != 0)
    {
      //TR("Finished Transmit at Tx Descriptor %d for skb 0x%08x and buffer = %08x whose status is %08x \n", desc_index,data1,dma_addr1,status);

#ifdef  IPC_OFFLOAD

      if(synopGMAC_is_tx_ipv4header_checksum_error(synopGMACdev, status))
      {
        TR("Harware Failed to Insert IPV4 Header Checksum\n");
      }

      if(synopGMAC_is_tx_payload_checksum_error(synopGMACdev, status))
      {
        TR("Harware Failed to Insert Payload Checksum\n");
      }
#endif

      if(synopGMAC_is_desc_valid(status))
      {
    	synopGMACdev->NetStatistics.TxBytes += length1;
    	synopGMACdev->NetStatistics.TxPackets++;
      }
      else
      {
        synopGMACdev->NetStatistics.TxErrors++;
        synopGMACdev->NetStatistics.TxAbortedErrors += synopGMAC_is_tx_aborted(status);
        synopGMACdev->NetStatistics.TxCarrierErrors += synopGMAC_is_tx_carrier_error(status);
      }
    }
    synopGMACdev->NetStatistics.Collisions += synopGMAC_get_tx_collision_count(status);
  } while(desc_index >= 0);
}


#ifdef AVB_SUPPORT

/**
 * Function to Receive a packet from the interface.
 * After Receiving a packet, DMA transfers the received packet to the system memory
 * and generates corresponding interrupt (if it is enabled). This function prepares
 * the sk_buff for received packet after removing the ethernet CRC, and hands it over
 * to linux networking stack.
 *   - Updataes the networking interface statistics
 *  - Keeps track of the rx descriptors
 * @param[in] pointer to netif structure.
 * \return void.
 * \note This function runs in interrupt context.
 */

void synop_handle_received_data_avb(struct netif *netdev, u32 channel_index)
{
  synopGMACNetworkAdapter *adapter;
  synopGMACdevice * gmacdev;
  struct pci_dev *pcidev;
  synopGMACavbStruct *gmacavb;
  s32 desc_index;

  u32 frame_count;

  u32 data1;
  u32 data2;
  u32 len;
  u32 status;
  u32 dma_addr1;
  u32 dma_addr2;
#ifdef ENH_DESC_8W
  u32 ext_status; 
  u32 time_stamp_high;
  u32 time_stamp_low;
#endif
  //u32 length;

  struct sk_buff *skb; //This is the pointer to hold the received data

  TR("%s\n",__FUNCTION__);

    adapter = (synopGMACNetworkAdapter *)netdev->state; /* WIPRO: */
  adapter = netdev->priv;
  if(adapter == NULL){
    TR("Unknown Device\n");
    return;
  }
  gmacavb = adapter->synopGMACavb;
  gmacdev = adapter->synopGMACdev; //Initialized to avoid compiler warning

     //Get the apporpriate handle for gmacdev for respective channel
    if(channel_index == 0){
      gmacdev = adapter->synopGMACdev;
      if(gmacdev == NULL){
        TR("GMAC device structure is missing\n");
        return;
      }
    }
    if(channel_index == 1){
      gmacdev = adapter->synopGMACdev_ch1;
      if(gmacdev == NULL){
        TR("GMAC device structure is missing\n");
        return;
      }
    }
    if(channel_index == 2){
      gmacdev = adapter->synopGMACdev_ch2;
      if(gmacdev == NULL){
        TR("GMAC device structure is missing\n");
        return;
      }
    }


   pcidev  = (struct pci_dev *)adapter->synopGMACpcidev;
  /*Handle the Receive Descriptors*/
  do{
#ifdef ENH_DESC_8W
  desc_index = synopGMAC_get_rx_qptr(gmacdev, &status,&dma_addr1,NULL, &data1,&dma_addr2,NULL,&data2,&ext_status,&time_stamp_high,&time_stamp_low);
  if(desc_index >0){
        synopGMAC_TS_read_timestamp_higher_val(gmacdev, &time_stamp_higher);
  TR("S:%08x ES:%08x DA1:%08x d1:%08x DA2:%08x d2:%08x TSH:%08x TSL:%08x TSHW:%08x \n",status,ext_status,dma_addr1, data1,dma_addr2,data2, time_stamp_high,time_stamp_low,time_stamp_higher);
  }
#else
  desc_index = synopGMAC_get_rx_qptr(gmacdev, &status,&dma_addr1,NULL, &data1,&dma_addr2,NULL,&data2);
#endif

    if(desc_index >= 0 && data1 != 0){
      TR("Received Data at Rx Descriptor %d for skb 0x%08x whose status is %08x\n",desc_index,data1,status);
      /*At first step unmapped the dma address*/
      if(synopGMAC_is_rx_desc_valid(status)){
        len =  synopGMAC_get_rx_desc_frame_length(status) - 4; //Not interested in Ethernet CRC bytes
      #ifdef IPC_OFFLOAD
        // Now lets check for the IPC offloading
        /*  Since we have enabled the checksum offloading in hardware, lets inform the kernel
            not to perform the checksum computation on the incoming packet. Note that ip header
              checksum will be computed by the kernel immaterial of what we inform. Similary TCP/UDP/ICMP
            pseudo header checksum will be computed by the stack. What we can inform is not to perform
            payload checksum.
               When CHECKSUM_UNNECESSARY is set kernel bypasses the checksum computation.
        */


        #ifdef ENH_DESC_8W
        if(synopGMAC_is_ext_status(gmacdev, status)){ // extended status present indicates that the RDES4 need to be probed
          TR("Extended Status present\n");
          if(synopGMAC_ES_is_IP_header_error(gmacdev,ext_status)){       // IP header (IPV4) checksum error
          //Linux Kernel doesnot care for ipv4 header checksum. So we will simply proceed by printing a warning ....
          TR("(EXTSTS)Error in IP header error\n");
          }
          if(synopGMAC_ES_is_rx_checksum_bypassed(gmacdev,ext_status)){   // Hardware engine bypassed the checksum computation/checking
          TR("(EXTSTS)Hardware bypassed checksum computation\n");
          }
          if(synopGMAC_ES_is_IP_payload_error(gmacdev,ext_status)){       // IP payload checksum is in error (UDP/TCP/ICMP checksum error)
          TR("(EXTSTS) Error in EP payload\n");
          }
        }
        else{ // No extended status. So relevant information is available in the status itself
          if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxNoChkError ){
          TR("Ip header and TCP/UDP payload checksum Bypassed <Chk Status = 4>  \n");
          }
          if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxIpHdrChkError ){
          //Linux Kernel doesnot care for ipv4 header checksum. So we will simply proceed by printing a warning ....
          TR(" Error in 16bit IPV4 Header Checksum <Chk Status = 6>  \n");
          }
          if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxLenLT600 ){
          TR("IEEE 802.3 type frame with Length field Lesss than 0x0600 <Chk Status = 0> \n");
          }
          if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxIpHdrPayLoadChkBypass ){
          TR("Ip header and TCP/UDP payload checksum Bypassed <Chk Status = 1>\n");
          }
          if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxChkBypass ){
          TR("Ip header and TCP/UDP payload checksum Bypassed <Chk Status = 3>  \n");
          }
          if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxPayLoadChkError ){
          TR(" TCP/UDP payload checksum Error <Chk Status = 5>  \n");
          }
          if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxIpHdrChkError ){
          //Linux Kernel doesnot care for ipv4 header checksum. So we will simply proceed by printing a warning ....
          TR(" Both IP header and Payload Checksum Error <Chk Status = 7>  \n");
          }
        }
        #else
        if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxNoChkError ){
        TR("Ip header and TCP/UDP payload checksum Bypassed <Chk Status = 4>  \n");
        }
        if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxIpHdrChkError ){
        //Linux Kernel doesnot care for ipv4 header checksum. So we will simply proceed by printing a warning ....
        TR(" Error in 16bit IPV4 Header Checksum <Chk Status = 6>  \n");
        }
        if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxLenLT600 ){
        TR("IEEE 802.3 type frame with Length field Lesss than 0x0600 <Chk Status = 0> \n");
        }
        if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxIpHdrPayLoadChkBypass ){
        TR("Ip header and TCP/UDP payload checksum Bypassed <Chk Status = 1>\n");
        }
        if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxChkBypass ){
        TR("Ip header and TCP/UDP payload checksum Bypassed <Chk Status = 3>  \n");
        }
        if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxPayLoadChkError ){
        TR(" TCP/UDP payload checksum Error <Chk Status = 5>  \n");
        }
        if(synopGMAC_is_rx_checksum_error(gmacdev, status) == RxIpHdrChkError ){
        //Linux Kernel doesnot care for ipv4 header checksum. So we will simply proceed by printing a warning ....
        TR(" Both IP header and Payload Checksum Error <Chk Status = 7>  \n");
        }

        #endif
      #endif //IPC_OFFLOAD

                    if(ext_status & DescRxAvTagPktRx){
                        if (((ext_status & DescRxVlanPrioVal) >> DescRxVlanPrioShVal) >= gmacavb->PrioTagForAV)
                            gmacavb->Ch2FramecountRx++;
                        else
                            gmacavb->Ch1FramecountRx++;
                    }
                    else{
                            gmacavb->Ch0FramecountRx++;
                    }

        netdev->last_rx = jiffies;
        adapter->synopGMACNetStats.rx_packets++;
        adapter->synopGMACNetStats.rx_bytes += len;
      }
      else{
        printk(KERN_CRIT "Packet Dropped here due to status = %08x\n",status);
        adapter->synopGMACNetStats.rx_errors++;
        adapter->synopGMACNetStats.collisions       += synopGMAC_is_rx_frame_collision(status);
        adapter->synopGMACNetStats.rx_crc_errors    += synopGMAC_is_rx_crc(status);
        adapter->synopGMACNetStats.rx_frame_errors  += synopGMAC_is_frame_dribbling_errors(status);
        adapter->synopGMACNetStats.rx_length_errors += synopGMAC_is_rx_frame_length_errors(status);
      }
      //Now lets allocate the skb for the emptied descriptor
            skb = (struct sk_buff *)data1;
      for(frame_count = 0; frame_count<10; frame_count++)
        TR("skb->data[%02d]= %08x\n",frame_count,* (u32 *)((skb->data)+(frame_count*4)));
      desc_index = synopGMAC_set_rx_qptr(gmacdev,dma_addr1, skb_tailroom(skb), (u32)skb,0,0,0);

      if(desc_index < 0){
        TR("Cannot set Rx Descriptor for skb %08x\n",(u32)skb);
      }

    }
  }while(desc_index >= 0);
}

/**
 * Function to handle housekeeping after a packet is transmitted over the wire.
 * After the transmission of a packet DMA generates corresponding interrupt
 * (if it is enabled). It takes care of returning the sk_buff to the linux
 * kernel, updating the networking statistics and tracking the descriptors.
 * @param[in] pointer to netif structure.
 * \return void.
 * \note This function runs in interrupt context
 */
void synop_handle_transmit_over_avb(struct netif *netdev, u32 channel_index)
{
  synopGMACNetworkAdapter *adapter;
  synopGMACdevice * gmacdev;
  struct pci_dev *pcidev;
  synopGMACavbStruct *gmacavb;
  s32 desc_index;
  s32 desc_status;
  u32 data1, data2;
  u32 status;
  u32 length1, length2;
  u32 dma_addr1, dma_addr2;

  u32 avb_frame_size;

#ifdef ENH_DESC_8W
  u32 ext_status;
  u16 time_stamp_higher;
  u32 time_stamp_high;
  u32 time_stamp_low;
#endif
  adapter = (synopGMACNetworkAdapter *)netdev->state; /* WIPRO: */
  adapter = netdev->priv;
  if(adapter == NULL){
    TR("Unknown Device\n");
    return;
  }
  gmacavb = adapter -> synopGMACavb;
  gmacdev = adapter->synopGMACdev;//Initialized to avaoid compiler warning
  avb_frame_size = 0;// Initialized to avoid compier warning
    if(channel_index == 0)
    {
  gmacdev = adapter->synopGMACdev;
      if(gmacdev == NULL){
        TR("GMAC device structure is missing for Best Effor Ethernet Channel\n");
        return;
      }
  avb_frame_size = gmacavb->Ch0_frame_size;
    }
    if(channel_index == 1)
    {
      gmacdev = adapter->synopGMACdev_ch1;
      if(gmacdev == NULL){
        TR("GMAC device structure is missing for DMA Channel 1\n");
        return;
      }
  avb_frame_size = gmacavb->Ch1_frame_size;
    }
    if(channel_index == 2)
    {
      gmacdev = adapter->synopGMACdev_ch2;
      if(gmacdev == NULL){
        TR("GMAC device structure is missing for DMA Channel 2\n");
        return;
      }
  avb_frame_size = gmacavb->Ch2_frame_size;
    }

   pcidev  = (struct pci_dev *)adapter->synopGMACpcidev;
  /*Handle the transmit Descriptors*/
  do {
#ifdef ENH_DESC_8W
  desc_index = synopGMAC_get_tx_qptr(gmacdev, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2,&ext_status,&time_stamp_high,&time_stamp_low);
        //synopGMAC_TS_read_timestamp_higher_val(gmacdev, &time_stamp_higher);
#else
  desc_index = synopGMAC_get_tx_qptr(gmacdev, &status, &dma_addr1, &length1, &data1, &dma_addr2, &length2, &data2);
#endif
  //desc_index = synopGMAC_get_tx_qptr(gmacdev, &status, &dma_addr, &length, &data1);
    if(desc_index >= 0 && data1 != 0){
      TR("Finished Transmit at Tx Descriptor %d for skb 0x%08x and buffer = %08x whose status is %08x \n", desc_index,data1,dma_addr1,status);
      #ifdef  IPC_OFFLOAD
      if(synopGMAC_is_tx_ipv4header_checksum_error(gmacdev, status)){
      TR("Harware Failed to Insert IPV4 Header Checksum\n");
      }
      if(synopGMAC_is_tx_payload_checksum_error(gmacdev, status)){
      TR("Harware Failed to Insert Payload Checksum\n");
      }
      #endif

            if(channel_index == 2){
                   gmacavb->Ch2FramecountTx++;
                  }
                  else if(channel_index == 1){
                    gmacavb->Ch1FramecountTx++;
                  }
                  else if(channel_index == 0){
                    gmacavb->Ch0FramecountTx++;
                  }

      if(synopGMAC_is_desc_valid(status)){
        adapter->synopGMACNetStats.tx_bytes += length1;
        adapter->synopGMACNetStats.tx_packets++;
      }
      else {
        TR("Error in Status %08x\n",status);
        adapter->synopGMACNetStats.tx_errors++;
        adapter->synopGMACNetStats.tx_aborted_errors += synopGMAC_is_tx_aborted(status);
        adapter->synopGMACNetStats.tx_carrier_errors += synopGMAC_is_tx_carrier_error(status);
      }

              // Create the frame and assign it to the respective descriptor
      if(global_avb_debug_enable){ // Only for Debugging
        global_avb_tx_count_debug[channel_index]--;
        if(global_avb_tx_count_debug[channel_index] == 0)
            synopGMACAvbDisSlotInterrupt(gmacdev);
                    synopGMAC_disable_dma_tx(gmacdev);
      }

                       desc_status = synopGMAC_set_tx_qptr(gmacdev,dma_addr1,length1, data1,0,0,0,0);//offload_needed is set to zero
               if(desc_status < 0){
               TR("No More free Descriptors??\n");
           }


    }  adapter->synopGMACNetStats.collisions += synopGMAC_get_tx_collision_count(status);
  } while(desc_index >= 0);
//  netif_wake_queue(netdev); //For AVB we dont use networking stack
}

/**
 * Interrupt service routing.
 * This is the function registered as ISR for device interrupts.
 * @param[in] interrupt number.
 * @param[in] void pointer to device unique structure (Required for shared interrupts in Linux).
 * @param[in] pointer to pt_regs (not used).
 * \return Returns IRQ_NONE if not device interrupts IRQ_HANDLED for device interrupts.
 * \note This function runs in interrupt context
 *
 */
irqreturn_t synopGMAC_intr_handler_avb(s32 intr_num, void * dev_id, struct pt_regs *regs)

{
  /*Kernels passes the netdev structure in the dev_id. So grab it*/
        struct netif *netdev;
        synopGMACNetworkAdapter *adapter;

  synopGMACavbStruct         *gmacavb;

        synopGMACdevice * gmacdev;       // For Place Holder
        synopGMACdevice * gmacdev_ch[3]; // [0] for Best Effor Ethernet, [1] For DMA CH 1, [2] For DMA CH 2


       struct pci_dev *pcidev;

        u32 dma_status_reg;     // For Place Holder
        u32 dma_status_reg_ch[3];  // [0]For Best Effort Ethernet, [1] for CH1, [2] for CH[2]
//        u32 temp_avg_bits = 0;
        u32 interrupt;
//  s32 status;
       //u32 dma_addr;
  u32 dma_ch_index ;

        netdev  = (struct netif *) dev_id;
        if(netdev == NULL){
                TR("Unknown Device\n");
                return -1;
        }

        adapter = (synopGMACNetworkAdapter *)netdev->state; /* WIPRO: */
        adapter  = netdev->priv;
        if(adapter == NULL){
                TR("Adapter Structure Missing\n");
                return -1;
        }

  gmacavb       = adapter->synopGMACavb;

        gmacdev_ch[0] = adapter->synopGMACdev;                         // for Best Effort Ethernet
        if(gmacdev_ch[0] == NULL){
                TR("GMAC device structure Missing for CH0\n");
                return -1;
        }
        gmacdev_ch[1] = adapter->synopGMACdev_ch1;                        // for Prioritized DMA Channel 1
        if(gmacdev_ch[1] == NULL){
                TR("GMAC device structure Missing for CH1\n");
                return -1;
        }
        gmacdev_ch[2] = adapter->synopGMACdev_ch2;                        // for Prioritized DMA Channel 2
        if(gmacdev_ch[2] == NULL){
                TR("GMAC device structure Missing for CH2\n");
                return -1;
        }

      pcidev  = (struct pci_dev *)adapter->synopGMACpcidev;

      /*Read the Dma interrupt status to know whether the interrupt got generated by our device or not*/
  dma_status_reg_ch[0] = synopGMACReadReg((u32 *)gmacdev_ch[0]->DmaBase, DmaStatus);
      dma_status_reg_ch[1] = synopGMACReadReg((u32 *)gmacdev_ch[1]->DmaBase, DmaStatus);
      dma_status_reg_ch[2] = synopGMACReadReg((u32 *)gmacdev_ch[2]->DmaBase, DmaStatus);

      if((dma_status_reg_ch[0] == 0) && (dma_status_reg_ch[1]== 0) && (dma_status_reg_ch[2] == 0)) // If all the three Dma_status registers are zero,
                                                                                            // it is not our interrupt
        return IRQ_NONE;


        // Handle the interrupts one after the other starting with Channel 0, the reason is it contains the Mac Interrupts
        synopGMAC_disable_interrupt_all(gmacdev_ch[0]);
        synopGMAC_disable_interrupt_all(gmacdev_ch[1]);
        synopGMAC_disable_interrupt_all(gmacdev_ch[2]);

        gmacdev = gmacdev_ch[0];
        dma_status_reg = dma_status_reg_ch[0];

        //Handle the GMAC core interrupts first
        if(dma_status_reg & GmacPmtIntr){
           TR("%s:: Interrupt due to PMT module\n",__FUNCTION__);
           synopGMAC_powerup_mac(gmacdev);
      }

        if(dma_status_reg & GmacMmcIntr){
          TR("%s:: Interrupt due to MMC module\n",__FUNCTION__);
          TR("%s:: synopGMAC_rx_int_status = %08x\n",__FUNCTION__,synopGMAC_read_mmc_rx_int_status(gmacdev));
        }

        if(dma_status_reg & GmacLineIntfIntr){
          TR("%s:: Interrupt due to GMAC LINE module\n",__FUNCTION__);
        }

        for(dma_ch_index = 0; dma_ch_index < 3; dma_ch_index++){
            dma_status_reg = dma_status_reg_ch[dma_ch_index];
            gmacdev        = gmacdev_ch[dma_ch_index];

            if(dma_status_reg != 0){   //Handle Channel 0 Interrupts
                 TR("%s:Dma Status Reg for ch[%01d]: 0x%08x\n",__FUNCTION__,dma_ch_index, dma_status_reg);

              /*Now lets handle the DMA interrupts*/
                interrupt = synopGMAC_get_interrupt_type(gmacdev);
                 TR("%s:Interrupts to be handled: 0x%08x\n",__FUNCTION__,interrupt);

                if(interrupt & synopGMADmaSlotCounter){
                        if(dma_ch_index == 2){
        gmacavb->Ch2AvgBitsNoOfInterrupts++;
                                gmacavb->Ch2AvgBitsPerSlot = synopGMACReadReg ((u32 *)gmacdev->DmaBase,DmaChannelAvSts) & ChannelAvgBitsPerSlotMsk ;
//          printk(KERN_CRIT "CH2: %08x\n",gmacavb->Ch2AvgBitsPerSlot);
                          if( ((gmacavb->Ch2AvgBitsPerSlotAccL & 0x80000000) != 0) &&
            (((gmacavb->Ch2AvgBitsPerSlotAccL + gmacavb->Ch2AvgBitsPerSlot) & 0x80000000) == 0))
                                        gmacavb->Ch2AvgBitsPerSlotAccH++;

        gmacavb->Ch2AvgBitsPerSlotAccL = gmacavb->Ch2AvgBitsPerSlotAccL + gmacavb->Ch2AvgBitsPerSlot;

                        }
                        if(dma_ch_index == 1){
        gmacavb->Ch1AvgBitsNoOfInterrupts++;
                                gmacavb->Ch1AvgBitsPerSlot = synopGMACReadReg ((u32 *)gmacdev->DmaBase,DmaChannelAvSts) & ChannelAvgBitsPerSlotMsk ;
//        printk(KERN_CRIT "CH1: %08x\n",gmacavb->Ch1AvgBitsPerSlot);
                                if( ((gmacavb->Ch1AvgBitsPerSlotAccL & 0x80000000) != 0) &&
                                    (((gmacavb->Ch1AvgBitsPerSlotAccL + gmacavb->Ch1AvgBitsPerSlot) & 0x80000000) == 0))
                                        gmacavb->Ch1AvgBitsPerSlotAccH++;

        gmacavb->Ch1AvgBitsPerSlotAccL = gmacavb->Ch1AvgBitsPerSlotAccL + gmacavb->Ch1AvgBitsPerSlot;
                        }
                }

                if(interrupt & synopGMACDmaError){
                u8 mac_addr0[6] = DEFAULT_MAC_ADDRESS;//after soft reset, configure the MAC address to default value
                TR("%s::Fatal Bus Error Inetrrupt Seen\n",__FUNCTION__);
                synopGMAC_disable_dma_tx(gmacdev);
                        synopGMAC_disable_dma_rx(gmacdev);

                synopGMAC_take_desc_ownership_tx(gmacdev);
                synopGMAC_take_desc_ownership_rx(gmacdev);

                synopGMAC_init_tx_rx_desc_queue(gmacdev);

                synopGMAC_reset(gmacdev);//reset the DMA engine and the GMAC ip

                synopGMAC_set_mac_addr(gmacdev,GmacAddr0High,GmacAddr0Low, mac_addr0);
                synopGMAC_dma_bus_mode_init(gmacdev,DmaFixedBurstEnable| DmaBurstLength8 | DmaDescriptorSkip2 );
                 synopGMAC_dma_control_init(gmacdev,DmaStoreAndForward);
                synopGMAC_init_rx_desc_base(gmacdev);
                synopGMAC_init_tx_desc_base(gmacdev);
                synopGMAC_mac_init(gmacdev);
                synopGMAC_enable_dma_rx(gmacdev);
                synopGMAC_enable_dma_tx(gmacdev);
                }

              if(interrupt & synopGMACDmaRxNormal){ //Handle Receive Interrupt
                TR("%s:: Rx Normal \n", __FUNCTION__);
                    synop_handle_received_data_avb(netdev,dma_ch_index);
              }

                if(interrupt & synopGMACDmaRxAbnormal){ //Handle Receive Abnormal Interrupt
                  TR("%s::Abnormal Rx Interrupt Seen\n",__FUNCTION__);
                #if 1
                    if(GMAC_Power_down == 0){  // If Mac is not in powerdown
                            adapter->synopGMACNetStats.rx_over_errors++;
                        /*Now Descriptors have been created in synop_handle_received_data().
                             * Just issue a poll demand to resume DMA operation*/
                        synopGMAC_resume_dma_rx(gmacdev);//To handle GBPS with 12 descriptors
                    }
                #endif
              }

                if(interrupt & synopGMACDmaRxStopped){
                  TR("%s::Receiver stopped seeing Rx interrupts\n",__FUNCTION__); //Receiver gone in to stopped state
              }

          if(interrupt & synopGMACDmaTxNormal){
            //xmit function has done its job
            TR("%s::Finished Normal Transmission \n",__FUNCTION__);
            synop_handle_transmit_over_avb(netdev,dma_ch_index);//Do whatever you want after the transmission is over
            }

            if(interrupt & synopGMACDmaTxAbnormal){
            TR("%s::Abnormal Tx Interrupt Seen\n",__FUNCTION__);
            #if 1
                 if(GMAC_Power_down == 0){  // If Mac is not in powerdown
                        synop_handle_transmit_over_avb(netdev,dma_ch_index);
                }
            #endif
          }

            if(interrupt & synopGMACDmaTxStopped){
            TR("%s::Transmitter stopped sending the packets\n",__FUNCTION__);
            }
          }// Per Channel interrupt handling is done

        }
          /* Enable the interrrupt before returning from ISR*/
        synopGMAC_enable_interrupt(gmacdev_ch[0],DmaIntEnable);
        synopGMAC_enable_interrupt(gmacdev_ch[1],DmaIntEnable);
        synopGMAC_enable_interrupt(gmacdev_ch[2],DmaIntEnable);

      return IRQ_HANDLED;
}

#endif

#ifdef LINUX_CODE
/**
 * Function to set multicast and promiscous mode.
 * @param[in] pointer to netif structure.
 * \return returns void.
 */
void synopGMAC_linux_set_multicast_list(synopGMACdevice * synopGMACdev)
{
  TR("%s called \n",__FUNCTION__);
  return;
}
#endif

/**
 * The function checks if the Given ethernet address is valid or not
 *
 * @param[in] MacAddr Mac address
 *
 * @return 1 if Ethernet MAC is valid, otherwise 0
 */
static __INLINE int is_valid_ether_addr(const unsigned char *MacAddr)
{
  /* <<<DD_ETH_PORT_13>>> */
  return (! (0x01 & MacAddr[0]) &&
		   (MacAddr[0] | MacAddr[1] | MacAddr[2] | MacAddr[3] |
		    MacAddr[4] | MacAddr[5]));
}


/**
 * Function to set Ethernet address of the NIC.
 * @param[in] synopGMACdev pointer to GMAC Device structure.
 * @param[in] macaddr pointer to an address structure.
 * \return Returns 0 on success Errorcode on failure.
 */
s32 synopGMAC_set_mac_address(synopGMACdevice *synopGMACdev, void * macaddr)
{
  if(synopGMACdev == NULL)
  {
    DBG002_ERROR(APP_GID, ETH_NULL_PARAM, 0, NULL);
    return ETH_NULL_PARAM;
  }

  /* Check if the Ethernet Address is valid */
  if(!is_valid_ether_addr((unsigned char*)macaddr))
  {
	  DBG002_ERROR(APP_GID, ETH_INVALID_MAC_ADDR, 0, NULL);
      return ETH_INVALID_MAC_ADDR;
  }

  synopGMAC_set_mac_addr(synopGMACdev, GmacAddr0High, GmacAddr0Low,
		  (unsigned char *)macaddr);

  synopGMAC_get_mac_addr(synopGMACdev, GmacAddr0High, GmacAddr0Low,
		  (u8 *)(synopGMACdev->MacAddress));

  return DAVEApp_SUCCESS;
}

/**
 * Function to change the Maximum Transfer Unit.
 * @param[in] pointer to synopGMACdevice structure.
 * @param[in] New value for maximum frame size.
 * \return Returns 0 on success Errorcode on failure.
 */
s32 synopGMAC_change_mtu(synopGMACdevice * synopGMACdev, s32 newmtu)
{
  //Todo Function not yet implemented.
  return 0;
}

#ifdef LINUX_CODE
/**
 * Function to handle a Tx Hang.
 * This is a software hook (Linux) to handle transmitter hang if any.
 * We get transmitter hang in the device interrupt status, and is handled
 * in ISR. This function is here as a place holder.
 * @param[in] pointer to netif structure
 * \return void.
 */
void synopGMAC_linux_tx_timeout(synopGMACdevice * synopGMACdev)
{
  // Function not yet implemented
  return;
}

#endif

/**
 * @}
 */

/**
 * @endcond
 */
