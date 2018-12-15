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
  char buffer[K];
  
  while(ch!=EOF) {
      if(ch=='b') {
        while((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
            if(ch=='b') {
              count++;
              while(ch!='\n' && ch!=EOF)   ch=getc(fp);
            }
            else  ch=fgetc(fp);
        }
      }
      else  ch=fgetc(fp);
  }
  
  
  
  int j=0;
  int k;
  for(i=0; i<=strlen(word)-1; i++) {
    while(word[i]!='\n' || word[i]!=' ') {
      buffer[j]=word[i];
      j++;
    }
    for(k=0; <=strlen(buffer); k++ {
      if(buffer[k]=='b' || buffer[k]=='B') {
	while(k<
	if(word[k+1]=='a' || word[k+1]=='A') {
	    if(word[i+2]=='d' || word[i+2]=='D') {
	      return 1;
	    }
	}
      }
  }
  return 0;
}