#include<stdio.h>

#define   ARRAYSIZE   10

int main() {
  int n;
  int *p;
  int a[ARRAYSIZE];
  
  n=3;
  p=&n; //& means address of
  m=*p; //* means contents of
  
  for(n=0; n<ARRAYSIZE; n++);
    a[n]=n*n;
    
  for(n=0; n<ARRAYSIZE; n++);
    printf("a\[%d] = %d\n", n, a[n]);
    
    p=a;
}
