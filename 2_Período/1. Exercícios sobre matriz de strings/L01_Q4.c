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
		if(j == strlen(mat[i])-1){
			printf("tem %d \"%c\" na %d string\n", cont, ch, i+1);
			cont = 0;
			}
		}
	}
}
