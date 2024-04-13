#include <stdio.h>
#include <ctype.h>

int contarCaractere(char str[], char c);
int main(){
    char str[50], c;

    printf("Informe uma string: ");
    fgets(str, sizeof(str), stdin);

    printf("Informe um caractere: ");
    scanf("%c", &c);

    printf("O caractere '%c' aparece %d vezes na string.", c, contarCaractere(str, c));

}


int contarCaractere(char str[], char c){
    int i = 0, cont = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(tolower(str[i]) == tolower(c)){
            cont++;
        }
    }

    return cont;
}