#include <stdio.h>

int main(void){
	
	int a, i, j;
	
	printf("Informe a altura da piramide: ");
	scanf("%d", &a);
	
	for(i = 0; i < a; i++){
		for(j = 0; j< i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
