#include <stdio.h>

int main(){
	int i;
	char mat[5][50];
	
	for(i = 0; i < 5; i++){
		printf("Informe a %d string: ", i+1);
		fgets(mat[i], 50 , stdin);
	}
	
	for(i = 0; i < 5; i++){
		printf("%d string: %s", i+1, mat[i]);

	}
	
}
