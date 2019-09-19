/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

int main(){

 int i;

for(i=0;i<6;i++){
  DDRB =DDRB | (1<<i);//output
}

//button A
  DDRD = DDRD & ~(1<<2);//input PD2
  EICRA = EICRA | (1<<ISC00) ;//& (1<<ISC01));//INT0 RISING EDGE
  EICRA = EICRA | (1<<ISC01);
  sei();//GLOBAL INTERRUPT ENABLE
  EIMSK = EIMSK | (1<<INT0) ;

//button B
  DDRD = DDRD & ~(1<<3);//INPUT PD3
  EICRA = EICRA | (1<<ISC10) ;//& (1<<ISC01));//INT0 RISING EDGE
  EICRA = EICRA | (1<<ISC11);
  sei();//GLOBAL INTERRUPT ENABLE
  EIMSK = EIMSK | (1<<INT1);//EXTERNAL INTERRUPT  ENABLE

  while(1){

 }

 return 0;
}

ISR(INT0_vect){
PORTB = PORTB<<1;//FOR A "0"-ONLY SHIFT ONE BIT
_delay_ms(1000);
}

ISR(INT1_vect){
  PORTB = PORTB<<1;//FOR B "1"-SHOFT ONE BIT
  PORTB = PORTB | (1<<0);//THEN ON 0TH BIT
_delay_ms(1000);
}
