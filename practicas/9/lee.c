#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	//open("/nombre", modo/permiso); abrir archivos, fopen, regresa un entero (ID del recurso) con el que podemos hacer wirte o read.
	int fd = open("./lee2.c", O_RDONLY, 0);
	if(fd < 0){
		printf("Erro al abrir el archivo \n");
		return 1;
	}
	char c;
	while(read(fd, &c, 1)){
		printf("%c", c);
	}
	return 0;
}