#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char *argv[]){



    int i, j, soma = 0;

    int opcao = atoi(argv[1]);
    int n = atoi(argv[2]);

    clock_t inicio, fim;
    unsigned long int tempo;
    inicio = clock();

    if( opcao == 1){
        for(i = 1; i<= n; i++){
            soma +=i;
        }
    }else if( opcao == 2){
        for(i = 0; i < n ; i++){
            for(j = 0; j<=i; j++){
                soma += 1;
            }
        }
    }else if(opcao == 3){
        soma = n * ( n + 1)/2;
    }
    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    printf("tempo: %lu milissegundos\n", tempo);

    printf("\nsoma = %d\n\n", soma);



    return 0;
}