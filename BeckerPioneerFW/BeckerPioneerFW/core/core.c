/*
 * core.c
 *
 * Created: 20.06.2021 20:08:24
 *  Author: Heinrich
 */ 

#include "core.h"

void ports_pins_init (void)
{
	// init spi pins:
	DDR_SPI |= (1 << DD_MOSI)|(1 << DD_SCK)|(1 << DD_CS);
	
	// init mcp-hw pins
	MCP_HW_INT |= (1 << MCP_SHDN)|(1 << MCP_RST)|(1 << RING);		// MCP_SHDN and MCP_RST are outputs
	MCP_HW_INT_PORT |= (1 << MCP_SHDN)|(1 << MCP_RST)|(1 << RING);	// MCP_SHDN and MCP_RST high
}