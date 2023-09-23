#include <stdio.h>

int main(void){
	
	float M;
	
	printf("Informe a distancia em Milhas: ");
	scanf("%f", &M);
	
	printf("%.2f milhas eh igual a %.2f quilometros", M, M * 1.61);
}
