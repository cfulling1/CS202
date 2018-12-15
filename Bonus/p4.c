#include<stdio.h>

int main() {
  int count=0;
  int x;
  for(int i=1; i<=1000; i++) {
    x=i;
    while(x) {
      if((x & 1)==1)  count++;
      x=x>>1;
    }
    if(count==2)  printf("%d\n", i);
    count=0;
  }
}
