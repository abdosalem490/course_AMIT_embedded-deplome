/*********************************************************************/
/*********************************************************************/
/**********************		Author: Amgad Samir			**************/
/**********************		Date: 18/9/2021				**************/
/**********************		layer: HAL					**************/
/**********************		Version: 1.00				**************/
/*********************************************************************/
/*********************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(uint8 Copy_u8Command);

void CLCD_voidSendData(uint8 Copy_u8Data);

void CLCD_voidInit(void);

uint8 CLCD_u8SendString(const char* Copy_pchString);

void CLCD_voidSendNumber(uint32 Copy_u32Number);

uint8 CLCD_u8GoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);

void CLCD_voidSendSpecialCharacter(uint8* Copy_pu8CharArr, uint8 Copy_u8BlockNum,uint8 Copy_u8XPos, uint8 Copy_u8YPos);


#endif
