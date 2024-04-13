#include <stdio.h>

int main(void){

    int salario, tempo;

    printf("Salario: R$");
    scanf("%d", &salario);

    printf("Tempo de servico em anos: ");
    scanf("%d", &tempo);

    if(tempo >= 5)
        salario = salario * 0.2;
    else
        salario = salario * 0.1;

    printf("O Bonus a ser recebido eh R$%d", salario);

    return 0;
}