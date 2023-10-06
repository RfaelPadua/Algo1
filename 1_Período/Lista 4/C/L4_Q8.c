#include <stdio.h>

int main(void){
	
	int a, b, c;
	
	printf("Informe A: ");
	scanf("%d", &a);
	
	printf("Informe B: ");
	scanf("%d", &b);
	
	c = (a * b) - (a * 2);
	
	printf("%d", c);
	
	return 0;
}
