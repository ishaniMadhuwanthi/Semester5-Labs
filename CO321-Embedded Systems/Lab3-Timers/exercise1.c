/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/


#include<avr/io.h>

void delay_timer0(){

TCNT0=116;//initial value
TCCR0A = 0x00;//normal mode
TCCR0B = 2;//pre scaler

  while((TIFR0 && 1)==0);//set overflow bit

//clear overflow settings
  TCCR0A = 0x00;//normal mode
  TCCR0B =0;//stop clock source
  TIFR0 =0x01;//clear overflow bit
}

int main(void){

DDRB = DDRB | (1<<5);//output pb4

while (1) {
  PORTB = PORTB ^ (1<<5);//toggle pb4
  delay_timer0();
}

}
