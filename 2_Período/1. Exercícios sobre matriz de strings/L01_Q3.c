#include <stdio.h>

int main(){
	int i, j, cont = 0;
	char mat[5][50], ch;
	
	
	for(i = 0; i < 5; i++){
		printf("Informe a %d string: ", i+1);
		fgets(mat[i], 50 , stdin);
	}
	printf("caractere: ");
	scanf("%c", &ch);
	
	for(i = 0; i < 5; i++){
		for(j = 0; j < strlen(mat[i]); j++){
		mat[i][j] == ch ? cont++ : cont;
		}
	}
	printf("%d", cont);
}
