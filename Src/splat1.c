/*
 * splat1.c
 *
 *  Created on: 26Sep.,2019
 *      Author: bob
 */

/*
 * splat1.c
 *
 *  Created on: 28 Sept.2019
 *      Author: bob
 */

/*
 * splat1.c
 *
 * Splat1 daughter board support
 *
 * Splat1 contains Bandpass filter,  RF switches, PGA Amp, Output Muxes, LEDS
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "stm32f7xx_hal.h"
#include "version.h"
#include "neo7m.h"
#include "adcstream.h"
#include "main.h"
#include <time.h>


#ifdef SPLAT1

#include "splat1.h"

extern SPI_HandleTypeDef hspi2;
extern I2C_HandleTypeDef hi2c1;

// globs for pressure sensor results
uint32_t pressure, pressfrac, temperature, tempfrac;

// MPL115A2 (cheapo pressure sensor compensation coeficients)
static double a0, b1, b2, c12;

// SPI based PGA
const uint16_t spicmdchan[] = { 0x4100 };	// set chan reg 0
uint16_t pgagain = 0x4001;  // initial gain set

// dual mux
uint8_t muxdat[] = { 1 };		// sw1A (AMPout -> ADC)
uint32_t logampmode = 0;	// log amp mode flag

//////////////////////////////////////////////
//
// Initialise and test the LEDS by cycling them
//
//////////////////////////////////////////////
void cycleleds(void)
{
	const uint16_t pattern[] = {
	LED_D1_Pin,
	LED_D1_Pin | LED_D2_Pin,
	LED_D1_Pin | LED_D2_Pin | LED_D3_Pin,
	LED_D1_Pin | LED_D2_Pin | LED_D3_Pin | LED_D4_Pin,
	LED_D1_Pin | LED_D2_Pin | LED_D3_Pin | LED_D4_Pin | LED_D5_Pin };

	int i;

	for (i = 0; i < 5; i++) {
		HAL_GPIO_WritePin(GPIOD, pattern[i], GPIO_PIN_RESET);
		osDelay(140);
	}
	osDelay(600);
	for (i = 0; i < 5; i++) {
		HAL_GPIO_WritePin(GPIOD, pattern[i], GPIO_PIN_SET);
		osDelay(140);
	}
	osDelay(500);
	for (i = 0; i < 5; i++) {
		HAL_GPIO_WritePin(GPIOD, pattern[i], GPIO_PIN_RESET);
		osDelay(140);
	}
}

//////////////////////////////////////////////
//
// Init RF Switch (low pass filter or bypass input)
//
//////////////////////////////////////////////
void initrfswtch(void)
{
	HAL_GPIO_WritePin(GPIOE, LP_FILT_Pin, GPIO_PIN_RESET);// select RF Switches to LP filter (normal route)
}

//////////////////////////////////////////////
//
// Set the Programmable Gain Amplifier GAIN
//
//////////////////////////////////////////////
void setpgagain(int gain)
{
	osDelay(5);
	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_SET);	// deselect the PGA
	osDelay(5);
	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_RESET);	// select the PGA
	osDelay(5);
	pgagain = 0x4000 | (gain & 0x07);
	HAL_SPI_Transmit(&hspi2, &pgagain, 1, 1000);	// select gain
	osDelay(5);
	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_SET);	// deselect the PGA
}

//////////////////////////////////////////////
//
// Initialise the Programmable Gain Amplifier MCP6S93
//
//////////////////////////////////////////////
void initpga()
{
	// init spi based single ended PG Amp
	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_SET);	// deselect the PGA

	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_RESET);	// reset the PGA seq
	osDelay(50);
	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_SET);	// deselect the PGA
	osDelay(50);

	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_RESET);	// select the PGA
	HAL_SPI_Transmit(&hspi2, (uint16_t[] ) { 0 }, 1, 1000);	// nop cmd
	{
		volatile int dly;
		for (dly = 0; dly < 50; dly++)
			;
	}
	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_SET);	// deselect the PG
	osDelay(50);

	HAL_GPIO_WritePin(GPIOG, CS_PGA_Pin, GPIO_PIN_RESET);	// select the PGA
	//osDelay(5);
	HAL_SPI_Transmit(&hspi2, &spicmdchan[0], 1, 1000);	// set the channel to ch1
	{
		volatile int dly;
		for (dly = 0; dly < 50; dly++)
			;
	}
	setpgagain(1);			// 1 == gain of 2x

}

//////////////////////////////////////////////
//
// Initialise the dual mux ADG729
//
//////////////////////////////////////////////
void initdualmux(void)
{
	//HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)

	if (HAL_I2C_Master_Transmit(&hi2c1, 0x44 << 1, &muxdat[0], 1, 1000) != HAL_OK) {	// RF dual MUX
		printf("I2C HAL returned error 1\n\r");
	}
}

//////////////////////////////////////////////
//
// get the pressure and put in globals
//
//////////////////////////////////////////////
void getpressure315(void)
{
	uint8_t data[8], dataout[8];
	int i;
	HAL_StatusTypeDef result;

	data[0] = 0x55;
	while (1) {

		result = HAL_I2C_Mem_Read(&hi2c1, 0x60 << 1, 0, 1, &data[0], 1, 1000);// rd status reg pressure sense
		if (result != HAL_OK) {
			printf("Splat1-1 I2C HAL returned error %d\n\r", result);
			return;
		}
//		printf("Press stat: 0x%0x\n", data[0]);

		if (data[0] & 0x08) {		// data ready
			for (i = 1; i < 6; i++) {
				HAL_I2C_Mem_Read(&hi2c1, 0x60 << 1, i, 1, &data[0], 1, 1000);	// rd status reg pressure sense
				if (result != HAL_OK) {
					printf("Splat1-2 I2C HAL returned error %d\n\r", result);
				}
				dataout[i - 1] = data[0];
//				printf("[0x%02x] ", data[0]);
			}  // end for

			pressure = dataout[0] << 10 | dataout[1] << 2 | (dataout[2] & 0xC0) >> 6;
			pressfrac = ((dataout[2] & 0x30) >> 4) * 25;
//			printf("\npressure = %d.%d  ", pressure, pressfrac);
			temperature = dataout[3];
			tempfrac = ((dataout[4] >> 4) * 625) / 1000;
//			printf("temp = %d.%d\n", temperature, tempfrac);
			break;
		} 		// if data  ready
		else {
			osDelay(50);
		}
	} // while 1
}


// 115 pressure sensor
void getpressure115(void)
{
	uint8_t data[8], dataout[8];
	int i;
	HAL_StatusTypeDef result;
	double p, t;
	uint16_t pr, tr;

	if (HAL_I2C_Master_Transmit(&hi2c1, 0x60 << 1, (uint8_t[] ) { 0x12, 0x00 }, 2, 1000) != HAL_OK) {	// CMD Start Conversion
		printf("I2C 115 HAL returned error 7\n\r");
	}
	osDelay(4);		// conversion time max 3mS

	if (HAL_I2C_Master_Transmit(&hi2c1, 0x60 << 1, (uint8_t[] ) { 0x00 }, 1, 1000) != HAL_OK) {	// CMD Read press etc
		printf("I2C 115 HAL returned error 8\n\r");
	}

	if (HAL_I2C_Master_Receive(&hi2c1, (0x60 << 1) | 0x01, data, 4, 1000) != HAL_OK) {	// press and temp
		printf("I2C 115 HAL returned error 9\n\r");
	}
#if 0
	printf("Pressure, Temp: ");
	for (i=0; i<4; i++)
	{
		printf(" %x",data[i]);
	}
	printf("\n");
#endif
	pr = (data[0] << 2) | ((data[1] & 0xc0) >> 6);
	tr = (data[2] << 2) | ((data[3] & 0xc0) >> 6);

//	pr = pr >> 6;
//	tr = tr >> 6;

//pr = 410;
//	tr = 507;
//a0 = 2009.75; b1 = -2.37585; b2 = -0.92047; c12 = 0.000790;

//	printf("Raw: Press=%d, Temp=%d\n",pr,tr);

	p = pr;
	t = tr;

// Pcomp = a0 + (b1 + c12 x Tadc) x Padc + b2 x Tadc

	p = (a0 + ((b1 + (c12 * t)) * p)) + (b2 * t);
//	printf("Comp: Press = %f\n",p);

	p = (p * ((115.0-50.0) / 1023.0)) + 50.0;
//	printf("kPA Press = %f\n",p);

//	pr = p;
	pressure = floor(p);
	pressfrac = 0;
//			printf("\npressure = %d.%d  ", pressure, pressfrac);
	temperature = 0;
	tempfrac = 0;
}


// the cheap pressure sensor
void initpressure115(void)
{
	uint8_t data[8];
	int16_t wdata[4];
	int16_t a0co, b1co, b2co, c12co;

	int i;

	for (i=0; i<8; i++)
		data[i] = 0x55;

	if (HAL_I2C_Master_Transmit(&hi2c1, 0x60 << 1, (uint8_t[] ) { 0x04 }, 1, 1000) != HAL_OK) {	// CMD Read “Coefficient data byte 1 High byte” = 0x04
		printf("I2C 115 HAL returned error 5\n\r");
	}

	if (HAL_I2C_Master_Receive(&hi2c1, (0x60 << 1) | 0x01, data, 8, 1000) != HAL_OK) {	// Coefficient data byte 1 High byte
		printf("I2C 115 HAL returned error 6\n\r");
	}
		else {
			a0co = (data[0] << 8) | data[1];
			b1co = (data[2] << 8) | data[3];
			b2co = (data[4] << 8) | data[5];
			c12co = ((data[6] << 8) | data[7]) >> 2;

//			a0co = 0x3ECE ; b1co = 0xB3F9; b2co = 0xC517; c12co = 0x33C8;

//			printf("a0=%d, b1=%d, b2=%d, c12=%d\n",a0co,b1co,b2co,c12co);

			a0 = (double)a0co  / (double)(1 << 3);
			b1 = (double)b1co  / (double)(1 << 13);
			b2 = (double)b2co  / (double)(1 << 14);
			c12 = (double)c12co  / (double)(1 << 24);

//			printf("a0=%f, b1=%f, b2=%f, c12=%f\n",a0,b1,b2,c12);
		}
	getpressure115();
}

void initpressure315(void)
{

	//HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)

	if (HAL_I2C_Master_Transmit(&hi2c1, 0x60 << 1, (uint8_t[] ) { 0x26, 0x38 }, 2, 1000) != HAL_OK) {	// set pressure mode OSR=128 pressure sense
		printf("I2C HAL returned error 2\n\r");
	}
	if (HAL_I2C_Master_Transmit(&hi2c1, 0x60 << 1, (uint8_t[] ) { 0x13, 0x07 }, 2, 1000) != HAL_OK) {	// enbl data flags pressure sense
		printf("I2C HAL returned error 3\n\r");
	}
	if (HAL_I2C_Master_Transmit(&hi2c1, 0x60 << 1, (uint8_t[] ) { 0x26, 0x39 }, 2, 1000) != HAL_OK) {	// set active pressure sense
		printf("I2C HAL returned error 4\n\r");
	}

	getpressure315();
}

//////////////////////////////////////////////
//
// Initialise the splat board
//
//////////////////////////////////////////////
void initsplat(void)
{
	int i, j, k;

	cycleleds();
	initdualmux();
	initpga();
//	initpressure315();
	initpressure115();
	osDelay(500);
}
#endif
