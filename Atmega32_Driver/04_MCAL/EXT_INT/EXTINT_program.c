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
#include "../DIO/DIO_interface.h"
#include "EXTINT_interface.h"

void static (*ExtInt_0_Callback) (void);
void static (*ExtInt_1_Callback) (void);


void EXTINT_vidInit( U16 pin, U8 mode )
{
	//Argument check
	if( (		mode != LOW_LEVEL
			&& 	mode != LOGICAL_CHANGE
			&& 	mode != FALLING_EDGE
			&& 	mode != RISING_EDGE)
			|| (pin != INT0 && pin != INT1 && pin != INT2) )
	{ return; }

	// setting interrupt mode and enabling interrupt:
	switch( pin )
	{
	// INT0:PortD,Pin2
	case INT0:

		setGeneralInterrupt();
		// setting pin as input with pull-up:
		DIO_vidPinInDirectionWithPullState(PD,pin2, INTERNAL_PULLUP);

		// ISC00:
		if( mode == LOW_LEVEL || mode == FALLING_EDGE )
			CLR_BIT(MCUCR_REG,ISC00);
		else
			SET_BIT(MCUCR_REG,ISC00);

		// ISC01:
		if( mode == LOW_LEVEL || mode == LOGICAL_CHANGE )
			CLR_BIT( MCUCR_REG, ISC01 );
		else
			SET_BIT( MCUCR_REG, ISC01 );

		// enable interrupt mask in
		SET_BIT( GICR_REG, INT0 );
	break;

	// INT1 PortD,Pin3
	case INT1:

		setGeneralInterrupt();
		// setting pin as input with pull-up:
		DIO_vidPinInDirectionWithPullState(PD,pin3, INTERNAL_PULLUP);

		// ISC10:
		if( mode == LOW_LEVEL || mode == FALLING_EDGE )
			CLR_BIT( MCUCR_REG, ISC10 );
		else
			SET_BIT( MCUCR_REG, ISC10 );

		// ISC11:
		if( mode == LOW_LEVEL || mode == LOGICAL_CHANGE )
			CLR_BIT( MCUCR_REG, ISC11 );
		else
			SET_BIT( MCUCR_REG, ISC11 );

		// enable interrupt mask in
		SET_BIT( GICR_REG, INT1 );
		break;

	// INT2 PortB,Pin2
	case INT2:

		setGeneralInterrupt();
		// setting pin as input with pull-up:
		DIO_vidPinInDirectionWithPullState(PB,pin2, INTERNAL_PULLUP);

		// ISC2
		if( mode == FALLING_EDGE )
			CLR_BIT( MCUCSR_REG, ISC2);
		else if( mode == RISING_EDGE )
			SET_BIT( MCUCSR_REG, ISC2 );

		// enable interrupt mask in
		SET_BIT( GICR_REG, INT2 );
	}
}

void EXTINT_vidSetExt0_Callback(void (*Callback)(void))
{
	ExtInt_0_Callback = Callback ;
}

void EXTINT_vidSetExt1_Callback(void (*Callback)(void))
{
	ExtInt_1_Callback = Callback ;
}



ISR(EXT_INT_0)
{
	ExtInt_0_Callback();
}


ISR(EXT_INT_1)
{
	ExtInt_1_Callback();
}
