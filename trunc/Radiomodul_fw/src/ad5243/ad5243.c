/*
 * ad5243.c
 *
 *  Created on: 02.11.2019
 *      Author: heinrich
 */

#include "ad5243.h"
#include "../i2c/i2c.h"

extern volatile uint32_t I2CCount;
extern volatile uint8_t I2CMasterBuffer[BUFSIZE];
extern volatile uint8_t I2CSlaveBuffer[BUFSIZE];
extern volatile uint32_t I2CMasterState;
extern volatile uint32_t I2CReadLength, I2CWriteLength;

void write_value (uint8_t channel, uint8_t value) {
	I2CWriteLength = 3;
	I2CReadLength = 0;

	I2CMasterBuffer[0] = AD5243_ADDR;

	switch (channel) {
	case 0:
		I2CMasterBuffer[1] = 0x00;
		break;
	case 1:
		I2CMasterBuffer[1] = 0x80;
		break;
	}

	I2CMasterBuffer[2] = value;

	I2CEngine();
}
