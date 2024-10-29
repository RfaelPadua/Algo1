#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>

#define MAIOR_VALOR_INTEIRO 18446744073709551615




// Função para converter inteiro para binário
void inteiroParaBinario(unsigned long long int n, char *binario) ;

// Função para converter decimal para binário
void decimalParaBinario(char *parteDecimal, char *numeroBinario, int precision);

// Função para converter número para binário
void converterNumeroParaBinario(char *num, char *parteInteira, char *parteDecimal);

// Função para calcular o expoente
int calcularExpoente(char *parteInteira, char *parteDecimal);

void normalizarNumero(char *parteInteira, char *parteDecimal, char *mantissa, int m);

void binarioParaInteiro(char *parteInteira, char *inteiro);

void binarioParaDecimal(char *parteBinaria, char *numeroDecimal, int precisao);

// Function prototype for aplicarRepresentacoesNegativas
void aplicarRepresentacoesNegativas(char *mantissa, int m, char *complemento1, char *complemento2);

// função para tirar o bit da normalização
void tirarBitNormalizacao(char *mantissa, int expoente, char *parteInteira, char *parteDecimal);




int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("cls");

    char mantissa[128];
    char num[128] = "12.5";
    char parteInteira[128];
    char parteDecimal[128];
    char sinal = '1';
    int m = 10;
    

    converterNumeroParaBinario(num, parteInteira, parteDecimal);
    int expoente = calcularExpoente(parteInteira, parteDecimal);

    normalizarNumero(parteInteira, parteDecimal, mantissa, m);

    // Normalizar o número
    printf("Número normalizado armazenado em binário: ");
    printf("%c ", sinal);
    printf("0.%s ", mantissa);
    printf("x 2^%d\n", expoente);
    char sinalAmplitude[128];
    char complemento1[128];
    char complemento2[128];
    if(sinal == '1'){
        aplicarRepresentacoesNegativas(mantissa, m, sinalAmplitude, complemento1, complemento2);
    }
    printf("parteInteira: %s\n", parteInteira);
    printf("parteDecimal: %s\n", parteDecimal);
    tirarBitNormalizacao(mantissa, expoente, parteInteira, parteDecimal);

    binarioParaInteiro(parteInteira, num);
    printf("Parte inteira: %s\n", num);
    binarioParaDecimal(parteDecimal, num, 100);
    printf("Parte decimal: %s\n", num);
    goto fimTeste;

    int programaEstaRodando = 1;
    while(programaEstaRodando){
        int m, l, u;
        // m = número de casas da mantissa
        // l = menor valor do expoente
        // u = maior valor do expoente
        printf("\tF(β,m,l,u)\n");
        printf("Digite o valor da mantissa(m): ");
        scanf("%d", &m);
        printf("Digite o valor do menor expoente(l): ");
        scanf("%d", &l);
        printf("Digite o valor do maior expoente(u): ");
        scanf("%d", &u);

        if(m < 0 || u<=l){
            printf("Valores inválidos, tente novamente\n");
            system("pause");
            system("cls");
            continue;
        }

        


        int controle = 1;
        while(controle){
            char num[1280];
            char sinal = '0';
            char parteInteira[128];
            char parteDecimal[128];

            
            printf("Digite 'v' para voltar ao menu principal ou 's' para sair do programa\n");
            printf("\n\t\t\tF(β,m,l,u)=F(10,%d,%d,%d)\n\n", m, l, u);
            // usuario escreve 'v' para voltar ao menu principal e 's' para sair do programa

            printf("Informe o número a ser convertido: ");
            
            scanf("%s", num); fflush(stdin);

            // Verificar se é uma string recebida é um número
            int i = 0;
            if(num[0] == '-'){
                i++;
                sinal = '1';
                //Tirar o sinal negativo
                strcpy(num, &num[1]);
            }else if(num[0] == 'v'){
                controle = 0;
                system("cls");
            }else if(tolower(num[0]) == 's'){
                controle = 0;
                programaEstaRodando = 0;
                system("cls");
            }

            for(i = 0; i < (int)strlen(num); i++){
                if(num[i] == ','){
                    num[i] = '.';
                }
            }
            while(num[i] != '\0'){
                if(num[i] == '.'){
                    i++;
                    
                    continue;
                }
                if(num[i] < '0' || num[i] > '9'){
                    printf("Número inválido, tente novamente\n");
                }
                i++;
            }

            converterNumeroParaBinario(num, parteInteira, parteDecimal);
            printf("Número em binário: %c %s.%s\n", sinal, parteInteira, parteDecimal);

            int expoente = calcularExpoente(parteInteira, parteDecimal);
            if(expoente < l){
                printf("Underflow\n");
            }else if(expoente > u){
                printf("Overflow\n");
            }

            char mantissa[128];

            normalizarNumero(parteInteira, parteDecimal, mantissa, m);

            // Normalizar o número
            printf("Número normalizado armazenado em binário: ");
            printf("%c ", sinal);
            printf("0.%s ", mantissa);
            printf("x 2^%d\n", expoente);

            // Implementar a representação negativa se necessário
            if(sinal == '1'){
                char sinalAmplitude[128];
                char complemento1[128];
                char complemento2[128];
                aplicarRepresentacoesNegativas(mantissa, m, complemento1, complemento2);
            }

            // Converter o número para decimal
            char numeroDecimal[128];
            converterBinarioParaNumero(mantissa, numeroDecimal);
            

            system("pause");
            system("cls");


        }
    }

    fimTeste:
    return 0;
}


// Função para converter inteiro para binário
void inteiroParaBinario(unsigned long long int n, char *binario) {
    if(n == 0){
        binario[0] = '0';
        binario[1] = '\0';
        return;
    }

    unsigned long long int num = n;
    int i = 0;
    while (num > 0) {
        binario[i] = (num % 2) + '0';
        num /= 2;
        i++;
    }
    binario[i] = '\0';


    // Inverte a string
    int j = 0;
    i--;
    while (j < i) {
        char temp = binario[j];
        binario[j] = binario[i];
        binario[i] = temp;
        j++;
        i--;
    }

    return;
}

// Função para converter decimal para binário
void decimalParaBinario(char *parteDecimal, char *numeroBinario, int precisao) {

    int casasDecimais = strlen(parteDecimal);
    char *endptr;
    long double numeroDecimal = strtold(parteDecimal, &endptr); // Converter a string para um número decimal


    if(numeroDecimal == 0){ // Se o número for 0, retorna 0
        numeroBinario[0] = '0';
        numeroBinario[1] = '\0';
        return;
    }

    int i;
    for(i = 0; i < precisao; i++) {
        numeroDecimal *= 2;
        if((unsigned long long int)(numeroDecimal / pow(10, casasDecimais)) > 0) { // Simula a movimentação da vírgula
            numeroBinario[i] = '1';
            numeroDecimal -= pow(10, casasDecimais); // Remove o 1 da parte inteira
        } else {
            numeroBinario[i] = '0'; // Se não houver 1 na parte inteira, adiciona 0
        }
        if (numeroDecimal == 0){  // Se a parte decimal for 0, finaliza
            numeroBinario[i+1] = '\0';
            break; // Finaliza se não houver mais fração
        }else if(i == precisao - 1){ // Se atingir a precisão, finaliza
            numeroBinario[i+1] = '\0';
            break;
        }
    }
    return;
}

void converterNumeroParaBinario(char *num, char *parteInteira, char *parteDecimal) {


    //converter a parte inteira e Decimal
    int inteiro = atoi(num);
    char decimal[128];

    for(int i = 0; num[i] != '\0'; i++){
        if(num[i] == '.'){
            
            strcpy(parteDecimal, num+i+1);
            break;
        }
    }

    inteiroParaBinario(inteiro, parteInteira);
    decimalParaBinario(parteDecimal, decimal, 100);

    strcpy(parteDecimal, decimal);

}

// Função para normalizar o número
int calcularExpoente(char *parteInteira, char *parteDecimal) {
    int i = 0;
    int expoente = 0;

    if(parteInteira[0] == '0'){
        while(parteDecimal[i] != '1'){
            i++;
            expoente--;
        }
    }else{
        expoente = strlen(parteInteira);
    }

    return expoente;
}

void normalizarNumero(char *parteInteira, char *parteDecimal, char *mantissa, int m) {
    int expoente = calcularExpoente(parteInteira, parteDecimal);

    mantissa[0] = '\0';
    // Implementação da normalização do número
    if(expoente < 0){
        expoente = expoente * -1;
        strcat(mantissa, &parteDecimal[expoente]);
        
    }else{
        strcat(mantissa, parteInteira);
        strcat(mantissa, parteDecimal);
    }

    if((int)strlen(mantissa) > m){
        mantissa[m] = '\0';
    }

}

// Função para aplicar representações negativas
void aplicarRepresentacoesNegativas(char *mantissa, int m, char *complemento1, char *complemento2) {
    // Implementação da representação negativa
    printf("Representação negativa\n");
    printf("Sinal de amplitude: 1 0.%s\n", mantissa);

    m = strlen(mantissa);

    // Complemento de 1
    strcpy(complemento1, mantissa);
    for(int i = 0; i < m; i++){
        if(complemento1[i] == '0'){
            complemento1[i] = '1';
        }else{
            complemento1[i] = '0';
        }
    }
    printf("Complemento de 1:   1 1.%s\n", complemento1);

    // Complemento de 2
    strcat(complemento2, "11");
    strcat(complemento2, complemento1);
    int carry = 1;
    m = strlen(complemento2);
    for (int i = m - 1; i >= 0; i--) {
        // Adiciona o carry ao dígito atual
        if (carry) { // Verifica se ainda há carry para adicionar
            if (complemento2[i] == '1') {
                complemento2[i] = '0'; // Se era 1, vira 0
                // O carry continua
            } else { // Se era 0
                complemento2[i] = '1'; // Se era 0, vira 1 e termina o carry
                carry = 0; // Não precisamos carregar mais
                break; // Sai do loop
            }
        }
    }
    
    for(int i = 0; i <= m; i++){
        if(i == 0){
            printf("Complemento de 2:   %c ", complemento2[i]);
        }else if(i == 1){
            printf("%c.", complemento2[i]);
        }else{
            printf("%c", complemento2[i]);
        }

    }

    printf("\n");

}


// Função para converter binário para decimal
void converterBinarioParaNumero(char *binario, char *numero) {
    
}

void binarioParaInteiro(char *parteInteira, char *inteiro) {
    int i = 0;
    int len = strlen(parteInteira);

    unsigned long long int num = 0;
   
    // Convertendo de binário para decimal
    for (i = 0; i < len; i++) {
        if (parteInteira[i] == '1') {
            num += 1ULL << (len - i - 1);
        }
    }

    // Converte o número inteiro para string na ordem correta
    sprintf(inteiro, "%llu", num);

}

void binarioParaDecimal(char *parteBinaria, char *numero, int precisao) {
    long double valorDecimal = 0.0;
    int len = strlen(parteBinaria);

    char numeroDecimal[128];

    
    // Percorre cada dígito da parte binária
    for (int i = 0; i < len; i++) {
        if (parteBinaria[i] == '1') {
            valorDecimal += pow(2, -(i + 1));
        }
    }


    // Formata o número decimal resultante como uma string
    snprintf(numeroDecimal, precisao + 2, "%.*Lf", precisao, valorDecimal);

    // copiar numero Decimal a parter da virgula em numero
    strcat(numero, numeroDecimal+1);

    // remover o 0 a direita
    int i = strlen(numero) - 1;
    while(numero[i] == '0'){
        numero[i] = '\0';
        i--;
    }
}

void tirarBitNormalizacao(char *mantissa, int expoente, char *parteInteira, char *parteDecimal){
    strcpy(parteInteira, "\0");
    strcpy(parteDecimal, "\0");

    int i;

    if(expoente < 0){
        expoente = expoente * -1;
        strcpy(parteInteira, "0");
        for(i = 0; i < expoente; i++){
            parteDecimal[i] = '0';
        }
        strcat(parteDecimal, mantissa);
    }else{
        for(i = 0; i < expoente; i++){
            parteInteira[i] = mantissa[i];
        }
        parteInteira[i] = '\0';
        strcpy(parteDecimal, &mantissa[i]);
    }
}
        