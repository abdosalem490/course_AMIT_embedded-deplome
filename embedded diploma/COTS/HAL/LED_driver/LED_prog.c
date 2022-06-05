#include "STD_TYPES.h"
#include "BTT_MATH.h"
#include "ERR_TYPE.h"

#include "LED_config.h"
#include "LED_private.h"
#include "LED_interface.h"

#include "DIO_interface.h"

//<--------------------LEDS-------------------->
uint8 LED_u8TurnON(const Led_Config_t* Copy_Pu8Object){
	uint8 Local_u8ErrorState = OK;
	if(Copy_Pu8Object != NULL){
		if(Copy_Pu8Object->Local_u8Direction <= DIO_u8_LED_FORWARD){

			if(Copy_Pu8Object->Local_u8Direction == DIO_u8_LED_FORWARD)
				DIO_u8SetPinValue(Copy_Pu8Object->Local_u8Port,Copy_Pu8Object->Local_u8Pin,DIO_u8_PIN_HIGH);
			else if(Copy_Pu8Object->Local_u8Direction == DIO_u8_LED_BACKWARD)
				DIO_u8SetPinValue(Copy_Pu8Object->Local_u8Port,Copy_Pu8Object->Local_u8Pin,DIO_u8_PIN_LOW);

		}else{
			Local_u8ErrorState = NOK;
		}
	}else{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

uint8 LED_u8TurnOFF(const Led_Config_t* Copy_Pu8Object){
	uint8 Local_u8ErrorState = OK;
	if(Copy_Pu8Object != NULL){
		if(Copy_Pu8Object->Local_u8Direction <= DIO_u8_LED_FORWARD){

			if(Copy_Pu8Object->Local_u8Direction == DIO_u8_LED_FORWARD)
				DIO_u8SetPinValue(Copy_Pu8Object->Local_u8Port,Copy_Pu8Object->Local_u8Pin,DIO_u8_PIN_LOW);
			else if(Copy_Pu8Object->Local_u8Direction == DIO_u8_LED_BACKWARD)
				DIO_u8SetPinValue(Copy_Pu8Object->Local_u8Port,Copy_Pu8Object->Local_u8Pin,DIO_u8_PIN_HIGH);

		}else{
			Local_u8ErrorState = NOK;
		}
	}else{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}
//<------------------------------------------------------>
