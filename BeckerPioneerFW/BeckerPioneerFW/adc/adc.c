/*
 * adc.c
 *
 * Created: 03.01.2020 15:46:51
 *  Author: Heinrich
 */ 

#include "adc.h"

uint8_t adc_value = 0;

void adc_init (void)
{
	//ADMUX = (1 << REFS0)|(1 << ADLAR);	// left justified, avcc reference, adc0 input
	ADMUX = (1 << REFS0);	// avcc reference, adc0 input
	ADCSRA = (1 << ADEN)|(1 << ADIE)|(1 << ADATE)|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0); // ad enabled, start convertion, interrupt enabled, auto trigger, prescaler = 128 (125kHz)
	// adcsrb is not used because of free runnging mode
	
	ADCSRA |= (1<<ADSC);	// start first convertion
}

ISR(ADC_vect)
{
	uint16_t adc_raw_value = ADC;
	adc_value = adc_raw_value >> 2;	
}