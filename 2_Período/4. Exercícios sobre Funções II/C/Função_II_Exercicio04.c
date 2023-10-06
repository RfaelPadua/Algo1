#include <stdio.h>

void diagonal_principal_1(int m, int a[m][m]);
int main(){
    int i, j, m;
    printf("Informe m de Amxm: ");
    scanf("%d", &m);

    int a[m][m];

    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            printf("Informe o numero da posicao A%dx%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    diagonal_principal_1(m, a);

    for(i = 0; i < m; i++){
        printf("|");
        for(j = 0; j < m; j++){
            printf("%3d ", a[i][j]);
        }
        printf("|\n");
    }

    return 0;
}

void diagonal_principal_1(int m, int a[m][m]){
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j< m; j++){
            if(i == j){
                a[i][j] = 1;
            }
        }
    }
}