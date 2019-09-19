/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/

void USART_Init()
{
/*Set baud rate */
UBBR0 = 103;

/*Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 1stop bit and no parity */
UCSR0C &= ~(1<<USBS0) ; //1 stop bit
UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01); // 8 bit
UCSR0C &= ~(1<<UPM01); //no parity
UCSR0C &= ~(1<<UPM00); //no parity

}
