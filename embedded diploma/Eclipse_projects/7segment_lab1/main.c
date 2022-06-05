#include<avr/io.h>
#include<util/delay.h>
#include"MATH_BTT.h"
int main(){
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);
	SET_BIT(DDRA,6);
	SET_BIT(DDRA,7);
	SET_BIT(DDRB,1);
	SET_BIT(DDRB,2);
	//enabling one of the two 7segments
	SET_BIT(PORTB,1);
	SET_BIT(PORTB,2);
	//making counter from 0 -> 9
	for(int i = 0 ; i < 100 ; i++){
		ASSIGN_BIT(PORTA,4,GET_BIT(i,0));
		ASSIGN_BIT(PORTA,5,GET_BIT(i,1));
		ASSIGN_BIT(PORTA,6,GET_BIT(i,2));
		ASSIGN_BIT(PORTA,7,GET_BIT(i,3));
		TOG_BIT(DDRB,1);
		_delay_ms(500);
		ASSIGN_BIT(PORTA,4,GET_BIT(i,4));
		ASSIGN_BIT(PORTA,5,GET_BIT(i,5));
		ASSIGN_BIT(PORTA,6,GET_BIT(i,6));
		ASSIGN_BIT(PORTA,7,GET_BIT(i,7));
		TOG_BIT(DDRB,2);
		_delay_ms(500);
	}
	return 0;
}
