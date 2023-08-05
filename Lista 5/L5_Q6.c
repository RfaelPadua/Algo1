#include <stdio.h>

int main(){
	
	float premio, g1, g2, g3;
	premio = 780000;
	
	g1 = premio * 0.46;
	g2 = premio * 0.32;
	g3 = premio - g1 - g2;
	
	printf("O primeiro ganhador recebera R$%.2f\nO Segundo recebera R$%.2f\nO Terceiro recebera R$%.2f\n", g1, g2, g3);
	
	return 0;
}
