/*
 * ibus.c
 *
 *  Created on: 30.10.2019
 *      Author: heinrich
 */

#include "ibus.h"

void send_message( ibus_msg *msg ) {

}

void test( void ) {
	ibus_msg msg;

	msg.src = 0x01;
	msg.len = 1;
	msg.dst = 0x80;
	msg.data = 0x01;
	msg.crc = 0x80;

	send_message(&msg);

}
