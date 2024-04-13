#include <stdio.h>

int soma_numeros_pares(int, int);

int main(){
	int m, n;
	
	printf("Informe dois numeros inteiros positivos: ");
	scanf("%d%d", &m, &n);
	
	if(m > n){
		m +=  n;
		n = m - n;
		m -= n;
	}
	printf("A soma dos numeros pares entre %d e %d eh %d", m, n, soma_numeros_pares(m, n));
}

int soma_numeros_pares(int x, int y){
	int i, soma = 0;
	
	for(i = x + 1; i < y; i++){
		if(!(i % 2)){
			soma += i;
		}
	}
	
	return soma;
	
}
