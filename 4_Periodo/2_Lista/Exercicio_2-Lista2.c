#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int vetor[], int tamanho, int chave);

int main(){
    int vetor[] = {1, 2, 3, 4, 6, 7, 8, 10, 10, 12, 15, 17, 19, 20, 21};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int resultado;
    int chave = 20;

    resultado = BuscaBinaria(vetor, tamanho, chave);

    if(resultado){
        printf("O numero %d esta no vetor\n", chave);
    }else{
        printf("O numero %d nao esta no vetor\n", chave);
    }

}

int BuscaBinaria(int vetor[], int tamanho, int chave){
    int inicio, fim, m;

    inicio = 0;
    fim = tamanho;


    

    while(inicio <= fim){
        m = (inicio + fim)/2;

        if(vetor[m] == chave){
            return 1;
        }else if(chave < vetor[m]){
            fim = m - 1;
        }else{
            inicio = m + 1;
        }
    }

    return 0;
}