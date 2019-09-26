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

// SPI based PGA
const uint16_t spicmdchan[] = { 0x4100 };	// set chan reg 0
uint16_t pgagain = 0x4001;  // initial gain set

// dual mux
uint8_t muxdat[] = { 1 };		// sw1A (AMPout -> ADC)

//////////////////////////////////////////////
//
// Initialise and test the LEDS by cycling them
//
//////////////////////////////////////////////
void cycleleds(void) {
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
void initpga() {
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
void initdualmux(void) {
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
void getpressure(void) {
	uint8_t data[8], dataout[8];
	int i;

	data[0] = 0x55;
	while (1) {

		if (HAL_I2C_Mem_Read(&hi2c1, 0x60 << 1, 0, 1, &data[0], 1, 1000) != HAL_OK) {	// rd status reg pressure sense
			printf("I2C HAL returned error 5\n\r");
			return;
		}
//		printf("Press stat: 0x%0x\n", data[0]);

		if (data[0] & 0x08) {		// data ready
			for (i = 1; i < 6; i++) {
				if (HAL_I2C_Mem_Read(&hi2c1, 0x60 << 1, i, 1, &data[0], 1, 1000) != HAL_OK) {	// rd status reg pressure sense
					printf("I2C HAL returned error 6+\n\r");
				}
				dataout[i - 1] = data[0];
//				printf("[0x%02x] ", data[0]);
			}  // end for

			pressure = dataout[0] << 10 | dataout[1] << 2 | (dataout[2] & 0xC0) >> 6;
			pressfrac = ((dataout[2] & 0x30) >> 4) * 25;

			printf("\npressure = %d.%d  ", pressure, pressfrac);
			temperature = dataout[3];
			tempfrac = ((dataout[4] >> 4) * 625) / 1000;
			printf("temp = %d.%d\n", temperature, tempfrac);
			break;
		} 		// if data  ready
		else {
			osDelay(50);
		}
	} // while 1
}

void initpressure(void) {

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

	getpressure();
}

//////////////////////////////////////////////
//
// Initialise the splat board
//
//////////////////////////////////////////////
void initsplat(void) {
	int i, j, k;

	cycleleds();
	initdualmux();
	initpga();
	initpressure();
	osDelay(500);
}
#endif
