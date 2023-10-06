#include <stdio.h>

float media_aritmetica(float, float, float);
float media_ponderada(float, float, float);

int main(){
	float n1, n2, n3;
	char letra;
	
	printf("Informe as 3 notas do aluno: "); scanf("%f%f%f", &n1, &n2, &n3);
	printf("Digite 'A' para receber a media aritmetica.\nDigite 'P' para receber a media ponderada.\n");
	fflush(stdin); scanf("%c", &letra);
	
	switch(letra){
		case 'A':
			printf("A media aritmetica eh %.2f\n", media_aritmetica(n1, n2, n3));
			break;
		case 'P':
			printf("A media ponderada eh %.2f\n", media_ponderada(n1, n2, n3));
			break;
		default:
			printf("Comando errado!\n");
			break;
	}
	
	return 0;
}

float media_aritmetica(float n1, float n2, float n3){
		return (n1+n2+n3)/3;
}
float media_ponderada(float n1, float n2, float n3){
		return (n1*5+n2*3+n3*2)/10;
}
