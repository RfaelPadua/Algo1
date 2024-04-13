#include <stdio.h>

int main(){
    int matriz[3][3];
    int i, j;
    int vetor[3] = {0};

    for(i = 0; i< 3; i ++){
        for(j = 0; j < 3; j ++){
            printf("Insira um valor na linha %d, coluna %d: ", i, j);
            scanf(" %d", &matriz[i][j]);
        }
    }

    for(i = 0; i< 3; i ++){
        for(j = 0; j < 3; j ++){
            vetor[i] += matriz[i][j];
        }
    }
    printf("|");
    for(i = 0; i< 3; i ++){
        printf("%3d|", vetor[i]);
    }
}