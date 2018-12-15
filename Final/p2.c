#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAYSIZE  256
#define K 1024

int main(int argc, char *argv[]) {
  int space,i;
  int j=0;
  
  char arrayTwo[K];
  int *arrayOne;
  int a;
  space=ARRAYSIZE; 
  arrayOne=malloc(space * sizeof(int));
  while(1==scanf("%d", &a)) {
     if(j>=space) {
      space*=2;
      arrayOne=realloc(arrayOne, space * sizeof(int));
    }
    for(i=0; i<strlen(arrayOne); i++) {
	if(arrayOne[i]==a) {
	  printf("%d\n", a);
	}
    }
    arrayOne[j]=a;
    j++;
  }
}
