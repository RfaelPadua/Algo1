#include <stdio.h>

int main(){
    float v_compra;

    printf("Valor de compra: ");
    scanf("%f", &v_compra);

    if(v_compra < 10){
        v_compra += v_compra*0.7;
        printf("Valor de Venda eh R$%.2f", v_compra);
    }
    else if(v_compra < 30){
        v_compra += v_compra*0.5;
        printf("Valor de Venda eh R$%.2f", v_compra);
    }
    else if(v_compra < 50){
        v_compra += v_compra*0.4;
        printf("Valor de Venda eh R$%.2f", v_compra);
    }
        else{
        v_compra += v_compra*0.3;
        printf("Valor de Venda eh R$%.2f", v_compra);
    }

return 0;
}