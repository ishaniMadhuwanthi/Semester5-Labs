/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

#define DELAY 500

int main(){

DDRB = DDRB | (1<<0);//OUTPUT PB0

DDRD = DDRD & ~(1<<2);//INPUT PD2 PUSH BUTTON

EICRA = EICRA & ~(1<<ISC00);//FALLING EDGEB SET
EICRA = EICRA | (1<<ISC01);

sei();//GLOBAL INTERRUPT ENABLE

EIMSK = EIMSK | (1<<INT0);//external interrupt set

while(1){

}
  return 0;
}

ISR(INT0_vect){
  PORTB ^= (1<<0);//toggling PB0

}
