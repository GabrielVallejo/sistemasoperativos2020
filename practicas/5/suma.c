#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    char c;
    unsigned i = 0;
    char buffer[250];
    unsigned total = 0;
    while(read(STDIN_FILENO,&c,1) != 0){
        if(c != ' '){
            buffer[i++] = c;
        }else{
            buffer[i] = '\0';
            total += atoi(buffer);
            i = 0;
        }
    }
    buffer[i] = '\0';
    total += atoi(buffer);
    printf("%u\n", total);
}