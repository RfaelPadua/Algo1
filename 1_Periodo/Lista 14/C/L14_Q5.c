#include <stdio.h>
#include <string.h>

int main(){
    
    char str1[100], str2[100];

    printf("informe uma palavra: ");
    fgets(str1, 100, stdin);

    printf("informe uma palavra: ");
    fgets(str2, 100, stdin);

    strcmp(str1, str2) ? printf("diferentes") : printf("iguais");
}