#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Estrutura de Dados Lista Din�mica*/
struct TipoItem{
	int codigo;
	char descricao[50];
	float valor;
	int ram;
	int ano;
};

typedef struct TipoCelula *TipoApontador;

struct TipoCelula {
	TipoItem Item ;
	TipoApontador Prox;
};

struct TipoLista{
	TipoApontador Primeiro , 		
		Ultimo ;
};


/* Fun��es de manipula��o da Lista Din�mica*/
void FLVazia(TipoLista *Lista){
	Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula)) ;
	Lista->Ultimo = Lista->Primeiro ; 
	Lista->Primeiro->Prox = NULL ;
}

int Vazia(TipoLista Lista){
		return(Lista.Primeiro == Lista.Ultimo);
}

void Insere (TipoItem x , TipoLista * Lista ){
	Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->Item = x ;
	Lista->Ultimo->Prox = NULL ;
}

void Imprime(TipoLista Lista){
	TipoApontador Aux;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		printf("%d\t" , Aux->Item.codigo);
		printf("%s\t" , Aux->Item.descricao);
		printf("%f\t" , Aux->Item.valor);
		printf("%d\n" , Aux->Item.ram);
		Aux = Aux->Prox ;
	}
}

/* Retorna o endere�o de mem�ria de uma c�lula que possui 
   um item com o codigo passado como par�metro*/
TipoApontador Busca(int cod, TipoLista Lista){
	TipoApontador Aux, p=NULL;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		if(Aux->Item.codigo==cod)
			p=Aux;
		Aux = Aux->Prox ;
	}
	return p;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
	TipoApontador q;
	if(Vazia(*Lista) || p==NULL || p->Prox == NULL){ 
		printf("Erro : Lista vazia ou posicao nao existe \n"); return ;
	}
	q = p->Prox; *Item = q->Item; p->Prox = q->Prox;
	if (p->Prox == NULL) 
		Lista->Ultimo = p;
	free (q) ;
}

TipoApontador MaiorValor(TipoLista *Lista){

	TipoApontador aux = Lista->Primeiro;
    TipoApontador auxMaiorValor = aux;

    if (aux == NULL) {
        return NULL; // Caso a lista esteja vazia
    }

    float maiorValor = aux->Item.valor;

    while (aux != NULL) {
        if (maiorValor < aux->Item.valor) {
            auxMaiorValor = aux;
            maiorValor = aux->Item.valor;
        }
        aux = aux->Prox;
    }

    return auxMaiorValor;
}

void RetirarAntigo(TipoLista *Lista) {
    if (Vazia(*Lista)) {
        printf("Erro: Lista vazia\n");
        return;
    }

    TipoApontador aux = Lista->Primeiro;
    TipoApontador auxAntigo = aux;
    TipoApontador anterior = NULL;
    TipoApontador anteriorAntigo = NULL;

    int ano = aux->Prox->Item.ano;

    while (aux->Prox != NULL) {
        if (aux->Prox->Item.ano < ano) {
            ano = aux->Prox->Item.ano;
            anteriorAntigo = aux;
            auxAntigo = aux->Prox;
        }
        aux = aux->Prox;
    }

    if (auxAntigo != Lista->Primeiro) {
        TipoItem itemRemovido;
        Retira(anteriorAntigo, Lista, &itemRemovido);
    } else {
        printf("Erro: Não foi encontrado um item mais antigo\n");
    }
}

main(){
	TipoLista lista;
	TipoApontador p;
	FLVazia(&lista);
	printf("\nLista Vazia %d", Vazia(lista));
	TipoItem item;
	item.codigo=1;strcpy(item.descricao, "N9");item.ram=4; item.valor=1500;
	Insere(item, &lista);
	item.codigo=2;strcpy(item.descricao, "N10");item.ram=6; item.valor=2000;
	Insere(item, &lista);
	item.codigo=3;strcpy(item.descricao, "N11");item.ram=10; item.valor=3000;
	Insere(item, &lista);
	
	printf("\n\nExibindo a Lista\n");
	Imprime(lista);			
	
	// Busca o endere�o da mem�ria da c�lula que cont�m um Item com isbn 1
	p=Busca(1, lista);
	printf("\nResultado da busca %p", p);//Exibe o endere�o de mem�ria da c�lula com o isbn passado por par�metro
	printf("\ - Celular %s", p->Item.descricao);
	
	// Retira a pr�xima c�lula (retira a c�lula com isbn 2)
	Retira(p, &lista, &item);
	printf("\nItem retirado %s", item.descricao);
	
	printf("\n\nExibindo a Lista Apos a funcao Retira\n");
	Imprime(lista);	
}
