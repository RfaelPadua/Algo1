#include <stdio.h>	
#include <string.h>

#define MAXTAM 100 

typedef int TipoApontador;
typedef int TipoChave;

typedef struct{
	char parenteses[MAXTAM];
	int topo = 0;
}Pilha;

void Empilha(Pilha *pilha, char caractere){
	
	if(pilha->topo < MAXTAM){ //Verifica se a pilha est� cheia antes de empilhar;
		pilha->topo++;
		pilha->parenteses[pilha->topo-1] = caractere;
	}else{
		printf("Pilha cheia!!\n");
	}
	
}

int Desempilha(Pilha *pilha){	
	if(pilha->topo == 0){
		printf("Pilha Vazia!!\n");
		return 0;
	}else{
		pilha->topo--;
		return 1;
	}
}

int ParidadeParenteses(Pilha *pilha, char *expresao){
	
	int i;
	char caractere;
	
	for(i = 0; expresao[i] != '\0';i++){
		caractere = expresao[i];
		
		if(caractere == '('){
			Empilha(pilha, caractere);
			
		}else if(caractere == ')'){
			
			if(pilha->topo == 0){
				return 0;
				
			}else{
				Desempilha(pilha);
			}
		}
	}
	
	if (pilha->topo == 0) {
        return 1; // Express�o com par�nteses balanceados
    } else {
        return 0; // Express�o com par�nteses desbalanceados
    }
}

int main() {
    Pilha pilha;
    char expressao[MAXTAM] = "((X+Y)+Z)/2";


    int resultado = ParidadeParenteses(&pilha, expressao);

    if (resultado == 1) {
        printf("A Expressao %s, esta com parenteses balanceados!\n", expressao);
    } else {
        printf("A Expressao %s, esta com parenteses desbalanceados!\n", expressao);
    }
    
    
    strcpy(expressao, "(X+Y)+Z/2)"); 


    resultado = ParidadeParenteses(&pilha, expressao);

    if (resultado == 1) {
        printf("A Expressao %s, esta com parenteses balanceados!\n", expressao);
    } else {
        printf("A Expressao %s, esta com parenteses desbalanceados!\n", expressao);
    }
    
    strcpy(expressao, "(X+Y)+(Z/2"); 


    resultado = ParidadeParenteses(&pilha, expressao);

    if (resultado == 1) {
        printf("A Expressao %s, esta com parenteses balanceados!\n", expressao);
    } else {
        printf("A Expressao %s, esta com parenteses desbalanceados!\n", expressao);
    }

    return 0;
}
