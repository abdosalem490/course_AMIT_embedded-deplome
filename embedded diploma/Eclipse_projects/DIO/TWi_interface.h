/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: Abdo salm	********************************/
/*************************  Date: 4/12/2021	    ********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStrtErr,
	SlaveAddWithWriteErr,
	SlaveAddWithReadErr,
	MstrSendByteErr,
	MstrReadByteErr
}TWI_ERRStatus_t;

/*send the address of your master node or send 0 if the master willn't be addressed*/
void TWI_voidMasterInit(uint8 Copy_u8Address);

void TWI_voidSlaveInit(uint8 Copy_u8Address);

TWI_ERRStatus_t TWI_SendStartCondition(void);

TWI_ERRStatus_t TWI_SendRepeatedStart(void);

TWI_ERRStatus_t TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);

TWI_ERRStatus_t TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);

TWI_ERRStatus_t TWI_MasterSendDataByte(uint8 Copy_u8Data);

TWI_ERRStatus_t TWI_MasterRecieveDataByte(uint8* Copy_pu8Data);

void TWI_SendStopCondition(void);


//EEPROM
void EEPROM_voidSendDataByte(uint16 Copy_u16Address,uint8 Copy_u8Data);
void EEPROM_voidRecieveDataByte(uint16 Copy_u16Address,uint8* Copy_pu8Value);

#endif
