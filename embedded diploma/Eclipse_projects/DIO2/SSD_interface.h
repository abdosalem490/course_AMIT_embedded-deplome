#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/*SSD TYPE*/
#define DIO_u8_SSD_TYPE_ANODE	1
#define DIO_u8_SSD_TYPE_CATHODE	0

typedef struct{
	uint8 Local_u8DataPort;
	uint8 Local_u8PinA;
	uint8 Local_u8PinB;
	uint8 Local_u8PinC;
	uint8 Local_u8PinD;
	uint8 Local_u8EnablePort;
	uint8 Local_u8EnablePin;
	uint8 Local_u8Type;
}SSD_Config_t;

//SSD driver functions
uint8 SSD_u8Enable(const SSD_Config_t* Copy_Pu8Object);
uint8 SSD_u8Disable(const SSD_Config_t* Copy_Pu8Object);
uint8 SSD_u8SetNumber(const SSD_Config_t* Copy_Pu8Object , uint8 Copy_u8Number);



#endif
