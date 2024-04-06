/*
 * USART_SERVICE.h
 *
 * Created: 3/22/2024 4:51:20 PM
 *  Author: lenovo
 */ 


#ifndef USART_SERVICE_H_
#define USART_SERVICE_H_

typedef struct
{
	u8 Str[10];
}String_t;


#define TXSize   10



void USART_SERVICE_vSendStringAsynchronous(u8* copy_pu8Str);

void USART_SERVICE_vReciveStringAsynchronous(void);



#endif /* USART_SERVICE_H_ */