/*
 * timer.c
 *
 * Created: 03.01.2020 17:11:19
 *  Author: Heinrich
 */ 

#include "timer.h"
#include "../radio_control/becker.h"
#include "../radio_control/pioneer.h"
#include "../ibus_processor/ibus_processor.h"
#include <stdbool.h>
#include <avr/interrupt.h>

extern volatile bool _is_in_init;
extern volatile bool _to_be_released;

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
		TCCR5B |= (1 << CS50);
		while ((TIFR5 & (1 << TOV5)) == 0);
		TIFR5 |= (1 << TOV5);
		delay--;
	} while (delay > 0);
}

// timer für die Initialisierung des Becker-Interfaces, Timer feuert alle 500ms
void becker_init_timer (void)
{
	TCNT4 = 34286;
	TCCR4B |= (1 << CS42);
	TIMSK4 |= (1 << TOIE4);
}

/*
// timer zum senden des Release Befehls, Timer feuert alle 80ms
void release_timer (void)
{
	TCNT4 = 64286;
	TCCR4B |= (1 << CS42)|(1 << CS40);	// prescaler 1024
	TIMSK4 |= (1 << TOIE4);
}
*/

// timer zum senden des Release Befehls, Timer feuert alle 10ms
void start_release_timer (void)
{
	TCNT4 = 63036;
	TCCR4B |= (1 << CS41)|(1 << CS40);	// prescaler 64
	TIMSK4 |= (1 << TOIE4);
}

void stop_release_timer (void)
{
	TCCR4B &= ~((1 << CS41)|(1 << CS40));
}

// update der Tastenbeleuchtung
void scheduler_init (void)
{
	TCNT3 = SCHEDULER_PRELOAD;
	TCCR3B |= (1<<CS32);
	TIMSK3 |= (1<<TOIE3);
}

void becker_disable_init_timer (void)
{
	TCCR4B &= ~(1 << CS42);
}

ISR(TIMER3_OVF_vect)
{
	TCNT3 = SCHEDULER_PRELOAD;
	set_brightness();
}

ISR(TIMER4_OVF_vect)
{	
	static uint8_t timerEventCounter = 0;
	static uint8_t msgCounter = 0;
	
	if(_is_in_init)
	{
		if (msgCounter < 8)
		{
			TCNT4 = 34286;
			becker_send_init();
			msgCounter++;
		}
		else
		{
			_is_in_init = false;
			becker_disable_init_timer();
		}
	}
	
	if(_to_be_released)
	{
		TCNT4 = 63036;
		timerEventCounter++;
				
		if (timerEventCounter == 8)
		{
			becker_send_release();
		}
		
		if (timerEventCounter == 10)
		{
			pioneer_send_release();
			_to_be_released = false;
			stop_release_timer();
			timerEventCounter = 0;
		}
	}
}