/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/


#include<avr/io.h>
#include<util/delay.h>

#define DELAY 100

int main (void){

int i,j;

  for(i=1;i<5;i++){
    DDRB = DDRB | (1<<i);//OUTPUT
  }

  while(1){
    for(j=1;j<5;j++){
      PORTB = PORTB | (1<<j);//on all bulbs ABCD
      _delay_ms(DELAY);

      PORTB = PORTB & ~(1<<j);//off
      _delay_ms(DELAY);
    }
    for(j=3;j>1;j--){
      PORTB = PORTB | (1<<j);//on BC
      _delay_ms(DELAY);

      PORTB = PORTB & ~(1<<j);//off
      _delay_ms(DELAY);
    }
  }
}
