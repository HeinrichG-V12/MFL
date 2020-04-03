/*
 * becker.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */


#include "becker.h"
#include "global_types.h"
#include "../timer/timer.h"

uint8_t RELEASE[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x35, 0x35, 0x30, 0x30, 0x41, 0x45, CR};

uint8_t INIT[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x35, 0x41, 0x41, 0x35, 0x30, 0x34, CR};

void b_init(void)
{
	for (int i = 0; i <= 8; i++)
	{
		uart1_sendCommand(INIT);
		// warte 500ms nach dem senden!
		timer_delay_ms(500);
	}
}

void b_next(void)
{
	// STX 0 B F 0 9 9 0 1 6 3 CR
	// warte 80ms
	timer_delay_ms(80);
	uart1_sendCommand(RELEASE);
}

void b_next_long(void)
{
	// STX 0 B F 0 5 5 4 0 E E CR
}

void b_back(void)
{
	// STX 0 B F 0 A A 0 1 5 0 CR
	
}

void b_back_long(void)
{
	// STX 0 B F 0 5 5 0 4 A A CR
	
}

void b_increase(void)
{
	
}

void b_decrease(void)
{
	
}