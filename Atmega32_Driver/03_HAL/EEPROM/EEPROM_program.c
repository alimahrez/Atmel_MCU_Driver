/*###############################################################################################
####################################### VECCHIATRON #############################################
#################################################################################################
        $ Title             :   Atmega32 Registers
        $ Author            :   A.Ali Mahrez
        $ Author contact    :   a.alimahrez@gmx.com
        $ Target            :   AVR Atmega32
        $ Date              :   Oct 25th, 2022
        $ Version           :   V005.22
        $ Description       :   None
        $ Notes             :   None
##################################################################################################
##################################################################################################*/

#include "../../02_LIB/stdtypes.h"
#include "../../02_LIB/bitmath.h"
#include "../../02_LIB/atmega32_Registers.h"

#include "../../04_MCAL/I2C/I2C_interface.h"
#include "EEPROM_interface.h"


void EEPROM_vidInit()
{
	I2C_vidInit();
}

U8 EEPROM_WriteByte(U16 Addr,U8 data)
{
	I2C_vidStart();
	if(I2C_u8Status() != I2C_START)
		return ERROR;
	I2C_vidWrite((U8)(0xA0 | ((Addr & 0x0700) >> 7)));
	if(I2C_u8Status() != I2C_MT_SLA_W_ACK)
		return ERROR;
	I2C_vidWrite((U8)Addr);
	if(I2C_u8Status() != I2C_MT_DATA_ACK)
		return ERROR;
	I2C_vidWrite(data);
	if(I2C_u8Status() != I2C_MT_DATA_ACK)
		return ERROR;
	I2C_vidStop();

	return SUCCESS;
}

U8 EEPROM_vidReadByte(U16 Addr,U8 *data)
{
	I2C_vidStart();
	if(I2C_u8Status() != I2C_START)
		return ERROR;
	I2C_vidWrite((U8)(0xA0 | ((Addr & 0x0700) >> 7)));
	if(I2C_u8Status() != I2C_MT_SLA_W_ACK)
		return ERROR;
	I2C_vidWrite((U8)Addr);
	if(I2C_u8Status() != I2C_MT_DATA_ACK)
		return ERROR;
	I2C_vidStart();
	if(I2C_u8Status() != I2C_REP_START)
		return ERROR;
	I2C_vidWrite((U8)(0xA0 | ((Addr & 0x0700) >> 7) | 1));
	if(I2C_u8Status() != I2C_MT_SLA_R_ACK)
		return ERROR;
	*data = I2C_u8_NO_ACK();
	if(I2C_u8Status() != I2C_MR_DATA_NACK)
		return ERROR;
	I2C_vidStop();

	return SUCCESS;
}
