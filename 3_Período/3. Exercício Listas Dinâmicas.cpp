#include <stdio.h>


struct TipoItem{
    int codigo;
    char descrição[50];
    float valor;
}

typedef struct TipoCelular *TipoApontador;


struct TipoItem{
    TipoApontador primeiro, ultimo;
}




int main(){

}