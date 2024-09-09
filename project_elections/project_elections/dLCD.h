/*
 * dLCD.h
 *
 * Created: 19/07/2024 01:34:16 م
 *  Author: Amira Al-wakeel
 */ 


#ifndef DLCD_H_
#define DLCD_H_

#include "DIO11.h"
#include "config.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0c
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined four_bit_mode
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0x28
#elif defined eight_bitmode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif
void lcd_init(void);
static void enable(void);
void lcd_send_cmd(unsigned char com);
void lcd_senddata(unsigned char data);
void lcd_send_string(const char *ptr);
void lcd_clearscreen(void);
void lcd_movecursor(char row,char col);

#endif /* DLCD_H_ */