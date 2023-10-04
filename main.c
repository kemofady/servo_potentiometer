/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Ali Othman
 */

/*****************************************************/
/* 1 - include libraries */
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "avr/delay.h"

/* 2 - include MCAL */
#include "DIO_driver/Dio_Interface.h"
#include "TIMER_driver/timer_interface.h"
#include "GIE_driver/Gie_interface.h"
#include "ADC_driver_karim/ADC_interface.h"

#include"servo.h"
void main()
{
	u8 ADC_read;
	u16 read_mapped;
	ADC_voidinti();
	PWM_voidinit1();

	Dio_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);



	while(1)
	{

		ADC_read=ADC_u8readvalue(0);
		read_mapped=map(0, 255, 500, 2500, ADC_read);
	    pwm_voidsetdutycycleA(read_mapped);

	}
}
