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
#include "SevenSeg_config.h"
#include "SevenSeg_interface.h"

void static Number0()
{
	DIO_vidPinWrite(A,HIGH);
	DIO_vidPinWrite(B,HIGH);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,HIGH);
	DIO_vidPinWrite(E,HIGH);
	DIO_vidPinWrite(F,HIGH);
	DIO_vidPinWrite(G,LOW);

}

void static Number1()
{
	DIO_vidPinWrite(A,LOW);
	DIO_vidPinWrite(B,HIGH);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,LOW);
	DIO_vidPinWrite(E,LOW);
	DIO_vidPinWrite(F,LOW);
	DIO_vidPinWrite(G,LOW);
}

void static Number2()
{
	DIO_vidPinWrite(A,HIGH);
	DIO_vidPinWrite(B,HIGH);
	DIO_vidPinWrite(C,LOW);
	DIO_vidPinWrite(D,HIGH);
	DIO_vidPinWrite(E,HIGH);
	DIO_vidPinWrite(F,LOW);
	DIO_vidPinWrite(G,HIGH);
}

void static Number3()
{
	DIO_vidPinWrite(A,HIGH);
	DIO_vidPinWrite(B,HIGH);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,HIGH);
	DIO_vidPinWrite(E,LOW);
	DIO_vidPinWrite(F,LOW);
	DIO_vidPinWrite(G,HIGH);
}

void static Number4()
{
	DIO_vidPinWrite(A,LOW);
	DIO_vidPinWrite(B,HIGH);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,LOW);
	DIO_vidPinWrite(E,LOW);
	DIO_vidPinWrite(F,HIGH);
	DIO_vidPinWrite(G,HIGH);
}

void static Number5()
{
	DIO_vidPinWrite(A,HIGH);
	DIO_vidPinWrite(B,LOW);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,HIGH);
	DIO_vidPinWrite(E,LOW);
	DIO_vidPinWrite(F,HIGH);
	DIO_vidPinWrite(G,HIGH);
}

void static Number6()
{
	DIO_vidPinWrite(A,HIGH);
	DIO_vidPinWrite(B,LOW);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,HIGH);
	DIO_vidPinWrite(E,HIGH);
	DIO_vidPinWrite(F,HIGH);
	DIO_vidPinWrite(G,HIGH);
}

void static Number7()
{
	DIO_vidPinWrite(A,HIGH);
	DIO_vidPinWrite(B,HIGH);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,LOW);
	DIO_vidPinWrite(E,LOW);
	DIO_vidPinWrite(F,LOW);
	DIO_vidPinWrite(G,LOW);
}

void static Number8()
{
	DIO_vidPinWrite(A,HIGH);
	DIO_vidPinWrite(B,HIGH);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,HIGH);
	DIO_vidPinWrite(E,HIGH);
	DIO_vidPinWrite(F,HIGH);
	DIO_vidPinWrite(G,HIGH);
}

void static Number9()
{
	DIO_vidPinWrite(A,HIGH);
	DIO_vidPinWrite(B,HIGH);
	DIO_vidPinWrite(C,HIGH);
	DIO_vidPinWrite(D,HIGH);
	DIO_vidPinWrite(E,LOW);
	DIO_vidPinWrite(F,HIGH);
	DIO_vidPinWrite(G,HIGH);
}


void SevenSeg_vidinit()
{
	DIO_vidPinDirection(A, OUTPUT);
	DIO_vidPinDirection(B, OUTPUT);
	DIO_vidPinDirection(C, OUTPUT);
	DIO_vidPinDirection(D, OUTPUT);
	DIO_vidPinDirection(E, OUTPUT);
	DIO_vidPinDirection(F, OUTPUT);
	DIO_vidPinDirection(G, OUTPUT);
	DIO_vidPinDirection(DOT, OUTPUT);

	DIO_vidPinDirection(COM1, OUTPUT);
	DIO_vidPinDirection(COM2, OUTPUT);
	DIO_vidPinDirection(COM3, OUTPUT);
	DIO_vidPinDirection(COM4, OUTPUT);
}

void SevenSeg_1_Control(Bool State)
{
	if (State)
		DIO_vidPinWrite(COM1, HIGH);
	else
		DIO_vidPinWrite(COM1, LOW);
}

void SevenSeg_2_Control(Bool State)
{
	if (State)
		DIO_vidPinWrite(COM2, HIGH);
	else
		DIO_vidPinWrite(COM2, LOW);
}

void SevenSeg_3_Control(Bool State)
{
	if (State)
		DIO_vidPinWrite(COM3, HIGH);
	else
		DIO_vidPinWrite(COM3, LOW);
}

void SevenSeg_4_Control(Bool State)
{
	if (State)
		DIO_vidPinWrite(COM4, HIGH);
	else
		DIO_vidPinWrite(COM4, LOW);
}

void SevenSeg_vidDisplay(Seg_Number Number)
{
	switch(Number)
	{
		case N0: Number0(); break;
		case N1: Number1(); break;
		case N2: Number2(); break;
		case N3: Number3(); break;
		case N4: Number4(); break;
		case N5: Number5(); break;
		case N6: Number6(); break;
		case N7: Number7(); break;
		case N8: Number8(); break;
		case N9: Number9(); break;
	}
}


void SevenSeg_vidCountUp(U8 Time_In_Sec)
{
	U8 i;
	for (i=0;i<10;i++)
	{
		SevenSeg_vidDisplay(i);
		TIM_vidDelay_ms(Time_In_Sec * 1000);
	}
}


void SevenSeg_vidConutDown(U8 Time_In_Sec)
{
	U8 i;
	for (i=9;i>=0;i--)
	{
		SevenSeg_vidDisplay(i);
		TIM_vidDelay_ms(Time_In_Sec * 1000);
	}
}
