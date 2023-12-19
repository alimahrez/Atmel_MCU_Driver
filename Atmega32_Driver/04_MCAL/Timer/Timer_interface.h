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

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#ifndef F_CPU
# define F_CPU 16000000UL
#endif

#define INVERTING_PWM			0
#define NON_INVERTING_PWM		1

void TIM_vidDelay_ms(double);
void TIM_vidDelay_us(double);
void TIM_vidPWM_PB3_Init(void);
void TIM_vidPWM_PD7_Init(void);
void TIM_vidPWM_PB3_Generate(U16);
void TIM_vidPWM_PD7_Generate(U16);


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
