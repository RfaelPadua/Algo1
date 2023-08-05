#include <stdio.h>

int main(void){
	int vetor[49];
	
	int i;
	
	for(i = 0; i < 50; i++){
		
		vetor[i]=(i + 5 *i) % (i + 1);
		
	}
	
	for(i = 0; i < 50; i++){
		printf("%d", vetor[i]);
		if(i < 49){
			printf(", ");
		}
		else{
			printf(".");
		}
	}
	
	return 0;
}
