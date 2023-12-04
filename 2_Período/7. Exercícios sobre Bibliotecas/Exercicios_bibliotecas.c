#include <stdio.h>
#include <string.h>
#include "prova.h"

int main(void){

    int op = 0, menu = 1;
    int m, n;
    char str[10];
    while(menu){
        printf("Digite a opcao desejada: \n");
        printf("1 - Questao\n");
        printf("2 - Questao\n");
        printf("3 - Questao\n");
        printf("4 - Questao\n");
        printf("0 - Sair\n");

        scanf("%d", &op);

        if(op == 1){
            printf("Informe uma string:\n"); fflush(stdin);
            fgets(str, 10, stdin);


            if(str[strlen(str)-1] == '\n'){
                str[strlen(str)-1] = '\0';
            }


            printf("\n%d\n", vogais_seguidas(str));


        }else if(op == 2){
            int maior, menor;

            printf("Informe m: ");
            scanf("%d", &m);

            printf("Informe n: ");
            scanf("%d", &n);

            int mat[m][n];

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    printf("Informe o valor da posicao [%d][%d]: ", i, j);
                    scanf("%d", &mat[i][j]);
                }
            }

            maior_menor(m, n, mat, &maior, &menor);

            printf("Maior: %d\n", maior);
            printf("Menor: %d\n", menor);
        }else if(op == 3){

            printf("Informe m: ");
            scanf("%d", &m);
            printf("Informe n: ");
            scanf("%d", &n);

            int mat[m][n];

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    printf("Informe o valor da posicao [%d][%d]: ", i, j);
                    scanf("%d", &mat[i][j]);
                }
            }
            if(temNperfeito(m,n, mat)){
                printf("A matriz possui um numero perfeito!\n");
            }else{
                printf("A matriz nao possui um numero perfeito!\n");
            }
        }else if (op == 4){
            printf("Informe m: ");
            scanf("%d", &m);
            printf("Informe n: ");
            scanf("%d", &n);

            int mat[m][n];

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    printf("Informe o valor da posicao [%d][%d]: ", i, j);
                    scanf("%d", &mat[i][j]);
                }
            }

            printf("%d\n", soma_linha(m, n, mat));
        }else if(op == 0){
            menu = 0;
        }else{
            printf("Opcao invalida!\n");
        }
    
    }
}