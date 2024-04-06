/*
 * USART_SERVICE.c
 *
 * Created: 3/22/2024 4:51:08 PM
 *  Author: lenovo
 */ 
#include "Utils.h"
#include "Mem_Map32.h"
#include "StdType.h"
#include "UART_Interface.h"
#include "USART_SERVICE.h"


volatile u8* USART_SERVICE_pu8TX[TXSize];
static volatile u8 Busyflag=0;

static void USART_SEVICE_vTX(void)
{
	static u8 i=1;
	static u8 j=0;
	if (USART_SERVICE_pu8TX[j][i]==0)
	{
		j++;
		if (Busyflag>0)
		{
			i=0;
			Busyflag--;
		}
		else
		{
			i=1;
		}
	}
	if (USART_SERVICE_pu8TX[j][i])
	{
		USART_vSendDataNoBlock(USART_SERVICE_pu8TX[j][i]);
		i++;
	}
}


void USART_SERVICE_vSendStringAsynchronous(u8* copy_pu8Str)
{
	static u8 j=0;
	if (j<TXSize)
	{
	    USART_SERVICE_pu8TX[j]=copy_pu8Str;
		j++;
	    UART_TX_SetCallBack(&USART_SEVICE_vTX);
		if (READ_BIT(UCSRA,UDRE) && Busyflag==0 )
		{
		    USART_vSendDataNoBlock(copy_pu8Str[0]);
		}
		else
		{
			Busyflag++;
		}
	    USART_vTX_InterruptEnable();
	}
	else
	{
		//can't send more
	}

}


volatile String_t USART_SERVICE_RX_Buffer1[10];
volatile u8 USART_SERVICE_RXIndex=0;


static void USART_SEVICE_vRX(void)
{
	static u8 j=0;
	if (USART_SERVICE_RXIndex<10)
	{
		USART_vReceiveDataNoBlock((u8*)&USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[j]);
		j++;
		if (USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[j-1]=='#')
		{   
			USART_SERVICE_RX_Buffer1[USART_SERVICE_RXIndex].Str[j-1]=0;
			USART_SERVICE_RXIndex++;
			j=0;
		}
	}
}


void USART_SERVICE_vReciveStringAsynchronous(void)
{
	UART_RX_SetCallBack(&USART_SEVICE_vRX);
	USART_vRX_InterruptEnable();
}


