#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>





#ifdef _WIN32

#include <windows.h>
#include <time.h>




// Declaracao das funcões de ordenacao
void heapSort(int *vetor, int n, int tam); 
void criaHeap(int *vetor, int i, int f);

void alunoSort(int *vetor, int inicio, int fim);
void separarMenoresMaiores(int* vetor, int inicio, int fim);



// Declaracao das funcões para testar a ordenacao
void testarOrdenacao(int *vetor, int tam);

void medirDesempenho(void (*sort)(int*, int, int), int *vetor, int tam, long double *temp) {
    int *copiaVetor = (int*) malloc(tam * sizeof(int));
    memcpy(copiaVetor, vetor, tam * sizeof(int));

    clock_t inicio = clock();
    sort(copiaVetor, 0, tam);
    clock_t fim = clock();

    // Verifica se o vetor foi ordenado corretamente
    testarOrdenacao(copiaVetor, tam);

    // Calcula o tempo total em segundos
    *temp = (long double)(fim - inicio) / CLOCKS_PER_SEC;
}

#else

#include <sys/resource.h>

void medirDesempenho(void (*sort)(int*, int, int), int *vetor, int tam, long double *temp) {
    int *copiaVetor = (int*) malloc(tam * sizeof(int));
    memcpy(copiaVetor, vetor, tam * sizeof(int));

    struct rusage inicio, fim;
    getrusage(RUSAGE_SELF, &inicio);
    
    sort(copiaVetor, 0, tam);
    
    getrusage(RUSAGE_SELF, &fim);

    // Verifica se o vetor foi ordenado corretamente
    testarOrdenacao(copiaVetor, tam);
    
    // Calcula o tempo no modo usuário em microsegundos
    long sec_user = fim.ru_utime.tv_sec - inicio.ru_utime.tv_sec;
    long usec_user = fim.ru_utime.tv_usec - inicio.ru_utime.tv_usec;
    long total_user_usec = sec_user * 1000000 + usec_user;

    // Calcula o tempo no modo sistema em microsegundos
    long sec_sys = fim.ru_stime.tv_sec - inicio.ru_stime.tv_sec;
    long usec_sys = fim.ru_stime.tv_usec - inicio.ru_stime.tv_usec;
    long total_sys_usec = sec_sys * 1000000 + usec_sys;

    // Soma os tempos (modo usuário + modo sistema)
    long total_usec = total_user_usec + total_sys_usec;

    // Armazena o tempo total na variável temp (em segundos com precisao de microsegundos)
    *temp = total_usec / 1000000.0;
}


#endif

int* gerarVetor(int tam) {
    int i;

    int *vetor = (int*) malloc(tam * sizeof(int));
    for(i = 0; i < tam; i++) {
        vetor[i] = rand() % 1000000;
    }

    return vetor;
}
// Funcao para medir desempenho de um algoritmo de ordenacao


int main() {
    int tamanhos[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000}; // Diferentes tamanhos de vetores
    int numTestes = 5; // Número de testes a serem feitos para cada tamanho
    long double tempHeap[5], tempAluno[5]; // Para armazenar os tempos de cada execucao

    //Loop sobre os tamanhos dos vetores
    for (int i = 0; i < 7; i++) { // 7 tamanhos diferentes
        int tam = tamanhos[i];
        printf("N = %d\n", tam);
        
        // Gerar 5 vetores diferentes para o tamanho atual
        int* vetores[5];
        for (int j = 0; j < numTestes; j++) {
            vetores[j] = gerarVetor(tam);
        }

        // Testar HeapSort
        printf("heapSort\n");
        for (int j = 0; j < numTestes; j++) {
            medirDesempenho(heapSort, vetores[j], tam, &tempHeap[j]);
            printf("%.6Lf\n", tempHeap[j]);
        }
        // Calcular o tempo medio para o HeapSort
        long double mediaHeap = 0;
        for (int j = 0; j < numTestes; j++) {
            mediaHeap += tempHeap[j];
        }
        mediaHeap /= numTestes;
        printf("%.6Lf\n", mediaHeap);

        // Testar AlunoSort
        printf("AlunoSort\n");
        for (int j = 0; j < numTestes; j++) {
            medirDesempenho(alunoSort, vetores[j], tam, &tempAluno[j]);
            printf("%.6Lf\n", tempAluno[j]);
        }
        // Calcular o tempo medio para o AlunoSort
        long double mediaAluno = 0;
        for (int j = 0; j < numTestes; j++) {
            mediaAluno += tempAluno[j];
        }
        mediaAluno /= numTestes;
        printf("%.6Lf\n", mediaAluno);

    }

    //testar alunnoSort para pior caso
    int* vetor = (int*) malloc(1000000 * sizeof(int));
    for(int i = 0; i < 1000000; i++){
        vetor[i] = 1000000 - i;
    }
    printf("Pior caso\n");
    medirDesempenho(alunoSort, vetor, 1000000, &tempAluno[0]);
    printf("%.6Lf\n", tempAluno[0]);
    return 0;
}

void criaHeap(int *vetor, int i, int f){
    int aux = vetor[i];
    int j = i * 2 + 1;


    while(j <= f){

        if(j < f && vetor[j] < vetor[j+1]){
            j = j + 1;
        }

        if(aux < vetor[j]){
            vetor[i] = vetor[j];
            i = j;
            j = i * 2 + 1;
        } else {
            j = f + 1;
        }
    }
    vetor[i] = aux;


}

void heapSort(int *vetor, int n, int tam){
    int i;

    for(i = (tam-1)/2; i >= 0; i--){
        criaHeap(vetor, i, tam - 1);
    }

    for(i = tam - 1; i > 0; i--){
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i - 1);
    }
}

void separarMenoresMaiores(int* vetor, int inicio, int fim) {
    int estaSeparado = 0; // Tag para verificar se o vetor está separado


    
   

    while(!estaSeparado){
        estaSeparado = 1; // Inicialmente, considera-se que o vetor está separado
        int i;
        int meio = (inicio + fim) / 2;
        int tam = ((fim - inicio)/2) * 0.1; // Tamanho do vetor de índices dos maiores elementos
        tam = tam < 3 ? 3 : tam; 
        int *maxIndex = (int*) malloc(tam * sizeof(int));
        int *minIndex = (int*) malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
            maxIndex[i] = -1;
            minIndex[i] = -1;
        } 

        // Definir o meio do vetor
        

        // Definir o tamanho do vetor de índices dos maiores elementos (10% do tamanho do vetor)
        // Se o tamanho for menor que 3, tam = 3
        

        // Vetor de índices dos maiores elementos, inicializado com -1
        
        

        // Coloca o primeiro elemento como o maior
        maxIndex[0] = inicio;

        // Marca o índice do maior elemento atual
        int ultimoMax = 0; 

        // Percorre a primeira metade do vetor
        // Se encontrar um elemento maior que o maior atual, atualiza o vetor de índices e o índice do maior atual
        for (i = inicio + 1; i < meio; i++) { 
            if (vetor[i] > vetor[maxIndex[ultimoMax]]) { 
                ultimoMax = (ultimoMax + 1) % tam; 
                maxIndex[ultimoMax] = i;  
            }
        }



        // Coloca o primeiro elemento como o menor
        minIndex[0] = meio;

        // Marca o índice do menor elemento atual
        int ultimoMin = 0;

        // Percorre a segunda metade do vetor
        // Se encontrar um elemento menor que o menor atual, atualiza o vetor de índices e o índice do menor atual
        for (i = meio + 1; i < fim; i++) {
            if (vetor[i] < vetor[minIndex[ultimoMin]]) {
                ultimoMin = (ultimoMin + 1) % tam;
                minIndex[ultimoMin] = i;
            }
        }

        //         // Coloca o primeiro elemento como o maior
        // maxIndex[0] = meio - 1;

        // // Marca o índice do maior elemento atual
        // int ultimoMax = 0; 

        // // Percorre a primeira metade do vetor
        // // Se encontrar um elemento maior que o maior atual, atualiza o vetor de índices e o índice do maior atual
        // for (i = meio - 1; i >= inicio; i--) { 
        //     if (vetor[i] > vetor[maxIndex[ultimoMax]]) { 
        //         ultimoMax = (ultimoMax + 1) % tam; 
        //         maxIndex[ultimoMax] = i;  
        //     }
        // }

        // // Vetor de índices dos menores elementos, inicializado com -1;

        // // Coloca o primeiro elemento como o menor
        // minIndex[0] = fim - 1;

        // // Marca o índice do menor elemento atual
        // int ultimoMin = 0;

        // // Percorre a segunda metade do vetor
        // // Se encontrar um elemento menor que o menor atual, atualiza o vetor de índices e o índice do menor atual
        // for(i = fim - 1; i >= meio; i--){
        //     if(vetor[i] < vetor[minIndex[ultimoMin]]){
        //         ultimoMin = (ultimoMin + 1) % tam;
        //         minIndex[ultimoMin] = i;
        //     }
        // }


        // Troca os elementos se o maior da primeira metade for maior que o menor da segunda metade
        for (i = 0; i < tam; i++) {
            if(minIndex[ultimoMin] == -1 || maxIndex[ultimoMax] == -1){
                break;
            }

            if (vetor[maxIndex[ultimoMax]] > vetor[minIndex[ultimoMin]]) {
                int aux = vetor[maxIndex[ultimoMax]];
                vetor[maxIndex[ultimoMax]] = vetor[minIndex[ultimoMin]];
                vetor[minIndex[ultimoMin]] = aux;



                ultimoMax = (ultimoMax - 1 + tam) % tam;
                ultimoMin = (ultimoMin - 1 + tam) % tam;



                estaSeparado = 0;
            }else{
                break;
            }
            
        }

        free(maxIndex);
        free(minIndex);
    }
}


void alunoSort(int* vetor, int inicio, int fim) {

    if (fim - inicio <= 1) return; // Se to tamanho <= 1, já está ordenado

    int meio = (inicio + fim) / 2; // Dividir o vetor em duas partes

    separarMenoresMaiores(vetor, inicio, fim); // Separar o vetor em menores e maiores
    alunoSort(vetor, inicio, meio); // Ordenar a primeira metade
    alunoSort(vetor, meio, fim); // Ordenar a segunda metade

}





void testarOrdenacao(int *vetor, int tam){
    int i;
    for(i = 0; i < tam - 1; i++){
        if(vetor[i] > vetor[i+1]){
            printf("Erro na ordenacao\n");
            printf(" %d nao eh menor que %d\n", vetor[i], vetor[i+1]);

        }
    }
}
