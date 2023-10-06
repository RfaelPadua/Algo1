#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(){
    setlocale(LC_ALL,"");
    int cpf[11] = {0};
    int menu, flag = 0, soma;
    int i, j, cont;



    do{
        int cpf[11] = {0};
        soma = 0;
        i = 0;
        printf("Selecione uma das opcoes\n");
        printf("1. Gerar digitos verificadores.\n");
        printf("2. Validar CPF.\n");
        printf("3. Gerar um CPF.\n");
        printf("4. Gerar varios CPFs.\n");
        printf("5. Fechar programa.\n");
        scanf(" %d", &menu);
        system("cls");

        switch (menu){
        case 1:
            do{
                printf("Informe o %d digito do CPF: ", i+1);
                scanf("%d", &cpf[i]);
                if(cpf[i] >= 0 && cpf[i] <= 9){
                    i++;
                }
                else{
                    printf("digito invalido\n");
                }
            }while(i < 9);

            for(i = 10; i < 12; i++){
                soma = 0;
                for(j = 0; j < 11; j++){
                soma += (cpf[j] * (i - j));
                }
                if(soma % 11 < 2){
                    cpf[i - 1] = 0;
                }else{
                    cpf[i - 1] = 11 - (soma % 11);
                }
            }
        
            for(i = 0; i < 11; i++){
                printf("%d", cpf[i]);
                if(i == 2)
                    printf(".");
                else if(i == 5)
                    printf(".");
                else if(i == 8)
                    printf("-");
            }
            break;
        case 2:
            cont = 0;
            do{
                printf("Informe o %d digito do CPF: ", i+1);
                scanf(" %d", &cpf[i]);
                if(cpf[i] >= 0 && cpf[i] <= 9){
                    i++;
                }
                else{
                    printf("Digito invalido\n");
                }
            }while(i < 11);

            for(i = 10; i < 12; i++){
                soma = 0;
                for(j = 0; j < i - 1; j++){
                    soma = soma + (cpf[j] * (i - j));
                }
                
                if(soma % 11 < 2){
                    if(cpf[i - 1] == 0){
                        cont++;
                    }
                }
                else{
                    if(cpf[i - 1] == 11 - (soma % 11)){
                        cont++;
                    }
                }
            }

            if(cont == 2){
                printf("CPF eh valido");
            }else
                printf("CPF eh invalido");
            break;
        case 3:
            srand(time(NULL));
            for(i = 0; i < 9;i++){
                cpf[i] = (rand() % 9);
            }
            for(i = 10; i < 12; i++){
                soma = 0;
                for(j = 0; j < 11; j++){
                    soma += (cpf[j] * (i - j));
                }
                if(soma % 11 < 2){
                    cpf[i - 1] = 0;
                }else{
                    cpf[i - 1] = 11 - (soma % 11);
                }
            }
                
            for(i = 0; i < 11; i++){
                printf("%d", cpf[i]);
                if(i == 2)
                printf(".");
                else if(i == 5)
                printf(".");
                else if(i == 8)
                printf("-");
            }
            break;
        case 4:
            int n;
            cont = 0;
            printf("Quantos CPF's você quer? ");
            scanf(" %d", &n);
            if(n < 1){
                break;
            }
            srand(time(NULL));
            do{
                
                int cpf[11] = {0};

                for(i = 0; i < 9;i++){
                    cpf[i] = (rand() % 10);
                }
                for(i = 10; i < 12; i++){
                    soma = 0;
                    for(j = 0; j < 11; j++){
                        soma += (cpf[j] * (i - j));
                    }
                    if(soma % 11 < 2){
                        cpf[i - 1] = 0;
                    }else{
                        cpf[i - 1] = 11 - (soma % 11);
                    }
                }
                    
                for(i = 0; i < 11; i++){
                    printf("%d", cpf[i]);
                    if(i == 2)
                    printf(".");
                    else if(i == 5)
                    printf(".");
                    else if(i == 8)
                    printf("-");
                }
                soma = 0;
                printf("\n");
                cont++;
            }while(cont < n);
            break;
        case 5:
            return 0;
            break;
        default:
            continue;
            break;
        }

        if(menu == 5){
            return 0;
        }

        printf("\n");
        system("pause");
        system("cls");

    }while(flag != 1);
}