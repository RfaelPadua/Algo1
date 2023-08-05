#include <stdio.h>
#include <string.h>

int main(){
	char str[100];
	int cont = 0, i;
	printf("Informe uma string: ");
	fgets(str, 100, stdin);
	
	for(i = 0; i < strlen(str); i++){
		if(str[i]== '1'){
			cont++;
		}
	}
	printf("%d", cont);
}