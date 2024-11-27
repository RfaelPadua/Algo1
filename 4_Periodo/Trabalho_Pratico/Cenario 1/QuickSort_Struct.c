#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/resource.h>

//--------------------------------------------------------------------------

typedef struct Registro {
    int chave;
    char string [10][200];
    bool booleano;
    float real [4];
} Registro;

//--------------------------------------------------------------------------

// Preenche o vetor com valores aleatórios
void preencherRegistroAleatorio(Registro r[], int qtdNums);

// Faz a troca entre dois elementos
void troca(Registro *a, Registro *b);

// Particiona o vetor e retorna o índice do pivô
int particiona(Registro r[], int esquerda, int direita, unsigned long long int *compChaves);

// Função principal do QuickSort
void quicksort(Registro r[], int esquerda, int direita, unsigned long long int *compChaves);

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], char argumentos[], double tempoUsuario, double tempoSistema, unsigned long long int compChaves); 

//--------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    struct rusage inicio, fim; // Estruturas para analisar o uso de CPU
    unsigned long long int compChaves = 0; // Quantidade de comparações de chaves

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

    Registro *registro = (Registro *)malloc(sizeof(Registro) * qtdNums); // Declara o registro e aloca o espaco necessário

    if(registro == NULL) { // Erro de alocacao de memoria
        perror("Erro de alocacao de memoria\n");
        return 1;
    }

    preencherRegistroAleatorio(registro, qtdNums); // Preenche o vetor com valores aleatórios

    // Obtém o tempo antes da execução do quicksort
    if (getrusage(RUSAGE_SELF, &inicio) != 0) { // Erro de recebimento das informações
        perror("Erro durante a obtencao das informacoes\n");
        free(registro);
        return 1;
    }

    quicksort(registro, 0, qtdNums - 1, &compChaves); // Ordena o vetor

    // Obtém o tempo após a execução do quicksort
    if (getrusage(RUSAGE_SELF, &fim) != 0) { // Erro de recebimento das informações
        perror("Erro durante a obtencao das informacoes\n");
        free(registro);
        return 1;
    }

    //verificar ordenação
    for (int i = 0; i < qtdNums - 1; i++) {
        if (registro[i].chave > registro[i + 1].chave) {
            printf("Erro: Vetor nao ordenado\n");
            free(registro);
            return 1;
        }
    }

    // Calcula o tempo de CPU gasto (segundos)
    double tempoUsuario = (fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) + (fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1e6;
    double tempoSistema = (fim.ru_stime.tv_sec - inicio.ru_stime.tv_sec) + (fim.ru_stime.tv_usec - inicio.ru_stime.tv_usec) / 1e6;

    resultadosArquivo(nomeArquivo, argv[1], tempoUsuario, tempoSistema, compChaves); // Insere os valores no arquivo

    free(registro);

    return 0;
}

//--------------------------------------------------------------------------

// Preenche o vetor com valores aleatórios
void preencherRegistroAleatorio(Registro r[], int qtdNums) {
    srand(time(NULL));

    // Preenche as chaves
    for (int i = 0; i < qtdNums; i++) {
        r[i].chave = rand() % 1000; // Gera chaves entre 0 e 999
    }

    // Preenche as strings
    for (int i = 0; i < qtdNums; i++) {
        for (int j = 0; j < 10; j++) {
            int tamanho = (rand() % 191) + 10; // Define o tamanho aleatório entre 10 e 200
            for (int k = 0; k < tamanho - 1; k++) { // Último índice será para '\0'
                if (k == 0) { // Primeira letra maiúscula
                    r[i].string[j][k] = (rand() % 26) + 'A';
                } else { // Letras subsequentes minúsculas
                    r[i].string[j][k] = (rand() % 26) + 'a';
                }
            }
            r[i].string[j][tamanho - 1] = '\0'; // Adiciona o terminador '\0'
        }
    }

    // Preenche os booleanos
    for (int i = 0; i < qtdNums; i++) {
        r[i].booleano = rand() % 2; // Booleano aleatório (0 ou 1)
    }

    // Preenche os valores reais
    for (int i = 0; i < qtdNums; i++) {
        for (int j = 0; j < 4; j++) {
            float dividendo = (float)(rand() % 1000 + 1); // Evita zero no divisor
            float divisor = (float)(rand() % 1000 + 1);   // Evita zero no divisor
            r[i].real[j] = dividendo / divisor;
        }
    }
}

// Faz a troca entre dois elementos
void troca(Registro *a, Registro *b) {
    Registro temp;

    // Troca as chaves
    temp.chave = a->chave;
    a->chave = b->chave;
    b->chave = temp.chave;

    // Troca as strings
    for (int i = 0; i < 10; i++) {
        strcpy(temp.string[i], a->string[i]);
        strcpy(a->string[i], b->string[i]);
        strcpy(b->string[i], temp.string[i]);
    }

    // Troca os booleanos
    temp.booleano = a->booleano;
    a->booleano = b->booleano;
    b->booleano = temp.booleano;

    // Troca os valores reais
    for (int i = 0; i < 4; i++) {
        temp.real[i] = a->real[i];
        a->real[i] = b->real[i];
        b->real[i] = temp.real[i];
    }
}

// Particiona o vetor e retorna o índice do pivô
int particiona(Registro r[], int esquerda, int direita, unsigned long long int *compChaves) {
    int pivo = r[esquerda].chave; // Escolhe o primeiro elemento como pivô
    int i = esquerda + 1;
    int j = direita;

    while (1) {
        while (i <= j && r[i].chave <= pivo) {
            i++;
            (*compChaves)++; // Incrementa a contagem de comparações
        }
        
        while (j >= i && r[j].chave >= pivo) {
            j--;
            (*compChaves)++; // Incrementa a contagem de comparações
        }

        if (i >= j) { // Índices se cruzaram
            break;
        }
        troca(&r[i], &r[j]); // Troca os elementos fora do lugar
    }

    troca(&r[esquerda], &r[j]); // Coloca o pivô na posição correta
    return j; // Retorna o índice do pivô
}

// Função principal do QuickSort
void quicksort(Registro r[], int esquerda, int direita, unsigned long long int *compChaves) {
    if (esquerda < direita) { // Condição de parada
        int pivo = particiona(r, esquerda, direita, compChaves);
        quicksort(r, esquerda, pivo - 1, compChaves); // Ordena à esquerda
        quicksort(r, pivo + 1, direita, compChaves); // Ordena à direita
    }
}

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], char argumentos[], double tempoUsuario, double tempoSistema, unsigned long long int compChaves) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s: %s\n", nomeArquivo, strerror(errno));
        return;
    }

    fprintf(arquivo, "Quantidade de itens: %s\n", argumentos);
    fprintf(arquivo, "Quantidade de comparações de chaves: %llu\n", compChaves);
    fprintf(arquivo, "Tempo de usuário: %.6f segundos\n", tempoUsuario);
    fprintf(arquivo, "Tempo de sistema: %.6f segundos\n", tempoSistema);
    fprintf(arquivo, "Tempo total: %.6f segundos\n\n", tempoUsuario + tempoSistema);

    fclose(arquivo);
}