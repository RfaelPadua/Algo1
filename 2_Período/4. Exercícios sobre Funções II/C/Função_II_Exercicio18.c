#include<stdio.h>
#include<string.h>

int porcentagemVogais(char str[]);

int main(){
    char str[50];

    printf("Informe uma palavra: ");
    fgets(str, sizeof(str), stdin);

    printf("%d%% da palavra eh vogal", porcentagemVogais(str));
}


int porcentagemVogais(char str[]){
    char vogais[10] = "aeiouAEIOU";
    int i, j, cont = 0;

    for(i = 0; i < strlen(str); i++){
        for(j = 0; j < 10; j++){
            if(str[i] == vogais[j]){
                cont++;
                break;
            }
        }
    }

    return (cont*100)/(strlen(str)-1);
}