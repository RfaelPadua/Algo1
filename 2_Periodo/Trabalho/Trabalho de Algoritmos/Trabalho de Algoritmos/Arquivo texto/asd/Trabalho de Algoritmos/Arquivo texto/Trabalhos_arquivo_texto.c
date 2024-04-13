/* 	- TRABALHO DE ALGORITMOS II - Parte do arquivo Texto
	- ALUNOS:
		. Gabriel Silva Xavier;
		. Rafael de P�dua Oliveira.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 100
#define MAX_CARACTERES 50
#define ARQUIVO_ENTRADA "nomes_entrada.txt"
#define ARQUIVO_SAIDA "nomes_saida.txt"


void lerNomesArquivo(char nomes[MAX_NOMES][MAX_CARACTERES], int *numNomes) { //Fun��o que l� os nomes do arquivo e os atribui a um vetor de strings para ser trabalhado
    FILE *arquivo1;
    
    if ((arquivo1 = fopen(ARQUIVO_ENTRADA, "r")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO_ENTRADA);
        return;
    }

    rewind(arquivo1);

    *numNomes = 0; //Contador que contar� a quantidade de nomes do arquivo
    while ((*numNomes < MAX_NOMES) && (fgets(nomes[*numNomes], MAX_CARACTERES, arquivo1) != NULL)) { //Verificando se n�o extrapola a quantidade m�xima e j� atribuindo
		(*numNomes)++;
    }

    fclose(arquivo1);
}

void escreverNomesArquivo(char nome[MAX_NOMES][MAX_CARACTERES], int cont) { //Fun��o que escreve no arquivo2 os nomes do arquivo1 que n�o foram informados no vetor de strings pelo usu�rio
    FILE *arquivo2;
    int i;

    if ((arquivo2 = fopen(ARQUIVO_SAIDA, "w")) == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO_SAIDA);
    }

    rewind(arquivo2);

    for(i = 0; i < cont; i++){ //Escrevendo os nomes no arquivo
        fprintf(arquivo2, "%s", nome[i]);
    }

    fclose(arquivo2);
}


int main() {
    char nomes[MAX_NOMES][MAX_CARACTERES]; //Matriz que reber� os nomes do arquivo 1
    char vetorNomes[MAX_NOMES][MAX_CARACTERES]; //Vetor de strings preenchido com os nomes inseridos pelo usu�rio
    char nomes2[MAX_NOMES][MAX_CARACTERES]; //Vetor de structs no qual estar�o os nomes de arquivo 1 que n�o est�o no vetor informado pelo us�rio
    int numNomesVetor = 0; //Vari�vel que ir� representar a quantidade de nomes cadastrados no vetor de structs
    int numNomesArquivo1 = 0; //Vari�vel que ir� representar a quantidade de nomes cadastrados no arquivo1
    int i, j, auxiliar = 1; //Vari�veis auxiliares
    
    char nomes_aux[MAX_CARACTERES]; //Vetor auxiliar que recebe uma string pelo usu�rio

    lerNomesArquivo(nomes, &numNomesArquivo1);//Fun��o que recebe os nomes que est�o em arquivo1

    printf("Digite os nomes no vetor (digite 0 para encerrar):\n");
    while (auxiliar != 0) {
    	//Recebendo um nome pelo usu�rio
    	fgets(nomes_aux, MAX_CARACTERES, stdin);
    	
    	if(strcmp(nomes_aux, "0\n") == 0){ //Verificando se acaso o usu�rio quer parar de informar mais nomes
    		auxiliar = 0;
		} else{ //Caso n�o, esse nome que ele informou � atribuido ao vetor de strings para ser trabalhado
			strcpy(vetorNomes[numNomesVetor], nomes_aux);
			numNomesVetor++;
		}
    }
    
    int cont = 0, aux = 0, aux2; //Vari�veis auxiliares

	//Atribuindo a um vetor de strings auxiliar os nomes que est�o em arquivo1 mas n�o est�o dentre os nomes que o usu�rio informou no primeiro vetor de strings
    for(i = 0; i < numNomesArquivo1; i++){ //'for' que percorrer� cada um dos nomes que est�o no arquivo1 (por meio do vetor de strings
        for(j = 0; j < numNomesVetor; j++){ //'for' que percorrer� o vetor de strings com os nomes que usu�rio informou
        	aux2 = strcmp(nomes[i], vetorNomes[j]);
        	
        	if(aux2 == 0){ //Verifica se os nomes s�o iguais
                aux = 1;
                break;
            }
        }
        if(aux == 0){ //Atribuindo ao segundo vetor de strings os nomes que do arquivo que n�o est�o no vetor de strings informado pelo usu�rio
            strcpy(nomes2[cont], nomes[i]);
            cont++;
        }
        aux = 0;
    }
    
    escreverNomesArquivo(nomes2, cont); //Fun��o que gravar� no arquivo2 os nomes que foram filtrados e atribuidos ao vetor de strings auxiliar
    
    printf("\n.Nomes foram escritos no arquivo 'nomes_saida.txt'.\n");

    return 0;
}
