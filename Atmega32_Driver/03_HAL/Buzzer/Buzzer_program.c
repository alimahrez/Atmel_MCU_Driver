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
#include "Buzzer_interface.h"
#include "Buzzer_config.h"

void Buzzer_vidInit()
{
	DIO_vidPinDirection(BUZZER, OUTPUT);
}

void Buzzer_vidTurnOn()
{
	DIO_vidPinWrite(BUZZER, HIGH);
}

void Buzzer_vidTurnOff()
{
	DIO_vidPinWrite(BUZZER, LOW);
}

void Buzzer_vidFixedTone(U16 Local_MilSec)
{
	Buzzer_vidTurnOn();
	TIM_vidDelay_ms(Local_MilSec);
	Buzzer_vidTurnOff();
	TIM_vidDelay_ms(Local_MilSec);
}
