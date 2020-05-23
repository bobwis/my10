
/* CODE_BLOCK_BEGIN[FATFS002.h]*/
/******************************************************************************
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with 
 * Infineon's microcontrollers. 
 * This file can be freely distributed within development
 * tools that are supporting such microcontrollers. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Oct 1, 2012                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials    Name                                                           **
** ---------------------------------------------------------------------------**
** SK          App Developer                                                  **
*******************************************************************************/
 


#ifndef FATFS002_H_
#define FATFS002_H_

/**
 * @file  FATFS002.h
 *
 * @App Version FATFS002 <1.0.12>
 *
 * @brief This file contains public data structures,enums and function
 *        prototypes for Fat file system App.
 *
 * 22 March 2012  v1.0.0    Initial version
 * 3 Aug 2012     v1.0.10   Cosmetic Changes.
 * 1 Oct 2012     v1.0.12   Max Logical Drives changed to 4.
 */
/*******************************************************************************
**                      INCLUDE FILES                                         **
*******************************************************************************/

#include "../../src/FATFS002/Src/ff.h"
#include "../../Inc/FATFS004/integer.h"
#include "../../Inc/FATFS004/diskio.h"
#include "ffconf.h"


/**
 * @ingroup FATFS002_publicparam
 * @{
 */
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/ 
 /**
  * Maximum Logical partitions created using the Multi-partition feature
  */
 #define FATFS002_MAX_LOGICAL_DRIVES                                 4


/*******************************************************************************
**                      ENUMERATIONS                                          **
*******************************************************************************/

/**
 * This enumerates the FAT file system error codes
 */
typedef enum FATFS002_ErrorCodeType
{
/**
 * Mutex creation failed
 */
  FATFS002_MUTEX_CREATE_FAILED = 1,
/**
 * Mutex release failed
 */  
  FATFS002_MUTEX_RELEASE_FAILED
} FATFS002_ErrorCodeType;


#if _FS_REENTRANT
/**
 * This enumerates the Mutex Availability Status. 
 */
typedef enum FATFS002_MutexStatusType
{
  /**
   * Mutex is available to use.
   */
  FATFS002_FREE = 0,
 /**
  * Mutex is busy.
  */
  FATFS002_BUSY 
} FATFS002_MutexStatusType;



/*******************************************************************************
**                      STRUCTURES                                          **
*******************************************************************************/
/**
 * This structure contains the Mutex Information like Mutex Id and the status of
 * corresponding Mutrex whether it is free or busy.
 */
typedef struct FATFS002_MutexInfoType
{
  /** Stores Mutex ID **/
  osMutexId MutexId;
  /** Status of the Mutex whether it is free or acquired. **/
  FATFS002_MutexStatusType MutexStatus;
} FATFS002_MutexInfoType;

#endif
/**
 * @}
 */
/**
 * @ingroup FATFS002_apidoc
 * @{
 */
/*******************************************************************************
**                       FUNCTION PROTOTYPES                                  **
*******************************************************************************/
/**
 * @brief This function initializes the FAT File System App.
 * @return void <BR>
 * <b>Reentrant: No </b><BR>
 * <b>Sync/Async: Synchronous</b>
 */
void FATFS002_Init(void);
/**
 * @}
 */
#endif /* FATFS002_H_ */

