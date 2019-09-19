#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

#define DELAY 1000

int main (){

  DDRB = DDRB | (1<<4);//OUTPUT PB4

  DDRD = DDRD & ~(1<<2);//INPUT PD2

  //INT0-on at rising edge
  EICRA = EICRA | (1<<ISC00);
  EICRA = EICRA | (1<<ISC01);

  //global interrupt enable
  sei();

  //external interupt enable
  EIMSK = EIMSK | (1<<INT0);

  while(1){

  }
  return 0;
}

  ISR(INT0_vect){
    PORTB = PORTB & ~(1<<4);//off at start
    _delay_ms(DELAY);

    PORTB = PORTB | (1<<4);//on


  }
