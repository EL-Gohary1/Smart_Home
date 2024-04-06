
#ifndef TIMERS_SERVICES_H_
#define TIMERS_SERVICES_H_




void PWM_Init(OC1A_Mode_type oc1a_mode, OC1B_Mode_type oc1b_mode );
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
void PWM_vOCRB1Duty(u16 duty);
void PWM_vOCRA1Duty(u16 duty);



#endif /* TIMERS_SERVICES_H_ */