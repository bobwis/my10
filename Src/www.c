/*
 * www.c
 *
 *  Created on: 6Jun.,2018
 *      Author: bob
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "main.h"
#include "stm32f7xx_hal.h"
#include "lwip.h"
#include "httpd_structs.h"
#include "httpclient.h"
#include "www.h"
#include "neo7m.h"
#include "udpstream.h"
#include "splat1.h"
#include "adcstream.h"
//#include "httpd.h"

extern uint32_t pressure, pressfrac, temperature, tempfrac;
extern uint8_t pgagain;

// Support functions

/*--------------------------------------------------*/
// httpd server support
/*--------------------------------------------------*/

extern I2C_HandleTypeDef hi2c1;


// The cgi handler is called when the user changes something on the webpage
void httpd_cgi_handler(const char *uri, int count, char **http_cgi_params,
		char **http_cgi_param_vals) {
	const char id[14][6] = { "led1", "sw1A", "sw1B", "sw1C", "sw1D", "sw2A", "sw2B", "sw2C", "sw2D",
			"btn", "PG2", "PG1", "PG0", "RF1" };

	int i, j, val;
	char *ptr;

	printf("httpd_cgi_handler: uri=%s, count=%d\n", uri, count);
	for (i = 0; i < count; i++) {			/// number of things sent from the form
		printf("params=%d, id=%c, val=%c\n", i, **http_cgi_params, (*http_cgi_param_vals)[i]);

		j = strtol(*http_cgi_params, &ptr, 10);

		switch (j) {

		case 11:				// LED1
			if (((*http_cgi_param_vals)[i]) == '0')
				HAL_GPIO_WritePin(GPIOD, LED_D1_Pin, GPIO_PIN_RESET);
			else
				HAL_GPIO_WritePin(GPIOD, LED_D1_Pin, GPIO_PIN_SET);
			break;

		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:		// output switch array
		case 19:
			j -= 11;	// now offset 0
			if (((*http_cgi_param_vals)[i]) == '0') {
				muxdat[0] = muxdat[0] & ~(1 << (j - 1));
			} else {
				muxdat[0] = muxdat[0] | (1 << (j - 1));
			}
			logampmode = muxdat[0] & 2;
			printf("setting outmux to 0x%02x\n", muxdat[0]);
			if (HAL_I2C_Master_Transmit(&hi2c1, 0x44 << 1, &muxdat[0], 1, 1000) != HAL_OK) {// RF dual MUX
				printf("I2C HAL returned error 1\n\r");
			}
			break;
		case 20:		// PGA G2
			val = (((*http_cgi_param_vals)[i]) == '0' ? pgagain & ~4 : pgagain | 4);
			setpgagain(val);
			break;
		case 21:		// PGA G1
			val = (((*http_cgi_param_vals)[i]) == '0' ? pgagain & ~2 : pgagain | 2);
			setpgagain(val);
			break;
		case 22:		// PGA G0
			val = (((*http_cgi_param_vals)[i]) == '0' ? pgagain & ~1 : pgagain | 1);
			setpgagain(val);
			break;

		case 23:		// RF Switch
			if (((*http_cgi_param_vals)[i]) == '1')
				HAL_GPIO_WritePin(GPIOE, LP_FILT_Pin, GPIO_PIN_RESET);// select RF Switches to LP filter (normal route)
				else
					HAL_GPIO_WritePin(GPIOE, LP_FILT_Pin, GPIO_PIN_SET);// select RF Switches to bypass LP filter
			break;

		default:
			printf("Unknown id in cgi handler %s\n", *http_cgi_params);
			break;
		} // end switch
	} // end for
}

err_t httpd_post_receive_data(void *connection, struct pbuf *p) {
	printf("httpd_post_receive_data: \n");
}

err_t httpd_post_begin(void *connection, const char *uri, const char *http_request,
		u16_t http_request_len, int content_len, char *response_uri, u16_t response_uri_len,
		u8_t *post_auto_wnd) {
	printf("httpd_post_begin: \n");
}

void httpd_post_finished(void *connection, char *response_uri, u16_t response_uri_len) {
	printf("httpd_post_finished: \n");
}

// this is called to process tags when constructing the webpage being sent to the user
void http_set_ssi_handler(tSSIHandler ssi_handler, const char **tags, int num_tags);  // prototype
// embedded ssi handler
const char *tagname[] = {  "temp", "pressure", "time", "led1", "sw1A", "sw1B", "sw1C", "sw1D",
		"sw2A", "sw2B", "sw2C", "sw2D", "butt1", "PG0", "PG1", "PG2", "RF1", "devid", "detinfo", (void *) NULL };
int i, j;

// the tag callback handler
tSSIHandler tag_callback(int index, char *newstring, int maxlen)
{
//  LOCK_TCPIP_CORE();

//		printf("tSSIHandler: index=0x%x, newstring=%s, maxlen=%d\n",index,newstring,maxlen);

	if ((index > 3) && (index < 12)) {		// omux array
		i = index - 4;		// 0 to 7
		i = (muxdat[0] & (1 << i));
		if (i == 0)		// around the houses
			strcpy(newstring, "0");
		else
			strcpy(newstring, "1");
//			sprintf(newstring,"<%d>",index);
	} else
		switch (index) {
		case 0:
			sprintf(newstring, "%d.%d", temperature, tempfrac);
			break;
		case 1:
			sprintf(newstring, "%d.%d", pressure, pressfrac);
			break;
		case 2:
			strcpy(newstring,nowtimestr);
			break;
		case 3:			// Led1
			if (HAL_GPIO_ReadPin(GPIOD, LED_D1_Pin) == GPIO_PIN_SET)
				strcpy(newstring, "1");
			else
				strcpy(newstring, "0");
			break;
		case 12:		// butt1
			strcpy(newstring, "5");
			break;
		case 13:	// PG0
			strcpy(newstring, (pgagain & 1) ? "1" : "0");
			break;
		case 14:	// PG1
			strcpy(newstring, (pgagain & 2) ? "1" : "0");
			break;
		case 15:	// PG2
			strcpy(newstring, (pgagain & 4) ? "1" : "0");
			break;
		case 16:	// RF1
			strcpy(newstring, (HAL_GPIO_ReadPin(GPIOE, LP_FILT_Pin) ? "0" : "1"));
			break;
		case 17:	// Device IDs
#ifdef TESTING
			sprintf(newstring, "\"STM_UUID=%lx %lx %lx, Server assigned S/N=%lu, TESTING Software S/N=%d, Ver %d.%d\"",
					STM32_UUID[0],STM32_UUID[1],STM32_UUID[2],statuspkt.uid,MY_UID,statuspkt.majorversion,statuspkt.minorversion);
#else
			sprintf(newstring, "\"STM_UUID=%lx %lx %lx, Server assigned S/N=%lu, Software S/N=%d, Ver %d.%d\"",
					STM32_UUID[0],STM32_UUID[1],STM32_UUID[2],statuspkt.uid,MY_UID,statuspkt.majorversion,statuspkt.minorversion);
#endif
//			strcpy(newstring,"17");
			break;
		case 18:	// Detector Info
			sprintf(newstring,"\"<b>Uptime</b> %d <b>secs<br><br>Last trigger</b> %s<br><br><b>Triggers</b> %d<br><br><b>Noise</b> %d<br><br><b>ADC Base</b> %d<br><br>\"",
						statuspkt.sysuptime,trigtimestr,statuspkt.trigcount,statuspkt.adcnoise,statuspkt.adcbase);
//			strcpy(newstring,"18");
			break;
		default:
			sprintf(newstring, "\"ssi_handler: bad tag index %d\"", index);
			break;
		}
//		sprintf(newstring,"index=%d",index);
//  UNLOCK_TCPIP_CORE();
	return (strlen(newstring));
}

// embedded ssi tag handler setup
init_httpd_ssi() {

	http_set_ssi_handler(tag_callback, tagname, 32);
}

/* ---------------------------------------------- */
// http client
/* ---------------------------------------------- */

// callback with the page
void returnpage(volatile u8_t Num, volatile hc_errormsg errorm, volatile char *content,
		volatile u16_t charcount) {
	char *errormsg[] = { "OK", "OUT_MEM", "TIMEOUT", "NOT_FOUND", "GEN_ERROR" };
	volatile uint32_t sn;

	if (errorm == 0) {
//		printf("returnpage: Num=%d, errorm=%d, charcount=%d, content=%s\n", Num, errorm, charcount,	content);
		if (sscanf(content, "%5u", &sn) == 1) {		// converted a number
			statuspkt.uid = sn;
			printf("A response from Server -> Serial Number Changed to %lu\n", statuspkt.uid);
		}
	} else {

		printf("returnpage: (error returned) Num=%d, errno=%d, error=%s\n", Num, errorm,
				errormsg[errorm]);
	}
}

void httpclient(char Page[64]) {
	volatile int result;
	uint32_t ip;
	int err;
	static ip_addr_t remoteip = { 0 };
	static char *Postvars = NULL;

	if (remoteip.addr == 0) {
		err = dnslookup("lightning.vk4ya.space", &remoteip);

		ip = remoteip.addr;
		printf("\nHTTP Target IP: %lu.%lu.%lu.%lu\n", ip & 0xff, (ip & 0xff00) >> 8,
				(ip & 0xff0000) >> 16, (ip & 0xff000000) >> 24);
	}

//	printf("calling hc_open\n");

	result = hc_open(remoteip, Page, Postvars, returnpage);
//	printf("result=%d\n",result);

}
