#include "Utils.h"
#include "StdType.h"
#include "DIO_interface.h"
#include "USART_SERVICE.h"

#include "LCD_interface.h"
#include "LED.h"
#include "Servo.h"

#include "Control_System.h"

extern	volatile String_t USART_SERVICE_RX_Buffer1[10];
extern	volatile u8 USART_SERVICE_RXIndex;

/*Array of struct of Control_System_Command_t 
which contains string of command and pointer to func for this command*/
static Control_System_Command_t ArrayOFCommand[]={
	{"LEDON" , LED_vTurnON },
	{"LEDOFF", LED_vTurnOFF},
	{"SERVO" , Servo_voidOn},
	{"LCD"   , LCD_vWriteInteger},
};


static bool_type CompareStr(u8*str1,u8*str2)
{
	for (u8 i=0; str1[i] || str2[i]; i++)
	{
	    if (str1[i]!=str2[i])
	    {
			return FALSE;
	    }
	}
	return TRUE;
}

//Global variable to store command after separate
static u8 Control_System_SeparateCommand[20];   

//func to check command is true
static bool_type Control_System_u8CheckCommand(u8* Copy_pu8Index)
{
		for (u8 j=0; j<4 ;j++)
		{
			if (CompareStr(Control_System_SeparateCommand,ArrayOFCommand[j].Command))
			{
				*Copy_pu8Index=j;
				return TRUE;
			}
		}
		return FALSE;
}

//func to check Received has true format
static bool_type Control_System_u8CheckFormat(void)
{
	u8 local_u8Index=0;
	for ( local_u8Index=0; USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[local_u8Index]!=' ' ; local_u8Index++)
	{
		if ( (USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[local_u8Index] >='A') && (USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[local_u8Index] <='Z'))
		{
			//nothing
		}
		else
		{
			return FALSE;
		}	
	}
	for (local_u8Index=local_u8Index+1 ; USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[local_u8Index]!=0 ;local_u8Index++)
	{
		//
		if ( USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[local_u8Index] >='0' && USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[local_u8Index] <='9')
		{
			//nothing
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}

void Control_System_vInit(void)
{
    USART_SERVICE_vReciveStringAsynchronous();
}


void Control_System_vRunnable(void)
{
    u8 Local_u8Index=0;
    u8 Local_u8Num=0;
    u8 j=0;
   if (USART_SERVICE_RXIndex>0)
   {
	   USART_SERVICE_RXIndex--;
	   //check if format correct
	   if (Control_System_u8CheckFormat()==TRUE)
	   {
		   //separate command and and number
		   for ( j=0; USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[j]!=' ' ;j++)
		   {
			   Control_System_SeparateCommand[j] = USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[j];
		   }
		   //ADD Null   
		   Control_System_SeparateCommand[j]=0;
		   for(j=j+1 ;USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[j]!=0; j++)
		   {
			   Local_u8Num = Local_u8Num*10+USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[j]-'0';
		   }
		   
		   //Check Command is true
		   if (Control_System_u8CheckCommand(&Local_u8Index)==TRUE)
		   {
			   //Check if the command isn't for Led 
			   if (Local_u8Index>1)
			   {
				   ArrayOFCommand[Local_u8Index].PtrF(Local_u8Num);
			   }
			   else
			   {
				   //Check number of led one of RED_LED    GREEN_LED  	BLUE_LED   	YELLOW_LED 
				   if (Local_u8Num>=RED_LED && Local_u8Num<=YELLOW_LED)
				   {
					   ArrayOFCommand[Local_u8Index].PtrF(Local_u8Num);
				   }
				   else
				   {
					   //Error State this led is unavailable
				   }
			   }
		   }
	   }
   }
}

