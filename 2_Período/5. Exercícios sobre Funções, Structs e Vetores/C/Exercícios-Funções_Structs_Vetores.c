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
    int cadastroID = 0;
    int i;

    while(menu != 0){
        system("cls");

        printf("Escolha uma das opcoes\n");
        printf("1. Cadastro de registro.\n");
        printf("2. Exibicao de registros.\n");
        
        printf("0. Sair.\n");
        scanf("%d", &menu);fflush(stdin);
        struct Produto produto[MAX_PESSOAS];

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
            default:
                menu = 0;
                break;
        }

    }
}