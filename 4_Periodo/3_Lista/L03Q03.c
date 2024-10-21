#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Escreva um algoritmo que receba valores em um vetor de 10 posições e 
//imprima  “ORDENADO” se o vetor estiver em ordem crescente. Qual é a 
//função de custo de pior caso e sua  ordem de complexidade O?

void GerarVetorOrdenado(int *vetor, int tam);

void GerarVetorAleatorio(int *vetor, int tam);

int EstaOrdenado(int *vetor, int tam);

void ImprimirVetor(int *vetor, int tam);



int main(){

    int tam = 10;
    int vetor[tam];




    GerarVetorAleatorio(vetor, tam); // Gerar um vetor aleatorio no range de 0 a 100;
    ImprimirVetor(vetor, tam); // Imprimir Vetor


    if(EstaOrdenado(vetor, tam)){ // Verifica se o vetor esta ordenado em ordem crescente
        printf("ORDENADO\n");
    }else{
        printf("NAO ESTA ORDENADO\n");
    }


    GerarVetorOrdenado(vetor, tam); // Gerar um vetor ordenado onde cada n é igual a i+i

    ImprimirVetor(vetor, tam); // Imprimir Vetor

    if(EstaOrdenado(vetor, tam)){ // Verifica se o vetor esta ordenado em ordem crescente
        printf("ORDENADO\n");
    }else{
        printf("NAO ESTA ORDENADO\n");
    }


    srand(time(NULL)); // Gerar Semente
    int n = rand() % 20; // Numero a ser inserido ao vetor

    



}


void GerarVetorOrdenado(int *vetor, int tam){
    int i;
    for(i=0; i <tam; i++){
        vetor[i] = i+i+1;
    }
}

void GerarVetorAleatorio(int *vetor, int tam){
    srand(time(NULL));
    int i;
    for(i = 0; i < tam; i++){
        vetor[i] = rand()%100;
    }
}

int EstaOrdenado(int *vetor, int tam){
    int i;

    for(i = 0; i < tam - 1 ; i++){
        if(vetor[i] > vetor[i+1]){
            return 0;
        }
    }

    return 1;
}

void ImprimirVetor(int *vetor, int tam){
    int i;

    for(i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}