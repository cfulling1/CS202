#include<stdio.h>

int main() {
  for(;;) {
  int num;
  int buffer=0;
  printf("? ");
  scanf("%d", &num);
  while(num>1) {
    if((num & 1)==1) {
      buffer=buffer+1;
      buffer=buffer<<1;
    }
    else {
      buffer=buffer<<1;
    }
    num=num>>1;
  }
  
  if(num==1) {
    buffer=buffer+1;
  }
  printf("%d\n", buffer);
  }
}
