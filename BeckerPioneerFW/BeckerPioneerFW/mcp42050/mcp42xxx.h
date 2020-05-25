/*
 * mcp42xxx.h
 *
 * Created: 27.01.2020 11:56:12
 *  Author: Heinrich
 */ 


#ifndef MCP42XXX_H_
#define MCP42XXX_H_

#include "../spi/spi.h"

#define OP_WRITE		0x10
#define OP_SHUTDOWN		0x20

#define	FIRST_POT		0x1
#define SECOND_POT		0x2
#define BOTH_POTS		0x3

void mcp42xxx_write (uint8_t channel, uint8_t value);
void mcp42xxx_shutdown (uint8_t channel);
void mcp42xxx_release (void);

#endif /* MCP42XXX_H_ */