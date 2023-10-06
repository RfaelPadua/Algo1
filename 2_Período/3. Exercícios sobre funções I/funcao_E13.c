#include <stdio.h>

int contar_divisores(int n);

int main(){
	int numero;
	
	scanf("%d", &numero);
	
	printf("O numero %d possui %d divisores positivos.\n", numero, contar_divisores(numero));
	
	return 0;
}

int contar_divisores(int n){
	
	int i, cont = 0;
	for(i = 1; i < n; i++){
		if(n % i == 0){
			cont++;
		}
	}
	
	return cont;
}
