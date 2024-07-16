#include<stdio.h>
#include<string.h>

// Estrutura Lista Est�tica
#define INICIOARRANJO 1
#define MAXTAM 10

typedef int TipoApontador;
typedef int TipoChave;

struct  TipoItem { // Livro
	TipoChave cod;
	char descricao[50];
	int ano;
	float valor;
};

struct  TipoLista {
	TipoItem itens [MAXTAM];
	TipoApontador primeiro , ultimo ;
};


// Fun��es para manipula��o da Lista Est�tica
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
		printf("\n%d\t",lista.itens[aux].cod);
		printf("%s\t",lista.itens[aux].descricao);
		printf("%d\t",lista.itens[aux].ano);
		printf("%.2f\t",lista.itens[aux].valor);
	}
} 

float SomaPorAno(TipoLista Lista, int ano){
	float soma = 0;
	int i;

	for(i = Lista.primeiro -1; i < Lista.ultimo -1; i++){
		if(Lista.itens[i].ano == ano)
			soma += Lista.itens[i].valor;
	}
	return soma;
}

main(){
	TipoLista lista;
	TipoItem item;
	fLVazia(&lista); //Inicia os campos primeiro e ultimo da lista
	item.cod=1; strcpy(item.descricao, "Algoritmos"); item.ano=2011;item.valor=20000;
	insere(item, &lista); // Insere o item na lista
	item.cod=2; strcpy(item.descricao, "Engenharia de Software"); item.ano=2008;item.valor=15000;
	insere(item, &lista); // Insere o item na lista
	item.cod=3; strcpy(item.descricao, "Estrutura de Dados"); item.ano=1997;item.valor=80000;
	insere(item, &lista); // Insere o item na lista
	imprime(lista); // Exibe os livros da lista
	
	retira(1,&lista, &item); // Retira o primeiro livro da lista
	printf("\n\nLivro retirado %s", item.descricao);
	
	printf("\n\n\n");
	imprime(lista);
}
