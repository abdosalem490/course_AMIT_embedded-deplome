#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

/*SWITCH PULL TYPRE*/
#define DIO_u8_PULL_UP		0
#define DIO_u8_PULL_DOWN	1

/*SWITCH STATUS*/
#define DIO_u8_SWITCH_PRESSED	1
#define DIO_u8_SWITCH_RELEASED  0

typedef struct{
	uint8 Local_u8Port;
	uint8 Local_u8Pin;
	uint8 Local_u8PullType;
}SW_Config_t;

//Switch driver functions
uint8 SW_u8GetState(const SW_Config_t* Copy_Pu8Object, uint8* Copy_Pu8State);

#endif
