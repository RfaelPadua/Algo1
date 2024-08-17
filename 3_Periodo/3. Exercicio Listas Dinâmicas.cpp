#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TipoItem{
    int codigo;
    char descricao[7];
    float valor;
};

typedef struct TipoCelula* TipoApontador;

struct TipoCelula{
    TipoItem item;
    TipoApontador Prox;
};

struct TipoLista{
    TipoApontador primeiro, ultimo;
};

void FazerListaVazia(TipoLista *Lista);

void inserir(TipoItem x, TipoLista *Lista);

void populaLista(TipoLista *Lista);

TipoCelula* EncontrarCarroPorCodigo(TipoLista *Lista, int codigo);

TipoCelula* EncontrarCarroPorDescricao(TipoLista *Lista, char* descricao);

void SomarValores(TipoLista *Lista);

int ContarItensCodigoPar(TipoLista *Lista);

int CompararListas(TipoLista *Lista1, TipoLista *Lista2);



int main(){
    
    TipoLista Lista;
    FazerListaVazia(&Lista);

    populaLista(&Lista);


    while(1){
        printf("1-A\n");
        printf("2-B\n");
        printf("0-Sair\n");

        int op;
        scanf("%d", &op);

        if(op == 0){
            printf("Saindo...\n");
            system("pause");
            return 0;
        }else if(op == 1){
            int codigo;
            printf("Digite o codigo do carro: ");

            scanf("%d", &codigo);
            TipoCelula* carro = EncontrarCarroPorCodigo(&Lista, codigo);
            if(carro != NULL){
                printf("Carro encontrado: %s\n", carro->item.descricao);
            }else{
                printf("Carro nao encontrado\n");
            }
        }else if(op == 2){
            char straux[7];
            printf("Digite a descriao do carro:\n");
            scanf("%s", straux);
            TipoCelula* carro = EncontrarCarroPorDescricao(&Lista, straux);
            if(carro != NULL){
                printf("Carro encontrado: %d\n", carro->item.codigo);
            }else{
                printf("Carro nao encontrado!\n");
            }
        }else if(op == 3){

        }else{
            printf("Opcao invalida\n");
        } 

        system("pause");
        system("cls");
    }


  
}

void FazerListaVazia(TipoLista *Lista){
    Lista->primeiro = (TipoApontador) malloc(sizeof(struct TipoCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->Prox = NULL;
}

int Vazia(TipoLista *Lista){
    return (Lista->primeiro == Lista->ultimo);
}
void inserir(TipoItem x, TipoLista *Lista){
    Lista->ultimo->Prox = (TipoApontador) malloc(sizeof(struct TipoCelula));
    Lista->ultimo = Lista->ultimo->Prox;
    Lista->ultimo->item = x;
    Lista->ultimo->Prox = NULL;
}

void populaLista(TipoLista *Lista){
    TipoItem Item;

    for(int i = 0; i < 10; i++){
        Item.codigo = i;
        sprintf(Item.descricao, "Item %d", i);
        Item.valor = i * 10.0;
        inserir(Item, Lista);
    }

}

TipoCelula* EncontrarCarroPorCodigo(TipoLista *Lista, int codigo){
    TipoCelula* celulaAtual = Lista->primeiro;
    while(celulaAtual != NULL){
        if(celulaAtual -> item.codigo == codigo){
            return celulaAtual;
        }
        celulaAtual = celulaAtual -> Prox;
    }
    return NULL;
}

TipoCelula* EncontrarCarroPorDescricao(TipoLista *Lista, char* descricao){
    TipoCelula* celulaAtual = Lista->primeiro;
    while(celulaAtual != NULL){
        if(strcmp(celulaAtual->item.descricao, descricao)){
            return celulaAtual;
        }
        celulaAtual = celulaAtual->Prox;
    }
    return NULL;
}

void SomarValores(TipoLista *Lista){
    TipoCelula* celulaAtual = Lista->primeiro;
    float soma = 0;
    while(celulaAtual != NULL){
        soma += celulaAtual->item.valor;
        celulaAtual = celulaAtual->Prox;
    }
    printf("Soma dos valores: %.2f\n", soma);
}

int ContarItensCodigoPar(TipoLista *Lista) {
    int contador = 0;
    TipoCelula* celulaAtual = Lista->primeiro;
    while (celulaAtual != NULL) {
        if (celulaAtual->item.codigo % 2 == 0) {
            contador++;
        }
        celulaAtual = celulaAtual->Prox;
    }
    return contador;
}

int CompararListas(TipoLista *Lista1, TipoLista *Lista2) {
    int contagem1 = ContarItensCodigoPar(Lista1);
    int contagem2 = ContarItensCodigoPar(Lista2);

    if (contagem1 > contagem2) {
        return 1;
    } else if (contagem1 < contagem2) {
        return 2;
    } else {
        return 0; // Empate
    }
}

void InserirAposPosicao(TipoLista *Lista, TipoCelula *Posicao, TipoItem Item) {
    TipoCelula* NovaCelula = (TipoCelula*) malloc(sizeof(TipoCelula));
    NovaCelula->item = Item;

    if (Posicao == NULL) { // Inserir no início da lista
        NovaCelula->Prox = Lista->primeiro;
        Lista->primeiro = NovaCelula;
        if (Lista->ultimo == NULL) { // Se a lista estava vazia
            Lista->ultimo = NovaCelula;
        }
    } else if (Posicao == Lista->ultimo) { // Inserir no final da lista
        Posicao->Prox = NovaCelula;
        NovaCelula->Prox = NULL;
        Lista->ultimo = NovaCelula;
    } else { // Inserir no meio da lista
        NovaCelula->Prox = Posicao->Prox;
        Posicao->Prox = NovaCelula;
    }
}

void TrocarItens(TipoLista *Lista, TipoCelula *PosicaoP, TipoCelula *PosicaoQ) {
    // Verifica se as posições são válidas
    if (PosicaoP == NULL || PosicaoQ == NULL) {
        printf("Posição inválida.\n");
        return;
    }

    // Troca os itens das posições P e Q
    TipoItem Temp = PosicaoP->item;
    PosicaoP->item = PosicaoQ->item;
    PosicaoQ->item = Temp;
}

void InserirNaCabeca(TipoLista *Lista, TipoItem Item) {
    TipoCelula* NovaCabeca = (TipoCelula*) malloc(sizeof(TipoCelula));
    NovaCabeca->item = Item;

    // Ajusta o ponteiro para a próxima célula
    NovaCabeca->Prox = Lista->primeiro;

    // Ajusta o ponteiro primeiro da lista
    Lista->primeiro = NovaCabeca;

    // Se a lista estava vazia, ajusta o ponteiro ultimo também
    if (Lista->ultimo == NULL) {
        Lista->ultimo = NovaCabeca;
    }
}

void Retira(TipoCelula *p, TipoLista *Lista, TipoItem *Item) {
    if (p == NULL || p->Prox == NULL) {
        printf("Erro: Posicao invalida.\n");
        return;
    }

    TipoCelula *anterior = Lista->primeiro;
    while (anterior != NULL && anterior->Prox != p) {
        anterior = anterior->Prox;
    }

    if (anterior == NULL) {
        printf("Erro: Posicao nao encontrada.\n");
        return;
    }

    *Item = p->item;
    anterior->Prox = p->Prox;
    if (p == Lista->ultimo) {
        Lista->ultimo = anterior;
    }
    free(p);
}

void ExcluirNegativos(TipoLista *Lista) {
    TipoCelula *celulaAtual = Lista->primeiro;
    TipoCelula *celulaAnterior = NULL;
    TipoItem item;

    while (celulaAtual != NULL) {
        if (celulaAtual->item.codigo < 0) {
            if (celulaAnterior == NULL) { // Primeiro elemento da lista
                Lista->primeiro = celulaAtual->Prox;
                Retira(celulaAtual, Lista, &item);
                celulaAtual = Lista->primeiro;
            } else {
                celulaAnterior->Prox = celulaAtual->Prox;
                Retira(celulaAtual, Lista, &item);
                celulaAtual = celulaAnterior->Prox;
            }
            if (celulaAtual == NULL) { // Último elemento da lista
                Lista->ultimo = celulaAnterior;
            }
        } else {
            celulaAnterior = celulaAtual;
            celulaAtual = celulaAtual->Prox;
        }
    }
}

int ContarItens(TipoLista *Lista) {
    int contador = 0;
    TipoCelula* celulaAtual = Lista->primeiro;
    while (celulaAtual != NULL) {
        contador++;
        celulaAtual = celulaAtual->Prox;
    }
    return contador;
}

int CompararListas(TipoLista *Lista1, TipoLista *Lista2) {
    int contagem1 = ContarItens(Lista1);
    int contagem2 = ContarItens(Lista2);

    if (contagem1 > contagem2) {
        return 1;
    } else if (contagem1 < contagem2) {
        return 2;
    } else {
        return 0; // Empate
    }
}

int EstaEmOrdemCrescente(TipoLista *Lista) {
    if (Lista->primeiro == NULL) {
        return 1; // Uma lista vazia é considerada ordenada
    }

    TipoCelula* celulaAtual = Lista->primeiro->Prox;
    int valorAnterior = Lista->primeiro->item.valor;

    while (celulaAtual != NULL) {
        if (celulaAtual->item.valor < valorAnterior) {
            return 0; // Encontrou um item que é menor que o item anterior
        }
        valorAnterior = celulaAtual->item.valor;
        celulaAtual = celulaAtual->Prox;
    }

    return 1; // Todos os itens estão em ordem crescente
}

void MoverMenorParaInicio(TipoLista *Lista) {
    if (Lista->primeiro == NULL) {
        return; // A lista está vazia
    }

    // Encontra o item de menor valor e sua posição
    TipoCelula* celulaMenor = Lista->primeiro;
    TipoCelula* celulaAtual = Lista->primeiro->Prox;
    while (celulaAtual != NULL) {
        if (celulaAtual->item.valor < celulaMenor->item.valor) {
            celulaMenor = celulaAtual;
        }
        celulaAtual = celulaAtual->Prox;
    }

    // Remove o item de menor valor da lista
    TipoItem itemMenor;
    Retira(celulaMenor, Lista, &itemMenor);

    // Insere o item de menor valor no início da lista
    InserirNaCabeca(Lista, itemMenor);
}

void CombinarListas(TipoLista *Lista1, TipoLista *Lista2, TipoLista *Lista3) {
    TipoItem item;

    // Retira os itens da Lista1 e os insere na Lista3
    while (!Vazia(Lista1)) {
        Retira(Lista1->primeiro, Lista1, &item);
        inserir(item, Lista3);
    }

    // Retira os itens da Lista2 e os insere na Lista3
    while (!Vazia(Lista2)) {
        Retira(Lista2->primeiro, Lista2, &item);
        inserir(item, Lista3);
    }
}

void CombinarItensImpares(TipoLista *Lista1, TipoLista *Lista2, TipoLista *Lista3) {
    TipoCelula* celulaAtual;

    // Percorre a Lista1 e insere os itens ímpares na Lista3
    celulaAtual = Lista1->primeiro;
    while (celulaAtual != NULL) {
        if (celulaAtual->item.codigo % 2 != 0) {
            inserir(celulaAtual->item, Lista3);
        }
        celulaAtual = celulaAtual->Prox;
    }

    // Percorre a Lista2 e insere os itens ímpares na Lista3
    celulaAtual = Lista2->primeiro;
    while (celulaAtual != NULL) {
        if (celulaAtual->item.codigo % 2 != 0) {
            inserir(celulaAtual->item, Lista3);
        }
        celulaAtual = celulaAtual->Prox;
    }
}

void IntercalarListas(TipoLista *Lista1, TipoLista *Lista2, TipoLista *Lista3) {
    TipoCelula* celulaAtual1 = Lista1->primeiro;
    TipoCelula* celulaAtual2 = Lista2->primeiro;

    while (celulaAtual1 != NULL || celulaAtual2 != NULL) {
        if (celulaAtual1 != NULL) {
            inserir(celulaAtual1->item, Lista3);
            celulaAtual1 = celulaAtual1->Prox;
        }
        if (celulaAtual2 != NULL) {
            inserir(celulaAtual2->item, Lista3);
            celulaAtual2 = celulaAtual2->Prox;
        }
    }
}




