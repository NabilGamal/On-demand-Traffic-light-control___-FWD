#include "MCAL/DIO_int.h"
#include "Library/BIT_MATH.h"
//#include "LCD_int.h"
#include "MCAL/EXTI_int.h"
#include "HAL/Led_int.h"
#include "APP/App_int.h"

#include "Library/STD_Types.h"

#include <util/delay.h>


int	main	(void)
{
	App_voidInit();
	
	while (1)
	{
		App_voidStart();
	}
	
}