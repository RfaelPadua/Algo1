#include <stdio.h>

int eh_vogal(char c){
	char vogais[10] = "aeiouAEIOU"; 
	int i;
	for(i = 0; i < 10; i++){
		if(c == vogais[i]){
			return 1;
		}
	}
	return 0;	
}

int main(){
	
	char caractere;
	scanf("%c", &caractere);
	
	
	if(eh_vogal(caractere)){
		printf("eh vogal");
		return 0;
	}
	
	printf("nao eh vogal");

}
