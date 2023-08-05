#include<stdio.h>

int main(){
    char str[100];
    int i, len = 0;

    printf("informe uma palavra: ");
    fgets(str, 100, stdin);

    for(i = 0; str[i] != '\n'; i++)
        len++;

    printf("%d", len);
    
    return 0;
}