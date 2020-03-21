/*
 * pioneer.c
 *
 * Created: 21.03.2020 10:22:28
 *  Author: Heinrich
 */


#include "pioneer.h"

void p_source(void)
{
	// 2k2
	mcp42xxx_write(FIRST_POT, 11);
}

void p_mute(void)
{
	// 4k4
	mcp42xxx_write(FIRST_POT, 22);
	
}

void p_next(void)
{
	// 8k8
	mcp42xxx_write(FIRST_POT, 45);
}

void p_back(void)
{
	
}

void p_increase(void)
{
	
}

void p_decrease(void)
{
	
}

void p_list(void) 
{
	
}

void p_select(void)
{
	
}

void p_mode(void)
{
	
}