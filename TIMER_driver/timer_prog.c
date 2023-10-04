#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"timer_reg.h"
#include"timer_interface.h"
void(*callback_ICU)(void);
void(*callback)(void);
void timer_voidiniti(){
	/*choose ctc mode*/
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

	OCR0=250;  //ctc value to send interrupt


	/*enable interrupt*/
	SET_BIT(TIMSK,1);  //SIE
	SET_BIT(SREG,7);	//GIE

	/*choose prescaller*/
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);


}

void timer_voidsetctc0isr(void(*func)(void))
{
	callback=func;

}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
if(callback !='\0'){
	callback();
}

}


void PWM_voidiniti0()
{
	//select mode fast pwm
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	//selsct non inverting
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);
	//p.s=8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);


}
void PWM_voidinit1()
{
	/* select the mode FAST PWM*/
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	/* Non inverting */
	SET_BIT(TCCR1A, 7);
	CLR_BIT(TCCR1A, 6);

	/* PS = 8 */
	CLR_BIT(TCCR1B, 0);
	SET_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);

	/* determine the max*/
	ICR1 = 20000;


}
void pwm_voidsetdutycycleA(u16 cpy_u16val)
{
	/*Output Compare Register 1 A*/
	OCR1A=cpy_u16val;
}



void pwm_voidsetdutycycle0(u8 cpy_u8val)
{
	/*Output Compare for timer 0*/
	OCR0=cpy_u8val;
}

void ICU_voidinit(){
	/*set rising edge*/
	SET_BIT(TCCR1B,6);
	/*enable interrupt*/
	SET_BIT(TIMSK,5);
	/*p.s 8*/
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

void ICU_voidsencecontrol(u8 state)

{
	if(state==0){
		CLR_BIT(TCCR1B,6);
	}
	else{
		SET_BIT(TCCR1B,6);
	}
}
u16 ICU_u16readvalue()
{
return 	ICR1;
}

void ICU_voidsetcallback(void(*func)(void))
{
	callback_ICU=func;

	}
void ICU_voiddisableinterrupt()
{
	/*enable interrupt*/
	CLR_BIT(TIMSK,5);  //SIE
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void){
	//Dio_voidSetPinValue(DIO_PORTD,DIO_PIN7,1);
if(callback_ICU !='\0'){
	callback_ICU();
}

}
