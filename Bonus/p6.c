#include<stdio.h>

int highbit(unsigned long word);

int main(int argc, char* argv) {
  unsigned long x;
  for(;;) {
    int count;
    int pos=1;

    printf("? ");
    scanf("%d", &x);

    count=highbit(x);
    for(int i=1; i<count; i++) {
      pos=pos*2;
    }
    printf("%d\n", pos);
  }
}

int highbit(unsigned long word) {
  int count=0;
  while(word) {
    word=word>>1;
    count++;
  }
  return count;
}
