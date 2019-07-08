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
** JRP          DAVE App Developer                                            **
*******************************************************************************/
/** \file
 * This file is the header file for ETH001 App
 * of ETH001 App.
 * 
 * \internal
 * ------------------------REVISION HISTORY--------------------------------------
 * Infineon                 12/Dec/2012                   Base line from 
 *                                                        version v1.0.14
 *                                                        dbg002 related macros are added
 */

#ifndef ETH001_H
#define ETH001_H
#include "ETH001_Conf.h"
#include "synopGMAC_plat.h"
#include "synopGMAC_stack_interface.h"
#include "SynopGMAC_Dev.h"
#include "synopGMAC_network_interface.h"
#include <stdlib.h>
#include <string.h>

void lwip_Input(unsigned char *PacketBuffer, uint32_t PacketLength);
/**
 * @addtogroup Ethernet_apidoc
 * @{
 */
/**
 * @brief
 * Syntax : void Eth_Received_Data_Handler
 * (
 * 		uint32_t PacketBuffer,
 * 		uint32_t PacketLength
 * )
 *
 * Service ID:  0x01
 *
 * <b>Sync/Async:  Synchronous</b>
 *
 * <b>Reentrant: YES </b><BR>
 *
 * Description: Eth_Received_Data_Handler function is used to handle the
 * packet received from the interface. This function should be defined
 * by the user for handling the received packet. Below code snippet demonstrates the usage of
 * Eth_Received_Data_Handler.
 *
 * Note: This function runs in interrupt context.
 *
 * @return void
 * @code
 * #include "DAVE3.h"
 * int main(void)
 * {
 *    status_t Status = DAVEApp_SUCCESS;
 *    DAVE_Init();
 *    Status = Eth_InitNetworkInterface();
 *    if(Status != DAVEApp_SUCCESS)
 *    {
 *      DBG002_ERROR(APP_GID, ETH_INIT_ERROR, 0, NULL);
 *    }
 *
 *    Status = Eth_OpenNetworkInterface();
 *    if (Status != DAVEApp_SUCCESS)
 *    {
 *      DBG002_ERROR(APP_GID, ETH_INIT_ERROR, 0, NULL);
 *    }
 *
 *  while(1) {}
 *  return 0;
 * }
 *
 * void Eth_Received_Data_Handler(uint32_t PacketBuffer, uint32_t PacketLength)
 * {
 *   // Definition needs to be provided by the user for handling the received packet
 * }
 * @endcode<BR> </p>
 */
void Eth_Received_Data_Handler(uint32_t PacketBuffer, uint32_t PacketLength);
/**
 *@}
 */

#endif /*ETH001_H*/

