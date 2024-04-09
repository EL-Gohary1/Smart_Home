/*
 * LM35.h
 *
 * Created: 3/7/2024 10:03:08 AM
 *  Author: lenovo
 */ 
#ifndef LM35_H_
#define LM35_H_


/*Select Channel of POT
ADC0
ADC1
ADC2
ADC3
ADC4
ADC5
ADC6
ADC7
*/

#define LM35_CH   ADC1

typedef enum{
	LVref_AREV,
	LVref_AVCC,
	LVref_265
}LM35_Vref_t;
 

u8 LM35_u8ReadTemp(LM35_Vref_t copy_enumVref,u16 Copy_u16VoltRefmv);

#endif

