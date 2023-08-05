#include <stdio.h>

int main(void){
    
    int n;
    do{
        printf("informe um numero possitivo: ");
        scanf("%d", &n);
    }while(n < 0);
    
    printf("Entrado...");
}