#include<stdio.h>
#include<string.h>

int ehPalindromo(char str[]);

int main(){
    char str[50];

    printf("Informe uma string: ");
    fgets(str, sizeof(str), stdin); fflush(stdin);
    str[strlen(str) - 1] = '\0';

    if(ehPalindromo(str)){
        printf("Eh um palindromo");
    }else{
        printf("Nao eh um palindromo");
    }

}

int ehPalindromo(char str[]){
    int i;
    int tam = strlen(str) - 1;

    for(i = 0; i < tam /2; i++){
        if(str[i] != str[tam - i]){
            return 0;
        }
    }

    return 1;
}