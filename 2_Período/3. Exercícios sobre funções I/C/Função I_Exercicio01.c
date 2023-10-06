#include <stdio.h>

int paridade(int numero){
	return !(numero % 2);
}
int main(){
	
	int x;
	scanf("%d", &x);
	
	if(paridade(x))
		printf("eh par!\n");
	else
		printf("eh impar!\n");
		
	return 0;
}
