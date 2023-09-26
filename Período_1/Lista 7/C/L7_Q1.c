/*******************************************************************
*  Escreva um programa que verifique a validade de uma senha fornecida 
*  pelo usuário. A senha válida é o número 1234. Devem ser impressas 
*  as seguintes mensagens: ACESSO PERMITIDO caso a senha seja válida. 
*  ACESSO NEGADO caso a senha seja inválida.
*******************************************************************/
#include <stdio.h>

int main(void){
    
    int senha = 1234, verificacao;

    //Pedir pela Senha
    printf("Senha: ");
    scanf("%d", &verificacao);

    //Verificar a calidade da senha 
    verificacao == senha ? printf("ACESSO PERMITIDO\n") : printf("ACESSO NEGADO\n");

    // switch (verificacao)
    // {
    // case 1234:
    //     printf("ACESSO PERMITIDO\n");
    //     break;
    // default:
    //     printf("ACESSO NEGADO\n");
    //     break;
    // }

    // if (senha = 1234)
    // {
    //     printf("ACESSO PERMITIDO\n");
    // }else
    // {
    //     printf("ACESSO NEGADO\n");
    // }
    
    return 0;
}