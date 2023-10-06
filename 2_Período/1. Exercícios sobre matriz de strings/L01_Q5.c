#include <stdio.h>
#include <string.h>

int main(){
	int i, j, k, cont = 0;
	char mat[5][50], vogais[10] = "aeiouAEIOU";
	
	
	for(i = 0; i < 5; i++){
		printf("Informe a %d string: ", i+1);
		fgets(mat[i], 50 , stdin);
	}
	
	for(i = 0; i < 5; i++){
		for(j = 0; j < strlen(mat[i]) - 1; j++){
			for(k = 0; k < 10; k++){
				if(vogais[k] == mat[i][j]){
					cont++;
					break;
				}
            }
		}
	}
	printf("%d", cont);
}
