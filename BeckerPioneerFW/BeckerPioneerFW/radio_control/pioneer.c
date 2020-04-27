/*
 * pioneer.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */


#include "pioneer.h"
#include "../timer/timer.h"
#include <stdbool.h>

extern bool _is_in_init;
extern bool _to_be_released;

void pioneer_init (void)
{
	spi_init();
	pioneer_send_release();
}

void pioneer_source(void)
{
	// 2k2
	mcp42xxx_write(FIRST_POT, 250);
	mcp42xxx_write(SECOND_POT, 251);
}

void pioneer_mute(void)
{
	// 4k4
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 250);
	
}

void pioneer_next(void)
{
	// 8k8
	mcp42xxx_write(FIRST_POT, 237);
	mcp42xxx_write(SECOND_POT, 230);
}

void pioneer_back(void)
{
	// 12k1
	mcp42xxx_write(FIRST_POT, 226);
	mcp42xxx_write(SECOND_POT, 225);
}

void pioneer_volume_increase(void)
{
	// 16k8
	mcp42xxx_write(FIRST_POT, 214);
	mcp42xxx_write(SECOND_POT, 214);
}

void pioneer_volume_decrease(void)
{
	// 23k6
	mcp42xxx_write(FIRST_POT, 196);
	mcp42xxx_write(SECOND_POT, 196);
}

void pioneer_list(void)
{
	// 6k6
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 240);
}

void pioneer_select(void)
{
	// 33k6
	mcp42xxx_write(FIRST_POT, 162);
	mcp42xxx_write(SECOND_POT, 182);
}

void pioneer_mode(void)
{
	// 48k6
	mcp42xxx_write(FIRST_POT, 135);
	mcp42xxx_write(SECOND_POT, 135);
}

void pioneer_release(void)
{
	_to_be_released = true;
	release_timer();
}

void pioneer_send_release(void)
{
	mcp42xxx_shutdown(BOTH_POTS);
}