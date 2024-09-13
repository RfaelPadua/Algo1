#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*Considere que o TipoItem tenha somente um campo inteiro "chave" nas questões 2, 3 , 4 e 5.

3. Faça uma função que receba uma lista dinâmica duplamente encadeada e gere:
• uma fila dinâmica com os itens com código par;
• uma lista dinâmica com os itens com código ímpar;
• uma pilha dinâmica com os itens com código igual a 0.*/

typedef struct TipoItem{
    int chave;
    char letra;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{
    TipoItem item;
    TipoApontador prox;
    TipoApontador ant;
}TipoCelula;

typedef struct TipoLista{
    TipoApontador primeiro;
    TipoApontador ultimo;
}TipoLista;

typedef struct TipoFila{
    TipoApontador frente;
    TipoApontador tras;
}TipoFila;

typedef struct TipoPilha{
    TipoApontador topo;
}TipoPilha;

void FFVazia(TipoFila *fila){
    fila->frente = (TipoApontador) malloc(sizeof(TipoCelula));
    fila->tras = fila->frente;
    fila->frente->prox = NULL;
}

int FilaVazia(TipoFila fila){
    return (fila.frente == fila.tras);
}

void Enfileira(TipoItem x, TipoFila *fila){
    fila->tras->prox = (TipoApontador) malloc(sizeof(TipoCelula));
    fila->tras = fila->tras->prox;
    fila->tras->item = x;
    fila->tras->prox = NULL;
}

void Desenfileira(TipoFila *fila, TipoItem *item){
    TipoApontador q;

    if(FilaVazia(*fila)){
        printf("Erro: Fila esta vazia\n");
    }
    q = fila->frente;
    fila->frente = fila->frente->prox;
    *item = fila->frente->item;
    free(q);
}

void FPVazia(TipoPilha *pilha){
    pilha->topo = (TipoApontador) malloc(sizeof(TipoCelula));
    pilha->topo->prox = NULL;
}

int PilhaVazia(TipoPilha pilha){
    return (pilha.topo->prox == NULL);
}

void Empilha(TipoItem x, TipoPilha *pilha){
    TipoApontador aux;

    aux = (TipoApontador) malloc(sizeof(TipoCelula));
    aux->item = x;
    aux->prox = pilha->topo->prox;
    pilha->topo->prox = aux;
}

void Desempilha(TipoPilha *pilha, TipoItem *item){
    TipoApontador q;

    if(PilhaVazia(*pilha)){
        printf("Erro: Pilha esta vazia\n");
    }
    q = pilha->topo->prox;
    pilha->topo->prox = q->prox;
    *item = q->item;
    free(q);
}

void InicializaLista(TipoLista *lista){
    lista->primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
}

int ListaVazia(TipoLista lista){
    return (lista.primeiro == lista.ultimo);
}

void Insere(TipoItem x, TipoLista *lista){
    lista->ultimo->prox = (TipoApontador) malloc(sizeof(TipoCelula));
    lista->ultimo->prox->item = x;
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
}

void Remove(TipoApontador p, TipoLista *lista, TipoItem *item){
    if(ListaVazia(*lista) || p == NULL || p == lista->primeiro){
        printf("Erro: Lista vazia ou posicao invalida\n");
    }
    TipoApontador aux;

    aux = p->prox;
    *item = aux->item;
    p->prox = aux->prox;
    if(p->prox == NULL){
        lista->ultimo = p;
    } else {
        aux->prox->ant = p;
    }
    free(aux);
}

void gerarEstruturas(TipoLista lista){
    TipoItem item;
    TipoFila fila;
    TipoPilha pilha;
    TipoApontador aux;

    FFVazia(&fila);
    FPVazia(&pilha);

    aux = lista.primeiro->prox;
    while(aux != NULL){
        if(aux->item.chave % 2 == 0){
            Enfileira(aux->item, &fila);
        } else if(aux->item.chave % 2 != 0){
            Insere(aux->item, &lista);
        } else {
            Empilha(aux->item, &pilha);
        }
        aux = aux->prox;
    }
}

/*5. Dada uma lista dinâmica duplamente encadeada com TipoItem com um campo (char letra). Construa
uma função que retorne uma fila na qual as vogais são mantidas na sequência original e os demais
caracteres são colocadas na ordem inversa.
Exemplos:
• A S I T O 3 R @ --> A I O @ 3 T S (fila gerada)
• # D F T U O A I --> U O A I T F D # (fila gerada)*/

void gerarFila(TipoLista lista, TipoFila *fila){
    TipoApontador aux;
    TipoItem item;
    
    char letra;
    aux = lista.primeiro->prox;
    while(aux != NULL){
            letra = toupper(aux->item.letra);
            if( letra == 'A' || letra == 'E' || letra == 'I' || 
                letra == 'O' || letra == 'U'){
                Enfileira(aux->item, fila);
            }
            aux = aux->prox;
    }

    aux = lista.ultimo;
    while(aux != lista.primeiro){
        letra = toupper(aux->item.letra);
        if (letra != 'A' && letra != 'E' && letra != 'I' && 
            letra != 'O' && letra != 'U'){
            Enfileira(aux->item, fila);
        }
        aux = aux->ant;
    }
}

// Fura fila: colocar o item na frente do item com chave igual a chave

void furarFila(TipoFila *fila, TipoItem item, int chave){
    TipoApontador aux = fila->frente->prox;
    TipoApontador anterior = fila->frente;



    while(aux != NULL){
        if(aux->item.chave == chave){
            TipoApontador novaCelula = (TipoApontador) malloc(sizeof(TipoCelula));
            novaCelula->item.chave = item.chave;
            novaCelula->item.letra = item.letra;
            anterior->prox = novaCelula;
            novaCelula->prox = aux;
            return; 
        }
        anterior = aux;
        aux = aux->prox;
    }


}