/*******************************************************************
*   Faça um programa que receba um número inteiro
*   e informe se ele é divisível por 10, por 5, 
*   por 2 ou se não é divisível por nenhum deles.
*******************************************************************/
#include <stdio.h>

int main(void){

    int n;
    
    printf("Informe um numero inteiro: ");
    scanf("%d", &n);

//  verificar se ele é divisível por 10, por 5, por 2
//   e imprimir
    if(n % 10 == 0)
        printf("O numero eh divisivel por 10, 5 e 2.");
    else if(n % 5 == 0)
        printf("O numero eh divisivel por 5.");
    else if(n % 2 == 0)
        printf("O numero eh divisivel por 2.");
    else
        printf("O numero nao eh divisivel por 10, 5 nem 2.");

    return 0;
}