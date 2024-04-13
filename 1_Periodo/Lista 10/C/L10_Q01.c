#include <stdio.h>

int main(void){
	
	int i, v, r= 0;
	
	for(i = 0; i < 10; i++){
		printf("Informe o valor %d: ", i+1);
		scanf("%d", &v);
		
		r += v;
	}
	
	printf("Soma desse valores eh %d", r);
	
	return 0;
}
