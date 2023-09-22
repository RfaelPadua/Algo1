/*******************************************************************
*   Faça um programa que faça 5 perguntas para uma pessoa sobre 
*   um crime. O programa deve no final emitir uma classificação
*   sobre a participação da pessoa no crime. Se a pessoa responder
*   positivamente a 2 questões ela deve ser classificada como 
*   “Suspeita”, entre 3 e 4 como “Cúmplice” e 5 como “Assassino“.
*   Caso contrário, ele será classificado como “Inocente “.
*******************************************************************/
#include <stdio.h>

int main(void){

    char p1;
    int n = 0;
    
    printf("Responda as seguintes perguntas com \"s\" para SIM e \"n\" para NAO\n");
    printf("Telefonou para a vitima? ");
    scanf(" %c", &p1);
    p1 == 's'? n++ : n == n;
    printf("Esteve no local do crime? ");
    scanf(" %c", &p1);
    p1 == 's' ? n++ : n == n;
    printf("Mora perto da vitima? ");
    scanf(" %c", &p1);
    p1 == 's' ? n++ : n == n;
    printf("Devia para a vitima? ");
    scanf(" %c", &p1);
    p1 == 's' ? n++ : n == n;
    printf("Ja trabalhou com a vitima? ");
    scanf(" %c", &p1);
    p1 == 's' ? n++ : n == n;

    if(n < 2)
        printf("Inocente.\n");
    else if(n < 3)
        printf("Suspeita.");
    else if (n < 5)
        printf("Cumplice.");
    else
        printf("Assasino.");
    
}