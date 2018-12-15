#include<stdio.h>

int main() {
  int i=0;
  int size=0;
  int j;
  char storage[100];
  
  while((storage[size]=getchar())!='\n') {
    size++;
  }
  storage[size]='\0';
  
  while(i<size) {
    if(storage[i]==' ' && (storage[i-1]==' ' || storage[i+1]==' ')){
      for(j=i; j<size; j++)
        storage[j]=storage[j+1];
      size--;
    }
    else  i++;
  }
  
    for(i=0; i<size; i++) {
    if(storage[i]>='A' && storage[i]<='Z') {
      storage[i]=storage[i]+32;
    }
  }
  
  
  printf("%s\n", storage);
}
