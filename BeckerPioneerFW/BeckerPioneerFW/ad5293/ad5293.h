/*
 * ad5293.h
 *
 * Created: 28.04.2020 01:05:19
 *  Author: Heinrich
 */ 


#ifndef AD5293_H_
#define AD5293_H_

#include "../spi/spi.h"
#include <stdint.h>

#define OP_COM0		0x000	// NOP
#define OP_COM1		0x400	// Write contents of serial register data to RDAC.
#define	OP_COM2		0x800	// Read RDAC wiper setting from SDO output in the next frame.
#define OP_COM3		0x1000	// Reset. Refresh RDAC with midscale code.
#define OP_COM4		0x1800	// Write contents of serial register data to control register.
#define OP_COM5		0x1C00	// Read control register from SDO output in the next frame.
#define OP_COM6		0x2000	// Software power-down, normal mode or +0x1 for shutdown

void ad5293_write (uint16_t value);
void ad5293_shutdown (void);

#endif /* AD5293_H_ */