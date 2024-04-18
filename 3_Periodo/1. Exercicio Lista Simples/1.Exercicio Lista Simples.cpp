#include <stdio.h>

#define InicioArranjo 1
#define MaxTam 1000

typedef int Apontador, TipoChave;

typedef struct{
    int ano;
    char montadora[50];
    char modelo[5];
    float valor;
} TipoItem;

typedef struct{
    TipoItem Item[MaxTam];
    Apontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);

float SomaValor(TipoLista Lista);

int main(){
    TipoLista lista;
    FLVazia(&lista);

    printf("certo");

}

void FLVazia(TipoLista Lista){
    Lista.Primeiro = InicioArranjo;
    Lista.Ultimo = Lista.Primeiro;
}
