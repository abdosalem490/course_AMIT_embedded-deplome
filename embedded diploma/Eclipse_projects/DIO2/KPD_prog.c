/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 22/10/2021	********************************/
/*************************  Layer: HAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"

uint8 KPD_u8GetPressedKey(void)
{
	uint8 Local_u8RowIdx,Local_u8ColIdx,Local_u8PinState,Local_u8PressedKey = KPD_u8_NO_PRESSED_KEY;

	static uint8 Local_u8KPDArr[ROW_NUM][COL_NUM] = KPD_KEY_ARR;
	static uint8 Local_u8ColArr[COL_NUM] = {KPD_u8_C0_PIN,KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN};
	static uint8 Local_u8RowArr[ROW_NUM] = {KPD_u8_R0_PIN,KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN};

	/*Activate columns*/
	for(Local_u8ColIdx = 0; Local_u8ColIdx < COL_NUM ;Local_u8ColIdx++)
	{
		/*Activate the current column*/
		DIO_u8SetPinValue(KPD_u8_COL_PORT,Local_u8ColArr[Local_u8ColIdx],DIO_u8_PIN_LOW);

		/*Read the rows*/
		for(Local_u8RowIdx = 0; Local_u8RowIdx < ROW_NUM;Local_u8RowIdx++)
		{
			/*Read the current row*/
			DIO_u8ReadPinValue(KPD_u8_ROW_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinState);

			if(DIO_u8_PIN_LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColIdx];

				/*Wait until the key is released*/
				while(DIO_u8_PIN_LOW == Local_u8PinState)
				{
					DIO_u8ReadPinValue(KPD_u8_ROW_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
		}
		/*DeActivate the current column*/
		DIO_u8SetPinValue(KPD_u8_COL_PORT,Local_u8ColArr[Local_u8ColIdx],DIO_u8_PIN_HIGH);
	}
	return Local_u8PressedKey;
}
