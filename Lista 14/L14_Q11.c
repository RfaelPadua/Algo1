#include<stdio.h>
#include <string.h>
int main(){
	char str[100];
	int i , cont = 0, len;
	
	printf("informe uma string: ");
	fgets(str, 100, stdin);
	
	len = strlen(str) - 2;
	for(i = 0; i < len/2; i++){
		if(str[i] != str[len - i]){
			printf("nao eh polindromo.");
			return 0;
		}
	}
	printf("eh polindromo");
}