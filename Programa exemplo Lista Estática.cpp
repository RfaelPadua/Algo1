#include<stdio.h>
#include<string.h>

// Estrutura Lista Estática
#define INICIOARRANJO 1
#define MAXTAM 10

typedef int TipoApontador;
typedef int TipoChave;

struct  TipoItem { // Livro
	TipoChave isbn;
	char titulo[50];
	char autor[50];
};

struct  TipoLista {
	TipoItem itens [MAXTAM];
	TipoApontador primeiro , ultimo ;
};


// Funções para manipulação da Lista Estática
void fLVazia(TipoLista *lista){
	lista->primeiro = INICIOARRANJO ; lista->ultimo = lista->primeiro; 
}

int vazia(TipoLista lista){
	return (lista.primeiro == lista.ultimo); 
}

void insere (TipoItem x , TipoLista *lista){ 
    if(lista->ultimo > MAXTAM)
	printf ( " Lista esta cheia \n" ) ;
     else{
		lista-> itens [lista->ultimo-1] = x ;
		lista->ultimo++;
      }
}

void retira (TipoApontador p , TipoLista *lista , TipoItem *item) { 
	int aux;
	if(vazia(*lista ) || p >= lista->ultimo ){ 
		printf("Erro : Posicao nao existe \n") ;
		return ;
	}
	*item = lista -> itens [p - 1];
	lista -> ultimo--;
	for (aux = p;aux<lista->ultimo; aux++)
		lista->itens[aux-1]=lista->itens[aux];
}

void imprime( TipoLista lista ) { 
	int aux;
	for (aux = lista.primeiro - 1; aux <= (lista.ultimo - 2); aux++){
		printf("\n%d\t",lista.itens[aux].isbn);
		printf("%s\t",lista.itens[aux].titulo);
		printf("%s\t",lista.itens[aux].autor);
	}
} 

main(){
	TipoLista lista;
	TipoItem item;
	fLVazia(&lista); //Inicia os campos primeiro e ultimo da lista
	item.isbn=1; strcpy(item.titulo, "Algoritmos"); strcpy(item.autor, "Ziviani");
	insere(item, &lista); // Insere o item na lista
	item.isbn=2; strcpy(item.titulo, "Engenharia de Software"); strcpy(item.autor, "Pressman");
	insere(item, &lista); // Insere o item na lista
	item.isbn=3; strcpy(item.titulo, "Estrutura de Dados"); strcpy(item.autor, "Cormen");
	insere(item, &lista); // Insere o item na lista
	imprime(lista); // Exibe os livros da lista
	
	retira(1,&lista, &item); // Retira o primeiro livro da lista
	printf("\n\nLivro retirado %s", item.titulo);
	
	printf("\n\n\n");
	imprime(lista);
}
