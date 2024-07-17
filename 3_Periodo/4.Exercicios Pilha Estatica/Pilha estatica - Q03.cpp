#include <stdio.h>
#include <string.h>

#define MAXTAM 100

typedef int Apontador;

typedef struct{
    char letra[MAXTAM];
    Apontador topo;
}TipoPilha;

void empilha(TipoPilha *pilha, char letra);
char desempilha(TipoPilha *pilha);
void inverterPalavra(char *palavra);

int main(){
    char palavra[7] = "Rafael";

    inverterPalavra(palavra);
}

void empilha(TipoPilha *pilha, char letra){

    if(pilha->topo > MAXTAM){
        printf("Pilha Cheia!!\n");
        return;
    }
    pilha->topo++;
    pilha->letra[pilha->topo - 1] = letra;
    
    return;
}

char desempilha(TipoPilha *pilha){

    if(pilha->topo == 0){
        printf("Pilha Vazia!!\n");
        return '\0';
    }

    pilha->topo--;
    return pilha->letra[pilha->topo];
}

void inverterPalavra(char *palavra){
    TipoPilha pilha;
    pilha.topo = 0;

    size_t i;

    for(i = 0; i < strlen(palavra); i++){
        empilha(&pilha, palavra[i]);
    }


    while(pilha.topo > 0){
        printf("%c", desempilha(&pilha));
    }
    
}


















