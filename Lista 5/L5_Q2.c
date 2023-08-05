#include <stdio.h>

int main(void){
	
	float K;
	
	printf("Informe a velocidade em KM/h: ");
	scanf("%f", &K);
	
	printf("%.2f m/s", K / 3.6);
}
