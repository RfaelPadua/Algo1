#include<stdio.h>

int eh_numero_perfeito(int valor);
int tem_numero_pefeito(int valores[]);
int n = 10;
int main(){
 
    int valores[n], i;

    printf("Informe dez valores inteiros:\n");

    for(i = 0; i < n; i++){
        scanf("%d", &valores[i]);
    }

    printf("%d", tem_numero_pefeito(valores));
}

int eh_numero_perfeito(int valor){
    int i;
    int soma = 1;
    for(i = 2;i < valor;i++){
        if(valor % i == 0){
            soma+=i;
        }
    }
    return soma == valor;
}

int tem_numero_pefeito(int valores[]){
    int i;

    for(i = 0; i < n; i++){
        if(eh_numero_perfeito(valores[i])){
            return 1;
        }
    }
    return 0;
}