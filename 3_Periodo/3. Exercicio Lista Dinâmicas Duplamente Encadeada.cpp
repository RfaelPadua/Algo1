#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char descricao[50];
    float valor;
} TipoItem;

typedef struct TipoCelula *Apontador;

typedef struct TipoCelula {
    TipoItem item;
    Apontador Prox;
    Apontador Ant;
} TipoCelula;

typedef struct {
    Apontador primeiro;
    Apontador ultimo;
} TipoLista;

void CriarLista(TipoLista *Lista) {
    Lista->primeiro = NULL;
    Lista->ultimo = NULL;
}

void InserirFinal(TipoItem x, TipoLista *Lista) {
    Apontador aux = (Apontador) malloc(sizeof(TipoCelula));
    aux->item = x;
    aux->Prox = NULL;
    if (Lista->primeiro == NULL) {
        aux->Ant = NULL;
        Lista->primeiro = aux;
    } else {
        aux->Ant = Lista->ultimo;
        Lista->ultimo->Prox = aux;
    }
    Lista->ultimo = aux;
}

void AlterarElemento(Apontador p, TipoItem x, TipoLista *Lista) {
    if (p != NULL) {
        p->item = x;
    }
}

void ExcluirElemento(Apontador p, TipoLista *Lista) {
    if (p != NULL) {
        if (p->Ant != NULL) {
            p->Ant->Prox = p->Prox;
        } else {
            Lista->primeiro = p->Prox;
        }
        if (p->Prox != NULL) {
            p->Prox->Ant = p->Ant;
        } else {
            Lista->ultimo = p->Ant;
        }
        free(p);
    }
}

void ExibirLista(TipoLista *Lista, int ordem) {
    Apontador p;
    if (ordem == 1) { // Do primeiro para o último
        p = Lista->primeiro;
        while (p != NULL) {
            printf("%d ", p->item.codigo);
            p = p->Prox;
        }
    } else { // Do último para o primeiro
        p = Lista->ultimo;
        while (p != NULL) {
            printf("%d ", p->item.codigo);
            p = p->Ant;
        }
    }
    printf("\n");
}

void InserirAposP(Apontador p, TipoItem x, TipoLista *Lista) {
    if (p != NULL) {
        Apontador aux = (Apontador) malloc(sizeof(TipoCelula));
        aux->item = x;
        aux->Prox = p->Prox;
        aux->Ant = p;
        if (p->Prox != NULL) {
            p->Prox->Ant = aux;
        } else {
            Lista->ultimo = aux;
        }
        p->Prox = aux;
    }
}

int main(){
    TipoLista Lista;
    CriarLista(&Lista);

    TipoItem Item;
    for (int i = 0; i < 10; i++) {
        Item.codigo = i;
        sprintf(Item.descricao, "Item %d", i);
        Item.valor = i * 10.0;
        InserirFinal(Item, &Lista);
    }

    printf("1. Exibir lista do primeiro para o último\n");
    printf("2. Exibir lista do último para o primeiro\n");
    printf("3. Alterar elemento\n");
    printf("4. Excluir elemento\n");
    printf("5. Inserir após um elemento\n");
    printf("6. Sair\n");
    int opcao;
    do {
        printf("Opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                ExibirLista(&Lista, 1);
                break;
            case 2:
                ExibirLista(&Lista, 2);
                break;
            case 3:
                printf("Código do elemento a ser alterado: ");
                int codigo;
                scanf("%d", &codigo);
                Apontador p = Lista.primeiro;
                while (p != NULL && p->item.codigo != codigo) {
                    p = p->Prox;
                }
                if (p != NULL) {
                    printf("Novo código: ");
                    scanf("%d", &Item.codigo);
                    printf("Nova descrição: ");
                    scanf(" %[^\n]", Item.descricao);
                    printf("Novo valor: ");
                    scanf("%f", &Item.valor);
                    AlterarElemento(p, Item, &Lista);
                } else {
                    printf("Elemento não encontrado\n");
                }
                break;
            case 4:
                printf("Código do elemento a ser excluído: ");
                scanf("%d", &codigo);
                p = Lista.primeiro;
                while (p != NULL && p->item.codigo != codigo) {
                    p = p->Prox;
                }
                ExcluirElemento(p, &Lista);
                break;
            case 5:
                printf("Código do elemento após o qual o novo elemento será inserido: ");
                scanf("%d", &codigo);
                p = Lista.primeiro;
                while (p != NULL && p->item.codigo != codigo) {
                    p = p->Prox;
                }
                if (p != NULL) {
                    printf("Código do novo elemento: ");
                    scanf("%d", &Item.codigo);
                    printf("Descrição do novo elemento: ");
                    scanf(" %[^\n]", Item.descricao);
                    printf("Valor do novo elemento: ");
                    scanf("%f", &Item.valor);
                    InserirAposP(p, Item, &Lista);
                } else {
                    printf("Elemento não encontrado\n");
                }
                break;
            case 6:
                break;
            default:
                printf("Opção inválida\n");
        }
        system("pause");
        system("cls");
    } while (opcao != 6);
}