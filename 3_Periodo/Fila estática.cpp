#include<stdio.h>
#define MAXTAM 5

typedef int TipoApontador;
typedef struct {
	char letra;
} TipoItem ;

typedef struct {
	TipoItem item [ MAXTAM ] ;
	TipoApontador frente, tras ;
} TipoFila;

void FFVazia( TipoFila *fila ){
	fila->frente = 1;
	fila->tras = fila->frente ;
}

int Vazia(TipoFila fila){
	return (fila.frente == fila.tras);
}

void Enfileira (TipoItem x, TipoFila * fila){
	if(fila->tras % MAXTAM + 1 == fila->frente)
			printf("Erro fila esta cheia \n" ) ;
	else {
             fila->item[fila->tras-1]=x;
             fila->tras=fila->tras%MAXTAM+1;
     }
}

void Desenfileira ( TipoFila * fila , TipoItem * item){
	if(Vazia(*fila))
		    printf("Erro fila esta vazia \n" ) ;
	else {
			 *item=fila->item [fila->frente - 1];
			 fila->frente = fila->frente % MAXTAM+1;
	}
}

void exibe (TipoFila fila){
	int i;	
	for(i=fila.frente;i != fila.tras; i=i% MAXTAM+1){
		printf("i==%d | Item==%c\n",i, fila.item[i-1].letra);
	}
}


main(){
	TipoFila fila;
	FFVazia(&fila);
	TipoItem item;
	item.letra='A'; Enfileira(item, &fila);
	item.letra='B'; Enfileira(item, &fila);
	item.letra='C'; Enfileira(item, &fila);
	item.letra='D'; Enfileira(item, &fila);
	item.letra='E'; Enfileira(item, &fila); // Fila cheia. Não será enfileirado. Cabe MAXTAM-1 itens
	printf("\nExibindo a fila\n");
	exibe(fila);
	
	Desenfileira(&fila, &item); printf("\nItem desenfileirado: %c", item.letra);
	Desenfileira(&fila, &item); printf("\nItem desenfileirado: %c", item.letra);
	Desenfileira(&fila, &item); printf("\nItem desenfileirado: %c", item.letra);
	
	item.letra='F'; Enfileira(item, &fila);
	item.letra='G'; Enfileira(item, &fila);
	printf("\n\nExibindo a fila apos as alteracoes\n");
	exibe(fila);
}


