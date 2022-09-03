/*
 * EXTI_prog.c
 *
 * Created: 9/1/2022 5:06:14 PM
 *  Author: Nabil Gamal
 */ 

#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL/EXTI_int.h"
#include "MCAL/EXTI_priv.h"
#include "MCAL/EXTI_config.h"
#include "MCAL/DIO_int.h"
//#define F_CPU 8000000UL
#include <util/delay.h>



static void (*EXTI_CallBack)(void) = NULL;

void EXTI_voidInit (void)
{
	#if	EXTI_ENALBE == ENABLE
	SET_BIT(GICR, GICR);
	
	#if	Copy_uint8Control == LOW_LEVEL
	CLEAR_BIT(MCUCR, MCUCR_ISC01);
	CLEAR_BIT(MCUCR, MCUCR_ISC00);
	
	#elif Copy_uint8Control == IOC
	CLEAR_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);
	
	#elif Copy_uint8Control == FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLEAR_BIT(MCUCR, MCUCR_ISC00);
	
	#elif Copy_uint8Control == RISING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);
	
	#else
	#error "EXTI_ENALBE Error Configuration"
	
	#endif
	
	#elif EXTI_ENALBE == DISABLE
	CLEAR_BIT(GICR, GICR);
	
	#else
	#error "EXTI_ENALBE Error Configuration"
	
	#endif
}


void EXTI_voidSetInt (uint8 Copy_uint8Control)
{
	
	switch (Copy_uint8Control)
	{
		case LOW_LEVEL:
		{
			CLEAR_BIT(MCUCR, MCUCR_ISC01);
			CLEAR_BIT(MCUCR, MCUCR_ISC00);
			break;
			
		}
		
		case IOC:
		{
			CLEAR_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
			break;
			
		}
		
		case FALLING_EDGE:
		{
			SET_BIT(MCUCR, MCUCR_ISC01);
			CLEAR_BIT(MCUCR, MCUCR_ISC00);
			break;
			
		}
		
		case RISING_EDGE:
		{
			SET_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
			break;
			
		}
		
		default:
		{
			
			break;
			
		}
		
	}
	
	SET_BIT(GICR, GICR);
	
}



void EXTI_voidSetCallBack (void (*Copy_Ptr) (void))
{
	EXTI_CallBack = Copy_Ptr;
}


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_CallBack != NULL)
	{
		EXTI_CallBack();
	}
	
	else
	{

	}
}