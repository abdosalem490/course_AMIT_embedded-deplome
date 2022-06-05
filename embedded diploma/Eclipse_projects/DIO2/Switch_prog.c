#include "STD_TYPES.h"
#include "BTT_MATH.h"
#include "ERR_TYPE.h"

#include "Switch_config.h"
#include "Switch_private.h"
#include "Switch_interface.h"

#include "DIO_interface.h"


//<--------------------SWITCH-------------------->
uint8 SW_u8GetState(const SW_Config_t* Copy_Pu8Object,uint8* Copy_Pu8State){
	uint8 Local_u8ErrorState = OK;
	if(Copy_Pu8Object != NULL && Copy_Pu8State != NULL){
		if(Copy_Pu8Object->Local_u8PullType <= DIO_u8_PULL_DOWN){
			uint8 Local_u8ValueOfPIN;
			Local_u8ErrorState = DIO_u8ReadPinValue(Copy_Pu8Object->Local_u8Port,Copy_Pu8Object->Local_u8Pin,&Local_u8ValueOfPIN);
			if(Local_u8ErrorState == OK)
			{
				if((Copy_Pu8Object->Local_u8PullType == DIO_u8_PULL_DOWN) && (Local_u8ValueOfPIN == DIO_u8_PIN_HIGH))
					*Copy_Pu8State = DIO_u8_SWITCH_PRESSED;
				else if((Copy_Pu8Object->Local_u8PullType == DIO_u8_PULL_UP) && (Local_u8ValueOfPIN == DIO_u8_PIN_LOW))
					*Copy_Pu8State = DIO_u8_SWITCH_PRESSED;
				else
					*Copy_Pu8State = DIO_u8_SWITCH_RELEASED;
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
