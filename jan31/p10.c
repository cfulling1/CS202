#include<stdio.h>
  
  int main(int argc, char* argv []) {
  int count=0;
  char ch;
  int i=0;
    FILE* fp = fopen(argv[1], "r");
      if(!fp) {
        fprintf(stderr, "Error: your file could not be opened\n");
          return 1;
      }
  while(ch!=EOF) {
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
      i++;
      if(i>=3) {
        count++;
        while(ch!=' ' && ch!='\n' && ch!=EOF)
          ch=getc(fp);
      }
      else  ch=getc(fp);
    }
    else {
      i=0;
      ch=getc(fp);
    }
  }
  printf("%d\n", count);
  fclose(fp);
}
