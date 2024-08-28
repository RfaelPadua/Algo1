#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    char chave;
    int ano;
    float valor;
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

void FPVazia(TipoPilha *pilha){
    pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
    pilha->Fundo = pilha->Topo;
    pilha->Topo->Prox = 0;
    pilha->tamanho = 0;
}

int pilhaVazia(TipoPilha *pilha){
    return (pilha->Topo == pilha->Fundo);
}



int pilhaIgual(TipoPilha *pilha1, TipoPilha *pilha2){
    if(!(pilhaVazia(pilha1) && pilhaVazia(pilha2))){
        printf("Pilhas vazias\n");
        return 0;
    }
    if(pilha1->tamanho != pilha2->tamanho){
        return 0;
    }
    TipoApontador aux1 = pilha1->Topo->Prox;
    TipoApontador aux2 = pilha2->Topo->Prox;
    while(aux1 != NULL && aux2 != NULL){
        if(aux1->item.chave != aux2->item.chave || 
           aux1->item.ano != aux2->item.ano || 
           aux1->item.valor != aux2->item.valor){

            return 0;
        }

        aux1 = aux1->Prox;
        aux2 = aux2->Prox;
    }
    
}


int main(){

}