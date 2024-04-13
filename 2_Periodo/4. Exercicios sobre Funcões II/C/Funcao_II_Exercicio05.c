#include <stdio.h>

int soma_diagonal_principal(int m, int a[m][m]);

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

    int soma = soma_diagonal_principal(m, a);

    printf("A soma da diagonal principal eh: %d\n", soma);

    return 0;
}

int soma_diagonal_principal(int m, int a[m][m]){
    int i, j, soma = 0;

    for(i = 0; i < m; i++){
        for(j = 0; j< m; j++){
            if(i == j){
                soma+= a[i][j];
            }
        }
    }
    return soma;
}