//*counting number of lines that have an 'a' followed by a 'b' somewhere within the same line *//

#include<stdio.h>

int main() {
  char ch;
  int i;
  int count=0;
  FILE* fp = fopen("/usr/dict/words", "r");
    if(!fp) {
      fprintf(stderr, "Error: your file could not be opened\n");
        return 1;
    }
  ch=getc(fp);
  
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
