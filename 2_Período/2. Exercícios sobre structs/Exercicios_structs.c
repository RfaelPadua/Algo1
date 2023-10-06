#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Imovel{
	int cod;
	char tipo[50];
	char endereco[100];
	float valor;
	char situacao[50];
};
float valor_total;
float valor_total_aluguel;
float maior_valor;
main(){
	struct Imovel imobiliaria[10];
	
	int tam=0, op=1, i;
	
	while(op!=0){
		system("cls"); // Limpa a tela
		printf("\nMENU\n0- Sair\n1- Cadastrar imovel\n2- Exibir imoveis cadastrados\n");
		printf("3- Consulta com o campo tipo\n4- Consulta com o campo situacao\n");
		printf("5- Exibir o valor total da soma de imoveis em situacao de \"venda\"\n");
		printf("6- Exibir o valor total da soma de imoveis em situacao de \"aluguel\"\n");
		printf("7- Exibir o valor do imóvel mais caro disponível para \"venda\"\n");
		scanf("%d", &op);
		switch(op){
			case 1: // Faz a leitura de uma struct Imovel armazenando-a no vetor na posição indicada pela variável tam
				system("cls");
				fflush(stdin);
				printf("Cod: "); scanf("%d",&imobiliaria[tam].cod);fflush(stdin);
			    printf("Tipo: "); gets(imobiliaria[tam].tipo);fflush(stdin);
			    printf("Endereco: "); gets(imobiliaria[tam].endereco);
			    printf("Valor: "); scanf("%f",&imobiliaria[tam].valor);fflush(stdin);
			    printf("Situacao: "); gets(imobiliaria[tam].situacao);
			    tam++;//Incrementa a variável
			break;
			case 2://Exibe as structs armazenadas no vetor
				system("cls");
				printf("\n*** Imoveis Cadastrados ***\n");
				for(i=0;i<tam;i++){
					printf("\nCod: %d", imobiliaria[i].cod);
					printf("\nTipo: %s", imobiliaria[i].tipo);
			    	printf("\nEndereco: %s", imobiliaria[i].endereco);
			    	printf("\nSalario: R$%.2f", imobiliaria[i].valor);
			    	printf("\nSituacao: %s\n", imobiliaria[i].situacao);
				}
				system("pause");
			break;
			case 3:
				system("cls");
				char consulta_tipo[50];
				printf("Tipo de imovel a ser consultado: ");fflush(stdin);
				gets(consulta_tipo);
				for(i=0;i<tam;i++){
					if(!strcmp(consulta_tipo,imobiliaria[i].tipo)){
						printf("\nCod: %d", imobiliaria[i].cod);
						printf("\nTipo: %s", imobiliaria[i].tipo);
			      		printf("\nEndereco: %s", imobiliaria[i].endereco);
			      		printf("\nSalario: R$%.2f", imobiliaria[i].valor);
			      		printf("\nSituacao: %s\n", imobiliaria[i].situacao);
					}
				}
				system("pause");
			break;
			case 4:
				system("cls");
				char consulta_situacao[50];
				printf("Situacao de imovel a ser consultado: ");fflush(stdin);
				gets(consulta_situacao);
				for(i=0;i<tam;i++){
					if(!strcmp(consulta_situacao,imobiliaria[i].situacao)){
						printf("\nCod: %d", imobiliaria[i].cod);
						printf("\nTipo: %s", imobiliaria[i].tipo);
			      		printf("\nEndereco: %s", imobiliaria[i].endereco);
			      		printf("\nSalario: R$%.2f", imobiliaria[i].valor);
			      		printf("\nSituacao: %s\n", imobiliaria[i].situacao);
					}
				}
				system("pause");
			break;
			case 5:
				system("cls");
				valor_total = 0;
				for(i=0;i<tam;i++){
					if(!strcmp("venda",imobiliaria[i].situacao)){
						
			      		valor_total += imobiliaria[i].valor;
					}
				}
				printf("O valor total da soma de imoveis em situacao de \"venda\" eh %.2f\n", valor_total);
				system("pause");
			break;
			case 6:
				system("cls");
				valor_total_aluguel = 0;
				for(i=0;i<tam;i++){
					if(!strcmp("aluguel",imobiliaria[i].situacao)){
						
			      		valor_total_aluguel += imobiliaria[i].valor;
					}
				}
				printf("O valor total da soma de imoveis em situacao de \"aluguel\" eh %.2f\n", valor_total_aluguel);
				system("pause");
			break;
			case 7:
				system("cls");
				maior_valor = 0;
				int aux;
				for(i=0;i<tam;i++){
					if(!strcmp("venda",imobiliaria[i].situacao)){
						if(maior_valor<imobiliaria[i].valor)
			      		maior_valor = imobiliaria[i].valor;
			      		aux = i;
					}
				}
				printf("O valor do imóvel mais caro disponivel para \"venda\" eh %.2f\n", maior_valor);
				system("pause");
			break;
				
				
				
				
		}//Fim do switch
	}//Fim do while
}// Fim do programa
