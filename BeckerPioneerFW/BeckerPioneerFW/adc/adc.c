/*
 * adc.c
 *
 * Created: 03.01.2020 15:46:51
 *  Author: Heinrich
 */ 

#include "adc.h"

uint8_t adc_value = 0;

void init_adc(void)
{
	ADMUX = (1 << REFS0)|(1 << MUX0)|(1 << ADLAR)|(1 << MUX1);	// adc on, left justified, avcc reference, adc3 input
	ADCSRA = (1 << ADEN)|(1 << ADIE)|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0); // ad enabled, interrupt enabled, prescaler = 128	
	// adcsrb is not used because of free runnging mode
}

ISR(ADC_vect)
{
	// If the result is left adjusted and no more than 8-bit precision is required, it is sufficient to read ADCH
	adc_value = ADCH;
}