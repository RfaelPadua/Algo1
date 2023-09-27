#include <stdio.h>

int main(void){

    char a;
    int n = 0;

    printf("Responda 'V'(venceu) ou 'P'(perdeu) para cada partida\n");
    printf("Primeira partida: ");
    scanf(" %c", &a);
    a == 'V' ? n++ : n == n;

    printf("Segunda partida: ");
    scanf(" %c", &a);
    a == 'V' ? n++ : n == n;

    printf("Terceira partida: ");
    scanf(" %c", &a);
    a == 'V' ? n++ : n == n;

    printf("Quarta partida: ");
    scanf(" %c", &a);
    a == 'V' ? n++ : n == n;
    
    printf("Quinta partida: ");
    scanf(" %c", &a);
    a == 'V' ? n++ : n == n;

    printf("Sexta partida: ");
    scanf(" %c", &a);
    a == 'V' ? n++ : n == n;

    if(n > 4)
        printf("1");
    else if(n > 2)
        printf("2");
    else if(n > 0)
        printf("3");
    else
        printf("0");
}