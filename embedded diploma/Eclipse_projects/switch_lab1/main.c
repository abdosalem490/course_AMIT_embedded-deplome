#include<avr/io.h>
#include<util/delay.h>
#include"MATH_BTT.h"
int main(){
	SET_BIT(DDRC,7);
	CLR_BIT(PINB,0);
	while(1){
		_delay_ms(100);
		if((GET_BIT(PINB,0)) == 1){
			SET_BIT(PORTC,7);
		}else{
			CLR_BIT(PORTC,7);
		}
	}

	return 0;
}


