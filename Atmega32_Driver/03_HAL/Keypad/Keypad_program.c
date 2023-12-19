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
#include "Keypad_config.h"
#include "Keypad_interface.h"

Pin_Number KeypadRows[] = {KEY_ROW_0, KEY_ROW_1, KEY_ROW_2, KEY_ROW_3};
Pin_Number KeypadCols[] = {KEY_COL_0, KEY_COL_1, KEY_COL_2,KEY_COL_3};

Pin_Number KeypadRowsD[] = {KEY_ROW_0, KEY_ROW_1, KEY_ROW_2, KEY_ROW_3};
Pin_Number KeypadColsD[] = {KEY_COL_0, KEY_COL_1, KEY_COL_2};

U8 KeyMap[4][4] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

U8 KeyMapD[4][3] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'*', '0', '#'}
};

void  Keypad_vidInit(void)
{
	U8 Index;

	#if (KEYBAD_TYPE == KEYPAD_4X4)
		for(Index = 0 ; Index < 4 ; Index++)
			DIO_vidPinInDirectionWithPullState(KEY_ROW_PORT,KeypadRows[Index], INTERNAL_PULLUP);
		for(Index = 0 ; Index < 4 ; Index++)
			DIO_vidPinDirection(KEY_COL_PORT,KeypadCols[Index], OUTPUT);
	#endif

	#if (KEYBAD_TYPE == KEYPAD_4X3)
		for(Index = 0 ; Index < 4 ; Index++)
			DIO_vidPinInDirectionWithPullState(KEY_ROW_PORT,KeypadRowsD[Index], INTERNAL_PULLUP);
		for(Index = 0 ; Index < 3 ; Index++)
			DIO_vidPinDirection(KEY_COL_PORT,KeypadColsD[Index], OUTPUT);
	#endif

}


U8 Keypad_GetKey()
{
	U16 IndexCol1, IndexCol2, IndexRow;

	#if (KEYBAD_TYPE == KEYPAD_4X4)
		for(IndexCol1 = 0 ; IndexCol1 < 4 ; IndexCol1++)
		{
			for(IndexCol2 = 0 ; IndexCol2 < 4 ;IndexCol2++)
				DIO_vidPinWrite(KEY_COL_PORT,KeypadCols[IndexCol2], HIGH);
			DIO_vidPinWrite(KEY_COL_PORT,KeypadCols[IndexCol1], LOW);
			for(IndexRow = 0; IndexRow < 4; IndexRow++)
			{
				if(!(DIO_u8PinReadValue(KEY_ROW_PORT,KeypadRows[IndexRow])))
				{
					while(!(DIO_u8PinReadValue(KEY_ROW_PORT,KeypadRows[IndexRow]))); /// Wait until the key is released.
					return KeyMap[IndexRow][IndexCol1];
				}
			}
		}
		return 'N';
	#endif

	#if (KEYBAD_TYPE == KEYPAD_4X3)
		for(IndexCol1 = 0 ; IndexCol1 < 4 ; IndexCol1++)
		{
			for(IndexCol2 = 0 ; IndexCol2 < 3 ;IndexCol2++)
				DIO_vidPinWrite(KEY_COL_PORT,KeypadColsD[IndexCol2], HIGH);
			DIO_vidPinWrite(KEY_COL_PORT,KeypadColsD[IndexCol1], LOW);
			for(IndexRow = 0; IndexRow < 4; IndexRow++)
			{
				if(!(DIO_u8PinReadValue(KEY_ROW_PORT,KeypadRowsD[IndexRow])))
				{
					while(!(DIO_u8PinReadValue(KEY_ROW_PORT,KeypadRowsD[IndexRow]))); /// Wait until the key is released.
					return KeyMapD[IndexRow][IndexCol1];
				}
			}
		}
		return 'N';
	#endif












}
