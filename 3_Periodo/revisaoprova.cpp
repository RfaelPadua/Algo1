#include <stdio.h>
#include <stdlib.h>

#define MaxTam 100

typedef int TipoApontador;

// Estrutura do Item
typedef struct {
    int chave;
}TipoItem;

// Estrutura da Fila estatica

typedef struct {
    TipoItem Item[MaxTam];
    int Frente, Tras;
}TipoFila;

// Funções básicas de manipulação da Fila Estatica

void FFVazia(TipoFila *fila){
    fila->Frente = 0;
    fila->Tras = fila->Frente;
}

int FilaVazia(TipoFila fila){
    return (fila.Frente == fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *fila){
    if((fila->Tras + 1) % MaxTam == fila->Frente){
        printf("Erro: Fila esta cheia\n");
    } else{
        fila->Item[fila->Tras] = x;
        fila->Tras = (fila->Tras + 1) % MaxTam;
    }
}

void Desenfileira(TipoFila *fila, TipoItem *item){
    if(FilaVazia(*fila)){
        printf("Erro: Fila esta vazia\n");
    } else{
        *item = fila->Item[fila->Frente];
        fila->Frente = (fila->Frente + 1) % MaxTam;
    }
}

void Exibe(TipoFila fila){
    TipoApontador aux = fila.Frente;
    while(aux != fila.Tras){
        printf("\nChave==%d", fila.Item[aux].chave);
        aux = (aux + 1) % MaxTam;
    }
}

