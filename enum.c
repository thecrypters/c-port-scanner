#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <netdb.h>
#include <time.h>

int main(int argc, char **argv)
{
     
    struct addrinfo* serv_addr;
    int erro;
     int msec = 0;
    
    clock_t before = clock();
		getaddrinfo("smtp.gmail.com", "587", NULL, &serv_addr);
		int sockfd = socket(serv_addr->ai_family, serv_addr->ai_socktype, 
                serv_addr->ai_protocol); 
		if( sockfd >= 0){
           
           int status = connect(sockfd, serv_addr->ai_addr, 
                 serv_addr->ai_addrlen);

           if(status >= 0){
              char buffer[1024] = {0}; 
              read( sockfd , buffer, 1024);
              write(sockfd, buffer, strlen(buffer));

           	  printf("Porta  aberta\n");
              printf("%s\n",buffer );
              write(sockfd, "vrfy", strlen("vrfy"));
              read( sockfd , buffer, 1024);
              printf("%s\n",buffer );
           }
            else
              printf("Porta  fechada\n");
        }
	
		else
           printf("Porta  fechada\n");

   clock_t difference = clock() - before;
   msec = difference * 1000 / CLOCKS_PER_SEC;
    printf("tempo levado em segundos: %d\ntempo lvado em millisegundos: %d\n",msec/1000, msec%1000);


    return 0;
}


