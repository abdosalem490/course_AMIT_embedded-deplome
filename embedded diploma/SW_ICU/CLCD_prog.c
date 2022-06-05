/*********************************************************************/
/*********************************************************************/
/**********************		Author: Amgad Samir			**************/
/**********************		Date: 18/9/2021				**************/
/**********************		layer: HAL					**************/
/**********************		Version: 1.00				**************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_type.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

static void SetHalfDataPort(uint8 Copy_u8Data)
{
	uint8 Local_u8DataPins[4]={CLCD_u8_DATA_PIN4,CLCD_u8_DATA_PIN5,CLCD_u8_DATA_PIN6,CLCD_u8_DATA_PIN7};
	uint8 Local_u8Iterator;
	for(Local_u8Iterator=0; Local_u8Iterator<4; Local_u8Iterator++)
	{
		DIO_u8SetPinValue(CLCD_u8_DATA_PORT,Local_u8DataPins[Local_u8Iterator],(GET_BIT(Copy_u8Data,Local_u8Iterator)));
	}
}

static void SendEnablePulse(void)
{
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN,DIO_u8_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN,DIO_u8_PIN_LOW);
}

void CLCD_voidSendCommand(uint8 Copy_u8Command)
{
	/*1- Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RS_PIN,DIO_u8_PIN_LOW);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RW_PIN,DIO_u8_PIN_LOW);

#if CLCD_u8_BIT_MODE == EIGHT_BIT
	/*3- Send the command on the LCD data pins*/
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Command);


	/*send enable pulse*/
	SendEnablePulse();

#elif CLCD_u8_BIT_MODE == FOUR_BIT
	/*Send High order 4 bits first*/
	SetHalfDataPort(Copy_u8Command>>4);

	/*Send enable pulse*/
	SendEnablePulse();

	SetHalfDataPort(Copy_u8Command);

	SendEnablePulse();

#endif
}

void CLCD_voidSendData(uint8 Copy_u8Data)
{
	/*1- Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RS_PIN,DIO_u8_PIN_HIGH);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RW_PIN,DIO_u8_PIN_LOW);

	/*3- Send the data on the LCD data pins*/
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Data);

#if CLCD_u8_BIT_MODE == EIGHT_BIT
	/*3- Send the command on the LCD data pins*/
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Data);


	/*send enable pulse*/
	SendEnablePulse();

#elif CLCD_u8_BIT_MODE == FOUR_BIT
	/*Send High order 4 bits first*/
	SetHalfDataPort(Copy_u8Data>>4);

	/*Send enable pulse*/
	SendEnablePulse();

	SetHalfDataPort(Copy_u8Data);

	SendEnablePulse();

#endif
}

void CLCD_voidInit(void)
{
	/*1- wait for more than 30 ms after power on*/
	_delay_ms(40);
#if CLCD_u8_BIT_MODE == EIGHT_BIT
	/*2- Function set command: 2 lines, Font: 5x8 */
	CLCD_voidSendCommand(0b00111000);

#elif CLCD_u8_BIT_MODE == FOUR_BIT
	SetHalfDataPort(0b0010);
	SendEnablePulse();

	SetHalfDataPort(0b0010);
	SendEnablePulse();

	SetHalfDataPort(0b1000);
	SendEnablePulse();
#endif

	/*3- Display on off control: Display on, cursor off, blink cursor off*/
	CLCD_voidSendCommand(0b00001100);

	/*4- Clear LCD*/
	CLCD_voidSendCommand(1);
}

uint8 CLCD_u8SendString(const char* Copy_pchString)
{
	uint8 Local_u8ErrorState = OK;

	uint8 Local_u8Counter=0;
	if(Copy_pchString != NULL)
	{
		while(Copy_pchString[Local_u8Counter] != '\0')
		{
			CLCD_voidSendData(Copy_pchString[Local_u8Counter]);
			Local_u8Counter++;
		}
	}
	else
	{
		Local_u8ErrorState= NULL_POINTER;
	}
	return Local_u8ErrorState;
}

uint8 CLCD_u8GoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8ErrorState= OK;
	uint8 Local_u8DDRamAdd ;
	switch(Copy_u8YPos)
	{
	case 0: Local_u8DDRamAdd = Copy_u8XPos; 		break;
	case 1: Local_u8DDRamAdd = Copy_u8XPos+0x40; 	break;
	default: Local_u8ErrorState = NOK; 				break;
	}
	/*another way
	 * Local_u8DDRamAdd = Copy_u8YPos * 0x40 + Copy_u8XPos;
	 * */

	/*Set bit number 7 for Set DDram address command*/
	SET_BIT(Local_u8DDRamAdd,7);

	/*Set DDRAM address command*/
	CLCD_voidSendCommand(Local_u8DDRamAdd);

	return Local_u8ErrorState;
}

void CLCD_voidSendSpecialCharacter(uint8* Copy_pu8CharArr, uint8 Copy_u8BlockNum,uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8Iterator;
	/*Calculate the starting address in the CGRAM for the required pattern number*/
	uint8 Local_u8CGRamAdd= Copy_u8BlockNum *8;

	/*Set bit number 6 and clear bit number 7 , for Set CGRAM address command*/
	SET_BIT(Local_u8CGRamAdd,6);

	/*Set CGRAM address command*/
	CLCD_voidSendCommand(Local_u8CGRamAdd);

	/*draw the pattern inside the CGRAM*/
	for(Local_u8Iterator =0; Local_u8Iterator<8 ; Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8CharArr[Local_u8Iterator]);
	}

	/*go back to DDRAM to display the pattern*/
	CLCD_u8GoToXY(Copy_u8XPos,Copy_u8YPos);

	/*Display the drawn pattern*/
	CLCD_voidSendData(Copy_u8BlockNum);

}

void CLCD_voidSendNumber(uint32 Copy_u32Number)
{
	uint32 Local_u32Reserved=1;

	if(Copy_u32Number==0)
	{
		CLCD_voidSendData('0');
		return;
	}
	/*Reverse the number*/
	while(Copy_u32Number!=0)
	{
		/*Get the right most digit*/
		Local_u32Reserved= Local_u32Reserved*10+ Copy_u32Number%10;

		/*Get rid of the right most digit*/
		Copy_u32Number /=10;
	}
	do
	{
		/*display the right most digit with converting its value to ASCII*/
		CLCD_voidSendData((Local_u32Reserved%10)+'0');

		/*Get rid of the right most digit*/
		Local_u32Reserved/=10;
	}while(Local_u32Reserved!=1);
}
