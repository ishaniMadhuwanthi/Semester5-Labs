/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/


#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<stdio.h>

void delay_timer0(){

TCNT0 = 131;//TIMER0_INITAIL VALUE
TCCR0A = 0X00;//NORMAL MODE
TCCR0B = 4;//pre scaler

while((TIFR0 && 1) == 0);

TCCR0A =0X00;//NORMAL MODE
TCCR0B =0;//stop clock source
TIFR0 = 0X01;//clear overflow bit

}

int main(void){

int i,j,k;
DDRB = 0b11111111;//output PortB
// for(i=0;i<5;i++){
//   DDRB = DDRB | (1<<i);
// }

//timer1 for toggling one LED
sei();//global interpit enable
TIMSK1 = 0X01; //ENABLE timer1 overflow interrupt
TCNT1=3036;//initial
TCCR1A = 0X00;//normal mode
TCCR1B = 4;//pre scaler

//knight Rider circuit
  while(1){
      for(j=0;j<4;j++){
        PORTB = PORTB ^(1<<j);
       for(i=0;i<250;i++){
        delay_timer0();
       }
      }
      for(k=2;k>0;k--){
        PORTB = PORTB | (1<<k);
        for(i=0;i<250;i++){
              delay_timer0();
            }
      }
  }
  return 0;
}

//timer1 overflow interrupt for bulb
ISR(TIMER1_OVF_vect){
  PORTB = PORTB ^ (1<<4);
  TCNT1 = 3036;
}
