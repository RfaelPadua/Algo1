#include<stdio.h>
int elementosRepetidos(int m, int a[][m]);
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
    if(elementosRepetidos(m, a)){
        printf("Ha elementos repetidos");
    }else{
        printf("Nao ha elementos repetidos");
    }
}


int elementosRepetidos(int m, int a[][m]){
    int i, j, k, l; 

    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){

            for(k = i+1; k < m; k++){
                for(l = j; l < m; l++){
                    if(a[i][j] == a[k][l]){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}