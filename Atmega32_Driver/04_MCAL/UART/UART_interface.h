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

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#define ENABLE_EVEN_PARITY		0
#define ENABLE_ODD_PARITY		1

#define ONE_BIT					1
#define TWO_BIT					2


void UART_vidInit(void);

void UART_vidTxChar(U8 );

void UART_vidRxChar(U8 *);

 void UART_vidTxString(U8 *);

 void UART_RxString(U8 *);

 void UART_vidTxString_To_CLI(U8 *);

 void UART_vidRxString_From_CLI(U8 *);


#endif /* MCAL_UART_UART_INTERFACE_H_ */
