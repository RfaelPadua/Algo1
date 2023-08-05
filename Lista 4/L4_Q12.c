#include <stdio.h>

int main(void){

    int C, F;

    printf("Temperatura em Celsius: ");
    scanf("%d", &C);

    F = (9 * C + 160) / 5;

    printf("A temperatura em Fahrenheit eh %d", F);

    return 0;
}