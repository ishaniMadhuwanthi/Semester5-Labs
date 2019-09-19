/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/


#include<avr/io.h>
#include<util/delay.h>

#define DELAY 100

int main (void){

int i,j,k;

  for(i=1;i<5;i++){
    DDRB = DDRB |(1<<i);//OUTPUT
  }

  while (1) {
    for(j=1;j<5;j++){
    PORTB = PORTB | (1<<j);//on
  }
  _delay_ms(DELAY);

    for(k=1;k<5;k++){
    PORTB = PORTB & ~(1<<k);//OFF
  }
  _delay_ms(DELAY);

  }
}
