/*
 * mcp42xxx.c
 *
 * Created: 27.01.2020 11:56:41
 *  Author: Heinrich
 */ 

#include "mcp42xxx.h"

void mcp42xxx_init(void)
{
	// configure as outputs
	MCP_HW_INT |= (1 << MCP_SHDN)|(1 << MCP_RST);
	
	// put mcp42xxx into shutdown, terminal A is disconnected and wiper connected to terminal B
	MCP_HW_SHDN();
	
	// reset mcp42xxx to bring the wipers to mid-scale and let them in shutdown mode until !SHDN goes high 
	MCP_HW_RESET();
	// wait at least 150ns and goes up
	MCP_HW_RESET_END();
}

void mcp42xxx_write (uint8_t channel, uint8_t value)
{
	DESELECT_CS();
	spi_write(OP_WRITE + channel);
	spi_write(value);
	SELECT_CS();
}

void mcp42xxx_release (void)
{
	MCP_HW_SHDN();
}