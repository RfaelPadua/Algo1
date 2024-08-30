#include<stdio.h>
#include<stdlib.h>

// Estrutura de Dados Fila Dinâmica
typedef struct TipoCelula *TipoApontador; 

typedef struct TipoItem { 
	int numero;
} TipoItem;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontador Prox;
} TipoCelula; 

typedef struct TipoFila {
	TipoApontador Frente, Tras;
}TipoFila;

// Funções de manipulação da Fila Dinâmica
void FFVazia(TipoFila *Fila ) { 
	Fila ->Frente = (TipoApontador) malloc(sizeof(TipoCelula )); 
	Fila ->Tras = Fila ->Frente; 
	Fila ->Frente ->Prox = NULL; 
}

int Vazia(TipoFila Fila ) { 
	return ( Fila.Frente == Fila.Tras) ;
}

void Enfileira (TipoItem x, TipoFila *Fila ) { 
	Fila ->Tras ->Prox = (TipoApontador) malloc(sizeof(TipoCelula )); 
	Fila ->Tras = Fila ->Tras ->Prox;
	Fila ->Tras ->Item = x; 
	Fila ->Tras ->Prox = NULL; 
}

void Desenfileira(TipoFila *Fila , TipoItem *Item) { 
	TipoApontador q; 
	if (Vazia( *Fila ) ) { 
		printf ( "Erro fila esta vazia\n" ) ; return;
	} 
	q = Fila ->Frente; 
	Fila ->Frente = Fila ->Frente ->Prox; 
	*Item = Fila ->Frente ->Item; 
	free(q); 
}

void exibe (TipoFila fila){
	TipoApontador aux=fila.Frente->Prox;
	while(aux!=NULL){
		printf("\n%d", aux->Item.numero);
		aux=aux->Prox;
	}
}

/* 1. Receba uma Fila de números (não ordenada) e mova a célula que 
   contém o maior valor para a primeira posição (com informação válida) 
   da Fila.
*/
void moveMaior(TipoFila *fila){
	TipoApontador aux=fila->Frente, antesMaior=fila->Frente, p;
	int maior=fila->Frente->Prox->Item.numero;
	
	while(aux->Prox!=NULL){
		if(aux->Prox->Item.numero > maior){
			antesMaior=aux;
			maior=aux->Prox->Item.numero;
		}
		aux=aux->Prox;
	}
	p=antesMaior->Prox;
	antesMaior->Prox=p->Prox;
	p->Prox=fila->Frente->Prox;
	fila->Frente->Prox=p;
}

main(){
	TipoFila fila;
	FFVazia(&fila);
	TipoItem item;
	item.numero=5; Enfileira(item, &fila);
	item.numero=10; Enfileira(item, &fila);
	item.numero=6; Enfileira(item, &fila);
	item.numero=4; Enfileira(item, &fila);
	printf("\nExibindo a fila\n");
	exibe(fila);
	
	// Ex 1
	moveMaior(&fila);
	
	printf("\n\nExibindo a fila apos a funcao do ex 1");
	exibe(fila);
}
