/*
 * Led.c
 *
 * Created: 8/31/2022 8:48:09 PM
 *  Author: Nabil Gamal
 */ 

#include "MCAL/DIO_int.h"	
#include "Library/STD_Types.h"
#include "HAL/Led_int.h"
#include "Library/BIT_MATH.h"

#include <util/delay.h>

void	LED_voidLEDON	(uint8	Copy_uint8LEDID)
{
	
	DIO_vid_SetPinValue(Copy_uint8LEDID, DIO_uint8_HIGH);
	
}

void	LED_voidLEDOFF	(uint8	Copy_uint8LEDID)
{
	
	DIO_vid_SetPinValue(Copy_uint8LEDID, DIO_uint8_LOW);	
	
}

void	LED_voidToggle	(uint8	Copy_uint8LEDID)
{
	
	if ((DIO_uint8_GetPinValue(Copy_uint8LEDID)) == DIO_uint8_HIGH)
	{
		DIO_vid_SetPinValue(Copy_uint8LEDID, DIO_uint8_LOW);
	}
	
	else if ((DIO_uint8_GetPinValue(Copy_uint8LEDID)) == DIO_uint8_LOW)
	{
		DIO_vid_SetPinValue(Copy_uint8LEDID, DIO_uint8_HIGH);
	}
	
	else
	{
		// DO Nothing
	}
	
}

void	LED_voidBlink	(uint8	Copy_uint8LEDID)
{
	if ((DIO_uint8_GetPinValue(Copy_uint8LEDID)) == DIO_uint8_HIGH)
	{
		_delay_ms(5000);
		DIO_vid_SetPinValue(Copy_uint8LEDID, DIO_uint8_LOW);
		_delay_ms(5000);
	}
	
	else if ((DIO_uint8_GetPinValue(Copy_uint8LEDID)) == DIO_uint8_LOW)
	{
		_delay_ms(5000);
		DIO_vid_SetPinValue(Copy_uint8LEDID, DIO_uint8_HIGH);
		_delay_ms(5000);
	}
	
	else
	{
		// DO Nothing
	}
}