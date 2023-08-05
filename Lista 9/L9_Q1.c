#include <stdio.h>

int main(void){
    int i = 0;

    // for(i = 1; i<100;i++)
    // {
    //     if(i % 2 == 0)
    //         printf("%d ", i);
    // }

    for(i = 2; i < 100; i+=2)
    {
        printf("%d ", i);
    }

    
    return 0;
}