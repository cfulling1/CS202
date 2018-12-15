#include<stdio.h>

int main(int argc, char* argv[]) {
  int count=0;
  int ch, i;
  FILE* fp = fopen(argv[1], "r");
    if(!fp) {
      fprintf(stderr, "Error: your file could not be opened\n");
        return 1;
    }
  ch=getc(fp);
  while(ch!=EOF) {
    if(ch=='\n') {
      count++;
      ch=getc(fp);
    }
    else  ch=getc(fp);
  }
  fprintf(stdout, "%d\n", count);
}
