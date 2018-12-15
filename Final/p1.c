#include<stdio.h>
#include<string.h>
  
#define K 1024
  
  int main(int argc, char* argv []) {
  int count=0;
  char ch[K];
  int i=0;
  int j;
  
  while(fgets(ch,K,stdin)) {
    for(j=0; j<=strlen(ch)-1; j++) {
      if(ch[j]>='0' && ch[j]<='9') {
	count++;
	break;
      }
    }
  }
	
  printf("%d\n", count);
}