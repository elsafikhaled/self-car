/*
 * EX_Interrupt.h
 *
 * Created: 17/11/2017 04:52:46 
 *  Author: El-safi
 */ 
#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

void Ex_interrupt_init(void);
/* **************************************************************************
Function Description: Setup external interrupt actually INT1.

Parameters: void

Return: void
* ***************************************************************************/

void Global_InterruptEnable(void);
/* **************************************************************************
Function Description:Enable global interrupt.

Parameters: void

Return: void
* ***************************************************************************/

#endif /* EX_INTERRUPT_H_ */