


/*CODE_BLOCK_BEGIN[CLK001.c]*/

/*******************************************************************************
 Copyright (c) 2012, Infineon Technologies AG                                 **
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
** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Oct 31, 2012                                           **
**                                                                            **
*******************************************************************************/
/**
 * @file   CLK001.c
 *
 * @brief  SCU_Clock_CLK001 App
 *         
 *  CLK001 App is a singleton app which is used by all applications to configure 
 *  the PLL as well as enable the Clock of Peripheral Units.
 
 * Revision History
 * 12 Dec 2012   v1.0.1    modified to take care java.utils and basecode updates
 
 *
 */

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** RS           App Developer                                                 **
*******************************************************************************/

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
/** Inclusion of header file */
#include <DAVE3.h>

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* Various options for CLK tree settings*/

/*Main PLL input clock options*/
#define CLK001_CLOCK_CRYSTAL                1U
#define CLK001_CLOCK_EXT_CLOCK              2U
#define CLK001_CLOCK_BACK_UP_CLOCK          3U

/*Options for back up clock trimming*/
#define CLK001_CLOCK_TRIM_FACTORY           1U
#define CLK001_CLOCK_TRIM_AUTOMATIC         2U

/*options for system clock source*/
#define CLK001_CLOCK_SRC_PLL            1U
#define CLK001_CLOCK_SRC_BACKUP         2U

/*options for PLL modes*/
#define CLK001_CLOCK_PLL_NORMAL         1U
#define CLK001_CLOCK_PLL_PRESCALER      2U

/*options for STDBY clock source*/
#define CLK001_HIB_CLOCK_FOSI          1U
#define CLK001_HIB_CLOCK_OSCULP        2U


/* MAIN PLL setup parameters */  


#define   CLK001_PLL_K1DIV        0U
#define   CLK001_PLL_K2DIV        3U      
#define   CLK001_PLL_PDIV         0U    
#define   CLK001_PLL_NDIV         39U  
#define   CLK001_PLL_K2DIV_STEP_1    19  /*PLL output is 24Mhz*/  
#define   CLK001_PLL_K2DIV_STEP_2    7  /*PLL output to 60Mhz*/  
#define   CLK001_PLL_K2DIV_STEP_3    4  /*PLL output to 96Mhz*/  

/* USB PLL setup parameters */
#define   CLK001_USBPLL_PDIV      1U
#define   CLK001_USBPLL_NDIV      63U
#define   CLK001_USBDIV           3U



/*Main PLL input clock configuration*/
#define  CLK001_PLL_CLOCK_INPUT  CLK001_CLOCK_CRYSTAL

/*Oscillator mode = External Crystal Mode*/
#define CLK001_OSC_HP_MODE  0x0U

/*Standby clock source configuration*/
#define  CLK001_STANDBY_CLOCK  CLK001_HIB_CLOCK_FOSI

/*Back up clock trimming option*/
#define CLK001_TRIM_OPTION CLK001_CLOCK_TRIM_AUTOMATIC

/*System clock source configuration*/
#define CLK001_CLOCK_SYS_SRC CLK001_CLOCK_SRC_PLL 

/*PLL mode configuration*/
#define CLK001_CLOCK_PLL_MODE CLK001_CLOCK_PLL_NORMAL

/*Values of various parameters based on UI selction*/

/*system clock frequency*/
#define CLK001_CLOCK_FSYS                    120000000U

/*crystal or digital clock input frequency*/
#define  CLK001_CLOCK_CRYSTAL_FREQUENCY      12000000U     

/*back up clock frequency*/
#define  CLK001_CLOCK_BACK_UP                24000000U

/*Reference frequency for sytem oscillator watch dog - 2.5 MHz*/
#define  CLK001_SOSCWDG_FREF                 2500000U

/*Regiser bit field mask to check if Oscillator is usable*/
#define CLK001_PLLSTAT_OSC_USABLE_MASK       (SCU_PLL_PLLSTAT_PLLHV_Msk | \
                                              SCU_PLL_PLLSTAT_PLLLV_Msk | \
                                              SCU_PLL_PLLSTAT_PLLSP_Msk)

/*delay values used in the below calculation
these are to be used with the delay function defined in this file
they are approximate values based on measurement*/
#define CLK001_DELAY_CNT_50US_50MHZ        100U
#define CLK001_DELAY_CNT_50US_90MHZ        150U
#define CLK001_DELAY_CNT_8US_50MHZ         10U
#define CLK001_LOOP_CNT_150MS              18000U /*150ms / 8us*/

/*values for PLL frequency stepping*/
#define CLK001_PLL_FREQ_STEP1               (24U * 1000U * 1000U)
#define CLK001_PLL_FREQ_STEP2               (60U * 1000U * 1000U)
#define CLK001_PLL_FREQ_STEP3               (90U * 1000U * 1000U)


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
static void Delay(uint32_t time_1);
static uint32_t System_Clock_valid(void);
static uint32_t System_Clock_init(void);     
static uint32_t	USB_Clock_valid(void);
static uint32_t	USB_Clock_init(void);



static void MMC_Clock_init(void);
 
static void RTC_Clock_init(void);

/*******************************************************************************
**                      Extern Declarations                                   **
*******************************************************************************/
extern void SystemCoreClockUpdate(void);
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
/**
  * @brief  Function to delay  
  * @note   -  
  * @param  number of loops
  * @retval None
  */
static void Delay(uint32_t time_1)
{
	uint32_t i = 0U;
	for(i=0U; i < time_1;i++)
	{
		__NOP();__NOP();__NOP();__NOP();
	}

} 
/**
  * @brief  Function to check current MAIN Clock setting based on UI configuration 
  * @note   -  
  * @param  None
  * @retval PASS/FAIL
  */
static uint32_t System_Clock_valid(void)
{
  uint32_t MAIN_clock_status = 1U;

  /* check if PLL is switched on */
  if((SCU_PLL->PLLCON0 &(SCU_PLL_PLLCON0_VCOPWD_Msk | SCU_PLL_PLLCON0_PLLPWD_Msk))!= 0U)
  {
    MAIN_clock_status=0U;
  }
  return(MAIN_clock_status);
}

/**
  * @brief  Function to initialize the Main Clock based on UI configuration 
  * @note   -  
  * @param  None
  * @retval PASS/FAIL
  */
static uint32_t System_Clock_init(void)
{
	uint32_t Return_status = 1U;
#if ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \
    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_NORMAL))
  uint32_t VCO; 
  uint32_t stepping_K2DIV;	
#endif
#if (((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \
    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_PRESCALER) && \
    (CLK001_PLL_CLOCK_INPUT != CLK001_CLOCK_BACK_UP_CLOCK))|| \
    ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \
    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_NORMAL)))
  uint32_t timeout_count;
#endif
  /*Back up clock trimming*/
#if ((CLK001_TRIM_OPTION == CLK001_CLOCK_TRIM_AUTOMATIC)&& \
    (CLK001_STANDBY_CLOCK == CLK001_HIB_CLOCK_FOSI))
  {
  
     /* check if HIB Domain enabled  */
     if((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk) == 0U)
     {
       SCU_POWER->PWRSET |= (uint32_t)SCU_POWER_PWRSET_HIB_Msk;/*enable Hibernate domain*/
     }

     /* check if HIB Domain is not in reset state  */
     if ((SCU_RESET->RSTSTAT & SCU_RESET_RSTSTAT_HIBRS_Msk) != 0U)
     {
	     /*de-assert hibernate reset*/
       SCU_RESET->RSTCLR |= (uint32_t)SCU_RESET_RSTCLR_HIBRS_Msk;
     }
     SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_FOTR_Msk;
     /*insert some delay */
     Delay(CLK001_DELAY_CNT_50US_50MHZ); /*~50us @ maximum back up clock freq*/
     SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_AOTREN_Msk;
  }
#elif((CLK001_TRIM_OPTION == CLK001_CLOCK_TRIM_AUTOMATIC)&& \
     (CLK001_STANDBY_CLOCK == CLK001_HIB_CLOCK_OSCULP))
  {
    /* check for HIB Domain enabled  */
    if((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk) == 0U)
    {
      SCU_POWER->PWRSET |= (uint32_t)SCU_POWER_PWRSET_HIB_Msk;/*enable Hibernate domain*/
    }

    /* check for HIB Domain is not in reset state  */
    if ((SCU_RESET->RSTSTAT & SCU_RESET_RSTSTAT_HIBRS_Msk) != 0U)
    {
      /*de-assert hibernate reset*/
      SCU_RESET->RSTCLR |= (uint32_t)SCU_RESET_RSTCLR_HIBRS_Msk;
    }
    /*check OSCUL if running correct*/
    if ((SCU_HIBERNATE->OSCULCTRL & SCU_HIBERNATE_OSCULCTRL_MODE_Msk) != 0U)
    {
      OSCULP_init();
	  /* select OSCUL clock for RTC*/
      SCU_HIBERNATE->HDCR |= (uint32_t)SCU_HIBERNATE_HDCR_RCS_Msk;
      while (SCU_GENERAL->MIRRSTS & SCU_GENERAL_MIRRSTS_HDCR_Msk)
      {}

      while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!=\
	       SCU_INTERRUPT_SRRAW_HDCR_Msk)
      {}
      SCU_INTERRUPT->SRCLR |= (uint32_t)SCU_INTERRUPT_SRCLR_HDCR_Msk;
    }              
      
    /* now OSCULP is running and can be used*/
    SCU_HIBERNATE->HDCR  |= (uint32_t)SCU_HIBERNATE_HDCR_STDBYSEL_Msk;
    while((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk)!= \
	       SCU_POWER_PWRSTAT_HIBEN_Msk)
    {}

    while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!= \
	       SCU_INTERRUPT_SRRAW_HDCR_Msk)
    {}
    SCU_INTERRUPT->SRCLR |= (uint32_t)SCU_INTERRUPT_SRCLR_HDCR_Msk;
	
    SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_FOTR_Msk;
    
    /*insert some delay */
    Delay(CLK001_DELAY_CNT_50US_50MHZ);/*~50us @ maximum back up clock freq*/
    SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_AOTREN_Msk;

  }
#else /*trimming option is factory trimming*/
  {
    SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_FOTR_Msk;
  }
#endif /*end of trimming options*/
  /*insert some delay after trimming is enabled*/
  Delay(CLK001_DELAY_CNT_50US_50MHZ);/*~50us @ maximum back up clock freq*/

  /*Select system clock = back up clock (is the default configuration anyway)*/
#if (CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_BACKUP)
  {
    SCU_CLK->SYSCLKCR &= (uint32_t)~(SCU_CLK_SYSCLKCR_SYSSEL_Msk);
  }
  /*system clock = pll */
#else/*(CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL)*/
  {
    /* enable PLL first */
    SCU_PLL->PLLCON0 &= (uint32_t)~(SCU_PLL_PLLCON0_VCOPWD_Msk | SCU_PLL_PLLCON0_PLLPWD_Msk);

    /*if crystal or external digital input for PLL input*/
#if ((CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_CRYSTAL)||\
    (CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_EXT_CLOCK))
    {
      /************************************************************************/
      /*    Use external crystal or digital input for PLL clock input         */
      /************************************************************************/ 

      /* Enable OSC_HP if not already on */
      if ((SCU_OSC->OSCHPCTRL & SCU_OSC_OSCHPCTRL_MODE_Msk) != \
         ((uint32_t)CLK001_OSC_HP_MODE << SCU_OSC_OSCHPCTRL_MODE_Pos))
      {
        /*The OSC HP mode is guaranteed to  be = 11b at this point
        * so we can just clear the bit(s) as per the selected mode
        */
        SCU_OSC->OSCHPCTRL &= (((uint32_t)(~(uint32_t)SCU_OSC_OSCHPCTRL_MODE_Msk)) | \
           ((uint32_t)CLK001_OSC_HP_MODE << SCU_OSC_OSCHPCTRL_MODE_Pos));

        /* setup OSC WDG divider - at this point the bitfield would be 0
        hence we can OR with the desired value*/
        SCU_OSC->OSCHPCTRL |=
          ((uint32_t)((CLK001_CLOCK_CRYSTAL_FREQUENCY/CLK001_SOSCWDG_FREF)-1)\
                                              <<SCU_OSC_OSCHPCTRL_OSCVAL_Pos);
        /* select external OSC as PLL input */
        SCU_PLL->PLLCON2 &= (uint32_t)~SCU_PLL_PLLCON2_PINSEL_Msk;
        /* restart OSC Watchdog */
        SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_OSCRES_Msk;

        /*approx loop count for 150ms @ max untrimmed Backup clock freq*/
        timeout_count = CLK001_LOOP_CNT_150MS; 
        do 
        {
          /* time out after ~150ms  */
          Delay(CLK001_DELAY_CNT_8US_50MHZ);  
          timeout_count--;

        }while((((SCU_PLL->PLLSTAT) & CLK001_PLLSTAT_OSC_USABLE_MASK) != \
              CLK001_PLLSTAT_OSC_USABLE_MASK) && (timeout_count !=0U));

        if (((SCU_PLL->PLLSTAT) & CLK001_PLLSTAT_OSC_USABLE_MASK) != \
              CLK001_PLLSTAT_OSC_USABLE_MASK)
        {
           /* Return Error */
        	Return_status = 0U;
        }
      }
    }
#else /*PLL clock source is back up clock */
    {
      /*select Backup Clock as input to PLL*/
      SCU_PLL->PLLCON2 |= (uint32_t)SCU_PLL_PLLCON2_PINSEL_Msk;
    }
#endif /*end of PLL clock source check */
    /**************************************************************************/
    /*   Setup and lock the main PLL (PLL is in normal mode)                  */
    /**************************************************************************/
#if ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \
    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_NORMAL))
    {
      if ((SCU_PLL->PLLSTAT & SCU_PLL_PLLSTAT_VCOLOCK_Msk)!= \
	       SCU_PLL_PLLSTAT_VCOLOCK_Msk)
      {
        /* System is still running from Backup clock */ 
       
        /*Calculation for stepping*/
#if((CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_CRYSTAL)||\
   (CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_EXT_CLOCK))
        {
          VCO = (CLK001_CLOCK_CRYSTAL_FREQUENCY/ \
                (CLK001_PLL_PDIV+1))*(CLK001_PLL_NDIV+1);
        }
#else /*PLL clcok source is back up clock in normal mode*/
        {
          VCO = (CLK001_CLOCK_BACK_UP/(CLK001_PLL_PDIV+1U))*(CLK001_PLL_NDIV+1U);
        }
#endif /*End of PLL clock source check in normal mode*/
        stepping_K2DIV = (VCO/CLK001_PLL_FREQ_STEP1)-1U;
           
        /* Go to bypass the Main PLL */
        SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_VCOBYP_Msk;
        /* disconnect Oscillator from PLL */
        SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_FINDIS_Msk;
        /* Setup divider settings for main PLL */
        SCU_PLL->PLLCON1 =(((uint32_t)CLK001_PLL_K1DIV) | \
               ((uint32_t)CLK001_PLL_NDIV<<SCU_PLL_PLLCON1_NDIV_Pos) | \
               ((uint32_t)stepping_K2DIV<<SCU_PLL_PLLCON1_K2DIV_Pos) | \
               ((uint32_t)CLK001_PLL_PDIV<<SCU_PLL_PLLCON1_PDIV_Pos));
        /* Set OSCDISCDIS */
        SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_OSCDISCDIS_Msk;
        /* connect Oscillator to PLL */
        SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_FINDIS_Msk;
        /* restart PLL Lock detection */
        SCU_PLL->PLLCON0 |= (uint32_t)SCU_PLL_PLLCON0_RESLD_Msk;
        /* wait for PLL Lock */

        /* Timeout for wait loop ~150ms */
        /*approx loop count for 150ms @ Backup Clock freq*/
        timeout_count = CLK001_LOOP_CNT_150MS;
        do
        {
          Delay(CLK001_DELAY_CNT_8US_50MHZ);  /*~8us Delay*/
          timeout_count--;
        } while (((SCU_PLL->PLLSTAT & SCU_PLL_PLLSTAT_VCOLOCK_Msk)!= \
		           SCU_PLL_PLLSTAT_VCOLOCK_Msk)&& (timeout_count !=0U));

        if ((SCU_PLL->PLLSTAT & SCU_PLL_PLLSTAT_VCOLOCK_Msk)== \
            SCU_PLL_PLLSTAT_VCOLOCK_Msk)
        {
          /* Disable bypass- put pll clock back */
          SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_VCOBYP_Msk;
        }
        else
        {
          
        	Return_status =0U;
        }
      }

    }
#endif /*end of setting PLL is in Normal mode - first frequency stepping*/
    /**************************************************************************/
    /*   Setup main PLL (PLL is in prescaler mode)                            */
    /**************************************************************************/
#if ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \
    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_PRESCALER))
    {
      /* Program PLL for Prescaler mode*/
      SCU_PLL->PLLCON0 |= \
             (SCU_PLL_PLLCON0_VCOBYP_Msk|SCU_PLL_PLLCON0_VCOPWD_Msk);
              
      /* wait for Prescaler mode to be entered*/
      while ((SCU_PLL->PLLSTAT & SCU_PLL_PLLSTAT_VCOBYST_Msk)!= \
	          SCU_PLL_PLLSTAT_VCOBYST_Msk)
      {}
       
      /* Choose fOSC as an input to K1divider*/
#if((CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_CRYSTAL)||\
   (CLK001_PLL_CLOCK_INPUT == CLK001_CLOCK_EXT_CLOCK))
      {
        SCU_PLL->PLLCON2 &= (uint32_t)~SCU_PLL_PLLCON2_K1INSEL_Msk;
      }
#else /*Input to K1 divider is back up clock*/
      {
        SCU_PLL->PLLCON2 |= (uint32_t)SCU_PLL_PLLCON2_K1INSEL_Msk;
      }
#endif /*end of input selection for K1 dividier*/
      /* Setup K1 divider for main PLL */
      SCU_PLL->PLLCON1 = CLK001_PLL_K1DIV;
    }
#endif /*end of Prescaler mode settings*/
	    /* Switch system clock to PLL */
    SCU_CLK->SYSCLKCR |=  (uint32_t)1 << SCU_CLK_SYSCLKCR_SYSSEL_Pos;
  }/*end of PLL configuration if PLL is the system clock
    (but it is pending frequency stepping to the target frequency)*/
#endif /*end of system clock selection - PLL Vs Back up clock*/
  
	/*******************************************************************
	Before scaling to final frequency we need to setup the clock dividers 
	*******************************************************************/
	
	
	
	
	


  /***************************************************************************/
  /*   Frequency stepping for main PLL (PLL is in normal mode)               */
  /***************************************************************************/
#if ((CLK001_CLOCK_SYS_SRC == CLK001_CLOCK_SRC_PLL) && \
    (CLK001_CLOCK_PLL_MODE == CLK001_CLOCK_PLL_NORMAL))
  {

    /* Reset OSCDISCDIS */
    SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_OSCDISCDIS_Msk;



    /*********************************************************
    here the ramp up of the system clock to FSys < 60MHz
    *********************************************************/
#if (CLK001_CLOCK_FSYS > CLK001_PLL_FREQ_STEP2)
    {
      /*********************************************************/
      /* Delay for next K2 step ~50?s */
      /*********************************************************/
      Delay(CLK001_DELAY_CNT_50US_50MHZ); /*~50us Backup clock*/

      /*calculation for stepping*/
      stepping_K2DIV = (VCO/CLK001_PLL_FREQ_STEP2)-1;	

      /*Setup divider settings for main PLL */
      SCU_PLL->PLLCON1 =(((uint32_t)CLK001_PLL_K1DIV) | \
               ((uint32_t)CLK001_PLL_NDIV<<SCU_PLL_PLLCON1_NDIV_Pos)|\
               ((uint32_t)stepping_K2DIV<<SCU_PLL_PLLCON1_K2DIV_Pos)|\
               ((uint32_t)CLK001_PLL_PDIV<<SCU_PLL_PLLCON1_PDIV_Pos));
    }
#endif /*end of check - if PLL target frequency is greater than 60 MHz*/


    /*********************************************************
    here the ramp up of the system clock to FSys < 90MHz
    *********************************************************/
#if (CLK001_CLOCK_FSYS > CLK001_PLL_FREQ_STEP3)
    {
      
      /*********************************************************/
      /* Delay for next K2 step ~50us */
      /*********************************************************/
      Delay(CLK001_DELAY_CNT_50US_50MHZ); /*~50?s @ 60MHz clock*/
      
      /*calulation for stepping*/
      stepping_K2DIV = (VCO/CLK001_PLL_FREQ_STEP3)-1;			

      /* Setup Divider settings for main PLL */

      SCU_PLL->PLLCON1 = (((uint32_t)CLK001_PLL_K1DIV) | \
                        ((uint32_t)CLK001_PLL_NDIV<<SCU_PLL_PLLCON1_NDIV_Pos)| \
              ((uint32_t)stepping_K2DIV<<SCU_PLL_PLLCON1_K2DIV_Pos)| \
              ((uint32_t)CLK001_PLL_PDIV<<SCU_PLL_PLLCON1_PDIV_Pos));
    }
#endif /*end of check if PLL target frequency is more than 90 MHz*/

    /*********************************************************/
    /* Delay for next K2 step ~50?s */
    /*********************************************************/

    Delay(CLK001_DELAY_CNT_50US_90MHZ); /*~50us @ 90 MHz clock*/

    /*********************************************************/

    /* Setup Divider settings for main PLL */
    SCU_PLL->PLLCON1 = (((uint32_t)CLK001_PLL_K1DIV) | \
            ((uint32_t)CLK001_PLL_NDIV<<SCU_PLL_PLLCON1_NDIV_Pos)  | \
            ((uint32_t)CLK001_PLL_K2DIV<<SCU_PLL_PLLCON1_K2DIV_Pos)| \
            ((uint32_t)CLK001_PLL_PDIV<<SCU_PLL_PLLCON1_PDIV_Pos));
            
    /* clear request for System OCS Watchdog Trap and System VCO Lock Trap  */
    SCU_TRAP->TRAPCLR = SCU_TRAP_TRAPCLR_SOSCWDGT_Msk |\
                        SCU_TRAP_TRAPCLR_SVCOLCKT_Msk; 
  }/*end PLL frequency stepping...*/
#endif /*end of PLL frequency stepping in case of PLL normal mode*/
   /*return success*/
  return Return_status;
}
     
/**
  * @brief  Function to check current USB Clock setting based on UI configuration 
  * @note   -  
  * @param  None
  * @retval PASS/FAIL
  */
static uint32_t	USB_Clock_valid(void)
{
  uint32_t USB_clock_status = 1U;
  /* check if PLL is switched on */
  if((SCU_PLL->USBPLLCON &(SCU_PLL_USBPLLCON_VCOPWD_Msk | \
                           SCU_PLL_USBPLLCON_PLLPWD_Msk)) != 0U)
  {
    USB_clock_status=0U;
  }
  return(USB_clock_status);
}

/**
  * @brief  Function to initialize the USB Clock based on UI configuration 
  * @note   -  
  * @param  None
  * @retval PASS/FAIL
  */
static uint32_t	USB_Clock_init(void)
{

  uint32_t timeout_count;
  uint32_t Return_status = 1U;
  /* enable USB PLL first */
  SCU_PLL->USBPLLCON &= (uint32_t)~(SCU_PLL_USBPLLCON_VCOPWD_Msk | \
                         SCU_PLL_USBPLLCON_PLLPWD_Msk);

  /* check and if not already running enable OSC_HP */
  if ((SCU_OSC->OSCHPCTRL & SCU_OSC_OSCHPCTRL_MODE_Msk) != \
     ((uint32_t)CLK001_OSC_HP_MODE << SCU_OSC_OSCHPCTRL_MODE_Pos))
  {
    /* check if Main PLL is switched on for OSC WD*/
    if ((SCU_PLL->PLLCON0 &(SCU_PLL_PLLCON0_VCOPWD_Msk | \
        SCU_PLL_PLLCON0_PLLPWD_Msk)) != 0U)
    {
      /* enable PLL first */
      SCU_PLL->PLLCON0 &= (uint32_t)~(SCU_PLL_PLLCON0_VCOPWD_Msk | \
                           SCU_PLL_PLLCON0_PLLPWD_Msk);
    }

    /*The OSC HP mode is guaranteed to  be = 11b at this point
    * so we can just clear the bit(s) as per the selected mode
    */
    SCU_OSC->OSCHPCTRL &= (((uint32_t)(~(uint32_t)SCU_OSC_OSCHPCTRL_MODE_Msk)) | \
       ((uint32_t)CLK001_OSC_HP_MODE << SCU_OSC_OSCHPCTRL_MODE_Pos));
   
    /* setup OSC WDG Divider */
    SCU_OSC->OSCHPCTRL|=
      ((uint32_t)((CLK001_CLOCK_CRYSTAL_FREQUENCY/CLK001_SOSCWDG_FREF)-1U)\
                                           <<SCU_OSC_OSCHPCTRL_OSCVAL_Pos);
   
    /* restart OSC Watchdog */
    SCU_PLL->PLLCON0 &= (uint32_t)~SCU_PLL_PLLCON0_OSCRES_Msk;  

     /* Timeout for wait loo ~150ms */
    /********************************/	  
    /*approx loop count for 150ms @ Backup Clock freq*/
    timeout_count = CLK001_LOOP_CNT_150MS;
    do
    {
      Delay(CLK001_DELAY_CNT_8US_50MHZ);  /*~8us Delay*/
      timeout_count--;

    }while((((SCU_PLL->PLLSTAT) & CLK001_PLLSTAT_OSC_USABLE_MASK) != \
          CLK001_PLLSTAT_OSC_USABLE_MASK) && (timeout_count !=0U));

    if (((SCU_PLL->PLLSTAT) & CLK001_PLLSTAT_OSC_USABLE_MASK) != \
          CLK001_PLLSTAT_OSC_USABLE_MASK)
    {
      Return_status =0U;/* Return Error */
    }
  }

  /* Setup USB PLL */
  /* Go to bypass the USB PLL */
  SCU_PLL->USBPLLCON |= (uint32_t)SCU_PLL_USBPLLCON_VCOBYP_Msk;
  /* disconnect Oscillator from USB PLL */
  SCU_PLL->USBPLLCON |= (uint32_t)SCU_PLL_USBPLLCON_FINDIS_Msk;
  /* Setup Divider settings for USB PLL */
  SCU_PLL->USBPLLCON =(((uint32_t)CLK001_USBPLL_NDIV<<SCU_PLL_USBPLLCON_NDIV_Pos)|\
                      ((uint32_t)CLK001_USBPLL_PDIV<<SCU_PLL_USBPLLCON_PDIV_Pos));
  /* Setup USBDIV settings USB clock */
  SCU_CLK->USBCLKCR = CLK001_USBDIV;
  /* Set OSCDISCDIS */
  SCU_PLL->USBPLLCON |= (uint32_t)SCU_PLL_USBPLLCON_OSCDISCDIS_Msk;
  /* connect Oscillator to USB PLL */
  SCU_PLL->USBPLLCON &= (uint32_t)~SCU_PLL_USBPLLCON_FINDIS_Msk;
  /* restart PLL Lock detection */
  SCU_PLL->USBPLLCON |= (uint32_t)SCU_PLL_USBPLLCON_RESLD_Msk;

  /* wait for PLL Lock */
  while ((SCU_PLL->USBPLLSTAT & SCU_PLL_USBPLLSTAT_VCOLOCK_Msk)!= \
          SCU_PLL_USBPLLSTAT_VCOLOCK_Msk)
  {}

  /* Enable USB Clock */
  SCU_CLK->CLKSET |= (uint32_t)SCU_CLK_CLKSET_USBCEN_Msk;

  return Return_status;
} 




/**
  * @brief  Function to enable the MMC clock 
  * @note   -  
  * @param  None
  * @retval None
  */
static void MMC_Clock_init(void){
  /* Enable MMC Clock */
  SCU_CLK->CLKSET |= (uint32_t)SCU_CLK_CLKSET_MMCCEN_Msk;
}

/**
  * @brief  Function to initialize the RTC clock based on UI configuration
  * @note   -  
  * @param  None
  * @retval None
  */
static void RTC_Clock_init(void)
{
  /*before enabling hibernate domain (if opted), check if it is already enabled.
  we do not repeat the enable if already done*/
  if((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk) == 0U )
  {
    /* Enable hibernate domain */
    SCU_POWER->PWRSET = (uint32_t)(SCU_POWER_PWRSET_HIB_Msk);
    
    /* Wait until hibernate enable status is set */
    while((SCU_POWER->PWRSTAT & SCU_POWER_PWRSTAT_HIBEN_Msk)!= \
         SCU_POWER_PWRSTAT_HIBEN_Msk)
    {}
  }
  /* check for HIB Domain is not in reset state  */
  if ((SCU_RESET->RSTSTAT & SCU_RESET_RSTSTAT_HIBRS_Msk) != 0U)
  {
	  SCU_RESET->RSTCLR |= (uint32_t)SCU_RESET_RSTCLR_HIBRS_Msk; /*de-assert hibernate reset*/
  }
  /*RTC Clock Source Selection*/   
    /* Enable internal slow clock */
	/*Selecting RTC Clock Source*/
  SCU_HIBERNATE->HDCR |= ((0U << SCU_HIBERNATE_HDCR_RCS_Pos) & \
                         SCU_HIBERNATE_HDCR_RCS_Msk); 
  while((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_HDCR_Msk)!= \
         SCU_INTERRUPT_SRRAW_HDCR_Msk)
  {}
  SCU_INTERRUPT->SRCLR |= (uint32_t)SCU_INTERRUPT_SRCLR_HDCR_Msk;
	
}
  

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/

/**
  * @brief  Function to initialize the Clock Tree based on UI configuration
  * @note   -  
  * @param  None
  * @retval None
  */
void CLK001_Init(void)
{
  /*<<<DD_CLK001_API_1>>>*/
 /*  Function to check the clock status based on UI configuration */
  if(System_Clock_valid() == 0U)
  {   
    /*  Function to initialize the System Clock based on UI configuration */
    System_Clock_init();
  }     
  /*  Function to initialize the USB Clock based on UI configuration */     
  if(USB_Clock_valid() == 0U)
  {   
  	USB_Clock_init();
  } 


  /*  Function to enable the MMC Clock based on UI configuration */
  MMC_Clock_init();
 
   /*  Function to initialize the RTC Clock based on UI configuration */     
  RTC_Clock_init();   
  /* Update the clock variable */
  SystemCoreClockUpdate();
}

/*
 * This routine is called by CMSIS startup to find out if clock tree setup should
 * be done by it. This routine is WEAKLY defined in CStart.
 *
 * In the absence of clock app, the weak definition takes precedence which always
 * permits clock tree setup by CStart.
 *
 * When clock app is defined, this function overrides the CStart definition.Clock
 * tree setup is launched and upon completion, control is ceded back to CStart.
 *
 * CStart abstains from setting up clock tree and instead proceeds with program
 * loading.
 *
 * Return 0 to disallow CStart from performing clock tree setup.
 */
uint32_t AllowPLLInitByStartup(void)
{
	/*
	 * Let the CStart know that there is no more a need to perform clock tree
	 * initialization.
	 */
	return 0U;
}

/*CODE_BLOCK_END*/

