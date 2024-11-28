#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef enum { ALUNO_SORT, HEAP_SORT } SortType;


//----------------------------------------------------------------//
                  // Funcoes de ordenacao
// HeapSort
void heapSort(int *vetor, int tam); 
void criaHeap(int *vetor, int i, int f);


// AlunoSort
void alunoSort(int *vetor, int inicio, int fim);
void separarMenoresMaiores(int* vetor, int inicio, int fim);



//----------------------------------------------------------------//
                  // Funcoes auxiliares


void testarOrdenacao(int *vetor, int tam);

int* gerarVetor(int tam);


//----------------------------------------------------------------//
                  // Funcoes de medicao de desempenho

// Para windows e linux (usando rusage)
#ifdef _WIN32
#include <windows.h>
#include <time.h>
void medirDesempenho(SortType sortType, int *vetor, int tam, long double *temp) {
    int *copiaVetor = (int*) malloc(tam * sizeof(int));
    memcpy(copiaVetor, vetor, tam * sizeof(int));

    clock_t inicio, fim;

    if(sortType == ALUNO_SORT){
        inicio = clock();
        alunoSort(copiaVetor, 0, tam);
        fim = clock();
    }else{
        inicio = clock();
        heapSort(copiaVetor, tam);
        fim = clock();
    }


    // Verifica se o vetor foi ordenado corretamente
    testarOrdenacao(copiaVetor, tam);

    // Calcula o tempo total em segundos
    *temp = (long double)(fim - inicio) / CLOCKS_PER_SEC;

    free(copiaVetor);
}

#else

#include <sys/resource.h>

void medirDesempenho(SortType sortType, int *vetor, int tam, long double *temp) {
    int *copiaVetor = (int*) malloc(tam * sizeof(int));
    memcpy(copiaVetor, vetor, tam * sizeof(int));

    struct rusage inicio, fim;
    if(sortType == ALUNO_SORT){
        getrusage(RUSAGE_SELF, &inicio);
        alunoSort(copiaVetor, 0, tam);
        getrusage(RUSAGE_SELF, &fim);
    }else{
        getrusage(RUSAGE_SELF, &inicio);
        heapSort(copiaVetor, tam);
        getrusage(RUSAGE_SELF, &fim);
    }

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

    free(copiaVetor);
}


#endif



int main() {
    int tamanhos[] = {1000, 2500, 5000, 7500, 10000, 25000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000}; // Diferentes tamanhos de vetores
    int numTestes = 5; // Numero de testes para cada tamanho de vetor
    long double tempHeap[5], tempAluno[5]; // Para armazenar os tempos de cada execucao

    //Loop sobre os tamanhos dos vetores
    for (int i = 0; i < 13; i++) { // 7 tamanhos diferentes
        int tam = tamanhos[i];
        
        // Gerar 5 vetores diferentes para o tamanho atual
        int* vetores[5];
        for (int j = 0; j < numTestes; j++) {
            vetores[j] = gerarVetor(tam);
        }

        // Testar HeapSort
        for (int j = 0; j < numTestes; j++) {
            medirDesempenho(HEAP_SORT, vetores[j], tam, &tempHeap[j]);
        }
        // Calcular o tempo medio para o HeapSort
        long double mediaHeap = 0;
        for (int j = 0; j < numTestes; j++) {
            mediaHeap += tempHeap[j];
        }
        mediaHeap /= numTestes;


        // Testar AlunoSort
        for (int j = 0; j < numTestes; j++) {
            medirDesempenho(ALUNO_SORT, vetores[j], tam, &tempAluno[j]);
        }
        // Calcular o tempo medio para o AlunoSort
        long double mediaAluno = 0;
        for (int j = 0; j < numTestes; j++) {
            mediaAluno += tempAluno[j];
        }
        
        mediaAluno /= numTestes;


        // printf resultados do heapSort e alunoSort lado a lado

        printf("\tN = %d\n", tam);
        printf("  HeapSort   vs   AlunoSort\n");
        for(int j = 0; j < numTestes; j++){
            printf("T%d:%.6Lf  |  %.6Lf\n",j + 1,  tempHeap[j], tempAluno[j]);
        }
        printf("TM:%.6Lf  |  %.6Lf\n", mediaHeap, mediaAluno);
    }
}

void criaHeap(int *vetor, int i, int f){
    int aux = vetor[i]; // Guarda o valor do pai
    int j = i * 2 + 1;  // Pega o primeiro filho

    // Enquanto o filho for menor que o pai
    while(j <= f){

        // Verifica se o filho da direita e maior que o da esquerda
        if(j < f && vetor[j] < vetor[j+1]){
            j = j + 1; 
        }

        // Se o filho for maior que o pai, troca
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

void heapSort(int *vetor, int tam){
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

        // Define o meio do vetor
        int meio = (inicio + fim) / 2;

        /*Define o vetor que vai armazenar os índices dos maiores elementos*/

        // Define o tamanho do vetor de índices dos maiores elementos, 25% do tamanho do vetor, no mínimo 3
        int tam = ((fim - inicio)/2) * 0.5; 
        tam = tam < 3 ? 3 : tam;   
        
        // Cria os vetores de índices
        int *maxIndex = (int*) malloc(tam * sizeof(int));
        int *minIndex = (int*) malloc(tam * sizeof(int));

        // Inicializa os vetores de índices
        for(int i = 0; i < tam; i++){
            maxIndex[i] = -1;
            minIndex[i] = -1;
        } 

        
        

        // Coloca o primeiro elemento como o maior
        maxIndex[0] = inicio;

        // Marca o índice do maior elemento atual
        int ultimoMax = 0; 

        // Percorre a primeira metade do vetor
        // Se encontrar um elemento maior que o maior atual, coloca o indice do maior atual no vetor de índices e atualiza o índice do maior atual
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
        // Se encontrar um elemento menor que o menor atual, coloca o indice do menor atual no vetor de índices e atualiza o índice do menor atual
        for (i = meio + 1; i < fim; i++) {
            if (vetor[i] < vetor[minIndex[ultimoMin]]) {
                ultimoMin = (ultimoMin + 1) % tam; // Atualiza o índice do menor atual de forma circular, se chegar ao final, volta para o início
                minIndex[ultimoMin] = i;
            }
        }


        // Percorre ambos os vetores de índices, de forma circular invertida, trocando assim os maiores elementos pelos menores
        for (i = 0; i < tam; i++) {

            // Se nao houver mais elementos para trocar, sai do loop
            if(minIndex[ultimoMin] == -1 || maxIndex[ultimoMax] == -1){
                break;
            }

            // Se o maior elemento for maior que o menor, troca
            // Se nao, sai do loop
            if (vetor[maxIndex[ultimoMax]] > vetor[minIndex[ultimoMin]]) {
                int aux = vetor[maxIndex[ultimoMax]];
                vetor[maxIndex[ultimoMax]] = vetor[minIndex[ultimoMin]];
                vetor[minIndex[ultimoMin]] = aux;

                ultimoMax = (ultimoMax - 1 + tam) % tam; // Atualiza o índice do maior atual de forma circular, se chegar ao início, volta para o final
                ultimoMin = (ultimoMin - 1 + tam) % tam; // Atualiza o índice do menor atual de forma circular, se chegar ao início, volta para o final

                estaSeparado = 0; // Se houve troca, o vetor nao está separado
            }else{
                break;
            }
            
        }

        // Libera a memória alocada para os vetores de índices
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


int* gerarVetor(int tam) {
    int i;

    int *vetor = (int*) malloc(tam * sizeof(int));
    for(i = 0; i < tam; i++) {
        vetor[i] = rand() % 1000000;
    }

    return vetor;
}