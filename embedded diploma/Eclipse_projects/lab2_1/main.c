#include<avr/io.h>
#include<util/delay.h>
#include"MATH_BTT.h"
int main(){
	CLR_BIT(DDRB,0);
	SET_BIT(DDRB,1);
	SET_BIT(DDRB,2);
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);
	SET_BIT(DDRA,6);
	SET_BIT(DDRA,7);
	SET_BIT(PORTB,1);
	CLR_BIT(PORTB,2);
	int i = 0;
	while(1){
		_delay_ms(150);
		if(GET_BIT(PINB,0) == 1){
			i = (i+1) % 10;
		}
		for(int x = 0; x < 4;x++){
			ASSIGN_BIT(PORTA,4,GET_BIT(i,0));
			ASSIGN_BIT(PORTA,5,GET_BIT(i,1));
			ASSIGN_BIT(PORTA,6,GET_BIT(i,2));
			ASSIGN_BIT(PORTA,7,GET_BIT(i,3));

		}
	}
	return 0;
}
