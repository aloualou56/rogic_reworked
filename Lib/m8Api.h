/*======================Copyright (c) 2010, Roborobo===========================
Project Name : ATmega8X API
File Name : m8Api.h
Desc : ATmega8X Application Programing Interface
==============================================================================*/
#ifndef __M8_API_H_
#define __M8_API_H_
/*
// ================ UART START ======================

void initUart(unsigned char baudrate);
int getChar(void);
void sendString(char* str);
void uprintf(char *fmt,...);
void sendStream(char* stream, unsigned char size);
void setRcvIsr(void (*pFunc)(void));
*/

// ================ EEPROM START ====================

void setEepromChar(unsigned int addr, char data);
void setEepromInt(unsigned int addr, int data);
void setEepromLong(unsigned int addr, long data);
void setEepromFloat(unsigned int addr, float data);

char getEepromChar(unsigned int addr);
int getEepromInt(unsigned int addr);
long getEepromLong(unsigned int addr);
float getEepromFloat(unsigned int addr);


// ================ TIMER START ====================

#define NO_CLOCK	0
#define DIV0		1
#define DIV2		2
#define DIV4		3
#define DIV8		4
#define DIV16		5
#define DIV32		6
#define DIV64		7
#define DIV128		8
#define DIV256		9
#define DIV512		10
#define DIV1024		11
#define T0_FALLING	12
#define T0_RISING	13
#define T1_FALLING	12
#define T1_RISING	13

#define OCR1A_EN	0x10
#define OCR1B_EN	0x08


// ================ TIMER0 START ====================

// Valid parameter of clock is : NO_CLOCK, DIV0, 8, 64, 256, 1024, T0_FALLING, T0_RISING
void initNormalTimer0(unsigned char clock);
void setTimer0(unsigned char on);


// ================ TIMER1 START ====================

// Valid parameter of clock is : NO_CLOCK, DIV0, 8, 64, 256, 1024, T1_FALLING, T1_RISING
// Valid parameter of flag is : OCR1A_EN, OCR1B_EN
// The parameter of flag allows 'or' operation between OCR1A_EN and OCR1B_EN.

void initNormalTimer1(unsigned char clock);
void setTimer1(unsigned char on);

void initCtcTimer1(unsigned char clock, unsigned int ocra, unsigned int ocrb, unsigned char flag);


// ================ TIMER2 START ====================

// Valid parameter of clock is : NO_CLOCK, DIV0, 8, 32, 64, 128, 256, 1024

void initNormalTimer2(unsigned char clock);
void setTimer2(unsigned char on);

void initCtcTimer2(unsigned char clock, unsigned int ocr);

#endif


