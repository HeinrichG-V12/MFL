/*
 * radio_controller.c
 *
 * Created: 05.04.2020 15:27:42
 *  Author: Heinrich
 */ 

#include "radio_controller.h"

bool is_in_init = false;
bool to_be_released = false;

void controller_release (void)
{
	becker_send_release();
	pioneer_send_release();
}

void controller_init (void)
{
	// connect to becker and shutdown both pots
	pioneer_init();
	becker_init();
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