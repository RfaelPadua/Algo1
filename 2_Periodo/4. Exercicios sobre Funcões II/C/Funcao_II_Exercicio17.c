#include<stdio.h>

void trocarCol(int m, int a[][m], int col1, int col2);

int main(){
    int m, i, j;
    int col1, col2;
    printf("Informe m de Amxm: ");
    scanf("%d", &m);
    int a[m][m];

    for(i = 0; i < m; i++){
        for(j = 0;j < m; j++){
            printf("Informe o numedo da posicao A%dx%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);fflush(stdin);
        }
    }
    printf("Informe col1: ");
    scanf("%d", &col1);fflush(stdin);

    printf("Informe col2: ");
    scanf("%d", &col2);

    printf("\n");
    col1--;
    col2--;
    trocarCol(m, a, col1, col2);

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    
}


void trocarCol(int m, int a[m][m], int col1, int col2){
    int i, temp;

    for (i = 0; i < m; i++) {
        temp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = temp;
    }
}