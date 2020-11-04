#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
extern int h_errno;
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int clientes [5] = {0,0,0,0,0};
int numClientes = 0;


typedef struct hd {
	int hid;
	char *name;
} ThreadData;

void * user(void * arg){
	printf("Tengo nuevo cliente \n");
	ThreadData *td = (ThreadData *)arg;
	char * bienvenida = "Bienvenid@ ";
	strcat(&bienvenida, &td->name);
	write(td->hid, bienvenida, strlen(bienvenida));
	char * msg;
	char *broadcast;
	while (read(td->hid, &msg, 250)) {
		if(msg != "bye"){
			broadcast = td->name;
			strcat(&broadcast, &msg);
		//printf("%s", msg); 
			for(int i=0; i<numClientes; i++){
				if(clientes[i] != td->hid && clientes[i] !=0){
					write(clientes[i], &broadcast, 250);
				}
			}
		}else{
			char * despedida ="Se desconecto ";
			strcat(&despedida, &td->name);
			for(int i=0; i<numClientes; i++){
				if(clientes[i] != td->hid && clientes[i] !=0){
					write(clientes[i], &despedida, 250);
				}
			}
			numClientes--;
			close(td->hid);
			pthread_exit(NULL);
			free(arg);
		}
		
//            write(clientSocket,&c,1);
    }  
	
	
} 

int main(int argc, const char *argv[]){
	printf("Hi \n");
    struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(2727); 
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bind(sockfd,&serverAddress,sizeof(serverAddress));
    listen(sockfd, 5);
    while (1) {
        printf("hola \n");
		pthread_t newThread;
		struct sockaddr_in clientAddress;
        int cleintSize = sizeof(clientAddress);
		//if(numClientes < 5){
			
			int clientSocket = accept(sockfd, &clientAddress, &cleintSize);
			clientes[numClientes] = clientSocket;
			char * name;
			printf("%d", clientSocket);
			if(read(clientSocket, &name, 20)){
				name = name;
			}
			numClientes++;
			//char c;
			//char *message = "Hello desde gitpod";
			 // 
			ThreadData  *td = (ThreadData *)calloc(1,sizeof(ThreadData));
			td->name = name;
			td->hid = clientSocket;
			//td[i].msg = "Hello world desde el hilo\n";
			//td[i].hid = i;
			pthread_create(&newThread,NULL,user,(void *)td);
	}
       
        //write(clientSocket, message, strlen(message));
        //close(clientSocket);
}
