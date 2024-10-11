#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void FillAleatory(int *vetor, int tamanho);

void BubbleSort(int *vetor, int tamanho);

int SearchSeq(int vetor[], int key, int tamanho);

int SearchBin(int vetor[], int key, int tamanho);

int main(){
    int tamanho = 1000000;
    int vetor[tamanho];
    int chave, resultado;

    clock_t inicio, fim;
    unsigned long int tempo;


    FillAleatory(vetor, tamanho);
    srand(time(NULL));
    chave = rand() % tamanho;


    
    inicio = clock();
    resultado = SearchSeq(vetor, chave, tamanho);
    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    
    if(resultado){
        printf("\n\tPor Busca Sequencial\nO Numero %d esta presente no vetor\n", chave);
    }else{
        printf("\n\tPor Busca Sequencial\nO Numero %d nao esta presente no vetor\n", chave);
    }
    printf("Tempo de busca por Busca Sequencial: %lu milissegundos\n", tempo);


    chave++;
    inicio = clock();

    BubbleSort(&vetor, tamanho);
    resultado = SearchBin(vetor, chave, tamanho);

    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    printf("Tempo de busca por Busca Binaria: %lu milissegundos\n", tempo);

   if(resultado){
        printf("\n\n\t\nPor Busca Binaria\nO Numero %d esta presente no vetor\n", chave);
    }else{
        printf("\n\tPor Busca Binaria\nO Numero %d nao esta presente no vetor\n", chave);
    }
    


}

void FillAleatory(int *vetor, int tamanho){
    int i;

    srand(time(NULL));
    for(i = 0; i < tamanho; i++){
        vetor[i] = rand() % tamanho;
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
}

int SearchSeq(int vetor[], int key, int tamanho){
    int i;


    for(i = 0; i < tamanho; i++){
        if(vetor[i] == key){
            return 1;
        }
    }

    return 0;

}

int SearchBin(int vetor[], int key, int tamanho){
    int inicio, fim, m;

    inicio = 0;
    fim = tamanho - 1;


    

    while(inicio <= fim){
        m = (inicio + fim)/2;

        if(vetor[m] == key){
            return 1;
        }else if(key < vetor[m]){
            fim = m - 1;
        }else{
            inicio = m + 1;
        }
    }

    return 0;

}
