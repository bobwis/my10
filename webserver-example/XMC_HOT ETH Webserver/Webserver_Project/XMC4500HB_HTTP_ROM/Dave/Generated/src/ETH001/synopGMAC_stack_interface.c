/*CODE_BLOCK_BEGIN[synopGMAC_stack_interface.c]*/
/* =============================================================================
 * Copyright (c) <2009> Synopsys, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software annotated with this license and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *============================================================================*/
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
 * ========================================================================== *
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
** JRP          DAVE App Developer                                            **
********************************************************************************

 *
 * @file synopGMAC_stack_interface.c
 * 
 * @App Version ETH001 <1.0.16>
 *
 * @brief  Network Interface code for Synop GMAC 
 *
 * Revision History
 * 12 Dec 2012  v1.0.16    Base line from version v1.0.14
 *                         dbg002 related macros are added
 *
 */
/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/


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

/**
 * @ingroup Ethernet_publicparam
 * @{
 */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define APP_GID DBG002_GID_ETH001

#ifdef CHECKSUM_BY_HARDWARE
  #define IPC_OFFLOAD
#endif
#define   ETH_BASE          (ETH0_BASE + 0x1000U)  /* not defined in XMC4500 header */
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/* These are the global pointers for their respective structures */
synopGMACdevice GMACdevice;
synopGMACdevice *synopGMACdev;

static SynopGMACPeriodicTimerCallbackType SynopGMACPeriodicTimerCallback;
static SynopGMACDeletePeriodicTimerType SynopGMACDeletePeriodicTimer;

/** Receive packet buffer list */
extern uint8_t Eth_RxBuffer[RX_BUFFER_SIZE];
extern uint8_t Eth_TxBuffer[RX_BUFFER_SIZE];

/* Cable plug-unplug Timer Handle */
/*handle_t Eth_TimerHandle;*/

/* This global variable is used to indicate the ISR whether the interrupts
 * occurred in the process of powering down the mac or not
 */
uint32_t GMAC_Power_down;
extern s32 synopGMAC_set_tx_address(synopGMACdevice * gmacdev,u32 count, u32 Buffer1);
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

static void Eth_lGetRMONCounters(Eth_StructRMONCountersType *Eth_IoctlParam);

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
status_t Eth_GetTxBuffer(uint8_t** Buffer)
{
	*Buffer = (uint8_t*)synopGMACdev->TxNextDesc->buffer1;
	return DAVEApp_SUCCESS;
}
status_t Eth_InitNetworkInterface(void)
{
  synopGMACdev = &GMACdevice;
  /* Set Ethernet MAC interface  (RMII/MII) to one selected by user */
  WR_REG(ETH0_CON->CON, ETH_CON_INFSEL_Msk, ETH_CON_INFSEL_Pos, ETH_MAC_SEL);
   
  
  /* To Deassert */
  RESET001_DeassertReset(PER2_ETH0);
  /** Configure CLKSET*/
  WR_REG(SCU_CLK->CLKSET, SCU_CLK_CLKSTAT_ETH0CST_Msk, SCU_CLK_CLKSTAT_ETH0CST_Pos, 1U);  
  /* Pad Driver Mode settings */  
  /* OUT PINs used in ETH for setting Pad drive modes */   
  /* Configuration of TXD0 Pin 2.8 based on User configuration */                                      
  WR_REG(PORT2->PDR1, PORT2_PDR1_PD8_Msk, PORT2_PDR1_PD8_Pos, 0U);    
  /* Configuration of TXD1 Pin 2.9 based on User configuration */                                      
  WR_REG(PORT2->PDR1, PORT2_PDR1_PD9_Msk, PORT2_PDR1_PD9_Pos, 0U);    
  /* Configuration of TXD1 Pin 5.9 based on User configuration */                                      
  WR_REG(PORT5->PDR1, PORT5_PDR1_PD9_Msk, PORT5_PDR1_PD9_Pos, 0U);       
  /* <<<DD_ETH_PORT_1>>> */
  /* Attach the device to MAC struct. This will configure all the required base
   * addresses such as MAC base, Configuration base, PHY base address
   * (out of 32 possible phys )
   */
  synopGMAC_attach(synopGMACdev, ETH0_BASE, ETH_BASE, PHY_BASE_ADDRESS);  
  /* Reset the GMAC */
  synopGMAC_reset(synopGMACdev);
  
  DBG002_INFO(APP_GID, ETH_INIT_SUCCESS, 0, NULL);
  return DAVEApp_SUCCESS;
}


void Eth_ExitNetworkInterface(void)
{
  /* <<<DD_ETH_PORT_2>>> */
  /* This function is an empty function kept for uniformity */
  DBG002_INFO(APP_GID, ETH_EXIT_SUCCESS, 0, NULL);
}


status_t Eth_OpenNetworkInterface(void)
{
  /* <<<DD_ETH_PORT_3>>> */
  status_t Status = ETH_OPEN_ERROR;
  uint32_t DescCount = 0;
  int32_t DescStatus = -1;

  do
  {
    /* Now platform dependent initialization.*/

    /* Attach the device to MAC struct. This will configure all the required base
     * addresses such as MAC base, Configuration base, PHY base address(out of 32
     * possible PHYs)
     */

    synopGMAC_attach(synopGMACdev, ETH0_BASE, ETH_BASE, PHY_BASE_ADDRESS);

    /* Lets read the version of IP in to device structure*/
    synopGMAC_read_version(synopGMACdev);

    /* Stack should use IOCTL to get the MAC Address */
    synopGMAC_get_mac_addr(synopGMACdev, GmacAddr0High, GmacAddr0Low,
        synopGMACdev->MacAddress);

    /* Check for PHY initialization */
    synopGMAC_set_mdc_clk_div(synopGMACdev, GmiiCsrClk3);

    synopGMACdev->ClockDivMdc = synopGMAC_get_mdc_clk_div(synopGMACdev);

    /* Initialize Ethernet PHY */
    Status = PHY_InitializeDevice();
    if (Status != DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, Status, 0, NULL);
      break;
    }

#ifndef BUILD_UIP  /* UIP polls the packets. Hence no interrupt handler.*/
    /* ISR will be registered via NVIC */
    NVIC_SetPriority(108, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),
       			                                    63, 0));
    NVIC_EnableIRQ(108);
#endif 

    /* Set up the TX descriptor queue/ring */
    /* Configure the descriptors in RING mode */
    synopGMAC_setup_tx_desc_queue(synopGMACdev, TRANSMIT_DESC_SIZE, RINGMODE);

    /* Program the transmit descriptor base address in to DmaTxBase Address */
    synopGMAC_init_tx_desc_base(synopGMACdev);

    /* Set up the Rx descriptor queue/ring */
    synopGMAC_setup_rx_desc_queue(synopGMACdev, RECEIVE_DESC_SIZE, RINGMODE);

    /* Program the receive descriptor base address in to DmaTxBase Address */
    synopGMAC_init_rx_desc_base(synopGMACdev);

#ifdef ENH_DESC_8W
    /* Note: Keeping the default values */
    /* pbl32 incr with rxthreshold 128 and Desc is 8 Words */
    synopGMAC_dma_bus_mode_init(synopGMACdev, DmaBurstLength32 |
        DmaDescriptorSkip2 | DmaDescriptor8Words );

#else
    /* Note: Keeping the default values */
    /* pbl32 incr with rxthreshold 128 */
    synopGMAC_dma_bus_mode_init(synopGMACdev,
        DmaBurstLength32 | DmaDescriptorSkip2);
#endif

    /* Configure Store and forward, OSF, RX threshold control */
    synopGMAC_dma_control_init(synopGMACdev,
        DmaStoreAndForward | DmaTxSecondFrame | DmaRxThreshCtrl128);
		 
#ifdef HALF_DUPLEX
    synopGMACdev->DuplexMode = HALFDUPLEX;
#else
    synopGMACdev->DuplexMode = FULLDUPLEX;
#endif

#ifdef SPEED_100	
	synopGMAC_rmii_100mbps_enable(synopGMACdev); 
#endif

#if AUTO_NEGO
	synopGMAC_rmii_100mbps_enable(synopGMACdev); 
#endif
    /* Initialize the MAC interface */
    synopGMAC_mac_init(synopGMACdev);

#ifdef ENABLE_MULTICAST    
    /* To enable Multicast */
    synopGMAC_multicast_enable(synopGMACdev);

    synopGMAC_multicast_hash_filter_enable(synopGMACdev);
#endif
    
   /* To enable Broadcast */
   synopGMAC_broadcast_enable(synopGMACdev);
   
#ifdef  ENABLE_PROMISCUOUS
   /* To enable Promiscuous Mode. */
   synopGMAC_promisc_enable(synopGMACdev); 
#endif
   
#ifndef HALF_DUPLEX
    /* This enables the pause control in Full Duplex mode of operation */
    //synopGMAC_pause_control(synopGMACdev);
#endif

  /* Enable this when Stack allows CHECKSUM OFFLOADING */
#ifdef IPC_OFFLOAD
    /* <<<DD_ETH_PORT_3_1>>> */
    /* <<<DD_ETH_PORT_3_2>>> */

    /* IPC Checksum offloading is enabled for this driver. Should only be used
     * if Full IP checksum offload engine is configured in the hardware
     */

    /* Enable the offload engine in the receive path */
    synopGMAC_enable_rx_chksum_offload(synopGMACdev);

    /* This is default configuration, DMA drops the packets if error in
     * encapsulated Ethernet payload
     */
    synopGMAC_rx_tcpip_chksum_drop_enable(synopGMACdev);

    /* The FEF bit in DMA control register is configured to 0 indicating DMA to
     * drop the errored frames.
     */
#endif

    do
    {
      DescStatus = synopGMAC_set_rx_qptr(synopGMACdev,
                                 (uint32_t)&Eth_RxBuffer[DescCount * ETH_PACKET_SIZE],
                                 ETH_PACKET_SIZE,
                                 (uint32_t)&Eth_RxBuffer[DescCount * ETH_PACKET_SIZE],
                                 0,0,0);


      DescStatus = synopGMAC_set_tx_address(synopGMACdev, DescCount,
                                            (uint32_t)&Eth_TxBuffer[DescCount * ETH_PACKET_SIZE]
                                            );

      DescCount++;
    }while((DescStatus >= 0) && (DescCount < RECEIVE_DESC_SIZE));

    DBG002_INFO(APP_GID, ETH_SETUP_RX_DESC, 0, NULL);

	if(NULL != SynopGMACPeriodicTimerCallback)
	{
		SynopGMACPeriodicTimerCallback(CABLE_STATUS_PERIOD, synopGMACdev);
	}
    /* Clear all the interrupts */
    synopGMAC_clear_interrupt(synopGMACdev);

    /**
     * Disable the interrupts generated by MMC and IPC counters.
     * If these are not disabled ISR should be modified accordingly to handle
     * these interrupts.
     */
    synopGMAC_disable_mmc_tx_interrupt(synopGMACdev, 0xFFFFFFFF);
    synopGMAC_disable_mmc_rx_interrupt(synopGMACdev, 0xFFFFFFFF);
    synopGMAC_disable_mmc_ipc_rx_interrupt(synopGMACdev, 0xFFFFFFFF);

    /** Configure DMA Interrupts */
    synopGMAC_enable_interrupt(synopGMACdev, DmaIntEnable);
    synopGMAC_enable_dma_rx(synopGMACdev);
    synopGMAC_enable_dma_tx(synopGMACdev);

    Status = DAVEApp_SUCCESS;
  }while (0);

  return Status;
}


status_t Eth_CloseNetworkInterface (void)
{
  /* <<<DD_ETH_PORT_4>>> */
  status_t Status = ETH_CLOSE_ERROR;

  /* Disable all the interrupts*/
  synopGMAC_disable_interrupt_all(synopGMACdev);

  DBG002_INFO(APP_GID, ETH_INTR_DISABLED, 0, NULL);

  /* Disable the reception */
  synopGMAC_disable_dma_rx(synopGMACdev);
  synopGMAC_take_desc_ownership_rx(synopGMACdev);

  DBG002_INFO(APP_GID, ETH_RX_DISABLED, 0, NULL);

  /* Disable the transmission */
  synopGMAC_disable_dma_tx(synopGMACdev);
  synopGMAC_take_desc_ownership_tx(synopGMACdev);

  DBG002_INFO(APP_GID, ETH_TX_DISABLED, 0, NULL);

  /* Free the Rx Descriptor contents */
  synopGMAC_giveup_rx_desc_queue(synopGMACdev, RINGMODE);

  /* Free the Tx Descriptor contents */
  synopGMAC_giveup_tx_desc_queue(synopGMACdev, RINGMODE);

  /* Delete the Cable plug/unplug Timer*/
  if(NULL != SynopGMACDeletePeriodicTimer)
  {
	SynopGMACDeletePeriodicTimer();
  }
  if (Status != DAVEApp_SUCCESS)
  {
    DBG002_WARNING(APP_GID, ETH_CLOSE_ERROR, 0, NULL);
  }
  Status = DAVEApp_SUCCESS;
  return Status;
}


status_t Eth_TransmitFrames
(
  uint8_t *PacketBuffer,
  uint32_t PacketLength
)
{
  /* <<<DD_ETH_PORT_5>>> */
  uint32_t Status = ETH_XMIT_ERROR;
  uint32_t OffloadNeeded = 0;
  int32_t DescStatus = -1;
  /* extern uint8_t Eth_TxBuffer[2048]; */
  
  do
  {
	if(NULL == PacketBuffer)
    {
      DBG002_ERROR(APP_GID, ETH_NULL_PARAM, 0, NULL);
      break;
    }


#ifdef IPC_OFFLOAD

    /* Checksum offloading is required */
    OffloadNeeded = 0x00000001;

#endif

    /*
     * Now we have packet ready and stack invoked this function.
     * Lets make our DMA know about this
     */
    /*DescStatus = synopGMAC_set_tx_qptr(synopGMACdev, (uint32_t)PacketBuffer,
        PacketLength, (uint32_t)PacketBuffer,0,0,0, OffloadNeeded); */

	DescStatus = synopGMAC_set_tx_qptr(synopGMACdev, (uint32_t)PacketBuffer,
        PacketLength, (uint32_t)PacketBuffer,0,0,0, OffloadNeeded);

    if(DescStatus < 0)
    {
      DBG002_ERROR(APP_GID, ETH_TX_SETUP_ERROR, 0, NULL);
      break;
    }

    /* Now force the DMA to start transmission*/
    synopGMAC_resume_dma_tx(synopGMACdev);

    Status = DAVEApp_SUCCESS;
  } while (0);

  return Status;
}

#ifdef BUILD_UIP
uint32_t Eth_ReceiveData(void *buf)
{
  /* <<<DD_ETH_PORT_6>>> */
  int32_t DescIndex = 0;
  uint32_t Data1 = 0 ;
  uint32_t Data2 = 0;
  uint32_t Length = 0;
  uint32_t Status = ETH_RECV_ERROR;
  uint32_t dma_addr1 = 0;
  uint32_t dma_addr2 = 0;

#ifdef ENH_DESC_8W
  u32 ext_status;
  u16 time_stamp_higher;
  u32 time_stamp_high;
  u32 time_stamp_low;
#endif

  /* Handle the Receive Descriptors*/
  do */
  {
    DmaDesc *rxdesc = synopGMACdev->RxBusyDesc;

    DescIndex = synopGMAC_get_rx_qptr(synopGMACdev,
    		                          &Status,
    		                          &dma_addr1,
    		                          NULL,
    		                          &Data1,
    		                          &dma_addr2,
    		                          NULL,
    		                          &Data2);
    if(DescIndex >= 0 && Data1 != 0)
    {
      //TR("Received Data at Rx Descriptor %d for skb 0x%08x whose Status is %08x\n",DescIndex,Data1,Status);

      if(synopGMAC_is_rx_desc_valid(Status))
      {
    	  /** Not interested in Ethernet CRC bytes */
        Length =  synopGMAC_get_rx_desc_frame_length(Status) - 4;

#ifdef IPC_OFFLOAD
        /* Now lets check for the IPC offloading */
        TR("Checksum Offloading will be done now\n");

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status)
        		== RxNoChkError )
        {
          TR("Ip header and TCP/UDP payload checksum Bypassed <Chk Status = 4>\n");
        }

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status)
        		== RxIpHdrChkError )
        {
          TR("Error in 16bit IPV4 Header Checksum <Chk Status = 6>  \n");
        }

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status) == RxLenLT600)
        {
          TR("IEEE 802.3 type frame with Length field Lesss than 0x0600 \
        		  <Chk Status = 0>\n");
        }

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status)
        		== RxIpHdrPayLoadChkBypass )
        {
          TR("Ip header and TCP/UDP payload checksum Bypassed \
        		  <Chk Status = 1>");
        }

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status) == RxChkBypass)
        {
          TR("Ip header and TCP/UDP payload checksum Bypassed \
        		  <Chk Status = 3>");
        }

        if(synopGMAC_is_rx_checksum_error(synopGMACdev, Status) ==
        		RxPayLoadChkError)
        {
          TR("TCP/UDP payload checksum Error <Chk Status = 5>");
        }

        if(synopGMAC_is_rx_checksum_error(synopGMACdev, Status) ==
        		RxIpHdrChkError)
        {
          TR("Both IP header and Payload Checksum Error <Chk Status = 7>");
        }
#endif /* IPC_OFFLOAD */

        synopGMACdev->NetStatistics.RxPackets++;
        synopGMACdev->NetStatistics.RxBytes += Length;

        buf = rxdesc->buffer1;

        /* Copy the packet to uIP buffer */
        for(offset=0; rxdesc->length; offset++)       
        {
          (*(buf + offset)) = (*( uint8_t *)((rxdesc->Buffer1Addr) + offset));
        }
      }
      else
      {
    	  synopGMACdev->NetStatistics.RxErrors++;
        synopGMACdev->NetStatistics.Collisions     +=
            synopGMAC_is_rx_frame_collision(Status);
        synopGMACdev->NetStatistics.RxCrcErrors    +=
            synopGMAC_is_rx_crc(Status);
        synopGMACdev->NetStatistics.RxFrameErrors  +=
            synopGMAC_is_frame_dribbling_errors(Status);
        synopGMACdev->NetStatistics.RxLengthErrors +=
            synopGMAC_is_rx_frame_length_errors(Status);
      }

      /* Return the descriptor back to DMA */
      DescIndex = synopGMAC_set_rx_qptr(synopGMACdev,
    		                            rxdesc->buffer1,
    		                            ETH_PACKET_SIZE,
    		                            rxdesc->buffer1,
    		                            0,0,0);
      if(DescIndex < 0)
      {
        TR("Cannot set Rx Descriptor\n");
      }
    }
    Status = DAVEApp_SUCCESS;
  }
  /* while(DescIndex >= 0); */

  /* Return the packet length */
  return Length;
}

#else  /* BUILD_UIP */
status_t Eth_ReceiveData(void)
{
  /* <<<DD_ETH_PORT_6>>> */
  int32_t DescIndex = 0;
  uint32_t Data1 = 0 ;
  uint32_t Data2 = 0;
  uint32_t Length = 0;
  uint32_t Status = ETH_RECV_ERROR;
  uint32_t dma_addr1 = 0;
  uint32_t dma_addr2 = 0;
  
#ifdef ENH_DESC_8W
  u32 ext_status;
  u32 time_stamp_high;
  u32 time_stamp_low;
#endif

  /* Handle the Receive Descriptors*/
  do
  {
    DmaDesc *rxdesc = synopGMACdev->RxBusyDesc;

    DescIndex = synopGMAC_get_rx_qptr(synopGMACdev,
    		                          &Status,
    		                          &dma_addr1,
    		                          NULL,
    		                          &Data1,
    		                          &dma_addr2,
    		                          NULL,
    		                          &Data2,&ext_status,&time_stamp_high,&time_stamp_low);
    if(DescIndex >= 0 && Data1 != 0)
    {
      //TR("Received Data at Rx Descriptor %d for skb 0x%08x whose Status is %08x\n",DescIndex,Data1,Status);

      if(synopGMAC_is_rx_desc_valid(Status))
      {
    	  /** Not interested in Ethernet CRC bytes */
        Length =  synopGMAC_get_rx_desc_frame_length(Status) - 4;

#ifdef IPC_OFFLOAD
        /* Now lets check for the IPC offloading */
        TR("Checksum Offloading will be done now\n");

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status)
        		== RxNoChkError )
        {
          TR("Ip header and TCP/UDP payload checksum Bypassed <Chk Status = 4>\n");
        }

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status)
        		== RxIpHdrChkError )
        {
          TR("Error in 16bit IPV4 Header Checksum <Chk Status = 6>  \n");
        }

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status) == RxLenLT600)
        {
          TR("IEEE 802.3 type frame with Length field Lesss than 0x0600 \
        		  <Chk Status = 0>\n");
        }

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status)
        		== RxIpHdrPayLoadChkBypass )
        {
          TR("Ip header and TCP/UDP payload checksum Bypassed \
        		  <Chk Status = 1>");
        }

        if (synopGMAC_is_rx_checksum_error(synopGMACdev, Status) == RxChkBypass)
        {
          TR("Ip header and TCP/UDP payload checksum Bypassed \
        		  <Chk Status = 3>");
        }

        if(synopGMAC_is_rx_checksum_error(synopGMACdev, Status) ==
        		RxPayLoadChkError)
        {
          TR("TCP/UDP payload checksum Error <Chk Status = 5>");
        }

        if(synopGMAC_is_rx_checksum_error(synopGMACdev, Status) ==
        		RxIpHdrChkError)
        {
          TR("Both IP header and Payload Checksum Error <Chk Status = 7>");
        }
#endif /* IPC_OFFLOAD */

        synopGMACdev->NetStatistics.RxPackets++;
        synopGMACdev->NetStatistics.RxBytes += Length;

        /* Send the packet buffer to Eth_Received_Data_Handler for processing */
        Eth_Received_Data_Handler(rxdesc->buffer1, Length);

		if(synopGMAC_is_rx_desc_chained(rxdesc))
		{
	   		synopGMACdev->RxBusyDesc = (DmaDesc *)rxdesc->data2;
			synopGMAC_rx_desc_init_chain(rxdesc);
			//synopGMAC_rx_desc_init_chain(rxdesc, synopGMAC_is_last_rx_desc(synopGMACdev,rxdesc),0,0);
		}
		else
		{
			synopGMACdev->RxBusyDesc = synopGMAC_is_last_rx_desc(synopGMACdev,rxdesc) ? synopGMACdev->RxDesc : (rxdesc + 1);
			synopGMAC_rx_desc_init_ring(rxdesc, synopGMAC_is_last_rx_desc(synopGMACdev,rxdesc));
		}
      }
      else
      {
    	  synopGMACdev->NetStatistics.RxErrors++;
        synopGMACdev->NetStatistics.Collisions     +=
            synopGMAC_is_rx_frame_collision(Status);
        synopGMACdev->NetStatistics.RxCrcErrors    +=
            synopGMAC_is_rx_crc(Status);
        synopGMACdev->NetStatistics.RxFrameErrors  +=
            synopGMAC_is_frame_dribbling_errors(Status);
        synopGMACdev->NetStatistics.RxLengthErrors +=
            synopGMAC_is_rx_frame_length_errors(Status);
      }

      /* Return the descriptor back to DMA */
      DescIndex = synopGMAC_set_rx_qptr(synopGMACdev,
                                        (uint32_t)&Eth_RxBuffer[DescIndex * ETH_PACKET_SIZE],
    		                            ETH_PACKET_SIZE,
                                        (uint32_t)&Eth_RxBuffer[DescIndex * ETH_PACKET_SIZE],
    		                            0,0,0);
      if(DescIndex < 0)
      {
        TR("Cannot set Rx Descriptor\n");
      }
    }
    Status = DAVEApp_SUCCESS;
  }while(DescIndex >= 0);

  return Status;
}
#endif  /* BUILD_UIP */

void IRQ_Hdlr_108(void)
{
  /* <<<DD_ETH_PORT_7>>> */
  uint32_t interrupt, dma_status_reg;
  uint32_t status;

  /* Read the Dma interrupt status to know whether the interrupt got generated
   * by our device or not
   *  <<<DD_ETH_PORT_7_1>>>
   */
  dma_status_reg = synopGMACReadReg((uint32_t *)ETH_BASE, DmaStatus);

  if(dma_status_reg == 0)
  {
    DBG002_ERROR(APP_GID, ETH_NO_INTERRUPT, 0, NULL);
    return;
  }

  /* Disable all interrupts */
  synopGMAC_disable_interrupt_all(synopGMACdev);

  if(dma_status_reg & GmacPmtIntr)
  {
    TR("Interrupt due to PMT module\n");
    synopGMAC_powerup_mac(synopGMACdev);
  }

  if(dma_status_reg & GmacMmcIntr)
  {
    TR("Interrupt due to MMC module\n");
 }

  if(dma_status_reg & GmacLineIntfIntr)
  {
    TR("Interrupt due to GMAC LINE module\n");
  }

  /* Now lets handle the DMA interrupts*/
  interrupt = synopGMAC_get_interrupt_type(synopGMACdev);

  if(interrupt & synopGMACDmaError)
  {
    /* <<<DD_ETH_PORT_7_2>>> */
    /* after soft reset, configure the MAC address to default value */
    uint8_t mac_addr0[6] = DEFAULT_MAC_ADDRESS;

    TR("Fatal Bus Error Interrupt Seen\n");

    synopGMAC_disable_dma_tx(synopGMACdev);
    synopGMAC_disable_dma_rx(synopGMACdev);

    synopGMAC_take_desc_ownership_tx(synopGMACdev);
    synopGMAC_take_desc_ownership_rx(synopGMACdev);

    synopGMAC_init_tx_rx_desc_queue(synopGMACdev);

    /* reset the DMA engine and the GMAC IP */
    synopGMAC_reset(synopGMACdev);

    synopGMAC_set_mac_addr(synopGMACdev, GmacAddr0High, GmacAddr0Low, mac_addr0);

    synopGMAC_dma_bus_mode_init(synopGMACdev, DmaFixedBurstEnable|
    		                    DmaBurstLength8 | DmaDescriptorSkip2 );

    synopGMAC_dma_control_init(synopGMACdev, DmaStoreAndForward);

    synopGMAC_init_rx_desc_base(synopGMACdev);

    synopGMAC_init_tx_desc_base(synopGMACdev);

    synopGMAC_mac_init(synopGMACdev);

    /* To enable Multicast */
    synopGMAC_multicast_enable(synopGMACdev);

    synopGMAC_multicast_hash_filter_enable(synopGMACdev);
   /* To enable Broadcast */
    synopGMAC_broadcast_enable(synopGMACdev);

    synopGMAC_enable_dma_rx(synopGMACdev);

    synopGMAC_enable_dma_tx(synopGMACdev);
  }

  if(interrupt & synopGMACDmaRxNormal)
  {
    TR("Rx Normal \n");

    /* <<<DD_ETH_PORT_7_3>>>
     * Send the packet to the TCP/IP stack.
     * This receive function retrieves packet from descriptor and delivers to
     * the TCP/IP stack.
     */
    Eth_ReceiveData();
  }

  if(interrupt & synopGMACDmaRxAbnormal)
  {
    TR("Abnormal Rx Interrupt Seen\n");

    if(GMAC_Power_down == 0)
    {
      /* If Mac is not in powerdown */
      synopGMACdev->NetStatistics.RxOverErrors++;

      /* Now Descriptors have been created in synop_handle_received_data(). 
       * Just issue a poll demand to resume DMA operation
       */
      synopGMAC_resume_dma_rx(synopGMACdev);
    }
  }

  if(interrupt & synopGMACDmaRxStopped)
  {
    /* <<<DD_ETH_PORT_7_4>>> */
	  uint32_t DescCount = 0;

	  /* Receiver gone in to stopped state */
    TR("Receiver stopped seeing Rx interrupts\n");

    if(GMAC_Power_down == 0)
    {
      /* If Mac is not in powerdown */
      synopGMACdev->NetStatistics.RxOverErrors++;
      do
      {
          /* Set Rx Q Pointer */
          status = synopGMAC_set_rx_qptr(synopGMACdev,
        		                 (uint32_t)&Eth_RxBuffer[DescCount * ETH_PACKET_SIZE],
              		             ETH_PACKET_SIZE,
              		             (uint32_t)&Eth_RxBuffer[DescCount * ETH_PACKET_SIZE],
              		             0,0,0);

          //TR("Set Rx Descriptor no %08x \n",status);

          DescCount++;
      }while(status >= 0 && (DescCount < TRANSMIT_DESC_SIZE));

      synopGMAC_enable_dma_rx(synopGMACdev);
    }
  }

  if(interrupt & synopGMACDmaTxNormal)
  {
    //xmit function has done its job
    TR("Finished Normal Transmission \n");

    /* Call function to update statistics. */
    synop_handle_transmit_over(synopGMACdev);
  }

  if(interrupt & synopGMACDmaTxAbnormal)
  {
    TR("Abnormal Tx Interrupt Seen\n");

    if(GMAC_Power_down == 0)
    {
      /* If Mac is not in powerdown */
      synop_handle_transmit_over(synopGMACdev);
    }
  }

  if(interrupt & synopGMACDmaTxStopped)
  {
    /* <<<DD_ETH_PORT_7_5>>> */
    TR("Transmitter stopped sending the packets\n");

    if(GMAC_Power_down == 0)
    {
      /* If Mac is not in powerdown */
      synopGMAC_disable_dma_tx(synopGMACdev);

      synopGMAC_take_desc_ownership_tx(synopGMACdev);

      synopGMAC_enable_dma_tx(synopGMACdev);

      TR("Transmission Resumed\n");
    }
  }

  /* Enable the Interrupts before returning from ISR */
  synopGMAC_enable_interrupt(synopGMACdev, DmaIntEnable);

  return;
}

status_t Eth_PerformIoctl(uint32_t Cmd, Eth_IoctlParamType *Eth_IoctlParam)
{
  /* <<<DD_ETH_PORT_8_1>>> */
  uint32_t Status = ETH_IOCTL_ERROR;

  do
  {
    if(NULL == Eth_IoctlParam)
    {
      DBG002_ERROR(APP_GID, ETH_NULL_PARAM, 0, NULL);
      break;
    }

    /* Check the command and take action */
    switch(Cmd)
    {
      case IOCTL_READ_REGISTER:
      {
        /* <<<DD_ETH_PORT_8_2>>> */
        /** IOCTL for reading IP registers : Read Registers */
        if (Eth_IoctlParam->Unit== 0)
        {
          /* Read Mac Register */
          Eth_IoctlParam->Data = synopGMACReadReg((uint32_t *)ETH0_BASE,
                                                  Eth_IoctlParam->Address);
        }
        else if (Eth_IoctlParam->Unit == 1)
        {
          /* Read DMA Register */
          Eth_IoctlParam->Data = synopGMACReadReg((uint32_t *)ETH_BASE,
                                                  Eth_IoctlParam->Address);
        }
        Status  = DAVEApp_SUCCESS;
        break;
      }

      case IOCTL_WRITE_REGISTER:
      {
        /* <<<DD_ETH_PORT_8_3>>> */
        /** IOCTL for writing registers : Write Registers */
        if (Eth_IoctlParam->Unit == 0)
        {
          /* Write Mac Register */
          synopGMACWriteReg((uint32_t *)ETH0_BASE,Eth_IoctlParam->Address,
              Eth_IoctlParam->Data);
        }
        else if (Eth_IoctlParam->Unit == 1)
        {
          /* Write DMA Register */
          synopGMACWriteReg((uint32_t *)ETH_BASE, Eth_IoctlParam->Address,
              Eth_IoctlParam->Data);
        }
        Status  = DAVEApp_SUCCESS;
        break;
      }

      case IOCTL_READ_IPSTRUCT:
      {
        /* <<<DD_ETH_PORT_8_4>>> */
        /** IOCTL for reading ETH0 DEVICE IP private structure */
        if (Eth_IoctlParam->Unit == 0)
        {
          memcpy((synopGMACdevice *)Eth_IoctlParam->Address,
                        synopGMACdev,
                        sizeof(synopGMACdevice));
        }
        else
        {
          TR("IOCTL_READ_IPSTRUCT failed");
        }
        Status  = DAVEApp_SUCCESS;
        break;
      }
      case IOCTL_READ_RXDESC:
      {
        /* <<<DD_ETH_PORT_8_5>>> */
        /** IOCTL for Reading Rx DMA DESCRIPTOR */ 
        memcpy((DmaDesc *)Eth_IoctlParam->Address,
				        synopGMACdev->RxDesc,
               sizeof(DmaDesc));
        Status  = DAVEApp_SUCCESS;
        break;
      }
      case IOCTL_READ_TXDESC:
      {
        /* <<<DD_ETH_PORT_8_6>>> */
        /** IOCTL for Reading Tx DMA DESCRIPTOR */
        memcpy((DmaDesc *)Eth_IoctlParam->Address,
                synopGMACdev->TxDesc,
                sizeof(DmaDesc));
        Status  = DAVEApp_SUCCESS;
        break;
      }
      case IOCTL_READ_RMON_COUNTERS:
      {
        /* <<<DD_ETH_PORT_8_7>>> */
        Eth_StructRMONCountersType *RMONCounters =
            (Eth_StructRMONCountersType *) Eth_IoctlParam->Address;

        Eth_lGetRMONCounters(RMONCounters);
        Status  = DAVEApp_SUCCESS;
        break;
      }
      case IOCTL_CHANGE_MTU:
      {
        /* <<<DD_ETH_PORT_8_8>>> */
        /** IOCTL for changing the MTU size */
        if (Eth_IoctlParam->Data > MAX_MTU_SIZE)
        {
          DBG002_ERROR(APP_GID, ETH_IOCTL_ERROR, sizeof("Invalid MTU size"), "Invalid MTU size");
          break;
        }
        synopGMAC_change_mtu(synopGMACdev, Eth_IoctlParam->Data);
        Status  = DAVEApp_SUCCESS;
        break;
      }
      case IOCTL_SET_MAC_ADDRESS:
      {
        /* <<<DD_ETH_PORT_8_9>>> */
        /** IOCTL to set MAC Address */
        synopGMAC_set_mac_address(synopGMACdev, (void *)Eth_IoctlParam->Address);
        Status  = DAVEApp_SUCCESS;
        break;
      }
      case IOCTL_GET_MAC_ADDRESS:
      {
        /* <<<DD_ETH_PORT_8_10>>> */
        /** IOCTL to get Eth MAC Address */
        memcpy((uint8_t *)Eth_IoctlParam->Address,
            synopGMACdev->MacAddress, MAC_ADDR_LEN);
        Status  = DAVEApp_SUCCESS;
        break;
      }
      case IOCTL_GET_NET_STATS:
      {
        /* <<<DD_ETH_PORT_8_11>>> */
        /** IOCTL to get network statistics */
        memcpy((void *)Eth_IoctlParam->Address, &(synopGMACdev->NetStatistics),
            sizeof(Eth_NetStatisticsType));
        Status  = DAVEApp_SUCCESS;
        break;
      }
      default:
      {
        DBG002_ERROR(APP_GID, ETH_IOCTL_ERROR, sizeof("INVALID option"),
            "INVALID option");
        break;
      }
    }
  }while(0);

  return Status;
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
static void Eth_lGetRMONCounters(Eth_StructRMONCountersType *RMONCounters)
{
  /* <<<DD_ETH_PORT_14>>> */
  RMONCounters->TXOCtetCountGB = synopGMACReadReg((uint32_t *)ETH0_BASE,
      TXFRAMECOUNTGB_OFFSET);

  RMONCounters->TxFrameCountGB = synopGMACReadReg((uint32_t *)ETH0_BASE,
      TXFRAMECOUNTGB_OFFSET);

  RMONCounters->TxBroadcastFramesG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXBROADCASTFRAMESG_OFFSET);

  RMONCounters->TxMulticastFramesG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXMULTICASTFRAMESG_OFFSET);

  RMONCounters->Tx64OctetsGB = synopGMACReadReg((uint32_t *)ETH0_BASE,
      TX64OCTETSGB_OFFSET);

  RMONCounters->Tx65To127OctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TX65TO127OCTETSGB_OFFSET);

  RMONCounters->Tx128To255OctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TX128TO255OCTETSGB_OFFSET);

  RMONCounters->Tx256To511OctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TX256TO511OCTETSGB_OFFSET);

  RMONCounters->Tx512To1023ctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TX512TO1023CTETSGB_OFFSET);

  RMONCounters->Tx1024ToMaxOctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TX1024TOMAXOCTETSGB_OFFSET);

  RMONCounters->TxUnicastFramesGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXUNICASTFRAMESGB_OFFSET);

  RMONCounters->TxMulticastFramesGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXMULTICASTFRAMESGB_OFFSET);

  RMONCounters->TxBroadcastFramesGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXBROADCASTFRAMESGB_OFFSET);

  RMONCounters->UnderFlowError =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          UNDERFLOWERROR_OFFSET);

  RMONCounters->SingleCollisionG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          SINGLECOLLISIONG_OFFSET);

  RMONCounters->MultiCollisionG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          MULTICOLLISIONG_OFFSET);

  RMONCounters->TxDeferred =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXDEFERRED_OFFSET);

  RMONCounters->TxLateCollision =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXLATECOLLISION_OFFSET);

  RMONCounters->ExcessCollision =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          EXCESSCOLLISION_OFFSET);

  RMONCounters->TxCarrierError =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXCARRIERERROR_OFFSET);

  RMONCounters->TxOctetCount =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXOCTETCOUNT_OFFSET);

  RMONCounters->TxFrameCount =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXFRAMECOUNT_OFFSET);

  RMONCounters->TxExcessDef =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXEXCESSDEF_OFFSET);

  RMONCounters->TxPauseFrames =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXPAUSEFRAMES_OFFSET);

  RMONCounters->TxVLANFrames =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          TXVLANFRAMES_OFFSET);

  RMONCounters->RxFrameCountGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXFRAMECOUNTGB_OFFSET);

  RMONCounters->RxOctetCountGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXOCTETCOUNTGB_OFFSET);

  RMONCounters->RxOctetCountG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXOCTETCOUNTG_OFFSET);

  RMONCounters->RxBroadcastFramesG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXBROADCASTFRAMESG_OFFSET);

  RMONCounters->RxMulticastFramesG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXMULTICASTFRAMESG_OFFSET);

  RMONCounters->RxCRCError =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXCRCERROR_OFFSET);

  RMONCounters->RxAlignmentError =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXALIGNMENTERROR_OFFSET);

  RMONCounters->RxRuntError =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXRUNTERROR_OFFSET);

  RMONCounters->RxJabberError =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXJABBERERROR_OFFSET);

  RMONCounters->RxUndersizeG =
            synopGMACReadReg((uint32_t *)ETH0_BASE,
            RXUNDERSIZEG_OFFSET);

  RMONCounters->RxOverSizeG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXOVERSIZEG_OFFSET);

  RMONCounters->Rx64OctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RX64OCTETSGB_OFFSET);

  RMONCounters->Rx65To127OctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RX65TO127OCTETSGB_OFFSET);

  RMONCounters->Rx127To255OctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RX127TO255OCTETSGB_OFFSET);

  RMONCounters->Rx256To511OctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RX256TO511OCTETSGB_OFFSET);

  RMONCounters->Rx512To1023OctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RX512TO1023OCTETSGB_OFFSET);

  RMONCounters->Rx1023ToMaxOctetsGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RX1023TOMAXOCTETSGB_OFFSET);

  RMONCounters->RxUnicastFramesG =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXUNICASTFRAMESG_OFFSET);

  RMONCounters->RxLengthError =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXLENGTHERROR_OFFSET);

  RMONCounters->RxOutofRangeType =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXOUTOFRANGETYPE_OFFSET);

  RMONCounters->RxPauseFrames =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXPAUSEFRAMES_OFFSET);

  RMONCounters->RxFifoOverflow =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXFIFOOVERFLOW_OFFSET);

  RMONCounters->RxVLANFrameGB =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXVLANFRAMEGB_OFFSET);

  RMONCounters->RxWatchDOGError =
      synopGMACReadReg((uint32_t *)ETH0_BASE,
          RXWATCHDOGERROR_OFFSET);
}

void synopGMAC_RegisterPeriodicTimerCallback(SynopGMACPeriodicTimerCallbackType Callback)
{
	SynopGMACPeriodicTimerCallback = Callback;
}

void synopGMAC_RegisterDeleteTimerCallback(SynopGMACDeletePeriodicTimerType Callback)
{
	SynopGMACDeletePeriodicTimer = Callback;
}

void synopGMAC_periodic_check()
{
	synopGMAC_cable_unplug_function(synopGMACdev);
}
/**
 * @}
 */
/*CODE_BLOCK_END*/



