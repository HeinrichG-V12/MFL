/*
===============================================================================
 Name        : MFL.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC13xx.h"
#endif

#include <cr_section_macros.h>
#include "i2c/i2c.h"

int main(void) {

	SystemInit();
	SysTick_Config(SystemCoreClock/1000);
	I2CInit(I2CMASTER);


    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}

void SysTick_Handler() {

}
