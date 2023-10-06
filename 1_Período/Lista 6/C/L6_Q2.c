#include <stdio.h>

int main(){
	float v, d;
	
	printf("Qual o valor da compra: ");
	scanf("%f", &v);
	
	if(v >= 100){
		printf("Qual o valor do desconto em porcentagem: ");
		scanf("%f", &d);

		d = d / 100;
		v -= v * d;

		printf("eh possivel conceder o desconto\nValor a ser pago eh R$%.2f", v);
	}else
		printf("Nao eh possivel conceder o desconto");
	
	return 0;
}