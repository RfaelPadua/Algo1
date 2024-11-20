#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "vetor_1000.c"   // Inclui o vetor de tamanho 1000
#include "vetor_5000.c"   // Inclui o vetor de tamanho 5000
#include "vetor_10000.c"  // Inclui o vetor de tamanho 10000
#include "vetor_50000.c"  // Inclui o vetor de tamanho 50000
#include "vetor_100000.c" // Inclui o vetor de tamanho 100000
#include "vetor_500000.c" // Inclui o vetor de tamanho 500000
#include "vetor_1000000.c"// Inclui o vetor de tamanho 1000000
#include "test.c"




void heapSort(int *vetor, int tam);
void criaHeap(int *vetor, int i, int f);

void bubbleSort(int *vetor, int tam);

void alunoSort(int *vetor, int tam);


int main() {
        
    int values[] = {34, 7, 23, 32, 5, 62};

    int size = sizeof(values) / sizeof(int);

    Node* nodes[size];

    printf("Vetor de valores: ");
    for(int i = 0; i < size; i++){
        printf("%d ", values[i]);
    }

    for(int i = 0; i < size; i++){
        nodes[i] = create_node(values[i]);
    }

    build_graph(nodes, size);

    printf("Iniciando ordenacao...\n");
    random_jump_sort(nodes, size);

    printf("Ordenacao finalizada.\n");
    

    for(int i = 0; i < size; i++){
        free(nodes[i]);
    }
}

void criaHeap(int *vetor, int i, int f){
    int aux = vetor[i];
    int j = i * 2 + 1;

    while(j <= f){
        if(j < f && vetor[j] < vetor[j+1]){
            j = j + 1;
        }
        if(aux < vetor[j]){
            vetor[i] = vetor[j];
            i = j;
            j = i * 2 + 1;
        } else {
            j = f + 1;
        }
    }
    vetor[i] = aux;
}

void heapSort(int *vetor, int tam){
    int i;

    for(i = (tam-1)/2; i >= 0; i--){
        criaHeap(vetor, i, tam - 1);
    }

    for(i = tam - 1; i > 0; i--){
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i - 1);
    }
}

void bubbleSort(int *vetor, int tam){
    int i, j, aux;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam - 1; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void alunoSort(int *vetor, int tam){
   // dividir o vetor em camadas de 10 elementos
    // ordenar cada camada com o bubble sort

    int i, j, aux;
    for(i = 0; i < tam; i+=10){
        for(j = i; j < i+10; j++){
            for(int k = i; k < i+10; k++){
                if(vetor[j] < vetor[k]){
                    aux = vetor[j];
                    vetor[j] = vetor[k];
                    vetor[k] = aux;
                }
            }
        }
    }

    // ordenar o vetor comparação entre as camadas, comparando o elemento com o elemento da camada seguinte e com seus visinhos
    for(i = 0; i < tam; i+=10){
        for(j = i; j < i+10; j++){
            if(j+10 < tam){
                if(vetor[j] > vetor[j+10]){
                    aux = vetor[j];
                    vetor[j] = vetor[j+10];
                    vetor[j+10] = aux;
                }
            }
            if(j-1 >= 0){
                if(vetor[j] < vetor[j-1]){
                    aux = vetor[j];
                    vetor[j] = vetor[j-1];
                    vetor[j-1] = aux;
                }
            }
            if(j+1 < tam){
                if(vetor[j] > vetor[j+1]){
                    aux = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = aux;
                }
            }
        }
    }

}