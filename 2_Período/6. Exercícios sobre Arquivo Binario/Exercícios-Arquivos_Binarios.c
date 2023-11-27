#include <stdio.h>
#include <stdlib.h>
#include <String.h>
/* Declara��o de arquivo. "FILE *" faz a fun��o de "arquivo de " */
FILE *Id_Arquivo, *Id_Arquivo2, *Id_Arquivo3;

/* Registro a ser manipulado no Arquivo */
struct Registro_Carro
{
    char Placa[10];
    char Modelo[50];
    int Ano;
    int Flag;
    char Cor[30];
    float Valor;
};

/* fun��o para gravar os dados de um registro (recebido como par�metro) no arquivo */
void Grava_Dados(struct Registro_Carro Carro)
{
    if((Id_Arquivo = fopen("carros1.dat","a+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    } 
     
    //Inlus�o l�gica
    Carro.Flag=1;
    /* fwrite grava o registro no arquivo. � necess�rio indicar o tamanho 
    do registro via "sizeof" */
    fwrite(&Carro, sizeof(struct Registro_Carro),1, Id_Arquivo);      
    // Grava dados que est�o no buffer
    fclose(Id_Arquivo);
}

/* fun��o para ler e exibir os registros do arquivo */
void Le_Dados()
{
    if((Id_Arquivo = fopen("carros1.dat","r")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
        return 0;
    }  
    
    // comando para voltar ao in�cio do arquivo
    rewind(Id_Arquivo);
    
    /* Registro para receber os valores do arquivo */
    struct Registro_Carro Carro;
   
    /* Percorre arquivo at� encontrar o fim */
    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conte�do do registro lido do arquivo
         no Registro Carro. � necess�rio indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1)
        {
            /* Imprimi o registro recuperado do arquivo */
            printf("\nPlaca: %s\n", Carro.Placa);
            printf("Modelo: %s\n", Carro.Modelo);
            printf("Cor: %s\n", Carro.Cor);
            printf("Ano: %d\n", Carro.Ano);
            printf("Valor: %.2f\n", Carro.Valor);
        }
    }
}

/* fun��o para alterar os dados de um registro com a placa passada por par�metro */
void altera(struct Registro_Carro CarroAlterado)
{
    if((Id_Arquivo = fopen("carros1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    // comando para voltar ao in�cio do arquivo
    rewind(Id_Arquivo);
    
    /* Registro para receber os valores do arquivo */
    struct Registro_Carro Carro;

    printf("*** Alteracao ***\n\n");
    // Contador utilizado para acessar o registro que ser� alterado
    int cont=-1;
    
    /* Percorre arquivo at� encontrar o fim */
    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conte�do do registro lido do arquivo
         no Registro Carro. � necess�rio indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        
        // Contador utilizado para acessar o registro que ser� alterado
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if((!feof(Id_Arquivo))&&(strcmp(Carro.Placa,CarroAlterado.Placa)==0)&&Carro.Flag==1)
        {
            // Posiciona-se no registro a ser alterado
            fseek(Id_Arquivo, sizeof(struct Registro_Carro)*cont, SEEK_SET);     
            // Grava o novo registro "CarroAlterado"
            CarroAlterado.Flag=1;
            fwrite(&CarroAlterado, sizeof(struct Registro_Carro),1, Id_Arquivo);
            // Posiciona-se no final do arquivo
            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
   fclose(Id_Arquivo);
}

/* fun��o para excluir logicamente um registro com a placa passada por par�metro */
void exclui(char Placa[7])
{
    if((Id_Arquivo = fopen("carros1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    // comando para voltar ao in�cio do arquivo
    rewind(Id_Arquivo);
    
    /* Registro para receber os valores do arquivo */
    struct Registro_Carro Carro;

    printf("*** Exclusao ***\n\n");
    // Contador utilizado para acessar o registro que ser� alterado
    int cont=-1;
    
    /* Percorre arquivo at� encontrar o fim */
    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conte�do do registro lido do arquivo
         no Registro Carro. � necess�rio indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        
        // Contador utilizado para acessar o registro que ser� alterado
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if((!feof(Id_Arquivo))&&(strcmp(Carro.Placa,Placa)==0)&& Carro.Flag==1)
        {
            //Faz a exclus�o l�gica
            Carro.Flag=0;
            
            // Posiciona-se no registro a ser alterado
            fseek(Id_Arquivo, sizeof(struct Registro_Carro)*cont, SEEK_SET);     
            // Grava o novo registro "CarroAlterado"
            fwrite(&Carro, sizeof(struct Registro_Carro),1, Id_Arquivo);
            // Posiciona-se no final do arquivo
            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
   fclose(Id_Arquivo);
}

void Modelo(char Modelo[50]){
    if((Id_Arquivo = fopen("carros1.dat","r")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
        return 0;
    } 
    
    // comando para voltar ao in�cio do arquivo
    rewind(Id_Arquivo);
    
    /* Registro para receber os valores do arquivo */
    struct Registro_Carro Carro;
    int aux = 0;
   
    /* Percorre arquivo at� encontrar o fim */
    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conte�do do registro lido do arquivo
         no Registro Carro. � necess�rio indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1)
        {
            aux = 0;
            if(strcmp(Carro.Modelo,Modelo)==0){
                aux = 1;
            }
            if(aux == 1){
                printf("\nPlaca: %s\n", Carro.Placa);
                printf("Modelo: %s\n", Carro.Modelo);
                printf("Cor: %s\n", Carro.Cor);
                printf("Ano: %d\n", Carro.Ano);
                printf("Valor: %.2f\n", Carro.Valor);
            }
        }
    }
}

void maisBarato_Caro(float valor){
    if((Id_Arquivo = fopen("carros1.dat","a+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    } 
     
    struct Registro_Carro Carro;


    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conte�do do registro lido do arquivo
         no Registro Carro. � necess�rio indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
            break;
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1)
        {
            if(Carro.Valor < valor){
                if((Id_Arquivo2 = fopen("carroscaros.dat","a+b")) == NULL)
            {
                printf("Problemas na abertura do arquivo de carros para gravar!\n");
            } 
            
            /* fwrite grava o registro no arquivo. � necess�rio indicar o tamanho 
            do registro via "sizeof" */
            fwrite(&Carro, sizeof(struct Registro_Carro),1, Id_Arquivo);

            }else{
                if((Id_Arquivo3 = fopen("carrosbaratos.dat","a+b")) == NULL)
            {
                printf("Problemas na abertura do arquivo de carros para gravar!\n");
            }
            /* fwrite grava o registro no arquivo. � necess�rio indicar o tamanho
            do registro via "sizeof" */
            fwrite(&Carro, sizeof(struct Registro_Carro),1, Id_Arquivo);      
            }
        }
    }
    fwrite(&Carro, sizeof(struct Registro_Carro),1, Id_Arquivo);      
    // Grava dados que est�o no buffer
    fclose(Id_Arquivo);
}
void Antigo(){
    if((Id_Arquivo = fopen("carros1.dat","r")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
        return 0;
    } 
    
    // comando para voltar ao in�cio do arquivo
    rewind(Id_Arquivo);
    
    /* Registro para receber os valores do arquivo */
    struct Registro_Carro Carro;
    struct Registro_Carro CarroAntigo;
    CarroAntigo.Ano = 9999;
   
    /* Percorre arquivo at� encontrar o fim */
    while (!feof(Id_Arquivo))
    {
        /* fread faz a leitura de um registro e armazena o conte�do do registro lido do arquivo
         no Registro Carro. � necess�rio indicar o tamanho do registro via "sizeof" */
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1)
        {
            if(Carro.Ano < CarroAntigo.Ano){
                CarroAntigo = Carro;
            }
        }
    }
    printf("\nPlaca: %s\n", CarroAntigo.Placa);
    printf("Modelo: %s\n", CarroAntigo.Modelo);
    printf("Cor: %s\n", CarroAntigo.Cor);
    printf("Ano: %d\n", CarroAntigo.Ano);
    printf("Valor: %.2f\n", CarroAntigo.Valor);

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
        printf("5- Pesquisar Carro por modelo:\n");
        printf("6- Exibir Carro mais antigo:\n");
        printf("7- Gerar arquivos de carros mais baratos e mais caros:\n");
        printf("0- Sair:\n");
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
                fflush(stdin);
                printf("\nValor: "); scanf("%f",&Carro.Valor);
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
                printf("\nValor: "); scanf("%f",&Carro.Valor);
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
            }case 0: 
            { 
                op=0;  
                break; 
            }case 5: 
            { 
                char modelo[50];
                printf("*** Pesquisar Carro por modelo ***\n");
                printf("\nDigite o modelo do carro a ser pesquisado:");
                scanf("%s", modelo);
                Modelo(modelo);
                system("pause");
                break;
            }case 6:
            {
                printf("*** Carro mais antigo ***\n");
                Antigo();
                system("pause");
                break;
            }case 7:
            {
                float valor;
                printf("*** Gerar arquivos de carros mais baratos e mais caros ***\n");
                printf("\nDigite o valor:");
                scanf("%f", &valor);
                maisBarato_Caro(valor);
                system("pause");
                break;
            }default: 
            {
                printf("Opcao invalida!\n");
                system("pause");
            }
        }// Fim do Switch  
    }// Fim do While
}
