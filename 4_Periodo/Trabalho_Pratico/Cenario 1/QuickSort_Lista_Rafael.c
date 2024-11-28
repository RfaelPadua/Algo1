#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <errno.h>


typedef struct TipoItem {
    int inteiro;
} TipoItem;

typedef struct TipoCelula {
    TipoItem item;
    unsigned long long int indice;
    struct TipoCelula* frente;
    struct TipoCelula* tras;
} TipoCelula;

typedef struct TipoLista {
    TipoCelula* inicio;
    TipoCelula* fim;
    int tamanho;
} TipoLista;

void IniciaLstDup(TipoLista *lista);

int VaziaLstDup(TipoLista lista);

void Inserir(TipoLista *lista, TipoItem item);

void Remover(TipoLista *lista, TipoItem *itemRemovido);

void ExibeLista(TipoLista lista);

void preencherLstDupAleatorio(TipoLista *lista, int qtdNums);

void troca(TipoCelula *a, TipoCelula *b);

TipoCelula* particiona(TipoCelula *esquerda, TipoCelula *direita, unsigned long long int *compChaves);

void quicksort(TipoCelula *esquerda, TipoCelula *direita, unsigned long long int *compChaves);

void ordenarLista(TipoLista *lista, unsigned long long int *compChaves);

int main(){
    TipoLista lista;
    unsigned long long int compChaves;

    IniciaLstDup(&lista);


    preencherLstDupAleatorio(&lista, 10);
    ExibeLista(lista);
    compChaves = 0;
    quicksort(lista.inicio, lista.fim, &compChaves);
    ExibeLista(lista);
    printf("Comparacoes: %llu\n", compChaves);


    return 0;
}


void IniciaLstDup(TipoLista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int VaziaLstDup(TipoLista lista) {
    return lista.inicio == NULL;
}

void Inserir(TipoLista *lista, TipoItem item) {
    TipoCelula *novaCelula = (TipoCelula*) malloc(sizeof(TipoCelula));
    if (novaCelula == NULL) {
        fprintf(stderr, "Erro: Memória insuficiente.\n");
        exit(3);
    }

    novaCelula->item = item;
    novaCelula->indice = lista->tamanho;

    if (VaziaLstDup(*lista)) {
        novaCelula->indice = 0;
        novaCelula->frente = NULL;
        novaCelula->tras = NULL;
        lista->inicio = novaCelula;
        lista->fim = novaCelula;
    } else {
        novaCelula->indice = novaCelula->tras->indice++;
        novaCelula->frente = NULL;
        novaCelula->tras = lista->fim;
        lista->fim->frente = novaCelula;
        lista->fim = novaCelula;
    }

    lista->tamanho++;
}

void Remover(TipoLista *lista, TipoItem *itemRemovido) {
    if (VaziaLstDup(*lista)) {
        fprintf(stderr, "Erro: Lista vazia.\n");
        exit(1);
    }

    TipoCelula *temp = lista->fim;
    *itemRemovido = temp->item;

    if (lista->tamanho == 1) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->fim = temp->tras;
        lista->fim->frente = NULL;
    }

    free(temp);
    lista->tamanho--;
}

void ExibeLista(TipoLista lista) {
    TipoCelula *celula = lista.inicio;
    while (celula != NULL) {
        printf("%d ", celula->item.inteiro);
        celula = celula->frente;
    }
    printf("\n");
}


void preencherLstDupAleatorio(TipoLista *lista, int qtdNums) {
    srand(time(NULL));
    
    for (int i = 0; i < qtdNums; i++) {
        TipoItem item;
        item.inteiro = rand() % 1000;
        Inserir(lista, item);
    }
}

void troca(TipoCelula *a, TipoCelula *b) {
    if (a == NULL || b == NULL) {
        fprintf(stderr, "Erro: Tentativa de trocar elementos nulos.\n");
        exit(2);
    }
    // Troca os itens
    TipoItem temp;
    temp.inteiro = a->item.inteiro;
    a->item.inteiro = b->item.inteiro;
    b->item.inteiro = temp.inteiro;

}

TipoCelula *particiona(TipoCelula *esquerda, TipoCelula *direita, unsigned long long int *compChaves) {
    TipoCelula *pivo = direita;
    TipoCelula *i = esquerda->tras;
    for (TipoCelula *j = esquerda; j != direita; j = j->frente) {
        if (j->item.inteiro < pivo->item.inteiro) {
            i = (i == NULL) ? esquerda : i->frente;
            troca(i, j);
        }
        (*compChaves)++;
    }
    i = (i == NULL) ? esquerda : i->frente;
    troca(i, direita);
    return i;
}

void quicksort(TipoCelula *esquerda, TipoCelula *direita, unsigned long long int *compChaves) {

    if(esquerda->indice < direita->indice) {
        TipoCelula *pivo = particiona(esquerda, direita, compChaves);
        quicksort(esquerda, pivo->frente, compChaves);
        quicksort(pivo->frente, direita, compChaves);
    }
}