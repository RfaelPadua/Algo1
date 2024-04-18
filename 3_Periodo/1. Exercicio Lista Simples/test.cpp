#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Vetor;

int Max(Vetor *A){
  int i, Temp;
  int n = 5;
  
  Temp = A[0];
  
  for(i = 1; i < n; i++){
    if(Temp < A[i])Temp = A[i];
  }
  return Temp;
}//Max


int main(){
    
    Vetor A[5] = {4, 3, 1, 8, 5};
    
    Max(A);
  
}