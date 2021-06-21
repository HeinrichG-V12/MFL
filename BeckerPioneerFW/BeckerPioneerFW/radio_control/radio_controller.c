/*
 * radio_controller.c
 *
 * Created: 05.04.2020 15:27:42
 *  Author: Heinrich
 */ 

#include "radio_controller.h"

bool _is_in_init = false;
bool _to_be_released = false;

bool _search_long = false;
bool _micro_long = false;

void controller_release (void)
{
	_to_be_released = true;
	release_timer();
}

void controller_init (void)
{
	// connect to becker and shutdown both pots
	pioneer_init();
	becker_init();
}

void controller_volume_increase (void)
{
	becker_volume_increase();
	pioneer_volume_increase();
	controller_release();
}

void controller_volume_decrease (void)
{
	becker_volume_decrease();
	pioneer_volume_decrease();
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
		becker_next_long();
		pioneer_next_long();
	}
	else
	{
		// kurzes druecken detektiert	
		becker_next();	
		pioneer_next();
	}
	
	controller_release();
}

void controller_exec_search_down (void)
{
	if (_search_long)
	{
		// langes druecken detektiert
		becker_back_long();
		pioneer_previous_long();
	}
	else
	{
		// kurzes druecken detektiert
		becker_back();
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