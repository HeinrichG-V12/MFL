/*
 * mcp42xxx.c
 *
 * Created: 27.01.2020 11:56:41
 *  Author: Heinrich
 */ 

#include "mcp42xxx.h"

void mcp42xxx_write (uint8_t channel, uint8_t value)
{
	spi_write(OP_WRITE + channel);
	spi_write(value);
}

void mcp42xxx_shutdown (uint8_t channel)
{
	spi_write(OP_SHUTDOWN + channel);
}