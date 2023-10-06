#include <stdio.h>

void recebe(int *a);
int eh_primo(int a);

int main(){
	int valor;
	
	recebe(&valor);
	
	eh_primo(valor) ? printf("O numero eh primo") : printf("O numero nao eh primo");
	
	
}

void recebe(int *a){
	scanf("%d", a);
}

int eh_primo(int a){
	
	int i;
	for(i = 2; i < a / 2; i++){
		if(a % i == 0){
			return 0;
		}
	}
	
	return 1;
}
