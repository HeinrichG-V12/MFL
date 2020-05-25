/*
 * ibus_processor.c
 *
 * Created: 05.04.2020 16:09:14
 *  Author: Heinrich
 */ 

#include "ibus_processor.h"
#include "../radio_control/radio_controller.h"

extern uint8_t adc_value;
bool _scheduler_initialized = false;

void set_brightness (void)
{
	uint8_t msg[5];
	msg[0] = DEV_LKM;
	msg[1] = 0x05;
	msg[2] = DEV_GLO;
	msg[3] = BRIGHTNESS;
	msg[4] = adc_value;
	msg[5] = 0x00;
	
	send_ibus_message(msg);
	
	if (!_scheduler_initialized)
	{
		scheduler_init();
		_scheduler_initialized = true;
	}
}

void device_status_ready (uint8_t source)
{
	uint8_t msg[5];
	
	msg[0] = source;
	msg[1] = 0x04;
	msg[2] = DEV_LOC;
	msg[3] = 0x02;
	msg[4] = 0x00;
	
	send_ibus_message(msg);
}

void device_status_ready_after_reset (uint8_t source)
{
	uint8_t msg[5];
	
	msg[0] = source;
	msg[1] = 0x04;
	msg[2] = DEV_LOC;
	msg[3] = 0x02;
	msg[4] = 0x01;
	
	send_ibus_message(msg);
}

// direkt nach dem einschalten sendet MFL zwei Botschaften (jeweils 3x):
// 0x50 0x3 0xd0 0x5d 0xde: MFL  --> LKM : Light dimmer status request, wird mit einem set_brightness() beantwortet
// 0x50 0x3 0xc8 0x01 0x9a: MFL  --> TEL : Device status request, wird mit einem TEL  --> LOC : Device status ready after Reset (C8 04 FF 02 01 30)

void ibus_processor (uint8_t *msg)
{
	switch (msg[IBUS_SRC])
	{
		// von wem kommt die Botschaft?
		case DEV_MFL:
			switch(msg[IBUS_DST])
			{
				// an wen ist die Botschaft gerichtet?
				case DEV_RAD:
					switch(msg[IBUS_FUNC])
					{
						case WHEEL_VOLUME:
							switch (msg[IBUS_DATA])
							{
								case VOLUME_INC:
									controller_volume_increase();
								break;
								
								case VOLUME_DEC:
									controller_volume_decrease();
								break;
							}
						break;
						
						case WHEEL_SEARCH:
							switch (msg[IBUS_DATA])
							{
								case SEARCH_UP:
									controller_set_search(false);
								break;
								
								case SEARCH_UP_LONG:
									controller_set_search(true);
								break;
								
								case SEARCH_UP_RELEASE:
									controller_exec_search_up();
								break;
								
								case SEARCH_DOWN:
									controller_set_search(false);
								break;
								
								case SEARCH_DOWN_LONG:
									controller_set_search(false);
								break;
								
								case SEARCH_DOWN_RELEASE:
									controller_exec_search_down();
								break;
							}
						break;
					}
				break;
				
				case DEV_LKM:
					switch(msg[IBUS_FUNC])
					{
						case LIGHT_DIMMER_STATUS:							
							set_brightness();						
						break;
					}
				break;
				
				case DEV_TEL:
					switch(msg[IBUS_FUNC])
					{
						case DEVICE_STATUS_REQ:
							device_status_ready_after_reset(DEV_TEL);						
						break;
						
						case WHEEL_MICRO:
							switch (msg[IBUS_DATA])
							{
								case MICRO:
									controller_set_micro(false);
								break;
							
								case MICRO_LONG:
									controller_set_micro(true);
								break;
							
								case MICRO_RELEASE:
									controller_exec_micro();
								break;
							}
						break;
					}
				break;
			}
		break;
	}
}
