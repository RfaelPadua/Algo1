#include <stdio.h>
#include <string.h>

#define INICIO_ARRANJO 1
#define MAX_TAM 20

typedef int TipoApontador;

struct TipoItem { // Um produto
    char descricao[100];
    int quantidade;
    float valor;
};

struct TipoLista {
    struct TipoItem itens[MAX_TAM];
    TipoApontador primeiro, ultimo;
};

// Função auxiliar para inserir um item na lista
void Inserir(struct TipoItem x, struct TipoLista *lista) {
    if (lista->ultimo >= MAX_TAM) {
        printf("Lista cheia\n");
        return;
    }
    lista->ultimo++;
    lista->itens[lista->ultimo] = x;
}

float calcularSomaValor(struct TipoLista lista) {
    float soma = 0;
    for (int i = lista.primeiro; i <= lista.ultimo; i++) {
        soma += lista.itens[i].valor;
    }
    return soma;
}

struct TipoItem encontrarMaisCaro(struct TipoLista lista) {
    struct TipoItem maisCaro = lista.itens[lista.primeiro];
    for (int i = lista.primeiro + 1; i <= lista.ultimo; i++) {
        if (lista.itens[i].valor > maisCaro.valor) {
            maisCaro = lista.itens[i];
        }
    }
    return maisCaro;
}

int contarDescricao(struct TipoLista lista, char *descricao) {
    int contador = 0;
    for (int i = lista.primeiro; i <= lista.ultimo; i++) {
        if (strcmp(lista.itens[i].descricao, descricao) == 0) {
            contador++;
        }
    }
    return contador;
}

void trocarPosicao(struct TipoLista *lista, int pos1, int pos2) {
    if (pos1 >= INICIO_ARRANJO && pos1 <= lista->ultimo &&
        pos2 >= INICIO_ARRANJO && pos2 <= lista->ultimo) {
        struct TipoItem temp = lista->itens[pos1];
        lista->itens[pos1] = lista->itens[pos2];
        lista->itens[pos2] = temp;
    } else {
        printf("Posições inválidas\n");
    }
}

int buscarDescricao(struct TipoLista lista, char *descricao) {
    for (int i = lista.primeiro; i <= lista.ultimo; i++) {
        if (strcmp(lista.itens[i].descricao, descricao) == 0) {
            return i;
        }
    }
    return -1;
}

void removerDescricao(struct TipoLista *lista, char *descricao) {
    int i = lista->primeiro;
    while (i <= lista->ultimo) {
        if (strcmp(lista->itens[i].descricao, descricao) == 0) {
            for (int j = i; j < lista->ultimo; j++) {
                lista->itens[j] = lista->itens[j + 1];
            }
            lista->ultimo--;
        } else {
            i++;
        }
    }
}

int compararListas(struct TipoLista lista1, struct TipoLista lista2) {
    if (lista1.ultimo != lista2.ultimo) {
        return 0;
    }
    for (int i = lista1.primeiro; i <= lista1.ultimo; i++) {
        if (strcmp(lista1.itens[i].descricao, lista2.itens[i].descricao) != 0 ||
            lista1.itens[i].quantidade != lista2.itens[i].quantidade ||
            lista1.itens[i].valor != lista2.itens[i].valor) {
            return 0;
        }
    }
    return 1;
}

int determinarMaiorLista(struct TipoLista lista1, struct TipoLista lista2) {
    if (lista1.ultimo > lista2.ultimo) {
        return 1;
    } else if (lista1.ultimo < lista2.ultimo) {
        return 2;
    } else {
        return 0;
    }
}

int determinarMaiorValor(struct TipoLista lista1, struct TipoLista lista2) {
    float somaLista1 = calcularSomaValor(lista1);
    float somaLista2 = calcularSomaValor(lista2);
    if (somaLista1 > somaLista2) {
        return 1;
    } else if (somaLista1 < somaLista2) {
        return 2;
    } else {
        return 0;
    }
}

void listarProdutosComuns(struct TipoLista lista1, struct TipoLista lista2) {
    for (int i = lista1.primeiro; i <= lista1.ultimo; i++) {
        for (int j = lista2.primeiro; j <= lista2.ultimo; j++) {
            if (strcmp(lista1.itens[i].descricao, lista2.itens[j].descricao) == 0) {
                printf("Produto comum: %s\n", lista1.itens[i].descricao);
                break;
            }
        }
    }
}

void listarProdutosExclusivos(struct TipoLista lista1, struct TipoLista lista2) {
    int encontrado;
    for (int i = lista1.primeiro; i <= lista1.ultimo; i++) {
        encontrado = 0;
        for (int j = lista2.primeiro; j <= lista2.ultimo; j++) {
            if (strcmp(lista1.itens[i].descricao, lista2.itens[j].descricao) == 0) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Produto exclusivo da lista 1: %s\n", lista1.itens[i].descricao);
        }
    }
}

void concatenarListas(struct TipoLista lista1, struct TipoLista lista2, struct TipoLista *concatenada) {
    concatenada->primeiro = INICIO_ARRANJO;
    concatenada->ultimo = -1;

    for (int i = lista1.primeiro; i <= lista1.ultimo; i++) {
        Inserir(lista1.itens[i], concatenada);
    }
    for (int i = lista2.primeiro; i <= lista2.ultimo; i++) {
        Inserir(lista2.itens[i], concatenada);
    }
}

void intercalarListas(struct TipoLista lista1, struct TipoLista lista2, struct TipoLista *intercalada) {
    intercalada->primeiro = INICIO_ARRANJO;
    intercalada->ultimo = -1;

    int i = lista1.primeiro;
    int j = lista2.primeiro;

    while (i <= lista1.ultimo || j <= lista2.ultimo) {
        if (i <= lista1.ultimo) {
            Inserir(lista1.itens[i], intercalada);
            i++;
        }
        if (j <= lista2.ultimo) {
            Inserir(lista2.itens[j], intercalada);
            j++;
        }
    }
}

void removerNPrimeiros(struct TipoLista *lista, int n) {
    if (n >= 0 && n <= (lista->ultimo - lista->primeiro + 1)) {
        lista->primeiro += n;
    } else {
        printf("N inválido\n");
    }
}

int main() {
    struct TipoLista lista1, lista2, listaConcatenada, listaIntercalada;
    lista1.primeiro = INICIO_ARRANJO;
    lista1.ultimo = -1;
    lista2.primeiro = INICIO_ARRANJO;
    lista2.ultimo = -1;
    listaConcatenada.primeiro = INICIO_ARRANJO;
    listaConcatenada.ultimo = -1;
    listaIntercalada.primeiro = INICIO_ARRANJO;
    listaIntercalada.ultimo = -1;

    // Populando lista 1
    struct TipoItem item1 = {"Produto 1", 5, 10.50};
    struct TipoItem item2 = {"Produto 2", 3, 15.75};
    Inserir(item1, &lista1);
    Inserir(item2, &lista1);

    // Populando lista 2
    struct TipoItem item3 = {"Produto 3", 2, 8.20};
    struct TipoItem item4 = {"Produto 1", 1, 12.30};
    Inserir(item3, &lista2);
    Inserir(item4, &lista2);

    // Testando as funções
    printf("Soma do valor de todos os produtos na lista 1: %.2f\n", calcularSomaValor(lista1));
    printf("Produto mais caro na lista 1: %s\n", encontrarMaisCaro(lista1).descricao);
    printf("Quantidade de produtos com a descrição 'Produto 1' na lista 1: %d\n", contarDescricao(lista1, "Produto 1"));

    trocarPosicao(&lista1, 1, 2);

    printf("Posição do produto com a descrição 'Produto 1' na lista 1: %d\n", buscarDescricao(lista1, "Produto 1"));

    removerDescricao(&lista1, "Produto 1");

    printf("Listas iguais: %d\n", compararListas(lista1, lista2));
    printf("Maior lista: %d\n", determinarMaiorLista(lista1, lista2));
    printf("Lista com maior valor: %d\n", determinarMaiorValor(lista1, lista2));

    printf("Produtos comuns:\n");
    listarProdutosComuns(lista1, lista2);

    printf("Produtos exclusivos da lista 1:\n");
    listarProdutosExclusivos(lista1, lista2);

    concatenarListas(lista1, lista2, &listaConcatenada);
    printf("Lista concatenada:\n");
    for (int i = listaConcatenada.primeiro; i <= listaConcatenada.ultimo; i++) {
        printf("Descrição: %s, Quantidade: %d, Valor: %.2f\n", listaConcatenada.itens[i].descricao, listaConcatenada.itens[i].quantidade, listaConcatenada.itens[i].valor);
    }

    intercalarListas(lista1, lista2, &listaIntercalada);
    printf("Lista intercalada:\n");
    for (int i = listaIntercalada.primeiro; i <= listaIntercalada.ultimo; i++) {
        printf("Descrição: %s, Quantidade: %d, Valor: %.2f\n", listaIntercalada.itens[i].descricao, listaIntercalada.itens[i].quantidade, listaIntercalada.itens[i].valor);
    }

    removerNPrimeiros(&lista1, 1);
    printf("Lista 1 após remover os primeiros elementos:\n");
    for (int i = lista1.primeiro; i <= lista1.ultimo; i++) {
        printf("Descrição: %s, Quantidade: %d, Valor: %.2f\n", lista1.itens[i].descricao, lista1.itens[i].quantidade, lista1.itens[i].valor);
    }

    return 0;
}

