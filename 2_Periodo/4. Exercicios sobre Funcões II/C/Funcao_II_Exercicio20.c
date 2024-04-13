#include<stdio.h>
#include<string.h>

int compararStrings(char str1[], char str2[]);
int estaPresente(char matriz[][50], char str[]);

int main(){
    char matriz[5][50], str[50];
    int i;

    for(i = 0; i < 5; i++){
        printf("Informe uma palavra: ");
        fgets(matriz[i], sizeof(matriz), stdin);
        matriz[i][strlen(matriz[i])-1] = '\0'; 
    }

    printf("Informe uma palavra a ser comparada: ");
    fgets(str,sizeof(str), stdin);

    str[strlen(str) - 1] = '\0';
    

    printf("%d", estaPresente(matriz, str));
}


int compararStrings(char str1[], char str2[]){

    int i, j, cont = 0;

    if(strlen(str1) != strlen(str2)){
        return 0;
    }

    for(i = 0; i < strlen(str1); i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }

    return 1;
}

int estaPresente(char matriz[][50], char str[]){
    int i;


    for(i = 1; i < 5; i++){
        if(compararStrings(str, matriz[i])){
            return 1;
        }
    }
    
    return 0;
}