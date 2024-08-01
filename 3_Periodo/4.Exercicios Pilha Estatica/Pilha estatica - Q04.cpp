#include <stdio.h>
#include <string.h>

#define MAXTAM 100

typedef int TipoApontador;

typedef struct{
    int chave;
    char nome[MAXTAM];
    float valor;
}TipoItem;

typedef struct{
    TipoItem item[MAXTAM];
    TipoApontador topo;
}TipoPilha;

void fazerPilhaVazia(TipoPilha *pilha);
void empilha(TipoPilha *pilha, TipoItem item);
void desempilha(TipoPilha *pilha);
void popularPilha(TipoPilha *pilha);
int pilhasIguais(TipoPilha pilha1, TipoPilha pilha2);

int main(){
    TipoPilha pilha1, pilha2;

    fazerPilhaVazia(&pilha1);
    fazerPilhaVazia(&pilha2);

    popularPilha(&pilha1);
    popularPilha(&pilha2);

    if(pilhasIguais(pilha1, pilha2) == 0){
        printf("As pilhas sao diferentes!\n");
    }else{
        printf("As pilha sao iguais\n");
    }

    desempilha(&pilha2);

    if(pilhasIguais(pilha1, pilha2) == 0){
        printf("As pilhas sao diferentes!\n");
    }else{
        printf("As pilha sao iguais\n");
    }
    
    return 0;
}
 
void fazerPilhaVazia(TipoPilha *pilha){
    pilha->topo =0;
}

void empilha(TipoPilha *pilha, TipoItem item){
    if(pilha->topo == MAXTAM){
        printf("ERRO: A Pilha esta cheia!!\n");
        return;
    }

    pilha->item[pilha->topo]= item;
    pilha->topo++;
}

void desempilha(TipoPilha *pilha){
    if(pilha->topo == 0){
        printf("ERRO: A Pilha esta vazia!!\n");
        return;
    }

    pilha->topo--;
}

void popularPilha(TipoPilha *pilha){
    int i;

    for(i = 0; i < 5; i++){
        TipoItem item;
        item.chave = i;
        item.valor = i * 10;
        sprintf(item.nome, "Nome %d", i);
        empilha(pilha, item);
    }
}

int pilhasIguais(TipoPilha pilha1, TipoPilha pilha2){
    int i;
    
    if(pilha1.topo != pilha2.topo){
        return 0;
    }

    for(i = 0; i < pilha1.topo; i++){
        if(pilha1.item[i].chave != pilha2.item[i].chave ||
           pilha1.item[i].valor != pilha2.item[i].valor ||
           strcmp(pilha1.item[i].nome, pilha2.item[i].nome) != 0){
            return 0;
        }
    }

    return 1;

}







