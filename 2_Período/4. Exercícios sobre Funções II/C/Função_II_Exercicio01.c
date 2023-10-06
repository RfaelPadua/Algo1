#include <stdio.h>

int menor_valor(int vet[], int tam);

int main(){
	int vetor[10];
	int i;
	
	for(i = 0; i < 10; i++){
		printf("Informe o %do numero: ", i+1);
		scanf("%d", &vetor[i]);	
	}
	
	int tam = sizeof(vetor) / sizeof(vetor[0]);
	printf("O menor valor eh: %d\n\n", menor_valor(vetor, tam));
	
	system("pause");
	
}

int menor_valor(int vet[], int tam){
	int i, menor_valor = vet[0];
	
	for(i = 0; i < tam; i++){
		if(vet[i] < menor_valor){
			menor_valor = vet[i];
		}
	}
	
	return menor_valor;
}
