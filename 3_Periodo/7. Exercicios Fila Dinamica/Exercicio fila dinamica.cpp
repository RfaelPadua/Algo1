/*Considere:
struct TipoItem{
char chave;
}
2. Receba um TipoItem e uma fila e uma fila e retorne 1, se o item estiver presente na fila, ou 0, caso
contrário.
3. Simule a função FuraFila (TipoFila *fila, TipoItem x), que insere um item na primeira posição da fila.
Observe que, neste caso, estaremos desrespeitando o conceito de FILA: primeiro a entrar é o primeiro a
sair.
4. Simule a função FuraFila (TipoFila *fila, TipoApontador p, TipoItem x), que insere um item na fila após a
posição apontada por p (sentido frente -> trás).
5. Retorne 1 se os elementos de uma fila dinâmica estiverem em ordem crescente. Caso contrário a função
deve retornar 0. A fila deverá ser passada para a função como passagem de parâmetros por valor.
6. Receba uma Fila de caracteres (não ordenada) e mova a célula que contém o maior valor para a primeira
posição (com informação válida) da Fila.
7. Receba duas Filas dinâmicas (A e B) e gere uma terceira Fila (passada como parâmetro) que seja a
diferença entre A e B, ou seja, os elementos que pertencem a A e não pertencem a B.
8. Receba duas Filas dinâmicas (A e B) e gere uma terceira Fila (como passagem de parâmetro por
referência) que seja a interseção entre A e B, ou seja, os elementos que pertencem a A e também
pertencem a B.
9. Simule uma Fila com prioridade. Adicione o campo int prioridade no TipoItem. A função desenfileira
deverá dar prioridade a itens com o campo prioridade == 1.
10. Receba uma fila dinâmica e inverta a ordem da fila recebida utilizando uma pilha. O TipoItem será o
mesmo para as duas estruturas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoCelula *TipoApontador;

typedef struct TipoItem{
    char chave;
} TipoItem;

typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila{
    TipoApontador Frente, Tras;
} TipoFila;

typedef struct TipoPilha{
    TipoItem Item;
    TipoApontador Topo;
} TipoPilha;

void FPVazia(TipoPilha *pilha){
    pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
    pilha->Topo->Prox = NULL;
}

int PilhaVazia(TipoPilha pilha){
    return (pilha.Topo->Prox == NULL);
}

void Empilha(TipoItem x, TipoPilha *pilha){
    TipoApontador aux = (TipoApontador) malloc(sizeof(TipoCelula));
    aux->Item = x;
    aux->Prox = pilha->Topo->Prox;
    pilha->Topo->Prox = aux;
}

void Desempilha(TipoPilha *pilha, TipoItem *item){
    TipoApontador q;

    if(PilhaVazia(*pilha)){
        printf("Erro: Pilha esta vazia\n");
    }
    q = pilha->Topo->Prox;
    pilha->Topo->Prox = q->Prox;
    *item = q->Item;
    free(q);
}



void FFVazia(TipoFila *fila){
    fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
    fila->Tras = fila->Frente;
    fila->Frente->Prox = NULL;
}

int FilaVazia(TipoFila fila){
    return (fila.Frente == fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *fila){
    fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    fila->Tras = fila->Tras->Prox;
    fila->Tras->Item = x;
    fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *fila, TipoItem *item){
    TipoApontador q;

    if(FilaVazia(*fila)){
        printf("Erro: Fila esta vazia\n");
    }
    q = fila->Frente;
    fila->Frente = fila->Frente->Prox;
    *item = fila->Frente->Item;
    free(q);
}

int ItemNaFila(TipoItem item, TipoFila fila){
    TipoApontador aux = fila.Frente->Prox;
    int achou = 0;

    while(aux != NULL && achou == 0){
        achou = (aux->Item.chave == item.chave);
        aux = aux->Prox;
    }

    return achou;
}

void FuraFila(TipoFila *fila, TipoItem x){
    TipoApontador aux = fila->Frente;
    TipoApontador novo = (TipoApontador) malloc(sizeof(TipoCelula));

    novo->Item = x;
    novo->Prox = aux->Prox;
    aux->Prox = novo;
}

int FilaOrdenada(TipoFila fila){
    TipoApontador aux = fila.Frente->Prox;
    int ordenada = 1;

    while(aux->Prox != NULL && ordenada == 1){
        ordenada = (aux->Item.chave <= aux->Prox->Item.chave);
        aux = aux->Prox;
    }

    return ordenada;
}

void MaiorNaFrente(TipoFila *fila){
    TipoApontador aux = fila->Frente->Prox;
    TipoApontador maior = aux;
    TipoItem item;

    while(aux != NULL){
        if(aux->Item.chave > maior->Item.chave){
            maior = aux;
        }
        aux = aux->Prox;
    }

    item = maior->Item;
    Desenfileira(fila, &item);
    FuraFila(fila, item);
}

void DiferencaFilas(TipoFila A, TipoFila B, TipoFila *C){
    TipoApontador auxA = A.Frente->Prox;
    TipoItem item;

    while(auxA != NULL){
        if(!ItemNaFila(auxA->Item, B)){
            item = auxA->Item;
            Enfileira(item, C);
        }
        auxA = auxA->Prox;
    }
}

void IntersecaoFilas(TipoFila A, TipoFila B, TipoFila *C){
    TipoApontador auxA = A.Frente->Prox;
    TipoItem item;

    while(auxA != NULL){
        if(ItemNaFila(auxA->Item, B)){
            item = auxA->Item;
            Enfileira(item, C);
        }
        auxA = auxA->Prox;
    }
}

void FilaPrioridade(TipoFila *fila, TipoItem x){
    TipoApontador aux = fila->Frente;
    TipoApontador novo = (TipoApontador) malloc(sizeof(TipoCelula));

    novo->Item = x;

    while(aux->Prox != NULL && aux->Prox->Item.chave == 1){
        aux = aux->Prox;
    }

    novo->Prox = aux->Prox;
    aux->Prox = novo;
}


void InverteFila(TipoFila *fila, TipoPilha *pilha){
    TipoItem item;

    while(!FilaVazia(*fila)){
        Desenfileira(fila, &item);
        Empilha(item, pilha);
    }

    while(!PilhaVazia(*pilha)){
        Desempilha(pilha, &item);
        Enfileira(item, fila);
    }
}

void exibe(TipoFila fila){
    TipoApontador aux = fila.Frente->Prox;

    while(aux != NULL){
        printf("\n%d", aux->Item.chave);
        aux = aux->Prox;
    }
}

int main(){
    TipoFila fila;
    TipoPilha pilha;
    TipoItem item;
    int i;

    FFVazia(&fila);
    FPVazia(&pilha);

    // Testar funções
    for(i = 0; i < 10; i++){
        item.chave = i;
        Enfileira(item, &fila);
    }

    //testar funcao ItemNaFila
    item.chave = 5;
    if(ItemNaFila(item, fila)){
        printf("\nItem na fila\n");
    }else{
        printf("\nItem nao esta na fila\n");
    }
    item.chave = 11;
    if(ItemNaFila(item, fila)){
        printf("\nItem na fila\n");
    }else{
        printf("\nItem nao esta na fila\n");
    }

    //testar funcao FuraFila
    item.chave = 11;
    FuraFila(&fila, item);
    item.chave = 12;
    FuraFila(&fila, item);

    //testar funcao FilaOrdenada
    if(FilaOrdenada(fila)){
        printf("\nFila ordenada\n");
    }else{
        printf("\nFila nao ordenada\n");
    }

    //testar funcao MaiorNaFrente
    MaiorNaFrente(&fila);

    printf("\nMaior na frente\n");
    exibe(fila);

    //testar funcao DiferencaFilas

    TipoFila A, B, C;
    FFVazia(&A);
    FFVazia(&B);
    FFVazia(&C);

    for(i = 0; i < 10; i++){
        item.chave = i;
        Enfileira(item, &A);
    }

    for(i = 5; i < 15; i++){
        item.chave = i;
        Enfileira(item, &B);
    }


    DiferencaFilas(A, B, &C);
    printf("\nDiferenca entre A e B\n");
    printf("\nA\n");
    exibe(A);
    printf("\nB\n");
    exibe(B);
    printf("\nC\n");
    exibe(C);

    //testar funcao IntersecaoFilas

    IntersecaoFilas(A, B, &C);

    printf("\nIntersecao entre A e B\n");
    exibe(A);

    //testar funcao FilaPrioridade

    TipoFila filaPrioridade;

    FFVazia(&filaPrioridade);

    for(i = 0; i < 10; i++){
        item.chave = i;
        FilaPrioridade(&filaPrioridade, item);
    }

    printf("\nFila com prioridade\n");
    exibe(filaPrioridade);

    //testar funcao InverteFila

    InverteFila(&fila, &pilha);
    printf("\nFila invertida\n");
    exibe(fila);








    return 0;
}