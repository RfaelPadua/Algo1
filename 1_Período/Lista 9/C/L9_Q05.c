#include <stdio.h>

int main(void){

    int n, r = 0;

    do{
        printf("Informe valores positivos: ");
        scanf("%d", &n);

        r = r + n;
        
    }while(n > 0);

    printf("%d", r);
}