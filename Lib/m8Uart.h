#ifndef __M8_UART_H_
#define __M8_UART_H_

#define STEP_RCV_HDR_HIGH 	0	
#define STEP_RCV_HDR_LOW 	1
#define STEP_RCV_DATA  		2

#define HEADER_HIGH   		0xaa
#define HEADER_LOW   		0x55
#define UART_BUFFER_SIZE 		64
#define uartTxOn				__vector_13
#define initUart(baud)			initUartBase((unsigned int)(F_CPU/baud/8-1))

void __vector_13(void);
void initUartBase(unsigned char baudrate);
int getChar(void);
void uartOut(char* pStr, unsigned short size);
void sendString(char* pStr);
void uprintf(char* fmt,...);

#endif
