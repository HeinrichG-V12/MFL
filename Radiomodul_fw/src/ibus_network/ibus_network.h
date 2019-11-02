/*
 * ibus_network.h
 *
 *  Created on: 02.11.2019
 *      Author: heinrich
 */

#ifndef IBUS_NETWORK_IBUS_NETWORK_H_
#define IBUS_NETWORK_IBUS_NETWORK_H_

#include <stdint.h>
#include "../ibus/ibus.h"

// ibus message format
#define IBUS_SRC		0
#define IBUS_LENGTH		1
#define	IBUS_DST		2
#define	IBUS_FUNC		3
#define	IBUS_DATA		4

// IBUS_DEVICE IBUS_SRC (byte0) oder IBUS_DST (byte2):
#define	MFL				0x50
#define	RAD				0x68
#define	TEL				0xC8
#define LKM				0xD0
#define RLS				0xE8
#define GLO				0xBF

// IBUS_FUNC (byte3):
#define VOLUME			0x32
#define LIGHTSENSOR		0x59
#define	ARROWS			0x3B
#define	RT				0x01
#define	MIC				0x3B
#define BRIGHTNESS		0x5C

// IBUS_DATA (byte 4 and more)
#define	VOL_INC			0x11
#define	VOL_DEC			0x01
#define MIC_PRESS		0x80
#define	MIC_RELEAS		0xA0
#define MIC_LONG_PRESS	0x90

void set_bright( uint8_t value );
void processIncomming( ibus_msg *msg );
void processMFL( ibus_msg *msg );


#endif /* IBUS_NETWORK_IBUS_NETWORK_H_ */
