#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void FillAleatory(int *vetor, int tamanho);

void BubbleSort(int *vetor, int tamanho);

int SearchSeq(int vetor[], int tamanho, int key);

int SearchBin(int vetor[], int tamanho, int key);

int main(){
    int tamanho = 1000000;
    int vetor[tamanho];

}

void FillAleatory(int *vetor, int tamanho){
    int i;
    srand(time(NULL));
    for(i = 0; i < tamanho; i++){
        vetor[i] = rand();
    }   
}

void BubbleSort(int *vetor, int tamanho){
    int i, j, aux;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
}

int SearchSeq(int vetor[], int tamanho, int key){
    int i;

    for(i = 0; i < tamanho; i++){
        if(vetor[i] == chave){
            return 1;
        }
    }

    return 0;

}

int SearchBin(int vetor[], int key){

}
