/*
 * timer.c
 *
 * Created: 03.01.2020 17:11:19
 *  Author: Heinrich
 */ 

#include "timer.h"

void timer0_init(void)
{
	// 8-bit timer, prescale 1024, timer clock 15625hz, click every 0.064ms
	TCCR0B = (1 << CS00)|(1 << CS02);
}

uint8_t timer0_getValue(void)
{
	// overflow occured?
	if (TIFR0 & (1 << TOV0)) {
		return 0xFF;
	}
	
	return TCNT0;	
}

void timer0_reset(void)
{
	// reset overflow
	TIFR0 = (1<<TOV0);
	// reset value
	TCNT0 = 0;
}

void timer_delay_ms (uint16_t delay)
{
	do
	{
		// timer5, prescaler 1, preload 49536, delay 0.
		TCNT5 = 49536;
		TCCR5B |= (1<<CS50);
		while ((TIFR5 & (1 << TOV5)) == 0);
		TIFR5 |= (1 << TOV5);
		delay--;
	} while (delay > 0);
}