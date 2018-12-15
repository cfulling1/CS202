#include<stdio.h>
#include<string.h>
#define K 1024

int main() {
  char word[K];
  char buffer[K];
  
  int i;
  int count=0;
  
  while(fgets(word,K,stdin)) {
    for(int i=0; i=strlen(word); i++) {
      while(word[i]!='\n' || word[i]!=' ') {
      buffer[j]=word[i];
      j++;
    }
    for(int k=0; k<strlen(buffer); k++) {
      if(buffer[k]=='b') {
	  
      }
    }
  
  while(ch!=EOF) {
      if(ch=='a') {
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
  printf("%d\n", count);
  fclose(fp);
}
