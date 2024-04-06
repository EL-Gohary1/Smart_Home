
/*
 * LCD_interface.h
 *
 * Created: 3/2/2024 9:24:02 AM
 *  Author: lenovo
 */ 

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define  F_CPU 16000000
#include "util\delay.h"



#define FOUR_BIT_MODE   1
#define EIGTH_BIT_MODE  0


#define CURSOR_BLINK        0
#define CURSOR_NOBLINK      1
#define NOCURSOR_NOBLINK    2
#define NOCURSOR_BLINK      3

void LCD_vInit(void);

void LCD_vWriteChar(u8 data);

void LCD_vSendCommand(u8 inst);

void LCD_vClear(void);

void LCD_vWriteString(u8* str);

void LCD_vGoToCollRow(u8 Copy_u8Coll , u8 Copy_u8Row);

void LCD_vSetCGRAM(u8 index );

void LCD_vWriteInteger(u8 num);

void LCD_vSetDDRAM(void);


void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum );

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ) ;





#endif
