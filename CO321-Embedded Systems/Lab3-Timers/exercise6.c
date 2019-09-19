/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/


#include<avr/io.h>
#include<avr/interrupt.h>

int count =0;

//blink by 100MS
void delay_timer0(){

  TCNT0=230;//TIMER0_INITAIL VALUE
  TCCR0A = 0X00;//NORMAL MODE
  TCCR0B = 5;//pre scaler

  while((TIFR0 && 1) ==0);

  TCCR0A =0X00;//NORMAL MODE
  TCCR0B=0;//stop clock source
  TIFR0 =0X01;//clear overflow bit

}
int main(){
   DDRB = DDRB | (1<<4);//output pb4

sei();//global interpit enable
TIMSK0 = 0X01;//ENABLE timer0 overflow interrupt

TCCR0A=0X00;//normal mode
TCCR0B=5;//pre scaler
TCNT0=0;//initial value

   while(1){

   }
}

//timer0 overflow interrupt for bulb
ISR(TIMER0_OVF_vect){
  count++;
  if(count == 6){
    delay_timer0();
    PORTB = PORTB ^ (1<<4);

    count=0;
    TCNT0=230;
   TCCR0A=0;
		TCCR0B=5;

  }
}
