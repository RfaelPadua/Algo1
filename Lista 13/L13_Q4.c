#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[10][3];
    int i, j, cont1, cont2, vetor[3] = {0};

    for(i = 0; i< 10; i ++){
        for(j = 0; j < 3; j ++){
            printf("Aluno %d, prova %d: ", i + 1, j + 1);
            scanf(" %d", &matriz[i][j]);
        }
        system("cls");
    }

    for(i = 0; i< 10; i ++){
        cont1 = 0;
        cont2 = 0;
        for(j = 0; j < 3; j ++){
            if(cont1 < matriz[i][j]){
                cont1 = matriz[i][j];
                cont2 = j;
            }
        }
        switch (cont2)
        {
        case 0:
            vetor[0]++;
            break;
        case 1:
            vetor[1]++;
            break;
        case 2:
            vetor[2]++;
            break;
        default:
            break;
        } 
    }

    printf("%d alunos cuja a melhor nota foi a prova 1\n", vetor[0]);
    printf("%d alunos cuja a melhor nota foi a prova 2\n", vetor[1]);
    printf("%d alunos cuja a melhor nota foi a prova 3\n", vetor[2]);
}