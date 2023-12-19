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
#include "../../02_LIB/interrupt.h"
#include "I2C_interface.h"

void I2C_vidInit()
{
	TWBR_REG = 0x02;
	TWCR_REG = (1<<TWEN);
	TWSR_REG = 0x00;
	TWAR_REG = 0b00000010;
}

void I2C_vidStart()
{
	TWCR_REG = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!GET_BIT(TWCR_REG,TWINT));
}

void I2C_vidStop()
{
	TWCR_REG = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void I2C_vidWrite(U8 data)
{
	TWDR_REG = data;
	TWCR_REG = (1<<TWINT)|(1<<TWEN);
	while(!GET_BIT(TWCR_REG,TWINT));
}

U8 I2C_u8ACK()
{
	TWCR_REG = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(!GET_BIT(TWCR_REG,TWINT));
	return TWDR_REG;
}

U8 I2C_u8_NO_ACK()
{
	TWCR_REG = (1<<TWINT)|(1<<TWEN);
	while(!GET_BIT(TWCR_REG,TWINT));
	return TWDR_REG;
}

U8 I2C_u8Status()
{
	U8 status;
	status = (TWSR_REG & 0xF8);
	return status;
}



