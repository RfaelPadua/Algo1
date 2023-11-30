#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMES 100
#define MAX_CARACTERES 50

int main() {
    char nomes[MAX_NOMES][MAX_CARACTERES];
    int numNomes;

    // Solicitar ao usuário que insira nomes
    printf("Digite os nomes (digite FIM para encerrar):\n");
    numNomes = 0;
    while (numNomes < MAX_NOMES && scanf("%s", nomes[numNomes]) == 1 && strcmp(nomes[numNomes], "FIM") != 0) {
        numNomes++;
    }

    // Abrir o arquivo para escrita
    FILE *arquivo = fopen("nomes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(EXIT_FAILURE);
    }

    // Escrever nomes no arquivo
    for (int i = 0; i < numNomes; i++) {
        fprintf(arquivo, "%s\n", nomes[i]);
    }

    // Fechar o arquivo
    fclose(arquivo);

    printf("Nomes foram escritos no arquivo 'nomes.txt'.\n");

    return 0;
}