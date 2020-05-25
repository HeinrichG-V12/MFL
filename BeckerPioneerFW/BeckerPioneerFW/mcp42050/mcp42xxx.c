/*
 * mcp42xxx.c
 *
 * Created: 27.01.2020 11:56:41
 *  Author: Heinrich
 */ 

#include "mcp42xxx.h"

void mcp42xxx_write (uint8_t channel, uint8_t value)
{
	DESELECT_CS();
	spi_write(OP_WRITE + channel);
	spi_write(value);
	SELECT_CS();
}

void mcp42xxx_shutdown (uint8_t channel)
{	
	DESELECT_CS();
	spi_write(OP_WRITE + channel);
	spi_write(1);
	SELECT_CS();
}

void mcp42xxx_release (void)
{
	mcp42xxx_write(FIRST_POT, 2);
	mcp42xxx_write(SECOND_POT, 2);
}