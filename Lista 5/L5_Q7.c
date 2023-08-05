#include <stdio.h>

int main(){
	
	float dias, valor_pago;
	
	printf("Quantos dias foram trabalhados: ");
	scanf("%f", &dias);
	
	valor_pago = (130 * dias) - (130 * dias)* 0.08;
	
	printf("A quantia liquida a ser paga eh R$%.2f", valor_pago);
	
	return 0;
}
