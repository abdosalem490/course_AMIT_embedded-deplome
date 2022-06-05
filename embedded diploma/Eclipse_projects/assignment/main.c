#include <util/delay.h>
#include <stdlib.h>


#include "STD_TYPES.h"
#include "BTT_MATH.h"
#include "ERR_TYPE.h"

#include "PORT_interface.h"

#include "DIO_interface.h"



void main()
{
	PORT_voidInit();
	sint16 i;
	while(1)
	{
		for(i =0; i <= 255 ; i++)
		{
			DIO_u8SetPortValue(DIO_u8_PORTC,i);
			_delay_ms(10);
		}

		for(i =255; i >= 0 ; i--)
		{
			DIO_u8SetPortValue(DIO_u8_PORTC,i);
			_delay_ms(10);
		}
	}

}
