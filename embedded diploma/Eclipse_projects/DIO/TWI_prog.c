#include "ERR_TYPE.h"
#include "STD_TYPES.h"
#include "BTT_MATH.h"

#include "TWI_config.h"
#include "TWi_interface.h"
#include "TWI_private.h"
#include "TWI_reg.h"

#include<util/delay.h>

void TWI_voidMasterInit(uint8 Copy_u8Address)
{
	/*1- Clock setting*/
	/*SCL frequency = 400kbps, CPU freq = 16000000 ->  TWBR = 12, TWPS = 0*/
	TWBR = 12;
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/*2- Address setting*/
	if(Copy_u8Address)
	{
		TWAR = Copy_u8Address<<1;
	}
	else
	{
		/*Do nothing*/
	}

	/*3- enable Acknowledge bit sending*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*TWI enable*/
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveInit(uint8 Copy_u8Address)
{
	/*2- Address setting*/
	TWAR = Copy_u8Address<<1;

	/*3- enable Acknowledge bit sending*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*TWI enable*/
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ERRStatus_t TWI_SendStartCondition(void)
{
	TWI_ERRStatus_t Local_ErrState = NoError;

	/*Set Start Condition Bit*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the interrupt flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != START_ACK)
	{
		Local_ErrState = StartConditionErr;
	}
	else
	{

	}

	return Local_ErrState;
}

TWI_ERRStatus_t TWI_SendRepeatedStart(void)
{
	TWI_ERRStatus_t Local_ErrState = NoError;

	/*Set Start Condition Bit*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the interrupt flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != REP_START_ACK)
	{
		Local_ErrState = RepeatedStrtErr;
	}
	else
	{

	}

	return Local_ErrState;
}

TWI_ERRStatus_t TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress)
{
	TWI_ERRStatus_t Local_ErrState = NoError;

	/*set the address of the slave*/
	TWDR = Copy_u8SlaveAddress<<1;

	/*put bit0 to be 0 to be write operation*/
	CLR_BIT(TWDR,0);

	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the interrupt flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrState = SlaveAddWithWriteErr;
	}
	else
	{

	}

	return Local_ErrState;
}

TWI_ERRStatus_t TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress)
{
	TWI_ERRStatus_t Local_ErrState = NoError;

	/*set the address of the slave*/
	TWDR = Copy_u8SlaveAddress<<1;

	/*put bit0 to be 1 to be read operation*/
	SET_BIT(TWDR,0);

	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the interrupt flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrState = SlaveAddWithReadErr;
	}
	else
	{

	}

	return Local_ErrState;
}

TWI_ERRStatus_t TWI_MasterSendDataByte(uint8 Copy_u8Data)
{
	TWI_ERRStatus_t Local_ErrState = NoError;

	/*put the data to the data register*/
	TWDR = Copy_u8Data;

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the interrupt flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check on status register*/
	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrState = MstrSendByteErr;
	}
	else
	{

	}

	return Local_ErrState;
}

TWI_ERRStatus_t TWI_MasterRecieveDataByte(uint8* Copy_pu8Data)
{
	TWI_ERRStatus_t Local_ErrState = NoError;

	/*Clear the interrupt flag to enable slave to send data*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the interrupt flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check on status register*/
	if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrState = MstrReadByteErr;
	}
	else
	{
		/*read the received data*/
		*Copy_pu8Data = TWDR;
	}

	return Local_ErrState;
}

void TWI_SendStopCondition(void)
{
	/*set the stop condition bit*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

}


//EEPROM function
void EEPROM_voidSendDataByte(uint16 Copy_u16Address,uint8 Copy_u8Data)
{
	uint8 Local_u8AddressPacket = EEPROM_FIXED_ADD | ((Copy_u16Address >> 8) & 0b00000111);

	TWI_SendStartCondition();

	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

	TWI_MasterSendDataByte((uint8)Copy_u16Address);

	TWI_MasterSendDataByte(Copy_u8Data);

	TWI_SendStopCondition();

	_delay_ms(5);
}

void EEPROM_voidRecieveDataByte(uint16 Copy_u16Address,uint8* Copy_pu8Value)
{
	uint8 Local_u8AddressPacket = EEPROM_FIXED_ADD | ((Copy_u16Address >> 8) & 0b00000111);

	TWI_SendStartCondition();

	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

	TWI_MasterSendDataByte((uint8)Copy_u16Address);

	TWI_SendRepeatedStart();

	TWI_SendSlaveAddressWithRead(Local_u8AddressPacket);

	TWI_MasterRecieveDataByte(Copy_pu8Value);

	TWI_SendStopCondition();

	//_delay_ms(5);
}

