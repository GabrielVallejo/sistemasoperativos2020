#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
	
typedef struct hd {
	int hid;
	char *msg;
} ThreadData;

void * hello(void * arg){
	ThreadData *td = (ThreadData *)arg;
	printf("%s %d\n",td->msg, td->hid);
	pthread_exit(NULL);
	free(arg);
} 

int main(){
	pthread_t newThread;
	//ThreadData td[10];
		
	for(int i=0; i < 10; i++){
		ThreadData  *td = (ThreadData *)calloc(1,sizeof(ThreadData));
		td->msg = "Hello world desde el hilo\n";
		td->hid = i;
		//td[i].msg = "Hello world desde el hilo\n";
		//td[i].hid = i;
		pthread_create(&newThread,NULL,hello,(void *)td);
		
	}
	pthread_exit(NULL);
}
// int * indica que es un apuntador/dirección del valor, igual aplica con otros 
//tipos de datos
//void * es un apuntador a cualquier cosa