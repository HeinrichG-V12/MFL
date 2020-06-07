/*
 * Radio.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */

#ifndef F_CPU
/* Definiere F_CPU, wenn F_CPU nicht bereits vorher definiert 
   (z.&nbsp;B. durch Übergabe als Parameter zum Compiler innerhalb 
   des Makefiles). Zusätzlich Ausgabe einer Warnung, die auf die
   "nachträgliche" Definition hinweist */
#warning "F_CPU war noch nicht definiert, wird nun mit 16MHz definiert"
#define F_CPU 16000000UL     /* Quarz mit 16 Mhz */
#endif

#include <avr/io.h>
#include "adc/adc.h"
#include "ibus_processor/ibus_processor.h"
#include "radio_control/radio_controller.h"

int main(void)
{
	uint8_t* msg;
	uint8_t depth = 0;
	
	// sei();
	adc_init();
	ibus_init();
	controller_init();
// 	// scheduler_init();
	
	

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

