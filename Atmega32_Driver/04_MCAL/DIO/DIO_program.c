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
#include "DIO_interface.h"



/*
*******************************************************************************************************
************************************* PORT DIRECTION **************************************************
*******************************************************************************************************
*/
void DIO_vidPortDirection(Port_Name port, Port_Direction direction)
{
    switch (port)
    {
        case PA:
            DDRA_REG = (direction == OUTPUT) ? 0xFF : 0X00;
            break;

        case PB:
            DDRB_REG = (direction == OUTPUT) ? 0xFF : 0X00;
            break;

        case PC:
            DDRC_REG = (direction == OUTPUT) ? 0xFF : 0X00;
            break;

        case PD:
            DDRD_REG = (direction == OUTPUT) ? 0xFF : 0X00;
            break;
    }
}

void DIO_vidPinDirection(Port_Name port, Pin_Number pin, Port_Direction direction)
{
    switch (port)
    {
        case PA:
            (direction == OUTPUT) ? SET_BIT(DDRA_REG, pin) : CLR_BIT(DDRA_REG, pin);
            break;

        case PB:
            (direction == OUTPUT) ? SET_BIT(DDRB_REG, pin) : CLR_BIT(DDRB_REG, pin);
            break;

        case PC:
            (direction == OUTPUT) ? SET_BIT(DDRC_REG, pin) : CLR_BIT(DDRC_REG, pin);
            break;

        case PD:
            (direction == OUTPUT) ? SET_BIT(DDRD_REG, pin) : CLR_BIT(DDRD_REG, pin);
            break;
    }
}

void DIO_vidPinInDirectionWithPullState(Port_Name port, Pin_Number pin, Pull_State pull)
{
    switch (port)
    {
    case PA:
        CLR_BIT(DDRA_REG, pin);
        if (pull == INTERNAL_PULLUP)
        {
            SET_BIT(PORTA_REG, pin);
            CLR_BIT(SFIOR_REG, 2);
        }
        else
        {
            CLR_BIT(PORTA_REG, pin);
            SET_BIT(SFIOR_REG, 2);
        }
        break;

    case PB:
        CLR_BIT(DDRB_REG, pin);
        if (pull == INTERNAL_PULLUP)
        {
            SET_BIT(PORTB_REG, pin);
            CLR_BIT(SFIOR_REG, 2);
        }
        else
        {
            CLR_BIT(PORTB_REG, pin);
            SET_BIT(SFIOR_REG, 2);
        }
        break;

    case PC:
        CLR_BIT(DDRC_REG, pin);
        if (pull == INTERNAL_PULLUP)
        {
            SET_BIT(PORTC_REG, pin);
            CLR_BIT(SFIOR_REG, 2);
        }
        else
        {
            CLR_BIT(PORTC_REG, pin);
            SET_BIT(SFIOR_REG, 2);
        }
        break;

    case PD:
        CLR_BIT(DDRD_REG, pin);
        if (pull == INTERNAL_PULLUP)
        {
            SET_BIT(PORTD_REG, pin);
            CLR_BIT(SFIOR_REG, 2);
        }
        else
        {
            CLR_BIT(PORTD_REG, pin);
            SET_BIT(SFIOR_REG, 2);
        }
        break;
    }
}

void DIO_vidPortRangeDirection(Port_Name port, Pin_Number stPin, Pin_Number endPin, Port_Direction direction)
{
    U16 i;

    switch (port)
    {
    case PA:
        for (i = stPin; i <= endPin; i++)
            SET_BIT(DDRA_REG, i);
        break;

    case PB:
        for (i = stPin; i <= endPin; i++)
            SET_BIT(DDRB_REG, i);
        break;

    case PC:
        for (i = stPin; i <= endPin; i++)
            SET_BIT(DDRC_REG, i);
        break;

    case PD:
        for (i = stPin; i <= endPin; i++)
            SET_BIT(DDRD_REG, i);
        break;
    }
}

/*
*******************************************************************************************************
************************************* WRITING TO PORT *************************************************
*******************************************************************************************************
*/

void DIO_vidPortWrite(Port_Name port, PinState value)
{
    switch (port)
    {
    case PA:
        PORTA_REG = (value == HIGH) ? 0xFF : 0X00;
        break;

    case PB:
        PORTB_REG = (value == HIGH) ? 0xFF : 0X00;
        break;

    case PC:
        PORTC_REG = (value == HIGH) ? 0xFF : 0X00;
        break;

    case PD:
        PORTD_REG = (value == HIGH) ? 0xFF : 0X00;
        break;
    }
}

void DIO_vidPinWrite(Port_Name port, Pin_Number pin, PinState value)
{

    switch (port)
    {
    case PA:
        (value == HIGH) ? SET_BIT(PORTA_REG, pin) : CLR_BIT(PORTA_REG, pin);
        break;

    case PB:
        (value == HIGH) ? SET_BIT(PORTB_REG, pin) : CLR_BIT(PORTB_REG, pin);
        break;

    case PC:
        (value == HIGH) ? SET_BIT(PORTC_REG, pin) : CLR_BIT(PORTC_REG, pin);
        break;

    case PD:
        (value == HIGH) ? SET_BIT(PORTD_REG, pin) : CLR_BIT(PORTD_REG, pin);
        break;
    }
}

void DIO_vidPortRangeWrite(Port_Name port, Pin_Number stPin, Pin_Number endPin, PinState value)
{
    U16 i;
    switch (port)
    {
    case PA:
        if (value == HIGH)
            for (i = stPin; i <= endPin; i++)
                SET_BIT(PORTA_REG, i);
        else
            for (i = stPin; i <= endPin; i++)
                CLR_BIT(PORTA_REG, i);
        break;

    case PB:
        if (value == HIGH)
            for (i = stPin; i <= endPin; i++)
                SET_BIT(PORTB_REG, i);
        else
            for (i = stPin; i <= endPin; i++)
                CLR_BIT(PORTB_REG, i);
        break;

    case PC:
        if (value == HIGH)
            for (i = stPin; i <= endPin; i++)
                SET_BIT(PORTC_REG, i);
        else
            for (i = stPin; i <= endPin; i++)
                CLR_BIT(PORTC_REG, i);
        break;

    case PD:
        if (value == HIGH)
            for (i = stPin; i <= endPin; i++)
                SET_BIT(PORTD_REG, i);
        else
            for (i = stPin; i <= endPin; i++)
                CLR_BIT(PORTD_REG, i);
        break;
    }
}

/*
*******************************************************************************************************
************************************* READING FROM PORT ***********************************************
*******************************************************************************************************
*/

void DIO_vidPortRead(Port_Name port, U8 *value)
{

    switch (port)
    {
    case PA:
        *value = PINA_REG;
        break;

    case PB:
        *value = PINB_REG;
        break;

    case PC:
        *value = PINC_REG;
        break;

    case PD:
        *value = PIND_REG;
        break;
    }
}

void DIO_vidPinRead(Port_Name port, Pin_Number pin, U8 *pinValue)
{

    switch (port)
    {
    case PA:
        *pinValue = GET_BIT(PINA_REG, pin);
        break;

    case PB:
        *pinValue = GET_BIT(PINB_REG, pin);
        break;

    case PC:
        *pinValue = GET_BIT(PINC_REG, pin);
        break;

    case PD:
        *pinValue = GET_BIT(PIND_REG, pin);
        break;
    }
}

U8 DIO_u8PinReadValue(Port_Name port, Pin_Number pin)
{

    switch (port)
    {
    case PA:
        return GET_BIT(PINA_REG, pin);
        break;

    case PB:
        return GET_BIT(PINB_REG, pin);
        break;

    case PC:
        return GET_BIT(PINC_REG, pin);
        break;

    case PD:
        return GET_BIT(PIND_REG, pin);
        break;
    }

    return 'X';
}

void DIO_vidPortRangeRead(Port_Name port, Pin_Number stPin, Pin_Number endPin, U8 *pinValue)
{
    U16 i;

    switch (port)
    {
    case PA:
        *pinValue = 0x00;
        for (i = stPin; i <= endPin; i++)
            *pinValue = GET_BIT(PINA_REG, i);
        break;

    case PB:
        *pinValue = 0x00;
        for (i = stPin; i <= endPin; i++)
            *pinValue = GET_BIT(PINB_REG, i);
        break;

    case PC:
        *pinValue = 0x00;
        for (i = stPin; i <= endPin; i++)
            *pinValue = GET_BIT(PINC_REG, i);
        break;

    case PD:
        *pinValue = 0x00;
        for (i = stPin; i <= endPin; i++)
            *pinValue = GET_BIT(PIND_REG, i);
        break;
    }
}

/*
*******************************************************************************************************
******************************************* TOGGLE PORT ***********************************************
*******************************************************************************************************
*/

void DIO_vidPortToggle(Port_Name port)
{
    U16 i;
    switch (port)
    {
    case PA:
        for (i = 0; i <= 8; i++)
            TOG_BIT(PORTA_REG, i);
        break;

    case PB:
        for (i = 0; i <= 8; i++)
            TOG_BIT(PORTB_REG, i);
        break;

    case PC:
        for (i = 0; i <= 8; i++)
            TOG_BIT(PORTC_REG, i);
        break;

    case PD:
        for (i = 0; i <= 8; i++)
            TOG_BIT(PORTD_REG, i);
        break;
    }
}

void DIO_vidPinToggle(Port_Name port, Pin_Number pin)
{

    switch (port)
    {
    case PA:
        TOG_BIT(PORTA_REG, pin);
        break;

    case PB:
        TOG_BIT(PORTB_REG, pin);
        break;

    case PC:
        TOG_BIT(PORTC_REG, pin);
        break;

    case PD:
        TOG_BIT(PORTD_REG, pin);
        break;
    }
}

void DIO_vidPortRangeToggle(Port_Name port, Pin_Number stPin, Pin_Number endPin)
{
    U16 i;
    switch (port)
    {
    case PA:
        for (i = stPin; i <= endPin; i++)
            TOG_BIT(PORTA_REG, i);
        break;

    case PB:
        for (i = stPin; i <= endPin; i++)
            TOG_BIT(PORTB_REG, i);
        break;

    case PC:
        for (i = stPin; i <= endPin; i++)
            TOG_BIT(PORTC_REG, i);
        break;

    case PD:
        for (i = stPin; i <= endPin; i++)
            TOG_BIT(PORTD_REG, i);
        break;
    }
}
