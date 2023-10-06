#include <stdio.h>
#include <string.h>

int main(){
    
    char str1[100], str2[100];
    int i, cont;

    printf("informe uma palavra: ");
    fgets(str1, 100, stdin);

    printf("informe uma palavra: ");
    fgets(str2, 100, stdin);

    for(i = 0; str1[i] != '\0'; i++){
        if(str1[i] != str2[i]){
            printf("diferente");
            return 0;
        } 
    }
    printf("igual");

    return 0;
}