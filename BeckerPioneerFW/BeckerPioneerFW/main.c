/*
 * Radio.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */


#include <avr/io.h>
#include "adc/adc.h"
#include "uart/uart.h"
#include "radio_control/becker.h"

extern uint16_t adc_value;

int main(void)
{
	uart0_init();
	uart1_init();
	b_init();
	
    /* Replace with your application code */
    while (1) 
    {
		adc_value++;
    }
}

