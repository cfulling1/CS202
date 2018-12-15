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
  int check2;
  int check3;
  int finalcheck;
  int mask=4;
 
  check2=n&mask;
  check3=((n>>1)&mask);
  
  finalcheck=check2^check3;
  
  if(finalcheck==4)  return 1;
  else  return 0;
}
