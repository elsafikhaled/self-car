/*
 * Timer1Compare.c
 *
 * Created: 17/11/2017 04:51:43 
 *  Author: El-safi
 */ 
#include "Timer1Compare.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void Timer1Compare_setup(void){//start setup for Channel A
//Compare Output Mode, non-PWM
 //Normal port operation, OC1A/OC1B disconnected.
   TCCR1A &=~((1<<COM1A1)|(1<<COM1A0));
 //Not PWM mode so must set bit3  
   TCCR1A |=(1<<FOC1A);
 //Waveform Generation Mode depend on CTC at OCR1A value.
   TCCR1A &=~((1<<WGM10)|(1<<WGM11)); 	
   TCCR1B |=(1<<WGM12);
   TCCR1B &=~(1<<WGM13);
 //clkI/O/8 (From prescaler)
   TCCR1B |=(1<<CS11);
 //reset counter storage register to 0
   TCNT1=0;
 //compare value.this value is compared with TCNT1 value when a match detected an interrupt is fired.
   OCR1A=24005;  
//interrupt initialization.
 //enable compare mode match interrupt flag status.
   TIFR |=(1<<OCF1A);  
 //enable compare mode match interrupt.        	
   TIMSK |=(1<<OCIE1A);
      
}// End of Setup function.


U16_t Timer1Compare_Read(void){//Start reading
//return number of counts.	
	return TCNT1;
	
}// End of reading function.
