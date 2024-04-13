#include <stdio.h>

int main(){
	int matriz[5][5];
	int i, j, soma = 0;
	
    for(i = 0; i< 5; i ++){
        for(j = 0; j < 5; j ++){
            printf("Insira um valor na linha %d, coluna %d: ", i, j);
            scanf(" %d", &matriz[i][j]);
        }
    }
    
    for(i = 0; i< 4; i ++){
            soma += matriz[i][i+1];
    }
    printf("%d", soma);

}
