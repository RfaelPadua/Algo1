#include <stdio.h>

int main(){
	
	float valor_hora, horas, valor_pago;
	
	printf("Informe o valor da hora de trabalho (em reais): ");
	scanf("%f", &valor_hora);
	
	printf("Informe o numero de horas trabalhadas no mes: ");
	scanf("%f", &horas);
	
	valor_pago = valor_hora * horas;
	valor_pago += valor_pago * 0.1;
	
	printf("Valor a ser pago eh R$%.2f", valor_pago);
}
