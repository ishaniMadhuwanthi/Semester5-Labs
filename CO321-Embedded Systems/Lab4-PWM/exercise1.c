/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/


#include<avr/io.h>

int main(){

 DDRD = DDRD | (1<<6);//OUTPUT PWM PB1

 TCNT0 =0;//initial value
 OCR0A=127;
 TCCR0A=131;//fast pwm
 TCCR0B=3;//64

while (1) {

}

  return 0;
}
