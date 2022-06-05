/*********************************************************************/
/*********************************************************************/
/**********************		Author: Amgad Samir			**************/
/**********************		Date: 18/9/2021				**************/
/**********************		layer: HAL					**************/
/**********************		Version: 1.00				**************/
/*********************************************************************/
/*********************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*Options:
 * 			1- FOUR_BIT
 * 			2- EIGHT_BIT
 * */
#define CLCD_u8_BIT_MODE			FOUR_BIT

#define CLCD_u8_DATA_PORT			DIO_u8_PORTA

#if CLCD_u8_BIT_MODE == FOUR_BIT
#define CLCD_u8_DATA_PIN4			DIO_u8_PIN4
#define CLCD_u8_DATA_PIN5			DIO_u8_PIN5
#define CLCD_u8_DATA_PIN6			DIO_u8_PIN6
#define CLCD_u8_DATA_PIN7			DIO_u8_PIN7
#endif

#define CLCD_u8_CTRL_PORT			DIO_u8_PORTB
#define CLCD_u8_RS_PIN				DIO_u8_PIN0
#define CLCD_u8_RW_PIN				DIO_u8_PIN1
#define CLCD_u8_E_PIN				DIO_u8_PIN2



#endif
