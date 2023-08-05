#include <stdio.h>

int main(){
	float PRODUTO, DESCONTO;
	
	printf("Valor do Produto: ");
	scanf("%f", &PRODUTO);
	
	DESCONTO = PRODUTO * 0.16;
	
	printf("O desconto eh de R$%.2f \nO valor final do produto sera de R$%.2f", DESCONTO, PRODUTO - DESCONTO);
	
	return 0;
	
}
