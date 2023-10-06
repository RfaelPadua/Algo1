#include <stdio.h>

int main(void){
    
    int n1, n2, n,i,j, eh_primo;

    printf("Informe 2 valores: ");
    scanf("%d%d", &n1, &n2);
    
    if(n1 > n2){
        n = n1;
        n1 = n2;
        n2 = n;
    }

    printf("\nOs numeros primos entre %d e %d sao:\n", n1, n2);

    for(i = n1; i <= n2; i++){
        eh_primo = 1;

        for(j = 2; j < i/2;j++){
            if(i % j == 0){
                eh_primo = 0;
                break;
            }
        }
        if(eh_primo == 1){
            printf("%d; ", i);
        }
    }
    printf("\n\n");

    return 0;
}