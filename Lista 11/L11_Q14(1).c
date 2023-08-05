#include <stdio.h>

int main(void){
	
	int v1[9], v2[9], v[19];
	int i, j, k = 10, cont;
	
	printf("Informe 10 valores par ao primeiro vetor:\n");
	
	for(i = 0; i< 10; i++){
		printf("%d valor: ", i+1);
		scanf(" %d", &v1[i]);
	}
	
	printf("\nInforme 10 valores par ao segundo vetor:\n");
	
	for(i = 0; i< 10; i++){
		printf("%d valor: ", i+1);
		scanf(" %d", &v2[i]);
	}
	
	for(i = 0; i<10 ; i++){
		v[i]=v1[i];
	}
	
	for(i = 0; i<10 ; i++){
		cont == 0;
		for(j=0; j < 10; j++){
			if(v2[i]==v1[j]){
				cont == 1;
				break;
			}
		}
		if(cont != 1){
			
			v[k] == v2[i];
			k++;
		}
	
	}

	for(i = 0; i < 20; i++){
		printf("%d ", v[i]);
	}

}
	
	

