/*
 * ad5293.c
 *
 * Created: 28.04.2020 01:05:06
 *  Author: Heinrich
 */ 

#include "ad5293.h"

void ad5293_write (uint16_t value)
{
	uint16_t data;
	
	data = OP_COM1 + value;
	DESELECT_CS();
	spi_write((uint8_t)data);
	spi_write((uint8_t)(data >> 8));
	SELECT_CS();
}

void ad5293_reset (void)
{
	DESELECT_CS();
	spi_write((uint8_t) OP_COM3);
	spi_write((uint8_t)(OP_COM3 >> 8));
	SELECT_CS();
}

void ad5293_shutdown (void)
{
	uint16_t data;
	data = OP_COM6 + 0x1;
	DESELECT_CS();
	spi_write((uint8_t)data);
	spi_write((uint8_t)(data >> 8));
	SELECT_CS();
}