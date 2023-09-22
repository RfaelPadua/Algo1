#include <stdio.h>
#include <string.h>

int main(){
    char str[100], aux;
    int i, len;

    printf("informe uma palavra: ");
    fgets(str, 100, stdin);
    
    len = strlen(str) - 2;

    for(i = 0; i < len - 1/2; i++){
        aux = str[i];
        str[i] = str[len - i];
        str[len - i] = aux;
    }

    printf("%s", str);

    return 0;
}