/*
 * Radio.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */

#include <avr/io.h>
#include "adc/adc.h"
#include "ibus_processor/ibus_processor.h"
#include "radio_control/radio_controller.h"

int main(void)
{
	// uint8_t data[] = {0xD0, 0x05, 0xBF, 0x5C, 0xFE, 0x00};
	// send_ibus_message(data);
	
	uint8_t* msg;
	uint8_t depth = 0;
	
	ibus_init();
	controller_init();
	adc_init();
	
	sei();
		
    while (1) 
    {
		depth = rx_buffer_get_depth();
		
		if (depth > 0)
		{
			msg = rx_buffer_get_entry();			
			ibus_processor(msg);
			rx_buffer_remove_entry();
		}
    }
}

