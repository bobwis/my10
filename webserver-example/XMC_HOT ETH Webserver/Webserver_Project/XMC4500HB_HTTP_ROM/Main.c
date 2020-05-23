/*
 * Main.c
 *
 *  Created on: Mar 18, 2013
 *      Author: toochang
 */





/** Inclusion of header file */
#include <DAVE3.h>
#include "netconf.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/tcp.h"
#include "lwip/netif.h"
#include "./Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.h"




const char *Dummy_cgi_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

/*
 * User declare the number of CGI
 */
#define CGI_MAX			1
tCGI CGI_TAB[CGI_MAX];

/*
 * Setting the CGI tag (eg./Dummy.cgi) and CGI handler
 */
const tCGI Dummy_CGI_Config1 = {"/Dummy.cgi", Dummy_cgi_handler};

/*
 * User can rename the "Value_?" to a better name which describe the checkbox option
 * as displayed on the webpage.
 */
typedef enum
{
	Value_0,
	Value_1,
	Value_2,
	value_3
}CheckBoxValue;

typedef struct Params_TAG
{
	CheckBoxValue CheckBox[value_3];
	char RadioButton;
	char SelectList;
}Params_T;

Params_T Dummy_CGI_Value;





/* Initialisation of functions to be used with CGi*/
//  CGI handler to switch LED status
const char *Dummy_cgi_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{

	uint32_t i,j;

	i=0;
	
	/* We have only one CGI handler iIndex = 0 */
	if (iIndex==0)
	{
	  /* Check cgi parameter : example GET /leds.cgi?led=2&led=4 */
	  for (i=0; i<iNumParams; i++)
	  {
		  j = *pcValue[i] - 0x30;	// Convert to dec

		  if (strcmp(pcParam[i] , "CheckBox")==0)
		  {
			  Dummy_CGI_Value.CheckBox[j-1] = j;
		  }
		  else if (strcmp(pcParam[i] , "RadioButton")==0)
		  {
			  Dummy_CGI_Value.RadioButton = j;
		  }
		  else if (strcmp(pcParam[i] , "SelectList")==0)
		  {
			  Dummy_CGI_Value.SelectList = j;
		  }
	  }
	}
	/* uri to send after cgi call*/


	return "/LED.htm";
}






//Initialise cgi environment
void http_CGI_init( void)
{
	//Initialised CGI structure for LED
	CGI_TAB[0] = Dummy_CGI_Config1;

	// Set CGI
	http_set_cgi_handlers(&CGI_TAB[0], 1);
}

u16_t SSI_ADC_Handler (int iIndex, char *pcInsert, int iInsertLen)
{

    char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    uint16_t ADCVal = 0;        
	status_t status;


	/* We have only one SSI handler iIndex = 0 */

	if (iIndex ==0)
	{  


	/* get ADC conversion value */

	status = ADCCH001_GetResult(&ADCCH001_Handle0, &ADCVal);
		//ADCVal = AD_result;//ADC_GetConversionValue(ADC3);
		
		/* convert to Voltage,	step = 0.8 mV */
		ADCVal = (uint16_t)(ADCVal * 0.8);	
		
		/* get digits to display */
		
		Digit1= ADCVal/1000;
		Digit2= (ADCVal-(Digit1*1000))/100 ;
		Digit3= (ADCVal-((Digit1*1000)+(Digit2*100)))/10;
		Digit4= ADCVal -((Digit1*1000)+(Digit2*100)+ (Digit3*10));
		   
		/* prepare data to be inserted in html */
		*pcInsert		= (char)(Digit1+0x30);
		*(pcInsert + 1) = (char)(Digit2+0x30);
		*(pcInsert + 2) = (char)(Digit3+0x30);
		*(pcInsert + 3) = (char)(Digit4+0x30);
	   
	   /* 4 characters need to be inserted in html*/
	   return 4;

	}

		return 0;

}


char const* TAGCHAR="t";
char const** TAGS=&TAGCHAR;


void http_SSI_init (void)
{


/*
SSI is a method used to dynamically include dynamic data in HTML code.
This done by placing a specific tag inside the HTML code of the web page. The tag should
have the following format: <!--#tag-->
For the ADC conversion page, the following tag "t" is used inside the HTML code: <!--#t-->
*/
http_set_ssi_handler(SSI_ADC_Handler, (char const **)TAGS, 1);


}



int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)


	DAVE_Init();			// Initialization of DAVE Apps

	ADC002_InitializeQueue((ADC002_HandleType*)&ADC002_Handle0);

	GUI_Init();

    lwIPStack_init();
    http_CGI_init();
    http_SSI_init();

	GUI_DispString("IP Adrress: 192.168.0.10");
	//GUI_DispString("MAC Adrress: 00:03:19:45:00:00");

	while(1)
	{
		//Process CGI
		if(Dummy_CGI_Value.CheckBox[0] == Value_1)
		{
			Dummy_CGI_Value.CheckBox[0] = Value_0;
			IO004_TogglePin(IO004_Handle2); //Toggle P3.9
		}

		if (Dummy_CGI_Value.RadioButton)
		{

		}

		if (Dummy_CGI_Value.SelectList)
		{

		}


	}
	return 0;
}
