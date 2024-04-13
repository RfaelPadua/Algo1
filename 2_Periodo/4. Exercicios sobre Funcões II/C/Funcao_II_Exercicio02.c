#include <stdio.h>

int qnt_primos(int vet[]);
int eh_primo(int n);

int main(){
	int vetor[10], i;
	
	printf("Digite 10 numeros inteiros:\n");
	
	for(i = 0; i < 10; i++){
		scanf("%d", &vetor[i]);
	}
	
	printf("Quantidade de números primos: %d\n", qnt_primos(vetor));
}

int eh_primo(int n){
	int i;
	if(n <= 1){
		return 0;
	}
	for(i = 2; i * i <= n;i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}
int qnt_primos(int vet[]){
	int i, cont = 0;
	
	for(i = 0; i < 10; i++){
		cont += eh_primo(vet[i]);
	}
	return cont;
}
