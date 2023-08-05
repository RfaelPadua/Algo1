#include<stdio.h>
#include<string.h>

int main(){
	
	char str[100], ch, vogais[]= "aeiouAEIOU";
	int i, j, cont;
	
	printf("informe uma palavra: ");
	fgets(str, 100, stdin);
	
	printf("informe um caractere: ");
	scanf("%c", &ch);
	
	for(i = 0; i< strlen(str) - 2; i++){
		for(j = 0; j < 10; j++){
			if(str[i] == vogais[j]){
				cont++;
				str[i] = ch; 
			}
		}
	}
	printf("%s\nHavia %d vogais na palavra.\n", str, cont);
	
}