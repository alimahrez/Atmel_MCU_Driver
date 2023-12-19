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
#include "../../02_LIB/bitmath.h"
#include "../../02_LIB/atmega32_Registers.h"
#include "../../02_LIB/interrupt.h"

#include "UART_interface.h"
#include "UART_config.h"

#define BAUD_PRESCALE_1X 	(((F_CPU / (BAUD_RATE * 16UL))) - 1)
#define BAUD_PRESCALE_1X 	(((F_CPU / (BAUD_RATE * 16UL))) - 1)



void UART_vidInit(void)
{
	(DOUBLE_TX_SPEED == ENABLE) ? (SET_BIT(UCSRA_REG,U2X)) : (CLR_BIT(UCSRA_REG,U2X));
	(FRAME_STOP_BITS == TWO_BIT) ? (SET_BIT(UCSRC_REG,USBS)) : (CLR_BIT(UCSRC_REG,USBS));

	UCSRB_REG |= (1 << RXEN) | (1 << TXEN);
	UCSRC_REG |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

	if(DOUBLE_TX_SPEED == DISABLE)
	{
		UBRRH_REG =	(BAUD_PRESCALE_1X >> 8);
		UBRRL_REG =	BAUD_PRESCALE_1X;
	}
	else
	{
		UBRRH_REG =	(BAUD_PRESCALE_1X >> 8);
		UBRRL_REG =	BAUD_PRESCALE_1X;
	}

}

void UART_vidTxChar(U8 data)
{
	while (( UCSRA_REG & (1 << UDRE)) == 0);
	UDR_REG = data;
}

void UART_vidRxChar(U8 * Ch)
{
	while(((UCSRA_REG) & (1 << RXC)) == 0);
	* Ch = UDR_REG;
}

void UART_vidTxString(U8 *str)
{
	while(*str != '\0')
	{
		UART_vidTxChar(*str);
		str++;
	}
}

void UART_vidRxString(U8 *str)
{
	int i = 0;
	UART_vidRxChar(&str[i]);

	while(str[i] != 0x0D)
	{
		i++;
		UART_vidRxChar(&str[i]);
	}
	str[i] = '\0';
}

void UART_vidTxString_To_CLI(U8 *str)
{
	while(*str != '\0')
	{
		UART_vidTxChar(*str);
		str++;
	}

	UART_vidTxString("\r");
	UART_vidTxString("\n");
}

void UART_vidRxString_From_CLI(U8 *str)
{
	int i = 0;
	UART_vidRxChar(&str[i]);
	UART_vidTxChar(str[i]);

	while(str[i] != 0x0D)
	{
		i++;
		UART_vidRxChar(&str[i]);
		UART_vidTxChar(str[i]);
	}
	UART_vidTxString("\r\n");
	str[i] = '\0';
}

