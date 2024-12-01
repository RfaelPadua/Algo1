#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXUNSIGNINT 4294967295

//função que volta todos os numeros primos até um numero n
int numerosPrimosForcaBruta(int n, int *primos){
    int i, j, cont = 1;
    for(i = 2; i <= n; i++){
        for(j = 2; j < i; j++){
            if(i % j == 0){
                break;
            }
        }
        if(j == i){
            primos[cont] = i;
            cont++;
        }
    }
    return cont;
}


int numerosPrimosCrivo(int n, int *primos){
    int i, j, cont = 1;
    int *numeros = (int*) malloc((n+1) * sizeof(int));
    for(i = 0; i <= n; i++){ 
        numeros[i] = 1; 
    }
    for(i = 2; i <= n; i++){ 
        if(numeros[i] == 1){ 
            primos[cont] = i;
            cont++;
            for(j = i; j <= n; j += i){
                numeros[j] = 0;
            }
        }
    }
    free(numeros);
    return cont;
}

int main(){
    int n = 1000000;
    int *primos = (int*) malloc((n+1) * sizeof(int));
    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    int qtdPrimos = numerosPrimosCrivo(n, primos);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Crivo\n");
    printf("Quantidade de primos: %d\n", qtdPrimos);
    printf("Tempo: %lf\n", tempo);
    printf("\n");

    inicio = clock();
    qtdPrimos = numerosPrimosForcaBruta(n, primos);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Forca Bruta\n");
    printf("Quantidade de primos: %d\n", qtdPrimos);
    printf("Tempo: %lf\n", tempo);
    printf("\n");


    return 0;
}