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

#include "Relay_config.h"
#include "Relay_interface.h"

void Relay_vidInit()
{
	#if (RELAY_0_STATE == ENABLE)
		DIO_vidPinDirection(RELAY_0_CONNE, OUTPUT);
	#endif
	#if (RELAY_1_STATE == ENABLE)
		DIO_vidPinDirection(RELAY_1_CONNE, OUTPUT);
	#endif
	#if (RELAY_2_STATE == ENABLE)
		DIO_vidPinDirection(RELAY_2_CONNE, OUTPUT);
	#endif
	#if (RELAY_3_STATE == ENABLE)
		DIO_vidPinDirection(RELAY_3_CONNE, OUTPUT);
	#endif
	#if (RELAY_4_STATE == ENABLE)
		DIO_vidPinDirection(RELAY_4_CONNE, OUTPUT);
	#endif
	#if (RELAY_5_STATE == ENABLE)
		DIO_vidPinDirection(RELAY_5_CONNE, OUTPUT);
	#endif
	#if (RELAY_6_STATE == ENABLE)
		DIO_vidPinDirection(RELAY_6_CONNE, OUTPUT);
	#endif
	#if (RELAY_7_STATE == ENABLE)
		DIO_vidPinDirection(RELAY_7_CONNE, OUTPUT);
	#endif
}

void Relay_vidTurnOn(Relay_No RelaySel)
{
	switch (RelaySel)
	{
		case R0:
			DIO_vidPinWrite(RELAY_0_CONNE, HIGH);
		break;

		case R1:
		DIO_vidPinWrite(RELAY_1_CONNE, HIGH);
		break;

		case R2:
		DIO_vidPinWrite(RELAY_2_CONNE, HIGH);
		break;

		case R3:
		DIO_vidPinWrite(RELAY_3_CONNE, HIGH);
		break;

		case R4:
		DIO_vidPinWrite(RELAY_4_CONNE, HIGH);
		break;

		case R5:
		DIO_vidPinWrite(RELAY_5_CONNE, HIGH);
		break;

		case R6:
		DIO_vidPinWrite(RELAY_6_CONNE, HIGH);
		break;


		default:
		DIO_vidPinWrite(RELAY_7_CONNE, HIGH);
		break;
	}
}

void Relay_vidTurnOff(Relay_No RelaySel)
{
	switch (RelaySel)
	{
	case R0:
		DIO_vidPinWrite(RELAY_0_CONNE, LOW);
		break;

	case R1:
		DIO_vidPinWrite(RELAY_1_CONNE, LOW);
		break;

	case R2:
		DIO_vidPinWrite(RELAY_2_CONNE, LOW);
		break;

	case R3:
		DIO_vidPinWrite(RELAY_3_CONNE, LOW);
		break;

	case R4:
		DIO_vidPinWrite(RELAY_4_CONNE, LOW);
		break;

	case R5:
		DIO_vidPinWrite(RELAY_5_CONNE, LOW);
		break;

	case R6:
		DIO_vidPinWrite(RELAY_6_CONNE, LOW);
		break;

	default:
		DIO_vidPinWrite(RELAY_7_CONNE, LOW);
		break;
	}
}

void Relay_vidOnDelay(Relay_No RelaySel, U16 Time_Delay_Ms)
{
	switch (RelaySel)
	{
		case R0:
			DIO_vidPinWrite(RELAY_0_CONNE, LOW);
			TIM_vidDelay_ms(Time_Delay_Ms);
			DIO_vidPinWrite(RELAY_0_CONNE, HIGH);
			TIM_vidDelay_ms(Time_Delay_Ms);
		break;

		case R1:
			DIO_vidPinWrite(RELAY_1_CONNE, LOW);
			TIM_vidDelay_ms(Time_Delay_Ms);
			DIO_vidPinWrite(RELAY_1_CONNE, HIGH);
			TIM_vidDelay_ms(Time_Delay_Ms);
		break;

		case R2:
			DIO_vidPinWrite(RELAY_2_CONNE, LOW);
			TIM_vidDelay_ms(Time_Delay_Ms);
			DIO_vidPinWrite(RELAY_2_CONNE, HIGH);
			TIM_vidDelay_ms(Time_Delay_Ms);
		break;

		case R3:
			DIO_vidPinWrite(RELAY_3_CONNE, LOW);
			TIM_vidDelay_ms(Time_Delay_Ms);
			DIO_vidPinWrite(RELAY_3_CONNE, HIGH);
			TIM_vidDelay_ms(Time_Delay_Ms);
		break;

		case R4:
			DIO_vidPinWrite(RELAY_4_CONNE, LOW);
			TIM_vidDelay_ms(Time_Delay_Ms);
			DIO_vidPinWrite(RELAY_4_CONNE, HIGH);
			TIM_vidDelay_ms(Time_Delay_Ms);
		break;

		case R5:
			DIO_vidPinWrite(RELAY_5_CONNE, LOW);
			TIM_vidDelay_ms(Time_Delay_Ms);
			DIO_vidPinWrite(RELAY_5_CONNE, HIGH);
			TIM_vidDelay_ms(Time_Delay_Ms);
		break;

		case R6:
			DIO_vidPinWrite(RELAY_6_CONNE, LOW);
			TIM_vidDelay_ms(Time_Delay_Ms);
			DIO_vidPinWrite(RELAY_6_CONNE, HIGH);
			TIM_vidDelay_ms(Time_Delay_Ms);
		break;


		default:
			DIO_vidPinWrite(RELAY_7_CONNE, LOW);
			TIM_vidDelay_ms(Time_Delay_Ms);
			DIO_vidPinWrite(RELAY_7_CONNE, HIGH);
			TIM_vidDelay_ms(Time_Delay_Ms);
		break;
	}
}

void Relay_vidOffDelay(Relay_No RelaySel, U16 Time_Delay_Ms)
{
	switch (RelaySel)
	{
	case R0:
		DIO_vidPinWrite(RELAY_0_CONNE, HIGH);
		TIM_vidDelay_ms(Time_Delay_Ms);
		DIO_vidPinWrite(RELAY_0_CONNE, LOW);
		TIM_vidDelay_ms(Time_Delay_Ms);
		break;

	case R1:
		DIO_vidPinWrite(RELAY_1_CONNE, HIGH);
		TIM_vidDelay_ms(Time_Delay_Ms);
		DIO_vidPinWrite(RELAY_1_CONNE, LOW);
		TIM_vidDelay_ms(Time_Delay_Ms);
		break;

	case R2:
		DIO_vidPinWrite(RELAY_2_CONNE, HIGH);
		TIM_vidDelay_ms(Time_Delay_Ms);
		DIO_vidPinWrite(RELAY_2_CONNE, LOW);
		TIM_vidDelay_ms(Time_Delay_Ms);
		break;

	case R3:
		DIO_vidPinWrite(RELAY_3_CONNE, HIGH);
		TIM_vidDelay_ms(Time_Delay_Ms);
		DIO_vidPinWrite(RELAY_3_CONNE, LOW);
		TIM_vidDelay_ms(Time_Delay_Ms);
		break;

	case R4:
		DIO_vidPinWrite(RELAY_4_CONNE, HIGH);
		TIM_vidDelay_ms(Time_Delay_Ms);
		DIO_vidPinWrite(RELAY_4_CONNE, LOW);
		TIM_vidDelay_ms(Time_Delay_Ms);
		break;

	case R5:
		DIO_vidPinWrite(RELAY_5_CONNE, HIGH);
		TIM_vidDelay_ms(Time_Delay_Ms);
		DIO_vidPinWrite(RELAY_5_CONNE, LOW);
		TIM_vidDelay_ms(Time_Delay_Ms);
		break;

	case R6:
		DIO_vidPinWrite(RELAY_6_CONNE, HIGH);
		TIM_vidDelay_ms(Time_Delay_Ms);
		DIO_vidPinWrite(RELAY_6_CONNE, LOW);
		TIM_vidDelay_ms(Time_Delay_Ms);
		break;

	default:
		DIO_vidPinWrite(RELAY_7_CONNE, HIGH);
		TIM_vidDelay_ms(Time_Delay_Ms);
		DIO_vidPinWrite(RELAY_7_CONNE, LOW);
		TIM_vidDelay_ms(Time_Delay_Ms);
		break;
	}
}