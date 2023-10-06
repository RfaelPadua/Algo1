#include <stdio.h>

float calcular_fx(float);

int main(){
	float x;
	
	printf("Informe X: ");
	scanf("%f", &x);
	
	if(x == 2){
		printf("f(%.2f)= 8/(2-x) eh indefinida", x);
		return 0;
	}
	printf("f(%.2f)= 8/(2-x) eh %.2f", x, calcular_fx(x));
}

float calcular_fx(float x){
	return 8 / (2 - x);
}
