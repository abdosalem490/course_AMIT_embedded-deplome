#include "STD_TYPES.h"
#include "BTT_MATH.h"
#include "ERR_TYPE.h"

#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"

#include "DIO_interface.h"

//<--------------------7 SEGMENT-------------------->
uint8 SSD_u8Enable(const SSD_Config_t* Copy_Pu8Object){
	uint8 Local_u8ErrorState = OK;
	if(Copy_Pu8Object != NULL){
		if(Copy_Pu8Object->Local_u8Type == DIO_u8_SSD_TYPE_CATHODE)
			DIO_u8SetPinValue(Copy_Pu8Object->Local_u8EnablePort,Copy_Pu8Object->Local_u8EnablePin,DIO_u8_PIN_HIGH);
		else if(Copy_Pu8Object->Local_u8Type == DIO_u8_SSD_TYPE_ANODE)
			DIO_u8SetPinValue(Copy_Pu8Object->Local_u8EnablePort,Copy_Pu8Object->Local_u8EnablePin,DIO_u8_PIN_LOW);

	}else{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

uint8 SSD_u8Disable(const SSD_Config_t* Copy_Pu8Object){
	uint8 Local_u8ErrorState = OK;
	if(Copy_Pu8Object != NULL){
		if(Copy_Pu8Object->Local_u8Type == DIO_u8_SSD_TYPE_CATHODE)
			DIO_u8SetPinValue(Copy_Pu8Object->Local_u8EnablePort,Copy_Pu8Object->Local_u8EnablePin,DIO_u8_PIN_LOW);
		else if(Copy_Pu8Object->Local_u8Type == DIO_u8_SSD_TYPE_ANODE)
			DIO_u8SetPinValue(Copy_Pu8Object->Local_u8EnablePort,Copy_Pu8Object->Local_u8EnablePin,DIO_u8_PIN_HIGH);
	}else{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

uint8 SSD_u8SetNumber(const SSD_Config_t* Copy_Pu8Object , uint8 Copy_u8Number){
	uint8 Local_u8ErrorState = OK;
	if(Copy_Pu8Object != NULL){
			if(Copy_Pu8Object->Local_u8Type <= DIO_u8_SSD_TYPE_ANODE)
			{
				if(Copy_u8Number <= 9){

					DIO_u8SetPinValue(Copy_Pu8Object->Local_u8DataPort,Copy_Pu8Object->Local_u8PinA,GET_BIT(Copy_u8Number,0));
					DIO_u8SetPinValue(Copy_Pu8Object->Local_u8DataPort,Copy_Pu8Object->Local_u8PinB,GET_BIT(Copy_u8Number,1));
					DIO_u8SetPinValue(Copy_Pu8Object->Local_u8DataPort,Copy_Pu8Object->Local_u8PinC,GET_BIT(Copy_u8Number,2));
					DIO_u8SetPinValue(Copy_Pu8Object->Local_u8DataPort,Copy_Pu8Object->Local_u8PinD,GET_BIT(Copy_u8Number,3));

				}else{
					Local_u8ErrorState = BIG_NUM;
				}
			}else{
				Local_u8ErrorState = NOK;
			}
	}else{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}
//<------------------------------------------------------>
