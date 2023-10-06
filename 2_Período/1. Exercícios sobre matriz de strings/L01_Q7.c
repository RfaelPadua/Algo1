#include <stdio.h>
#include <string.h>

int main(){
	char mat[5][50], vogais[10] = "aeiouAEIOU";
	int i, j, k, maiorCont = 0, maiorStr = 0, cont = 0;
	
	for(i = 0; i < 5; i++){
		fgets(mat[i], 50, stdin);
	}
	
	for(i = 0; i < 5; i++, cont = 0){
		for(j = 0; j < strlen(mat[i]) - 1; j++){
			for(k = 0; k < 10; k++){
				if(vogais[k] == mat[i][j]){
					cont++;
					break;
				}
			}
		}
		if(cont > maiorCont){
			maiorCont = cont;
			maiorStr = i;
		}
	}
	printf("A string %d possui o maior numero de vogais.", maiorStr);
	
	return 0;
}
