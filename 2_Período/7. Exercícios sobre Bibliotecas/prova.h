int vogais_seguidas(char *str){ //Questão 1
    int i, j, cont = 0, ehvogal = 0;
    char vogais[11] = "aeiouAEIOU";

    for(i = 0; str[i] != '\0'; i++, ehvogal = 0){
        for(j = 0; j < 10; j++){
            if(str[i] == vogais[j]){
                ehvogal = 1;
                break;
            }
        }
        if(ehvogal == 1){
            cont++;
        }else{
            cont = 0;
        }

        if(cont == 2){
            return 1;
        }
    }
    return 0;
} 

void maior_menor(int m, int n, int matriz[m][n], int *maior, int *menor){ //Questão 2
    int max = matriz[0][0], min = matriz[0][0];
    int i, j;

    for(i = 0; i< m; i++){
        for(j = 0; j < n; j++){
            if(matriz[i][j] > max){
                max = matriz[i][j];
            }
            if(matriz[i][j] < min){
                min = matriz[i][j];
            }
        }
    }
    *maior = max;
    *menor = min;
}

int temNperfeito(int m, int n, int matriz[m][n]){ //Questão 3
    int i, j, k, soma = 0;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            for(k = 1; k < matriz[i][j]; k++){
                if(matriz[i][j] % k == 0){
                    soma += k;
                }
            }
            if(soma == matriz[i][j]){
                return 1
            }
            soma = 0;
        }
    }
    return 0;
}

int soma_linha(int m, int n, int matriz[m][n]){
    int i, j, somas[m];

    for(i = 0; i < m; i==){
        soma[i] = 0;
        for(j = 0; j < n; j++){
            soma[i] += matriz[i][j];
        }
        if(i == 0){
            continue;
        }else{
            if(soma[i]!= soma [i - 1]){
                return 0;
            }
        }
    }
    return 1;
}