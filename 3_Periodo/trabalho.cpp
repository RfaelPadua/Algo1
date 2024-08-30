#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 5

typedef int TipoApontadorEstatica;

// Estrutura do Item
typedef struct {
    char placa[10];
    int deslocamento;
    int prioridade;
}TipoItem;


// Estrutura da Fila Estatica
typedef struct {
    TipoItem item[MAXTAM];
    TipoApontadorEstatica frente, tras;
}TipoFilaEstatica;

// Funções de manipulação da Fila Estatica
void FFEVazia(TipoFilaEstatica *fila){ 
    fila->frente = 1;
    fila->tras = fila->frente;
};

void EnfileiraEstatica(TipoItem x, TipoFilaEstatica *fila){
    if(fila->tras % MAXTAM + 1 == fila->frente){
        printf("Erro fila esta cheia \n");
    }else{
        fila->item[fila->tras-1] = x;
        fila->tras = fila->tras % MAXTAM + 1;
    }
};

void DesenfileiraEstatica(TipoFilaEstatica *fila, TipoItem *item){
    if(fila->frente == fila->tras){
        printf("Erro fila esta vazia \n");
    }else{
        *item = fila->item[fila->frente - 1];
        fila->frente = fila->frente % MAXTAM + 1;
    }
};

void ExibeEstatica(TipoFilaEstatica fila){
    int i;
    for(i = fila.frente; i != fila.tras; i = i % MAXTAM + 1){
        printf("i==%d | Placa==%s | Deslocamento==%d | Prioridade==%d\n", i, fila.item[i-1].placa, fila.item[i-1].deslocamento, fila.item[i-1].prioridade);
    }
};


// Estrutura da Fila Dinamica
typedef TipoCelula *TipoApontadorDinamica;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontadorDinamica Prox;
} TipoCelula; 

typedef struct TipoFilaDinamica{
    TipoApontadorDinamica Frente, Tras;
}TipoFilaDinamica;

// Funções de manipulação da Fila Dinamica

void FFDVazia(TipoFilaDinamica *fila){
    fila->Frente = (TipoApontadorDinamica) malloc(sizeof(TipoCelula));
    fila->Tras = fila->Frente;
    fila->Frente->Prox = NULL;
};

void EnfileiraDinamica(TipoItem x, TipoFilaDinamica *fila){
    fila->Tras->Prox = (TipoApontadorDinamica) malloc(sizeof(TipoCelula));
    fila->Tras = fila->Tras->Prox;
    fila->Tras->Item = x;
    fila->Tras->Prox = NULL;
};

void DesenfileiraDinamica(TipoFilaDinamica *fila, TipoItem *item){
    TipoApontadorDinamica q;
    if(fila->Frente == fila->Tras){
        printf("Erro fila esta vazia\n");
    }
    q = fila->Frente;
    fila->Frente = fila->Frente->Prox;
    *item = fila->Frente->Item;
    free(q);
};

void ExibeDinamica(TipoFilaDinamica fila){
    TipoApontadorDinamica aux = fila.Frente->Prox;
    while(aux != NULL){
        printf("\nPlaca==%s | Deslocamento==%d | Prioridade==%d", aux->Item.placa, aux->Item.deslocamento, aux->Item.prioridade);
        aux = aux->Prox;
    }
};

int main(){

    TipoFilaEstatica filaEstacionamento;
    TipoFilaDinamica filaEspera;
    TipoFilaDinamica filaAuxiliar;
    FFDVazia(&filaEspera);
    FFDVazia(&filaAuxiliar);
    FFEVazia(&filaEstacionamento);
    TipoItem item;
    int opcao;

    do{
        printf("------------------\n");
        printf("--Escollha uma opção--\n");
        printf("1.\n");
        printf("2.\n");
        printf("0. Sair\n");
        printf("------------------\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            // Chegada de um carro
            // Quando um carro chegar, a mensagem devera especificar se existe ou 
            // nao vaga para o carro dentro do estacionamento. Se nao exister vaga, 
            // o carro esperara pela vaga na FilaEspera

                break;
            case 2:
            // Saida de um carro
            // Quando um carro partir, a mensagem devera incluir o numero de vezes que 
            // o carro foi deslocado dentro do estacionamento, incluindo a propria partida, 
            // mas não a chegada
                
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
                break;
            default:
                printf("Opção inválida\n");

        }
        

        system("cls");
        system("pause");

    }while(opcao != 0);

    return 0;

}