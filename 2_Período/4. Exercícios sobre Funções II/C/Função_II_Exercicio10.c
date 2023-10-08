#include <stdio.h>
#include <ctype.h>
#include <string.h>

void retirarCaractere(char str[], char c);
int main(){
    char str[50], c;

    printf("Informe uma string: ");
    fgets(str, sizeof(str), stdin);

    str[strlen(str) - 1] = '\0';

    printf("Informe um caractere: ");
    scanf("%c", &c);

    retirarCaractere(str, c);
    printf("%s", str);

}


void retirarCaractere(char str[], char c){
    int i, j, cont = 0;
    int tam = strlen(str);
    for(i = 0; i < tam; i++){
        if(tolower(str[i]) == tolower(c)){
            for(j = i; j < tam;j++){
                str[j] = str[j+1];
            }
            tam--;
        }
    }
}