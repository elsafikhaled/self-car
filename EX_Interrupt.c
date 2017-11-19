/*
 * EX_Interrupt.c
 *
 * Created: 17/11/2017 04:53:03 
 *  Author: El-safi
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "EX_Interrupt.h"

void Ex_interrupt_init(void){//start External Interrupt function below !!
//setup INT1
 //Falling edge request interrupt.	
   MCUCR |=(1<<ISC11);	
 //enable INT1	
   GICR |=(1<<INT1);
   
}// End of EX-interrupt Function.

void Global_InterruptEnable(void){//start enable function below
//enable global interrupt
	 sei();
}// End of enable global function.