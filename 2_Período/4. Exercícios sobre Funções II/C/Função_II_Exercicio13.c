#include <stdio.h>
#include <string.h>

void removerZeroEsquerda(char str[]);
void removerDigito(char str[], char digito);

int main(){
    char str[5], digito;

    printf("Informe um valor inteiro de 5 digitos: ");
    scanf("%s", &str);fflush(stdin);

    printf("Informe o digito a ser removido: ");
    scanf("%c", &digito);

    removerZeroEsquerda(str);
    removerDigito(str, digito);

    printf("%s\n", str);
} 

void removerZeroEsquerda(char str[]){

    int i, j = 0;
    char straux[5];

    for(i = 0; i< 5; i++){
        if(str[i] != '0'){
            straux[j] = str[i];
            j++;
        }
    }

    for(i = 0; i < strlen(straux)+1; i++){
        str[i] = straux[i];
    }
}

void removerDigito(char str[], char digito){
    int i, j = 0;
    char straux[5];

    for(i = 0; i < 5; i++){
        if(str[i] != digito){
            straux[j] = str[i];
            j++;
        }
    }

    for(i = 0; i < strlen(straux)+1; i++){
        str[i] = straux[i];
    }
}