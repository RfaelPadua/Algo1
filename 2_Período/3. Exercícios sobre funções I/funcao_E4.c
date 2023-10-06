#include <stdio.h>

void recebe(int *a, int *b, int *c);
int menor_valor(int a, int b, int c);

int main(){
	int a, b, c;
	
	recebe(&a, &b, &c);
	
	printf("%d", menor_valor(a, b, c));
	
	return 0;
}


void recebe(int *a, int *b, int *c){
	scanf("%d%d%d", a, b, c);
}

int menor_valor(int a, int b, int c){
	return a < b && a < c ? a : b < a && b < c ? b : c;
}
