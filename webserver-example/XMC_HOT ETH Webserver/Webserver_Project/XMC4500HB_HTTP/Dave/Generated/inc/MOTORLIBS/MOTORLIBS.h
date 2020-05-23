
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
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4500/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE :  29 May, 2013                                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PA           App Developer                                                 **
*******************************************************************************/
/**
 * @file MOTORLIBS.h
 *
 * @brief This file contains all public data structures,enums and function
 *        prototypes for motor control library.
 *
 */
/* Revision History
 * 03 Apr 2013   v1.0.0    Initial version
 * 25 Apr 2013   v1.0.2    Added support for XMC1302
 * 29  May 2013  v1.0.12   Added FOC support for XMC1302
 */
#ifndef MOTORLIBS_H_
#define MOTORLIBS_H_
/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include <DAVE3.h>

/**
  * @ingroup MOTORLIBS_publicparam
  * @{
  */
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/    
/*Limit1 is the higher limit and Limit2 is the lower limit and Buffer is the value which need to compare*/
#define MIN_MAX_LIMIT(Buffer,Limit1,Limit2) ((Buffer) > (Limit1)) ? (Limit1) : (((Buffer) < (Limit2))? (Limit2): (Buffer))

/*******************************************************************************
 *                                ENUMERATIONS                                **
 ******************************************************************************/

/*******************************************************************************
 *                             STRUCTURES                                     **
 ******************************************************************************/
/**
 * This structure holds the values of PI parameters.
 */
typedef struct MOTORLIBS_PIHandleType
{
  /**
   * This is the Kp value
   */
  uint16_t  Kp;  
 /**
  * This is the Ki value
  */
  uint16_t  Ki; 
 /**
  * This is the buffer
  */
  int32_t  Ibuf; 
  /**
   * Maximum limit for buffer
   */
  const int32_t  Yimax;    
  /**
   * Minimum limit for buffer
   */
  const int32_t  Yimin; 
  /**
   * Maximum limit for PI controller output
   */
  const int16_t  Ymax;     
  /**
   * Minimum limit for PI controller output
   */
  const int16_t  Ymin; 
  /**
   * This is the required output value for PI controller
   */  
  int16_t PiOutVal;
  
} MOTORLIBS_PIHandleType;
 
/**
 * This structure holds the values of PT1 filter parameters.
 */
typedef struct MOTORLIBS_PT1HandleType
{
  /**
   * Filter constant 
   */
  int32_t  Z1;
  /**
   * Filter constant 
   */
  int32_t  Z2;
  /**
   * Maximum limit of PT1 buffer
   */
  const int32_t  Ymax;
  /**
   * Minimum limit of PT1 buffer
   */
  const int32_t  Ymin;
  /**
   * This is the integral buffer of pt1 filter
   */
  int32_t  PT1buf;
  /**
   * This is PT1 filter output.
   */
  int32_t  PT1OutVal;
  
} MOTORLIBS_PT1HandleType;
 
/**
 * @}
 */
/**
 * @ingroup MOTORLIBS_apidoc
 * @{
 */
/*******************************************************************************
 **FUNCTION PROTOTYPES                                                        **
*******************************************************************************/
/**
  * @brief This function is the implementation of PI controller. 
  * PI Output = kp*error + Ki * integral of error
  * @param[in] HandlePtr Pointer to MOTORLIBS_PIHandleType
  * @param[in] RefValue int32_t which is reference value for PI controller
  * @param[in] ActValue int32_t which is actual value for PI controller
  * 
  * @return   void <BR>
  *         
  *         
  * <b>Reentrancy:  Yes</b><BR>
  * 
  * <b>Sync/Async:  Synchronous</b><BR>
  */
void MOTORLIBS_PIController
(
    MOTORLIBS_PIHandleType* HandlePtr,
    int32_t RefValue,
    int32_t ActValue
);

/**
  * @brief This function is the implementation of PT1 filter. 
  * @param[in] HandlePtr PT1 Handle of the MOTORLIBS App
  * @param[in] ActValue int32_t which is actual value for PT1 filter
  * 
  * @return  void <BR>
  *         
  *         
  * <b>Reentrancy:  Yes</b><BR>
  * 
  * <b>Sync/Async:  Synchronous</b><BR>
  */
void MOTORLIBS_PT1Controller
(
   MOTORLIBS_PT1HandleType* HandlePtr,
   int32_t ActValue
);
/**
 * @}
 */
#endif /* MOTORLIBS_H_ */





