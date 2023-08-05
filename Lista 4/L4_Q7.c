#include <stdio.h>

int main(void){

	float n1, n2, media;
	
	printf("Numero: ");
	scanf("%f", &n1);
	
	printf("Numero: ");
	scanf("%f", &n2);
	
	media = (n1 + n2)/ 2;
	
	printf("A media dos valores e %.2f", media);
	
	return 0;
}

