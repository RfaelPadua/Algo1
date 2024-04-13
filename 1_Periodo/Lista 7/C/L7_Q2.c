/*******************************************************************
*   Escreva um programa para ler 3 valores inteiros
*   (não considere que não serão lidos valores iguais)
*   e escrevê-los em ordem crescente.
*******************************************************************/
#include <stdio.h>

int main(void){
    
    int n1, n2, n3;

    //Pedir por 3 numeros inteiro e salvar nas variaveis.
    printf("Informe 3 valores inteira: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    //Ordendar os numeros e os imprima.
    if (n1 < n2)
            if (n2 < n3)
                printf("%d, %d, %d.", n1, n2, n3);
            else if (n1 < n3)
                printf("%d, %d, %d.", n1, n3, n2);
            else
                printf("%d, %d, %d.", n3, n1, n2);
        else 
            if (n1 < n3)
                printf("%d, %d, %d.", n2, n1, n3);
            else if (n2 < n3)
                printf("%d, %d, %d.", n2, n3, n1);
            else
                printf("%d, %d, %d.", n3, n2, n1);
    
    return 0;    
}