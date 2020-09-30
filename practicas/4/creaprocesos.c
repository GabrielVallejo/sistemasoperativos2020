#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

 void signalHandler(int signum){
    int status;
    wait(&status);
    printf("Limpiando los desastres del hijo, estatus %d\n",status);
}

int main(int argc, char **argv){
    unsigned pid = fork();
    signal(17,signalHandler);
    if(pid == 0){
        printf("Soy el proceso hijo\n");
        sleep(5);
        //execv(argv[1], &argv[1]);
        return 10;
    }else{
        printf("Soy el proceso padre y mi hijo es %u\n", pid);
        while(1){
            sleep(2);
            printf("trabajando\n");
        }
    }
    printf("Hola mundo\n");
    return 0;
}
