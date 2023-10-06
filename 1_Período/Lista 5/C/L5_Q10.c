#include <stdio.h>

int main(void){
    
    char letra, i = 0;
    do{
    printf("Informe uma letra maiuscula: ");
    scanf(" %c", &letra);

    if(letra > 64 && letra < 91){
        i = 1;
    }
    } while (i != 1);

    printf("Letra minuscula: %c", letra + 32);
}