/*
 * radio_controller.c
 *
 * Created: 05.04.2020 15:27:42
 *  Author: Heinrich
 */ 

#include "radio_controller.h"

volatile bool _is_in_init = false;
volatile bool _to_be_released = false;
volatile bool _search_long = false;
volatile bool _micro_long = false;

void controller_release (void)
{
	_to_be_released = true;
	start_release_timer();
}

void controller_init (void)
{
	// connect to becker and shutdown both pots
	pioneer_init();
}

void controller_volume_increase (void)
{
	pioneer_volume_increase();
	controller_release();
}

void controller_volume_decrease (void)
{
	pioneer_volume_decrease();
	controller_release();
}

void controller_next (void)
{
	pioneer_next();
	controller_release();
}

void controller_back (void)
{
	pioneer_previous();
	controller_release();
}

void controller_set_search (bool state)
{
	_search_long = state;
}

void controller_exec_search_up (void)
{
	if (_search_long) 
	{
		// langes druecken detektiert
		pioneer_next_long();
	}
	else
	{
		// kurzes druecken detektiert	
		pioneer_next();
	}
	
	controller_release();
}

void controller_exec_search_down (void)
{
	if (_search_long)
	{
		// langes druecken detektiert
		pioneer_previous_long();
	}
	else
	{
		// kurzes druecken detektiert
		pioneer_previous();
	}
		
	controller_release();
}

void controller_set_micro (bool state)
{
	_micro_long = state;
}

void controller_exec_micro (void)
{
	// pruefen, ob _micro_long true oder false ist und entsprechend reagieren
}

void controller_rt (void)
{
	// mach was sinnvolles
}