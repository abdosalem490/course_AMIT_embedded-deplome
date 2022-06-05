#include<avr/io.h>
#include<util/delay.h>
#include "MATH_BTT.h"
void SSD_SetNumber(unsigned char Number);
int main(){
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);
	SET_BIT(DDRA,6);
	SET_BIT(DDRA,7);
	SET_BIT(DDRB,1);
	SET_BIT(DDRB,2);
	for(int Counter = 0;Counter < 100 ; Counter++){
		SSD_SetNumber(Counter);
	}
	SET_BIT(PORTB,1);
	SET_BIT(PORTB,2);
}
void SSD_SetNumber(unsigned char Number){
	unsigned char units = Number % 10;
	unsigned char tenths = Number / 10;
	for(int i = 0; i < 300 ; i++){
		SET_BIT(PORTB,1);
		CLR_BIT(PORTB,2);
		ASSIGN_BIT(PORTA,4,GET_BIT(units,0));
		ASSIGN_BIT(PORTA,5,GET_BIT(units,1));
		ASSIGN_BIT(PORTA,6,GET_BIT(units,2));
		ASSIGN_BIT(PORTA,7,GET_BIT(units,3));
		_delay_ms(0.005);
		CLR_BIT(PORTB,1);
		SET_BIT(PORTB,2);
		ASSIGN_BIT(PORTA,4,GET_BIT(tenths,0));
		ASSIGN_BIT(PORTA,5,GET_BIT(tenths,1));
		ASSIGN_BIT(PORTA,6,GET_BIT(tenths,2));
		ASSIGN_BIT(PORTA,7,GET_BIT(tenths,3));
		_delay_ms(0.005);
	}
}
