#include<stdio.h>
#include<string.h>

void inverterString(char *str, int tam);
int main(){
    char str[50];

    printf("Informe uma string: ");
    fgets(str, sizeof(str), stdin);
    int tam = strlen(str);

    inverterString(str, tam);
    printf("%s", str);

    return 0;
}

void inverterString(char *str, int tam){
    int i;
    char aux;
    tam -=2;
    for(i = 0; i < tam/2 ;i++){
        aux = str[i];
        str[i] = str[tam-i];
        str[tam-i] = aux;
    }
}