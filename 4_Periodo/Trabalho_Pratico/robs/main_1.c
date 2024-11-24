#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/resource.h>
#include "auxiliaresc1.h"

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

    if(vetorInt == NULL) {
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
