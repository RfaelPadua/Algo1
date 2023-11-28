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
        switch (op)
        {case 1:
            

            printf("Informe uma string:\n"); fflush(stdin);
            fgets(str, 10, stdin);


            if(str[strlen(str)-1] == '\n'){
                str[strlen(str)-1] = '\0';
            }


            printf("\n%d\n", vogais_seguidas(str));
            break;
        case 2:
            
            printf("Informe m: ");
            scanf("%d", &m);

            printf("Informe n: ");
            scanf("%d", &n);

            int matriz[m][n];
            break;

        case 0:
            menu = 0;
            break;
        }
    }
    
}