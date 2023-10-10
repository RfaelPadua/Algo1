#include<stdio.h>
int colunasNulas(int m, int a[][m]);
int main(){
    int m, i, j;
    printf("Informe m de Amxm: ");
    scanf("%d", &m);
    int a[m][m];

    for(i = 0; i < m; i++){
        for(j = 0;j < m; j++){
            printf("Informe o numedo da posicao A%dx%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d",  colunasNulas(m, a));

}


int colunasNulas(int m, int a[][m]){
    int i, j, cont = 0, qntNulo = 0; 

    for(i = 0; i < m; i++, cont = 0){
        for(j = 0; j < m; j++){
            cont+=a[j][i];
        }
        if(cont == 0){
            qntNulo++;
        }
    }

    return qntNulo;
}