#include <stdio.h>

int main(void){
	
	int v, vmaior, vmenor, r= 0;
	
	printf("Informe um valor inteiro: ");
	scanf("%d", &v);
	
	vmaior = v;
	vmenor = v;
	
	while( v >= 0){
		if(v > vmaior)
			vmaior = v;
		if(v < vmenor)
			vmenor = v;
		
		r += v;
		
		printf("Informe um valor inteiro: ");
		scanf("%d", &v);
	}
	
	printf("Maior valor : %d\nMenor valor: %d\nSoma dos valores: %d", vmaior, vmenor, r);
	
	return 0;
}
