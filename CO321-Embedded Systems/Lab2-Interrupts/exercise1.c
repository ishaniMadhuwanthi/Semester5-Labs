/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include<stdio.h>

#define DELAY 1000

int main(){

  int count =0;
  int i;

for(i=0;i<6;i++){
  DDRB = DDRB | (1<<i);//output led6 PB0,1,2,3,4,5
}
  DDRD = DDRD & ~(1<<2);//input PD2 switch

PORTB = 0;
while(1){

  if((PIND>>2) & 1){
    PORTB +=1;
    _delay_ms(DELAY);
    count++;
  }
 if(count >127){
   count =0;
 }

}
return 0;
}
