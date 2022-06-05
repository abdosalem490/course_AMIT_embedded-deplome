#include "ERR_TYPE.h"
#include "STD_TYPES.h"
#include "BTT_MATH.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_reg.h"

void SPI_voidINitMaster(void)
{
	//set the microController to be master
	SET_BIT(SPCR,SPCR_MSTR);

	//set the prescalar to be divisable by 16
	CLR_BIT(SPSR,SPSR_SPI2X);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);

	//enable the SPI
	SET_BIT(SPCR,SPCR_SPE);
}
void SPI_voidInitSlave(void)
{
	//set the microController to be slave
	CLR_BIT(SPCR,SPCR_MSTR);

	//enable the SPI
	SET_BIT(SPCR,SPCR_SPE);
}
uint8 SPI_u8Transcieve(uint8 Copy_u8Data)
{
	//send the data
	SPDR = Copy_u8Data;

	//wait until the transfer is complete
	while(SPSR_SPIF == 0);

	//return the recieved value
	return SPDR;
}
