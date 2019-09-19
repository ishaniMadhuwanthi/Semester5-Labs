/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/


#include<avr/io.h>

void delay_timer1(){

  TCNT1=3036;//initial value
  TCCR1A=0x00;//NORMAL MODE
  TCCR1B=4;//PRESCALER

while((TIFR1 && 1)==0);

TCCR1A=0x00;//NORMAL MODE
TCCR1B=0;//stops the clock

TIFR1=0X01;//clear flag bit
}

int main(){

int i,j;

  DDRD = DDRD | (1<<6);

  TCNT0=0;//INITIAL
  TCCR0A=131;//FAST PWM MODE
  TCCR0B=3;//64

  while(1){
    for(i=0;i< 256;i = i + 5){//fade high
      OCR0A=i;
      delay_timer1();
    }
    for(j=255;j>=0;j = j - 5){//fade low
      OCR0A=j;
      delay_timer1();
    }
  }
  return 0;
}
