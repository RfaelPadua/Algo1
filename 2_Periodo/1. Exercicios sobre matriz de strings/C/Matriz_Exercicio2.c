#include <stdio.h>

int main(){
	int i, cont = 0, x;
	char mat[5][50], str[50];
	
	
	for(i = 0; i < 5; i++){
		printf("Informe a %d string: ", i+1);
		fgets(mat[i], 50 , stdin);
	}
	printf("string: ");
	fgets(str, 50, stdin);
	
	for(i = 0; i < 5; i++){
		if(strcmp(str, mat[i]) == 0){
			cont++;
		}
	}
	printf("%d", cont);
}
