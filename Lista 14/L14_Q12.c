#include<stdio.h>
#include<string.h>

int main(){
    char str1[100], str2[100];
    char *i;

    printf("informe a primeira string: ");
    fgets(str1, 100,stdin);

    printf("informe a segunda string: ");
    fgets(str2, 200, stdin);

   i = strstr(str1, str2);

    if (i != 0) {
        printf("Substring encontrada: %s\n", i);
    } else {
        printf("Substring nao encontrada.\n");
    }

    return 0;
}