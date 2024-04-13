#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct TipoItem{
    int codigo;
    char descricao[7];
    float valor;
};

typedef struct TipoCelula* TipoApontador;

struct TipoCelula{
    TipoItem item;
    TipoApontador Prox;
};

struct TipoLista{
    TipoApontador primeiro, ultimo;
};

void FazerListaVazia(TipoLista *Lista){
    Lista->primeiro = (TipoApontador) malloc(sizeof(struct TipoCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->Prox = NULL;
}

void InserirAntes(TipoItem x, TipoApontador p, TipoLista *Lista){
    TipoApontador aux = (TipoApontador) malloc(sizeof(struct TipoCelula));

    
    
    while(p->Prox != NULL){
        if(p->item.codigo == x.codigo){
            aux->item = x;
            aux->Prox = p->Prox;
            p->Prox = aux;
            return;
        }
        p = p->Prox;
    }
}

void inserir(TipoItem x, TipoLista *Lista){
    Lista->ultimo->Prox = (TipoApontador) malloc(sizeof(struct TipoCelula));
    Lista->ultimo = Lista->ultimo->Prox;
    Lista->ultimo->item = x;
    Lista->ultimo->Prox = NULL;
}

void populaLista(TipoLista *Lista){
    TipoItem Item;

    for(int i = 0; i < 10; i++){
        Item.codigo = i;
        sprintf(Item.descricao, "Item %d", i);
        Item.valor = i * 10.0;
        inserir(Item, Lista);
    }

}



int main(){
    
    TipoLista Lista;
    FazerListaVazia(&Lista);

    populaLista(&Lista);

    TipoItem Item;
    Item.codigo = 10;
    sprintf(Item.descricao, "Item %d", 10);
    Item.valor = 10 * 10.0;

    TipoApontador p = Lista.primeiro;

    InserirAntes(Item, p, &Lista);
   
  
}