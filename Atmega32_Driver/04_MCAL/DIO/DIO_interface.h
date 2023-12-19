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

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

void DIO_vidPortDirection(Port_Name port, Port_Direction direction);
void DIO_vidPinDirection(Port_Name port, Pin_Number pin, Port_Direction direction);
void DIO_vidPinInDirectionWithPullState(Port_Name port, Pin_Number pin, Pull_State pull);
void DIO_vidPortRangeDirection(Port_Name port, Pin_Number stPin, Pin_Number endPin, Port_Direction direction);


void DIO_vidPortWrite(Port_Name port, PinState value);
void DIO_vidPinWrite(Port_Name port, Pin_Number pin, PinState value);
void DIO_vidPortRangeWrite(Port_Name port, Pin_Number stPin, Pin_Number endPin, PinState value);


void DIO_vidPortRead(Port_Name port, U8 *value);
void DIO_vidPinRead(Port_Name port, Pin_Number pin, U8 *pinValue);
U8 DIO_u8PinReadValue(Port_Name port, Pin_Number pin);
void DIO_vidPortRangeRead(Port_Name port, Pin_Number stPin, Pin_Number endPin, U8 *pinValue);


void DIO_vidPortToggle(Port_Name port);
void DIO_vidPinToggle(Port_Name port, Pin_Number pin);
void DIO_vidPortRangeToggle(Port_Name port, Pin_Number stPin, Pin_Number endPin);


#endif /*__DIO_INTERFACE_H_*/
