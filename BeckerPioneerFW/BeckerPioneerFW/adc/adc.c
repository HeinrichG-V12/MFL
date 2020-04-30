/*
 * adc.c
 *
 * Created: 03.01.2020 15:46:51
 *  Author: Heinrich
 */ 

#include "adc.h"

uint8_t adc_value = 250;

void adc_init (void)
{
	ADMUX = (1 << REFS0)|(1 << ADLAR);	// adc on, left justified, avcc reference, adc0 input
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADIE)|(1<<ADATE)|(1<<ADPS2)|(1<<ADPS0); // ad enabled, interrupt enabled, prescaler = 128
	// adcsrb is not used because of free runnging mode
}

ISR(ADC_vect)
{
	// If the result is left adjusted and no more than 8-bit precision is required, it is sufficient to read ADCH
	adc_value = ADCH + 5;
}