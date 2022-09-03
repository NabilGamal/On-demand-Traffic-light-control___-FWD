/*
 * App_int.h
 *
 * Created: 9/2/2022 9:40:26 PM
 *  Author: Nabil Gamal
 */ 

#ifndef APP_INT_H_
#define APP_INT_H_

#include "Library/BIT_MATH.h"
#include "Library/STD_Types.h"
#include "MCAL/DIO_int.h"	
#include "MCAL/EXTI_int.h"
#include "HAL/LED_int.h"
#include "MCAL/GIE_int.h"
#include "MCAL/EXTI_priv.h"


void	App_voidInit					(void);
void	App_voidStart					(void);
void	App_voidPedestrain_Interrupt	(void);

#endif