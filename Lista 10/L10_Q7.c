#include <stdio.h>

int main(void){
    
    int n, i, r = 1;

    printf("Infome uma valor: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        r *= i;
    }

    printf("fatorial de %d eh %d", n, r);

    return 0;
}