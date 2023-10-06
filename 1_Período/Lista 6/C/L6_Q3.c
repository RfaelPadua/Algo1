#include <stdio.h>

int main(){
	float n_macas, preco_1 = 0.90, preco_2 = 0.70;
	
	printf("Informe o valor de Macas: ");
	scanf("%f", &n_macas);
	
	if(n_macas< 12)
		printf("Valor a ser pago = R$%.2f", n_macas * preco_1);
	else
		printf("Valor a ser pago = R$%.2f", n_macas * preco_2);
		
	return 0;
}