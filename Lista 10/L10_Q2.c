#include <stdio.h>

int main(void){
	
	int i = 0, v, r = 0;
	
	while( i < 10){
		printf("Informe o valor %d: ", i+1);
		scanf("%d", &v);
		
		r += v;
		
		i++;
	}
	
	printf("Soma desse valores eh %d", r);
	
	return 0;
}
