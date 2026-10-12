#ifndef _SCHOOL_KITS_H_
#define _SCHOOL_KITS_H_

extern volatile unsigned char conData[5];

//About Input=============================
void initInput(void);
unsigned char getIn(unsigned port);
unsigned char getIn1(void);
unsigned char getIn2(void);
unsigned char getIn3(void);
unsigned char getIn4(void);
unsigned char getIn5(void);
unsigned char getIn6(void);
unsigned char getIn7(void);

//About Output=============================
void initOutput(void);
void clearOut(void);
char getOutFlag(void);
void setOut(unsigned char port, unsigned char val);
void setMotor(unsigned char port, unsigned char val);
void setOut1(unsigned char pwm);
void setOut2(unsigned char pwm);
void setOut3(unsigned char pwm);
void setOut4(unsigned char pwm);
void setOut5(unsigned char pwm);
void setOut6(unsigned char pwm);
void setOut7(unsigned char pwm);
void setOut8(unsigned char pwm);
void setOut9(unsigned char pwm);

//About Remocon=============================
void initRemocon(void);
unsigned char getRemocon(void);
void setRemoconPort(unsigned char val);

//About Delay=============================
void initDelay(void);
void delayMs(volatile unsigned char time);
void sleep(volatile unsigned char time);
void resetTime(void);
unsigned char getTime(void);

//About Module=============================
void doDcMotor(unsigned char dcMotor);
void doServoMotor(unsigned char outpin, unsigned char duty);
void doPortOn(unsigned char port);
void doPortOff(unsigned char port);

//About Rogic(User Reference Function)=============================
#define OUT1			1
#define OUT2			2
#define OUT3			3
#define OUT4			4
#define OUT5			5

#define in1				!getIn(0)
#define in2				!getIn(1)
#define in3				!getIn(2)
#define in4				!getIn(3)
#define in5				!getIn(4)
#define in6				!getIn(5)
#define in7				!getIn(6)

#define IN1				!getIn(0)
#define IN2				!getIn(1)
#define IN3				!getIn(2)
#define IN4				!getIn(3)
#define IN5				!getIn(4)
#define IN6				!getIn(5)
#define IN7				!getIn(6)

#define DIR_CW			1
#define DIR_CCW			0

#define PS2_SELECT 	(conData[0]&0x01)
#define PS2_L_SW	(conData[0]&0x02)
#define PS2_R_SW	(conData[0]&0x04)
#define PS2_START  	(conData[0]&0x08)

#define PS2_L_FF  	(conData[0]&0x10)
#define PS2_L_RR  	(conData[0]&0x20)
#define PS2_L_BB  	(conData[0]&0x40)
#define PS2_L_LL  	(conData[0]&0x80)

#define PS2_R_FF  	(conData[1]&0x10)
#define PS2_R_RR  	(conData[1]&0x20)
#define PS2_R_BB  	(conData[1]&0x40)
#define PS2_R_LL  	(conData[1]&0x80)

#define PS2_L_2  	(conData[1]&0x01)
#define PS2_R_2  	(conData[1]&0x02)
#define PS2_L_1  	(conData[1]&0x04)
#define PS2_R_1  	(conData[1]&0x08)

#define remocon1 		(getRemocon()&0x01)
#define remocon2 		(getRemocon()&0x02)
#define remocon3 		(getRemocon()&0x04)
#define remocon4 		(getRemocon()&0x08)
#define remocon5 		(getRemocon()&0x10)
#define remocon6 		(getRemocon()&0x20)
#define remocon7 		(getRemocon()&0x40)
#define remocon8 		(getRemocon()&0x80)

#define REMOCON1 		(getRemocon()&0x01)
#define REMOCON2 		(getRemocon()&0x02)
#define REMOCON3 		(getRemocon()&0x04)
#define REMOCON4 		(getRemocon()&0x08)
#define REMOCON5 		(getRemocon()&0x10)
#define REMOCON6 		(getRemocon()&0x20)
#define REMOCON7 		(getRemocon()&0x40)
#define REMOCON8 		(getRemocon()&0x80)


#define REMOCON			(getRemocon()&0x1F)
#define BTN1			0x01
#define BTN2			0x02
#define BTN3			0x04
#define BTN4			0x08
#define BTN5			0x10

#define START			start
#define END				end
#define ON				on
#define OFF				off
#define DELAY			delay

#define FFSPEED			ffspeed
#define BBSPEED			bbspeed

#define MOTORSPEED		motorspeed

#define MOTOR1			motor1
#define MOTOR2			motor2
#define MOTOR3			motor3
#define MOTOR4			motor4

#define SERVO1			servo1
#define SERVO2			servo2
#define SERVO3			servo3
#define SERVO4			servo4
#define SERVO5			servo5

#define BRAKE			0
#define brake			0
#define STOP			1
#define stop			1

#define timerstart		startCounter
#define timerend		endCounter
#define timecounter		timeCounter
#define ledonoff		ledOnOff

void start(void);
void end(void);
void on(unsigned char portOut);
void off(unsigned char portOut);
void delay(volatile unsigned int msTime);

void ffspeed(unsigned char lSpd, unsigned char rSpd);
void bbspeed(unsigned char lSpd, unsigned char rSpd);
void motorspeed(unsigned char mode);

void motor(char mtPort, char mtDir, char mtSpd);
void motor1(signed char mtSpd);
void motor2(signed char mtSpd);
void motor3(signed char mtSpd);
void motor4(signed char mtSpd);

void wheel12(signed char mt1Spd, signed char mt2Spd);
void wheel34(signed char mt3Spd, signed char mt4Spd);

void servo1(unsigned char servoPos);
void servo2(unsigned char servoPos);
void servo3(unsigned char servoPos);
void servo4(unsigned char servoPos);
void servo5(unsigned char servoPos);

void voice(unsigned char portOut);

void setUserTimer(unsigned int time);
unsigned int getUserTimer(void);

void setSegment(unsigned char dspNum);

void setMsecTimer(unsigned int time);
void setSecTimer(unsigned int time);
unsigned int getSecTimer(void);
void startCounter(void);
void endCounter(void);
unsigned char timeCounter(unsigned int time);
void ledOnOff(unsigned char port, unsigned char time);

#endif
