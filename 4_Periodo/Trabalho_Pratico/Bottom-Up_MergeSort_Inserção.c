#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<windows.h>
#define BLOCK_SIZE 10
#include "vetor_1000000.c"// Inclui o vetor de tamanho 1000000

void insertionSort(int arr[], int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para realizar o Merge Sort Bottom-Up sem vetor auxiliar
void mergeBottomUp(int arr[], int n) {
    for (int size = BLOCK_SIZE; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);
            if (mid < right) {
                int i = left;
                int j = mid + 1;
                int k = left;
                while (i <= mid && j <= right) {
                    if (arr[i] <= arr[j]) {
                        i++;
                    } else {
                        int temp = arr[j];
                        for (int m = j; m > i; m--) {
                            arr[m] = arr[m - 1];
                        }
                        arr[i] = temp;
                        i++;
                        mid++;
                        j++;
                    }
                }
            }
        }
    }
}

// Função principal que realiza o algoritmo
void sortWithBlockAndMerge(int arr[], int n) {
    // Passo 1: Ordenar blocos de 10 elementos com Insertion Sort
    for (int i = 0; i < n; i += BLOCK_SIZE) {
        int end = (i + BLOCK_SIZE - 1 < n) ? (i + BLOCK_SIZE - 1) : (n - 1);
        insertionSort(arr, i, end);
    }
    
    // Passo 2: Fazer o Merge Sort Bottom-Up entre os blocos
    mergeBottomUp(arr, n);
}


int main(){
    int vetor[100];
    clock_t start, end;
    double time;
    int tamanho = 100;
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 1000000;

    }

    start = clock();
    sortWithBlockAndMerge(vetor, tamanho);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", time);

    for(int i = 0; i < tamanho-1; i++){
        if(vetor[i] > vetor[i+1]){
            printf("Erro na ordenacao\n");
            printf(" %d nao eh menor que %d\n", vetor[i], vetor[i+1]);
            break;
        }
    }
}