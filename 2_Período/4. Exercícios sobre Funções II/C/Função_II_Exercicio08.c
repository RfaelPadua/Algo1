#include<stdio.h>
void coordenadaMaiorElemento(int m, int a[][m], int *linha, int *coluna);
int main(){
    int m;
    printf("Informe m de Amxm: ");
    scanf("%d", &m);

    int a[m][m];
    int i, j;
    int maiorLinha, maiorColuna;

    for(i = 0; i < m; i++){
        for(j = 0;j < m; j++){
            printf("Informe o numedo da posicao A%dx%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    coordenadaMaiorElemento(m, a, &maiorLinha, &maiorColuna);

    printf("O maior elementa esta em A%dx%d.\n", maiorLinha, maiorColuna);
    
    return 0;
}

void coordenadaMaiorElemento(int m, int a[][m], int *linha, int *coluna){
    int i, j;
    int maiorElemento = a[0][0];
    for(i = 0; i < m; i++){
        for(j = 0; j < m ; j++){
            if(maiorElemento < a[i][j]){
                maiorElemento = a[i][j];
                *linha = i+1;
                *coluna = j+1;
            }
        }
    }
}
