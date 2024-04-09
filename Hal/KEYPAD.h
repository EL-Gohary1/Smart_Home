

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Utils.h"
#include "StdType.h"

/**********************************keypad_cfg.h******************/
#define  INPUT1     PIND7
#define  INPUT2     PIND6
#define  INPUT3     PIND5
#define  INPUT4     PIND3

#define  OUTPUT1    PINC5
#define  OUTPUT2    PINC4
#define  OUTPUT3    PINC3
#define  OUTPUT4    PINC2

#define  COL   4
#define  ROW   4

#define  KEY_DEFAULT   't'
/********************************keypad_Private.h************/
extern const u8 KeysArray[ROW][COL];
/********************************keypad_INTERFACE.h**************/

extern void KEYPAD_Init(void);
extern u8 KEYPAD_GetEntry(void);




#endif /* KEYPAD_H_ */