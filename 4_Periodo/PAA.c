#include<stdio.h>
#include<stdlib.h>
#include<time.h>





#define MAXUNSIGNINT 4294967295

//função que volta todos os numeros primos até um numero n
int numerosPrimosForcaBruta(int n, int *primos){
    int i, j, cont = 1;
    for(i = 2; i <= n; i++){
        for(j = 2; j < i; j++){
            if(i % j == 0){
                break;
            }
        }
        if(j == i){ 
            primos[cont] = i;
            cont++;
        }
    }
    return cont;
}


int numerosPrimosCrivo(int n, int *primos){
    int i, j, cont = 1;
    int *numeros = (int*) malloc((n+1) * sizeof(int));
    for(i = 0; i <= n; i++){ 
        numeros[i] = 1; 
    }
    for(i = 2; i <= n; i++){ 
        if(numeros[i] == 1){ 
            primos[cont] = i;
            cont++;
            for(j = i; j <= n; j += i){
                numeros[j] = 0;
            }
        }
    }
    free(numeros);
    return cont;
}


#ifdef _WIN32
#include <windows.h>
#include <time.h>

void medirDesempenho(int n, int *primos){
    clock_t inicio, fim;

    inicio = clock();
    int numerosPrimos = numerosPrimosForcaBruta(n, primos);
    fim = clock();
    printf("Forca Bruta\n");
    printf("Tempo: %lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    printf("Quantidade de primos: %d\n", numerosPrimos);
    printf("\n");

    inicio = clock();
    numerosPrimos = numerosPrimosCrivo(n, primos);
    fim = clock();
    printf("Crivo\n");
    printf("Tempo: %lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    printf("Quantidade de primos: %d\n", numerosPrimos);
    printf("\n");


}


#else

#include <sys/resource.h>

void medirDesempenho(int n, int *primos){
    struct rusage usage;
    struct timeval start, end;
    double tempo;
    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_utime;
    int numerosPrimos = numerosPrimosForcaBruta(n, primos);
    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;
    tempo = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Forca Bruta\n");
    printf("Tempo: %lf\n", tempo);
    printf("Quantidade de primos: %d\n", numerosPrimos);
    printf("\n");

    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_utime;
    numerosPrimos = numerosPrimosCrivo(n, primos);
    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;
    tempo = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Crivo\n");
    printf("Tempo: %lf\n", tempo);
    printf("Quantidade de primos: %d\n", numerosPrimos);
    printf("\n");

}


#endif

int main(){
    int n = 10;
    

    for(;n <= 1000000000; n *= 10){
        int *primos = (int*) malloc((n+1) * sizeof(int));
        printf("N: %d\n", n);
        medirDesempenho(n, primos);
        printf("\n");
        free(primos);
    }


    return 0;
}