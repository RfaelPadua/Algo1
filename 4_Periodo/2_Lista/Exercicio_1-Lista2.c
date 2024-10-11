#include <stdio.h>
#include <stdlib.h>

int BuscaSequencial(int vetor[], int tamanho, int chave);


int main(){
    int vetor[] = {10, 12, 11, 6, 7, 8, 3, 4, 2, 1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int chave = 20;

    int resultado = BuscaSequencial(vetor,tamanho, chave);

    if(resultado == 1){
        printf("O numero %d esta presente no vetor\n", chave);
    }else{
        printf("O numero %d nao esta presente no vetor\n", chave);
    }

    return 0;
}

int BuscaSequencial(int vetor[], int tamanho, int chave){

    int i;

    for(i = 0; i < tamanho; i++){
        if(vetor[i] == chave){
            return 1;
        }
    }

    return 0;

}