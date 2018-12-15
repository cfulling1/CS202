#include<stdio.h>

int main() {
  char c;
  int count;
  count=0;
  int charcount=0;
  
  while((c=getchar())!=EOF) {
    while(c!='\n') { 
      charcount++;
    }
    if(charcount>=10) count++;
    
    charcount=0;
  }
}
