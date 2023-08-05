#include <stdio.h>
#include <string.h>

int main(){
	char str[100];
	char vogais[] = "aeiouAEIOU"; 
	int i, j;
	printf("Informe uma string: ");
	fgets(str, 100, stdin);
	
	for(i = 0; i < strlen(str); i++){
		for(j = 0; j < strlen(vogais); j++){
			if(str[i] == vogais[j]){
				break;
			}else if(j  == strlen(vogais) - 1){
				printf("%c", str[i]);
			}
		}
	}
}