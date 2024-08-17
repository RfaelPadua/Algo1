#include<stdio.h>
#include<stdlib.h>
#define MAXTAM 5
// Estrutura Pilha est�tica
typedef struct { 
    char chave; 
}TipoItem; 

typedef struct TipoCelula *TipoApontador; 

typedef struct TipoCelula{ 
	TipoItem Item; 
	TipoApontador Prox; 
} TipoCelula; 

typedef struct { 
	TipoApontador  Fundo, Topo; 
	int Tamanho; 
} TipoPilha;

typedef struct TipoLista{
	TipoApontador primeiro;
	TipoItem item;
	struct TipoLista *prox;
}TipoLista;


// Fun��es de manipula��o da pilha din�mica

void FPVazia(TipoPilha *Pilha) { 
	Pilha ->Topo=(TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Fundo = Pilha ->Topo; 
	Pilha ->Topo->Prox = NULL; 
	Pilha ->Tamanho = 0; 
}

int Vazia(TipoPilha Pilha) {
	return ( Pilha .Topo == Pilha .Fundo) ; 
}

void Empilha(TipoItem x, TipoPilha *Pilha) { 
	TipoApontador Aux; 
	Aux = (TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Topo->Item = x; 
	Aux->Prox = Pilha ->Topo; 
	Pilha ->Topo = Aux; 	
	Pilha ->Tamanho++; 
}

void Desempilha(TipoPilha *Pilha , TipoItem *Item) {
	TipoApontador q; 
	if (Vazia( *Pilha ) ) { 
		printf ( "Erro : lista vazia\n" ) ; 	return; 
	} 
	q = Pilha ->Topo; 
	Pilha ->Topo = q ->Prox; 
	*Item = q ->Prox->Item; 
	free(q) ;
	Pilha ->Tamanho--; 
}

int Tamanho(TipoPilha Pilha) { 
	return ( Pilha .Tamanho) ; 
}

void exibePilha(TipoPilha pilha){
	TipoApontador aux=pilha.Topo->Prox;
	while(aux!=NULL){
		printf("\n%c", aux->Item.chave);
		aux=aux->Prox;
	}
}

TipoApontador busca(TipoPilha pilha, TipoItem item){
	TipoApontador aux=pilha.Topo->Prox;
	while(aux!=NULL){
		if(aux->Item.chave==item.chave)
			return aux;
		aux=aux->Prox;		
	}
	return NULL;
}

void insere(TipoItem item, TipoLista *lista){
	TipoLista *aux=lista;
	
	if(lista==NULL){
		lista=(TipoLista*)malloc(sizeof(TipoLista));
		lista->item=item;
		lista->prox=NULL;
	}else{
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=(TipoLista*)malloc(sizeof(TipoLista));
		aux=aux->prox;
		aux->item=item;
		aux->prox=NULL;
	}
}

int estaPresente(TipoLista *lista, int x){
	TipoApontador aux = lista.primeiro->prox;;
	
	while(aux!=NULL){
		if(aux->item.chave==x)
			return 1;
		aux=aux->prox;
	}
	return 0;
}

TipoLista *interseccao(TipoLista *L1, TipoLista *L2){
	TipoLista *aux1=L1, *aux2=L2, *L3=NULL;
	
	while(aux1!=NULL){
		if(estaPresente(L2, aux1->item.chave)){
			insere(aux1->item, L3);
		}
		aux1=aux1->prox;
	}
	return L3;
}


main(){
	/*testar as funções*/
	TipoPilha pilha;
	TipoItem item;
	TipoLista *L1=NULL, *L2=NULL, *L3=NULL;

	FPVazia(&pilha);
	
}
