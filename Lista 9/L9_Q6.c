#include <stdio.h>

int main(void){
    int n_valor = 0, i, valor, r = 0;

    printf("Informe a quantidade de valores: ");
    scanf("%d", &n_valor);

    for(i = 1; i<= n_valor; i++)
    {
        printf("informe o %d valor: ", i);
        scanf(" %d", &valor);

        r = r + valor;
    }
    r = r / n_valor;

    printf("a media artimetica dos valores eh: %d", r);
}