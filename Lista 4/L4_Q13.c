#include <stdio.h>

int main(void){

    int valor_empre, parcelas, valor_parcelas, salario;
 
    printf("Valor do Emprestimo: ");
    scanf("%d", &valor_empre);

    printf("Numero de Parcelas: ");
    scanf("%d", &parcelas);

    printf("Salario: ");
    scanf("%d", &salario);

    
    valor_parcelas = valor_empre / parcelas;

    if(valor_parcelas <= salario * 0.3)
        printf("APROVADO");
    else
        printf("NAO APROVADO");

    return 0;
}