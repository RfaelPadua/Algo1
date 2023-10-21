#include <stdio.h>

int main(){
    int matriz[3][3];
    int i, j, soma = 0;

    for(i = 0; i< 3; i ++){
        for(j = 0; j < 3; j ++){
            printf("Insira um valor na linha %d, coluna %d: ", i, j);
            scanf(" %d", &matriz[i][j]);
        }
    }

    for(i = 0; i< 3; i ++){
            soma += matriz[i][i];
    }
    printf("%d", soma);
    
    return 0;
}
