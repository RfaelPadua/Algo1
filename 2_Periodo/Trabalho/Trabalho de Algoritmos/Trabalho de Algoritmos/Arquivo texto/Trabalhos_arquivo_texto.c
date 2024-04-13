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
    while ((*numNomes < MAX_NOMES) && (fgets(nomes[*numNomes], MAX_CARACTERES, arquivo1) != NULL)) {
		(*numNomes)++;
    }

    fclose(arquivo1);
}

void escreverNomesArquivo(char nome[MAX_NOMES][MAX_CARACTERES], int cont) {
    FILE *arquivo2;
    int i;

    if ((arquivo2 = fopen(ARQUIVO_SAIDA, "w")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO_SAIDA);
    }

    rewind(arquivo2);

    for(i = 0; i < cont; i++){
        fprintf(arquivo2, "%s\n", nome[i]);
    }

    fclose(arquivo2);
}


int main() {
    char nomes[MAX_NOMES][MAX_CARACTERES]; //Matriz que reber� os nomes do arquivo 1
    char vetorNomes[MAX_NOMES][MAX_CARACTERES]; //Vetor de strings preenchido com os nomes inseridos pelo usu�rio
    char nomes2[MAX_NOMES][MAX_CARACTERES]; //Vetor de structs no qual estar�o os nomes de arquivo 1 que n�o est�o no vetor informado pelo us�rio
    int numNomesVetor = 0;
    int numNomesArquivo1 = 0;
    int i, j, auxiliar = 1;
    
    char nomes_aux[MAX_CARACTERES]; //Vetor auxiliar

    lerNomesArquivo(nomes, &numNomesArquivo1);

    printf("Digite os nomes no vetor (digite 0 para encerrar):\n");
    while (auxiliar != 0) {
    	//Recebendo um nome
    	fgets(nomes_aux, MAX_CARACTERES, stdin);
    	
    	if(strcmp(nomes_aux, "0\n") == 0){
    		auxiliar = 0;
		} else{
			strcpy(vetorNomes[numNomesVetor], nomes_aux);
			numNomesVetor++;
		}
    }
    
    int cont = 0, aux = 0, aux2;

    for(i = 0; i < numNomesArquivo1; i++){
        for(j = 0; j < numNomesVetor; j++){
        	aux2 = strcmp(nomes[i], vetorNomes[j]);
        	if(aux2 == 0){
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
    
    for(i = 0; i < cont; i++){
    	printf("\nNome: %s", nomes2[i]);
	}
    escreverNomesArquivo(nomes2, cont);

    printf("Nomes foram escritos no arquivo 'nomes_saida.txt'.\n");

    return 0;
}
