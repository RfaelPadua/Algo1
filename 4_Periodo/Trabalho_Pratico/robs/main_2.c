#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/resource.h>

//--------------------------------------------------------------------------

// Armazena os dados
typedef struct TipoItem {
    int inteiro;
} TipoItem;

// Faz a conexão entre as células
typedef struct TipoCelula {
    TipoItem item;
    size_t indice;        // Índice da posição do item na lista
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

// Faz a troca entre dois itens da lista
void troca(TipoCelula* a, TipoCelula* b);

// Particiona a lista e retorna o pivô
TipoCelula* particiona(TipoCelula* esquerda, TipoCelula* direita, size_t* compChaves);

// Função principal do QuickSort
void quicksort(TipoCelula* esquerda, TipoCelula* direita, size_t* compChaves);

void ordenarLista(TipoLista* lista, size_t* compChaves);

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], double tempoUsuario, double tempoSistema, size_t compChaves);

//--------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    TipoLista lista;
    struct rusage inicio, fim; // Estruturas para analisar o uso de CPU
    size_t compChaves; // Quantidade de comparações de chaves

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
        printf("Erro: numero fora do intervalo permitido\n");
        return 1;
    }

    IniciaLstDup(&lista);
    preencherVetorAleatorio(&lista, qtdNums); // Preenche a lista com valores aleatórios

    // Obtém o tempo antes da execução do quicksort
    if (getrusage(RUSAGE_SELF, &inicio) != 0) { // Erro de recebimento das informações
        perror("Erro: falha durante a obtencao das informacoes\n");
        
        TipoCelula* aux = &lista.inicio; // Esvazia a lista
        while(!VaziaLstDup(lista)) {
            TipoItem i;
            RemoveNaPosicao(&lista, 0, &i);
            aux = aux->frente;
        }

        return 1;
    }

    quicksort(&lista.inicio, &lista.fim, &compChaves); // Ordena a lista

    // Obtém o tempo após a execução do quicksort
    if (getrusage(RUSAGE_SELF, &fim) != 0) { // Erro de recebimento das informações
        perror("Erro: falha durante a obtencao das informacoes\n");

        TipoCelula* aux = &lista.inicio; // Esvazia a lista
        while(!VaziaLstDup(lista)) {
            TipoItem i;
            RemoveNaPosicao(&lista, 0, &i);
            aux = aux->frente;
        }

        return 1;
    }

    TipoCelula* aux = &lista.inicio; // Esvazia a lista
    while(!VaziaLstDup(lista)) {
        TipoItem i;
        RemoveNaPosicao(&lista, 0, &i);
        aux = aux->frente;
    }

    // Calcula o tempo de CPU gasto (segundos)
    double tempoUsuario = (fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec) + (fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec) / 1e6;
    double tempoSistema = (fim.ru_stime.tv_sec - inicio.ru_stime.tv_sec) + (fim.ru_stime.tv_usec - inicio.ru_stime.tv_usec) / 1e6; 

    resultadosArquivo(nomeArquivo, tempoUsuario, tempoSistema, compChaves); // Insere os valores no arquivo

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

    // Atualiza os índices dos itens à direita
    TipoCelula* temp = novaCelula->frente;
    while (temp != NULL) {
        temp->indice += 1;  // Aumenta o índice dos itens à direita
        temp = temp->frente;
    }

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

    // Atualiza os índices dos itens à direita
    TipoCelula* next = temp->frente;
    while (next != NULL) {
        next->indice -= 1;  // Ajusta os índices
        next = next->frente;
    }

    free(temp); // Libera a memória da célula removida
    lista->tamanho--; // Atualiza o tamanho da lista
}


// Exibe a lista e seus índices
void ExibeLista(TipoLista lista) {
    TipoCelula* temp = lista.inicio;
    printf("Valores armazenados:\n");
    while (temp != NULL) {
        printf("Índice: %zu, Valor: %d\n", temp->indice, temp->item.inteiro);
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
        item.inteiro = rand() % 1000;  // Gera um valor aleatório de 0 a 999
        InserirNaPosicao(lista, item, i);  // Insere na posição i
    }
}

// Faz a troca entre dois itens da lista
void troca(TipoCelula* a, TipoCelula* b) {
    TipoItem temp = a->item;
    a->item = b->item;
    b->item = temp;
}


// Particiona a lista e retorna o pivô
TipoCelula* particiona(TipoCelula* esquerda, TipoCelula* direita, size_t* compChaves) {
    int pivo = esquerda->item.inteiro; // Escolhe o primeiro item como pivô
    TipoCelula* i = esquerda->frente;
    TipoCelula* j = direita;

    while (1) {
        // Avança `i` até encontrar um elemento maior ou igual ao pivô
        while (i != NULL && i != direita->frente) {
            (*compChaves)++; // Incrementa a contagem de comparações
            if (i->item.inteiro >= pivo) {
                (*compChaves)++;
                break;
            }
            i = i->frente;
        }

        // Retrocede `j` até encontrar um elemento menor ou igual ao pivô
        while (j != NULL && j != esquerda) {
            (*compChaves)++; // Incrementa a contagem de comparações
            if (j->item.inteiro <= pivo) {
                (*compChaves)++; // Incrementa a contagem de comparações
                break;
            }
            j = j->tras;
        }

        if (i == NULL || i == j || j == esquerda) { // Índices se cruzaram ou chegaram aos limites
            (*compChaves)++; // Incrementa a contagem de comparações
            break;
        } 

        troca(i, j); // Troca os elementos fora do lugar
    }

    troca(esquerda, j); // Coloca o pivô na posição correta
    return j; // Retorna o nó do pivô
}

// Função principal do QuickSort
void quicksort(TipoCelula* esquerda, TipoCelula* direita, size_t* compChaves) {
    if (esquerda != NULL && direita != NULL && esquerda != direita && esquerda != direita->frente) {
        (*compChaves)++; // Incrementa a contagem de comparações

        // Particiona a lista
        TipoCelula* pivo = particiona(esquerda, direita, compChaves);

        // Ordena a sublista à esquerda do pivô
        quicksort(esquerda, pivo->tras, compChaves);

        // Ordena a sublista à direita do pivô
        quicksort(pivo->frente, direita, compChaves);
    }
}

void ordenarLista(TipoLista* lista, size_t* compChaves) {
    if (lista->inicio == NULL || lista->fim == NULL) return; // Lista vazia
    *compChaves = 0; // Reseta o contador de comparações
    quicksort(lista->inicio, lista->fim, compChaves);
}

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], double tempoUsuario, double tempoSistema, size_t compChaves) {
    FILE *arquivo = fopen(nomeArquivo, "a");

    if (arquivo == NULL) { // Verifica se foi possível abrir o arquivo
        perror("Erro: nao foi possivel abrir o arquivo\n");
        exit(1);
    }

    fprintf(arquivo, "Quantidade de comparacoes de chaves: %zu\n", compChaves);
    fprintf(arquivo, "Tempo de usuario: %.6f segundos\n", tempoUsuario);
    fprintf(arquivo, "Tempo de sistema: %.6f segundos\n", tempoSistema);
    fprintf(arquivo, "Tempo total: %.6f segundos\n\n", tempoUsuario + tempoSistema);

    fclose(arquivo);
}