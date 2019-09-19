/*
E/15/211
Department of Computer Engineering-UoP
Semester5-CO321
*/

unsigned char USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSR0A & (1<<RXC0)) )
;
/* Get and return received data from buffer */
return UDR0;
}
