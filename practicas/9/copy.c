#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
	char *origen = argv[1];
	char *destination = argv[2];
	
	int fd = open(origen, O_RDONLY, 0);
	int des = open(destination, O_WRONLY|O_CREAT, 0);
	if(fd < 0){
		printf("Erro al abrir el archivo \n");
		return 1;
	}
	char c;
	while(read(fd, &c, 1)){
		write(des, &c, 1);
	}
	close(fd);
	close(des);
	return 0;
}