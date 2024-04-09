
/*
 * LCD_cfg.h
 *
 * Created: 3/2/2024 9:24:52 AM
 *  Author: lenovo
 */ 
/*
FOUR_BIT_MODE
EIGTH_BIT_MODE
*/

#ifndef LCD_CFG_H_
#define LCD_CFG_H_



#define LCD_MODE  FOUR_BIT_MODE
#define EN        PINA2
#define LCD_PORT  PD    //configuration 8 BIT MODE
#define RS        PINA3

//configuration for 4 bit mode
#define  D7 PINB4
#define  D6 PINB2
#define  D5 PINB1
#define  D4 PINB0

 /*
 CURSOR_BLINK
 CURSOR_NOBLINK
 NOCURSOR_NOBLINK
 NOCURSOR_BLINK
 */
#define CURSOR_BLINK_MODE     NOCURSOR_NOBLINK

#endif