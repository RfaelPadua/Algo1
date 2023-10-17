#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PESSOAS 100

struct Produto {
    char marca[100];
    char descricao[50];
    int quantidade;
    float valor;
};

void somaTotal(struct Produto produto[], int n);
void somaPorDescricao(struct Produto produto[], int n, char *descricao);
void menorValor(struct Produto produto[], int n);
void alterar(struct Produto produto[], struct Produto novoProduto, int n, int cadastroID);
void excluir(struct Produto produto[], int n, int *cadastroID);

struct Produto produto[MAX_PESSOAS] = {
        {"Marca 1", "Descricao 1", 5, 10.5},
        {"Marca 2", "Descricao 2", 7, 15.2},
        {"Marca 3", "Descricao 3", 3, 8.9},
        {"Marca 4", "Descricao 4", 2, 12.6},
        {"Marca 5", "Descricao 10", 9, 11.0},
        {"Marca 6", "Descricao 6", 4, 9.8},
        {"Marca 7", "Descricao 7", 6, 14.5},
        {"Marca 8", "Descricao 10", 1, 7.2},
        {"Marca 9", "Descricao 9", 8, 13.3},
        {"Marca 10", "Descricao 10", 10, 16.7}
    };

int main(){

    int menu = 666;
    int cadastroID = 9;
    int i, j;
    float soma;

    while(menu != 0){
        system("cls");

        printf("Escolha uma das opcoes\n");
        printf("1. Cadastro de registro.\n");
        printf("2. Exibicao de registros.\n");
        printf("3. Soma de todos os produtos.\n");
        printf("4. Soma de todos os produtos baseado na descricao.\n");
        printf("5. Menor Valor.\n");
        printf("6. Alterar.\n");
        printf("7. Excluir.\n");
        
        printf("0. Sair.\n");
        scanf("%d", &menu);fflush(stdin);
        // struct Produto produto[MAX_PESSOAS];
        

        switch(menu){
            case 1:
                
                char marca[100];
                char descricao[50];
                cadastroID++;
                system("cls");

                printf("Informe a marca do produto: \n");
                fgets(marca, 100, stdin);fflush(stdin);
                marca[strlen(marca) - 1] = '\0';
                strcpy(produto[cadastroID].marca, marca);
                system("cls");

                printf("Informe a descricao: \n");
                fgets(descricao, 50, stdin);fflush(stdin);
                descricao[strlen(descricao) - 1] = '\0';
                strcpy(produto[cadastroID].descricao, descricao);
                system("cls");

                printf("Informe a quantidade: \n");
                scanf("%d", &produto[cadastroID].quantidade);
                system("cls");

                printf("Informe o valor: \n");
                scanf("%f", &produto[cadastroID].valor);
                
                
                system("pause");
                break;
            case 2:
                for(i = 0; i <= cadastroID; i++){
                    printf("\nMarca: %s", produto[i].marca);
                    printf("\nDescricao: %s", produto[i].descricao);
                    printf("\nQuantidade: %d", produto[i].quantidade);
                    printf("\nValor: %.2f", produto[i].valor);
                    printf("\n");
                }
                system("pause");
                break;
            case 3:
                system("cls");
                somaTotal(produto, cadastroID);
                system("pause");
                break;
            case 4:
                system("cls");
                char consultaDescricao[50];
                printf("Informe a descricao a ser consultada: ");
                fgets(consultaDescricao, 50, stdin);fflush(stdin);
                consultaDescricao[strlen(consultaDescricao) - 1] = '\0';

                somaPorDescricao(produto, cadastroID, consultaDescricao);

                system("pause");
                break;
            case 5:
                system("cls");
                menorValor(produto, cadastroID);
                system("pause");
                break;
            case 6:
                system("cls");
                fflush(stdin);

                struct Produto novoProduto;
                int alterarID;
                char alterarMarca[100], alterarDescricao[50];

                printf("Qual registro quer alterar? (de 0 ate %d)", cadastroID);
                scanf("%d", &alterarID);fflush(stdin);

                printf("Informe a marca do produto: \n");
                fgets(alterarMarca, 100, stdin);fflush(stdin);
                alterarMarca[strlen(alterarMarca) - 1] = '\0';
                strcpy(novoProduto.marca, alterarMarca);
                system("cls");

                printf("Informe a descricao: \n");
                fgets(alterarDescricao, 50, stdin);fflush(stdin);
                alterarDescricao[strlen(alterarDescricao) - 1] = '\0';
                strcpy(novoProduto.descricao, alterarDescricao);
                system("cls");

                printf("Informe a quantidade: \n");
                scanf("%d", &novoProduto.quantidade);
                system("cls");

                printf("Informe o valor: \n");
                scanf("%f", &novoProduto.valor);
                system("cls");

                alterar(produto, novoProduto, alterarID, cadastroID);

                
                system("pause");
                break;
            case 7:
                system("cls");
                int excluirID;
                printf("Qual registro quer excluir? (de 0 ate %d)", cadastroID);
                scanf("%d", &excluirID);fflush(stdin);

                excluir(produto, excluirID, &cadastroID);
                system("pause");
                break;
            default:
                menu = 0;
                break;
        }

    }
}

void somaTotal(struct Produto produto[], int n){
    float soma = 0;
    int i;
    for(i = 0; i < n; i++){
        soma += produto[i].valor * produto[i].quantidade;
    }
    printf("A soma dos valores dos produtos eh %.2f.\n", soma);
}

void somaPorDescricao(struct Produto produto[], int n, char *descricao){
    int i;
    float soma = 0;
    for(i = 0; i < n; i++){
        if (strcmp(produto[i].descricao, descricao) == 0) {
            soma += produto[i].valor * produto[i].quantidade;
        }
    }
    printf("A soma dos produtod com essa descricao eh R$%.2f\n", soma);
}

void menorValor(struct Produto produto[], int n){
    float min = produto[0].valor;
    int i;
    for(i = 0; i < n; i++){
        if(produto[i].valor< min){
            min = produto[i].valor;
        }
    }

    printf("O valor do produto mais barato eh R$%.2f.\n", min);
}

void alterar(struct Produto produto[], struct Produto novoProduto, int n, int cadastroID){
    if(n >= 0 && n <= cadastroID){
    strcpy(produto[n].marca, novoProduto.marca);
    strcpy(produto[n].descricao, novoProduto.descricao);
    produto[n].quantidade = novoProduto.quantidade;
    produto[n].valor = novoProduto.valor;
    printf("Alteração feita com sucesso.\n");
    }else{
        printf("Indice invalido.\n");
    }
}

void excluir(struct Produto produto[], int n, int *cadastroID){
    if(n >= 0 && n < *cadastroID){
        int i;
        for(i = n; i < *cadastroID; i++){
            strcpy(produto[i].marca, produto[i+1].marca);
            strcpy(produto[i].descricao, produto[i+1].descricao);
            produto[i].quantidade = produto[i+1].quantidade;
            produto[i].valor = produto[i+1].valor;
        }
        (*cadastroID)--;
        printf("%d\n", *cadastroID);
        printf("Exclusao feita com sucesso.\n");
    }else if(n == *cadastroID){
        (*cadastroID)--;
        printf("Exclusao feita com sucesso.\n");
    }else{
        printf("Indice invalido.\n");
    }
}