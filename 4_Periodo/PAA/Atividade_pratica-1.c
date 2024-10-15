#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void OrdenacaoSelecao(int vetor[], int tam){
    int i, j, min, aux;
    for(i = 0; i < tam-1; i++){
        min = i;
        for(j = i+1; j < tam; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        if(i != min){
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

void OrdenacaoBolha(int vetor[], int tam){
    int i, j, aux;
    for(i = 0; i < tam-1; i++){
        for(j = tam-1; j > i; j--){
            if(vetor[j] < vetor[j-1]){
                aux = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = aux;
            }
        }
    }
}



int main(){
    clock_t inicio, fim;
    unsigned long int tempo;
    
    int i, tamanho = 1000000;
    int vetor[tamanho];

    srand(time(NULL));
    for(i = 0; i < tamanho; i++){
        vetor[i] = rand() % tamanho;
    }

    printf("Vetor original: ");
    for(i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    OrdenacaoSelecao(vetor, tamanho);

    printf("Vetor ordenado por selecao: ");
    for(i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    srand(time(NULL));
    for(i = 0; i < tamanho; i++){
        vetor[i] = rand() % tamanho;
    }

    printf("Vetor original: ");
    for(i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    OrdenacaoBolha(vetor, tamanho);

    printf("Vetor ordenado por bolha: ");
    for(i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    printf("\n\nTempo de busca por Busca Binaria: %lu milissegundos\n", tempo);

    return 0;

}  