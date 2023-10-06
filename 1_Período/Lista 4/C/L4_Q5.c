#include <stdio.h>

int main(void){
	
	int n1, n2, media;
	
	printf("Numero: ");
	scanf("%d", &n1);
	
	printf("Numero: ");
	scanf("%d", &n2);
	
	media = (n1 + n2)/ 2;
	
	printf("A media dos valores e %d", media);
	
	return 0;
}
