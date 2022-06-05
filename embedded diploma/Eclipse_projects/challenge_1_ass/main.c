//traffic light
#include<avr/io.h>
#include<util/delay.h>
#include"MATH_BTT.h"
int main(){
	//setting port A as output
	DDRA = 0xff;
	PORTA = 0;
	int i = 0;
	//setting first 3 bits of pinc as input
	CLR_BIT(PINC,0);
	CLR_BIT(PINC,1);
	CLR_BIT(PINC,2);
	while(1){
		//green or red
		if(((GET_BIT(PINC,0)) == 1) ||((GET_BIT(PINC,1)) == 1))
			i = 9;
		//yellow
		else if((GET_BIT(PINC,2)) == 1)
			i = 3;
		while(i >= 0){
			ASSIGN_BIT(PORTA,0,GET_BIT(i,0));
			ASSIGN_BIT(PORTA,1,GET_BIT(i,1));
			ASSIGN_BIT(PORTA,2,GET_BIT(i,2));
			ASSIGN_BIT(PORTA,3,GET_BIT(i,3));
			i--;
			_delay_ms(25);
		}
		i = 0;
		_delay_ms(50);
	}
	return 0;
}

