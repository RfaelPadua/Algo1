#include <stdio.h>

int eh_perfeito(int);

int main(){
	int numero;
	
	scanf("%d", &numero);
	
	eh_perfeito(numero) ? printf("O numero %d e perfeito.\n", numero) : printf("O numero %d nao e perfeito.\n", numero);
	
	return 0;
}

int eh_perfeito(int n){
	int cont = 0, i;
	
	for(i = 1; i < n; i++){
		if(n % i == 0){
			cont += i;
		}
	}
	
	if(cont == n){
		return 1;
	}
	
	return 0;
}
