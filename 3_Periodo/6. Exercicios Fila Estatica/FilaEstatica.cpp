/*Faça uma função que:
1. Receba um TipoItem e uma fila e retorne 1 se o item estiver presente na fila, ou 0, caso contrário.
2. Receba uma fila e retorne quantos itens possuem na fila.
3. Receba uma fila, um item e retorne a posição do vetor que o item se encontra na fila. Caso o item não
esteja presente na fila, a função deve retornar um valor negativo.
4. Receba uma fila, um item e retorne a posição que o item se encontra na fila (não a posição do vetor).
Caso o item não esteja presente na fila, a função deve retornar um valor negativo.
5. Receba uma fila estática e retorne o código do item com maior valor de saque.
6. Receba uma fila estática e retorne o valor do maior depósito realizado.
7. Receba uma fila estática e retorne quantas operações de pagamento foram feitas.
8. Receba uma fila estática e uma operação (char op[20]). Retorne o valor total dos itens para a operação
passada como parâmetro.
9. Receba uma fila estática e inverta a ordem da fila recebida utilizando uma pilha dinâmica. O TipoItem
será o mesmo para as duas estruturas.
10. Receba uma fila estática e retorne 1 se os itens estiverem em ordem crescente (considere o campo
cod), caso contrário retorne 0.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXTAM 100

typedef struct {
    int cod;
    float valor;
    char operacao[20]; // saque / deposito / pagamento
} TipoItem;

typedef struct {
    TipoItem itens[MAXTAM];
    int frente;
    int tras;
} FilaEstatica;

typedef struct Celula {
    TipoItem item;
    struct Celula *prox;
} Celula;

typedef struct {
    Celula *topo;
} PilhaDinamica;

void FFVazia(FilaEstatica *fila){
    fila->frente = 0;
    fila->tras = fila->frente;
}

int Vazia(FilaEstatica fila){
    return fila.frente == fila.tras;
}

int Cheia(FilaEstatica fila){
    return fila.tras == MAXTAM;
}

void FPVazia(PilhaDinamica *pilha){
    pilha->topo = (Celula*) malloc(sizeof(Celula));
    pilha->topo->prox = NULL;
}

int PVazia(PilhaDinamica pilha){
    return pilha.topo->prox == NULL;
}

void Empilha(TipoItem x, PilhaDinamica *pilha){
    Celula *novo = (Celula*) malloc(sizeof(Celula));
    novo->item = x;
    novo->prox = pilha->topo->prox;
    pilha->topo->prox = novo;
}

void Desempilha(PilhaDinamica *pilha, TipoItem *item){
    Celula *aux;
    if(PVazia(*pilha)){
        printf("Erro: pilha vazia\n");
        return;
    }
    aux = pilha->topo->prox;
    pilha->topo->prox = aux->prox;
    *item = aux->item;
    free(aux);
}


void Enfileira(TipoItem x, FilaEstatica *fila){
    if(Cheia(*fila)){
        printf("Erro: fila cheia\n");
        return;
    }
    fila->itens[fila->tras] = x;
    fila->tras++;
}

void Desenfileira(FilaEstatica *fila, TipoItem *item){
    if(Vazia(*fila)){
        printf("Erro: fila vazia\n");
        return;
    }
    *item = fila->itens[fila->frente];
    fila->frente++;
}

void exibeFila(FilaEstatica fila){
    int i;
    for(i = fila.frente; i < fila.tras; i++){
        printf("\n%d - %.2f - %s", fila.itens[i].cod, fila.itens[i].valor, fila.itens[i].operacao);
    }
}

int itemPresente(FilaEstatica fila, TipoItem item){
    int i;
    for(i = fila.frente; i < fila.tras; i++){
        if(fila.itens[i].cod == item.cod){
            return 1;
        }
    }
    return 0;
}

int quantidadeItens(FilaEstatica fila){
    return fila.tras - fila.frente;
}

int PosicaoVetor(FilaEstatica fila, TipoItem item){
    int i;
    for(i = fila.frente; i < fila.tras; i++){
        if(fila.itens[i].cod == item.cod){
            return i;
        }
    }
    return -1;
}

int posicaoFila(FilaEstatica fila, TipoItem item){
    int i;
    for(i = fila.frente; i < fila.tras; i++){
        if(fila.itens[i].cod == item.cod){
            return i - fila.frente;
        }
    }
    return -1;
}

int maiorSaque(FilaEstatica fila){
    int i, posicao = 0;
    float maior = fila.itens[0].valor;
    for(i = fila.frente; i < fila.tras; i++){
        if(fila.itens[i].valor > maior && strcmp(fila.itens[i].operacao, "saque") == 0){
            maior = fila.itens[i].valor;
            posicao = i;
        }
    }
    return fila.itens[posicao].cod;
}

float maiorDeposito(FilaEstatica fila){
    int i;
    float maior = fila.itens[0].valor;
    for(i = fila.frente; i < fila.tras; i++){
        if(fila.itens[i].valor > maior && strcmp(fila.itens[i].operacao, "deposito") == 0){
            maior = fila.itens[i].valor;
        }
    }
    return maior;
}

int operacoesPagamento(FilaEstatica fila){
    int i, cont = 0;
    for(i = fila.frente; i < fila.tras; i++){
        if(strcmp(fila.itens[i].operacao, "pagamento") == 0){
            cont++;
        }
    }
    return cont;
}

float valorTotalOperacao(FilaEstatica fila, char op[20]){
    int i;
    float total = 0;
    for(i = fila.frente; i < fila.tras; i++){
        if(strcmp(fila.itens[i].operacao, op) == 0){
            total += fila.itens[i].valor;
        }
    }
    return total;
}

void inverteFila(FilaEstatica *fila){
    PilhaDinamica pilha;
    TipoItem item;
    FPVazia(&pilha);
    while(!Vazia(*fila)){
        Desenfileira(fila, &item);
        Empilha(item, &pilha);
    }
    while(!PVazia(pilha)){
        Desempilha(&pilha, &item);
        Enfileira(item, fila);
    }
}

int ordemCrescente(FilaEstatica fila){
    int i;
    for(i = fila.frente; i < fila.tras - 1; i++){
        if(fila.itens[i].cod > fila.itens[i + 1].cod){
            return 0;
        }
    }
    return 1;
}

void popularFila(FilaEstatica *fila){
    TipoItem item;
    item.cod = 1;
    item.valor = 100;
    strcpy(item.operacao, "saque");
    Enfileira(item, fila);
    item.cod = 2;
    item.valor = 200;
    strcpy(item.operacao, "deposito");
    Enfileira(item, fila);
    item.cod = 3;
    item.valor = 300;
    strcpy(item.operacao, "pagamento");
    Enfileira(item, fila);
    item.cod = 4;
    item.valor = 400;
    strcpy(item.operacao, "saque");
    Enfileira(item, fila);
    item.cod = 5;
    item.valor = 500;
    strcpy(item.operacao, "deposito");
    Enfileira(item, fila);
    item.cod = 6;
    item.valor = 600;
    strcpy(item.operacao, "pagamento");
    Enfileira(item, fila);
}









int main(){
    FilaEstatica fila;
    TipoItem item;
    FFVazia(&fila);
    popularFila(&fila);
    int opcao;
    
    do{
        printf("\n1 - Exibir fila");
        printf("\n2 - Item presente");
        printf("\n3 - Quantidade de itens");
        printf("\n4 - Posicao vetor");
        printf("\n5 - Posicao fila");
        printf("\n6 - Maior saque");
        printf("\n7 - Maior deposito");
        printf("\n8 - Operacoes de pagamento");
        printf("\n9 - Valor total operacao");
        printf("\n10 - Inverter fila");
        printf("\n11 - Ordem crescente");
        printf("\n0 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao){
            case 1:
                exibeFila(fila);
                break;
            case 2:
                printf("\nDigite o codigo do item: ");
                scanf("%d", &item.cod);
                if(itemPresente(fila, item)){
                    printf("\nItem presente");
                }else{
                    printf("\nItem nao presente");
                }
                break;
            case 3:
                printf("\nQuantidade de itens: %d", quantidadeItens(fila));
                break;
            case 4:
                printf("\nDigite o codigo do item: ");
                scanf("%d", &item.cod);
                printf("\nPosicao vetor: %d", PosicaoVetor(fila, item));
                break;
            case 5:
                printf("\nDigite o codigo do item: ");
                scanf("%d", &item.cod);
                printf("\nPosicao fila: %d", posicaoFila(fila, item));
                break;
            case 6:
                printf("\nMaior saque: %d", maiorSaque(fila));
                break;
            case 7:
                printf("\nMaior deposito: %.2f", maiorDeposito(fila));
                break;
            case 8:
                printf("\nOperacoes de pagamento: %d", operacoesPagamento(fila));
                break;
            case 9:
                printf("\nDigite a operacao: ");
                scanf("%s", item.operacao);
                printf("\nValor total operacao: %.2f", valorTotalOperacao(fila, item.operacao));
                break;
            case 10:
                inverteFila(&fila);
                break;
            case 11:
                if(ordemCrescente(fila)){
                    printf("\nItens em ordem crescente");
                }else{
                    printf("\nItens nao em ordem crescente");
                }
                break;
        }
    
        printf("\n");
        system("pause");
        system("cls");

    }while(opcao != 0);


    return 0;
}



