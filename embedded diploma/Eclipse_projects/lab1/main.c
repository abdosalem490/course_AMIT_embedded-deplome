#include <avr/io.h>
#include "MATH_BTT.h"
int main()
{
	//turning on 3 leds
	//making ddr 1 to indicate output
	SET_BIT(DDRD,3);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,7);
	//setting 1 to led bits
	SET_BIT(PORTC,7); //led1
	SET_BIT(PORTC,2); //led2
	SET_BIT(PORTD,3); //led0
}
