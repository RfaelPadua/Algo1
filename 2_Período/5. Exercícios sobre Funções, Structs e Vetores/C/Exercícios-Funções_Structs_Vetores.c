#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Produto {
    char marca[100];
    char descricao[50];
    int quantidade;
    float valor;
};
#define MAX_PESSOAS 100

int main(){

    int menu = 666;
    int cadastroID = 10;
    int i, j;
    float soma;

    while(menu != 0){
        system("cls");

        printf("Escolha uma das opcoes\n");
        printf("1. Cadastro de registro.\n");
        printf("2. Exibicao de registros.\n");
        printf("3. Soma de todos os produtos.\n");
        printf("4. Soma de todos os produtos baseado na descricao.\n");
        
        printf("0. Sair.\n");
        scanf("%d", &menu);fflush(stdin);
        // struct Produto produto[MAX_PESSOAS];
        struct Produto produto[10] = {
        {"Marca 1", "Descricao 1", 5, 10.5},
        {"Marca 2", "Descricao 2", 7, 15.2},
        {"Marca 3", "Descricao 3", 3, 8.9},
        {"Marca 4", "Descricao 4", 2, 12.6},
        {"Marca 5", "Descricao 5", 9, 11.0},
        {"Marca 6", "Descricao 6", 4, 9.8},
        {"Marca 7", "Descricao 7", 6, 14.5},
        {"Marca 8", "Descricao 8", 1, 7.2},
        {"Marca 9", "Descricao 9", 8, 13.3},
        {"Marca 10", "Descricao 10", 10, 16.7}
    };

        switch(menu){
            case 1:
                
                char marca[100];
                char descricao[50];

                system("cls");

                printf("Informe a marca do produto: \n");
                fgets(marca, 100, stdin);
                marca[strlen(marca) - 1] = '\0';
                strcpy(produto[cadastroID].marca, marca);
                system("cls");

                printf("Informe a descricao: \n");
                fgets(descricao, 100, stdin);
                descricao[strlen(descricao) - 1] = '\0';
                strcpy(produto[cadastroID].descricao, descricao);
                system("cls");

                printf("Informe a quantidade: \n");
                scanf("%d", &produto[cadastroID].quantidade);
                system("cls");

                printf("Informe o valor: \n");
                scanf("%f", &produto[cadastroID].valor);
                
                cadastroID++;
                system("pause");
                break;
            case 2:
                for(i = 0; i < cadastroID; i++){
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
                soma = 0;
                for(i = 0; i < cadastroID; i++){
                    soma += produto[i].valor;
                }
                printf("A soma dos valores dos produtos eh %.2f.\n", soma);
                system("pause");
                break;
            case 4:
                system("cls");
                soma = 0;
                char consultaDescricao[50];

                printf("Informe a descricao a ser consultada: ");
                fgets(consultaDescricao, 50, stdin);
                consultaDescricao[strlen(consultaDescricao) - 1] = '\0';

                for(i = 0; i < cadastroID; i++){
                    if(strlen(consultaDescricao) != strlen(produto[i].descricao)){
                        continue;
                    }
                    for(j = 0; j < strlen(consultaDescricao); j++){
                        if(consultaDescricao[j] != produto[i].descricao[j]){
                            break;
                        }
                        if(j == strlen(consultaDescricao)){
                            soma+=produto[i].valor;
                        }
                    }
                }
                printf("%d", soma);
                system("pause");
                break;
            default:
                menu = 0;
                break;
        }

    }
}