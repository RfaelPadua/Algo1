#include <stdio.h>

int verificar_valor(int);

int main(){
	int valor;
	
	scanf("%d", &valor);
	
	verificar_valor(valor) == 1 ? printf("O valor eh positivo.\n") : verificar_valor(valor) == -1 ? printf("O valor eh negativo.\n"): printf("O valor eh zero.\n");
	
	return 0;
}

int verificar_valor(int valor){
	if (valor > 0) {
        return 1; 
    } else if (valor < 0) {
        return -1;
    } else {
        return 0;
    }
}
