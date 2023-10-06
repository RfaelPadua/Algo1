#include <stdio.h>

float IMC(float, float);

int main(){
	float peso, altura;
	
	printf("Informe o peso(kg): "); scanf("%f", &peso);
	printf("Informe a altura(metro e cm): "); scanf("%f", &altura);
	
	printf("IMC = %.2f", IMC(peso, altura));
	
	return 0;
}

float IMC(float p , float a){
	return p/(a*a);
}
