#include <stdio.h>

int main(){
int x = 150;

if(x <= 200)
    if(x < 100)
        if(x < 0) printf("A");
        else printf("B");
else printf("C");
else printf("D");

printf("\nA faixa de valores para que a letra C seja impresa eh 100>x>=200");

return 0;
}