#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Estrutura do Item
typedef struct {
    char placa[10];
    int deslocamento;
    int prioridade;
}TipoItem;


// Estrutura da Fila Dinamica
typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila{
    TipoApontador Frente, Tras;
}TipoFila;

// Fun��es b�sicas de manipula��o da Fila Dinamica

void FFVazia(TipoFila *fila){
    fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
    fila->Tras = fila->Frente;
    fila->Frente->Prox = NULL;
}

int FilaVazia(TipoFila fila){
	return (fila.Frente == fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *fila){
    fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    fila->Tras = fila->Tras->Prox;
    fila->Tras->Item = x;
    fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *fila, TipoItem *item){
    TipoApontador q;
    
    if(FilaVazia(*fila)){
        printf("Erro: Fila esta vazia\n");
    }
    q = fila->Frente;
    fila->Frente = fila->Frente->Prox;
    *item = fila->Frente->Item;
    free(q);
}

void Exibe(TipoFila fila){
    TipoApontador aux = fila.Frente->Prox;
    
    while(aux != NULL){
        printf("\nPlaca==%s | Deslocamento==%d | Prioridade==%d", aux->Item.placa, aux->Item.deslocamento, aux->Item.prioridade);
        aux = aux->Prox;
    }
}


//Fun��es elaboradas para solu��o do probema apresentado

int CalculaQtdItensFila(TipoFila fila){
	TipoApontador aux;
	int quantidade = 0;
	
	aux = fila.Frente->Prox;
	while(aux != NULL){
		quantidade ++;
	}
	
	return quantidade;
}

void OrganizaFilaEspera(TipoFila *fila){
	TipoApontador aux;
	
	aux = fila->Frente->Prox;
	while(aux != NULL){
		
	}
}



int main(){
	//Filas e Itens que auxiliar�o na manipula��o e organiza��o dos estacionamentos
    TipoFila filaEstacionamento;
    TipoFila filaEspera;
    TipoFila filaAuxiliar;
    TipoItem item;
    
    //Vari�veis auxiliares
	int opcao, verificador;
	char resposta[4];
    
    
    //Criando as tr�s filas necess�rias
    FFVazia(&filaEspera);
    FFVazia(&filaAuxiliar);
    FFVazia(&filaEstacionamento);

	//Menu
    do{
        printf("------------------\n");
        printf("\t-- Escolha uma opcao --\n\n");
        printf("1. Estacionar um Carro\n");
        printf("2. Retirar um Carro\n");
        printf("0. Sair\n");
        printf("------------------\n");
        printf("R: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 1:
	            system("cls");
				// Chegada de um carro
	            // Quando um carro chegar, a mensagem devera especificar se existe ou 
	            // nao vaga para o carro dentro do estacionamento. Se nao exister vaga, 
	            // o carro esperara pela vaga na FilaEspera
	            
	            //Coletando informa��es do carro:
	            printf("-- Dados do carro --\n\n");
	            printf(". Informe a placa do carro: ");
	            gets(item.placa);
	            
	            do{
	            	verificador = 0;
	            	
	            	printf(". Voce possui prioridade para estacionar? ");
	            	gets(resposta);
	            	
	            	if(strcmp(resposta, "Sim") == 0 || strcmp(resposta, "sim") == 0){
		            	item.prioridade = 1;
		            	verificador =  1;
					} else if(strcmp(resposta, "Nao") == 0 || strcmp(resposta, "nao") == 0){
						item.prioridade = 0;
						verificador = 1;
					} else{
						printf("\nR: OPCAO INVALIDA!\n\n");
						system("pause");
						printf("\n");
					}
				} while(verificador == 0);
	            
	            item.deslocamento = 0;
	            
	            system("cls");
	            
	            /*Verificando se a Tv. Sr. Bom Jesus dos Passos est� com vaga para estacionar. 
				Se sim, o carro � estacionado nela e, caso contr�rio, ele fica aguardando na 
				Tv. Monsehor Jo�o Pedro*/
				if(CalculaQtdItensFila(filaEstacionamento) < 5){
					Enfileira(item, &filaEstacionamento);
					printf("\nR: Seu carro esta estacionado na Tv. Sr. Bom Jesus dos Passos.\n\n");
				} else{
					Enfileira(item, &filaEspera);
					printf("\nR: Como a Tv. Sr. Bom Jesus dos Passos esta cheia, seu carro esta aguardando na Tv. Monsenhor Joao Pedro.\n\n");
				}
				
				system("pause");

                break;
            case 2:
	                            // Saida de um carro
                // Quando um carro partir, a mensagem devera incluir o numero de vezes que 
                // o carro foi deslocado dentro do estacionamento, incluindo a propria partida, 
                // mas não a chegada
                printf("-- Saida de veiculo --/n");
                printf("\nInforme a placa do veiculo: ");
                gets(item.placa);

                /*
                  while(não achar o carro)
				  	verifica se carro está no estacionamento
					Desinfeleira 
					deslocamento++
					carro desenfileirado é o carro que vai sair?
						printf(informações do carro)
						print(Relatoria da situacao do estacionamento)
					Enfileira o carro na fila auxiliar
					
                */

			   

                
                
                
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
                
                break;
            default:
                printf("Opcao invalida\n");

        }
        

        system("cls");

    }while(opcao != 0);

    return 0;

}
