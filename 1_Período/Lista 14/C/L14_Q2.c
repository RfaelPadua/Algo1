#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int i;
    printf("Informe uma palavra: ");
    fgets(str, 100, stdin);

    for(i = 0; i < strlen(str); i++){
        i % 2 == 0 ? printf(" ") : printf("%c", str[i]); 
    }

    return 0;
}