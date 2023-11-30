#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 100
#define MAX_CARACTERES 50


FILE *arquivo1, *arquivo2;

void escreverNomesArquivo(char *nome) {
    if ((arquivo2 = fopen("nomes2.txt", "a+b")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo2);
        return;
    }

    fprintf(arquivo2, "%s\n", nome);

    fclose(arquivo2);
}

void lerNomesArquivo(char nomes[MAX_NOMES][MAX_CARACTERES], int *numNomes) {
    if ((arquivo1 = fopen("nomes.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo1);
        return;
    }

    rewind(arquivo1);

    *numNomes = 0;
    while ((*numNomes < MAX_NOMES) && (fscanf(arquivo1, "%s", nomes[*numNomes]) == 1)) {
        (*numNomes)++;
    }

    fclose(arquivo1);
}



int main() {
    char nomes[MAX_NOMES][MAX_CARACTERES];
    char vetorNomes[MAX_NOMES][MAX_CARACTERES];
    int numNomesVetor = 0;
    int numNomesArquivo1 = 0;

    lerNomesArquivo(nomes, &numNomesArquivo1);

    printf("Digite os nomes no vetor (digite 0 para encerrar):\n");
    while (scanf("%s", vetorNomes[numNomesVetor]) == 1 && strcmp(vetorNomes[numNomesVetor], "0") != 0) {
        numNomesVetor++;
    }

    for (int i = 0; i < numNomesArquivo1; i++) {
        int encontrado = 0;
        for (int j = 0; j < numNomesVetor; j++) {
            if (strcmp(nomes[i], vetorNomes[j]) == 0) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            escreverNomesArquivo(nomes[i]);
        }
    }

}