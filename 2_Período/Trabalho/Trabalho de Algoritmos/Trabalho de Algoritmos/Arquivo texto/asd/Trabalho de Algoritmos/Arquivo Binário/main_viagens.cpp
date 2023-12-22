/*	- TRABALHO DE ALGORITMOS II - Parte do arquivo Bin�rio
		. Programa de gerenciamento de viagens dos ve�culos do c�mpus
	- ALUNOS:
		. Gabriel Silva Xavier;
		. Rafael de P�dua Oliveira.
	- REFER�NCIAS:
		. https://www.ibm.com/docs/pt-br/i/7.5?topic=functions-fopen-open-files
*/

#include<stdio.h>
#include<stdlib.h>

//Declara��o das estruturas que referenciar�o os arquivos:
FILE *Id_Veiculos;
FILE *Id_Professores;
FILE *Id_Viagens;


//Vari�veis respons�veis por gerenciar os c�digos das estruturas Ve�culo e Professor:
int cod_veiculo;
int cod_professor;


//Estruturas:
struct Veiculo{
	int cod;
	char marca_modelo[20];
	char placa[8];
	char cor[20];
	
	int flag;
};

struct Professor{
	int cod;
	char nome[50];
	char cpf[15];
	
	int flag;
};

struct Viagem{
	int codVeiculo; //C�digo de identifica��o do ve�culo
	int codProfessor; //C�digo de identifica��o do professor
	char cidadeDestino[50];
	char dataSaida[11];
	char dataRetorno[11];
	
	int flag;
};


//Fun��o que atualiza as vari�veis respons�veis por atribuir os c�digos das estruturas cada vez que o programa � executado
void atualizaCodigos(struct Veiculo veiculo, struct Professor professor){
	int aux = 0; //Vari�vel utilizada para verificar se o arquivo est� vazio ou n�o
	
	if((Id_Veiculos = fopen("veiculos.dat", "r")) == NULL){
		fclose(Id_Veiculos); //Se h� algum erro com o arquivo, o mesmo � fechado
		Id_Veiculos = fopen("veiculos.dat", "w+b"); //Criando o arquivo. "w+b" cria o arquivo bin�rio para leitura e grava��o
	}
	if((Id_Professores = fopen("professores.dat", "r")) == NULL){
		fclose(Id_Professores); //Se h� algum erro com o arquivo, o mesmo � fechado
		Id_Professores = fopen("professores.dat", "w+b"); // Criando o arquivo. "w+b" cria o arquivo bin�rio para leitura e grava��o
	}
	
	rewind(Id_Veiculos);
	rewind(Id_Professores);
	
	//Atualizando o c�digo do ve�culo
	while(!feof(Id_Veiculos)){
		aux ++;
		fread(&veiculo, sizeof(struct Veiculo), 1, Id_Veiculos);
		cod_veiculo = veiculo.cod; //Atualizando a vari�vel do c�digo do ve�culo com o �ltimo c�digo cadastrado
	}
	//Pelos testes que fizemos, se 'aux' � incrementada uma �nica vez, � devido ao arquivo estar em branco. Assim a vari�vel � atualizada novamente com 0
	if(aux == 1){
		cod_veiculo = 0;
	}
	
	//Atualizando o c�digo do professor
	aux = 0;
	while(!feof(Id_Professores)){
		aux ++;
		fread(&professor, sizeof(struct Professor), 1, Id_Professores);
		cod_professor = professor.cod; //Atualizando a vari�vel do c�digo do ve�culo com o �ltimo c�digo cadastrado
	}
	//Pelos testes que fizemos, se 'aux' � incrementada uma �nica vez, � devido ao arquivo estar em branco. Assim a vari�vel � atualizada novamente com 0
	if(aux == 1){
		cod_professor = 0;
	}
	
	fclose(Id_Veiculos);
	fclose(Id_Professores);
}


//-- FUN��ES DE MANIPULA��O DOS VE�CULOS:

void cadastraVeiculo(struct Veiculo veiculo){
	if((Id_Veiculos = fopen("veiculos.dat", "a+b")) == NULL){
		printf("Problemas na abertura do arquivo Veiculos para cadastrar!");
	}
	
	veiculo.flag = 1;
	
	//Gravando o registro feito no arquivo:
	fwrite(&veiculo, sizeof(struct Veiculo), 1, Id_Veiculos);
	
	fclose(Id_Veiculos);
}
void consultaVeiculos(struct Veiculo veiculo){
	int aux = 0;
	
	if((Id_Veiculos = fopen("veiculos.dat", "r")) == NULL){
		printf("Problemas na abertura do arquivo Veiculos para consultar!\n");
	}
	
	rewind(Id_Veiculos);
	
	while(!feof(Id_Veiculos)){
		fread(&veiculo, sizeof(struct Veiculo), 1, Id_Veiculos);
		
		if(ferror(Id_Veiculos)){
			printf("\nProblemas na leitura do arquivo veiculos!");
		} else if(!feof(Id_Veiculos) && veiculo.flag == 1){
			aux = 1;
			
			printf("- %s", veiculo.marca_modelo);
			printf(". Codigo: %d", veiculo.cod);
			printf("\n. Placa: %s", veiculo.placa);
			printf("\n. Cor: %s", veiculo.cor);
			printf("\n\n");
		}
	}
	
	if(aux == 0){
		printf("\nNao ha nenhum veiculo cadastrado!\n\n");
	}
	
	fclose(Id_Veiculos);
}
void alteraVeiculo(struct Veiculo veiculo){
	struct Veiculo veiculo_aux;
	int cont = -1, aux = 0; //Contador utilizado para acessar o registro que ser� acessado
	
	//Recebendo o c�digo do ve�culo que o usu�rio deseja alterar:
	printf("- Informe o codigo do veiculo: ");
	scanf("%d", &veiculo_aux.cod); fflush(stdin);
	
	if((Id_Veiculos = fopen("veiculos.dat", "r+b")) == NULL){
		printf("Problemas na abertura do arquivo Veiculos para edicao!\n");
	}
	
	rewind(Id_Veiculos);
	
	while(!feof(Id_Veiculos)){
		fread(&veiculo, sizeof(struct Veiculo), 1, Id_Veiculos);
		
		cont ++;
		if(ferror(Id_Veiculos)){
			printf("\nProblemas na leitura do arquivo de veiculos!\n");
		} else if((!feof(Id_Veiculos)) && (veiculo.cod == veiculo_aux.cod) && (veiculo.flag == 1)){
			aux = 1;
			
			printf("\n. Informe a marca e o modelo: "); fgets(veiculo_aux.marca_modelo, 20, stdin); fflush(stdin);
			printf("\n. Informe a placa: "); fgets(veiculo_aux.placa, 8, stdin); fflush(stdin);
			printf("\n. Informe a cor: "); fgets(veiculo_aux.cor, 20, stdin);
			
			fseek(Id_Veiculos, sizeof(struct Veiculo)*cont, SEEK_SET);
			veiculo_aux.flag = 1;
			fwrite(&veiculo_aux, sizeof(struct Veiculo), 1, Id_Veiculos);
			fseek(Id_Veiculos, 0, SEEK_END);
		}
	}
	
	if(aux == 0){
		printf("\n\n- Nao ha nenhum veiculo cadastrado com esse codigo!\n");
	}
	
	fclose(Id_Veiculos);
}
void excluiVeiculo(struct Veiculo veiculo, int cod){
	int cont = -1, aux = 0; //Contador utilizado para acessar o registro que ser� acessado
	
	if((Id_Veiculos = fopen("veiculos.dat", "r+b")) == NULL){
		printf("Problemas na abertura do arquivo Veiculos para edicao!\n");
	}
	
	rewind(Id_Veiculos);
	
	while(!feof(Id_Veiculos)){
		fread(&veiculo, sizeof(struct Veiculo), 1, Id_Veiculos);
		
		cont ++;
		if(ferror(Id_Veiculos)){
			printf("\nProblemas na leitura do arquivo de veiculos!\n");
		} else if((!feof(Id_Veiculos)) && (veiculo.cod == cod) && (veiculo.flag == 1)){
			aux = 1;
			
			veiculo.flag = 0;
			
			fseek(Id_Veiculos, sizeof(struct Veiculo)*cont, SEEK_SET);
			fwrite(&veiculo, sizeof(struct Veiculo), 1, Id_Veiculos);
			fseek(Id_Veiculos, 0, SEEK_END);
			
			printf("\n- Veiculo excluido com sucesso!");
		}
	}
	
	if(aux == 0){
		printf("\n\n- Nao ha nenhum veiculo cadastrado com esse codigo!\n\n");
	}
	
	fclose(Id_Veiculos);
}


//-- FUN��ES DE MANIPULA��O DE PROFESSORES:


void cadastraProfessor(struct Professor professor){
	if((Id_Professores = fopen("professores.dat", "a+b")) == NULL){
		printf("Problemas na abertura do arquivo Professores para cadastrar!");
	}
	
	professor.flag = 1;
	
	//Gravando o registro feito no arquivo:
	fwrite(&professor, sizeof(struct Professor), 1, Id_Professores);
	
	fclose(Id_Professores);
}
void consultaProfessores(struct Professor professor){
	int aux = 0;
	
	if((Id_Professores = fopen("professores.dat", "r")) == NULL){
		printf("Problemas na abertura do arquivo Professores para consultar!\n");
	}
	
	rewind(Id_Professores);
	
	while(!feof(Id_Professores)){
		fread(&professor, sizeof(struct Professor), 1, Id_Professores);
		
		if(ferror(Id_Professores)){
			printf("\nProblemas na leitura do arquivo professores!");
		} else if(!feof(Id_Professores) && professor.flag == 1){
			aux = 1;
			
			printf("- %s", professor.nome);
			printf(". Codigo: %d", professor.cod);
			printf("\n. CPF: %s", professor.cpf);
			printf("\n\n\n");
		}
	}
	
	if(aux == 0){
		printf("\nNao ha nenhum professor cadastrado!\n\n\n");
	}
	
	fclose(Id_Professores);
}
void alteraProfessor(struct Professor professor){
	struct Professor professor_aux;
	int cont = -1, aux = 0; //Contador utilizado para acessar o registro que ser� acessado
	
	//Recebendo o c�digo do professor que o usu�rio deseja alterar:
	printf("- Informe o codigo do professor: ");
	scanf("%d", &professor_aux.cod); fflush(stdin);
	
	if((Id_Professores = fopen("professores.dat", "r+b")) == NULL){
		printf("Problemas na abertura do arquivo Professores para edicao!\n");
	}
	
	rewind(Id_Professores);
	
	while(!feof(Id_Professores)){
		fread(&professor, sizeof(struct Professor), 1, Id_Professores);
		
		cont ++;
		if(ferror(Id_Professores)){
			printf("\nProblemas na leitura do arquivo de professores!\n");
		} else if((!feof(Id_Professores)) && (professor.cod == professor_aux.cod) && (professor.flag == 1)){
			aux = 1;
			
			printf("\n. Informe o nome: "); fgets(professor_aux.nome, 50, stdin); fflush(stdin);
			printf("\n. Informe o CPF: "); fgets(professor_aux.cpf, 15, stdin); fflush(stdin);
			
			fseek(Id_Professores, sizeof(struct Professor)*cont, SEEK_SET);
			professor_aux.flag = 1;
			fwrite(&professor_aux, sizeof(struct Professor), 1, Id_Professores);
			fseek(Id_Professores, 0, SEEK_END);
		}
	}
	
	if(aux == 0){
		printf("\n\n- Nao ha nenhum professor cadastrado com esse codigo!\n");
	}
	
	fclose(Id_Professores);
}
void excluiProfessor(struct Professor professor, int cod){
	int cont = -1, aux = 0; //Contador utilizado para acessar o registro que ser� acessado
	
	if((Id_Professores = fopen("professores.dat", "r+b")) == NULL){
		printf("Problemas na abertura do arquivo Professores para edicao!\n");
	}
	
	rewind(Id_Professores);
	
	while(!feof(Id_Professores)){
		fread(&professor, sizeof(struct Professor), 1, Id_Professores);
		
		cont ++;
		if(ferror(Id_Professores)){
			printf("\nProblemas na leitura do arquivo de professores!\n");
		} else if((!feof(Id_Professores)) && (professor.cod == cod) && (professor.flag == 1)){
			aux = 1;
			
			professor.flag = 0;
			
			fseek(Id_Professores, sizeof(struct Professor)*cont, SEEK_SET);
			fwrite(&professor, sizeof(struct Professor), 1, Id_Professores);
			fseek(Id_Professores, 0, SEEK_END);
			
			printf("\n- Professor excluido com sucesso!");
		}
	}
	
	if(aux == 0){
		printf("\n\n- Nao ha nenhum professor cadastrado com esse codigo!\n");
	}
	
	fclose(Id_Professores);
}


//-- FUN��ES DE MANIPULA��O DE VIAGENS:


void cadastraViagem(struct Viagem viagem){
	struct Veiculo veiculo;
	struct Professor professor;
	int verificador1 = 0, verificador2 = 0;
	
	if((Id_Viagens = fopen("viagens.dat", "a+b")) == NULL){
		printf("Problemas na abertura do arquivo Viagens para cadastrar!\n");
	}
	if((Id_Veiculos = fopen("veiculos.dat", "r")) == NULL){
		printf("Problemas na abertura do arquivo de Veiculos para leitura!\n");
	}
	if((Id_Professores = fopen("professores.dat", "r")) == NULL){
		printf("Problemas na abertura do arquivo de Professores para leitura!\n");
	}
	
	//Verificando se o veiculo referente ao codigo informado existe:
	rewind(Id_Veiculos);
	
	while(!feof(Id_Veiculos)){
		fread(&veiculo, sizeof(struct Veiculo), 1, Id_Veiculos);
		
		if(ferror(Id_Veiculos)){
			printf("\nProblemas na leitura do arquivo de veiculos!\n");
		} else if((!feof(Id_Veiculos)) && (veiculo.cod == viagem.codVeiculo) && (veiculo.flag == 1)){
			verificador1 = 1; //Significa que o professor esta cadastrado
		}
	}
	
	//Verificando se o professor referente ao codigo informado existe:
	rewind(Id_Professores);
	
	while(!feof(Id_Professores)){
		fread(&professor, sizeof(struct Professor), 1, Id_Professores);
		
		if(ferror(Id_Professores)){
			printf("\nProblemas na leitura do arquivo de professores!\n");
		} else if((!feof(Id_Professores)) && (professor.cod == viagem.codProfessor) && (professor.flag == 1)){
			verificador2 = 1; //Significa que o professor esta cadastrado
		}
	}
	
	if(verificador1 == 0 || verificador2 == 0){ //Verifica��o para que a tela possa ser limpa no momento certo
		system("cls");
	}
	if(verificador1 == 0){
		printf("\n\nO VEICULO NAO ESTA CADASTRADO NO SISTEMA!");
	}
	if(verificador2 == 0){
		printf("\n\nO PROFESSOR NAO ESTA CADASTRADO NO SISTEMA!");
	}
	if(verificador1 == 1 && verificador2 == 1){
		viagem.flag = 1;
	
		//Gravando o registro feito no arquivo:
		fwrite(&viagem, sizeof(struct Viagem), 1, Id_Viagens);
	}
	
	fclose(Id_Viagens);
	fclose(Id_Veiculos);
	fclose(Id_Professores);
}
void consultaViagensProfessor(struct Viagem viagem, int codigo_prof){ //Fun��o que mostra todas as viagens vinculadas a um professor, a partir do codigo deste
	int aux = 0;
	
	if((Id_Viagens = fopen("viagens.dat", "r")) == NULL){
		printf("Problemas na abertura do arquivo Viagens para consultar!\n");
	}
	
	rewind(Id_Viagens);
	
	while(!feof(Id_Viagens)){
		fread(&viagem, sizeof(struct Viagem), 1, Id_Viagens);
		
		if(ferror(Id_Viagens)){
			printf("\nProblemas na leitura do arquivo viagens!");
		} else if(!feof(Id_Viagens) && (viagem.codProfessor == codigo_prof) && (viagem.flag == 1)){
			aux = 1;
			
			printf(". Codigo veiculo: %d", viagem.codVeiculo);
			printf("\n. Cidade de destino: %s", viagem.cidadeDestino);
			printf(". Data saida: %s", viagem.dataSaida);
			printf("\n. Data retorno: %s", viagem.dataRetorno);
			printf("\n\n");
		}
	}
	
	if(aux == 0){
		printf("\nNao ha nenhuma viagem cadastrada desse professor!\n\n");
	}
	
	fclose(Id_Viagens);
}



int main(){
	//Vari�veis de op��o dos menus
	int opcao1, opcao2;
	
	//Estruturas auxiliares
	struct Veiculo veiculo;
	struct Professor professor;
	struct Viagem viagem;
	
	//Atualizando a vari�vel que gerencia o c�digo de ve�culo e de professor com o �ltimo c�digo correspondente que foi cadastrado anteriormente
	atualizaCodigos(veiculo, professor);
	
	do{
		//Menu principal
		printf("\t\t\t-- GERENCIAMENTO DE VIAGENS DO CAMPUS --");
		
		printf("\n\n- Selecione uma opcao:");
		printf("\n. 1 Gerenciamento de veiculos;");
		printf("\n. 2 Gerenciamento de professores");
		printf("\n. 3 Gerenciamento de viagens;");
		printf("\n. 0 Sair.\nR: ");
		scanf("%d", &opcao1);
		
		switch(opcao1){
			case 1:{ //Gerenciamento dos ve�culos
				system("cls");
				//Menu da manipula��o dos ve�culo
				printf("\t\tVeiculos");
				
				printf("\n\n- Selecione uma opcao:");
				printf("\n. 1 Cadastrar novo veiculo;");
				printf("\n. 2 Consultar veiculos cadastrados;");
				printf("\n. 3 Editar dados de algum veiculo;");
				printf("\n. 4 Excluir veiculo;");
				printf("\n. 0 Voltar.\nR: ");
				scanf("%d", &opcao2);
				
				system("cls");
				
				switch(opcao2){
					case 1:{
						printf("\t-- Cadastro de veiculo --");
						
						printf("\n\nInforme os dados:");
						veiculo.cod = ++cod_veiculo;
						printf("\n. Cod: %d", veiculo.cod); fflush(stdin);
						printf("\n. Marca e modelo: "); fgets(veiculo.marca_modelo, 20, stdin); fflush(stdin);
						printf(". Placa: "); fgets(veiculo.placa, 8, stdin); fflush(stdin);
						printf(". Cor: "); fgets(veiculo.cor, 20, stdin);
						
						cadastraVeiculo(veiculo);
						printf("\n\n");
						break;
					}
					case 2:{
						printf("\t-- Veiculos cadastrados --\n\n");
						
						consultaVeiculos(veiculo);
						break;
					}
					case 3:{
						printf("\t-- Editar dados --\n\n");
						
						alteraVeiculo(veiculo);
						printf("\n\n");
						break;
					}
					case 4:{
						printf("\t-- Excluir veiculo --\n\n");
						
						int cod;
						
						printf("Informe o codigo do veiculo a ser excluido: ");
						scanf("%d", &cod);
						
						excluiVeiculo(veiculo, cod);
						printf("\n\n");
						break;
					}
				}
				
				break;
			}
			case 2:{ //Gerenciamento dos professores
				system("cls");
				//Menu da manipula��o dos professores
				printf("\t\tProfessores");
				
				printf("\n\n- Selecione uma opcao:");
				printf("\n. 1 Cadastrar novo professor;");
				printf("\n. 2 Consultar professores cadastrados;");
				printf("\n. 3 Editar dados de algum professor;");
				printf("\n. 4 Excluir professor;");
				printf("\n. 0 Voltar.\nR: ");
				scanf("%d", &opcao2);
				
				system("cls");
				
				switch(opcao2){
					case 1:{
						printf("\t-- Cadastro de Professor --");
						
						printf("\n\nInforme os dados:");
						professor.cod = ++cod_professor;
						printf("\n. Codigo: %d", professor.cod); fflush(stdin);
						printf("\n. Nome: "); fgets(professor.nome, 50, stdin); fflush(stdin);
						printf(". CPF: "); fgets(professor.cpf, 15, stdin);
						
						cadastraProfessor(professor);
						printf("\n\n");
						break;
					}
					case 2:{
						printf("\t-- Professores cadastrados --\n\n");
						
						consultaProfessores(professor);
						break;
					}
					case 3:{
						printf("\t-- Editar dados --\n\n");
						
						alteraProfessor(professor);
						printf("\n\n");
						break;
					}
					case 4:{
						printf("\t-- Excluir professor --\n\n");
						
						int cod;
						
						printf("Informe o codigo do professor a ser excluido: ");
						scanf("%d", &cod);
						
						excluiProfessor(professor, cod);
						printf("\n\n");
						break;
					}
				}
				
				break;
			}
			case 3:{ //Gerenciamento das Viagens
				system("cls");
				//Menu da manipula��o das viagens
				printf("\t\tVeiculos");
				
				printf("\n\n- Selecione uma opcao:");
				printf("\n. 1 Cadastrar nova viagem;");
				printf("\n. 2 Consultar viagens cadastradas;");
				printf("\n. 0 Voltar.\nR: ");
				scanf("%d", &opcao2);
				
				system("cls");
				
				switch(opcao2){
					case 1:{
						printf("\t-- Cadastro de viagem --");
						
						printf("\n\nInforme os dados:\n");
						printf("\n. Codigo do veiculo: "); scanf("%d", &viagem.codVeiculo); fflush(stdin);
						printf(". Codigo do professor: "); scanf("%d", &viagem.codProfessor); fflush(stdin);
						printf(". Informe a cidade de destino: "); fgets(viagem.cidadeDestino, 50, stdin); fflush(stdin);
						printf(". Data de saida: "); fgets(viagem.dataSaida, 11, stdin); fflush(stdin);
						printf(". Data de retorno: "); fgets(viagem.dataRetorno, 11, stdin);
						
						cadastraViagem(viagem);
						printf("\n\n");
						break;
					}
					case 2:{
						int codigo_prof;
						
						printf("\t-- Viagens cadastradas --\n\n");
						
						printf("Informe o codigo do professor responsavel pela viagem: ");
						scanf("%d", &codigo_prof);
						
						printf("\n");
						consultaViagensProfessor(viagem, codigo_prof);
						break;
					}
				}
				
				break;
			}
			default:{
				
				break;
			}
		}
		
		system("pause");
		system("cls");
	} while(opcao1 > 0);
	
	printf("\n\nFim do sistema...");
	
	return 0;
}
