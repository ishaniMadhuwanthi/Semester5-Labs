/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/


#include<avr/io.h>
#include<avr/interrupt.h>

int count0=0;
int count1=0;

//blink by 50MS
void delay_timer0(){

  TCNT0 =242;//TIMER0_INITAIL VALUE
  TCCR0A=0X00;//NORMAL MODE
  TCCR0B=5;//pre scaler

  while((TIFR0 && 1)==0);//check overflow set

//clear timer setting
  TCCR0A = 0X00;//NORMAL mode
  TCCR0B=0;//stop clock source
  TIFR0=0X01;//clear overflow bit
}

//blink by 500MS
void delay_timer1(){

TCNT1=3036;//TIMER1_INITAIL VALUE
TCCR1A=0X00;//NORMAL MODE
TCCR1B=2;//pre scaler

while((TIFR1 && 1)==0);//check overflow set

//clear timer setting
TCCR1A=0X00;//NORMl mode
TCCR1B=0;//stop clock source
TIFR1=0X01;//clear overflow bit
}

int main(){

DDRB = DDRB | (1<<4);//output pb4
DDRB = DDRB | (1<<3);//output pb3

//FIRST BULB-50MS
TCNT0=0;//initial value
TCCR0A=0X00;//normal mode
TCCR0B=5;//pre scaler
sei();//global interpit enable
TIMSK0=0X01;//ENABLE timer0 overflow interrupt

//SECOND BULB-500MS
TCNT1=0;//initial value
TCCR1A=0X00;//normal mode
TCCR1B=2;//pre scaler
sei();//global interpit enable
TIMSK1=0X01;//ENABLE timer1 overflow interrupt

while(1){

}

  return 0;
}

//timer0 overflow interrupt for bulb1
ISR(TIMER0_OVF_vect){
  count0++;
  if(count0 ==3){
  delay_timer0();
  PORTB = PORTB ^ (1<<4);
  count0=0;
  TCNT0=242;
  TCCR0A=0X00;
  TCCR0B=0;

 }
}

//timer1 overflow interrupt for bulb2
ISR(TIMER1_OVF_vect){
  count1++;
    delay_timer1();
  PORTB = PORTB ^ (1<<3);
  count1=0;
  TCCR1A=0X00;
  TCCR1B=2;

}
