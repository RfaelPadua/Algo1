#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    char chave;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{
    TipoItem item;
    TipoApontador Prox;
}TipoCelula;

typedef struct{
    TipoApontador Topo, Fundo;
    int tamanho;
}TipoPilha;

void FPVazia(TipoPilha *pilha);

int main(){
    TipoItem item;
    TipoPilha pilha;
    FPVazia(&pilha);
    
}

void FPVazia(TipoPilha *pilha){
    pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
    pilha->Fundo = pilha->Topo;
    pilha->Topo->Prox = 0;
    pilha->tamanho = 0;
}





