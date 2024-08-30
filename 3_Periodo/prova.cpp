#include <stdio.h>
#include <stdlib.h>


#define MAXTAM 30

typedef struct{
    int chave;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct{
    TipoApontador Primeiro, Ultimo;
}TipoLista;

void FLVazia(TipoLista *Lista){//inicializa a lista ou esvazia a lista
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

void insere(TipoItem x, TipoLista *Lista){
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void imprime(TipoLista *Lista){
    TipoApontador Aux;
    Aux = Lista->Primeiro->Prox;
    while(Aux != NULL){
        printf("%d\n", Aux->Item.chave);
        Aux = Aux->Prox;
    }
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){
    TipoApontador Aux;
    if(Vazia(*Lista) || p == NULL || p->Prox == NULL){
        printf("Erro: Lista vazia ou posicao invalida\n");
        return;
    }
    Aux = p->Prox;
    *Item = Aux->Item;
    p->Prox = Aux->Prox;
    if(p->Prox == NULL){
        Lista->Ultimo = p;
    }
    free(Aux);
}

int estaPresente(TipoLista *lista, int x){
    TipoApontador aux=lista->Primeiro->Prox;
    while(aux!=NULL){
        if(aux->Item.chave==x)
            return 1;
        aux=aux->Prox;        
    }
    return 0;
}

void interseccao(TipoLista *lista1, TipoLista *lista2, TipoLista *lista3){
    TipoApontador aux1=lista1->Primeiro->Prox;

    FLVazia(lista3);
    
    while(aux1!=NULL){
        if(estaPresente(lista2, aux1->Item.chave)){
            insere(aux1->Item, lista3);
        }
        aux1=aux1->Prox;
    }
}

int main(){
    TipoLista lista1, lista2, lista3;
    TipoItem item;
    FLVazia(&lista1);
    FLVazia(&lista2);

    item.chave = 1;
    insere(item, &lista1);
    item.chave = 2;
    insere(item, &lista1);
    item.chave = 3;
    insere(item, &lista1);
    item.chave = 4;
    insere(item, &lista1);
    item.chave = 5;
    insere(item, &lista1);

    item.chave = 3;
    insere(item, &lista2);
    item.chave = 4;
    insere(item, &lista2);
    item.chave = 5;
    insere(item, &lista2);
    item.chave = 6;
    insere(item, &lista2);
    item.chave = 7;
    insere(item, &lista2);

    interseccao(&lista1, &lista2 ,&lista3);

    imprime(&lista3);

    return 0;
}