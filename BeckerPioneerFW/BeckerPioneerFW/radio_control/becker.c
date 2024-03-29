/*
 * becker.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */


#include "becker.h"
#include "../timer/timer.h"
#include "global_types.h"
#include <stdbool.h>

uint8_t INIT[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x35, 0x41, 0x41, 0x35, 0x30, 0x34, CR};
	
uint8_t RELEASE[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x35, 0x35, 0x30, 0x30, 0x41, 0x45, CR};

extern bool volatile _is_in_init;

void becker_next(void)
{
	// STX 0 B F 0 9 9 0 1 6 3 CR
	uint8_t msg[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x39, 0x39, 0x30, 0x31, 0x36, 0x33, CR};
	uart1_sendCommand(msg);
}

void becker_next_long(void)
{
	// STX 0 B F 0 5 5 4 0 E E CR
	uint8_t msg[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x35, 0x35, 0x34, 0x30, 0x45, 0x45, CR};
	uart1_sendCommand(msg);
}

void becker_back(void)
{
	// STX 0 B F 0 A A 0 1 5 0 CR
	uint8_t msg[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x41, 0x41, 0x30, 0x31, 0x35, 0x30, CR};
	uart1_sendCommand(msg);
}

void becker_back_long(void)
{
	// STX 0 B F 0 5 5 0 4 A A CR	
	uint8_t msg[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x35, 0x35, 0x30, 0x34, 0x41, 0x41, CR};
	uart1_sendCommand(msg);
}

void becker_volume_increase(void)
{
	// STX 0 B F 0 5 5 0 2 A C CR
	uint8_t msg[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x35, 0x35, 0x30, 0x32, 0x41, 0x43, CR};
	uart1_sendCommand(msg);
}

void becker_volume_decrease(void)
{
	// STX 0 B F 0 5 5 0 1 A F CR
	uint8_t msg[] = {STX, 0x30, 0x42, 0x46, 0x30, 0x35, 0x35, 0x30, 0x31, 0x41, 0x46, CR};
	uart1_sendCommand(msg);
}

void becker_init(void)
{
	uart1_init();
	_is_in_init = true;
	becker_init_timer();
}

void becker_send_init (void)
{
	uart1_sendCommand(INIT);
}

void becker_send_release (void)
{
	uart1_sendCommand(RELEASE);
}