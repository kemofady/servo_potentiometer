#ifndef	TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
/*Timer 0*/
void timer_voidiniti();
void timer_voidsetctc0isr(void(*func)(void));
void PWM_voidiniti0();
void pwm_voidsetdutycycle0(u8 cpy_u8val);
/*Timer 1*/
void pwm_voidsetdutycycleA(u16 cpy_u8val);
void PWM_voidinit1();

void ICU_voidinit();
void ICU_voidsencecontrol(u8 state);
u16  ICU_u16readvalue();
void ICU_voidsetcallback(void(*func)(void));
void ICU_voiddisableinterrupt();
#endif
