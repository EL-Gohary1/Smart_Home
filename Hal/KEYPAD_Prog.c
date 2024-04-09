#include "KEYPAD.h"
#include "DIO_Interface.h"

void KEYPAD_Init(void)
{
	
}

#define  F_CPU 16000000
#include "util\delay.h"

u8 KEYPAD_GetEntry(void)
{
	u8 key=KEY_DEFAULT;
	u8 IR=3;
	for(u8 r=0;r<ROW;r++)
	{
		DIO_WritePin(OUTPUT4+r,HIGH);
	}
	for(u8 r=0;r<ROW;r++)
	{ 		
		DIO_WritePin(OUTPUT4+r,LOW);

			if (!DIO_ReadPin(INPUT4))
			{
				while(!DIO_ReadPin(INPUT4));
				key=KeysArray[IR][3];
			}
			if (!DIO_ReadPin(INPUT3))
			{
				while(!DIO_ReadPin(INPUT3));
				key=KeysArray[IR][2];
			}
			if (!DIO_ReadPin(INPUT2))
			{
				while(!DIO_ReadPin(INPUT2));
				key=KeysArray[IR][1];
			}
			if (!DIO_ReadPin(INPUT1))
			{
				while(!DIO_ReadPin(INPUT1));
				key=KeysArray[IR][0];
			}
		DIO_WritePin(OUTPUT4+r,HIGH);	
		IR--;
		if(IR>3)
		IR=3;
	}
	return key;
}


