/*
 * SmartLigthControlSystem.c
 *
 * Created: 3/10/2024 9:08:03 PM
 *  Author: lenovo
 */ 
#include "KEYPAD.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LED.h"
#include "LDR.h"

void SmartLigthControlSystem_vSmartLigthInit(void)
{
	LCD_vGoToCollRow(0,0);
	LCD_vWriteString((u8*)"LDR VALUE:");
	LCD_vWriteInteger(LDR_vLDRPrecentage());
	LCD_vGoToCollRow(0,1);
	LCD_vWriteString((u8*)"threshold:");
}

void SmartLigthControlSystem_vSmartLigthRunnable(void)
{
	u8 local_u8threshold = 0;
	u8 local_u8flag   = 0;
	static s8 Threshold=-1;
	LCD_vGoToCollRow(10,0);
	LCD_vWriteString((u8*)"   ");
	LCD_vGoToCollRow(10,0);
	LCD_vWriteInteger(LDR_vLDRPrecentage());   //update LDR percentage
	LCD_vGoToCollRow(10,1);
	while (Threshold==-1)  //take two number from 0 to 9
	{
		u8 button=KEYPAD_GetEntry();
		if (button!=KEY_DEFAULT && button!='*' && button!='/'  && button!='+' && button!='-' && button!='=' && button!='c')
		{
			LCD_vWriteChar(button);
            local_u8threshold=local_u8threshold*10+button-'0';
			local_u8flag++;
		}
		if (local_u8flag==2)
		{
			Threshold=local_u8threshold;
		}
	}
	if (LDR_vLDRPrecentage()>Threshold)
	{
	   LED_vTurnOFF(BLUE_LED);
	    //DIO_WritePin(PINA5,LOW);	 //led off
	}
	else if (LDR_vLDRPrecentage()<Threshold)
	{
	    LED_vTurnON(BLUE_LED);
		DIO_WritePin(PINA5,HIGH); //led on
	}
	else
	{
		//nothing
	}
	u8 v=KEYPAD_GetEntry();
	if (v =='c')   //to change threshold
	{
		Threshold=-1;
		LCD_vGoToCollRow(10,1);
		LCD_vWriteString((u8*)"   ");
	}
}