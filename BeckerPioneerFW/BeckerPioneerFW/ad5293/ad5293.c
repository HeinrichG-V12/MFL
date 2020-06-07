/*
 * ad5293.c
 *
 * Created: 28.04.2020 01:05:06
 *  Author: Heinrich
 */ 

#include "ad5293.h"

void ad5293_init (void)
{
	uint16_t data = 0;
	data |= (1 << 12)|(1 << 11)|(1 << 1);
	DESELECT_CS();
	spi_write16(data);
	SELECT_CS();
}

void ad5293_write (uint16_t value)
{	
	uint16_t data;
	data = OP_COM1 + value;
	DESELECT_CS();
	spi_write16(data);	
	SELECT_CS();
}

void ad5293_reset (void)
{
	uint16_t data;
	data = OP_COM3;
	DESELECT_CS();
	spi_write16(data);
	SELECT_CS();
}

void ad5293_shutdown (bool state)
{
	uint16_t data;
	
	if (state)
	{
		data = OP_COM6 + 0x1;
	}
	else 
	{
		data = OP_COM6;
	}
	
	DESELECT_CS();
	spi_write16(data);
	SELECT_CS();
}

void ad5293_release (void)
{
	ad5293_write(1020);
}