#include <stdio.h>

char conceito(float);

int main(){
	float media;
	
	scanf("%f", &media);
	
	printf("O conceito do aluno e: %c\n", conceito(media));
	
	return 0;
}

char conceito(float m){
	if (m >= 0.0 && m <= 4.9) {
        return 'D';
    } else if (m >= 5.0 && m <= 6.9) {
        return 'C';
    } else if (m >= 7.0 && m <= 8.9) {
        return 'B';
    } else if (m >= 9.0 && m <= 10.0) {
        return 'A';
	}
}
