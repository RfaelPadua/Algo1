#include <stdio.h>

#define MAXTAM 100

typedef int TipoApontador, chave;

typedef struct{
    chave chave;
    char nome[MAXTAM];
}TipoItem;

typedef struct{
    TipoItem item[MAXTAM];
    TipoApontador topo;
}TipoPilha;


void FazerPilhaVazia(TipoPilha*pilha);
void empilha(TipoPilha *pilha, char letra);
void desempilha(TipoPilha *pilha);
void erguePilha(TipoPilha pilha, TipoApontador p, TipoItem item);

int main(){

}


void FazerPilhaVazia(TipoPilha*pilha){
    pilha->topo = 0;
}

void empilha(TipoPilha *pilha, TipoItem item){
    if(pilha->topo >= MAXTAM){
        printf("A Pilha esta cheia!!\n");
    }

    pilha->item[pilha->topo] = item;
    pilha->topo++;

}
void desempilha(TipoPilha *pilha){
    if(pilha->topo == 0){
        printf("A Pilha esta vazia!!\n");
    }
    pilha->topo--;
}

void erguePilha(TipoPilha pilha, TipoApontador p, TipoItem item){
    
}

