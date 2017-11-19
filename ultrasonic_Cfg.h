/*
 * ultrasonic_Cfg.h
 *
 * Created: 17/11/2017 04:49:56 
 *  Author: El-safi
 */ 


#ifndef ULTRASONIC_CFG_H_
#define ULTRASONIC_CFG_H_
#include <avr/io.h>

#define TRIGGER_ON   PORTD |=(1<<PD2)
#define TRIGGER_OFF  PORTD &=~(1<<PD2)



/* ***************************************************************************
 Ultrasonic sensor Connection::
 VCC: +5VDC
 Trig : Trigger (OUTPUT) 10 uSec - PD2
 Echo: Echo (INPUT) to INT1      - PD3
 GND: GND
 * *************************************************************************/
void GPIO_Setup(void);
/* **************************************************************************
Function Description:Enable PORTD.

Parameters: void

Return: void
* ***************************************************************************/



#endif /* ULTRASONIC_CFG_H_ */