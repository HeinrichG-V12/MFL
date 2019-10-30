/*
 * ibus.h
 *
 *  Created on: 30.10.2019
 *      Author: heinrich
 */

#ifndef IBUS_IBUS_H_
#define IBUS_IBUS_H_

#include <stdint.h>

typedef struct {
	uint8_t src;
	uint8_t len;
	uint8_t dst;
	uint8_t *data;
	uint8_t crc;
} ibus_msg;

void send_message( ibus_msg *msg );

void test( void );

#endif /* IBUS_IBUS_H_ */
