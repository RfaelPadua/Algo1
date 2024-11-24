#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/resource.h>

//--------------------------------------------------------------------------

// Preenche o vetor com valores aleatórios
void preencherVetorAleatorio(int vetorInt[], int qtdNums);

// Faz a troca entre dois elementos
void troca(int *a, int *b);

// Particiona o vetor e retorna o índice do pivô
int particiona(int vetor[], int esquerda, int direita, size_t *compChaves);

// Função principal do QuickSort
void quicksort(int vetor[], int esquerda, int direita, size_t *compChaves);

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], double tempoUsuario, double tempoSistema, size_t compChaves);

//--------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    struct rusage inicio, fim; // Estruturas para analisar o uso de CPU
    size_t compChaves = 0; // Quantidade de comparações de chaves

    if (argc != 3) { // Informações recebidas fora do padrão
        printf("Uso: %s <quantidade> <arquivo>\n", argv[0]);
        return 1;
    }

    char *nomeArquivo = argv[2];
    char *ptrFim;
    long int qtdNums = strtol(argv[1], &ptrFim, 10);

    if (*ptrFim != '\0') { // Erro durante a conversao do valor recebido
        printf("Erro: '%s' nao eh um numero valido\n", argv[1]);
        return 1;
    }

    if (qtdNums <= 0 || qtdNums > INT_MAX) { // Valor fora do intervalo estipulado
        printf("Erro: numero fora do intervalo permitido\n");
        return 1;
    }

    int *vetorInt = (int *)malloc(sizeof(int) * (qtdNums));

    if(vetorInt == NULL) { // Verifica se foi alocado todo o valor
        perror("Erro: falta de memoria para a alocacao\n");
        free(vetorInt);
        return 1;
    }

    preencherVetorAleatorio(vetorInt, qtdNums); // Preenche o vetor com valores aleatórios

    // Obtém o tempo antes da execução do quicksort
    if (getrusage(RUSAGE_SELF, &inicio) != 0) { // Erro de recebimento das informações
        perror("Erro: falha durante a obtencao das informacoes\n");
        free(vetorInt);
        return 1;
    }

    quicksort(vetorInt, 0, qtdNums - 1, &compChaves); // Ordena o vetor

    // Obtém o tempo após a execução do quicksort
    if (getrusage(RUSAGE_SELF, &fim) != 0) { // Erro de recebimento das informações
        perror("Erro: falha durante a obtencao das informacoes\n");
        free(vetorInt);
        return 1;
    }

    // Calcula o tempo de CPU gasto (segundos)
    double tempoUsuario = (fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) + (fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1e6;
    double tempoSistema = (fim.ru_stime.tv_sec - inicio.ru_stime.tv_sec) + (fim.ru_stime.tv_usec - inicio.ru_stime.tv_usec) / 1e6;

    resultadosArquivo(nomeArquivo, tempoUsuario, tempoSistema, compChaves); // Insere os valores no arquivo

    free(vetorInt);

    return 0;
}

//--------------------------------------------------------------------------

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
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s: %s\n", nomeArquivo, strerror(errno));
        exit(1);
    }

    fprintf(arquivo, "Quantidade de comparações de chaves: %zu\n", compChaves);
    fprintf(arquivo, "Tempo de usuário: %.6f segundos\n", tempoUsuario);
    fprintf(arquivo, "Tempo de sistema: %.6f segundos\n", tempoSistema);
    fprintf(arquivo, "Tempo total: %.6f segundos\n\n", tempoUsuario + tempoSistema);

    fclose(arquivo);
}