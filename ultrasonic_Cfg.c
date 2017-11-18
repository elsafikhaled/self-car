/*
 * ultrasonic_Cfg.c
 *
 * Created: 18/11/2017 01:49:27 
 *  Author: El-safi
 */ 
#include "ultrasonic_Cfg.h"



void GPIO_Setup(void){//start setup GPIO
//Trigger pin:OUTPUTS
	DDRD|=(1<<PD2);
//ECHO pin:INPUT
    DDRD&=~(1<<PD3);
		
}// End of GPIO function.