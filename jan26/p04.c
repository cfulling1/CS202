#include<stdio.h>

int main() {
  int i;
  int j=0;
  for(i=1; i<=100; i++){
      if((i%3)!=0 && (i%5)!=0){
          printf("%3d",i);
          j++;
          if(j==3){
            printf("\n");
            j=0;
          }
      }
    }
  printf("\n");
}
