
/*CODE_BLOCK_BEGIN[MOTORLIBS.c]*/
/*******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
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
** MODIFICATION DATE : 29 May, 2013                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PA           Dave App Developer                                            **
**                                                                            **
*******************************************************************************/
/**
 * @file  MOTORLIBS.c
 *
 * @brief This file contains implementations of all Public and Private functions
 *        of Motor control library.
 *
 */
 /* Revision History
 * 03 Apr 2013   v1.0.0    Initial version
 * 25 Apr 2013   v1.0.2    Added support for XMC1302
 * 29  May 2013  v1.0.12   Added FOC support for XMC1302
 */ 
/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include <DAVE3.h>
#include "../../inc/MOTORLIBS/MOTORLIBS.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/**
 * @cond INTERNAL_DOCS
 */
/**
  * @ingroup MOTORLIBS_privatefunc
  * @{
  */
#ifdef USE_MOTORLIBS  
/*****************************************************************************
**                      Private Type Definitions                            **
******************************************************************************/
/*****************************************************************************
 *                 Private Function declarations                             *
 *****************************************************************************/
/**
 * @}
 */
/*******************************************************************************
**                      Imported Global Variables                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/

/**
 * This function is the implementation of PI controller. 
 * PIOutput= kp*error + Ki * integral of error
 */
void MOTORLIBS_PIController
(
    MOTORLIBS_PIHandleType* HdlPtr,
    int32_t RefValue,
    int32_t ActValue
)
{
  int32_t Output=0;
  /* yn(k+1)= yn(k)   + ki * e(k) */
  HdlPtr->Ibuf += (int32_t) ((int32_t)HdlPtr->Ki) * (RefValue-ActValue);

  /* Checking the buffer limits in the range of Yimin to Yimax */
  HdlPtr->Ibuf = MIN_MAX_LIMIT(((int32_t)HdlPtr->Ibuf),((int32_t)HdlPtr->Yimax),((int32_t)HdlPtr->Yimin));            

  /* y(k+1) = yn(k+1) + kp * e(k) * 64 */
  Output=  ((int32_t) ((int32_t)HdlPtr->Kp) * (RefValue-ActValue));

  Output  =  (HdlPtr->Ibuf>>15) +(Output>>9);
  
  /* Checking the buffer limits in the range of Ymin to Ymax */
  HdlPtr->PiOutVal= MIN_MAX_LIMIT(((int32_t)(Output)),((int32_t)HdlPtr->Ymax),((int32_t)HdlPtr->Ymin));

}
/**
 * This function is the implementation of PT1 filter. 
 */
void MOTORLIBS_PT1Controller
(
   MOTORLIBS_PT1HandleType* HdlPtr,
   int32_t ActValue
)
{
  int32_t TempBuff;
  /* yn+1=yn + z1*(x - yn) */
  TempBuff = HdlPtr->PT1buf + HdlPtr->Z1*(ActValue - (HdlPtr->PT1buf>>16));
  /* Checking the buffer limits in the range of Ymin to Ymax */
  HdlPtr->PT1buf = MIN_MAX_LIMIT((TempBuff),(HdlPtr->Ymax),(HdlPtr->Ymin));
  HdlPtr->PT1OutVal = (HdlPtr->PT1buf>>16);
}


#endif 

/**
 * @endcond
 */
/*CODE_BLOCK_END*/

