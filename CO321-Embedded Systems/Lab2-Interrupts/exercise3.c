/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#define DELAY 500
int count=0;

int main(){

int i;

for(i=0;i<6;i++){
  DDRB = DDRB |(1<<i); //output PB0,1,2,3,4,5
}

  DDRD = DDRD & ~(1<<2);//input PD2

  EICRA = EICRA & ~(1<<ISC00);//FALLING/RISING EDGEB
  EICRA = EICRA | (1<<ISC01);

  sei();//global interrupt enable

  EIMSK = EIMSK | (1<<INT0);//external interrupt enable

  while(1){

  }

  return 0;
}

ISR(INT0_vect){
    count++;
  PORTB = count;
  if(count >127){
    count =0;
  }
}
