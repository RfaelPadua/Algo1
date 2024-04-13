#include <stdio.h>

int quantasVezesAparece(int numeros[10], int numero);

int main(){
    int numeros[10];
    int numero;
    int i;
    for(i = 0; i<10; i++){
        printf("Informe o %do valor: ", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("Informe o Numero: ");
    scanf("%d", &numero);

    printf("O numero aparece %d vezes.", quantasVezesAparece(numeros, numero));
}

int quantasVezesAparece(int numeros[10], int numero){
    int i, cont = 0;

    for(i = 0; i < 10; i++){
        if (numeros[i] == numero){
            cont++;
        }
    }

    return cont;
}