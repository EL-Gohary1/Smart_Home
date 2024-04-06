/*
 * LED.c
 *
 * Created: 3/20/2024 8:02:10 PM
 *  Author: lenovo
 */

#include "StdType.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "LED.h"



void LED_vTurnON(Led_t copy_enumLedName)
{
	DIO_WritePin(copy_enumLedName,HIGH);
}

void LED_vTurnOFF(Led_t copy_enumLedName)
{
	DIO_WritePin(copy_enumLedName,LOW);
}

void LED_vToggle(Led_t copy_enumLedName)
{
	DIO_TogglePin(copy_enumLedName);
}