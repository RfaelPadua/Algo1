#include <stdio.h>

int main(){
	int n1, n2;
	
	printf("Informe um numero: ");
	scanf("%d", &n1);

	printf("Informe outro numero: ");
	scanf("%d", &n2);
	
	if(n1 > n2)
		printf("O numero %d eh maior\n", n1);
	else
		printf("O numero %d eh maior\n", n2);
		
	return 0;

}
