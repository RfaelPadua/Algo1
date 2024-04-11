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

void inserir(TipoItem x, TipoLista *Lista){
    if(Lista->primeiro == Lista->ultimo){
        Lista->ultimo->item = x;
        Lista->ultimo->Prox = NULL;
        return;
    }
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

TipoCelula* EncontrarCarroPorCodigo(TipoLista *Lista, int codigo){
    TipoCelula* celulaAtual = Lista->primeiro;
    while(celulaAtual != NULL){
        if(celulaAtual -> item.codigo == codigo){
            return celulaAtual;
        }
        celulaAtual = celulaAtual -> Prox;
    }
    return NULL;
}

int main(){
    
    TipoLista Lista;
    FazerListaVazia(&Lista);

    populaLista(&Lista);
    int codigo = 4;
    TipoCelula* carro = EncontrarCarroPorCodigo(&Lista, codigo);
    if(carro != NULL){
        printf("Carro encontrado: %s\n", carro->item.descricao);
    }else{
        printf("Carro nao encontrado\n");
    }


    

    system("pause");
    system("cls");
  
}