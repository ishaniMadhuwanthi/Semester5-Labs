/*
CO323-E/15/211
*/


/* Sample echo server */

#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char**argv)  {
      int sockfd,n;
      struct sockaddr_in servaddr, cliaddr;
      socklen_t len;
      char mesg[1000];

 // char* banner = "Hello UDP client! This is UDP server";

 sockfd=socket(AF_INET,SOCK_DGRAM,0);

 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
 servaddr.sin_port=htons(32000);
 bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

 len = sizeof(cliaddr);

n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len);
mesg[n] = 0;

//recieve the number of lines from client
	int noOfLines=atoi(mesg);
sendto(sockfd,"ack",n,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));

printf("Received: %s\n",mesg);

//send ack to client
printf("Sent : ack\n");
 
int i,j;
i=0;
while(i<noOfLines){

n=recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);
		
//receive number of lines given
	mesg[n]=0;
	printf("Recieved : %s",mesg);	
	
//convert message to upper characters
for(j=0;j<n;j++)mesg[j]=toupper(mesg[j]);
			
//send
sendto(sockfd,mesg,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));	
printf("Sent : %s",mesg);
 
i++;
}

return 0;

}
