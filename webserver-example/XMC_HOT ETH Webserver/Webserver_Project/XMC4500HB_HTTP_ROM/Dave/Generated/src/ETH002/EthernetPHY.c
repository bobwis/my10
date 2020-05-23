
/*CODE_BLOCK_BEGIN[EthernetPHY.c]*/
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
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Dec 12, 2012                                           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** -------------------------------------------------------------------------- **
** RS           App Developer                                                 **
**                                                                            **
*******************************************************************************/
/**
 * @file EthernetPHY.c
 *
 * @brief  This file contains Ethernet PHY Function definitions.
 *
 * Revision History
 * 12 Dec 2012  v1.0.12    Base line from version v1.0.10
 *                         dbg002 related macros are added
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
/** Inclusion of header file */
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
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* BUSY_WAIT_LOOP_COUNT max count */
#define BUSY_WAIT_LOOP_COUNT        1000U
#define CHECK_AUTO_NEGO_TIME_COUNT  100U
/* Reset delay currently ~30ms */
#define RESET_COMPLETE_WAIT_PERIOD  30U
#define PHY_REG_OPERATION_WAIT_TIME 10U
#define APP_GID                     DBG002_GID_ETH002
/**
 * @ingroup EthernetPHY_privateparam
 * @{
 */
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
static uint32_t PHY_lWriteReg(uint32_t PhyBase,uint32_t RegOffset,uint16_t Data);
static uint32_t PHY_lReadReg(uint32_t PhyBase,uint32_t RegOffset,uint16_t *RegData);
static status_t PHY_lResetPHY(void);

#if AUTO_NEGO

static status_t PHY_lPerformLinkNegotiation(void);

static BOOLType PHY_lIsAutoNegoComplete(void);

#endif
/**
 * @}
 */
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
PHYTimerCallbackType PHYtimerCallback;
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
/**
 * @addtogroup EthernetPHY_apidoc
 * @{
 */

/**
 *
 * This function initializes Ethernet PHY
 */
status_t  PHY_InitializeDevice (void)
{
  /* <<<DD_ETHPHY_API_1>>> */
  uint16_t RegData = 0; /* Initialize to 0 */
  status_t Status = (uint32_t)PHY_INIT_ERROR;
  BOOLType IsLinkUp = FALSE;

  DBG002_FUNCTION_ENTRY(APP_GID,ETH002_FUNCTION_ENTRY);
  do
  {
    Status = PHY_lResetPHY();
    if (Status != DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, PHY_INIT_ERROR, 0, NULL);
      break;
    }
#if AUTO_NEGO
    Status = PHY_lPerformLinkNegotiation();
    if (Status != DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, PHY_INIT_ERROR, 0, NULL);
      break;
    }
#endif

#if (AUTO_NEGO != 1)

#ifdef SPEED_100
    /* <<<DD_ETHPHY_API_1_1>>> */
    Status = PHY_lWriteReg (PHY_BASE_ADDRESS,
                           BASIC_MODE_CONTROL_REG,
                           RegData | Mii_SPEED_100);
#else
	Status = PHY_lReadReg (PHY_BASE_ADDRESS,
	                          (uint32_t)BASIC_MODE_CONTROL_REG,
	                          &RegData);
	                          
	RegData &= ~Mii_SPEED_100; /* reset the bit 100Mbit setting */ 

  Status = PHY_lWriteReg (PHY_BASE_ADDRESS,
                           BASIC_MODE_CONTROL_REG,
                           RegData);
#endif
    if (Status != DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, PHY_SPEED_SET_ERROR, 0, NULL);
      break;
    }

    /* Note: this MACRO should be set from GUI */
#ifdef HALF_DUPLEX
    /* <<<DD_ETHPHY_API_1_2>>> */
    /* if not set to Master configuration in case of Half duplex mode set
     * it manually as Master
     */
    Status = PHY_lWriteReg (PHY_BASE_ADDRESS,
                           BASIC_MODE_CONTROL_REG,
                           RegData | Mii_MANUAL_MASTER_CONFIG);

#else
    /* Set to Full Duplex Mode */
    Status = PHY_lWriteReg (PHY_BASE_ADDRESS,
                           BASIC_MODE_CONTROL_REG,
                           RegData | Mii_DUPLEX );
#endif
    if(Status != DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, PHY_MODE_SET_ERROR, 0, NULL);
      break;
    }
#endif /*!AUTO_NEGO */

#ifdef PHY_National_DP83848C
/* set PHY to RMII mode */
		Status = PHY_lReadReg (PHY_BASE_ADDRESS,
		                          (uint32_t)RMII_AND_BYPASS_REG,
		                          &RegData);
		
		Status = PHY_lWriteReg (PHY_BASE_ADDRESS,
		                           RMII_AND_BYPASS_REG,
		                           RegData | 0x20 );
                          

#endif

    /* check for LINK is up... */
    IsLinkUp = PHY_IsLinkUP();
    if (TRUE == IsLinkUp)
    {
      DBG002_INFO(APP_GID, PHY_LINK_UP, 0, NULL);
    }
    else
    {
      DBG002_INFO(APP_GID, PHY_LINK_DOWN, 0, NULL);
    }


    /* PHY Initialization is successful */
    DBG002_INFO(APP_GID, PHY_INIT_SUCCSS, 0, NULL);
    Status = DAVEApp_SUCCESS;
  }while(0);

  DBG002_FUNCTION_EXIT(APP_GID,ETH002_FUNCTION_EXIT);
  return Status;
}

/**
 * The function returns Link status of Ethernet PHY
 *
 * @return: True if Link is UP, False otherwise
 */
BOOLType PHY_IsLinkUP (void)
{
  /* <<<DD_ETHPHY_API_2>>> */
  BOOLType IsLinkUP = FALSE;
  uint16_t RegData = (uint16_t)0U;  /* Initialize to 0 */
  uint16_t RegData1 = (uint16_t)0U; /* Initialize to 0 */
  status_t Status = (status_t)DAVEApp_SUCCESS;

  DBG002_FUNCTION_ENTRY(APP_GID,ETH002_FUNCTION_ENTRY);
  Status = (status_t)PHY_lReadReg((uint32_t)PHY_BASE_ADDRESS,
                         (uint32_t)BASIC_MODE_STATUS_REG,
                         &RegData);
  if (Status != (status_t)DAVEApp_SUCCESS)
  {
	DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
  }
  else
  {
    Status =  (status_t)PHY_lReadReg((uint32_t)PHY_BASE_ADDRESS,
                         (uint32_t)BASIC_MODE_STATUS_REG,
                         &RegData1);
    if (Status != (status_t)DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
    }
    else if (RegData1 & (uint16_t)Mii_LINK_STATUS)
    {
      DBG002_INFO(APP_GID, PHY_LINK_UP, 0, NULL);
      IsLinkUP = TRUE;
    }
    else
    {
      DBG002_INFO(APP_GID, PHY_LINK_DOWN, 0, NULL);
    }
  }
  DBG002_FUNCTION_EXIT(APP_GID,ETH002_FUNCTION_EXIT);
  return IsLinkUP;
}

/**
 * @}
 */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/**
 * @addtogroup EthernetPHY_privatefunc
 * @{
 */

/**
  * @brief Function to read the Phy register. The access to phy register
  * is a slow process as the data is moved accross MDI/MDO interface
  *
  * @param[in] PhyBase register is the index of one of supported 32 PHY devices.
  * @param[in] RegOffset Register offset is the index of one of the 32 phy register.
  * @param[out] RegData  data read from the respective phy register (only valid
  *             iff return value is 0).
  *
  * @return Returns 0 on success else return the error status.
  */

static uint32_t PHY_lReadReg
(
  uint32_t PhyBase,
  uint32_t RegOffset,
  uint16_t *RegData
)
{
  ETH_GLOBAL_TypeDef *GMACRegs = (ETH_GLOBAL_TypeDef *) ETH0_BASE;
  uint32_t Address;
  uint32_t LoopVariable;
  status_t Status = (uint32_t)PHY_READ_ERROR;

  DBG002_FUNCTION_ENTRY(APP_GID,ETH002_FUNCTION_ENTRY);

  Address = ((PhyBase << (uint32_t)GmiiDevShift) & (uint32_t)GmiiDevMask) |
        ((RegOffset << (uint32_t)GmiiRegShift) & (uint32_t)GmiiRegMask);

  Address = Address | (uint32_t)GmiiBusy; /* Gmii busy bit */
  /* write the Addressess from where the data to be read in GmiiGmiiAddr
   * register of synopGMAC ip
   */
  GMACRegs->GMII_ADDRESS = Address;

  for(LoopVariable = (uint32_t)0U; LoopVariable < (uint32_t)BUSY_WAIT_LOOP_COUNT; LoopVariable++)
  {
    /* Wait till the busy bit gets cleared with in a certain amount of time */
    if ((GMACRegs->GMII_ADDRESS & (uint32_t)GmiiBusy) != (uint32_t)1U)
    {
      break;
    }

	if(NULL != PHYtimerCallback)
	{
		PHYtimerCallback(PHY_REG_OPERATION_WAIT_TIME);
	}

  }

  if(LoopVariable < (uint32_t)BUSY_WAIT_LOOP_COUNT)
  {
    *RegData =   (uint16_t)((uint32_t)GMACRegs->GMII_DATA & (uint32_t)0xFFFFU);
     Status = (status_t)DAVEApp_SUCCESS;
  }
  else
  {
    DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
  }
  DBG002_FUNCTION_EXIT(APP_GID,ETH002_FUNCTION_EXIT);
  return Status;
}

/**
  * @brief Function to write to the Phy register. The access to phy register
  * is a slow process as the data is moved accross MDI/MDO interface
  *
  * @param[in] PhyBase register is the index of one of supported 32 PHY devices.
  * @param[in] RegOffset is the index of one of the 32 phy register.
  * @param[in] Data to be written to the respective phy register.
  *
  * @return Returns DAVEApp_SUCCESS on success else return the error status.
  */
static uint32_t PHY_lWriteReg
(
  uint32_t PhyBase,
  uint32_t RegOffset,
  uint16_t Data
)
{
  ETH_GLOBAL_TypeDef *GMACRegs = (ETH_GLOBAL_TypeDef *) ETH0_BASE;
  uint32_t Address;
  uint32_t LoopVariable;
  status_t Status = (uint32_t)PHY_WRITE_ERROR;

  DBG002_FUNCTION_ENTRY(APP_GID,ETH002_FUNCTION_ENTRY);

  /* write the data in to GmacGmiiData register of synopGMAC IP */
  GMACRegs->GMII_DATA = Data;

  Address = ((PhyBase << (uint32_t)GmiiDevShift) & (uint32_t)GmiiDevMask) |
        ((RegOffset << (uint32_t)GmiiRegShift) & (uint32_t)GmiiRegMask) | (uint32_t)GmiiWrite;

  /* set Gmii clk to 20-35 Mhz and Gmii busy bit */
  Address = Address | (uint32_t)GmiiBusy;

  GMACRegs->GMII_ADDRESS = Address;

  for(LoopVariable = (uint32_t)0U; LoopVariable < (uint32_t)BUSY_WAIT_LOOP_COUNT; LoopVariable++)
  {
    if ((GMACRegs->GMII_ADDRESS & (uint32_t)GmiiBusy) != (uint32_t)1U)
    {
      break;
    }
	if(NULL != PHYtimerCallback)
	{
		PHYtimerCallback(PHY_REG_OPERATION_WAIT_TIME);
	}
  }

  if(LoopVariable < (uint32_t)BUSY_WAIT_LOOP_COUNT)
  {
    Status = (status_t)DAVEApp_SUCCESS;
  }
  else
  {
	  DBG002_ERROR(APP_GID, PHY_BUSY_BIT_NOT_CLEARED, 0, NULL);
  }

  DBG002_FUNCTION_EXIT(APP_GID,ETH002_FUNCTION_EXIT);
  return Status;
}
/**
* @brief Function to reset the Phy and disable interrupts. 
*
* @param[in] void
*
* @return Returns DAVEApp_SUCCESS on success else return the error status.
*/
static status_t PHY_lResetPHY(void)
{
  status_t  Status = (uint32_t)PHY_RESET_ERROR;
  uint16_t RegData =  (uint16_t)0; /* Initialize to 0 */
  
  /* Reset Ethernet PHY */
  Status = PHY_lWriteReg ((uint32_t)PHY_BASE_ADDRESS,
            (uint32_t)BASIC_MODE_CONTROL_REG,
            (uint16_t)(RegData | (uint32_t)Mii_RESET));
  if (Status != (status_t)DAVEApp_SUCCESS)
  {
    DBG002_ERROR(APP_GID, PHY_RESET_ERROR, 0, NULL);
  }
  /* Wait for for reset to complete, actually 30 milliseconds @120Mhz CPU clock */
  else
  {
    if(NULL != PHYtimerCallback)
    {
    	PHYtimerCallback(RESET_COMPLETE_WAIT_PERIOD);
    }
    /* Check if Ethernet PHY Reset is complete */
    Status = PHY_lReadReg ((uint32_t)PHY_BASE_ADDRESS,
                          (uint32_t)BASIC_MODE_CONTROL_REG,
                          &RegData);
    if (Status != (status_t)DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
    }
    else
    {
      if ((RegData & (uint32_t)Mii_RESET) == (uint32_t)Mii_RESET)
      {
        /* Ethernet Reset is not complete */
        DBG002_ERROR(APP_GID, PHY_RESET_ERROR, 0, NULL);
      }
      else
      {
        /* Read PHY ID to check if the correct PHY is used */
        Status = PHY_lReadReg ((uint32_t)PHY_BASE_ADDRESS,
                          (uint32_t)PHY_ID_REG_1,
                          &RegData);
        if (Status != (status_t)DAVEApp_SUCCESS)
        {
          DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
        }
        else if (RegData != (uint16_t)PHY_ID1_REGISTER)
        {
          /* Wrong PHY connected */
          DBG002_ERROR(APP_GID, PHY_RESET_ERROR, 0, NULL);
        }
        else
        {

#ifdef PHY_National_DP83848C

          /* Read interrupt control register */
          Status = PHY_lReadReg ((uint32_t)PHY_BASE_ADDRESS,
                          (uint32_t)MII_INTERRUPT_CONTROL_REG,
                          &RegData);
          if (Status != (status_t)DAVEApp_SUCCESS)
          {
            DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
          }
          else
          {
            /* Disable all PHY interrupts */
            Status = PHY_lWriteReg ((uint32_t)PHY_BASE_ADDRESS,
                           (uint32_t)MII_INTERRUPT_CONTROL_REG,
                           (uint16_t)(RegData | (uint32_t)Mii_INTR_DISABLE));
            if (Status != (status_t)DAVEApp_SUCCESS)
            {
              DBG002_ERROR(APP_GID, PHY_DISABLE_INTR_ERROR, 0, NULL);
            }
          }
#endif
        }
      }
    }
  }
  return Status;
}

#if AUTO_NEGO
/**
* @brief Function to perform link negotiation. 
*
* @param[in] void
*
* @return Returns DAVEApp_SUCCESS on success else return the error status.
*/
static status_t PHY_lPerformLinkNegotiation(void)
{
  status_t Status = (uint32_t)PHY_READ_ERROR;
  uint16_t RegData = (uint16_t)0; /* Initialize to 0 */

  Status = PHY_lReadReg ((uint32_t)PHY_BASE_ADDRESS,
                          (uint32_t)AN_ADV_REG,
                          &RegData);
  if (Status != (status_t)DAVEApp_SUCCESS)
  {
    DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
  }
  else
  {
	  Status = PHY_lWriteReg ((uint32_t)PHY_BASE_ADDRESS,
              (uint32_t)AN_ADV_REG,
              (uint16_t)(RegData | (uint32_t)0xC00));
    if (Status != (status_t)DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, PHY_RESET_ERROR, 0, NULL);
    }
    else
    {
      Status = PHY_lReadReg ((uint32_t)PHY_BASE_ADDRESS,
                          (uint32_t)BASIC_MODE_CONTROL_REG,
                          &RegData);
      if (Status != (status_t)DAVEApp_SUCCESS)
      {
        DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
      }
      else
      {
        Status = PHY_lWriteReg ((uint32_t)PHY_BASE_ADDRESS,
              (uint32_t)BASIC_MODE_CONTROL_REG,
              (uint16_t)(RegData | (uint32_t)Mii_AUTONEGO));
        if (Status != (status_t)DAVEApp_SUCCESS)
        {
          DBG002_ERROR(APP_GID, PHY_RESET_ERROR, 0, NULL);
        }
        else
        {
	        if(NULL != PHYtimerCallback)
	        {
	          PHYtimerCallback(RESET_COMPLETE_WAIT_PERIOD);
	        }
          do
          {
          }while(PHY_lIsAutoNegoComplete() != TRUE);
          if(((uint32_t)RegData & (uint32_t)Mii_AUTO_NEGO_COMPLETE) != (uint32_t)0)
          {
            DBG002_INFO(APP_GID, PHY_AUTO_NEGO_COMPLETE, 0, NULL);
            Status = (status_t)DAVEApp_SUCCESS;
          }
          else
          {
	          Status = PHY_lReadReg ((uint32_t)PHY_BASE_ADDRESS,
                          (uint32_t)LNK_PART_ABl_REG,
                          &RegData);
            if (Status != (status_t)DAVEApp_SUCCESS)
            {
              DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
            }
            else
            {
	            Status = PHY_lReadReg ((uint32_t)PHY_BASE_ADDRESS,
                          (uint32_t)AN_EXP_REG,
                          &RegData);
              if (Status != (status_t)DAVEApp_SUCCESS)
              {
                DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
              }
            }
          }
        }
      }
    }
  }
  return Status;
}

/**
* @brief Function to check if link auto negotiation is complete.
*
* @param[in] void
*
* @return Returns TRUE is auto negotiation is complete, false otherwise.
*/
static BOOLType PHY_lIsAutoNegoComplete(void)
{
  uint16_t RegData = (uint16_t)0; /* Initialize to 0 */
  uint32_t LoopCount = (uint32_t)CHECK_AUTO_NEGO_TIME_COUNT;
  status_t Status = (uint32_t)PHY_INIT_ERROR;
  BOOLType IsAutoNegoComplete = FALSE;

  while(LoopCount != (uint32_t)0)
  {
    Status = PHY_lReadReg ((uint32_t)PHY_BASE_ADDRESS,
                      (uint32_t)BASIC_MODE_STATUS_REG,
                           &RegData);
    if(Status != (status_t)DAVEApp_SUCCESS)
    {
      DBG002_ERROR(APP_GID, PHY_READ_ERROR, 0, NULL);
      break;
    }
    if(((uint32_t)RegData & (uint32_t)Mii_AUTO_NEGO_COMPLETE) != (uint32_t)0)
    {
      DBG002_INFO(APP_GID, PHY_AUTO_NEGO_COMPLETE, 0, NULL);
      IsAutoNegoComplete = TRUE;
    }
    else
    {
      LoopCount--;
    }
  }
  if((uint32_t)0 == LoopCount)
  {
  	 IsAutoNegoComplete = TRUE;
  }
  return IsAutoNegoComplete;
}
#endif


/**
 * This function is a timer call back function
 *
 */
void PHY_RegisterTimerCallback(PHYTimerCallbackType Callback)
{
	PHYtimerCallback = Callback;
}

/**
 * @}
 */

/*CODE_BLOCK_END*/



 