#include<avr/io.h>
#include<util/delay.h>
#include"MATH_BTT.h"
int main(){
	//turning on 3 leds
		//making ddr 1 to indicate output
		SET_BIT(DDRD,3);
		SET_BIT(DDRC,2);
		SET_BIT(DDRC,7);
	for(int i = 0 ; i < 1000;i++){
		_delay_ms(1000);
		//setting 1 to led bits
		TOG_BIT(PORTC,7); //led1
		TOG_BIT(PORTC,2); //led2
		TOG_BIT(PORTD,3); //led0
	}

	return 0;
}
