#include<stdio.h>
#include<string.h>

int main(){
    
    char str1[100], str2[100], str3[100];
    int i;
    
    printf("informe uma palavra: ");
    fgets(str1, 100, stdin);

    printf("informe uma palavra: ");
    fgets(str2, 100, stdin);

    strcat(str3, str1);
    strcat(str3, str2);
    for(i = 0; str3[i] != '\0'; i++)
        str3[i] == '\n' ? printf(" ") : printf("%c", str3[i]);

    return 0;
}