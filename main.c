/*
 * main.c
 *
 * Created: 17/11/2017 04:48:30 
 *  Author: El-safi
 */ 
//microprocessor frequency
#define F_CPU 16000000
//choose dubugging:1 or not:0
#define DEBUG 1

//linking files.
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Timer1Compare.h"
#include "EX_Interrupt.h"
#include "ultrasonic_Cfg.h"

#if(DEBUG==1)
#include "TbUart.h"	
#endif //debugging file.

//data types that serves interrupt service routine.
volatile U16_t time_ultrasonic=0;
volatile U8_t  distance_object=0;



int main(void)
{ 
	 
//!System initialization function.	
     Global_InterruptEnable();
	 Ex_interrupt_init();
	 Timer1Compare_setup();
	#if(DEBUG==1)
		TbUart_init();
	#endif //debug_setup function
		
	
	//Background
    while(1)
    {
        //NOTE:: All Application Code is Running in Foreground :) 
		//    :: IF You try to understand my code and failed traverse there :-
		//       -Background VS Foreground https://doc.micrium.com/display/osiiidoc/Foreground-Background+Systems
		//       -Timer mode as Compare with interrupt Request http://maxembedded.com/2011/07/avr-timers-ctc-mode/
		//       -Why volatile with interrupt http://www.embedds.com/using-volatile-keyword-in-embedded-code/
    }
	return 0;
}


//FOREGROUNG.

//Compare Match interrupt
ISR(TIMER1_COMPA_vect){//start service routine for Timer Match (priority=8)
	#if(DEBUG==1)
	TbUart_Send_stri((U8_t*)"No object detected");
	TbUart_Send_char('\n');
	#endif //debug_send attention!!.
		
	//empty counter register as it reaches max without detecting any obstacles
	TCNT1=0;
	//Trigger ultrasonic again.
	//ensure that Pin PD2 output is low.
	TRIGGER_OFF;_delay_us(2);
	//start Trigger on.
	TRIGGER_ON;
	_delay_us(10);
	TRIGGER_OFF;
	//Write here your action while no object detected yet.

	
}//End of TIMER service routine.


//External interrupt service routine.
ISR(INT1_vect){//start service routine of INT1 (priority=3) 
	//calculate time.
	// 12msec           ----> 24005 counts
	// time_ultrasonic  ----> TCNT1
	time_ultrasonic=(U16_t)((Timer1Compare_Read()*12)/24005);

	//calculate distance.
	// 12msec           -----> 2meter
	// time_ultrasonic  -----> distance_object
	distance_object=(U8_t)(((time_ultrasonic*2)/12)*100);

	#if(DEBUG==1)
		TB_intNumASCII(distance_object);
	#endif //debug_send distance to terminal GUI.
	
	//empty counter register.
	TCNT1=0;
	//Trigger ultrasonic again.
	//ensure that Pin PD2 output is low.
	TRIGGER_OFF;_delay_us(2);
	//start Trigger on.
	TRIGGER_ON;
	_delay_us(10);
	TRIGGER_OFF;
	
}//End of service routine of INT1.
