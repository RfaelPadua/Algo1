#include <stdio.h>

int main(void){
    
    float valor = 100, valor_desc;

    printf("Informe o valor da venda: ");
    scanf("%f", &valor);
    valor_desc = valor - valor*0.1;

    printf("\nTotal da pagar com discondo de 10%% eh R$%.2f\n", valor_desc);
    printf("O valor de cada parcela, 3x sem juros eh R$%.2f\n", valor / 3);
    printf("A comissao do vendedor, na venda a vista eh R$%.2f\n", valor_desc * 0.05);
    printf("A comissao do vendedor, na venda parcelada eh R$%.2f\n", valor * 0.05);

    printf("\n\n");

}