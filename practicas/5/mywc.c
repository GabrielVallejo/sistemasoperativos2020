#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    char c;
    unsigned caracteres = 0;
    unsigned palabras = 0;
    unsigned lineas = 0;
    int i = 0,
        j = 0;
    while(read(STDIN_FILENO,&c,1) != 0){
        if(c == '\n'){
            if(i == 0){
                palabras++;
            }else{
                i = 0;
            }
            lineas++;
            j = 0;
        }else if(c == ' ' && j == 0){
            palabras++;
            i = 1;
            j = 1;
        }else if(c != ' ' && c != '\n'){
            i = 0;
            j = 0;
        }
        caracteres++;
    }
    printf("lineas: %u, palabras: %u, caracteres: %u\n",lineas, palabras, caracteres);
}