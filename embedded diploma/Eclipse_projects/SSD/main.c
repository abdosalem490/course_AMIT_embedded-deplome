#include"MATH_BTT.h"
#include<avr/io.h>
#include<util/delay.h>
void SSD_SetNumber(unsigned char Number);
int main(){
	unsigned char Counter =0;
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);
	SET_BIT(DDRA,6);
	SET_BIT(DDRA,7);

	SET_BIT(DDRB,1);
	CLR_BIT(DDRB,2);

	SET_BIT(PORTB,1);
	for(;Counter < 100 ; Counter++){

	}

}
void SSD_SetNumber(unsigned char Number){
	ASSIGN_BIT(PORTA,4,GET_BIT(Number,0));
	ASSIGN_BIT(PORTA,5,GET_BIT(Number,1));
	ASSIGN_BIT(PORTA,6,GET_BIT(Number,2));
	ASSIGN_BIT(PORTA,7,GET_BIT(Number,3));
}
