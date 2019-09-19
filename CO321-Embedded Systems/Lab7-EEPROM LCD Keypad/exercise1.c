/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/

#include<avr/eeprom.h>
#include<stdio.h>

void EEPROMWrite(unsigned int address ,char data){

	//wait for completion of previous write
	
	while(EECR &(1<<EEPE));
	
	//set up address and data regs
	EEAR = address;
	EEDR = data;
	
	//write logical 1 to EEMPE
	EECR |= (1<<EEMPE);
	
	//start eeprom write
	EECR |= (1<<EEPE);
	
}

char EEPROMread(unsigned int address){

	//wait for completion of previous write
	
	while(EECR &(1<<EEPE));
	
	//set up address and data regs
	EEAR = address;
	
	//start eeprom read
	EECR |=(1<<EERE);
	
	//return data
	return EEDR;


}

void usart_Init()
{
    /*Set baud rate */
    UBRR0 = 103;

    /*Enable receiver and transmitter */
    UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 1stop bit and no parity */
    UCSR0C &= ~(1<<USBS0) ; //1 stop bit
    UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01); // 8 bit
    UCSR0C &= ~(1<<UPM01); //no parity
    UCSR0C &= ~(1<<UPM00); //no parity

}

void usart_send( unsigned char data )
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) );
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

unsigned char usart_receive( void )
{
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) );
    /* Get and return received data from buffer */
    return UDR0;
}

int main(){
 
  usart_Init();
 EEPROMWrite(30, 'a');

 char x=EEPROMread(30);
 usart_send(x);
//printf("%c",'b');

return 0;

}



