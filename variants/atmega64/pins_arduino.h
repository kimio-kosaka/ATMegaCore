/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h
#include <avr/pgmspace.h>

#define NOT_A_PIN 0
#define NOT_A_PORT 0

#define NOT_ON_TIMER 0
#define TIMER0  1
#define TIMER0A 1
#define TIMER0B 2
#define TIMER1A 3
#define TIMER1B 4
#define TIMER2  5
#define TIMER2A 6
#define TIMER2B 7
#define TIMER3A 8
#define TIMER3B 9
#define TIMER3C 10

#define TIMER4A 11
#define TIMER4B 12
#define TIMER4C 13
#define TIMER5A 14
#define TIMER5B 15
#define TIMER5C 16

#define TCCR0A TCCR0
#define OCR0A OCR0
#define OCF0A OCF0
#define OCIE0A OCIE0
#define TIFR0 TIFR
#define TIMSK0 TIMSK

/*
                    PF PF PF PF PF PF PF PF       PA PA PA
                     0  1  2  3  4  5  6  7        0  3  2
                    D  D  D  D  D  D  D  D        D  D  D
           AV GD AR 52 51 50 49 48 47 46 45 GD VC 44 43 42
           64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 
PEN      1          A0 A1 A2 A3 A4 A5 A6 A7                48 D41 PA3
PE0  D0  2                                                 47 D40 PA4
PE1  D1  3                                                 46 D39 PA5
PE2  D2  4                                                 45 D38 PA6
PE3  D3  5                                                 44 D37 PA7
PE4  D4  6                                                 43 D36  PG2
PE5  D5  7                  ATmega64A                      42 D35 PC7
PE6  D6  8                                                 41 D34 PC6
PE7  D7  9                                                 40 D33 PC5
PB0  D8 10 /SS                                             39 D32 PC4
PB1  D9 11 SCK                                             38 D31 PC3
PB2 D10 12 MOSI                                            37 D30 PC2
PB3 D11 13 MISO                                            36 D29 PC1
PB4 D12 14                                                 35 D28 PC0
PB5 D13 15                                                 34 D27  PG1
PB6 D14 16                        SCL SDA                  33 D26  PG0
           17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
           D  D  D  RS VC GD X1 X2 D  D  D  D  D  D  D  D
           15 16 17                18 19 20 21 22 23 24 25
	       PB PG PG                PD PD PD PD PD PD PD PD
	        7  3  4                 0  1  2  3  4  5  6  7

PWM port
D3(PE3),D4(PE4),D5(PE5)
D13(PB5),D14(PB6),D15(PB7)

ICSP Programming
 RESET 20 
 SCK   11 PB1
 MOSI  2  PE0
 MISO  3  PE1
			
*/

//SPI
const static uint8_t SS   = 8;
const static uint8_t SCK  = 9;
const static uint8_t MOSI = 10;
const static uint8_t MISO = 11;

//I2C
static const uint8_t SDA = 19;
static const uint8_t SCL = 18;
//static const uint8_t LED_BUILTIN = 13;

//analog vs digital
static const uint8_t A0 = 52;  
static const uint8_t A1 = 51;
static const uint8_t A2 = 50;
static const uint8_t A3 = 49;
static const uint8_t A4 = 48;
static const uint8_t A5 = 47;
static const uint8_t A6 = 46;
static const uint8_t A7 = 45;  

#define NUM_DIGITAL_PINS            53 
#define NUM_ANALOG_INPUTS           8


#define analogInputToDigitalPin(p)  ((p < 8) ? 52-(p) : -1)  

#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 4 || (p) == 5 || (p) == 13  || (p) == 14 || (p) == 15 )

#ifndef PA
 #define PA 1
 #define PB 2
 #define PC 3
 #define PD 4
 #define PE 5
 #define PF 6
 #define PG 7
 #define PH 8
 #define PJ 10
 #define PK 11
 #define PL 12
#endif

#ifdef ARDUINO_MAIN
// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading

//__AVR_ATmega64__
const uint16_t PROGMEM port_to_mode_PGM[] = {
 NOT_A_PORT,
 (uint16_t) &DDRA,
 (uint16_t) &DDRB,
 (uint16_t) &DDRC,
 (uint16_t) &DDRD,
 (uint16_t) &DDRE,
 (uint16_t) &DDRF,
 (uint16_t) &DDRG,
// NOT_A_PORT,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
 NOT_A_PORT,
 (uint16_t) &PORTA,
 (uint16_t) &PORTB,
 (uint16_t) &PORTC,
 (uint16_t) &PORTD,
 (uint16_t) &PORTE,
 (uint16_t) &PORTF,
 (uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
 NOT_A_PIN,
 (uint16_t) &PINA,
 (uint16_t) &PINB,
 (uint16_t) &PINC,
 (uint16_t) &PIND,
 (uint16_t) &PINE,
 (uint16_t) &PINF,
 (uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
 // PORTLIST  
 //-------------------------------------------  

// ALE  ** Physical pin 1 ** 

PE, //PE0 D0
PE,
PE,
PE,
PE,
PE,
PE,
PE, //PE7 D7

PB, //PB0 D8
PB,
PB,
PB,
PB,
PB,
PB,
PB, //PB7 D15

PG, //PG3 D16
PG, //PG4 D17

PD, //PD0 D18
PD,
PD,
PD,
PD,
PD,
PD,
PD, //PD7 D25

PG, //PG0 D26
PG, //PG1 D27

PC, //PC0 D28
PC,
PC,
PC,
PC,
PC,
PC,
PC, //PC7 D35

PG, //PG2 D36

PA, //PA7 D37
PA,
PA,
PA,
PA,
PA,
PA,
PA, //PA0 D44

PF, //PF7 D45
PF,
PF,
PF,
PF,
PF,
PF,
PF, //PF0 D52


 
};
//_BOARD_AMBER128_
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
 // PIN IN PORT  
 // -------------------------------------------  
 _BV( 0 ) , // PE D0
 _BV( 1 ) , // PE 
 _BV( 2 ) , // PE 
 _BV( 3 ) , // PE 
 _BV( 4 ) , // PE 
 _BV( 5 ) , // PE 
 _BV( 6 ) , // PE 
 _BV( 7 ) , // PE

 _BV( 0 ) , // PB 
 _BV( 1 ) , // PB 
 _BV( 2 ) , // PB 
 _BV( 3 ) , // PB 
 _BV( 4 ) , // PB 
 _BV( 5 ) , // PB 
 _BV( 6 ) , // PB 
 _BV( 7 ) , // PB

 _BV( 3 ) , // PG
 _BV( 4 ) , // PG
 
 _BV( 0 ) , // PD 
 _BV( 1 ) , // PD 
 _BV( 2 ) , // PD 
 _BV( 3 ) , // PD 
 _BV( 4 ) , // PD 
 _BV( 5 ) , // PD 
 _BV( 6 ) , // PD
 _BV( 7 ) , // PD
 
 _BV( 0 ) , // PG
 _BV( 1 ) , // PG
 
 _BV( 0 ) , // PC 
 _BV( 1 ) , // PC 
 _BV( 2 ) , // PC 
 _BV( 3 ) , // PC 
 _BV( 4 ) , // PC 
 _BV( 5 ) , // PC 
 _BV( 6 ) , // PC 
 _BV( 7 ) , // PC

 _BV( 2 ) , // PG

 _BV( 7 ) , // PA 
 _BV( 6 ) , // PA 
 _BV( 5 ) , // PA 
 _BV( 4 ) , // PA 
 _BV( 3 ) , // PA 
 _BV( 2 ) , // PA 
 _BV( 1 ) , // PA 
 _BV( 0 ) , // PA

 _BV( 7 ) , // PF 
 _BV( 6 ) , // PF 
 _BV( 5 ) , // PF 
 _BV( 4 ) , // PF 
 _BV( 3 ) , // PF 
 _BV( 2 ) , // PF 
 _BV( 1 ) , // PF 
 _BV( 0 ) , // PF 
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
 // TIMERS  
 // -------------------------------------------  
        NOT_ON_TIMER,   /* 0  - PE0 */
        NOT_ON_TIMER,   /* 1  - PE1 */
        NOT_ON_TIMER,   /* 2  - PE2 */
        TIMER3A,        /* 3  - PE3 */
        TIMER3B,        /* 4  - PE4 */
        TIMER3C,		/* 5  - PE5 */
        NOT_ON_TIMER,   /* 6  - PE6 */
        NOT_ON_TIMER,   /* 7  - PE7 */

		NOT_ON_TIMER,   /* 8  - PB0 */
        NOT_ON_TIMER,   /* 9  - PB1 */
        NOT_ON_TIMER,   /* 10 - PB2 */
        NOT_ON_TIMER,   /* 11 - PB3 */
        NOT_ON_TIMER,   /* 12 - PB4 */
        TIMER1A,        /* 13 - PB5 */
        TIMER1B,        /* 14 - PB6 */
        TIMER2,         /* 15 - PB7 */

		NOT_ON_TIMER,   /* 16 - PG3 */ 
        NOT_ON_TIMER,   /* 17 - PG4 */ 

		NOT_ON_TIMER,   /* 18 - PD0 */ 
        NOT_ON_TIMER,   /* 19 - PD1 */ 
        NOT_ON_TIMER,   /* 20 - PD2 */ 
        NOT_ON_TIMER,   /* 21 - PD3 */ 
        NOT_ON_TIMER,   /* 22 - PD4 */ 
        NOT_ON_TIMER,   /* 23 - PD5 */ 
        NOT_ON_TIMER,   /* 24 - PD6 */ 
        NOT_ON_TIMER,   /* 25 - PD7 */ 
		
        NOT_ON_TIMER,   /* 26 - PG0 */ 
        NOT_ON_TIMER,   /* 27 - PG1 */ 
		
        NOT_ON_TIMER,   /* 28 - PC0 */ 
        NOT_ON_TIMER,   /* 29 - PC1 */ 
        NOT_ON_TIMER,   /* 30 - PC2 */ 
        NOT_ON_TIMER,   /* 31 - PC3 */ 
        NOT_ON_TIMER,   /* 32 - PC4 */ 
        NOT_ON_TIMER,   /* 33 - PC5 */ 
        NOT_ON_TIMER,   /* 34 - PC6 */ 
        NOT_ON_TIMER,   /* 35 - PC7 */ 
		
        NOT_ON_TIMER,   /* 36 - PG2 */ 
		
        NOT_ON_TIMER,   /* 37 - PA7 */ 
        NOT_ON_TIMER,   /* 39 - PA6 */ 
        NOT_ON_TIMER,   /* 39 - PA5 */ 
        NOT_ON_TIMER,   /* 40 - PA4*/ 
        NOT_ON_TIMER,   /* 41 - PA3 */ 
        NOT_ON_TIMER,   /* 42 - PA1 */ 
        NOT_ON_TIMER,   /* 43 - PA1 */
        NOT_ON_TIMER,   /* 44 - PA0 */ 
		
        NOT_ON_TIMER,   /* 45 - PF7 */ 
        NOT_ON_TIMER,   /* 46 - PF6 */ 
        NOT_ON_TIMER,   /* 47 - PF5*/ 
        NOT_ON_TIMER,   /* 48 - PF4 */ 
        NOT_ON_TIMER,   /* 49 - PF3 */ 
        NOT_ON_TIMER,   /* 50 - PF2 */ 
        NOT_ON_TIMER,   /* 51 - PF1 */
        NOT_ON_TIMER,   /* 52 - PF0 */ 
};
#endif
#endif
