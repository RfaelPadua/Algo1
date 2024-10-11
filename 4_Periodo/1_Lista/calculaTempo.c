//Calcula tempo
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	clock_t inicio, fim;
	unsigned long int tempo;
	inicio = clock();
	//=========================
	int a;
	for(int i = 0; i<1000000000; i++){
		a++;
	}
	//=========================
	fim = clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	printf("tempo: %lu milissegundos\n",tempo);
	return 0;
}

