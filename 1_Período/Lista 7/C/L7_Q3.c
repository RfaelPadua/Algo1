/*******************************************************************
*   Escreva um programa para ler o número de lados
*   de um polígono regular e a medida do lado (em
*   cm). 
*******************************************************************/
#include <stdio.h>
#include <math.h>

int main(void){
    
    int n_lados;
    float m_lado, area;

    printf("Numero de lados de um poligono regular: ");
    scanf("%d", &n_lados);

    printf("Medida do lado em cm: ");
    scanf("%f", &m_lado);

    switch (n_lados)
    {
    case 3 :
//      Se o número de lados for igual a 3 escrever
//      TRIÂNGULO e o valor da área
        area = (m_lado * m_lado * sqrt(3)) / 4;
        printf("TRIANGULO\nArea = %.2f cm^2\n", area);
        break;
    case 4:
//      Se o número de lados for igual a 4 escrever
//      QUADRADO e o valor da sua área.
        area = m_lado * m_lado;
        printf("QUADRADO\nArea = %.2f cm^2\n", area);
        break;
    case 5:
//      Se o número de lados for igual a 5 escrever
//      PENTÁGONO.
        area = m_lado * m_lado;
        printf("PENTAGONO\n");
        break;
    default:
        printf("Numero de lados invalida\n");
        break;
    }
    return 0;
}