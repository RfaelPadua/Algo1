#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "vetor_1000.c"   // Inclui o vetor de tamanho 1000
#include "vetor_5000.c"   // Inclui o vetor de tamanho 5000
#include "vetor_10000.c"  // Inclui o vetor de tamanho 10000
#include "vetor_50000.c"  // Inclui o vetor de tamanho 50000
#include "vetor_100000.c" // Inclui o vetor de tamanho 100000
#include "vetor_500000.c" // Inclui o vetor de tamanho 500000
#include "vetor_1000000.c"// Inclui o vetor de tamanho 1000000

// Declaração das funções de ordenação
void heapSort(int *vetor, int tam); 
void criaHeap(int *vetor, int i, int f);

void alunoSort(int *vetor, int inicio, int fim);
void separarMenoresMaiores(int* vetor, int inicio, int fim);

void bubbleSort(int *vetor, int tam);


// Declaração das funções para testar a ordenação
void testarOrdenacao(int *vetor, int tam);
void test(void (*sort)(int*, int, int),int fim);

int* gerarVetor(int tam){
    int i;

    int *vetor = (int*) malloc(tam * sizeof(int));

    for(i = 0; i < tam; i++){
        vetor[i] = rand() % 1000000;
    }

    return vetor;
}


int main(){


    int vetor[20] = {34, 36, 23, 32, 5, 62, 32, 102, 25, 12, 22, 11, 9, 3, 17, 1, 8, 4, 6, 2};
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    printf("Testando alunoSort\n");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    alunoSort(vetor, 0, tam);

    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    for(int i = 10; i <= 1000000000; i *= 10){
        int *vetor1 = gerarVetor(i);
        //criar copia do vetor 1
        int *vetor2 = (int*) malloc(i * sizeof(int));
        int *vetor3 = (int*) malloc(i * sizeof(int));

        for(int j = 0; j < i; j++){
            vetor2[j] = vetor1[j];
            vetor3[j] = vetor1[j];
        }

        clock_t start, end;
        double time;

        printf("\t\tTestando vetor de tamanho %d\n\n", i);

        printf("Testando heapSort\n");
        start = clock();
        heapSort(vetor1, i);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Tempo de execucao do heapSort para %d elementos: %f\n", i, time);

        printf("Testando alunoSort\n");
        start = clock();
        alunoSort(vetor2, 0, i);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Tempo de execucao do alunoSort para %d elementos: %f\n", i, time);
        testarOrdenacao(vetor2, i);

        // printf("Testando bubbleSort\n");
        // start = clock();
        // bubbleSort(vetor3, i);
        // end = clock();
        // time = (double)(end - start) / CLOCKS_PER_SEC;
        // printf("Tempo de execucao do bubbleSort para %d elementos: %f\n", i, time);
        
        
        free(vetor1);
        free(vetor2);
    }

    // test(alunoSort, 1000000);
    
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

void separarMenoresMaiores(int* vetor, int inicio, int fim) {
    int estaSeparado = 0; // Flag para indicar se a partição está separada


    while(!estaSeparado){ // Enquanto a partição não estiver separada 
        estaSeparado = 1; // Supor que a partição está separada


        int meio = (inicio + fim) / 2; // Indice do meio do vetor
        // int tam = (fim - inicio + 1) * 0.1 < 3 ? 3 : (fim - inicio + 1) * 0.1; // Tamanho do bloco de 10% do vetor
        int tam = (fim - inicio + 1) * 0.1 < 3 ? 3 : (fim - inicio + 1) * 0.1 > 100000 ? 100000 : (fim - inicio + 1) * 0.1; // Tamanho do bloco de 10% do vetor
        int maxIndex[tam]; // Índice do maior elemento
        for(int i = 0; i < tam; i++) maxIndex[i] = -1; // Inicializar o índice do maior elemento

        maxIndex[0] = inicio; // Inicializar o índice do maior elemento
        int i, comecoMax = 0;


        for (i = inicio + 1; i < meio; i++) { // Percorrer a primeira metade e encontrar o maior
            if (vetor[i] > vetor[maxIndex[comecoMax]]) {
                comecoMax = (comecoMax + 1) % tam; // Incrementar o índice do maior
                maxIndex[comecoMax] = i;
                

            }
        }

        int minIndex[tam]; // Índice do menor elemento
        for(int i = 0; i < tam; i++) minIndex[i] = -1; // Inicializar o índice do menor elemento

        minIndex[0] = meio; // Inicializar o índice do menor elemento
        int comecoMin = 0;

        for (i = meio + 1; i < fim; i++) { // Percorrer a segunda metade
            if (vetor[i] < vetor[minIndex[comecoMin]]) {
                comecoMin = (comecoMin + 1) % tam; // Incrementar o índice do menor
                minIndex[comecoMin] = i;
                
            }
        }


        for (i = 0; i < tam; i++) {
            if(minIndex[comecoMin] == -1 || maxIndex[comecoMax] == -1) break;
            if (vetor[maxIndex[comecoMax]] > vetor[minIndex[comecoMin]]) {
                int aux = vetor[maxIndex[comecoMax]];
                vetor[maxIndex[comecoMax]] = vetor[minIndex[comecoMin]];
                vetor[minIndex[comecoMin]] = aux;

                comecoMax = (comecoMax - 1 + tam) % tam; // Decrementar o índice do maior
                comecoMin = (comecoMin - 1 + tam) % tam; // Decrementar o índice do menor

                
                estaSeparado = 0; // Se houve troca, a partição não está separada, então resetar a flag
            }
        }
    }
}


// void separarMenoresMaiores(int* vetor, int inicio, int fim) {
//     int estaSeparado = 0; // Flag para indicar se a partição está separada

//     while (!estaSeparado) { // Enquanto a partição não estiver separada 
        
//         estaSeparado = 1; // Supor que a partição está separada

//         // Encontrar o maior na primeira metade

//         int maxIndex = inicio; // Índice do maior elemento
//         int meio = (inicio + fim) / 2; // Indice do meio do vetor

//         for (int i = inicio; i < meio; i++) { // Percorrer a primeira metade e encontrar o maior
//             if (vetor[i] > vetor[maxIndex]) {
//                 maxIndex = i;
//             }
//         }

//         // Encontrar o menor na segunda metade


//         int minIndex = meio; // Índice do menor elemento

//         for (int j = meio; j < fim; j++) { // Percorrer a segunda metade e encontrar o menor

//             if (vetor[j] < vetor[minIndex]) {
//                 minIndex = j;
//             }
//         }

//         // Verificar se o maior da primeira metade é menor que o menor da segunda metade, se sim, trocar
//         if (vetor[maxIndex] > vetor[minIndex]) {
//             int aux = vetor[maxIndex];
//             vetor[maxIndex] = vetor[minIndex];
//             vetor[minIndex] = aux;
//             estaSeparado = 0; // Se houve troca, a partição não está separada, então resetar a flag
//         }
//     }
// }



void alunoSort(int* vetor, int inicio, int fim) {

    if (fim - inicio <= 1) return; // Se to tamanho <= 1, já está ordenado

    int meio = (inicio + fim) / 2; // Dividir o vetor em duas partes

    separarMenoresMaiores(vetor, inicio, fim); // Separar o vetor em menores e maiores
    alunoSort(vetor, inicio, meio); // Ordenar a primeira metade
    alunoSort(vetor, meio, fim); // Ordenar a segunda metade

}

void testarOrdenacao(int *vetor, int tam){
    int i;
    for(i = 0; i < tam - 1; i++){
        if(vetor[i] > vetor[i+1]){
            printf("Erro na ordenação\n");
            printf(" %d não é menor que %d\n", vetor[i], vetor[i+1]);

        }
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

void test(void (*sort)(int*, int, int), int fim) {
    if (fim < 1000) return;

    clock_t start, end;
    double time;

    printf("\nTestando vetor de tamanho 1000\n");
    start = clock();
    sort(vetor_1000, 0, 1000);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", time);
    testarOrdenacao(vetor_1000, 1000);

    if (fim == 1000) return;

    printf("\nTestando vetor de tamanho 5000\n");
    start = clock();
    sort(vetor_5000, 0, 5000);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", time);
    testarOrdenacao(vetor_5000, 5000);

    if (fim == 5000) return;

    printf("\nTestando vetor de tamanho 10000\n");
    start = clock();
    sort(vetor_10000, 0, 10000);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", time);
    testarOrdenacao(vetor_10000, 10000);

    if (fim == 10000) return;

    printf("\nTestando vetor de tamanho 50000\n");
    start = clock();
    sort(vetor_50000, 0, 50000);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", time);
    testarOrdenacao(vetor_50000, 50000);

    if (fim == 50000) return;

    printf("\nTestando vetor de tamanho 100000\n");
    start = clock();
    sort(vetor_100000, 0, 100000);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", time);
    testarOrdenacao(vetor_100000, 100000);

    if (fim == 100000) return;

    printf("\nTestando vetor de tamanho 500000\n");
    start = clock();
    sort(vetor_500000, 0, 500000);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", time);
    testarOrdenacao(vetor_500000, 500000);

    if (fim == 500000) return;

    printf("\nTestando vetor de tamanho 1000000\n");
    start = clock();
    sort(vetor_1000000, 0, 1000000);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", time);
    testarOrdenacao(vetor_1000000, 1000000);

    for(int i = 0; i < 1000000; i++){
        if(i % 50 == 0) printf("\n");
        printf("%d ", vetor_1000000[i]);
    }
}
