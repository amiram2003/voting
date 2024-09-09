/*
 * DIO11.h
 *
 * Created: 19/04/2024 05:42:31 م
 *  Author: Amira Al-wakeel
 */ 


#ifndef DIO11_H_
#define DIO11_H_


void DIO_setpindir(unsigned char p ,unsigned char pin ,unsigned char dir);
void DIO_pinwrite(char p , char pin , char val);
void DIO_pintoggile(unsigned char p ,unsigned char pin);
char DIO_pinread(unsigned char p ,unsigned char pin);
void DIO_setportdir(char p , char dir);
void DIO_portwrite(unsigned char p ,unsigned char val);
char DIO_portread(unsigned char p);
void DIO_porttoggle(unsigned char p);
void DIO_connectpullup(unsigned char port ,unsigned char pin ,unsigned char connect_pullup);
void DIO_write_low_nibble(unsigned char port , unsigned char val);
void DIO_write_high_nibble(unsigned char port , unsigned char val);


#endif /* DIO11_H_ */