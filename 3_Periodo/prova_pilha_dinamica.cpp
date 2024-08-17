#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct{
    TipoApontador Fundo, Topo;
    int Tamanho;
}TipoPilha;

void FPVazia(TipoPilha *Pilha){
    Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha){
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TipoItem x, TipoPilha *Pilha){
    TipoApontador Aux;
    Aux = (TipoApontador) malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item){
    TipoApontador q;
    if(Vazia(*Pilha)){
        printf("Erro: Pilha vazia\n");
        return;
    }
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}

void exibePilha(TipoPilha pilha){
    TipoApontador aux = pilha.Topo->Prox;
    while(aux != NULL){
        printf("\n%d", aux->Item.chave);
        aux = aux->Prox;
    }
}
void FuraPilha(TipoPilha *pilha, TipoApontador p, TipoItem item){
    /*insere um item recebido apos a posição apontada por p*/
    TipoApontador aux;
    aux = (TipoApontador) malloc(sizeof(TipoCelula));
    aux->Item = item;
    aux->Prox = p->Prox;
    p->Prox = aux;
    pilha->Tamanho++;
}

int main(){
    //testar a função FuraPilha
    TipoPilha pilha;
    TipoItem item;
    TipoApontador aux;
    FPVazia(&pilha);
    item.chave = 1;
    Empilha(item, &pilha);
    item.chave = 2;
    Empilha(item, &pilha);
    item.chave = 3;
    Empilha(item, &pilha);
    item.chave = 4;
    Empilha(item, &pilha);
    item.chave = 5;
    Empilha(item, &pilha);
    item.chave = 6;
    aux = pilha.Topo->Prox->Prox->Prox;
    FuraPilha(&pilha, aux, item);
    exibePilha(pilha);
    return 0;
}