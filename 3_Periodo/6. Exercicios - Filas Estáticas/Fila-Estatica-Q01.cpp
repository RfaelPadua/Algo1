/* Receba um TipoItem e uma fila e retorne 1 se o item 
estiver presente na fila, ou 0, caso contrário.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 5;

typedef int TipoApontador;

typedef struct TipoItem{
    int cod;
    float valor;
    char operacao[20];
}TipoItem;

typedef struct{
    TipoItem item[MAXTAM];
    TipoApontador frente, tras;
}TipoLista;



int main(){

}