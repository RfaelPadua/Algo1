/*******************************************************************
*   As organizações CSM resolveram dar um aumento de salário aos 
*   seus colaboradores e lhe contrataram para desenvolver o 
*   programa que calcula os reajustes.
*******************************************************************/
#include <stdio.h>

int main(void){
    
    float salario;

    printf("Informe o seu salario: ");
    scanf("%f", &salario);

    if(salario <= 280)
        printf("Salario depois do reajuste eh R$%.2f", salario * 1.20);
    else if (salario <= 700)
        printf("Salario depois do reajuste eh R$%.2f", salario * 1.15);
    else if (salario <= 1500)
        printf("Salario depois do reajuste eh R$%.2f", salario * 1.10);
    else
        printf("Salario depois do reajuste eh R$%.2f", salario * 1.05);
}