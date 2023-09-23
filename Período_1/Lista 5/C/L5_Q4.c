#include <stdio.h>

int main(void){
	
	float lado;

	printf("Informe um lado do Quadrado: ");
	scanf("%f", &lado);
	
	printf("A area do quadrado eh: %.2f", lado * lado);
	
	return 0;
}
