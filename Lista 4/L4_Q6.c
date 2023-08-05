#include <stdio.h>

int main(void){
	
	int a, b, modulo;
	
	printf("Informe o valor A: ");
	scanf("%d", &a);
	
	printf("Informe o valor B: ");
	scanf("%d", &b);
	
	modulo = a % b;
	
	printf("O modulo de A por B eh %d");
	
	return 0;
}
