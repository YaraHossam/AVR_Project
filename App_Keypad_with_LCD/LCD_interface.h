/*
 * LCD_interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: Yara
 */
// da fih kol 2l #define el bagbha mn el datasheet


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "DIO_interface.h"
#include "../_standard/datatypes.h"

#define LCD_RSPin 0
#define LCD_RWPin 1
#define LCD_EnablePin 2

extern void LCD_vWriteCommand(u8 copy_u8command);
extern void LCD_vWriteChar(u8 copy_u8Char);
extern void LCD_vInitialize(void);
extern void gotoXY(u8 X,u8 Y);


#endif /* LCD_INTERFACE_H_ */
