#include <stdio.h>
#include <ctype.h>
#include <string.h>

void trocarCaractere(char str[], char c1, char c2);
int main(){
    char str[50], c1, c2;

    printf("Informe uma string: ");
    fgets(str, sizeof(str), stdin);

    str[strlen(str) - 1] = '\0';

    printf("Informe um caractere: ");
    scanf(" %c", &c1);
    printf("Informe um caractere: ");
    scanf(" %c", &c2);

    trocarCaractere(str, c1, c2);
    printf("%s", str);

}


void trocarCaractere(char str[], char c1, char c2){
    int i, j, cont = 0;
    int tam = strlen(str);
    for(i = 0; i < tam; i++){
        if(tolower(str[i]) == tolower(c1)){
                str[i] = c2;
        }
    }
}