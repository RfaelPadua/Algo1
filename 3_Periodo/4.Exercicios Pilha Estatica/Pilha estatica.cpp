#include <stdio.h>
#include <string.h>

#define MAXTAM 100

typedef int TipoApontador, TipoChave;

typedef struct{
    TipoChave chave;
    char nome[MAXTAM];
    float valor;
}TipoItem;

typedef struct{
    TipoItem item;
    TipoApontador topo;
}TipoPilha;

int main(){
    
}