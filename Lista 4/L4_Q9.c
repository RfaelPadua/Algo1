#include <stdio.h>

int main(void){

    int n, a1, razao;


    printf("O valor inicial(a1): ");
    scanf("%d", &a1);

    printf("razao(q): ");
    scanf("%d", &razao);

    printf("N: ");
    scanf("%d", &n);


    printf("PG = (%d, ", a1);

    for(int i = 0; i < n-1; i++){
        a1 *= razao;

        if(i < n-2){
        printf("%d, ", a1);
        }
        else
        printf("%d)\n", a1);
    }
    return 0;
} 