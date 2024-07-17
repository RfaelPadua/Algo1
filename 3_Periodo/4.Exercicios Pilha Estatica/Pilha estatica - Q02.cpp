/* Receba uma string (char palavra[50]) e uma Pilha. 
A função deve empilhar as vogais presentes na string 
recebida.*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTAM 30

typedef int Apontador;
typedef char Vogais;

typedef struct{
    Vogais vogais[MAXTAM];
    Apontador topo;
}TipoPilha;

void empilha(TipoPilha *pilha, Vogais vogal);
char desempilha(TipoPilha *pilha);
int ehVogal(char letra);
void empilhaVogais(TipoPilha *pilha, char *palavra, int tam);
void exibePilha(TipoPilha *pilha);

int main(){
    TipoPilha pilha;
    pilha.topo = 0;
    char palavra[50];
    strcpy(palavra, "Rafael de Padua Oliveira");

    empilhaVogais(&pilha, palavra, 25);

    exibePilha(&pilha);

    


}

void empilha(TipoPilha *pilha, Vogais vogal){

    if(pilha->topo > 30){
        printf("Pilha cheia!!\n");
        return;
    }

    pilha->topo++;
    pilha->vogais[pilha->topo - 1] = vogal;

    return;
}

char desempilha(TipoPilha *pilha){

    if(pilha->topo == 0){
        printf("Pilha vazia!!\n");
    }

    pilha->topo--;
    return pilha->vogais[pilha->topo+1];
}

int ehVogal(char letra){
    char vogais[6] = "aeiou";

    int i;

    for(i = 0; i < 5; i++){
        if(letra == vogais[i] || letra == toupper(vogais[i])){
            return 1;
        }
    }
    return 0;
}

void empilhaVogais(TipoPilha *pilha, char *palavra, int tam){
    int i;

    for(i = 0; i < tam; i++){
        if(ehVogal(palavra[i])){
            empilha(pilha, palavra[i]);
        }
    }
}

void exibePilha(TipoPilha *pilha){
    int i;
    char aux;
    if(pilha->topo == 0){
        printf("Pilha Vazia!!\n");
        return;
    }


    for(i = pilha->topo -1; i > -1; i--){
        aux = pilha->vogais[i];
        printf("%c\n", aux);
    }

}




















