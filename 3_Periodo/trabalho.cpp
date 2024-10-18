#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



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
        aux = aux->Prox;
	}
	
	return quantidade;
}
void retiraCarroFilaEspera(TipoFila *filaEspera, TipoItem *item){
	TipoApontador aux, q;
	
	
	aux = filaEspera->Frente;
	if(aux->Prox->Item.prioridade == 1){
		Desenfileira(filaEspera, item);
	} else{
		aux = aux->Prox;
		while(aux->Prox != NULL){
			if(aux->Prox->Item.prioridade == 1){
				q = aux->Prox;
				*item = aux->Prox->Item;
				aux->Prox = aux->Prox->Prox;
				free(q);
				
				//Verificando se por acaso a célula que foi retirada junto do item não é a célula que demarca a parte de Tras da fila:
				if(aux->Prox == NULL){
					filaEspera->Tras = aux;
				}
				
				/*Como queremos retornar apenas o primeiro carro na fila que possui prioridade '1', o percorrimento da fila é interrompido para que não aconteça 
				de ter outro carro com prioridade '1' e este ser sobreescrito no retorno da função pelo '*item'*/
				break;
			}
			
			aux = aux->Prox;
		}
	}
	
	
}


int CarroEstacionado(TipoFila *fila, char *placa){
    TipoApontador aux;
    int achou = 0;

    aux = fila->Frente->Prox;

    if(FilaVazia(*fila)){
        return 0;
    }

    while(aux != NULL &&  achou == 0){
        if(strcmp(aux->Item.placa, placa) == 0){
            achou = 1;
        }
        aux = aux->Prox;
    }

    return achou;
}

void exibirItem(TipoItem item){
    printf("\nPlaca==%s | Deslocamento==%d | Prioridade==%d", item.placa, item.deslocamento, item.prioridade);
}

void exibirRelarotio(TipoFila filaEstacionamento, TipoFila filaEspera){
    printf("\n\t\t-- Relatorio --\n");
    printf("\n\t  -- Estacionamento --");
    Exibe(filaEstacionamento);
    printf("\n\n\t  -- Fila de Espera --");
    Exibe(filaEspera);
}

void PopularFilaEstacionamento(TipoFila *filaEstacionamento){
    TipoItem item;
    char placa[10];
    int i;

    //gerei 5 placas aleatórias para popular a fila de estacionamento
    for(i = 0; i < 5; i++){
        sprintf(placa, "ABC%d", i);
        strcpy(item.placa, placa);

        item.deslocamento = 0;
        item.prioridade = 0;
        Enfileira(item, filaEstacionamento);
    }
}

void PopularFilaEspera(TipoFila *filaEspera){
    TipoItem item;
    char placa[10];
    int i;

    //gerei 5 placas aleatórias para popular a fila de espera
    for(i = 1; i < 6; i++){
        sprintf(placa, "ABC%d", i*10);
        strcpy(item.placa, placa);
        item.deslocamento = 0;
        item.prioridade = 0;
        Enfileira(item, filaEspera);
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

    //Populando a fila de estacionamento com 5 carros
    PopularFilaEstacionamento(&filaEstacionamento);

    //Populando a fila de espera com 5 carros
    PopularFilaEspera(&filaEspera);

	//Menu
    do{
        printf("------------------\n");
        printf("\t-- Escolha uma opcao --\n\n");
        printf("1. Estacionar um Carro\n");
        printf("2. Retirar um Carro\n");
        printf("3. Exibir Relatorio\n");
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
                fgets(item.placa, 10, stdin);
                item.placa[strlen(item.placa) - 1] = '\0';
                //verificar se a placa é 7 digitos sendo 3 letras e 4 números
                while(strlen(item.placa) != 7){
                    printf("\nR: PLACA INVALIDA!\n\n");
                    printf(". Informe a placa do carro: ");
                    fgets(item.placa, 10, stdin);
                    item.placa[strlen(item.placa) - 1] = '\0';
                }

	            
	            do{
	            	verificador = 0;
	            	
	            	printf(". Voce possui prioridade para estacionar? ");
	            	scanf("%3s", resposta);
	            	
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
				
				

                break;
            case 2:
	            // Saida de um carro
                // Quando um carro partir, a mensagem devera incluir o numero de vezes que 
                // o carro foi deslocado dentro do estacionamento, incluindo a propria partida, 
                // mas não a chegada
                char placa[10];

                printf("-- Saida de veiculo --\n");
                printf("\nInforme a placa do veiculo: "); 
                scanf("%9s", placa);

                do{
                    verificador = 0;
                    // Verifica se o carro esta estacionado na Tv. Sr. Bom Jesus dos Passos
                    if(FilaVazia(filaEstacionamento) || !CarroEstacionado(&filaEstacionamento, placa)){
                        printf("\nO Seu carro nao esta estacionado na Tv. Sr. Bom Jesus dos Passos\n");
                        system("pause");
                        break;
                    }

                    // Retira o carro da fila de estacionamento
                    Desenfileira(&filaEstacionamento, &item);
                    item.deslocamento++;
                    
                    // Se carro retirado da fila de estacionamento eh o carro que vai sair
                    // Então exibe as informacoes do carro e finaliza o loop
                    // Caso contrário, o carro eh enfileirado na fila auxiliar
                    if(strcmp(item.placa, placa) == 0){
                        printf("\t\t-- Carro --");
                        exibirItem(item);
                        printf("\n\t\t-- Retirado --\n");
                        system("pause");
                        verificador = 1;

                    }else{
                        Enfileira(item, &filaAuxiliar);
                    }


                }while(verificador == 0);


                // Reorganiza a fila de estacionamento
                while(!FilaVazia(filaAuxiliar)){
                    Desenfileira(&filaAuxiliar, &item);
                    Enfileira(item, &filaEstacionamento);
                }

                // Verifica se existe carro na fila de espera e tem vaga na fila de estacionamento
                // Se sim, o carro da fila de espera eh estacionado na fila de estacionamento
                if (!FilaVazia(filaEspera) && CalculaQtdItensFila(filaEstacionamento) < 5){
                    retiraCarroFilaEspera(&filaEspera, &item);
                    Enfileira(item, &filaEstacionamento);
                    printf("\n\t\t-- O Carro --");
                    exibirItem(item);
                    printf("\n\t\t-- Foi Estacionado --\n");
                    system("pause");
                }

                exibirRelarotio(filaEstacionamento, filaEspera);
                
                
                break;
            case 3:
                system("cls");
                exibirRelarotio(filaEstacionamento, filaEspera);
                printf("\n");
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
                
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
        
        printf("\n");
        system("pause");
        system("cls");

    }while(opcao != 0);

    return 0;

}
