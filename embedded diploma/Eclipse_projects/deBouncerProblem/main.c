#include<avr/io.h>
#include"MATH_BTT.h"
int main(){
	SET_BIT(DDRC,2); //LED 0
	SET_BIT(DDRC,7); //LED 1
	SET_BIT(DDRD,3); //LED 2
	CLR_BIT(PINB,0); //Button
	unsigned char led = 0;
	unsigned char counter = 0;
	unsigned char isClicked = 0;
	while(1){
		for(int i = 0; i < 30000 ; i++){
			if(GET_BIT(PINB,0) == 1){
				isClicked = 1;
			}else{
				isClicked = 0;
				break;
			}
		}
		if(isClicked == 1){
			counter = (counter + 1) % 3;
			led = 0;
			SET_BIT(led,counter);
		}
		for(int i = 0; i < 2500 ; i++){
			ASSIGN_BIT(PORTC,2,GET_BIT(led,0));
			ASSIGN_BIT(PORTC,7,GET_BIT(led,1));
			ASSIGN_BIT(PORTD,3,GET_BIT(led,2));
		}
	}
	return 0;
}
