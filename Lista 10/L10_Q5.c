#include <stdio.h>

int main(void){
	int i, j, k, lado;
	do{
		printf("informe o tamanho do lado do quadrado: ");
		scanf("%d", &lado);
	}while(lado < 0 || lado > 20);

	
	
	for(k = 0; k < lado; k++){
		printf("*");
	}
	
	printf("\n");
	
	for(i = 0; i < lado - 2; i++){
		printf("*");
		for(j= 0; j< lado - 2; j++){
			printf(" ");
		}
		printf("*\n");		
	}
	
	for(k = 0; k < lado; k++){
		printf("*");
	}
	
	return 0;
}
