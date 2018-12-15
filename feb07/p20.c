#include<stdio.h>

int threeConsec();

int main() {
  int i;
  for(i=1; i<=100; i++) {
    threeConsec(i);
      if(threeConsec()) printf("%d\n", i);
  }
}

int threeConsec(int n) {
  int mask=7;
  int check;

  while(n) {
    check=n&mask;
    if(check==7)  return 1;
    else  n=n>>1;
  }
  return 0;
}
