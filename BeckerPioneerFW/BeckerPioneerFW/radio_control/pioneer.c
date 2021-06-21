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

void pioneer_init (void){}

void pioneer_source(void)
{	
	mcp42xxx_write(FIRST_POT, 251);
	mcp42xxx_write(SECOND_POT, 252);
}

void pioneer_mute(void)
{
	// 4k4
	mcp42xxx_write(FIRST_POT, 241);
	mcp42xxx_write(SECOND_POT, 251);
}

void pioneer_list(void)
{
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 241);
}

void pioneer_next(void)
{
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 230);
}

void pioneer_next_long(void)
{
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 230);
}

void pioneer_previous(void)
{
	mcp42xxx_write(FIRST_POT, 225);
	mcp42xxx_write(SECOND_POT, 229);
}

void pioneer_previous_long(void)
{
	mcp42xxx_write(FIRST_POT, 225);
	mcp42xxx_write(SECOND_POT, 229);
}

void pioneer_volume_increase(void)
{
	mcp42xxx_write(FIRST_POT, 216);
	mcp42xxx_write(SECOND_POT, 215);
}

void pioneer_volume_decrease(void)
{
	mcp42xxx_write(FIRST_POT, 197);
	mcp42xxx_write(SECOND_POT, 199);
}

void pioneer_select(void)
{
	mcp42xxx_write(FIRST_POT, 162);
	mcp42xxx_write(SECOND_POT, 184);
}

void pioneer_mode(void)
{
	mcp42xxx_write(FIRST_POT, 135);
	mcp42xxx_write(SECOND_POT, 134);
}

void pioneer_release(void)
{
	release_timer();
}

void pioneer_send_release(void)
{
	mcp42xxx_release();
}