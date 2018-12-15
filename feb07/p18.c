#include<stdio.h>

int checkBit();

int main() {
  int x;
  int i;
  for(i=1; i<=100; i++) {
    checkBit(i);
      if(checkBit())  printf("%d\n", i); 
  }
}

int checkBit(int n) {
  int check;
  int mask=4;
 
  check=(n&mask);

  if(check!=4)  return 1;
  else  return 0;
}
