/*
 * App_config.h
 *
 * Created: 9/2/2022 9:40:48 PM
 *  Author: Nabil Gamal
 */ 

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#include "MCAL/DIO_int.h"
#include "MCAL/DIO_config.h"
#include "MCAL/DIO_priv.h"

#define CAR_LED_GREEN			DIO_uint8_PIN_2
#define CAR_LED_RED				DIO_uint8_PIN_0
#define CAR_LED_YELLOW			DIO_uint8_PIN_1


#define PEDESTRAIN_LED_GREEN	DIO_uint8_PIN_10
#define PEDESTRAIN_LED_RED		DIO_uint8_PIN_8
#define PEDESTRAIN_LED_YELOW	DIO_uint8_PIN_9		


#define YELLOW_LED_BLINKTIME	5000

#endif