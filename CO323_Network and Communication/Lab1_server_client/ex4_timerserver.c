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
#include <stdio.h>
#include <time.h>
#include <string.h>


int main(int argc, char**argv)  {
      int sockfd,n=10;
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

 recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len);
mesg[n];

        time_t current_time;
	struct tm * time_info;
	char timeString[8];
	char timeOldString[8];

while(1){

		strcpy(timeOldString,timeString);
		time(&current_time);
		time_info = localtime(&current_time);
		strftime(timeString, 9, "%H:%M:%S", time_info);
		if(timeOldString[7]!=timeString[7]){
			sendto(sockfd,timeString,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));	
			printf("Sent : %s\n",timeString);	
		}
	}

return 0;

}
