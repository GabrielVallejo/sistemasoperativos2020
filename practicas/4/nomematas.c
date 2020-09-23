#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void signalHandler(int signum){
    printf("hahaha no me matas\n");
}

int main(){
    signal(2,signalHandler);
    while(1){
        sleep(2);
        printf("trabajando\n");
    }
    return 0;
}