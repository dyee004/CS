/*	Author: dyee004
 *  Partner(s) Name: Azat Melkonyan
 *	Lab Section:
 *	Assignment: Lab #2  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
  DDRA = 0x00; PORTA = 0xFF;
  DDRB = 0xFF; PORTB = 0x00;
  unsigned char cntavail = 0;
  unsigned char tmpA = 0;
  unsigned char freeSpace = 0;
  unsigned char tmpB = 0;
    /* Insert your solution below */
    while (1) {
     cntavail = 0;
     tmpA = PINA & 0x01;
     if(tmpA == 0x01){
	cntavail = cntavail + 1;
      }
      tmpA = PINA &  0x02;
      if(tmpA == 0x02){
	cntavail = cntavail + 1;
      }
      tmpA = PINA & 0x04;
      if(tmpA == 0x04){
	cntavail = cntavail + 1;
      }
      tmpA = PINA & 0x08;
      if(tmpA == 0x08){
	cntavail = cntavail + 1;
      }
      freeSpace = 4 - cntavail;
      tmpB = freeSpace & 0x0F;
      	if(cntavail == 0){
      		tmpB = tmpB | 0x80;
      	}
	PORTB = tmpB;
    }
    return 1;
}
