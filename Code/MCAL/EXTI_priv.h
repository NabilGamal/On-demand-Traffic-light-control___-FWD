/*
 * EXTI_priv.h
 *
 * Created: 9/1/2022 5:05:02 PM
 *  Author: Nabil Gamal
 */ 


#ifndef EXTI_PRIV_H
#define EXTI_PRIV_H

#define MCUCR			(*((volatile uint8*)0x55))
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1


#define MCUCSR			(*((volatile uint8*)0x54))
#define MCUCSR			6

#define GICR			(*((volatile uint8*)0x5B))
#define GICR			6

#define GIFR			(*((volatile uint8*)0x5A))
#define GIFR			6


#define FALLING_EDGE	0
#define RISING_EDGE		1
#define LOW_LEVEL		2
#define IOC				3


#define ENABLE			0
#define DISABLE			1

#endif