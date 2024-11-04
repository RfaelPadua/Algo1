// Implemente  o  algoritmo  Merge  Sort  visto  em  sala.  Teste  o  algoritmo  com  um  vetor 
// de 10 posições.

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* vetor, int inicio, int fim);
void merge(int* vetor, int inicio, int meio, int fim);


int main(){
    int vetor[15] = {34, 7, 23, 32, 5, 62, 32, 14, 25, 12, 22, 11, 9, 3, 17};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);

    

    printf("\nVetor desordenado:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    mergeSort(vetor, 0, tamanho - 1);

    printf("\nVetor ordenado:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
}

void mergeSort(int *vetor, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
        
        for(int i = 0; i < 15; i++){
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }
}

void merge(int* vetor, int inicio, int meio, int fim){
    int tamanho, fim1, fim2, p1, p2, i, j;
    tamanho = fim - inicio + 1;
    fim1 = 0; fim2 = 0;
    p1 = inicio;
    p2 = meio + 1;
    int* temp;

    temp = (int*) malloc(tamanho * sizeof(int));

    for(i = 0; i <= tamanho - 1; i++){
        if(!fim1 && !fim2){
            if(vetor[p1] < vetor[p2]){
                temp[i] = vetor[p1++];
            }else{
                temp[i] = vetor[p2++];
            }
            
            if (p1 > meio) fim1 = 1;
            if (p2 > fim ) fim2 = 1;
        }else{
            if(!fim1){
                temp[i] = vetor[p1++];
            }else{
                temp[i] = vetor[p2++];
            }
        }
    }

    for(i = 0, j = inicio; i < tamanho; i++, j++){
        vetor[j] = temp[i];
    }
}