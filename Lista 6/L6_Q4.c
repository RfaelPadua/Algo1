#include<stdio.h>

int main(){
    int idade;

    printf("Informe a sua idade: ");
    scanf("%d", &idade);

    if(idade < 16)
        printf("Nao pode votar!");
    else if(idade < 18 || idade >= 65)
        printf("Seu voto eh facultativo!");
    else
        printf("Seu voto eh obrigatorio");

return 0;

}