/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 22/10/2021	********************************/
/*************************  Layer: HAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_u8_ROW_PORT		DIO_u8_PORTB
#define KPD_u8_COL_PORT		DIO_u8_PORTB

#define KPD_u8_R0_PIN		DIO_u8_PIN0
#define KPD_u8_R1_PIN		DIO_u8_PIN1
#define KPD_u8_R2_PIN		DIO_u8_PIN2
#define KPD_u8_R3_PIN		DIO_u8_PIN3

#define KPD_u8_C0_PIN		DIO_u8_PIN4
#define KPD_u8_C1_PIN		DIO_u8_PIN5
#define KPD_u8_C2_PIN		DIO_u8_PIN6
#define KPD_u8_C3_PIN		DIO_u8_PIN7


#define KPD_KEY_ARR			{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'.','0','=','+'}}

#define KPD_u8_NO_PRESSED_KEY	0xff
#endif
