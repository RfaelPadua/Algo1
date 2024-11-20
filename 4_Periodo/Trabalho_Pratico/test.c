#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "vetor_1000.c"   // Inclui o vetor de tamanho 1000
#include "vetor_5000.c"   // Inclui o vetor de tamanho 5000
#include "vetor_10000.c"  // Inclui o vetor de tamanho 10000
#include "vetor_50000.c"  // Inclui o vetor de tamanho 50000
#include "vetor_100000.c" // Inclui o vetor de tamanho 100000
#include "vetor_500000.c" // Inclui o vetor de tamanho 500000
#include "vetor_1000000.c"// Inclui o vetor de tamanho 1000000

/*
 * Algoritmo de Ordenação por Partições Dinâmicas
 * 
 * Descrição:
 * Este algoritmo realiza a ordenação de um vetor de números inteiros utilizando 
 * uma abordagem baseada em partições dinâmicas. Cada partição é criada a partir 
 * de um intervalo definido por [x - y, x + y], onde 'x' é um valor do vetor e 
 * 'y' é determinado dinamicamente de acordo com as características dos dados 
 * (por exemplo, por meio de média, desvio padrão ou uma constante fixa).
 *
 * O objetivo principal deste algoritmo é otimizar a ordenação para entradas 
 * com grande número de elementos (até 1.000.000), oferecendo uma alternativa 
 * eficiente e adaptativa às técnicas tradicionais.
 *
 * Passos principais do algoritmo:
 * 1. Definir o intervalo 'y' com base na distribuição dos dados.
 * 2. Criar partições dinâmicas para armazenar os números que se enquadram 
 *    em intervalos específicos.
 * 3. Ordenar individualmente as partições e combiná-las para formar o vetor final.
 *
 * Complexidade esperada:
 * - Determinação de 'y': O(n) para métodos baseados em média/desvio padrão.
 * - Criação das partições: O(n).
 * - Ordenação das partições: Dependente do método de ordenação escolhido (por exemplo, O(n log n)).
 * - Combinação das partições: O(n).
 *
 * Estrutura do código:
 * - Função `calcular_intervalo`: Calcula o valor de 'y' com base na distribuição dos dados.
 * - Função `criar_particoes`: Divide o vetor original em partições dinâmicas baseadas no intervalo [x - y, x + y].
 * - Função `ordenar_particoes`: Ordena os elementos dentro de cada partição.
 * - Função `combinar_particoes`: Combina as partições ordenadas no vetor final.
 * - Função `ordenar_por_particoes`: Função principal que integra todas as etapas e realiza a ordenação.
 *
 * Vantagens:
 * - Adaptação às características dos dados.
 * - Potencial para melhor desempenho em conjuntos de dados heterogêneos.
 *
 * Desvantagens:
 * - Custo inicial para determinar 'y' pode ser significativo em alguns cenários.
 * - Sensível à escolha da lógica de definição de 'y'.
 *
 * Uso:
 * O algoritmo pode ser utilizado em casos onde a distribuição dos dados é desconhecida 
 * ou varia significativamente, sendo uma abordagem intermediária entre algoritmos tradicionais.

 */



// função para teste de algoritmos de ordenação
// deve receber a função de ordenação como parâmetro e até qual vetor ordenar, vetor de 1000, 5000, 10000, 50000, 100000, 500000, 1000000
void test(void (*sort)(int*, int), int size){
    if(size < 1000) return;

    clock_t start, end;
    double time;

    start = clock();
    sort(vetor_1000, 1000);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", time);

    if(size == 1000) return;

    start = clock();
    sort(vetor_5000, 5000);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", time);

    if(size == 5000) return;

    start = clock();
    sort(vetor_10000, 10000);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", time);

    if(size == 10000) return;

    start = clock();
    sort(vetor_50000, 50000);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", time);

    if(size == 50000) return;

    start = clock();
    sort(vetor_100000, 100000);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", time);

    if(size == 100000) return;

    start = clock();
    sort(vetor_500000, 500000);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", time);

    if(size == 500000) return;

    start = clock();
    sort(vetor_1000000, 1000000);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", time);
}
    


int main(){
            

}