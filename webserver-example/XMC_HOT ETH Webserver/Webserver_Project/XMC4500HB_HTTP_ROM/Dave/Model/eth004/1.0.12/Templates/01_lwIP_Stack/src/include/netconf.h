/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2011)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
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
** MODIFICATION DATE : Dec 29, 2011                                           **
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

/**
 * @file netconf.h
 *
 * @brief  This file is a template file demonstrating various file sections.
 *
 */

#ifndef NETCONF_H_
#define NETCONF_H_
#include "types.h"
/* TODO. Update */
#define GID_LWIP 0x20

/**
 * @addtogroup lwIP_publicparam
 * @{
 */

/**
 * lwIP Error types and message types
 */
typedef enum lwIP_ErrorType
{
  /**
   * lwIP Stack Initialization failed
   */
  lwIP_INIT_ERROR = 1,
  /**
   * lwIP Stack UnInitialization failed
   */
  lwIP_UNINIT_ERROR,
  /*
   * NULL Input Parameter
   */
  lwIP_NULL_PARAM,
  /*
   * No space for memory
   */
  lwIP_OUT_OF_MEM,
  /**
   * lwIP MBOX ERROR
   */
  lwIP_MBOX_ERROR,
  /**
   * lwip Message
   */
  lwIP_INFO_MSG,
}lwIP_ErrorType;

/**
 * @}
 */

/**
 * @addtogroup lwIP_apidoc
 * @{
 */

/**
  * @brief
  * Syntax: status_t lwIPStack_init(void);
  *
  * Service ID:  0x1
  *
  * <b>Sync/Async:  Synchronous </b>
  *
  * <b>Reentrant:  No </b><BR>
  *
  * Description: Initializes the lwIP stack
  * @retval DAVEApp_SUCCESS on success or error code
  */
status_t lwIPStack_init(void);

/**
 * @brief
 * Syntax: status_t lwIPStack_init(void);
 *
 * Service ID:  0x2
 *
 * <b>Sync/Async:  Synchronous</b>
 *
 * <b>Reentrant:  No</b> <BR>
 *
 * Description: The function de-initializes the lwIP stack
 *
 *
 * @return DAVEApp_SUCCESS on success error code otherwise
 */
status_t lwIPStack_UnInit (void);

/**
 * @}
 */

#endif /* NETCONF_H_ */
