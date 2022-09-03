/*
 * EXTI_int.h
 *
 * Created: 9/1/2022 5:05:32 PM
 *  Author: Nabil Gamal
 */ 

#ifndef EXTI_INT_H
#define EXTI_INT_H


void EXTI_voidSetInt (uint8 Copy_uint8Control);
void EXTI_voidInit (void);
void EXTI_voidSetCallBack (void (*Copy_pvNotificationFunction) (void));


#endif