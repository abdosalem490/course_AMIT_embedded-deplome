#include<util/delay.h>

#include "STD_TYPES.h"
#include "BTT_MATH.h"
#include "ERR_TYPE.h"

#include "PORT_interface.h"

#include "DIO_interface.h"


#define SREG *((volatile uint8*) 0x5F)
#define MCUCR *((volatile uint8*) 0x55)
#define MCUCSR *((volatile uint8*) 0x54)
#define GICR *((volatile uint8*) 0x5B)

void main()
{
	PORT_voidInit();

	/*initialize INT0*/
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	/*PIE enable*/
	SET_BIT(SREG,7);
	/*GIE enable*/
	SET_BIT(GICR,6);

	while(1)
	{

	}




}
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_PIN_HIGH);
}
