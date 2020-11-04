#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#inclide <semaphore.h>

unsigned saldo;
sem_t semSaldo;

void *addToSaldo(void * arg){
	sem_wait(&semSaldo);
	unsigned valorinicial  = saldo;
	unsigned SaldoFinal = valorinicial + 500;
	saldo = SaldoFinal;
	sem_pos(&semSaldo);
	printf("El saldo inicial es %d el saldo actual es %d \n", valorinicial,SaldoFinal);
	pthread_exit(NULL);
}

int main(){
	unsigned NUM_THREAD = 100;
	saldo = 0;
	sem_init(&semSaldo,0,1);
	pthread_t threads[NUM_THREAD];
	for(int i = 0; i < NUM_THREAD; i++){
		pthread_create(&threads[i], NULL, addToSaldo, NULL);
	}
	for(int i = 0; i < NUM_THREAD; i++){
		pthread_join(threads[i], NULL);
	}
	printf("El saldo final es %d \n", saldo);
	pthread_exit(NULL);
}