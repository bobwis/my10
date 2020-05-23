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
** MODIFICATION DATE : Dec 12, 2012                                           **
**                                                                            **
*******************************************************************************/
 
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** JRP        DAVE App Developer                                              **
*******************************************************************************/
/**\file
 *  This file for stack interface
 *
 * \internal
 * -------------------------------------REVISION HISTORY---------------------------
 * Infineon 				12/Dec/2012		 	   Base line from version v1.0.14
 *                                                 dbg002 related macros are added   
 * 
 */ 
#ifndef SYNOPGMAC_STACK_INTERFACE_H_
#define SYNOPGMAC_STACK_INTERFACE_H_

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
#include <DAVE3.h>

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/**
 * @addtogroup Ethernet_publicparam
 * @{
 */
/** This should be in sync with lwIP stack */
#define MAX_MTU_SIZE 1500

/** List of Ethernet IOCTL Codes*/
typedef enum Eth_IOCTLType
{
  /**
   * IOCTL code to read register
   */
  IOCTL_READ_REGISTER,

  /**
   * IOCTL code to write into register
   */
  IOCTL_WRITE_REGISTER,

  /**
   * IOCTL code to read device specific structure
   */
  IOCTL_READ_IPSTRUCT,

  /**
   * IOCTL code to read receive descriptor
   */
  IOCTL_READ_RXDESC,

  /**
   * IOCTL code to read transmit descriptor
   */
  IOCTL_READ_TXDESC,

  /**
   * IOCTL code to read RMON Counters
   */
  IOCTL_READ_RMON_COUNTERS,

  /**
   * IOCTL code to change MTU size
   */
  IOCTL_CHANGE_MTU,

  /**
   * IOCTL code to set MAC Address
   */
  IOCTL_SET_MAC_ADDRESS,

  /**
   * IOCTL code to get MAC Address
   */
  IOCTL_GET_MAC_ADDRESS,

  /**
   * IOCTL code to get network statistics
   */
  IOCTL_GET_NET_STATS,
}Eth_IOCTLType;

/**
 * Error enumeration for Ethernet LLD
 */
typedef enum ETH_ERRORType
{
  /**
   * Ethernet Initialization failed
   */
  /**
   * @cond INTERNAL_DOCS
   * @param MODULENAME ETH001
   * @endcond
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING1 ETH_INIT_ERROR
   * @param STRCODESTRING1 Ethernet Initialization failed
   * @endcond
   */
  ETH_INIT_ERROR = 1,
  /**
   * Ethernet Open call failed
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING2 ETH_OPEN_ERROR
   * @param STRCODESTRING2 Ethernet Open call failed
   * @endcond
   */
  ETH_OPEN_ERROR,
  /**
   * Ethernet Close call failed
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING3 ETH_CLOSE_ERROR
   * @param STRCODESTRING3 Ethernet Close call failed
   * @endcond
   */
  ETH_CLOSE_ERROR,
  /**
   * Ethernet Packet Transmit failed
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING4 ETH_XMIT_ERROR
   * @param STRCODESTRING4 Ethernet Packet Transmit failed
   * @endcond
   */
  ETH_XMIT_ERROR,
  /**
   * Ethernet Packet Receive failed
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING5 ETH_RECV_ERROR
   * @param STRCODESTRING5 Ethernet Packet Receive failed
   * @endcond
   */
  ETH_RECV_ERROR,
  /**
   * Ethernet IOCTL failed
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING6 ETH_IOCTL_ERROR
   * @param STRCODESTRING6 Ethernet IOCTL failed
   * @endcond
   */
  ETH_IOCTL_ERROR,
  /**
   * No Ethernet Interrupt
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING7 ETH_NO_INTERRUPT
   * @param STRCODESTRING7 No Ethernet Interrupt
   * @endcond
   */
  ETH_NO_INTERRUPT,
  /**
   * Invalid MAC Address
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING8 ETH_INVALID_MAC_ADDR
   * @param STRCODESTRING8 Invalid MAC Address
   * @endcond
   */
  ETH_INVALID_MAC_ADDR,
  /**
   * NULL input parameter
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING9 ETH_NULL_PARAM
   * @param STRCODESTRING9 NULL input parameter
   * @endcond
   */
  ETH_NULL_PARAM,
  /**
   * Error Setting up Tx Desc
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING10 ETH_TX_SETUP_ERROR
   * @param STRCODESTRING10 Error Setting up Tx Desc
   * @endcond
   */
  ETH_TX_SETUP_ERROR,
  /**
   * Ethernet Init successful
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING11 ETH_INIT_SUCCESS
   * @param STRCODESTRING11 Ethernet Init successful
   * @endcond
   */
  ETH_INIT_SUCCESS,
  /**
   * Exit from Ethernet Interface
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING12 ETH_EXIT_SUCCESS
   * @param STRCODESTRING12 Exit from Ethernet Interface
   * @endcond
   */
  ETH_EXIT_SUCCESS,
  /**
   * Setup RX Q Descriptors
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING13 ETH_SETUP_RX_DESC
   * @param STRCODESTRING13 Setup RX Q Descriptors
   * @endcond
   */
  ETH_SETUP_RX_DESC,
  /**
   * Setup TX Q Descriptors
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING14 ETH_SETUP_TX_DESC
   * @param STRCODESTRING14 Setup TX Q Descriptors
   * @endcond
   */
  ETH_SETUP_TX_DESC,
  /**
   * The synopGMAC interrupt has been disabled
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING15 ETH_INTR_DISABLED
   * @param STRCODESTRING15 The synopGMAC interrupt has been disabled
   * @endcond
   */
  ETH_INTR_DISABLED,
  /**
   * Ethernet Rx is disabled
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING16 ETH_RX_DISABLED
   * @param STRCODESTRING16 Ethernet Rx is disabled
   * @endcond
   */
  ETH_RX_DISABLED,
  /**
   * Ethernet Tx is disabled
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING17 ETH_TX_DISABLED
   * @param STRCODESTRING17 Ethernet Tx is disabled
   * @endcond
   */
   ETH_TX_DISABLED,
  /**
   * Synopsys driver related messages
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING18 ETH_SYNOPSYS_MSG
   * @param STRCODESTRING18 Synopsys driver related messages
   * @endcond
   */
  ETH_SYNOPSYS_MSG,
}ETH_ERRORType;

/**
 * This data structure is used for sharing the RMON counters with Application
 */

typedef struct Eth_StructRMONCountersType{
  /**
   * Number of bytes transmitted, exclusive of preamble and retried bytes,
   * in good and bad frames.
   */
  uint32_t TXOCtetCountGB;
  /**
   * Number of good and bad frames transmitted, exclusive of retried frames
   */
  uint32_t TxFrameCountGB;
  /**
   * Number of good broadcast frames transmitted.
   */
  uint32_t TxBroadcastFramesG;
  /**
   * Number of good multicast frames transmitted.
   */
  uint32_t TxMulticastFramesG;
  /**
   * Number of good and bad frames transmitted with length 64 bytes, exclusive
   * of preamble and retried frames.
   */
  uint32_t Tx64OctetsGB;
  /**
   * Number of good and bad frames transmitted with length between 65 and 127
   * (inclusive) bytes, exclusive of preamble and retried frames.
   */
  uint32_t Tx65To127OctetsGB;
  /**
   * Number of good and bad frames transmitted with length between 128 and 255
   * (inclusive) bytes, exclusive of preamble and retried frames.
   */
  uint32_t Tx128To255OctetsGB;
  /**
   * Number of good and bad frames transmitted with length between 256 and 511
   * (inclusive) bytes, exclusive of preamble and retried frames.
   */
  uint32_t Tx256To511OctetsGB;
  /**
   * Number of good and bad frames transmitted with length between 512 and 1.023
   * (inclusive) bytes, exclusive of preamble and retried frames.
   */
  uint32_t Tx512To1023ctetsGB;
  /**
   * Number of good and bad frames transmitted with length between 1.024 and maxsize
   * (inclusive) bytes, exclusive of preamble and retried frames.
   */
  uint32_t Tx1024ToMaxOctetsGB;
  /**
   * Number of good and bad unicast frames transmitted.
   */
  uint32_t TxUnicastFramesGB;
  /**
   * Number of good and bad multicast frames transmitted.
   */
  uint32_t TxMulticastFramesGB;
  /**
   * Number of good and bad broadcast frames transmitted.
   */
  uint32_t TxBroadcastFramesGB;
  /**
   * Number of frames aborted due to frame underflow error.
   */
  uint32_t UnderFlowError;
  /**
   * Number of successfully transmitted frames after a single collision in Half-
   * duplex mode.
   */
  uint32_t SingleCollisionG;
  /**
   * Number of successfully transmitted frames after more than a single collision in
   * Halfduplex mode.
   */
  uint32_t MultiCollisionG;
  /**
   * Number of successfully transmitted frames after a deferral in Half-duplex mode.
   */
  uint32_t TxDeferred;
  /**
   * Number of frames aborted due to late collision error.
   */
  uint32_t TxLateCollision;
  /**
   * Number of frames aborted due to excessive (16) collision errors.
   */
  uint32_t ExcessCollision;
  /**
   * Number of frames aborted due to carrier sense error (no carrier or loss of
   * carrier).
   */
  uint32_t TxCarrierError;
  /**
   * Number of bytes transmitted, exclusive of preamble, in good frames only.
   */
  uint32_t TxOctetCount;
  /**
   * Number of good frames transmitted.
   */
  uint32_t TxFrameCount;
  /**
   * Number of frames aborted due to excessive deferral error (deferred for more
   * than two max-sized frame times).
   */
  uint32_t TxExcessDef;
  /**
   * Number of good PAUSE frames transmitted.
   */
  uint32_t TxPauseFrames;
  /**
   * Number of good VLAN frames transmitted, exclusive of retried frames.
   */
  uint32_t TxVLANFrames;
  /**
   * Number of good and bad frames received
   */
  uint32_t RxFrameCountGB;
  /**
   * Number of bytes received, exclusive of preamble, in good and bad frames.
   */
  uint32_t RxOctetCountGB;
  /**
   * Number of bytes received, exclusive of preamble, only in good frames.
   */
  uint32_t RxOctetCountG;
  /**
   * Number of good broadcast frames received.
   */
  uint32_t RxBroadcastFramesG;
  /**
   * Number of good multicast frames received.
   */
  uint32_t RxMulticastFramesG;
  /**
   * Number of frames received with CRC error.
   */
  uint32_t RxCRCError;
  /**
   * Number of frames received with alignment (dribble) error. Valid only in
   * 10/100 mode.
   */
  uint32_t RxAlignmentError;
  /**
   * Number of frames received with runt (<64 bytes and CRC error) error.
   */
  uint32_t RxRuntError;
  /**
   * Number of giant frames received with length (including CRC) greater than
   * 1.518 bytes (1.522 bytes for VLAN tagged) and with CRC error. If Jumbo
   * Frame mode is enabled, then frames of length greater than 9,018 bytes
   * (9,022 for VLAN tagged) are considered as giant frames.
   */
  uint32_t RxJabberError;
  /**
   * Number of frames received with length less than 64 bytes, without any
   * errors.
   */
  uint32_t RxUndersizeG;
  /**
   * Number of frames received with length greater than the maxsize
   * (1.518 or 1.522 for VLAN tagged frames), without errors.
   */
  uint32_t RxOverSizeG;
  /**
   * Number of good and bad frames received with length 64 bytes, exclusive of
   * preamble.
   */
  uint32_t Rx64OctetsGB;
  /**
   * Number of good and bad frames received with length between 65 and 127
   * (inclusive) bytes, exclusive of preamble.
   */
  uint32_t Rx65To127OctetsGB;
  /**
   * Number of good and bad frames received with length between 128 and 255
   * (inclusive) bytes, exclusive of preamble.
   */
  uint32_t Rx127To255OctetsGB;
  /**
   * Number of good and bad frames received with length between 256 and 511
   * (inclusive) bytes, exclusive of preamble.
   */
  uint32_t Rx256To511OctetsGB;
  /**
   * Number of good and bad frames received with length between 512 and 1.023
   * (inclusive) bytes, exclusive of preamble.
   */
  uint32_t Rx512To1023OctetsGB;
  /**
   * Number of good and bad frames received with length between 1.024 and
   * maxsize (inclusive) bytes, exclusive of preamble and retried frames.
   */
  uint32_t Rx1023ToMaxOctetsGB;
  /**
   * Number of good unicast frames received.
   */
  uint32_t RxUnicastFramesG;
  /**
   * Number of frames received with length error (Length type field ¼ frame
   * size), for all frames with valid length field.
   */
  uint32_t RxLengthError;
  /**
   * Number of frames received with length field not equal to the valid frame
   * size (greater than 1.500 but less than 1.536).
   */
  uint32_t RxOutofRangeType;
  /**
   * Number of good and valid PAUSE frames received.
   */
  uint32_t RxPauseFrames;
  /**
   * Number of missed received frames due to FIFO overflow. This counter is not
   * present in the GMAC-CORE configuration.
   */
  uint32_t RxFifoOverflow;
  /**
   * Number of good and bad VLAN frames received.
   */
  uint32_t RxVLANFrameGB;
  /**
   * Number of frames received with error due to watchdog timeout error
   * (frames with a data load larger than 2.048 bytes).
   */
  uint32_t RxWatchDOGError;
} Eth_StructRMONCountersType;

/**
 * Data structure used for Ethernet IOCTL
 */

typedef struct Eth_IoctlParamType{
  /**
   * Unit (MAC Register/ DMA register)
   */
  uint32_t Unit;
  /**
   * Register Address (Offset)
   */
  uint32_t Address;
  /**
   * Data to be set or returned.
   */
  uint32_t Data;
}Eth_IoctlParamType;

/**
 * Data structure containing network statistics. The Ethernet LLD gathers these
 * statistics during the network operations.
 */
typedef struct Eth_NetStatisticsType
{
  /**
   * Total packets received
   */
  uint32_t RxPackets;
  /**
   * Total packets transmitted
   */
  uint32_t TxPackets;
  /**
   * Total bytes received
   */
  uint32_t RxBytes;
  /**
   * Total bytes transmitted
   */
  uint32_t TxBytes;
  /**
   * bad packets received
   */
  uint32_t RxErrors;
  /**
   * packet transmit problems
   */
  uint32_t TxErrors;
  /**
   * no space for rx buffers
   */
  uint32_t RxDropped;
  /**
   *  no space for tx buffers
   */
  uint32_t TxDropped;
  /**
   * multicast packets received
   */
  uint32_t MulticastPackets;
  /**
   * Number of collisions.
   */
  uint32_t Collisions;
  /**
   * Rx Packet length error
   */
  uint32_t RxLengthErrors;
  /**
   * Receiver ring buffer overflow
   */
  uint32_t RxOverErrors;
  /**
   * Received packet with CRC error
   */
  uint32_t RxCrcErrors;
  /**
   * Received frame alignment error
   */
  uint32_t RxFrameErrors;
  /**
   * Receiver FIFO overrun
   */
  uint32_t RxFifoErrors;
  /**
   * Receiver missed packet
   */
  uint32_t RxMissedErrors;
  /**
   * Number of times Tx was aborted.
   */
  uint32_t TxAbortedErrors;
  /**
   * Number of Tx carrier errors.
   */
  uint32_t TxCarrierErrors;
  /**
   * Number of Tx FIFO errors.
   */
  uint32_t TxFIFOErrors;
  /**
   * Number of Tx heartbeat errors.
   */
  uint32_t TxHeartbeatErrors;
  /**
   * Number of Tx window errors
   */
  uint32_t TxWindowErrors;
}Eth_NetStatisticsType;

/**
 * @}
 */


/*******************************************************************************
** FUNCTION PROTOTYPES                                                        **
*******************************************************************************/

/**
 * @addtogroup Ethernet_apidoc
 * @{
 */

/**
 * @brief
 * Syntax : status_t Eth_InitNetworkInterface(void)
 *
 * Service ID:  0x01
 *
 * <b>Sync/Async:  Synchronous</b>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * Description: Function to initialize the network interface.
 *
 *
 * @return Returns  on success and Error code on failure.
 */
/**
* @code
*  #include "DAVE3.h"
*  int main(void)
*  {
*      status_t Status = DAVEApp_SUCCESS;
*      DAVE_Init();
*      Status = Eth_InitNetworkInterface();
*	   if(Status != DAVEApp_SUCCESS)
*	   {
*	       DBG002_ERROR(APP_GID, ETH_INIT_ERROR, 0, NULL);
*	   }
*  }
* @endcode<BR> </p>
*/
status_t Eth_InitNetworkInterface (void);

/**
 * @brief
 * Syntax : void Eth_ExitNetworkInterface(void)
 *
 * Service ID:  0x02
 *
 * <b>Sync/Async:  Synchronous</b>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * Description: Function to de-initialize the network interface.
 *
 * @return    None
 */
/**
* @code
*  #include "DAVE3.h"
*  int main(void)
*  {
*      DAVE_Init();
*      Eth_ExitNetworkInterface();
*  }
* @endcode<BR> </p>
*/
void Eth_ExitNetworkInterface(void);

/**
 * @brief
 * Syntax : status_t Eth_OpenNetworkInterface (void)
 *
 * Service ID:  0x03
 *
 * <b>Sync/Async:  Synchronous</b>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * Description: Function used to open the interface for use.
 * Basically this function prepares the device for operation.
 * This function registers system resources needed
 *   - Attaches device to device specific structure
 *   - Programs the MDC clock for PHY configuration
 *   - Check and initialize the PHY interface
 *   - Setup and initialize Tx and Rx descriptors
 *   - Initialize MAC and DMA
 *   - Allocate Memory for RX descriptors
 *   - Initialize one second timer to detect cable plug/unplug
 *   - Configure and Enable Interrupts
 *   - Enable Tx and Rx
 *
 *
 * @return Returns DAVEApp_SUCCESS on success and error status upon failure.
 *
 */
/**
* @code
*  #include "DAVE3.h"
*  int main(void)
*  {
*      status_t Status = DAVEApp_SUCCESS;
*      DAVE_Init();
*      Status = Eth_InitNetworkInterface();
*	   if(Status != DAVEApp_SUCCESS)
*	   {
*	       DBG002_ERROR(APP_GID, ETH_INIT_ERROR, 0, NULL);
*	   }
*      
*      Status = Eth_OpenNetworkInterface();
*      if (Status != DAVEApp_SUCCESS)
*      {
*          DBG002_ERROR(APP_GID, ETH_INIT_ERROR, 0, NULL);
*      }
* }
* @endcode<BR> </p>
*/
status_t Eth_OpenNetworkInterface (void);


/**
 * @brief
 * Syntax : status_t Eth_CloseNetworkInterface (void)
 *
 * Service ID:  0x04
 *
 * <b>Sync/Async:  Synchronous</b>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * Description: Function used when the interface is closed.
 * This releases all the system resources allocated during open call.
 * system resources int needs
 *   - Disable the device interrupts
 *   - Stop the receiver and get back all the rx descriptors from the Eth DMA
 *   - Stop the transmitter and get back all the tx descriptors from the Eth DMA
 *   - Release the TX and RX descripor memory
 *   - De-initialize one second timer registered for cable plug/unplug tracking
 *
 *
 * @return Returns DAVEApp_SUCCESS on success and error status upon failure.
 *
 */
/**
* @code
*  #include "DAVE3.h"
*  int main(void)
*  {
*      typedef enum lwIP_ErrorType
*      {
*	       lwIP_UNINIT_ERROR,
*      }lwIP_ErrorType;
*      status_t Status = ETH_CLOSE_ERROR;
*      DAVE_Init();
*      Status = Eth_CloseNetworkInterface();
*      if (Status != DAVEApp_SUCCESS)
*      {
*	       DBG002_WARNING(APP_GID, ETH_CLOSE_ERROR, 0, NULL);
*      }
*  }
* @endcode<BR> </p>
*/
status_t Eth_CloseNetworkInterface (void);

/**
 * @brief
 *
 * Syntax : status_t Eth_TransmitFrames
 * (
 *   unsigned char *PacketBuffer,
 *   uint32_t PacketLength
 * )
 *
 * Service ID:  0x06
 *
 * <b>Sync/Async:  Synchronous</b>
 *
 * <b>Reentrant: YES </b><BR>
 *
 * Description: Function to transmit a given packet on the wire.
 * Whenever TCP/IP stack has a packet ready to be transmitted, this function
 * is called. The function prepares a packet and prepares the descriptor and
 * enables/resumes the transmission.
 *
 * @param[in] PacketBuffer pointer to the packet buffer.
 * @param[in] PacketLength Length of the packet.
 *
 * @return Returns DAVEApp_SUCCESS on success and Error code on failure.
 *
 */
/**
* @code
*  #include "DAVE3.h"
*  int main(void)
*  {
*      typedef enum lwIP_ErrorType
*      {
*          lwIP_UNINIT_ERROR,
*      }lwIP_ErrorType;
*      status_t Status = ETH_XMIT_ERROR;
*      uint32_t TxLength = 0;
* 	   uint8_t *GetBuffer = 0;
*      
*      DAVE_Init();
*      Status = Eth_TransmitFrames(GetBuffer, TxLength);
*      if (Status != DAVEApp_SUCCESS)
*      {
*          DBG002_WARNING(APP_GID, ETH_XMIT_ERROR, sizeof("TX FAILE"), "TX FAILE");
*      }
*  }
* @endcode<BR> </p>
*/
status_t Eth_TransmitFrames
(
unsigned char *PacketBuffer,
uint32_t PacketLength
);

/**
 * @brief IOCTL interface.
 *
 * Syntax : status_t Eth_PerformIoctl
 * (
 *   uint32_t Cmd,
 *   Eth_IoctlParamType *Eth_IoctlParam
 * )
 *
 * Service ID:  0x07
 *
 * <b>Sync/Async:  Synchronous</b>
 *
 * <b>Reentrant: YES </b><BR>
 *
 * Description: This function is mainly for setting/getting Ethernet parameters.
 * This provides hooks for Register read write, Retrieve descriptor status
 * and Retrieving Device structure information.

 * @param[in] Cmd IOCTL command.
 * @param[in] Eth_IoctlParam Pointer to Eth_IoctlParamType structure
 *
 * @return Returns 0 on success Error code on failure.
 */
/**
* @code
*  #include "DAVE3.h"
*  int main(void)
*  {
*      status_t Status = DAVEApp_SUCCESS;
*      DAVE_Init();
* 	   Eth_IoctlParamType GetMacParams;
* 	   Status = Eth_PerformIoctl(IOCTL_GET_MAC_ADDRESS, &GetMacParams);
* 	   if(Status != DAVEApp_SUCCESS)
* 	   {
* 	       DBG002_ERROR(APP_GID, ETH_INIT_ERROR, 0, NULL);
* 	   }
*  }
* @endcode<BR> </p>
*/
status_t Eth_PerformIoctl (uint32_t Cmd, Eth_IoctlParamType *Eth_IoctlParam);
/**
 *@}
 */
#ifdef BUILD_UIP
uint32_t Eth_ReceiveData(void *buf)
#else
status_t Eth_ReceiveData(void);
#endif


#endif /* SYNOPGMAC_STACK_INTERFACE_H_ */



