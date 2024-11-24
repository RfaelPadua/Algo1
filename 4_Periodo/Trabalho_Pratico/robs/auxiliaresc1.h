#ifndef AUXILIARESC1_H
#define AUXILIARESC1_H

// Preenche o vetor com valores aleatórios
void preencherVetorAleatorio(int vetorInt[], int qtdNums);

// Faz a troca entre dois elementos
void troca(int *a, int *b);

// Particiona o vetor e retorna o índice do pivô
int particiona(int vetor[], int esquerda, int direita, size_t *compChaves);

// Função principal do QuickSort
void quicksort(int vetor[], int esquerda, int direita, size_t *compChaves);

// Escreve os resultados no arquivo com o tempo de CPU gasto
void resultadosArquivo(char nomeArquivo[], double tempoUsuario, double tempoSistema, size_t compChaves);

#endif// AUXILIARESC1_H