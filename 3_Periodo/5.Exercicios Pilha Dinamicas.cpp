/*Exercicios de Pilha Dinamica*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 30

// Definição da estrutura da pilha e dos itens
typedef struct TipoItem {
    char caracter[MAXTAM];
    int valor;
    float real;
    
} TipoItem;

typedef struct Celula {
    TipoItem item;
    struct Celula *prox;
} Celula;

typedef struct TipoPilha {
    Celula *topo;
} TipoPilha;



// Função para inicializar a pilha
void inicializaPilha(TipoPilha *pilha) {
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(TipoPilha *pilha) {
    return (pilha->topo == NULL);
}

// Função para empilhar um item
void empilha(TipoPilha *pilha, TipoItem item) {
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->item = item;
    nova->prox = pilha->topo;
    pilha->topo = nova;
}

// Função para desempilhar um item
int desempilha(TipoPilha *pilha, TipoItem *item) {
    if (pilhaVazia(pilha)) return 0;
    Celula *aux = pilha->topo;
    *item = aux->item;
    pilha->topo = aux->prox;
    free(aux);
    return 1;
}

/*Receba duas pilhas e retorne 1 se as duas pilhas dinâmicas recebidas forem iguais, caso contrário
retorne 0. Use somente a função desempilha.*/

int comparaPilhas(TipoPilha *pilha1, TipoPilha *pilha2) {
    TipoItem item1, item2;
    while (!pilhaVazia(pilha1) && !pilhaVazia(pilha2)) {
        desempilha(pilha1, &item1);
        desempilha(pilha2, &item2);
        if (item1.valor != item2.valor) return 0;
    }
    return pilhaVazia(pilha1) && pilhaVazia(pilha2);
}

/*Receba um texto e retorne 1 se ele for palíndromo. Utilize pilha dinâmica para realizar a checagem.
Protótipo da Função: int verificaPalindromo(char texto[]);*/

int verificaPalindromo(char texto[]) {
    TipoPilha pilha;
    inicializaPilha(&pilha);
    TipoItem item;
    int tam = strlen(texto);
    for (int i = 0; i < tam; i++) {
        item.valor = texto[i];
        empilha(&pilha, item);
    }
    for (int i = 0; i < tam; i++) {
        desempilha(&pilha, &item);
        if (item.valor != texto[i]) return 0;
    }
    return 1;
}

/*Receba como parâmetros uma Pilha dinâmica e um elemento TipoItem. A função deve retornar a posição
de memória da Pilha em que se encontra a célula que possui o elemento informado. Caso o elemento
não seja encontrado, a função deve retornar NULL. Percorra a pilha sem desempilhar os itens.*/

Celula* buscaItem(TipoPilha *pilha, TipoItem item) {
    Celula *aux = pilha->topo;
    while (aux != NULL) {
        if (aux->item.valor == item.valor) return aux;
        aux = aux->prox;
    }
    return NULL;
}

/*Receba uma pilha e retorne 1 (um), caso a pilha esteja composta por todos os itens em ordem crescente,
ou 0 (zero), caso contrário. Use apenas a função desempilha para acessar os itens da pilha.*/

int verificaOrdemCrescente(TipoPilha *pilha) {
    TipoItem item, itemAnterior;
    if (pilhaVazia(pilha)) return 1;
    desempilha(pilha, &itemAnterior);
    while (!pilhaVazia(pilha)) {
        desempilha(pilha, &item);
        if (item.valor < itemAnterior.valor) return 0;
        itemAnterior = item;
    }
    return 1;
}

/*Receba duas pilhas (P1 e P2), um item (TipoItem item) e retorne 1 (um), caso o item esteja presente nas
duas pilhas, ou 0 (zero), caso contrário. Use apenas a função desempilha para acessar os itens da pilha.*/

int verificaItemNasDuasPilhas(TipoPilha *pilha1, TipoPilha *pilha2, TipoItem item) {
    TipoItem itemAux;
    int encontrou1 = 0, encontrou2 = 0;
    while (!pilhaVazia(pilha1)) {
        desempilha(pilha1, &itemAux);
        if (itemAux.valor == item.valor) encontrou1 = 1;
    }
    while (!pilhaVazia(pilha2)) {
        desempilha(pilha2, &itemAux);
        if (itemAux.valor == item.valor) encontrou2 = 1;
    }
    return encontrou1 && encontrou2;
}

/*Receba uma pilha e retire todos os itens com uma vogal. A forma para retirada dos itens é livre.*/

void retiraVogais(TipoPilha *pilha) {
    TipoPilha pilhaAux;
    inicializaPilha(&pilhaAux);
    TipoItem item;
    while (!pilhaVazia(pilha)) {
        desempilha(pilha, &item);
        if (item.valor != 'a' && item.valor != 'e' && item.valor != 'i' && item.valor != 'o' && item.valor != 'u') {
            empilha(&pilhaAux, item);
        }
    }
    while (!pilhaVazia(&pilhaAux)) {
        desempilha(&pilhaAux, &item);
        empilha(pilha, item);
    }
}

/*Elabore uma função FuraPilha (TipoPilha *Pilha; TipoApontador p; TipoItem item) que insere um item
recebido após (na direção topo -> fundo) a posição apontada por p. Após a inserção do item, a Pilha
dinâmica deve obedecer aos critérios estruturais vistos para a estrutura.*/

void furaPilha(TipoPilha *pilha, Celula *p, TipoItem item) {
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
}

/*Receba um texto e use uma pilha para inverter a ordem das letras de cada palavra do texto, preservando
a ordem das palavras. Por exemplo, dado o texto ESTE EXERCICIO E MUITO FACIL, a saída deve ser
ETSE OICICREXE E OTIUM LICAF.*/

void invertePalavras(TipoPilha *pilha, char texto[]) {
    TipoItem item;
    int tam = strlen(texto);
    for (int i = 0; i < tam; i++) {
        if (texto[i] != ' ') {
            item.valor = texto[i];
            empilha(pilha, item);
        } else {
            while (!pilhaVazia(pilha)) {
                desempilha(pilha, &item);
                printf("%c", item.valor);
            }
            printf(" ");
        }
    }
    while (!pilhaVazia(pilha)) {
        desempilha(pilha, &item);
        printf("%c", item.valor);
    }
    printf("\n");
}


/*Receba uma Lista estática e inverta a ordem do itens da lista utilizando uma Pilha Dinâmica.*/

void inverteLista(TipoPilha *pilha, TipoItem lista[], int tam) {
    TipoItem item;
    for (int i = 0; i < tam; i++) {
        item = lista[i];
        empilha(pilha, item);
    }
    for (int i = 0; i < tam; i++) {
        desempilha(pilha, &item);
        lista[i] = item;
    }
}

/*Receba uma lista dinâmica com números inteiros e gere 2 pilhas dinâmicas: a primeira contendo as
células cujo conteúdo seja par e a segunda cujo conteúdo seja ímpar. Protótipo da Função: void
gerarPilhasParImpar(TipoLista lista, TipoPilha *pilhaPar, TipoPilha *pilhaImpar);*/

void gerarPilhasParImpar(TipoPilha *pilha, TipoPilha *pilhaPar, TipoPilha *pilhaImpar) {
    TipoItem item;
    TipoPilha pilhaAux;
    inicializaPilha(&pilhaAux);
    while (!pilhaVazia(pilha)) {
        desempilha(pilha, &item);
        if (item.valor % 2 == 0) {
            empilha(pilhaPar, item);
        } else {
            empilha(pilhaImpar, item);
        }
        empilha(&pilhaAux, item);
    }
    while (!pilhaVazia(&pilhaAux)) {
        desempilha(&pilhaAux, &item);
        empilha(pilha, item);
    }
}

int main() {
    TipoPilha pilha1, pilha2;
    TipoItem item;
    inicializaPilha(&pilha1);
    inicializaPilha(&pilha2);
    item.valor = 1;
    empilha(&pilha1, item);
    item.valor = 2;
    empilha(&pilha1, item);
    item.valor = 3;
    empilha(&pilha1, item);
    item.valor = 1;
    empilha(&pilha2, item);
    item.valor = 2;
    empilha(&pilha2, item);
    item.valor = 3;
    empilha(&pilha2, item);
    printf("%d\n", comparaPilhas(&pilha1, &pilha2));
    char texto[] = "arara";
    printf("%d\n", verificaPalindromo(texto));
    Celula *celula = buscaItem(&pilha1, item);
    if (celula != NULL) {
        printf("%p\n", celula);
    }
    printf("%d\n", verificaOrdemCrescente(&pilha1));
    printf("%d\n", verificaItemNasDuasPilhas(&pilha1, &pilha2, item));
    retiraVogais(&pilha1);
    invertePalavras(&pilha1, texto);
    TipoItem lista[] = {{1}, {2}, {3}, {4}, {5}};
    inverteLista(&pilha1, lista, 5);
    TipoPilha pilhaPar, pilhaImpar;
    inicializaPilha(&pilhaPar);
    inicializaPilha(&pilhaImpar);
    gerarPilhasParImpar(&pilha1, &pilhaPar, &pilhaImpar);
    return 0;
}













