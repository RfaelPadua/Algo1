#include<stdio.h>

void crescente(int vet[]);

void decrescente(int vet[]);

int main(){
    system("cls");

    int i,
    vet[10];
    char letra;

    printf("Preencha um vetor de 10 posicoes:\n");
    for(i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
    }
    fflush(stdin);
    printf("Aperte C para ordenar de forma crescente ou D para ordem decrescente: ");
    scanf("%c", &letra);

    if(letra == 'C'){
        crescente(vet);
        printf("O vetor em ordem crescente:\n");
    }else if(letra == 'D'){
        decrescente(vet);
        printf("O vetor em ordem decrescente:\n");
    }else{
        printf("Input invalido.");
        return 0;
    }

    for(i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }
}

void crescente(int vet[]){
    int i = 0, tam = 9, aux;
    while(tam > 0){
        for(i = 0; i < tam; i++){
        if(vet[i] > vet[i+1]){
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
            
            }
        }
        tam--;
    }
}

void decrescente(int vet[]){
    int i = 0, tam = 9, aux;
    while(tam > 0){
        for(i = 0; i < tam; i++){
        if(vet[i] < vet[i+1]){
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
            
            }
        }
        tam--;
    }
}