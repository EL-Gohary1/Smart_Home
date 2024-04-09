/*
 * LED.h
 *
 * Created: 3/20/2024 8:01:45 PM
 *  Author: lenovo
 */ 


#ifndef LED_H_
#define LED_H_


#define RED_LED          PINB7
#define GREEN_LED        PINA4
#define BLUE_LED         PINA5
#define YELLOW_LED       PINA6

typedef  DIO_Pin_type   Led_t;

void LED_vTurnON(Led_t copy_enumLedName);

void LED_vTurnOFF(Led_t copy_enumLedName);

void LED_vToggle(Led_t copy_enumLedName);




#endif /* LED_H_ */