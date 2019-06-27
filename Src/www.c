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
#include "main.h"
#include "stm32f7xx_hal.h"
#include "lwip.h"
#include "httpd_structs.h"
#include "httpclient.h"
#include "www.h"
#include "neo7m.h"
#include "udpstream.h"
//#include "httpd.h"


// Support functions


/*--------------------------------------------------*/
// httpd server support
/*--------------------------------------------------*/

void httpd_cgi_handler(const char *uri, int count, char **http_cgi_params,
		char **http_cgi_param_vals)
{
	int i;

	printf("httpd_cgi_handler: uri=%s, count=%d\n", uri, count);
	for (i=0; i<count; i++) {
		printf("param %d, id=%c, va;=%c\n",i,(*http_cgi_params)[i],(*http_cgi_param_vals)[i] );
	}
}

err_t httpd_post_receive_data(void *connection, struct pbuf *p) {
	printf("httpd_post_receive_data: \n");
}

err_t httpd_post_begin(void *connection, const char *uri,
		const char *http_request, u16_t http_request_len, int content_len,
		char *response_uri, u16_t response_uri_len, u8_t *post_auto_wnd) {
	printf("httpd_post_begin: \n");
}

void httpd_post_finished(void *connection, char *response_uri,
		u16_t response_uri_len) {
	printf("httpd_post_finished: \n");
}


//void http_set_ssi_handler(tSSIHandler ssi_handler, const char **tags, int num_tags);  // proto


// embedded ssi handler
static char *tagname[] = {"tag1","tag2","tag3",(void *)NULL};

tSSIHandler tag_callback(volatile char *tag, char *newstring, int maxlen) {
	static char *insert[] = {"TAGGED1","TAGGED2","TAGGED3"};
	int i;

	i = 0;
    while (tagname[i] != NULL) {
      if(strcmp(tag, tagname[i]) == 0)		// find tag index
    	  break;
      i++;
    }

	strcpy(newstring,insert[i]);		// display the actual replacement
	return(strlen(insert[i]));
}

// embedded ssi tag handler setup
init_httpd_ssi() {


	http_set_ssi_handler(tag_callback, tagname, 3);
}



/* ---------------------------------------------- */
// http client
/* ---------------------------------------------- */

// callback with the page
void returnpage(volatile u8_t Num, volatile hc_errormsg errorm,
		volatile char *content, volatile u16_t charcount) {
	char *errormsg[] = {
			"OK",
			"OUT_MEM",
			"TIMEOUT",
			"NOT_FOUND",
			"GEN_ERROR"
		};
	volatile uint32_t sn;


	if (errorm == 0) {
		printf("returnpage: Num=%d, errorm=%d, charcount=%d, content=%s\n", Num,
				errorm, charcount, content);
	if (sscanf(content,"%5u",&sn) == 1) {		// converted a number
		statuspkt.uid = sn;
		printf("A response from Server -> Serial Number Changed to %lu\n",statuspkt.uid);
		}
	}
	else {

		printf("returnpage: (error returned) Num=%d, errno=%d, error=%s\n", Num, errorm, errormsg[errorm]);
	}
}


void httpclient(char Page[64]) {
	volatile int result;
	uint32_t ip;
	int err;
	static ip_addr_t remoteip = { 0 };
	static char *Postvars = NULL;

	if (remoteip.addr == 0) {
		err = dnslookup(/*"192.168.1.102" *//* "b7.bayside.space" */ "lightning.vk4ya.space" ,&remoteip);

		ip = remoteip.addr;
		printf("\nHTTP Target IP: %lu.%lu.%lu.%lu\n", ip & 0xff,
				(ip & 0xff00) >> 8, (ip & 0xff0000) >> 16,
				(ip & 0xff000000) >> 24);
	}

//	printf("calling hc_open\n");

	result = hc_open(remoteip, Page, Postvars, returnpage);
//	printf("result=%d\n",result);

}
