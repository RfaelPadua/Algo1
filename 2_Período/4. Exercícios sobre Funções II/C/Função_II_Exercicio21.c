#include<stdio.h>
#include<stdlib.h>

void juntarVetores(int vet1[], int vet2[], int vetFinal[]);

int main(){
    int vet1[10], vet2[10], vetFinal[20];
    int i;
    
    printf("Preencha o primeiro vetor com numeros inteiros:\n");
    for(i = 0; i < 10; i++){
        scanf("%d", &vet1[i]);
    }
    system("cls");

    printf("Preencha o segundo vetor com numeros inteiros:\n");
    for(i = 0; i < 10; i++){
        scanf("%d", &vet2[i]);
    }

    juntarVetores(vet1, vet2, vetFinal);
    printf("O vetor final e: \n");
    for(i = 0; i < 20; i++){
        printf("%d ", vetFinal[i]);
    }
}



void juntarVetores(int vet1[], int vet2[], int vetFinal[]){
    int i, 
    j = 0, k = 0;

    for(i = 0; i < 20; i++){
        if(i % 2 == 0){
            vetFinal[i] = vet1[j];
            j++;
        }else{
            vetFinal[i] = vet2[k];
            k++;
        }
    }
}