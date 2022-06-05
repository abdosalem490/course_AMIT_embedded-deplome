#include <avr/io.h>
#include "MATH_BTT.h"
#include <util/delay.h>
int main(){
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);
	SET_BIT(DDRA,6);
	SET_BIT(DDRA,7);
	SET_BIT(DDRB,0);
	while(1){
		CLR_BIT(PORTB,0);
		for(int i = 4; i < 8 ; i++){
			for(int j = i ; j < 8 ;j++){
				SET_BIT(PORTA,j);
			}
			_delay_ms(250);
			for(int j = 4 ; j < 8;j++ ){
				CLR_BIT(PORTA,j);
			}
		}
		SET_BIT(PORTB,0);
		for(int i = 4; i < 8 ; i++){
			for(int j = i ; j < 8 ;j++){
				SET_BIT(PORTA,j);
			}
			_delay_ms(250);
			for(int j = 4 ; j < 8;j++ ){
				CLR_BIT(PORTA,j);
			}
		}
		_delay_ms(250);


	}


	return 0;
}
