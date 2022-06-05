//snake effect
#include<avr/io.h>
#include<util/delay.h>
#include "MATH_BTT.h"
int main(){
	//setting port A as output
	DDRA = 0xff;
	PORTA = 0;
	int i = 0;
	//shifting
	while(1){
		_delay_ms(30);
		if(i == 0)
			PORTA = 0;
		SET_BIT(PORTA,i);
		//snake
		i = (i+1) % 8;
	}
	return 0;
}
