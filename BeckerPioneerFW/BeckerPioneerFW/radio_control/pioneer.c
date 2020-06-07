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
	DDRB |= (1 << DDB4);
	PORTB |= (1 << PB4);
	spi_init();
	
	#ifdef AD5293
	ad5293_reset();
	ad5293_init();
	#endif
	
	pioneer_send_release();
	SELECT_PIONEER_2();
}

void pioneer_source(void)
{
	// 2k2
	#ifdef AD5293
	ad5293_write(23);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 251);
	mcp42xxx_write(SECOND_POT, 252);
	#endif // AD5293
}

void pioneer_mute(void)
{
	// 4k4
	#ifdef AD5293
	ad5293_write(45);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 241);
	mcp42xxx_write(SECOND_POT, 251);
	#endif // MCP42050
}

void pioneer_list(void)
{
	// 6k6
	#ifdef AD5293
	ad5293_write(68);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 241);
	#endif // MCP42050
}

void pioneer_next(void)
{
	// 8k8
	#ifdef AD5293
	ad5293_write(90);
	#endif // AD5293
		
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 230);
	#endif // MCP42050
}

void pioneer_next_long(void)
{
	// 8k8
	#ifdef AD5293
	ad5293_write(90);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 240);
	mcp42xxx_write(SECOND_POT, 230);
	#endif // MCP42050
	DESELECT_PIONEER_2();
}

void pioneer_back(void)
{
	// 12k1
	#ifdef AD5293
	ad5293_write(124);
	#endif // AD5293
		
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 225);
	mcp42xxx_write(SECOND_POT, 229);
	#endif // MCP42050
}

void pioneer_back_long(void)
{
	// 12k1
	#ifdef AD5293
	ad5293_write(124);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 225);
	mcp42xxx_write(SECOND_POT, 229);
	#endif // MCP42050
	DESELECT_PIONEER_2();
}

void pioneer_volume_increase(void)
{
	// 16k8
	#ifdef AD5293
	ad5293_write(172);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 216);
	mcp42xxx_write(SECOND_POT, 215);
	#endif // MCP42050
}

void pioneer_volume_decrease(void)
{
	// 23k6
	#ifdef AD5293
	ad5293_write(242);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 197);
	mcp42xxx_write(SECOND_POT, 199);
	#endif // MCP42050
}

void pioneer_select(void)
{
	// 33k6
	#ifdef AD5293
	ad5293_write(344);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 162);
	mcp42xxx_write(SECOND_POT, 184);
	#endif // MCP42050
}

void pioneer_mode(void)
{
	// 48k6
	#ifdef AD5293
	ad5293_write(498);
	#endif // AD5293
	
	#ifdef MCP42050
	mcp42xxx_write(FIRST_POT, 135);
	mcp42xxx_write(SECOND_POT, 134);
	#endif // MCP42050
}

void pioneer_release(void)
{
	release_timer();
}

void pioneer_send_release(void)
{
	#ifdef AD5293
	ad5293_release();
	#endif // AD5293
		
	#ifdef MCP42050
	mcp42xxx_release();
	#endif // MCP42050
	
	//DESELECT_PIONEER_2();
}