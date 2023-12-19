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

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_CLEAR_CMD					0X01U
#define LCD_RETURN_HOME_CMD				0X80U
#define LCD_CURSOR_OFF_CMD				0X0CU
#define LCD_UNDERLINE_ON_CMD			0X0EU
#define LCD_BLINK_CURSOR_ON_CMD			0X0FU
#define LCD_TURN_ON_CMD					0X0CU
#define LCD_TURN_OFF_CMD				0X08U
#define LCD_SHIFT_LIFT_CMD				0X18U
#define LCD_SHIFT_RIGHT_CMD				0X1CU
#define LCD_CURSOR_SHIFT_LIFT_CMD		0X10U
#define LCD_CURSOR_SHIFT_RIGHT_CMD		0X14U

#define INITIALIZATION_MODE_1			0X33U
#define INITIALIZATION_MODE_2			0X32U
#define INITIALIZATION_MODE_3			0X28U
#define INITIALIZATION_MODE_4			0X0CU
#define INITIALIZATION_MODE_5			0X01U

#define LCD_ROW_1						0U
#define LCD_ROW_2						1U


#define LCD_POSITION_1					0U
#define LCD_POSITION_2					1U
#define LCD_POSITION_3					2U
#define LCD_POSITION_4					3U
#define LCD_POSITION_5					4U
#define LCD_POSITION_6					5U
#define LCD_POSITION_7					6U
#define LCD_POSITION_8					7U
#define LCD_POSITION_9					8U
#define LCD_POSITION_10					9U
#define LCD_POSITION_11					10U
#define LCD_POSITION_12					11U
#define LCD_POSITION_13					12U
#define LCD_POSITION_14					13U
#define LCD_POSITION_15					14U
#define LCD_POSITION_16					15U

void LCD_vidInit(void);
void LCD_vidWriteCharacter(U8 Character);
void LCD_vidWriteString(U8 *str);
void LCD_vidSetCursor(U8 row, U8 position);
void LCD_vidClear(void);

#endif /* LCD_INTERFACE_H_ */
