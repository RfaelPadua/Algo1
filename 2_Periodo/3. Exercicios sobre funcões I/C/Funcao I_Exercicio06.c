#include <stdio.h>
#include <math.h>

void recebe(float *a, float *b, float *c);

void raizes(float a, float b, float c, double *raiz1, double *raiz2, int *flag);


int main(){
	int flag = 1;
	float a, b, c;
	double raiz1, raiz2;
	
	recebe(&a, &b, &c);
	
	raizes(a, b, c, &raiz1, &raiz2, &flag);
	if(flag)
	printf("A raiz 1 eh: %.2lf\nA raiz 2 eh: %.2lf\n", raiz1, raiz2);
	else
	printf("Nao tem raiz.");
	
}

void recebe(float *a, float *b, float *c){
	scanf("%f %f %f", a, b, c);
}

void raizes(float a, float b, float c, double *raiz1, double *raiz2, int *flag){
	float delta;
	
	delta = (b * b) - (4*a*c);
	delta < 0 ? *flag = 0 : delta;
	
	*raiz1 = (-b + sqrt(delta)) / (2*a);
	*raiz2 = (-b - sqrt(delta)) / (2*a);
}
