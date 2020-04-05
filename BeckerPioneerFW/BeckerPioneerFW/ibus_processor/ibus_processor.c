/*
 * ibus_processor.c
 *
 * Created: 05.04.2020 16:09:14
 *  Author: Heinrich
 */ 

#include "ibus_processor.h"

extern uint8_t adc_value;

void set_brightness (void)
{
	uint8_t msg[6];
	msg[0] = LKM;
	msg[1] = 5;
	msg[2] = GLO;
	msg[3] = adc_value;
	msg[4] = 0x00;
	
	send_ibus_message(msg);
}