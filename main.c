/*
 * main.c
 *
 * Created: 17/11/2017 04:48:30 
 *  Author: El-safi
 */ 

#include "Timer1Compare.h"
#include "EX_Interrupt.h"
#include "ultrasonic_Cfg.h"
#define F_CPU 16000000


int main(void)
{  
//!System initialization function.	
    Global_InterruptEnable();
	Ex_interrupt_init();
	Timer1Compare_setup();
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

