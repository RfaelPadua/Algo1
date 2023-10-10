#include <stdio.h>

int main(void){
	int valor[4];
	int i;
	
	for(i = 0; i<5; i++){
		printf("Informe o valor %d: ", i+1);
		scanf("%d", &valor[i]);
	}
	
	for( i = 0; i< 5; i++){
		printf("%d", valor[4-i]);
		if(i < 4){
			printf(", ");
		}
		else{
			printf(".");
		}
	}
}
