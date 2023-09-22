#include <stdio.h>

int main(){
    char str[100];
    printf("Informe uma palavra: ");
    fgets(str, 100, stdin);

    printf("%s", str);

    return 0;
}