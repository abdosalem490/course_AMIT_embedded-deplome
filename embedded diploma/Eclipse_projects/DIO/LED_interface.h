#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/*LED DIRECTION*/
#define DIO_u8_LED_FORWARD	 1
#define DIO_u8_LED_BACKWARD	 0

typedef struct{
	uint8 Local_u8Port;
	uint8 Local_u8Pin;
	uint8 Local_u8Direction;
}Led_Config_t;

//Led driver functions
uint8 LED_u8TurnON(const Led_Config_t* Copy_Pu8Object);
uint8 LED_u8TurnOFF(const Led_Config_t* Copy_Pu8Object);

#endif
