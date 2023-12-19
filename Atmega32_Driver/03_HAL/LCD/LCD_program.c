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
##################################################################################################
##################################################################################################*/

#include "../../02_LIB/stdtypes.h"
#include "../../02_LIB//bitmath.h"
#include "../../02_LIB/atmega32_Registers.h"
#include "../../04_MCAL/DIO/DIO_interface.h"
#include "../../04_MCAL/Timer/Timer_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"


void static LCD_vidReadPuls(void)
{
	DIO_vidPinWrite(LCD_EN,HIGH);
	TIM_vidDelay_us(2);
	DIO_vidPinWrite(LCD_EN,LOW);
	TIM_vidDelay_us(3);
}

void static LCD_vidWrite(U8 value)
{
	// WORKING WITH 4 BIT MODE
	// SEND EACH BIT OF HUGH NIBBLES FORM 4 TO 7 IN VALUE ARRG,
	DIO_vidPinWrite(LCD_D7,GET_BIT(value,7));
	DIO_vidPinWrite(LCD_D6,GET_BIT(value,6));
	DIO_vidPinWrite(LCD_D5,GET_BIT(value,5));
	DIO_vidPinWrite(LCD_D4,GET_BIT(value,4));

	// READ PULS TO MAKE LCD TAKE THE FOUR BIT DATA FROM REGISTER INSIDE TO THE MEMORY
	LCD_vidReadPuls();

	// SEND EACH BIT OF HUGH NIBBLES FORM 0 TO 3 IN VALUE ARRG,
	DIO_vidPinWrite(LCD_D7,GET_BIT(value,3));
	DIO_vidPinWrite(LCD_D6,GET_BIT(value,2));
	DIO_vidPinWrite(LCD_D5,GET_BIT(value,1));
	DIO_vidPinWrite(LCD_D4,GET_BIT(value,0));

	// READ PULS TO MAKE LCD TAKE THE FOUR BIT DATA FROM REGISTER INSIDE TO THE MEMORY
	LCD_vidReadPuls();

}

void static LCD_vidWriteCommand(U8 cmd)
{
	DIO_vidPinWrite(LCD_RS,LOW);
	LCD_vidWrite(cmd);
}

void LCD_vidInit(void)
{
	TIM_vidDelay_ms(15);						// waiting for 15ms until LCD is powered up

	DIO_vidPinDirection(LCD_RS, OUTPUT);
	DIO_vidPinDirection(LCD_EN, OUTPUT);
	DIO_vidPinDirection(LCD_D4, OUTPUT);
	DIO_vidPinDirection(LCD_D5, OUTPUT);
	DIO_vidPinDirection(LCD_D6, OUTPUT);
	DIO_vidPinDirection(LCD_D7, OUTPUT);

	TIM_vidDelay_ms(2);								// waiting 2ms after initiate the PINS

	LCD_vidWriteCommand(INITIALIZATION_MODE_1); // send initialization 1 value as in data sheet
	LCD_vidWriteCommand(INITIALIZATION_MODE_2); // send initialization 2 value as in data sheet
	LCD_vidWriteCommand(INITIALIZATION_MODE_3); // command to set LCD as 4bit mode + 2 line + 5*7 dots
	LCD_vidWriteCommand(INITIALIZATION_MODE_4); // command to make the display is on and cursor off "hidden"
	LCD_vidWriteCommand(INITIALIZATION_MODE_5); // command to make the display is cleared and make cursor in home

	TIM_vidDelay_ms(15);
}

void LCD_vidWriteCharacter(U8 Character)
{
	DIO_vidPinWrite(LCD_RS, HIGH);
	LCD_vidWrite(Character);
}

void LCD_vidWriteString(U8 *str)
{
	U16 Count = 0;

	while(*str > 0)
	{
		Count++;
		LCD_vidWriteCharacter(*str++);
		if(Count == 16)
			LCD_vidSetCursor(1,0);
		else if(Count == 32 || Count == 33)
		{
			LCD_vidClear();
			LCD_vidSetCursor(0, 0);
			Count = 0;
		}
	}
}

void LCD_vidSetCursor(U8 row, U8 position)
{
	if(row == LCD_ROW_1)
		LCD_vidWriteCommand(position | 0x80);

	else if(row == LCD_ROW_2)
		LCD_vidWriteCommand(0x80 | 0x40 | position);
}

void LCD_vidClear(void)
{
	LCD_vidWriteCommand(LCD_CLEAR_CMD);
}


