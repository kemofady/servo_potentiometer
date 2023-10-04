#ifndef	TIMER_REG_H_
#define	TIMER_REG_H_

/*TIMER 0*/
#define TIMSK 	(*((volatile u8 *)0x59))	//enable interrupt
#define TIFR 	(*((volatile u8 *)0x58))	//interrupt flag
#define OCR0  	(*((volatile u8 *)0x5C))	//compare match
#define TCCR0 	(*((volatile u8 *)0x53))	//control
#define TCNT0 	(*((volatile u8 *)0x52))	//timer counter
#define SREG	(*((volatile u8 *)0x5F))
/*TIMER 1*/
#define TCCR1A	(*((volatile u8 *)0x4F)) /*Timer1 control regA*/
#define TCCR1B	(*((volatile u8 *)0x4E)) /*Timer1 control regB*/
#define TCNT1	(*((volatile u16 *)0x4C))
#define OCR1A	(*((volatile u16 *)0x4A)) /*Output Compare Register 1 A*/
#define OCR1B	(*((volatile u16 *)0x48)) /*Output Compare Register 1 B*/
#define ICR1	(*((volatile u16 *)0x46)) /*Input Capture Register 1: Input Capture can be used for defining the counter TOP value.*/

#endif
