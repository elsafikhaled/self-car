/*
 * Timer1Compare.h
 *
 * Created: 17/11/2017 04:51:21
 *  Author: El-safi
 */ 


#ifndef TIMER1COMPARE_H_
#define TIMER1COMPARE_H_

#include "dataTypes.h"

void Timer1Compare_setup(void);
/* ************************************************************************************************************************
Function description:# making initialization for Timer 1 registers to operate at Compare mode with external clock (16 MHZ).
                     # Default Setup - Channel A
					                 - 16MHZ
					                 - prescaler 8
						    	   	 - Tick Time is 0.5 uSec = 0.0005 mSec
									 - Top counts 65536 so (0 --> 65535) as 16bit timer resolution.
									 - Max counts to get 12 mSec is 24005in OC1A then TCNT1 : 0--->24005--->0--->24005 and so on.
					 # compared value detected interrupt is accessed and then empty the TCNT1 register to 0. 
					 # Note:: Call Global interrupt enable function in EX_interrupt.h file.				
parameters: Void.

Return: Void. 
* ************************************************************************************************************************/


U16_t Timer1Compare_Read(void);
/* **********************************************************************************************************************
Function Description: Read TCNT1 register.

Parameters: void

return: number of counts in 2 bytes
* ************************************************************************************************************************/



#endif /* TIMER1COMPARE_H_ */