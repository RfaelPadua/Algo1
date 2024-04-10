#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct TipoItem{
    int codigo;
    char descrição[50];
    float valor;
};

typedef struct TipoCelula *TipoApontador;

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

void Insere(TipoItem x, TipoLista *Lista){
    Lista->ultimo->Prox = (TipoApontador) malloc(sizeof(struct TipoCelula));
    Lista->ultimo = Lista->ultimo->Prox;
    Lista->ultimo->item = x;
    Lista->ultimo->Prox = NULL;
}

void retira(int p, TipoLista *Lista, TipoItem *Item){
    TipoApontador Aux, AuxAnt;
    AuxAnt = Lista->primeiro;
    Aux = Lista->primeiro->Prox;
    while(Aux != NULL && Aux->item.codigo != p){
        AuxAnt = Aux;
        Aux = Aux->Prox;
    }
    if(Aux == NULL || Aux->item.codigo != p){
        printf("Item não encontrado\n");
        return;
    }
    *Item = Aux->item;
    AuxAnt->Prox = Aux->Prox;
    free(Aux);
}

void Imprime(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.primeiro->Prox;
    while(Aux != NULL){
        printf("Codigo: %d\n", Aux->item.codigo);
        printf("Descricao: %s\n", Aux->item.descrição);
        printf("Valor: %.2f\n\n", Aux->item.valor);
        Aux = Aux->Prox;
    }
}

void InsereItem(TipoItem *Item){
    printf("Digite o código: ");
    scanf("%d", &Item->codigo);
    printf("Digite a descrição: ");
    scanf("%s", Item->descrição);
    printf("Digite o valor: ");
    scanf("%f", &Item->valor);
}

void populaLista(TipoLista *Lista){
    TipoItem Item;

    for(int i = 0; i < 10; i++){
        Item.codigo = i;
        sprintf(Item.descrição, "Item %d", i);
        Item.valor = i * 10.0;
        Insere(Item, Lista);
    }

}

void buscar(TipoLista *Lista, int codigo){
    TipoApontador Aux;
    Aux = Lista->primeiro->Prox;
    while(Aux != NULL && Aux->item.codigo != codigo){
        Aux = Aux->Prox;
    }
    if(Aux == NULL || Aux->item.codigo != codigo){
        printf("Item não encontrado\n");
        return;
    }
    printf("Codigo: %d\n", Aux->item.codigo);
    printf("Descricao: %s\n", Aux->item.descrição);
    printf("Valor: %.2f\n\n", Aux->item.valor);
}

void soma(TipoLista *Lista){
    TipoApontador Aux;
    Aux = Lista->primeiro->Prox;
    float soma = 0;
    while(Aux != NULL){
        soma += Aux->item.valor;
        Aux = Aux->Prox;
    }
    printf("Soma dos valores: %.2f\n", soma);
}





int main(){
    
    TipoLista Lista;
    FazerListaVazia(&Lista);

    populaLista(&Lista);

    while(1){
        TipoItem Item;
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("4 - Buscar por codigo\n");
        printf("5 - Retornar soma dos valores\n");
        printf("0 - Sair\n");
        int opcao;
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                InsereItem(&Item);
                break;
            case 2:
                int codigo;
                printf("Digite o codigo do item a ser removido: ");
                scanf("%d", &codigo);
                retira(codigo, &Lista, &Item);
                break;
            case 3:
                Imprime(Lista);
                break;
            case 4:
                printf("Digite o codigo do item a ser buscado: ");
                scanf("%d", &codigo);
                buscar(&Lista, codigo);
                break;
            case 5:
                soma(&Lista);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("Opção inválida\n");
        }
        system("pause");
        system("cls");
    }
}