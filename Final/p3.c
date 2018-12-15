#include<stdio.h>
#include<string.h>
#define K 1024

int bad(char word[]);

int main() {
  char word[K];
  while(fgets(word,K,stdin)) {
    if(bad(word))
      printf("%s", word); 
  }
}

int bad(char word[]) {
  int i;
  for(i=0; i<=strlen(word)-3; i++) {
      if(word[i]=='b' || word[i]=='B') {
	if(word[i+1]=='a' || word[i+1]=='A') {
	    if(word[i+2]=='d' || word[i+2]=='D') {
	      return 1;
	    }
	}
      }
  }
  return 0;
}