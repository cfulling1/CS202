#include<stdio.h>

int main() {
  int size=0;
  char storage[100];
  
  while((storage[size]=getchar())!='\n') {
    size++;
  }
  storage[size]='\0';

  printf("%s\n", storage);
}
