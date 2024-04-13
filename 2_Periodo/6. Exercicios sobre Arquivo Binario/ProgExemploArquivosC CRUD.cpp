#include <stdio.h>
#include <stdlib.h>
#include <String.h>
/* Declaração de arquivo. "FILE *" faz a função de "arquivo de " */
FILE *Id_Arquivo;

/* Registro a ser manipulado no Arquivo */
struct Registro_Carro
{
     char Placa[10];
     char Modelo[50];
     int Ano;
     int Flag;
     char Cor[30];
};

/* função para gravar os dados de um registro (recebido como parâmetro) no arquivo */
void Grava_Dados(struct Registro_Carro Carro)
{
     if((Id_Arquivo = fopen("carros1.dat","a+b")) == NULL)
     {
         printf("Problemas na abertura do arquivo de carros para gravar!\n");
     } 
     
     //Inlusão lógica
     Carro.Flag=1;
     /* fwrite grava o registro no arquivo. É necessário indicar o tamanho 
     do registro via "sizeof" */
     fwrite(&Carro, sizeof(struct Registro_Carro),1, Id_Arquivo);      
     // Grava dados que estão no buffer
     fclose(Id_Arquivo);
}

/* função para ler e exibir os registros do arquivo */
void Le_Dados()
{
    if((Id_Arquivo = fopen("carros1.dat","r")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    // comando para voltar ao início do arquivo
    rewind(Id_Arquivo);
    
    /* Registro para receber os valores do arquivo */
    Registro_Carro Carro;
   
    /* Percorre arquivo até encontrar o fim */
    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conteúdo do registro lido do arquivo
         no Registro Carro. É necessário indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1)
        {
            /* Imprimi o registro recuperado do arquivo */
            printf("%d\n",Carro.Ano);
            printf("%s\n",Carro.Placa);
            printf("%s\n",Carro.Modelo);
            printf("%s\n",Carro.Cor);
            printf("\n\n");
        }
    }
}

/* função para alterar os dados de um registro com a placa passada por parâmetro */
void altera(Registro_Carro CarroAlterado)
{
    if((Id_Arquivo = fopen("carros1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    // comando para voltar ao início do arquivo
    rewind(Id_Arquivo);
    
    /* Registro para receber os valores do arquivo */
    Registro_Carro Carro;

    printf("*** Alteracao ***\n\n");
    // Contador utilizado para acessar o registro que será alterado
    int cont=-1;
    
    /* Percorre arquivo até encontrar o fim */
    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conteúdo do registro lido do arquivo
         no Registro Carro. É necessário indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        
        // Contador utilizado para acessar o registro que será alterado
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if((!feof(Id_Arquivo))&&(strcmp(Carro.Placa,CarroAlterado.Placa)==0)&&Carro.Flag==1)
        {
            // Posiciona-se no registro a ser alterado
            fseek(Id_Arquivo, sizeof(Registro_Carro)*cont, SEEK_SET);     
            // Grava o novo registro "CarroAlterado"
            CarroAlterado.Flag=1;
            fwrite(&CarroAlterado, sizeof(Registro_Carro),1, Id_Arquivo);
            // Posiciona-se no final do arquivo
            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
   fclose(Id_Arquivo);
}

/* função para excluir logicamente um registro com a placa passada por parâmetro */
void exclui(char Placa[7])
{
    if((Id_Arquivo = fopen("carros1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    // comando para voltar ao início do arquivo
    rewind(Id_Arquivo);
    
    /* Registro para receber os valores do arquivo */
    Registro_Carro Carro;

    printf("*** Exclusao ***\n\n");
    // Contador utilizado para acessar o registro que será alterado
    int cont=-1;
    
    /* Percorre arquivo até encontrar o fim */
    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conteúdo do registro lido do arquivo
         no Registro Carro. É necessário indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        
        // Contador utilizado para acessar o registro que será alterado
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if((!feof(Id_Arquivo))&&(strcmp(Carro.Placa,Placa)==0)&& Carro.Flag==1)
        {
            //Faz a exclusão lógica
            Carro.Flag=0;
            
            // Posiciona-se no registro a ser alterado
            fseek(Id_Arquivo, sizeof(Registro_Carro)*cont, SEEK_SET);     
            // Grava o novo registro "CarroAlterado"
            fwrite(&Carro, sizeof(Registro_Carro),1, Id_Arquivo);
            // Posiciona-se no final do arquivo
            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
   fclose(Id_Arquivo);
}




int main()
{
  
    struct Registro_Carro Carro;
	
	int op=1;
	
	while (op!=0){
          system("cls");
          printf("Digite a sua escolha:\n");      
          printf("1- Cadastrar carro:\n");      
          printf("2- Exibir Carros cadastrados:\n");     
          printf("3- Alterar Carro:\n");       
          printf("4- Excluir Carro:\n"); 
          scanf("%d",&op);
          switch (op){
                 
          case 1: 
          {     
               printf("*** Cadastro de Carro ***\n");
               fflush(stdin);
               printf("Placa: "); scanf("%s",&Carro.Placa); 
               fflush(stdin);
               printf("\nModelo: "); scanf("%s",&Carro.Modelo);  
               fflush(stdin);
               printf("\nCor: "); scanf("%s",&Carro.Cor);        
               fflush(stdin);
               printf("\nAno: "); scanf("%d",&Carro.Ano);
               Grava_Dados(Carro);
               system("pause");
          break;  
          }
          case 2: 
          {     
               printf("*** Carros Cadastrados ***\n");
               Le_Dados();
               system("pause");
          break;   
          }
          case 3: 
          {
               printf("*** Alteracao de Carro ***\n");
               printf("\nPlaca do carro a ser alterado: "); scanf("%s",&Carro.Placa); 
               printf("\nModelo: "); scanf("%s",&Carro.Modelo);  
               printf("\nCor: "); scanf("%s",&Carro.Cor);        
               printf("\nAno: "); scanf("%d",&Carro.Ano);
               altera(Carro);
               system("pause");
          break;
          }
          case 4: 
          {
               char placa[7];
               printf("*** Excluir Carro ***\n");
               printf("\nDigite a placa do carro a ser excluido:");
               scanf("%s", placa);
               exclui(placa);
               system("pause");
          break;
          } 
    }      
    }// Fim do While
 	printf("***     FIM DO PROGRAMA     ***\n");
	system("pause");
}
