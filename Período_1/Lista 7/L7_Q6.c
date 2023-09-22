/*******************************************************************
*   Escrever um programa em C que lê um valor i,inteiro e positivo
*   e 3 valores a, b e c. Se o valor de i é par  então calcular e
*   imprimir na tela a média aritmética de a, b e c. Caso contrário,
*   se i>10 então calcular e imprimir na tela a média ponderada de
*   a, b e c. Os pesos dos valores são respectivamente 2, 3 e 4.
*******************************************************************/
#include <stdio.h>

int main(void){
    
    int i;
    float a, b, c, m;

    printf("Digite um valor inteiro e positivo para: ");
    scanf("%d", &i);

    printf("Digite tres valores: ");
    scanf("%f %f %f", &a, &b, &c);

    if(i % 2 == 0)
    {
        m = (a + b + c) / 3;
        printf("Media aritimetica: %.2f", m);
    }
    else if (i > 10)
    {
        m = (a * 2 + a * 3 + a * 4) / 9;
        printf("Media ponderada: %.2f", m);
    }

    return 0;
}