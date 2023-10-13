#include<stdio.h>
#include<string.h>

int contagemVogais(char str[]);
int maisVogais(char str[][50]);

int main(){
    char str[5][50];
    int i;

    for(i = 0; i < 5; i++){
        printf("Informe uma palavra: ");
        fgets(str[i], sizeof(str), stdin);
    }
    

    printf("A string %d tem mais vogais", maisVogais(str));
}


int contagemVogais(char str[]){
    char vogais[11] = "aeiouAEIOU";
    int i, j, cont = 0;

    for(i = 0; i < strlen(str); i++){
        for(j = 0; j < 10; j++){
            if(str[i] == vogais[j]){
                cont++;
                break;
            }
        }
    }

    return cont;
}

int maisVogais(char str[][50]){
    int i;
    int maisVogais = 0;
    int aux = contagemVogais(str[0]);

    for(i = 1; i < 5; i++){
        int a = contagemVogais(str[i]);
        if( a > aux){
            maisVogais = i;
            aux = a;
        }
    }
    return maisVogais;
}