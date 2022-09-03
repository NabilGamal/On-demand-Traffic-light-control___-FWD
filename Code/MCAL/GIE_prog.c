/*
 * GIE_prog.c
 *
 * Created: 9/1/2022 5:01:33 PM
 *  Author: Nabil Gamal
 */ 

#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL/GIE_int.h"
#include "MCAL/GIE_priv.h"
#include "MCAL/GIE_config.h"

void GIE_voidEnableGlobalInterrupt(void)
{
	SET_BIT(SREG, SREG_PIN);
}

void GIE_voidDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG, SREG_PIN);
}