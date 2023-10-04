

#include"STD_TYPES.h"
#include"BIT_MATH.h"


#include"ADC_reg.h"
#include"ADC_interface.h"
#include"ADC_confg.h"
#include"ADC_privet.h"

void(*callback)(void);
u8 *adcvalue;


void ADC_voidinti(){
	//SELECT VCC as max volt
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	//TO work with 8bit mode
	SET_BIT(ADMUX,5);

	SET_BIT(ADCSRA,7); //ENABLE ADC
	CLR_BIT(ADCSRA,5); //Disable auto trigger
	CLR_BIT(ADCSRA,3);  //disable interrupt

	/* select prescaller(freq) */
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);


}

u8 ADC_u8readvalueAsynch(u8 cpy_u8channel,u8 *adc_read,void(*func)(void)){

	/*select channel */
	ADMUX &=0b11100000;  //clear frist 5 bits
	ADMUX |=cpy_u8channel;

	//start channel
	SET_BIT(ADCSRA,6);

	adcvalue=adc_read;
	callback=func;

	SET_BIT(SREG,7);
	SET_BIT(ADCSRA,3);


}
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
	*adcvalue=ADCH;
	callback();

}



u8 ADC_u8readvalue(u8 cpy_u8channel){
	/*select channel */
	ADMUX &=0b11100000;  //clear frist 5 bits
	ADMUX |=cpy_u8channel;

	//start channel
	SET_BIT(ADCSRA,6);

	/* wait till finish */
	while(GET_BIT(ADCSRA,4)==0){}

	/*  STOP ,CLEAR FLAG*/
	CLR_BIT(ADCSRA,6);
	SET_BIT(ADCSRA,4);

	return ADCH;
}
