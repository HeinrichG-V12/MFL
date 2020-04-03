/*
 * timer.c
 *
 * Created: 03.01.2020 17:11:19
 *  Author: Heinrich
 */ 

#include "timer.h"

void timer0_init(void)
{
	TCCR0B = (1 << CS00)|(1 << CS02);
}


uint8_t timer0_getValue(void)
{
	if (TIFR0 & (1 << TOV0)) {
		return 0xFF;
	}
	return TCNT0;	
}

void timer0_reset(void)
{
	TIFR0 = (1<<TOV0);
	TCNT0 = 0;
}

void timer_delay_ms (uint16_t delay)
{
	do
	{
		// timer5, prescaler 1, preload 50790, delay 0.
		TCNT5 = 50790;
		TCCR5B |= (1<<CS50);
		while ((TIFR5 & (1 << TOV5)) == 0);
		TIFR5 |= (1 << TOV5);
		delay--;
	} while (delay > 0);
}