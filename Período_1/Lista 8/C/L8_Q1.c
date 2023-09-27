
#include <stdio.h>

int main(void){
	int a, b, c, d;
	
	printf("Informe o comprimentos das 4 varetas: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	if(a < b+c && b < a+c && c < a+b)
		printf("S");
	else if(a < b+d && b < a+d && d < a+b)
		printf("S");
	else if(a < c+d && c < a+d && d < a+c)
		printf("S");
	else if(b < c+d && c < b+d && d < b+c)
	printf("S");
	else
	printf("N");

	return 0;
}
