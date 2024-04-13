#include <stdio.h>
#include <math.h>

float calcular_montante_final(float, float, int);

int main(){
	float capital, juros;
	int meses;
	
	printf("Capital: ");
	scanf("%f", &capital);
	
	printf("Juros: ");
	scanf("%f", &juros);
	
	printf("Meses: ");
	scanf("%d", &meses);
	
	printf("%.2f", calcular_montante_final(capital, juros, meses));
	
}

float calcular_montante_final(float c, float j , int m){
	return c*pow(1+j/100, m);
}
