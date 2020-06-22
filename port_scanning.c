#include <unistd.h> 
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

    char ip[16] = {0};
    strcpy(ip, argv[1]);

	char primeiraPorta[4] = {0};
	strcpy(primeiraPorta, argv[2]);

	char ultimaPorta[4] = {0};

    strcpy(ultimaPorta, argv[3]);

    int i ;
    int limite = atoi(ultimaPorta);
    char portaAtual[5];

    clock_t before = clock();
    printf("Iniciando o scaneamento no host %s :\n", ip);

	for(i=atoi(primeiraPorta); i <= limite; i++ ){

        sprintf(portaAtual,"%d",i);
		getaddrinfo(ip, portaAtual, NULL, &serv_addr);
		int sockfd = socket(serv_addr->ai_family, serv_addr->ai_socktype, 
                serv_addr->ai_protocol); 
		if( sockfd >= 0){
           
           int status = connect(sockfd, serv_addr->ai_addr, 
                 serv_addr->ai_addrlen);

           if(status >= 0)
           	  printf("Porta %s aberta\n",portaAtual);
            else
              printf("Porta %s fechada\n",portaAtual);
		}
		else
           printf("Porta %s fechada\n",portaAtual);
	}
	clock_t difference = clock() - before;

    msec = difference *  / CLOCKS_PER_SEC;
    printf("%d\n",msec);
    printf("tempo levado em segundos: %d\ntempo lvado em millisegundos: %d\n",msec/1000, msec%1000);

    return 0;
}


