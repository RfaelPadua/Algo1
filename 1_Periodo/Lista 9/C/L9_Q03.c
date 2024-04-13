#include <stdio.h>

int main(void){
    
    int n1, n2, i, r =0;

    printf("informe dois valores inteiros: ");
    scanf("%d%d", &n1, &n2);

    for(i = 0; i < n1; i++)
    {
        r += n2;
    }

    printf("%d * %d = %d", n1, n2, r);
}