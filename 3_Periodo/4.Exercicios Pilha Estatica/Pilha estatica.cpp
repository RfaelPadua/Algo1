#include <stdio.h>
#include <string.h>

#define MAXTAM 100
#define INT_MIN -2147483648

typedef int TipoApontador, TipoChave;

typedef struct{
    TipoChave chave;
    char nome[MAXTAM];
    float valor;
}TipoItem;

typedef struct{
    TipoItem item[MAXTAM];
    TipoApontador topo;
}TipoPilha;

void empilha(TipoPilha *pilha, TipoItem item){
    if(pilha->topo >= MAXTAM){
        printf("Pilha cheia!!\n");
        return;
    }

    pilha->item[pilha->topo] = item;
    pilha->topo++;
}

TipoItem desempilha(TipoPilha *pilha){
    TipoItem item;

    if(pilha->topo == 0){
        printf("Pilha vazia!!\n");
        return item;
    }

    pilha->topo--;
    return pilha->item[pilha->topo];
}

void FazerPilhaVazia(TipoPilha *pilha){
    pilha->topo = 0;
}

int testarParidadeParenteses(const char* expressao) {
    TipoPilha pilha;
    FazerPilhaVazia(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            TipoItem item;
            item.chave = '(';
            empilha(&pilha, item);
        } else if (expressao[i] == ')') {
            if (pilha.topo == 0) {
                return 0; 
            } else {
                desempilha(&pilha);
            }
        }
    }

    if (pilha.topo == 0) {
        return 1; 
    } else {
        return 0; 
    }
}

void empilharVogais(const char* palavra, TipoPilha* pilha) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' ||
            palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U') {
            TipoItem item;
            item.chave = palavra[i];
            empilha(pilha, item);
        }
    }
}

void inverterString(const char* palavra, TipoPilha* pilha) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        TipoItem item;
        item.chave = palavra[i];
        empilha(pilha, item);
    }
}

int pilhasIguais(TipoPilha* pilha1, TipoPilha* pilha2) {
    if (pilha1->topo != pilha2->topo) {
        return 0; 
    }

    while (pilha1->topo > 0) {
        TipoItem item1 = desempilha(pilha1);
        TipoItem item2 = desempilha(pilha2);

        if (item1.chave != item2.chave) {
            return 0; 
        }
    }

    return 1; 
}

void erguePilha(TipoPilha* pilha, TipoApontador p, TipoItem item) {
    TipoPilha aux;
    FazerPilhaVazia(&aux);

    while (pilha->topo > p) {
        TipoItem auxItem = desempilha(pilha);
        empilha(&aux, auxItem);
    }

    empilha(pilha, item);

    while (aux.topo > 0) {
        TipoItem auxItem = desempilha(&aux);
        empilha(pilha, auxItem);
    }
}

int pilhaEmOrdemCrescente(TipoPilha* pilha) {
    TipoPilha aux;
    FazerPilhaVazia(&aux);

    int valorAnterior = INT_MIN;

    while (pilha->topo > 0) {
        TipoItem item = desempilha(pilha);
        empilha(&aux, item);

        if (item.chave < valorAnterior) {
            return 0; 
        }

        valorAnterior = item.chave;
    }

    while (aux.topo > 0) {
        TipoItem item = desempilha(&aux);
        empilha(pilha, item);
    }

    return 1; 
}

int itemPresenteEmAmbasPilhas(TipoPilha* pilha1, TipoPilha* pilha2, TipoItem item) {
    TipoPilha aux1, aux2;
    FazerPilhaVazia(&aux1);
    FazerPilhaVazia(&aux2);

    int encontrado1 = 0;
    int encontrado2 = 0;

    while (pilha1->topo > 0) {
        TipoItem auxItem = desempilha(pilha1);
        empilha(&aux1, auxItem);

        if (auxItem.chave == item.chave) {
            encontrado1 = 1;
        }
    }

    while (pilha2->topo > 0) {
        TipoItem auxItem = desempilha(pilha2);
        empilha(&aux2, auxItem);

        if (auxItem.chave == item.chave) {
            encontrado2 = 1;
        }
    }

    while (aux1.topo > 0) {
        TipoItem auxItem = desempilha(&aux1);
        empilha(pilha1, auxItem);
    }

    while (aux2.topo > 0) {
        TipoItem auxItem = desempilha(&aux2);
        empilha(pilha2, auxItem);
    }

    if (encontrado1 && encontrado2) {
        return 1; 
    } else {
        return 0; 
    }
}

int pilhasIguaisDesempilha(TipoPilha* pilha1, TipoPilha* pilha2) {
    if (pilha1->topo != pilha2->topo) {
        return 0; 
    }

    TipoPilha aux1, aux2;
    FazerPilhaVazia(&aux1);
    FazerPilhaVazia(&aux2);

    int iguais = 1;

    while (pilha1->topo > 0) {
        TipoItem item1 = desempilha(pilha1);
        TipoItem item2 = desempilha(pilha2);

        empilha(&aux1, item1);
        empilha(&aux2, item2);

        if (item1.chave != item2.chave) {
            iguais = 0; 
        }
    }

    while (aux1.topo > 0) {
        TipoItem item1 = desempilha(&aux1);
        empilha(pilha1, item1);
    }

    while (aux2.topo > 0) {
        TipoItem item2 = desempilha(&aux2);
        empilha(pilha2, item2);
    }

    return iguais;
}


int main(){
    TipoPilha pilha1, pilha2;
    FazerPilhaVazia(&pilha1);
    FazerPilhaVazia(&pilha2);

    // Testar a funçao empilha
    TipoItem item1;
    item1.chave = 1;
    empilha(&pilha1, item1);

    TipoItem item2;
    item2.chave = 2;
    empilha(&pilha1, item2);

    TipoItem item3;
    item3.chave = 3;
    empilha(&pilha1, item3);

    // Testar a funçao desempilha
    TipoItem itemDesempilhado = desempilha(&pilha1);
    printf("Item desempilhado: %d\n", itemDesempilhado.chave);

    // Testar a funçao testarParidadeParenteses
    const char* expressao1 = "((()))";
    int paridade1 = testarParidadeParenteses(expressao1);
    printf("Paridade da expressao 1: %d\n", paridade1);

    const char* expressao2 = "(()))";
    int paridade2 = testarParidadeParenteses(expressao2);
    printf("Paridade da expressao 2: %d\n", paridade2);

    // Testar a funçao empilharVogais
    const char* palavra1 = "Hello World";
    empilharVogais(palavra1, &pilha1);

    const char* palavra2 = "Rafael de Padua";
    empilharVogais(palavra2, &pilha2);

    // Testar a funçao inverterString
    const char* palavra3 = "Hello World";
    inverterString(palavra3, &pilha1);

    const char* palavra4 = "Rafael de Padua";
    inverterString(palavra4, &pilha2);

    // Testar a funçao pilhasIguais
    int iguais1 = pilhasIguais(&pilha1, &pilha2);
    printf("Pilhas 1 e 2 sao iguais: %d\n", iguais1);

    int iguais2 = pilhasIguais(&pilha1, &pilha1);
    printf("Pilhas 1 e 1 sao iguais: %d\n", iguais2);

    // Testar a funçao erguePilha
    TipoItem item4;
    item4.chave = 4;
    erguePilha(&pilha1, 1, item4);

    // Testar a funçao pilhaEmOrdemCrescente
    int ordem1 = pilhaEmOrdemCrescente(&pilha1);
    printf("Pilha 1 esta em ordem crescente: %d\n", ordem1);

    int ordem2 = pilhaEmOrdemCrescente(&pilha2);
    printf("Pilha 2 esta em ordem crescente: %d\n", ordem2);

    // Testar a funçao itemPresenteEmAmbasPilhas
    TipoItem item5;
    item5.chave = 5;
    int presente1 = itemPresenteEmAmbasPilhas(&pilha1, &pilha2, item5);
    printf("Item 5 esta presente nas duas pilhas: %d\n", presente1);

    TipoItem item6;
    item6.chave = 6;
    int presente2 = itemPresenteEmAmbasPilhas(&pilha1, &pilha2, item6);
    printf("Item 6 esta presente nas duas pilhas: %d\n", presente2);

    // Testar a funçao pilhasIguaisDesempilha
    int iguaisDesempilha1 = pilhasIguaisDesempilha(&pilha1, &pilha2);
    printf("Pilhas 1 e 2 sao iguais (desempilhando): %d\n", iguaisDesempilha1);

    int iguaisDesempilha2 = pilhasIguaisDesempilha(&pilha1, &pilha1);
    printf("Pilhas 1 e 1 sao iguais (desempilhando): %d\n", iguaisDesempilha2);

    return 0;
}