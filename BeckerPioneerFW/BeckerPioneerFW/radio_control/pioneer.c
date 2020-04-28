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
	pioneer_send_release();
}

void pioneer_source(void)
{
	// 2k2
	ad5293_write(1001);
}

void pioneer_mute(void)
{
	// 4k4
	ad5293_write(979);
}

void pioneer_list(void)
{
	// 6k6
	ad5293_write(956);
}

void pioneer_next(void)
{
	// 8k8
	ad5293_write(956);
}

void pioneer_back(void)
{
	// 12k1
	ad5293_write(900);
}

void pioneer_volume_increase(void)
{
	// 16k8
	ad5293_write(852);
}

void pioneer_volume_decrease(void)
{
	// 23k6
	ad5293_write(782);
}

void pioneer_select(void)
{
	// 33k6
	ad5293_write(680);
}

void pioneer_mode(void)
{
	// 48k6
	ad5293_write(526);
}

void pioneer_release(void)
{
	_to_be_released = true;
	release_timer();
}

void pioneer_send_release(void)
{
	ad5293_shutdown();
}