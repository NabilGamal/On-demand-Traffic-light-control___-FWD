/*
 * App_prog.c
 *
 * Created: 9/2/2022 9:40:56 PM
 *  Author: Nabil Gamal
 */ 

#include "APP/App_int.h"
#include "APP/App_config.h"
#include <util/delay.h>


static	uint8	Global_uint8YellowCarLEDState = 0;

void	App_voidInit		(void)
{
	DIO_vid_SetPinValue(DIO_uint8_PIN_26, DIO_uint8_HIGH);
	DIO_vid_Init();
	GIE_voidEnableGlobalInterrupt();
	EXTI_voidInit();
	EXTI_voidSetCallBack(&App_voidPedestrain_Interrupt);
}

void	App_voidStart		(void)
{
	uint8	Local_uint8Iterator;
	
	LED_voidLEDON(CAR_LED_GREEN);
	_delay_ms(20000);
	
	for (Local_uint8Iterator = 0 ; Local_uint8Iterator < 5; Local_uint8Iterator++)
	{
		Global_uint8YellowCarLEDState = 1;
		LED_voidBlink(CAR_LED_YELLOW);
		LED_voidLEDOFF(CAR_LED_GREEN);
		
	}
	
			Global_uint8YellowCarLEDState = 0;
	LED_voidLEDOFF(CAR_LED_YELLOW);
	LED_voidLEDON(CAR_LED_RED);
	_delay_ms(20000);
	
	for (Local_uint8Iterator = 0 ; Local_uint8Iterator < 5; Local_uint8Iterator++)
	{
		Global_uint8YellowCarLEDState = 1;
		LED_voidBlink(CAR_LED_YELLOW);
		LED_voidLEDOFF(CAR_LED_RED);

		
	}
			Global_uint8YellowCarLEDState = 0;	
			LED_voidLEDOFF(CAR_LED_YELLOW);
}

void	App_voidPedestrain_Interrupt	(void)
{
	LED_voidLEDOFF(PEDESTRAIN_LED_RED);
	
	if ((DIO_uint8_GetPinValue(CAR_LED_RED)) == DIO_uint8_HIGH)
	{
		LED_voidLEDON(PEDESTRAIN_LED_GREEN);
		LED_voidLEDON(CAR_LED_RED);
		_delay_ms(20000);
		LED_voidLEDOFF(CAR_LED_RED);
	}
	
	else if ((DIO_uint8_GetPinValue(CAR_LED_GREEN)) == DIO_uint8_HIGH || (DIO_uint8_GetPinValue(CAR_LED_YELLOW)) == DIO_uint8_HIGH)
	{
		if ((DIO_uint8_GetPinValue(CAR_LED_GREEN)) == DIO_uint8_HIGH)
		{
			LED_voidLEDON(PEDESTRAIN_LED_RED);
			_delay_ms(20000);
			LED_voidLEDOFF(PEDESTRAIN_LED_RED);
			LED_voidLEDOFF(CAR_LED_GREEN);
		}
		
		LED_voidLEDOFF(CAR_LED_YELLOW);
		LED_voidLEDOFF(PEDESTRAIN_LED_YELOW);
		
		for (uint8 Local_uint8Iterator = 0 ; Local_uint8Iterator < 10; Local_uint8Iterator++)
		{
			Global_uint8YellowCarLEDState = 1;
			LED_voidToggle(CAR_LED_YELLOW);
			LED_voidToggle(PEDESTRAIN_LED_YELOW);
			_delay_ms(10000);
		}
		Global_uint8YellowCarLEDState = 0;
		LED_voidLEDON(PEDESTRAIN_LED_GREEN);
		LED_voidLEDON(CAR_LED_RED);
		_delay_ms(20000);
		LED_voidLEDOFF(CAR_LED_RED);
	}
	
	LED_voidLEDOFF(PEDESTRAIN_LED_YELOW);
	LED_voidLEDOFF(CAR_LED_YELLOW);
	
	for (uint8 Local_uint8Iterator = 0 ; Local_uint8Iterator < 10; Local_uint8Iterator++)
	{
		Global_uint8YellowCarLEDState = 1;
		LED_voidToggle(CAR_LED_YELLOW);
		LED_voidToggle(PEDESTRAIN_LED_YELOW);
		_delay_ms(10000);
	}
	
	Global_uint8YellowCarLEDState = 0;
	LED_voidLEDOFF(PEDESTRAIN_LED_GREEN);
	LED_voidLEDON(PEDESTRAIN_LED_RED);
	
}
