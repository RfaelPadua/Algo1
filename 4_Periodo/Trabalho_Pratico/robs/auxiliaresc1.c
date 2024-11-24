#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "auxiliaresc1.h"

// Preenche o vetor com valores aleatórios
void preencherVetorAleatorio(int vetorInt[], int qtdNums) {
    srand(time(NULL));
    for (int i = 0; i < qtdNums; i++) {
        vetorInt[i] = rand() % 1000;
    }
}

// Faz a troca entre dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Particiona o vetor e retorna o índice do pivô
int particiona(int vetor[], int esquerda, int direita, size_t *compChaves) {
    int pivo = vetor[esquerda]; // Escolhe o primeiro elemento como pivô
    int i = esquerda + 1;
    int j = direita;

    while (1) {
        while (i <= direita && vetor[i] < pivo) {
            i++;
            (*compChaves)++; // Incrementa a contagem de comparações
        }
        
        while (j >= esquerda && vetor[j] > pivo) {
            j--;
            (*compChaves)++; // Incrementa a contagem de comparações
        }

        if (i >= j) { // Índices se cruzaram
            (*compChaves)++; // Incrementa a contagem de comparações
            break;
        }
        troca(&vetor[i], &vetor[j]); // Troca os elementos fora do lugar
    }

    troca(&vetor[esquerda], &vetor[j]); // Coloca o pivô na posição correta
    return j; // Retorna o índice do pivô
}

// Função principal do QuickSort
void quicksort(int vetor[], int esquerda, int direita, size_t *compChaves) {
    if (esquerda < direita) { // Condição de parada
        (*compChaves)++; // Incrementa a contagem de comparações
        int pivo = particiona(vetor, esquerda, direita, compChaves);
        quicksort(vetor, esquerda, pivo - 1, compChaves); // Ordena à esquerda
        quicksort(vetor, pivo + 1, direita, compChaves); // Ordena à direita
    }
}

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], double tempoUsuario, double tempoSistema, size_t compChaves) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s: %s\n", nomeArquivo, strerror(errno));
        return 1;
    }

    fprintf(arquivo, "Quantidade de comparações de chaves: %zu\n", compChaves);
    fprintf(arquivo, "Tempo de usuário: %.6f segundos\n", tempoUsuario);
    fprintf(arquivo, "Tempo de sistema: %.6f segundos\n", tempoSistema);
    fprintf(arquivo, "Tempo total: %.6f segundos\n\n", tempoUsuario + tempoSistema);

    fclose(arquivo);
}