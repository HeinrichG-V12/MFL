/*
 * pioneer.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */


#include "pioneer.h"
#include "../timer/timer.h"
#include <stdbool.h>

void pioneer_init (void)
{
	mcp42xxx_init();
}


void pioneer_source(void)
{	
	mcp42xxx_write(FIRST_POT, 250);
	mcp42xxx_write(SECOND_POT, 250);
	mcp42xxx_wakeup();
}

void pioneer_mute(void)
{
	// 4k4
	mcp42xxx_write(FIRST_POT, 241);
	mcp42xxx_write(SECOND_POT, 251);
	mcp42xxx_wakeup();
}

void pioneer_list(void)
{
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 241);
	mcp42xxx_wakeup();
}

void pioneer_next(void)
{
	mcp42xxx_write(FIRST_POT, 236);
	mcp42xxx_write(SECOND_POT, 236);
	mcp42xxx_wakeup();
}

void pioneer_next_long(void)
{
	/*
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 230);
	mcp42xxx_wakeup();
	*/
	
	mcp42xxx_write(FIRST_POT, 253);
	mcp42xxx_write(SECOND_POT, 254);
	mcp42xxx_wakeup();
}

void pioneer_previous(void)
{
	mcp42xxx_write(FIRST_POT, 228);
	mcp42xxx_write(SECOND_POT, 228);
	mcp42xxx_wakeup();
}

void pioneer_previous_long(void)
{
	mcp42xxx_write(FIRST_POT, 225);
	mcp42xxx_write(SECOND_POT, 229);
	mcp42xxx_wakeup();
}

void pioneer_volume_increase(void)
{
	mcp42xxx_write(FIRST_POT, 216);
	mcp42xxx_write(SECOND_POT, 215);
	mcp42xxx_wakeup();
}

void pioneer_volume_decrease(void)
{
	mcp42xxx_write(FIRST_POT, 197);
	mcp42xxx_write(SECOND_POT, 199);
	mcp42xxx_wakeup();
}

void pioneer_select(void)
{
	mcp42xxx_write(FIRST_POT, 162);
	mcp42xxx_write(SECOND_POT, 184);
	mcp42xxx_wakeup();
}

void pioneer_mode(void)
{
	mcp42xxx_write(FIRST_POT, 135);
	mcp42xxx_write(SECOND_POT, 134);
	mcp42xxx_wakeup();
}

void pioneer_send_release(void)
{
	mcp42xxx_shutdown();
}