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

void FazerListaVazia(TipoLista *Lista);

void inserir(TipoItem x, TipoLista *Lista);

void populaLista(TipoLista *Lista);

TipoCelula* EncontrarCarroPorCodigo(TipoLista *Lista, int codigo);

TipoCelula* EncontrarCarroPorDescricao(TipoLista *Lista, char* descricao);

int main(){
    
    TipoLista Lista;
    FazerListaVazia(&Lista);

    populaLista(&Lista);


    while(1){
        printf("1-A\n");
        printf("2-B\n");
        printf("0-Sair\n");

        int op;
        scanf("%d", &op);

        if(op == 0){
            printf("Saindo...\n");
            system("pause");
            return 0;
        }else if(op == 1){
            int codigo;
            printf("Digite o codigo do carro: ");

            scanf("%d", &codigo);
            TipoCelula* carro = EncontrarCarroPorCodigo(&Lista, codigo);
            if(carro != NULL){
                printf("Carro encontrado: %s\n", carro->item.descricao);
            }else{
                printf("Carro nao encontrado\n");
            }
        }else if(op == 2){
            char straux[7];
            printf("Digite a descriao do carro:\n");
            scanf("%s", straux);
            TipoCelula* carro = EncontrarCarroPorDescricao(&Lista, straux);
            if(carro != NULL){
                printf("Carro encontrado: %d\n", carro->item.codigo);
            }else{
                printf("Carro nao encontrado!\n");
            }
        }else if(op == 3){

        }else{
            printf("Opcao invalida\n");
        } 

        system("pause");
        system("cls");
    }


  
}

void FazerListaVazia(TipoLista *Lista){
    Lista->primeiro = (TipoApontador) malloc(sizeof(struct TipoCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->Prox = NULL;
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

TipoCelula* EncontrarCarroPorDescricao(TipoLista *Lista, char* descricao){
    TipoCelula* celulaAtual = Lista->primeiro;
    while(celulaAtual != NULL){
        if(strcmp(celulaAtual->item.descricao, descricao)){
            return celulaAtual;
        }
        celulaAtual = celulaAtual->Prox;
    }
    return NULL;
}













