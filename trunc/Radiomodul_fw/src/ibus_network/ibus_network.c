/*
 * ibus_network.c
 *
 *  Created on: 02.11.2019
 *      Author: heinrich
 */


#include "ibus_network.h"

void set_bright( uint8_t value ) {
	ibus_msg msg;
	msg.src = LKM;
	msg.len = 5;
	msg.dst = GLO;
	msg.data = (uint8_t*) calloc(3, sizeof(uint8_t));
	msg.data[0] = BRIGHTNESS;
	msg.data[1] = value;
	msg.data[2] = 0x00;
	send_message(&msg);
}

void processIncomming( ibus_msg *msg ) {
	switch (msg->dst) {
	case MFL:
		processMFL(msg);
		break;
	}
}

void processMFL( ibus_msg *msg ) {

	switch (msg->dst) {
	case RAD:
		switch (msg->func) {
		case VOLUME:
			switch (msg->data[0]) {
			case VOL_INC:
				//LAUTER
				break;
			case VOL_DEC:
				//leiser;
				break;
			}
			break;
		}
		break;
	case TEL:
		switch (msg->func) {
		case RT:
			// rt wurde gedrückt
			break;
		case MIC:
			switch (msg->data[0]) {
			case MIC_PRESS:
				// gedrückt
				break;
			case MIC_LONG_PRESS:
				// lange gedrückt
				break;
			case MIC_RELEAS:
				// losgelassen
				break;
			}
			break;
		}
		break;
	}
}
