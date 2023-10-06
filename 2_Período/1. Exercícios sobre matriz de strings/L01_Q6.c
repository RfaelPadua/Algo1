#include <stdio.h>
#include <string.h>

int main(){
	char mat[5][50], vogais[10] = "aeiouAEIOU";
	int i, j, k, cont = 0;
	int porcentagem = 0, len = 0;
	
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
		len = strlen(mat[i]) - 1;
		porcentagem = (cont * 100) / len;
		printf("\n%d%% dos caracteres na string %d sao vogais", porcentagem, i);
	}
}
