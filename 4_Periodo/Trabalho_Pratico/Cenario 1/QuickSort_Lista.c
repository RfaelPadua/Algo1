#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/resource.h>

//--------------------------------------------------------------------------

// Armazena os dados
typedef struct TipoItem {
    int inteiro;
} TipoItem;

// Faz a conexão entre as células
typedef struct TipoCelula {
    TipoItem item;
    unsigned long long int indice;        // Índice da posição do item na lista
    struct TipoCelula* frente;  // Ponteiro para a próxima célula
    struct TipoCelula* tras;    // Ponteiro para a célula anterior
} TipoCelula;

// Armazena o primeiro e último item da lista
typedef struct TipoLista {
    TipoCelula* inicio;
    TipoCelula* fim;
    int tamanho;  // Quantidade de itens na lista
} TipoLista;

//--------------------------------------------------------------------------

// Função para inicializar a lista
void IniciaLstDup(TipoLista *lista);

// Função para verificar se a lista está vazia
int VaziaLstDup(TipoLista lista);

// Função para inserir um item em uma posição específica
void InserirNaPosicao(TipoLista *lista, TipoItem item, int pos);

// Função para remover um item da lista
void RemoveNaPosicao(TipoLista *lista, int pos, TipoItem *itemRemovido);

// Função para exibir a lista
void ExibeLista(TipoLista lista);

//--------------------------------------------------------------------------

// Preenche a lista com valores aleatórios
void preencherLstDupAleatorio(TipoLista *lista, int qtdNums);

// Faz a troca entre dois elementos
void troca(TipoCelula *a, TipoCelula *b);

// Particiona a lista e retorna o índice do pivô
int particiona(TipoLista *lista, int esquerda, int direita, unsigned long long int *compChaves);

// Função principal do QuickSort
void quicksort(TipoLista *lista, int esquerda, int direita, unsigned long long int *compChaves);

void ordenarLista(TipoLista* lista, unsigned long long int* compChaves);

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], char argumentos[], double tempoUsuario, double tempoSistema, unsigned long long int compChaves);

//--------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    TipoLista lista;
    struct rusage inicio, fim; // Estruturas para analisar o uso de CPU
    unsigned long long int compChaves; // Quantidade de comparações de chaves

    if (argc != 3) { // Informações recebidas fora do padrão
        printf("Uso: %s <quantidade> <arquivo>\n", argv[0]);
        return 1;
    }

    char *nomeArquivo = argv[2];
    char *ptrFim;
    long int qtdNums = strtol(argv[1], &ptrFim, 10);

    if (*ptrFim != '\0') { // Erro durante a conversao do valor recebido
        printf("Erro: '%s' nao eh um numero valido\n", argv[1]);
        return 1;
    }

    if (qtdNums <= 0 || qtdNums > INT_MAX) { // Valor fora do intervalo estipulado
        printf("Numero fora do intervalo permitido\n");
        return 1;
    }

    IniciaLstDup(&lista);
    preencherLstDupAleatorio(&lista, qtdNums); // Preenche a lista com valores aleatórios

    // Obtém o tempo antes da execução do quicksort
    if (getrusage(RUSAGE_SELF, &inicio) != 0) { // Erro de recebimento das informações
        perror("Erro durante a obtencao das informacoes\n");

        while(!VaziaLstDup(lista)) { // Esvazia a lista
            TipoItem i;
            RemoveNaPosicao(&lista, 0, &i);
        }

        return 1;
    }

    quicksort(&lista, 0, lista.tamanho - 1, &compChaves); // Ordena a lista

    // Obtém o tempo após a execução do quicksort
    if (getrusage(RUSAGE_SELF, &fim) != 0) { // Erro de recebimento das informações
        perror("Erro durante a obtencao das informacoes\n");

        while(!VaziaLstDup(lista)) { // Esvazia a lista
            TipoItem i;
            RemoveNaPosicao(&lista, 0, &i);
        }

        return 1;
    }

    while(!VaziaLstDup(lista)) { // Esvazia a lista
        TipoItem i;
        RemoveNaPosicao(&lista, 0, &i);
    }

    // Calcula o tempo de CPU gasto (segundos)
    double tempoUsuario = (fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) + (fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1e6;
    double tempoSistema = (fim.ru_stime.tv_sec - inicio.ru_stime.tv_sec) + (fim.ru_stime.tv_usec - inicio.ru_stime.tv_usec) / 1e6; 

    resultadosArquivo(nomeArquivo, argv[1], tempoUsuario, tempoSistema, compChaves); // Insere os valores no arquivo

    return 0;
}

//--------------------------------------------------------------------------

// Inicia uma lista duplamente encadeada
void IniciaLstDup(TipoLista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

// Verifica se a lista está vazia
int VaziaLstDup(TipoLista lista) {
    return lista.inicio == NULL;
}

// Insere um item na posição específica da lista
void InserirNaPosicao(TipoLista *lista, TipoItem item, int pos) {
    if (pos < 0 || pos > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }

    // Cria a nova célula
    TipoCelula* novaCelula = (TipoCelula*) malloc(sizeof(TipoCelula));
    if (novaCelula == NULL) {
        perror("Erro de alocação de memória");
        exit(1);
    }
    novaCelula->item = item;
    novaCelula->indice = pos;  // Atribui o índice
    novaCelula->frente = NULL;
    novaCelula->tras = NULL;

    if (pos == 0) {  // Inserir no início
        if (VaziaLstDup(*lista)) {
            lista->inicio = novaCelula;
            lista->fim = novaCelula;
        } else {
            novaCelula->frente = lista->inicio;
            lista->inicio->tras = novaCelula;
            lista->inicio = novaCelula;
        }
    } else if (pos == lista->tamanho) {  // Inserir no final
        novaCelula->tras = lista->fim;
        lista->fim->frente = novaCelula;
        lista->fim = novaCelula;
    } else {  // Inserir no meio
        TipoCelula* temp = lista->inicio;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->frente;
        }
        novaCelula->frente = temp->frente;
        novaCelula->tras = temp;
        temp->frente->tras = novaCelula;
        temp->frente = novaCelula;
    }
    
    /*// Atualiza os índices dos itens à direita
    TipoCelula* temp = novaCelula->frente;
    while (temp != NULL) {
        temp->indice += 1;  // Aumenta o índice dos itens à direita
        temp = temp->frente;
    }*/

    lista->tamanho++;
}


// Remove um item da lista com base no índice
void RemoveNaPosicao(TipoLista *lista, int pos, TipoItem *itemRemovido) {
    if (pos < 0 || pos >= lista->tamanho) {
        printf("Posição inválida para remoção!\n");
        return;
    }

    TipoCelula* temp = lista->inicio;

    // Encontra a célula na posição desejada
    for (int i = 0; i < pos; i++) {
        temp = temp->frente;
    }

    // Copia os dados do item para o ponteiro recebido
    *itemRemovido = temp->item;

    // Atualiza os ponteiros para remover a célula
    if (temp->tras == NULL) { // Se for o primeiro item
        lista->inicio = temp->frente;
        if (lista->inicio != NULL) {
            lista->inicio->tras = NULL;
        }
    } else {
        temp->tras->frente = temp->frente;
    }

    if (temp->frente == NULL) { // Se for o último item
        lista->fim = temp->tras;
        if (lista->fim != NULL) {
            lista->fim->frente = NULL;
        }
    } else {
        temp->frente->tras = temp->tras;
    }
    /*
    // Atualiza os índices dos itens à direita
    TipoCelula* next = temp->frente;
    while (next != NULL) {
        next->indice -= 1;  // Ajusta os índices
        next = next->frente;
    }*/

    free(temp); // Libera a memória da célula removida
    lista->tamanho--; // Atualiza o tamanho da lista
}


// Exibe a lista e seus índices
void ExibeLista(TipoLista lista) {
    TipoCelula* temp = lista.inicio;
    printf("Valores armazenados:\n");
    while (temp != NULL) {
        printf("Índice: %llu, Valor: %d\n", temp->indice, temp->item.inteiro);
        temp = temp->frente;
    }
    printf("\n");
}

//--------------------------------------------------------------------------

// Preenche a lista com valores aleatórios
void preencherLstDupAleatorio(TipoLista *lista, int qtdNums) {
    srand(time(NULL));
    
    for (int i = 0; i < qtdNums; i++) {
        TipoItem item;
        item.inteiro = rand() % 100;  // Gera um valor aleatório de 0 a 999
        InserirNaPosicao(lista, item, i);  // Insere na posição i
    }
}

// Faz a troca entre dois elementos
void troca(TipoCelula *a, TipoCelula *b) {
    if (a == NULL || b == NULL) {
        fprintf(stderr, "Erro: Tentativa de trocar elementos nulos.\n");
        exit(1);
    }
    TipoItem temp = a->item;
    a->item = b->item;
    b->item = temp;
}

// Função para obter a célula na posição específica
TipoCelula *obterCelula(TipoLista *lista, int posicao) {
    if (lista == NULL || posicao < 0 || posicao >= lista->tamanho) {
        return NULL; // Posição inválida
    }
    TipoCelula *celula = lista->inicio;
    for (int i = 0; i < posicao && celula != NULL; i++) {
        celula = celula->frente;
    }
    return celula;
}

// Particiona a lista e retorna o índice do pivô
int particiona(TipoLista *lista, int esquerda, int direita, unsigned long long int *compChaves) {
    TipoCelula *celulaEsquerda = obterCelula(lista, esquerda);
    TipoCelula *celulaDireita = obterCelula(lista, direita);

    if (celulaEsquerda == NULL || celulaDireita == NULL) {
        fprintf(stderr, "Erro: Índices fora dos limites da lista.\n");
        exit(1);
    }

    int pivo = celulaEsquerda->item.inteiro;
    TipoCelula *i = celulaEsquerda->frente;
    TipoCelula *j = celulaDireita;

    while (1) {
        while (i != NULL && i->item.inteiro <= pivo) {
            i = i->frente;
            (*compChaves)++;
        }

        while (j != NULL && j->item.inteiro > pivo) {
            j = j->tras;
            (*compChaves)++;
        }

        if (i == NULL || j == NULL || i == j || i->indice >= j->indice) {
            break;
        }

        troca(i, j);
    }

    if (j != NULL) {
        troca(celulaEsquerda, j);
        return j->indice;
    }

    return esquerda; // Caso especial onde `j` seja NULL
}

// Função principal do QuickSort
void quicksort(TipoLista *lista, int esquerda, int direita, unsigned long long int *compChaves) {
    if (esquerda < direita) {
        int pivo = particiona(lista, esquerda, direita, compChaves);
        quicksort(lista, esquerda, pivo - 1, compChaves);
        quicksort(lista, pivo + 1, direita, compChaves);
    }
}

// Ordena a lista
void ordenarLista(TipoLista *lista, unsigned long long int *compChaves) {
    if (lista == NULL || lista->inicio == NULL || lista->fim == NULL) return;
    *compChaves = 0;
    quicksort(lista, 0, lista->tamanho - 1, compChaves);
}

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], char argumentos[], double tempoUsuario, double tempoSistema, unsigned long long int compChaves) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s: %s\n", nomeArquivo, strerror(errno));
        return;
    }

    fprintf(arquivo, "Quantidade de itens: %s\n", argumentos);
    fprintf(arquivo, "Quantidade de comparações de chaves: %llu\n", compChaves);
    fprintf(arquivo, "Tempo de usuário: %.6f segundos\n", tempoUsuario);
    fprintf(arquivo, "Tempo de sistema: %.6f segundos\n", tempoSistema);
    fprintf(arquivo, "Tempo total: %.6f segundos\n\n", tempoUsuario + tempoSistema);

    fclose(arquivo);
}