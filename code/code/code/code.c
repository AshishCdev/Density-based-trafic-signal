/*
 * density_based_trafic_signal.c
 *
 * Created: 3/9/2014 5:26:46 PM
 *  Author: DNTS
 */ 


#include <avr/io.h>
#include <util/delay.h>

void counter1(void);
void counter2(void);
void green1(void);
void green2(void);
void green3(void);
void green4(void);
void density(void);
void simple(void);
int main(void)
 {
	DDRC=0xff;
	DDRA=0x00;
	DDRB=0xff;
	DDRD=0xff;
	while (1)
	{
//	if ((((PINA&0b00000011)==0b000000011)&&((PINA&0b00001100)==0b00001100)&&((PINA&0b00110000)==0b000000)&&((PINA&0b11000000)==0b00000000)))
//	simple();
	if ((((PINA&0b00000011)==0b00000011)||((PINA&0b00001100)==0b00001100)||((PINA&0b00110000)==0b00110000)||((PINA&0b11000000)==0b11000000)))
    density();
	else simple();
	}
 } 	
void simple(void)
 {
   PORTD=0b00000010;PORTB=0b01001001;
   green1();
   counter1();
   if ((((PINA&0b00000011)==0b00000011)||((PINA&0b00001100)==0b00001100)||((PINA&0b00110000)==0b00110000)||((PINA&0b11000000)==0b11000000)))
   density();
   green2();
   counter1();
   if ((((PINA&0b00000011)==0b00000011)||((PINA&0b00001100)==0b00001100)||((PINA&0b00110000)==0b00110000)||((PINA&0b11000000)==0b11000000)))
   density();
   green3();
   counter1();
   if ((((PINA&0b00000011)==0b00000011)||((PINA&0b00001100)==0b00001100)||((PINA&0b00110000)==0b00110000)||((PINA&0b11000000)==0b11000000)))
   density();
   green4();
   counter1();
   if ((((PINA&0b00000011)==0b00000011)||((PINA&0b00001100)==0b00001100)||((PINA&0b00110000)==0b00110000)||((PINA&0b11000000)==0b11000000)))
   density();	 
 }
void density(void)
{
  
   
  PORTD=0b00000010;PORTB=0b01001001;
  PORTC=0b11111110;
 
   if ((PINA&0b00000011)==0b00000011)
     {
         green1();
	     counter1();
	     PORTD=0b00000010;PORTB=0b01001001;
	 }
	 if ((PINA&0b00001100)==0b00001100)
	 {
		 green2();
		 counter1();
		 PORTD=0b00000010;PORTB=0b01001001;
	 }
	 if ((PINA&0b00110000)==0b00110000)
	 {
		 green3();
		 counter1();
		 PORTD=0b00000010;PORTB=0b01001001;
	 }
	 if ((PINA&0b11000000)==0b11000000)
	 {
		 green4();
		 counter1();
		 PORTD=0b00000010;PORTB=0b01001001;
	 }
   	 
 
}
void counter1(void)
{
	PORTC=0b00001000;
	_delay_ms(1000);
	PORTC=0b00000000;
	_delay_ms(1000);
	PORTC=0b00111100;
	_delay_ms(1000);
	PORTC=0b10000000;
	_delay_ms(1000);
	PORTC=0b10001000;
	_delay_ms(1000);
	PORTC=0b01001100;
	_delay_ms(1000);
	PORTC=0b00101000;
	_delay_ms(1000);
	PORTC=0b00100010;
	_delay_ms(1000);
	PORTC=0b01111100;
	_delay_ms(1000);
	PORTC=0b00010000;
	_delay_ms(1000);
	
	
}
void counter2(void)
  {
	PORTC=0b01001100;
	_delay_ms(1000);
	PORTC=0b00101000;
	_delay_ms(1000);
	PORTC=0b00100010;
	_delay_ms(1000);
	PORTC=0b01111100;
	_delay_ms(1000);
	PORTC=0b00010000;
	
  }
void green1(void)
{
    PORTD=0b00000010;PORTB=0b10001001;
    counter2();
    PORTD=0b00000011;PORTB=0b00001001;	
}
void green2(void)
{
	PORTD=0b00000100;PORTB=0b01001001;
	counter2();
	PORTD=0b00001000;PORTB=0b01001001;
}  
void green3(void)
{
	PORTD=0b00000010;PORTB=0b01001010;
	counter2();
	PORTD=0b00000010;PORTB=0b01001100;
}
void green4(void)
{
	PORTD=0b00000010;PORTB=0b01010001;
	counter2();
	PORTD=0b00000010;PORTB=0b01100001;
}