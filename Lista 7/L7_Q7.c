/*******************************************************************
*   Faça um programa que dada a idade de uma
*   pessoa, retorna uma das seguintes mensagens:
*   “Não pode nem votar e nem dirigir”, “Pode votar,
*   mas não pode dirigir”, “Pode votar e pode dirigir”.
*******************************************************************/
#include <stdio.h>

int main(void){
    int idade;

    printf("Informe a sua idade: ");
    scanf("%d", &idade);

    if(idade < 16)
        printf("Nao pode nem votar e nem dirigir");
    else if (idade < 18)
        printf("Pode votar, mas nao pode dirigir.");
    else
        printf("Pode votar e dirigir.");

    return 0;
    
}