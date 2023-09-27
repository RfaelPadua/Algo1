#include <stdio.h>

int main(void){
    int B, T, area, area_felix, area_marzia;

    area = 160 * 70;

    printf("Informe o ponto B: ");
    scanf(" %d", &B);

    printf("Informe o ponto T: ");
    scanf(" %d", &T);

    area_felix = ((B + T)*70)/2;
    area_marzia = area - area_felix;

    if(area_felix < area_marzia)
        printf("2");
    else if(area_marzia < area_felix)
        printf("1");
    else
        printf("0");

    return 0;
}