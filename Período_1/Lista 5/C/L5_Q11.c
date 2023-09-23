#include <stdio.h>

int main(void){
    
    int n = 0, u, d, c;

    do{
        printf("Informe um numero inteiro de 100 a 999: ");
        scanf("%d", &n);

    }while(n < 100 || n > 999);

    u = n % 10;
    d = (n % 100) / 10;
    c = n /100;


    printf("%d%d%d.\n", u, d, c);
}