/*
 * radio_controller.c
 *
 * Created: 05.04.2020 15:27:42
 *  Author: Heinrich
 */ 

#include "radio_controller.h"

void controller_release (void)
{
	timer_delay_ms(50);
	becker_release();
	pioneer_release();
}

void controller_init (void)
{
	// connect to becker and shutdown both pots
	becker_init();
	pioneer_init();	
}

void controller_increase (void)
{
	becker_increase();
	pioneer_increase();
	controller_release();
}

void controller_decrease (void)
{
	becker_decrease();
	pioneer_decrease();
	controller_release();
}

void controller_next (void)
{
	becker_next();
	pioneer_next();
	controller_release();
}

void controller_back (void)
{
	becker_back();
	pioneer_back();
	controller_release();
}