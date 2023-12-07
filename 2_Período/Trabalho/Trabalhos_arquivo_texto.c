#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 100
#define MAX_CARACTERES 50
#define ARQUIVO_ENTRADA "nomes_entrada.txt"
#define ARQUIVO_SAIDA "nomes_saida.txt"


void lerNomesArquivo(char nomes[MAX_NOMES][MAX_CARACTERES], int *numNomes) {
    FILE *arquivo1;
    if ((arquivo1 = fopen(ARQUIVO_ENTRADA, "r")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO_ENTRADA);
        return;
    }

    rewind(arquivo1);

    *numNomes = 0;
    while ((*numNomes < MAX_NOMES) && (fscanf(arquivo1, "%s", nomes[*numNomes]) == 1)) {
        (*numNomes)++;
    }

    fclose(arquivo1);
}

void escreverNomesArquivo(char nome[MAX_NOMES][MAX_CARACTERES], int cont) {
    FILE *arquivo2;
    int i;

    if ((arquivo2 = fopen(ARQUIVO_SAIDA, "w")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO_SAIDA);
        return;
    }

    rewind(arquivo2);

    for(i = 0; i < cont; i++){
        fprintf(arquivo2, "%s\n", nome[i]);
    }

    fclose(arquivo2);
}


int main() {
    char nomes[MAX_NOMES][MAX_CARACTERES];
    char vetorNomes[MAX_NOMES][MAX_CARACTERES];
    char nomes2[MAX_NOMES][MAX_CARACTERES];
    int numNomesVetor = 0;
    int numNomesArquivo1 = 0;
    int i, j; 

    lerNomesArquivo(nomes, &numNomesArquivo1);

    printf("Digite os nomes no vetor (digite 0 para encerrar):\n");
    while (scanf("%s", vetorNomes[numNomesVetor]) == 1 && strcmp(vetorNomes[numNomesVetor], "0") != 0) {
        numNomesVetor++;
    }

    int cont = 0, aux = 0;

    for(int i = 0; i < numNomesArquivo1; i++){
        for(j = 0; j < numNomesVetor; j++){
            if(strcmp(nomes[i], vetorNomes[j]) == 0){
                aux = 1;
                break;
            }
        }
        if(aux == 0){
            strcpy(nomes2[cont], nomes[i]);
            cont++;
        }
        aux = 0;
    }
    escreverNomesArquivo(nomes2, cont);

    printf("Nomes foram escritos no arquivo 'nomes_saida.txt'.\n");

    return 0;
}