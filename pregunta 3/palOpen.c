#include "stdio.h"
#include <string.h>
#include "omp.h"

#define MAX 10

int main(){
  int i;
  char cad[] = "oruro";
  int p = 0;
#pragma omp parallel for private(i) reduction(+:p)
  for (i = 0; i < strlen(cad); i++){
    if(cad[i] != cad[strlen(cad)-(i+1)])
       p = p + 1;
} 
  if( p == 0)
    printf("verdad\n");
  else
        printf("falso\n");
  
}
