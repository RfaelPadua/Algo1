#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INICIOARRANJO 0
#define MAXTAM 20

typedef int TipoApontador;

struct TipoItem{ // Um Veiculo
    int ano;
    char montadora[50];
    char modelo[50];
    float valor;
};

struct TipoLista{ // Lista de Veiculos
    TipoItem item[MAXTAM];
    TipoApontador primeiro, ultimo;
};

void listaVazia(TipoLista *Lista);
void insere(TipoItem *item, TipoLista *Lista);
void populaLista(TipoLista *Lista);
void imprimeLista(TipoLista *Lista);
void somaValores(TipoLista *Lista);


int main(){
    TipoItem veiculo;
    TipoLista lista;

    listaVazia(&lista);
    populaLista(&lista);

    while(1){
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir um veiculo\n");
        printf("2 - Imprimir lista de veiculos\n");
        printf("0 - Sair\n");
        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite a montadora: "); fflush(stdin);
            scanf("%s", veiculo.montadora);
            printf("Digite o modelo: ");
            scanf("%s", veiculo.modelo); fflush(stdin);
            printf("Digite o ano: ");
            scanf("%d", &veiculo.ano);
            printf("Digite o valor: ");
            scanf("%f", &veiculo.valor);
            insere(&veiculo, &lista);
            break;
        case 2:
            imprimeLista(&lista);
            break;
        case 3:
            somaValores(&lista);
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
    }

    imprimeLista(&lista);
    

}

void listaVazia(TipoLista *Lista){
    Lista->primeiro = INICIOARRANJO;
    Lista->ultimo = Lista->primeiro;
}

void insere(TipoItem *item, TipoLista *Lista){
    if(Lista->ultimo >= MAXTAM){
        printf("Lista cheia\n");
    }else{
        Lista->item[Lista->ultimo] = *item;
        Lista->ultimo++;
    }
}

void populaLista(TipoLista *Lista){
    TipoItem item;

    strcpy(item.montadora, "Fiat");
    strcpy(item.modelo, "Uno");
    item.ano = 2010;
    item.valor = 15000.00;
    insere(&item, Lista);

    strcpy(item.montadora, "Ford");
    strcpy(item.modelo, "Fiesta");
    item.ano = 2012;
    item.valor = 13000.00;
    insere(&item, Lista);

    strcpy(item.montadora, "Chevrolet");
    strcpy(item.modelo, "Cruze");
    item.ano = 2015;
    item.valor = 20000.00;
    insere(&item, Lista);

    strcpy(item.montadora, "Volkswagen");
    strcpy(item.modelo, "Golf");
    item.ano = 2018;
    item.valor = 30000.00;
    insere(&item, Lista);
}

void imprimeLista(TipoLista *Lista){
    int i;
    for(i = 0; i < Lista->ultimo; i++){
        printf("Montadora: %s\n", Lista->item[i].montadora);
        printf("Modelo: %s\n", Lista->item[i].modelo);
        printf("Ano: %d\n", Lista->item[i].ano);
        printf("Valor: %.2f\n", Lista->item[i].valor);
        printf("\n");
    }
}

void somaValores(TipoLista *Lista){
    int i;
    float soma = 0;
    for(i = 0; i < Lista->ultimo; i++){
        soma += Lista->item[i].valor;
    }
    printf("Soma dos valores: %.2f\n", soma);
}









